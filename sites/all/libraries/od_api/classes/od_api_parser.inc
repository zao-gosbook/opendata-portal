<?php

/**
 * @file
 * Contains the OdApiObject class.
 */

abstract class OdApiParser {
  public $vars;
  public $url;
  public $error;
  public $comments = array();
  public $result = array();
}
