<?php
/**
 * @file
 */

/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function  _od_common_idea_node_form_alter(&$form, &$form_state) {
  global $user;
  if ($user->uid <> 1) {
    if (count($form['workflow']['workflow_options']['#options']) == 1 && $form['workflow']['workflow_options']['#type'] = 'radios') {
      $form['workflow']['#attributes']['class'][] = 'element-invisible';
    } elseif ($form['workflow']['workflow_options']['#type'] == 'item') {
      $form['workflow']['#attributes']['class'][] = 'element-invisible';
    }
  }
}
