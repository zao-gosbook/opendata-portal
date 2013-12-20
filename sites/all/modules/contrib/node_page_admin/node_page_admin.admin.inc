<?php

/**
 * @file
 * Administration file for node_page_admin module.
 */

/**
 * Administration settings form of node_page_admin module.
 */
function node_page_admin_settings_form($form_state) {
  $form = array();
  
  $form['node_page_admin_type'] = array(
    '#title' => t('Node page administration type'),
    '#description' => t('Changes node page access behaviour.'),
    '#type' => 'select',
    '#default_value' => variable_get('node_page_admin_type', NODE_PAGE_ADMIN_CORE),
    '#options' => array(
      NODE_PAGE_ADMIN_DISABLED => t('Node page disabled'),
      NODE_PAGE_ADMIN_PERMISSION => t('Node page access by "access node page" permission'),
      NODE_PAGE_ADMIN_CORE => t('Node page access by "access content" permission'),
    )
  );
  
  // We need variables to be set before rebuilding menu router
  $form = system_settings_form($form);
  $form['#submit'][] = 'node_page_admin_settings_form_submit';
  
  return $form;
}

/**
 * Node page admin settings submition: rebuilds menu router to set the new access behaviour.
 */
function node_page_admin_settings_form_submit($form, $form_state) {
  menu_rebuild();
}
