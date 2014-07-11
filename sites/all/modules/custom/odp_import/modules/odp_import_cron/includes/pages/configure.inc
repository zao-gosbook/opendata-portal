<?php

function odp_import_cron_configure_page() {
  $form = drupal_get_form('odp_import_cron_configure_page_form');
  return $form;
}

function odp_import_cron_configure_page_form($form, &$form_state) {
  $form['sites'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => 'Сайты',
  );

  $mapping = variable_get('odp-import-cron-mapping', array());
  $configure = variable_get('odp-import-cron-configure', array());
  $last_import = variable_get('odp-import-cron-last-import', array());

  $periods = array(
    1 * 60 * 60 * 24 => 'Ежедневно',
    1 * 60 * 60 * 24 * 7 => 'Еженедельно',
  );
  $sites = odp_import_cron_sites();
  foreach ($mapping as $key => $value) {
    $form['sites'][$key] = array(
      '#type' => 'fieldset',
      '#collapsible' => FALSE,
      '#title' => $sites[$mapping[$key]]['name'] . ' (' . $sites[$mapping[$key]]['site'] . ')',
    );

    $form['sites'][$key]['last'] = array(
      '#type' => 'markup',
      '#markup' => 'Последний запуск: '  . (isset($last_import[$key]) ? date(ODP_IMPORT_TIMER_FORMAT , $last_import[$key]) : 'никогда'),
    );
    $form['sites'][$key]['period'] = array(
      '#type' => 'select',
      '#options' => $periods,
      '#empty_value' => 0,
      '#default_value' => isset($configure[$key]) ? $configure[$key] : FALSE,
      '#title' => 'Выберите период',
    );
  }

  // Submit button.
  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

function odp_import_cron_configure_page_form_submit($form, &$form_state) {
  $values = $form_state['values']['sites'];
  foreach ($values as &$value) {
    $value = $value['period'];
  }
  variable_set('odp-import-cron-configure', array_filter($values));
  drupal_set_message('Изменения сохранены.');
}
