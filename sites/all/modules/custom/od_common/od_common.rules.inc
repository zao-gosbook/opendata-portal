<?php
/*
 * @file
 */

function od_common_rules_action_info() {
  return array(
//    'generate_password' => array(
//      'label' => t('Generate password'),
//      'parameter' => array(
//        'length' => array(
//          'type' => 'integer',
//          'label' => t('Length'),
//        ),
//      ),
//      'group' => t('Gosbook'),
//      'base' => 'common_rules_actions_generate_pass',
//      'provides' => array(
//        'password_generated' => array(
//          'type' => 'text',
//          'label' => t('Generated password'),
//        ),
//      ),
//    ),
//    'set_users_password' => array(
//      'label' => t('Set users password'),
//      'parameter' => array(
//        'account' => array(
//          'type' => 'user',
//          'label' => t('User'),
//        ),
//        'password' => array(
//          'type' => 'text',
//          'label' => t('Password'),
//        ),
//      ),
//      'group' => t('User'),
//      'base' => 'common_rules_actions_set_user_password',
//    ),
//    'get_ulogin_data' => array(
//      'label' => t('Get uLogin data'),
//      'provides' => array(
//        'ulogin_data' => array(
//          'type' => 'ulogin_data',
//          'label' => t('uLogin data'),
//        ),
//      ),
//      'group' => t('uLogin'),
//      'base' => 'common_rules_actions_get_ulogin_data',
//    ),
    'copy_entity_form_to_node' => array(
      'label' => t('Copy entity form type to node'),
      'parameter' => array(
        'ef' => array(
          'type' => 'entityform',
          'label' => t('Entity form type to copy'),
        ),
        'node_type' => array(
          'type' => 'text',
          'label' => t('Node type name to create'),
        ),
        'save_node' => array(
          'type' => 'boolean',
          'label' => t('Save created node'),
        ),
      ),
      'provides' => array(
        'node_created' => array(
          'type' => 'node',
          'label' => t('Created node'),
          'save' => TRUE,
        ),
//        'node_type_created' => array(
//          'type' => 'boolean',
//          'label' => t('Returns true if new node type has been created'),
//        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'common_rules_actions_copy_entity_form_to_node',
    ),
    'od_common_format_date' => array(
      'label' => t('Format timestamp to appropriate format'),
      'parameter' => array(
        'timestamp' => array(
          'type' => 'date',
          'label' => t('Valid unix timestamp'),
        ),
        'format' => array(
          'label' => t('Select date format'),
          'type' => 'text',
          'options list' => '_od_common_callbacks_date_formats',
        ),
      ),
      'provides' => array(
        'date_formated' => array(
          'type' => 'text',
          'label' => t('Formated date string'),
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'od_common_rules_actions_od_common_format_date',
    ),
  );
}

function _od_common_callbacks_date_formats() {
  module_load_include('admin.inc', 'system');
  $formats_trash = system_date_time_settings();

  $options = array();
  foreach ($formats_trash['formats']['format'] as $format_name => $element) {
    $options[$format_name] = $element['#title'] . '('. date($element['#default_value']). ')';
  }

  return $options;
}

function od_common_rules_actions_od_common_format_date($timestamp, $format_name) {
  return array('date_formated' => format_date($timestamp, str_replace('date_format_', '', $format_name)));
}

function common_rules_actions_copy_entity_form_to_node($ef, $node_type, $save_node = FALSE) {
  $node_types = node_type_get_types();

  if (!isset($node_types[$node_type])) {
    $fields = (object) array(
      'type' => (string) $node_type,
      'name' => 'Node type '. $node_type . ' created by rules action',
      'base' => 'node_content',
      'has_title' => FALSE,
      'title_label' => 'title label',
      'description' => 'This node type has been created by rules action',
      'help' => '',
      'custom' => TRUE,
      'modified' => FALSE,
      'locked' => FALSE,
      'disabled' => FALSE,
      'module' => 'common',
    );

    node_type_save($fields);
  }

  $wrapper = entity_metadata_wrapper('entityform', $ef);
  $pi = $wrapper->getPropertyInfo();

  $node = new stdClass();
  $node->type = $node_type;
  $node->title = 'Entity form submission copy from ' . date('c');
  $node->uid = $GLOBALS['user']->uid;
  node_object_prepare($node);
  foreach ($pi as $property => $info) {
    if (!empty($info['field']) && isset($ef->{$property})) {
      if (!($instance = field_info_instance('node', $property, $node_type))) {
        $instance = field_info_instance('entityform', $property, $ef->type);
        $instance['entity_type'] = 'node';
        $instance['bundle'] = $node_type;

        field_create_instance($instance);
      }

      $node->{$property} = $ef->{$property};
    }
  }

  if ($save_node) {
    entity_save('node', $node);
  }

  return array('node_created' => $node);
}

function common_rules_actions_generate_pass($length = 10) {
  $info = array();
  $info['password_generated'] = user_password($length);

  return $info;
}

function common_rules_actions_set_user_password($account, $password) {
  $edit = array(
    'pass' => $password,
  );
  user_save($account, $edit);
}

function common_rules_actions_get_ulogin_data() {
  //if ()
}

