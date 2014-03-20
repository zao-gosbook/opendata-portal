<?php
/**
 * @file
 * entityforms.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function entityforms_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_approve_publisher_request'] = entity_import('rules_config', '{ "rules_link_condition_approve_publisher_request" : {
      "LABEL" : "Rules link: \\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u0438\\u0442\\u044c \\u0437\\u043d\\u0430\\u0447\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_pubreq_status" } },
        { "NOT data_is" : { "data" : [ "node:field-pubreq-status" ], "value" : "approved" } }
      ]
    }
  }');
  $items['rules_link_condition_on_completion_publisher_request'] = entity_import('rules_config', '{ "rules_link_condition_on_completion_publisher_request" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0437\\u0430\\u044f\\u0432\\u043a\\u0443 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "AND" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "publisher_request" } },
        { "NOT data_is" : { "data" : [ "node:field-pubreq-status" ], "value" : "sendedback" } }
      ]
    }
  }');
  $items['rules_link_condition_reject_publisher_request'] = entity_import('rules_config', '{ "rules_link_condition_reject_publisher_request" : {
      "LABEL" : "Rules link: \\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u0438\\u0442\\u044c \\u0437\\u043d\\u0430\\u0447\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "AND" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "publisher_request" } },
        { "NOT data_is" : { "data" : [ "node:field-pubreq-status" ], "value" : "denied" } }
      ]
    }
  }');
  $items['rules_link_set_approve_publisher_request'] = entity_import('rules_config', '{ "rules_link_set_approve_publisher_request" : {
      "LABEL" : "Rules link: \\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u0438\\u0442\\u044c \\u0437\\u043d\\u0430\\u0447\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_pubreq_status" } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-pubreq-status" ], "value" : "approved" } }
            ],
            "LABEL" : "\\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0437\\u0430\\u044f\\u0432\\u043a\\u0443 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_on_completion_publisher_request'] = entity_import('rules_config', '{ "rules_link_set_on_completion_publisher_request" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0437\\u0430\\u044f\\u0432\\u043a\\u0443 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_pubreq_status" } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-pubreq-status" ], "value" : "sendedback" } },
              { "redirect" : { "url" : "node\\/[node:nid]\\/edit" } },
              { "drupal_message" : {
                  "message" : "\\u0423\\u043a\\u0430\\u0436\\u0438\\u0442\\u0435, \\u043f\\u043e\\u0436\\u0430\\u043b\\u0443\\u0439\\u0441\\u0442\\u0430, \\u043f\\u0440\\u0438\\u0447\\u0438\\u043d\\u0443, \\u043f\\u043e \\u043a\\u043e\\u0442\\u043e\\u0440\\u043e\\u0439 \\u0442\\u0440\\u0435\\u0431\\u0443\\u0435\\u0442\\u0441\\u044f \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0430 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0438 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e.",
                  "type" : "warning"
                }
              }
            ],
            "LABEL" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u0437\\u0430\\u044f\\u0432\\u043a\\u0443 \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_reject_publisher_request'] = entity_import('rules_config', '{ "rules_link_set_reject_publisher_request" : {
      "LABEL" : "Rules link: \\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u0438\\u0442\\u044c \\u0437\\u043d\\u0430\\u0447\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "type" : "node", "label" : "node" } },
      "RULES" : [
        { "RULE" : {
            "IF" : [
              { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_pubreq_status" } }
            ],
            "DO" : [
              { "data_set" : { "data" : [ "node:field-pubreq-status" ], "value" : "denied" } },
              { "redirect" : { "url" : "node\\/[node:nid]\\/edit" } },
              { "drupal_message" : {
                  "message" : "\\u0412\\u0432\\u0435\\u0434\\u0438\\u0442\\u0435 \\u043f\\u0440\\u0438\\u0447\\u0438\\u043d\\u044b \\u043e\\u0442\\u043a\\u0430\\u0437\\u0430 \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435.",
                  "type" : "warning"
                }
              }
            ],
            "LABEL" : "\\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0437\\u0430\\u044f\\u0432\\u043a\\u0443 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e"
          }
        }
      ]
    }
  }');
  return $items;
}
