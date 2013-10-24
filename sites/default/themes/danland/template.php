<?php
// $Id: template.php,v 1.10.4.3 2010/12/14 03:30:39 danprobo Exp $
if (module_exists('ctools')) drupal_add_js(drupal_get_path('module','ctools') . '/js/collapsible-div.js');

function danland_page_class($sidebar_first, $sidebar_second) {
	if ($sidebar_first && $sidebar_second) {
		$id = 'layout-type-2';
	}
	else if ($sidebar_first || $sidebar_second) {
		$id = 'layout-type-1';
	}

	if(isset($id)) {
		print ' id="'. $id .'"';
	}
}

function danland_preprocess_html(&$vars) {
  // Add conditional CSS for IE6.
drupal_add_css(path_to_theme() . '/style.ie6.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'IE 6', '!IE' => FALSE), 'preprocess' => FALSE));
}

function danland_preprocess_maintenance_page(&$variables) {
  if (!$variables['db_is_active']) {
    unset($variables['site_name']);
  }
  drupal_add_css(drupal_get_path('theme', 'danland') . '/maintenance.css');
  drupal_add_js(drupal_get_path('theme', 'danland') . '/scripts/jquery.cycle.all.js');
}

if (drupal_is_front_page()) {
  drupal_add_js(drupal_get_path('theme', 'danland') . '/scripts/jquery.cycle.all.js');
}

function danland_preprocess_comment(&$variables) {
  if ($variables['node']->type == 'blog') {
    $variables['created'] = format_date($variables['comment']->created,'short');
    $variables['permalink'] = str_replace(t('Permalink'),'#',$variables['permalink']);
  }

}

function danland_preprocess_forum_list(&$variables) {
  foreach ($variables['tables'] as $table_id => $table) {
    foreach ($table['items'] as $item_id => $item) {
      $last_post_user = user_load($item -> last_post_obj -> uid);
      $variables['tables'][$table_id]['items'][$item_id] -> last_post =
        l($item -> last_post_obj -> node_title,
          'node/' . $item -> last_post_obj -> nid) . '<br>' . t('Author') . ': ' .
        l($last_post_user -> realname, 'user/' . $item -> last_post_obj -> uid) .
        '<br>' . format_interval(REQUEST_TIME - $item -> last_post_obj -> created) .
        ' ' . t('ago');
    }
  }
}

function danland_preprocess_username(&$vars) {
  $vars['name'] = check_plain($vars['name_raw']);
}
