<?php
/**
 * @file
 * opendata_query.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function opendata_query_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_rules_link().
 */
function opendata_query_default_rules_link() {
  $items = array();
  $items['answered_opendata_query'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041e\\u0442\\u0432\\u0435\\u0442 \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d",
      "link_type" : "token",
      "bundles" : { "opendata_query" : "opendata_query" },
      "entity_link" : 1
    },
    "name" : "answered_opendata_query",
    "label" : "\\u041e\\u0442\\u0432\\u0435\\u0442 \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d \\u043d\\u0430 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435",
    "path" : "answered_opendata_query",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['approve_opendata_query'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c",
      "link_type" : "token",
      "bundles" : { "opendata_query" : "opendata_query" },
      "entity_link" : 1
    },
    "name" : "approve_opendata_query",
    "label" : "\\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435",
    "path" : "approve_opendata_query",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['dataset_produced_opendata_query'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u043f\\u0440\\u0435\\u0434\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d",
      "link_type" : "token",
      "bundles" : { "opendata_query" : "opendata_query" },
      "entity_link" : 1
    },
    "name" : "dataset_produced_opendata_query",
    "label" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043f\\u0440\\u0435\\u0434\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d \\u043f\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0443 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435",
    "path" : "produced_opendata_query",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['reject_opendata_query'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c",
      "link_type" : "token",
      "bundles" : { "opendata_query" : "opendata_query" },
      "entity_link" : 1
    },
    "name" : "reject_opendata_query",
    "label" : "\\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435",
    "path" : "reject_openda_query",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['send_to_ministry_opendata_query'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u0432 \\u0433\\u043e\\u0441\\u043e\\u0440\\u0433\\u0430\\u043d",
      "link_type" : "token",
      "bundles" : { "opendata_query" : "opendata_query" },
      "entity_link" : 1
    },
    "name" : "send_to_ministry_opendata_query",
    "label" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 \\u0432 \\u043c\\u0438\\u043d\\u0438\\u0441\\u0442\\u0435\\u0440\\u0441\\u0442\\u0432\\u043e",
    "path" : "send_to_ministry_opendata_query",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  return $items;
}
