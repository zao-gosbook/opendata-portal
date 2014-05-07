<?php
/**
 * @file
 * field_revision_dirty.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function field_revision_dirty_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-dataset-field_revision_dirty'
  $field_instances['node-dataset-field_revision_dirty'] = array(
    'bundle' => 'dataset',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'list_default',
        'weight' => 26,
      ),
      'table' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_revision_dirty',
    'label' => 'Dirty revision',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 34,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Dirty revision');

  return $field_instances;
}
