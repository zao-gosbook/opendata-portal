<?php
/**
 * @file
 * analyst_instruments.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function analyst_instruments_user_default_roles() {
  $roles = array();

  // Exported role: analyst.
  $roles['analyst'] = array(
    'name' => 'analyst',
    'weight' => 6,
  );

  return $roles;
}
