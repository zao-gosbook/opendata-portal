<?php
/**
 * @file
 */

class ODConverterFormat_topojson extends ODConverterFormatAbstract {
  public static function name() {
    return 'topojson';
  }

  public static function extension() {
    return 'topo.json';
  }
}