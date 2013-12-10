<?php

/**
 * @file
 * Definition of the 'Tabs' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Tabs'),
  'description' => t('Show panel panes in a region as tabs.'),
  'render region' => 'panels_tabs_style_render_region',
  'settings form' => 'panels_tabs_pane_settings_form',
);

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_panels_tabs_style_render_region($vars) {
  $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];

  $tab_id = 'tabs-';
  $pattern = isset($vars['settings']['panel_tab_id_pattern']) ? $vars['settings']['panel_tab_id_pattern'] : 'region';
  if ($pattern == 'random') {
    $tab_id .= md5($owner_id . $region_id . REQUEST_TIME . rand());
  }
  else {
    $tab_id .= $owner_id . '-' . $region_id;
  }

  $element = array(
    '#prefix' => '<div id="' . $tab_id . '">',
    '#suffix' => '</div>',
    '#attached' => array(
      'library' => array(array('system', 'ui.tabs')),
      'js' => array(
        drupal_get_path('module', 'panels_tabs') . '/js/panels_tabs.js' => array('type' => 'file'),
      ),
    ),
  );

  $settings = array();
  $settings['panelsTabs']['tabsID'][] = $tab_id;

  $element['#attached']['js'][] = array(
    'type' => 'setting',
    'data' => $settings,
  );

  // Get the pane titles.
  $items = array();
  $delta = 1;
  foreach ($display->panels[$region_id] as $pane_id) {
    // Make sure the pane exists.
    if (!empty($panes[$pane_id])) {
      $title = panels_tabs_pane_titles($display->did, $pane_id);
      $title = $title ? $title : t('Tab @delta', array('@delta' => $delta));
      $items[] = '<a href="#'. $tab_id . '-' . $delta .'">' . $title . '</a>';
      $delta++;
    }
  }

  $element['tabs_title'] = array('#theme' => 'item_list', '#items' => $items);

  $delta = 1;
  foreach ($panes as $pane_id => $item) {
    $element['tabs_content'][$pane_id] = array(
      '#prefix' => '<div id="' . $tab_id . '-' . $delta . '">',
      '#suffix' => '</div>',
      '#markup' => $item,
    );
    $delta++;
  }

  return drupal_render($element);
}

function panels_tabs_pane_settings_form($style_settings) {
  $form = array();

  $form['panel_tab_id_pattern'] = array(
    '#type' => 'radios',
    '#title' => t("Tab ID pattern"),
    '#decsription' => t("Method to generate HTML id attribute for tabs."),
    '#default_value' => isset($style_settings['panel_tab_id_pattern']) ? $style_settings['panel_tab_id_pattern'] : 'region',
    '#options' => array(
      'region' => t('Fixed, based on region id (select this when panel region can be placed on the page only once)'),
      'random' => t('Generate random id (select this when panel region can be placed on the page multiple times)'),
    ),
  );

  return $form;
}
