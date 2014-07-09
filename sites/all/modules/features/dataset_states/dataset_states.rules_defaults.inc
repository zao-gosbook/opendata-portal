<?php
/**
 * @file
 * dataset_states.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function dataset_states_default_rules_configuration() {
  $items = array();
  $items['rules_dataset_reworked_and_send_to_moderation'] = entity_import('rules_config', '{ "rules_dataset_reworked_and_send_to_moderation" : {
      "LABEL" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u0430\\u043d \\u0438 \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d \\u043d\\u0430 \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u044e",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "privatemsg_rules", "flag" ],
      "ON" : { "flag_flagged_dataset_reworked" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "flagged-node:type" ], "value" : "dataset" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "flagged-node:field-dataset-status" ], "value" : "reworked" } },
        { "privatemsg_rules_new_role" : {
            "USING" : {
              "roles" : { "value" : { "4" : "4" } },
              "author" : "1",
              "subject" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u0430\\u043d",
              "body" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0022[flagged-node:title]\\u0022 : [flagged-node:url] \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u0430\\u043d \\u0438 \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0442\\u043e\\u0440\\u0443."
            },
            "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
          }
        }
      ]
    }
  }');
  $items['rules_link_condition_approve_dataset'] = entity_import('rules_config', '{ "rules_link_condition_approve_dataset" : {
      "LABEL" : "Rules link: \\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "AND" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "dataset" : "dataset" } } } },
        { "NOT data_is" : {
            "data" : [ "node:field-dataset-status" ],
            "op" : "IN",
            "value" : { "value" : { "reworking" : "reworking", "approved" : "approved" } }
          }
        }
      ]
    }
  }');
  $items['rules_link_condition_send_dataset_to_rework'] = entity_import('rules_config', '{ "rules_link_condition_send_dataset_to_rework" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "AND" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "dataset" } },
        { "NOT data_is" : {
            "data" : [ "node:field-dataset-status" ],
            "op" : "IN",
            "value" : { "value" : { "reworking" : "reworking", "approved" : "approved" } }
          }
        }
      ]
    }
  }');
  $items['rules_link_set_approve_dataset'] = entity_import('rules_config', '{ "rules_link_set_approve_dataset" : {
      "LABEL" : "Rules link: \\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "privatemsg_rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } },
            "IF" : [ { "data_is" : { "data" : [ "node:type" ], "value" : "dataset" } } ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-dataset-status" ], "value" : "approved" } },
              { "mail" : {
                  "to" : [ "node:author:mail" ],
                  "subject" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0022[node:field_dataset_title]\\u0022 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d",
                  "message" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439(-\\u0430\\u044f) [node:author].\\r\\n\\r\\n\\u0412\\u0430\\u0448 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0022[node:field_dataset_title]\\u0022 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d \\u0438 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d \\u043d\\u0430 \\u043f\\u043e\\u0440\\u0442\\u0430\\u043b\\u0435.\\r\\n\\r\\n\\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u043d\\u0430\\u0431\\u043e\\u0440: [node:url]\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435\\u043c, \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0420\\u0424.",
                  "language" : [ "" ]
                }
              },
              { "privatemsg_rules_new" : {
                  "USING" : {
                    "recipient" : [ "node:author" ],
                    "author" : "1",
                    "subject" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0022[node:field-dataset-title]\\u0022 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d.",
                    "body" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439(-\\u0430\\u044f) [node:author].\\r\\n\\r\\n\\u0412\\u0430\\u0448 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0022[node:field_dataset_title]\\u0022 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d \\u0438 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d \\u043d\\u0430 \\u043f\\u043e\\u0440\\u0442\\u0430\\u043b\\u0435.\\r\\n\\r\\n\\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u043d\\u0430\\u0431\\u043e\\u0440: [node:url]\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435\\u043c, \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0420\\u0424."
                  },
                  "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
                }
              },
              { "drupal_message" : { "message" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d." } }
            ],
            "LABEL" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_send_dataset_to_rework'] = entity_import('rules_config', '{ "rules_link_set_send_dataset_to_rework" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [
              { "redirect" : {
                  "url" : "eform\\/submit\\/dataset-reworking?field_dataset=[node:nid]",
                  "destination" : 1
                }
              }
            ],
            "LABEL" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445"
          }
        }
      ]
    }
  }');
  return $items;
}
