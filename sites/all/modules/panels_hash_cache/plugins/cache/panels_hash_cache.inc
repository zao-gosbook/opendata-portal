<?php
// $Id: simple.inc,v 1.1.2.5 2011/01/07 20:59:09 merlinofchaos Exp $

/**
 * @file
 * Provides hash caching for panels
 * 
 * Copyright (c) 2010-2011 Board of Trustees, Leland Stanford Jr. University
 * This software is open-source licensed under the GNU Public License Version 2 or later
 * The full license is available at http://www.gnu.org/licenses/gpl-2.0.html
 */

// Plugin definition
$plugin = array(
  'title' => t("Hash Cache"),
  'description' => t('Hash-based cache with automated or triggered expiration'),
  'cache get' => 'panels_hash_cache_get_cache',
  'cache set' => 'panels_hash_cache_set_cache',
  'cache clear' => 'panels_hash_cache_clear_cache',
  'settings form' => 'panels_hash_cache_settings_form',
  'settings form submit' => 'panels_hash_cache_settings_form_submit',
  'defaults' => array(
    'lifetime' => 15,
    'granularity' => array(),
  ),
);

/**
 * Get cached content.
 */
function panels_hash_cache_get_cache($conf, $display, $args, $contexts, $pane = NULL) {
  // Optionally allow us to clear the cache from the URL using a key,
  // This lets us, for example, to automatically re-generate a cache using cron
  // hitting a url. This way users never see uncached content.
  if ($key = variable_get('panels_hash_cache_reset_key', FALSE)) {
    if (isset($_GET['panels-hash-cache-reset']) && $_GET['panels-hash-cache-reset'] == $key) {
     return FALSE;
    }
  }
  
  $cid = panels_hash_cache_get_id($conf, $display, $args, $contexts, $pane);
  
  $cache = cache_get($cid, 'panels_hash_cache');
  if (!$cache) {
    return FALSE;
  }
  
  if ((time() - $cache->created) > $conf['lifetime']) {
    return FALSE;
  }
  
  return $cache->data;
}

/**
 * Set cached content.
 */
function panels_hash_cache_set_cache($conf, $content, $display, $args, $contexts, $pane = NULL) {
  $cid = panels_hash_cache_get_id($conf, $display, $args, $contexts, $pane);
  cache_set($cid, $content,'panels_hash_cache', ($conf['lifetime'] ? $conf['lifetime'] : CACHE_PERMANENT));
}

/**
 * Clear cached content.
 *
 * Cache clears are always for an entire display, regardless of arguments.
 */
function panels_hash_cache_clear_cache($display) {
  $cid = 'panels-hash-cache';

  // This is used in case this is an in-code display, which means did will be something like 'new-1'.
  if (isset($display->owner) && isset($display->owner->id)) {
    $cid .= ':' . $display->owner->id;
  }
  $cid .= ':' . $display->did;

  cache_clear_all($cid, 'panels_hash_cache', TRUE);
}

/**
 * Figure out an id for our cache based upon input and settings.
 */
function panels_hash_cache_get_id($conf, $display, $args, $contexts, $pane) {
  $id = 'panels-hash-cache';
  
  // This is used in case this is an in-code display, which means did will be something like 'new-1'.
  if (isset($display->owner) && isset($display->owner->id)) {
    $id .= '-' . $display->owner->id;
  }
  $id .= '-' . $display->cache_key;
  
  if ($pane) {
    $id .= '-' . $pane->pid;
  }

  if (user_access('view pane admin links')) {
    $id .= '-admin';
  }
  
  // For each selected ganularity situation, add it to the "hashable-string"
  // This hashable string becomes our cache-key (after it's hashed to shorten it)
  $hashable_string = '';
  
  if ($conf['granularity']['args']) {
    foreach ($args as $arg) {
      $hashable_string .= $arg;
    }
  }
  if ($conf['granularity']['context']) {
    if (!is_array($contexts)) {
      $contexts = array($contexts);
    }
    foreach ($contexts as $context) {
      $hashable_string .= serialize($context->data);
    }
  }
  if ($conf['granularity']['path']) {
    $hashable_string .= implode('/', arg());
  }
  
  if ($conf['granularity']['url']) {
    $url = parse_url('http://'.$_SERVER['HTTP_HOST'].$_SERVER['REQUEST_URI']);
    
    // If panels-hash-cache-reset is set, then unset it from the query to hash
    if (isset($_GET['panels-hash-cache-reset']) && $key = $_GET['panels-hash-cache-reset']) {
      $url['query'] = str_replace('panels-hash-cache-reset='.$key,'',$url['query']);
      $url['query'] = trim($url['query'],"&");
    }
    
    $hashable_string = $url['host'].$url['path'];
    if(!empty($url['query'])) {
      $hashable_string .= $url['query'];
    }
  }
  
  if ($conf['granularity']['user']) {
    // For the user we hash on their UID, username, email and roles. In D7 we will have an "updated" timestamp to hash on
    global $user;
    $hashable_string .= $user->uid.$user->name.$user->mail.serialize($user->roles);
  }
  if ($conf['granularity']['user_role']) {
    global $user;
    $hashable_string .= serialize($user->roles);
  }
  
  if ($hashable_string) {
    $id .= '-'.sha1($hashable_string);
  }
  
  if (module_exists('locale')) {
    global $language;
    $id .= '-' . $language->language;
  }
  
  if(isset($pane->configuration['use_pager']) && $pane->configuration['use_pager'] == 1) {
    $id .= '-p' . check_plain($_GET['page']);
  }
  
  return $id;
}

function panels_hash_cache_settings_form($conf, $display, $pid) {
  $options = drupal_map_assoc(array(15, 30, 60, 120, 180, 240, 300, 600, 900, 1200, 1800, 3600, 7200, 14400, 28800, 43200, 86400, 172800, 259200, 345600, 604800), 'format_interval');
  $form['lifetime'] = array(
    '#title' => t('Maximum Lifetime'),
    '#type' => 'select',
    '#options' => $options,
    '#default_value' => $conf['lifetime'],
    '#description' => t('The cache will be expired after this amount of time elapses. Note that the cache will also automatically be rotated (expired) if any of the granularity-circumstances (set below) are changed or updated.')
  );

  $form['granularity'] = array(
    '#title' => t('Granularity'),
    '#type' => 'checkboxes',
    '#options' => array(
      'args' => t('Arguments'),
      'context' => t('Context'),
      'user' => t('Active User'),
      'user_role' => t('Active User\'s Role'),
      'url' => t('Full URL (including query strings)'),
      'path' => t('Drupal Menu Path and Arguments'),
    ),
    '#description' => t('The methods in which you wish to store and expire the cache. A change in any of these things will result in a new cache being generated. If more than one is selected, a unique cache will be created for that combination and the cache expires upon a change if any of the components.'),
    '#default_value' => $conf['granularity'],
  );
  
  return $form;
}

