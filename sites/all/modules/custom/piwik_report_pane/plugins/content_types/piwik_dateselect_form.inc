<?php

$plugin = array(
  'title' => t('Piwik date select form'),
  'single' => TRUE,
  'category' => t('Miscellaneous'),
  'defaults' => array('report' => ''),
);

function piwik_report_pane_piwik_dateselect_form_content_type_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $block->title = !empty($conf['override_title']) ? check_plain($conf['override_title_text']) : '';
  module_load_include('inc', 'piwik_reports', 'piwik_reports.pages');
  $block->content = drupal_get_form('piwik_reports_dateselect_form');
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function piwik_report_pane_piwik_dateselect_form_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function piwik_report_pane_piwik_dateselect_form_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Provide a summary description.
 */
function piwik_report_pane_piwik_dateselect_form_content_type_summary($conf, $context) {
  return 'Piwik date select form';
}

if (!function_exists('piwik_reports_dateselect_form_submit')) {
  function piwik_reports_dateselect_form_submit($form, &$form_state) {
    $_SESSION['piwik_reports_period'] = $form_state['values']['period'];
  }
}
