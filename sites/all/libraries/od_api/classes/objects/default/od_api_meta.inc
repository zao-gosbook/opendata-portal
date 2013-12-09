<?php

/**
 * @file
 * Contains the OdApiMeta class.
 */

abstract class OdApiMetaDefault extends OdApiObject {
  public static $title = 'Паспорт открытых данных';
  public static $type = self::OBJECT_TYPE_IS_META;
  public static $typeCardinality = self::OBJECT_CARDINALITY_IS_MULTIPLE;
  public static $parentType = self::OBJECT_TYPE_IS_LIST;
  public static $childrenTypes = array(self::OBJECT_TYPE_IS_PUBLISHER, self::OBJECT_TYPE_IS_SOURCE);

  // Errors.
  const SITE_OPENDATA_META_ARG_IS_VALID = 21;
  const SITE_OPENDATA_META_PAGE_EXISTS = 22;

  protected static $validatorsInfo = array(
    self::SITE_OPENDATA_META_ARG_IS_VALID => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'Site url is valid.',
        FALSE => 'Site url is invalid.',
      ),
    ),
    self::SITE_OPENDATA_META_PAGE_EXISTS => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'Site main page exists.',
        FALSE => 'Site main page does not exist.',
      ),
    ),
  );
}
