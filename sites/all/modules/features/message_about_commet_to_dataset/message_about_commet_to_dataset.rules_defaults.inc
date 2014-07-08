<?php
/**
 * @file
 * message_about_commet_to_dataset.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function message_about_commet_to_dataset_default_rules_configuration() {
  $items = array();
  $items['rules_message_about_comment_to_dataset'] = entity_import('rules_config', '{ "rules_message_about_comment_to_dataset" : {
      "LABEL" : "\\u0421\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043e \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0438 \\u043a \\u043c\\u0430\\u0442\\u0435\\u0440\\u0438\\u0430\\u043b\\u0443 (\\u0430\\u0432\\u0442\\u043e\\u0440\\u0430\\u043c \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0435\\u0432)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rb_misc", "rules_conditional", "privatemsg_rules", "comment" ],
      "ON" : { "comment_insert--comment_node_dataset" : { "bundle" : "comment_node_dataset" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "dataset" : "dataset" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "\\u0421\\u0440\\u0430\\u0431\\u043e\\u0442\\u0430\\u043b\\u043e \\u043f\\u0440\\u0430\\u0432\\u0438\\u043b\\u043e \\u0022\\u0421\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043e \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0438 \\u043a \\u043c\\u0430\\u0442\\u0435\\u0440\\u0438\\u0430\\u043b\\u0443 (\\u0430\\u0432\\u0442\\u043e\\u0440\\u0430\\u043c \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0435\\u0432)\\u0022 \\r\\n\\u0430\\u0440\\u0433\\u0443\\u043c\\u0435\\u043d\\u0442 \\u0434\\u043b\\u044f \\u0432\\u044c\\u044e\\u0441\\u0430 - [comment:node:nid]. " } },
        { "rb_misc_action_views_load_comment_list" : {
            "USING" : {
              "view" : "dataset_list_comment_authors|default",
              "args" : [ "comment:node:nid" ]
            },
            "PROVIDE" : { "comment_list" : { "comment_list" : "View comment list" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "list\\u003Cuser\\u003E" },
            "PROVIDE" : { "variable_added" : { "variable_added" : "variable_added" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "comment-list" ] },
            "ITEM" : { "list_item_comment" : "list_item_comment" },
            "DO" : [
              { "list_add" : {
                  "list" : [ "variable-added" ],
                  "item" : [ "list-item-comment:author" ],
                  "unique" : 1
                }
              }
            ]
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "variable-added" ] },
            "ITEM" : { "list_item_user" : "list_item_user" },
            "DO" : [
              { "entity_fetch" : {
                  "USING" : { "type" : "user", "id" : [ "list-item-user:uid" ] },
                  "PROVIDE" : { "entity_fetched" : { "entity_fetched_user" : "entity_fetched_user" } }
                }
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "NOT data_is" : { "data" : [ "comment:author" ], "value" : [ "entity-fetched-user" ] } },
                    "DO" : [
                      { "CONDITIONAL" : [
                          {
                            "IF" : { "NOT data_is" : { "data" : [ "comment:node:author" ], "value" : [ "site:current-user" ] } },
                            "DO" : [
                              { "privatemsg_rules_new" : {
                                  "USING" : {
                                    "recipient" : [ "entity-fetched-user" ],
                                    "author" : "1",
                                    "subject" : "\\u041a \\u043d\\u0430\\u0431\\u043e\\u0440\\u0443 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043e\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439. ",
                                    "body" : "\\u0414\\u043e\\u0431\\u0440\\u044b\\u0439 \\u0434\\u0435\\u043d\\u044c!\\r\\n\\u0423\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u044f\\u0435\\u043c \\u0412\\u0430\\u0441 \\u043e \\u0442\\u043e\\u043c, \\u0447\\u0442\\u043e \\u043a \\u043d\\u0430\\u0431\\u043e\\u0440\\u0443 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445  \\u003Ca href=\\u0022[comment:node:url]\\u0022\\u003E[comment:node:title]\\u003C\\/a\\u003E \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u0435\\u043c \\u043e\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439."
                                  },
                                  "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
                                }
                              },
                              { "drupal_message" : { "message" : "\\u043f\\u0440\\u043e\\u0432\\u0435\\u0440\\u0438\\u0442\\u044c \\u043f\\u043e\\u0447\\u0442\\u0443 \\u043f\\u043e \\u0430\\u0434\\u0440\\u0435\\u0441\\u0430\\u043c - [entity-fetched-user:mail] \\u003Cbr\\/\\u003E\\r\\n\\u0447\\u0442\\u043e \\u043a \\u043d\\u0430\\u0431\\u043e\\u0440\\u0443 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u003Ca href=\\u0022[comment:node:url]\\u0022\\u003E[comment:node:title]\\u003C\\/a\\u003E \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u0435\\u043c \\u043e\\u0441\\u0442\\u0430\\u0432\\u043b\\u0435\\u043d \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439." } }
                            ]
                          }
                        ]
                      }
                    ]
                  }
                ]
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
