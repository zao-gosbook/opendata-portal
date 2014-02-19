<?php

/**
 * @file
 * Plugin to handle the user registration form.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('User Register Form'),
  'icon' => 'icon_user.png',
  'description' => t('The new user registration form.'),
  'render callback' => 'ctools_user_register_form_content_type_render',
  'category' => t('Forms'),
);

/**
 * Outputs the user registration form.
 */
function ctools_user_register_form_content_type_render($subtype, $conf, $panel_args) {
  module_load_include('inc', 'user', 'user.pages');
  
  $block = new stdClass();
  $block->content = t('User Register');
  $block->content = drupal_get_form('user_register_form');
  return $block;
}

function ctools_user_register_form_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
