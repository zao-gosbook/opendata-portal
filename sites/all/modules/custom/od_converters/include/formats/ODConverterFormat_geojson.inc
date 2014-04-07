<?php
/**
 * @file
 */

class ODConverterFormat_geojson extends ODConverterFormatAbstract {
  public static function name() {
    return 'geojson';
  }

  public static function extension() {
    return 'geo.json';
  }
}