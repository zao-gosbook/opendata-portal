<?php

/**
 * @file
 * Contains the OdApiSource class.
 */

class OdApiSource extends OdApiObject {
  public $parentClass = 'OdApiMeta';

  public function setUrl() {
    $dc_source = $this->localNamespaceUnwrap('dc:source');

    if (isset($this->parent->subjects[$this->parent->url][$dc_source])) {
      $this->url = reset($this->parent->subjects[$this->parent->url][$dc_source]);
    }
  }

  public function validate() {
    return (bool) (end($this->args) === 'source');
  }

  public function getResult() {
    $result = array();

    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_created = $this->localNamespaceUnwrap('dc:created');

    $result['data'] = array();
    if (isset($this->subject[$dc_hasPart])) {
      foreach ($this->subject[$dc_hasPart] as $item) {
        if (isset($this->subjects[$item][$dc_created])) {
          $created = reset($this->subjects[$item][$dc_created]);
          $date = new DateTime($created);
          $data_arg = $date->format('Y-m-d');

          $result['data'][] = array(
            '#api' => $this->baseUrl . $this->api . '/' . $data_arg,
            'created' => $created,
          );
        }
      }
    }

    return $result;
  }
}
