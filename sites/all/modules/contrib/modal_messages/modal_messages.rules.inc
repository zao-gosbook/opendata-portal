<?php

/**
 * Implements hook_rules_action_info().
 */
function modal_messages_rules_action_info() {
  return array(
    'modal_messages_drupal_message' => array(
      'label' => t('Show a popup message on the site'),
      'group' => t('System'),
      'parameter' => array(
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'sanitize' => TRUE,
          'translatable' => TRUE,
        ),
        'type' => array(
          'type' => 'token',
          'label' => t('Message type'),
          'options list' => 'modal_messages_message_types',
          'default value' => 'modal-status',
          'optional' => TRUE,
        ),
        'repeat' => array(
          'type' => 'boolean',
          'label' => t('Repeat message'),
          'description' => t("If disabled and the message has been already shown, then the message won't be repeated."),
          'default value' => TRUE,
          'optional' => TRUE,
          'restriction' => 'input',
        ),
      ),
    ),
  );
}

/**
 * Action: Show a popup drupal message.
 */
function modal_messages_drupal_message($message, $status, $repeat) {
  drupal_set_message(filter_xss_admin($message), $status, $repeat);
}
