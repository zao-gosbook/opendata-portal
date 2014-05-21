<?php
/**
 * @file
 * generation_api_key.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function generation_api_key_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entityform_type().
 */
function generation_api_key_default_entityform_type() {
  $items = array();
  $items['get_api_key'] = entity_import('entityform_type', '{
    "type" : "get_api_key",
    "label" : "Get Key to API",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "Get Key",
      "submit_confirm_msg" : "",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "1" : 0, "6" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "get-api-key",
      "instruction_pre" : {
        "value" : "\\u0418\\u043d\\u0441\\u0442\\u0440\\u0443\\u043a\\u0446\\u0438\\u044f \\u043f\\u043e \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d\\u0438\\u044e \\u043a\\u043b\\u044e\\u0447\\u0430.",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}
