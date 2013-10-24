<?php

function theme_opendata_views_plugin_style_opendata_table($vars) {
  $rows = $vars['rows'];

  $nids = array();

  foreach ($rows as $row) {
    $nids[] = $row->nid;
  }

  $nodes = node_load_multiple($nids);

  $opendata_list = new OpendataList($nodes);
  $opendata_list_content = $opendata_list->render();

  return $opendata_list_content;
}
