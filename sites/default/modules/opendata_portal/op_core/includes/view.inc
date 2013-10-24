<?php

/**
 * Theme opendata list.
 */
function theme_op_opendata_list_in_textarea($vars) {
  // Allocate variables.
  $user = $vars['user'];

  $opendata_list_view_name = 'user_opendata_list';
  $opendata_list_display_name = 'view';

  $opendata_list_view = views_get_view($opendata_list_view_name);

  $opendata_list_view->set_display($opendata_list_display_name);
  $opendata_list_view->execute();
  $result = $opendata_list_view->result;

  $nids = op_core_get_views_result_nids($result);

  $nodes = node_load_multiple($nids);

  // Get opendata list table.
  $opendata_list = new OpendataList($nodes);
  $opendata_list_table = $opendata_list->render();

  // Render html source in textarea.
  $opendata_list = theme('op_render_in_textarea', array('html' => $opendata_list_table));

  return $opendata_list;
}

/**
 * Theme opendata meta.
 */
function theme_op_opendata_meta_in_textarea($vars) {
  // Init output variable.
  $opendata_meta = '';

  // Allocate variables.
  $node = $vars['node'];

  // Load opendata object.
  $opendata = new Opendata($node);

  // Get opendata meta table.
  $opendata_meta_content = $opendata->render();

  // Render html source in textarea.
  $opendata_meta .= theme('op_render_in_textarea', array('html' => $opendata_meta_content));

  return $opendata_meta;
}

/**
 * Theme opendata render in textarea.
 */
function theme_op_render_in_textarea($vars) {
  // Init output variable.
  $rendered_textarea = '';

  // Allocate variables.
  $html = $vars['html'];

  // Input opendata table to textarea.
  $textarea = array(
    '#type' => 'textarea',
    '#value' => $html,
    '#rows' => 16,
  );

  // Render textarea.
  $rendered_textarea .= drupal_render($textarea);

  return $rendered_textarea;
}
