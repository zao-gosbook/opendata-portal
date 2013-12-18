<?php

/**
 * @file
 * Contains the OdApiList class.
 */

abstract class OdApiListDefault extends OdApiObject {
  public static $title = 'Реестр открытых данных';
  public static $type = self::OBJECT_TYPE_IS_LIST;
  public static $typeCardinality = self::OBJECT_CARDINALITY_IS_MULTIPLE;
  public static $parentType = FALSE;
  public static $childrenTypes = array(self::OBJECT_TYPE_IS_META);

  // Errors.
  const SITE_OPENDATA_ARG_IS_VALID = 11;
  const SITE_MAIN_PAGE_EXISTS = 12;
  const SITE_OPENDATA_PAGE_EXISTS = 13;

  static function processArg(&$arg = NULL) {
    // Add default http:// scheme if it is empty.
    $arg = rtrim($arg, '/') . '/';
    $parsed_url = parse_url($arg);
    if (!isset($parsed_url['scheme'])) {
      $arg = 'http://' . $arg;
    }
  }

  protected static $validatorsInfo = array(
    self::SITE_OPENDATA_ARG_IS_VALID => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'site url is valid',
        FALSE => 'site url is invalid',
      )
    ),
    self::SITE_MAIN_PAGE_EXISTS => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'site main page exists',
        FALSE => 'site main page does not exist',
      ),
    ),
    self::SITE_OPENDATA_PAGE_EXISTS => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'site opendata page exists',
        FALSE => 'site opendata page does not exist',
      ),
    ),
  );
}
