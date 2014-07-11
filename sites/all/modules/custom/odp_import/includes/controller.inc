<?php

function odp_import_get_subject_id($subject) {
  return odp_import_get_term_id_by_name(strtolower($subject), ODP_IMPORT_VOCABULARY_SUBJECTS);
}

function odp_import_get_format_id($format) {
  return odp_import_get_term_id_by_name(strtolower($format), ODP_IMPORT_VOCABULARY_FORMATS);
}

function odp_import_get_term_id_by_name($name, $vocabulary) {
  // Get terms by name.
  $terms = taxonomy_get_term_by_name($name, $vocabulary);

  return !empty($terms) ? reset($terms)->tid : FALSE;
}

function odp_import_get_file_by_uri($uri) {
  $conditions = array('uri' => trim($uri));

  return file_load_multiple(array(), $conditions);
}

function odp_import_load_or_create_subject_by_name($name) {
  $subject_id = odp_import_get_subject_id($name);

  if ($subject_id) {
    $subject = taxonomy_term_load($subject_id);
  }

  if (empty($subject)) {
    $subject = new stdClass();
    $subject->name = $name;
    $subject->vid = ODP_IMPORT_VOCABULARY_SUBJECTS_ID;
    taxonomy_term_save($subject);
  }

  return $subject;
}

function odp_import_load_file($uri) {
  // Get file by url.
  $files = odp_import_get_file_by_uri($uri);
  $file = !empty($files) ? reset($files) : FALSE;

  return $file;
}

function odp_import_convert_to_utf8(&$data) {
  $encoder = od_detect_encoding_get_detector();
  $converted_data = $encoder->convertString($data, 'UTF-8');

  if ($converted_data) {
    $data = $converted_data;
  }

  return (bool) $converted_data;
}

function odp_import_create_local_file($destination, $origin_uri) {
  $data = odp_import_get_url_content($origin_uri);
  if ($data === FALSE) {
    return FALSE;
  }

  $exists = file_prepare_directory(drupal_dirname($destination), FILE_CREATE_DIRECTORY);
  if ($exists === FALSE) {
    return FALSE;
  }

  $is_utf8 = odp_import_convert_to_utf8($data);

  // Save file.
  $uri = file_unmanaged_save_data($data, $destination, FILE_EXISTS_REPLACE);
  if ($uri === FALSE) {
    return FALSE;
  }

  $file = odp_import_create_file($uri);

  $file->utf8 = (integer) $is_utf8;

  return $file;
}

function odp_import_create_remote_file($uri) {
  $file_exists = odp_import_check_file_exists($uri);
  if ($file_exists === FALSE) {
    return FALSE;
  }

  $file = odp_import_create_file($uri);

  return $file;
}

function odp_import_create_file($uri) {
  // Create a file object.
  $file = new stdClass();
  $file->fid = NULL;
  $file->uri = $uri;
  $file->filename = drupal_basename($uri);
  $file->filemime = file_get_mimetype($uri);
  $file->uid = OD_COMMON_IMPORT_USER_ID;
  $file->status = FILE_STATUS_PERMANENT;

  // If we are replacing an existing file re-use its database record.
  $existing_files = file_load_multiple(array(), array('uri' => $uri));
  if (count($existing_files)) {
    $existing = reset($existing_files);
    $file->fid = $existing->fid;
    $file->filename = $existing->filename;
  }

  return file_save($file);
}

function odp_import_get_url_content($url) {
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_URL, $url);
  curl_setopt($curl, CURLOPT_BUFFERSIZE, '1024');
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($curl, CURLOPT_FRESH_CONNECT, 1);
  curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($curl, CURLOPT_NOPROGRESS, 0);
  curl_setopt($curl, CURLOPT_PROGRESSFUNCTION, function($resource, $download_size) {
    return $download_size > ODP_IMPORT_OPENDATA_MAX_SIZE;
  });

  $content = curl_exec($curl);

  $http_code = curl_getinfo($curl, CURLINFO_HTTP_CODE);

  curl_close($curl);

  return $http_code < 400 ? $content : FALSE;
}

function odp_import_check_file_exists($url) {
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_URL, $url);
  curl_setopt($curl, CURLOPT_BUFFERSIZE, '1024');
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($curl, CURLOPT_FRESH_CONNECT, 1);
  curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($curl, CURLOPT_NOPROGRESS, 0);
  curl_setopt($curl, CURLOPT_PROGRESSFUNCTION, function($resource, $download_size) {
    return $download_size > (1024 * 1024);
  });

  curl_exec($curl);

  $http_code = curl_getinfo($curl, CURLINFO_HTTP_CODE);

  curl_close($curl);

  return $http_code < 400 ? TRUE : FALSE;
}

