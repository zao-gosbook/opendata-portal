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
function od_file_process_rules_action_info() {
  $action = array(
    'od_file_process_rule_callback' => array(
      'label' => t('Process opendata file'),
      'group' => t('Opendata process'),
      'arguments' => array(
        'file_2process' => array(
          'type' => 'unknown',
          'label' => t('File to process'),
        ),
        'node_2attach' => array(
          'type' => 'node',
          'label' => t('Node to process'),
        ),
        'field_2attach_data' => array(
          'type' => 'text',
          'label' => t('Field to save data'),
        ),
        'field_2attach_structure' => array(
          'type' => 'text',
          'label' => t('Field to save data structure'),
        ),
      ),
      'provides' => array(
        'saved_node' => array(
          'type' => 'node',
          'label' => t('Saved node'),
        ),
      ),
    ),
    'od_file_process_rule_callback_get_file' => array(
      'label' => t('Process opendata file (returns new file)'),
      'group' => t('Opendata process'),
      'arguments' => array(
        'file_2process' => array(
          'type' => 'unknown',
          'label' => t('File to process'),
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
        'created_file' => array(
          'type' => 'file',
          'label' => t('Created file'),
        ),
      ),
    ),
    'od_file_process_rule_callback_get_files' => array(
      'label' => t('Process opendata file (returns list of files)'),
      'group' => t('Opendata process'),
      'arguments' => array(
        'file_2process' => array(
          'type' => 'unknown',
          'label' => t('File to process'),
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
        'created_files' => array(
          'type' => 'list<file>',
          'label' => t('Created files'),
        ),
        'created_structure' => array(
          'type' => 'file',
          'label' => t('Created structure file'),
        ),
        'created_structure_media' => array(
          'type' => 'field_item_file',
          'label' => t('Created structure file (field_item_file)'),
        ),
        'structure_meta' => array(
          'type' => 'universal_data_storage',
          'label' => t('Structure record as universal_data_storage entity')
        ),
      ),
      'base' => 'od_file_process_rule_callback_get_files',
    ),
    'od_copy_recline_visualization_data' => array(
      'label' => t('Copy recline visualization data to a file'),
      'group' => t('Opendata process'),
      'arguments' => array(
        'data' => array(
          'type' => 'list<text>',
          'label' => t('Visualization data'),
        ),
        'entity' => array(
          'type' => 'entity',
          'label' => t('An entity that\'s field will be changed'),
        ),
        'entity_type' => array(
          'type' => 'text',
          'label' => t('A type of an entity provided above'),
        ),
        'field_name' => array(
          'type' => 'text',
          'label' => t('Field name that represents recline file')
        ),
      ),
      'base' => 'od_file_process_rule_callback_od_copy_recline_visualization_data',
    ),
  );


  if (module_exists('recline')) {
    $action['od_file_process_rule_callback']['arguments']['recline_additional_info'] = array(
      'type' => 'unknown',
      'label' => t('Recline additional info'),
    );
  }
  return $action;
}


/**
 * Rule action
 * @deprecated
 */
function od_file_process_rule_callback($file_2process, $node_2attach, $field_2attach_data, $field_2attach_structure, $recline_additional_info = array()) {
  od_file_process_prepare_playground();
  $file = file_load($file_2process['fid']);

  $file_2process['file_data']['convert_to'] = 'csv';
  if (in_array($file->filemime, od_file_preprocess_table_mimes())) { //} && !empty($file_2process['file_data'])) {
    if (isset($file_2process['file_data']['convert_to'])) {

      $path = drupal_realpath($file->uri);

      if ($file->filemime == 'text/csv') {
        $data = od_file_preprocess_parse_csv($path);
      }
      else {
        module_load_include('inc', 'phpexcel');
        $data = od_file_preprocess_excel_import($path, FALSE);
      }

      $data = $data[0];     // first worksheet
      array_shift($data);   // skip headers row

/*
      if (!isset($structure['process_2nd_row']) || !$structure['process_2nd_row']) {
        array_shift($data); // skip second row if it contains columns descriptions
      }
*/
      
      switch ($file_2process['file_data']['convert_to']) {
        case 'csv':
            $ext_data = 'csv';
            $ext_struct = 'csv';
            $processed = od_file_process_2csv($data, $file_2process['file_data']);
          break;
        case 'xml':
            $ext_data = 'xml';
            $ext_struct = 'xsd';
            $processed = od_file_process_2xml($data, $file_2process['file_data']);
          break;
        default:
            return array(
              'saved_node' => $node_2attach,
            );
          break;
      }
    }
  } elseif (in_array($file->filemime, od_file_preprocess_graph_mimes())) {
    if (module_exists('recline')) {
      foreach ($recline_additional_info as $recline_info) {
        $file->view[$recline_info] = '1';
      }
    }
    $field_lang = field_language('node', $node_2attach, $field_2attach_data);
    $node_2attach->{$field_2attach_data}[$field_lang][0] = (array) $file;
    node_save($node_2attach);
    return array(
      'saved_node' => $node_2attach,
    );
  }
  else {
    return array(
      'saved_node' => $node_2attach,
    );
  }
  
  if (empty($processed['structure']) || empty($processed['data'])) {
    return array(
      'saved_node' => $node_2attach,
    );
  }
  
  // save files and attach it to node fields
  $file_info = pathinfo($file->uri);
  if (mb_substr($file_info['dirname'], -1) == ':') {
    $file_info['dirname'] .= '/';
  }
  
  // save structure file
  $filename = $file_info['dirname'] . '/' . $file_info['filename'] . '-structure.' . $ext_struct;
  $file_structure = file_save_data($processed['structure'], $filename);
  if (module_exists('filefield_sources')) {
    $file_structure->display = 1; 
    // display property not availible
  }
  $field_lang = field_language('node', $node_2attach, $field_2attach_structure);
  $node_2attach->{$field_2attach_structure}[$field_lang][0] = (array) $file_structure;

  // save data file
  $filename = $file_info['dirname'] . '/' . $file_info['filename'] . '.' . $ext_data;
  $file_data = file_save_data($processed['data'], $filename);
  if (module_exists('recline')) {
    foreach ($recline_additional_info as $recline_info) {
      $file_data->view[$recline_info] = '1';
    }
  }
  $field_lang = field_language('node', $node_2attach, $field_2attach_data);
  $node_2attach->{$field_2attach_data}[$field_lang][0] = (array) $file_data;

  node_save($node_2attach);

  return array(
    'saved_node' => $node_2attach,
  );
}

/**
 * Rule action
 * @deprecated
 */
function od_file_process_rule_callback_get_file($file_2process,  $can_expire) {
  $salt = substr(md5(time(). microtime()), 0, 8);
  $file = file_load($file_2process['fid']);
  if (in_array($file->filemime, od_file_preprocess_table_mimes()) && !empty($file_2process['file_data'])) {
    if (isset($file_2process['file_data']['convert_to'])) {
      $path = drupal_realpath($file->uri);

      if ($file->filemime == 'text/csv') {
        $data = od_file_preprocess_parse_csv($path);
      }
      else {
        module_load_include('inc', 'phpexcel');
        $data = od_file_preprocess_excel_import($path, FALSE);
      }

      $data = $data[0];     // first worksheet
      array_shift($data);   // skip headers row
      switch ($file_2process['file_data']['convert_to']) {
        case 'csv':
          $ext_data = 'csv';
          $ext_struct = 'csv';
          $processed = od_file_process_2csv($data, $file_2process['file_data']);
          break;
        case 'xml':
          $ext_data = 'xml';
          $ext_struct = 'xsd';
          $processed = od_file_process_2xml($data, $file_2process['file_data']);
          break;
      }
    }
  }

  $file_data = $file_structure = NULL;
  if (isset($ext_data) && isset($ext_struct)) {
    // save files and attach it to node fields
    $file_info = pathinfo($file->uri);
    if (mb_substr($file_info['dirname'], -1) == ':') {
      $file_info['dirname'] .= '/';
    }
    $file_info['filename'] = "{$salt}_{$file_info['filename']}";

    // save structure file
    $filename = $file_info['dirname'] . '/' . $file_info['filename'] . '-structure.' . $ext_struct;
    $file_structure = file_save_data($processed['structure'], $filename);

    // save data file
    $filename = $file_info['dirname'] . '/' . $file_info['filename'] . '.' . $ext_data;
    $file_data = file_save_data($processed['data'], $filename);

    if ($can_expire) {
      //Make files not permanent
      foreach (array($file_structure, $file_data) as $file) {
        $file->status = 0;
        file_save($file);
      }
    }
  }

  return array(
    'created_file' => $file_data,
    'created_structure' => $file_structure,
  );
}


/**
 * Rule action
 */
function od_file_process_rule_callback_get_files($file_2process,  $can_expire) {
  $salt = substr(md5(time(). microtime()), 0, 8);
  $file = file_load($file_2process['fid']);

  $file_structure = $files_created = $structure_meta = NULL;
  if ($file->filemime == 'application/xml') {
    $files_created[] = $file;
  }
  elseif (in_array($file->filemime, od_file_preprocess_table_mimes()) && !empty($file_2process['file_data'])) {
    if (isset($file_2process['file_data']['convert_to'])) {
      $path = drupal_realpath($file->uri);
      $file_info = pathinfo($file->uri);
      if (mb_substr($file_info['dirname'], -1) == ':') {
        $file_info['dirname'] .= '/';
      }

      $file_info['filename'] = "{$salt}_{$file_info['filename']}";

      if ($file->filemime == 'text/csv') {
        $data_whole = od_file_preprocess_parse_csv($path);
      }
      elseif ($file->filemime == 'application/zip') {
        $data_whole = od_file_preprocess_parse_zip($path);
      }
      else {
        module_load_include('inc', 'phpexcel');
        $data_whole = od_file_preprocess_excel_import($path, FALSE);
      }

      $files_created = array();
      foreach ($data_whole as $list_index => &$data) {
        $processed = NULL;
        array_shift($data);   // skip headers row
        switch ($file_2process['file_data']['convert_to']) {
          case 'csv':
            $ext_data = 'csv';
            $ext_struct = 'csv';
            $processed = od_file_process_2csv($data, $file_2process['file_data']);
            break;
          case 'xml':
            $ext_data = 'xml';
            $ext_struct = 'xsd';
            $processed = od_file_process_2xml($data, $file_2process['file_data']);
            break;
        }

        // Try to save file
        if (isset($ext_data) && isset($ext_struct)) {
          // Create structure file only once using first list
          if ($file_structure === NULL && isset($processed['structure'])) {
            // save structure file
            $filename = $file_info['dirname'] . '/' . $file_info['filename'] . '-structure.' . $ext_struct;
            $file_structure = file_save_data($processed['structure'], $filename);
            $structure_meta = od_file_process_structure_record($file_2process['file_data'], $file_structure->fid);
          }

          // save data file
          $filename = $file_info['dirname'] . '/' . $file_info['filename'] . '.' . $ext_data;
          $files_created[$list_index] = file_save_data($processed['data'], $filename);
        }
      }

      //@fixme: Enable this.
//      if ($can_expire) {
//        //Make files not permanent
//        foreach ((array($file_structure) + $files_created) as $file) {
//          $file->status = 0;
//          file_save($file);
//        }
//      }
    }
  }

  return array(
    'created_files' => $files_created,
    'created_structure' => $file_structure,
    'created_structure_media' => (array) $file_structure + array(
      'description' => $file_structure->filename,
      'display' => TRUE,
    ),
    'structure_meta' => $structure_meta,
  );
}

function od_file_process_rule_callback_od_copy_recline_visualization_data($data, $entity, $entity_type, $field_name) {
  try {
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $entity_full = $wrapper->value();
    if (($pi = $wrapper->{$field_name}->getPropertyInfo()) && is_array($data) && !empty($data)) {
      $langcode = $entity->{$field_name}->getPropertyLanguage();
      $langcode = !$langcode ? LANGUAGE_NONE : $langcode;
      foreach ($data as $visual_type) {
        foreach ($entity_full->{$field_name}[$langcode] as &$_item) {
          $_item[$visual_type] = 1;
        }
      }
    }
  }
  catch (Exception $e) {
    watchdog_exception('od_file_process', $e);
    return NULL;
  }
}