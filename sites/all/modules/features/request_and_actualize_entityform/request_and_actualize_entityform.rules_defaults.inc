<?php
/**
 * @file
 * request_and_actualize_entityform.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function request_and_actualize_entityform_default_rules_configuration() {
  $items = array();
  $items['rules_actualize_form_validation'] = entity_import('rules_config', '{ "rules_actualize_form_validation" : {
      "LABEL" : "\\u0412\\u0430\\u043b\\u0438\\u0434\\u0430\\u0446\\u0438\\u044f \\u0444\\u043e\\u0440\\u043c\\u044b \\u0430\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438 \\u041d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_validation" ],
      "REQUIRES" : [ "rules", "rules_conditional", "rules_dev_comments" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "entity_is_validate" : { "label" : "Entity Validates", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_actualization" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 1 } },
        { "DO" : [] },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "entity:field-dataset-variant" ], "value" : "external" } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "entity:field-link-passport:url" ] } },
                      "DO" : [
                        { "drupal_message" : {
                            "message" : "\\u0417\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e\\u043b\\u044f \\u0022\\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0443 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 \\u043e\\u0431\\u043b\\u0430\\u0434\\u0430\\u0442\\u0435\\u043b\\u044f\\u0022 \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c \\u0434\\u043b\\u044f \\u0432\\u0430\\u0440\\u0438\\u0430\\u043d\\u0442\\u0430 \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - \\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0444\\u0430\\u0439\\u043b.",
                            "type" : "error"
                          }
                        },
                        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 0 } }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "entity:field-dataset-variant" ], "value" : "api" } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "entity:field-link-api:url" ] } },
                      "DO" : [
                        { "drupal_message" : {
                            "message" : "\\u0417\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e\\u043b\\u044f \\u0022\\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 API\\u0022 \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c \\u0434\\u043b\\u044f \\u0432\\u0430\\u0440\\u0438\\u0430\\u043d\\u0442\\u0430 \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - \\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 API.",
                            "type" : "error"
                          }
                        },
                        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 0 } }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "entity:field-dataset-variant" ], "value" : "upload" } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "entity:field-od-wizard-upload-file:file" ] } },
                      "DO" : [
                        { "drupal_message" : {
                            "message" : "\\u0417\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e\\u043b\\u044f \\u0022\\u0424\\u0430\\u0439\\u043b\\u0022 \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c \\u0434\\u043b\\u044f \\u0432\\u0430\\u0440\\u0438\\u0430\\u043d\\u0442\\u0430 \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u043a\\u0430 \\u0444\\u0430\\u0439\\u043b\\u0430.",
                            "type" : "error"
                          }
                        },
                        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 0 } }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        }
      ],
      "PROVIDES VARIABLES" : [ "entity_is_validate" ]
    }
  }');
  $items['rules_add_opendata'] = entity_import('rules_config', '{ "rules_add_opendata" : {
      "LABEL" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "rules_conditional", "rules_dev_comments" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "entity" ],
            "type" : "entityform",
            "bundle" : { "value" : { "od_preprocess_wizard" : "od_preprocess_wizard" } }
          }
        }
      ],
      "DO" : [
        { "DO" : [] },
        { "component_rules_passport_creation" : {
            "USING" : { "entity" : [ "entity" ] },
            "PROVIDE" : { "new_dataset" : { "new_dataset" : "new_dataset" } }
          }
        },
        { "DO" : [] },
        { "component_rules_create_resources" : {
            "enitityform_submission" : [ "entity" ],
            "new_dataset" : [ "new_dataset" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_create_resource_link_api_link'] = entity_import('rules_config', '{ "rules_create_resource_link_api_link" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0444\\u0430\\u0439\\u043b\\/API",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entityform_to_node", "rules_conditional" ],
      "USES VARIABLES" : {
        "enitityform_submission" : { "label" : "enitityform submission", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "enitityform-submission:type" ],
            "value" : "od_preprocess_wizard"
          }
        },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-variant" ],
            "op" : "IN",
            "value" : { "value" : { "external" : "external", "api" : "api" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "new-dataset" ],
            "type" : { "value" : { "dataset" : "dataset" } }
          }
        }
      ],
      "DO" : [
        { "entityform_to_node_copy_create_node" : {
            "USING" : {
              "ef" : [ "enitityform-submission" ],
              "config" : { "value" : {
                  "entityform_type" : "od_preprocess_wizard",
                  "node_type" : "resource",
                  "field_mappings" : {
                    "field_contact_name" : "",
                    "field_license" : "",
                    "field_link_api" : "field_link_api",
                    "field_link_remote_file" : "field_link_remote_file",
                    "field_rubric" : "",
                    "field_dataset_id" : "",
                    "field_contact_phone" : "",
                    "field_email_responsible" : "",
                    "field_organization" : "",
                    "field_date_first_time_publ" : "",
                    "field_date_last_change" : "",
                    "field_date_dataset_actual" : "",
                    "field_content_last_change" : "field_provenance",
                    "field_data_structure" : "field_link_structure_file",
                    "field_dataset_title" : "",
                    "field_od_wizard_upload_file" : "",
                    "field_link_passport" : "field_link_passport",
                    "field_dataset_variant" : "",
                    "field_od_wizard_upload_structure" : ""
                  }
                }
              },
              "create_fields" : 0,
              "save_node" : 0
            },
            "PROVIDE" : { "node_created" : { "node_created" : "Created node" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "node-created:type" ], "value" : "resource" } },
              "DO" : [
                { "data_set" : {
                    "data" : [ "node-created:field-created" ],
                    "value" : [ "enitityform-submission:created" ]
                  }
                },
                { "data_set" : {
                    "data" : [ "node-created:title" ],
                    "value" : "[new-dataset:title] - [site:current-date:custom:d.m.Y]"
                  }
                },
                { "data_set" : {
                    "data" : [ "node-created:field-dataset-ref" ],
                    "value" : [ "new-dataset" ]
                  }
                }
              ]
            }
          ]
        },
        { "entity_save" : { "data" : [ "node-created" ], "immediate" : 1 } },
        { "list_add" : {
            "list" : [ "new-dataset:field-resources" ],
            "item" : [ "node-created" ],
            "unique" : 1
          }
        }
      ]
    }
  }');
  $items['rules_create_resource_ulpload'] = entity_import('rules_config', '{ "rules_create_resource_ulpload" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u0442\\u044c \\u0444\\u0430\\u0439\\u043b (\\u0441 \\u043a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u0435\\u0439 \\u0438 \\u0431\\u0435\\u0437)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [
        "rules",
        "od_file_process",
        "entityform_to_node",
        "rules_conditional",
        "file_rules",
        "php"
      ],
      "USES VARIABLES" : {
        "enitityform_submission" : { "label" : "enitityform submission", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "enitityform-submission:type" ],
            "value" : "od_preprocess_wizard"
          }
        },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-variant" ],
            "value" : "upload"
          }
        },
        { "data_is" : { "data" : [ "new-dataset:type" ], "value" : "dataset" } }
      ],
      "DO" : [
        { "od_file_process_rule_callback_get_files" : {
            "USING" : {
              "file_2process" : [ "enitityform-submission:field-od-wizard-upload-file" ],
              "can_expire" : 1
            },
            "PROVIDE" : {
              "created_files" : { "upload_files_list" : "upload_files_list" },
              "created_structure" : { "created_structure" : "Created structure file" },
              "created_structure_media" : { "created_structure_media" : "Created structure file (field_item_file)" }
            }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "upload-files-list" ] },
            "ITEM" : { "upload_file" : "upload_file" },
            "DO" : [
              { "entityform_to_node_copy_create_node" : {
                  "USING" : {
                    "ef" : [ "enitityform-submission" ],
                    "config" : { "value" : {
                        "entityform_type" : "od_preprocess_wizard",
                        "node_type" : "resource",
                        "field_mappings" : {
                          "field_contact_name" : "",
                          "field_license" : "",
                          "field_link_api" : "",
                          "field_link_remote_file" : "",
                          "field_rubric" : "",
                          "field_dataset_id" : "",
                          "field_contact_phone" : "",
                          "field_email_responsible" : "",
                          "field_organization" : "",
                          "field_date_first_time_publ" : "",
                          "field_date_last_change" : "",
                          "field_date_dataset_actual" : "",
                          "field_content_last_change" : "field_provenance",
                          "field_data_structure" : "",
                          "field_dataset_title" : "",
                          "field_od_wizard_upload_file" : "",
                          "field_link_passport" : "",
                          "field_dataset_variant" : "",
                          "field_od_wizard_upload_structure" : ""
                        }
                      }
                    },
                    "create_fields" : 0,
                    "save_node" : 0
                  },
                  "PROVIDE" : { "node_created" : { "node_created" : "Created node" } }
                }
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "data_is" : { "data" : [ "node-created:type" ], "value" : "resource" } },
                    "DO" : [
                      { "data_set" : {
                          "data" : [ "node-created:field-created" ],
                          "value" : [ "enitityform-submission:created" ]
                        }
                      },
                      { "data_set" : {
                          "data" : [ "node-created:title" ],
                          "value" : "[new-dataset:title] - [site:current-date:custom:d.m.Y]"
                        }
                      },
                      { "data_set" : {
                          "data" : [ "node-created:field-dataset-ref" ],
                          "value" : [ "new-dataset" ]
                        }
                      },
                      { "file_rules_copy_file" : {
                          "source_entity" : [ "enitityform-submission" ],
                          "source_field" : "field_od_wizard_upload_file",
                          "destination_entity" : [ "node-created" ],
                          "destination_field" : "field_upload_original",
                          "remove_source" : "0"
                        }
                      },
                      { "CONDITIONAL" : [
                          {
                            "IF" : { "data_is" : {
                                "data" : [ "enitityform-submission:field-dataset-convert" ],
                                "value" : 0
                              }
                            },
                            "DO" : [
                              { "file_rules_copy_file" : {
                                  "source_entity" : [ "enitityform-submission" ],
                                  "source_field" : "field_od_wizard_upload_structure",
                                  "destination_entity" : [ "node-created" ],
                                  "destination_field" : "field_upload_structure",
                                  "remove_source" : "0"
                                }
                              }
                            ]
                          },
                          { "ELSE" : [
                              { "data_set" : {
                                  "data" : [ "node-created:field-upload-structure" ],
                                  "value" : [ "created-structure-media" ]
                                }
                              }
                            ]
                          }
                        ]
                      },
                      { "data_set" : { "data" : [ "node-created:field-upload" ], "value" : [ "upload-file" ] } }
                    ]
                  }
                ]
              },
              { "entity_save" : { "data" : [ "node-created" ], "immediate" : 1 } },
              { "list_add" : {
                  "list" : [ "new-dataset:field-resources" ],
                  "item" : [ "node-created" ],
                  "unique" : 1
                }
              }
            ]
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "php_eval" : { "code" : "return count($upload_files_list) \\u003E 1;" } },
              "DO" : [
                { "data_set" : { "data" : [ "new-dataset:field-multivolume" ], "value" : 1 } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_create_resources'] = entity_import('rules_config', '{ "rules_create_resources" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "enitityform_submission" : { "label" : "enitityform submission", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "enitityform-submission:type" ],
            "value" : "od_preprocess_wizard"
          }
        }
      ],
      "DO" : [
        { "component_rules_create_resource_link_api_link" : {
            "enitityform_submission" : [ "enitityform_submission" ],
            "new_dataset" : [ "new_dataset" ]
          }
        },
        { "component_rules_create_resource_ulpload" : {
            "enitityform_submission" : [ "enitityform_submission" ],
            "new_dataset" : [ "new_dataset" ]
          }
        }
      ]
    }
  }');
  $items['rules_dataset_actualization_form'] = entity_import('rules_config', '{ "rules_dataset_actualization_form" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_actualization" } }
      ],
      "DO" : [
        { "component_rules_passport_actualization" : {
            "USING" : { "entity" : [ "entity" ] },
            "PROVIDE" : { "new_dataset" : { "new_dataset" : "new_dataset" } }
          }
        },
        { "component_rules_resource_updating" : {
            "enitityform_submission" : [ "entity" ],
            "new_dataset" : [ "new_dataset" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_passport_actualization'] = entity_import('rules_config', '{ "rules_passport_actualization" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043f\\u0430\\u0441\\u043f\\u043e\\u0440\\u0442\\u0430",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "rules_conditional", "rules_dev_comments" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node", "parameter" : false }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_actualization" } },
        { "node_is_of_type" : {
            "node" : [ "entity:field-ef-dataset" ],
            "type" : { "value" : { "dataset" : "dataset" } }
          }
        }
      ],
      "DO" : [
        { "DO" : [] },
        { "data_set" : {
            "data" : [ "entity:field-ef-dataset:field-date-last-change" ],
            "value" : [ "entity:field-date-last-change" ]
          }
        },
        { "data_set" : { "data" : [ "new-dataset" ], "value" : [ "entity:field-ef-dataset" ] } }
      ],
      "PROVIDES VARIABLES" : [ "new_dataset" ]
    }
  }');
  $items['rules_passport_creation'] = entity_import('rules_config', '{ "rules_passport_creation" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u043f\\u0430\\u0441\\u043f\\u043e\\u0440\\u0442\\u0430",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [
        "rules",
        "rules_conditional",
        "rules_dev_comments",
        "entityform_to_node"
      ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node", "parameter" : false }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "od_preprocess_wizard" } }
      ],
      "DO" : [
        { "DO" : [] },
        { "entityform_to_node_copy_create_node" : {
            "USING" : {
              "ef" : [ "entity" ],
              "config" : { "value" : {
                  "entityform_type" : "od_preprocess_wizard",
                  "node_type" : "dataset",
                  "field_mappings" : {
                    "field_contact_name" : "field_contact_name",
                    "field_license" : "field_license",
                    "field_tags" : "field_tags",
                    "field_rubric" : "field_rubric",
                    "field_dataset_id" : "field_dataset_id",
                    "field_contact_phone" : "field_contact_phone",
                    "field_email_responsible" : "field_email_responsible",
                    "field_organization" : "field_organization",
                    "field_date_first_time_publ" : "field_date_first_time_publ",
                    "field_date_last_change" : "field_date_last_change",
                    "field_date_dataset_actual" : "field_date_dataset_actual",
                    "field_content_last_change" : "",
                    "field_dataset_title" : "",
                    "field_dataset_body" : "field_dataset_body",
                    "field_dataset_variant" : "",
                    "field_dataset_convert" : ""
                  }
                }
              },
              "create_fields" : 0,
              "save_node" : 1
            },
            "PROVIDE" : { "node_created" : { "new_dataset_node" : "new_dataset_node" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "new-dataset-node:type" ], "value" : "dataset" } },
              "DO" : [
                { "data_set" : {
                    "data" : [ "new-dataset-node:title" ],
                    "value" : [ "entity:field-dataset-title" ]
                  }
                },
                { "data_set" : {
                    "data" : [ "new-dataset-node:field-dataset-title" ],
                    "value" : [ "entity:field-dataset-title" ]
                  }
                },
                { "data_set" : {
                    "data" : [ "new-dataset-node:field-owner" ],
                    "value" : [ "entity:field-organization:title" ]
                  }
                },
                { "entity_save" : { "data" : [ "new-dataset-node" ], "immediate" : 1 } },
                { "data_set" : {
                    "data" : [ "new-dataset-node:field-rubric" ],
                    "value" : [ "entity:field-rubric" ]
                  }
                }
              ]
            }
          ]
        },
        { "data_set" : { "data" : [ "new-dataset" ], "value" : [ "new-dataset-node" ] } }
      ],
      "PROVIDES VARIABLES" : [ "new_dataset" ]
    }
  }');
  $items['rules_resource_actualization_file_link_or_api'] = entity_import('rules_config', '{ "rules_resource_actualization_file_link_or_api" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0444\\u0430\\u0439\\u043b\\/API",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entityform_to_node", "rules_conditional" ],
      "USES VARIABLES" : {
        "enitityform_submission" : { "label" : "enitityform submission", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "enitityform-submission:type" ],
            "value" : "dataset_actualization"
          }
        },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-variant" ],
            "op" : "IN",
            "value" : { "value" : { "external" : "external", "api" : "api" } }
          }
        },
        { "node_is_of_type" : {
            "node" : [ "new-dataset" ],
            "type" : { "value" : { "dataset" : "dataset" } }
          }
        }
      ],
      "DO" : [
        { "entityform_to_node_copy_create_node" : {
            "USING" : {
              "ef" : [ "enitityform-submission" ],
              "config" : { "value" : {
                  "entityform_type" : "od_preprocess_wizard",
                  "node_type" : "resource",
                  "field_mappings" : {
                    "field_contact_name" : "",
                    "field_license" : "",
                    "field_link_api" : "field_link_api",
                    "field_link_remote_file" : "field_link_remote_file",
                    "field_rubric" : "",
                    "field_dataset_id" : "",
                    "field_contact_phone" : "",
                    "field_email_responsible" : "",
                    "field_organization" : "",
                    "field_date_first_time_publ" : "",
                    "field_date_last_change" : "",
                    "field_date_dataset_actual" : "",
                    "field_content_last_change" : "field_provenance",
                    "field_data_structure" : "field_link_structure_file",
                    "field_dataset_title" : "",
                    "field_od_wizard_upload_file" : "",
                    "field_link_passport" : "field_link_passport",
                    "field_dataset_variant" : "",
                    "field_od_wizard_upload_structure" : ""
                  }
                }
              },
              "create_fields" : 0,
              "save_node" : 0
            },
            "PROVIDE" : { "node_created" : { "node_created" : "Created node" } }
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "node-created:type" ], "value" : "resource" } },
              "DO" : [
                { "data_set" : {
                    "data" : [ "node-created:field-created" ],
                    "value" : [ "enitityform-submission:created" ]
                  }
                },
                { "data_set" : {
                    "data" : [ "node-created:title" ],
                    "value" : "[new-dataset:title] - [site:current-date:custom:d.m.Y]"
                  }
                },
                { "data_set" : {
                    "data" : [ "node-created:field-dataset-ref" ],
                    "value" : [ "new-dataset" ]
                  }
                }
              ]
            }
          ]
        },
        { "entity_save" : { "data" : [ "node-created" ], "immediate" : 1 } },
        { "list_add" : {
            "list" : [ "new-dataset:field-resources" ],
            "item" : [ "node-created" ],
            "unique" : 1
          }
        }
      ]
    }
  }');
  $items['rules_resource_actualization_upload_file'] = entity_import('rules_config', '{ "rules_resource_actualization_upload_file" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u0442\\u044c \\u0444\\u0430\\u0439\\u043b (\\u0441 \\u043a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u0435\\u0439 \\u0438 \\u0431\\u0435\\u0437)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [
        "rules",
        "od_file_process",
        "entityform_to_node",
        "rules_conditional",
        "file_rules",
        "php"
      ],
      "USES VARIABLES" : {
        "enitityform_submission" : { "label" : "enitityform submission", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "enitityform-submission:type" ],
            "value" : "od_preprocess_wizard"
          }
        },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-variant" ],
            "value" : "upload"
          }
        },
        { "data_is" : { "data" : [ "new-dataset:type" ], "value" : "dataset" } }
      ],
      "DO" : [
        { "od_file_process_rule_callback_get_files" : {
            "USING" : {
              "file_2process" : [ "enitityform-submission:field-od-wizard-upload-file" ],
              "can_expire" : 1
            },
            "PROVIDE" : {
              "created_files" : { "upload_files_list" : "upload_files_list" },
              "created_structure" : { "created_structure" : "Created structure file" },
              "created_structure_media" : { "created_structure_media" : "Created structure file (field_item_file)" }
            }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "upload-files-list" ] },
            "ITEM" : { "upload_file" : "upload_file" },
            "DO" : [
              { "entityform_to_node_copy_create_node" : {
                  "USING" : {
                    "ef" : [ "enitityform-submission" ],
                    "config" : { "value" : {
                        "entityform_type" : "od_preprocess_wizard",
                        "node_type" : "resource",
                        "field_mappings" : {
                          "field_contact_name" : "",
                          "field_license" : "",
                          "field_link_api" : "",
                          "field_link_remote_file" : "",
                          "field_rubric" : "",
                          "field_dataset_id" : "",
                          "field_contact_phone" : "",
                          "field_email_responsible" : "",
                          "field_organization" : "",
                          "field_date_first_time_publ" : "",
                          "field_date_last_change" : "",
                          "field_date_dataset_actual" : "",
                          "field_content_last_change" : "field_provenance",
                          "field_data_structure" : "",
                          "field_dataset_title" : "",
                          "field_od_wizard_upload_file" : "",
                          "field_link_passport" : "",
                          "field_dataset_variant" : "",
                          "field_od_wizard_upload_structure" : ""
                        }
                      }
                    },
                    "create_fields" : 0,
                    "save_node" : 0
                  },
                  "PROVIDE" : { "node_created" : { "node_created" : "Created node" } }
                }
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "data_is" : { "data" : [ "node-created:type" ], "value" : "resource" } },
                    "DO" : [
                      { "data_set" : {
                          "data" : [ "node-created:field-created" ],
                          "value" : [ "enitityform-submission:created" ]
                        }
                      },
                      { "data_set" : {
                          "data" : [ "node-created:title" ],
                          "value" : "[new-dataset:title] - [site:current-date:custom:d.m.Y]"
                        }
                      },
                      { "data_set" : {
                          "data" : [ "node-created:field-dataset-ref" ],
                          "value" : [ "new-dataset" ]
                        }
                      },
                      { "file_rules_copy_file" : {
                          "source_entity" : [ "enitityform-submission" ],
                          "source_field" : "field_od_wizard_upload_file",
                          "destination_entity" : [ "node-created" ],
                          "destination_field" : "field_upload_original",
                          "remove_source" : "0"
                        }
                      },
                      { "CONDITIONAL" : [
                          {
                            "IF" : { "data_is" : {
                                "data" : [ "enitityform-submission:field-dataset-convert" ],
                                "value" : 0
                              }
                            },
                            "DO" : [
                              { "file_rules_copy_file" : {
                                  "source_entity" : [ "enitityform-submission" ],
                                  "source_field" : "field_od_wizard_upload_structure",
                                  "destination_entity" : [ "node-created" ],
                                  "destination_field" : "field_upload_structure",
                                  "remove_source" : "0"
                                }
                              }
                            ]
                          },
                          { "ELSE" : [
                              { "data_set" : {
                                  "data" : [ "node-created:field-upload-structure" ],
                                  "value" : [ "created-structure-media" ]
                                }
                              }
                            ]
                          }
                        ]
                      },
                      { "data_set" : { "data" : [ "node-created:field-upload" ], "value" : [ "upload-file" ] } }
                    ]
                  }
                ]
              },
              { "entity_save" : { "data" : [ "node-created" ], "immediate" : 1 } },
              { "list_add" : {
                  "list" : [ "new-dataset:field-resources" ],
                  "item" : [ "node-created" ],
                  "unique" : 1
                }
              }
            ]
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "php_eval" : { "code" : "return count($upload_files_list) \\u003E 1;" } },
              "DO" : [
                { "data_set" : { "data" : [ "new-dataset:field-multivolume" ], "value" : 1 } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_resource_updating'] = entity_import('rules_config', '{ "rules_resource_updating" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "enitityform_submission" : { "label" : "enitityform submission", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "enitityform-submission:type" ],
            "value" : "dataset_actualization"
          }
        }
      ],
      "DO" : [
        { "component_rules_resource_actualization_file_link_or_api" : {
            "enitityform_submission" : [ "enitityform_submission" ],
            "new_dataset" : [ "new_dataset" ]
          }
        },
        { "component_rules_resource_actualization_upload_file" : {
            "enitityform_submission" : [ "enitityform_submission" ],
            "new_dataset" : [ "new_dataset" ]
          }
        }
      ]
    }
  }');
  $items['rules_validation_od_preprocess_wizard'] = entity_import('rules_config', '{ "rules_validation_od_preprocess_wizard" : {
      "LABEL" : "\\u0412\\u0430\\u043b\\u0438\\u0434\\u0430\\u0446\\u0438\\u044f \\u0444\\u043e\\u0440\\u043c\\u044b \\u0414\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_validation" ],
      "REQUIRES" : [ "rules", "rules_conditional", "rules_dev_comments" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "entity_is_validate" : { "label" : "Entity Validates", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "od_preprocess_wizard" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 1 } },
        { "DO" : [] },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "entity:field-dataset-variant" ], "value" : "external" } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "entity:field-link-passport:url" ] } },
                      "DO" : [
                        { "drupal_message" : {
                            "message" : "\\u0417\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e\\u043b\\u044f \\u0022\\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0443 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 \\u043e\\u0431\\u043b\\u0430\\u0434\\u0430\\u0442\\u0435\\u043b\\u044f\\u0022 \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c \\u0434\\u043b\\u044f \\u0432\\u0430\\u0440\\u0438\\u0430\\u043d\\u0442\\u0430 \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - \\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0444\\u0430\\u0439\\u043b.",
                            "type" : "error"
                          }
                        },
                        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 0 } }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "entity:field-dataset-variant" ], "value" : "api" } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "entity:field-link-api:url" ] } },
                      "DO" : [
                        { "drupal_message" : {
                            "message" : "\\u0417\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e\\u043b\\u044f \\u0022\\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 API\\u0022 \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c \\u0434\\u043b\\u044f \\u0432\\u0430\\u0440\\u0438\\u0430\\u043d\\u0442\\u0430 \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - \\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 API.",
                            "type" : "error"
                          }
                        },
                        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 0 } }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "entity:field-dataset-variant" ], "value" : "upload" } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "entity:field-od-wizard-upload-file:file" ] } },
                      "DO" : [
                        { "drupal_message" : {
                            "message" : "\\u0417\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e\\u043b\\u044f \\u0022\\u0424\\u0430\\u0439\\u043b\\u0022 \\u044f\\u0432\\u043b\\u044f\\u0435\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c \\u0434\\u043b\\u044f \\u0432\\u0430\\u0440\\u0438\\u0430\\u043d\\u0442\\u0430 \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u043a\\u0430 \\u0444\\u0430\\u0439\\u043b\\u0430.",
                            "type" : "error"
                          }
                        },
                        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 0 } }
                      ]
                    }
                  ]
                }
              ]
            }
          ]
        }
      ],
      "PROVIDES VARIABLES" : [ "entity_is_validate" ]
    }
  }');
  return $items;
}
