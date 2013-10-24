<?php

/**
 * @file
 * Contains the OdApiData class.
 */

class OdApiData extends OdApiObject {
  public $parentClass = 'OdApiSource';

  public function setUrl() {
    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_created = $this->localNamespaceUnwrap('dc:created');

    if (isset($this->parent->subjects[$this->parent->url][$dc_hasPart])) {
      foreach ($this->parent->subjects[$this->parent->url][$dc_hasPart] as $item) {
        if (isset($this->parent->subjects[$item][$dc_created])) {
          $created = reset($this->parent->subjects[$item][$dc_created]);
          $date = new DateTime($created);
          $data_arg = $date->format('Y-m-d');

          if ($data_arg === end($this->args)) {
            $this->url = $item;
            break;
          }
        }
      }
    }
  }

  public function validate() {
    return (bool) preg_match('/^[0-9]{4}-[0-9]{2}-[0-9]{2}$/', end($this->args));
  }

  public function getResult() {
    $result = array();

    $dc_source = $this->localNamespaceUnwrap('dc:source');
    $dc_format = $this->localNamespaceUnwrap('dc:format');
    $dc_created = $this->localNamespaceUnwrap('dc:created');
    $dc_provenance = $this->localNamespaceUnwrap('dc:provenance');
    $dc_conformsTo = $this->localNamespaceUnwrap('dc:conformsTo');

    if (isset($this->subject[$dc_source])) {
      $result['source'] = reset($this->subject[$dc_source]);
    }
    if (isset($this->subject[$dc_format])) {
      $result['format'] = reset($this->subject[$dc_format]);
    }
    if (isset($this->subject[$dc_created])) {
      $result['created'] = reset($this->subject[$dc_created]);
    }
    if (isset($this->subject[$dc_provenance])) {
      $result['provenance'] = reset($this->subject[$dc_provenance]);
    }
    if (isset($this->subject[$dc_conformsTo])) {
      $result['conformsTo'] = array(
        '#api' => $this->baseUrl . $this->api . '/' . 'structure',
      );
    }

    return $result;
  }
}
