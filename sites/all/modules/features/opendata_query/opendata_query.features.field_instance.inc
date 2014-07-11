<?php
/**
 * @file
 * opendata_query.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function opendata_query_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_opendata_query-field_comment_od_query_files'
  $field_instances['comment-comment_node_opendata_query-field_comment_od_query_files'] = array(
    'bundle' => 'comment_node_opendata_query',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(
          'conditions' => array(),
          'field_formatter_attributes' => array(),
        ),
        'type' => 'file_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'comment',
    'field_name' => 'field_comment_od_query_files',
    'label' => 'Файлы',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'txt doc odt xls docx jpg pdf',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-opendata_query-field_query_state'
  $field_instances['node-opendata_query-field_query_state'] = array(
    'bundle' => 'opendata_query',
    'default_value' => array(
      0 => array(
        'value' => 'discussion',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'conditions' => array(),
          'field_formatter_attributes' => array(),
        ),
        'type' => 'list_default',
        'weight' => 22,
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
    'field_name' => 'field_query_state',
    'label' => 'State',
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
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('State');
  t('Файлы');

  return $field_instances;
}
