<?php

/**
 * @file
 *
 * This is the task handler plugin to modify node form.
 */

// Plugin definition
$plugin = array(
  // is a 'context' handler type, meaning it supports the API of the
  // context handlers provided by ctools context plugins.
  'handler type' => 'context',
  'visible' => TRUE, // may be added up front.

  // Administrative fields.
  'title' => t('Node form modification'),
  'admin summary' => 'node_form_mutator_form_mutator_admin_summary',
  'admin title' => 'node_form_mutator_form_mutator_title',
  'operations' => array(
    'settings' => array(
      'title' => t('General'),
      'description' => t('Change general settings for this variant.'),
      'form' => 'node_form_mutator_form_mutator_edit_settings',
    ),
    'criteria' => array(
      'title' => t('Selection rules'),
      'description' => t('Control the criteria used to decide whether or not this variant is used.'),
      'ajax' => FALSE,
      'form' => array(
        'order' => array(
          'form' => t('Selection rules'),
        ),
        'forms' => array(
          'form' => array(
            'include' => drupal_get_path('module', 'ctools') . '/includes/context-task-handler.inc',
            'form id' => 'ctools_context_handler_edit_criteria',
          ),
        ),
      ),
    ),
    'context' => array(
      'title' => t('Contexts'),
      'ajax' => FALSE,
      'description' => t('Add additional context objects to this variant that can be used by the content.'),
      'form' => array(
        'order' => array(
          'form' => t('Context'),
        ),
        'forms' => array(
          'form' => array(
            'include' => drupal_get_path('module', 'ctools') . '/includes/context-task-handler.inc',
            'form id' => 'ctools_context_handler_edit_context',
          ),
        ),
      ),
    ),
  ),

  // Callback to render the data.
  'render' => 'node_form_mutator_form_mutator_render',

  'add features' => array(
    'criteria' => t('Selection rules'),
    'context' => t('Contexts'),
  ),
  // Where to go when finished.
  'add finish' => 'settings',

  'required forms' => array(
    'settings' => t('Panel settings'),
  ),

  'edit forms' => array(
    'criteria' => t('Selection rules'),
    'settings' => t('General'),
    'context' => t('Contexts'),
  ),
  'forms' => array(
    'settings' => array(
      'form id' => 'node_form_mutator_form_mutator_edit_settings',
    ),
    'context' => array(
      'include' => drupal_get_path('module', 'ctools') . '/includes/context-task-handler.inc',
      'form id' => 'ctools_context_handler_edit_context',
    ),
    'criteria' => array(
      'include' => drupal_get_path('module', 'ctools') . '/includes/context-task-handler.inc',
      'form id' => 'ctools_context_handler_edit_criteria',
    ),
  ),
  'default conf' => array(
    'title' => t('Node form modification'),
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(),
  ),
);

