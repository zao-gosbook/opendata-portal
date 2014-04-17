<?php
/**
 * @file
 * entityforms.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function entityforms_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entity_rule_setting().
 */
function entityforms_default_entity_rule_setting() {
  $items = array();
  $items['2'] = entity_import('entity_rule_setting', '{
    "id" : "2",
    "entity_type" : "entityform",
    "bundle" : "add_app",
    "op" : "entityform_submission",
    "rules_config" : "rules_create_app",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['3'] = entity_import('entity_rule_setting', '{
    "id" : "3",
    "entity_type" : "entityform",
    "bundle" : "request_to_become_a_publisher",
    "op" : "create",
    "rules_config" : "rules_copy_ef_to_node",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['4'] = entity_import('entity_rule_setting', '{
    "id" : "4",
    "entity_type" : "entityform",
    "bundle" : "add_new_forum",
    "op" : "entityform_submission",
    "rules_config" : "rules_add_forum_forum",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['5'] = entity_import('entity_rule_setting', '{
    "id" : "5",
    "entity_type" : "entityform",
    "bundle" : "feedback",
    "op" : "entityform_submission",
    "rules_config" : "rules_feedback_notification",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['6'] = entity_import('entity_rule_setting', '{
    "id" : "6",
    "entity_type" : "entityform",
    "bundle" : "notify_dataset_subscribers",
    "op" : "entityform_submission",
    "rules_config" : "rules_dataset_send_notifications",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['7'] = entity_import('entity_rule_setting', '{
    "id" : "7",
    "entity_type" : "entityform",
    "bundle" : "dataset_actualization",
    "op" : "entityform_submission",
    "rules_config" : "rules_dataset_actualization",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['9'] = entity_import('entity_rule_setting', '{
    "id" : "9",
    "entity_type" : "entityform",
    "bundle" : "file_converting_service",
    "op" : "entityform_submission",
    "rules_config" : "rules_create_file_and_download",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['10'] = entity_import('entity_rule_setting', '{
    "id" : "10",
    "entity_type" : "entityform",
    "bundle" : "dataset_error_report",
    "op" : "entityform_submission",
    "rules_config" : "rules_register_anonymous_through_the_dataset_error_report",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['11'] = entity_import('entity_rule_setting', '{
    "id" : "11",
    "entity_type" : "node",
    "bundle" : "app",
    "op" : "validation",
    "rules_config" : "rules_app_form_validation",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['12'] = entity_import('entity_rule_setting', '{
    "id" : "12",
    "entity_type" : "entityform",
    "bundle" : "od_preprocess_wizard",
    "op" : "validation",
    "rules_config" : "rules_validation_od_preprocess_wizard",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['13'] = entity_import('entity_rule_setting', '{
    "id" : "13",
    "entity_type" : "entityform",
    "bundle" : "dataset_actualization",
    "op" : "validation",
    "rules_config" : "rules_validation_od_preprocess_wizard",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['16'] = entity_import('entity_rule_setting', '{
    "id" : "16",
    "entity_type" : "entityform",
    "bundle" : "dataset_error_report",
    "op" : "entityform_submission",
    "rules_config" : "rules_back_redirect_to_the_resource",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['17'] = entity_import('entity_rule_setting', '{
    "id" : "17",
    "entity_type" : "entityform",
    "bundle" : "request_to_become_a_publisher",
    "op" : "entityform_submission",
    "rules_config" : "rules_create_publisher_request_node",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  $items['18'] = entity_import('entity_rule_setting', '{
    "id" : "18",
    "entity_type" : "entityform",
    "bundle" : "request_to_become_a_publisher",
    "op" : "entityform_submission",
    "rules_config" : "rules_fill_up_user_profile",
    "weight" : "0",
    "args" : null,
    "false_msg" : null,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_entityform_type().
 */
function entityforms_default_entityform_type() {
  $items = array();
  $items['add_app'] = entity_import('entityform_type', '{
    "type" : "add_app",
    "label" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u0438\\u0442\\u044c \\u043f\\u0440\\u0438\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u0435",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u0438\\u0442\\u044c",
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
      "roles" : { "2" : "2", "1" : 0, "6" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "add_app",
      "instruction_pre" : { "value" : "", "format" : "full_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['add_idea'] = entity_import('entityform_type', '{
    "type" : "add_idea",
    "label" : "Add idea",
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
      "roles" : { "1" : "1", "2" : 0, "6" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u041d\\u0430 \\u044d\\u0442\\u043e\\u0439 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0435 \\u0432\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u043f\\u0440\\u0435\\u0434\\u043b\\u043e\\u0436\\u0438\\u0442\\u044c \\u0438\\u0434\\u0435\\u044e \\u0440\\u0430\\u0437\\u0432\\u0438\\u0442\\u0438\\u044f \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b\\u0430, \\u043d\\u043e\\u0432\\u043e\\u0433\\u043e \\u043f\\u0440\\u0438\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u044f \\u0438\\u043b\\u0438 \\u0441\\u0435\\u0440\\u0432\\u0438\\u0441\\u0430, \\u0438\\u043b\\u0438 \\u0438\\u0434\\u0435\\u044e \\u0440\\u0430\\u0437\\u0432\\u0438\\u0442\\u0438\\u044f \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0432 \\u0420\\u043e\\u0441\\u0441\\u0438\\u0438. \\u041f\\u043e\\u0441\\u043b\\u0435 \\u043f\\u0440\\u043e\\u0432\\u0435\\u0440\\u043a\\u0438 \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c \\u0438\\u0434\\u0435\\u044f \\u0431\\u0443\\u0434\\u0435\\u0442 \\u0434\\u043e\\u0441\\u0442\\u0443\\u043f\\u043d\\u0430 \\u0434\\u043b\\u044f \\u0432\\u0441\\u0435\\u0445 \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u0435\\u0439 \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0435 \\u00ab\\u0418\\u0434\\u0435\\u0438\\u00bb. \\u0412 \\u0441\\u043b\\u0443\\u0447\\u0430\\u0435 \\u0435\\u0441\\u043b\\u0438 \\u0438\\u0434\\u0435\\u044f \\u043d\\u0430\\u0431\\u0440\\u0430\\u043b\\u0430 \\u0434\\u043e\\u0441\\u0442\\u0430\\u0442\\u043e\\u0447\\u043d\\u043e \\u0431\\u043e\\u043b\\u044c\\u0448\\u043e\\u0435 \\u0447\\u0438\\u0441\\u043b\\u043e \\u0433\\u043e\\u043b\\u043e\\u0441\\u043e\\u0432, \\u043e\\u043d\\u0430 \\u0431\\u0443\\u0434\\u0435\\u0442 \\u043d\\u0435\\u0437\\u0430\\u043c\\u0435\\u0434\\u043b\\u0438\\u0442\\u0435\\u043b\\u044c\\u043d\\u043e \\u043f\\u0435\\u0440\\u0435\\u0430\\u0434\\u0440\\u0435\\u0441\\u043e\\u0432\\u0430\\u043d\\u0430 \\u043b\\u0438\\u0446\\u0430\\u043c, \\u043e\\u0442\\u0432\\u0435\\u0442\\u0441\\u0442\\u0432\\u0435\\u043d\\u043d\\u044b\\u043c \\u0437\\u0430 \\u0435\\u0435 \\u0440\\u0435\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044e.",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['add_new_forum'] = entity_import('entityform_type', '{
    "type" : "add_new_forum",
    "label" : "Add new forum",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u0442\\u044c",
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
      "roles" : { "4" : "4", "1" : 0, "2" : 0, "6" : 0, "3" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "forum",
      "instruction_pre" : { "value" : "", "format" : "full_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['dataset_actualization'] = entity_import('entityform_type', '{
    "type" : "dataset_actualization",
    "label" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043e\\u0434\\u043d\\u043e\\u0442\\u043e\\u043c\\u043d\\u043e\\u0433\\u043e \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0438\\u0440\\u043e\\u0432\\u0430\\u0442\\u044c",
      "submit_confirm_msg" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043f\\u0440\\u043e\\u0448\\u043b\\u0430 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e",
      "your_submissions" : "\\u003Cnone\\u003E",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "\\u003Cnone\\u003E",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "6" : "6", "5" : "5", "1" : 0, "2" : 0, "3" : 0, "4" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003C?php \\r\\nif (!empty($_GET[\\u0027field_ef_dataset\\u0027]) \\u0026\\u0026 is_numeric($_GET[\\u0027field_ef_dataset\\u0027])) {\\r\\n  $dataset_nid = $_GET[\\u0027field_ef_dataset\\u0027];\\r\\n  global $language;\\r\\n  $prefix = $language-\\u003Elanguage;\\r\\n  $passport = t(\\u0027Passport\\u0027);\\r\\n  $edit_passport = t(\\u0027Edit passport\\u0027);\\r\\n  $actualize_passport = t(\\u0027Actualize dataset\\u0027);\\r\\n  print \\u003C\\u003C\\u003CEND\\r\\n  \\u003Cdiv class=\\u0022panel-pane pane-pane-messages\\u0022\\u003E\\r\\n    \\u003Ch2 class=\\u0022element-invisible\\u0022\\u003E\\u0413\\u043b\\u0430\\u0432\\u043d\\u044b\\u0435 \\u0432\\u043a\\u043b\\u0430\\u0434\\u043a\\u0438\\u003C\\/h2\\u003E\\r\\n      \\u003Cul class=\\u0022tabs-primary tabs primary\\u0022\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab is-active\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/node\\/$dataset_nid\\u0022 class=\\u0022tabs-primary__tab-link\\u0022\\u003E$passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/node\\/$dataset_nid\\/edit\\u0022 class=\\u0022tabs-primary__tab-link\\u0022\\u003E$edit_passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/actualize-dataset?field_ef_dataset=$dataset_nid\\u0022 class=\\u0022tabs-primary__tab-link  is-active active\\u0022\\u0022\\u003E$actualize_passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n      \\u003C\\/ul\\u003E\\r\\n  \\u003C\\/div\\u003E\\r\\nEND;\\r\\n}\\r\\n?\\u003E\\r\\n",
        "format" : "ds_code"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['dataset_actualization_multivol'] = entity_import('entityform_type', '{
    "type" : "dataset_actualization_multivol",
    "label" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043c\\u043d\\u043e\\u0433\\u043e\\u0442\\u043e\\u043c\\u043d\\u043e\\u0433\\u043e \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0438\\u0440\\u043e\\u0432\\u0430\\u0442\\u044c",
      "submit_confirm_msg" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043f\\u0440\\u043e\\u0448\\u043b\\u0430 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e",
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
      "roles" : { "6" : "6", "5" : "5", "1" : 0, "2" : 0, "3" : 0, "4" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003C?php \\r\\nif (!empty($_GET[\\u0027field_ef_dataset\\u0027]) \\u0026\\u0026 is_numeric($_GET[\\u0027field_ef_dataset\\u0027])) {\\r\\n  $dataset_nid = $_GET[\\u0027field_ef_dataset\\u0027];\\r\\n  global $language;\\r\\n  $prefix = $language-\\u003Elanguage;\\r\\n  $passport = t(\\u0027Passport\\u0027);\\r\\n  $edit_passport = t(\\u0027Edit passport\\u0027);\\r\\n  $actualize_passport = t(\\u0027Actualize dataset\\u0027);\\r\\n  print \\u003C\\u003C\\u003CEND\\r\\n  \\u003Cdiv class=\\u0022panel-pane pane-pane-messages\\u0022\\u003E\\r\\n    \\u003Ch2 class=\\u0022element-invisible\\u0022\\u003E\\u0413\\u043b\\u0430\\u0432\\u043d\\u044b\\u0435 \\u0432\\u043a\\u043b\\u0430\\u0434\\u043a\\u0438\\u003C\\/h2\\u003E\\r\\n      \\u003Cul class=\\u0022tabs-primary tabs primary\\u0022\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab is-active\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/node\\/$dataset_nid\\u0022 class=\\u0022tabs-primary__tab-link\\u0022\\u003E$passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/node\\/$dataset_nid\\/edit\\u0022 class=\\u0022tabs-primary__tab-link\\u0022\\u003E$edit_passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/actualize-dataset?field_ef_dataset=$dataset_nid\\u0022 class=\\u0022tabs-primary__tab-link  is-active active\\u0022\\u0022\\u003E$actualize_passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n      \\u003C\\/ul\\u003E\\r\\n  \\u003C\\/div\\u003E\\r\\nEND;\\r\\n}\\r\\n?\\u003E\\r\\n",
        "format" : "ds_code"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['dataset_error_report'] = entity_import('entityform_type', '{
    "type" : "dataset_error_report",
    "label" : "\\u041e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e \\u043e\\u0448\\u0438\\u0431\\u043a\\u0435 \\u0432 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "Send",
      "submit_confirm_msg" : "\\u041e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u0435 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u043e.",
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
      "roles" : { "1" : "1", "2" : "2", "6" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "full_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['feedback'] = entity_import('entityform_type', '{
    "type" : "feedback",
    "label" : "Feedback",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "Send",
      "submit_confirm_msg" : "\\u0421\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u043e.",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "",
      "submission_text" : {
        "value" : "\\u003Ca href=\\u0022\\/feedback\\u0022\\u003E\\u0412\\u0435\\u0440\\u043d\\u0443\\u0442\\u044c\\u0441\\u044f \\u043e\\u0431\\u0440\\u0430\\u0442\\u043d\\u043e\\u003C\\/a\\u003E",
        "format" : "full_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "6" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cdiv class=\\u0022messages messages--warning\\u0022\\u003E\\u0412 \\u0441\\u043b\\u0443\\u0447\\u0430\\u0435 \\u043f\\u043e\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u0432\\u043e\\u043f\\u0440\\u043e\\u0441\\u043e\\u0432 \\u043f\\u043e \\u0440\\u0430\\u0431\\u043e\\u0442\\u0435 \\u0441 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u043c\\u0438 \\u0434\\u0430\\u043d\\u043d\\u044b\\u043c\\u0438 \\u0432\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u043e\\u0431\\u0440\\u0430\\u0442\\u0438\\u0442\\u044c\\u0441\\u044f \\u0432 \\u0441\\u043b\\u0443\\u0436\\u0431\\u0443 \\u0442\\u0435\\u0445\\u043d\\u0438\\u0447\\u0435\\u0441\\u043a\\u043e\\u0439 \\u043f\\u043e\\u0434\\u0434\\u0435\\u0440\\u0436\\u043a\\u0438 \\u043f\\u043e \\u0442\\u0435\\u043b\\u0435\\u0444\\u043e\\u043d\\u0443 8-495-721-56-28 (\\u0441 10:00 \\u0434\\u043e 19:00, \\u043f\\u043e \\u043c\\u043e\\u0441\\u043a\\u043e\\u0432\\u0441\\u043a\\u043e\\u043c\\u0443 \\u0432\\u0440\\u0435\\u043c\\u0435\\u043d\\u0438).\\r\\n\\u0422\\u0430\\u043a\\u0436\\u0435 \\u0432\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430\\u043c \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435, \\u0437\\u0430\\u043f\\u043e\\u043b\\u043d\\u0438\\u0432 \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0443\\u044e \\u0444\\u043e\\u0440\\u043c\\u0443:\\u003C\\/div\\u003E",
        "format" : "ds_code"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['notify_dataset_subscribers'] = entity_import('entityform_type', '{
    "type" : "notify_dataset_subscribers",
    "label" : "\\u0423\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e\\u0434\\u043f\\u0438\\u0441\\u0447\\u0438\\u043a\\u043e\\u0432 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u0443\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0435",
      "submit_confirm_msg" : "\\u0423\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0435 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u043e",
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
      "roles" : { "6" : "6", "1" : 0, "2" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "user\\/[current-user:uid]\\/datasets",
      "instruction_pre" : { "value" : "", "format" : "full_html" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['od_preprocess_wizard'] = entity_import('entityform_type', '{
    "type" : "od_preprocess_wizard",
    "label" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430\\u0431\\u043e\\u0440",
      "submit_confirm_msg" : "\\u003Cnone\\u003E",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "\\u003Cnone\\u003E",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "6" : "6", "5" : "5", "1" : 0, "2" : 0, "3" : 0, "4" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "user",
      "instruction_pre" : {
        "value" : "\\u003Cspan class=\\u0022form-required\\u0022\\u003E*\\u003C\\/span\\u003E - \\u003Cspan class=\\u0022hint\\u0022\\u003E\\u041f\\u043e\\u043b\\u044f \\u0441\\u043e \\u0437\\u0432\\u0435\\u0437\\u0434\\u043e\\u0447\\u043a\\u043e\\u0439 \\u044f\\u0432\\u043b\\u044f\\u044e\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c\\u0438\\u003C\\/span\\u003E",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  $items['opendata_query'] = entity_import('entityform_type', '{
    "type" : "opendata_query",
    "label" : "Request to open data",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "html" },
      "submit_button_text" : "Send",
      "submit_confirm_msg" : "\\u003Cnone\\u003E",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "\\u0417\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435",
      "submission_text" : {
        "value" : "\\u003Ca href=\\u0022\\/askopendata\\u0022\\u003E\\u0412\\u0435\\u0440\\u043d\\u0443\\u0442\\u044c\\u0441\\u044f \\u043e\\u0431\\u0440\\u0430\\u0442\\u043d\\u043e\\u003C\\/a\\u003E",
        "format" : "full_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "6" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cp\\u003E\\u0412 \\u0441\\u043b\\u0443\\u0447\\u0430\\u0435, \\u0435\\u0441\\u043b\\u0438 \\u0432\\u0430\\u043c \\u043d\\u0443\\u0436\\u043d\\u044b \\u043a\\u0430\\u043a\\u0438\\u0435-\\u0442\\u043e \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435, \\u043d\\u043e \\u0432\\u044b \\u043d\\u0435 \\u043d\\u0430\\u0448\\u043b\\u0438 \\u0438\\u0445 \\u043d\\u0430 \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b\\u0435, \\u0432\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u043f\\u043e\\u0434\\u0430\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u0434\\u043b\\u044f \\u0438\\u0445 \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f. \\u0417\\u0430\\u043f\\u0440\\u043e\\u0441 \\u0431\\u0443\\u0434\\u0435\\u0442 \\u043f\\u0435\\u0440\\u0435\\u0430\\u0434\\u0440\\u0435\\u0441\\u043e\\u0432\\u0430\\u043d \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0421\\u043e\\u0432\\u0435\\u0442 \\u043f\\u043e \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u043c \\u0434\\u0430\\u043d\\u043d\\u044b\\u043c \\u0432 \\u043e\\u0442\\u0432\\u0435\\u0442\\u0441\\u0442\\u0432\\u0435\\u043d\\u043d\\u043e\\u0435 \\u0432\\u0435\\u0434\\u043e\\u043c\\u0441\\u0442\\u0432\\u043e, \\u043a\\u043e\\u0442\\u043e\\u0440\\u043e\\u0435 \\u0432\\u044b \\u0443\\u043a\\u0430\\u0437\\u044b\\u0432\\u0430\\u0435\\u0442\\u0435 \\u0432 \\u044d\\u043b\\u0435\\u043a\\u0442\\u0440\\u043e\\u043d\\u043d\\u043e\\u0439 \\u0444\\u043e\\u0440\\u043c\\u0435. \\u041f\\u043e\\u0441\\u043b\\u0435 \\u043e\\u0442\\u0432\\u0435\\u0442\\u0430 \\u0432\\u0435\\u0434\\u043e\\u043c\\u0441\\u0442\\u0432\\u0430 \\u043e \\u0441\\u0440\\u043e\\u043a\\u0430\\u0445 \\u0440\\u0430\\u0441\\u043a\\u0440\\u044b\\u0442\\u0438\\u044f \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0438 \\u043f\\u0440\\u0435\\u0434\\u043e\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0438 \\u0441\\u0430\\u043c\\u0438\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043e\\u043d\\u0438 \\u0431\\u0443\\u0434\\u0443\\u0442 \\u0440\\u0430\\u0437\\u043c\\u0435\\u0449\\u0435\\u043d\\u044b \\u043d\\u0430 \\u043d\\u0430\\u0448\\u0435\\u043c \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b\\u0435. \\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u0412\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u043f\\u043e\\u0434\\u0430\\u0442\\u044c \\u043a\\u0430\\u043a \\u043f\\u0443\\u0431\\u043b\\u0438\\u0447\\u043d\\u044b\\u0439 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441, \\u0442\\u0430\\u043a \\u0438 \\u043a\\u043e\\u043d\\u0444\\u0438\\u0434\\u0435\\u043d\\u0446\\u0438\\u0430\\u043b\\u044c\\u043d\\u044b\\u0439. \\u0415\\u0441\\u043b\\u0438 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043f\\u0443\\u0431\\u043b\\u0438\\u0447\\u043d\\u044b\\u043c, \\u0442\\u043e \\u043e\\u043d \\u0431\\u0443\\u0434\\u0435\\u0442 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0435 \\u0432\\u0441\\u0435\\u0445 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u043e\\u0432 \\u043f\\u043e\\u0441\\u043b\\u0435 \\u043f\\u0440\\u043e\\u0432\\u0435\\u0440\\u043a\\u0438 \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c. \\u041d\\u0438\\u043a\\u0430\\u043a\\u0430\\u044f \\u043b\\u0438\\u0447\\u043d\\u0430\\u044f \\u0438\\u043d\\u0444\\u043e\\u0440\\u043c\\u0430\\u0446\\u0438\\u044f \\u043d\\u0435 \\u043f\\u043e\\u043f\\u0430\\u0434\\u0435\\u0442 \\u043d\\u0430 \\u043e\\u0431\\u0449\\u0443\\u044e \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0443. \\u0415\\u0441\\u043b\\u0438 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043a\\u043e\\u043d\\u0444\\u0438\\u0434\\u0435\\u043d\\u0446\\u0438\\u0430\\u043b\\u044c\\u043d\\u044b\\u043c, \\u0442\\u043e \\u0435\\u0433\\u043e \\u0443\\u0432\\u0438\\u0434\\u044f\\u0442 \\u0442\\u043e\\u043b\\u044c\\u043a\\u043e \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0442\\u043e\\u0440\\u044b \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b\\u0430 \\u0438 \\u043f\\u0440\\u0435\\u0434\\u0441\\u0442\\u0430\\u0432\\u0438\\u0442\\u0435\\u043b\\u0438 \\u043e\\u0442\\u0432\\u0435\\u0442\\u0441\\u0442\\u0432\\u0435\\u043d\\u043d\\u043e\\u0433\\u043e \\u0432\\u0435\\u0434\\u043e\\u043c\\u0441\\u0442\\u0432\\u0430, \\u043a\\u043e\\u0442\\u043e\\u0440\\u043e\\u043c\\u0443 \\u0430\\u0434\\u0440\\u0435\\u0441\\u043e\\u0432\\u0430\\u043d \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441.\\u003C\\/p\\u003E",
        "format" : "html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
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
      "submission_page_title" : "",
      "submission_text" : { "value" : "", "format" : "full_html" },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "2" : "2", "1" : 0, "6" : 0, "3" : 0, "4" : 0, "5" : 0 },
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
 * Implements hook_default_rules_link().
 */
function entityforms_default_rules_link() {
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
