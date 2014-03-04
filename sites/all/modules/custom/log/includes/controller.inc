<?php

/**
 * Create a log entity.
 */
function log_create($values = array()) {
  return entity_create('log', $values);
}

/**
 * Save a log entity.
 */
function log_save($log) {
  return entity_save('log', $log);
}

/**
 * Load a log entity.
 */
function log_load($lid, $reset = FALSE) {
  return reset(log_load_multiple(array($lid), array(), $reset));
}

/**
 * Load multiple log entities based on certain conditions.
 */
function log_load_multiple($lids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('log', $lids, $conditions, $reset);
}

/**
 * Delete single log entity.
 */
function log_delete($lid) {
  log_delete_multiple(array($lid));
}

/**
 * Delete multiple log entities.
 */
function log_delete_multiple($lids) {
  entity_delete_multiple('log', $lids);
}