function odp_import_build_file_uri($type, $data, $meta) {
  switch ($type) {
    case ODP_IMPORT_STRUCTURE_TYPE:
      if (empty($data['structure']['source']) || empty($data['structure']['created'])) {
        return FALSE;
      }
      $origin_uri = $data['structure']['source'];
      $structure_created = odp_import_format_date_iso_url($data['structure']['created']);
      $name = 'structure-' . $structure_created;
      break;
    case ODP_IMPORT_DATA_TYPE:
      if (empty($data['source']) || empty($data['created']) || empty($data['structure']['created'])) {
        return FALSE;
      }
      $origin_uri = $data['source'];
      $data_created = odp_import_format_date_iso_url($data['created']);
      $structure_created = odp_import_format_date_iso_url($data['structure']['created']);
      $name = 'data-' . $data_created . '-structure-' . $structure_created;
      break;
    default:
      return FALSE;
  }

  $meta_identifier = $meta['identifier'];

  $path_info = pathinfo($origin_uri);
  $format = $path_info['extension'];

  $path = array();

  $path[] = 'opendata';
  $path[] = $meta_identifier;
  $path[] = $name . '.' . $format;

  $uri = file_build_uri(implode('/', $path));

  if (!file_valid_uri($uri)) {
    return FALSE;
  }

  return $uri;
}

function odp_import_format_date_iso_url($created) {
  $created = strtotime($created);

  return $created ? date('Y-m-d\TH-i-s', $created) : FALSE;
}

function odp_import_get_source_revisions($nid) {
  $revisions = array();

  $query = db_select('node_revision', 'r');
  $query->addExpression('MAX(r.vid)', 'vid');
  $query->innerJoin('field_revision_field_created', 'c', 'r.vid = c.revision_id');
  $query->condition('r.nid', $nid);
  $query->groupBy('c.field_created_value');
  $query->orderBy('c.field_created_value', 'DESC');
  $resource = $query->execute();
  $result = $resource->fetchAllAssoc('vid');

  $vids = !empty($result) ? array_keys($result) : array();

  foreach ($vids as $vid) {
    $revisions[$vid] = node_load($nid, $vid);
  }
  return $revisions;
}

function odp_import_meta_list($list_vars) {
  // List object.
  $od = new OdApi($list_vars['vars']);
  $meta_list = $od->getResult($list_vars['args']);

  $error = $od->getError();

  if (!empty($error)) {
    $message = 'Ошибка в реестре раздела открытых данных организации "' . $list_vars['org_name'] . '": ' . $error;
    od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $list_vars['org_nid']);
  }

  return $meta_list['meta'];
}

function odp_import_meta($meta_vars) {
  // Load "Opendata API" library.
  od_api();

  $od = new OdApi($meta_vars['vars']);

  // Meta object.
  $meta = $od->getResult($meta_vars['args']);

  $error = $od->getError();

  if (empty($error)) {
    OdApiHelper::clearProperties($meta);

    odp_import_publisher($od, $meta);

    odp_import_data_list($od, $meta);
  }
  else {
    if (!is_array($meta)) {
      $meta = array();
    }
    if (!isset($meta['title'])) {
      $meta['title'] = $meta_vars['meta']['title'];
    }

    $meta['#error'] = $error;
  }

  return $meta;
}

function odp_import_publisher(OdApi $od, &$meta) {
  if (!isset($meta['publisher'])) {
    return;
  }

  // Publisher object.
  $publisher_args = $meta['publisher']['#api'];
  $publisher = $od->getResult($publisher_args);

  $error = $od->getError();

  if (empty($error)) {
    $meta['publisher'] = $publisher;
    OdApiHelper::clearProperties($meta['publisher']);
  }
}

function odp_import_data_list(OdApi $od, &$meta) {
  if (!isset($meta['data'])) {
    return;
  }

  // Source object.
  $data_args = $meta['data']['#api'];
  $data_list = $od->getResult($data_args);

  $error = $od->getError();

  if (empty($error)) {
    $meta['data'] = $data_list['data'];
    OdApiHelper::clearProperties($meta['data']);

    odp_import_data($od, $meta);
  }
}

function odp_import_data(OdApi $od, &$meta) {
  if (!isset($meta['data'])) {
    return;
  }

  // Data object.
  foreach ($meta['data'] as &$data) {
    $data_args = $data['#api'];
    $data = $od->getResult($data_args);

    $error = $od->getError();

    if (empty($error)) {
      OdApiHelper::clearProperties($data);

      odp_import_structure($od, $data);
    }
  }
}

