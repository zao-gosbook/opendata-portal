<?php
/**
 * @file
 */

abstract class ODConverterFormatAbstract implements ODConverterFormatInterface {
  public static function checkFilename($filename) {
    return (pathinfo($filename, PATHINFO_EXTENSION) == static::extension());
  }

  public static function normalizeFilename($filename) {
    $fixed = $filename;
    if (!static::checkFilename($filename)) {
      $info = pathinfo($filename);
      $info['basename'] = $info['filename'] . '.' . static::extension();
      $info['dirname'] = (isset($info['dirname']) && $info['dirname'] != '.' && $info['dirname'] != '..')
        ? $info['dirname']. '/'
        : NULL;

      $fixed = $info['dirname']. $info['basename'];
    }

    return $fixed;
  }

  public function __call($method, $args) {
    return call_user_func_array(array(get_class(), $method), $args);
  }

  public static function label() {
    return static::name();
  }
}