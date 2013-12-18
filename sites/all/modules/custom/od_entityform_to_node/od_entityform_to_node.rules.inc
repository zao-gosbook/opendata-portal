<?php
/**
 * @file
 */

function od_entityform_to_node_rules_action_info() {
  $actions = array();

  $actions['copy_entity_form_to_node'] = array(
    'label' => t('Copy entity form type to node'),
    'parameter' => array(
      'ef' => array(
        'type' => 'entityform',
        'label' => t('Entity form type to copy'),
      ),
      'title' => array(
        'type' => 'text',
        'label' => t('Node title'),
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
    ),
    'group' => t('Entityforms'),
    'base' => 'od_entityform_to_node_rules_actions_copy_entity_form_to_node',
  );

  return $actions;
}

function od_entityform_to_node_rules_actions_copy_entity_form_to_node($ef, $title, $node_type, $save_node = FALSE) {
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
  $node->title = $title;
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