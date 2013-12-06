<?php

/**
 * @file
 * Contains the OdApiStructure class.
 */

class OdApiStructure23 extends OdApiStructureDefault {
  public function validateArg() {
    $structure_arg = $this->args[OdApiObject::OBJECT_TYPE_IS_STRUCTURE];
    $structure_arg_is_valid = $structure_arg === OdApiObject::OBJECT_TYPE_IS_STRUCTURE;
    $this->setValidator($this::SITE_OPENDATA_STRUCTURE_EXISTS, $structure_arg_is_valid);
  }

  public function validateVersion() {
    return TRUE;
  }

  public function setPossibleUrls() {
    // Collect available urls.
    $urls = array();

    $dc_conformsTo = $this->localNamespaceUnwrap('dc:conformsTo');

    if (isset($this->parent->parserRDFa->subjects[$this->parent->url][$dc_conformsTo])) {
      $this->url = reset($this->parent->parserRDFa->subjects[$this->parent->url][$dc_conformsTo]);
      $urls['semantic'] = $this->url;
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

    if (!$content) {
      $this->setValidator($this::FORMAT_RDFA_DETECTED, FALSE);
      return;
    }

    $this->content = $content;

    $this->setValidator($this::FORMAT_RDFA_DETECTED, TRUE);
  }

  public function _parseCsv() {
    // Check CSV object existing.
    $data = $this->parent;
    $source = $data->parent;
    $meta = $source->parent;
    if ($meta->parserCSV->error) {
      $this->setValidator($this::FORMAT_CSV_DETECTED, FALSE);
      return;
    }

    $result = $meta->parserCSV->result;

    $content = array();
    if (isset($result['10']['2'])) {
      $content['source'] = $result['10']['2'];
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

    return $result;
  }
}
