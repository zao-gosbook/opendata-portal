<?php
/*
 * @file
 */

function od_dataset_rules_action_info() {
  return array(
    'od_dataset_create_new_revision' => array(
      'label' => t('Create new revision of dataset (with resources)'),
      'parameter' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
      'provides' => array(
        'new_revision' => array(
          'type' => 'node',
          'label' => t('New revision node'),
          'save' => TRUE,
        ),
      ),
      'group' => t('Gosbook'),
      'base' => 'od_dataset_rules_actions_create_new_revision',
    ),
  );
}

function od_dataset_rules_actions_create_new_revision($node) {
  return array('new_revision' => od_dataset_revision($node));
}

