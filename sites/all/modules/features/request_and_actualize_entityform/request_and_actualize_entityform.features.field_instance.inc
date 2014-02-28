<?php
/**
 * @file
 * request_and_actualize_entityform.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function request_and_actualize_entityform_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityform-dataset_actualization-field_content_last_change'
  $field_instances['entityform-dataset_actualization-field_content_last_change'] = array(
    'bundle' => 'dataset_actualization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_content_last_change',
    'label' => 'Содержание последнего изменения',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 'ds_code',
          'full_html' => 'full_html',
          'html' => 'html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'html' => array(
              'weight' => -9,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'wysiwyg' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 128,
      ),
      'type' => 'text_textfield',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_dataset_convert'
  $field_instances['entityform-dataset_actualization-field_dataset_convert'] = array(
    'bundle' => 'dataset_actualization',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_convert',
    'label' => 'Загрузка с конвертацией',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_dataset_instruction_api'
  $field_instances['entityform-dataset_actualization-field_dataset_instruction_api'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_instruction_api',
    'label' => 'Инструкция для API',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_dataset_instruction_file'
  $field_instances['entityform-dataset_actualization-field_dataset_instruction_file'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_instruction_file',
    'label' => 'Инструкция для Файла',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_dataset_instruction_link'
  $field_instances['entityform-dataset_actualization-field_dataset_instruction_link'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_instruction_link',
    'label' => 'Инструкция для ссылки',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_dataset_instruction_main'
  $field_instances['entityform-dataset_actualization-field_dataset_instruction_main'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_instruction_main',
    'label' => 'Инструкция',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_dataset_variant'
  $field_instances['entityform-dataset_actualization-field_dataset_variant'] = array(
    'bundle' => 'dataset_actualization',
    'default_value' => array(
      0 => array(
        'value' => 'external',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_variant',
    'label' => 'Вариант создания набора',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_date_last_change'
  $field_instances['entityform-dataset_actualization-field_date_last_change'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_date_last_change',
    'label' => 'Дата последнего внесения изменений',
    'required' => 1,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'none',
        'text_parts' => array(),
        'year_range' => '-6:+0',
      ),
      'type' => 'date_popup',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_ef_dataset'
  $field_instances['entityform-dataset_actualization-field_ef_dataset'] = array(
    'bundle' => 'dataset_actualization',
    'default_value' => NULL,
    'default_value_function' => 'entityreference_prepopulate_field_default_value',
    'default_value_widget' => array(
      'default_value_token' => '',
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_ef_dataset',
    'label' => 'Набор данных',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'action' => 'hide',
          'action_on_edit' => 0,
          'fallback' => 'form_error',
          'og_context' => 0,
          'skip_perm' => 0,
          'status' => 1,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_link_api'
  $field_instances['entityform-dataset_actualization-field_link_api'] = array(
    'bundle' => 'dataset_actualization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_link_api',
    'label' => 'Ссылка на API',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_link_passport'
  $field_instances['entityform-dataset_actualization-field_link_passport'] = array(
    'bundle' => 'dataset_actualization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_link_passport',
    'label' => 'Ссылка на страницу набора на сайте обладателя',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => 'nofollow',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_link_remote_file'
  $field_instances['entityform-dataset_actualization-field_link_remote_file'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_link_remote_file',
    'label' => 'Набор данных',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'csv xls xlsx ods xml rdf',
      'max_filesize' => '',
      'od_file_preprocess' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 'remotefile',
            'upload' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_link_structure_file'
  $field_instances['entityform-dataset_actualization-field_link_structure_file'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_link_structure_file',
    'label' => 'Структура открытых данных',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'xsd csv',
      'max_filesize' => '',
      'od_file_preprocess' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 'remotefile',
            'upload' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_od_wizard_upload_file'
  $field_instances['entityform-dataset_actualization-field_od_wizard_upload_file'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_od_wizard_upload_file',
    'label' => 'Файл',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'csv xls xlsx ods xml rdf',
      'max_filesize' => '',
      'od_file_preprocess' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_od_wizard_upload_structure'
  $field_instances['entityform-dataset_actualization-field_od_wizard_upload_structure'] = array(
    'bundle' => 'dataset_actualization',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_od_wizard_upload_structure',
    'label' => 'Файл структуры',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'xsd csv',
      'max_filesize' => '',
      'od_file_preprocess' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'entityform-dataset_actualization-field_recline_file_view'
  $field_instances['entityform-dataset_actualization-field_recline_file_view'] = array(
    'bundle' => 'dataset_actualization',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_recline_file_view',
    'label' => 'Представление файла',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_contact_name'
  $field_instances['entityform-od_preprocess_wizard-field_contact_name'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Фамилия, Имя, Отчество (через пробел, на русском языке) лица, ответственного за набор данных. <br />
Например: Иванов Иван Иванович',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_contact_name',
    'label' => 'Ответственное лицо',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'full_html' => 'full_html',
          'html' => 'html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'html' => array(
              'weight' => -9,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'wysiwyg' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_contact_phone'
  $field_instances['entityform-od_preprocess_wizard-field_contact_phone'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Номер телефон ответственного лица, в соответствии с примером <br />
Например: +7 495 123 4567',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_contact_phone',
    'label' => 'Телефон ответственного лица',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'full_html' => 'full_html',
          'html' => 'html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'html' => array(
              'weight' => -9,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'wysiwyg' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_content_last_change'
  $field_instances['entityform-od_preprocess_wizard-field_content_last_change'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Данное поле заполняется русскоязычным текстом, описывающим изменения, внесенные в последнюю версию. <br />
Например: обновление набора данных
',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_content_last_change',
    'label' => 'Содержание последнего изменения',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'full_html' => 'full_html',
          'html' => 'html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'html' => array(
              'weight' => -9,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'wysiwyg' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_data_structure'
  $field_instances['entityform-od_preprocess_wizard-field_data_structure'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_data_structure',
    'label' => 'Структура набора данных',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'xsd csv json',
      'max_filesize' => '',
      'od_file_preprocess' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 'remotefile',
            'upload' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 34,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_body'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_body'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Русскоязычное описание набора данных, дающее представление об информации внутри набора данных <br />
Например: Список выставочных залов с указанием контактных данных по округам и районам.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_body',
    'label' => 'Описание набора данных',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'full_html' => 'full_html',
          'html' => 'html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'html' => array(
              'weight' => -9,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'wysiwyg' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'display_summary' => 0,
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 4,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_convert'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_convert'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => array(
      0 => array(
        'value' => 1,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 24,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_convert',
    'label' => 'Загрузка с конвертацией',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 39,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_id'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_id'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Состоит из 10-значного ИНН организации-владельца набора и через дефис наименование набора данных на латинице <br />
Например: 7712345678-showrooms',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_id',
    'label' => 'Идентификационный номер',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'full_html' => 'full_html',
          'html' => 'html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'html' => array(
              'weight' => -9,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'wysiwyg' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_instruction_api'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_instruction_api'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 28,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_instruction_api',
    'label' => 'Инструкция для API',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 36,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_instruction_file'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_instruction_file'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 29,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_instruction_file',
    'label' => 'Инструкция для Файла',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 38,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_instruction_link'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_instruction_link'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 27,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_instruction_link',
    'label' => 'Инструкция для ссылки',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_instruction_main'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_instruction_main'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(),
        'type' => 'markup_default',
        'weight' => 30,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_instruction_main',
    'label' => 'Инструкция',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'markup',
      'settings' => array(),
      'type' => 'markup',
      'weight' => 30,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_title'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_title'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Русскоязычное наименование набора данных. <br />
Например: Список выставочных залов',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_title',
    'label' => 'Наименование паспорта',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'full_html' => 'full_html',
          'html' => 'html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'html' => array(
              'weight' => -9,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'wysiwyg' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_dataset_variant'
  $field_instances['entityform-od_preprocess_wizard-field_dataset_variant'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => array(
      0 => array(
        'value' => 'external',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 23,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_dataset_variant',
    'label' => 'Вариант создания набора',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_date_dataset_actual'
  $field_instances['entityform-od_preprocess_wizard-field_date_dataset_actual'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => 'Выберете дату, до которой данные в наборе будут считаться актуальными. <br />
Например: 12/04/2013',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_date_dataset_actual',
    'label' => 'Дата актуальности набора данных',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'none',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_date_first_time_publ'
  $field_instances['entityform-od_preprocess_wizard-field_date_first_time_publ'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => 'Выберите дату, когда набор был опубликован впервые (в случае, если создается новый набор, выберите текущую дату). <br />
Например: 12/04/2013',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_date_first_time_publ',
    'label' => 'Дата первой публикации набора данных',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'none',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_date_last_change'
  $field_instances['entityform-od_preprocess_wizard-field_date_last_change'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => 'Выберите дату последнего внесения изменения в набор, структуру или паспорт открытых данных (в случае, если изменения не вносились, дата должна совпадать с датой первичной публикации). <br />
Например: 12/04/2013',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_date_last_change',
    'label' => 'Дата последнего внесения изменений',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'none',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_email_responsible'
  $field_instances['entityform-od_preprocess_wizard-field_email_responsible'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'E-mail ответственного лица, в соответствии с примером. <br />
Например: ivanov123@gmail.com',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_email_responsible',
    'label' => 'Адрес электронной почты ответственного лица',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_license'
  $field_instances['entityform-od_preprocess_wizard-field_license'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => array(
      0 => array(
        'value' => 'notspecified',
      ),
    ),
    'deleted' => 0,
    'description' => 'Выберите лицензию, в соответствии с которой публикуется набор открытых данных.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_license',
    'label' => 'Лицензия',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'full_html' => 'full_html',
          'html' => 'html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'full_html' => array(
              'weight' => -10,
            ),
            'html' => array(
              'weight' => -9,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -8,
            ),
            'wysiwyg' => array(
              'weight' => 0,
            ),
          ),
        ),
      ),
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'select_or_other',
      'settings' => array(
        'available_options' => 'cc-by|Лицензия «С указанием авторства»
cc-by-sa|Лицензия «Распространение на тех же условиях - Копилефт»
notspecified|Лицензия отсутствует',
        'available_options_php' => '',
        'markup_available_options_php' => '&lt;none&gt;',
        'other' => 'Другое',
        'other_size' => 60,
        'other_title' => '',
        'other_unknown_defaults' => 'other',
        'sort_options' => 0,
      ),
      'type' => 'select_or_other',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_link_api'
  $field_instances['entityform-od_preprocess_wizard-field_link_api'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_link_api',
    'label' => 'Ссылка',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 37,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_link_passport'
  $field_instances['entityform-od_preprocess_wizard-field_link_passport'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This field is mandatory and is filled to find the dataset, in the absence or improper publication dataset.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_link_passport',
    'label' => 'Link to this page dataset site owner',
    'required' => 0,
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'configurable_title' => 0,
        'rel' => 'nofollow',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'rel_remove_external',
      'title' => 'none',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 35,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_link_remote_file'
  $field_instances['entityform-od_preprocess_wizard-field_link_remote_file'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_link_remote_file',
    'label' => 'Набор данных',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'csv xls xlsx ods xml rdf',
      'max_filesize' => '',
      'od_file_preprocess' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 'remotefile',
            'upload' => 0,
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_od_wizard_upload_file'
  $field_instances['entityform-od_preprocess_wizard-field_od_wizard_upload_file'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_od_wizard_upload_file',
    'label' => 'Файл',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'csv xls xlsx ods xml rdf',
      'max_filesize' => '',
      'od_file_preprocess' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 40,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_od_wizard_upload_structure'
  $field_instances['entityform-od_preprocess_wizard-field_od_wizard_upload_structure'] = array(
    'bundle' => 'od_preprocess_wizard',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 25,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_od_wizard_upload_structure',
    'label' => 'Файл структуры',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'xsd csv',
      'max_filesize' => '',
      'od_file_preprocess' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_organization'
  $field_instances['entityform-od_preprocess_wizard-field_organization'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Выберите организацию, от лица которой вы публикуете данные, и которая является владельцем этого набора. <br />
Например: Министерство культуры',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_organization',
    'label' => 'Организация',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_recline_file_view'
  $field_instances['entityform-od_preprocess_wizard-field_recline_file_view'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_recline_file_view',
    'label' => 'Представление файла',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_rubric'
  $field_instances['entityform-od_preprocess_wizard-field_rubric'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Выберите рубрику, к которой относится набор <br />
Например: Экономика',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_rubric',
    'label' => 'Рубрика',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => 0,
      ),
      'type' => 'options_select',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'entityform-od_preprocess_wizard-field_tags'
  $field_instances['entityform-od_preprocess_wizard-field_tags'] = array(
    'bundle' => 'od_preprocess_wizard',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Слова и словосочетания (через запятую, на русском языке), описывающие набор данных. <br />
Например: Выставка, зал, выставочный зал, культура',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_tags',
    'label' => 'Ключевые слова',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'autocomplete_deluxe',
      'settings' => array(
        'autocomplete_deluxe_path' => 'autocomplete_deluxe/taxonomy',
        'delimiter' => '',
        'limit' => 10,
        'min_length' => 0,
        'size' => 60,
      ),
      'type' => 'autocomplete_deluxe_taxonomy',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'taxonomy_term-rubrics-field_rubric_image'
  $field_instances['taxonomy_term-rubrics-field_rubric_image'] = array(
    'bundle' => 'rubrics',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'field_formatter_label' => '',
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'front_page' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'field_formatter_label' => '',
          'image_link' => 'content',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'rubric_icon_with_title' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'taxonomy-w-65',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'term_in_idea' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'field_formatter_label' => '',
          'image_link' => '',
          'image_style' => 'taxonomy-w-65',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_rubric_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => 'rubric_images',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'reference' => 0,
            'remote' => 0,
            'remotefile' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'taxonomy_term-rubrics-field_show_front_page'
  $field_instances['taxonomy_term-rubrics-field_show_front_page'] = array(
    'bundle' => 'rubrics',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'front_page' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'rubric_icon_with_title' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'term_in_idea' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_show_front_page',
    'label' => 'Показывать на главной странице',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('E-mail ответственного лица, в соответствии с примером. <br />
Например: ivanov123@gmail.com');
  t('Image');
  t('Link to this page dataset site owner');
  t('This field is mandatory and is filled to find the dataset, in the absence or improper publication dataset.');
  t('Адрес электронной почты ответственного лица');
  t('Вариант создания набора');
  t('Выберете дату, до которой данные в наборе будут считаться актуальными. <br />
Например: 12/04/2013');
  t('Выберите дату последнего внесения изменения в набор, структуру или паспорт открытых данных (в случае, если изменения не вносились, дата должна совпадать с датой первичной публикации). <br />
Например: 12/04/2013');
  t('Выберите дату, когда набор был опубликован впервые (в случае, если создается новый набор, выберите текущую дату). <br />
Например: 12/04/2013');
  t('Выберите лицензию, в соответствии с которой публикуется набор открытых данных.');
  t('Выберите организацию, от лица которой вы публикуете данные, и которая является владельцем этого набора. <br />
Например: Министерство культуры');
  t('Выберите рубрику, к которой относится набор <br />
Например: Экономика');
  t('Данное поле заполняется русскоязычным текстом, описывающим изменения, внесенные в последнюю версию. <br />
Например: обновление набора данных
');
  t('Дата актуальности набора данных');
  t('Дата первой публикации набора данных');
  t('Дата последнего внесения изменений');
  t('Загрузка с конвертацией');
  t('Идентификационный номер');
  t('Инструкция');
  t('Инструкция для API');
  t('Инструкция для Файла');
  t('Инструкция для ссылки');
  t('Ключевые слова');
  t('Лицензия');
  t('Набор данных');
  t('Наименование паспорта');
  t('Номер телефон ответственного лица, в соответствии с примером <br />
Например: +7 495 123 4567');
  t('Описание набора данных');
  t('Организация');
  t('Ответственное лицо');
  t('Показывать на главной странице');
  t('Представление файла');
  t('Рубрика');
  t('Русскоязычное наименование набора данных. <br />
Например: Список выставочных залов');
  t('Русскоязычное описание набора данных, дающее представление об информации внутри набора данных <br />
Например: Список выставочных залов с указанием контактных данных по округам и районам.');
  t('Слова и словосочетания (через запятую, на русском языке), описывающие набор данных. <br />
Например: Выставка, зал, выставочный зал, культура');
  t('Содержание последнего изменения');
  t('Состоит из 10-значного ИНН организации-владельца набора и через дефис наименование набора данных на латинице <br />
Например: 7712345678-showrooms');
  t('Ссылка');
  t('Ссылка на API');
  t('Ссылка на страницу набора на сайте обладателя');
  t('Структура набора данных');
  t('Структура открытых данных');
  t('Телефон ответственного лица');
  t('Файл');
  t('Файл структуры');
  t('Фамилия, Имя, Отчество (через пробел, на русском языке) лица, ответственного за набор данных. <br />
Например: Иванов Иван Иванович');

  return $field_instances;
}
