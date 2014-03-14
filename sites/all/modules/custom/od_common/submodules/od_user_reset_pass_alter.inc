<?php
/**
 * @file
 */
 
/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_form_user_pass_alter(&$form, &$form_state) {
  unset($form['name']['#title']);
  $form['name']['#attributes'] = array('placeholder' => t('E-mail'));
}
