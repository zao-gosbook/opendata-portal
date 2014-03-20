<?php
/**
 * @file
 * views_menus_and_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function views_menus_and_rules_default_rules_configuration() {
  $items = array();
  $items['rules_access_rule_dataset_is_multivolume'] = entity_import('rules_config', '{ "rules_access_rule_dataset_is_multivolume" : {
      "LABEL" : "Access rule: \\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043c\\u043d\\u043e\\u0433\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "resource" : "resource" } }
          }
        },
        { "data_is" : { "data" : [ "node:field-dataset-ref:type" ], "value" : "dataset" } },
        { "data_is" : { "data" : [ "node:field-dataset-ref:field-multivolume" ], "value" : 1 } }
      ]
    }
  }');
  $items['rules_access_rule_geofield_is_empty'] = entity_import('rules_config', '{ "rules_access_rule_geofield_is_empty" : {
      "LABEL" : "Access rule: Geofield \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043f\\u0443\\u0441\\u0442\\u043e\\u0435",
      "PLUGIN" : "and",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "AND" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "dataset" : "dataset" } } } },
        { "data_is_empty" : { "data" : [ "node:field-spatial" ] } }
      ]
    }
  }');
  $items['rules_actualize_dataset_multivolume'] = entity_import('rules_config', '{ "rules_actualize_dataset_multivolume" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 (\\u041c\\u043d\\u043e\\u0433\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439 \\u043d\\u0430\\u0431\\u043e\\u0440)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_actualization_multivol" } }
      ],
      "DO" : [
        { "component_rules_passport_actualization_multivolume" : {
            "USING" : { "entity" : [ "entity" ] },
            "PROVIDE" : { "new_dataset" : { "new_dataset" : "new_dataset" } }
          }
        },
        { "component_rules_actualize_dataset_one_volume_without_convert_multivolume" : {
            "enitityform_submission" : [ "entity" ],
            "new_dataset" : [ "new_dataset" ]
          }
        },
        { "component_rules_upload_file_actualization_multivolume" : {
            "enitityform_submission" : [ "entity" ],
            "new_dataset" : [ "new_dataset" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_actualize_dataset_one_volume'] = entity_import('rules_config', '{ "rules_actualize_dataset_one_volume" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 (\\u041e\\u0434\\u043d\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439 \\u043d\\u0430\\u0431\\u043e\\u0440)",
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
        { "component_rules_resource_actualization_file_link_or_api" : {
            "enitityform_submission" : [ "entity" ],
            "new_dataset" : [ "new_dataset" ]
          }
        },
        { "component_rules_upload_file_actualization__one_volume" : {
            "enitityform_submission" : [ "entity" ],
            "new_dataset" : [ "new_dataset" ]
          }
        },
        { "component_rules_actualize_dataset_one_volume_without_convert" : {
            "enitityform_submission" : [ "entity" ],
            "new_dataset" : [ "new_dataset" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_actualize_dataset_one_volume_without_convert'] = entity_import('rules_config', '{ "rules_actualize_dataset_one_volume_without_convert" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u0442\\u044c \\u0444\\u0430\\u0439\\u043b (\\u0431\\u0435\\u0437 \\u043a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u0438) (\\u041e\\u0434\\u043d\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [
        "rules",
        "od_file_process",
        "entityform_to_node",
        "rules_conditional",
        "file_rules",
        "od_common"
      ],
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
            "value" : "upload"
          }
        },
        { "data_is" : { "data" : [ "new-dataset:type" ], "value" : "dataset" } },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-convert" ],
            "value" : 0
          }
        },
        { "data_is" : { "data" : [ "new-dataset:field-multivolume" ], "value" : 0 } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "0" },
            "PROVIDE" : { "variable_added" : { "counter" : "counter" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "new-dataset:field-resources" ] },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "od_file_process_rule_callback_get_files" : {
                  "USING" : {
                    "file_2process" : [ "enitityform-submission:field-od-wizard-upload-file" ],
                    "can_expire" : 1
                  },
                  "PROVIDE" : {
                    "created_files" : { "upload_files_list" : "upload_files_list" },
                    "created_structure" : { "created_structure" : "Created structure file" },
                    "created_structure_media" : { "created_structure_media" : "Created structure file (field_item_file)" },
                    "structure_meta" : { "structure_meta" : "Structure record as universal_data_storage entity" }
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
                          "IF" : { "data_is" : { "data" : [ "resource:type" ], "value" : "resource" } },
                          "DO" : [
                            { "file_rules_copy_file" : {
                                "source_entity" : [ "enitityform-submission" ],
                                "source_field" : "field_od_wizard_upload_file",
                                "destination_entity" : [ "resource" ],
                                "destination_field" : "field_upload_original",
                                "remove_source" : "0"
                              }
                            },
                            { "data_set" : { "data" : [ "resource:field-upload" ], "value" : [ "upload-file" ] } },
                            { "od_common_file_get_extension_term" : {
                                "USING" : { "file" : [ "upload-file" ], "vocabulary" : "format" },
                                "PROVIDE" : { "extension_term" : { "file_extension" : "file_extension" } }
                              }
                            },
                            { "data_set" : { "data" : [ "resource:field-format" ], "value" : [ "file-extension" ] } },
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
                                        "destination_entity" : [ "resource" ],
                                        "destination_field" : "field_upload_structure",
                                        "remove_source" : "0"
                                      }
                                    }
                                  ]
                                },
                                { "ELSE" : [
                                    { "data_set" : {
                                        "data" : [ "resource:field-upload-structure" ],
                                        "value" : [ "created-structure-media" ]
                                      }
                                    }
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
              },
              { "data_calc" : {
                  "USING" : { "input_1" : [ "counter" ], "op" : "+", "input_2" : "1" },
                  "PROVIDE" : { "result" : { "result" : "Calculation result" } }
                }
              },
              {
                "WHILE" : { "data_is" : { "data" : [ "result" ], "value" : "1" } },
                "DO" : []
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_actualize_dataset_one_volume_without_convert_multivolume'] = entity_import('rules_config', '{ "rules_actualize_dataset_one_volume_without_convert_multivolume" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u0442\\u044c \\u0444\\u0430\\u0439\\u043b (\\u0431\\u0435\\u0437 \\u043a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u0438) (\\u041c\\u043d\\u043e\\u0433\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [
        "rules",
        "od_file_process",
        "entityform_to_node",
        "rules_conditional",
        "file_rules",
        "od_common"
      ],
      "USES VARIABLES" : {
        "enitityform_submission" : { "label" : "enitityform submission", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "enitityform-submission:type" ],
            "value" : "dataset_actualization_multivol"
          }
        },
        { "data_is" : { "data" : [ "new-dataset:type" ], "value" : "dataset" } },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-convert" ],
            "value" : 0
          }
        },
        { "data_is" : { "data" : [ "new-dataset:field-multivolume" ], "value" : 1 } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "new-dataset:field-resources" ] },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "od_file_process_rule_callback_get_files" : {
                  "USING" : {
                    "file_2process" : [ "enitityform-submission:field-od-wizard-upload-file" ],
                    "can_expire" : 1
                  },
                  "PROVIDE" : {
                    "created_files" : { "upload_files_list" : "upload_files_list" },
                    "created_structure" : { "created_structure" : "Created structure file" },
                    "created_structure_media" : { "created_structure_media" : "Created structure file (field_item_file)" },
                    "structure_meta" : { "structure_meta" : "Structure record as universal_data_storage entity" }
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
                          "IF" : { "data_is" : { "data" : [ "resource:type" ], "value" : "resource" } },
                          "DO" : [
                            { "file_rules_copy_file" : {
                                "source_entity" : [ "enitityform-submission" ],
                                "source_field" : "field_od_wizard_upload_file",
                                "destination_entity" : [ "resource" ],
                                "destination_field" : "field_upload_original",
                                "remove_source" : "0"
                              }
                            },
                            { "data_set" : { "data" : [ "resource:field-upload" ], "value" : [ "upload-file" ] } },
                            { "od_common_file_get_extension_term" : {
                                "USING" : { "file" : [ "upload-file" ], "vocabulary" : "format" },
                                "PROVIDE" : { "extension_term" : { "file_extension" : "file_extension" } }
                              }
                            },
                            { "data_set" : { "data" : [ "resource:field-format" ], "value" : [ "file-extension" ] } },
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
                                        "destination_entity" : [ "resource" ],
                                        "destination_field" : "field_upload_structure",
                                        "remove_source" : "0"
                                      }
                                    }
                                  ]
                                },
                                { "ELSE" : [
                                    { "data_set" : {
                                        "data" : [ "resource:field-upload-structure" ],
                                        "value" : [ "created-structure-media" ]
                                      }
                                    }
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
        }
      ]
    }
  }');
  $items['rules_actualize_form_validation'] = entity_import('rules_config', '{ "rules_actualize_form_validation" : {
      "LABEL" : "\\u0412\\u0430\\u043b\\u0438\\u0434\\u0430\\u0446\\u0438\\u044f \\u0444\\u043e\\u0440\\u043c\\u044b \\u0430\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438 \\u041d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "entity_is_validate" : { "label" : "Entity Validates", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_actualization" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 1 } },
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
  $items['rules_add_forum_forum'] = entity_import('rules_config', '{ "rules_add_forum_forum" : {
      "LABEL" : "Add forum forum",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "created_term" : "Created term" } },
            "IF" : [
              { "entity_has_field" : { "entity" : [ "entity" ], "field" : "field_addforum_name" } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "taxonomy_term",
                    "param_name" : [ "entity:field-addforum-name" ],
                    "param_vocabulary" : "forums"
                  },
                  "PROVIDE" : { "entity_created" : { "created_term" : "Created term" } }
                }
              },
              { "entity_save" : { "data" : [ "created-term" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create term"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_add_opendata'] = entity_import('rules_config', '{ "rules_add_opendata" : {
      "LABEL" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
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
        { "component_rules_passport_creation" : {
            "USING" : { "entity" : [ "entity" ] },
            "PROVIDE" : { "new_dataset" : { "new_dataset" : "new_dataset" } }
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_add_title'] = entity_import('rules_config', '{ "rules_add_title" : {
      "LABEL" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u0437\\u0430\\u0433\\u043e\\u043b\\u043e\\u0432\\u043a\\u0430 \\u043a \\u043c\\u0430\\u0442\\u0435\\u0440\\u0438\\u0430\\u043b\\u0443 \\u0411\\u044b\\u0441\\u0442\\u0440\\u044b\\u0435 \\u0444\\u0430\\u043a\\u0442\\u044b",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_presave--quick_fact" : { "bundle" : "quick_fact" } },
      "DO" : [
        { "data_set" : {
            "data" : [ "node:title" ],
            "value" : "\\u0411\\u044b\\u0441\\u0442\\u0440\\u044b\\u0435 \\u0444\\u0430\\u043a\\u0442\\u044b"
          }
        }
      ]
    }
  }');
  $items['rules_app_form_validation'] = entity_import('rules_config', '{ "rules_app_form_validation" : {
      "LABEL" : "\\u041f\\u0440\\u043e\\u0432\\u0435\\u0440\\u043a\\u0430 \\u043f\\u0440\\u0430\\u0432\\u0438\\u043b\\u044c\\u043d\\u043e\\u0441\\u0442\\u0438 \\u0437\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u044f \\u041f\\u0440\\u0438\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u044f",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_validation" ],
      "REQUIRES" : [ "rules", "rules_conditional", "rules_dev_comments" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "node" },
        "entity_is_validate" : { "label" : "Entity Validates", "type" : "boolean" }
      },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "entity" ], "type" : { "value" : { "app" : "app" } } } }
      ],
      "DO" : [
        { "DO" : [] },
        { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 0 } },
        { "CONDITIONAL" : [
            {
              "IF" : { "NOT data_is_empty" : { "data" : [ "entity:field-app-full-name" ] } },
              "DO" : [ { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 1 } } ]
            }
          ]
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "NOT data_is_empty" : { "data" : [ "entity:field-app-url-organization:title" ] } },
              "DO" : [ { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 1 } } ]
            }
          ]
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is_empty" : { "data" : [ "entity:field-app-url-organization:title" ] } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "entity:field-app-full-name" ] } },
                      "DO" : [
                        { "drupal_message" : {
                            "message" : "\\u041d\\u0443\\u0436\\u043d\\u043e \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u043e \\u0437\\u0430\\u043f\\u043e\\u043b\\u043d\\u0438\\u0442\\u044c \\u043f\\u043e\\u043b\\u044f \\u0424\\u0418\\u041e \\u0438\\u043b\\u0438 \\u041e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f",
                            "type" : "error"
                          }
                        }
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
  $items['rules_back_redirect_to_the_resource'] = entity_import('rules_config', '{ "rules_back_redirect_to_the_resource" : {
      "LABEL" : "\\u0420\\u0435\\u0434\\u0438\\u0440\\u0435\\u043a\\u0442 \\u0430\\u0432\\u0442\\u043e\\u0440\\u0430 \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u044f \\u043e\\u0431\\u0440\\u0430\\u0442\\u043d\\u043e \\u043d\\u0430 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_error_report" } }
      ],
      "DO" : [
        { "redirect" : { "url" : [ "entity:field-ef-dataset-resources:url" ] } }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_bind_user_to_copied_node'] = entity_import('rules_config', '{ "rules_bind_user_to_copied_node" : {
      "LABEL" : "Bind user to copied node",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "node" ],
            "type" : "node",
            "bundle" : { "value" : { "publisher_request" : "publisher_request" } }
          }
        }
      ],
      "DO" : []
    }
  }');
  $items['rules_create_app'] = entity_import('rules_config', '{ "rules_create_app" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u043f\\u0440\\u0438\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u044f",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "file_rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [ { "data_is" : { "data" : [ "entity:type" ], "value" : "add_app" } } ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "app",
              "param_title" : [ "entity:field-app-name" ],
              "param_author" : [ "site:current-user" ]
            },
            "PROVIDE" : { "entity_created" : { "new_app" : "new_app" } }
          }
        },
        { "data_set" : {
            "data" : [ "new-app:field-app-mail" ],
            "value" : [ "entity:field-app-mail" ]
          }
        },
        { "data_set" : {
            "data" : [ "new-app:field-app-full-name" ],
            "value" : [ "entity:field-app-full-name" ]
          }
        },
        { "data_set" : {
            "data" : [ "new-app:field-app-phone" ],
            "value" : [ "entity:field-app-phone" ]
          }
        },
        { "data_set" : {
            "data" : [ "new-app:field-app-url-datasets" ],
            "value" : [ "entity:field-app-url-datasets" ]
          }
        },
        { "file_rules_copy_file" : {
            "source_entity" : [ "entity" ],
            "source_field" : "field_app_image",
            "destination_entity" : [ "new-app" ],
            "destination_field" : "field_app_image",
            "remove_source" : "1"
          }
        },
        { "data_set" : {
            "data" : [ "new-app:field-app-url-apple-store" ],
            "value" : [ "entity:field-app-url-apple-store" ]
          }
        },
        { "data_set" : {
            "data" : [ "new-app:field-app-url-google-play" ],
            "value" : [ "entity:field-app-url-google-play" ]
          }
        },
        { "data_set" : {
            "data" : [ "new-app:field-app-url-windows-phone" ],
            "value" : [ "entity:field-app-url-windows-phone" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_create_dataset'] = entity_import('rules_config', '{ "rules_create_dataset" : {
      "LABEL" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "od_preprocess_wizard" } }
      ],
      "DO" : [
        { "component_rules_passport_creation" : {
            "USING" : { "entity" : [ "entity" ] },
            "PROVIDE" : { "new_dataset" : { "new_dataset" : "new_dataset" } }
          }
        },
        { "component_rules_create_resources" : {
            "enitityform_submission" : [ "entity" ],
            "new_dataset" : [ "new_dataset" ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_create_file_and_download'] = entity_import('rules_config', '{ "rules_create_file_and_download" : {
      "LABEL" : "\\u041a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u044f \\u0444\\u0430\\u0439\\u043b\\u0430 \\u0432 \\u043c\\u0430\\u0448\\u0438\\u043d\\u043e\\u0447\\u0438\\u0442\\u0430\\u0435\\u043c\\u044b\\u0439 \\u0444\\u043e\\u0440\\u043c\\u0430\\u0442",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "od_file_process", "rules_conditional", "php" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : {
              "variable_added" : { "message" : "Message with a download link" },
              "created_file" : { "created_file" : "Created file" }
            },
            "IF" : [
              { "entity_has_field" : { "entity" : [ "entity" ], "field" : "field_od_wizard_upload_file" } }
            ],
            "DO" : [
              { "variable_add" : {
                  "USING" : { "type" : "text" },
                  "PROVIDE" : { "variable_added" : { "message" : "Message with a download link" } }
                }
              },
              { "od_file_process_rule_callback_get_file" : {
                  "USING" : {
                    "file_2process" : [ "entity:field-od-wizard-upload-file" ],
                    "can_expire" : 1
                  },
                  "PROVIDE" : { "created_file" : { "created_file" : "Created file" } }
                }
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "NOT data_is_empty" : { "data" : [ "created-file" ] } },
                    "DO" : [
                      { "data_set" : {
                          "data" : [ "message" ],
                          "value" : "\\u003C?php\\r\\n  $entity_wrapper = entity_metadata_wrapper(\\u0027entityform\\u0027, $entity);\\r\\n  print t(\\u0027Link for downloading the file:\\u0027). \\u0027 \\u0027;\\r\\n  $options = array(\\u0027query\\u0027 =\\u003E array( \\u0027encoding\\u0027 =\\u003E $entity_wrapper-\\u003Efield_fcs_output_encoding-\\u003Eraw()));\\r\\n  $url = \\u0027dataset-actions\\/download_file\\/\\u0027. $created_file-\\u003Efid;\\r\\n  print l(url($url, $options + array(\\u0027absolute\\u0027 =\\u003E TRUE)), $url, $options) . \\u0027\\u003Cbr \\/\\u003E\\u0027;\\r\\n  print t(\\u0027Note: This url is accessible withing 6 hours. After 6 hours this link will be invalid.\\u0027);\\r\\n?\\u003E"
                        }
                      }
                    ]
                  },
                  { "ELSE" : [
                      { "data_set" : {
                          "data" : [ "message" ],
                          "value" : "\\u003C?php print t(\\u0027This file can\\\\\\u0027t be converted to machine format because converting is not supported or your file contain errors.\\u0027); ?\\u003E"
                        }
                      }
                    ]
                  }
                ]
              },
              { "php_eval" : { "code" : "drupal_set_message($message);" } }
            ],
            "LABEL" : "\\u041a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u044f \\u0444\\u0430\\u0439\\u043b\\u0430"
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
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
                    "field_pubreg_post" : "field_pubreg_post",
                    "field_pubreq_phone" : "field_pubreq_phone",
                    "field_pubreq_selected_org" : "field_pubreq_selected_org",
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
  $items['rules_create_resource_ulpload'] = entity_import('rules_config', '{ "rules_create_resource_ulpload" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u0442\\u044c \\u0444\\u0430\\u0439\\u043b (\\u0441 \\u043a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u0435\\u0439)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [
        "rules",
        "od_file_process",
        "entityform_to_node",
        "rules_conditional",
        "file_rules",
        "od_common",
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
        { "data_is" : { "data" : [ "new-dataset:type" ], "value" : "dataset" } },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-convert" ],
            "value" : 1
          }
        }
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
              "created_structure_media" : { "created_structure_media" : "Created structure file (field_item_file)" },
              "structure_meta" : { "structure_meta" : "Structure record as universal_data_storage entity" }
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
                      { "data_set" : { "data" : [ "node-created:field-upload" ], "value" : [ "upload-file" ] } },
                      { "od_common_file_get_extension_term" : {
                          "USING" : { "file" : [ "upload-file" ], "vocabulary" : "format" },
                          "PROVIDE" : { "extension_term" : { "file_extension" : "file_extension" } }
                        }
                      },
                      { "data_set" : {
                          "data" : [ "node-created:field-format" ],
                          "value" : [ "file-extension" ]
                        }
                      },
                      { "od_copy_recline_visualization_data" : {
                          "data" : [ "enitityform-submission:field-recline-file-view" ],
                          "entity" : [ "node-created" ],
                          "entity_type" : "node",
                          "field_name" : "field_upload"
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
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "php_eval" : { "code" : "return count($upload_files_list) \\u003E 1;" } },
              "DO" : [
                { "data_set" : { "data" : [ "new-dataset:field-multivolume" ], "value" : 1 } }
              ]
            }
          ]
        },
        { "data_set" : { "data" : [ "structure-meta:bind-to" ], "value" : [ "new-dataset:nid" ] } },
        { "entity_save" : { "data" : [ "structure-meta" ], "immediate" : 1 } }
      ]
    }
  }');
  $items['rules_create_resources'] = entity_import('rules_config', '{ "rules_create_resources" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
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
        { "component_rules_creation_resources_api" : {
            "enitityform_submission" : [ "enitityform_submission" ],
            "new_dataset" : [ "new_dataset" ]
          }
        },
        { "component_rules_create_resource_ulpload" : {
            "enitityform_submission" : [ "enitityform_submission" ],
            "new_dataset" : [ "new_dataset" ]
          }
        },
        { "component_rules_creating_resource_no_convert" : {
            "enitityform_submission" : [ "enitityform_submission" ],
            "new_dataset" : [ "new_dataset" ]
          }
        }
      ]
    }
  }');
  $items['rules_creating_resource_no_convert'] = entity_import('rules_config', '{ "rules_creating_resource_no_convert" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u0442\\u044c \\u0444\\u0430\\u0439\\u043b (\\u0431\\u0435\\u0437 \\u043a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u0438)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [
        "rules",
        "od_file_process",
        "entityform_to_node",
        "rules_conditional",
        "file_rules",
        "od_common",
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
        { "data_is" : { "data" : [ "new-dataset:type" ], "value" : "dataset" } },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-convert" ],
            "value" : 0
          }
        }
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
              "created_structure_media" : { "created_structure_media" : "Created structure file (field_item_file)" },
              "structure_meta" : { "structure_meta" : "Structure record as universal_data_storage entity" }
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
                      { "data_set" : { "data" : [ "node-created:field-upload" ], "value" : [ "upload-file" ] } },
                      { "od_common_file_get_extension_term" : {
                          "USING" : { "file" : [ "upload-file" ], "vocabulary" : "format" },
                          "PROVIDE" : { "extension_term" : { "file_extension" : "file_extension" } }
                        }
                      },
                      { "data_set" : {
                          "data" : [ "node-created:field-format" ],
                          "value" : [ "file-extension" ]
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
  $items['rules_creation_resources_api'] = entity_import('rules_config', '{ "rules_creation_resources_api" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0444\\u0430\\u0439\\u043b\\/API",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entityform_to_node", "rules_conditional", "od_common" ],
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
                },
                { "od_common_file_get_extension_term" : {
                    "USING" : {
                      "file" : [ "node-created:field-link-remote-file:file" ],
                      "vocabulary" : "format"
                    },
                    "PROVIDE" : { "extension_term" : { "extension_term" : "Formated date string" } }
                  }
                },
                { "data_set" : {
                    "data" : [ "node-created:field-format" ],
                    "value" : [ "extension-term" ]
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
  $items['rules_dataset_is_recommended'] = entity_import('rules_config', '{ "rules_dataset_is_recommended" : {
      "LABEL" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u0438\\u0442\\u044c \\u041d\\u0430\\u0431\\u043e\\u0440 \\u0432 \\u0431\\u043b\\u043e\\u043a \\u0022\\u0420\\u0435\\u043a\\u043e\\u043c\\u0435\\u043d\\u0434\\u0443\\u0435\\u043c\\u044b\\u0435\\u0022",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "dataset" : { "label" : "dataset", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "dataset" ],
            "type" : { "value" : { "dataset" : "dataset" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "dataset:field-dataset-standard" ], "value" : 1 } }
      ]
    }
  }');
  $items['rules_dataset_isnt_recommended'] = entity_import('rules_config', '{ "rules_dataset_isnt_recommended" : {
      "LABEL" : "\\u0423\\u0434\\u0430\\u043b\\u0438\\u0442\\u044c \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0438\\u0437 \\u0431\\u043b\\u043e\\u043a\\u0430 \\u0022\\u0420\\u0435\\u043a\\u043e\\u043c\\u0435\\u043d\\u0434\\u0443\\u0435\\u043c\\u044b\\u0435\\u0022",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "dataset" : { "label" : "dataset", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "dataset" ],
            "type" : { "value" : { "dataset" : "dataset" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "dataset:field-dataset-standard" ], "value" : 0 } }
      ]
    }
  }');
  $items['rules_dataset_send_notifications'] = entity_import('rules_config', '{ "rules_dataset_send_notifications" : {
      "LABEL" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043a\\u0430 \\u0443\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0439 \\u0432\\u0441\\u0435\\u043c \\u043f\\u043e\\u0434\\u043f\\u0438\\u0441\\u0447\\u0438\\u043a\\u0430\\u043c \\u043d\\u0430 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "flag", "od_common", "privatemsg_rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "entity" ], "field" : "field_body" } },
        { "entity_has_field" : { "entity" : [ "entity" ], "field" : "field_date_update" } },
        { "entity_has_field" : { "entity" : [ "entity" ], "field" : "field_dataset" } }
      ],
      "DO" : [
        { "flag_fetch_users_node" : {
            "USING" : { "flag" : "subscribe_dataset", "node" : [ "entity:field-dataset" ] },
            "PROVIDE" : { "users" : { "dataset_subscribers" : "dataset_subscribers" } }
          }
        },
        { "od_common_format_date" : {
            "USING" : {
              "timestamp" : [ "entity:field-date-update" ],
              "format" : "date_format_mail_date"
            },
            "PROVIDE" : { "date_formated" : { "date_formated" : "Formated date string" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "uri", "value" : [ "entity:field-dataset:url" ] },
            "PROVIDE" : { "variable_added" : { "dataset_url" : "Dataset_url" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "dataset-subscribers" ] },
            "ITEM" : { "subscriber" : "subscriber" },
            "DO" : [
              { "privatemsg_rules_new" : {
                  "USING" : {
                    "recipient" : [ "subscriber" ],
                    "author" : [ "entity:user" ],
                    "subject" : "\\u0423\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0431 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u0438 \\u0432 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
                    "body" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [subscriber:name].\\r\\n\\r\\n\\u0412 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u003Ca href=\\u0022[dataset-url:value]\\u0022\\u003E \\u0022[entity:field-dataset]\\u0022 \\u003C\\/a\\u003E \\u0431\\u0443\\u0434\\u0443\\u0442 \\u0432\\u043d\\u0435\\u0441\\u0435\\u043d\\u044b \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0435 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u044f: \\r\\n[entity:field_body]\\r\\n\\r\\n\\u041f\\u043b\\u0430\\u043d\\u0438\\u0440\\u0443\\u0435\\u043c\\u043e\\u0435 \\u0432\\u0440\\u0435\\u043c\\u044f \\u0432\\u043d\\u0435\\u0441\\u0435\\u043d\\u0438\\u044f \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u0439: [date-formated:value]"
                  },
                  "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
                }
              },
              { "mail" : {
                  "to" : [ "subscriber:mail" ],
                  "subject" : "\\u0423\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0431 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u0438 \\u0432 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
                  "message" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [subscriber:name].\\r\\n\\r\\n\\u0412 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u003Ca href=\\u0022[dataset-url:value]\\u0022\\u003E \\u0022[entity:field-dataset]\\u0022 \\u003C\\/a\\u003E \\u0431\\u0443\\u0434\\u0443\\u0442 \\u0432\\u043d\\u0435\\u0441\\u0435\\u043d\\u044b \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0435 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u044f: \\r\\n[entity:field_body]\\r\\n\\r\\n\\u041f\\u043b\\u0430\\u043d\\u0438\\u0440\\u0443\\u0435\\u043c\\u043e\\u0435 \\u0432\\u0440\\u0435\\u043c\\u044f \\u0432\\u043d\\u0435\\u0441\\u0435\\u043d\\u0438\\u044f \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u0439: [date-formated:value]\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435\\u043c. \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_delete_datasets_and_its_resources'] = entity_import('rules_config', '{ "rules_delete_datasets_and_its_resources" : {
      "LABEL" : "\\u0423\\u0434\\u0430\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0438 \\u0441\\u0432\\u044f\\u0437\\u0430\\u043d\\u043d\\u044b\\u0445 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_delete--dataset" : { "bundle" : "dataset" } },
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-resources" ] },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "entity_delete" : { "data" : [ "resource" ] } },
              { "drupal_message" : { "message" : "\\u0420\\u0435\\u0441\\u0443\\u0440\\u0441 [resource:title] \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u0443\\u0434\\u0430\\u043b\\u0435\\u043d." } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_delete_user_publisher'] = entity_import('rules_config', '{ "rules_delete_user_publisher" : {
      "LABEL" : "\\u0423\\u0434\\u0430\\u043b\\u0435\\u043d\\u0438\\u0435 \\u0440\\u043e\\u043b\\u0438 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0430 (\\u041c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u044f)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_unflagged_make_publisher" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "flagging" ], "field" : "field_organization" } },
        { "entity_has_field" : {
            "entity" : [ "flagging:field-organization" ],
            "field" : "field_organization_curators"
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "\\u0420\\u043e\\u043b\\u044c \\u041f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0430  \\u0443\\u0434\\u0430\\u043b\\u0435\\u043d\\u0430" } },
        { "list_remove" : {
            "list" : [ "flagging:field-organization:field-organization-curators" ],
            "item" : [ "flagged-user" ]
          }
        },
        { "user_remove_role" : { "account" : [ "flagged-user" ], "roles" : { "value" : { "6" : "6" } } } }
      ]
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
  $items['rules_entityform_submission'] = entity_import('rules_config', '{ "rules_entityform_submission" : {
      "LABEL" : "\\u0423\\u0434\\u0430\\u043b\\u0435\\u043d\\u0438\\u0435 entityform submission",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "entityform_submission" : { "label" : "entityform_submission", "type" : "entityform" } },
      "IF" : [
        { "data_is" : {
            "data" : [ "entityform-submission:type" ],
            "op" : "IN",
            "value" : { "value" : {
                "opendata_query" : "opendata_query",
                "dataset_error_report" : "dataset_error_report"
              }
            }
          }
        }
      ],
      "DO" : [ { "entity_delete" : { "data" : [ "entityform-submission" ] } } ]
    }
  }');
  $items['rules_feedback_notification'] = entity_import('rules_config', '{ "rules_feedback_notification" : {
      "LABEL" : "\\u0423\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0442\\u043e\\u0440\\u0430 \\u043e \\u043d\\u043e\\u0432\\u043e\\u043c \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0438 \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u043d\\u044b\\u043c \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0444\\u043e\\u0440\\u043c\\u0443 \\u043e\\u0431\\u0440\\u0430\\u0442\\u043d\\u043e\\u0439 \\u0441\\u0432\\u044f\\u0437\\u0438",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "privatemsg_rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "DO" : [
        { "mail" : {
            "to" : "support@opendatagov.ru",
            "subject" : "\\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445. \\u041f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d\\u043e \\u043d\\u043e\\u0432\\u043e\\u0435 \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0444\\u043e\\u0440\\u043c\\u0443 \\u043e\\u0431\\u0440\\u0430\\u0442\\u043d\\u043e\\u0439 \\u0441\\u0432\\u044f\\u0437\\u0438. ",
            "message" : "\\u041f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d\\u043e \\u043d\\u043e\\u0432\\u043e\\u0435 \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0444\\u043e\\u0440\\u043c\\u0443 \\u043e\\u0431\\u0440\\u0430\\u0442\\u043d\\u043e\\u0439 \\u0441\\u0432\\u044f\\u0437\\u0438.\\r\\n\\r\\n\\u041f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043c\\u043e\\u0436\\u043d\\u043e \\u043f\\u043e \\u0441\\u0441\\u044b\\u043b\\u043a\\u0435: \\u003Ca href=\\u0022[entity:url]\\u0022\\u003E[entity:url]\\u003C\\/a\\u003E\\r\\n\\r\\n\\r\\n\\r\\n\\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
            "language" : [ "entity:type" ]
          }
        },
        { "privatemsg_rules_new_role" : {
            "USING" : {
              "roles" : { "value" : { "4" : "4" } },
              "author" : "1",
              "subject" : "\\u041d\\u043e\\u0432\\u043e\\u0435 \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0444\\u043e\\u0440\\u043c\\u0443 \\u043e\\u0431\\u0440\\u0430\\u0442\\u043d\\u043e\\u0439 \\u0441\\u0432\\u044f\\u0437\\u0438.",
              "body" : "\\u041f\\u043e\\u043b\\u0443\\u0447\\u0435\\u043d\\u043e \\u043d\\u043e\\u0432\\u043e\\u0435 \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0444\\u043e\\u0440\\u043c\\u0443 \\u043e\\u0431\\u0440\\u0430\\u0442\\u043d\\u043e\\u0439 \\u0441\\u0432\\u044f\\u0437\\u0438.\\r\\n\\r\\n\\u041f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043c\\u043e\\u0436\\u043d\\u043e \\u043f\\u043e \\u0441\\u0441\\u044b\\u043b\\u043a\\u0435: \\u003Ca href=\\u0022[entity:url]\\u0022\\u003E[entity:url]\\u003C\\/a\\u003E"
            },
            "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
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
  $items['rules_idea_creation'] = entity_import('rules_config', '{ "rules_idea_creation" : {
      "LABEL" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0435 \\u0438\\u0434\\u0435\\u0438",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "workflow_rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [ { "data_is" : { "data" : [ "entity:type" ], "value" : "add_idea" } } ],
      "DO" : [
        { "entity_create" : {
            "USING" : {
              "type" : "node",
              "param_type" : "idea",
              "param_title" : [ "entity:field-title" ],
              "param_author" : [ "entity:user" ]
            },
            "PROVIDE" : { "entity_created" : { "new_idea" : "new_idea" } }
          }
        },
        { "data_set" : { "data" : [ "new-idea:body:value" ], "value" : [ "entity:field-body" ] } },
        { "entity_save" : { "data" : [ "new-idea" ], "immediate" : 1 } },
        { "data_set" : {
            "data" : [ "new-idea:field-rubric" ],
            "value" : [ "entity:field-rubric" ]
          }
        },
        { "workflow_rules_set_state" : {
            "node" : [ "new-idea" ],
            "workflow_state" : { "value" : { "2" : "2" } }
          }
        }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_make_user_publisher'] = entity_import('rules_config', '{ "rules_make_user_publisher" : {
      "LABEL" : "\\u0414\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 \\u0440\\u043e\\u043b\\u0438 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0430 (\\u041c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u044f)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_make_publisher" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "flagging" ], "field" : "field_organization" } },
        { "entity_has_field" : {
            "entity" : [ "flagging:field-organization" ],
            "field" : "field_organization_curators"
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "\\u0420\\u043e\\u043b\\u044c \\u041f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0430  \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0430" } },
        { "list_add" : {
            "list" : [ "flagging:field-organization:field-organization-curators" ],
            "item" : [ "flagged-user" ],
            "unique" : 1
          }
        },
        { "user_add_role" : { "account" : [ "flagged-user" ], "roles" : { "value" : { "6" : "6" } } } }
      ]
    }
  }');
  $items['rules_message_after_creater_dataset'] = entity_import('rules_config', '{ "rules_message_after_creater_dataset" : {
      "LABEL" : "\\u0421\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044e \\u0441\\u043e\\u0437\\u0434\\u0430\\u0432\\u0448\\u0435\\u043c\\u0443 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "privatemsg_rules", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "IF" : [
        { "data_is" : { "data" : [ "entityform:type" ], "value" : "od_preprocess_wizard" } }
      ],
      "DO" : [
        { "privatemsg_rules_new_role" : {
            "USING" : {
              "roles" : { "value" : { "4" : "4" } },
              "author" : [ "entityform:user" ],
              "subject" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0022[entityform:field-dataset-title]\\u0022 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
              "body" : "\\u0421\\u043e\\u0437\\u0434\\u0430\\u043d \\u043d\\u043e\\u0432\\u044b\\u0439 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - [entityform:field-dataset-title].\\r\\n\\u0410\\u0432\\u0442\\u043e\\u0440 - [entityform:user]."
            },
            "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
          }
        },
        { "privatemsg_rules_new" : {
            "USING" : {
              "recipient" : [ "entityform:user" ],
              "author" : [ "entityform:user" ],
              "subject" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - \\u0022[entityform:field-dataset-title]\\u0022 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u0441\\u043e\\u0437\\u0434\\u0430\\u043d.",
              "body" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 - \\u0022[entityform:field-dataset-title]\\u0022 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u0441\\u043e\\u0437\\u0434\\u0430\\u043d.\\r\\n\\u041f\\u0435\\u0440\\u0435\\u0434 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d\\u0438\\u0435\\u043c \\u043d\\u0430 \\u043f\\u043e\\u0440\\u0442\\u0430\\u043b\\u0435 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0431\\u0443\\u0434\\u0435\\u0442 \\u043f\\u0440\\u043e\\u0432\\u0435\\u0440\\u0435\\u043d \\u0441\\u043b\\u0443\\u0436\\u0431\\u043e\\u0439 \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u0438."
            },
            "PROVIDE" : { "thread_id" : { "thread_id_author" : "ID of new thread author" } }
          }
        },
        { "drupal_message" : { "message" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u044b \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u044f \\u043e \\u0441\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u0438 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430. \\u041f\\u0440\\u043e\\u0432\\u0435\\u0440\\u044c\\u0442\\u0435 \\u0432 \\u043b\\u0438\\u0447\\u043d\\u044b\\u0445 \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u044f\\u0445 \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435." } }
      ]
    }
  }');
  $items['rules_new_comment_to_dataset'] = entity_import('rules_config', '{ "rules_new_comment_to_dataset" : {
      "LABEL" : "\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442 \\u043d\\u0430 \\u043d\\u0430\\u0431\\u043e\\u0440 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "privatemsg_rules", "comment" ],
      "ON" : { "comment_insert--comment_node_dataset" : { "bundle" : "comment_node_dataset" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "comment:node" ],
            "type" : { "value" : { "dataset" : "dataset" } }
          }
        }
      ],
      "DO" : [
        { "CONDITIONAL" : [
            {
              "IF" : { "NOT data_is" : { "data" : [ "comment:node:author" ], "value" : "1" } },
              "DO" : [
                { "privatemsg_rules_new" : {
                    "USING" : {
                      "recipient" : [ "comment:node:author" ],
                      "author" : [ "comment:author" ],
                      "subject" : "\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439 \\u043a \\u043d\\u0430\\u0431\\u043e\\u0440\\u0443 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
                      "body" : [ "comment:comment-body:value" ]
                    },
                    "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
                  }
                },
                { "drupal_message" : { "message" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u043e \\u0441\\u043e\\u043e\\u0431\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043e \\u043d\\u043e\\u0432\\u043e\\u043c \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0438." } }
              ]
            },
            { "ELSE" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "entity_has_field" : { "entity" : [ "comment:node" ], "field" : "field_email_responsible" } },
                      "DO" : [
                        { "mail" : {
                            "to" : [ "comment:node:field-email-responsible" ],
                            "subject" : "\\u041d\\u043e\\u0432\\u044b\\u0439 \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0439 \\u043a \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u043c \\u0434\\u0430\\u043d\\u043d\\u044b\\u043c.",
                            "message" : [ "comment:comment-body:value" ],
                            "language" : [ "" ]
                          }
                        },
                        { "drupal_message" : { "message" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u043e \\u043f\\u0438\\u0441\\u044c\\u043c\\u043e \\u043e \\u043d\\u043e\\u0432\\u043e\\u043c \\u043a\\u043e\\u043c\\u043c\\u0435\\u043d\\u0442\\u0430\\u0440\\u0438\\u0438." } }
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
  }');
  $items['rules_next_resource_redirect'] = entity_import('rules_config', '{ "rules_next_resource_redirect" : {
      "LABEL" : "\\u041f\\u0435\\u0440\\u0435\\u0439\\u0442\\u0438 \\u043a \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0435\\u043c\\u0443 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u0443",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "rb_misc" ],
      "ON" : { "rb_misc_trigger_page_next_resource_panel_context" : [] },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "relationship-entity-from-field--field-dataset-ref-node-node-1" ],
            "field" : "field_resources"
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "boolean", "value" : 0 },
            "PROVIDE" : { "variable_added" : { "redirect_is_ready" : "Ready to redirect" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "boolean", "value" : 0 },
            "PROVIDE" : { "variable_added" : { "redirect_is_complete" : "Redirect is complete" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [
                "relationship-entity-from-field--field-dataset-ref-node-node-1:field-resources"
              ]
            },
            "ITEM" : { "recource" : "resource" },
            "DO" : [
              { "CONDITIONAL" : [
                  {
                    "IF" : { "data_is" : { "data" : [ "redirect-is-ready" ], "value" : 1 } },
                    "DO" : [
                      { "data_set" : { "data" : [ "redirect-is-complete" ], "value" : 1 } },
                      { "data_set" : { "data" : [ "redirect-is-ready" ], "value" : 0 } },
                      { "redirect" : { "url" : [ "recource:url" ] } }
                    ]
                  }
                ]
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "data_is" : {
                        "data" : [ "recource:nid" ],
                        "value" : [ "argument-entity-id--node-1:nid" ]
                      }
                    },
                    "DO" : [ { "data_set" : { "data" : [ "redirect-is-ready" ], "value" : 1 } } ]
                  }
                ]
              }
            ]
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "redirect-is-complete" ], "value" : 0 } },
              "DO" : [
                { "redirect" : { "url" : [ "argument-entity-id--node-1:url" ] } },
                { "drupal_message" : {
                    "message" : "\\u0421\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439 \\u0442\\u043e\\u043c \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043e\\u0442\\u0441\\u0443\\u0442\\u0441\\u0442\\u0432\\u0443\\u0435\\u0442. \\u0412\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u0432\\u0435\\u0440\\u043d\\u0443\\u0442\\u044c\\u0441\\u044f \\u043a \\u043f\\u0440\\u0435\\u0434\\u044b\\u0434\\u0443\\u0449\\u0435\\u043c\\u0443 \\u0442\\u043e\\u043c\\u0443.",
                    "type" : "warning"
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_notify_organization_curators'] = entity_import('rules_config', '{ "rules_notify_organization_curators" : {
      "LABEL" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043a\\u0430 \\u0443\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u044f \\u041a\\u0443\\u0440\\u0430\\u0442\\u043e\\u0440\\u0430\\u043c \\u043e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438 \\u043e \\u043d\\u043e\\u0432\\u043e\\u043c \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0435 \\u043d\\u0430 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0435 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0435 (\\u041c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u044f)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "submission" : { "label" : "submission", "type" : "entityform" } },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "submission" ],
            "field" : "field_od_query_data_organization"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "submission:field-od-query-data-organization" ],
            "field" : "field_organization_curators"
          }
        }
      ],
      "DO" : [
        { "CONDITIONAL" : [
            {
              "IF" : { "NOT data_is_empty" : { "data" : [
                    "submission:field-od-query-data-organization:field-organization-curators"
                  ]
                }
              },
              "DO" : [
                { "LOOP" : {
                    "USING" : { "list" : [
                        "submission:field-od-query-data-organization:field-organization-curators"
                      ]
                    },
                    "ITEM" : { "curator" : "curator" },
                    "DO" : [
                      { "mail" : {
                          "to" : [ "curator:mail" ],
                          "subject" : "\\u041f\\u043e\\u0441\\u0442\\u0443\\u043f\\u043b\\u0435\\u043d\\u0438\\u0435 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 \\u043d\\u0430 \\u0438\\u043d\\u0444\\u043e\\u0440\\u043c\\u0430\\u0446\\u0438\\u0438 \\u0432 \\u0432\\u0438\\u0434\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
                          "message" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [curator:name]!\\r\\n\\r\\n\\u0412\\u0430\\u043c \\u043f\\u043e\\u0441\\u0442\\u0443\\u043f\\u0438\\u043b \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
                          "from" : [ "" ],
                          "language" : [ "" ]
                        }
                      }
                    ]
                  }
                }
              ]
            },
            { "ELSE" : [
                { "mail" : {
                    "to" : "support@opendatagov.ru",
                    "subject" : "\\u041f\\u043e\\u0441\\u0442\\u0443\\u043f\\u043b\\u0435\\u043d\\u0438\\u0435 \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441\\u0430 \\u043d\\u0430 \\u0438\\u043d\\u0444\\u043e\\u0440\\u043c\\u0430\\u0446\\u0438\\u0438 \\u0432 \\u0432\\u0438\\u0434\\u0435 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
                    "message" : "\\u0412\\u0430\\u043c \\u043f\\u043e\\u0441\\u0442\\u0443\\u043f\\u0438\\u043b \\u0437\\u0430\\u043f\\u0440\\u043e\\u0441 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438 \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
                    "language" : [ "" ]
                  }
                }
              ]
            }
          ]
        },
        { "flag_flagentityform" : {
            "flag" : "for_request",
            "entityform" : [ "submission" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_notify_organization_curators_about_new_reports'] = entity_import('rules_config', '{ "rules_notify_organization_curators_about_new_reports" : {
      "LABEL" : "\\u041e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043a\\u0430 \\u0443\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u044f \\u041a\\u0443\\u0440\\u0430\\u0442\\u043e\\u0440\\u0430\\u043c \\u043e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u0438 \\u043e \\u043d\\u043e\\u0432\\u043e\\u043c \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u0438",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "rules_dev_comments", "privatemsg_rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "entityform_submission" : { "label" : "entityform_submission", "type" : "entityform" } },
      "IF" : [
        { "data_is" : {
            "data" : [ "entityform-submission:type" ],
            "value" : "dataset_error_report"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "entityform-submission:field-ef-dataset-resources" ],
            "field" : "field_dataset_ref"
          }
        },
        { "entity_has_field" : {
            "entity" : [ "entityform-submission:field-ef-dataset-resources:field-dataset-ref" ],
            "field" : "field_organization"
          }
        },
        { "entity_has_field" : {
            "entity" : [
              "entityform-submission:field-ef-dataset-resources:field-dataset-ref:field-organization"
            ],
            "field" : "field_organization_curators"
          }
        }
      ],
      "DO" : [
        { "DO" : [] },
        { "variable_add" : {
            "USING" : {
              "type" : "node",
              "value" : [ "entityform-submission:field-ef-dataset-resources:field-dataset-ref" ]
            },
            "PROVIDE" : { "variable_added" : { "dataset" : "dataset" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [
                "entityform-submission:field-ef-dataset-resources:field-dataset-ref:field-organization:field-organization-curators"
              ]
            },
            "ITEM" : { "publisher" : "Publisher" },
            "DO" : [
              { "drupal_message" : { "message" : "\\u0423\\u0432\\u0435\\u0434\\u043e\\u043c\\u043b\\u0435\\u043d\\u0438\\u0435 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0442\\u043f\\u0440\\u0430\\u0432\\u043b\\u0435\\u043d\\u043e." } },
              { "mail" : {
                  "to" : [ "publisher:mail" ],
                  "subject" : "\\u041f\\u043e\\u0441\\u0442\\u0443\\u043f\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u044f \\u043f\\u043e \\u043e\\u0448\\u0438\\u0431\\u043a\\u0435 \\u0432 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0435.",
                  "message" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [publisher:name]!\\r\\n\\r\\n\\u0412\\u0430\\u043c \\u043f\\u043e\\u0441\\u0442\\u0443\\u043f\\u0438\\u043b\\u043e \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e \\u043e\\u0448\\u0438\\u0431\\u043a\\u0435 \\u0432 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0435 \\u0022[dataset:title]\\u0022 \\u0434\\u043e\\u0441\\u0442\\u0443\\u043f\\u043d\\u043e\\u0433\\u043e \\u043f\\u043e \\u0441\\u0441\\u044b\\u043b\\u043a\\u0435: \\u003Ca href=\\u0022[dataset:url]\\u0022\\u003E[dataset:url]\\u003C\\/a\\u003E\\r\\n\\r\\n\\u0414\\u0435\\u0442\\u0430\\u043b\\u0438 \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u044f: \\r\\n\\r\\n\\u041d\\u043e\\u043c\\u0435\\u0440 \\u0441\\u0442\\u0440\\u043e\\u043a\\u0438: [entityform-submission:field-ds-report-row]\\r\\n\\u041d\\u043e\\u043c\\u0435\\u0440 \\u0441\\u0442\\u043e\\u043b\\u0431\\u0446\\u0430: [entityform-submission:field-ds-report-col]\\r\\n\\u041f\\u0440\\u043e\\u0431\\u043b\\u0435\\u043c\\u0430: [entityform-submission:field-ef-problem]\\r\\nemail: [entityform-submission:field-ef-email]\\r\\n\\u0418\\u043c\\u044f: [entityform-submission:field-ef-name]\\r\\n\\u0424\\u0430\\u043c\\u0438\\u043b\\u0438\\u044f: [entityform-submission:field-ef-last-name]\\r\\n\\u041d\\u043e\\u043c\\u0435\\u0440 \\u0442\\u0435\\u043b\\u0435\\u0444\\u043e\\u043d\\u0430: [entityform-submission:field-phone-number]\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435\\u043c, \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.\\r\\n"
                }
              },
              { "privatemsg_rules_new" : {
                  "USING" : {
                    "recipient" : [ "publisher" ],
                    "author" : "1",
                    "subject" : "\\u041f\\u043e\\u0441\\u0442\\u0443\\u043f\\u043b\\u0435\\u043d\\u0438\\u0435 \\u043d\\u043e\\u0432\\u043e\\u0433\\u043e \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u044f \\u043e\\u0431 \\u043e\\u0448\\u0438\\u0431\\u043a\\u0435",
                    "body" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [publisher:name]!\\r\\n\\r\\n\\u0412\\u0430\\u043c \\u043f\\u043e\\u0441\\u0442\\u0443\\u043f\\u0438\\u043b\\u043e \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u0435 \\u043f\\u043e \\u043e\\u0448\\u0438\\u0431\\u043a\\u0435 \\u0432 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0435 \\u0022[dataset:title]\\u0022 \\u0434\\u043e\\u0441\\u0442\\u0443\\u043f\\u043d\\u043e\\u0433\\u043e \\u043f\\u043e \\u0441\\u0441\\u044b\\u043b\\u043a\\u0435:  \\u003Ca href=\\u0022[dataset:url]\\u0022\\u003E[dataset:url]\\u003C\\/a\\u003E\\r\\n\\r\\n\\u0414\\u0435\\u0442\\u0430\\u043b\\u0438 \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u044f: \\r\\n\\u041d\\u043e\\u043c\\u0435\\u0440 \\u0441\\u0442\\u0440\\u043e\\u043a\\u0438: [entityform-submission:field-ds-report-row]\\r\\n\\u041d\\u043e\\u043c\\u0435\\u0440 \\u0441\\u0442\\u043e\\u043b\\u0431\\u0446\\u0430: [entityform-submission:field-ds-report-col]\\r\\n\\u041f\\u0440\\u043e\\u0431\\u043b\\u0435\\u043c\\u0430: [entityform-submission:field-ef-problem]\\r\\nemail: [entityform-submission:field-ef-email]\\r\\n\\u0418\\u043c\\u044f: [entityform-submission:field-ef-name]\\r\\n\\u0424\\u0430\\u043c\\u0438\\u043b\\u0438\\u044f: [entityform-submission:field-ef-last-name]\\r\\n\\u041d\\u043e\\u043c\\u0435\\u0440 \\u0442\\u0435\\u043b\\u0435\\u0444\\u043e\\u043d\\u0430: [entityform-submission:field-phone-number]\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435\\u043c, \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.\\r\\n"
                  },
                  "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
                }
              }
            ]
          }
        },
        { "data_set" : { "data" : [ "entityform-submission:field-notified" ], "value" : 1 } }
      ]
    }
  }');
  $items['rules_passport_actualization'] = entity_import('rules_config', '{ "rules_passport_actualization" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043f\\u0430\\u0441\\u043f\\u043e\\u0440\\u0442\\u0430 (\\u041e\\u0434\\u043d\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439 \\u043d\\u0430\\u0431\\u043e\\u0440)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
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
  $items['rules_passport_actualization_multivolume'] = entity_import('rules_config', '{ "rules_passport_actualization_multivolume" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u043f\\u0430\\u0441\\u043f\\u043e\\u0440\\u0442\\u0430 (\\u041c\\u043d\\u043e\\u0433\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439 \\u043d\\u0430\\u0431\\u043e\\u0440)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node", "parameter" : false }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_actualization_multivol" } },
        { "node_is_of_type" : {
            "node" : [ "entity:field-ef-dataset" ],
            "type" : { "value" : { "dataset" : "dataset" } }
          }
        }
      ],
      "DO" : [
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
      "REQUIRES" : [ "rules", "entityform_to_node", "rules_conditional" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node", "parameter" : false }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "od_preprocess_wizard" } }
      ],
      "DO" : [
        { "entityform_to_node_copy_create_node" : {
            "USING" : {
              "ef" : [ "entity" ],
              "config" : { "value" : {
                  "entityform_type" : "od_preprocess_wizard",
                  "node_type" : "dataset",
                  "field_mappings" : {
                    "field_dataset_title" : "",
                    "field_dataset_id" : "field_dataset_id",
                    "field_dataset_body" : "field_dataset_body",
                    "field_organization" : "",
                    "field_contact_name" : "field_contact_name",
                    "field_contact_phone" : "field_contact_phone",
                    "field_email_responsible" : "field_email_responsible",
                    "field_date_first_time_publ" : "field_date_first_time_publ",
                    "field_date_last_change" : "field_date_last_change",
                    "field_content_last_change" : "",
                    "field_date_dataset_actual" : "field_date_dataset_actual",
                    "field_rubric" : "field_rubric",
                    "field_tags" : "field_tags",
                    "field_license" : "field_license",
                    "field_dataset_convert" : "",
                    "field_dataset_variant" : "",
                    "field_ef_organization" : "field_organization"
                  }
                }
              },
              "create_fields" : 0,
              "save_node" : 0
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
                    "value" : [ "entity:field-ef-organization:title" ]
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
  $items['rules_previous_redirect_resource'] = entity_import('rules_config', '{ "rules_previous_redirect_resource" : {
      "LABEL" : "\\u041f\\u0435\\u0440\\u0435\\u0439\\u0442\\u0438 \\u043a \\u043f\\u0440\\u0435\\u0434\\u044b\\u0434\\u0443\\u0449\\u0435\\u043c\\u0443 \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u0443",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "rb_misc" ],
      "ON" : { "rb_misc_trigger_page_previous_resource_panel_context" : [] },
      "IF" : [
        { "entity_has_field" : {
            "entity" : [ "relationship-entity-from-field--field-dataset-ref-node-node-1" ],
            "field" : "field_resources"
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "list\\u003Cnode\\u003E" },
            "PROVIDE" : { "variable_added" : { "reverted_resource_list" : "reverted_resource_list" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [
                "relationship-entity-from-field--field-dataset-ref-node-node-1:field-resources"
              ]
            },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "list_add" : {
                  "list" : [ "reverted-resource-list" ],
                  "item" : [ "resource" ],
                  "unique" : 1,
                  "pos" : "start"
                }
              }
            ]
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "boolean", "value" : 0 },
            "PROVIDE" : { "variable_added" : { "redirect_is_ready" : "Ready to redirect" } }
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "boolean", "value" : 0 },
            "PROVIDE" : { "variable_added" : { "redirect_is_complete" : "Redirect is complete" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "reverted-resource-list" ] },
            "ITEM" : { "recource" : "resource" },
            "DO" : [
              { "CONDITIONAL" : [
                  {
                    "IF" : { "data_is" : { "data" : [ "redirect-is-ready" ], "value" : 1 } },
                    "DO" : [
                      { "data_set" : { "data" : [ "redirect-is-complete" ], "value" : 1 } },
                      { "data_set" : { "data" : [ "redirect-is-ready" ], "value" : 0 } },
                      { "redirect" : { "url" : [ "recource:url" ] } }
                    ]
                  }
                ]
              },
              { "CONDITIONAL" : [
                  {
                    "IF" : { "data_is" : {
                        "data" : [ "recource:nid" ],
                        "value" : [ "argument-entity-id--node-1:nid" ]
                      }
                    },
                    "DO" : [ { "data_set" : { "data" : [ "redirect-is-ready" ], "value" : 1 } } ]
                  }
                ]
              }
            ]
          }
        },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "redirect-is-complete" ], "value" : 0 } },
              "DO" : [
                { "redirect" : { "url" : [ "argument-entity-id--node-1:url" ] } },
                { "drupal_message" : {
                    "message" : "\\u041f\\u0440\\u0435\\u0434\\u044b\\u0434\\u0443\\u0449\\u0438\\u0439 \\u0442\\u043e\\u043c \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u043e\\u0442\\u0441\\u0443\\u0442\\u0441\\u0442\\u0432\\u0443\\u0435\\u0442. \\u0412\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u043f\\u0435\\u0440\\u0435\\u0439\\u0442\\u0438 \\u043a \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0435\\u043c\\u0443 \\u0442\\u043e\\u043c\\u0443.",
                    "type" : "warning"
                  }
                }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_pub_request'] = entity_import('rules_config', '{ "rules_pub_request" : {
      "LABEL" : "\\u0411\\u0438\\u0437\\u043d\\u0435\\u0441-\\u043f\\u0440\\u043e\\u0446\\u0435\\u0441\\u0441 - \\u0417\\u0430\\u044f\\u0432\\u043a\\u0430 \\u043d\\u0430 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0442\\u043e\\u0440\\u0441\\u0442\\u0432\\u043e",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "php" ],
      "USES VARIABLES" : {
        "node" : { "label" : "node", "type" : "node" },
        "user" : { "label" : "user", "type" : "user" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "variable_added" : { "var_organization" : "Orgranization" } },
            "IF" : [
              { "node_is_of_type" : {
                  "node" : [ "node" ],
                  "type" : { "value" : { "publisher_request" : "publisher_request" } }
                }
              },
              { "data_is" : { "data" : [ "node:field-pubreq-status" ], "value" : "approved" } }
            ],
            "DO" : [
              { "CONDITIONAL" : [
                  {
                    "IF" : { "data_is" : { "data" : [ "node:field-pubreq-organization-exists" ], "value" : 0 } },
                    "DO" : [
                      { "php_eval" : { "code" : "$wrapper = entity_metadata_wrapper(\\u0027node\\u0027, $node);\\r\\n$org = $wrapper-\\u003Efield_pubreq_created_org-\\u003Evalue();\\r\\n$org-\\u003Etype = \\u0027organization\\u0027;\\r\\nnode_save($org);" } }
                    ]
                  }
                ]
              },
              { "user_add_role" : {
                  "account" : [ "node:field-pubreq-user" ],
                  "roles" : { "value" : { "6" : "6" } }
                }
              },
              { "entity_save" : { "data" : [ "node:field-pubreq-user" ], "immediate" : 1 } },
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
  $items['rules_publish_dataset_and_referenced_resource'] = entity_import('rules_config', '{ "rules_publish_dataset_and_referenced_resource" : {
      "LABEL" : "\\u041f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u044f \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 + \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u0430",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rb_misc" ],
      "ON" : { "node_update--dataset" : { "bundle" : "dataset" } },
      "IF" : [
        { "NOT node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "rb_misc_action_views_load_list" : {
            "USING" : { "view" : "resources|panel_pane_1", "args" : [ "node:nid" ] },
            "PROVIDE" : { "node_list" : { "dataset_resources" : "dataset_resources" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "dataset-resources" ] },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "drupal_message" : { "message" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0022[node:title]\\u0022 \\u0438 \\u0420\\u0435\\u0441\\u0443\\u0440\\u0441 \\u0022[resource:title]\\u0022 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d\\u044b." } },
              { "node_publish" : { "node" : [ "resource" ] } }
            ]
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
        { "component_rules_pub_request" : { "node" : [ "node" ], "user" : [ "node:field-pubreq-user" ] } }
      ]
    }
  }');
  $items['rules_recommended'] = entity_import('rules_config', '{ "rules_recommended" : {
      "LABEL" : "\\u0420\\u0435\\u043a\\u043e\\u043c\\u0435\\u043d\\u0434\\u043e\\u0432\\u0430\\u043d\\u043d\\u044b\\u0439 \\u043d\\u0430\\u0431\\u043e\\u0440 (Field formatter rule)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "ffc" ],
      "ON" : { "field_is_rendered" : [] },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_dataset_standard" } },
        { "data_is" : { "data" : [ "node:field-dataset-standard" ], "value" : 0 } }
      ],
      "DO" : [
        { "ffc_rules_hide_fields" : { "ffc_element" : [ "" ], "ffc_field" : [ "" ] } }
      ]
    }
  }');
  $items['rules_redirects_to_success_page_with_message'] = entity_import('rules_config', '{ "rules_redirects_to_success_page_with_message" : {
      "LABEL" : "Redirects to Success page with message (Nodes)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional" ],
      "ON" : { "node_insert" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "node:type" ],
            "op" : "IN",
            "value" : { "value" : { "idea" : "idea", "competition" : "competition" } }
          }
        }
      ],
      "DO" : [
        { "redirect" : { "url" : "success" } },
        { "CONDITIONAL" : [
            {
              "IF" : { "node_is_of_type" : {
                  "node" : [ "node" ],
                  "type" : { "value" : { "competition" : "competition" } }
                }
              },
              "DO" : [
                { "drupal_message" : { "message" : "\\u041a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u0441\\u043e\\u0437\\u0434\\u0430\\u043d. \\u003Cbr \\/\\u003E\\r\\n\\u0412\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u043f\\u0435\\u0440\\u0435\\u0439\\u0442\\u0438 \\u043d\\u0430 \\u003Ca href=\\u0022\\/\\u0022\\u003E\\u0413\\u043b\\u0430\\u0432\\u043d\\u0443\\u044e\\u003C\\/a\\u003E \\u0438\\u043b\\u0438 \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0443  \\u003Ca href=\\u0022\\/competitions\\u0022\\u003E\\u041a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441\\u043e\\u0432\\u003C\\/a\\u003E" } }
              ]
            },
            {
              "ELSE IF" : { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "idea" : "idea" } } } },
              "DO" : [
                { "drupal_message" : { "message" : "\\u0418\\u0434\\u0435\\u044f \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u0441\\u043e\\u0437\\u0434\\u0430\\u043d\\u0430 \\u0438 \\u043f\\u0435\\u0440\\u0435\\u0434\\u0430\\u043d\\u0430 \\u043d\\u0430 \\u043c\\u043e\\u0434\\u0435\\u0440\\u0430\\u0446\\u0438\\u044e. \\u003Cbr \\/\\u003E\\r\\n\\u0412\\u044b \\u043c\\u043e\\u0436\\u0435\\u0442\\u0435 \\u043f\\u0435\\u0440\\u0435\\u0439\\u0442\\u0438 \\u043d\\u0430 \\u003Ca href=\\u0022\\/\\u0022\\u003E\\u0413\\u043b\\u0430\\u0432\\u043d\\u0443\\u044e\\u003C\\/a\\u003E \\u0438\\u043b\\u0438 \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0443  \\u003Ca href=\\u0022\\/ideas\\u0022\\u003E\\u0418\\u0434\\u0435\\u0439\\u003C\\/a\\u003E" } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_redirects_to_success_page_with_message_entityform'] = entity_import('rules_config', '{ "rules_redirects_to_success_page_with_message_entityform" : {
      "LABEL" : "Redirects to Success page with message (Entityforms)",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rules_conditional", "php", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "IF" : [
        { "data_is" : {
            "data" : [ "entityform:type" ],
            "op" : "IN",
            "value" : { "value" : {
                "opendata_query" : "opendata_query",
                "od_preprocess_wizard" : "od_preprocess_wizard",
                "add_app" : "add_app",
                "request_to_become_a_publisher" : "request_to_become_a_publisher"
              }
            }
          }
        }
      ],
      "DO" : [
        { "redirect" : { "url" : "success" } },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is" : { "data" : [ "entityform:type" ], "value" : "opendata_query" } },
              "DO" : [
                { "php_eval" : { "code" : "print drupal_set_message(t(\\u0027Your application for the provision of data received. \\u003Cbr \\/\\u003E You can go to \\u003Ca href=\\u0022\\/\\u0022\\u003Ehomepage\\u003C\\/a\\u003E\\u0027), \\u0027status\\u0027);" } }
              ]
            },
            {
              "ELSE IF" : { "data_is" : {
                  "data" : [ "entityform:type" ],
                  "value" : "request_to_become_a_publisher"
                }
              },
              "DO" : [
                { "php_eval" : { "code" : "print drupal_set_message(t(\\u0027Your application has been successfully sent to moderation. Once it is processed, you will receive a notification to the email address specified in your personal information. \\u003Cbr \\/\\u003E You can go to \\u003Ca href=\\u0022\\/\\u0022\\u003Ehomepage\\u003C\\/a\\u003E\\u0027), \\u0027status\\u0027);" } }
              ]
            },
            {
              "ELSE IF" : { "data_is" : { "data" : [ "entityform:type" ], "value" : "add_app" } },
              "DO" : [
                { "php_eval" : { "code" : "print drupal_set_message(t(\\u0027Your application has been successfully added. \\u003Cbr \\/\\u003E You can go to the \\u003Ca href=\\u0022\\/apps\\u0022\\u003Eapplications page\\u003C\\/a\\u003E or to the \\u003Ca href=\\u0022\\/\\u0022\\u003Ehomepage\\u003C\\/a\\u003E\\u0027), \\u0027status\\u0027);" } }
              ]
            },
            {
              "ELSE IF" : { "data_is" : { "data" : [ "entityform:type" ], "value" : "od_preprocess_wizard" } },
              "DO" : [
                { "php_eval" : { "code" : "print drupal_set_message(t(\\u0027Dataset has been successfully added. \\u003Cbr \\/\\u003E You can go to the \\u003Ca href=\\u0022@homepage\\u0022\\u003Ehomepage\\u003C\\/a\\u003E\\u0027, array(\\u0027@homepage\\u0027 =\\u003E url(\\u0027\\u0027))), \\u0027status\\u0027);" } }
              ]
            }
          ]
        }
      ]
    }
  }');
  $items['rules_redirects_user_from_user_user_edit_user_user'] = entity_import('rules_config', '{ "rules_redirects_user_from_user_user_edit_user_user" : {
      "LABEL" : "Redirects user from user\\/%user\\/edit  \\/user\\/%user",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "php", "rules" ],
      "ON" : { "user_update" : [] },
      "IF" : [
        { "php_eval" : { "code" : "return arg(0) == \\u0027user\\u0027 \\u0026\\u0026 arg(2) == \\u0027edit\\u0027;" } }
      ],
      "DO" : [ { "redirect" : { "url" : [ "account:url" ] } } ]
    }
  }');
  $items['rules_register_anonymous_through_the_dataset_error_report'] = entity_import('rules_config', '{ "rules_register_anonymous_through_the_dataset_error_report" : {
      "LABEL" : "\\u0420\\u0435\\u0433\\u0438\\u0441\\u0442\\u0440\\u0430\\u0446\\u0438\\u044f \\u0430\\u043d\\u043e\\u043d\\u0438\\u043c\\u043d\\u043e\\u0433\\u043e \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044f \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0444\\u043e\\u0440\\u043c\\u0443 \\u043e\\u0431\\u0440\\u0430\\u0449\\u0435\\u043d\\u0438\\u044f",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [ "rules", "php" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "continue" : { "label" : "Continue Rules", "type" : "boolean" }
      },
      "IF" : [
        { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_error_report" } },
        { "user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "1" : "1" } }
          }
        }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "entity:field-ef-email" ] },
            "PROVIDE" : { "variable_added" : { "email" : "email" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "\\u003C?php echo str_replace(\\u0027@\\u0027, \\u0027_\\u0027, $email); ?\\u003E"
            },
            "PROVIDE" : { "variable_added" : { "new_email" : "new_email" } }
          }
        },
        { "entity_create" : {
            "USING" : {
              "type" : "user",
              "param_name" : [ "new-email" ],
              "param_mail" : [ "entity:field-ef-email" ]
            },
            "PROVIDE" : { "entity_created" : { "new_user" : "new_user" } }
          }
        },
        { "data_set" : { "data" : [ "new-user:status" ], "value" : "1" } },
        { "entity_save" : { "data" : [ "new-user" ], "immediate" : 1 } },
        { "data_set" : {
            "data" : [ "new-user:field-user-name" ],
            "value" : [ "entity:field-ef-name" ]
          }
        },
        { "data_set" : {
            "data" : [ "new-user:field-user-last-name" ],
            "value" : [ "entity:field-ef-last-name" ]
          }
        },
        { "data_set" : {
            "data" : [ "new-user:field-user-middle-name" ],
            "value" : [ "entity:field-ef-patronymic" ]
          }
        },
        { "data_set" : {
            "data" : [ "new-user:field-contact-phone-number" ],
            "value" : [ "entity:field-phone-number" ]
          }
        },
        { "php_eval" : { "code" : "echo _user_mail_notify(\\u0027register_no_approval_required\\u0027, $new_user);" } }
      ],
      "PROVIDES VARIABLES" : [ "continue" ]
    }
  }');
  $items['rules_register_through_hybridauth'] = entity_import('rules_config', '{ "rules_register_through_hybridauth" : {
      "LABEL" : "\\u0420\\u0435\\u0433\\u0438\\u0441\\u0442\\u0440\\u0430\\u0446\\u0438\\u044f \\u043f\\u043e\\u043b\\u044c\\u0437\\u043e\\u0432\\u0430\\u0442\\u0435\\u043b\\u044f \\u0447\\u0435\\u0440\\u0435\\u0437 HybridAuth",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "php", "hybridauth" ],
      "ON" : { "hybridauth_user_insert" : [] },
      "DO" : [
        { "data_set" : {
            "data" : [ "hybridauth-user:field-user-name" ],
            "value" : [ "hybridauth:firstName" ]
          }
        },
        { "data_set" : {
            "data" : [ "hybridauth-user:field-user-last-name" ],
            "value" : [ "hybridauth:lastName" ]
          }
        },
        { "variable_add" : {
            "USING" : { "type" : "text", "value" : [ "hybridauth-user:name" ] },
            "PROVIDE" : { "variable_added" : { "user_name" : "user_name" } }
          }
        },
        { "variable_add" : {
            "USING" : {
              "type" : "text",
              "value" : "\\u003C?php echo str_replace(\\u0027@\\u0027, \\u0027_\\u0027, $user_name); ?\\u003E"
            },
            "PROVIDE" : { "variable_added" : { "new_login" : "new_login" } }
          }
        },
        { "data_set" : { "data" : [ "hybridauth-user:name" ], "value" : [ "new-login" ] } }
      ]
    }
  }');
  $items['rules_reject_request'] = entity_import('rules_config', '{ "rules_reject_request" : {
      "LABEL" : "\\u041e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0438\\u0442\\u044c \\u043a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0438 \\u0443\\u0432\\u0435\\u0434\\u043e\\u043c\\u0438\\u0442\\u044c \\u0430\\u0432\\u0442\\u043e\\u0440\\u0430",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "privatemsg_rules" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : {
        "competiton" : { "label" : "competiton", "type" : "node" },
        "reject_reason" : {
          "label" : "\\u041f\\u0440\\u0438\\u0447\\u0438\\u043d\\u0430 \\u043e\\u0442\\u043a\\u0430\\u0437\\u0430",
          "type" : "text"
        }
      },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "competiton" ],
            "type" : { "value" : { "competition" : "competition" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "competiton:field-competition-status" ], "value" : "reject" } },
        { "privatemsg_rules_new" : {
            "USING" : {
              "recipient" : [ "competiton:author" ],
              "author" : [ "site:current-user" ],
              "subject" : "\\u041a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0022[competiton:title]\\u0022 \\u043e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0435\\u043d",
              "body" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [competiton:author].\\r\\n\\r\\n\\u0412\\u0430\\u0448 \\u043a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0022[competiton:title]\\u0022 \\u043e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0435\\u043d \\u043f\\u043e \\u043f\\u0440\\u0438\\u0447\\u0438\\u043d\\u0435: [reject-reason:value] .\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435 \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445."
            },
            "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
          }
        },
        { "mail" : {
            "to" : [ "competiton:author:mail" ],
            "subject" : "\\u041a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0022[competiton:title]\\u0022 \\u043e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0435\\u043d \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
            "message" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [competiton:author].\\r\\n\\r\\n\\u0412\\u0430\\u0448 \\u043a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0022[competiton:title]\\u0022 \\u043e\\u0442\\u043a\\u043b\\u043e\\u043d\\u0435\\u043d \\u043f\\u043e \\u043f\\u0440\\u0438\\u0447\\u0438\\u043d\\u0435: [reject-reason:value] .\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435 \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
            "language" : [ "" ]
          }
        }
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
  $items['rules_resource_actualization_file_link_or_api'] = entity_import('rules_config', '{ "rules_resource_actualization_file_link_or_api" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0444\\u0430\\u0439\\u043b\\/API (\\u041e\\u0434\\u043d\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439)",
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
        },
        { "data_is" : { "data" : [ "new-dataset:field-multivolume" ], "value" : 0 } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "0" },
            "PROVIDE" : { "variable_added" : { "counter" : "counter" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "new-dataset:field-resources" ] },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "entityform_to_node_copy_existing_node" : {
                  "ef" : [ "enitityform-submission" ],
                  "node" : [ "resource" ],
                  "create_fields" : 0,
                  "config" : { "value" : {
                      "entityform_type" : "dataset_actualization",
                      "node_type" : "resource",
                      "field_mappings" : {
                        "field_ef_dataset" : "",
                        "field_link_api" : "field_link_api",
                        "field_link_remote_file" : "field_link_remote_file",
                        "field_date_last_change" : "",
                        "field_content_last_change" : "field_provenance",
                        "field_od_wizard_upload_file" : "",
                        "field_link_structure_file" : "field_link_structure_file",
                        "field_link_passport" : "field_link_passport",
                        "field_od_wizard_upload_structure" : "",
                        "field_dataset_convert" : "",
                        "field_dataset_variant" : ""
                      }
                    }
                  }
                }
              },
              { "data_calc" : {
                  "USING" : { "input_1" : [ "counter" ], "op" : "+", "input_2" : "1" },
                  "PROVIDE" : { "result" : { "result" : "Calculation result" } }
                }
              },
              {
                "WHILE" : { "data_is" : { "data" : [ "counter" ], "value" : "1" } },
                "DO" : []
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_rules_apply_request'] = entity_import('rules_config', '{ "rules_rules_apply_request" : {
      "LABEL" : "\\u041e\\u0434\\u043e\\u0431\\u0440\\u0438\\u0442\\u044c, \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u0442\\u044c \\u041a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0438 \\u0443\\u0432\\u0435\\u0434\\u043e\\u043c\\u0438\\u0442\\u044c \\u0430\\u0432\\u0442\\u043e\\u0440\\u0430",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "privatemsg_rules" ],
      "USES VARIABLES" : { "competiton" : { "label" : "competiton", "type" : "node" } },
      "IF" : [
        { "node_is_of_type" : {
            "node" : [ "competiton" ],
            "type" : { "value" : { "competition" : "competition" } }
          }
        }
      ],
      "DO" : [
        { "data_set" : {
            "data" : [ "competiton:field-competition-status" ],
            "value" : "approve"
          }
        },
        { "node_publish" : { "node" : [ "competiton" ] } },
        { "privatemsg_rules_new" : {
            "USING" : {
              "recipient" : [ "competiton:author" ],
              "author" : [ "site:current-user" ],
              "subject" : "\\u041a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d \\u0438 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d",
              "body" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [competiton:author].\\r\\n\\r\\n\\u0412\\u0430\\u0448 \\u043a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0022[competiton:title]\\u0022 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d \\u0438 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435.\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435 \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445."
            },
            "PROVIDE" : { "thread_id" : { "thread_id" : "ID of new thread" } }
          }
        },
        { "mail" : {
            "to" : [ "competiton:author:mail" ],
            "subject" : "\\u041a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0022[competiton:title]\\u0022 \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d \\u0438 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
            "message" : "\\u0423\\u0432\\u0430\\u0436\\u0430\\u0435\\u043c\\u044b\\u0439 [competiton:author].\\r\\n\\r\\n\\u0412\\u0430\\u0448 \\u043a\\u043e\\u043d\\u043a\\u0443\\u0440\\u0441 \\u0022[competiton:title]\\u0022 \\u0443\\u0441\\u043f\\u0435\\u0448\\u043d\\u043e \\u043e\\u0434\\u043e\\u0431\\u0440\\u0435\\u043d \\u0438 \\u043e\\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u043e\\u0432\\u0430\\u043d \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435.\\r\\n\\r\\n\\u0421 \\u0423\\u0432\\u0430\\u0436\\u0435\\u043d\\u0438\\u0435 \\u041f\\u043e\\u0440\\u0442\\u0430\\u043b \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445.",
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
  $items['rules_setting_flag_after_show'] = entity_import('rules_config', '{ "rules_setting_flag_after_show" : {
      "LABEL" : "\\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u043a\\u0430 \\u0444\\u043b\\u0430\\u0433\\u0430 \\u043f\\u0440\\u0438 \\u043f\\u0435\\u0440\\u0432\\u043e\\u043c \\u043f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435 ",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "node_view" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "dataset" : "dataset" } } } },
        { "NOT flag_flagged_node" : {
            "flag" : "materials_shown",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ]
          }
        }
      ],
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "materials_shown",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_setting_flag_if_cheked'] = entity_import('rules_config', '{ "rules_setting_flag_if_cheked" : {
      "LABEL" : "\\u0423\\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u043a\\u0430 \\u0444\\u043b\\u0430\\u0433\\u0430 \\u043f\\u043e\\u0432\\u0442\\u043e\\u0440\\u043d\\u043e \\u043f\\u0440\\u0438 \\u043f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435 \\u0432 \\u0441\\u043b\\u0435\\u0434\\u0443\\u044e\\u0449\\u0438\\u0439 \\u0440\\u0430\\u0437",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "node_view" : [] },
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "dataset" : "dataset" } } } },
        { "flag_flagged_node" : {
            "flag" : "materials_shown",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ]
          }
        }
      ],
      "DO" : [
        { "flag_unflagnode" : {
            "flag" : "materials_shown",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        },
        { "flag_flagnode" : {
            "flag" : "materials_shown",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_test_mail_system'] = entity_import('rules_config', '{ "rules_test_mail_system" : {
      "LABEL" : "test mail system",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "email" : { "label" : "email", "type" : "text" } },
      "DO" : [
        { "mail" : {
            "to" : [ "email" ],
            "subject" : "\\u041f\\u044b\\u0449\\u044c \\u0442\\u0435\\u0441\\u0442",
            "message" : "\\u043f\\u044b\\u0449\\u044c \\u043f\\u044b\\u0449\\u044c \\u043f\\u044b\\u0449\\u044c \\u043f\\u0440\\u0438\\u0448\\u043b\\u043e \\u043f\\u0438\\u0441\\u044c\\u043c\\u043e\\r\\n\\u043f\\u044b\\u0449\\u044c \\u043f\\u044b\\u0449\\u044c \\u043f\\u044b\\u0449\\u044c \\u043f\\u044b\\u0449\\u044c \\u043f\\u044b\\u0449\\u044c!\\r\\n\\u041f\\u044b\\u0449\\u044c \\u043f\\u044b\\u0449\\u044c!",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_unpublish_dataset_and_referenced_resource'] = entity_import('rules_config', '{ "rules_unpublish_dataset_and_referenced_resource" : {
      "LABEL" : "\\u0421\\u043d\\u044f\\u0442\\u0438\\u0435 \\u0441 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 + \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u0430",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "rb_misc" ],
      "ON" : { "node_update--dataset" : { "bundle" : "dataset" } },
      "IF" : [
        { "node_is_published" : { "node" : [ "node-unchanged" ] } },
        { "NOT node_is_published" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "rb_misc_action_views_load_list" : {
            "USING" : { "view" : "resources|panel_pane_1", "args" : [ "node:nid" ] },
            "PROVIDE" : { "node_list" : { "dataset_resources" : "dataset_resources" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "dataset-resources" ] },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "drupal_message" : { "message" : "\\u041d\\u0430\\u0431\\u043e\\u0440 \\u0022[node:title]\\u0022 \\u0438 \\u0420\\u0435\\u0441\\u0443\\u0440\\u0441 \\u0022[resource:title]\\u0022 \\u0441\\u043d\\u044f\\u0442\\u044b \\u0441 \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438." } },
              { "node_unpublish" : { "node" : [ "resource" ] } }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_upload_file_actualization__one_volume'] = entity_import('rules_config', '{ "rules_upload_file_actualization__one_volume" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u0442\\u044c \\u0444\\u0430\\u0439\\u043b (\\u0441 \\u043a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u0435\\u0439) (\\u041e\\u0434\\u043d\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439)",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_entityform_submission" ],
      "REQUIRES" : [
        "rules",
        "od_file_process",
        "entityform_to_node",
        "rules_conditional",
        "file_rules",
        "od_common"
      ],
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
            "value" : "upload"
          }
        },
        { "data_is" : { "data" : [ "new-dataset:type" ], "value" : "dataset" } },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-convert" ],
            "value" : 1
          }
        },
        { "data_is" : { "data" : [ "new-dataset:field-multivolume" ], "value" : 0 } }
      ],
      "DO" : [
        { "variable_add" : {
            "USING" : { "type" : "integer", "value" : "0" },
            "PROVIDE" : { "variable_added" : { "counter" : "counter" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "new-dataset:field-resources" ] },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "od_file_process_rule_callback_get_files" : {
                  "USING" : {
                    "file_2process" : [ "enitityform-submission:field-od-wizard-upload-file" ],
                    "can_expire" : 1
                  },
                  "PROVIDE" : {
                    "created_files" : { "upload_files_list" : "upload_files_list" },
                    "created_structure" : { "created_structure" : "Created structure file" },
                    "created_structure_media" : { "created_structure_media" : "Created structure file (field_item_file)" },
                    "structure_meta" : { "structure_meta" : "Structure record as universal_data_storage entity" }
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
                          "IF" : { "data_is" : { "data" : [ "resource:type" ], "value" : "resource" } },
                          "DO" : [
                            { "file_rules_copy_file" : {
                                "source_entity" : [ "enitityform-submission" ],
                                "source_field" : "field_od_wizard_upload_file",
                                "destination_entity" : [ "resource" ],
                                "destination_field" : "field_upload_original",
                                "remove_source" : "0"
                              }
                            },
                            { "data_set" : { "data" : [ "resource:field-upload" ], "value" : [ "upload-file" ] } },
                            { "od_common_file_get_extension_term" : {
                                "USING" : { "file" : [ "upload-file" ], "vocabulary" : "format" },
                                "PROVIDE" : { "extension_term" : { "file_extension" : "file_extension" } }
                              }
                            },
                            { "data_set" : { "data" : [ "resource:field-format" ], "value" : [ "file-extension" ] } },
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
                                        "destination_entity" : [ "resource" ],
                                        "destination_field" : "field_upload_structure",
                                        "remove_source" : "0"
                                      }
                                    }
                                  ]
                                },
                                { "ELSE" : [
                                    { "data_set" : {
                                        "data" : [ "resource:field-upload-structure" ],
                                        "value" : [ "created-structure-media" ]
                                      }
                                    }
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
              },
              { "data_calc" : {
                  "USING" : { "input_1" : [ "counter" ], "op" : "+", "input_2" : "1" },
                  "PROVIDE" : { "result" : { "result" : "Calculation result" } }
                }
              },
              {
                "WHILE" : { "data_is" : { "data" : [ "result" ], "value" : "1" } },
                "DO" : []
              }
            ]
          }
        }
      ]
    }
  }');
  $items['rules_upload_file_actualization_multivolume'] = entity_import('rules_config', '{ "rules_upload_file_actualization_multivolume" : {
      "LABEL" : "\\u0410\\u043a\\u0442\\u0443\\u0430\\u043b\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u0440\\u0435\\u0441\\u0443\\u0440\\u0441\\u043e\\u0432 - \\u0417\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u0442\\u044c \\u0444\\u0430\\u0439\\u043b (\\u0441 \\u043a\\u043e\\u043d\\u0432\\u0435\\u0440\\u0442\\u0430\\u0446\\u0438\\u0435\\u0439) (\\u041c\\u043d\\u043e\\u0433\\u043e\\u0442\\u043e\\u043c\\u043d\\u044b\\u0439) ",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "REQUIRES" : [
        "rules",
        "od_file_process",
        "entityform_to_node",
        "rules_conditional",
        "file_rules",
        "od_common"
      ],
      "USES VARIABLES" : {
        "enitityform_submission" : { "label" : "enitityform submission", "type" : "entityform" },
        "new_dataset" : { "label" : "new_dataset", "type" : "node" }
      },
      "IF" : [
        { "data_is" : {
            "data" : [ "enitityform-submission:type" ],
            "value" : "dataset_actualization_multivol"
          }
        },
        { "data_is" : { "data" : [ "new-dataset:type" ], "value" : "dataset" } },
        { "data_is" : {
            "data" : [ "enitityform-submission:field-dataset-convert" ],
            "value" : 1
          }
        },
        { "data_is" : { "data" : [ "new-dataset:field-multivolume" ], "value" : 1 } }
      ],
      "DO" : [
        { "LOOP" : {
            "USING" : { "list" : [ "new-dataset:field-resources" ] },
            "ITEM" : { "resource" : "resource" },
            "DO" : [
              { "od_file_process_rule_callback_get_files" : {
                  "USING" : {
                    "file_2process" : [ "enitityform-submission:field-od-wizard-upload-file" ],
                    "can_expire" : 1
                  },
                  "PROVIDE" : {
                    "created_files" : { "upload_files_list" : "upload_files_list" },
                    "created_structure" : { "created_structure" : "Created structure file" },
                    "created_structure_media" : { "created_structure_media" : "Created structure file (field_item_file)" },
                    "structure_meta" : { "structure_meta" : "Structure record as universal_data_storage entity" }
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
                          "IF" : { "data_is" : { "data" : [ "resource:type" ], "value" : "resource" } },
                          "DO" : [
                            { "file_rules_copy_file" : {
                                "source_entity" : [ "enitityform-submission" ],
                                "source_field" : "field_od_wizard_upload_file",
                                "destination_entity" : [ "resource" ],
                                "destination_field" : "field_upload_original",
                                "remove_source" : "0"
                              }
                            },
                            { "data_set" : { "data" : [ "resource:field-upload" ], "value" : [ "upload-file" ] } },
                            { "od_common_file_get_extension_term" : {
                                "USING" : { "file" : [ "upload-file" ], "vocabulary" : "format" },
                                "PROVIDE" : { "extension_term" : { "file_extension" : "file_extension" } }
                              }
                            },
                            { "data_set" : { "data" : [ "resource:field-format" ], "value" : [ "file-extension" ] } },
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
                                        "destination_entity" : [ "resource" ],
                                        "destination_field" : "field_upload_structure",
                                        "remove_source" : "0"
                                      }
                                    }
                                  ]
                                },
                                { "ELSE" : [
                                    { "data_set" : {
                                        "data" : [ "resource:field-upload-structure" ],
                                        "value" : [ "created-structure-media" ]
                                      }
                                    }
                                  ]
                                }
                              ]
                            },
                            { "od_copy_recline_visualization_data" : {
                                "data" : [ "enitityform-submission:field-recline-file-view" ],
                                "entity" : [ "node-created" ],
                                "entity_type" : "node",
                                "field_name" : "file_upload"
                              }
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
        }
      ]
    }
  }');
  $items['rules_validation_od_preprocess_wizard'] = entity_import('rules_config', '{ "rules_validation_od_preprocess_wizard" : {
      "LABEL" : "\\u0412\\u0430\\u043b\\u0438\\u0434\\u0430\\u0446\\u0438\\u044f \\u0444\\u043e\\u0440\\u043c\\u044b \\u0434\\u043e\\u0431\\u0430\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f \\u043e\\u0442\\u043a\\u0440\\u044b\\u0442\\u044b\\u0445 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "entity_rules_validation" ],
      "REQUIRES" : [ "rules", "rules_conditional", "rules_dev_comments" ],
      "USES VARIABLES" : {
        "entity" : { "label" : "Entity", "type" : "entityform" },
        "entity_is_validate" : { "label" : "Entity Validates", "type" : "boolean" }
      },
      "IF" : [
        { "OR" : [
            { "data_is" : { "data" : [ "entity:type" ], "value" : "od_preprocess_wizard" } },
            { "data_is" : { "data" : [ "entity:type" ], "value" : "dataset_actualization" } }
          ]
        }
      ],
      "DO" : [
        { "DO" : [] },
        { "CONDITIONAL" : [
            {
              "IF" : { "data_is_empty" : { "data" : [ "entity:field-link-api:url" ] } },
              "DO" : [
                { "CONDITIONAL" : [
                    {
                      "IF" : { "data_is_empty" : { "data" : [ "entity:field-od-wizard-upload-file:file" ] } },
                      "DO" : [
                        { "CONDITIONAL" : [
                            {
                              "IF" : { "data_is_empty" : { "data" : [ "entity:field-link-passport:url" ] } },
                              "DO" : [
                                { "drupal_message" : {
                                    "message" : "\\u0412 \\u0441\\u043b\\u0443\\u0447\\u0430\\u0435, \\u0435\\u0441\\u043b\\u0438 \\u0432\\u044b \\u043d\\u0435 \\u0443\\u043a\\u0430\\u0437\\u0430\\u043b\\u0438 \\u0441\\u0441\\u044b\\u043b\\u043a\\u0443 \\u043d\\u0430 API \\u0438\\u043b\\u0438 \\u043d\\u0435 \\u0437\\u0430\\u0433\\u0440\\u0443\\u0437\\u0438\\u043b\\u0438 \\u0444\\u0430\\u0439\\u043b \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430, \\u043f\\u043e\\u043b\\u0435 \\u0022\\u0421\\u0441\\u044b\\u043b\\u043a\\u0430 \\u043d\\u0430 \\u0441\\u0442\\u0440\\u0430\\u043d\\u0438\\u0446\\u0443 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u043d\\u0430 \\u0441\\u0430\\u0439\\u0442\\u0435 \\u043e\\u0431\\u043b\\u0430\\u0434\\u0430\\u0442\\u0435\\u043b\\u044f\\u0022 \\u0441\\u0442\\u0430\\u043d\\u043e\\u0432\\u0438\\u0442\\u0441\\u044f \\u043e\\u0431\\u044f\\u0437\\u0430\\u0442\\u0435\\u043b\\u044c\\u043d\\u044b\\u043c \\u0434\\u043b\\u044f \\u0437\\u0430\\u043f\\u043e\\u043b\\u043d\\u0435\\u043d\\u0438\\u044f.",
                                    "type" : "error"
                                  }
                                },
                                { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 0 } }
                              ]
                            },
                            { "ELSE" : [ { "data_set" : { "data" : [ "entity-is-validate" ], "value" : 1 } } ] }
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
      ],
      "PROVIDES VARIABLES" : [ "entity_is_validate" ]
    }
  }');
  return $items;
}
