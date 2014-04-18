<?php

/**
 * Implementation of hook_views_plugins().
 */
function geofield_ymap_views_plugins() {
  return array(
    'module' => 'geofield_ymap',
    'style' => array(
      'geofield_ymap' => array(
        'title' => t('Yandex Map'),
        'handler' => 'geofield_ymap_plugin_style_geofield_ymap',
        'type' => 'normal',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'uses grouping' => FALSE,
        'even empty' => TRUE,
      ),
    ),
  );
}
