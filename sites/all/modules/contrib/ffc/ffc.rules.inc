<?php

/**
 * @file
 * Rules integration for Field formatter conditions.
 */

/**
 * Implements hook_rules_data_info().
 */
function ffc_rules_data_info() {
  return array(
    'ffc_element' => array(
      'label' => t('FFC element'),
      'wrap' => TRUE,
    ),
    'ffc_field' => array(
      'label' => t('FFC field'),
    ),
    'ffc_empty' => array(
      'label' => t('FFC empty parameters'),
    ),
  );
}

/**
 * Implements hook_rules_event_info().
 */
function ffc_rules_event_info() {

  $base = array('variables' => array());
  $entity_info = entity_get_info();
  foreach ($entity_info as $entity_type => $info) {
    $base['variables'][$entity_type] = array('type' => $entity_type, 'label' => $info['label']);
  }

  return array(
    'field_is_rendered' => array(
      'label' => t('A field is rendered'),
      'group' => t('Field formatter conditions'),
    ) + $base,
  );
}

/**
 * Implements hook_rules_action_info().
 */
function ffc_rules_action_info() {

  $base_parameters = array(
    'ffc_element' => array(
      'type' => 'element',
      'label' => t('Element'),
      'optional' => TRUE,
    ),
    'ffc_field' => array(
      'type' => 'element',
      'label' => t('Field'),
      'optional' => TRUE,
    ),
  );

  return array(
    'ffc_rules_hide_fields' => array(
      'label' => t('Hide a field'),
      'group' => t('Field formatter conditions'),
      'parameter' => array() + $base_parameters,
    ),
    'ffc_rules_change_image_style' => array(
      'label' => t('Change image style'),
      'group' => t('Field formatter conditions'),
      'parameter' => $base_parameters + array(
        'ffc_empty' => array(
          'allow null' => TRUE,
          'optional' => TRUE,
          'type' => 'ffc_empty',
          'label' => t('Image style'),
          'ui class' => 'RulesDataUIText',
          'options list' => 'ffc_rules_change_image_style_options',
        ),
      ),
    ),
  );
}

/**
 * Rules options list for image styles.
 */
function ffc_rules_change_image_style_options() {
  $options = array();
  $image_styles = image_styles();
  foreach (array_keys($image_styles) as $image_style) {
    $options[$image_style] = $image_style;
  }
  return $options;
}

/**
 * Rules callback: hide fields.
 */
function ffc_rules_hide_fields($ffc_element, $ffc_field) {
  $ffc_element->fired = TRUE;
  $ffc_element->element[$ffc_field]['#access'] = FALSE;
}

/**
 * Rules callback: change image style.
 */
function ffc_rules_change_image_style($ffc_element, $ffc_field, $empty, $configuration) {
  $ffc_element->fired = TRUE;
  foreach (element_children($ffc_element->element[$ffc_field]) as $key) {
    $ffc_element->element[$ffc_field][$key]['#image_style'] = $configuration['ffc_empty'];
  }
}

/**
 * Helper function to hide our optional element and field data selectors.
 */
function _ffc_form_rules_ui_element_alter(&$form) {
  if (isset($form['parameter']) && isset($form['parameter']['ffc_element'])) {
    $form['parameter']['ffc_element']['#access'] = FALSE;
    $form['parameter']['ffc_field']['#access'] = FALSE;
  }
}
