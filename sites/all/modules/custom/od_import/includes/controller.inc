<?php

/**
 * Action callback. Import opendata from organizations.
 */
function od_import_import_organizations_opendata($entities) {
  foreach ($entities as $entity) {
    od_import_import_organization_opendata($entity);
  }
}

/**
 * Parse opendata organization.
 */
function od_import_import_organization_opendata($org) {
  // Get organization title.
  $org_name = $org->title;

  $od_library = libraries_load('od_api');
  if (!$od_library['loaded']) {
    $message = 'Ошибка обработки реестра наборов открытых данных организации %org_name: %error.';

    $error = 'Внутренняя ошибка - библиотека "Opendata API" не установлена.';
    $message = format_string($message, array('%org_name' => $org_name, '%error' => $error));

    drupal_set_message($message, 'warning');
    watchdog('od_import', $message, array(), WATCHDOG_WARNING);
    return FALSE;
  }

  // Get organization url.
  if (empty($org->field_site_url[LANGUAGE_NONE][0])) {
    $message = 'Ошибка обработки реестра наборов открытых данных организации %org_name: %error.';

    $error = 'Ошибка организации - у организации отсутствует ссылка на сайт.';
    $message = format_string($message, array('%org_name' => $org_name, '%error' => $error));

    drupal_set_message($message, 'warning');
    watchdog('od_import', $message, array(), WATCHDOG_WARNING);
    return FALSE;
  }

  // Set date format.
  $format = 'Y-m-d H:i:s';

  // Get organization url.
  $org_url = $org->field_site_url[LANGUAGE_NONE][0]['url'];

  $time_start = date($format);
  $od = new OdApi();
  $data = $od->getOpendata($org_url);

  $errors = $od->getErrors();

  if (!empty($errors)) {
    $error = reset($errors);
    $error = 'Ошибка открытых данных - ' . mb_strtolower($error['description']);
  }

  if (!empty($error) && !is_array($data)) {
    $message = 'Ошибка обработки реестра наборов открытых данных организации %org_name: %error.';
    $message = format_string($message, array('%org_name' => $org_name, '%error' => $error));

    drupal_set_message($message, 'warning');
    watchdog('od_import', $message, array(), WATCHDOG_WARNING);
    return FALSE;
  }

  $meta_added_count = 0;
  $meta_updated_count = 0;
  $meta_existed_count = 0;
  $dataset_list = array();
  foreach ($data as $meta) {
    $identifier = $meta['identifier'];

    $dataset_node = od_import_load_dataset($identifier);

    $meta_node = od_import_load_or_create_dataset($identifier, $meta, $org->nid, $dataset_node, $updated);

    if (!$dataset_node) {
      $meta_added_count++;
      $dataset_list[] = l($meta_node->title, 'node/' . $meta_node->nid);
    }
    else {
      if ($updated) {
        $meta_updated_count++;
      }
      else {
        $meta_existed_count++;
      }
    }
  }
  $dataset_list = implode('<br />', $dataset_list);

  $time_finish = date($format);

  $message = <<<'MESSAGE'
Обработан реестр наборов открытых данных организации %org_name.<br />
Время начало обработки: %time_start. Время завершения обработки: %time_finish.<br />
Количество новых загруженных наборов: %meta_added_count.<br />
Количество актуализированных наборов: %meta_updated_count.<br />
Количество ранее загруженных наборов: %meta_existed_count.<br />
Список загруженных наборов:<br />
!dataset_list.
MESSAGE;

  $args = array(
    '%org_name' => $org_name,
    '%time_start' => $time_start,
    '%time_finish' => $time_finish,
    '%meta_added_count' => $meta_added_count,
    '%meta_updated_count' => $meta_updated_count,
    '%meta_existed_count' => $meta_existed_count,
    '!dataset_list' => $dataset_list,
  );
  $message = format_string($message, $args);

  drupal_set_message($message);
  watchdog('od_import', $message, array(), WATCHDOG_INFO);

  return TRUE;
}