function node_form_mutator_form_mutator_admin_summary($handler, $task, $subtask, $page, $show_title = TRUE) {
  $task_name = page_manager_make_task_name($task['name'], $subtask['name']);
  $output = '';

  ctools_include('context');
  ctools_include('context-task-handler');

  // Get the operations
  $operations = page_manager_get_operations($page);

  // Get operations for just this handler.
  $operations = $operations['handlers']['children'][$handler->name]['children']['actions']['children'];
  $args = array('handlers', $handler->name, 'actions');
  $rendered_operations = page_manager_render_operations($page, $operations, array(), array('class' => array('actions')), 'actions', $args);

  $plugin = page_manager_get_task_handler($handler->handler);

  $object = ctools_context_handler_get_task_object($task, $subtask, $handler);
  $context = ctools_context_load_contexts($object, TRUE);

  $access = ctools_access_group_summary(!empty($handler->conf['access']) ? $handler->conf['access'] : array(), $context);
  if ($access) {
    $access = t('This panel will be selected if @conditions.', array('@conditions' => $access));
  }
  else {
    $access = t('This panel will always be selected.');
  }

  $rows = array();

  $type = $handler->type == t('Default') ? t('In code') : $handler->type;
  $rows[] = array(
    array('class' => array('page-summary-label'), 'data' => t('Storage')),
    array('class' => array('page-summary-data'), 'data' => $type),
    array('class' => array('page-summary-operation'), 'data' => ''),
  );

  if (!empty($handler->disabled)) {
    $link = l(t('Enable'), page_manager_edit_url($task_name, array('handlers', $handler->name, 'actions', 'enable')));
    $text = t('Disabled');
  }
  else {
    $link = l(t('Disable'), page_manager_edit_url($task_name, array('handlers', $handler->name, 'actions', 'disable')));
    $text = t('Enabled');
  }

  $rows[] = array(
    array('class' => array('page-summary-label'), 'data' => t('Status')),
    array('class' => array('page-summary-data'), 'data' => $text),
    array('class' => array('page-summary-operation'), 'data' => $link),
  );

  $link = l(t('Edit'), page_manager_edit_url($task_name, array('handlers', $handler->name, 'criteria')));
  $rows[] = array(
    array('class' => array('page-summary-label'), 'data' => t('Selection rule')),
    array('class' => array('page-summary-data'), 'data' => $access),
    array('class' => array('page-summary-operation'), 'data' => $link),
  );

  $link = l(t('Edit'), page_manager_edit_url($task_name, array('handlers', $handler->name, 'settings')));
  $modification = $handler->conf['modification'];
  $overridden_fields = array();
  foreach ($modification as $field_name => $field_conf) {
    if (isset($field_conf['override']) && ($field_conf['override'])) {
      $overridden_fields[] = $field_name;
    }
  }
  $overridden_fields_str = (count($overridden_fields) > 0) ? implode(', ', $overridden_fields) : 'none';
  $rows[] = array(
    array('class' => array('page-summary-label'), 'data' => t('Node form modification')),
    array('class' => array('page-summary-data'), 'data' => t('Overridden fields: @fields.', array('@fields' => $overridden_fields_str))),
    array('class' => array('page-summary-operation'), 'data' => $link),
  );

  $info = theme('table', array('header' => array(), 'rows' => $rows, 'attributes' => array('class' => array('page-manager-handler-summary'))));

  $title = $handler->conf['title'];
  if ($title != t('Panel')) {
    $title = t('Panel: @title', array('@title' => $title));
  }

  $output .= '<div class="clearfix">';
  if ($show_title) {
  $output .= '<div class="handler-title clearfix">';
    $output .= '<div class="actions handler-actions">' . $rendered_operations['actions'] . '</div>';
    $output .= '<span class="title-label">' . $title . '</span>';
  }

  $output .= '</div>';
  $output .= $info;
  $output .= '</div>';

  return $output;
}

/**
 * Set up a title for the panel based upon the selection rules.
 */
function node_form_mutator_form_mutator_title($handler, $task, $subtask) {
  if (isset($handler->conf['title'])) {
    return check_plain($handler->conf['title']);
  }
  else {
    return t('Node form modification');
  }
}

/**
 * General settings for the panel
 */
