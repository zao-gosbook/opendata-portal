<?php

/**
 * @file
 * Contains the OdApiSource class.
 */

class OdApiSource30 extends OdApiSourceDefault {
  public function setUrl() {
    $dc_source = $this->localNamespaceUnwrap('dc:source');

    if (isset($this->parent->rdfSubjects[$this->parent->url][$dc_source])) {
      $this->url = reset($this->parent->rdfSubjects[$this->parent->url][$dc_source]);
    }
  }

  public function validateArg() {
    $parent_content = $this->parent->content;

    if (isset($parent_content) && end($this->args) === 'source') {
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

    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_created = $this->localNamespaceUnwrap('dc:created');

    $content = array();
    $content['data'] = array();
    if (isset($this->rdfResult[$dc_hasPart])) {
      foreach ($this->rdfResult[$dc_hasPart] as $item) {
        if (isset($this->rdfSubjects[$item][$dc_created])) {
          $created = reset($this->rdfSubjects[$item][$dc_created]);

          $content['data'][] = array(
            'created' => $created,
          );
        }
      }
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
    $content['data'] = array();
    if (isset($csv_content['8']['2'])) {
      $match = preg_match('/^.*data-([0-9-T]+)-structure-[0-9-T]+\.[a-z]*$/u', $csv_content['8']['2'], $matches);
      if ($match && isset($matches['1'])) {
        $version = $matches['1'];
        $content['data'][] = array(
          'version' => $version,
        );
      }
    }

    if (isset($csv_content['16']['2'])) {
      $previous_versions = explode("\n", $csv_content['16']['2']);
      foreach ($previous_versions as $previous_version) {
        $match = preg_match('/^.*data-([0-9-T]+)-structure-[0-9-T]+\.[a-z]*$/u', $previous_version, $matches);
        if ($match && isset($matches['1'])) {
          $version = $matches['1'];
          $content['data'][] = array(
            'version' => $version,
          );
        }
      }
    }

    $this->content = $content;

    return TRUE;
  }

  public function getResult() {
    $result = $this->content;
    // TODO: Sync version and created.
    foreach($result['data'] as &$list) {
      if (isset($list['created'])) {
        $date = new DateTime($list['created']);
        $data_arg = $date->format('Y-m-d');

        $data_api = $this->getApi($data_arg);

        $list = array(
          '#api' => $data_api,
          'created' => $list['created'],
        );
      }
      else if (isset($list['version'])) {
        $version = $list['version'];
        $data_api = $this->getApi($version);

        $list = array(
          '#api' => $data_api,
          'version' => $list['version'],
        );
      }
    }

    return $result;
  }
}
