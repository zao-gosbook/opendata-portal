<?php

/**
 * @file
 * Contains the OdApiMeta class.
 */

class OdApiMeta23 extends OdApiMetaDefault {
  public function validateArg() {
    // Check searching meta arg is valid.
    $meta_arg = $this->args[OdApiObject::OBJECT_TYPE_IS_META];
    $meta_arg_is_valid = (bool) preg_match('/^[0-9]{10}-[a-z0-9_]+$/', $meta_arg);

    $meta_is_exist = FALSE;
    if ($meta_arg_is_valid) {
      // Check searching meta exists.
      foreach ($this->parent->content['meta'] as $meta) {
        if ($meta['identifier'] === $meta_arg) {
          $meta_is_exist = TRUE;
          break;
        }
      }
    }

    $this->setValidator($this::SITE_OPENDATA_META_ARG_IS_VALID, $meta_is_exist);
  }

  public function validateVersion() {
    return TRUE;
  }

  public function setPossibleUrls() {
    // Collect available urls.
    $urls = array();

    // Get meta arg.
    $meta_arg = $this->args[OdApiObject::OBJECT_TYPE_IS_META];

    $this->url = $this->od_api->opendata_page_url . '/' . $meta_arg;

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
    $site_opendata_meta_page_exists = $this->checkUrl($this->url);
    $this->setValidator($this::SITE_OPENDATA_META_PAGE_EXISTS, $site_opendata_meta_page_exists);

    return $this->checkErrorExists();
  }

  public function _parseRdf() {
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

    $content = array();
    if (isset($this->parserRDFa->result[$dc_identifier])) {
      $content['identifier'] = reset($this->parserRDFa->result[$dc_identifier]);
    }
    if (isset($this->parserRDFa->result[$dc_title])) {
      $content['title'] = reset($this->parserRDFa->result[$dc_title]);
    }
    if (isset($this->parserRDFa->result[$dc_description])) {
      $content['description'] = reset($this->parserRDFa->result[$dc_description]);
    }
    if (isset($this->parserRDFa->result[$dc_owner])) {
      $content['owner'] = reset($this->parserRDFa->result[$dc_owner]);
    }
    if (isset($this->parserRDFa->result[$dc_created])) {
      $content['created'] = reset($this->parserRDFa->result[$dc_created]);
    }
    if (isset($this->parserRDFa->result[$dc_valid])) {
      $content['valid'] = reset($this->parserRDFa->result[$dc_valid]);
    }
    if (isset($this->parserRDFa->result[$dc_subject])) {
      $content['subject'] = reset($this->parserRDFa->result[$dc_subject]);
    }

    if (isset($this->parserRDFa->result[$dc_publisher])) {
      $content['publisher'][] = array();
    }
    if (isset($this->parserRDFa->result[$dc_source])) {
      $content['source'][] = array();
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_RDFA_DETECTED, TRUE);
  }

  public function _parseCsv() {
    // Check CSV object existing.
    if ($this->parserCSV->error) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $result = $this->parserCSV->result;

    $content = array();
    if (isset($result['1']['2'])) {
      $content['identifier'] = $result['1']['2'];
    }
    if (isset($result['2']['2'])) {
      $content['title'] = $result['2']['2'];
    }
    if (isset($result['3']['2'])) {
      $content['description'] = $result['3']['2'];
    }
    if (isset($result['4']['2'])) {
      $content['owner'] = $result['4']['2'];
    }
    if (isset($result['11']['2'])) {
      $content['created'] = $result['11']['2'];
    }
    if (isset($result['14']['2'])) {
      $content['valid'] = $result['14']['2'];
    }
    if (isset($result['15']['2'])) {
      $content['subject'] = $result['15']['2'];
    }

    if (isset($result['5']['2']) && isset($result['6']['2']) && isset($result['7']['2'])) {
      $content['publisher'][] = array();
    }
    if (isset($result['8']['2'])) {
      $content['source'][] = array();
    }

    if (!$content) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_CSV_DETECTED, TRUE);
  }

  public function getResult() {
    $result = array(
      '#version' => '2.3',
    );

    $result += $this->content;

    if (isset($result['publisher'])) {
      $publisher_api = $this->getApi(array(OdApiObject::OBJECT_TYPE_IS_PUBLISHER => OdApiObject::OBJECT_TYPE_IS_PUBLISHER));
      $result['publisher'] = array(
        '#api' => $publisher_api,
      );
    }

    if (isset($result['source'])) {
      $source_api = $this->getApi(array(OdApiObject::OBJECT_TYPE_IS_SOURCE => OdApiObject::OBJECT_TYPE_IS_SOURCE));
      $result['source'] = array(
        '#api' => $source_api,
      );
    }

    return $result;
  }
}
