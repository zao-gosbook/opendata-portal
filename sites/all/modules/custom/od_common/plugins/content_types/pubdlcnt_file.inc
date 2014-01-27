<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Public download count of a file'),
  'description' => t('Public download count of a file'),
  'category' => t('Opendata Common'),
  'edit form' => 'od_common_pubdlcnt_file_content_type_edit_form',
  'required context' => new ctools_context_required(t('File'), 'entity:file'),
  'render callback' => 'od_common_pubdlcnt_file_content_type_render',
  //'summary' => 'od_common_pubdlcnt_file_content_type_summary',
);

function od_common_pubdlcnt_file_content_type_render($subtype, $conf, $args, $context) {
  // На всякий случай, если вдруг контекст был, плагин включили, а потом контекст убрали.
  if (empty($context) || empty($context->data)) {
    return;
  }

  $count = od_common_pubdlcnt_count($context->data);

  $build = array();
  $build['file'] = array(
    '#prefix' => '<div class="od-common-pubdlcnt-count-wrapper">',
    '#suffix' => '</div>',
    'data' => array(
      '#markup' => "<span class=\"value\">{$count}</span>"
    ),
  );

  return (object) array(
    'title' => $conf['override_title'] ? $conf['override_title_text'] : '',
    'content' => $build,
  );
}

function od_common_pubdlcnt_file_content_type_edit_form($form, &$form_state) {
  return $form;
}

function od_common_pubdlcnt_file_content_type_summary($conf, $context) {
  return t('File download count from ');
}