<?php
/**
 * @file
 */
 
/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_form_user_login_alter(&$form, &$form_state) {
  unset($form['name']['#title']);
  $form['name']['#attributes'] = array('placeholder' => 'Email');
  unset($form['pass']['#title']);
  $form['pass']['#attributes'] = array('placeholder' => t('Password'));
  $form['custom_text'] = array(
    '#markup' => '<p>If you have not registered, return to <a href="/user/register">register</a>.</p>',
    '#weight' => 5000,
  );
}
