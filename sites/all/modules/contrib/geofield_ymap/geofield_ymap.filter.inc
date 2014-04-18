<?php

/**
 * Implements hook_filter_info().
 */
function geofield_ymap_filter_info() {
  return array(
    'filter_ymap' => array(
      'title' => t('Yandex Maps'),
      'description' => t('Replace [map][/map] on Yandex Map. Do not forget to enable option "Use loader" on <a href="@url">module settings page</a>.', array('@url' => url('admin/config/system/geofield-ymap'))),
      'process callback'  => 'geofield_ymap_filter_process',
      'settings callback' => 'geofield_ymap_filter_settings',
      'default settings' => array(
        'map_type' => 'yandex#map',
        'map_center' => '0,0',
        'map_zoom' => 10,
        'map_auto_centering' => TRUE,
        'map_auto_zooming' => TRUE,
        'map_clusterize' => FALSE,
      ),
      'tips callback' => 'geofield_ymap_filter_tips',
    ),
  );
}

/**
 * Filter settings callback.
 */
function geofield_ymap_filter_settings($form, &$form_state, $filter, $format, $defaults, $filters) {
  $filter->settings += $defaults;

  $settings['map_type'] = array(
    '#type' => 'select',
    '#title' => t('Map type'),
    '#options' => _geofield_ymap_get_map_types(),
    '#default_value' => $filter->settings['map_type'],
  );

  $settings['map_center'] = array(
    '#type' => 'textfield',
    '#title' => t('Map center'),
    '#default_value' => $filter->settings['map_center'],
    '#size' => 30,
  );

  $settings['map_zoom'] = array(
    '#type' => 'textfield',
    '#title' => t('Map zoom'),
    '#default_value' => $filter->settings['map_zoom'],
    '#size' => 5,
  );

  $settings['map_auto_centering'] = array(
    '#type' => 'checkbox',
    '#title' => t('Map auto centering'),
    '#default_value' => $filter->settings['map_auto_centering'],
  );

  $settings['map_auto_zooming'] = array(
    '#type' => 'checkbox',
    '#title' => t('Map auto zooming'),
    '#default_value' => $filter->settings['map_auto_zooming'],
  );

  $settings['map_clusterize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Clusterize placemarks'),
    '#default_value' => $filter->settings['map_clusterize'],
  );

  return $settings;
}

/**
 * Filter process callback.
 */
function geofield_ymap_filter_process($text, $filter, $format, $langcode, $cache, $cache_id) {
  if (preg_match_all('#\[map(.*?)\](.*?)\[/map\]#s', $text, $matches_all, PREG_SET_ORDER)) {
    $default_element = array();
    foreach ($filter->settings as $filter_setting_name => $filter_setting_value) {
      $default_element['#' . $filter_setting_name] = $filter_setting_value;
    }

    foreach ($matches_all as $matches) {
      $map_settings = trim($matches[1]);
      $map_objects = trim($matches[2]);
      $element = $default_element;
      
      if ($map_settings) {
        foreach (explode(' ', $map_settings) as $map_setting) {
          list($map_setting_name, $map_setting_value) = explode('=', $map_setting);
          $map_setting_name = str_replace('-', '_', $map_setting_name);
          if (isset($filter->settings['map_' . $map_setting_name])) {
            $element['#map_' . $map_setting_name] = trim($map_setting_value, '"');
          }
        }
      }
      if ($map_objects) {
        $element['#map_objects'] = str_replace("\n", ' ', $map_objects);
      }

      $text = str_replace($matches[0], theme('geofield_ymap', array('element' => $element)), $text);
    }
  }

  return $text;
}

/**
 * Filter tips callback.
 */
function geofield_ymap_filter_tips($filter, $format, $long) {
  if ($long) {
    return t('You may insert maps with [map][/map] tag.') . ' ' . t('Example') . ': <code>[map]{"type":"Point","coordinates":[37.62,55.75]}[/map]</code> or <code>[map zoom=10 auto-zooming=0][{"type":"Point","coordinates":[37.62,55.75]},{"type":"Point","coordinates":[38.22,51.55]}][/map]</code>';
  }
  else {
    return t('You may insert maps with [map][/map] tag.');
  }
}
