<?php
/*
 * @file
 */

/**
 * Implements hook_views_data().
 */
function od_dataset_views_data() {
  $data = array();

  $data['views']['od_dataset_selected_facets_info'] = array(
    'title' => t('Dataset Search Selected Facets Info'),
    'help' => t('Renders selected facets information'),
    'group' => t('Datasets'),
    'area' => array(
      'help' => t('Renders selected facets information'),
      'handler' => 'od_dataset_views_handler_area_facets_info',
    ),
  );
  
  

  return $data;
}