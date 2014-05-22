<?php
/**
 * @file
 * analyst_instruments.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function analyst_instruments_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function analyst_instruments_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
