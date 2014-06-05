<?php

/**
 * @file
 * Contains the OdApiObject class.
 */

class OdApiHelper {
  static function getUrlHttpStatus($url) {
    // Collect options.
    $options = array(
      CURLOPT_RETURNTRANSFER => TRUE,
      CURLOPT_FRESH_CONNECT => TRUE,
    );

    // Init connect.
    $curl = curl_init($url);
    curl_setopt_array($curl, $options);

    // Execute connect.
    curl_exec($curl);

    // Get http code.
    $http_code = curl_getinfo($curl, CURLINFO_HTTP_CODE);

    // Close connect.
    curl_close($curl);

    return $http_code;
  }

  static function getUrlDataStatus($url) {
    // Collect options.
    $options = array(
      CURLOPT_RETURNTRANSFER => TRUE,
      CURLOPT_FRESH_CONNECT => TRUE,
      CURLOPT_FOLLOWLOCATION => TRUE,
      CURLOPT_NOPROGRESS => FALSE,
      CURLOPT_PROGRESSFUNCTION => function ($resource, $download_size) {
        return $download_size > (1 * 1024 * 1024);
      },
    );

    // Init connect.
    $curl = curl_init($url);
    curl_setopt_array($curl, $options);

    $data = curl_exec($curl);

    // Close connect.
    curl_close($curl);

    return !empty($data);
  }

  static function getUrlRedirect($url) {
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
        return substr($header, 10);
      }
    }

    return FALSE;
  }

  static function getUrlData($url) {
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

    return $http_code < 400 ? $data : FALSE;
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
      return FALSE;
    }

    $converter = new idna_convert();
    $decoded_url = $converter->decode($arg);
    $encoded_url = $converter->encode_uri($decoded_url);

    return TRUE;
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
}
