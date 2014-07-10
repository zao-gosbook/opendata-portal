<?php

/**
 * @file
 * Contains the OdApiList class.
 */

class OdApiMetaList30 extends OdApiMetaList23 {
  protected function _validateArg() {
    OdApiHelper::convertIdna($this->arg, $this->site_decoded_url, $this->site_encoded_url);

    $url_is_valid = preg_match($this::REGEXP_META_LIST_URL, $this->site_decoded_url);

    $this->setValidator($this::SITE_OPENDATA_ARG_IS_VALID, $url_is_valid);
  }

  protected function _validateUrl() {
    // Check main page url.
    $site_main_page_exists = OdApiHelper::checkUrlSuccess($this->site_encoded_url);
    $this->setValidator($this::SITE_MAIN_PAGE_EXISTS, $site_main_page_exists);

    if ($site_main_page_exists === FALSE) {
      return;
    }

    // Define opendata page url.
    $parsed_url = parse_url($this->site_encoded_url);
    $portal_url = $parsed_url['scheme'] . '://' . 'opendata.' . $parsed_url['host'] . '/';
    $section_url = $parsed_url['scheme'] . '://' . $parsed_url['host'] . '/' . 'opendata';

    if (OdApiHelper::checkUrlSuccess($portal_url)) {
      $this->urls[] = $portal_url;
    }
    if (OdApiHelper::checkUrlSuccess($section_url)) {
      $this->urls[] = $section_url;
    }

    $this->setValidator($this::SITE_OPENDATA_PAGE_EXISTS, !empty($this->urls));
  }

  protected function _getFormatUrl($format) {
    $result = FALSE;
    switch ($format) {
      case $this::OBJECT_FORMAT_RDFA;
        $result = $this->url;
        break;
      case $this::OBJECT_FORMAT_JSON;
        $result = rtrim($this->url, '/') . '/list.json';
        break;
      case $this::OBJECT_FORMAT_XML;
        $result = rtrim($this->url, '/') . '/list.xml';
        break;
      case $this::OBJECT_FORMAT_CSV;
        $result = rtrim($this->url, '/') . '/list.csv';
        break;
    }

    return $result;
  }

  protected function _parseCsv() {
    // Check CSV object existing.
    if ($this->parserCsv['error']) {
      switch ($this->parserCsv['error']) {
        case 'fileNotExists':
          $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
          break;
      }
      return;
    }

    $result = $this->parserCsv['result'];

    $header = array_shift($result);
    $index_property = array_search('property', $header);
    $index_title = array_search('title', $header);
    $index_value = array_search('value', $header);
    $index_format = array_search('format', $header);

    if (in_array(FALSE, array($index_property, $index_title, $index_value, $index_format), TRUE)) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    foreach ($result as $key => $property) {
      if (!isset($property[$index_property])) {
        unset($result[$key]);
        continue;
      }

      $result[$property[$index_property]] = array(
        'title' => isset($property[$index_title]) ? $property[$index_title] : FALSE,
        'value' => isset($property[$index_value]) ? $property[$index_value] : FALSE,
        'format' => isset($property[$index_format]) ? $property[$index_format] : FALSE,
      );
      unset($result[$key]);
    }

    if (!isset($result['standardversion']) || basename($result['standardversion']['value']) !== $this->version) {
      return;
    }

    $content = array();
    foreach ($result as $key => $value) {
      if (!preg_match(OdApiMeta30::REGEXP_META_IDENTIFIER, $key)) {
        continue;
      }

      $identifier = OdApiHelper::trim($key);
      $content[$identifier] = array(
        'identifier' => $identifier,
        'title' => OdApiHelper::trim($value['title']),
        '#value' => OdApiHelper::trim($value['value']),
        '#format' => OdApiHelper::trim($value['format']),
      );
    }

    $this->content = !empty($content) ? array('meta' => $content) : NULL;
  }
}
