<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
//$plugin = array(
//  'single' => TRUE,
//  'title' => t('Public download count of a file (by node)'),
//  'description' => t('Public download count of a file'),
//  'category' => t('Opendata Common'),
//  'required context' => new ctools_context_required(t('Node'), 'entity:node'),
//  'render callback' => 'od_common_pubdlcnt_node_content_type_render',
//  'edit form' => 'od_common_pubdlcnt_node_content_type_edit_form',
//);

function od_common_pubdlcnt_node_content_type_render($subtype, $conf, $args, $context) {
  // На всякий случай, если вдруг контекст был, плагин включили, а потом контекст убрали.
  if (empty($context) || empty($context->data)) {
    return;
  }
  
  return (object) array(
    'title' => t('Widget configurator form.'),
//    'content' => kpr(get_defined_vars(), true),
    'content' => drupal_get_form('widget_configurator_form', $context->data->nid),
  );
}
