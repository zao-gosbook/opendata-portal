<?php

/**
 *  Функция вывода списка наборов организации на карте.
 */ 
function _od_common_organization_datasets($org_nid) {
 $query_datasets = new EntityFieldQuery;
  $result_datasets = $query_datasets->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'dataset')
  ->propertyCondition('status', 1)
  ->fieldCondition('field_organization', 'target_id', $org_nid, '=')
  ->execute();
 if (count($result_datasets['node'])) {
   $org_datasets = '';
   $counter = 0;
   foreach ($result_datasets['node'] as $node) {
     $counter++;
     $dataset = node_load($node->nid);
     $dataset_link = l($dataset->title, 'node/' . $dataset->nid);
     $dataset_string = '<div>' . $dataset_link . '<div>';
     $org_datasets .= $dataset_string;
     if ($counter > 10) break;
   }
   if (count($result_datasets['node']) >= 20) {
     $org_datasets .= '<div class="more-link">' . l(t('More @count datasets', array('@count' => count($result_datasets['node']) - $counter)), 'node/' . $org_nid). '</div>';
   }
  return $org_datasets;
  }
}
