<?php

$plugin = array(
  'title' => t('Piwik report'),
  'single' => TRUE,
  'category' => t('Miscellaneous'),
  'defaults' => array('report' => ''),
);

function piwik_report_pane_piwik_report_content_type_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $block->title = !empty($conf['override_title']) ? check_plain($conf['override_title_text']) : '';
  module_load_include('inc', 'piwik_reports', 'piwik_reports.pages');
  $block->content = empty($conf['report']) ? 'Report is not selected' : drupal_get_form('piwik_reports_reports', $conf['report']);
  return $block;
}

/**
 * Edit form callback for the content type.
 */
function piwik_report_pane_piwik_report_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['report'] = array(
    '#type' => 'textfield',
    '#title' => t('Report name'),
    '#required' => TRUE,
    '#size' => 60,
    '#default_value' => isset($conf['report']) ? $conf['report'] : '',
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function piwik_report_pane_piwik_report_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Provide a summary description.
 */
function piwik_report_pane_piwik_report_content_type_summary($conf, $context) {
  return 'Piwik report: ' . check_plain($conf['report']);
}
