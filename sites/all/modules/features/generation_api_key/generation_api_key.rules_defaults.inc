<?php
/**
 * @file
 * generation_api_key.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function generation_api_key_default_rules_configuration() {
  $items = array();
  $items['rules_api_key_generation'] = entity_import('rules_config', '{ "rules_api_key_generation" : {
      "LABEL" : "\\u0413\\u0435\\u043d\\u0435\\u0440\\u0430\\u0446\\u0438\\u044f \\u043a\\u043b\\u044e\\u0447\\u0430",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "od_common" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "get_api_key" } }
      ],
      "DO" : [
        { "generate_api_key" : {
            "USING" : { "user" : [ "site:current-user" ] },
            "PROVIDE" : { "api_key_generated" : { "api_key_generated" : "Generated key" } }
          }
        },
        { "drupal_message" : { "message" : "[api-key-generated:value]", "type" : "warning" } },
        { "list_add" : {
            "list" : [ "site:current-user:field-user-old-api-keys" ],
            "item" : [ "site:current-user:field-user-current-api-key" ]
          }
        },
        { "data_set" : {
            "data" : [ "site:current-user:field-user-current-api-key" ],
            "value" : [ "api-key-generated" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  return $items;
}
