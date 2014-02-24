<?php
/**
 * @file
 * publisher_requests.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function publisher_requests_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit own publisher_request content'.
  $permissions['edit own publisher_request content'] = array(
    'name' => 'edit own publisher_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
