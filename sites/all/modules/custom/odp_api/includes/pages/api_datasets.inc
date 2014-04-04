<?php

/**
 * Page callback.
 */
function odp_api_datasets_page($function) {
  $tags = array('datasets', 'dataset');
  $result = FALSE;

  // Get $_GET query parameters.
  $args = drupal_get_query_parameters();

  switch ($function) {
    case 'search':
    default:
      // Check for mad values
      $result = _odp_api_retrieve_search_datasets($args);
      break;
  }

  return odp_api_variable_to_xml($result, $tags);
}

function _odp_api_retrieve_search_datasets($params) {
  $query = db_select('node', 'datasets');
  $query->leftJoin('field_data_field_organization', 'field_organization', 'datasets.nid = field_organization.entity_id AND field_organization.entity_type = \'node\' AND field_organization.deleted = \'0\'');
  $query->leftJoin('field_data_field_dataset_id', 'field_dataset_id', 'datasets.nid = field_dataset_id.entity_id AND field_dataset_id.entity_type = \'node\' AND field_dataset_id.deleted = \'0\'');

  $query->leftJoin('node', 'organizations', 'organizations.nid = field_organization.field_organization_target_id AND field_organization.entity_type = \'node\'');
  $query->leftJoin('field_data_field_organization_inn', 'field_organization_inn', 'organizations.nid = field_organization_inn.entity_id AND field_organization_inn.entity_type = \'node\' AND field_organization_inn.deleted = \'0\'');

  $query->addField('datasets', 'nid');
  $query->addField('field_dataset_id', 'field_dataset_id_value', 'dataset_id');

  $query->condition('datasets.type', 'dataset');
  $query->condition('datasets.status', 1);

  if (isset($params['owner_name'])) {
    $query->condition('organizations.title', $params['owner_name'], 'LIKE');
  }
  if (isset($params['owner_id'])) {
    $query->condition('field_organization_inn.field_organization_inn_value', $params['owner_id'], 'LIKE');
  }
  if (isset($params['owner_id'])) {
    $query->condition('field_organization_inn.field_organization_inn_value', $params['owner_id']);
  }

  $offset = isset($params['offset']) ? $params['offset'] : 0;
  $limit = isset($params['limit']) ? $params['limit'] : 10000;

  $query->range($offset, $limit);
  $query->orderBy('datasets.created', 'DESC');
  $resource = $query->execute();
  $result = $resource->fetchAllKeyed(0);

  return $result;
}
