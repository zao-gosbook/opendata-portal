<?php
/*
 * @file
 */

function od_common_actualize_page_callback($dataset) {
  $dataset_wrapper = entity_metadata_wrapper('node', $dataset);
  if ($dataset_wrapper->field_multivolume->value() == FALSE) {
    drupal_goto('actualize-dataset', array('query' => array('field_ef_dataset'=>$dataset->nid)));
  }
  if ($dataset_wrapper->field_multivolume->value() == TRUE) {
    drupal_goto('actualize-dataset-mv', array('query' => array('field_ef_dataset'=>$dataset->nid)));
  }
}
