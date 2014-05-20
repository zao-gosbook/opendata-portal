<?php

/**
 * @file
 * Contains the OdApiPublisher class.
 */

class OdApiPublisher23 extends OdApiPublisherDefault {
  public function validateArg() {
    // Check publisher arg is valid.
    $publisher_arg_is_valid = $this->args[$this::OBJECT_TYPE_IS_PUBLISHER] === 'publisher';
    $this->setValidator($this::SITE_OPENDATA_PUBLISHER_ARG_IS_VALID, $publisher_arg_is_valid);
  }

  public function validateVersion() {
    return TRUE;
  }

  public function setPossibleUrls() {
    // Collect available urls.
    $urls = array();

    $dc_publisher = $this->localNamespaceUnwrap('dc:publisher');

    if (isset($this->parent->parserRDFa->subjects[$this->parent->url][$dc_publisher])) {
      $this->url = reset($this->parent->parserRDFa->subjects[$this->parent->url][$dc_publisher]);
      $urls['semantic'] = $this->url;
    }

    $urls['file_csv'] = TRUE;

    $this->urls = $urls;
  }

  public function validateObject() {}

  protected function _parseRdf() {
    // Check RDFa object existing.
    if ($this->parserRDFa->error) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $foaf_name = $this->localNamespaceUnwrap('foaf:name');
    $foaf_phone = $this->localNamespaceUnwrap('foaf:phone');
    $foaf_mbox = $this->localNamespaceUnwrap('foaf:mbox');

    $content = array();
    if (isset($this->parserRDFa->result[$foaf_name])) {
      $content['name'] = OdApiHelper::trim(reset($this->parserRDFa->result[$foaf_name]));
    }
    if (isset($this->parserRDFa->result[$foaf_phone])) {
      $content['phone'] = OdApiHelper::trim(reset($this->parserRDFa->result[$foaf_phone]));
    }
    if (isset($this->parserRDFa->result[$foaf_mbox])) {
      $content['mbox'] = OdApiHelper::trim(reset($this->parserRDFa->result[$foaf_mbox]));
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_RDFA_DETECTED, TRUE);
  }

  protected function _parseCsv() {
    // Check RDFa object existing.
    $meta = $this->parent;
    if ($meta->format !== $this::OBJECT_FORMAT_CSV || $meta->parserCSV->error) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $result = $meta->parserCSV->result;

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

    if (!$content) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }
    $this->content = $content;

    $this->setValidator($this::FORMAT_CSV_DETECTED, TRUE);
  }

  protected function _getResult() {
    $result = $this->content;

    return $result;
  }
}
