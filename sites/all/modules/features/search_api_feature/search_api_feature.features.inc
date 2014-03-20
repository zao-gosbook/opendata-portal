<?php
/**
 * @file
 * search_api_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function search_api_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function search_api_feature_default_search_api_index() {
  $items = array();
  $items['apps'] = entity_import('search_api_index', '{
    "name" : "\\u041f\\u0440\\u0438\\u043b\\u043e\\u0436\\u0435\\u043d\\u0438\\u044f",
    "machine_name" : "apps",
    "description" : null,
    "server" : "search_api_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text", "boost" : "5.0" },
        "field_rubric" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "body:value" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "app" : "app" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['datasets'] = entity_import('search_api_index', '{
    "name" : "Datasets",
    "machine_name" : "datasets",
    "description" : null,
    "server" : "search_api_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "status" : { "type" : "boolean" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "clone_title" : { "type" : "string" },
        "field_rubric" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_organization" : { "type" : "integer", "entity_type" : "node" },
        "field_dataset_standard" : { "type" : "boolean" },
        "field_popularity_range" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text" },
        "field_resources:field_format" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_organization:field_organization_type" : { "type" : "integer", "entity_type" : "taxonomy_term" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "dataset" : "dataset" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['documents'] = entity_import('search_api_index', '{
    "name" : "\\u0414\\u043e\\u043a\\u0443\\u043c\\u0435\\u043d\\u0442\\u044b",
    "machine_name" : "documents",
    "description" : null,
    "server" : "search_api_solr",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "title" : { "type" : "text", "boost" : "5.0" },
        "status" : { "type" : "boolean" },
        "created" : { "type" : "date" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "views" : { "type" : "integer" },
        "field_rubric" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_document_type" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : { "default" : "0", "bundles" : { "document" : "document" } }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['nodes'] = entity_import('search_api_index', '{
    "name" : "Nodes",
    "machine_name" : "nodes",
    "description" : "\\u041f\\u043e\\u0438\\u0441\\u043a \\u043f\\u043e \\u0441\\u0430\\u0439\\u0442\\u0443",
    "server" : "datasets",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "type" : { "type" : "string" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "status" : { "type" : "boolean" },
        "changed" : { "type" : "date" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_rubric" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "body:value" : { "type" : "text" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "blog" : "blog",
              "idea" : "idea",
              "news" : "news",
              "event" : "event",
              "forum" : "forum"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function search_api_feature_default_search_api_server() {
  $items = array();
  $items['datasets'] = entity_import('search_api_server', '{
    "name" : "Datasets",
    "machine_name" : "datasets",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "indexes" : { "nodes" : {
          "type" : {
            "table" : "search_api_db_nodes",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_nodes_title",
            "type" : "text",
            "boost" : "5.0"
          },
          "field_tags" : {
            "table" : "search_api_db_nodes_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_rubric" : {
            "table" : "search_api_db_nodes",
            "column" : "field_rubric",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_nodes",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_nodes_body_value",
            "type" : "text",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_nodes",
            "column" : "status",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_nodes",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_nodes_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_nodes",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  $items['search_api_solr'] = entity_import('search_api_server', '{
    "name" : "Search API Solr",
    "machine_name" : "search_api_solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "scheme" : "http",
      "host" : "solr.p1ratrulezzz.com",
      "port" : "8983",
      "path" : "\\/solr\\/opendatagov.ru",
      "http_user" : "solr",
      "http_pass" : "G0$bookru",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "http_method" : "AUTO"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function search_api_feature_default_search_api_sort() {
  $items = array();
  $items['datasets__author'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "author",
    "name" : "\\u0410\\u0432\\u0442\\u043e\\u0440",
    "enabled" : "0",
    "weight" : "-94",
    "identifier" : "datasets__author",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0410\\u0432\\u0442\\u043e\\u0440" },
    "rdf_mapping" : []
  }');
  $items['datasets__changed'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "changed",
    "name" : "date of change",
    "enabled" : "1",
    "weight" : "-98",
    "identifier" : "datasets__changed",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0414\\u0430\\u0442\\u0430 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0430" },
    "rdf_mapping" : []
  }');
  $items['datasets__clone_title'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "clone_title",
    "name" : "or title",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "datasets__clone_title",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Title clone" },
    "rdf_mapping" : []
  }');
  $items['datasets__field_dataset_standard'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "field_dataset_standard",
    "name" : "Recommended",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "datasets__field_dataset_standard",
    "default_sort" : "1",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0420\\u0435\\u043a\\u043e\\u043c\\u0435\\u043d\\u0434\\u043e\\u0432\\u0430\\u043d\\u043e" },
    "rdf_mapping" : []
  }');
  $items['datasets__field_organization'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "field_organization",
    "name" : "\\u041e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f",
    "enabled" : "0",
    "weight" : "-92",
    "identifier" : "datasets__field_organization",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0412\\u043b\\u0430\\u0434\\u0435\\u043b\\u0435\\u0446 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445" },
    "rdf_mapping" : []
  }');
  $items['datasets__field_organization:field_organization_type'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "field_organization:field_organization_type",
    "name" : "\\u041e\\u0440\\u0433\\u0430\\u043d\\u0438\\u0437\\u0430\\u0446\\u0438\\u044f \\u00bb \\u0422\\u0438\\u043f",
    "enabled" : "0",
    "weight" : "-90",
    "identifier" : "datasets__field_organization:field_organization_type",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0412\\u043b\\u0430\\u0434\\u0435\\u043b\\u0435\\u0446 \\u043d\\u0430\\u0431\\u043e\\u0440\\u0430 \\u0434\\u0430\\u043d\\u043d\\u044b\\u0445 \\u00bb \\u0422\\u0438\\u043f" },
    "rdf_mapping" : []
  }');
  $items['datasets__field_popularity'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "field_popularity",
    "name" : "\\u041f\\u043e\\u043f\\u0443\\u043b\\u044f\\u0440\\u043d\\u043e\\u0441\\u0442\\u0438",
    "enabled" : "1",
    "weight" : "-97",
    "identifier" : "datasets__field_popularity",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "field_popularity" },
    "rdf_mapping" : []
  }');
  $items['datasets__field_rubric'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "field_rubric",
    "name" : "\\u0420\\u0443\\u0431\\u0440\\u0438\\u043a\\u0430",
    "enabled" : "0",
    "weight" : "-93",
    "identifier" : "datasets__field_rubric",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0420\\u0443\\u0431\\u0440\\u0438\\u043a\\u0430" },
    "rdf_mapping" : []
  }');
  $items['datasets__search_api_language'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "search_api_language",
    "name" : "Item language",
    "enabled" : "0",
    "weight" : "-91",
    "identifier" : "datasets__search_api_language",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Item language" },
    "rdf_mapping" : []
  }');
  $items['datasets__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "0",
    "weight" : "-100",
    "identifier" : "datasets__search_api_relevance",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" },
    "rdf_mapping" : []
  }');
  $items['datasets__status'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "status",
    "name" : "\\u0421\\u0442\\u0430\\u0442\\u0443\\u0441",
    "enabled" : "0",
    "weight" : "-95",
    "identifier" : "datasets__status",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0421\\u0442\\u0430\\u0442\\u0443\\u0441" },
    "rdf_mapping" : []
  }');
  $items['datasets__title'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "title",
    "name" : "\\u041d\\u0430\\u0438\\u043c\\u0435\\u043d\\u043e\\u0432\\u0430\\u043d\\u0438\\u044e",
    "enabled" : "1",
    "weight" : "-99",
    "identifier" : "datasets__title",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "asc",
    "options" : { "field_name" : "\\u0417\\u0430\\u0433\\u043e\\u043b\\u043e\\u0432\\u043e\\u043a" },
    "rdf_mapping" : []
  }');
  $items['datasets__title_phantom'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "title_phantom",
    "name" : "Title clone",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "datasets__title_phantom",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "title_phantom" },
    "rdf_mapping" : []
  }');
  $items['datasets__type'] = entity_import('search_api_sort', '{
    "index_id" : "datasets",
    "field" : "type",
    "name" : "\\u0422\\u0438\\u043f \\u043c\\u0430\\u0442\\u0435\\u0440\\u0438\\u0430\\u043b\\u0430",
    "enabled" : "0",
    "weight" : "-96",
    "identifier" : "datasets__type",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0422\\u0438\\u043f \\u043c\\u0430\\u0442\\u0435\\u0440\\u0438\\u0430\\u043b\\u0430" },
    "rdf_mapping" : []
  }');
  $items['documents__changed'] = entity_import('search_api_sort', '{
    "index_id" : "documents",
    "field" : "changed",
    "name" : "date of change",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "documents__changed",
    "default_sort" : "0",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0414\\u0430\\u0442\\u0430 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0430" },
    "rdf_mapping" : []
  }');
  $items['documents__created'] = entity_import('search_api_sort', '{
    "index_id" : "documents",
    "field" : "created",
    "name" : "creation date",
    "enabled" : "0",
    "weight" : "0",
    "identifier" : "documents__created",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0414\\u0430\\u0442\\u0430 \\u0441\\u043e\\u0437\\u0434\\u0430\\u043d\\u0438\\u044f" },
    "rdf_mapping" : []
  }');
  $items['documents__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "documents",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "0",
    "weight" : "0",
    "identifier" : "documents__search_api_relevance",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" },
    "rdf_mapping" : []
  }');
  $items['documents__views'] = entity_import('search_api_sort', '{
    "index_id" : "documents",
    "field" : "views",
    "name" : "popularity",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "documents__views",
    "default_sort" : "1",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u041a\\u043e\\u043b\\u0438\\u0447\\u0435\\u0441\\u0442\\u0432\\u043e \\u043f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u043e\\u0432" },
    "rdf_mapping" : []
  }');
  $items['nodes__changed'] = entity_import('search_api_sort', '{
    "index_id" : "nodes",
    "field" : "changed",
    "name" : "\\u0434\\u0430\\u0442\\u0435 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u044f",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "nodes__changed",
    "default_sort" : "0",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "\\u0414\\u0430\\u0442\\u0430 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0430" },
    "rdf_mapping" : []
  }');
  $items['nodes__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "nodes",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "nodes__search_api_relevance",
    "default_sort" : "1",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" },
    "rdf_mapping" : []
  }');
  return $items;
}
