<?php
/**
 * @file
 * opendata_requests.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function opendata_requests_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'od_query';
  $path_breadcrumb->name = 'Запрос на открытые данные';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Opendata query',
      2 => '%node:field-od-query-data-name',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'opendata-query',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'opendata_query' => 'opendata_query',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -94;
  $export['od_query'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'opendata_query';
  $path_breadcrumb->name = 'Запросы на данные';
  $path_breadcrumb->path = 'opendata-query';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Opendata query',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -98;
  $export['opendata_query'] = $path_breadcrumb;

  return $export;
}
