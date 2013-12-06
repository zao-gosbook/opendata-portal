<?php

/**
 * @file
 * Contains the OdApiList class.
 */

class OdApiList30 extends OdApiListDefault {
  public function setUrl() {
    $this->url = rtrim($this->args['0'], '/') . '/' . 'opendata';
    $this->csvUrl = $this->url . '/list.csv';
  }

  public function validateArg() {
    // str_replace('://', '://opendata.', $this->od_api->base_url),
    // Add default http:// scheme.
    if (isset($this->args['0'])) {
      $parsed_url = parse_url($this->args['0']);
      if (!isset($parsed_url['scheme'])) {
        $this->args['0'] = 'http://' . $this->args['0'];
      }
    } // @todo Сделать

    return TRUE;
  }

  public function validateObject() {
    $url_is_valid = (bool) preg_match('/^(?:https?:\/\/)?[a-zа-я0-9\-]+(\.[a-zа-я0-9\-]+)*\.[a-z]{2,4}\/?$/', end($this->args));

    if (!$url_is_valid) {
      $this->errors[] = OD_API_LIST_ERROR_SITE_URL_IS_INVALID;
    }

    return $url_is_valid;
  }

  public function _parseRdf() {
    // Check RDFa object existing.
    if (!$this->rdfResult) {
      $this->errors[] = OD_API_LIST_ERROR_RDFA_DOES_NOT_EXIST;
      return FALSE;
    }

    // Declare used RDFa types.
    $rdf_type = $this->localNamespaceUnwrap('rdf:type');
    $dc_hasPart = $this->localNamespaceUnwrap('dc:hasPart');
    $dc_title = $this->localNamespaceUnwrap('dc:title');
    $dc_Collection = $this->localNamespaceUnwrap('dc:Collection');

    // If object is not DC Collection m
    if (!isset($this->rdfResult[$rdf_type]) || !in_array($dc_Collection, $this->rdfResult[$rdf_type])) {
      $this->errors[] = OD_API_LIST_ERROR_RDFA_DOES_NOT_EXIST;
      return FALSE;
    }

    $content = array();
    if (!isset($this->rdfResult[$dc_hasPart])) {
      $this->errors[] = OD_API_LIST_ERROR_RDFA_LIST_IS_EMPTY;
      return FALSE;
    }

    $content['meta'] = array();
    foreach ($this->rdfResult[$dc_hasPart] as $item) {
      if (!isset($this->rdfSubjects[$item][$dc_title])) {
        continue;
      }

      $content['meta'][] = array(
        'title' => reset($this->rdfSubjects[$item][$dc_title]),
        'link' => $item,
      );
    }

    if (!$content) {
      $this->errors[] = OD_API_LIST_ERROR_RDFA_LIST_IS_EMPTY;
      return FALSE;
    }

    $this->content = $content;

    return TRUE;
  }

  public function _parseCsv() {
    if (!$this->csvResult) {
      switch ($this->csvError) {
        case 'fileNotExists':
          $this->errors[] = OD_API_LIST_ERROR_OPENDATA_CSV_DOES_NOT_EXIST;
          break;
        case 'notUtf8':
          $this->errors[] = OD_API_LIST_ERROR_OPENDATA_CSV_NOT_UTF8;
          break;
      }
      return FALSE;
    }

    $csv_content = $this->csvResult;

    $content = array();
    $content['meta'] = array();

    $row_counter = 0;
    foreach ($csv_content as $row) {
      $row_counter++;
      if ($row_counter === 1) {
        continue;
      }

      if (!isset($row['1']) || !isset($row['2'])) {
        continue;
      }
      $content['meta'][] = array(
        'title' => $row['1'],
        'link' => $row['2'],
      );
    }

    $this->content = $content;

    return TRUE;
  }

  public function getResult() {
    $result = $this->content;

    if (!empty($result['meta'])) {
      foreach($result['meta'] as &$list) {
        $identifier = end(explode('/', $list['link']));

        $meta_api = $this->getApi($identifier);

        $list = array(
          '#api' => $meta_api,
          'identifier' => $identifier,
          'title' => $list['title'],
        );
      }
    }

    return $result;
  }
}
