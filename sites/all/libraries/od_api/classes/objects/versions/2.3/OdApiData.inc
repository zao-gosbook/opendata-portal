<?php

/**
 * @file
 * Contains the OdApiData class.
 */

class OdApiData23 extends OdApiDataDefault {
  protected function _validateArg() {
    $data_exists = FALSE;
    foreach ($this->parent->content['data'] as $version => $data) {
      if ((string) $version === $this->arg) {
        $data_exists = TRUE;
        break;
      }
    }

    $this->setValidator($this::SITE_OPENDATA_DATA_EXISTS, $data_exists);
  }

  protected function _validateUrl() {
    $dc_hasPart = OdApiHelper::namespaceUnwrap('dc:hasPart');
    $dc_created = OdApiHelper::namespaceUnwrap('dc:created');

    if (isset($this->parent->parserRdfa['subjects'][$this->parent->url][$dc_hasPart])) {
      foreach ($this->parent->parserRdfa['subjects'][$this->parent->url][$dc_hasPart] as $item) {
        if (isset($this->parent->parserRdfa['subjects'][$item][$dc_created])) {
          $version = strtotime(reset($this->parent->parserRdfa['subjects'][$item][$dc_created]));

          if ($version !== FALSE && (string) $version === $this->arg) {
            $this->urls[] = $item;
          }
        }
      }
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

    $dc_source = OdApiHelper::namespaceUnwrap('dc:source');
    $dc_format = OdApiHelper::namespaceUnwrap('dc:format');
    $dc_created = OdApiHelper::namespaceUnwrap('dc:created');
    $dc_provenance = OdApiHelper::namespaceUnwrap('dc:provenance');
    $dc_conformsTo = OdApiHelper::namespaceUnwrap('dc:conformsTo');

    $content = array();
    if (isset($result[$dc_source])) {
      $content['source'] = OdApiHelper::trim(reset($result[$dc_source]));
    }
    if (isset($result[$dc_format])) {
      $content['format'] = OdApiHelper::trim(reset($result[$dc_format]));
    }
    if (isset($result[$dc_created])) {
      $content['created'] = OdApiHelper::trim(reset($result[$dc_created]));
    }
    if (isset($result[$dc_provenance])) {
      $content['provenance'] = OdApiHelper::trim(reset($result[$dc_provenance]));
    }
    if (isset($result[$dc_conformsTo])) {
      $content['structure'][] = array();
    }

    $this->content = !empty($content) ? $content : NULL;
  }

  protected function _parseMicrodata() {}

  protected function _parseJson() {}

  protected function _parseXml() {}

  protected function _parseCsv() {
    $data_list = $this->parent;
    $meta = $data_list->parent;
    if ($meta->parserCsv['error']) {
      return;
    }

    $result = $meta->parserCsv['result'];

    $content = array();
    if (isset($result['8']['2'])) {
      $content['source'] = OdApiHelper::trim($result['8']['2']);
    }
    if (isset($result['9']['2'])) {
      $content['format'] = OdApiHelper::trim($result['9']['2']);
    }
    if (isset($result['12']['2'])) {
      $content['created'] = OdApiHelper::trim($result['12']['2']);
    }
    if (isset($result['13']['2'])) {
      $content['provenance'] = OdApiHelper::trim($result['13']['2']);
    }
    if (isset($result['10']['2'])) {
      $content['structure'][] = array();
    }

    $this->content = !empty($content) ? $content : NULL;
  }

  protected function _getResult() {
    $result = $this->content;

    if (isset($result['structure'])) {
      $structure_api = $this->getApi(array($this::OBJECT_TYPE_IS_STRUCTURE => 'structure'));

      $result['structure'] = array(
        '#api' => $structure_api,
      );
    }

    return $result;
  }
}
