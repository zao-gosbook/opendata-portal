<?php
/**
 * @file
 */

/**
 * Interface ODConverterFormatInterface
 */
interface ODConverterFormatInterface {
  public static function name();
  public static function label();
  public static function extension();
  public static function checkFilename($filename);
  public static function normalizeFilename($filename);
}