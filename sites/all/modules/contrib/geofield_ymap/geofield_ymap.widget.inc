<?php

/**
 * Implements hook_field_widget_info().
 */
function geofield_ymap_field_widget_info() {
  return array(
    'geofield_ymap' => array(
      'label' => t('Yandex Map'),
      'field types' => array('geofield'),
      'settings' => array(
        'map_type' => 'yandex#map',
        'map_center' => '37.62221595263608,55.75378270800939', // Moscow
        'map_zoom' => 10,
        'map_controls' => 'default',
        'map_selected_control' => '',
        'map_object_types' => array('point'),
        'map_object_preset' => '',
      ),
      'behaviors' => array(
        'multiple values' => FIELD_BEHAVIOR_CUSTOM,
      ),
    ),
  );
}

/**
 * Implements hook_field_widget_settings_form().
 */
function geofield_ymap_field_widget_settings_form($field, $instance) {
  $settings = $instance['widget']['settings'];

  $form['map_type'] = array(
    '#type' => 'select',
    '#title' => t('Map type'),
    '#options' => _geofield_ymap_get_map_types(),
    '#default_value' => $settings['map_type'],
  );

  $form['map_center'] = array(
    '#type' => 'textfield',
    '#title' => t('Map center'),
    '#description' => t('Map center coordinates: Longtitude,Latitude'),
    '#default_value' => $settings['map_center'],
  );

  $form['map_zoom'] = array(
    '#type' => 'textfield',
    '#title' => t('Map zoom'),
    '#description' => t('From 1 to 16'),
    '#default_value' => $settings['map_zoom'],
    '#size' => 5,
  );

  $form['map_object_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Object types'),
    '#description' => t('Select object types that the user can add to the map'),
    '#options' => array(
      'point' => t('Point'),
      'line' => t('Line'),
      'polygon' => t('Polygon'),
    ),
    '#default_value' => $settings['map_object_types'],
  );

  $form['map_selected_control'] = array(
    '#type' => 'select',
    '#title' => t('Default selected control'),
    '#options' => array(
      '' => t('< none >'),
      'point' => t('Point'),
      'line' => t('Line'),
      'polygon' => t('Polygon'),
    ),
    '#default_value' => $settings['map_selected_control'],
  );

  $form['map_object_preset'] = array(
    '#type' => 'textfield',
    '#title' => t('Preset name'),
    '#description' => t('<a href="@url" target="_blank">Preset name</a>.', array(
      '@url' => 'http://api.yandex.ru/maps/doc/jsapi/beta/ref/reference/option.presetStorage.xml'
    )),
    '#default_value' => $settings['map_object_preset'],
  );

  $form['map_controls'] = array(
    '#type' => 'textfield',
    '#title' => t('Controls'),
    '#description' => t('<a href="@url" target="_blank">Controls</a> through a comma, or controls set name. Use <code>&lt;none&gt;</code> to hide all controls. Default set name: <code>default</code>', array(
      '@url' => 'http://api.yandex.ru/maps/doc/jsapi/beta/ref/reference/control.Manager.xml#add',
    )),
    '#default_value' => $settings['map_controls'],
  );
  
  return $form;
}

/**
 * Implements hook_field_widget_form().
 */
function geofield_ymap_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $settings = $instance['widget']['settings'];

  $element['geom'] = array(
    '#type' => 'geofield_ymap',
    '#title' => $instance['label'],
    '#description' => $instance['description'],
    '#map_multiple' => ($field['cardinality'] != 1),
    '#map_type' => $settings['map_type'],
    '#map_center' => $settings['map_center'],
    '#map_zoom' => $settings['map_zoom'],
    '#map_auto_centering' => TRUE,
    '#map_auto_zooming' => TRUE,
    '#map_controls' => $settings['map_controls'],
    '#map_selected_control' => $settings['map_selected_control'],
    '#map_object_types' => array_filter($settings['map_object_types']),
    '#map_object_preset' => $settings['map_object_preset'],
    '#default_value' => geofield_ymap_items_to_geojson($items),
  );

  // Validate and prepare field value callback
  $element['#element_validate'][] = 'geofield_ymap_field_widget_validate';

  return $element;
}

/**
 * Widget validate callback.
 */
function geofield_ymap_field_widget_validate($element, &$form_state) {
  if (!empty($element['geom']['#value'])) {
    geophp_load();
    $geom = geoPHP::load($element['geom']['#value']);
    $geom = geoPHP::geometryReduce($geom);

    $values = array();
    foreach (geofield_ymap_split_objects($geom) as $geom) {
      $values[] = array(
        'geom' => $geom->out('json'),
        'input_format' => 'json',
      );
    }

    form_set_value($element, $values, $form_state);
  }
}
