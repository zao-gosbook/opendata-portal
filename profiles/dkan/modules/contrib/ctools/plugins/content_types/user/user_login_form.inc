<?php

/**
 * @file
 * Plugin to handle the login form content type.
 */

$plugin = array(
  'single' => TRUE,
  'title' => t('User Login Form'),
  'icon' => 'icon_user.png',
  'description' => t('The user login form.'),
  'render callback' => 'ctools_user_login_form_content_type_render',
  'category' => t('Forms'),
);

/**
 * Outputs the login form.
 */
function ctools_user_login_form_content_type_render($subtype, $conf, $panel_args) {
  module_load_include('inc', 'user', 'user.pages');
  
  $block = new stdClass();
  $block->content = t('User Login');
  $block->content = drupal_get_form('user_login');
  return $block;
}

function ctools_user_login_form_content_type_edit_form($form, &$form_state) {
  // provide a blank form so we have a place to have context setting.
  return $form;
}
