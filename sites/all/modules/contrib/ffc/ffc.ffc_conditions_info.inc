<?php

/**
 * @file
 * Hook implementations and API functions for Field formatter settings.
 */

/**
 * Implements hook_field_formatter_settings_form_alter().
 */
function _ffc_field_formatter_settings_form_alter(&$settings_form, $context, $conditions) {
  // Check if this is a Display Suite field.
  $ds = !empty($context['ds']);

  // Get display settings.
  if ($ds) {
    $field = $context['field'];
    $settings = array('conditions' => array());
    if (!empty($field['formatter_settings']['conditions'])) {
      $settings = array('conditions' => $field['formatter_settings']['conditions']);
    }
  }
  else {
    $settings = $context['instance']['display'][$context['view_mode']]['settings'];
  }

  // Get context variables.
  $entity_type = $context['form']['#entity_type'];
  $bundle = $context['form']['#bundle'];
  $view_mode = $context['form']['#view_mode'];
  $field_name = !$ds ? $context['field']['field_name'] : $context['field']['name'];
  $field_type = !$ds ? $context['field']['type'] : 'ds';

  $ffc_context = array(
    'settings' => $settings,
    'entity_type' => $entity_type,
    'bundle' => $bundle,
    'view_mode' => $view_mode,
    'field_name' => $field_name,
    'ds_layout' => !empty($context['form']['#ds_layout']),
    'ds_field' => !empty($context['ds']),
  );

  $settings_form['conditions'] = array(
    '#type' => 'fieldset',
    '#collapsed' => TRUE,
    '#collapsible' => TRUE,
    '#title' => t('Conditions'),
    '#weight' => 100,
  );

  $condition_options = array();
  foreach ($conditions as $key => $info) {

    // Check field types.
    if (!ffc_can_use_condition($info, $field_type)) {
      continue;
    }

    $condition_options[$key] = $info['title'];
  }

  // We don't iterate for now, this is to make sure we can have
  // multiple conditions in the future if we really need this.
  $settings_form['conditions'][0]['condition'] = array(
    '#type' => 'select',
    '#empty_option' => t('- Select a condition -'),
    '#options' => $condition_options,
    '#default_value' => isset($settings['conditions'][0]['condition']) ? $settings['conditions'][0]['condition'] : '',
    '#ajax' => array(
      '#submit' => array('ffc_field_ui_display_overview_multistep_submit'),
      'callback' => 'ffc_field_ui_display_overview_multistep_js',
      'wrapper' => 'field-display-overview-wrapper',
      'ffc_context' => $ffc_context,
    ),
  );

  // Get the form.
  if (isset($context['form_state']['values']['fields'][$field_name]['settings_edit_form']['settings']['conditions'][0]['condition'])) {
    $condition = $context['form_state']['values']['fields'][$field_name]['settings_edit_form']['settings']['conditions'][0]['condition'];
  }
  elseif (!empty($settings['conditions'][0]['condition'])) {
    $condition = $settings['conditions'][0]['condition'];
  }

  $open_field_set = FALSE;
  if (!empty($condition)) {
    $callback = 'ffc_condition_form_' . $condition;
    if (function_exists($callback)) {
      $open_field_set = TRUE;
      $configuration = !empty($settings['conditions'][0]['configuration']) ? $settings['conditions'][0]['configuration'] : array();
      $settings_form['conditions'][0]['configuration'] = $callback($ffc_context, $configuration);
    }
    elseif (!empty($conditions[$condition]['no form'])) {
      $open_field_set = TRUE;
      $settings_form['conditions'][0]['configuration'] = '';
    }
    else {
      $settings_form['conditions'][0]['error'] = array(
        '#markup' => t('The "%callback" function was not found.', array('%callback' => $callback))
      );
    }
  }

  if ($open_field_set) {
    $settings_form['conditions']['#collapsed'] = FALSE;
  }
}

/**
 * Ajax handler for changing conditions on the 'Manage display' screen.
 */
function ffc_field_ui_display_overview_multistep_js($form, &$form_state) {
  return $form['fields'];
}

/**
 * Form submission handler for changing conditions in field_ui_display_overview_form().
 */
