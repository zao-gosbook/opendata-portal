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
  $form['reset_pass_text'] = array(
    '#markup' => t('<p>Forgot your password? You can restore it <a href="/user/password">here</a>.</p>'),
    '#weight' => 4999,
  );
  $form['register_text'] = array(
    '#markup' => t('<p>If you have not registered, return to <a href="/user/register">register</a>.</p>'),
    '#weight' => 5000,
  );
}
