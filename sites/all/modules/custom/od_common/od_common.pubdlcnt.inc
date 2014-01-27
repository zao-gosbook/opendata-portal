<?php

/**
 * This file contains functions and other things related with public_download_count module's functionality
 * @file
 */

function od_common_pubdlcnt_count($fid_or_file) {
  $fid = is_numeric($fid_or_file) ? $fid_or_file : $fid_or_file->fid;

  return db_query('SELECT count FROM {pubdlcnt} WHERE :fid', array(':fid' => $fid))->fetchField();
}


function od_common_pubdlcnt_node_content_type_edit_form($form, &$form_state) {
  ctools_include('modal');
  ctools_include('ajax');
  ctools_include('content');
  $conf = $form_state['conf'];

  $wrapper_id = 'od-common-pubdlcnt-node-ajax-form-wrapper';
  $ajax_config = array(
    'wrapper' => $wrapper_id,
    'callback' => '_od_common_pubdlcnt_node_content_type_edit_form_ajax_callback',
    'method' => 'replace',
  );

  $form['context']['#ajax'] = $ajax_config + array('event' => 'change');

  //$build = &$form['ajax_block'];
  $form['#prefix'] = '<div id="'.$wrapper_id.'">';
  $form['#suffix'] = '</div>';
  $form['test']['#markup'] = date('c', time());

  $form['submits']['button'] = array(
    '#type' => 'submit',
    '#value' => 'AJAX test',
    '#ajax' => $ajax_config + array('event' => 'click'),
  );

  return $form;
}

function od_common_pubdlcnt_node_content_type_edit_form_submit($form, &$form_state) {
  ctools_include('modal');
  ctools_include('ajax');
  ctools_include('content');
  form_state_values_clean($form_state);
  $form_state['conf'] = $form_state['values'];
}

function _od_common_pubdlcnt_node_content_type_edit_form_ajax_callback($form, $form_state) {
  ctools_include('modal');
  ctools_include('ajax');
  ctools_include('content');
  return $form;
}