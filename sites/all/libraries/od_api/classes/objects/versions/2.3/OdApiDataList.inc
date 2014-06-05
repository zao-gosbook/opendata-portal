<?php

/**
 * @file
 * Contains the OdApiSource class.
 */

class OdApiDataList23 extends OdApiDataListDefault {
  public function validateArg() {
    // Check publisher arg is valid.
    $source_arg_is_valid = $this->args[$this::OBJECT_TYPE_IS_DATA_LIST] === 'data';
    $this->setValidator($this::SITE_OPENDATA_SOURCE_ARG_IS_VALID, $source_arg_is_valid);
  }

  public function validateVersion() {
    return TRUE;
  }

  public function setPossibleUrls() {
    // Collect available urls.
    $urls = array();

    $dc_source = $this->localNamespaceUnwrap('dc:source');

    if (isset($this->parent->parserRDFa->subjects[$this->parent->url][$dc_source])) {
      $this->url = reset($this->parent->parserRDFa->subjects[$this->parent->url][$dc_source]);
      $urls['semantic'] = $this->url;
    }

    $urls['file_csv'] = TRUE;

    $this->urls = $urls;
  }

  public function validateObject() {}

  protected function _parseRdf() {
    // Check RDFa object existing.
    if ($this->parserRDFa->error) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_created = $this->localNamespaceUnwrap('dc:created');

    $content = array();
    if (isset($this->parserRDFa->result[$dc_hasPart])) {
      $content['data'] = array();
      foreach ($this->parserRDFa->result[$dc_hasPart] as $item) {
        $item = rtrim(OdApiHelper::trim($item), '/');
        if (!isset($this->parserRDFa->subjects[$item])) {
          continue;
        }

        if (!isset($this->parserRDFa->subjects[$item][$dc_created])) {
          continue;
        }

        $version = strtotime(reset($this->parserRDFa->subjects[$item][$dc_created]));
        if ($version === FALSE) {
          continue;
        }

        $content['data'][] = array(
          'version' => (string) $version,
        );
      }
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_RDFA_DETECTED, TRUE);
  }

  protected function _parseCsv() {
    // Check CSV object existing.
    $meta = $this->parent;
    if ($meta->format !== $this::OBJECT_FORMAT_CSV || $meta->parserCSV->error) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $result = $meta->parserCSV->result;

    $content = array();
    $content['data'] = array();
    if (isset($result['8']['2'])) {
      $match = preg_match('/^.*data-([0-9-T]+)-structure-[0-9-T]+\.[a-z]*$/u', $result['8']['2'], $matches);
      if ($match && isset($matches['1'])) {
        $version = $matches['1'];
        $content['data'][] = array(
          'version' => OdApiHelper::trim($version),
        );
      }
    }

    if (isset($result['16']['2'])) {
      $previous_versions = explode("\n", $result['16']['2']);
      foreach ($previous_versions as $previous_version) {
        $match = preg_match('/^.*data-([0-9-T]+)-structure-[0-9-T]+\.[a-z]*$/u', $previous_version, $matches);
        if ($match && isset($matches['1'])) {
          $version = $matches['1'];
          $content['data'][] = array(
            'version' => OdApiHelper::trim($version),
          );
        }
      }
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_CSV_DETECTED, TRUE);
  }

  protected function _getResult() {
    $result = $this->content;

    usort($result['data'], function($a, $b) {
      if ($a['version'] == $b['version']) {
        return 0;
      }
      return ($a['version'] < $b['version']) ? 1 : -1;
    });

    foreach($result['data'] as &$data) {
      $version = $data['version'];
      $data_api = $this->getApi(array($this::OBJECT_TYPE_IS_DATA => $version));

      $version = $data['version'];

      $data = array(
        '#api' => $data_api,
        'version' => $version,
      );
    }

    return $result;
  }
}
