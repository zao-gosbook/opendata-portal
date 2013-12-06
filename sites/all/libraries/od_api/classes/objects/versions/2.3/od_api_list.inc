<?php

/**
 * @file
 * Contains the OdApiList class.
 */

class OdApiList23 extends OdApiListDefault {
  public function validateArg() {
    $list_arg = &$this->args[OdApiObject::OBJECT_TYPE_IS_LIST];

    $this::processArg($list_arg);

    // Define main page url.
    $this->od_api->main_page_url = $list_arg;

    // Fix args.
    $this->args[OdApiObject::OBJECT_TYPE_IS_LIST] = $list_arg;

    $url_is_valid = (bool) preg_match('/^https?:\/\/[a-zа-я0-9\-]+(\.[a-zа-я0-9\-]+)*\.[a-z]{2,4}\/?$/', $list_arg);

    $this->setValidator($this::SITE_OPENDATA_ARG_IS_VALID, $url_is_valid);
  }

  public function validateVersion() {
    return TRUE;
  }

  public function setPossibleUrls() {
    // Collect available urls.
    $urls = array();

    // Define opendata page url.
    $this->url = $this->od_api->main_page_url . 'opendata';
    $this->od_api->opendata_page_url = $this->url;

    // Visual representation.
    $urls['semantic'] = $this->url;

    // File url template.
    $file_url = $this->url . '/opendatalist.!extension';

    // File CSV representation.
    $urls['file_csv'] = strtr($file_url, array('!extension' => 'csv'));

    // File XML representation.
    $urls['file_xml'] = strtr($file_url, array('!extension' => 'xml'));

    $this->urls = $urls;
  }

  public function validateObject() {
    // Check main page url.
    $site_main_page_exists = $this->checkUrl($this->od_api->main_page_url);
    $this->setValidator($this::SITE_MAIN_PAGE_EXISTS, $site_main_page_exists);

    // Check opendata page url.
    $site_opendata_page_exists = $this->checkUrl($this->url);
    $this->setValidator($this::SITE_OPENDATA_PAGE_EXISTS, $site_opendata_page_exists);

    return $this->checkErrorExists();
  }

  public function _parseRdf() {
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
      if (!isset($this->parserRDFa->subjects[$item][$dc_title])) {
        continue;
      }

      $content['meta'][] = array(
        'identifier' => end(explode('/', rtrim($item, '/'))),
        'title' => reset($this->parserRDFa->subjects[$item][$dc_title]),
      );
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_RDFA_DETECTED, TRUE);
  }

  public function _parseCsv() {
    // Check CSV object existing.
    if ($this->parserCSV->error) {
      switch ($this->parserCSV->error) {
        case 'fileNotExists':
          $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
          break;
        case 'notUtf8':
          $this->setValidator($this::FORMAT_CSV_IS_UTF8, FALSE);
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
      $title_column = 1;
      // Find url column by url filter.
      $url_column = NULL;
      if ($url_column === NULL) {
        foreach ($row as $index => $col) {
          if (filter_var($col, FILTER_VALIDATE_URL) !== FALSE) {
            $url_column = $index;
            break;
          }
        }
      }

      if ($url_column === NULL) {
        $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
        return;
      }

      $content['meta'][] = array(
        'identifier' => end(explode('/', rtrim($row[$url_column], '/'))),
        'title' => $row[$title_column],
      );
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_CSV_DETECTED, TRUE);
  }

  public function getResult() {
    $result = array(
      '#version' => '2.3',
    );

    $result += $this->content;

    if (!empty($result['meta'])) {
      foreach($result['meta'] as &$list) {
        $meta_api = $this->getApi(array(OdApiObject::OBJECT_TYPE_IS_META => $list['identifier']));

        $list['#api'] = $meta_api;
      }
    }

    return $result;
  }
}
