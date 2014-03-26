<?php

/**
 * Parse opendata organization.
 */
function _od_import_organization_opendata($org) {
  // Set date format.
  $format = 'Y-m-d H:i:s';

  // Start timer.
  $time_start = date($format);

  $list = _od_import_list($org);

  if (!is_array($list) || empty($list)) {
    return FALSE;
  }

  $operations = array();
  // Meta object.
  foreach ($list as $meta) {
    $meta_args = $meta['#api'];
    $operations[] = array('_od_import_meta', array($meta_args, $org->nid, $time_start));
  }

  $batch = array(
    'title' => t('Import meta'),
    'operations' => $operations,
    'finished' => '_od_import_batch_meta_finished',
    'file' => drupal_get_path('module', 'od_import') . '/includes/helper/opendata_parser.inc',
  );

  batch_set($batch);
  batch_process();

  return TRUE;
}

function _od_import_batch_meta_finished($success, $results, $operations) {
  // Include helper content import functions.
  require_once OD_IMPORT . '/' . 'includes/helper/opendata_import.inc';

  _od_import_meta_from_data($results['data'], $results['org'], $results['time_start']);
}

function _od_import_list($org) {
  // Get organization url.
  if (empty($org->field_site_url[LANGUAGE_NONE][0])) {
    $message = 'У организации отсутствует ссылка на сайт.';
    od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $org->nid);
    return FALSE;
  }

  // Define variables for opendata API library.
  $vars = array();

  // Get organization opendata site url.
  if (!empty($org->field_opendata_portal_url[LANGUAGE_NONE][0]['url'])) {
    $opendata_site_url = $org->field_opendata_portal_url[LANGUAGE_NONE][0]['url'];
  }
  else {
    $opendata_site_url = $org->field_site_url[LANGUAGE_NONE][0]['url'];
  }

  // Get organization opendata page url.
  if (!empty($org->field_opendata_page_url[LANGUAGE_NONE][0]['value'])) {
    $vars['semantic_list_url'] = $org->field_opendata_page_url[LANGUAGE_NONE][0]['value'];
  }

  // Set list args.
  $list_args = array('list' => $opendata_site_url);

  // Remove time limit execution script.
  set_time_limit(0);

  // List object.
  $od = new OdApi($vars);
  $list_result = $od->getResult($list_args);

  // Restore default time limit execution script.
  set_time_limit(ini_get('max_execution_time'));

  $errors = array();
  foreach ($od->getErrors() as $error) {
    $errors[] = t($error['description']);
  }
  $errors = implode(', ', $errors);

  if (!empty($errors)) {
    $message = 'Ошибка в реестре раздела открытых данных организации: ' . $errors;
    od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $org->nid);
  }

  return $list_result['meta'];
}

function _od_import_meta_init(&$context, $org_nid, $time_start) {
  if (!isset($context['results']['data'])) {
    $context['results']['data'] = array();
  }

  if (!isset($context['results']['org'])) {
    $context['results']['org'] = $org_nid;
  }

  if (!isset($context['results']['time_start'])) {
    $context['results']['time_start'] = $time_start;
  }
}

function _od_import_meta($meta_args, $org_nid, $time_start, &$context) {
  // Load "Opendata API" library.
  libraries_load('od_api');

  _od_import_meta_init($context, $org_nid, $time_start);

  // Remove time limit execution script.
  set_time_limit(0);

  $od = new OdApi();

  // Meta object.
  $meta = $od->getResult($meta_args);

  $errors = _od_import_get_errors($od);

  if (empty($errors)) {
    unset($meta['#version']);

    _od_import_publisher($od, $meta);

    _od_import_source($od, $meta);
  }
  else {
    if (!is_array($meta)) {
      $meta = array();
    }

    $meta['#errors'] = $errors;
  }

  // Restore default time limit execution script.
  set_time_limit(ini_get('max_execution_time'));

  $context['results']['data'][] = $meta;
  return;
}

function _od_import_publisher(OdApi $od, &$meta) {
  // Publisher object.
  $publisher_args = $meta['publisher']['#api'];
  $publisher = $od->getResult($publisher_args);

  $errors = _od_import_get_errors($od);

  if (empty($errors)) {
    $meta['publisher'] = $publisher;
    unset($meta['publisher']['#version']);
  }
}

function _od_import_source(OdApi $od, &$meta) {
  $meta['data'] = $meta['source'];
  unset($meta['source']);

  // Source object.
  $source_args = $meta['data']['#api'];
  $source = $od->getResult($source_args);

  $errors = _od_import_get_errors($od);

  if (empty($errors)) {
    $meta['data'] = $source['data'];
    unset($source['data']['#version']);

    _od_import_data($od, $meta);
  }
}

