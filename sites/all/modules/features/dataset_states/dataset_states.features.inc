<?php
/**
 * @file
 * dataset_states.features.inc
 */

/**
 * Implements hook_default_entityform_type().
 */
function dataset_states_default_entityform_type() {
  $items = array();
  $items['dataset_reworking'] = entity_import('entityform_type', '{
    "type" : "dataset_reworking",
    "label" : "\\u0414\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0430 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443",
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
      "roles" : { "4" : "4", "1" : 0, "2" : 0, "6" : 0, "3" : 0, "5" : 0, "7" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "full_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function dataset_states_flag_default_flags() {
  $flags = array();
  // Exported flag: "Доработка набора".
  $flags['dataset_reworked'] = array(
    'entity_type' => 'node',
    'title' => 'Доработка набора',
    'global' => 0,
    'types' => array(
      0 => 'dataset',
    ),
    'flag_short' => 'Набор доработан',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Снять флаг',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Набор отправлен на модерацию',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'ideas_list' => 0,
      'token' => 0,
      'search' => 0,
      'table' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => 'own',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'dataset_states',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_default_rules_link().
 */
function dataset_states_default_rules_link() {
  $items = array();
  $items['approve_dataset'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u043d\\u0430\\u0431\\u043e\\u0440",
      "link_type" : "token",
      "bundles" : { "dataset" : "dataset" },
      "entity_link" : 1
    },
    "name" : "approve_dataset",
    "label" : "\\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
    "path" : "approve_dataset",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  $items['send_dataset_to_rework'] = entity_import('rules_link', '{
    "settings" : {
      "text" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443",
      "link_type" : "token",
      "bundles" : { "dataset" : "dataset" },
      "entity_link" : 1
    },
    "name" : "send_dataset_to_rework",
    "label" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
    "path" : "send_to_rework",
    "entity_type" : "node",
    "rdf_mapping" : []
  }');
  return $items;
}
