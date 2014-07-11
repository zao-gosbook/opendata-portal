<?php
/**
 * @file
 * opendata_query.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function opendata_query_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_comment_od_query_files'
  $field_bases['field_comment_od_query_files'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_comment_od_query_files',
    'field_permissions' => array(
      'type' => 2,
    ),
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_query_state'
  $field_bases['field_query_state'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_query_state',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'discussion' => 'Поступил',
        'registred' => 'Отправлено в госорган',
        'approved' => 'Одобрено модератором',
        'rejected' => 'Отклонено',
        'answered' => 'Ответ получен',
        'produced' => 'Набор представлен',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
