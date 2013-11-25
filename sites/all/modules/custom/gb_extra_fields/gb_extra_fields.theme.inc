<?php
/**
 * @file
 * Theme functions for GB Extra Fields module.
 */

function theme_gb_extra_fields_dataset_title($vars) {
  return $vars['node']->title;
}

function theme_gb_extra_fields_dataset_resource_data_url($vars) {
  return $vars['node']->title;
}

function theme_gb_extra_fields_dataset_resource_data_format($vars) {
  return $vars['node']->title;
}

function theme_gb_extra_fields_dataset_resource_structure_url($vars) {
  return $vars['node']->title;
}

function gb_extra_fields_preprocess_gb_extra_fields_dataset_resource_data_url($vars) {
  if ($vars) {

  }
  $wrapper = entity_metadata_wrapper('node', $vars['node']);
  try {
    $resource = current($wrapper->field_resources);
  }
  catch (EntityMetadataWrapperException $e) {
    $vars['dataset_resource_data_url'] = '';
  }
}
