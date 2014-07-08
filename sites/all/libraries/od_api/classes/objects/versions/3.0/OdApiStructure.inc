<?php

/**
 * @file
 * Contains the OdApiStructure class.
 */

class OdApiStructure30 extends OdApiStructure23 {
  protected function _parseCsv() {
    $data = $this->parent;
    $data_list = $data->parent;
    $meta = $data_list->parent;
    if ($meta->parserCsv['error']) {
      return;
    }

    $result = $meta->csvResult; // @todo

    $content = array();
    foreach ($result as $key => $value) {
      if (strpos($key, 'data-' . $this->parent->arg) === 0) {
        $content['source'] = OdApiHelper::trim($result[$key]['value']);

        preg_match(OdApiData30::REGEXP_CSV_DATA, OdApiHelper::trim($key), $matches);
        $version = $matches[2];
        if (isset($result['structure-' . $version])) {
          $content['source'] = OdApiHelper::trim($result['structure-' . $version]['value']);
        }
        break;
      }
    }

    $this->content = !empty($content) ? $content : NULL;
  }
}
