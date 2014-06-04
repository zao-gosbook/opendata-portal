<?php

/**
 * Create dataset for organization by identifier for.
 */
function _od_import_create_dataset($meta, $organization) {
  $dataset_node = new stdClass();

  $dataset_node->type = 'dataset';
  node_object_prepare($dataset_node);
  $dataset_node->language = LANGUAGE_NONE;
  $dataset_node->uid = OD_COMMON_IMPORT_USER_ID;
  $dataset_node->promote = NODE_NOT_PROMOTED;
  $dataset_node->comment = COMMENT_NODE_OPEN;
  $dataset_node->status = NODE_NOT_PUBLISHED;

  // Meta identifier.
  $dataset_node->{ODP_FIELD_DATASET_IDENTIFIER}[LANGUAGE_NONE][0] = array(
    'value' => $meta['identifier'],
    'format' => NULL,
    'safe_value' => check_plain($meta['identifier']),
  );

  // Meta owner.
  $dataset_node->{ODP_FIELD_DATASET_OWNER}[LANGUAGE_NONE][0] = array(
    'target_id' => $organization->nid,
  );

  // Set opendata log variables.
  if (empty($dataset_node->od_logged)) {
    $dataset_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
  }

  // Save node.
  node_save($dataset_node);

  return $dataset_node;
}

/**
 * Update dataset with meta values.
 */