function odp_import_structure(OdApi $od, &$data) {
  if (!isset($data['structure'])) {
    return;
  }

  // Structure object.
  $structure_args = $data['structure']['#api'];
  $structure_result = $od->getResult($structure_args);

  $error = $od->getError();

  if (empty($error)) {
    $data['structure'] = $structure_result;
    OdApiHelper::clearProperties($data['structure']);
  }
}

/**
 * Parse opendata organization.
 */
function _odp_import_organizations_opendata($organizations) {
  // Check "Opendata API" library.
  if (!od_api()) {
    $error = 'Библиотека "Opendata API" не установлена.';
    od_log($error, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA);
    return FALSE;
  }

  // Get first organization.
  $organization = array_shift($organizations);

  $operations = _odp_import_organization_opendata($organization);

  if (!empty($organizations)) {
    $operations[] = array('_odp_import_organizations_opendata', array($organizations));
  }

  if (!empty($operations)) {
    $batch = array(
      'operations' => $operations,
      'finished' => '_odp_import_batch_meta_finished',
    );
    batch_set($batch);
    return TRUE;
  }

  return FALSE;
}

function _odp_import_organization_opendata($organization) {
  $operations = array();

  // Start timer.
  $time_start = date(ODP_IMPORT_TIMER_FORMAT);

  // Get organization url.
  if (!empty($organization->field_site_url[LANGUAGE_NONE][0])) {
    // Define variables for opendata API library.
    $vars = array();

    // Get organization opendata site url.
    $opendata_site_url = array();

    if (!empty($organization->field_opendata_portal_url[LANGUAGE_NONE][0]['url'])) {
      $opendata_site_url['portal'] = $organization->field_opendata_portal_url[LANGUAGE_NONE][0]['url'];
    }
    else {
      $opendata_site_url['site-url'] = $organization->field_site_url[LANGUAGE_NONE][0]['url'];
    }

    if (!empty($organization->field_organization_system[LANGUAGE_NONE][0]['url'])) {
      foreach($organization->field_organization_system[LANGUAGE_NONE] as $key => $system_url) {
        $opendata_site_url[$key . '-system url'] = $system_url['url'];
      }
    }

    // Get organization opendata page url.
    if (!empty($organization->field_opendata_page_url[LANGUAGE_NONE][0]['value'])) {
      $vars['semantic_list_url'] = $organization->field_opendata_page_url[LANGUAGE_NONE][0]['value'];
    }

    foreach ($opendata_site_url as $site_url) {
      $list_vars = array(
        'args' => array('meta-list' => $site_url),
        'vars' => $vars,
        'org_nid' => $organization->nid,
        'org_name' => $organization->title,
      );
      $list = odp_import_meta_list($list_vars);

      if (is_array($list) && !empty($list)) {
        // Meta object.
        foreach ($list as $meta) {
          $meta_vars = array(
            'args' => $meta['#api'],
            'vars' => $vars,
            'org_nid' => $organization->nid,
            'org_name' => $organization->title,
            'meta' => $meta,
            'time_start' => $time_start,
          );
          $operations[] = array('_odp_import_batch_meta', array($meta_vars));
        }
      }
    }
  }
  else {
    $message = 'У организации "' . $organization->title . '" отсутствует ссылка на сайт организации.';
    od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $organization->nid);
  }

  return $operations;
}

function _odp_import_batch_meta_finished($success, $results) {
  if (!empty($results['data'])) {
    odp_import_meta_from_data($results);
  }
}

function _odp_import_batch_meta($meta_vars, &$context) {
  // Init some variables.
  if (!isset($context['results']['data'])) {
    $context['results']['data'] = array();
  }
  if (!isset($context['results']['org_nid'])) {
    $context['results']['org_nid'] = $meta_vars['org_nid'];
  }
  if (!isset($context['results']['org_name'])) {
    $context['results']['org_name'] = $meta_vars['org_name'];
  }
  if (!isset($context['results']['time_start'])) {
    $context['results']['time_start'] = $meta_vars['time_start'];
  }

  $context['results']['data'][] = odp_import_meta($meta_vars);
  return;
}

