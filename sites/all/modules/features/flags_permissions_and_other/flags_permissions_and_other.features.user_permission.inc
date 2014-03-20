<?php
/**
 * @file
 * flags_permissions_and_other.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function flags_permissions_and_other_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access node page'.
  $permissions['access node page'] = array(
    'name' => 'access node page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node_page_admin',
  );

  // Exported permission: 'access piwik reports'.
  $permissions['access piwik reports'] = array(
    'name' => 'access piwik reports',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'piwik_reports',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access resource better_watchdog_ui_watchdog'.
  $permissions['access resource better_watchdog_ui_watchdog'] = array(
    'name' => 'access resource better_watchdog_ui_watchdog',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource comment'.
  $permissions['access resource comment'] = array(
    'name' => 'access resource comment',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource entity_rule_setting'.
  $permissions['access resource entity_rule_setting'] = array(
    'name' => 'access resource entity_rule_setting',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource entityform'.
  $permissions['access resource entityform'] = array(
    'name' => 'access resource entityform',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource entityform_type'.
  $permissions['access resource entityform_type'] = array(
    'name' => 'access resource entityform_type',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource file'.
  $permissions['access resource file'] = array(
    'name' => 'access resource file',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource flagging'.
  $permissions['access resource flagging'] = array(
    'name' => 'access resource flagging',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource i18n_translation'.
  $permissions['access resource i18n_translation'] = array(
    'name' => 'access resource i18n_translation',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource log'.
  $permissions['access resource log'] = array(
    'name' => 'access resource log',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource node'.
  $permissions['access resource node'] = array(
    'name' => 'access resource node',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource privatemsg_message'.
  $permissions['access resource privatemsg_message'] = array(
    'name' => 'access resource privatemsg_message',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource rules_config'.
  $permissions['access resource rules_config'] = array(
    'name' => 'access resource rules_config',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource rules_link'.
  $permissions['access resource rules_link'] = array(
    'name' => 'access resource rules_link',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource search_api_index'.
  $permissions['access resource search_api_index'] = array(
    'name' => 'access resource search_api_index',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource search_api_server'.
  $permissions['access resource search_api_server'] = array(
    'name' => 'access resource search_api_server',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource search_api_sort'.
  $permissions['access resource search_api_sort'] = array(
    'name' => 'access resource search_api_sort',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource taxonomy_term'.
  $permissions['access resource taxonomy_term'] = array(
    'name' => 'access resource taxonomy_term',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource taxonomy_vocabulary'.
  $permissions['access resource taxonomy_vocabulary'] = array(
    'name' => 'access resource taxonomy_vocabulary',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource typo'.
  $permissions['access resource typo'] = array(
    'name' => 'access resource typo',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource universal_data_storage'.
  $permissions['access resource universal_data_storage'] = array(
    'name' => 'access resource universal_data_storage',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource user'.
  $permissions['access resource user'] = array(
    'name' => 'access resource user',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access resource wysiwyg_profile'.
  $permissions['access resource wysiwyg_profile'] = array(
    'name' => 'access resource wysiwyg_profile',
    'roles' => array(),
    'module' => 'restws',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access rules link approve_publisher_request'.
  $permissions['access rules link approve_publisher_request'] = array(
    'name' => 'access rules link approve_publisher_request',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'access rules link on_completion_publisher_request'.
  $permissions['access rules link on_completion_publisher_request'] = array(
    'name' => 'access rules link on_completion_publisher_request',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'access rules link reject_publisher_request'.
  $permissions['access rules link reject_publisher_request'] = array(
    'name' => 'access rules link reject_publisher_request',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access statistics'.
  $permissions['access statistics'] = array(
    'name' => 'access statistics',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'access typo list'.
  $permissions['access typo list'] = array(
    'name' => 'access typo list',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'typo',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access vote up/down statistics'.
  $permissions['access vote up/down statistics'] = array(
    'name' => 'access vote up/down statistics',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'access workflow summary views'.
  $permissions['access workflow summary views'] = array(
    'name' => 'access workflow summary views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow_views',
  );

  // Exported permission: 'add terms in format'.
  $permissions['add terms in format'] = array(
    'name' => 'add terms in format',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in forums'.
  $permissions['add terms in forums'] = array(
    'name' => 'add terms in forums',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in organization_type'.
  $permissions['add terms in organization_type'] = array(
    'name' => 'add terms in organization_type',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in rubrics'.
  $permissions['add terms in rubrics'] = array(
    'name' => 'add terms in rubrics',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in tags'.
  $permissions['add terms in tags'] = array(
    'name' => 'add terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer CAPTCHA settings'.
  $permissions['administer CAPTCHA settings'] = array(
    'name' => 'administer CAPTCHA settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'administer RDF field mappings'.
  $permissions['administer RDF field mappings'] = array(
    'name' => 'administer RDF field mappings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rdfui',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer addtoany'.
  $permissions['administer addtoany'] = array(
    'name' => 'administer addtoany',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'addtoany',
  );

  // Exported permission: 'administer advanced forum'.
  $permissions['administer advanced forum'] = array(
    'name' => 'administer advanced forum',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer ctools access ruleset'.
  $permissions['administer ctools access ruleset'] = array(
    'name' => 'administer ctools access ruleset',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ctools_access_ruleset',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer entity view modes'.
  $permissions['administer entity view modes'] = array(
    'name' => 'administer entity view modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_view_mode',
  );

  // Exported permission: 'administer entityform types'.
  $permissions['administer entityform types'] = array(
    'name' => 'administer entityform types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'administer facetapi pretty paths'.
  $permissions['administer facetapi pretty paths'] = array(
    'name' => 'administer facetapi pretty paths',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi_pretty_paths',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer forums'.
  $permissions['administer forums'] = array(
    'name' => 'administer forums',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'forum',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer masquerade'.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer menu_per_role'.
  $permissions['administer menu_per_role'] = array(
    'name' => 'administer menu_per_role',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_per_role',
  );

  // Exported permission: 'administer menu_token'.
  $permissions['administer menu_token'] = array(
    'name' => 'administer menu_token',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_token',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer multistep'.
  $permissions['administer multistep'] = array(
    'name' => 'administer multistep',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'multistep',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer path breadcrumbs'.
  $permissions['administer path breadcrumbs'] = array(
    'name' => 'administer path breadcrumbs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path_breadcrumbs_ui',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer phpexcel'.
  $permissions['administer phpexcel'] = array(
    'name' => 'administer phpexcel',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'phpexcel',
  );

  // Exported permission: 'administer piwik'.
  $permissions['administer piwik'] = array(
    'name' => 'administer piwik',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'administer piwik reports'.
  $permissions['administer piwik reports'] = array(
    'name' => 'administer piwik reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik_reports',
  );

  // Exported permission: 'administer popup elements'.
  $permissions['administer popup elements'] = array(
    'name' => 'administer popup elements',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'popup',
  );

  // Exported permission: 'administer privatemsg settings'.
  $permissions['administer privatemsg settings'] = array(
    'name' => 'administer privatemsg settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'administer radioactivity'.
  $permissions['administer radioactivity'] = array(
    'name' => 'administer radioactivity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'radioactivity',
  );

  // Exported permission: 'administer rdf'.
  $permissions['administer rdf'] = array(
    'name' => 'administer rdf',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rdfx',
  );

  // Exported permission: 'administer realname'.
  $permissions['administer realname'] = array(
    'name' => 'administer realname',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'realname',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer rules links'.
  $permissions['administer rules links'] = array(
    'name' => 'administer rules links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules_link',
  );

  // Exported permission: 'administer schema'.
  $permissions['administer schema'] = array(
    'name' => 'administer schema',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'schema',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer services'.
  $permissions['administer services'] = array(
    'name' => 'administer services',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer statistics'.
  $permissions['administer statistics'] = array(
    'name' => 'administer statistics',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'administer superfish'.
  $permissions['administer superfish'] = array(
    'name' => 'administer superfish',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'superfish',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer vote up/down'.
  $permissions['administer vote up/down'] = array(
    'name' => 'administer vote up/down',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'administer voting api'.
  $permissions['administer voting api'] = array(
    'name' => 'administer voting api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'votingapi',
  );

  // Exported permission: 'administer workflow'.
  $permissions['administer workflow'] = array(
    'name' => 'administer workflow',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow_admin_ui',
  );

  // Exported permission: 'allow disabling privatemsg'.
  $permissions['allow disabling privatemsg'] = array(
    'name' => 'allow disabling privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear dkan_file feeds'.
  $permissions['clear dkan_file feeds'] = array(
    'name' => 'clear dkan_file feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear dkan_link feeds'.
  $permissions['clear dkan_link feeds'] = array(
    'name' => 'clear dkan_link feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear rss_import feeds'.
  $permissions['clear rss_import feeds'] = array(
    'name' => 'clear rss_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create app content'.
  $permissions['create app content'] = array(
    'name' => 'create app content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create blog content'.
  $permissions['create blog content'] = array(
    'name' => 'create blog content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create competition content'.
  $permissions['create competition content'] = array(
    'name' => 'create competition content',
    'roles' => array(
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create dataset content'.
  $permissions['create dataset content'] = array(
    'name' => 'create dataset content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create date_format_mail_date content'.
  $permissions['create date_format_mail_date content'] = array(
    'name' => 'create date_format_mail_date content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create document content'.
  $permissions['create document content'] = array(
    'name' => 'create document content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_dataset_standard'.
  $permissions['create field_dataset_standard'] = array(
    'name' => 'create field_dataset_standard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ds_report_col'.
  $permissions['create field_ds_report_col'] = array(
    'name' => 'create field_ds_report_col',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ds_report_row'.
  $permissions['create field_ds_report_row'] = array(
    'name' => 'create field_ds_report_row',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ef_dataset_resources'.
  $permissions['create field_ef_dataset_resources'] = array(
    'name' => 'create field_ef_dataset_resources',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_ef_email'.
  $permissions['create field_ef_email'] = array(
    'name' => 'create field_ef_email',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_frequency'.
  $permissions['create field_frequency'] = array(
    'name' => 'create field_frequency',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_multivolume'.
  $permissions['create field_multivolume'] = array(
    'name' => 'create field_multivolume',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_notified'.
  $permissions['create field_notified'] = array(
    'name' => 'create field_notified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_organization_curators'.
  $permissions['create field_organization_curators'] = array(
    'name' => 'create field_organization_curators',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create forum content'.
  $permissions['create forum content'] = array(
    'name' => 'create forum content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create idea content'.
  $permissions['create idea content'] = array(
    'name' => 'create idea content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create news content'.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create organization content'.
  $permissions['create organization content'] = array(
    'name' => 'create organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create potential_organization content'.
  $permissions['create potential_organization content'] = array(
    'name' => 'create potential_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create private message tags'.
  $permissions['create private message tags'] = array(
    'name' => 'create private message tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'create publisher_request content'.
  $permissions['create publisher_request content'] = array(
    'name' => 'create publisher_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create quick_fact content'.
  $permissions['create quick_fact content'] = array(
    'name' => 'create quick_fact content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create resource content'.
  $permissions['create resource content'] = array(
    'name' => 'create resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'delete any app content'.
  $permissions['delete any app content'] = array(
    'name' => 'delete any app content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any blog content'.
  $permissions['delete any blog content'] = array(
    'name' => 'delete any blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any competition content'.
  $permissions['delete any competition content'] = array(
    'name' => 'delete any competition content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any dataset content'.
  $permissions['delete any dataset content'] = array(
    'name' => 'delete any dataset content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any date_format_mail_date content'.
  $permissions['delete any date_format_mail_date content'] = array(
    'name' => 'delete any date_format_mail_date content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any document content'.
  $permissions['delete any document content'] = array(
    'name' => 'delete any document content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any entityform'.
  $permissions['delete any entityform'] = array(
    'name' => 'delete any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any forum content'.
  $permissions['delete any forum content'] = array(
    'name' => 'delete any forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any idea content'.
  $permissions['delete any idea content'] = array(
    'name' => 'delete any idea content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news content'.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any organization content'.
  $permissions['delete any organization content'] = array(
    'name' => 'delete any organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any potential_organization content'.
  $permissions['delete any potential_organization content'] = array(
    'name' => 'delete any potential_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any publisher_request content'.
  $permissions['delete any publisher_request content'] = array(
    'name' => 'delete any publisher_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any quick_fact content'.
  $permissions['delete any quick_fact content'] = array(
    'name' => 'delete any quick_fact content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any resource content'.
  $permissions['delete any resource content'] = array(
    'name' => 'delete any resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own app content'.
  $permissions['delete own app content'] = array(
    'name' => 'delete own app content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own blog content'.
  $permissions['delete own blog content'] = array(
    'name' => 'delete own blog content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own competition content'.
  $permissions['delete own competition content'] = array(
    'name' => 'delete own competition content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own dataset content'.
  $permissions['delete own dataset content'] = array(
    'name' => 'delete own dataset content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own date_format_mail_date content'.
  $permissions['delete own date_format_mail_date content'] = array(
    'name' => 'delete own date_format_mail_date content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own document content'.
  $permissions['delete own document content'] = array(
    'name' => 'delete own document content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own entityform'.
  $permissions['delete own entityform'] = array(
    'name' => 'delete own entityform',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own forum content'.
  $permissions['delete own forum content'] = array(
    'name' => 'delete own forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own idea content'.
  $permissions['delete own idea content'] = array(
    'name' => 'delete own idea content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news content'.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own organization content'.
  $permissions['delete own organization content'] = array(
    'name' => 'delete own organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own potential_organization content'.
  $permissions['delete own potential_organization content'] = array(
    'name' => 'delete own potential_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own publisher_request content'.
  $permissions['delete own publisher_request content'] = array(
    'name' => 'delete own publisher_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own quick_fact content'.
  $permissions['delete own quick_fact content'] = array(
    'name' => 'delete own quick_fact content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own resource content'.
  $permissions['delete own resource content'] = array(
    'name' => 'delete own resource content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete privatemsg'.
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any app content'.
  $permissions['edit any app content'] = array(
    'name' => 'edit any app content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any blog content'.
  $permissions['edit any blog content'] = array(
    'name' => 'edit any blog content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any competition content'.
  $permissions['edit any competition content'] = array(
    'name' => 'edit any competition content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any dataset content'.
  $permissions['edit any dataset content'] = array(
    'name' => 'edit any dataset content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any date_format_mail_date content'.
  $permissions['edit any date_format_mail_date content'] = array(
    'name' => 'edit any date_format_mail_date content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any document content'.
  $permissions['edit any document content'] = array(
    'name' => 'edit any document content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any entityform'.
  $permissions['edit any entityform'] = array(
    'name' => 'edit any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any forum content'.
  $permissions['edit any forum content'] = array(
    'name' => 'edit any forum content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any idea content'.
  $permissions['edit any idea content'] = array(
    'name' => 'edit any idea content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news content'.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any organization content'.
  $permissions['edit any organization content'] = array(
    'name' => 'edit any organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any potential_organization content'.
  $permissions['edit any potential_organization content'] = array(
    'name' => 'edit any potential_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any publisher_request content'.
  $permissions['edit any publisher_request content'] = array(
    'name' => 'edit any publisher_request content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any quick_fact content'.
  $permissions['edit any quick_fact content'] = array(
    'name' => 'edit any quick_fact content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any resource content'.
  $permissions['edit any resource content'] = array(
    'name' => 'edit any resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_dataset_standard'.
  $permissions['edit field_dataset_standard'] = array(
    'name' => 'edit field_dataset_standard',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ds_report_col'.
  $permissions['edit field_ds_report_col'] = array(
    'name' => 'edit field_ds_report_col',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ds_report_row'.
  $permissions['edit field_ds_report_row'] = array(
    'name' => 'edit field_ds_report_row',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ef_dataset_resources'.
  $permissions['edit field_ef_dataset_resources'] = array(
    'name' => 'edit field_ef_dataset_resources',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_ef_email'.
  $permissions['edit field_ef_email'] = array(
    'name' => 'edit field_ef_email',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_frequency'.
  $permissions['edit field_frequency'] = array(
    'name' => 'edit field_frequency',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_multivolume'.
  $permissions['edit field_multivolume'] = array(
    'name' => 'edit field_multivolume',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_notified'.
  $permissions['edit field_notified'] = array(
    'name' => 'edit field_notified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_organization_curators'.
  $permissions['edit field_organization_curators'] = array(
    'name' => 'edit field_organization_curators',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own app content'.
  $permissions['edit own app content'] = array(
    'name' => 'edit own app content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own blog content'.
  $permissions['edit own blog content'] = array(
    'name' => 'edit own blog content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own competition content'.
  $permissions['edit own competition content'] = array(
    'name' => 'edit own competition content',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own dataset content'.
  $permissions['edit own dataset content'] = array(
    'name' => 'edit own dataset content',
    'roles' => array(
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own date_format_mail_date content'.
  $permissions['edit own date_format_mail_date content'] = array(
    'name' => 'edit own date_format_mail_date content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own document content'.
  $permissions['edit own document content'] = array(
    'name' => 'edit own document content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own entityform'.
  $permissions['edit own entityform'] = array(
    'name' => 'edit own entityform',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_dataset_standard'.
  $permissions['edit own field_dataset_standard'] = array(
    'name' => 'edit own field_dataset_standard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ds_report_col'.
  $permissions['edit own field_ds_report_col'] = array(
    'name' => 'edit own field_ds_report_col',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ds_report_row'.
  $permissions['edit own field_ds_report_row'] = array(
    'name' => 'edit own field_ds_report_row',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ef_dataset_resources'.
  $permissions['edit own field_ef_dataset_resources'] = array(
    'name' => 'edit own field_ef_dataset_resources',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_ef_email'.
  $permissions['edit own field_ef_email'] = array(
    'name' => 'edit own field_ef_email',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_frequency'.
  $permissions['edit own field_frequency'] = array(
    'name' => 'edit own field_frequency',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_multivolume'.
  $permissions['edit own field_multivolume'] = array(
    'name' => 'edit own field_multivolume',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_notified'.
  $permissions['edit own field_notified'] = array(
    'name' => 'edit own field_notified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_organization_curators'.
  $permissions['edit own field_organization_curators'] = array(
    'name' => 'edit own field_organization_curators',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own forum content'.
  $permissions['edit own forum content'] = array(
    'name' => 'edit own forum content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own idea content'.
  $permissions['edit own idea content'] = array(
    'name' => 'edit own idea content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own news content'.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own organization content'.
  $permissions['edit own organization content'] = array(
    'name' => 'edit own organization content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own potential_organization content'.
  $permissions['edit own potential_organization content'] = array(
    'name' => 'edit own potential_organization content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own publisher_request content'.
  $permissions['edit own publisher_request content'] = array(
    'name' => 'edit own publisher_request content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own quick_fact content'.
  $permissions['edit own quick_fact content'] = array(
    'name' => 'edit own quick_fact content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own resource content'.
  $permissions['edit own resource content'] = array(
    'name' => 'edit own resource content',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit radioactivity'.
  $permissions['edit radioactivity'] = array(
    'name' => 'edit radioactivity',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'radioactivity',
  );

  // Exported permission: 'exclude from message filtering'.
  $permissions['exclude from message filtering'] = array(
    'name' => 'exclude from message filtering',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'execute auto_entitylabel_entity_update_action'.
  $permissions['execute auto_entitylabel_entity_update_action'] = array(
    'name' => 'execute auto_entitylabel_entity_update_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_publish_action'.
  $permissions['execute comment_publish_action'] = array(
    'name' => 'execute comment_publish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_save_action'.
  $permissions['execute comment_save_action'] = array(
    'name' => 'execute comment_save_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_unpublish_action'.
  $permissions['execute comment_unpublish_action'] = array(
    'name' => 'execute comment_unpublish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute comment_unpublish_by_keyword_action'.
  $permissions['execute comment_unpublish_by_keyword_action'] = array(
    'name' => 'execute comment_unpublish_by_keyword_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute flag_comment_action'.
  $permissions['execute flag_comment_action'] = array(
    'name' => 'execute flag_comment_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute flag_node_action'.
  $permissions['execute flag_node_action'] = array(
    'name' => 'execute flag_node_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute flag_user_action'.
  $permissions['execute flag_user_action'] = array(
    'name' => 'execute flag_user_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_assign_owner_action'.
  $permissions['execute node_assign_owner_action'] = array(
    'name' => 'execute node_assign_owner_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_sticky_action'.
  $permissions['execute node_make_sticky_action'] = array(
    'name' => 'execute node_make_sticky_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_unsticky_action'.
  $permissions['execute node_make_unsticky_action'] = array(
    'name' => 'execute node_make_unsticky_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_promote_action'.
  $permissions['execute node_promote_action'] = array(
    'name' => 'execute node_promote_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_publish_action'.
  $permissions['execute node_publish_action'] = array(
    'name' => 'execute node_publish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_save_action'.
  $permissions['execute node_save_action'] = array(
    'name' => 'execute node_save_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpromote_action'.
  $permissions['execute node_unpromote_action'] = array(
    'name' => 'execute node_unpromote_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_action'.
  $permissions['execute node_unpublish_action'] = array(
    'name' => 'execute node_unpublish_action',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_by_keyword_action'.
  $permissions['execute node_unpublish_by_keyword_action'] = array(
    'name' => 'execute node_unpublish_by_keyword_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute od_import_import_opendata_action'.
  $permissions['execute od_import_import_opendata_action'] = array(
    'name' => 'execute od_import_import_opendata_action',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute od_log_notify_organization'.
  $permissions['execute od_log_notify_organization'] = array(
    'name' => 'execute od_log_notify_organization',
    'roles' => array(),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_node_update_action'.
  $permissions['execute pathauto_node_update_action'] = array(
    'name' => 'execute pathauto_node_update_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_taxonomy_term_update_action'.
  $permissions['execute pathauto_taxonomy_term_update_action'] = array(
    'name' => 'execute pathauto_taxonomy_term_update_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_user_update_action'.
  $permissions['execute pathauto_user_update_action'] = array(
    'name' => 'execute pathauto_user_update_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'execute realname_action_realname_update'.
  $permissions['execute realname_action_realname_update'] = array(
    'name' => 'execute realname_action_realname_update',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_block_ip_action'.
  $permissions['execute system_block_ip_action'] = array(
    'name' => 'execute system_block_ip_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_goto_action'.
  $permissions['execute system_goto_action'] = array(
    'name' => 'execute system_goto_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_message_action'.
  $permissions['execute system_message_action'] = array(
    'name' => 'execute system_message_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_send_email_action'.
  $permissions['execute system_send_email_action'] = array(
    'name' => 'execute system_send_email_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute typo_vbo_delete_item'.
  $permissions['execute typo_vbo_delete_item'] = array(
    'name' => 'execute typo_vbo_delete_item',
    'roles' => array(),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute user_block_user_action'.
  $permissions['execute user_block_user_action'] = array(
    'name' => 'execute user_block_user_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_archive_action'.
  $permissions['execute views_bulk_operations_archive_action'] = array(
    'name' => 'execute views_bulk_operations_archive_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_argument_selector_action'.
  $permissions['execute views_bulk_operations_argument_selector_action'] = array(
    'name' => 'execute views_bulk_operations_argument_selector_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_item'.
  $permissions['execute views_bulk_operations_delete_item'] = array(
    'name' => 'execute views_bulk_operations_delete_item',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_modify_action'.
  $permissions['execute views_bulk_operations_modify_action'] = array(
    'name' => 'execute views_bulk_operations_modify_action',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_script_action'.
  $permissions['execute views_bulk_operations_script_action'] = array(
    'name' => 'execute views_bulk_operations_script_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_roles_action'.
  $permissions['execute views_bulk_operations_user_roles_action'] = array(
    'name' => 'execute views_bulk_operations_user_roles_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute workflow_vbo_given_state_action'.
  $permissions['execute workflow_vbo_given_state_action'] = array(
    'name' => 'execute workflow_vbo_given_state_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute workflow_vbo_next_state_action'.
  $permissions['execute workflow_vbo_next_state_action'] = array(
    'name' => 'execute workflow_vbo_next_state_action',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'filter private messages'.
  $permissions['filter private messages'] = array(
    'name' => 'filter private messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'flag for_request'.
  $permissions['flag for_request'] = array(
    'name' => 'flag for_request',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag make_publisher'.
  $permissions['flag make_publisher'] = array(
    'name' => 'flag make_publisher',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag materials_shown'.
  $permissions['flag materials_shown'] = array(
    'name' => 'flag materials_shown',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag sent_to_minek'.
  $permissions['flag sent_to_minek'] = array(
    'name' => 'flag sent_to_minek',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag subscribe_dataset'.
  $permissions['flag subscribe_dataset'] = array(
    'name' => 'flag subscribe_dataset',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'get a system variable'.
  $permissions['get a system variable'] = array(
    'name' => 'get a system variable',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get any binary files'.
  $permissions['get any binary files'] = array(
    'name' => 'get any binary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'get own binary files'.
  $permissions['get own binary files'] = array(
    'name' => 'get own binary files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'import dkan_file feeds'.
  $permissions['import dkan_file feeds'] = array(
    'name' => 'import dkan_file feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import dkan_link feeds'.
  $permissions['import dkan_link feeds'] = array(
    'name' => 'import dkan_link feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import or export menu'.
  $permissions['import or export menu'] = array(
    'name' => 'import or export menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu_import',
  );

  // Exported permission: 'import rss_import feeds'.
  $permissions['import rss_import feeds'] = array(
    'name' => 'import rss_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'manage datastore'.
  $permissions['manage datastore'] = array(
    'name' => 'manage datastore',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'dkan_datastore',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'masquerade as admin'.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as user'.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'may send typo reports'.
  $permissions['may send typo reports'] = array(
    'name' => 'may send typo reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'typo',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'od_common localize access taxonomy_term'.
  $permissions['od_common localize access taxonomy_term'] = array(
    'name' => 'od_common localize access taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'od_common',
  );

  // Exported permission: 'od_publisher_map_publisher'.
  $permissions['od_publisher_map_publisher'] = array(
    'name' => 'od_publisher_map_publisher',
    'roles' => array(
      'administrator' => 'administrator',
      'publisher' => 'publisher',
    ),
    'module' => 'od_publisher',
  );

  // Exported permission: 'opt-in or out of tracking'.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'participate in workflow'.
  $permissions['participate in workflow'] = array(
    'name' => 'participate in workflow',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'workflow_admin_ui',
  );

  // Exported permission: 'perform unlimited index queries'.
  $permissions['perform unlimited index queries'] = array(
    'name' => 'perform unlimited index queries',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'publish button publish any competition'.
  $permissions['publish button publish any competition'] = array(
    'name' => 'publish button publish any competition',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any content types'.
  $permissions['publish button publish any content types'] = array(
    'name' => 'publish button publish any content types',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any dataset'.
  $permissions['publish button publish any dataset'] = array(
    'name' => 'publish button publish any dataset',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any news'.
  $permissions['publish button publish any news'] = array(
    'name' => 'publish button publish any news',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish any page'.
  $permissions['publish button publish any page'] = array(
    'name' => 'publish button publish any page',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable competition'.
  $permissions['publish button publish editable competition'] = array(
    'name' => 'publish button publish editable competition',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable dataset'.
  $permissions['publish button publish editable dataset'] = array(
    'name' => 'publish button publish editable dataset',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable news'.
  $permissions['publish button publish editable news'] = array(
    'name' => 'publish button publish editable news',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish editable page'.
  $permissions['publish button publish editable page'] = array(
    'name' => 'publish button publish editable page',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own competition'.
  $permissions['publish button publish own competition'] = array(
    'name' => 'publish button publish own competition',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own dataset'.
  $permissions['publish button publish own dataset'] = array(
    'name' => 'publish button publish own dataset',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own news'.
  $permissions['publish button publish own news'] = array(
    'name' => 'publish button publish own news',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button publish own page'.
  $permissions['publish button publish own page'] = array(
    'name' => 'publish button publish own page',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any competition'.
  $permissions['publish button unpublish any competition'] = array(
    'name' => 'publish button unpublish any competition',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any content types'.
  $permissions['publish button unpublish any content types'] = array(
    'name' => 'publish button unpublish any content types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any dataset'.
  $permissions['publish button unpublish any dataset'] = array(
    'name' => 'publish button unpublish any dataset',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any news'.
  $permissions['publish button unpublish any news'] = array(
    'name' => 'publish button unpublish any news',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish any page'.
  $permissions['publish button unpublish any page'] = array(
    'name' => 'publish button unpublish any page',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable competition'.
  $permissions['publish button unpublish editable competition'] = array(
    'name' => 'publish button unpublish editable competition',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable dataset'.
  $permissions['publish button unpublish editable dataset'] = array(
    'name' => 'publish button unpublish editable dataset',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable news'.
  $permissions['publish button unpublish editable news'] = array(
    'name' => 'publish button unpublish editable news',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish editable page'.
  $permissions['publish button unpublish editable page'] = array(
    'name' => 'publish button unpublish editable page',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own competition'.
  $permissions['publish button unpublish own competition'] = array(
    'name' => 'publish button unpublish own competition',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own dataset'.
  $permissions['publish button unpublish own dataset'] = array(
    'name' => 'publish button unpublish own dataset',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own news'.
  $permissions['publish button unpublish own news'] = array(
    'name' => 'publish button unpublish own news',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'publish button unpublish own page'.
  $permissions['publish button unpublish own page'] = array(
    'name' => 'publish button unpublish own page',
    'roles' => array(),
    'module' => 'publish_button',
  );

  // Exported permission: 'rate content'.
  $permissions['rate content'] = array(
    'name' => 'rate content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'fivestar',
  );

  // Exported permission: 'read all private messages'.
  $permissions['read all private messages'] = array(
    'name' => 'read all private messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'read privatemsg'.
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'reply only privatemsg'.
  $permissions['reply only privatemsg'] = array(
    'name' => 'reply only privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'reset vote up/down votes'.
  $permissions['reset vote up/down votes'] = array(
    'name' => 'reset vote up/down votes',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'save file information'.
  $permissions['save file information'] = array(
    'name' => 'save file information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'schedule workflow transitions'.
  $permissions['schedule workflow transitions'] = array(
    'name' => 'schedule workflow transitions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'select text format for privatemsg'.
  $permissions['select text format for privatemsg'] = array(
    'name' => 'select text format for privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'set a system variable'.
  $permissions['set a system variable'] = array(
    'name' => 'set a system variable',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'services',
  );

  // Exported permission: 'show format selection for comment'.
  $permissions['show format selection for comment'] = array(
    'name' => 'show format selection for comment',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for entityform'.
  $permissions['show format selection for entityform'] = array(
    'name' => 'show format selection for entityform',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for flagging'.
  $permissions['show format selection for flagging'] = array(
    'name' => 'show format selection for flagging',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for log'.
  $permissions['show format selection for log'] = array(
    'name' => 'show format selection for log',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for privatemsg_message'.
  $permissions['show format selection for privatemsg_message'] = array(
    'name' => 'show format selection for privatemsg_message',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_link'.
  $permissions['show format selection for rules_link'] = array(
    'name' => 'show format selection for rules_link',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: 'show workflow state form'.
  $permissions['show workflow state form'] = array(
    'name' => 'show workflow state form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'workflow',
  );

  // Exported permission: 'skip CAPTCHA'.
  $permissions['skip CAPTCHA'] = array(
    'name' => 'skip CAPTCHA',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'captcha',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: 'tag private messages'.
  $permissions['tag private messages'] = array(
    'name' => 'tag private messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'toggle multistep'.
  $permissions['toggle multistep'] = array(
    'name' => 'toggle multistep',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'multistep',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unflag for_request'.
  $permissions['unflag for_request'] = array(
    'name' => 'unflag for_request',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag make_publisher'.
  $permissions['unflag make_publisher'] = array(
    'name' => 'unflag make_publisher',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'moderator' => 'moderator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag materials_shown'.
  $permissions['unflag materials_shown'] = array(
    'name' => 'unflag materials_shown',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag sent_to_minek'.
  $permissions['unflag sent_to_minek'] = array(
    'name' => 'unflag sent_to_minek',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag subscribe_dataset'.
  $permissions['unflag subscribe_dataset'] = array(
    'name' => 'unflag subscribe_dataset',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unlock dkan_file feeds'.
  $permissions['unlock dkan_file feeds'] = array(
    'name' => 'unlock dkan_file feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock dkan_link feeds'.
  $permissions['unlock dkan_link feeds'] = array(
    'name' => 'unlock dkan_link feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock rss_import feeds'.
  $permissions['unlock rss_import feeds'] = array(
    'name' => 'unlock rss_import feeds',
    'roles' => array(),
    'module' => 'feeds',
  );

  // Exported permission: 'update any fullcalendar event'.
  $permissions['update any fullcalendar event'] = array(
    'name' => 'update any fullcalendar event',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'fullcalendar',
  );

  // Exported permission: 'use PHP for label patterns'.
  $permissions['use PHP for label patterns'] = array(
    'name' => 'use PHP for label patterns',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'auto_entitylabel',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use PHP for tracking visibility'.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'piwik',
  );

  // Exported permission: 'use Rules component rules_dataset_is_recommended'.
  $permissions['use Rules component rules_dataset_is_recommended'] = array(
    'name' => 'use Rules component rules_dataset_is_recommended',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_dataset_isnt_recommended'.
  $permissions['use Rules component rules_dataset_isnt_recommended'] = array(
    'name' => 'use Rules component rules_dataset_isnt_recommended',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_entityform_submission'.
  $permissions['use Rules component rules_entityform_submission'] = array(
    'name' => 'use Rules component rules_entityform_submission',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_notify_organization_curators'.
  $permissions['use Rules component rules_notify_organization_curators'] = array(
    'name' => 'use Rules component rules_notify_organization_curators',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_notify_organization_curators_about_new_reports'.
  $permissions['use Rules component rules_notify_organization_curators_about_new_reports'] = array(
    'name' => 'use Rules component rules_notify_organization_curators_about_new_reports',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use Rules component rules_reject_request'.
  $permissions['use Rules component rules_reject_request'] = array(
    'name' => 'use Rules component rules_reject_request',
    'roles' => array(
      'moderator' => 'moderator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use hybridauth'.
  $permissions['use hybridauth'] = array(
    'name' => 'use hybridauth',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'hybridauth',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use search_api_sorts'.
  $permissions['use search_api_sorts'] = array(
    'name' => 'use search_api_sorts',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'search_api_sorts',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format html'.
  $permissions['use text format html'] = array(
    'name' => 'use text format html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format wysiwyg'.
  $permissions['use text format wysiwyg'] = array(
    'name' => 'use text format wysiwyg',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use tokens in privatemsg'.
  $permissions['use tokens in privatemsg'] = array(
    'name' => 'use tokens in privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'use vote up/down'.
  $permissions['use vote up/down'] = array(
    'name' => 'use vote up/down',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'vud',
  );

  // Exported permission: 'view any entityform'.
  $permissions['view any entityform'] = array(
    'name' => 'view any entityform',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'view error messages'.
  $permissions['view error messages'] = array(
    'name' => 'view error messages',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'view field_dataset_standard'.
  $permissions['view field_dataset_standard'] = array(
    'name' => 'view field_dataset_standard',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ds_report_col'.
  $permissions['view field_ds_report_col'] = array(
    'name' => 'view field_ds_report_col',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ds_report_row'.
  $permissions['view field_ds_report_row'] = array(
    'name' => 'view field_ds_report_row',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ef_dataset_resources'.
  $permissions['view field_ef_dataset_resources'] = array(
    'name' => 'view field_ef_dataset_resources',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_ef_email'.
  $permissions['view field_ef_email'] = array(
    'name' => 'view field_ef_email',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_frequency'.
  $permissions['view field_frequency'] = array(
    'name' => 'view field_frequency',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_multivolume'.
  $permissions['view field_multivolume'] = array(
    'name' => 'view field_multivolume',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_notified'.
  $permissions['view field_notified'] = array(
    'name' => 'view field_notified',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_organization_curators'.
  $permissions['view field_organization_curators'] = array(
    'name' => 'view field_organization_curators',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view forum statistics'.
  $permissions['view forum statistics'] = array(
    'name' => 'view forum statistics',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'view last edited notice'.
  $permissions['view last edited notice'] = array(
    'name' => 'view last edited notice',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'advanced_forum',
  );

  // Exported permission: 'view own entityform'.
  $permissions['view own entityform'] = array(
    'name' => 'view own entityform',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: 'view own field_dataset_standard'.
  $permissions['view own field_dataset_standard'] = array(
    'name' => 'view own field_dataset_standard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ds_report_col'.
  $permissions['view own field_ds_report_col'] = array(
    'name' => 'view own field_ds_report_col',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ds_report_row'.
  $permissions['view own field_ds_report_row'] = array(
    'name' => 'view own field_ds_report_row',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ef_dataset_resources'.
  $permissions['view own field_ef_dataset_resources'] = array(
    'name' => 'view own field_ef_dataset_resources',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_ef_email'.
  $permissions['view own field_ef_email'] = array(
    'name' => 'view own field_ef_email',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_frequency'.
  $permissions['view own field_frequency'] = array(
    'name' => 'view own field_frequency',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_multivolume'.
  $permissions['view own field_multivolume'] = array(
    'name' => 'view own field_multivolume',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_notified'.
  $permissions['view own field_notified'] = array(
    'name' => 'view own field_notified',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_organization_curators'.
  $permissions['view own field_organization_curators'] = array(
    'name' => 'view own field_organization_curators',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view post access counter'.
  $permissions['view post access counter'] = array(
    'name' => 'view post access counter',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'statistics',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
      'moderator' => 'moderator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view roles recipients'.
  $permissions['view roles recipients'] = array(
    'name' => 'view roles recipients',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'view status messages'.
  $permissions['view status messages'] = array(
    'name' => 'view status messages',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view warning messages'.
  $permissions['view warning messages'] = array(
    'name' => 'view warning messages',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'write privatemsg'.
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
      'moderator' => 'moderator',
      'publisher' => 'publisher',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'write privatemsg to roles'.
  $permissions['write privatemsg to roles'] = array(
    'name' => 'write privatemsg to roles',
    'roles' => array(
      'administrator' => 'administrator',
      'moderator' => 'moderator',
    ),
    'module' => 'privatemsg_roles',
  );

  return $permissions;
}