function node_form_mutator_form_mutator_edit_settings($form, &$form_state) {
  $conf = $form_state['handler']->conf;
  $node_types = array();
  if (isset($conf['access']['plugins'])) {
    foreach ($conf['access']['plugins'] as $plugin) {
      if ($plugin['name'] == 'node_type') {
        if ((isset($plugin['settings']['type'])) && (is_array($plugin['settings']['type']))) {
          foreach ($plugin['settings']['type'] as $type) {
            $node_types[] = $type;
          }
        }
      }
    }
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#default_value' => $conf['title'],
    '#title' => t('Administrative title'),
    '#description' => t('Administrative title of this variant.'),
  );

  if (count($node_types) == 0) {
    $form['error'] = array(
      '#markup' => t('In order to configure node form, please select node type in selection rules.'),
    );
    return $form;
  }

  if (count($node_types) > 1) {
    $form['error'] = array(
      '#markup' => t('You must select exactly one node type in selection rules.'),
    );
    return $form;
  }
  $node_type = $node_types[0];

/* Take form parts which are not fields.
  module_load_include('inc', 'node', 'node.pages');
  global $user;
  $node = (object) array('uid' => $user->uid, 'name' => (isset($user->name) ? $user->name : ''), 'type' => $node_type, 'language' => LANGUAGE_NONE);
  $node_form = drupal_get_form($node_type . '_node_form', $node);*/

  $node_type_title_label = node_type_get_type($node_type)->title_label;
  $node_fields = array(':title' => array('label' => $node_type_title_label));

  $field_info = field_info_instances('node', $node_type);
  foreach ($field_info as $field) {
    if ($field['deleted']) {
      continue;
    }
    $node_fields[$field['field_name']] = $field;
  }

  // Commonly used elements for node forms.
  $form_elements = array(
    array(
      'field_name' => ':author',
      'label' => t('Authoring information'),
    ),
    array(
      'field_name' => ':menu',
      'label' => t('Menu settings'),
    ),
    array(
      'field_name' => ':comment_settings',
      'label' => t('Comment settings'),
    ),
    array(
      'field_name' => ':path',
      'label' => t('URL path settings'),
    ),
    array(
      'field_name' => ':options',
      'label' => t('Publishing options'),
    ),
    array(
      'field_name' => ':revision_information',
      'label' => t('Revision information'),
    ),
    array(
      'field_name' => ':redirect',
      'label' => t('URL redirects'),
    ),
    array(
      'field_name' => ':flag',
      'label' => t('Flags'),
    ),
    array(
      'field_name' => ':actions:submit',
      'label' => t('Save'),
    ),
    array(
      'field_name' => ':actions:preview',
      'label' => t('Preview'),
    ),
    array(
      'field_name' => ':actions:delete',
      'label' => t('Delete'),
    ),
  );
  foreach ($form_elements as $field) {
    $node_fields[$field['field_name']] = $field;
  }


  $form['#tree'] = TRUE;
  $form['#theme'] = 'node_form_mutator_field_form_table';

  $form['field_table'] = array();
  foreach ($node_fields as $field_name => $field) {
    $values = isset($conf['modification'][$field_name]) ? $conf['modification'][$field_name] : array();

    $form['field_table'][$field_name] = array(
      'title' => array('#markup' => $field['label']),
      'field_name' => array('#markup' => $field_name),
      'override' => array(
        '#type' => 'checkbox',
        '#default_value' => isset($values['override']) ? $values['override'] : FALSE,
      ),
      'label' => array(
        '#type' => 'textfield',
        '#size' => 20,
        '#default_value' => isset($values['label']) ? $values['label'] : $field['label'],
        '#states' => array(
          'enabled' => array(
            ':input[name="field_table[' . $field_name . '][override]"]' => array('checked' => TRUE),
          ),
        ),
      ),
      'hidden_field' => array(
        '#type' => 'select',
        '#default_value' => isset($values['hidden_field']) ? intval($values['hidden_field']) : 0,
        '#options' => array(
          0 => t('Editable'),
          1 => t('Hidden'),
          2 => t('Disabled'),
          3 => t('Read only'),
        ),
        '#states' => array(
          'enabled' => array(
            ':input[name="field_table[' . $field_name . '][override]"]' => array('checked' => TRUE),
          ),
        ),
      ),
    );
  }

  $form['form_title'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($conf['form_title']) ? $conf['form_title'] : '',
    '#title' => t('Form title'),
    '#description' => t('Set to non-empty value to override the form title.'),
  );

  return $form;
}

function node_form_mutator_form_mutator_edit_settings_submit($form, &$form_state) {
  $form_state['handler']->conf['title'] = $form_state['values']['title'];
  if (isset($form_state['values']['form_title'])) {
    $form_state['handler']->conf['form_title'] = $form_state['values']['form_title'];
  }
  if (isset($form_state['values']['field_table'])) {
    $form_state['handler']->conf['modification'] = $form_state['values']['field_table'];
  }
  else {
    $form_state['handler']->conf['modification'] = array();
  }
}

function node_form_mutator_form_mutator_render($handler, $base_contexts, $args, $test = TRUE) {
  // Go through arguments and see if they match.
  ctools_include('context');
  ctools_include('context-task-handler');

  // Add my contexts
  $contexts = ctools_context_handler_get_handler_contexts($base_contexts, $handler);

  // Test.
  if ($test && !ctools_context_handler_select($handler, $contexts)) {
    return;
  }

  $context = reset($base_contexts);
  $output = array(
    'content' => $context->form,
  );
  if ((isset($handler->conf['form_title'])) && (strlen($handler->conf['form_title']) > 0)) {
    $output['title'] = $handler->conf['form_title'];
  }
  return $output;
}
