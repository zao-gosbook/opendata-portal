<?php
/**
 * @file
 */

/**
 * Class ODDetectEncodingMimeProcessorFactory
 * @todo: Cache
 */
class ODDetectEncodingMimeProcessorFactory {
  protected static $default_processor_class = 'ODDetectEncodingMimeProcessorDefault';
  protected static $class_prefix = 'ODDetectEncodingMimeProcessor_';
  protected static $cached = array();

  /**
   * @param $mime
   * @return bool|ODDetectEncodingMimeProcessorInterface
   */
  public static function getProcessor($mime) {
    if (static::inc($mime)) {
      $parts = static::mimeParse($mime);

      // Search for a definite processor
      $class_paths = array();
      $class_paths[] = "ODDetectEncodingMimeProcessor\\Processors\\{$parts[0]}\\{$parts[1]}";
      $class_paths[] = "ODDetectEncodingMimeProcessor\\Processors\\{$parts[0]}Default";

      $processor = FALSE;
      foreach ($class_paths as $_class_path) {
        if (class_exists($_class_path)) {
          $processor = new $_class_path();
          break;
        }
      }
    }

    return $processor ? $processor : static::getProcessorDefault();
  }

  /**
   * @param $uri
   * @return bool|ODDetectEncodingMimeProcessorInterface
   */
  public static function getProcessorFile($uri) {
    if (file_exists($uri) && ($mime = file_get_mimetype($uri))) {
      return static::getProcessor($mime);
    }

    return FALSE;
  }

  public static function getProcessorDefault() {
    return new static::$default_processor_class();
  }

  public static function inc($mime) {
    $parts = static::mimeParse($mime);
    $env = static::env();

    $filepath = NULL;
    // Default handler for group type e.g. Text,Application, Image and etc
    if ($parts[1] === NULL) {
      $path = "classes/{$parts[0]}Default.inc";
      $filepath = "{$env}/{$path}";
    }
    else {
      // Search for a definite processor
      $path = "classes/{$parts[0]}/{$parts[1]}.inc";
      $filepath = "{$env}/{$path}";
    }

    // Try to load require file
    if ($status = file_exists($filepath)) {
      require_once $filepath;
    }

    return $status;
  }

  protected static function mimeParse($mime) {
    $parts = explode('/', trim($mime, "\r\n\t "));
    if (count($parts) < 2) {
      $parts[0] = $mime;
      $parts[1] = NULL;
    }

    // Normalize names
    foreach ($parts as &$_part) {
      $_part = ($_part !== NULL) ? strtoupper(substr($_part, 0, 1)). strtolower(substr($_part, 1)) : $_part;
    }
    unset($_part);

    return $parts;
  }

  public static function env() {
    return dirname(__FILE__);
  }
}