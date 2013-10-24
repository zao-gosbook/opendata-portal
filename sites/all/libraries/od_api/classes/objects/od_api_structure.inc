<?php

/**
 * @file
 * Contains the OdApiStructure class.
 */

class OdApiStructure extends OdApiObject {
  public $parentClass = 'OdApiData';

  public function setUrl() {
    $dc_conformsTo = $this->localNamespaceUnwrap('dc:conformsTo');

    if (isset($this->parent->subjects[$this->parent->url][$dc_conformsTo])) {
      $this->url = reset($this->parent->subjects[$this->parent->url][$dc_conformsTo]);
    }
  }

  public function validate() {
    return (bool) (end($this->args) === 'conforms-to');
  }

  public function getResult() {
    $result = array();

    $dc_source = $this->localNamespaceUnwrap('dc:source');
    $dc_format = $this->localNamespaceUnwrap('dc:format');
    $dc_created = $this->localNamespaceUnwrap('dc:created');

    if (isset($this->subject[$dc_source])) {
      $result['source'] = reset($this->subject[$dc_source]);
    }
    if (isset($this->subject[$dc_format])) {
      $result['format'] = reset($this->subject[$dc_format]);
    }
    if (isset($this->subject[$dc_created])) {
      $result['created'] = reset($this->subject[$dc_created]);
    }

    return $result;
  }
}
