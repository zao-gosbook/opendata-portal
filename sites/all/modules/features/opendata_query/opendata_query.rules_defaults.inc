<?php
/**
 * @file
 * opendata_query.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function opendata_query_default_rules_configuration() {
  $items = array();
  $items['rules_link_condition_answered_opendata_query'] = entity_import('rules_config', '{ "rules_link_condition_answered_opendata_query" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u0432\\u0435\\u0442 \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d \\u043d\\u0430 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "opendata_query" } },
        { "NOT data_is" : { "data" : [ "node:field-query-state" ], "value" : "answered" } }
      ]
    }
  }');
  $items['rules_link_condition_approve_opendata_query'] = entity_import('rules_config', '{ "rules_link_condition_approve_opendata_query" : {
      "LABEL" : "Rules link: \\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "opendata_query" } },
        { "NOT data_is" : { "data" : [ "node:field-query-state" ], "value" : "approved" } }
      ]
    }
  }');
  $items['rules_link_condition_reject_opendata_query'] = entity_import('rules_config', '{ "rules_link_condition_reject_opendata_query" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "opendata_query" } },
        { "NOT data_is" : { "data" : [ "node:field-query-state" ], "value" : "rejected" } }
      ]
    }
  }');
  $items['rules_link_condition_send_to_ministry_opendata_query'] = entity_import('rules_config', '{ "rules_link_condition_send_to_ministry_opendata_query" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 \\u0432 \\u043c\\u0438\\u043d\\u0438\\u0441\\u0442\\u0435\\u0440\\u0441\\u0442\\u0432\\u043e condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "data_is" : { "data" : [ "node:type" ], "value" : "opendata_query" } },
        { "NOT data_is" : { "data" : [ "node:field-query-state" ], "value" : "registred" } }
      ]
    }
  }');
  $items['rules_link_set_answered_opendata_query'] = entity_import('rules_config', '{ "rules_link_set_answered_opendata_query" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u0432\\u0435\\u0442 \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d \\u043d\\u0430 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [ { "component_rules_query_change_answered" : { "node" : [ "node" ] } } ],
            "LABEL" : "\\u041e\\u0442\\u0432\\u0435\\u0442 \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d \\u043d\\u0430 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_approve_opendata_query'] = entity_import('rules_config', '{ "rules_link_set_approve_opendata_query" : {
      "LABEL" : "Rules link: \\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [ { "component_rules_query_change_approve" : { "node" : [ "node" ] } } ],
            "LABEL" : "\\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_reject_opendata_query'] = entity_import('rules_config', '{ "rules_link_set_reject_opendata_query" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [ { "component_rules_query_change_rejected" : { "node" : [ "node" ] } } ],
            "LABEL" : "\\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435"
          }
        }
      ]
    }
  }');
  $items['rules_link_set_send_to_ministry_opendata_query'] = entity_import('rules_config', '{ "rules_link_set_send_to_ministry_opendata_query" : {
      "LABEL" : "Rules link: \\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 \\u0432 \\u043c\\u0438\\u043d\\u0438\\u0441\\u0442\\u0435\\u0440\\u0441\\u0442\\u0432\\u043e rules set",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "RULES" : [
        { "RULE" : {
            "DO" : [ { "component_rules_query_change_registred" : { "node" : [ "node" ] } } ],
            "LABEL" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 \\u0432 \\u043c\\u0438\\u043d\\u0438\\u0441\\u0442\\u0435\\u0440\\u0441\\u0442\\u0432\\u043e"
          }
        }
      ]
    }
  }');
  $items['rules_query_change_answered'] = entity_import('rules_config', '{ "rules_query_change_answered" : {
      "LABEL" : "\\u0421\\u043c\\u0435\\u043d\\u0430 \\u0441\\u0442\\u0430\\u0442\\u0443\\u0441 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 - \\u041e\\u0442\\u0432\\u0435\\u0442 \\u043f\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0443 \\u043f\\u0440\\u0435\\u0434\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "privatemsg_rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "opendata_query" : "opendata_query" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-query-state" ], "value" : "answered" } },
        { "mail" : {
            "to" : [ "node:author:mail" ],
            "subject" : "\\u041e\\u0442\\u0432\\u0435\\u0442 \\u043f\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0443 \\u043d\\u0430 \\u043f\\u0440\\u0435\\u0434\\u043e\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d",
            "message" : "\\u0414\\u043e\\u0431\\u0440\\u044b\\u0439 \\u0434\\u0435\\u043d\\u044c! \\r\\n\\u041d\\u0430 \\u0412\\u0430\\u0448 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u0440\\u0430\\u0441\\u043a\\u0440\\u044b\\u0442\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0431\\u044b\\u043b \\u043f\\u0440\\u0435\\u0434\\u043e\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d \\u043e\\u0442\\u0432\\u0435\\u0442 \\u0438\\u0437 \\u043e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438, \\u043a \\u043a\\u043e\\u0442\\u043e\\u0440\\u043e\\u0439 \\u043e\\u043d \\u0431\\u044b\\u043b \\u0430\\u0434\\u0440\\u0435\\u0441\\u043e\\u0432\\u0430\\u043d. \\r\\n\\u041a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439 \\u043f\\u0440\\u0435\\u0434\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0435 \\u0412\\u0430\\u0448\\u0435\\u0433\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430: [node:url]\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435\\u043c,\\r\\n\\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.\\r\\n[site:url]",
            "language" : [ "" ]
          }
        },
        { "privatemsg_rules_new" : {
            "USING" : {
              "recipient" : [ "node:author" ],
              "author" : "1",
              "subject" : "\\u041e\\u0442\\u0432\\u0435\\u0442 \\u043f\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0443 \\u043d\\u0430 \\u043f\\u0440\\u0435\\u0434\\u043e\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d",
              "body" : "\\u0414\\u043e\\u0431\\u0440\\u044b\\u0439 \\u0434\\u0435\\u043d\\u044c! \\r\\n\\u041d\\u0430 \\u0412\\u0430\\u0448 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u0440\\u0430\\u0441\\u043a\\u0440\\u044b\\u0442\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0431\\u044b\\u043b \\u043f\\u0440\\u0435\\u0434\\u043e\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d \\u043e\\u0442\\u0432\\u0435\\u0442 \\u0438\\u0437 \\u043e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438, \\u043a \\u043a\\u043e\\u0442\\u043e\\u0440\\u043e\\u0439 \\u043e\\u043d \\u0431\\u044b\\u043b \\u0430\\u0434\\u0440\\u0435\\u0441\\u043e\\u0432\\u0430\\u043d. \\r\\n\\u041a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439 \\u043f\\u0440\\u0435\\u0434\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0435 \\u0412\\u0430\\u0448\\u0435\\u0433\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430: [node:url]\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435\\u043c,\\r\\n\\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.\\r\\n[site:url]"
            },
            "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
          }
        }
      ]
    }
  }');
  $items['rules_query_change_approve'] = entity_import('rules_config', '{ "rules_query_change_approve" : {
      "LABEL" : "\\u0421\\u043c\\u0435\\u043d\\u0430 \\u0441\\u0442\\u0430\\u0442\\u0443\\u0441 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 - \\u041e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d\\u043e",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "opendata_query" : "opendata_query" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-query-state" ], "value" : "approved" } }
      ]
    }
  }');
  $items['rules_query_change_registred'] = entity_import('rules_config', '{ "rules_query_change_registred" : {
      "LABEL" : "\\u0421\\u043c\\u0435\\u043d\\u0430 \\u0441\\u0442\\u0430\\u0442\\u0443\\u0441 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 - \\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u043e \\u0432 \\u043c\\u0438\\u043d\\u0438\\u0441\\u0442\\u0435\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "opendata_query" : "opendata_query" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-query-state" ], "value" : "registred" } }
      ]
    }
  }');
  $items['rules_query_change_rejected'] = entity_import('rules_config', '{ "rules_query_change_rejected" : {
      "LABEL" : "\\u0421\\u043c\\u0435\\u043d\\u0430 \\u0441\\u0442\\u0430\\u0442\\u0443\\u0441 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 - \\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0435\\u043d\\u043e",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "opendata_query" : "opendata_query" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-query-state" ], "value" : "rejected" } }
      ]
    }
  }');
  return $items;
}
