<?php
/**
 * @file
 * request_and_actualize_entityform.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function request_and_actualize_entityform_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_div|entityform|od_preprocess_wizard|form';
  $field_group->group_name = 'group_div';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'od_preprocess_wizard';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '15',
    'children' => array(
      0 => 'field_link_remote_file',
      1 => 'field_link_api',
      2 => 'field_od_wizard_upload_file',
      3 => 'field_format',
      4 => 'field_data_structure',
      5 => 'field_recline_file_view',
      6 => 'field_link_passport',
      7 => 'field_dataset_variant',
      8 => 'field_dataset_convert',
      9 => 'field_od_wizard_upload_structure',
      10 => 'field_dataset_instruction_link',
      11 => 'field_dataset_instruction_api',
      12 => 'field_dataset_instruction_file',
      13 => 'field_dataset_instruction_main',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_div|entityform|od_preprocess_wizard|form'] = $field_group;

  return $export;
}
