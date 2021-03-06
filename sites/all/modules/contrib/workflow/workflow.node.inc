<?php
/**
 * @file
 * Node specific hooks and functions, remnants of nodeapi.
 */

/**
 * Theme the current workflow state as top line of History tab.
 */
function theme_workflow_current_state($variables) {
  $state = $variables['state'];
  return '<div class="workflow-current-state '
    . 'workflow-current-sid-' . intval($variables['sid']) . ' '
    . drupal_html_class($state)
    . '">'
    . t('Current state: <span class="state">@state</span>', array('@state' => $state))
    . '</div>';
}

/**
 * Implements hook_node_load().
 */
function workflow_node_load($nodes, $types) {
  // Get which types have workflows associated with them.
  $workflow_types = array_filter(workflow_get_workflow_type_map());

  foreach ($nodes as $node) {
    // If it's not a workflow type, quit immediately.
    if (!array_key_exists($node->type, $workflow_types)) {
      continue;
    }

    $workflow = workflow_get_workflows_by_type($node->type);

    // ALERT: With the upgrade to Drupal 7, values stored on the node as _workflow_x
    // have been standardized to workflow_x, dropping the initial underscore.
    // Module maintainers integrating with workflow should keep that in mind.
    // As of workflow 7.x-2.x, the scheduled transition is not loaded. See issue #2138591. 
    $last_history = workflow_get_recent_node_history($node->nid);

    // Nodes that existed before the workflow don't have any history.
    if (!$last_history) {
      $node->workflow = $workflow->getCreationSid();
      $node->workflow_stamp = $node->created;
    }
    else {
      $state = $workflow->getState($last_history->new_sid);
      $node->workflow = $last_history->new_sid;
      $node->workflow_stamp = $last_history->stamp;
      $node->workflow_state_name = ($state) ? $state->getName() : 'unknown state';
    }
  }
}

/**
 * Implements hook_node_view().
 */
function workflow_node_view($node, $view_mode, $langcode) {
  $entity_type = 'node'; // This hook is only for nodes.

  // Skip if there are no Node API workflows.
  if (!workflow_get_workflow_type_map_by_type($node->type)) {
    return;
  }

  if (!user_access('show workflow state form') || $node->status == 0) {
    return;
  }

  $current_sid = workflow_node_current_state($node);
  $current_state = WorkflowState::load($current_sid);

  // Show current state at the top of the node display.
  $node->content['workflow_current_state'] = workflow_state_formatter($entity_type, $node);
  $node->content['workflow_current_state']['#weight'] = -99;

  $choices = $current_state->getOptions($entity_type, $node);
  if ($current_state->showWidget($choices)) {
    $workflow = $current_state->getWorkflow();

//    // Show state change form at the bottom of the node display.
//    module_load_include('inc', 'workflow', 'workflow.pages');

    // Emulate a Field API interface.
    $field = array();
    $field['field_name'] = '';
    $field['settings']['wid'] = $workflow->wid;
    $field['settings']['widget'] = $workflow->options;
    $field['settings']['widget']['options'] = 'radios';
    $field['settings']['widget']['comment'] = !empty($workflow->options['comment_log_node']); // vs. ['comment_log_tab']; 
    $field['settings']['widget']['current_status'] = FALSE;

    $instance = array();

    // By including the nid in the form id.
    $form = drupal_get_form('workflow_transition_form_' . $node->nid, $field, $instance, $entity_type, $node);
    $form['#weight'] = 99;

    $node->content['workflow'] = $form;
  }
}

/**
 * Implements hook_node_insert().
 *
 * This is executed after saving data to the database.
 * We cannot use hook_node_presave, because workflow_execute_transition() needs the nid.
 */
function workflow_node_insert($node) {
  return workflow_node_update($node);
}

/**
 * Implements hook_node_update().
 */
function workflow_node_update($node) {
  // Retrieve the data from the form.
  if (!isset($node->workflow_field)) {
    // For this type_map, user did not want a form here. 
    return;
  }

  $form_state['values']['workflow_field'] = $node->workflow_field;
  $form_state['values']['workflow_instance'] = $node->workflow_instance;
  $form['#entity_type'] = 'node';
  $form['#entity'] = $node;
  // For some reason, the Workflow Form does not return the form in an 'workflow' element.
  // @todo: correct this, or filter on 'workflow' elements.
  $form_state['values'] = (array) $node;

  workflow_save_transition($form, $form_state);
}

/**
 * Implements hook_node_delete().
 */
function workflow_node_delete($node) {
  $node->workflow_stamp = REQUEST_TIME;
  // Delete the association of node to state.
  workflow_delete_workflow_node_by_nid($node->nid);
  if (!empty($node->workflow)) {
    global $user;
    $data = array(
      'nid' => $node->nid,
      'old_sid' => $node->workflow,
      'sid' => WORKFLOW_DELETION,
      'uid' => $user->uid,
      'stamp' => $node->workflow_stamp,
      'comment' => t('Node deleted'),
    );
    workflow_insert_workflow_node_history($data);
  }
  // Delete any scheduled transitions for this node.
  WorkflowScheduledTransition::deleteById('node', $node->nid);
}

