<?php

/**
 * Page callback.
 */
function odp_api_dataset_page($dataset_id, $function) {
  // Init output variable.
  $result = FALSE;

  // Get $_GET query parameters.
  $args = drupal_get_query_parameters();

  $dataset = odp_load_dataset($dataset_id);

  if (!$dataset) {
    return FALSE;
  }

  switch ($function) {
    case 'data':
      $tags = array('data', 'row');
      $resource = odp_load_dataset_resource($dataset_id);

      if (empty($resource->field_upload[LANGUAGE_NONE][0]['fid'])) {
        return $result;
      }

      $file = file_load($resource->field_upload[LANGUAGE_NONE][0]['fid']);

      if ($file->status && $file->size > 2000000 && !empty($file->uri)) {
        return $result;
      }

      $content = file_get_contents($file->uri);

      if (empty($file->uri)) {
        return $result;
      }

      if ($file->filemime === 'text/csv') {
        $content = preg_split("/\\r\\n|\\r|\\n/", $content);

        $delimiter = isset($resource->field_csv_delimiter['und'][0]['value']) ? $resource->field_csv_delimiter['und'][0]['value'] : ',';

        $header = array_shift($content);

        if (!empty($args['search']) && (is_string($args['search']) || is_numeric($args['search']))) {
          foreach ($content as $key => $string) {
            if (stripos($string, $args['search']) === FALSE) {
              unset($content[$key]);
            }
          }
        }

        array_unshift($content, $header);
        foreach ($content as &$row) {
          $row = str_getcsv($row, $delimiter);
        }
      }

      $result = $content;
      break;
    default:
      $tags = array('dataset');

      $result = $dataset;
      break;
  }

  return odp_api_variable_to_xml($result, $tags);
}
