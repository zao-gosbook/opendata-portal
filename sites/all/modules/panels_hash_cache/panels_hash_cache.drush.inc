<?php


/**
 * Implementation of hook_drush_cache_clear().
 */
 
 function panels_hash_cache_drush_cache_clear(&$types) { 
  $types['panels hash cache'] = 'panels_hash_cache_clear';
 }
  
 function panels_hash_cache_clear() {
  cache_clear_all('panels-hash-cache','panels_hash_cache',TRUE); 
 }
