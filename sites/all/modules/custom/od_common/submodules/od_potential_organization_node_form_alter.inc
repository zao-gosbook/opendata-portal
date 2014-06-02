<?php
/**
 * @file
 */

/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_potential_organization_node_form_alter(&$form, &$form_state) {
  $form['field_organization_type']['#element_validate'] = array('organization_type_validation');
}

/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_organization_node_form_alter(&$form, &$form_state) {
  $form['field_organization_type']['#element_validate'] = array('organization_type_validation');
}

/**
 *  Custom validation function. 
 **/
function organization_type_validation($element, &$form_state, $form) {
  if ($element['und']['#value'] == '17') {
    form_error($element, t('You can\'t choose the State level, you should choose one of the three sublevels (Federal, Regional, Municipal)'));
  }
}
