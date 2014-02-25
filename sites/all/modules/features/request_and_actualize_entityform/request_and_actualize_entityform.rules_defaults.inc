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
