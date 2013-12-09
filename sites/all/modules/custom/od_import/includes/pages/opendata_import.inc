<?php

/**
 * Page callback (opendata-import).
 */
function od_import_opendata_import() {
  // Init output variable.
  $content = array();

  // Add opendata checking form.
  $content['form'] = drupal_get_form('od_import_opendata_import_form');

  // Validate opendata if url has been set. Default opendata validation script, that return result of validation.
  $content['result'] = od_import_opendata_import_result();

  return $content;
}

/**
 * Form for opendata checking.
 */
function od_import_opendata_import_form($form, &$form_state) {
  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Импортировать открытые данные',
  );

  return $form;
}

/**
 * Default form submit handler.
 */
function od_import_opendata_import_form_submit($form, &$form_state) {
  $form_state['redirect'] = url(current_path(), array('absolute' => TRUE, 'query' => array('import' => 'true')));
}

/**
 * Default opendata validation script.
 *
 * @return array
 *   Renderable array with opendata validation result.
 */
function od_import_opendata_import_result() {
  // Init output variable.
  $content = array();

  // Include Opendata API library.
  $od_library = libraries_load('od_api');
  if (!$od_library['loaded']) {
    return $content;
  }

  // Get $_GET parameters for current page.
  $query = drupal_get_query_parameters();

  if (!isset($query['import']) || $query['import'] !== 'true') {
    return $content;
  }

  // Fill table headers.
  $thead = array();
  $thead[] = array(
    'data' => 'Госорган',
  );
  $thead[] = array(
    'data' => 'Название набора',
  );
  $thead[] = array(
    'data' => 'Ссылка на набор',
  );
  $thead[] = array(
    'data' => 'Дата загрузки',
  );

  // @todo get "ФОИВ" sites.
  $sites = array(
    'http://www.mkrf.ru/',
  );

  $od = new OdApi();
  $tbody = array();
  foreach ($sites as $site) {
    // Process site argument.
    OdApiListDefault::processArg($site);

    // Get opendata for current site.
    $opendata = $od->getOpendata($site);

    // Get list
    $list = $od->objects['list'][$site];
    $all_meta = $list->objects['meta'];

    kpr($all_meta);
    kpr($opendata);

    foreach ($all_meta as $meta) {

    }

/*
    foreach ($opendata as $meta) {
      $row = array();
      $row[] = array(
        'data' => $site,
      );
      $row[] = array(
        'data' => $step['result'] ? 'Да' : 'Нет',
      );
      $row[] = array(
        'data' => implode("\n", $step['comments']),
      );
      $tbody[] = $row;
    }
*/
  }
  $content['table'] = array(
    '#theme' => 'table',
    '#header' => $thead,
    '#rows' => $tbody,
  );

  return $content;
}
