<?php
/**
 * @file
 */

interface ODDetectEncodingAdapterInterface {
  public function guessFileEncoding($path);
  public function guessEncoding($string);
  public static function check();
  public function name();
  public function errorMsg();
  public function version();
  public function convertList();
}