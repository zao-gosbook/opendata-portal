<?php

/**
 * @file
 * Contains the OdApiMeta class.
 */

class OdApiMeta extends OdApiObject {
  public $parentClass = 'OdApiList';

  public function setUrl() {
    $this->url = 'http://' . $this->args['0'] . '/opendata/' . $this->args['1'];
  }

  public function validate() {
    $parent = $this->parent;
    $url = $this->url;

    return isset($parent->subjects[$url]);
  }

  public function getResult() {
    $result = array();

    $dc_identifier = $this->localNamespaceUnwrap('dc:identifier');
    $dc_title = $this->localNamespaceUnwrap('dc:title');
    $dc_description = $this->localNamespaceUnwrap('dc:description');
    $dc_owner = $this->localNamespaceUnwrap('dc:owner');
    $dc_created = $this->localNamespaceUnwrap('dc:created');
    $dc_valid = $this->localNamespaceUnwrap('dc:valid');
    $dc_subject = $this->localNamespaceUnwrap('dc:subject');
    $dc_publisher = $this->localNamespaceUnwrap('dc:publisher');
    $dc_source = $this->localNamespaceUnwrap('dc:source');

    if (isset($this->subject[$dc_identifier])) {
      $result['identifier'] = reset($this->subject[$dc_identifier]);
    }
    if (isset($this->subject[$dc_title])) {
      $result['title'] = reset($this->subject[$dc_title]);
    }
    if (isset($this->subject[$dc_description])) {
      $result['description'] = reset($this->subject[$dc_description]);
    }
    if (isset($this->subject[$dc_owner])) {
      $result['owner'] = reset($this->subject[$dc_owner]);
    }
    if (isset($this->subject[$dc_created])) {
      $result['created'] = reset($this->subject[$dc_created]);
    }
    if (isset($this->subject[$dc_valid])) {
      $result['valid'] = reset($this->subject[$dc_valid]);
    }
    if (isset($this->subject[$dc_subject])) {
      $result['subject'] = reset($this->subject[$dc_subject]);
    }

    if (isset($this->subject[$dc_publisher])) {
      $publisher_api = $this->api . '/' . 'publisher';
      $result['publisher'] = array(
        '#api' => $this->baseUrl . $publisher_api,
      );
    }
    if (isset($this->subject[$dc_source])) {
      $source_api = $this->api . '/' . 'source';
      $result['source'] = array(
        '#api' => $this->baseUrl . $source_api,
      );
    }

    return $result;
  }
}
