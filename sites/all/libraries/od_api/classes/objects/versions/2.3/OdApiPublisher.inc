<?php

/**
 * @file
 * Contains the OdApiPublisher class.
 */

class OdApiPublisher23 extends OdApiPublisherDefault {
  protected function _validateArg() {
    // Check publisher arg is valid.
    $publisher_arg_is_valid = $this->arg === 'publisher';

    // Check searching publisher exists.
    $publisher_correct = $publisher_arg_is_valid && isset($this->parent->content[$this::OBJECT_TYPE_IS_PUBLISHER]);

    $this->setValidator($this::SITE_OPENDATA_PUBLISHER_ARG_IS_VALID, $publisher_correct);
  }

  protected function _validateUrl() {
    $dc_publisher = OdApiHelper::namespaceUnwrap('dc:publisher');

    if (isset($this->parent->parserRdfa['result'][$dc_publisher])) {
      $this->urls[] = reset($this->parent->parserRdfa['result'][$dc_publisher]);
    }
  }

  protected function _getFormatUrl($format) {
    $result = FALSE;
    switch ($format) {
      case $this::OBJECT_FORMAT_RDFA;
        $result = $this->url ? $this->url : FALSE;
        break;
      case $this::OBJECT_FORMAT_CSV;
        $result = TRUE;
        break;
    }

    return $result;
  }

  protected function _parseRdfa() {
    if ($this->parserRdfa['error']) {
      return;
    }

    $result = $this->parserRdfa['result'];

    $foaf_name = OdApiHelper::namespaceUnwrap('foaf:name');
    $foaf_phone = OdApiHelper::namespaceUnwrap('foaf:phone');
    $foaf_mbox = OdApiHelper::namespaceUnwrap('foaf:mbox');

    $content = array();
    if (isset($result[$foaf_name])) {
      $content['name'] = OdApiHelper::trim(reset($result[$foaf_name]));
    }
    if (isset($result[$foaf_phone])) {
      $content['phone'] = OdApiHelper::trim(reset($result[$foaf_phone]));
    }
    if (isset($result[$foaf_mbox])) {
      $content['mbox'] = OdApiHelper::trim(reset($result[$foaf_mbox]));
    }

    $this->content = !empty($content) ? $content : NULL;
  }

  protected function _parseMicrodata() {}

  protected function _parseJson() {}

  protected function _parseXml() {}

  protected function _parseCsv() {
    $meta = $this->parent;
    if ($meta->parserCsv['error']) {
      return;
    }

    $result = $meta->parserCsv['result'];

    $content = array();
    if (isset($result['5']['2'])) {
      $content['name'] = OdApiHelper::trim($result['5']['2']);
    }
    if (isset($result['6']['2'])) {
      $content['phone'] = OdApiHelper::trim($result['6']['2']);
    }
    if (isset($result['7']['2'])) {
      $content['mbox'] = OdApiHelper::trim($result['7']['2']);
    }

    $this->content = !empty($content) ? $content : NULL;
  }

  protected function _getResult() {
    $result = $this->content;

    return $result;
  }
}
