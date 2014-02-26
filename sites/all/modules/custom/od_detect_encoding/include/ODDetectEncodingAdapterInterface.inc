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

  /**
   * @return string
   */
  public function version();

  /**
   * @return array
   */
  public function convertList();

  /**
   * @return Exception
   */
  public function getExceptionObject();

  /**
   * @param string $in_charset
   * @param $out_charset
   * @param $string
   * @return string
   */
  public function convertTo($in_charset = ODDetectEncoding::ENC_AUTO, $out_charset, $string);
}