function ffc_field_ui_display_overview_multistep_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}

/**
 * API function: get all fields for the current context.
 *
 * @param $context
 *   A collection of keys:
 *     - entity_type: The name of the entity type
 *     - bundle: The name of the bundle
 *     - view_mode: The name of the view mode
 *     - field_name: The name of the field
 *     - ds_layout: Whether a Display Suite layout is configured or not.
 *
 *    If you implement a condition form, simply pass on the $context variable
 *    that is passed to that callback to this function, otherwise you will
 *    have to construct it yourself.
 *
 * @param $exclude_current_field
 *   Whether to exclude the current field or not.
 *
 * @return
 *   A collection of fields on the current entity type and bundle
 */
function ffc_get_condition_fields($context, $exclude_current_field = TRUE) {

  // Get the context.
  $entity_type = $context['entity_type'];
  $bundle = $context['bundle'];
  $view_mode = $context['view_mode'];
  $current_field = $context['field_name'];

  $condition_fields = array();

  // Get Field API fields.
  $instances = field_info_instances($entity_type, $bundle);
  foreach ($instances as $field_name => $instance) {
    if ($field_name == $current_field && $exclude_current_field) {
      continue;
    }
    $condition_fields[$field_name] = $instance['label'];
  }

  // Get Display Suite fields.
  if (module_exists('ds') && !empty($context['ds_layout'])) {
    $ds_fields = ds_get_fields($entity_type);
    foreach ($ds_fields as $key => $field) {
      if ($key == $current_field && $exclude_current_field) {
        continue;
      }

      // Check on ui_limit.
      if (isset($field['ui_limit'])) {
        $continue = TRUE;
        foreach ($field['ui_limit'] as $limitation) {
          list($limit_bundle, $limit_view_mode) = explode('|', $limitation);
          if ($limit_bundle == '*' || $limit_bundle == $bundle) {
            if ($limit_view_mode == '*' || $limit_view_mode == $view_mode) {
              $continue = FALSE;
            }
          }
        }

        if ($continue) {
          continue;
        }
      }

      $condition_fields[$key] = $field['title'];
    }
  }

  return $condition_fields;
}

/**
 * Check whether this condition has field types and
 * if the current field type can use it.
 *
 * @param $condition
 *   The condition definition.
 * @param $current_field_type
 *   The current field type.
 *
 * @return
 *   TRUE if the field type can use the condition, FALSE otherwise.
 */
function ffc_can_use_condition($condition, $current_field_type) {

  if (!empty($condition['field types'])) {
    foreach ($condition['field types'] as $field_type) {
      if ($field_type === $current_field_type) {
        return TRUE;
      }
    }
    return FALSE;
  }

  return TRUE;
}

/**
 * Implements hook_ffc_conditions_info().
 */
function ffc_ffc_conditions_info() {

  $conditions = array(
    'hide_not_empty' => array(
      'title' => t('Hide when target field is not empty'),
    ),
    'hide_if_empty' => array(
      'title' => t('Hide if target field is empty'),
    ),
    'hide_no_string' => array(
      'title' => t('Hide when target field does not contain a string'),
    ),
    'hide_if_string' => array(
      'title' => t('Hide when target field contains a string'),
    ),
    'hide_on_role' => array(
      'title' => t('Hide when current user has role'),
    ),
    'hide_on_pages' => array(
      'title' => t('Hide on specific pages'),
    ),
    'hide_link_when_title_is_empty' => array(
      'title' => t('Hide link when title is empty'),
      'field types' => array('link_field'),
      'no form' => TRUE,
    ),
    'hide_date_time' => array(
      'title' => t('Hide date/time'),
      'field types' => array('datetime', 'date', 'datestamp'),
    ),
  );

  // Rules support.
  if (module_exists('rules')) {
    $conditions['rules_event'] = array(
      'title' => t('Use an event from rules'),
      'form callback' => 'ffc_condition_rules_form',
      'execute callback' => 'ffc_condition_rules_execute'
    );
  }

  return $conditions;
}

/**
 * Field formatter conditional form.
 *
 * Present the hide not empty form.
 */
