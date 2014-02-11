<?php

/**
 * Implements hook_rules_action_info().
 */
function file_rules_rules_action_info() {
  $items = array();

  $items['file_rules_copy_file'] = array(
    'label' => t('Copy file field contents'),
    'group' => t('Data'),
    'parameter' => array(
      'source_entity' => array(
        'type' => 'entity',
        'label' => t('Source entity'),
        'description' => t('Specifies the entity containing the source field.'),
        'wrapped' => TRUE,
        'restriction' => 'selector',
      ),
      'source_field' => array(
        'type' => 'token',
        'label' => t('Source field'),
        'description' => t('The name of the source file field.'),
        'options list' => 'file_rules_file_field_options',
        'restriction' => 'input',
      ),
      'destination_entity' => array(
        'type' => 'entity',
        'label' => t('Destination entity'),
        'description' => t('Specifies the entity containing the destination field.'),
        'wrapped' => TRUE,
        'restriction' => 'selector',
      ),
      'destination_field' => array(
        'type' => 'token',
        'label' => t('Destination field'),
        'description' => t('The name of the destination file field.'),
        'options list' => 'file_rules_file_field_options',
        'restriction' => 'input',
      ),
      'remove_source' => array(
        'type' => 'integer',
        'label' => t('Remove the source files'),
        'description' => t('Remove the source field contents and the source files. Please do not select "Remove source files and save source entity" if the source entity must not be saved (e.g. memory-only content).'),
        'options list' => 'file_rules_remove_source_options',
        'default value' => 0,
        'optional' => FALSE,
        'restriction' => 'input',
      ),
    ),
  );

  return $items;
}

/**
 * Returns options for choosing a file field for the selected entity.
 */
function file_rules_file_field_options() {
  $options = array();
  foreach (field_info_fields() as $field_name => $field) {
    if (($field['type'] == 'file') || ($field['type'] == 'image')) {
      $options[$field_name] = $field_name;
    }
  }
  return $options;
}

/**
 * Returns options for 'Remove source' parameter.
 */
function file_rules_remove_source_options() {
  return array(
    0 => t('Do not remove source files'),
    1 => t('Remove source files, do not save source entity'),
    2 => t('Remove source files and save source entity'),
  );
}

/**
 * Action: Copy file field contents.
 */
function file_rules_copy_file($source_entity, $source_field_name, $destination_entity, $destination_field_name, $remove_source, $settings, $state) {
  $source_field = field_info_field($source_field_name);
  if (!$source_field) {
    throw new RulesEvaluationException('Non-existing field "@field".', array('@field' => $source_field_name));
  }
  $destination_field = field_info_field($destination_field_name);
  $destination_entity_object = $destination_entity->value();
  if (!$destination_field) {
    throw new RulesEvaluationException('Non-existing field "@field".', array('@field' => $destination_field_name));
  }
  if ($source_field['type'] !== $destination_field['type']) {
    throw new RulesEvaluationException('Field types differ for fields "@source_field" and "@destination_field".',
      array('@source_field' => $source_field_name, '@destination_field' => $destination_field_name));
  }
  if ((!isset($source_entity->$source_field_name)) && (!isset($source_entity->value()->$source_field_name))) {
    throw new RulesEvaluationException('Source entity does not contain field "@field".', array('@field' => $source_field_name));
  }
  if ((!isset($destination_entity->$destination_field_name)) && (!isset($destination_entity_object->$destination_field_name))) {
    throw new RulesEvaluationException('Destination entity does not contain field "@field".', array('@field' => $destination_field_name));
  }

  $destination_instance = field_info_instance($destination_entity->type(), $destination_field_name, $destination_entity->getBundle());
  $destination_location = file_field_widget_uri($destination_field, $destination_instance);

  $source_fids = array();
  $file_data = array();
  foreach ($source_entity->value()->$source_field_name as $values) {
    foreach ($values as $value) {
      $file_data[] = $value;
      $source_fids[] = $value['fid'];
    }
  }
  foreach ($file_data as &$item) {
    $file = file_load($item['fid']);
    // The copy must be temporary file, it will become permanent when entity is saved.
    $file->status = 0;
    $new_file = file_copy($file, $destination_location, FILE_EXISTS_RENAME);
    if ($new_file) {
      $item['fid'] = $new_file->fid;
    }
    else {
      throw new RulesEvaluationException('File could not be copied. More information is available in the system log.');
    }
  }

  $langcode = field_language($destination_entity->type(), $destination_entity_object, $destination_field_name);
  if (!$langcode) {
    $langcode = LANGUAGE_NONE;
  }

  $destination_entity_object->$destination_field_name = array($langcode => $file_data);
  $state->saveChanges($settings['destination_entity:select'], $destination_entity);

  if ($remove_source > 0) {
    foreach ($source_fids as $fid) {
      $file = file_load($fid);
      $source_entity_type = $source_entity->type();
      $source_entity_id = $source_entity->getIdentifier();
      file_field_delete_file($file, $source_field, $source_entity_type, $source_entity_id);
    }
    $source_entity->value()->$source_field_name = array();
    if ($remove_source == 2) {
      $state->saveChanges($settings['source_entity:select'], $source_entity);
    }
  }
}
