<?php

/**
 * Create dataset for organization by identifier for.
 */
function _od_import_create_dataset($identifier, $org_id) {
  $dataset_node = new stdClass();

  $dataset_node->type = 'dataset';
  node_object_prepare($dataset_node);
  $dataset_node->language = LANGUAGE_NONE;
  $dataset_node->uid = OD_COMMON_IMPORT_USER_ID;
  $dataset_node->promote = NODE_NOT_PROMOTED;
  $dataset_node->comment = COMMENT_NODE_OPEN;
  $dataset_node->status = NODE_NOT_PUBLISHED;

  // Meta identifier.
  $dataset_node->{OD_COMMON_FIELD_DATASET_IDENTIFIER}[LANGUAGE_NONE][0] = array(
    'value' => $identifier,
    'format' => NULL,
    'safe_value' => $identifier,
  );

  // Meta owner.
  $dataset_node->{OD_COMMON_FIELD_DATASET_OWNER}[LANGUAGE_NONE][0] = array(
    'target_id' => $org_id,
  );

  // Set opendata log variables.
  $dataset_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);

  node_save($dataset_node);

  return $dataset_node;
}

/**
 * Update dataset with meta values.
 */
function _od_import_update_dataset($dataset_node, $meta, $org_id, &$dataset_updated, &$resource_updated) {
  // Init messages variable.
  $messages = array();

  // Set dataset title field.
  _od_import_dataset_set_title($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset description field.
  _od_import_dataset_set_description($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset created field.
  _od_import_dataset_set_created($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset updated field.
  _od_import_dataset_set_updated($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset provenance field.
  _od_import_dataset_set_provenance($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset subject field.
  _od_import_dataset_set_subject($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset publisher name field.
  _od_import_dataset_set_publisher_name($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset publisher phone field.
  _od_import_dataset_set_publisher_phone($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset publisher email field.
  _od_import_dataset_set_publisher_mbox($dataset_node, $meta, $messages, $dataset_updated);
  // Set dataset resource.
  _od_import_dataset_set_resource($dataset_node, $meta, $messages, $dataset_updated, $resource_updated);

  // Set opendata log variables if log has not disabled.
  if ($dataset_node->od_log !== FALSE) {
    $dataset_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
  }

  // Update dataset.
  node_save($dataset_node);

  // Set warning messages.
  foreach ($messages as $message) {
    od_log($message, OD_LOG_IMPORTANCE_WARNING, OD_LOG_EVENT_IMPORT_DATA, $org_id, $dataset_node->nid);
  }

  return $dataset_node;
}

/**
 * Set dataset title field.
 */
function _od_import_dataset_set_title($dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->title;

  if (isset($meta['title'])) {
    // Get the new field value.
    $new_field_value = $meta['title'];

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = '';

    // Set warning message.
    $messages[] = 'Не заполнено поле "Наименование набора данных".';
  }
}

/**
 * Set dataset description field.
 */
function _od_import_dataset_set_description($dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_DESCRIPTION};

  if (isset($meta['description'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array('0' => array(
      'value' => $meta['description'],
      'summary' => '',
      'format' => 'full_html',
      'safe_value' => $meta['description'],
      'safe_summary' => '',
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Описание набора данных".';
  }
}

/**
 * Set dataset created field.
 */
function _od_import_dataset_set_created(&$dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_CREATED};

  if (isset($meta['created'])) {
    // Get created in unix timestamp format.
    $created = od_import_format_date_unix_timestamp($meta['created']);

    if ($created) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'value' => $created,
        'timezone' => 'Europe/Moscow',
        'timezone_db' => 'Europe/Moscow',
        'date_type' => 'datestamp',
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $dataset_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Дата первой публикации набора данных".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата первой публикации набора данных".';
  }
}

/**
 * Set dataset updated field.
 */
function _od_import_dataset_set_updated(&$dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_UPDATED};

  if (isset($meta['data'][0]['created'])) {
    // Get created in unix timestamp format.
    $created = od_import_format_date_unix_timestamp($meta['data'][0]['created']);

    if ($created) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'value' => $created,
        'timezone' => 'Europe/Moscow',
        'timezone_db' => 'Europe/Moscow',
        'date_type' => 'datestamp',
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $dataset_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Дата последнего изменения".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата последнего изменения".';
  }
}

/**
 * Set dataset provenance field.
 */
function _od_import_dataset_set_provenance(&$dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_PROVENANCE};

  if (isset($meta['data'][0]['provenance'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $meta['data'][0]['provenance'],
      'format' => NULL,
      'safe_value' => $meta['data'][0]['provenance'],
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Содержание последнего изменения".';
  }
}

/**
 * Set dataset subject field.
 */
function _od_import_dataset_set_subject(&$dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_SUBJECT};

  if (isset($meta['subject'])) {
    // Get the new field value.
    $subjects = explode(',', $meta['subject']);
    $new_field_value = array(LANGUAGE_NONE => array());
    foreach ($subjects as $subject) {
      $subject = od_import_load_or_create_subject_by_name(trim($subject)); //dk
      $new_field_value[LANGUAGE_NONE][] = array(
        'tid' => $subject->tid,
      );
    }

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Ключевые слова".';
  }
}

/**
 * Set dataset publisher name field.
 */
function _od_import_dataset_set_publisher_name(&$dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_PUBLISHER_NAME};

  if (isset($meta['publisher']['name'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $meta['publisher']['name'],
      'format' => NULL,
      'safe_value' => $meta['publisher']['name'],
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Ответственное лицо".';
  }
}

/**
 * Set dataset publisher phone field.
 */
function _od_import_dataset_set_publisher_phone(&$dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_PUBLISHER_PHONE};

  if (isset($meta['publisher']['phone'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $meta['publisher']['phone'],
      'format' => NULL,
      'safe_value' => $meta['publisher']['phone'],
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $dataset_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Номер телефона ответственного лица".';
  }
}

/**
 * Set dataset publisher email field.
 */
function _od_import_dataset_set_publisher_mbox(&$dataset_node, $meta, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_PUBLISHER_EMAIL};

  if (isset($meta['publisher']['mbox'])) {
    if (valid_email_address($meta['publisher']['mbox'])) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'email' => $meta['publisher']['mbox'],
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $dataset_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Адрес электронной почты ответственного лица".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Адрес электронной почты ответственного лица".';
  }
}

/**
 * Set dataset resource. It requires existing dataset node.
 */
function _od_import_dataset_set_resource(&$dataset_node, $meta, &$messages, &$dataset_updated, &$resource_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{OD_COMMON_FIELD_DATASET_RESOURCES};

  // Return if data does not exist.
  if (isset($meta['data'])) {
    // Load resource node.
    if (!empty($field_value)) {
      $resource_nid = $dataset_node->{OD_COMMON_FIELD_DATASET_RESOURCES}['und'][0]['target_id'];
      $resource_node = node_load($resource_nid);
    }
    // Or create if it has not created yet.
    else {
      $resource_node = _od_import_create_resource($dataset_node->nid);

      $dataset_node->{OD_COMMON_FIELD_DATASET_RESOURCES}[LANGUAGE_NONE][0] = array(
        'target_id' => $resource_node->nid,
      );
      $dataset_updated = TRUE;
    }

    _od_import_update_resource($resource_node, $meta, $messages, $resource_updated);
  }
  else {
    if (empty($field_value)) {
      $dataset_node->{OD_COMMON_FIELD_DATASET_RESOURCES} = array();
    }
    $messages[] = 'Не заполнено поле "Ресурс".';
  }
}

/**
 * Create resource for dataset.
 */
function _od_import_create_resource($dataset_id) {
  $resource_node = new stdClass();

  // $resource_node->title = $meta['title']; //dk
  $resource_node->type = 'resource';
  node_object_prepare($resource_node);
  $resource_node->language = LANGUAGE_NONE;
  $resource_node->uid = OD_COMMON_IMPORT_USER_ID;
  $resource_node->status = NODE_PUBLISHED;
  $resource_node->promote = NODE_NOT_PROMOTED;
  $resource_node->comment = COMMENT_NODE_OPEN;

  $resource_node->{OD_COMMON_FIELD_RESOURCE_DATASET}[LANGUAGE_NONE][0] = array(
    'target_id' => $dataset_id,
  );

  // Set opendata log variables.
  $resource_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);

  node_save($resource_node);

  return $resource_node;
}

/**
 * Update resource with data values.
 */
function _od_import_update_resource($resource_node, $meta, &$messages, &$resource_updated) {
  $revisions = od_import_get_source_revisions($resource_node->nid);

  $revisions_created = array();
  foreach ($revisions as $revision) {
    $created = $revision->{OD_COMMON_FIELD_RESOURCE_CREATED}['und'][0]['value'];
    $revisions_created[$created] = $revision->vid;
  }

  foreach ($meta['data'] as $data) {
    if (empty($data['created'])) {
      continue;
    }

    $created = od_import_format_date_unix_timestamp($data['created']);

    if (!$created) {
      continue;
    }

    if (isset($revisions_created[$created])) {
      continue;
    }

    $resource_updated = TRUE;

    if (!empty($revisions_created)) {
      $resource_node->revision = TRUE;
    }

    // Set resource created field.
    _od_import_resource_set_created($resource_node, $data, $messages, $resource_updated);
    // Set resource provenance field.
    _od_import_resource_set_provenance($resource_node, $data, $messages, $resource_updated);
    // Set resource format field.
    _od_import_resource_set_format($resource_node, $data, $messages, $resource_updated);
    // Set resource data file field.
    _od_import_resource_set_data($resource_node, $data, $messages, $resource_updated, $meta);
    // Set resource structure field.
    _od_import_resource_set_structure($resource_node, $data, $messages, $resource_updated, $meta);

    // Set opendata log variables if log has not disabled.
    if ($resource_node->od_log !== FALSE) {
      $resource_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
    }

    node_save($resource_node);

    $revisions_created[$created] = $resource_node->vid;
  }

  return $resource_node;
}

/**
 * Set resource created field.
 */
function _od_import_resource_set_created($resource_node, $data, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{OD_COMMON_FIELD_RESOURCE_CREATED};

  if (isset($data['created'])) {
    // Get created in unix timestamp format.
    $created = od_import_format_date_unix_timestamp($data['created']);

    if ($created) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'value' => $created,
        'timezone' => 'Europe/Moscow',
        'timezone_db' => 'Europe/Moscow',
        'date_type' => 'datestamp',
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $resource_updated = TRUE;
      }
    }
    // Unreachable statement, because $data['created'] must be correct always.
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Дата создания версии набора открытых данных".';
    }
  }
  // Unreachable statement, because $data['created'] must be defined always.
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата создания версии набора открытых данных".';
  }
}

/**
 * Set resource provenance field.
 */
function _od_import_resource_set_provenance($resource_node, $data, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{OD_COMMON_FIELD_RESOURCE_PROVENANCE};

  if (isset($data['provenance'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $data['provenance'],
      'format' => NULL,
      'safe_value' => $data['provenance'],
    )));

    // Update the field if it has changed.
    if ($field_value !== $new_field_value) {
      $field_value = $new_field_value;
      $resource_updated = TRUE;
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Содержание изменения версии набора открытых данных".';
  }
}

/**
 * Set resource format field.
 */
function _od_import_resource_set_format($resource_node, $data, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{OD_COMMON_FIELD_RESOURCE_FORMAT};

  if (isset($data['format'])) {
    // Get format tid.
    $format = od_import_get_format_id($data['format']);

    if ($format) {
      // Get the new field value.
      $new_field_value = array(LANGUAGE_NONE => array(0 => array(
        'tid' => $format,
      )));

      // Update the field if it has changed.
      if ($field_value !== $new_field_value) {
        $field_value = $new_field_value;
        $resource_updated = TRUE;
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Формат версии набора открытых данных".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Формат версии набора открытых данных".';
  }
}

/**
 * Set resource data file field.
 */
function _od_import_resource_set_data($resource_node, $data, &$messages, &$resource_updated, $meta) {
  // Get the current field value.
  $field_value = &$resource_node->{OD_COMMON_FIELD_RESOURCE_DATA};

  if (isset($data['source'])) {
    $url = $data['source'];
    if (valid_url($url)) {
      // Get correct system file uri.
      $uri = od_import_build_file_uri(OD_IMPORT_DATA_TYPE, $data, $meta);

      // Get opendata data file.
      $file = od_import_load_file($uri);

      // Create file if it has not create yet.
      if (empty($file)) {
        $file = od_import_create_file($uri, $data['source']);

        $file->display = 1;

        switch ($file->filemime) {
          case 'text/csv':
            $file->grid = 1;
            $delimiter = od_import_detect_delimiter($file->uri);
            $resource_node->{OD_COMMON_FIELD_RESOURCE_CSV_DELIMITER}[LANGUAGE_NONE][0]['value'] = $delimiter;
            $resource_node->{OD_COMMON_FIELD_RESOURCE_ENCODING}[LANGUAGE_NONE][0]['value'] = 'utf-8';
            break;
        }

        $new_field_value = array(LANGUAGE_NONE => array(0 => (array) $file));

        // Update the field if it has changed.
        if ($field_value !== $new_field_value) {
          $field_value = $new_field_value;
          $resource_updated = TRUE;
        }
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Не корреткно заполнено поле "Ссылка на файл версии набора открытых данных".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Ссылка на файл версии набора открытых данных".';
  }
}

/**
 * Set resource structure field.
 */
function _od_import_resource_set_structure($resource_node, $data, &$messages, &$resource_updated, $meta) {
  // Get the current field value.
  $field_value = &$resource_node->{OD_COMMON_FIELD_RESOURCE_STRUCTURE};

  if (isset($data['source'])) {
    $url = $data['source'];
    if (valid_url($url)) {
      // Get file uri.
      $uri = od_import_build_file_uri(OD_IMPORT_STRUCTURE_TYPE, $data, $meta);

      // Get opendata data file.
      $file = od_import_load_file($uri);

      // Create file if it has not create yet.
      if (empty($file)) {
        $file = od_import_create_file($uri, $data['structure']['source']);

        $file->display = 1;

        $new_field_value = array(LANGUAGE_NONE => array(0 => (array) $file));

        // Update the field if it has changed.
        if ($field_value !== $new_field_value) {
          $field_value = $new_field_value;
          $resource_updated = TRUE;
        }
      }
    }
    else {
      // Set the field default value.
      $field_value = array();

      // Set warning message.
      $messages[] = 'Не корреткно заполнено поле "Ссылка на файл версии структуры набора открытых данных".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Ссылка на файл версии структуры набора открытых данных".';
  }
}
