<?php
/**
 * @file
 * Provides a remote stream wrapper and filefield source integration.
 */

/**
 * Implements hook_filefield_sources_info().
 */
function od_dataset_filefield_sources_info() {
  $source = remote_file_source_filefield_sources_info();
  $source['remotefile']['value'] = 'od_dataset_filefield_source_remotefile_value';

  return $source;
}

/**
 * Implements hook_module_implements_alter()
 */
function od_dataset_module_implements_alter(&$implementations, $hook) {
  //Убиваем имплементацию hook_node_view() модуля remote_file_source
  if ($hook == 'filefield_sources_info' && isset($implementations['remote_file_source'])) {
    unset($implementations['remote_file_source']);
  }
}

/**
 * A #filefield_value_callback function.
 */
function od_dataset_filefield_source_remotefile_value($element, &$item) {
  if (isset($item['filefield_remotefile']['url']) && drupal_strlen($item['filefield_remotefile']['url']) > 0 && $item['filefield_remotefile']['url'] != REMOTE_FILE_SOURCE_HINT_TEXT) {
    $value = $item['filefield_remotefile']['url'];
    if (!valid_url($value, TRUE)) {
      form_error($element, t('Invalid Remote File URL.'));
      return;
    }
    elseif (!file_stream_wrapper_valid_scheme(file_uri_scheme($value))) {
      // Check that the scheme is supported.
      form_error($element, t('Remote File URLs with the %scheme scheme are not supported.', array('%scheme' => $scheme)));
      return;
    }
    else {
      od_common_module('tools.http_request2');
      $http = od_common_tools_http_request2();
      // Check that the file exists.
      $http->setUrl($value);
      $http->setMethod('PARTIAL_GET');
      $http->setConfig('store_body', false);
      try {
        // Try to make a request
        $request = $http->send();
      }
      catch (Exception $e) {
        // Silently log exception to watchdog
        watchdog_exception('od_dataset', $e);
        $request = FALSE;
      }

      // If an error occurred or file not found then set an error on a form.
      if ($request === FALSE || (($status = $request->getStatus()) && (!$status || $status != '200'))) {
        form_error($element, t('Unable to fetch file from Remote File URL %url (error @code: %error).', array('%url' => $value, '@code' => $status, '%error' => $request->error)));
        return;
      }
    }

    try {
      $file = remote_stream_wrapper_file_load_by_uri($value);
      if (!$file) {
        $file = remote_stream_wrapper_file_create_by_uri($value);
        $file->status = FALSE;
        file_save($file);
      }

      // Clean filename
      od_dataset_file_widget_clean_filename_validator($file, TRUE);
    }
    catch (Exception $e) {
      form_set_error('url', $e->getMessage());
      return;
    }

    if (empty($file->fid)) {
      form_set_error($element, t('Unable to add file from URL %file.', array('%file' => $value)));
      return;
    }

    // Run all the normal validations, minus file size restrictions.
    if (isset($element['#upload_validators']['file_validate_size'])) {
      unset($element['#upload_validators']['file_validate_size']);
    }

    if (od_dataset_filefield_sources_element_validate($element, (object) $file)) {

      $item = array_merge($item, (array) $file);
    }
  }
}


function od_dataset_file_widget_clean_filename_validator(stdClass $file, $save = FALSE) {
  if (isset($file->filename)) {
    $file->filename = preg_replace('/\?.*$/i', '', $file->filename);
  }

  if ($save && isset($file->fid)) {
    file_save($file);
  }
}

/**
 * Validate a file based on the $element['#upload_validators'] property.
 */
function od_dataset_filefield_sources_element_validate($element, $file) {
  $validators = $element['#upload_validators'];
  $errors = array();

  foreach ($validators as $function => $args) {
    // Add the $file variable to the list of arguments and pass it by
    // reference (required for PHP 5.3 and higher).
    array_unshift($args, NULL);
    $args[0] = &$file;
    $errors = array_merge($errors, call_user_func_array($function, $args));
  }


  // Check for validation errors.
  if (!empty($errors)) {
    $message = t('The selected file %name could not be referenced.', array('%name' => $file->filename));
    if (count($errors) > 1) {
      $message .= '<ul><li>' . implode('</li><li>', $errors) . '</li></ul>';
    }
    else {
      $message .= ' ' . array_pop($errors);
    }
    form_error($element, $message);
    return 0;
  }

  return 1;
}