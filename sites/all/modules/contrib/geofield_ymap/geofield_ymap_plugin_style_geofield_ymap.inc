<?php

class geofield_ymap_plugin_style_geofield_ymap extends views_plugin_style {
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['map_type']           = array('default' => 'yandex#map');
    $options['map_center']         = array('default' => '0,0');
    $options['map_zoom']           = array('default' => 10);
    $options['map_auto_centering'] = array('default' => FALSE, 'bool' => TRUE);
    $options['map_auto_zooming']   = array('default' => FALSE, 'bool' => TRUE);
    $options['map_clusterize']     = array('default' => FALSE, 'bool' => TRUE);
    $options['map_hide_empty']     = array('default' => FALSE, 'bool' => TRUE);
    $options['map_object_preset']  = array('default' => '');
    $options['map_controls']       = array('default' => 'default');
    $options['hint_content_field'] = array('default' => '');
    $options['icon_content_field'] = array('default' => '');
    $options['preset_field']       = array('default' => '');
    $options['additional_settings']['object_options']            = array('default' => '');
    $options['additional_settings']['object_options_use_tokens'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  /**
   * Options form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $field_options = array('' => t('< none >'));
    $fields = $this->display->handler->get_handlers('field');
    foreach ($fields as $id => $handler) {
      $field_options[$id] = $handler->ui_name(FALSE);
    }

    $form['map_type'] = array(
      '#type' => 'select',
      '#title' => t('Map type'),
      '#options' => _geofield_ymap_get_map_types(),
      '#default_value' => $this->options['map_type'],
    );

    $form['map_center'] = array(
      '#type' => 'textfield',
      '#title' => t('Map center'),
      '#default_value' => $this->options['map_center'],
      '#size' => 40,
    );

    $form['map_zoom'] = array(
      '#type' => 'textfield',
      '#title' => t('Map zoom'),
      '#default_value' => $this->options['map_zoom'],
      '#size' => 5,
    );

    $form['map_auto_centering'] = array(
      '#type' => 'checkbox',
      '#title' => t('Map auto centering'),
      '#default_value' => $this->options['map_auto_centering'],
    );

    $form['map_auto_zooming'] = array(
      '#type' => 'checkbox',
      '#title' => t('Map auto zooming'),
      '#default_value' => $this->options['map_auto_zooming'],
    );

    $form['map_clusterize'] = array(
      '#type' => 'checkbox',
      '#title' => t('Clusterize placemarks'),
      '#default_value' => $this->options['map_clusterize'],
    );

    $form['map_hide_empty'] = array(
      '#type' => 'checkbox',
      '#title' => t('Hide empty map'),
      '#default_value' => $this->options['map_hide_empty'],
    );

    $form['hint_content_field'] = array(
      '#type' => 'select',
      '#title' => t('Hint content field'),
      '#options' => $field_options,
      '#default_value' => $this->options['hint_content_field'],
    );

    $form['icon_content_field'] = array(
      '#type' => 'select',
      '#title' => t('Icon content field'),
      '#options' => $field_options,
      '#default_value' => $this->options['icon_content_field'],
    );

    $form['preset_field'] = array(
      '#type' => 'select',
      '#title' => t('Preset field'),
      '#description' => t('Use next modules for replace field value to preset name: !modules', array(
        '!modules' => '
          <a href="https://drupal.org/sandbox/xandeadx/2205151" target="_blank">Views field replace value</a>,
          <a href="https://drupal.org/project/views_regex_rewrite" target="_blank">Views Regex Rewrite</a>,
          <a href="https://drupal.org/project/views_fieldrewrite" target="_blank">Views Field Rewrite</a>
        ',
      )),
      '#options' => $field_options,
      '#default_value' => $this->options['preset_field'],
    );

    $form['map_object_preset'] = array(
      '#type' => 'textfield',
      '#title' => t('Default objects preset'),
      '#description' => t('Default <a href="@url" target="_blank">preset name</a>.', array(
        '@url' => 'http://api.yandex.ru/maps/doc/jsapi/beta/ref/reference/option.presetStorage.xml',
      )),
      '#default_value' => $this->options['map_object_preset'],
      '#size' => 40,
    );

    $form['map_controls'] = array(
      '#type' => 'textfield',
      '#title' => t('Controls'),
      '#description' => t('<a href="@url" target="_blank">Controls</a> through a comma, or controls set name. Use <code>&lt;none&gt;</code> to hide all controls. Default set name: <code>default</code>', array(
        '@url' => 'http://api.yandex.ru/maps/doc/jsapi/beta/ref/reference/control.Manager.xml#add',
      )),
      '#default_value' => $this->options['map_controls'],
      '#size' => 40,
    );

    $form['additional_settings'] = array(
      '#title' => t('Additional settings'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE, 
      '#collapsed' => TRUE,
    );

    $form['additional_settings']['object_options'] = array(
      '#title' => t('Object options'),
      '#description' => t('Additional object options in JSON format. <a href="!url" target="_blank">Options list</a>. Example: !example', array(
        '!url' => 'http://api.yandex.ru/maps/doc/jsapi/beta/ref/reference/GeoObject.xml#constructor-summary',
        '!example' => '
          <code><br />
            {<br />
            &nbsp;&nbsp;"iconLayout": "default#image",<br />
            &nbsp;&nbsp;"iconImageHref": "http://api.yandex.ru/maps/doc/jsapi/2.x/examples/images/myIcon.gif",<br />
            &nbsp;&nbsp;"iconImageSize": [30, 42],<br />
            &nbsp;&nbsp;"iconImageOffset": [-3, -42]<br />
            }
          </code>
        ',
      )),
      '#type' => 'textarea',
      '#default_value' => $this->options['additional_settings']['object_options'],
    );

    $form['additional_settings']['object_options_use_tokens'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use replacement tokens (reduce performance)'),
      '#default_value' => $this->options['additional_settings']['object_options_use_tokens'],
    );
  }

  /**
   * Render the display in this style.
   */
  function render() {
    $geofield = '';
    foreach ($this->view->field as $field_name => $field_handler) {
      if (isset($field_handler->field_info) && $field_handler->field_info['type'] == 'geofield') {
        $geofield = $field_name;
        break;
      }
    }
    if (!$geofield) {
      return t('Add geofield to fields list.');
    }

    $this->view->field[$geofield]->options['exclude'] = TRUE;
    $this->render_fields($this->view->result);

    if ($this->view->result) {
      geophp_load();
    }
    elseif ($this->options['map_hide_empty']) {
      return NULL;
    }

    $features = array();

    // Additional object options without tokens
    $object_options = array();
    if ($this->options['additional_settings']['object_options'] && !$this->options['additional_settings']['object_options_use_tokens']) {
      $object_options = json_decode($this->options['additional_settings']['object_options'], TRUE);
    }

    // Each on result rows
    foreach ($this->view->result as $row_index => $row) {
      $this->view->row_index = $row_index;
      $geofield_values = $this->view->field[$geofield]->get_value($row);
      $geofield_values = array_filter(array_map('array_filter', $geofield_values));
      if (empty($geofield_values)) {
        continue;
      }

      $baloon_content = trim($this->row_plugin->render($row));
      $hint_content = $this->options['hint_content_field'] ? trim($this->get_field($row_index, $this->options['hint_content_field'])) : '';
      $icon_content = $this->options['icon_content_field'] ? trim($this->get_field($row_index, $this->options['icon_content_field'])) : '';
      $preset = $this->options['preset_field'] ? trim($this->get_field($row_index, $this->options['preset_field'])) : '';

      // Additional object options with tokens
      if ($this->options['additional_settings']['object_options'] && $this->options['additional_settings']['object_options_use_tokens']) {
        $object_options = $this->safe_tokenize_value($this->options['additional_settings']['object_options'], $row_index);
        $object_options = json_decode($object_options, TRUE);
      }

      // Each on geofield items
      foreach ($geofield_values as $geofield_value) {
        $geoms = geoPHP::load($geofield_value['geom']);

        // Each on item geoms
        foreach (geofield_ymap_split_objects($geoms) as $geom) {
          $feature = array(
            'type' => 'Feature',
            'geometry' => $geom->out('json', TRUE),
          );
          if ($baloon_content) {
            $feature['properties']['balloonContent'] = $baloon_content;
          }
          if ($hint_content) {
            $feature['properties']['hintContent'] = $hint_content;
          }
          if ($icon_content) {
            $feature['properties']['iconContent'] = $icon_content;
            $feature['options']['preset'] = 'islands#blueStretchyIcon';
          }
          if ($preset) {
            $feature['options']['preset'] = $preset;
          }
          if ($object_options) {
            $feature_options = isset($feature['options']) ? $feature['options'] : array();
            $feature['options'] = $object_options + $feature_options;
          }
          $features[] = $feature;
        }
      }
    }
    unset($this->view->row_index);

    return array(
      '#theme'              => 'geofield_ymap',
      '#map_objects'        => $features ? array('type' => 'FeatureCollection', 'features' => $features) : array(),
      '#map_type'           => $this->options['map_type'],
      '#map_center'         => $this->options['map_center'],
      '#map_zoom'           => $this->options['map_zoom'],
      '#map_auto_centering' => $this->options['map_auto_centering'],
      '#map_auto_zooming'   => $this->options['map_auto_zooming'],
      '#map_clusterize'     => $this->options['map_clusterize'],
      '#map_object_preset'  => $this->options['map_object_preset'],
      '#map_controls'       => $this->options['map_controls'],
      '#id'                 => drupal_html_id('geofield-ymap-' . $this->view->name . '-' . $this->view->current_display),
    );
  }

  /**
   * Take a value and apply token replacement logic to it.
   */
  function safe_tokenize_value($value, $row_index) {
    if (strpos($value, '[') !== FALSE || strpos($value, '!') !== FALSE || strpos($value, '%') !== FALSE) {
      $tokens = isset($this->row_tokens[$row_index]) ? $this->row_tokens[$row_index] : array();
      if (!empty($this->view->build_info['substitutions'])) {
        $tokens += $this->view->build_info['substitutions'];
      }

      if ($tokens) {
        foreach ($tokens as &$token) {
          $token = drupal_substr(json_encode($token), 1, -1);
        }
        $value = strtr($value, $tokens);
      }
    }

    return $value;
  }
}
