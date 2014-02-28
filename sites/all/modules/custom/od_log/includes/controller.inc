<?php

/**
 * Create opendata log.
 */
function od_log($message, $importance = 'status', $type = NULL, $organization_id = NULL, $dataset_id = NULL, $user_id = NULL) {
  $vars = array();
  $vars['uid'] = (!empty($user_id) && is_numeric($user_id)) ? $user_id : NULL;
  $vars['message'] = $message;
  $vars[OD_COMMON_FIELD_LOG_IMPORTANCE_TYPE] = array(LANGUAGE_NONE => array('0' => array('value' => $importance)));
  $vars[OD_COMMON_FIELD_LOG_EVENT_TYPE] = !empty($type) ? array(LANGUAGE_NONE => array('0' => array('value' => $type))) : array();
  $vars[OD_COMMON_FIELD_LOG_CURATOR_WAS_NOTIFIED] = array(LANGUAGE_NONE => array('0' => array('value' => 0)));

  if (!empty($organization_id)) {
    $vars[OD_COMMON_FIELD_LOG_ORGANIZATION] = array(LANGUAGE_NONE => array('0' => array('target_id' => $organization_id)));
  }

  if (!empty($dataset_id)) {
    $vars[OD_COMMON_FIELD_LOG_DATASET] = array(LANGUAGE_NONE => array('0' => array('target_id' => $dataset_id)));
  }

  drupal_set_message($message, $importance);
  $log = log_create($vars);
  log_save($log);
}
