<?php

/**
 * @file
 * Contains the OdApiStructure class.
 */

class OdApiStructure23 extends OdApiStructureDefault {
  public function _validateArg() {
    $structure_arg_is_valid = $this->arg === 'structure';
    $this->setValidator($this::SITE_OPENDATA_STRUCTURE_EXISTS, $structure_arg_is_valid);
  }

  public function _validateUrl() {
    $dc_conformsTo = OdApiHelper::namespaceUnwrap('dc:conformsTo');

    if (isset($this->parent->parserRdfa['subjects'][$this->parent->url][$dc_conformsTo])) {
      $this->urls[] = reset($this->parent->parserRdfa['subjects'][$this->parent->url][$dc_conformsTo]);
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

    $this->content = !empty($content) ? $content : NULL;
  }

  protected function _parseMicrodata() {}

  protected function _parseJson() {}

  protected function _parseXml() {}

  protected function _parseCsv() {
    $data = $this->parent;
    $data_list = $data->parent;
    $meta = $data_list->parent;
    if ($meta->parserCsv['error']) {
      return;
    }

    $result = $meta->parserCsv['result'];

    $content = array();
    if (isset($result['10']['2'])) {
      $content['source'] = OdApiHelper::trim($result['10']['2']);
    }

    $this->content = !empty($content) ? $content : NULL;
  }

  protected function _getResult() {
    $result = $this->content;

    return $result;
  }
}
