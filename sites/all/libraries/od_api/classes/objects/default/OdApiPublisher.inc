<?php

/**
 * @file
 * Contains the OdApiPublisher class.
 */

abstract class OdApiPublisherDefault extends OdApiObject {
  public static $title = 'Ответственное лицо открытых данных';
  public static $type = self::OBJECT_TYPE_IS_PUBLISHER;
  public static $typeCardinality = self::OBJECT_CARDINALITY_IS_SINGLE;
  public static $parentType = self::OBJECT_TYPE_IS_META;
  public static $childrenTypes = array();

  // Errors.
  const SITE_OPENDATA_PUBLISHER_ARG_IS_VALID = 31;

  protected static $validatorsInfo = array(
    self::SITE_OPENDATA_PUBLISHER_ARG_IS_VALID => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'publisher arg is valid',
        FALSE => 'publisher arg is invalid',
      ),
    ),
  );

  protected function _getAvailableFormats() {
    return array($this->parent->format);
  }
}