function _od_import_data(OdApi $od, &$meta) {
  // Data object.
  foreach ($meta['data'] as &$data) {
    $data_args = $data['#api'];
    $data = $od->getResult($data_args);

    $errors = _od_import_get_errors($od);

    if (empty($errors)) {
      unset($data['#version']);

      _od_import_structure($od, $data);
    }
  }
}

function _od_import_structure(OdApi $od, &$data) {
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
    unset($data['structure']['#version']);
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

function _od_import_meta_from_data($data, $org_nid, $time_start) {
  // Get organization object.
  $org = node_load($org_nid);

  // Set date format.
  $format = 'Y-m-d H:i:s';

  $meta_added_count = 0;
  $meta_actualized_count = 0;
  $meta_updated_count = 0;
  $meta_existed_count = 0;
  $meta_failed_count = 0;

  $dataset_list_added = array();
  $dataset_list_actualized = array();
  $dataset_list_updated = array();
  $dataset_list_failed = array();
  foreach ($data as $meta) {
    // Skip opendata meta with error.
    if (isset($meta['#errors'])) {
      if (isset($meta['title'])) {
        $message = 'Ошибка в паспорте набора "' . $meta['title'] . '" открытых данных (' . $meta['#errors'] . ').';
      }
      else {
        $message = 'Ошибка в паспорте набора открытых данных (' . $meta['#errors'] . '), набор не идентифицирован.';
      }
      od_log($message, OD_LOG_IMPORTANCE_ERROR, OD_LOG_EVENT_IMPORT_DATA, $org_nid);
      $meta_failed_count++;
      $dataset_list_failed[] = $meta['title'];
      continue;
    }

    $identifier = $meta['identifier'];
    $dataset_node = od_import_load_dataset($identifier);

    $dataset_is_new = !$dataset_node ? TRUE : FALSE;

    if ($dataset_is_new) {
      $dataset_node = _od_import_create_dataset($identifier, $org_nid);
    }

    $dataset_updated = FALSE;
    $resource_updated = FALSE;
    $dataset_node = _od_import_update_dataset($dataset_node, $meta, $org->nid, $dataset_updated, $resource_updated);

    if ($dataset_is_new) {
      $meta_added_count++;
      $dataset_list_added[] = l($dataset_node->title, 'node/' . $dataset_node->nid);
    }
    else {
      if ($resource_updated || $dataset_updated) {
        if ($resource_updated) {
            $meta_actualized_count++;
            $dataset_list_actualized[] = l($dataset_node->title, 'node/' . $dataset_node->nid);
        }
        if ($dataset_updated) {
          $meta_updated_count++;
          $dataset_list_updated[] = l($dataset_node->title, 'node/' . $dataset_node->nid);
        }
      }
      else {
        $meta_existed_count++;
      }
    }
  }

  $dataset_list_added = implode('<br />', $dataset_list_added);
  $dataset_list_actualized = implode('<br />', $dataset_list_actualized);
  $dataset_list_updated = implode('<br />', $dataset_list_updated);
  $dataset_list_failed = implode('<br />', $dataset_list_failed);

  $time_finish = date($format);

  $message = <<<'MESSAGE'
Обработан реестр наборов открытых данных организации %org_name.<br />
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

  $timer = 'Время начало обработки: ' . $time_start . '. Время завершения обработки: ' . $time_finish . '.<br />';
  $meta_added_count = 'Количество новых загруженных наборов: ' . $meta_added_count . '.<br />';
  $meta_actualized_count = 'Количество актуализированных наборов: ' . $meta_actualized_count . '.<br />';
  $meta_updated_count = 'Количество обновленных наборов: ' . $meta_updated_count . '.<br />';
  $meta_existed_count = 'Количество не измененных наборов: ' . $meta_existed_count . '.<br />';
  $meta_failed_count = 'Количество наборов содержащих ошибки: ' . $meta_failed_count . '.<br />';
  $dataset_list_added = $dataset_list_added ? ('Список загруженных наборов:<br />' . $dataset_list_added . '.<br />') : '';
  $dataset_list_actualized = $dataset_list_actualized ? ('Список актуализированных наборов:<br />' . $dataset_list_actualized . '.<br />') : '';
  $dataset_list_updated = $dataset_list_updated ? ('Список обновленных наборов:<br />' . $dataset_list_updated . '.<br />') : '';
  $dataset_list_failed = $dataset_list_failed ? ('Список наборов содержащих ошибки:<br />' . $dataset_list_failed . '.<br />') : '';

  $args = array(
    '%org_name' => $org->title,
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

  od_log($message, OD_LOG_IMPORTANCE_STATUS, OD_LOG_EVENT_IMPORT_DATA, $org_nid);

  return TRUE;
}