/**
 * Implements hook_comment_insert().
 */
function workflow_comment_insert($comment) {
  workflow_comment_update($comment);
}

/**
 * Implements hook_comment_update().
 */
function workflow_comment_update($comment) {
  // Retrieve the data from the form.
  if (!isset($comment->workflow_field)) {
    // For this type_map, user did not want a form here. 
    return;
  }

  $node = node_load($comment->nid);

  $form_state['values']['workflow_field'] = $comment->workflow_field;
  $form_state['values']['workflow_instance'] = $comment->workflow_instance;
  $form['#entity_type'] = 'node';
  $form['#entity'] = $node;
  // For some reason, the Workflow Form does not return the form in an 'workflow' element.
  // @todo: correct this, or filter on 'workflow' elements.
  $form_state['values'] = (array) $comment;

  workflow_save_transition($form, $form_state);
}

/**
 * Implements hook_field_extra_fields().
 */
function workflow_field_extra_fields() {
  $extra = array();

  // Get all workflows by content types.
  $types = array_filter(workflow_get_workflow_type_map());

  // Add the extra fields to each content type that has a workflow.
  foreach ($types as $type => $wid) {
    $extra['node'][$type] = array(
      'form' => array(
        'workflow' => array(
          'label' => t('Workflow'),
          'description' => t('Workflow module form'),
          'weight' => 99,    // Default to bottom.
        ),
      ),
      'display' => array(
        'workflow_current_state' => array(
          'label' => t('Workflow: Current State'),
          'description' => t('Current workflow state'),
          'weight' => -99,   // Default to top.
        ),
        'workflow' => array(
          'label' => t('Workflow: State Change Form'),
          'description' => t('The form for controlling workflow state changes.'),
          'weight' => 99,    // Default to bottom.
        ),
      ),
    );
  }

  return $extra;
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 *
 * Shows the form only on Node Edit forms.
 */
function workflow_form_node_form_alter(&$form, &$form_state, $form_id) {
  return _workflow_form_alter($form, $form_state, $form_id);
}

/**
 * Implements hook_form_BASE_FORM_ID_alter().
 *
 * Shows the form only on Comment forms.
 */
function workflow_form_comment_form_alter(&$form, &$form_state, $form_id) {
  return _workflow_form_alter($form, $form_state, $form_id);
}

/**
 * Used to Implement hook_form_alter().
 *
 * Is now a subfunction of workflow_form_BASE_FORM_ID_alter().
 * This is more performant, since it is called only on form with correct BASE_FORM_ID.
 *
 * @param object &$node
 *
 * @return array
 *
 * @see http://bryanbraun.com/2013/08/17/using-hook-form-base-form-id-alter
 */
function _workflow_form_alter(&$form, &$form_state, $form_id) {
  // Set node to #node if available or load from nid value.
  $node = isset($form['#node']) ? $form['#node'] : node_load($form['nid']['#value']);
  $bundle = $node->type;
  $entity= $node;
  $entity_type = 'node';

  // Skip if there are no Node API workflows.
  if (!workflow_get_workflow_type_map_by_type($bundle)) {
    return;
  }
  if ($workflow = workflow_get_workflows_by_type($bundle)) {
    $workflow_entities = variable_get('workflow_' . $bundle, array());
    // Abort if the entity type of the form is not in the list that the user
    // wants to display the workflow form on.
    if (!in_array($form['#entity_type'], $workflow_entities)) {
      return;
    }
/*
      $form['#wf'] = $workflow;
      $form['workflow'] = array(
        '#type' => 'fieldset',
        '#title' => $label,
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#weight' => 10,
      );
*/
    // Emulate a Field API interface.
    $field = array();
    $field['field_name'] = '';
    $field['settings']['wid'] = $workflow->wid;
    $field['settings']['widget'] = $workflow->options;
    $field['settings']['widget']['options'] = 'radios';
    $field['settings']['widget']['comment'] = !empty($workflow->options['comment_log_node']); // vs. ['comment_log_tab']; 
    $field['settings']['widget']['current_status'] = TRUE;

    $instance = array();
    $instance['widget']['settings'] = $workflow->options;
    // Do not include the default 'Update Workflow' button, since we are already in an Edit form.
    $instance['widget']['settings']['submit_function'] = '';

    // Include the 'workflow form'. $form is modified by reference.
//    workflow_node_form($form, $form_state, t('Change !name state', array('!name' => $label)), $label, $current_sid, $choices, $timestamp, $comment);
    workflow_transition_form($form, $form_state, $field, $instance, $entity_type, $entity);
  }
}
