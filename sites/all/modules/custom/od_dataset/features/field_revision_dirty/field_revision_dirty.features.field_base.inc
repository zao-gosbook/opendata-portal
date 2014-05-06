<?php
/**
 * @file
 * field_revision_dirty.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function field_revision_dirty_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_revision_dirty'
  $field_bases['field_revision_dirty'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_revision_dirty',
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
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
