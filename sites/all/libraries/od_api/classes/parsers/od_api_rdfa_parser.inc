<?php

/**
 * @file
 * Contains the OdApiRDFParser class.
 */

class OdApiRDFaParser extends OdApiParser {
  /**
   * @var ARC2_RDFParser
   */
  public $parser;
  public $subjects;

  public function __construct() {
    $parser = $this->getRDFParser();
    $this->parser = $parser;

    return $this;
  }

  /**
   * Get ARC2 RDF parser.
   *
   * @return ARC2_RDFParser
   */
  public function getRDFParser() {
    return ARC2::getRDFParser();
  }

  public function parse($url, $actual_url = NULL) {
    $this->url = $url;
    // Using "@" for ignoring ARC2 library errors.

    $parsing_url = !empty($actual_url) ? $actual_url : $this->url;
    $this->parser->parse($parsing_url);

    $subjects = $this->parser->getSimpleIndex();

    if (is_array($subjects)) {
      foreach ($subjects as $link => $subject) {
        if (substr($link, -1) !== '/') {
          continue;
        }

        $correct_link = substr($link, 0, -1);

        if (isset($subjects[$correct_link])) {
          $subjects[$correct_link] = array_merge($subjects[$correct_link], $subjects[$link]);
        }
        else {
          $subjects[$correct_link] = $subjects[$link];
        }

        unset($subjects[$link]);
      }
    }

    if (!empty($actual_url)) {
      $subjects[$this->url] = isset($subjects[$this->url]) ? array_merge($subjects[$this->url], $subjects[$actual_url]) : $subjects[$actual_url];
      unset($subjects[$actual_url]);
    }

    $this->subjects = $subjects;

    $this->result = isset($this->subjects[$this->url]) ? $this->subjects[$this->url] : array();
    return $this;
  }

  public function getSubjects() {
    return $this->subjects;
  }

  public function getResult() {
    return $this->result;
  }

  public function getRDFXml() {
    $triples = $this->parser->getTriples();
    return $this->parser->toRDFXML($triples);
  }
}
