<?php

/**
 * @file
 * Contains the OdApiData class.
 */

class OdApiData30 extends OdApiDataDefault {
  public function setUrl() {
    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_created = $this->localNamespaceUnwrap('dc:created');

    if (isset($this->parent->rdfSubjects[$this->parent->url][$dc_hasPart])) {
      foreach ($this->parent->rdfSubjects[$this->parent->url][$dc_hasPart] as $item) {
        if (isset($this->parent->rdfSubjects[$item][$dc_created])) {
          $created = reset($this->parent->rdfSubjects[$item][$dc_created]);
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

  public function validateArg() {
    $parent = $this->parent;
    foreach ($parent->content['data'] as $data) {
      if (isset($data['created'])) {
        $date = new DateTime($data['created']);
        $data_created = $date->format('Y-m-d');

        if ($data_created === end($this->args)) {
          return TRUE;
        }
      }
      if (isset($data['version'])) {
        if ($data['version'] === end($this->args)) {
          return TRUE;
        }
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

    $dc_source = $this->localNamespaceUnwrap('dc:source');
    $dc_format = $this->localNamespaceUnwrap('dc:format');
    $dc_created = $this->localNamespaceUnwrap('dc:created');
    $dc_provenance = $this->localNamespaceUnwrap('dc:provenance');
    $dc_conformsTo = $this->localNamespaceUnwrap('dc:conformsTo');

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
    if (isset($this->rdfResult[$dc_provenance])) {
      $content['provenance'] = reset($this->rdfResult[$dc_provenance]);
    }
    if (isset($this->rdfResult[$dc_conformsTo])) {
      $content['structure'][] = array();
    }

    if (!$content) {
      return FALSE;
    }

    $this->content = $content;

    return TRUE;
  }

  public function _parseCsv() {
    $source = $this->parent;
    $meta = $source->parent;
    $csv_content = $meta->csvResult;

    if (!$csv_content) {
      return FALSE;
    }

    $content = array();
    if (isset($csv_content['8']['2'])) {
      $content['source'] = $csv_content['8']['2'];
    }
    if (isset($csv_content['9']['2'])) {
      $content['format'] = $csv_content['9']['2'];
    }
    if (isset($csv_content['12']['2'])) {
      $content['created'] = $csv_content['12']['2'];
    }
    if (isset($csv_content['13']['2'])) {
      $content['provenance'] = $csv_content['13']['2'];
    }
    if (isset($csv_content['10']['2'])) {
      $content['structure'][] = array();
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
