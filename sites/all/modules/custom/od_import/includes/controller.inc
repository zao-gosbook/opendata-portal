<?php

function od_import_get_subject_id($subject) {
  return od_import_get_term_id_by_name(strtolower($subject), OD_IMPORT_VOCABULARY_SUBJECTS);
}

function od_import_get_format_id($format) {
  return od_import_get_term_id_by_name(strtolower($format), OD_IMPORT_VOCABULARY_FORMATS);
}

function od_import_get_term_id_by_name($name, $vocabulary) {
  // Get terms by name.
  $terms = taxonomy_get_term_by_name($name, $vocabulary);

  return !empty($terms) ? reset($terms)->tid : FALSE;
}

function od_import_get_file_by_uri($uri) {
  $conditions = array('uri' => trim($uri));

  return file_load_multiple(array(), $conditions);
}

function od_import_load_or_create_subject_by_name($name) {
  $subject_id = od_import_get_subject_id($name);

  if ($subject_id) {
    $subject = taxonomy_term_load($subject_id);
  }

  if (empty($subject)) {
    $subject = new stdClass();
    $subject->name = $name;
    $subject->vid = OD_IMPORT_VOCABULARY_SUBJECTS_ID;
    taxonomy_term_save($subject);
  }

  return $subject;
}

function od_import_load_file($uri) {
  if (!file_valid_uri($uri)) {
    return FALSE;
  }

  // Get file by url.
  $files = od_import_get_file_by_uri($uri);
  $file = !empty($files) ? reset($files) : FALSE;

  return $file;
}

function od_import_create_file($uri, $origin_uri) {
  if (!file_valid_uri($uri)) {
    return FALSE;
  }

  file_prepare_directory(drupal_dirname($uri), FILE_CREATE_DIRECTORY);

  $file_content = od_import_get_url_content($origin_uri);
  $file = file_save_data($file_content, $uri);

  $file->uid = OD_IMPORT_USER_ID;
  file_save($file);

  return $file;
}

function od_import_get_url_content($url, $encoding = NULL) {
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_URL, $url);
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($curl, CURLOPT_FRESH_CONNECT, 1);
  curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);

  $content = curl_exec($curl);

  // Try to check on UTF-8 if encoding not defined.
  if (!$encoding) {
    // Detect UTF-8.
    $is_utf8 = preg_match('//u', $content);
    // Trying to encode from "Windows-1251" as most popular encoding in Russia if UTF-8 not detected.
    if (!$is_utf8) {
      $encoding = 'Windows-1251';
    }
  }

  // Encode if encoding is defined.
  if ($encoding) {
    $content = iconv($encoding, 'UTF-8', $content);
  }

  $http_code = curl_getinfo($curl, CURLINFO_HTTP_CODE);

  curl_close($curl);

  return $http_code < 400 ? $content : FALSE;
}

function od_import_build_file_uri($type, $data, $meta) {
  switch ($type) {
    case OD_IMPORT_STRUCTURE_TYPE:
      if (empty($data['structure']['source']) || empty($data['structure']['created'])) {
        return FALSE;
      }
      $origin_uri = $data['structure']['source'];
      $structure_created = od_import_format_date_iso_url($data['structure']['created']);
      $name = 'structure-' . $structure_created;
      break;
    case OD_IMPORT_DATA_TYPE:
      if (empty($data['source']) || empty($data['created']) || empty($data['structure']['created'])) {
        return FALSE;
      }
      $origin_uri = $data['source'];
      $data_created = od_import_format_date_iso_url($data['created']);
      $structure_created = od_import_format_date_iso_url($data['structure']['created']);
      $name = 'data-' . $data_created . '-structure-' . $structure_created;
      break;
    default:
      return FALSE;
  }

  $meta_identifier = $meta['identifier'];

  $path_info = pathinfo($origin_uri);
  $format = $path_info['extension'];

  $path = array();

  $path[] = 'opendata';
  $path[] = $meta_identifier;
  $path[] = $name . '.' . $format;

  $uri = file_build_uri(implode('/', $path));

  return $uri;
}

function od_import_format_date_iso_url($created) {
  $date = new DateTime($created);
  return strtolower($date->format('Y-m-d\TH-i-s'));
}

function od_import_format_date_unix_timestamp($created) {
  if (strtotime($created)) {
    $date = new DateTime($created);
    $created = (string) $date->getTimestamp();
  }
  else {
    $created = FALSE;
  }

  return $created;
}

function od_import_load_dataset($identifier) {
  $node = FALSE;

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'dataset');
  $query->fieldCondition('field_dataset_id', 'value', $identifier);
  $query->range(0, 1);
  $query->addMetaData('account', user_load(1));
  $result = $query->execute();
  if (isset($result['node'])) {
    $query_node = reset($result['node']);
    $node = node_load($query_node->nid);
  }

  return $node;
}

function od_import_get_source_revisions($nid) {
  $revisions = array();

  $query = db_select('node_revision', 'r');
  $query->addExpression('MAX(r.vid)', 'vid');
  $query->innerJoin('field_revision_field_created', 'c', 'r.vid = c.revision_id');
  $query->condition('r.nid', $nid);
  $query->groupBy('c.field_created_value');
  $query->orderBy('c.field_created_value', 'DESC');
  $resource = $query->execute();
  $result = $resource->fetchAllAssoc('vid');

  $vids = !empty($result) ? array_keys($result) : array();

  foreach ($vids as $vid) {
    $revisions[$vid] = node_load($nid, $vid);
  }
  return $revisions;
}

function od_import_detect_delimiter($data, $end_of_line = PHP_EOL, $enclosure = '"') {
  if (file_valid_uri($data)) {
    $data = file_get_contents($data);
  }

  if ($data === FALSE) {
    return FALSE;
  }

  $delimiters = array();
  $available_delimiters = array(',', ';');

  $data = explode($end_of_line, $data);

  foreach ($available_delimiters as $available_delimiter) {
    $cols_count = array();
    foreach ($data as $row) {
      if (empty($row)) {
        continue;
      }

      $cols_count[] = count(str_getcsv($row, $available_delimiter, $enclosure));
    }

    $count_values = array_count_values($cols_count);
    arsort($count_values);
    $popular_key = key($count_values);
    $max_key = max(array_keys($count_values));

    if ($popular_key === $max_key) {
      $delimiters[$popular_key] = $available_delimiter;
    }
  }

  krsort($delimiters);

  $delimiter = !empty($delimiters) ? reset($delimiters) : FALSE;

  return $delimiter;
}
