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

  public function parse($url) {
    $this->url = $url;
    // Using "@" for ignoring ARC2 library errors.
    @$this->parser->parse($url);

    $this->subjects = $this->parser->getSimpleIndex();
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
