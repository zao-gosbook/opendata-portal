<?php

/**
 * @file
 * Provide views data for modules making use of the entity CRUD API.
 */



/**
 * Implements hook_views_plugins().
 */
function cached_entity_view_views_plugins() {
  // Have views cache the table list for us so it gets
  // cleared at the appropriate times.
  $data = views_cache_get('entity_base_tables', TRUE);
  if (!empty($data->data)) {
    $base_tables = $data->data;
  }
  else {
    $base_tables = array();
    foreach (views_fetch_data() as $table => $data) {
      if (!empty($data['table']['entity type']) && !empty($data['table']['base'])) {
        $base_tables[] = $table;
      }
    }
    views_cache_set('entity_base_tables', $base_tables, TRUE);
  }
  if (!empty($base_tables)) {
    return array(
      'module' => 'cached_entity_view',
      'row' => array(
        'cached_entity_view' => array(
          'title' => t('Rendered entity using cache'),
          'help' => t('Same, as original, but uses powers of caching! Renders a single entity in a specific view mode (e.g. teaser).'),
          'handler' => 'cached_entity_view_views_plugin_row_entity_cached_view',
          'uses fields' => FALSE,
          'uses options' => TRUE,
          'type' => 'normal',
          'base' => $base_tables,
        ),
      ),
    );
  }
}