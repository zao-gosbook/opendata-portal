<?php
/**
 * @file
 * suggestions.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function suggestions_default_rules_configuration() {
  $items = array();
  $items['rules_rules_suggestion_creation'] = entity_import('rules_config', '{ "rules_rules_suggestion_creation" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u043f\\u0440\\u0435\\u0434\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u044f",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "add_suggestion" } }
      ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "suggestion",
              "param_title" : [ "entity:field-add-suggetion-title" ],
              "param_author" : [ "entity:user" ]
            },
            "PROVIDE" : { "entity_created" : { "new_suggestion" : "new_suggestion" } }
          }
        },
        { "data_set" : {
            "data" : [ "new-suggestion:body:value" ],
            "value" : [ "entity:field-add-suggetion-body" ]
          }
        },
        { "entity_save" : { "data" : [ "new-suggestion" ], "immediate" : 1 } },
        { "data_set" : {
            "data" : [ "new-suggestion:field-suggestion-rubric" ],
            "value" : [ "entity:field-add-suggetion-rubric" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  return $items;
}
