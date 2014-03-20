<?php
/**
 * @file
 * entityforms.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function entityforms_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional|node|dataset|table';
  $field_group->group_name = 'group_additional';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset';
  $field_group->mode = 'table';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Паспорт',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_contact_name',
      2 => 'field_frequency',
      3 => 'field_tags',
      4 => 'field_dataset_id',
      5 => 'field_contact_phone',
      6 => 'field_email_responsible',
      7 => 'field_organization',
      8 => 'field_date_first_time_publ',
      9 => 'field_date_last_change',
      10 => 'field_date_dataset_actual',
      11 => 'field_content_last_change',
      12 => 'dataset_table_1',
      13 => 'dynamic_field',
      14 => 'dynamic_field_3',
      15 => 'dynamic_field_4',
      16 => 'dynamic_field_5',
      17 => 'dynamic_field_6',
    ),
    'format_type' => 'table',
    'format_settings' => array(
      'label' => 'Паспорт',
      'instance_settings' => array(
        'label' => 'hide',
        'desc' => '',
        'first_column' => 'Название поля паспорта',
        'second_column' => 'Значение поля паспорта',
        'cells' => 'empty',
      ),
    ),
  );
  $export['group_additional|node|dataset|table'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_div|entityform|add_app|form';
  $field_group->group_name = 'group_div';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'add_app';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ссылки на приложения',
    'weight' => '9',
    'children' => array(
      0 => 'field_app_url_apple_store',
      1 => 'field_app_url_google_play',
      2 => 'field_app_url_windows_phone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_div|entityform|add_app|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_div|node|app|form';
  $field_group->group_name = 'group_div';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'app';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ссылки на приложения',
    'weight' => '12',
    'children' => array(
      0 => 'field_app_url_windows_phone',
      1 => 'field_app_url_google_play',
      2 => 'field_app_url_apple_store',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_div|node|app|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hidden_fields|node|dataset|form';
  $field_group->group_name = 'group_hidden_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Скрытые поля',
    'weight' => '17',
    'children' => array(
      0 => 'field_additional_info',
      1 => 'field_author',
      2 => 'field_data_dictionary',
      3 => 'field_frequency',
      4 => 'field_granularity',
      5 => 'field_related_content',
      6 => 'field_resources',
      7 => 'field_spatial_geographical_cover',
      8 => 'field_popularity',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Скрытые поля',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_hidden_fields|node|dataset|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hidden_fields|node|dataset|table';
  $field_group->group_name = 'group_hidden_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset';
  $field_group->mode = 'table';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Скрытые поля',
    'weight' => '16',
    'children' => array(
      0 => 'field_additional_info',
      1 => 'field_author',
      2 => 'field_data_dictionary',
      3 => 'field_granularity',
      4 => 'field_related_content',
      5 => 'field_spatial',
      6 => 'field_spatial_geographical_cover',
      7 => 'field_popularity',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Скрытые поля',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_hidden_fields|node|dataset|table'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_map|node|dataset|form';
  $field_group->group_name = 'group_map';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Карта',
    'weight' => '16',
    'children' => array(
      0 => 'field_spatial',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Карта',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_map|node|dataset|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_map|node|potential_organization|form';
  $field_group->group_name = 'group_map';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'potential_organization';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Map',
    'weight' => '6',
    'children' => array(
      0 => 'field_geolocation',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Map',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_map|node|potential_organization|form'] = $field_group;

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
    'label' => 'Информация об организации',
    'weight' => '0',
    'children' => array(
      0 => 'field_pubreq_organization_exists',
      1 => 'field_pubreq_created_org',
      2 => 'field_pubreq_selected_org',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Информация об организации',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
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
    'label' => 'Информация об издателе',
    'weight' => '6',
    'children' => array(
      0 => 'field_pubreg_surname',
      1 => 'field_pubreg_name',
      2 => 'field_pubreg_patronymic',
      3 => 'field_pubreg_post',
      4 => 'field_pubreq_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Информация об издателе',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_publisher|entityform|request_to_become_a_publisher|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publsher|node|publisher_request|form';
  $field_group->group_name = 'group_publsher';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'publisher_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Издатель',
    'weight' => '4',
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
  $export['group_publsher|node|publisher_request|form'] = $field_group;

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
