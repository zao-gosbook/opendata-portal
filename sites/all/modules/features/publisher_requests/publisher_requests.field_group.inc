<?php
/**
 * @file
 * publisher_requests.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function publisher_requests_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_organization|entityform|request_to_become_a_publisher|form';
  $field_group->group_name = 'group_organization';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'request_to_become_a_publisher';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Organization info',
    'weight' => '0',
    'children' => array(
      0 => 'field_pubreq_organization_exists',
      1 => 'field_pubreq_created_org',
      2 => 'field_pubreq_selected_org',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_organization|entityform|request_to_become_a_publisher|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publisher|entityform|request_to_become_a_publisher|form';
  $field_group->group_name = 'group_publisher';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'request_to_become_a_publisher';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Publisher info',
    'weight' => '1',
    'children' => array(
      0 => 'field_pubreg_post',
      1 => 'field_pubreq_phone',
      2 => 'field_pubreg_name',
      3 => 'field_pubreg_surname',
      4 => 'field_pubreg_patronymic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_publisher|entityform|request_to_become_a_publisher|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publisher|node|publisher_request|form';
  $field_group->group_name = 'group_publisher';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publisher_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Издатель',
    'weight' => '4',
    'children' => array(
      0 => 'field_pubreq_phone',
      1 => 'field_pubreg_post',
      2 => 'field_pubreg_name',
      3 => 'field_pubreg_surname',
      4 => 'field_pubreg_patronymic',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Издатель',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_publisher|node|publisher_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pubreg_info|node|publisher_request|form';
  $field_group->group_name = 'group_pubreg_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publisher_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Информация по заявке',
    'weight' => '2',
    'children' => array(
      0 => 'field_pubreq_status',
      1 => 'field_pubreq_user',
      2 => 'field_pubreq_processed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pubreg_info|node|publisher_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pubreg_organization|node|publisher_request|form';
  $field_group->group_name = 'group_pubreg_organization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publisher_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Организация',
    'weight' => '3',
    'children' => array(
      0 => 'field_pubreq_organization_exists',
      1 => 'field_pubreq_created_org',
      2 => 'field_pubreq_selected_org',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_pubreg_organization|node|publisher_request|form'] = $field_group;

  return $export;
}
