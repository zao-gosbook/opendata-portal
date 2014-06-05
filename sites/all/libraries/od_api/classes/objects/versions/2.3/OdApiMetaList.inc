<?php

/**
 * @file
 * Contains the OdApiList class.
 */

class OdApiMetaList23 extends OdApiMetaListDefault {
  const REGEXP_URL = '/^https?:\/\/[a-zа-яё0-9\-]+(\.[a-zа-яё0-9\-]+)*\.[a-zа-яё]{2,4}\/$/u';

  public function validateArg() {
    $this::processArg($this->args[$this::OBJECT_TYPE_IS_META_LIST], $decoded_url, $encoded_url);

    // Define main page url.
    $this->od_api->main_url = $encoded_url;

    $url_is_valid = (bool) preg_match($this::REGEXP_URL, $decoded_url);

    if (isset($this->od_api->vars['semantic_list_url'])) {
      $this::processArg($this->od_api->vars['semantic_list_url'], $decoded_semantic_url, $encoded_semantic_url);
      $semantic_url_is_valid = (bool) preg_match($this::REGEXP_URL, $decoded_semantic_url);
    }
    else {
      $semantic_url_is_valid = TRUE;
    }

    $this->setValidator($this::SITE_OPENDATA_ARG_IS_VALID, $url_is_valid && $semantic_url_is_valid);
  }

  public function validateVersion() {
    return TRUE;
  }

  public function setPossibleUrls() {
    // Collect available urls.
    $urls = array();

    // Define opendata page url.
    $this->url = $this->od_api->main_url . 'opendata';
    $this->od_api->list_url = $this->url;

    // Visual representation.
    $urls['semantic'] = isset($this->od_api->vars['semantic_list_url']) ? $this->od_api->vars['semantic_list_url'] : $this->url;

    // File url template.
    $file_url = $this->url . '/opendatalist.!extension';

    // File CSV representation.
    $urls['file_csv'] = strtr($file_url, array('!extension' => 'csv'));

    $this->urls = $urls;
  }

  public function validateObject() {
    // Check main page url.
    $site_main_page_exists = $this->checkUrlSuccess($this->od_api->main_url);
    $this->setValidator($this::SITE_MAIN_PAGE_EXISTS, $site_main_page_exists);

    if ($site_main_page_exists === FALSE) {
      return;
    }

    // Check opendata page url.
    $site_opendata_page_exists = $this->checkUrlSuccess($this->url);
    if (!$site_opendata_page_exists) {
      $site_opendata_page_exists = $this->checkUrlSuccess($this->url . '/');
    }
    $this->setValidator($this::SITE_OPENDATA_PAGE_EXISTS, $site_opendata_page_exists);
  }

  protected function _parseRdf() {
    // Check RDFa object existing.
    if ($this->parserRDFa->error) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    // Declare used RDFa types.
    $rdf_type = $this->localNamespaceUnwrap('rdf:type');
    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_title = $this->localNamespaceUnwrap('dc:title');
    $dc_Collection = $this->localNamespaceUnwrap('dc:Collection');

    // If object is not DC Collection.
    if (!isset($this->parserRDFa->result[$rdf_type]) || !in_array($dc_Collection, $this->parserRDFa->result[$rdf_type])) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $content = array();
    if (!isset($this->parserRDFa->result[$dc_hasPart])) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $content['meta'] = array();
    foreach ($this->parserRDFa->result[$dc_hasPart] as $item) {
      $item = rtrim(OdApiHelper::trim($item), '/');
      if (!isset($this->parserRDFa->subjects[$item])) {
        continue;
      }

      if (!isset($this->parserRDFa->subjects[$item][$dc_title])) {
        continue;
      }

      $title = OdApiHelper::trim(reset($this->parserRDFa->subjects[$item][$dc_title]));
      if (empty($title)) {
        continue;
      }

      $content['meta'][] = array(
        'identifier' => end(explode('/', $item)),
        'title' => $title,
      );
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_RDFA_DETECTED, TRUE);
  }

  protected function _parseCsv() {
    // Check CSV object existing.
    if ($this->parserCSV->error) {
      switch ($this->parserCSV->error) {
        case 'fileNotExists':
          $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
          break;
      }
      return;
    }

    $result = $this->parserCSV->result;

    $content = array();
    $content['meta'] = array();

    $row_counter = 0;
    foreach ($result as $row) {
      $row_counter++;

      // Skip header.
      if ($row_counter === 1) {
        continue;
      }

      // Define title like second column of row.
      if (!isset($title_column)) {
        $title_column = 1;
      }

      $title = OdApiHelper::trim($row[$title_column]);
      if (empty($title)) {
        continue;
      }

      // Find url column by url filter.
      if (!isset($url_column)) {
        foreach ($row as $index => $col) {
          if (filter_var($col, FILTER_VALIDATE_URL) !== FALSE) {
            $url_column = $index;
            break;
          }
        }

        if (!isset($url_column)) {
          $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
          return;
        }
      }

      $content['meta'][] = array(
        'identifier' => end(explode('/', rtrim(OdApiHelper::trim($row[$url_column]), '/'))),
        'title' => $title,
      );
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_CSV_DETECTED, TRUE);
  }

  protected function _getResult() {
    $result = $this->content;

    if (!empty($result['meta'])) {
      foreach($result['meta'] as &$list) {
        $meta_api = $this->getApi(array($this::OBJECT_TYPE_IS_META => $list['identifier']));

        $list['#api'] = $meta_api;
      }
    }

    return $result;
  }
}
