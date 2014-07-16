<?php

/**
 * @file
 * Contains the OdApiMeta class.
 */

class OdApiMeta23 extends OdApiMetaDefault {
  protected function _validateArg() {
    // Check searching meta arg is valid.
    $meta_arg_is_valid = preg_match($this::REGEXP_META_IDENTIFIER, $this->arg);

    // Check searching meta exists.
    $meta_correct = $meta_arg_is_valid && isset($this->parent->content[$this::$type][$this->arg]);

    $this->setValidator($this::SITE_OPENDATA_META_ARG_IS_VALID, $meta_correct);
  }

  protected function _validateUrl() {
    // Get meta arg.
    $meta_arg = $this->arg;

    $meta_list = $this->parent;

    // Define opendata meta page url.
    $url = rtrim($meta_list->url, '/') . '/' . $meta_arg;

    // Check opendata meta page url.
    if (OdApiHelper::checkUrlSuccess($url)) {
      $this->urls[] = $url;
    }

    $this->setValidator($this::SITE_OPENDATA_META_PAGE_EXISTS, !empty($this->urls));
  }

  protected function _getFormatUrl($format) {
    $result = FALSE;
    switch ($format) {
      case $this::OBJECT_FORMAT_RDFA;
        $result = $this->url;
        break;
      case $this::OBJECT_FORMAT_CSV;
        $result = $this->url . '.csv';
        break;
    }

    return $result;
  }

  protected function _parseRdfa() {
    if ($this->parserRdfa['error']) {
      return;
    }

    $result = $this->parserRdfa['result'];

    $dc_identifier = OdApiHelper::namespaceUnwrap('dc:identifier');
    $dc_title = OdApiHelper::namespaceUnwrap('dc:title');
    $dc_description = OdApiHelper::namespaceUnwrap('dc:description');
    $dc_creator = OdApiHelper::namespaceUnwrap('dc:creator');
    $dc_created = OdApiHelper::namespaceUnwrap('dc:created');
    $dc_valid = OdApiHelper::namespaceUnwrap('dc:valid');
    $dc_subject = OdApiHelper::namespaceUnwrap('dc:subject');
    $dc_publisher = OdApiHelper::namespaceUnwrap('dc:publisher');
    $dc_source = OdApiHelper::namespaceUnwrap('dc:source');

    if (!isset($result[$dc_identifier])) {
      return;
    }

    $identifier = OdApiHelper::trim(reset($result[$dc_identifier]));
    if ($identifier !== $this->arg) {
      return;
    }

    $content = array();
    if (isset($result[$dc_identifier])) {
      $content['identifier'] = $identifier;
    }
    if (isset($result[$dc_title])) {
      $content['title'] = OdApiHelper::trim(reset($result[$dc_title]));
    }
    if (isset($result[$dc_description])) {
      $content['description'] = OdApiHelper::trim(reset($result[$dc_description]));
    }
    if (isset($result[$dc_creator])) {
      $content['creator'] = OdApiHelper::trim(reset($result[$dc_creator]));
    }
    if (isset($result[$dc_created])) {
      $content['created'] = OdApiHelper::trim(reset($result[$dc_created]));
    }
    if (isset($result[$dc_valid])) {
      $content['valid'] = OdApiHelper::trim(reset($result[$dc_valid]));
    }
    if (isset($result[$dc_subject])) {
      $content['subject'] = OdApiHelper::trim(reset($result[$dc_subject]));
    }

    if (isset($result[$dc_publisher])) {
      $content['publisher'][] = array();
    }
    if (isset($result[$dc_source])) {
      $content['data'][] = array();
    }

    // Fake property. It need for compatibility with RDFa property error on http://opendata.gosmonitor.ru/
    // where "dc:owner" was used instead "dc:creator" improperly.
    $dc_owner = OdApiHelper::namespaceUnwrap('dc:owner');
    if (isset($result[$dc_owner])) {
      $content['owner'] = OdApiHelper::trim(reset($result[$dc_owner]));
    }

    $this->content = !empty($content) ? $content : NULL;
  }

  protected function _parseMicrodata() {}

  protected function _parseJson() {}

  protected function _parseXml() {}

  protected function _parseCsv() {
    if ($this->parserCsv['error']) {
      return;
    }

    $result = $this->parserCsv['result'];

    if (!isset($result['1']['2'])) {
      return;
    }

    $identifier = OdApiHelper::trim($result['1']['2']);
    if ($identifier !== $this->arg) {
      return;
    }

    $content = array();
    if (isset($result['1']['2'])) {
      $content['identifier'] = $identifier;
    }
    if (isset($result['2']['2'])) {
      $content['title'] = OdApiHelper::trim($result['2']['2']);
    }
    if (isset($result['3']['2'])) {
      $content['description'] = OdApiHelper::trim($result['3']['2']);
    }
    if (isset($result['4']['2'])) {
      $content['creator'] = OdApiHelper::trim($result['4']['2']);
    }
    if (isset($result['11']['2'])) {
      $content['created'] = OdApiHelper::trim($result['11']['2']);
    }
    if (isset($result['14']['2'])) {
      $content['valid'] = OdApiHelper::trim($result['14']['2']);
    }
    if (isset($result['15']['2'])) {
      $content['subject'] = OdApiHelper::trim($result['15']['2']);
    }

    if (isset($result['5']['2']) || isset($result['6']['2']) || isset($result['7']['2'])) {
      $content['publisher'][] = array();
    }
    if (isset($result['8']['2'])) {
      $content['data'][] = array();
    }

    $this->content = !empty($content) ? $content : NULL;
  }

  protected function _getResult() {
    $result = $this->content;

    if (isset($result['publisher'])) {
      $publisher_api = $this->getApi(array($this::OBJECT_TYPE_IS_PUBLISHER => 'publisher'));
      $result['publisher'] = array(
        '#api' => $publisher_api,
      );
    }

    if (isset($result['data'])) {
      $source_api = $this->getApi(array($this::OBJECT_TYPE_IS_DATA_LIST => 'data'));
      $result['data'] = array(
        '#api' => $source_api,
      );
    }

    return $result;
  }
}
