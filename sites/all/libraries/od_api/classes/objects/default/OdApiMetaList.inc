<?php

/**
 * @file
 * Contains the OdApiList class.
 */

abstract class OdApiMetaListDefault extends OdApiObject {
  protected $site_encoded_url;
  protected $site_decoded_url;

  public static $title = 'Реестр открытых данных';
  public static $type = self::OBJECT_TYPE_IS_META_LIST;
  public static $typeCardinality = self::OBJECT_CARDINALITY_IS_MULTIPLE;
  public static $parentType = FALSE;
  public static $childrenTypes = array(self::OBJECT_TYPE_IS_META);

  // Errors.
  const SITE_OPENDATA_ARG_IS_VALID = 11;
  const SITE_MAIN_PAGE_EXISTS = 12;
  const SITE_OPENDATA_PAGE_EXISTS = 13;

  const REGEXP_META_LIST_URL = '/^https?:\/\/[a-zа-яё0-9\-]+(\.[a-zа-яё0-9\-]+)*\.[a-zа-яё]{2,4}\/$/u';

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

  static function processArg($arg) {
    // Check redirect.
    $redirect = OdApiHelper::getUrlRedirect($arg);
    if ($redirect !== FALSE && !in_array(substr($redirect, 0, 1), array('/', '\\', '.'), TRUE)) {
      $arg = $redirect;
    }

    // Check format.
    $arg = OdApiHelper::formatUrl($arg, PHP_URL_HOST);

    return $arg;
  }

  protected function _getAvailableFormats() {
    return array_keys($this::$allFormats);
  }
}
