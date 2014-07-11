<?php

/**
 * @file
 * Contains the OdApiSource class.
 */

class OdApiDataList23 extends OdApiDataListDefault {
  protected function _validateArg() {
    // Check publisher arg is valid.
    $source_arg_is_valid = $this->arg === 'data';

    // Check searching publisher exists.
    $source_correct = $source_arg_is_valid && isset($this->parent->content[$this::OBJECT_TYPE_IS_DATA]);

    $this->setValidator($this::SITE_OPENDATA_SOURCE_ARG_IS_VALID, $source_correct);
  }

  protected function _validateUrl() {
    $dc_source = OdApiHelper::namespaceUnwrap('dc:source');

    if (isset($this->parent->parserRdfa['subjects'][$this->parent->url][$dc_source])) {
      $this->urls[] = reset($this->parent->parserRdfa['subjects'][$this->parent->url][$dc_source]);
    }
  }

  protected function _getFormatUrl($format) {
    $result = FALSE;
    switch ($format) {
      case $this::OBJECT_FORMAT_RDFA;
        $result = $this->url ? $this->url : FALSE;
        break;
      case $this::OBJECT_FORMAT_CSV;
        $result = TRUE;
        break;
    }

    return $result;
  }

  protected function _parseRdfa() {
    if ($this->parserRdfa['error']) {
      return;
    }

    $result = $this->parserRdfa['result'];

    $dc_hasPart = OdApiHelper::namespaceUnwrap('dc:hasPart');
    $dc_created = OdApiHelper::namespaceUnwrap('dc:created');

    if (!isset($result[$dc_hasPart])) {
      return;
    }

    $content = array();
    foreach ($result[$dc_hasPart] as $item) {
      $item = rtrim(OdApiHelper::trim($item), '/');
      if (!isset($this->parserRdfa['subjects'][$item])) {
        continue;
      }

      if (!isset($this->parserRdfa['subjects'][$item][$dc_created])) {
        continue;
      }

      $version = strtotime(reset($this->parserRdfa['subjects'][$item][$dc_created]));
      if ($version === FALSE) {
        continue;
      }

      $content[$version] = array(
        'version' => (string) $version,
      );
    }

    $this->content = !empty($content) ? array('data' => $content) : NULL;
  }

  protected function _parseMicrodata() {}

  protected function _parseJson() {}

  protected function _parseXml() {}

  protected function _parseCsv() {
    $meta = $this->parent;
    if ($meta->parserCsv['error']) {
      return;
    }

    $result = $meta->parserCsv['result'];

    $content = array();
    if (isset($result['8']['2'])) {
      $match = preg_match('/^.*data-([0-9-T]+)-structure-[0-9-T]+\.[a-z]*$/u', OdApiHelper::trim($result['8']['2']), $matches);
      if ($match && isset($matches['1'])) {
        $version = $matches['1'];
        $content[$version] = array(
          'version' => $version,
        );
      }
    }

    if (isset($result['16']['2'])) {
      $previous_versions = explode("\n", $result['16']['2']);
      foreach ($previous_versions as $previous_version) {
        $match = preg_match('/^.*data-([0-9-T]+)-structure-[0-9-T]+\.[a-z]*$/u', OdApiHelper::trim($previous_version), $matches);
        if ($match && isset($matches['1'])) {
          $version = $matches['1'];
          $content[$version] = array(
            'version' => $version,
          );
        }
      }
    }

    $this->content = !empty($content) ? array('data' => $content) : NULL;
  }

  protected function _getResult() {
    $result = $this->content;

    uasort($result['data'], function($a, $b) {
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
