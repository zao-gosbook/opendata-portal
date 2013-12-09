<?php

/**
 * @file
 * Contains the OdApiStructure class.
 */

class OdApiStructure30 extends OdApiStructureDefault {
  public function setUrl() {
    $dc_conformsTo = $this->localNamespaceUnwrap('dc:conformsTo');

    if (isset($this->parent->rdfSubjects[$this->parent->url][$dc_conformsTo])) {
      $this->url = reset($this->parent->rdfSubjects[$this->parent->url][$dc_conformsTo]);
    }
  }

  public function validateArg() {
    $parent_content = $this->parent->content;

    if (isset($parent_content) && end($this->args) === 'structure') {
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

    $dc_source = $this->localNamespaceUnwrap('dc:source');
    $dc_format = $this->localNamespaceUnwrap('dc:format');
    $dc_created = $this->localNamespaceUnwrap('dc:created');

    $content = array();
    if (isset($this->rdfResult[$dc_source])) {
      $content['source'] = reset($this->rdfResult[$dc_source]);
    }
    if (isset($this->rdfResult[$dc_format])) {
      $content['format'] = reset($this->rdfResult[$dc_format]);
    }
    if (isset($this->rdfResult[$dc_created])) {
      $content['created'] = reset($this->rdfResult[$dc_created]);
    }

    if (!$content) {
      return FALSE;
    }

    $this->content = $content;

    return TRUE;
  }

  public function _parseCsv() {
    $data = $this->parent;
    $source = $data->parent;
    $meta = $source->parent;
    $csv_content = $meta->csvResult;

    if (!$csv_content) {
      return FALSE;
    }

    $content = array();
    if (isset($csv_content['10']['2'])) {
      $content['source'] = $csv_content['10']['2'];
    }

    if (!$content) {
      return FALSE;
    }

    $this->content = $content;

    return TRUE;
  }

  public function getResult() {
    $result = $this->content;

    if (isset($result['structure'])) {
      $structure_api = $this->getApi('structure');

      $result['structure']['0'] = array(
        '#api' => $structure_api,
      );
    }

    return $result;
  }
}
