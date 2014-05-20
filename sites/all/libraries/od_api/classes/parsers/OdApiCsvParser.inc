<?php

/**
 * @file
 * Contains the OdApiRDFParser class.
 */

/**
 * Opendata API class.
 */
class OdApiCSVParser extends OdApiParser {
  public function __construct() {
    return $this;
  }

  protected function parseUrl($url) {
    return OdApiHelper::getUrlData($url);
  }

  public function parse($url, $encoding = NULL) {
    // Set default encoding from Windows-1251.
    if (empty($encoding)) {
      $encoding = 'Windows-1251';
    }

    $this->url = $url;

    $content = $this->parseUrl($url, $encoding);

    // Detect empty result.
    if (!$content) {
      $this->error = 'fileNotExists';
      return $this;
    }

    // Detect UTF-8.
    $is_utf8 = preg_match('//u', $content);
    if (!$is_utf8) {
      if ($encoding) {
        // Used "@" because mixed encoding text returns error always.
        $content = @iconv($encoding, "utf-8//IGNORE", $content);
      }
      else {
        $this->error = 'notUtf8';
        return $this;
      }
    }

    $available_delimiters = array(',', ';');

    $error = FALSE;
    foreach ($available_delimiters as $available_delimiter) {
      $error = FALSE;
      $columns_count = NULL;
      $rows = str_getcsv($content, "\n");

      $this->result = array();

      foreach($rows as &$row) {
        $row = str_getcsv($row, $available_delimiter);

        if ($columns_count === NULL) {
          $columns_count = count($row);
          if (!in_array($columns_count, range(2, 10))) {
            $error = TRUE;
            break;
          }
          foreach ($row as $str) {
            if (mb_strlen($str) > 255) {
              $error = TRUE;
              break(2);
            }
          }
        }
        else {
          if (count($row) !== $columns_count) {
            $error = TRUE;
            break;
          }
        }

        $this->result[] = $row;
      }

      if (!$error) {
        break;
      }
    }

    if ($error) {
      $this->result = array();
      $this->error = 'fileNotExists';
    }

    return $this;
  }
}
