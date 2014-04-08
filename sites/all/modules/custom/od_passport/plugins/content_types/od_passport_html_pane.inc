<?php

$plugin = array(
  'title' => t('Opendata passport html'),
  'single' => TRUE,
  'category' => t('Dataset'),
  'edit form' => 'od_passport_html_pane_content_type_edit_form',
  'render callback' => 'od_passport_html_pane_content_type_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'all contexts' => TRUE,
);

/**
 * 'Edit form' callback for the content type.
 */
function od_passport_html_pane_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function od_passport_html_pane_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function od_passport_html_pane_content_type_render($subtype, $conf, $args, $contexts) {
  require_once dirname(__FILE__) . '/od_passport_pane.inc';
  $html = drupal_render(od_passport_render($args[0], array('addtip' => FALSE))->content);
  $form['html_code'] = array(
    '#title' => t('Html code'),
    '#type' => 'textarea',
    '#value' => isset($html) ? $html : t('No info'),
    '#rows' => 40,
  );
  
  $block = new stdClass();
  $block->title = t('Dataset passport');
  $block->content = $form;
  
  return $block;
}

