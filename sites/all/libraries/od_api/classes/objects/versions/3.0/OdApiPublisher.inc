<?php

/**
 * @file
 * Contains the OdApiPublisher class.
 */

class OdApiPublisher30 extends OdApiPublisher23 {
  protected function _parseCsv() {
    $meta = $this->parent;
    if ($meta->parserCsv['error']) {
      return;
    }

    $result = $meta->csvResult; // @todo

    $content = array();
    if (isset($result['publishername']['value'])) {
      $content['name'] = OdApiHelper::trim($result['publishername']['value']);
    }
    if (isset($result['publisherphone']['value'])) {
      $content['phone'] = OdApiHelper::trim($result['publisherphone']['value']);
    }
    if (isset($result['publishermbox']['value'])) {
      $content['mbox'] = OdApiHelper::trim($result['publishermbox']['value']);
    }

    $this->content = !empty($content) ? $content : NULL;
  }
}
