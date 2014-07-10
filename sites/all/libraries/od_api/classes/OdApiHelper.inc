<?php

/**
 * @file
 * Contains the OdApiObject class.
 */

class OdApiHelper {
  private static $urlData = array();
  private static $urlRedirect = array();

  static $namespaces = array(
    'rdf:' => 'http://www.w3.org/1999/02/22-rdf-syntax-ns#',
    'dc:' => 'http://purl.org/dc/terms/',
    'foaf:' => 'http://xmlns.com/foaf/0.1/',
  );

  static function getUrlRedirect($url) {
    $url = self::formatUrl($url, PHP_URL_FRAGMENT);
    if (isset(self::$urlRedirect[$url])) {
      return self::$urlRedirect[$url];
    }

    // Collect options.
    $options = array(
      CURLOPT_HEADER => TRUE,
      CURLOPT_NOBODY => TRUE,
      CURLOPT_RETURNTRANSFER => TRUE,
      CURLOPT_FRESH_CONNECT => TRUE,
    );

    // Init connect.
    $curl = curl_init($url);
    curl_setopt_array($curl, $options);

    // Execute connect.
    $data = curl_exec($curl);

    // Close connect.
    curl_close($curl);

    // Convert CRLF into LF.
    $data = str_replace("\r", '', $data);

    // Check all headers for redirect.
    $headers = explode("\n", $data);
    foreach ($headers as $header) {
      if (substr($header, 0, 10) === 'Location: ') {
        $redirect = substr($header, 10);
        break;
      }
    }

    self::$urlRedirect[$url] = isset($redirect) ? $redirect : FALSE;

    return self::$urlRedirect[$url];
  }

  static function getUrlData($url) {
    $url = self::formatUrl($url, PHP_URL_FRAGMENT);
    if (isset(self::$urlData[$url])) {
      return self::$urlData[$url];
    }

    // Collect options.
    $options = array(
      CURLOPT_RETURNTRANSFER => TRUE,
      CURLOPT_FRESH_CONNECT => TRUE,
      CURLOPT_FOLLOWLOCATION => TRUE,
    );

    // Init connect.
    $curl = curl_init($url);
    curl_setopt_array($curl, $options);

    // Execute connect.
    $data = curl_exec($curl);
    $http_code = !empty($data) ? curl_getinfo($curl, CURLINFO_HTTP_CODE) : 404;

    // Close connect.
    curl_close($curl);

    self::$urlData[$url] = $http_code < 400 ? $data : FALSE;

    return self::$urlData[$url];
  }

  static function checkUrlSuccess($url) {
    $data = OdApiHelper::getUrlData($url);

    if (empty($data) && substr($url, -1) !== '/') {
      $data = self::checkUrlSuccess($url . '/');
    }

    return (bool) $data;
  }

  static function trim($text) {
    // Strip out line breaks
    $text = preg_replace('/\n|\r|\t/m', ' ', $text);

    // Strip out non-breaking spaces
    $text = str_replace('&nbsp;', ' ', $text);
    $text = str_replace("\xc2\xa0", ' ', $text);

    // Strip out extra spaces
    $text = preg_replace('/\s\s+/', ' ', $text);

    // Trim extra spaces.
    $text = trim($text);

    return $text;
  }

  static function convertIdna($arg, &$decoded_url, &$encoded_url) {
    if (!class_exists('idna_convert')) {
      $decoded_url = $arg;
      $encoded_url = $arg;
    }

    $converter = new idna_convert();
    $decoded_url = $converter->decode($arg);
    $encoded_url = $converter->encode_uri($decoded_url);
  }

  static function clearProperties(&$array) {
    if (!is_array($array)) {
      return;
    }

    foreach (array_keys($array) as $key) {
      if ($key[0] === '#') {
        unset($array[$key]);
      }
    }
  }

  static function namespaceWrap($var) {
    return strtr($var, array_flip(OdApiHelper::$namespaces));
  }

  static function namespaceUnwrap($var) {
    return strtr($var, OdApiHelper::$namespaces);
  }

  static function formatUrl($url, $part) {
    $parsed_url = parse_url($url);
    if (!isset($parsed_url['scheme'])) {
      $url = 'http://' . $url;
    }
    $parsed_url = parse_url($url);
    $url = $parsed_url['scheme'] . '://' . $parsed_url['host'];

    $path = isset($parsed_url['path']) ? $parsed_url['path'] : '/';
    $query = isset($parsed_url['query']) ? ('?' . $parsed_url['query']) : '';
    $fragment = isset($parsed_url['fragment']) ? ('#' . $parsed_url['fragment']) : '';

    switch ($part) {
      case PHP_URL_HOST:
        $url .= '/';
        break;
      case PHP_URL_PATH:
        $url .= $path;
        break;
      case PHP_URL_QUERY:
        $url .= $path . $query;
        break;
      case PHP_URL_FRAGMENT:
        default:
        $url .= $path . $query . $fragment;
        break;
    }

    return $url;
  }

  static function detectDelimiter(&$content) {
    $result = array();

    $available_delimiters = array(',', ';', "\t");

    $delimiter_error = TRUE;
    foreach ($available_delimiters as $available_delimiter) {
      $delimiter_error = FALSE;
      $columns_count = NULL;
      $rows = str_getcsv($content, "\n");

      $result = array();

      foreach($rows as &$row) {
        $row = str_getcsv($row, $available_delimiter);

        if ($columns_count === NULL) {
          $columns_count = count($row);
          if (!in_array($columns_count, range(2, 10))) {
            $delimiter_error = TRUE;
            break;
          }
          foreach ($row as $str) {
            if (mb_strlen($str) > 255) {
              $delimiter_error = TRUE;
              break(2);
            }
          }
        }
        else {
          if (count($row) !== $columns_count) {
            $delimiter_error = TRUE;
            break;
          }
        }

        $result[] = $row;
      }

      if (!$delimiter_error) {
        break;
      }
    }

    return !$delimiter_error ? $result : FALSE;
  }

  /**
   * @param $type
   * @param $version
   * @return OdApiObject
   */
  static function getClassNameByType($type, $version = NULL) {
    $type = preg_replace('/(^|-)([a-z])/e', 'strtoupper("\\2")', $type);
    $version = empty($version) ? 'Default' : filter_var($version, FILTER_SANITIZE_NUMBER_INT);
    return 'OdApi' . $type . $version;
  }

  static function validateIso8601($date) {
   // ISO 8601 validation pattern. See https://www.debuggex.com/r/3rZt9hgYEIE5RaI2
    $pattern = '/^([\+-]?\d{4}(?!\d{2}\b))((-?)((0[1-9]|1[0-2])(\3([12]\d|0[1-9]|3[01]))?|W([0-4]\d|5[0-2])(-?[1-7])?|(00[1-9]|0[1-9]\d|[12]\d{2}|3([0-5]\d|6[1-6])))([T\s]((([01]\d|2[0-3])((:?)[0-5]\d)?|24\:?00)([\.,]\d+(?!:))?)?(\17[0-5]\d([\.,]\d+)?)?([zZ]|([\+-])([01]\d|2[0-3]):?([0-5]\d)?)?)?)?$/';

    return (bool) preg_match($pattern, $date);
  }
}
