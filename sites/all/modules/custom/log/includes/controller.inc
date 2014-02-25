<?php

/**
 * Common function for create log.
 */
function log_event($vars = array()) {
  $log = new LogEntity($vars, 'log');
  module_invoke_all('log_presave', $log);
  $log->save();
  module_invoke_all('log_insert', $log);

  return $log;
}

/**
 * Load a log entry.
 */
function log_load($lid, $reset = FALSE) {
  return reset(log_load_multiple(array($lid), array(), $reset));
}

/**
 * Load multiple log entries based on certain conditions.
 */
function log_load_multiple($lids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('log', $lids, $conditions, $reset);
}

/**
 * Delete single log entry.
 */
function log_delete($lid) {
  log_delete_multiple(array($lid));
}

/**
 * Delete multiple log entries.
 */
function log_delete_multiple($lids) {
  entity_delete_multiple('log', $lids);
}

/**
 * Get log entity uri.
 */
function log_uri($log) {
  $uri = array(
    'path' => 'log/' . $log->lid,
  );

  return $uri;
}

/**
 * Get log title.
 */
function log_title() {
  return 'Log'; //dk
}
