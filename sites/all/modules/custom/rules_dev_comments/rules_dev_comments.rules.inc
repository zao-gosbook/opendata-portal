<?php
/**
 * @file
 * Rules integration file.
 */

/**
 * Implements hook_rules_plugin_info().
 */
function rules_dev_comments_rules_plugin_info() {
  return array(
    'comment' => array(
      'label' => t('Comment'),
      'class' => 'RulesDevComment',
      'embeddable' => 'RulesContainerPlugin',
      'extenders' => array(
        'RulesPluginUIInterface' => array(
          'class' => 'RulesDevCommentUI',
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_plugin_info_alter().
 */
function rules_dev_comments_rules_plugin_info_alter(&$data) {
  // To allow place comment before Else and Default Case
  foreach(array('else', 'default case') as $plugin) {
    $data[$plugin]['conditional depends'][] = 'comment';
  }
}
