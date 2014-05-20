<?php

/**
 * @file
 * Contains the OdApiMeta class.
 */

class OdApiMeta23 extends OdApiMetaDefault {
  const REGEXP_IDENTIFIER = '/^[0-9]{10}-[a-zA-Z0-9_]+$/u';

  public function validateArg() {
    // Check searching meta arg is valid.
    $meta_arg_is_valid = (bool) preg_match($this::REGEXP_IDENTIFIER, $this->args[$this::OBJECT_TYPE_IS_META]);

    $meta_exists = FALSE;
    if ($meta_arg_is_valid) {
      // Check searching meta exists.
      foreach ($this->parent->content['meta'] as $meta) {
        if ($meta['identifier'] === $this->args[$this::OBJECT_TYPE_IS_META]) {
          $meta_exists = TRUE;
          break;
        }
      }
    }

    $this->setValidator($this::SITE_OPENDATA_META_ARG_IS_VALID, $meta_exists);
  }

  public function validateVersion() {
    return TRUE;
  }

  public function setPossibleUrls() {
    // Collect available urls.
    $urls = array();

    // Get meta arg.
    $meta_arg = $this->args[$this::OBJECT_TYPE_IS_META];

    $this->url = $this->od_api->list_url . '/' . $meta_arg;

    // Visual representation.
    $urls['semantic'] = $this->url;

    // File url template.
    $file_url = $this->url . '.!extension';

    // File CSV representation.
    $urls['file_csv'] = strtr($file_url, array('!extension' => 'csv'));

    // File XML representation.
    $urls['file_xml'] = strtr($file_url, array('!extension' => 'xml'));

    $this->urls = $urls;
  }

  public function validateObject() {
    // Check opendata meta page url.
    $site_opendata_meta_page_exists = $this->checkUrlSuccess($this->url);
    if (!$site_opendata_meta_page_exists) {
      $site_opendata_meta_page_exists = $this->checkUrlSuccess($this->url . '/');
    }
    $this->setValidator($this::SITE_OPENDATA_META_PAGE_EXISTS, $site_opendata_meta_page_exists);
  }

  protected function _parseRdf() {
    // Check RDFa object existing.
    if ($this->parserRDFa->error) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $dc_identifier = $this->localNamespaceUnwrap('dc:identifier');
    $dc_title = $this->localNamespaceUnwrap('dc:title');
    $dc_description = $this->localNamespaceUnwrap('dc:description');
    $dc_owner = $this->localNamespaceUnwrap('dc:owner');
    $dc_created = $this->localNamespaceUnwrap('dc:created');
    $dc_valid = $this->localNamespaceUnwrap('dc:valid');
    $dc_subject = $this->localNamespaceUnwrap('dc:subject');
    $dc_publisher = $this->localNamespaceUnwrap('dc:publisher');
    $dc_source = $this->localNamespaceUnwrap('dc:source');

    $identifier = isset($this->parserRDFa->result[$dc_identifier]) ? OdApiHelper::trim(reset($this->parserRDFa->result[$dc_identifier])) : FALSE;
    if ($identifier === FALSE || $identifier !== $this->args[$this::OBJECT_TYPE_IS_META]) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $content = array();
    if (isset($this->parserRDFa->result[$dc_identifier])) {
      $content['identifier'] = $identifier;
    }
    if (isset($this->parserRDFa->result[$dc_title])) {
      $content['title'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_title]));
    }
    if (isset($this->parserRDFa->result[$dc_description])) {
      $content['description'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_description]));
    }
    if (isset($this->parserRDFa->result[$dc_owner])) {
      $content['owner'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_owner]));
    }
    if (isset($this->parserRDFa->result[$dc_created])) {
      $content['created'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_created]));
    }
    if (isset($this->parserRDFa->result[$dc_valid])) {
      $content['valid'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_valid]));
    }
    if (isset($this->parserRDFa->result[$dc_subject])) {
      $content['subject'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_subject]));
    }

    if (isset($this->parserRDFa->result[$dc_publisher])) {
      $content['publisher'][] = array();
    }
    if (isset($this->parserRDFa->result[$dc_source])) {
      $content['data'][] = array();
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
    if ($this->parserCSV->error) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $result = $this->parserCSV->result;

    $identifier = isset($result['1']['2']) ? OdApiHelper::trim($result['1']['2']) : FALSE;
    if ($identifier === FALSE || $identifier !== $this->args[$this::OBJECT_TYPE_IS_META]) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $content = array();
    if (isset($result['1']['2'])) {
      $content['identifier'] = $identifier;
    }
    if (isset($result['2']['2'])) {
      $content['title'] = OdApiHelper::trim($result['2']['2']);
    }
    if (isset($result['3']['2'])) {
      $content['description'] = OdApiHelper::trim($result['3']['2']);
    }
    if (isset($result['4']['2'])) {
      $content['owner'] = OdApiHelper::trim($result['4']['2']);
    }
    if (isset($result['11']['2'])) {
      $content['created'] = OdApiHelper::trim($result['11']['2']);
    }
    if (isset($result['14']['2'])) {
      $content['valid'] = OdApiHelper::trim($result['14']['2']);
    }
    if (isset($result['15']['2'])) {
      $content['subject'] = OdApiHelper::trim($result['15']['2']);
    }

    if (isset($result['5']['2']) && isset($result['6']['2']) && isset($result['7']['2'])) {
      $content['publisher'][] = array();
    }
    if (isset($result['8']['2'])) {
      $content['data'][] = array();
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

    if (isset($result['publisher'])) {
      $publisher_api = $this->getApi(array($this::OBJECT_TYPE_IS_PUBLISHER => 'publisher'));
      $result['publisher'] = array(
        '#api' => $publisher_api,
      );
    }

    if (isset($result['data'])) {
      $source_api = $this->getApi(array($this::OBJECT_TYPE_IS_DATA_LIST => 'data'));
      $result['data'] = array(
        '#api' => $source_api,
      );
    }

    return $result;
  }
}
