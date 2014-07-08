<?php

/**
 * @file
 * Contains the OdApiData class.
 */

class OdApiData30 extends OdApiData23 {
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
    $content['structure'] = array();

    $this->content = !empty($content) ? $content : NULL;
  }
}
