<?php
/**
 * @file
 * Internationalization (i18n) hooks
 */

/**
 * Implements hook_i18n_object_info().
 */
function od_common_i18n_object_info() {
  module_load_include('i18n.inc', 'i18n_taxonomy');
  $info = i18n_taxonomy_i18n_object_info();

  $info['taxonomy_term']['class'] = 'od_common_i18n_taxonomy_term';

  return $info;
}

class od_common_i18n_taxonomy_term extends i18n_taxonomy_term {
  function localize_access() {
    return user_access('od_common localize access taxonomy_term');
  }
}