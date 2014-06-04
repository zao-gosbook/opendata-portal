<?php
/**
 * @file
 */

/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function _od_commmon_form_get_api_key_form_alter(&$form, &$form_state) {
  if (current_path()  == 'get-api-key') {
    $form['my_captcha_element'] = array(
      '#type' => 'captcha',
      '#captcha_type' => 'draggable_captcha/Draggable Captcha',
    );

    $form['key_message'] = array(
      '#markup' => _api_key_message(),
    );

    $form['#validate'][] = 'od_common_session_writer_user_got_key_validate';
  }
}

/**
 * @return null|string.
 */
function _api_key_message() {
  if (isset($_SESSION['got_key'])) {
    global $user;
    $user = user_load($user->uid);
    return t("<div class='your-key'>Your key: <span class='key'>@key</span></div>", array('@key' => $user->field_user_current_api_key['und'][0]['value']));
  }
}

/*
 * Submit handler for the user registration form.
 */
function od_common_session_writer_user_got_key_validate($form, &$form_state) {
  if (!form_get_errors()) {
    $_SESSION['got_key'] = TRUE;
  }
}