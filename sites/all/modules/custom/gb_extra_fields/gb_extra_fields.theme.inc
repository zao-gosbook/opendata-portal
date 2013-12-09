<?php
/**
 * @file
 * Theme functions for GB Extra Fields module.
 */

function theme_gb_extra_fields_dataset_title($vars) {
  return $vars['node']->title;
}

function theme_gb_extra_fields_dataset_resource_data_url($vars) {
  return $vars['data_url'];
}

function theme_gb_extra_fields_dataset_resource_data_format($vars) {
  return $vars['data_format'];
}

function theme_gb_extra_fields_dataset_resource_structure_url($vars) {
  return $vars['structure_url'];
}

function gb_extra_fields_preprocess_gb_extra_fields_dataset_resource_data_url(&$vars) {
  $dataset_wrapper = entity_metadata_wrapper('node', $vars['node']);

  try {
    $resource = current($dataset_wrapper->field_resources->value());

    $resource_wrapper = entity_metadata_wrapper('node', $resource);

    $remote_structure = $resource_wrapper->field_link_remote_file->value();

    $vars['data_url'] = '';
    if (!empty($remote_structure)) {
      $vars['data_url'] = $remote_structure['uri'];
    }
    else {
      $upload_structure = $resource_wrapper->field_upload->value();
      if (!empty($upload_structure)) {
        $vars['data_url'] = file_create_url($upload_structure->uri);
      }
    }
  }
  catch (EntityMetadataWrapperException $e) {
    $vars['data_url'] = '';
  }
}

function gb_extra_fields_preprocess_gb_extra_fields_dataset_resource_data_format(&$vars) {
  $dataset_wrapper = entity_metadata_wrapper('node', $vars['node']);

  try {
    $resource = current($dataset_wrapper->field_resources->value());

    $resource_wrapper = entity_metadata_wrapper('node', $resource);

    $format = $resource_wrapper->field_format->value();

    $vars['data_format'] = $format->name;
  }
  catch (EntityMetadataWrapperException $e) {
    $vars['data_format'] = '';
  }
}

function gb_extra_fields_preprocess_gb_extra_fields_dataset_resource_structure_url(&$vars) {
  $dataset_wrapper = entity_metadata_wrapper('node', $vars['node']);

  try {
    $resource = current($dataset_wrapper->field_resources->value());

    $resource_wrapper = entity_metadata_wrapper('node', $resource);

    $remote_structure = $resource_wrapper->field_link_structure_file->value();

    $vars['structure_url'] = '';
    if (!empty($remote_structure)) {
      $vars['structure_url'] = $remote_structure['uri'];
    }
    else {
      $upload_structure = $resource_wrapper->field_upload_structure->value();
      if (!empty($upload_structure)) {
        $vars['structure_url'] = file_create_url($upload_structure['uri']);
      }
    }
  }
  catch (EntityMetadataWrapperException $e) {
    $vars['structure_url'] = '';
  }
}
