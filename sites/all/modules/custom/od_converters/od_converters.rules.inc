<?php

/**
 * defined into od_file_preprocess module:
 *   CSV_ENCLOSURE
 *   CSV_DELIMETER
 *   CRLF
 *   od_file_preprocess_structure_headers()
 *   od_file_preprocess_table_mimes()
 */


/**
 * Implements hook_rules_action_info().
 */
function od_converters_rules_action_info() {
  $action = array(
    'od_converters_rule_callback_convert_format_zip' => array(
      'label' => t('Convert formats for mulpitple files in zip'),
      'group' => t('Opendata Converters'),
      'arguments' => array(
        'file' => array(
          'type' => 'unknown',
          'label' => t('File to process'),
        ),
        'fmt_source' => array(
          'type' => 'text',
          'label' => t('Source format to convert from'),
          'options list' => 'od_converters_availaible_formats_list',
        ),
        'fmt_target' => array(
          'type' => 'text',
          'label' => t('Target format to convert to'),
          'options list' => 'od_converters_availaible_formats_list',
        ),
        'destination_path' => array(
          'type' => 'text',
          'label' => t('Path where to store output file'),
        ),
        'can_expire' => array(
          'type' => 'boolean',
          'label' => t('File will be deleted by cron after @time', array(
            '@time' => format_plural((floor(DRUPAL_MAXIMUM_TEMP_FILE_AGE/3600)) % 24, '1 hour', '@count hours')
              . ' '. t('and'). ' '. format_plural((floor(DRUPAL_MAXIMUM_TEMP_FILE_AGE/60)) % 60, '1 minute', '@count minutes')
              . ' '. t('and'). ' '. format_plural(DRUPAL_MAXIMUM_TEMP_FILE_AGE % 60, '1 second', '@count seconds')
            )
          ),
          'default' => FALSE,
        ),
      ),
      'provides' => array(
        'formatted_file' => array(
          'type' => 'file',
          'label' => t('Formatted file'),
        ),
      ),
      'base' => 'od_converters_rule_callback_convert_format_zip',
    ),
    'od_converters_rule_callback_convert_format' => array(
      'label' => t('Convert formats for files'),
      'group' => t('Opendata Converters'),
      'arguments' => array(
        'file' => array(
          'type' => 'unknown',
          'label' => t('File to process'),
        ),
        'fmt_source' => array(
          'type' => 'text',
          'label' => t('Source format to convert from'),
          'options list' => 'od_converters_availaible_formats_list',
        ),
        'fmt_target' => array(
          'type' => 'text',
          'label' => t('Target format to convert to'),
          'options list' => 'od_converters_availaible_formats_list',
        ),
        'destination_path' => array(
          'type' => 'text',
          'label' => t('Path where to store output file'),
        ),
        'can_expire' => array(
          'type' => 'boolean',
          'label' => t('File will be deleted by cron after @time', array(
              '@time' => format_plural((floor(DRUPAL_MAXIMUM_TEMP_FILE_AGE/3600)) % 24, '1 hour', '@count hours')
                . ' '. t('and'). ' '. format_plural((floor(DRUPAL_MAXIMUM_TEMP_FILE_AGE/60)) % 60, '1 minute', '@count minutes')
                . ' '. t('and'). ' '. format_plural(DRUPAL_MAXIMUM_TEMP_FILE_AGE % 60, '1 second', '@count seconds')
            )
          ),
          'default' => FALSE,
        ),
      ),
      'provides' => array(
        'formatted_file' => array(
          'type' => 'file',
          'label' => t('Formatted file'),
        ),
      ),
      'base' => 'od_converters_rule_callback_convert_format',
    ),
  );

  return $action;
}



/**
 * Rule action callback :-)
 */
function od_converters_rule_callback_convert_format($file, $fmt_source, $fmt_target, $destination_path, $can_expire) {
  $formatted_file = NULL;
  $converter = od_converter_object();
  od_common_module('core');
  $fmt = od_converter_object()->getFormat($fmt_target);
  $tempFiledir = od_common_tmpfilename('temporary:/', 'od_converters');
  $tempfile = $tempFiledir. '/' . $fmt->normalizeFilename($file->filename);
  @mkdir($tempFiledir);
  if ($converter->convertFile($file->uri, $fmt_source, $tempfile, $fmt_target)) {
    od_common_module('file');
    $destination = od_common_tmpfilename($destination_path);
    @mkdir($destination);
    if ($file_object = od_common_file_save_data_by_path($tempfile, $destination, FILE_EXISTS_RENAME, $can_expire)) {
      $formatted_file = $file_object;
    }

    unlink($tempfile);
  }

  rmdir($tempFiledir);
  return array(
    'formatted_file' => $formatted_file,
  );
}

/**
 * Rule action callback :-)
 */
function od_converters_rule_callback_convert_format_zip($file, $fmt_source, $fmt_target, $destination_path, $can_expire) {
  $formatted_file = NULL;
  od_common_module('core');
  $tempFiledir = od_common_tmpfilename('temporary:/', 'od_converters');
  $fmt = od_converter_object()->getFormat('zip');
  $tempfile = $tempFiledir. '/' . $fmt->normalizeFilename($file->filename);
  @mkdir($tempFiledir);
  if (od_converter_convert_zip($file->uri, $fmt_source, $tempfile, $fmt_target)) {
    $destination = od_common_tmpfilename($destination_path);
    @mkdir($destination);
    if ($file_object = od_common_file_save_data_by_path($tempfile, $destination, FILE_EXISTS_RENAME, $can_expire)) {
      $formatted_file = $file_object;
    }

    unlink($tempfile);
  }

  rmdir($tempFiledir);
  return array(
    'formatted_file' => $formatted_file,
  );
}