function od_import_load_or_create_dataset($identifier, $meta, $org_id, $dataset_node = FALSE, &$updated = FALSE) {
  $is_new = !$dataset_node;

  if ($is_new) {
    $dataset_node = new stdClass();

    $dataset_node->type = 'dataset';
    node_object_prepare($dataset_node);
    $dataset_node->language = LANGUAGE_NONE;
    $dataset_node->uid = OD_IMPORT_USER_ID;
    $dataset_node->promote = NODE_NOT_PROMOTED;
    $dataset_node->comment = COMMENT_NODE_OPEN;

    // Meta identifier.
    $dataset_node->{OD_IMPORT_FIELD_META_IDENTIFIER}[LANGUAGE_NONE][0] = array(
      'value' => $identifier,
      'format' => NULL,
      'save_value' => $identifier,
    );

    // Meta owner.
    $dataset_node->{OD_IMPORT_FIELD_META_OWNER}[LANGUAGE_NONE][0] = array(
      'target_id' => $org_id,
    );
  }

  $dataset_node->status = NODE_NOT_PUBLISHED;
  $dataset_node->title = $meta['title'];

  // Meta description.
  $dataset_node->{OD_IMPORT_FIELD_META_DESCRIPTION}[LANGUAGE_NONE][0] = array(
    'value' => $meta['description'],
    'summary' => '',
    'format' => 'full_html',
    'save_value' => $meta['description'],
    'safe_summary' => '',
  );

  // Meta created.
  $dataset_node->{OD_IMPORT_FIELD_META_CREATED}[LANGUAGE_NONE][0] = array(
    'value' => od_import_format_date_unix_timestamp($meta['created']),
    'timezone' => 'Europe/Moscow',
    'timezone_db' => 'Europe/Moscow',
    'date_type' => 'datestamp',
  );

  // Meta updated.
  $dataset_node->{OD_IMPORT_FIELD_META_UPDATED} = array();
  if (isset($meta['data'][0])) {
    $dataset_node->{OD_IMPORT_FIELD_META_UPDATED}[LANGUAGE_NONE][0] = array(
      'value' => od_import_format_date_unix_timestamp($meta['data'][0]['created']),
      'timezone' => 'Europe/Moscow',
      'timezone_db' => 'Europe/Moscow',
      'date_type' => 'datestamp',
    );
  }

  // Meta provenance.
  $dataset_node->{OD_IMPORT_FIELD_META_PROVENANCE} = array();
  if (isset($meta['data'][0])) {
    $dataset_node->{OD_IMPORT_FIELD_META_PROVENANCE}[LANGUAGE_NONE][0] = array(
      'value' => $meta['data'][0]['provenance'],
      'format' => NULL,
      'save_value' => $meta['data'][0]['provenance'],
    );
  }

  // Publisher subject.
  $subjects = explode(',', $meta['subject']);
  $dataset_node->{OD_IMPORT_FIELD_META_SUBJECT}[LANGUAGE_NONE] = array();
  foreach ($subjects as $subject) {
    $subject = od_import_load_or_create_subject_by_name(trim($subject));
    $dataset_node->{OD_IMPORT_FIELD_META_SUBJECT}[LANGUAGE_NONE][] = array(
      'tid' => $subject->tid,
    );
  }

  // Publisher name.
  $dataset_node->{OD_IMPORT_FIELD_PUBLISHER_NAME}[LANGUAGE_NONE][0] = array(
    'value' => $meta['publisher']['name'],
    'format' => NULL,
    'save_value' => $meta['publisher']['name'],
  );

  // Publisher phone.
  $dataset_node->{OD_IMPORT_FIELD_PUBLISHER_PHONE}[LANGUAGE_NONE][0] = array(
    'value' => $meta['publisher']['phone'],
    'format' => NULL,
    'save_value' => $meta['publisher']['phone'],
  );

  // Publisher email.
  $dataset_node->{OD_IMPORT_FIELD_PUBLISHER_EMAIL}[LANGUAGE_NONE][0] = array(
    'email' => $meta['publisher']['mbox'],
  );

  // Save dataset.
  if ($is_new) {
    node_save($dataset_node);
  }

  // Add resource to dataset. It requires existing dataset node with node ID.
  od_import_source_set_resource($dataset_node, $meta, $is_new, $updated);

  // Update dataset.
  node_save($dataset_node);

  return $dataset_node;
}

/**
 * Add resource to dataset. It requires existing dataset node with node ID.
 */
function od_import_source_set_resource(&$meta_node, $meta, $is_new, &$updated = FALSE) {
  $resource = od_import_load_or_create_resource($meta_node, $meta, $is_new, $updated);

  $meta_node->{OD_IMPORT_FIELD_META_RESOURCES} = array();
  if ($resource) {
    $meta_node->{OD_IMPORT_FIELD_META_RESOURCES}[LANGUAGE_NONE][0] = array(
      'target_id' => $resource->nid,
    );
  }
}

