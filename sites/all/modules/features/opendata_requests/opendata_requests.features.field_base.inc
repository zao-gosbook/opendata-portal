<?php
/**
 * @file
 * opendata_requests.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function opendata_requests_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_od_query_organiz_exist'
  $field_bases['field_od_query_organiz_exist'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_od_query_organiz_exist',
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
        0 => 'Нет',
        1 => 'Да',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_od_query_vote_up_down'
  $field_bases['field_od_query_vote_up_down'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_od_query_vote_up_down',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'vud_field',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'votingapi_tag' => 'vote',
      'vud_widget' => 'updown',
    ),
    'translatable' => 0,
    'type' => 'vud_field',
  );

  // Exported field_base: 'field_od_user_email'
  $field_bases['field_od_user_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_od_user_email',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'email',
  );

  return $field_bases;
}
