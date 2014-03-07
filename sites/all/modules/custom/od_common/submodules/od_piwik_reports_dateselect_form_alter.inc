<?php
/**
 * @file
 */
 
/**
 *  Implements hook_form_FORM_ID_alter()
 **/
function  _od_common_form_piwik_reports_dateselect_form_alter(&$form, &$form_state) {
  $form['basic']['inline']['period']['#type'] = 'radios';
  $form['basic']['inline']['submit']['#attributes']['class'][] = 'element-invisible';
  $form['basic']['#type'] = 'container';
  $form['basic']['inline']['period']['#attached']['js'][] = array(
    'data' => drupal_get_path('module', 'od_common') . '/js/commands/piwik_radios_select_submit.js', 
    'type' => 'file',
  );
}
