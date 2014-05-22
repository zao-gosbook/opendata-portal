<?php
/**
 * @file
 * analyst_instruments.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function analyst_instruments_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any unpublished opendata_query content'.
  $permissions['view any unpublished opendata_query content'] = array(
    'name' => 'view any unpublished opendata_query content',
    'roles' => array(
      'administrator' => 'administrator',
      'analyst' => 'analyst',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
