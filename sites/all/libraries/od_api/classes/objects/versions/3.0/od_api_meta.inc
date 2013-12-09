<?php

/**
 * @file
 * Contains the OdApiMeta class.
 */

class OdApiMeta30 extends OdApiMetaDefault {
  public function setUrl() {
    $this->url = $this->parent->url . '/' . $this->args['1'];
    $this->csvUrl = $this->url . '/' . 'meta.csv';
  }

  public function validateArg() {
    $parent_content = $this->parent->content;

    foreach ($parent_content['meta'] as $meta) {
      if ($meta['link'] === $this->url) {
        return TRUE;
      }
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

    $dc_identifier = $this->localNamespaceUnwrap('dc:identifier');
    $dc_title = $this->localNamespaceUnwrap('dc:title');
    $dc_description = $this->localNamespaceUnwrap('dc:description');
    $dc_owner = $this->localNamespaceUnwrap('dc:owner');
    $dc_created = $this->localNamespaceUnwrap('dc:created');
    $dc_valid = $this->localNamespaceUnwrap('dc:valid');
    $dc_subject = $this->localNamespaceUnwrap('dc:subject');
    $dc_publisher = $this->localNamespaceUnwrap('dc:publisher');
    $dc_source = $this->localNamespaceUnwrap('dc:source');

    $content = array();
    if (isset($this->rdfResult[$dc_identifier])) {
      $content['identifier'] = reset($this->rdfResult[$dc_identifier]);
    }
    if (isset($this->rdfResult[$dc_title])) {
      $content['title'] = reset($this->rdfResult[$dc_title]);
    }
    if (isset($this->rdfResult[$dc_description])) {
      $content['description'] = reset($this->rdfResult[$dc_description]);
    }
    if (isset($this->rdfResult[$dc_owner])) {
      $content['owner'] = reset($this->rdfResult[$dc_owner]);
    }
    if (isset($this->rdfResult[$dc_created])) {
      $content['created'] = reset($this->rdfResult[$dc_created]);
    }
    if (isset($this->rdfResult[$dc_valid])) {
      $content['valid'] = reset($this->rdfResult[$dc_valid]);
    }
    if (isset($this->rdfResult[$dc_subject])) {
      $content['subject'] = reset($this->rdfResult[$dc_subject]);
    }

    if (isset($this->rdfResult[$dc_publisher])) {
      $content['publisher'][] = array();
    }
    if (isset($this->rdfResult[$dc_source])) {
      $content['source'][] = array();
    }

    if (!$content) {
      return FALSE;
    }

    $this->content = $content;

    return TRUE;
  }

  public function _parseCsv() {
    if (!$this->csvResult) {
      return FALSE;
    }

    $csv_content = $this->csvResult;

    $content = array();
    if (isset($csv_content['1']['2'])) {
      $content['identifier'] = $csv_content['1']['2'];
    }
    if (isset($csv_content['2']['2'])) {
      $content['title'] = $csv_content['2']['2'];
    }
    if (isset($csv_content['3']['2'])) {
      $content['description'] = $csv_content['3']['2'];
    }
    if (isset($csv_content['4']['2'])) {
      $content['owner'] = $csv_content['4']['2'];
    }
    if (isset($csv_content['11']['2'])) {
      $content['created'] = $csv_content['11']['2'];
    }
    if (isset($csv_content['14']['2'])) {
      $content['valid'] = $csv_content['14']['2'];
    }
    if (isset($csv_content['15']['2'])) {
      $content['subject'] = $csv_content['15']['2'];
    }

    if (isset($csv_content['5']['2']) && isset($csv_content['6']['2']) && isset($csv_content['7']['2'])) {
      $content['publisher'][] = array();
    }
    if (isset($csv_content['8']['2'])) {
      $content['source'][] = array();
    }

    if (!$content) {
      return FALSE;
    }

    $this->content = $content;

    return TRUE;
  }

  public function getResult() {
    $result = $this->content;

    if (isset($result['publisher'])) {
      $publisher_api = $this->getApi('publisher');
      $result['publisher']['0'] = array(
        '#api' => $publisher_api,
      );
    }

    if (isset($result['source'])) {
      $source_api = $this->getApi('source');
      $result['source']['0'] = array(
        '#api' => $source_api,
      );
    }

    return $result;
  }
}
