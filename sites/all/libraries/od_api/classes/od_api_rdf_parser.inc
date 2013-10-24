<?php

/**
 * @file
 * Contains the OdApiRDFParser class.
 */

/**
 * Opendata API class.
 */
class OdApiRDFParser {
  public $url;
  /**
   * @var ARC2_RDFParser
   */
  public $parser;

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
    $this->parser->parse($url);
    return $this;
  }

  public function getSubjects() {
    return $this->parser->getSimpleIndex();
  }

  public function getRDFXml() {
    $triples = $this->parser->getTriples();
    return $this->parser->toRDFXML($triples);
  }
}
