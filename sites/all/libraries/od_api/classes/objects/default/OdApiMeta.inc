<?php

/**
 * @file
 * Contains the OdApiMeta class.
 */

abstract class OdApiMetaDefault extends OdApiObject {
  public static $title = 'Паспорт открытых данных';
  public static $type = self::OBJECT_TYPE_IS_META;
  public static $typeCardinality = self::OBJECT_CARDINALITY_IS_MULTIPLE;
  public static $parentType = self::OBJECT_TYPE_IS_META_LIST;
  public static $childrenTypes = array(self::OBJECT_TYPE_IS_PUBLISHER, self::OBJECT_TYPE_IS_DATA_LIST);

  // Errors.
  const SITE_OPENDATA_META_ARG_IS_VALID = 21;
  const SITE_OPENDATA_META_PAGE_EXISTS = 22;

  const REGEXP_META_IDENTIFIER = '/^[0-9]{10}-[a-zA-Z0-9_-]+$/u';

  protected static $validatorsInfo = array(
    self::SITE_OPENDATA_META_ARG_IS_VALID => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'meta url is valid',
        FALSE => 'meta url is invalid',
      ),
    ),
    self::SITE_OPENDATA_META_PAGE_EXISTS => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'meta page exists',
        FALSE => 'meta page does not exist',
      ),
    ),
  );

  protected function _getAvailableFormats() {
    $meta = $this->parent->content['meta'][$this->arg];

    if (isset($meta['#format'])) {
      return in_array($meta['#format'], array_keys($this::$allFormats)) ? array($meta['#format']) : array();
    }

    return array($this::OBJECT_FORMAT_RDFA, $this::OBJECT_FORMAT_JSON, $this::OBJECT_FORMAT_XML, $this::OBJECT_FORMAT_CSV);
  }
}
