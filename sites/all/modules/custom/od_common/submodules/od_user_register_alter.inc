<?php
/**
 * @file
 */
 
/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_form_user_register_form_alter(&$form, &$form_state) {
  $form['account']['mail']['#attributes'] = array('placeholder' => 'Email');
  $form['field_user_name']['und'][0]['value']['#attributes'] = array('placeholder' => t('Username'));
  $form['field_user_last_name']['und'][0]['value']['#attributes'] = array('placeholder' => t('Lastname'));
  $form['field_user_middle_name']['und'][0]['value']['#attributes'] = array('placeholder' => t('Patronymic'));
  $form['custom_text'] = array(
    '#markup' => t('<p>Already have an account? Return to <a href="/user/login">login</a>.</p>'),
    '#weight' => 5000,
  );
}
