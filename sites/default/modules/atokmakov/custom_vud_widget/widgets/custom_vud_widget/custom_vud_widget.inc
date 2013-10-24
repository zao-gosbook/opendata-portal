<?php

function custom_vud_widget_custom_vud_widget_vud_widgets() {
  return array(
    'title' => t('Custom'),
    'widget template' => 'widget',
    'alter template variables' => 'custom_vud_widget_custom_vud_widget_vud_widget_alter'
  );
}

function custom_vud_widget_custom_vud_widget_vud_widget_alter($template_type, &$variables) {
  $criteria = array(
    'entity_type' => $variables['type'],
    'entity_id' => $variables['entity_id'],
    'value_type' => 'points',
    'tag' => $variables['tag'],
    'function' => 'positives'
  );
  $positives = (int)votingapi_select_single_result_value($criteria);
  $variables['up_points'] = $positives;

  $criteria = array(
    'entity_type' => $variables['type'],
    'entity_id' => $variables['entity_id'],
    'value_type' => 'points',
    'tag' => $variables['tag'],
    'function' => 'negatives'
  );
  $negatives = (int)votingapi_select_single_result_value($criteria);
  $variables['down_points'] = $negatives;
}
