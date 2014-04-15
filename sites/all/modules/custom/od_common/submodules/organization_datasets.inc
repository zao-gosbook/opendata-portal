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
   $counter = 1;
   foreach ($result_datasets['node'] as $node) {
     $counter++;
     $dataset = node_load($node->nid);
     $dataset_link = l($dataset->title, 'node/' . $dataset->nid);
     $dataset_string = '<div>' . $dataset_link . '</div>';
     $org_datasets .= $dataset_string;
     if ($counter > 10 && ((count($result_datasets['node']) - 10) !== 0)) {
       $org_datasets .= '<div class="more-link">' . l(t('More @count datasets', array('@count' => count($result_datasets['node']) - 10)), 'node/' . $org_nid). '</div>';
       break;
     }
   }
  return $org_datasets;
  }
}


/**
 *  Функция вывода списка наборов организации на карте по определенной рубрике.
 */ 
function _od_common_organization_topic_datasets($org_nid, $topic_id) {
 $query_datasets = new EntityFieldQuery;
  $result_datasets = $query_datasets->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', 'dataset')
  ->propertyCondition('status', 1)
  ->fieldCondition('field_organization', 'target_id', $org_nid, '=')
  ->fieldCondition('field_rubric', 'tid', $topic_id, '=')
  ->execute();
 if (count($result_datasets['node'])) {
   $org_datasets = '';
   $counter = 1;
   foreach ($result_datasets['node'] as $node) {
     $counter++;
     $dataset = node_load($node->nid);
     $dataset_link = l($dataset->title, 'node/' . $dataset->nid);
     $dataset_string = '<div>' . $dataset_link . '</div>';
     $org_datasets .= $dataset_string;
     if ($counter > 10 && ((count($result_datasets['node']) - 10) !== 0)) {
       $org_datasets .= '<div class="more-link">' . l(t('More @count datasets', array('@count' => count($result_datasets['node']) - 10)), 'node/' . $org_nid). '</div>';
       break;
     }
   }
  return $org_datasets;
  }
}