function ffc_condition_form_hide_not_empty($context, $configuration) {
  $form = array();

  $form['target'] = array(
    '#type' => 'select',
    '#title' => t('Select target field'),
    '#options' => ffc_get_condition_fields($context),
    '#default_value' => isset($configuration['target']) ? $configuration['target'] : '',
  );

  return $form;
}

/**
 * Field formatter conditional form.
 *
 * Present the hide when empty form.
 */
function ffc_condition_form_hide_if_empty($context, $configuration) {
  $form = array();

  $form['target'] = array(
    '#type' => 'select',
    '#title' => t('Select target field'),
    '#options' => ffc_get_condition_fields($context),
    '#default_value' => isset($configuration['target']) ? $configuration['target'] : '',
  );

  return $form;
}

/**
 * Field formatter conditional form.
 *
 * Present the hide if string not found form.
 */
function ffc_condition_form_hide_no_string($context, $configuration) {
  $form = array();

  $form['target'] = array(
    '#type' => 'select',
    '#title' => t('Select target field'),
    '#options' => ffc_get_condition_fields($context),
    '#default_value' => isset($configuration['target']) ? $configuration['target'] : '',
  );
  $form['string'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter target string'),
    '#default_value' => isset($configuration['string']) ? $configuration['string'] : '',
  );

  return $form;
}

/**
 * Field formatter conditional form.
 *
 * Present the hide when string is present form.
 */
function ffc_condition_form_hide_if_string($context, $configuration) {
  $form = array();

  $form['target'] = array(
    '#type' => 'select',
    '#title' => t('Select target field'),
    '#options' => ffc_get_condition_fields($context),
    '#default_value' => isset($configuration['target']) ? $configuration['target'] : '',
  );
  $form['string'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter target string'),
    '#default_value' => isset($configuration['string']) ? $configuration['string'] : '',
  );

  return $form;
}

/**
 * Field formatter conditional form.
 *
 * Present the hide on role form.
 */
function ffc_condition_form_hide_on_role($context, $configuration) {
  $form = array();

  $form['roles'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Select roles'),
    '#options' => user_roles(),
    '#default_value' => isset($configuration['roles']) ? $configuration['roles'] : '',
  );

  return $form;
}

/**
 * Field formatter conditional form.
 *
 * Present the hide on pages form.
 */
function ffc_condition_form_hide_on_pages($context, $configuration) {
  $form = array();

  $form['visibility'] = array(
    '#type' => 'radios',
    '#options' => array(
      0 => t('All pages except those listed'),
      1 => t('Only the listed pages'),
    ),
    '#default_value' => isset($configuration['visibility']) ? $configuration['visibility'] : 0,
  );

  $form['pages'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter pages'),
    '#cols' => 10,
    '#default_value' => isset($configuration['pages']) ? $configuration['pages'] : '',
    '#description' => t("Specify pages by using their paths. Enter one path per line. * is used as wildcard."),
  );

  return $form;
}

/**
 * Field formatter conditional form.
 *
 * Present the hide date field.
 */
function ffc_condition_form_hide_date_time($context, $configuration) {
  $form = array();

  $form['field'] = array(
    '#title' => t('Hide after'),
    '#type' => 'radios',
    '#options' => array(
      'value' => t('from date has expired'),
      'value2' => t('to date has expired'),
    ),
    '#default_value' => isset($configuration['field']) ? $configuration['field'] : 'value',
  );

  return $form;
}

/**
 * Field formatter conditional form.
 *
 * Present the Rules selection form.
 */
function ffc_condition_form_rules_event($context, $configuration) {
  $form = array();

  $rule_options = array();
  $rules = entity_load('rules_config', FALSE, array('plugin' => 'reaction rule', 'active' => TRUE, 'event' => 'field_is_rendered'));
  foreach ($rules as $key => $rule) {
    $rule_options[$rule->name] = $rule->label;
  }

  $form['rule'] = array(
    '#type' => 'select',
    '#title' => t('Select a rule to execute'),
    '#options' => $rule_options,
    '#default_value' => isset($configuration['rule']) ? $configuration['rule'] : '',
    '#description' => t('Only rules from the "Field formatter conditions" group are supported.'),
  );

  return $form;
}
