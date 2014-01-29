<?php
/*
 * @file
 */

function od_common_actualize_page_callback($dataset) {
  drupal_goto('actualize-dataset', array('query' => array('field_ef_dataset'=>$dataset->nid)));
}