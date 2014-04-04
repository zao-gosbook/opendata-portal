<?php

/**
 * Deliver callback.
 */
function odp_api_xml_output($xml) {
  // Return default error page.
  if (is_int($xml)) {
    drupal_deliver_page($xml);
  }

  if ($xml === FALSE) {
    $xml = '<result>Запрос не дал результатов</result>';
  }

  // XML declaration.
  $xml = '<?xml version="1.0"?>' . "\n" . $xml;
  drupal_add_http_header('Content-Length', strlen($xml));
  drupal_add_http_header('Content-Type', 'text/xml');
  echo $xml;
  drupal_exit();
}

/**
 * Php variable to xml converter.
 */
function odp_api_variable_to_xml($var, $tags = array(), $max_depth = 0, $depth = 0) {
  $xml = '';
  if (!$depth) {
    if (empty($var)) {
      $xml .= '<' . $tags[0] . ' />';
      return $xml;
    }
    else {
      $xml .= '<' . $tags[0] . '>';
    }
  }
  $depth++;

  // Test it.
  if (is_object($var)) {
    $var = (array) $var;
  }

  if (is_array($var)) {
    if ($max_depth >= $depth || $max_depth == 0) {
      $assoc_array = array_keys($var) !== range(0, count($var) - 1) ? TRUE : FALSE;
      foreach ($var as $key => $value) {
        if (isset($tags[$depth])) {
          $key = $tags[$depth];
        }
        elseif (!$assoc_array) {
          $key = 'item' . $key;
        }
        elseif (is_numeric($key)) {
          $key = 'val' . $key;
        }
        $xml .= "\n";
        for ($i = 0; $i < $depth; $i++) {
          $xml .= '  ';
        }
        $xml .= '<' . $key . '>';
        $inner_xml = odp_api_variable_to_xml($value, $tags, $max_depth, $depth);
        $xml .= $inner_xml;
        $xml .= '</' . $key . '>';
      }
      if ($var) {
        $xml .= "\n";
        for ($i = 0; $i < $depth - 1; $i++) {
          $xml .= '  ';
        }
      }
    }
  }
  else {
    $xml .= $var;
  }

  $depth--;
  if (!$depth) {
    $xml .= '</' . $tags[0] . '>';
  }

  return $xml;
}
