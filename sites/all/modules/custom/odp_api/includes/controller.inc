<?php

/**
 * Include API points.
 */
require_once ODP_API . '/includes/point.inc';

/**
 * Deliver callback.
 */
function odp_api_json_deliver($content) {
  // Return default error page.
  if (is_int($content)) {
    drupal_deliver_html_page($content);
  }

  if ($content === FALSE) {
    $content = 'Запрос не дал результатов.';
  }

  $content = odp_api_json_encode($content);
  drupal_add_http_header('Content-Type', 'application/json; charset=utf-8');
  drupal_add_http_header('Content-Length', strlen($content));
  echo $content;
  drupal_exit();
}

/**
 * Deliver callback.
 */
function odp_api_xml_deliver($content) {
  // Return default error page.
  if (is_int($content)) {
    drupal_deliver_html_page($content);
  }

  if ($content === FALSE) {
    $content = new stdClass();
    $content->result = 'Запрос не дал результатов.';
  }

  $content = odp_api_xml_encode($content);
  $content = '<?xml version="1.0"?>' . "\n" . $content;
  drupal_add_http_header('Content-Type', 'application/xml; charset=utf-8');
  drupal_add_http_header('Content-Length', strlen($content));
  echo $content;
  drupal_exit();
}

/**
 * Php variable to xml converter.
 */
function odp_api_xml_encode($var, $depth = 0) {
  $_myself = __FUNCTION__;
  $content = '';

  if (is_object($var)) {
    $var = (array) $var;
  }

  if (is_array($var)) {
    if (isset($var['#tag'])) {
      $global_tag = $var['#tag'];
      unset($var['#tag']);
    }
    foreach ($var as $key => $value) {
      if ($key === '#tag') {
        continue;
      }
      $tag = isset($global_tag) ? $global_tag : $key;

      if ($depth) {
        $content .= "\n";
      }
      for ($i = 0; $i < $depth; $i++) {
        $content .= '  ';
      }
      $inner_output = $_myself($value, $depth + 1);
      $content .= !empty($inner_output) ? ('<' . $tag . '>' . $inner_output . '</' . $tag . '>') : '<' . $tag . '/>';
    }
    if ($var) {
      $content .= "\n";
      for ($i = 0; $i < $depth - 1; $i++) {
        $content .= '  ';
      }
    }
  }
  else {
    $content .= $var;
  }

  return $content;
}

function odp_api_json_encode($var, $depth = 0) {
  $_myself = __FUNCTION__;
  $_escape = function($str) {
    return preg_replace("!([\b\t\n\r\f\"\\'])!", "\\\\\\1", $str);
  };

  $content = '';

  if (is_object($var)) {
    $var = (array) $var;
  }

  if (is_array($var)) {
    $is_object = !empty($var) && array_keys($var) !== range(0, count($var) - 1) ? TRUE : FALSE;

    $content .= $is_object ? '{' : '[';
    $inner_output = '';
    foreach ($var as $key => $value) {
      $inner_output .= str_repeat('  ', $depth + 1);
      if ($is_object) {
        $inner_output .=  "\"" . (is_string($key) ? $_escape($key) : $key) . "\"" . ': ';
      }
      $inner_output .= $_myself($value, $depth + 1) . ",\n";
    }
    if ($inner_output) {
      $inner_output = substr($inner_output, 0, -2);
      $content .= "\n" . $inner_output . "\n" . str_repeat('  ', $depth);
    }
    $content .= $is_object ? '}' : ']';
  }
  elseif (is_bool($var)) {
    $content .= $var ? 'true' : 'false';
  }
  elseif (is_null($var)) {
    $content .= 'null';
  }
  elseif (is_string($var)) {
    $content .= "\"" . $_escape($var) . "\"";
  }
  else {
    $content .= $var;
  }

  return $content;
}

function odp_api_detect_format() {
  $format = &drupal_static('od_api_format', NULL);

  if ($format === NULL) {
    $item = menu_get_item();
    $path = $item['path'];

    switch ($path) {
      case 'api/json':
        $format = ODP_API_FORMAT_JSON;
        break;
      case 'api/xml':
        $format = ODP_API_FORMAT_XML;
        break;
      default:
        $format = ODP_API_FORMAT_JSON;
        break;
    }
  }

  return $format;
}

function _odp_api_language_sort($language = NULL) {
  static $language_sort;

  if (!$language_sort && !$language) {
    $language = 'ru';
  }

  if ($language) {
    // Define language sorting.
    $language_sort = array($language, LANGUAGE_NONE);

    // Prepare language sorting for sql query.
    foreach ($language_sort as &$item) {
      $item = '\'' . $item . '\'';
    }
    $language_sort = implode(',', array_reverse($language_sort));
  }

  return $language_sort;
}
