<?php

function op_core_opendata_list_in_textarea($user) {
  return theme('op_opendata_list_in_textarea', array('user' => $user));
}

function op_core_opendata_meta_in_textarea($node) {
  return theme('op_opendata_meta_in_textarea', array('node' => $node));
}

function op_core_get_views_result_nids($result) {
  $nids = array();
  foreach ($result as $row) {
    $nids[] = $row->nid;
  }

  return $nids;
}
