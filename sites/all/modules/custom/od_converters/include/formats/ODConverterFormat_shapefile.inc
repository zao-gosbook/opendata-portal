<?php
/**
 * @file
 */

class ODConverterFormat_shapefile extends ODConverterFormatAbstract {
  public static function name() {
    return 'shapefile';
  }

  public static function extension() {
    return 'shp';
  }
}