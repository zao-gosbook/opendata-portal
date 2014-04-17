<?php

/**
 * Detect CSV delimiter.
 */
function odp_detect_csv_delimiter($data, $end_of_line = PHP_EOL, $enclosure = '"') {
  if (file_valid_uri($data)) {
    $data = file_get_contents($data);
  }

  if ($data === FALSE) {
    return ',';
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
