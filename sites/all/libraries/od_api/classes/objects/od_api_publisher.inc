<?php

/**
 * @file
 * Contains the OdApiPublisher class.
 */

class OdApiPublisher extends OdApiObject {
  public $parentClass = 'OdApiMeta';

  public function setUrl() {
    $dc_publisher = $this->localNamespaceUnwrap('dc:publisher');

    if (isset($this->parent->subjects[$this->parent->url][$dc_publisher])) {
      $this->url = reset($this->parent->subjects[$this->parent->url][$dc_publisher]);
    }
  }

  public function validate() {
    return (bool) (end($this->args) === 'publisher');
  }

  public function getResult() {
    $result = array();

    $foaf_name = $this->localNamespaceUnwrap('foaf:name');
    $foaf_phone = $this->localNamespaceUnwrap('foaf:phone');
    $foaf_mbox = $this->localNamespaceUnwrap('foaf:mbox');

    if (isset($this->subject[$foaf_name])) {
      $result['name'] = reset($this->subject[$foaf_name]);
    }
    if (isset($this->subject[$foaf_phone])) {
      $result['phone'] = reset($this->subject[$foaf_phone]);
    }
    if (isset($this->subject[$foaf_mbox])) {
      $result['mbox'] = reset($this->subject[$foaf_mbox]);
    }

    return $result;
  }
}
