<?php
/**
 * @file
 */
 
/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_common_form_user_login_alter(&$form, &$form_state) {
  unset($form['name']['#title']);
  $form['name']['#attributes'] = array('placeholder' => t('E-mail'));
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
  $form['#validate'][2] = 'od_common_user_login_final_validate';
}


/**
 * The final validation handler on the login form.
 *
 * Sets a form error if user has not been authenticated, or if too many
 * logins have been attempted. This validation function should always
 * be the last one.
 */
function od_common_user_login_final_validate($form, &$form_state) {
  if (empty($form_state['uid'])) {
    // Always register an IP-based failed login event.
    flood_register_event('failed_login_attempt_ip', variable_get('user_failed_login_ip_window', 3600));
    // Register a per-user failed login event.
    if (isset($form_state['flood_control_user_identifier'])) {
      flood_register_event('failed_login_attempt_user', variable_get('user_failed_login_user_window', 21600), $form_state['flood_control_user_identifier']);
    }

    if (isset($form_state['flood_control_triggered'])) {
      if ($form_state['flood_control_triggered'] == 'user') {
        form_set_error('name', format_plural(variable_get('user_failed_login_user_limit', 5), 'Sorry, there has been more than one failed login attempt for this account. It is temporarily blocked. Try again later or <a href="@url">request a new password</a>.', 'Sorry, there have been more than @count failed login attempts for this account. It is temporarily blocked. Try again later or <a href="@url">request a new password</a>.', array('@url' => url('user/password'))));
      }
      else {
        // We did not find a uid, so the limit is IP-based.
        form_set_error('name', t('Sorry, too many failed login attempts from your IP address. This IP address is temporarily blocked. Try again later or <a href="@url">request a new password</a>.', array('@url' => url('user/password'))));
      }
    }
    else {
      form_set_error('name', t('Sorry, unrecognized username or password. <a href="@password">Have you forgotten your password?</a>', array('@password' => url('user/password', array('query' => array('name' => $form_state['input']['name']))))));
      watchdog('user', 'Login attempt failed for %user.', array('%user' => $form_state['values']['name']));
    }
  }
  elseif (isset($form_state['flood_control_user_identifier'])) {
    // Clear past failures for this user so as not to block a user who might
    // log in and out more than once in an hour.
    flood_clear_event('failed_login_attempt_user', $form_state['flood_control_user_identifier']);
  }
}
