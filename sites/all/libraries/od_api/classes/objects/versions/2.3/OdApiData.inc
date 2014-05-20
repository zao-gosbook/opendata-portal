<?php

/**
 * @file
 * Contains the OdApiData class.
 */

class OdApiData23 extends OdApiDataDefault {
  public function validateArg() {
    $data_exists = FALSE;
    foreach ($this->parent->content['data'] as $data) {
      if ($data['version'] === $this->args[$this::OBJECT_TYPE_IS_DATA]) {
        $data_exists = TRUE;
        break;
      }
    }

    $this->setValidator($this::SITE_OPENDATA_DATA_EXISTS, $data_exists);
  }

  public function validateVersion() {
    return TRUE;
  }

  public function setPossibleUrls() {
    // Collect available urls.
    $urls = array();

    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_created = $this->localNamespaceUnwrap('dc:created');

    if (isset($this->parent->parserRDFa->subjects[$this->parent->url][$dc_hasPart])) {
      foreach ($this->parent->parserRDFa->subjects[$this->parent->url][$dc_hasPart] as $item) {
        if (isset($this->parent->parserRDFa->subjects[$item][$dc_created])) {
          $version = strtotime(reset($this->parent->parserRDFa->subjects[$item][$dc_created]));

          if ($version !== FALSE && (string) $version === end($this->args)) {
            $this->url = $item;
            $urls['semantic'] = $this->url;
            break;
          }
        }
      }
    }

    $urls['file_csv'] = TRUE;

    $this->urls = $urls;
  }

  public function validateObject() {}

  protected function _parseRdf() {
    // Check RDFa object existing.
    if ($this->parserRDFa->error) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $dc_source = $this->localNamespaceUnwrap('dc:source');
    $dc_format = $this->localNamespaceUnwrap('dc:format');
    $dc_created = $this->localNamespaceUnwrap('dc:created');
    $dc_provenance = $this->localNamespaceUnwrap('dc:provenance');
    $dc_conformsTo = $this->localNamespaceUnwrap('dc:conformsTo');

    $content = array();
    if (isset($this->parserRDFa->result[$dc_source])) {
      $content['source'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_source]));
    }
    if (isset($this->parserRDFa->result[$dc_format])) {
      $content['format'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_format]));
    }
    if (isset($this->parserRDFa->result[$dc_created])) {
      $content['created'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_created]));
    }
    if (isset($this->parserRDFa->result[$dc_provenance])) {
      $content['provenance'] = OdApiHelper::trim(reset($this->parserRDFa->result[$dc_provenance]));
    }
    if (isset($this->parserRDFa->result[$dc_conformsTo])) {
      $content['structure'][] = array();
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
    $source = $this->parent;
    $meta = $source->parent;
    if ($meta->format !== $this::OBJECT_FORMAT_CSV || $meta->parserCSV->error) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $result = $meta->parserCSV->result;

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

    if (!$content) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_CSV_DETECTED, TRUE);
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
