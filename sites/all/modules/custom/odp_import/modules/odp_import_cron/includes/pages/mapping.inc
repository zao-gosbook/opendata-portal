<?php

function odp_import_cron_mapping_page() {
  $form = drupal_get_form('odp_import_cron_mapping_page_form');
  return $form;
}

function odp_import_cron_mapping_page_form($form, &$form_state) {
  $form['sites'] = array(
    '#type' => 'fieldset',
    '#tree' => TRUE,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => 'Сайты',
    '#description' => 'В заголовке указано наименование организации с сайта мониторинга государственных сайтов. Для каждой организации необходимо соответственно выбрать из списка организацию с портала открытых данных.<br />В случае установки некорректного соответствия открытые данные будут импортироваться в некорректную организацию!',
  );

  $mapping = array_flip(variable_get('odp-import-cron-mapping', array()));
  $organizations = odp_import_cron_get_organizations();
  $options = array();
  foreach ($organizations as $organization) {
    $options[$organization->nid] = $organization->title . ' (' . $organization->url . ')';
  }

  $sites = odp_import_cron_sites();
  foreach ($sites as $key => $site) {
    $form['sites'][$key] = array(
      '#type' => 'select',
      '#options' => $options,
      '#empty_value' => 0,
      '#default_value' => isset($mapping[$key]) ? $mapping[$key] : FALSE,
      '#title' => $site['name'] . ' (' . $site['site'] . ')',
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

function odp_import_cron_mapping_page_form_validate(&$form, &$form_state) {
  $values = $form_state['values']['sites'];

  $values_count = array_count_values($values);
  $message_sent = FALSE;
  foreach ($values_count as $value => $count) {
    if ($value === 0) {
      continue;
    }

    if ($count > 1) {
      while($count !== 0) {
        $key = array_search($value, $values);
        unset($values[$key]);
        form_set_error('sites][' . $key);
        $count--;
      }
      if ($message_sent === FALSE) {
        drupal_set_message('Для разных сайтов не могут сответствовать одинаковые значения.', 'error');
        $message_sent = TRUE;
      }
    }
  }
}

function odp_import_cron_mapping_page_form_submit($form, &$form_state) {
  $new_mapping = array_flip(array_filter($form_state['values']['sites']));
  $configure = variable_get('odp-import-cron-configure', array());

  $diff = array_diff_key($configure, $new_mapping);
  if (!empty($diff)) {
    $old_mapping = variable_get('odp-import-cron-mapping', array());
    foreach (array_keys($diff) as $key) {
      $sites = odp_import_cron_sites();
      $site = $sites[$old_mapping[$key]];
      drupal_set_message('Удалены настройки периодчности для сайта: ' . $site['name'] . ' (' . $site['site'] . ').');
    }
    $configure = array_diff_key($configure, $diff);
    variable_set('odp-import-cron-configure', $configure);
  }

  variable_set('odp-import-cron-mapping', $new_mapping);
  drupal_set_message('Изменения сохранены.');
}
