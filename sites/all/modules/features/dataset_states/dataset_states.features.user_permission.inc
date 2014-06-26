<?php
/**
 * @file
 * dataset_states.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dataset_states_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access rules link approve_dataset'.
  $permissions['access rules link approve_dataset'] = array(
    'name' => 'access rules link approve_dataset',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'access rules link send_dataset_to_rework'.
  $permissions['access rules link send_dataset_to_rework'] = array(
    'name' => 'access rules link send_dataset_to_rework',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  return $permissions;
}
