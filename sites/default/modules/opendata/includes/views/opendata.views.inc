<?php

/**
 * Implements hook_views_plugins().
 */
function opendata_views_plugins() {
  // Init output variable.
  $views_plugins = array(
    'module' => 'opendata',
    'style' => array(),
  );

  // Define opendata list table plugin.
  $views_plugins['style']['opendata_list_table'] = array(
    'title' => t('Opendata list table'),
    'help' => t('Displays rows in a opendata list table.'),
    'handler' => 'opendata_views_plugin_style_opendata_table',
    'path' => drupal_get_path('module', 'opendata') . '/includes/views/plugins',
    'theme' => 'opendata_views_plugin_style_opendata_table',
    'theme path' => drupal_get_path('module', 'opendata') . '/includes/views/theme',
    'theme file' => 'theme.inc',
    'type' => 'normal',
    'uses row plugin' => FALSE,
    'uses row class' => FALSE,
    'uses fields' => FALSE,
    'uses options' => FALSE,
    'uses grouping' => FALSE,
    'even empty' => FALSE,
  );

  return $views_plugins;
}
