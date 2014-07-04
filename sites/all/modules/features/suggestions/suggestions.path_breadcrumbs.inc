<?php
/**
 * @file
 * suggestions.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function suggestions_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'add_suggestion';
  $path_breadcrumb->name = 'Добавление предложения';
  $path_breadcrumb->path = 'add-suggestion';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Suggestions',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'suggestions',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['add_suggestion'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'suggestion';
  $path_breadcrumb->name = 'Предложение';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Suggestions',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'suggestions',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Содержимое: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'suggestion' => 'suggestion',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['suggestion'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'suggestions';
  $path_breadcrumb->name = 'Предложения';
  $path_breadcrumb->path = 'suggestions';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Suggestions',
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
  $path_breadcrumb->weight = 0;
  $export['suggestions'] = $path_breadcrumb;

  return $export;
}
