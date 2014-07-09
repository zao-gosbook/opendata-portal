<?php

/**
 * @file
 * Contains the OdApiRDFParser class.
 */

/**
 * Opendata API class.
 */
class OdApiCsvParser extends OdApiParser {
  protected function parseUrl($url) {
    return OdApiHelper::getUrlData($url);
  }

  public function parse($url, $encoding = NULL, $delimiter = ',') {
    $parsing_url = OdApiHelper::formatUrl($url, PHP_URL_QUERY);

    if (isset($this->results[$parsing_url])) {
      return $this->results[$parsing_url];
    }

    $this->results[$parsing_url] = array();
    $error = &$this->results[$parsing_url]['error'];
    $result = &$this->results[$parsing_url]['result'];

    // Set default encoding from Windows-1251.
    if (empty($encoding)) {
      $encoding = 'Windows-1251';
    }

    $content = $this->parseUrl($url, $encoding);

    // Detect empty result.
    if (!$content) {
      $error = 'fileNotExists';
      return $this->results[$parsing_url];
    }

    // Detect UTF-8.
    $is_utf8 = preg_match('//u', $content);
    if (!$is_utf8) {
      if ($encoding) {
        // Used "@" because mixed encoding text returns error always.
        $content = @iconv($encoding, "utf-8//IGNORE", $content);
      }
    }

    if (!empty($delimiter)) {
      $rows = str_getcsv($content, "\n");

      $result = array();

      foreach($rows as &$row) {
        $row = str_getcsv($row, $delimiter);

        $result[] = $row;
      }
    }
    else {
      $result = OdApiHelper::detectDelimiter($content);
    }

    if (empty($result)) {
      $result = array();
      $error = 'fileNotExists';
    }

    return $this->results[$parsing_url];
  }
}
