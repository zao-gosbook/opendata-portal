<?php

/**
 * @file
 * Contains the OdApiMeta class.
 */

class OdApiMeta30 extends OdApiMeta23 {
  protected function _getFormatUrl($format) {
    $result = FALSE;
    switch ($format) {
      case $this::OBJECT_FORMAT_RDFA;
        $result = $this->url;
        break;
      case $this::OBJECT_FORMAT_CSV;
        $meta = $this->parent->content['meta'][$this->arg];
        $result = $meta['#value'];
        break;
    }

    return $result;
  }

  protected function _parseRdfa() {
    parent::_parseRdfa();

    if (empty($this->content)) {
      return;
    }

    if (!isset($this->content['valid'])) {
      unset($this->content['valid']);
    }
  }

  protected function _parseCsv() {
    if ($this->parserCsv['error']) {
      return;
    }

    $result = $this->parserCsv['result'];

    $header = array_shift($result);
    $index_property = array_search('property', $header);
    $index_value = array_search('value', $header);

    if (in_array(FALSE, array($index_property, $index_value), TRUE)) {
      return;
    }

    foreach ($result as $key => $property) {
      if (!isset($property[$index_property])) {
        unset($result[$key]);
        continue;
      }

      $result[$property[$index_property]] = array(
        'value' => isset($property[$index_value]) ? $property[$index_value] : NULL,
      );
      unset($result[$key]);
    }

    if (!isset($result['standardversion']) || basename($result['standardversion']['value']) !== $this->version) {
      return;
    }

    if (!isset($result['identifier']['value'])) {
      return;
    }

    $identifier = OdApiHelper::trim($result['identifier']['value']);
    if ($identifier !== $this->arg) {
      return;
    }

    $this->csvResult = $result; // @todo
    $content = array();
    if (isset($result['identifier']['value'])) {
      $content['identifier'] = $identifier;
    }
    if (isset($result['title']['value'])) {
      $content['title'] = OdApiHelper::trim($result['title']['value']);
    }
    if (isset($result['description']['value'])) {
      $content['description'] = OdApiHelper::trim($result['description']['value']);
    }
    if (isset($result['creator']['value'])) {
      $content['creator'] = OdApiHelper::trim($result['creator']['value']);
    }
    if (isset($result['created']['value'])) {
      $content['created'] = OdApiHelper::trim($result['created']['value']);
    }
    if (isset($result['subject']['value'])) {
      $content['subject'] = OdApiHelper::trim($result['subject']['value']);
    }

    if (isset($result['publishername']['value']) || isset($result['publisherphone']['value']) || isset($result['publishermbox']['value'])) {
      $content['publisher'][] = array();
    }

    foreach ($result as $key => $value) {
      if (preg_match(OdApiData30::REGEXP_CSV_DATA, $key)) {
        $content['data'][] = array();
        break;
      }
    }

    $this->content = !empty($content) ? $content : NULL;
  }
}
