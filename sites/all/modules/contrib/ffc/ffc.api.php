<?php

/**
 * @file
 * Hooks provided by Field formatter conditions.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Implements hook_ffc_conditions_info().
 *
 * This hook can be put in a separate file called
 * MODULE.ffc_conditions.inc.
 *
 * Returns an array of conditions where the keys are
 * an unique name and the value is an array with following keys:
 *   - title: the label of the condition.
 *   - field types: (optional) A collection of field types
 *     on which this conditions only applies.
 *   - no form: (optional) whether this condition has no form.
 *
 * The key is used to construct the form and the execute callback.
 */
function hook_ffc_conditions_info() {
  $conditions = array();

  $conditions['show'] = array(
    'title' => t('Hide field when target is not empty'),
    'field types' => array('image'),
  );

  return $conditions;
}

/**
 * Implements ffc_condition_form_CONDITION().
 *
 * Present the condition form. This is an automatically generated function
 * callback where CONDITION is the key you return in hook_ffc_conditions_info.
 *
 * This function can be put in a separate
 * file called MODULE.ffc_conditions.inc as the conditions are
 * loaded only when configuring. In case you need helper files
 * for the form, you can also put them in there. The ffc module
 * also has a couple of helper functions that are available there.
 *
 * @param $context
 *   A collection with the following keys:
 *     - settings: all display settings, if any.
 *     - entity_type: The name of the entity type.
 *     - bundle: The name of the bundle.
 *     - view_mode: the name of the view mode.
 *     - field_name: the name of the field.
 *     - ds_layout: whether a Display Suite layout is configured.
 *     - ds_field: whether this is a Display Suite field.
 * @param $configuration
 *   A collection of the current configuration for this condition.
 *
 * @return
 *   A Form API definition.
 */
function ffc_condition_form_hide_source($context, $configuration) {
  $form = array();

  $form['condition'] = array(
    '#type' => 'select',
    '#title' => t('Select an option'),
    '#options' => array(
       '0' => 'Option 1',
       '1' => 'Options 2',
    ),
    '#default_value' => isset($configuration['target']) ? $configuration['target'] : '',
  );

  return $form;
}

/**
 * Implements ffc_condition_execute_CONDITION().
 *
 * Executes the condition. This is an automatically generated function
 * callback where CONDITION is the key you return in hook_ffc_conditions_info.
 *
 * @param $build
 *   The current entity that is being creating for output.
 * @param $source
 *   The source field for which this condition is executed.
 * @param $configuration
 *   The configuration of the condition.
 * @param $context
 *   The current context of the field in which it is being rendered.
 */
function ffc_condition_execute_CONDITION(&$build, $source, $configuration, $context) {
  if (!empty($build[$configuration['target']]['#items'])) {
    $build[$source]['#access'] = FALSE;
  }
}

/**
 * @} End of "addtogroup hooks".
 */

