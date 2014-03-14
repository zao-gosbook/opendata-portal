<?php
/**
 * @file
 */

/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_for_user_pass_reset_form_alter(&$form, &$form_state) {
  $timeout = variable_get('user_password_reset_timeout', 86400);
  $timestamp = arg(3);
  $form['message'] = array('#markup' => t('<p> This is a one-time login for %user_name and will expire on %expiration_date.</p><p>Click on this button to log in to the site and change your password.</p>', array('%user_name' => $account->name, '%expiration_date' => format_date($timestamp + $timeout, 'custom', 'd.m.Y, H:i'))));
}
