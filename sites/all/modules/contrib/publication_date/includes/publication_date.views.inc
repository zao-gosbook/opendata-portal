<?php

/**
 * @file
 * Provide views data and handlers for the Publication Date module.
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */

/**
 * Implements hook_views_data()
 */
function publication_date_views_data() {
  $data = array();

  $data['publication_date']['table']['group'] = t('Node');

  // how is the scheduler table linked to the nodes
  $data['publication_date']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );

  // description of the fields (columns)
  $data['publication_date']['published_at'] = array(
    'title' => t('Published at'),
    'help' => t('Date/time on which the article has been published'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'label' => t('Published at'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  return $data;
}
