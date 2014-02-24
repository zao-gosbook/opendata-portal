<?php

/**
 * Implements of hook_views_data().
 */
function log_views_data() {
  $items = array();

  // Log base table.
  $items['log']['table'] = array(
    'base' => array(
      'field' => 'lid',
      'title' => t('Log'),
      'help' => t('Log.'),
      'weight' => 25,
    ),
    'group' => t('Log'),
    'join' => array(
      'users' => array(
        'field' => 'uid',
        'left_field' => 'uid',
      ),
    ),
  );

  // Log user ID.
  $items['log']['lid'] = array(
    'title' => t('Lid'),
    'help' => t('Unique log ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'lid',
      'numeric' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Log user ID.
  $items['log']['uid'] = array(
    'title' => t('User'),
    'help' => t('The user who triggered log.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'uid',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Log created.
  $items['log']['created'] = array(
    'title' => t('Created'),
    'help' => t('Unix timestamp of when log occurred.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_date',
      'name field' => 'timestamp',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  // Log message.
  $items['log']['message'] = array(
    'title' => t('Message'),
    'help' => t('Text of log message.'),
    'field' => array(
      'handler' => 'views_handler_field_markup',
      'format' => 'full_html',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'name field' => 'message',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Relation to user.
  $user_entity_type = 'user';
  $user_entity_info = entity_get_info($user_entity_type);
  $items['log']['log_related_user'] = array(
    'group' => t('Log'),
    'title' => t('Log to @entity',
      array('@entity' => drupal_ucfirst($user_entity_info['label']))),
    'help' => t('The @entity entity that is associated with the log.',
      array('@entity' => $user_entity_info['label'])),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'label' => t('@entity from log',
        array('@entity' => $user_entity_type)),
      'base' => $user_entity_info['base table'],
      'base field' => $user_entity_info['entity keys']['id'],
      'relationship field' => 'uid',
    ),
  );

  return $items;
}
