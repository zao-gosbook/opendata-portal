<?php
/**
 * @file
 */
 
/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function  _od_common_form_user_profile_form_alter(&$form, &$form_state) {
  $form['privatemsg']['#type'] = 'container';
}
