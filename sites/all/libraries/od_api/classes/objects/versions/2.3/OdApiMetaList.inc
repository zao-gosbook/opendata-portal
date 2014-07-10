<?php

/**
 * @file
 * Contains the OdApiList class.
 */

class OdApiMetaList23 extends OdApiMetaListDefault {
  protected function _validateArg() {
    OdApiHelper::convertIdna($this->arg, $this->site_decoded_url, $this->site_encoded_url);

    $url_is_valid = preg_match($this::REGEXP_META_LIST_URL, $this->site_decoded_url);

    if (isset($this->odApi->vars['semantic_list_url'])) {
      $this::processArg($this->odApi->vars['semantic_list_url']);
      OdApiHelper::convertIdna($this->arg, $decoded_semantic_url, $encoded_semantic_url);
      $semantic_url_is_valid = preg_match($this::REGEXP_META_LIST_URL, $decoded_semantic_url);
    }
    else {
      $semantic_url_is_valid = TRUE;
    }

    $this->setValidator($this::SITE_OPENDATA_ARG_IS_VALID, $url_is_valid && $semantic_url_is_valid);
  }

  protected function _validateUrl() {
    // Check main page url.
    $site_main_page_exists = OdApiHelper::checkUrlSuccess($this->site_encoded_url);
    $this->setValidator($this::SITE_MAIN_PAGE_EXISTS, $site_main_page_exists);

    if ($site_main_page_exists === FALSE) {
      return;
    }

    // Define opendata page url.
    $url = $this->site_encoded_url . 'opendata';

    // Check opendata page url.
    if (OdApiHelper::checkUrlSuccess($url)) {
      $this->urls[] = $url;
    }

    $this->setValidator($this::SITE_OPENDATA_PAGE_EXISTS, !empty($this->urls));
  }

  protected function _getFormatUrl($format) {
    $result = FALSE;
    switch ($format) {
      case $this::OBJECT_FORMAT_RDFA;
        $result = isset($this->odApi->vars['semantic_list_url']) ? $this->odApi->vars['semantic_list_url'] : $this->url;
        break;
      case $this::OBJECT_FORMAT_CSV;
        $result = $this->url . '/opendatalist.csv';
        break;
    }

    return $result;
  }

  protected function _parseRdfa() {
    if ($this->parserRdfa['error']) {
      return;
    }

    $result = $this->parserRdfa['result'];

    $rdf_type = OdApiHelper::namespaceUnwrap('rdf:type');
    $dc_hasPart = OdApiHelper::namespaceUnwrap('dc:hasPart');
    $dc_title = OdApiHelper::namespaceUnwrap('dc:title');
    $dc_Collection = OdApiHelper::namespaceUnwrap('dc:Collection');

    if (!isset($result[$rdf_type]) || !in_array($dc_Collection, $result[$rdf_type])) {
      return;
    }

    if (!isset($result[$dc_hasPart])) {
      return;
    }

    $content = array();
    foreach ($result[$dc_hasPart] as $item) {
      $item = rtrim(OdApiHelper::trim($item), '/');
      if (!isset($this->parserRdfa['subjects'][$item])) {
        continue;
      }

      if (!isset($this->parserRdfa['subjects'][$item][$dc_title])) {
        continue;
      }

      $title = OdApiHelper::trim(reset($this->parserRdfa['subjects'][$item][$dc_title]));
      if (empty($title)) {
        continue;
      }

      $identifier = end(explode('/', $item));
      $content[$identifier] = array(
        'identifier' => $identifier,
        'title' => $title,
      );
    }

    $this->content = !empty($content) ? array('meta' => $content) : NULL;
  }

  protected function _parseMicrodata() {}

  protected function _parseJson() {}

  protected function _parseXml() {}

  protected function _parseCsv() {
    if ($this->parserCsv['error']) {
      return;
    }

    $result = $this->parserCsv['result'];

    $content = array();
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
          return;
        }
      }

      $identifier = end(explode('/', rtrim(OdApiHelper::trim($row[$url_column]), '/')));
      $content[$identifier] = array(
        'identifier' => $identifier,
        'title' => $title,
      );
    }

    $this->content = !empty($content) ? array('meta' => $content) : NULL;
  }

  protected function _getResult() {
    $result = $this->content;

    foreach($result['meta'] as &$list) {
      $meta_api = $this->getApi(array($this::OBJECT_TYPE_IS_META => $list['identifier']));

      $list['#api'] = $meta_api;
    }

    return $result;
  }
}
