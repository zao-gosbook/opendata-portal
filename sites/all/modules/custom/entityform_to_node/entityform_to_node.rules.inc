<?php
/**
 * @file
 * Rules file.
 */

/**
 * Implements hook_rules_action_info().
 */
function entityform_to_node_rules_action_info() {
  return array(
    'entityform_to_node_copy_create_node' => array(
      'label' => t('Copy entityform type to a new node'),
      'parameter' => array(
        'ef' => array(
          'type' => 'entityform',
          'label' => t('Entityform type to copy'),
        ),
        'config' => array(
          'type' => 'struct',
          'label' => t('Copy config'),
          'optional' => TRUE,
          'ui class' => 'EntityFormToNodeRulesUIConfig',
        ),
        'create_fields' => array(
          'type' => 'boolean',
          'label' => t('Create fields'),
          'default' => FALSE,
        ),
        'save_node' => array(
          'type' => 'boolean',
          'label' => t('Save created node immediately'),
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
      'base' => 'entityform_to_node_rules_action_callbacks_copy_create_node',
    ),
    'entityform_to_node_copy_existing_node' => array(
      'label' => t('Copy entityform type to an existing node'),
      'parameter' => array(
        'ef' => array(
          'type' => 'entityform',
          'label' => t('Entityform type to copy'),
        ),
        'node' => array(
          'type' => 'node',
          'label' => t('Node to copy to'),
        ),
        'create_fields' => array(
          'type' => 'boolean',
          'label' => t('Create fields'),
          'default' => FALSE,
        ),
        'config' => array(
          'type' => 'struct',
          'label' => t('Copy config'),
          'optional' => TRUE,
          'ui class' => 'EntityFormToNodeRulesUIConfig',
        ),
      ),
      'group' => t('Entityforms'),
      'base' => 'entityform_to_node_rules_action_callbacks_copy_existing_node',
    ),
  );
}

/**
 * Callback for "entityform_to_node_copy_create_node" action.
 */
function entityform_to_node_rules_action_callbacks_copy_create_node($ef, $config, $create_fields, $save_node = FALSE) {
  $options = array(
    'create_fields' => $create_fields,
    'save_node' => $save_node,
    'field_mappings' => $config['field_mappings'],
  );

  $node = entityform_to_node_copy_to_node($ef, $config['node_type'], $options);
  return array('node_created' => $node);
}


/**
 * Callback for "entityform_to_node_copy_existing_node" action.
 */
function entityform_to_node_rules_action_callbacks_copy_existing_node($ef, $node, $create_fields, $config) {
  $options = array(
    'create_fields' => $create_fields,
    'save_node' => FALSE,
    'field_mappings' => $config['field_mappings'],
    'node' => $node,
  );

  entityform_to_node_copy_to_node($ef, $config['node_type'], $options);
}
