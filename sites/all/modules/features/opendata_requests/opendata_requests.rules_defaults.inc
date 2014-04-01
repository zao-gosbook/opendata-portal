<?php
/**
 * @file
 * opendata_requests.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function opendata_requests_default_rules_configuration() {
  $items = array();
  $items['rules_access_rule_user_is_org_publisher'] = entity_import('rules_config', '{ "rules_access_rule_user_is_org_publisher" : {
      "LABEL" : "Access rule: \\u041f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044c \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043a\\u0443\\u0440\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c \\u043e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438, \\u043a\\u043e\\u0442\\u043e\\u0440\\u043e\\u0439 \\u043d\\u0430\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u041e\\u0414",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "opendata_query" : "opendata_query" } }
          }
        },
        { "OR" : [
            { "user_has_role" : {
                "account" : [ "site:current-user" ],
                "roles" : { "value" : { "4" : "4", "5" : "5" } },
                "operation" : "OR"
              }
            },
            { "AND" : [
                { "NOT data_is_empty" : { "data" : [ "node:field-od-query-data-organization" ] } },
                { "entity_has_field" : {
                    "entity" : [ "node:field-od-query-data-organization" ],
                    "field" : "field_organization_curators"
                  }
                },
                { "list_contains" : {
                    "list" : [ "node:field-od-query-data-organization:field-organization-curators" ],
                    "item" : [ "site:current-user" ]
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_notify_organization_curators_2'] = entity_import('rules_config', '{ "rules_notify_organization_curators_2" : {
      "LABEL" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043a\\u0430 \\u0443\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u044f \\u041a\\u0443\\u0440\\u0430\\u0442\\u043e\\u0440\\u0430\\u043c \\u043e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438 \\u043e \\u043d\\u043e\\u0432\\u043e\\u043c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0435 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 (\\u041c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u044f)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "opendata_query" : "opendata_query" } }
          }
        },
        { "entity_has_field" : {
            "entity" : [ "node:field-od-query-data-organization" ],
            "field" : "field_organization_curators"
          }
        }
      ],
      "DO" : [
        { "CONDITIONAL" : [
            {
              "IF" : { "NOT data_is_empty" : { "data" : [ "node:field-od-query-data-organization:field-organization-curators" ] } },
              "DO" : [
                { "LOOP" : {
                    "USING" : { "list" : [ "node:field-od-query-data-organization:field-organization-curators" ] },
                    "ITEM" : { "curator" : "curator" },
                    "DO" : [
                      { "mail" : {
                          "to" : [ "curator:mail" ],
                          "subject" : "\\u041f\\u043e\\u0441\\u0442\\u0443\\u043f\\u043b\\u0435\\u043d\\u0438\\u0435 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 \\u043d\\u0430 \\u0438\\u043d\\u0444\\u043e\\u0440\\u043c\\u0430\\u0446\\u0438\\u0438 \\u0432 \\u0432\\u0438\\u0434\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
                          "message" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [curator:name]!\\r\\n\\r\\n\\u0412\\u0430\\u043c \\u043f\\u043e\\u0441\\u0442\\u0443\\u043f\\u0438\\u043b \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.\\r\\n\\u0417\\u0430\\u043f\\u0440\\u043e\\u0441\\u044b \\u0434\\u043e\\u0441\\u0442\\u0443\\u043f\\u0435\\u043d \\u043f\\u043e \\u0441\\u0441\\u044b\\u043b\\u043a\\u0435: [node:url]\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435\\u043c, \\r\\n\\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
                          "language" : [ "" ]
                        }
                      },
                      { "data_set" : { "data" : [ "node:field-notified" ], "value" : 1 } }
                    ]
                  }
                }
              ]
            },
            { "ELSE" : [
                { "drupal_message" : {
                    "message" : "\\u0412 \\u0443\\u043a\\u0430\\u0437\\u0430\\u043d\\u043d\\u043e\\u0439 \\u043e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438 \\u043e\\u0442\\u0441\\u0443\\u0442\\u0441\\u0442\\u0432\\u0443\\u044e\\u0442 \\u043a\\u0443\\u0440\\u0430\\u0442\\u043e\\u0440\\u044b.",
                    "type" : "warning"
                  }
                }
              ]
            }
          ]
        },
        { "data_set" : { "data" : [ "node:status" ], "value" : "1" } }
      ]
    }
  }');
  $items['rules_publish_query'] = entity_import('rules_config', '{ "rules_publish_query" : {
      "LABEL" : "\\u041f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u044f \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 \\u0438 \\u0432\\u043a\\u043b\\u044e\\u0447\\u0435\\u043d\\u0438\\u0435 \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0435\\u0432",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "opendata_query" : "opendata_query" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-od-query-type" ], "value" : "public" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:status" ], "value" : "1" } },
        { "data_set" : { "data" : [ "node:comment" ], "value" : "2" } }
      ]
    }
  }');
  return $items;
}
