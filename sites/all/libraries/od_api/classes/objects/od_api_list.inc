<?php

/**
 * @file
 * Contains the OdApiList class.
 */

class OdApiList extends OdApiObject {
  public function setUrl() {
    $this->url = 'http://' . $this->args['0'] . '/opendata';
  }

  public function validate() {
    return (bool) preg_match('/^[a-zа-я0-9\-]+(\.[a-zа-я0-9\-]+)*\.[a-z]{2,4}$/', end($this->args));
  }

  public function getResult() {
    $result = array();

    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_title = $this->localNamespaceUnwrap('dc:title');

    if (!isset($this->subject[$dc_hasPart])) {
      return $result;
    }

    $result['meta'] = array();
    foreach ($this->subject[$dc_hasPart] as $item) {
      if (!isset($this->subjects[$item][$dc_title])) {
        continue;
      }

      $identifier = end(explode('/', $item));

      $result['meta'][] = array(
        '#api' => $this->baseUrl . $this->api . '/' . $identifier,
        'identifier' => $identifier,
        'title' => reset($this->subjects[$item][$dc_title]),
      );
    }

    return $result;
  }
}
