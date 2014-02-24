<?php
/**
 * @file
 * publisher_requests.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function publisher_requests_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entityform_type().
 */
function publisher_requests_default_entityform_type() {
  $items = array();
  $items['request_to_become_a_publisher'] = entity_import('entityform_type', '{
    "type" : "request_to_become_a_publisher",
    "label" : "\\u0417\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c",
      "submit_confirm_msg" : "\\u003Cnone\\u003E",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0438",
      "submission_text" : {
        "value" : "\\u0412\\u0430\\u0448\\u0430 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0430 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u0430 \\u043d\\u0430 \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u044e. \\u041a\\u0430\\u043a \\u0442\\u043e\\u043b\\u044c\\u043a\\u043e \\u043e\\u043d\\u0430 \\u0431\\u0443\\u0434\\u0435\\u0442 \\u043e\\u0431\\u0440\\u0430\\u0431\\u043e\\u0442\\u0430\\u043d\\u0430, \\u0432\\u044b \\u043f\\u043e\\u043b\\u0443\\u0447\\u0438\\u0442\\u0435 \\u0443\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043d\\u0430 \\u0430\\u0434\\u0440\\u0435\\u0441 \\u044d\\u043b\\u0435\\u043a\\u0442\\u0440\\u043e\\u043d\\u043d\\u043e\\u0439 \\u043f\\u043e\\u0447\\u0442\\u044b, \\u0443\\u043a\\u0430\\u0437\\u0430\\u043d\\u043d\\u043e\\u0439 \\u0432 \\u043b\\u0438\\u0447\\u043d\\u043e\\u0439 \\u0438\\u043d\\u0444\\u043e\\u0440\\u043c\\u0430\\u0446\\u0438\\u0438. ",
        "format" : "full_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "6" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "full_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/request-to-become-a-publisher",
        "alias" : "become-a-publisher",
        "language" : "und"
      }
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function publisher_requests_node_info() {
  $items = array(
    'publisher_request' => array(
      'name' => t('Заявка на публикаторство'),
      'base' => 'node_content',
      'description' => t('This node type has been created by rules action. Publisher request workflow.'),
      'has_title' => '0',
      'title_label' => '',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_rules_link().
 */
function publisher_requests_default_rules_link() {
  $items = array();
  $items['approve_publisher_request'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c",
      "link_type" : "javascript",
      "bundles" : { "publisher_request" : "publisher_request" },
      "entity_link" : 1
    },
    "name" : "approve_publisher_request",
    "label" : "\\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u0438\\u0442\\u044c \\u0437\\u043d\\u0430\\u0447\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
    "path" : "approve_publisher_request",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['on_completion_publisher_request'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443",
      "link_type" : "token",
      "bundles" : { "publisher_request" : "publisher_request" },
      "entity_link" : 1
    },
    "name" : "on_completion_publisher_request",
    "label" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0443 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
    "path" : "on_completion_publisher_request",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['reject_publisher_request'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c",
      "link_type" : "token",
      "bundles" : { "publisher_request" : "publisher_request" },
      "entity_link" : 1
    },
    "name" : "reject_publisher_request",
    "label" : "\\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u0438\\u0442\\u044c \\u0437\\u043d\\u0430\\u0447\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
    "path" : "reject_publisher_request",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  return $items;
}
