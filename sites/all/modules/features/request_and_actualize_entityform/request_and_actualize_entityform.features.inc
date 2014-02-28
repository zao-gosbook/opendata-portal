<?php
/**
 * @file
 * request_and_actualize_entityform.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function request_and_actualize_entityform_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_entityform_type().
 */
function request_and_actualize_entityform_default_entityform_type() {
  $items = array();
  $items['dataset_actualization'] = entity_import('entityform_type', '{
    "type" : "dataset_actualization",
    "label" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0438\\u0440\\u043e\\u0432\\u0430\\u0442\\u044c \\u043d\\u0430\\u0431\\u043e\\u0440",
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
      "user_submissions_view" : "",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "6" : "6", "1" : 0, "2" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003C?php \\r\\nif (!empty($_GET[\\u0027field_ef_dataset\\u0027]) \\u0026\\u0026 is_numeric($_GET[\\u0027field_ef_dataset\\u0027])) {\\r\\n  $dataset_nid = $_GET[\\u0027field_ef_dataset\\u0027];\\r\\n  global $language;\\r\\n  $prefix = $language-\\u003Elanguage;\\r\\n  $passport = t(\\u0027Passport\\u0027);\\r\\n  $edit_passport = t(\\u0027Edit passport\\u0027);\\r\\n  $actualize_passport = t(\\u0027Actualize dataset\\u0027);\\r\\n  print \\u003C\\u003C\\u003CEND\\r\\n  \\u003Cdiv class=\\u0022panel-pane pane-pane-messages\\u0022\\u003E\\r\\n    \\u003Ch2 class=\\u0022element-invisible\\u0022\\u003E\\u0413\\u043b\\u0430\\u0432\\u043d\\u044b\\u0435 \\u0432\\u043a\\u043b\\u0430\\u0434\\u043a\\u0438\\u003C\\/h2\\u003E\\r\\n      \\u003Cul class=\\u0022tabs-primary tabs primary\\u0022\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab is-active\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/node\\/$dataset_nid\\u0022 class=\\u0022tabs-primary__tab-link\\u0022\\u003E$passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/node\\/$dataset_nid\\/edit\\u0022 class=\\u0022tabs-primary__tab-link\\u0022\\u003E$edit_passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n        \\u003Cli class=\\u0022tabs-primary__tab\\u0022\\u003E\\u003Ca href=\\u0022\\/$prefix\\/actualize-dataset?field_ef_dataset=$dataset_nid\\u0022 class=\\u0022tabs-primary__tab-link  is-active active\\u0022\\u0022\\u003E$actualize_passport\\u003C\\/a\\u003E\\u003C\\/li\\u003E\\r\\n      \\u003C\\/ul\\u003E\\r\\n  \\u003C\\/div\\u003E\\r\\nEND;\\r\\n}\\r\\n?\\u003E\\r\\n",
        "format" : "ds_code"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/dataset-actualization",
        "alias" : "actualize-dataset",
        "language" : "und"
      }
    }
  }');
  $items['od_preprocess_wizard'] = entity_import('entityform_type', '{
    "type" : "od_preprocess_wizard",
    "label" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "full_html" },
      "submit_button_text" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430\\u0431\\u043e\\u0440",
      "submit_confirm_msg" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d",
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
      "roles" : { "6" : "6", "1" : 0, "2" : 0, "3" : 0, "4" : 0, "5" : 0 },
      "resubmit_action" : "new",
      "redirect_path" : "user",
      "instruction_pre" : {
        "value" : "\\u003Cspan class=\\u0022form-required\\u0022\\u003E*\\u003C\\/span\\u003E - \\u003Cspan class=\\u0022hint\\u0022\\u003E\\u041f\\u043e\\u043b\\u044f \\u0441\\u043e \\u0437\\u0432\\u0435\\u0437\\u0434\\u043e\\u0447\\u043a\\u043e\\u0439 \\u044f\\u0432\\u043b\\u044f\\u044e\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c\\u0438\\u003C\\/span\\u003E",
        "format" : "full_html"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/od-preprocess-wizard",
        "alias" : "new-dataset",
        "language" : "und"
      }
    }
  }');
  return $items;
}