function odp_import_meta_from_data($results) {
  $dataset_list_added = array();
  $dataset_list_actualized = array();
  $dataset_list_updated = array();
  $dataset_list_existed = array();
  $dataset_list_failed = array();

  $organization = new stdClass();
  $organization->nid = $results['org_nid'];
  $organization->name = $results['org_name'];

  foreach ($results['data'] as $meta) {
    // Skip opendata meta with error.
    if (isset($meta['#error'])) {
      $message = 'Ошибка в паспорте набора открытых данных "' . $meta['title'] . '" организации "' . $results['org_name'] . '" (' . $meta['#error'] . ').';
      od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $results['org_nid']);
      $dataset_list_failed[] = $meta['title'];
      continue;
    }

    $dataset_node = odp_load_dataset($meta['identifier']);

    $dataset_is_new = !$dataset_node ? TRUE : FALSE;

    if ($dataset_is_new) {
      $dataset_node = _odp_import_create_dataset($meta, $organization);
    }

    $dataset_updated = FALSE;
    $resource_updated = FALSE;
    $dataset_node = _odp_import_update_dataset($dataset_node, $meta, $organization, $dataset_updated, $resource_updated);

    if ($dataset_is_new) {
      $dataset_list_added[] = l($dataset_node->title, 'node/' . $dataset_node->nid);
    }
    else {
      if ($resource_updated || $dataset_updated) {
        if ($resource_updated) {
          $dataset_list_actualized[] = l($dataset_node->title, 'node/' . $dataset_node->nid);
        }
        if ($dataset_updated) {
          $dataset_list_updated[] = l($dataset_node->title, 'node/' . $dataset_node->nid);
        }
      }
      else {
        $dataset_list_existed[] = l($dataset_node->title, 'node/' . $dataset_node->nid);
      }
    }
  }

  $time_finish = date(ODP_IMPORT_TIMER_FORMAT);

  $message = <<<'MESSAGE'
Обработан реестр наборов открытых данных организации "%org_name".<br />
!timer
!meta_added_count
!meta_actualized_count
!meta_updated_count
!meta_existed_count
!meta_failed_count
!dataset_list_added
!dataset_list_actualized
!dataset_list_updated
!dataset_list_failed
MESSAGE;

  $timer = 'Время начало обработки: ' . $results['time_start'] . '. Время завершения обработки: ' . $time_finish . '.<br />';
  $meta_added_count = 'Количество новых загруженных наборов: ' . count($dataset_list_added) . '.<br />';
  $meta_actualized_count = 'Количество актуализированных наборов: ' . count($dataset_list_actualized) . '.<br />';
  $meta_updated_count = 'Количество обновленных наборов: ' . count($dataset_list_updated) . '.<br />';
  $meta_existed_count = 'Количество не измененных наборов: ' . count($dataset_list_existed) . '.<br />';
  $meta_failed_count = 'Количество наборов содержащих ошибки: ' . count($dataset_list_failed) . '.<br />';
  $dataset_list_added = $dataset_list_added ? ('Список загруженных наборов:<br />&nbsp;&nbsp;' . implode('<br />&nbsp;&nbsp;', $dataset_list_added) . '.<br />') : '';
  $dataset_list_actualized = $dataset_list_actualized ? ('Список актуализированных наборов:<br />&nbsp;&nbsp;' . implode('<br />&nbsp;&nbsp;', $dataset_list_actualized) . '.<br />') : '';
  $dataset_list_updated = $dataset_list_updated ? ('Список обновленных наборов:<br />&nbsp;&nbsp;' . implode('<br />&nbsp;&nbsp;', $dataset_list_updated) . '.<br />') : '';
  $dataset_list_failed = $dataset_list_failed ? ('Список наборов содержащих ошибки:<br />&nbsp;&nbsp;' . implode('<br />&nbsp;&nbsp;', $dataset_list_failed) . '.<br />') : '';

  $args = array(
    '%org_name' => $results['org_name'],
    '!timer' => $timer,
    '!meta_added_count' => $meta_added_count,
    '!meta_actualized_count' => $meta_actualized_count,
    '!meta_updated_count' => $meta_updated_count,
    '!meta_existed_count' => $meta_existed_count,
    '!meta_failed_count' => $meta_failed_count,
    '!dataset_list_added' => $dataset_list_added,
    '!dataset_list_actualized' => $dataset_list_actualized,
    '!dataset_list_updated' => $dataset_list_updated,
    '!dataset_list_failed' => $dataset_list_failed,
  );
  $message = format_string($message, $args);

  od_log($message, OD_LOG_IMPORTANCE_STATUS, OD_LOG_EVENT_IMPORT_DATA, $results['org_nid']);

  return TRUE;
}

/**
 * Create dataset for organization by identifier for.
 */
function _odp_import_create_dataset($meta, $organization) {
  $dataset_node = new stdClass();

  $dataset_node->type = 'dataset';
  node_object_prepare($dataset_node);
  $dataset_node->language = LANGUAGE_NONE;
  $dataset_node->uid = OD_COMMON_IMPORT_USER_ID;
  $dataset_node->promote = NODE_NOT_PROMOTED;
  $dataset_node->status = NODE_NOT_PUBLISHED;

  // Meta identifier.
  $dataset_node->{ODP_FIELD_DATASET_IDENTIFIER}[LANGUAGE_NONE][0] = array(
    'value' => $meta['identifier'],
    'format' => NULL,
    'safe_value' => check_plain($meta['identifier']),
  );

  // Meta creator.
  $dataset_node->{ODP_FIELD_DATASET_ORGANIZATION}[LANGUAGE_NONE][0] = array(
    'target_id' => $organization->nid,
  );

  // Set opendata log variables.
  if (empty($dataset_node->od_logged)) {
    $dataset_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
  }

  // Save node.
  node_save($dataset_node);

  return $dataset_node;
}

