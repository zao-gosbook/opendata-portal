<?php
/**
 * @file
 * publisher_requests.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function publisher_requests_default_rules_configuration() {
  $items = array();
  $items['rules_create_publisher_request_node'] = entity_import('rules_config', '{ "rules_create_publisher_request_node" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0438 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "entityform_to_node", "rules_conditional" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "request_to_become_a_publisher" } }
      ],
      "DO" : [
        { "entityform_to_node_copy_create_node" : {
            "USING" : {
              "ef" : [ "entity" ],
              "config" : { "value" : {
                  "entityform_type" : "request_to_become_a_publisher",
                  "node_type" : "publisher_request",
                  "field_mappings" : {
                    "field_pubreq_organization_exists" : "field_pubreq_organization_exists",
                    "field_pubreq_created_org" : "field_pubreq_created_org",
                    "field_pubreq_selected_org" : "field_pubreq_selected_org",
                    "field_pubreg_post" : "field_pubreg_post",
                    "field_pubreq_phone" : "field_pubreq_phone",
                    "field_pubreg_name" : "field_pubreg_name",
                    "field_pubreg_surname" : "field_pubreg_surname",
                    "field_pubreg_patronymic" : "field_pubreg_patronymic"
                  }
                }
              },
              "create_fields" : 0,
              "save_node" : 1
            },
            "PROVIDE" : { "node_created" : { "node_created" : "Created node" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "node_is_of_type" : {
                  "node" : [ "node-created" ],
                  "type" : { "value" : { "publisher_request" : "publisher_request" } }
                }
              },
              "DO" : [
                { "data_set" : {
                    "data" : [ "node-created:field-pubreq-user" ],
                    "value" : [ "entity:user" ]
                  }
                },
                { "data_set" : {
                    "data" : [ "node-created:title" ],
                    "value" : "\\u0417\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e  - [entity:uid]\\/[entity:user]\\/[entity:created]"
                  }
                }
              ]
            }
          ]
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_deny_or_reject_publisher_request'] = entity_import('rules_config', '{ "rules_deny_or_reject_publisher_request" : {
      "LABEL" : "\\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0438\\u043b\\u0438 \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443 \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--publisher_request" : { "bundle" : "publisher_request" } },
      "IF" : [
        { "data_is" : {
            "data" : [ "node:field-pubreq-status" ],
            "op" : "IN",
            "value" : { "value" : { "denied" : "denied", "sendedback" : "sendedback" } }
          }
        },
        { "NOT data_is" : {
            "data" : [ "node:field-pubreg-message" ],
            "value" : [ "node-unchanged:field-pubreg-message" ]
          }
        }
      ],
      "DO" : [
        { "component_rules_reject_request_publisher" : { "node" : [ "node" ] } },
        { "component_rules_sent_to_rework_publisher_request" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_fill_up_user_profile'] = entity_import('rules_config', '{ "rules_fill_up_user_profile" : {
      "LABEL" : "\\u0417\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u0435 \\u043f\\u0440\\u043e\\u0444\\u0438\\u043b\\u044f \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044f",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "request_to_become_a_publisher" } }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "entity:user:field-user-name" ],
            "value" : [ "entity:field-pubreg-name" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity:user:field-user-last-name" ],
            "value" : [ "entity:field-pubreg-surname" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity:user:field-user-middle-name" ],
            "value" : [ "entity:field-pubreg-patronymic" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity:user:field-user-work-position" ],
            "value" : [ "entity:field-pubreg-post" ]
          }
        },
        { "data_set" : {
            "data" : [ "entity:user:field-contact-phone-number" ],
            "value" : [ "entity:field-pubreq-phone" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_link_condition_approve_publisher_request'] = entity_import('rules_config', '{ "rules_link_condition_approve_publisher_request" : {
      "LABEL" : "Rules link: \\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u0438\\u0442\\u044c \\u0437\\u043d\\u0430\\u0447\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e condition",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "publisher_request" : "publisher_request" } }
          }
        },
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
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "publisher_request" : "publisher_request" } }
          }
        },
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
              { "drupal_message" : { "message" : "\\u0412\\u0432\\u0435\\u0434\\u0438\\u0442\\u0435 \\u043f\\u0440\\u0438\\u0447\\u0438\\u043d\\u044b \\u043e\\u0442\\u043a\\u0430\\u0437\\u0430 \\u0432 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0435." } }
            ],
            "LABEL" : "\\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u0437\\u0430\\u044f\\u0432\\u043a\\u0443 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e"
          }
        }
      ]
    }
  }');
  $items['rules_pub_resuest'] = entity_import('rules_config', '{ "rules_pub_resuest" : {
      "LABEL" : "\\u0411\\u0438\\u0437\\u043d\\u0435\\u0441-\\u043f\\u0440\\u043e\\u0446\\u0435\\u0441\\u0441 - \\u0417\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "rules_dev_comments", "php" ],
      "USES VARIABLES" : {
        "node" : { "label" : "node", "type" : "node" },
        "user" : { "label" : "user", "type" : "user" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "variable_added" : { "var_organization" : "Orgranization" } },
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "node" ],
                  "type" : "node",
                  "bundle" : { "value" : { "publisher_request" : "publisher_request" } }
                }
              },
              { "data_is" : { "data" : [ "node:field-pubreq-status" ], "value" : "approved" } }
            ],
            "DO" : [
              { "CONDITIONAL" : [
                  { "DO" : [] },
                  {
                    "ELSE IF" : { "data_is" : { "data" : [ "node:field-pubreq-organization-exists" ], "value" : 0 } },
                    "DO" : [
                      { "php_eval" : { "code" : "$wrapper = entity_metadata_wrapper(\\u0027node\\u0027, $node);\\r\\n$org = $wrapper-\\u003Efield_pubreq_created_org-\\u003Evalue();\\r\\n$org-\\u003Etype = \\u0027organization\\u0027;\\r\\nnode_save($org);" } }
                    ]
                  }
                ]
              },
              { "DO" : [] },
              { "user_add_role" : {
                  "account" : [ "node:field-pubreq-user" ],
                  "roles" : { "value" : { "6" : "6" } }
                }
              },
              { "entity_save" : { "data" : [ "node:field-pubreq-user" ], "immediate" : 1 } },
              { "DO" : [] },
              { "variable_add" : {
                  "USING" : { "type" : "node", "value" : [ "" ] },
                  "PROVIDE" : { "variable_added" : { "var_organization" : "Orgranization" } }
                }
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "data_is" : { "data" : [ "node:field-pubreq-organization-exists" ], "value" : 1 } },
                    "DO" : [
                      { "data_set" : {
                          "data" : [ "var-organization" ],
                          "value" : [ "node:field-pubreq-selected-org" ]
                        }
                      }
                    ]
                  },
                  { "ELSE" : [
                      { "data_set" : {
                          "data" : [ "var-organization" ],
                          "value" : [ "node:field-pubreq-created-org" ]
                        }
                      }
                    ]
                  }
                ]
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "entity_has_field" : {
                        "entity" : [ "var-organization" ],
                        "field" : "field_organization_curators"
                      }
                    },
                    "DO" : [
                      { "list_add" : {
                          "list" : [ "var-organization:field-organization-curators" ],
                          "item" : [ "user" ],
                          "unique" : 1
                        }
                      }
                    ]
                  }
                ]
              },
              { "mail" : {
                  "to" : [ "node:field-pubreq-user:mail" ],
                  "subject" : "\\u0418\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u0435 \\u0441\\u0442\\u0430\\u0442\\u0443\\u0441\\u0430 \\u0432\\u0430\\u0448\\u0435\\u0433\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 \\u043d\\u0430 \\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c",
                  "message" : "\\u0412\\u0430\\u0448 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c, \\u0438 \\u0442\\u0435\\u043f\\u0435\\u0440\\u044c \\u0432\\u044b \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0435\\u0441\\u044c \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c.",
                  "language" : [ "" ]
                }
              }
            ],
            "LABEL" : "\\u041f\\u043e\\u0434\\u0442\\u0432\\u0435\\u0440\\u0436\\u0434\\u0435\\u043d\\u0438\\u0435 - \\u0437\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e"
          }
        },
        { "RULE" : {
            "IF" : [
              { "entity_is_of_bundle" : {
                  "entity" : [ "node" ],
                  "type" : "node",
                  "bundle" : { "value" : { "publisher_request" : "publisher_request" } }
                }
              },
              { "data_is" : { "data" : [ "node:field-pubreq-organization-exists" ], "value" : 1 } }
            ],
            "DO" : [
              { "entity_delete" : { "data" : [ "node:field-pubreq-created-org" ] } },
              { "data_set" : { "data" : [ "node:field-pubreq-created-org" ], "value" : [ "" ] } }
            ],
            "LABEL" : "\\u0423\\u0434\\u0430\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438 - \\u0437\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e"
          }
        }
      ]
    }
  }');
  $items['rules_publisher_request_reworked'] = entity_import('rules_config', '{ "rules_publisher_request_reworked" : {
      "LABEL" : "\\u0414\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0430 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0438 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--publisher_request" : { "bundle" : "publisher_request" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:field-pubreg-reworked" ],
            "value" : [ "node-unchanged:field-pubreg-reworked" ]
          }
        },
        { "data_is" : { "data" : [ "node:field-pubreg-reworked" ], "value" : 1 } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-pubreq-status" ], "value" : "reworked" } }
      ]
    }
  }');
  $items['rules_publisher_request_workflow'] = entity_import('rules_config', '{ "rules_publisher_request_workflow" : {
      "LABEL" : "\\u0411\\u0438\\u0437\\u043d\\u0435\\u0441-\\u043f\\u0440\\u043e\\u0446\\u0435\\u0441\\u0441 - \\u0417\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_update--publisher_request" : { "bundle" : "publisher_request" } },
      "IF" : [
        { "NOT data_is" : {
            "data" : [ "node:field-pubreq-status" ],
            "value" : [ "node-unchanged:field-pubreq-status" ]
          }
        }
      ],
      "DO" : [
        { "component_rules_pub_resuest" : { "node" : [ "node" ], "user" : [ "node:field-pubreq-user" ] } }
      ]
    }
  }');
  $items['rules_reject_request_publisher'] = entity_import('rules_config', '{ "rules_reject_request_publisher" : {
      "LABEL" : "\\u041e\\u0442\\u043a\\u0430\\u0437\\u0430\\u043d\\u043e - \\u0437\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "publisher_request" : "publisher_request" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-pubreq-status" ], "value" : "denied" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-pubreq-user:mail" ],
            "subject" : "\\u0418\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u0435 \\u0441\\u0442\\u0430\\u0442\\u0443\\u0441\\u0430 \\u0432\\u0430\\u0448\\u0435\\u0433\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 \\u043d\\u0430 \\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c",
            "message" : "\\u0412\\u0430\\u0448\\u0430 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0435\\u043d\\u0430 \\u043f\\u043e \\u043f\\u0440\\u0438\\u0447\\u0438\\u043d\\u0435: [node:field-pubreg-message]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_sent_to_rework_publisher_request'] = entity_import('rules_config', '{ "rules_sent_to_rework_publisher_request" : {
      "LABEL" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u0438\\u0442\\u044c \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443 - \\u0437\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "publisher_request" : "publisher_request" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-pubreq-status" ], "value" : "sendedback" } }
      ],
      "DO" : [
        { "mail" : {
            "to" : [ "node:field-pubreq-user:mail" ],
            "subject" : "\\u0418\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u0435 \\u0441\\u0442\\u0430\\u0442\\u0443\\u0441\\u0430 \\u0432\\u0430\\u0448\\u0435\\u0433\\u043e \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 \\u043d\\u0430 \\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u043e\\u043c",
            "message" : "\\u0412\\u0430\\u0448\\u0430 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u0430 \\u043d\\u0430 \\u0434\\u043e\\u0440\\u0430\\u0431\\u043e\\u0442\\u043a\\u0443 \\u043f\\u043e \\u043f\\u0440\\u0438\\u0447\\u0438\\u043d\\u0435: [node:field-pubreg-message]\\r\\n\\r\\n\\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0437\\u0430\\u044f\\u0432\\u043a\\u0443: [node:edit-url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  return $items;
}