function od_import_load_or_create_resource($meta_node, $meta, $is_new, &$updated = FALSE) {
  // Init output variable.
  $resource_node = FALSE;

  // Return if data does not exist.
  if (empty($meta['data'])) {
    return $resource_node;
  }

  // Return if meta node does not exist.
  if (empty($meta_node->nid)) {
    return $resource_node;
  }

  if ($is_new) {
    $resource_node = new stdClass();

    $resource_node->title = $meta['title'];
    $resource_node->type = 'resource';
    node_object_prepare($resource_node);
    $resource_node->language = LANGUAGE_NONE;
    $resource_node->uid = OD_IMPORT_USER_ID;
    $resource_node->status = NODE_PUBLISHED;
    $resource_node->promote = NODE_NOT_PROMOTED;
    $resource_node->comment = COMMENT_NODE_OPEN;

    $resource_node->field_dataset_ref[LANGUAGE_NONE][0] = array(
      'target_id' => $meta_node->nid,
    );

    node_save($resource_node);

    $revisions = array();
  }
  else {
    $resource_nid = $meta_node->field_resources['und'][0]['target_id'];

    $resource_node = node_load($resource_nid);

    $revisions = od_import_get_source_revisions($resource_nid);

    $revisions_created = array();
    foreach ($revisions as $revision) {
      $created = $revision->{OD_IMPORT_FIELD_RESOURCE_CREATED}['und'][0]['value'];
      $revisions_created[$created] = $revision->vid;
    }
  }

  foreach ($meta['data'] as $data) {
    $created = od_import_format_date_unix_timestamp($data['created']);

    if (isset($revisions_created[$created])) {
      continue;
    }

    $updated = TRUE;

    if (!empty($revisions)) {
      $resource_node->revision = TRUE;
    }

    // Set created field.
    od_import_source_set_created($resource_node, $data);
    // Set provenance field.
    od_import_source_set_provenance($resource_node, $data);
    // Set format field.
    od_import_source_set_format($resource_node, $data);
    // Set data file field.
    od_import_source_set_data($resource_node, $meta, $data);
    // Set structure field.
    od_import_source_set_structure($resource_node, $meta, $data);

    node_save($resource_node);
  }

  return $resource_node;
}

function od_import_source_set_created(&$source_node, $data) {
  // Set opendata created to source node.
  $source_node->{OD_IMPORT_FIELD_RESOURCE_CREATED} = array();
  $source_node->{OD_IMPORT_FIELD_RESOURCE_CREATED}[LANGUAGE_NONE][0] = array(
    'value' => od_import_format_date_unix_timestamp($data['created']),
    'timezone' => 'Europe/Moscow',
    'timezone_db' => 'Europe/Moscow',
    'date_type' => 'datestamp',
  );
}

function od_import_source_set_provenance(&$source_node, $data) {
  // Set opendata created to source node.
  $source_node->{OD_IMPORT_FIELD_RESOURCE_PROVENANCE} = array();
  $source_node->{OD_IMPORT_FIELD_RESOURCE_PROVENANCE}[LANGUAGE_NONE][0] = array(
    'value' => $data['provenance'],
    'format' => NULL,
    'save_value' => $data['provenance'],
  );
}

function od_import_source_set_format(&$source_node, $data) {
  // Get opendata format.
  $format = od_import_get_format_id($data['format']);

  // Set opendata format to source node.
  $source_node->{OD_IMPORT_FIELD_RESOURCE_FORMAT} = array();
  if ($format) {
    $source_node->{OD_IMPORT_FIELD_RESOURCE_FORMAT}[LANGUAGE_NONE][0] = array(
      'tid' => $format,
    );
  }
}

function od_import_source_set_data(&$source_node, $meta, $data) {
  // Get file uri.
  $uri = od_import_build_file_uri(OD_IMPORT_DATA_TYPE, $meta, $data);

  // Get origin uri.
  $origin_uri = $data['source'];

  // Get opendata data file.
  $file = od_import_load_or_create_file($uri, $origin_uri);

  // Set opendata data file to source node.
  $source_node->{OD_IMPORT_FIELD_RESOURCE_DATA} = array();
  if ($file) {
    $file->display = 1;
    $file->grid = 1;
    $file->graph = 1;
    $file->map = 1;
    $source_node->{OD_IMPORT_FIELD_RESOURCE_DATA}[LANGUAGE_NONE][0] = (array) $file;
  }
}