/**
 * Update dataset with meta values.
 */
function _odp_import_update_dataset($dataset_node, $meta, $organization, &$dataset_updated, &$resource_updated) {
  // Init messages variable.
  $messages = array();

  // Set dataset title field.
  _odp_import_dataset_set_title($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset description field.
  _odp_import_dataset_set_description($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset creator field.
  _odp_import_dataset_set_creator($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset created field.
  _odp_import_dataset_set_created($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset updated field.
  _odp_import_dataset_set_updated($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset valid field.
  _odp_import_dataset_set_valid($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset subject field.
  _odp_import_dataset_set_subject($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset publisher name field.
  _odp_import_dataset_set_publisher_name($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset publisher phone field.
  _odp_import_dataset_set_publisher_phone($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset publisher email field.
  _odp_import_dataset_set_publisher_mbox($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset resource.
  _odp_import_dataset_set_resource($dataset_node, $meta, $organization, $messages, $dataset_updated, $resource_updated);

  // Set opendata log variables if log has not disabled.
  if (empty($dataset_node->od_logged)) {
    $dataset_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
  }

  // Update dataset.
  if ($dataset_updated || $resource_updated) {
    $dataset_node->revision = TRUE;
    node_save($dataset_node);
  }

  // Set warning messages.
  foreach ($messages as $message) {
    od_log($message, OD_LOG_IMPORTANCE_WARNING, OD_LOG_EVENT_IMPORT_DATA, $organization->nid, $dataset_node->nid);
  }

  return $dataset_node;
}

/**
 * Set dataset title field.
 */
function _odp_import_dataset_set_title($dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_TITLE};

  $str_len = mb_strlen($meta['title']);

  if ($str_len > 255) {
    // Set warning message.
    $messages[] = 'Превышен допустимый размер в 255 символов для поля "Наименование набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '". Наименование набора не может быть записано в базу данных Портала ОД полностью. Значение поля обрезано до 255 символов.';
  }

  // Get the new field value.
  $title = $str_len > 255 ? mb_substr($meta['title'], 0, 255) : $meta['title'];

  // Get the new field value.
  $new_field_value = array(LANGUAGE_NONE => array('0' => array(
    'value' => $title,
    'format' => NULL,
    'safe_value' => check_plain($title),
  )));

  // Update the field if it has changed.
  if ($field_value !== $new_field_value) {
    $field_value = $new_field_value;
    $dataset_node->title = $title;
    $dataset_updated = TRUE;
  }
}

/**
 * Set dataset description field.
 */
function _odp_import_dataset_set_description($dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_DESCRIPTION};

  if (isset($meta['description'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array('0' => array(
      'value' => $meta['description'],
      'summary' => '',
      'format' => NULL,
      'safe_value' => check_plain($meta['description']),
      'safe_summary' => '',
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Описание набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset creator field.
 */
function _odp_import_dataset_set_creator($dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_CREATOR};

  if (isset($meta['creator'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array('0' => array(
      'value' => $meta['creator'],
      'format' => NULL,
      'safe_value' => check_plain($meta['creator']),
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Владелец набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset created field.
 */
function _odp_import_dataset_set_created(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_CREATED};

  if (isset($meta['created'])) {
    // Get created in unix timestamp format.
    $created = (string) strtotime($meta['created']);

    if ($created) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'value' => $created,
        'timezone' => 'Europe/Moscow',
        'timezone_db' => 'Europe/Moscow',
        'date_type' => 'datestamp',
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $dataset_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Дата первой публикации набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата первой публикации набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset updated field.
 */
function _odp_import_dataset_set_updated(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_UPDATED};

  if (isset($meta['data'][0]['created'])) {
    // Get created in unix timestamp format.
    $created = (string) strtotime($meta['data'][0]['created']);

    if ($created) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'value' => $created,
        'timezone' => 'Europe/Moscow',
        'timezone_db' => 'Europe/Moscow',
        'date_type' => 'datestamp',
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $dataset_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Дата последнего изменения набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата последнего изменения набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset valid field.
 */
function _odp_import_dataset_set_valid(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_VALID};

  if (isset($meta['data'][0]['valid'])) {
    // Get created in unix timestamp format.
    $created = (string) strtotime($meta['data'][0]['valid']);

    if ($created) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'value' => $created,
        'timezone' => 'Europe/Moscow',
        'timezone_db' => 'Europe/Moscow',
        'date_type' => 'datestamp',
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $dataset_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Дата актуальности набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата актуальности набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset subject field.
 */
function _odp_import_dataset_set_subject(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_SUBJECT};

  if (isset($meta['subject'])) {
    // Get the new field value.
    $subjects = explode(',', $meta['subject']);
    $new_field_value = array(LANGUAGE_NONE => array());
    foreach ($subjects as $subject) {
      $subject = odp_import_load_or_create_subject_by_name(trim($subject)); //dk
      $new_field_value[LANGUAGE_NONE][] = array(
        'tid' => $subject->tid,
      );
    }

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Ключевые слова набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset publisher name field.
 */
function _odp_import_dataset_set_publisher_name(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_PUBLISHER_NAME};

  if (isset($meta['publisher']['name'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $meta['publisher']['name'],
      'format' => NULL,
      'safe_value' => check_plain($meta['publisher']['name']),
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Ответственное лицо набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset publisher phone field.
 */
function _odp_import_dataset_set_publisher_phone(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_PUBLISHER_PHONE};

  if (isset($meta['publisher']['phone'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $meta['publisher']['phone'],
      'format' => NULL,
      'safe_value' => check_plain($meta['publisher']['phone']),
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Номер телефона ответственного лица набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset publisher email field.
 */
function _odp_import_dataset_set_publisher_mbox(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_PUBLISHER_EMAIL};

  if (isset($meta['publisher']['mbox'])) {
    if (valid_email_address($meta['publisher']['mbox'])) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'email' => $meta['publisher']['mbox'],
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $dataset_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Адрес электронной почты ответственного лица набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Адрес электронной почты ответственного лица набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset resource. It requires existing dataset node.
 */
function _odp_import_dataset_set_resource(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated, &$resource_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_RESOURCES};

  // Return if data does not exist.
  if (isset($meta['data'])) {
    // Load resource node.
    if (!empty($field_value)) {
      $resource_nid = $dataset_node->{ODP_FIELD_DATASET_RESOURCES}['und'][0]['target_id'];
      $resource_node = node_load($resource_nid);
    }
    // Or create if it has not created yet.
    else {
      $resource_node = _odp_import_create_resource($dataset_node);

      $dataset_node->{ODP_FIELD_DATASET_RESOURCES}[LANGUAGE_NONE][0] = array(
        'target_id' => $resource_node->nid,
      );
      $dataset_updated = TRUE;
    }

    _odp_import_update_resource($resource_node, $meta, $dataset_node, $organization, $messages, $resource_updated);
  }
  else {
    if (empty($field_value)) {
      $dataset_node->{ODP_FIELD_DATASET_RESOURCES} = array();
    }
    $messages[] = 'Не заполнено поле "Гиперссылка на набор открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Create resource for dataset.
 */
function _odp_import_create_resource($dataset_node) {
  $resource_node = new stdClass();

  $resource_node->type = 'resource';
  node_object_prepare($resource_node);
  $resource_node->language = LANGUAGE_NONE;
  $resource_node->uid = OD_COMMON_IMPORT_USER_ID;
  $resource_node->status = NODE_PUBLISHED;
  $resource_node->promote = NODE_NOT_PROMOTED;

  $resource_node->{ODP_FIELD_RESOURCE_DATASET}[LANGUAGE_NONE][0] = array(
    'target_id' => $dataset_node->nid,
  );

  // Set opendata log variables.
  if (empty($resource_node->od_logged)) {
    $resource_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
  }

  // Save node.
  node_save($resource_node);

  return $resource_node;
}

/**
 * Update resource with data values.
 */
function _odp_import_update_resource($resource_node, $meta, $dataset_node, $organization, &$messages, &$resource_updated) {
  $revisions = odp_import_get_source_revisions($resource_node->nid);

  $revisions_created = array();
  foreach ($revisions as $revision) {
    if (empty($revision->{ODP_FIELD_RESOURCE_CREATED})) {
      continue;
    }

    $created = $revision->{ODP_FIELD_RESOURCE_CREATED}['und'][0]['value'];
    $revisions_created[$created] = $revision->vid;
  }

  foreach ($meta['data'] as $data) {
    if (empty($data['created'])) {
      continue;
    }

    $created = (string) strtotime($data['created']);

    if (!$created) {
      continue;
    }

    if (isset($revisions_created[$created])) {
      continue;
    }

    // Set resource created field.
    _odp_import_resource_set_created($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated);
    // Set resource provenance field.
    _odp_import_resource_set_provenance($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated);
    // Set resource format field.
    _odp_import_resource_set_format($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated);
    // Set resource data file field.
    _odp_import_resource_set_data($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated, $meta);
    // Set resource structure field.
    _odp_import_resource_set_structure($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated, $meta);

    // Set opendata log variables if log has not disabled.
    if (empty($resource_node->od_logged)) {
      $resource_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
    }

    if ($resource_updated) {
      $resource_node->revision = TRUE;
      node_save($resource_node);
    }

    $revisions_created[$created] = $resource_node->vid;
  }

  return $resource_node;
}

/**
 * Set resource created field.
 */
function _odp_import_resource_set_created($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{ODP_FIELD_RESOURCE_CREATED};

  if (isset($data['created'])) {
    // Get created in unix timestamp format.
    $created = (string) strtotime($data['created']);

    if ($created) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'value' => $created,
        'timezone' => 'Europe/Moscow',
        'timezone_db' => 'Europe/Moscow',
        'date_type' => 'datestamp',
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $resource_updated = TRUE;
      }
    }
    // Unreachable statement, because $data['created'] must be correct always.
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Дата создания набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  // Unreachable statement, because $data['created'] must be defined always.
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата создания набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set resource provenance field.
 */
function _odp_import_resource_set_provenance($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{ODP_FIELD_RESOURCE_PROVENANCE};

  if (isset($data['provenance'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $data['provenance'],
      'format' => NULL,
      'safe_value' => check_plain($data['provenance']),
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $resource_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Содержание изменения набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set resource format field.
 */
function _odp_import_resource_set_format($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{ODP_FIELD_RESOURCE_FORMAT};

  if (isset($data['format'])) {
    // Get format tid.
    $format = odp_import_get_format_id($data['format']);

    if ($format) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'tid' => $format,
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $resource_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Формат набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Формат набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set resource data file field.
 */
function _odp_import_resource_set_data($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated, $meta) {
  // Get the current field values.
  $field_local_value = &$resource_node->{ODP_FIELD_RESOURCE_LOCAL_DATA};
  $field_remote_value = &$resource_node->{ODP_FIELD_RESOURCE_REMOTE_DATA};

  if (isset($data['source'])) {
    $url = $data['source'];
    if (valid_url($url)) {
      // Get default values.
      $new_field_local_value = array();
      $new_field_remote_value = array();

      // Get file extension validators.
      $local_valid_extensions = _odp_import_resource_get_available_extensions(ODP_FIELD_RESOURCE_LOCAL_DATA, $url);
      $remote_valid_extensions = _odp_import_resource_get_available_extensions(ODP_FIELD_RESOURCE_REMOTE_DATA, $url);

      // Get validations.
      $local_valid = $local_valid_extensions;

      if ($local_valid) {
        // Get correct system file uri.
        $uri = odp_import_build_file_uri(ODP_IMPORT_DATA_TYPE, $data, $meta);

        if ($uri !== FALSE) {
          // Get existing opendata data file.
          $file = odp_import_load_file($uri);

          // Create file if it has not created yet.
          if (empty($file)) {
            $file = odp_import_create_local_file($uri, $url);

            if (!empty($file)) {
              $resource_node->{ODP_FIELD_RESOURCE_UTF8_ENCODING}[LANGUAGE_NONE][0]['value'] = $file->utf8;

              switch ($file->filemime) {
                case 'text/csv':
                  $file->grid = 1;
                  $delimiter = odp_detect_csv_delimiter($file->uri);
                  $resource_node->{ODP_FIELD_RESOURCE_CSV_DELIMITER}[LANGUAGE_NONE][0]['value'] = $delimiter;
                  break;
                default:
                  $resource_node->{ODP_FIELD_RESOURCE_CSV_DELIMITER} = array();
                  break;
              }
            }
          }

          if (!empty($file)) {
            $file->display = 1;
          }

          if (!empty($file)) {
            $new_field_local_value = array(LANGUAGE_NONE => array(0 => (array) $file));
          }
        }
      }

      // Get validations.
      $remote_valid = empty($new_field_local_value) && $remote_valid_extensions;

      if ($remote_valid) {
        // Get existing opendata data file.
        $file = odp_import_load_file($url);

        // Create file if it has not created yet.
        if (empty($file)) {
          $file = odp_import_create_remote_file($url);

          if (!empty($file)) {
            $resource_node->{ODP_FIELD_RESOURCE_UTF8_ENCODING} = array();
            $resource_node->{ODP_FIELD_RESOURCE_CSV_DELIMITER} = array();
          }
        }

        if (!empty($file)) {
          $file->display = 1;
        }

        if (!empty($file)) {
          $new_field_remote_value = array(LANGUAGE_NONE => array(0 => (array) $file));
        }
      }

      if (!empty($new_field_local_value) && $field_local_value !== $new_field_local_value) {
        $field_local_value = $new_field_local_value;
        $resource_updated = TRUE;
      }

      if (!empty($new_field_remote_value) && $field_remote_value !== $new_field_remote_value) {
        $field_remote_value = $new_field_remote_value;
        $resource_updated = TRUE;
      }

      if (empty($new_field_local_value) && empty($new_field_remote_value)) {
        // Set warning message.
        $messages[] = 'Некорректно заполнено поле "Гиперссылка на набор открытых данных" и/или "Гиперссылки на версии набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
      }
    }
    else {
      // Set the field default values.
      $field_local_value = array();
      $field_remote_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Гиперссылка на набор открытых данных" и/или "Гиперссылки на версии набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default values.
    $field_local_value = array();
    $field_remote_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Гиперссылка на набор открытых данных" и/или "Гиперссылки на версии набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set resource structure field.
 */
function _odp_import_resource_set_structure($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated, $meta) {
  // Get the current field values.
  $field_local_value = &$resource_node->{ODP_FIELD_RESOURCE_LOCAL_STRUCTURE};;
  $field_remote_value = &$resource_node->{ODP_FIELD_RESOURCE_REMOTE_STRUCTURE};

  if (isset($data['structure']['source'])) {
    $url = $data['structure']['source'];
    if (valid_url($url)) {
      // Get default values.
      $new_field_local_value = array();
      $new_field_remote_value = array();

      // Get the current data field values.
      $field_data_local_value = $resource_node->{ODP_FIELD_RESOURCE_LOCAL_DATA};
      $field_data_remote_value = $resource_node->{ODP_FIELD_RESOURCE_REMOTE_DATA};

      // Get file extension validators.
      $local_valid_extensions = _odp_import_resource_get_available_extensions(ODP_FIELD_RESOURCE_LOCAL_STRUCTURE, $url);
      $remote_valid_extensions = _odp_import_resource_get_available_extensions(ODP_FIELD_RESOURCE_REMOTE_STRUCTURE, $url);

      // Get validations.
      $local_valid = $local_valid_extensions && !empty($field_data_local_value);

      if ($local_valid) {
        // Get correct system file uri.
        $uri = odp_import_build_file_uri(ODP_IMPORT_STRUCTURE_TYPE, $data, $meta);

        if ($uri !== FALSE) {
          // Get existing opendata data file.
          $file = odp_import_load_file($uri);

          // Create file if it has not created yet.
          if (empty($file)) {
            $file = odp_import_create_local_file($uri, $url);
          }

          if (!empty($file)) {
            $file->display = 1;
          }

          if (!empty($file)) {
            $new_field_local_value = array(LANGUAGE_NONE => array(0 => (array) $file));
          }
        }
      }

      // Get validations.
      $remote_valid = empty($new_field_local_value) && $remote_valid_extensions && !empty($field_data_remote_value);

      if ($remote_valid) {
        // Get existing opendata data file.
        $file = odp_import_load_file($url);

        // Create file if it has not created yet.
        if (empty($file)) {
          $file = odp_import_create_remote_file($url);
        }

        if (!empty($file)) {
          $file->display = 1;
        }

        if (!empty($file)) {
          $new_field_remote_value = array(LANGUAGE_NONE => array(0 => (array) $file));
        }
      }

      if (!empty($new_field_local_value) && $field_local_value !== $new_field_local_value) {
        $field_local_value = $new_field_local_value;
        $resource_updated = TRUE;
      }

      if (!empty($new_field_remote_value) && $field_remote_value !== $new_field_remote_value) {
        $field_remote_value = $new_field_remote_value;
        $resource_updated = TRUE;
      }

      if (empty($new_field_local_value) && empty($new_field_remote_value)) {
        // Set warning message.
        $messages[] = 'Некорректно заполнено поле "Гиперссылка на структуру наборов открытых данных" и/или "Гиперссылки на версии структур наборов открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
      }
    }
    else {
      // Set the field default values.
      $field_local_value = array();
      $field_remote_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Гиперссылка на структуру наборов открытых данных" и/или "Гиперссылки на версии структур наборов открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default values.
    $field_local_value = array();
    $field_remote_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Гиперссылка на структуру наборов открытых данных" и/или "Гиперссылки на версии структур наборов открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

function _odp_import_resource_get_available_extensions($field, $url) {
  $instance = field_info_instance('node', $field, 'resource');
  $extensions = trim((string) $instance['settings']['file_extensions']);
  $extensions = explode(',', str_replace(' ', ',', $extensions));

  $extension = mb_strtolower(pathinfo($url, PATHINFO_EXTENSION));

  return in_array($extension, $extensions);
}
