<?php
/**
 * @file
 * suggestions.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function suggestions_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'entityform-add_suggestion-field_add_suggetion_body'
  $field_instances['entityform-add_suggestion-field_add_suggetion_body'] = array(
    'bundle' => 'add_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_add_suggetion_body',
    'label' => 'Описание предложения',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 'ds_code',
          'forum_input' => 'forum_input',
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
            'forum_input' => array(
              'weight' => 0,
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
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'entityform-add_suggestion-field_add_suggetion_rubric'
  $field_instances['entityform-add_suggestion-field_add_suggetion_rubric'] = array(
    'bundle' => 'add_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_add_suggetion_rubric',
    'label' => 'Тема',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'entityform-add_suggestion-field_add_suggetion_title'
  $field_instances['entityform-add_suggestion-field_add_suggetion_title'] = array(
    'bundle' => 'add_suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'entityform',
    'field_name' => 'field_add_suggetion_title',
    'label' => 'Название предложения',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 'ds_code',
          'forum_input' => 'forum_input',
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
            'forum_input' => array(
              'weight' => 0,
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

  // Exported field_instance: 'node-suggestion-body'
  $field_instances['node-suggestion-body'] = array(
    'bundle' => 'suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Пожалуйста, опишите свое предложение. При необходимости приведите ссылки на ответственные государственные организации.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'ideas_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'conditions' => array(),
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Описание предложения',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ds_code' => 0,
          'forum_input' => 0,
          'full_html' => 0,
          'html' => 0,
          'php_code' => 0,
          'plain_text' => 'plain_text',
          'wysiwyg' => 'wysiwyg',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ds_code' => array(
              'weight' => 12,
            ),
            'forum_input' => array(
              'weight' => 0,
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
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-suggestion-field_suggestion_instruction'
  $field_instances['node-suggestion-field_suggestion_instruction'] = array(
    'bundle' => 'suggestion',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'markup',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'markup_default',
        'weight' => 1,
      ),
      'ideas_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suggestion_instruction',
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
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-suggestion-field_suggestion_rubric'
  $field_instances['node-suggestion-field_suggestion_rubric'] = array(
    'bundle' => 'suggestion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 2,
      ),
      'ideas_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suggestion_rubric',
    'label' => 'Тема',
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
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-suggestion-field_suggestion_vote'
  $field_instances['node-suggestion-field_suggestion_vote'] = array(
    'bundle' => 'suggestion',
    'default_value' => array(
      0 => array(
        'vud_widget' => 'updown',
        'votingapi_tag' => 'vote',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'vud_field',
        'settings' => array(
          'conditions' => array(),
        ),
        'type' => 'default',
        'weight' => 3,
      ),
      'ideas_list' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suggestion_vote',
    'label' => 'Голосовать',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
      'votingapi_tag' => 'suggestion_vote',
      'vud_widget' => 'thumbs',
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'vud_field',
      'settings' => array(),
      'type' => 'vud_field_default_widget',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Голосовать');
  t('Инструкция');
  t('Название предложения');
  t('Описание предложения');
  t('Пожалуйста, опишите свое предложение. При необходимости приведите ссылки на ответственные государственные организации.');
  t('Тема');

  return $field_instances;
}