function od_import_source_set_structure(&$source_node, $meta, $data) {
  // Get file uri.
  $uri = od_import_build_file_uri(OD_IMPORT_STRUCTURE_TYPE, $meta, $data);

  // Get origin uri.
  $origin_uri = $data['structure']['source'];

  // Get opendata structure file.
  $file = od_import_load_or_create_file($uri, $origin_uri);

  // Set opendata structure file to source node.
  $source_node->{OD_IMPORT_FIELD_RESOURCE_STRUCTURE} = array();
  if ($file) {
    $file->display = 1;
    $source_node->{OD_IMPORT_FIELD_RESOURCE_STRUCTURE}[LANGUAGE_NONE][0] = (array) $file;
  }
}

function od_import_get_subject_id($subject) {
  return od_import_get_term_id_by_name(strtolower($subject), OD_IMPORT_VOCABULARY_SUBJECTS);
}

function od_import_get_format_id($format) {
  return od_import_get_term_id_by_name(strtolower($format), OD_IMPORT_VOCABULARY_FORMATS);
}

function od_import_get_term_id_by_name($name, $vocabulary) {
  // Get terms by name.
  $terms = taxonomy_get_term_by_name($name, $vocabulary);

  return !empty($terms) ? reset($terms)->tid : FALSE;
}

function od_import_get_file_by_uri($uri) {
  $conditions = array('uri' => trim($uri));

  return file_load_multiple(array(), $conditions);
}

function od_import_load_or_create_subject_by_name($name) {
  $subject_id = od_import_get_subject_id($name);

  if ($subject_id) {
    $subject = taxonomy_term_load($subject_id);
  }

  if (empty($subject)) {
    $subject = new stdClass();
    $subject->name = $name;
    $subject->vid = OD_IMPORT_VOCABULARY_SUBJECTS_ID;
    taxonomy_term_save($subject);
  }

  return $subject;
}

function od_import_load_or_create_file($uri, $origin_uri) {
  if (!file_valid_uri($uri)) {
    return FALSE;
  }

  // Get file by url.
  $files = od_import_get_file_by_uri($uri);
  $file = !empty($files) ? reset($files) : FALSE;

  if (empty($file)) {
    file_prepare_directory(drupal_dirname($uri), FILE_CREATE_DIRECTORY);

    $file_content = od_import_get_url_content($origin_uri);
    $file = file_save_data($file_content, $uri);

    $file->uid = OD_IMPORT_USER_ID;
    file_save($file);
  }

  return $file;
}

function od_import_get_url_content($url) {
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_URL, $url);
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($curl, CURLOPT_FRESH_CONNECT, 1);
  curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);

  $content = curl_exec($curl);

  $result = curl_getinfo($curl, CURLINFO_HTTP_CODE) < 400;

  curl_close($curl);

  return $result ? $content : FALSE;
}

function od_import_build_file_uri($type, $meta, $data) {
  switch ($type) {
    case OD_IMPORT_STRUCTURE_TYPE:
      $origin_uri = $data['structure']['source'];
      $structure_created = od_import_format_date_iso_url($data['structure']['created']);
      $name = 'structure-' . $structure_created;
      break;
    case OD_IMPORT_DATA_TYPE:
      $origin_uri = $data['source'];
      $data_created = od_import_format_date_iso_url($data['created']);
      $structure_created = od_import_format_date_iso_url($data['structure']['created']);
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

  return $uri;
}

function od_import_format_date_iso_url($created) {
  $date = new DateTime($created);
  return strtolower($date->format('Y-m-d\TH-i-s'));
}

function od_import_format_date_unix_timestamp($created) {
  $date = new DateTime($created);
  return $date->getTimestamp();
}

function od_import_load_dataset($identifier) {
  $node = FALSE;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'dataset');
  $query->fieldCondition('field_dataset_id', 'value', $identifier);
  $query->range(0, 1);
  $query->addMetaData('account', user_load(1));
  $result = $query->execute();
  if (isset($result['node'])) {
    $query_node = reset($result['node']);
    $node = node_load($query_node->nid);
  }

  return $node;
}

function od_import_get_source_revisions($nid) {
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
