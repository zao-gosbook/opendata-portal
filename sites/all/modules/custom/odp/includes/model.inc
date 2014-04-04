<?php

/**
 * Load dataset node by identifier.
 */
function odp_load_dataset($identifier) {
  $node = FALSE;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'dataset');
  $query->fieldCondition('field_dataset_id', 'value', $identifier);
  $query->range(0, 1);
  $query->addMetaData('account', user_load(1));
  $result = $query->execute();
  if (isset($result['node'])) {
    $query_node = reset($result['node']);
    $node = node_load($query_node->nid);
  }

  return $node;
}

/**
 * Load resource node by dataset identifier.
 */
function odp_load_dataset_resource($identifier) {
  $resource = FALSE;

  $dataset = odp_load_dataset($identifier);

  if (!empty($dataset->field_resources[LANGUAGE_NONE][0]['target_id'])) {
    $resource = node_load($dataset->field_resources[LANGUAGE_NONE][0]['target_id']);
  }

  return $resource;
}
