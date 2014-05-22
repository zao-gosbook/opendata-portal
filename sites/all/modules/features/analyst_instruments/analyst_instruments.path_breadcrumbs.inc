<?php
/**
 * @file
 * analyst_instruments.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function analyst_instruments_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'analyst_opendata_queries';
  $path_breadcrumb->name = 'Аналитика - Запросы на открытые данные';
  $path_breadcrumb->path = 'user/%user/opendata-queries';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%user:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%user:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Пользователь: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['analyst_opendata_queries'] = $path_breadcrumb;

  return $export;
}
