<?php

/**
 * @file
 * Contains the OdApiData class.
 */

class OdApiData23 extends OdApiDataDefault {
  public function validateArg() {
    $data_arg = $this->args[OdApiObject::OBJECT_TYPE_IS_DATA];

    $data_is_exist = FALSE;
    foreach ($this->parent->content['data'] as $data) {
      if (isset($data['created'])) {
        $date = new DateTime($data['created']);
        $data_created = $date->format('Y-m-d\TH:i:s');

        if ($data_created === $data_arg) {
          $data_is_exist = TRUE;
        }
      }
      if (isset($data['version'])) {
        if ($data['version'] === $data_arg) {
          $data_is_exist = TRUE;
        }
      }
    }

    $this->setValidator($this::SITE_OPENDATA_DATA_EXISTS, $data_is_exist);
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
          $created = reset($this->parent->parserRDFa->subjects[$item][$dc_created]);
          $date = new DateTime($created);
          $data_arg = $date->format('Y-m-d\TH:i:s');

          if ($data_arg === end($this->args)) {
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

  public function validateObject() {
    return TRUE;
  }

  public function _parseRdf() {
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
      $content['source'] = reset($this->parserRDFa->result[$dc_source]);
    }
    if (isset($this->parserRDFa->result[$dc_format])) {
      $content['format'] = reset($this->parserRDFa->result[$dc_format]);
    }
    if (isset($this->parserRDFa->result[$dc_created])) {
      $content['created'] = reset($this->parserRDFa->result[$dc_created]);
    }
    if (isset($this->parserRDFa->result[$dc_provenance])) {
      $content['provenance'] = reset($this->parserRDFa->result[$dc_provenance]);
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

  public function _parseCsv() {
    // Check CSV object existing.
    $source = $this->parent;
    $meta = $source->parent;
    if ($meta->parserCSV->error) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $result = $meta->parserCSV->result;

    $content = array();
    if (isset($result['8']['2'])) {
      $content['source'] = $result['8']['2'];
    }
    if (isset($result['9']['2'])) {
      $content['format'] = $result['9']['2'];
    }
    if (isset($result['12']['2'])) {
      $content['created'] = $result['12']['2'];
    }
    if (isset($result['13']['2'])) {
      $content['provenance'] = $result['13']['2'];
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

  public function getResult() {
    $result = array(
      '#version' => '2.3',
    );

    $result += $this->content;

    if (isset($result['structure'])) {
      $structure_api = $this->getApi(array(OdApiObject::OBJECT_TYPE_IS_STRUCTURE => OdApiObject::OBJECT_TYPE_IS_STRUCTURE));

      $result['structure'] = array(
        '#api' => $structure_api,
      );
    }

    return $result;
  }
}
