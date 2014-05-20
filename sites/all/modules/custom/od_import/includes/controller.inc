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
  // Get file by url.
  $files = od_import_get_file_by_uri($uri);
  $file = !empty($files) ? reset($files) : FALSE;

  return $file;
}

function od_import_convert_to_utf8(&$data) {
  $encoder = od_detect_encoding_get_detector();
  $converted_data = $encoder->convertString($data, 'UTF-8');

  if ($converted_data) {
    $data = $converted_data;
  }

  return (bool) $converted_data;
}

function od_import_create_local_file($destination, $origin_uri) {
  $data = od_import_get_url_content($origin_uri);
  if ($data === FALSE) {
    return FALSE;
  }

  $exists = file_prepare_directory(drupal_dirname($destination), FILE_CREATE_DIRECTORY);
  if ($exists === FALSE) {
    return FALSE;
  }

  $is_utf8 = od_import_convert_to_utf8($data);

  // Save file.
  $uri = file_unmanaged_save_data($data, $destination, FILE_EXISTS_REPLACE);
  if ($uri === FALSE) {
    return FALSE;
  }

  $file = od_import_create_file($uri);

  $file->utf8 = (integer) $is_utf8;

  return $file;
}

function od_import_create_remote_file($uri) {
  $file_exists = od_import_check_file_exists($uri);
  if ($file_exists === FALSE) {
    return FALSE;
  }

  $file = od_import_create_file($uri);

  return $file;
}

function od_import_create_file($uri) {
  // Create a file object.
  $file = new stdClass();
  $file->fid = NULL;
  $file->uri = $uri;
  $file->filename = drupal_basename($uri);
  $file->filemime = file_get_mimetype($uri);
  $file->uid = OD_COMMON_IMPORT_USER_ID;
  $file->status = FILE_STATUS_PERMANENT;

  // If we are replacing an existing file re-use its database record.
  $existing_files = file_load_multiple(array(), array('uri' => $uri));
  if (count($existing_files)) {
    $existing = reset($existing_files);
    $file->fid = $existing->fid;
    $file->filename = $existing->filename;
  }

  return file_save($file);
}

function od_import_get_url_content($url) {
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_URL, $url);
  curl_setopt($curl, CURLOPT_BUFFERSIZE, '1024');
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($curl, CURLOPT_FRESH_CONNECT, 1);
  curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($curl, CURLOPT_NOPROGRESS, 0);
  curl_setopt($curl, CURLOPT_PROGRESSFUNCTION, '_od_import_curl_progress_function_size_limit_checker_callback');

  $content = curl_exec($curl);

  $http_code = curl_getinfo($curl, CURLINFO_HTTP_CODE);

  curl_close($curl);

  return $http_code < 400 ? $content : FALSE;
}

function od_import_check_file_exists($url) {
  $curl = curl_init();
  curl_setopt($curl, CURLOPT_URL, $url);
  curl_setopt($curl, CURLOPT_BUFFERSIZE, '1024');
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
  curl_setopt($curl, CURLOPT_FRESH_CONNECT, 1);
  curl_setopt($curl, CURLOPT_FOLLOWLOCATION, 1);
  curl_setopt($curl, CURLOPT_NOPROGRESS, 0);
  curl_setopt($curl, CURLOPT_PROGRESSFUNCTION, '_od_import_curl_progress_function_file_existing_checker_callback');

  curl_exec($curl);

  $http_code = curl_getinfo($curl, CURLINFO_HTTP_CODE);

  curl_close($curl);

  return $http_code < 400 ? TRUE : FALSE;
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

  if (!file_valid_uri($uri)) {
    return FALSE;
  }

  return $uri;
}

function od_import_format_date_iso_url($created) {
  $created = strtotime($created);

  return $created ? date('Y-m-d\TH-i-s', $created) : FALSE;
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

function _od_import_curl_progress_function_size_limit_checker_callback($resource, $download_size) {
  return $download_size > OD_IMPORT_OPENDATA_MAX_SIZE;
}

function _od_import_curl_progress_function_file_existing_checker_callback($resource, $download_size) {
  return $download_size > (1024 * 1024);
}
