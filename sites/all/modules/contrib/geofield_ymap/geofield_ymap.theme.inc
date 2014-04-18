<?php

/**
 * Preprocess function for theme_geofield_ymap().
 */
function template_preprocess_geofield_ymap(&$variables) {
  $element = $variables['element'];

  if (!empty($element['#id'])) {
    $variables['#attributes']['id'] = $element['#id'] . '-map';
  }
  $variables['#attributes']['class'][] = 'geofield-ymap';

  // Formatting #map_objects as string
  if (!empty($element['#map_objects'])) {
    if (is_array($element['#map_objects'])) {
      $element['#map_objects'] = _geofield_ymap_json_encode($element['#map_objects']);
    }
    else {
      $element['#map_objects'] = trim($element['#map_objects']);
    }
  }
  else {
    $variables['#attributes']['class'][] = 'geofield-ymap-empty';
  }

  // See Drupal.geofieldYmap.defaultSettings
  $map_settings = array(
    'map_type'             => 'yandex#map',
    'map_center'           => '0,0',
    'map_zoom'             => 0,
    'map_auto_centering'   => FALSE,
    'map_auto_zooming'     => FALSE,
    'map_editable'         => FALSE,
    'map_multiple'         => FALSE,
    'map_clusterize'       => FALSE,
    'map_controls'         => 'default',
    'map_selected_control' => '',
    'map_object_types'     => '',
    'map_object_preset'    => '',
    'map_input_id'         => '',
    'map_objects'          => '',
  );
  foreach ($map_settings as $setting_name => $setting_value) {
    if (isset($element['#' . $setting_name])) {
      $attribute_name = 'data-' . str_replace('_', '-', $setting_name);
      $attribute_value = $element['#' . $setting_name];
      if (is_array($attribute_value)) {
        $attribute_value = implode(',', $attribute_value);
      }
      if ($attribute_value != $setting_value && $attribute_value !== '') {
        $variables['#attributes'][$attribute_name] = $attribute_value;
      }
    }
  }

  drupal_add_library('geofield_ymap', 'geofield_ymap');
}

/**
 * Return map markup.
 */
function theme_geofield_ymap($variables) {
  return '<div' . drupal_attributes($variables['#attributes']) . '></div>' . drupal_render_children($variables['element']);
}
