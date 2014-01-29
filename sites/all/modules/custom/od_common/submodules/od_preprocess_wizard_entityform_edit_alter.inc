<?php
/**
 * @file
 */

/**
 * Implements hook_form_FORM_ID_alter()
 */
function _od_common_form_od_preprocess_wizard_entityform_edit_form_alter(&$form, &$form_state) {
  if (drupal_match_path($_GET['q'], 'file/ajax/field_od_wizard_upload_file/*/*/*') && !empty($form_state['values']['field_od_wizard_upload_file'][LANGUAGE_NONE]['0']['fid'])) {
    $file = file_load($form_state['values']['field_od_wizard_upload_file'][LANGUAGE_NONE]['0']['fid']);
    od_common_module('core');
    if ($file && ($extension = pathinfo($file->uri, PATHINFO_EXTENSION)) && ($ext_term = od_common_file_get_extension_term($extension))) {
      $commands = array();
      $commands[] = ajax_command_setval('.'. implode('.', $form['field_format']['#attributes']['class']).' select', $ext_term->tid);
      od_common_static_storage('catch_delievery', $commands);
    }
  }
}

function _od_common_page_delivery_callback_alter(&$callback) {
  od_common_module('core');
  if (od_common_static_storage('catch_delievery')) {
    $callback = '_od_common_page_ajax_delivery_callback';
  }
}

function _od_common_page_ajax_delivery_callback($page_result) {
  $commands = od_common_static_storage('catch_delievery', NULL, TRUE);
  $page_result['#commands'] = array_merge($page_result['#commands'], $commands);
  return ajax_deliver($page_result);
}