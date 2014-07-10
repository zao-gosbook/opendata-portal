<?php

/**
 * @file
 * Contains the OdApiObject class.
 */

abstract class OdApiParser {
  protected $results = array();

  abstract public function parse($url);
  abstract protected function parseUrl($url);
}
