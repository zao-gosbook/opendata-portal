<?php

/**
 * @file
 * Contains the OdApiData class.
 */

class OdApiData30 extends OdApiData23 {
  protected function _parseRdfa() {
    parent::_parseRdfa();

    if (empty($this->content)) {
      return;
    }

    $result = $this->parserRdfa['result'];

    $dc_valid = OdApiHelper::namespaceUnwrap('dc:valid');

    $content = array();
    if (isset($result[$dc_valid])) {
      $content['valid'] = OdApiHelper::trim(reset($result[$dc_valid]));
    }

    $this->content = array_merge($this->content, $content);
  }

  protected function _parseCsv() {
    $data_list = $this->parent;
    $meta = $data_list->parent;
    if ($meta->parserCsv['error']) {
      return;
    }

    $result = $meta->csvResult; // @todo

    $content = array();
    foreach ($result as $key => $value) {
      if (strpos($key, 'data-' . $this->arg) === 0) {
        $content['source'] = OdApiHelper::trim($result[$key]['value']);
        break;
      }
    }
    if (isset($result['format']['value'])) {
      $content['format'] = OdApiHelper::trim($result['format']['value']);
    }
    if (isset($result['created']['value'])) {
      $content['created'] = OdApiHelper::trim($result['created']['value']);
    }
    if (isset($result['provenance']['value'])) {
      $content['provenance'] = OdApiHelper::trim($result['provenance']['value']);
    }
    if (isset($result['valid']['value'])) {
      $content['valid'] = OdApiHelper::trim($result['valid']['value']);
    }

    $content['structure'] = array();

    $this->content = !empty($content) ? $content : NULL;
  }
}
