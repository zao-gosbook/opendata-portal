<?php
/**
 * @file
 */

/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_preprocess_wizard_form_alter(&$form, &$form_state) {
  $form['field_link_passport']['#element_validate'] = array('preprocess_wizard_validate');
}

/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_dataset_actualization_form_alter(&$form, &$form_state) {
  $form['field_link_passport']['#element_validate'] = array('preprocess_wizard_validate');
}

/**
 *  Custom validate function.
 **/
function preprocess_wizard_validate($element, &$form_state, $form) {
  if ($form_state['values']['field_dataset_variant']['und'] <> 'upload' && empty($form_state['input']['field_link_passport']['und'][0]['url'])) {
    form_error($element, t('In case you have not downloaded file , the "Link to this page on the website owner" becomes mandatory.'));
  }
}
