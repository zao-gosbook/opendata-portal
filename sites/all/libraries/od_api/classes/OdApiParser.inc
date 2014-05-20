<?php

/**
 * @file
 * Contains the OdApiObject class.
 */

abstract class OdApiParser {
  public $url;
  public $error;
  public $result = array();

  abstract public function parse($url);
  abstract protected function parseUrl($url);
}
