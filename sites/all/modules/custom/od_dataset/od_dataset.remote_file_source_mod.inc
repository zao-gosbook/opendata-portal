<?php
/**
 * @file
 * Provides a remote stream wrapper and filefield source integration.
 */

define('REMOTE_FILE_SOURCE_HINT_TEXT', 'http://example.com/files/file.zip');

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
      //$request = drupal_http_request($value, array('method' => 'HEAD'));
      $http->setUrl($value);
      $http->setMethod(HTTP_Request2::METHOD_HEAD);
      $http->setConfig('store_body', false);
      $request = $http->send();
      if (($status = $request->getStatus()) && (!$status || $status != '200')) {
        form_error($element, t('Unable to fetch file from Remote File URL %url (error @code: %error).', array('%url' => $value, '@code' => $status, '%error' => $request->error)));
        return;
      }
    }

    try {
      $file = remote_stream_wrapper_file_load_by_uri($value);
      if (!$file) {
        $file = remote_stream_wrapper_file_create_by_uri($value);
        $file->status = FALSE;

        // Clean filename
        od_dataset_file_widget_clean_filename_validator($file);
        file_save($file);
      }
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

    if (filefield_sources_element_validate($element, (object) $file)) {

      $item = array_merge($item, (array) $file);
    }
  }
}


function od_dataset_file_widget_clean_filename_validator(stdClass $file) {
  if (isset($file->fid)) {
    $file->filename = preg_replace('/\?.*$/i', '', $file->filename);
  }
}