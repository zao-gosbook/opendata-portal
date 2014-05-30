<?php

/**
 * @file
 * Contains the administrative functions of the autoupload module.
 *
 * This file is included by the autoupload module, and includes the
 * settings form.
 */

/**
 * Form builder for the autoupload settings page.
 */
function autoupload_admin_form($form, $form_state) {
  $settings_predefined = variable_get('autoupload_predefined');

  $form['predefined'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Predefined File Types'),
    '#collapsible' => TRUE,
  );
  $form['predefined']['desc'] = array(
    '#markup' => t('Choose the type(s) of file fields where you would like to use Auto Upload.'),
  );
  $form['predefined']['managed_file'] = array(
    '#type' => 'checkbox',
    '#title' => t('Managed'),
    '#description' => t('Drupal core managed file fields.'),
    '#default_value' => $settings_predefined['managed_file'],
  );

  $media_disabled = module_exists('media') ? FALSE : TRUE;
  $form['predefined']['media'] = array(
    '#type' => 'checkbox',
    '#title' => t('Media'),
    '#description' => t('Auto upload files using the Media module media file selector.'),
    '#disabled' => $media_disabled,
    '#default_value' => $media_disabled ? 0 : $settings_predefined['media'],
  );
  $form['predefined']['media_library'] = array(
    '#type' => 'checkbox',
    '#title' => t('Media Library'),
    '#description' => t('Auto select media files from the media library.'),
    '#disabled' => $media_disabled,
    '#default_value' => $media_disabled ? 0 : $settings_predefined['media_library'],
  );

  $form['custom'] = array(
    '#type' => 'fieldset',
    '#title' => t('Custom File Types'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['custom']['desc'] = array(
    '#markup' => t('Enter your own custom configurations for fields you would like to use Auto Upload. All selectors should be relative to the context (container) element.'),
  );
  $form['custom']['custom_type'] = array(
    '#type' => 'container',
    '#attributes' => array('id' => 'autoupload-custom-wrapper'),
    '#tree' => TRUE,
    '#theme' => 'autoupload_custom',
  );

  $settings_userdefined = variable_get('autoupload_userdefined');

  // Get count of how many custom types there are.
  $count = isset($form_state['custom_count']) ? $form_state['custom_count'] : count($settings_userdefined);
  $index = 0;
  foreach ((array) $settings_userdefined as $key => $value) {
    $form['custom']['custom_type'][$index] = autoupload_custom_combo($index, TRUE, $key, $value);
    $index++;
  }

  $settings_userdefined_disabled = variable_get('autoupload_userdefined_disabled');
  $count += count($settings_userdefined_disabled);
  foreach ((array) $settings_userdefined_disabled as $key => $value) {
    $form['custom']['custom_type'][$index] = autoupload_custom_combo($index, FALSE, $key, $value);
    $index++;
  }

  $count++;
  for ($index; $index < $count; $index++) {
    $form['custom']['custom_type'][$index] = autoupload_custom_combo($index);
  }

  $form['custom']['custom_more'] = array(
    '#type' => 'submit',
    '#value' => t('Add another'),
    '#description' => t('Click to add more custom configurations.'),
    '#weight' => 2,
    '#submit' => array('autoupload_custom_more_submit'),
    '#ajax' => array(
      'callback' => 'autoupload_custom_ajax',
      'wrapper' => 'autoupload-custom-wrapper',
      'method' => 'replace',
      'effect' => 'none',
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * Function to return a textbox combo form.
 */
function autoupload_custom_combo($delta = 0, $enabled = NULL, $name = '', $settings = array()) {
  $form['#tree'] = TRUE;
  $form['enabled'] = array(
    '#type' => 'checkbox',
    '#default_value' => $enabled === NULL ? TRUE : $enabled,
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $name,
  );
  $form['context'] = array(
    '#type' => 'textfield',
    '#title' => t('Context'),
    '#description' => t('Selector for the field container.'),
    '#default_value' => isset($settings['context']) ? $settings['context'] : '',
  );
  $form['file_input'] = array(
    '#type' => 'textfield',
    '#title' => t('File Input Selector'),
    '#description' => t('Selector for the file input.'),
    '#default_value' => isset($settings['file_input']) ? $settings['file_input'] : '',
  );
  $form['file_event'] = array(
    '#type' => 'textfield',
    '#title' => t('File Event'),
    '#description' => t('Event on the file input that should trigger the submit event.'),
    '#default_value' => isset($settings['file_event']) ? $settings['file_event'] : '',
  );
  $form['submit_input'] = array(
    '#type' => 'textfield',
    '#title' => t('Submit Input Selector'),
    '#description' => t('Selector for the submit input.'),
    '#default_value' => isset($settings['submit_input']) ? $settings['submit_input'] : '',
  );
  $form['submit_event'] = array(
    '#type' => 'textfield',
    '#title' => t('Submit Event'),
    '#description' => t('Event on the submit input that should be triggered to start the upload.'),
    '#default_value' => isset($settings['submit_event']) ? $settings['submit_event'] : '',
  );
  $form['error'] = array(
    '#type' => 'textfield',
    '#title' => t('Error Element Selector'),
    '#description' => t('Selector for error element. Before upload, a check is done. If element is found, submit will not trigger.'),
    '#default_value' => isset($settings['error']) ? $settings['error'] : '',
  );
  $form['error_remove'] = array(
    '#type' => 'select',
    '#title' => t('Error removal handling'),
    '#description' => t('Choose the type of removal for the element that matches the selector above.'),
    '#default_value' => isset($settings['error_remove']) ? $settings['error_remove'] : '',
    '#options' => array(
      '' => t('None; error removal is handled already'),
      'id' => t('Remove the ID'),
      'class' => t('Remove the class'),
      'element' => t('Remove the entire element'),
    ),
  );
  $form['delete'] = array(
    '#type' => 'checkbox',
    '#default_value' => FALSE,
  );
  return $form;
}

/**
 * Theme the custom field type inputs.
 */
function theme_autoupload_custom($variables) {
  $form = $variables['form'];
  $rows = array();
  foreach (element_children($form) as $key) {
    // Build the table row.
    $rows[$key] = array(
      'data' => array(
        array(
          'data' => drupal_render($form[$key]['enabled']),
          'class' => 'autoupload-custom-enabled',
        ),
        array(
          'data' => drupal_render($form[$key]['name']),
          'class' => 'autoupload-custom-name',
        ),
        array(
          'data' =>
            drupal_render($form[$key]['context']) .
            drupal_render($form[$key]['file_input']) .
            drupal_render($form[$key]['file_event']) .
            drupal_render($form[$key]['submit_input']) .
            drupal_render($form[$key]['submit_event']) .
            drupal_render($form[$key]['error']) .
            drupal_render($form[$key]['error_remove']),
          'class' => 'autoupload-custom-configuration',
        ),
        array(
          'data' => drupal_render($form[$key]['delete']),
          'class' => 'autoupload-custom-delete',
        ),
      ),
    );
    // Add attributes from the element to the row, such as ahah class.
    if (array_key_exists('#attributes', $form[$key])) {
      $rows[$key] = array_merge($rows[$key], $form[$key]['#attributes']);
    }
  }
  $header = array(
    array('data' => t('Enabled'), 'title' => t('Flag whether Auto Upload should be active for this field type.')),
    array('data' => t('Name'), 'title' => t('Give the field type a name.')),
    array('data' => t('Configuration'), 'title' => t('Enter configuration details for this field type.')),
    array('data' => t('Delete'), 'title' => t('Delete the configuration.')),
  );

  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
  ));
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Menu callback to display a new custom configuration combo input.
 */
function autoupload_custom_ajax($form, &$form_state) {
  return $form['custom']['custom_type'];
}

/**
 * Submit handler for the "Add another" button on the autoupload settings form.
 */
function autoupload_custom_more_submit($form, &$form_state) {
  $form_state['custom_count'] = count($form_state['values']['custom_type']);
  $form_state['rebuild'] = TRUE;
}

/**
 * Validation handler for autoupload settings form.
 */
function autoupload_admin_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $names = array();
  foreach ($values['custom_type'] as $key => $value) {
    if ($value['name'] == '' && $value['context'] == '' && $value['file_input'] == '' && $value['file_event'] == '' && $value['submit_input'] == '' && $value['submit_event'] == '' && $value['error'] == '') {
      continue;
    }
    // Make sure machine names are unique.
    if (in_array($value['name'], $names)) {
      form_set_error('custom_type][' . $key . '][name', t('Name %name is already used. Please enter a unique name for each configuration.', array('%name' => $value['name'])));
    }
    else {
      $names[] = $value['name'];
    }

    // Make sure names are only letters, numbers, and underscores.
    if (preg_match('/[^a-zA-Z0-9_]/', $value['name']) !== 0) {
      form_set_error('custom_type][' . $key . '][name', t('Name %name is invalid. Only letters, numbers, and underscores allowed.', array('%name' => $value['name'])));
    }

    if ($value['name'] == '') {
      form_set_error('custom_type][' . $key . '][name', t('Name cannot be empty.'));
    }
    if ($value['context'] == '') {
      form_set_error('custom_type][' . $key . '][context', t('Context cannot be empty.'));
    }
    if ($value['file_input'] == '') {
      form_set_error('custom_type][' . $key . '][file_input', t('File input selector cannot be empty.'));
    }
    if ($value['file_event'] == '') {
      form_set_error('custom_type][' . $key . '][file_event', t('File event cannot be empty.'));
    }
    if ($value['submit_input'] == '') {
      form_set_error('custom_type][' . $key . '][submit_input', t('Submit input selector cannot be empty.'));
    }
    if ($value['submit_event'] == '') {
      form_set_error('custom_type][' . $key . '][submit_event', t('Submit event cannot be empty.'));
    }
  }
}

/**
 * Submit handler for autoupload settings form.
 */
function autoupload_admin_form_submit($form, &$form_state) {
  $settings_predefined = $settings_userdefined = $settings_userdefined_disabled = array();
  $values = $form_state['values'];

  $predefined_types = _autoupload_get_predefined();
  foreach ($predefined_types as $type => $type_data) {
    $settings_predefined[$type] = $values[$type];
  }

  foreach ($values['custom_type'] as $value) {
    if ($value['name'] == '' || $value['delete'] == TRUE) {
      continue;
    }
    $enabled = $value['enabled'];
    $name = $value['name'];
    unset($value['name'], $value['enabled']);
    if ($enabled) {
      $settings_userdefined[$name] = $value;
    }
    else {
      $settings_userdefined_disabled[$name] = $value;
    }
  }

  variable_set('autoupload_userdefined', $settings_userdefined);
  variable_set('autoupload_userdefined_disabled', $settings_userdefined_disabled);
  variable_set('autoupload_predefined', $settings_predefined);
  drupal_set_message(t('The configuration options have been saved.'));
}
