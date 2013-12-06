<?php

/**
 * @file
 * Contains the OdApiPublisher class.
 */

class OdApiPublisher30 extends OdApiPublisherDefault {
  public function setUrl() {
    $dc_publisher = $this->localNamespaceUnwrap('dc:publisher');

    if (isset($this->parent->rdfSubjects[$this->parent->url][$dc_publisher])) {
      $this->url = reset($this->parent->rdfSubjects[$this->parent->url][$dc_publisher]);
    }
  }

  public function validateArg() {
    $parent_content = $this->parent->content;

    if (isset($parent_content) && end($this->args) === 'publisher') {
      return TRUE;
    }

    return FALSE;
  }

  public function validateObject() {
    return TRUE;
  }

  public function _parseRdf() {
    if (!$this->rdfResult) {
      return FALSE;
    }

    $foaf_name = $this->localNamespaceUnwrap('foaf:name');
    $foaf_phone = $this->localNamespaceUnwrap('foaf:phone');
    $foaf_mbox = $this->localNamespaceUnwrap('foaf:mbox');

    $content = array();
    if (isset($this->rdfResult[$foaf_name])) {
      $content['name'] = reset($this->rdfResult[$foaf_name]);
    }
    if (isset($this->rdfResult[$foaf_phone])) {
      $content['phone'] = reset($this->rdfResult[$foaf_phone]);
    }
    if (isset($this->rdfResult[$foaf_mbox])) {
      $content['mbox'] = reset($this->rdfResult[$foaf_mbox]);
    }

    if (!$content) {
      return FALSE;
    }

    $this->content = $content;

    return TRUE;
  }

  public function _parseCsv() {
    if (!$this->parent->csvResult) {
      return FALSE;
    }

    $csv_content = $this->parent->csvResult;

    $content = array();
    if (isset($csv_content['5']['2'])) {
      $content['name'] = $csv_content['5']['2'];
    }
    if (isset($csv_content['6']['2'])) {
      $content['phone'] = $csv_content['6']['2'];
    }
    if (isset($csv_content['7']['2'])) {
      $content['mbox'] = $csv_content['7']['2'];
    }

    if (!$content) {
      return FALSE;
    }

    $this->content = $content;

    return TRUE;
  }

  public function getResult() {
    $result = $this->content;

    return $result;
  }
}