function _od_import_update_dataset($dataset_node, $meta, $organization, &$dataset_updated, &$resource_updated) {
  // Init messages variable.
  $messages = array();

  // Set dataset title field.
  _od_import_dataset_set_title($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset description field.
  _od_import_dataset_set_description($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset created field.
  _od_import_dataset_set_created($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset updated field.
  _od_import_dataset_set_updated($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset subject field.
  _od_import_dataset_set_subject($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset publisher name field.
  _od_import_dataset_set_publisher_name($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset publisher phone field.
  _od_import_dataset_set_publisher_phone($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset publisher email field.
  _od_import_dataset_set_publisher_mbox($dataset_node, $meta, $organization, $messages, $dataset_updated);
  // Set dataset resource.
  _od_import_dataset_set_resource($dataset_node, $meta, $organization, $messages, $dataset_updated, $resource_updated);

  // Set opendata log variables if log has not disabled.
  if (empty($dataset_node->od_logged)) {
    $dataset_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
  }

  // Update dataset.
  if ($dataset_updated || $resource_updated) {
    node_save($dataset_node);
  }

  // Set warning messages.
  foreach ($messages as $message) {
    od_log($message, OD_LOG_IMPORTANCE_WARNING, OD_LOG_EVENT_IMPORT_DATA, $organization->nid, $dataset_node->nid);
  }

  return $dataset_node;
}

/**
 * Set dataset title field.
 */
function _od_import_dataset_set_title($dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->title;

  $str_len = mb_strlen($meta['title']);

  if ($str_len > 255) {
    // Set warning message.
    $messages[] = 'Превышен допустимый размер в 255 символов для поля "Наименование набора данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '". Наименование набора не может быть записано в базу данных Портала ОД полностью. Значение поля обрезано до 255 символов.';
  }

  // Get the new field value.
  $new_field_value = $str_len > 255 ? mb_substr($meta['title'], 0, 255) : $meta['title'];

  // Update the field if it has changed.
  if ($field_value !== $new_field_value) {
    $field_value = $new_field_value;
    $dataset_updated = TRUE;
  }
}

/**
 * Set dataset description field.
 */
function _od_import_dataset_set_description($dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_DESCRIPTION};

  if (isset($meta['description'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array('0' => array(
      'value' => $meta['description'],
      'summary' => '',
      'format' => 'full_html',
      'safe_value' => check_plain($meta['description']),
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
    $messages[] = 'Не заполнено поле "Описание набора данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset created field.
 */
function _od_import_dataset_set_created(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_CREATED};

  if (isset($meta['created'])) {
    // Get created in unix timestamp format.
    $created = (string) strtotime($meta['created']);

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
      $messages[] = 'Некорректно заполнено поле "Дата первой публикации набора данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата первой публикации набора данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset updated field.
 */
function _od_import_dataset_set_updated(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_UPDATED};

  if (isset($meta['data'][0]['created'])) {
    // Get created in unix timestamp format.
    $created = (string) strtotime($meta['data'][0]['created']);

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
      $messages[] = 'Некорректно заполнено поле "Дата последнего изменения" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата последнего изменения" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset subject field.
 */
function _od_import_dataset_set_subject(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_SUBJECT};

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
    $messages[] = 'Не заполнено поле "Ключевые слова" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset publisher name field.
 */
function _od_import_dataset_set_publisher_name(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_PUBLISHER_NAME};

  if (isset($meta['publisher']['name'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $meta['publisher']['name'],
      'format' => NULL,
      'safe_value' => check_plain($meta['publisher']['name']),
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
    $messages[] = 'Не заполнено поле "Ответственное лицо" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset publisher phone field.
 */
function _od_import_dataset_set_publisher_phone(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_PUBLISHER_PHONE};

  if (isset($meta['publisher']['phone'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $meta['publisher']['phone'],
      'format' => NULL,
      'safe_value' => check_plain($meta['publisher']['phone']),
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
    $messages[] = 'Не заполнено поле "Номер телефона ответственного лица" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset publisher email field.
 */
function _od_import_dataset_set_publisher_mbox(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_PUBLISHER_EMAIL};

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
      $messages[] = 'Некорректно заполнено поле "Адрес электронной почты ответственного лица" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Адрес электронной почты ответственного лица" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set dataset resource. It requires existing dataset node.
 */
function _od_import_dataset_set_resource(&$dataset_node, $meta, $organization, &$messages, &$dataset_updated, &$resource_updated) {
  // Get the current field value.
  $field_value = &$dataset_node->{ODP_FIELD_DATASET_RESOURCES};

  // Return if data does not exist.
  if (isset($meta['data'])) {
    // Load resource node.
    if (!empty($field_value)) {
      $resource_nid = $dataset_node->{ODP_FIELD_DATASET_RESOURCES}['und'][0]['target_id'];
      $resource_node = node_load($resource_nid);
    }
    // Or create if it has not created yet.
    else {
      $resource_node = _od_import_create_resource($dataset_node);

      $dataset_node->{ODP_FIELD_DATASET_RESOURCES}[LANGUAGE_NONE][0] = array(
        'target_id' => $resource_node->nid,
      );
      $dataset_updated = TRUE;
    }

    _od_import_update_resource($resource_node, $meta, $dataset_node, $organization, $messages, $resource_updated);
  }
  else {
    if (empty($field_value)) {
      $dataset_node->{ODP_FIELD_DATASET_RESOURCES} = array();
    }
    $messages[] = 'Не заполнено поле "Гиперссылка на набор открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Create resource for dataset.
 */
function _od_import_create_resource($dataset_node) {
  $resource_node = new stdClass();

  $resource_node->type = 'resource';
  node_object_prepare($resource_node);
  $resource_node->language = LANGUAGE_NONE;
  $resource_node->uid = OD_COMMON_IMPORT_USER_ID;
  $resource_node->status = NODE_PUBLISHED;
  $resource_node->promote = NODE_NOT_PROMOTED;
  $resource_node->comment = COMMENT_NODE_OPEN;

  $resource_node->{ODP_FIELD_RESOURCE_DATASET}[LANGUAGE_NONE][0] = array(
    'target_id' => $dataset_node->nid,
  );

  // Set opendata log variables.
  if (empty($resource_node->od_logged)) {
    $resource_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
  }

  // Save node.
  node_save($resource_node);

  return $resource_node;
}

/**
 * Update resource with data values.
 */
function _od_import_update_resource($resource_node, $meta, $dataset_node, $organization, &$messages, &$resource_updated) {
  $revisions = od_import_get_source_revisions($resource_node->nid);

  $revisions_created = array();
  foreach ($revisions as $revision) {
    $created = $revision->{ODP_FIELD_RESOURCE_CREATED}['und'][0]['value'];
    $revisions_created[$created] = $revision->vid;
  }

  foreach ($meta['data'] as $data) {
    if (empty($data['created'])) {
      continue;
    }

    $created = (string) strtotime($data['created']);

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
    _od_import_resource_set_created($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated);
    // Set resource provenance field.
    _od_import_resource_set_provenance($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated);
    // Set resource format field.
    _od_import_resource_set_format($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated);
    // Set resource data file field.
    _od_import_resource_set_data($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated, $meta);
    // Set resource structure field.
    _od_import_resource_set_structure($resource_node, $data, $dataset_node, $organization, $messages, $resource_updated, $meta);

    // Set opendata log variables if log has not disabled.
    if (empty($resource_node->od_logged)) {
      $resource_node->od_log = array('user' => OD_COMMON_IMPORT_USER_ID);
    }

    if ($resource_updated) {
      node_save($resource_node);
    }

    $revisions_created[$created] = $resource_node->vid;
  }

  return $resource_node;
}

/**
 * Set resource created field.
 */
function _od_import_resource_set_created($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{ODP_FIELD_RESOURCE_CREATED};

  if (isset($data['created'])) {
    // Get created in unix timestamp format.
    $created = (string) strtotime($data['created']);

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
      $messages[] = 'Некорректно заполнено поле "Дата создания набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  // Unreachable statement, because $data['created'] must be defined always.
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Дата создания набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set resource provenance field.
 */
function _od_import_resource_set_provenance($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{ODP_FIELD_RESOURCE_PROVENANCE};

  if (isset($data['provenance'])) {
    // Get the new field value.
    $new_field_value = array(LANGUAGE_NONE => array(0 => array(
      'value' => $data['provenance'],
      'format' => NULL,
      'safe_value' => check_plain($data['provenance']),
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
    $messages[] = 'Не заполнено поле "Содержание изменения набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set resource format field.
 */
function _od_import_resource_set_format($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated) {
  // Get the current field value.
  $field_value = &$resource_node->{ODP_FIELD_RESOURCE_FORMAT};

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
      $messages[] = 'Некорректно заполнено поле "Формат набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default value.
    $field_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Формат набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set resource data file field.
 */
function _od_import_resource_set_data($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated, $meta) {
  // Get the current field values.
  $field_local_value = &$resource_node->{ODP_FIELD_RESOURCE_LOCAL_DATA};
  $field_remote_value = &$resource_node->{ODP_FIELD_RESOURCE_REMOTE_DATA};

  if (isset($data['source'])) {
    $url = $data['source'];
    if (valid_url($url)) {
      // Get default values.
      $new_field_local_value = array();
      $new_field_remote_value = array();

      // Get file extension validators.
      $local_valid_extensions = _od_import_resource_get_available_extensions(ODP_FIELD_RESOURCE_LOCAL_DATA, $url);
      $remote_valid_extensions = _od_import_resource_get_available_extensions(ODP_FIELD_RESOURCE_REMOTE_DATA, $url);

      // Get validations.
      $local_valid = $local_valid_extensions;

      if ($local_valid) {
        // Get correct system file uri.
        $uri = od_import_build_file_uri(OD_IMPORT_DATA_TYPE, $data, $meta);

        if ($uri !== FALSE) {
          // Get existing opendata data file.
          $file = od_import_load_file($uri);

          // Create file if it has not created yet.
          if (empty($file)) {
            $file = od_import_create_local_file($uri, $url);

            if (!empty($file)) {
              $resource_node->{ODP_FIELD_RESOURCE_UTF8_ENCODING}[LANGUAGE_NONE][0]['value'] = $file->utf8;

              switch ($file->filemime) {
                case 'text/csv':
                  $file->grid = 1;
                  $delimiter = odp_detect_csv_delimiter($file->uri);
                  $resource_node->{ODP_FIELD_RESOURCE_CSV_DELIMITER}[LANGUAGE_NONE][0]['value'] = $delimiter;
                  break;
                default:
                  $resource_node->{ODP_FIELD_RESOURCE_CSV_DELIMITER} = array();
                  break;
              }
            }
          }

          if (!empty($file)) {
            $file->display = 1;
          }

          if (!empty($file)) {
            $new_field_local_value = array(LANGUAGE_NONE => array(0 => (array) $file));
          }
        }
      }

      // Get validations.
      $remote_valid = empty($new_field_local_value) && $remote_valid_extensions;

      if ($remote_valid) {
        // Get existing opendata data file.
        $file = od_import_load_file($url);

        // Create file if it has not created yet.
        if (empty($file)) {
          $file = od_import_create_remote_file($url);

          if (!empty($file)) {
            $resource_node->{ODP_FIELD_RESOURCE_UTF8_ENCODING} = array();
            $resource_node->{ODP_FIELD_RESOURCE_CSV_DELIMITER} = array();
          }
        }

        if (!empty($file)) {
          $file->display = 1;
        }

        if (!empty($file)) {
          $new_field_remote_value = array(LANGUAGE_NONE => array(0 => (array) $file));
        }
      }

      if (!empty($new_field_local_value) && $field_local_value !== $new_field_local_value) {
        $field_local_value = $new_field_local_value;
        $resource_updated = TRUE;
      }

      if (!empty($new_field_remote_value) && $field_remote_value !== $new_field_remote_value) {
        $field_remote_value = $new_field_remote_value;
        $resource_updated = TRUE;
      }

      if (empty($new_field_local_value) && empty($new_field_remote_value)) {
        // Set warning message.
        $messages[] = 'Некорректно заполнено поле "Гиперссылка на набор открытых данных" и/или "Гиперссылки на версии набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
      }
    }
    else {
      // Set the field default values.
      $field_local_value = array();
      $field_remote_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Гиперссылка на набор открытых данных" и/или "Гиперссылки на версии набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default values.
    $field_local_value = array();
    $field_remote_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Гиперссылка на набор открытых данных" и/или "Гиперссылки на версии набора открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

/**
 * Set resource structure field.
 */
function _od_import_resource_set_structure($resource_node, $data, $dataset_node, $organization, &$messages, &$resource_updated, $meta) {
  // Get the current field values.
  $field_local_value = &$resource_node->{ODP_FIELD_RESOURCE_LOCAL_STRUCTURE};;
  $field_remote_value = &$resource_node->{ODP_FIELD_RESOURCE_REMOTE_STRUCTURE};

  if (isset($data['structure']['source'])) {
    $url = $data['structure']['source'];
    if (valid_url($url)) {
      // Get default values.
      $new_field_local_value = array();
      $new_field_remote_value = array();

      // Get the current data field values.
      $field_data_local_value = $resource_node->{ODP_FIELD_RESOURCE_LOCAL_DATA};
      $field_data_remote_value = $resource_node->{ODP_FIELD_RESOURCE_REMOTE_DATA};

      // Get file extension validators.
      $local_valid_extensions = _od_import_resource_get_available_extensions(ODP_FIELD_RESOURCE_LOCAL_STRUCTURE, $url);
      $remote_valid_extensions = _od_import_resource_get_available_extensions(ODP_FIELD_RESOURCE_REMOTE_STRUCTURE, $url);

      // Get validations.
      $local_valid = $local_valid_extensions && !empty($field_data_local_value);

      if ($local_valid) {
        // Get correct system file uri.
        $uri = od_import_build_file_uri(OD_IMPORT_STRUCTURE_TYPE, $data, $meta);

        if ($uri !== FALSE) {
          // Get existing opendata data file.
          $file = od_import_load_file($uri);

          // Create file if it has not created yet.
          if (empty($file)) {
            $file = od_import_create_local_file($uri, $url);
          }

          if (!empty($file)) {
            $file->display = 1;
          }

          if (!empty($file)) {
            $new_field_local_value = array(LANGUAGE_NONE => array(0 => (array) $file));
          }
        }
      }

      // Get validations.
      $remote_valid = empty($new_field_local_value) && $remote_valid_extensions && !empty($field_data_remote_value);

      if ($remote_valid) {
        // Get existing opendata data file.
        $file = od_import_load_file($url);

        // Create file if it has not created yet.
        if (empty($file)) {
          $file = od_import_create_remote_file($url);
        }

        if (!empty($file)) {
          $file->display = 1;
        }

        if (!empty($file)) {
          $new_field_remote_value = array(LANGUAGE_NONE => array(0 => (array) $file));
        }
      }

      if (!empty($new_field_local_value) && $field_local_value !== $new_field_local_value) {
        $field_local_value = $new_field_local_value;
        $resource_updated = TRUE;
      }

      if (!empty($new_field_remote_value) && $field_remote_value !== $new_field_remote_value) {
        $field_remote_value = $new_field_remote_value;
        $resource_updated = TRUE;
      }

      if (empty($new_field_local_value) && empty($new_field_remote_value)) {
        // Set warning message.
        $messages[] = 'Некорректно заполнено поле "Гиперссылка на структуру наборов открытых данных" и/или "Гиперссылки на версии структур наборов открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
      }
    }
    else {
      // Set the field default values.
      $field_local_value = array();
      $field_remote_value = array();

      // Set warning message.
      $messages[] = 'Некорректно заполнено поле "Гиперссылка на структуру наборов открытых данных" и/или "Гиперссылки на версии структур наборов открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
    }
  }
  else {
    // Set the field default values.
    $field_local_value = array();
    $field_remote_value = array();

    // Set warning message.
    $messages[] = 'Не заполнено поле "Гиперссылка на структуру наборов открытых данных" и/или "Гиперссылки на версии структур наборов открытых данных" набора открытых данных "' . $dataset_node->title . '" организации "' . $organization->name . '".';
  }
}

function _od_import_resource_get_available_extensions($field, $url) {
  $instance = field_info_instance('node', $field, 'resource');
  $extensions = trim((string) $instance['settings']['file_extensions']);
  $extensions = explode(',', str_replace(' ', ',', $extensions));

  $extension = mb_strtolower(pathinfo($url, PATHINFO_EXTENSION));

  return in_array($extension, $extensions);
}
