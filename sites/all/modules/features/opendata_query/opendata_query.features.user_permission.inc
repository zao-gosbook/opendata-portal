<?php
/**
 * @file
 * opendata_query.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function opendata_query_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access rules link answered_opendata_query'.
  $permissions['access rules link answered_opendata_query'] = array(
    'name' => 'access rules link answered_opendata_query',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'access rules link approve_opendata_query'.
  $permissions['access rules link approve_opendata_query'] = array(
    'name' => 'access rules link approve_opendata_query',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'access rules link reject_opendata_query'.
  $permissions['access rules link reject_opendata_query'] = array(
    'name' => 'access rules link reject_opendata_query',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'access rules link send_to_ministry_opendata_query'.
  $permissions['access rules link send_to_ministry_opendata_query'] = array(
    'name' => 'access rules link send_to_ministry_opendata_query',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'use Rules component rules_link_set_answered_opendata_query'.
  $permissions['use Rules component rules_link_set_answered_opendata_query'] = array(
    'name' => 'use Rules component rules_link_set_answered_opendata_query',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_link_set_approve_opendata_query'.
  $permissions['use Rules component rules_link_set_approve_opendata_query'] = array(
    'name' => 'use Rules component rules_link_set_approve_opendata_query',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_link_set_reject_opendata_query'.
  $permissions['use Rules component rules_link_set_reject_opendata_query'] = array(
    'name' => 'use Rules component rules_link_set_reject_opendata_query',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_link_set_send_to_ministry_opendata_query'.
  $permissions['use Rules component rules_link_set_send_to_ministry_opendata_query'] = array(
    'name' => 'use Rules component rules_link_set_send_to_ministry_opendata_query',
    'roles' => array(),
    'module' => 'rules',
  );

  return $permissions;
}
