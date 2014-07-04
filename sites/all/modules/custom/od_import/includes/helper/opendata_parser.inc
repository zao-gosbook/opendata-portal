<?php

/**
 * Parse opendata organization.
 */
function _od_import_organization_opendata($organizations) {
  // Check "Opendata API" library.
  if (!od_api()) {
    $error = 'Библиотека "Opendata API" не установлена.';
    od_log($error, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA);
    return FALSE;
  }

  // Set date format.
  $format = 'Y-m-d H:i:s';

  // Start timer.
  $time_start = date($format);

  // Get first organization.
  $organization = array_shift($organizations);

  $operations = array();

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
      $list = _od_import_meta_list($list_vars);

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
          $operations[] = array('_od_import_meta', array($meta_vars));
        }
      }
    }
  }
  else {
    $message = 'У организации "' . $organization->title . '" отсутствует ссылка на сайт организации.';
    od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $organization->nid);
  }

  if (!empty($organizations)) {
    $operations[] = array('_od_import_organization_opendata', array($organizations));
  }

  if (!empty($operations)) {
    $batch = array(
      'operations' => $operations,
      'finished' => '_od_import_batch_meta_finished',
      'file' => drupal_get_path('module', 'od_import') . '/includes/helper/opendata_parser.inc',
    );
    batch_set($batch);
    return TRUE;
  }

  return FALSE;
}

function _od_import_batch_meta_finished($success, $results) {
  // Include helper content import functions.
  require_once OD_IMPORT . '/' . 'includes/helper/opendata_import.inc';

  if (!empty($results['data'])) {
    _od_import_meta_from_data($results);
  }
}

function _od_import_meta_list($list_vars) {
  // List object.
  $od = new OdApi($list_vars['vars']);
  $meta_list = $od->getResult($list_vars['args']);

  $errors = array();
  foreach ($od->getErrors() as $error) {
    $errors[] = t($error['description']);
  }
  $errors = implode(', ', $errors);

  if (!empty($errors)) {
    $message = 'Ошибка в реестре раздела открытых данных организации "' . $list_vars['org_name'] . '": ' . $errors;
    od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $list_vars['org_nid']);
  }

  return $meta_list['meta'];
}

function _od_import_meta($meta_vars, &$context) {
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

  // Load "Opendata API" library.
  od_api();

  $od = new OdApi($meta_vars['vars']);

  // Meta object.
  $meta = $od->getResult($meta_vars['args']);

  $errors = _od_import_get_errors($od);

  if (empty($errors)) {
    OdApiHelper::clearProperties($meta);

    _od_import_publisher($od, $meta);

    _od_import_data_list($od, $meta);
  }
  else {
    if (!is_array($meta)) {
      $meta = array();
    }
    if (!isset($meta['title'])) {
      $meta['title'] = $meta_vars['meta']['title'];
    }

    $meta['#errors'] = $errors;
  }

  $context['results']['data'][] = $meta;
  return;
}

function _od_import_publisher(OdApi $od, &$meta) {
  if (!isset($meta['publisher'])) {
    return;
  }

  // Publisher object.
  $publisher_args = $meta['publisher']['#api'];
  $publisher = $od->getResult($publisher_args);

  $errors = _od_import_get_errors($od);

  if (empty($errors)) {
    $meta['publisher'] = $publisher;
    OdApiHelper::clearProperties($meta['publisher']);
  }
}

function _od_import_data_list(OdApi $od, &$meta) {
  if (!isset($meta['data'])) {
    return;
  }

  // Source object.
  $data_args = $meta['data']['#api'];
  $data_list = $od->getResult($data_args);

  $errors = _od_import_get_errors($od);

  if (empty($errors)) {
    $meta['data'] = $data_list['data'];
    OdApiHelper::clearProperties($meta['data']);

    _od_import_data($od, $meta);
  }
}

function _od_import_data(OdApi $od, &$meta) {
  if (!isset($meta['data'])) {
    return;
  }

  // Data object.
  foreach ($meta['data'] as &$data) {
    $data_args = $data['#api'];
    $data = $od->getResult($data_args);

    $errors = _od_import_get_errors($od);

    if (empty($errors)) {
      OdApiHelper::clearProperties($data);

      _od_import_structure($od, $data);
    }
  }
}

function _od_import_structure(OdApi $od, &$data) {
  if (!isset($data['structure'])) {
    return;
  }

  // Structure object.
  $structure_args = $data['structure']['#api'];
  $structure_result = $od->getResult($structure_args);

  $errors = array();
  foreach ($od->getErrors() as $error) {
    $errors[] = t($error['description']);
  }
  $errors = implode(', ', $errors);

  if (empty($errors)) {
    $data['structure'] = $structure_result;
    OdApiHelper::clearProperties($data['structure']);
  }
}

function _od_import_get_errors(OdApi $od) {
  $errors = array();
  foreach ($od->getErrors() as $error) {
    $errors[] = t($error['description']);
  }
  $errors = implode(', ', $errors);

  return $errors;
}

function _od_import_meta_from_data($results) {
  // Set date format.
  $format = 'Y-m-d H:i:s';

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
    if (isset($meta['#errors'])) {
      $message = 'Ошибка в паспорте набора открытых данных "' . $meta['title'] . '" организации "' . $results['org_name'] . '" (' . $meta['#errors'] . ').';
      od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $results['org_nid']);
      $dataset_list_failed[] = $meta['title'];
      continue;
    }

    $dataset_node = odp_load_dataset($meta['identifier']);

    $dataset_is_new = !$dataset_node ? TRUE : FALSE;

    if ($dataset_is_new) {
      $dataset_node = _od_import_create_dataset($meta, $organization);
    }

    $dataset_updated = FALSE;
    $resource_updated = FALSE;
    $dataset_node = _od_import_update_dataset($dataset_node, $meta, $organization, $dataset_updated, $resource_updated);

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

  $time_finish = date($format);

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
