<?php
/**
 * @file
 */
 
/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function  _od_common_form_user_profile_form_alter(&$form, &$form_state) {
  $form['privatemsg']['#type'] = 'container';
  
  $form['account']['check'] = array(
    '#type' => 'checkbox',
    '#title' => t('Change password'),
    '#weight' => -4,
  );
  
  $form['account']['pass_reset'] = array(
    '#type' => 'container',
    'pass' => $form['account']['pass'],
    '#weight' => -3,
    '#states' => array(
      "visible" => array(
        ':input[name="check"]' => array("checked" => TRUE),
      ),
    ),
  );
  
  unset($form['account']['pass']);
}
