<?php
/**
 * @file
 * suggestions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function suggestions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function suggestions_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function suggestions_default_entityform_type() {
  $items = array();
  $items['add_suggestion'] = entity_import('entityform_type', '{
    "type" : "add_suggestion",
    "label" : "Add suggestion",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "Create",
      "submit_confirm_msg" : "\\u003Cnone\\u003E",
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
      "roles" : { "1" : "1", "2" : 0, "6" : 0, "3" : 0, "4" : 0, "5" : 0, "7" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u041d\\u0430 \\u044d\\u0442\\u043e\\u0439 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0435 \\u0432\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u0432\\u043d\\u0435\\u0441\\u0442\\u0438 \\u041f\\u0440\\u0435\\u0434\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e \\u0440\\u0430\\u0437\\u0432\\u0438\\u0442\\u0438\\u0435 \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b\\u0430, \\u043d\\u043e\\u0432\\u043e\\u0433\\u043e \\u043f\\u0440\\u0438\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u044f \\u0438\\u043b\\u0438 \\u0441\\u0435\\u0440\\u0432\\u0438\\u0441\\u0430. \\u041f\\u043e\\u0441\\u043b\\u0435 \\u043f\\u0440\\u043e\\u0432\\u0435\\u0440\\u043a\\u0438 \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c \\u041f\\u0440\\u0435\\u0434\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u0435 \\u0431\\u0443\\u0434\\u0435\\u0442 \\u0434\\u043e\\u0441\\u0442\\u0443\\u043f\\u043d\\u043e \\u0434\\u043b\\u044f \\u0432\\u0441\\u0435\\u0445 \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u0435\\u0439 \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0435 \\u00ab\\u041f\\u0440\\u0435\\u0434\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u044f\\u00bb.",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function suggestions_node_info() {
  $items = array(
    'suggestion' => array(
      'name' => t('Предложение'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название предложения'),
      'help' => '',
    ),
  );
  return $items;
}
