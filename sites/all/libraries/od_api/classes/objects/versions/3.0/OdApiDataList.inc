<?php

/**
 * @file
 * Contains the OdApiSource class.
 */

class OdApiDataList30 extends OdApiDataList23 {
  protected function _parseCsv() {
    $meta = $this->parent;
    if ($meta->parserCsv['error']) {
      return;
    }

    $result = $meta->csvResult; // @todo

    $content = array();
    foreach ($result as $key => $value) {
      if (preg_match(OdApiData30::REGEXP_CSV_DATA, OdApiHelper::trim($key), $matches)) {
        if (!OdApiHelper::validateIso8601($matches[1]) || !OdApiHelper::validateIso8601($matches[2])) {
          continue;
        }
        $version = $matches['1'];
        $content[$version] = array(
          'version' => $version,
        );
      }
    }

    $this->content = !empty($content) ? array('data' => $content) : NULL;
  }
}
