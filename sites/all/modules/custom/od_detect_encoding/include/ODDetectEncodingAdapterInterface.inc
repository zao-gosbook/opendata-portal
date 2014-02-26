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
   * Converts a string
   * @param string $string
   * @param string $out_charset
   * @param string $in_charset
   * @return bool|string
   */
  public function convertString($string, $out_charset, $in_charset = ODDetectEncoding::ENC_AUTO);

  /**
   * Converts file
   * @param string $input_file
   * @param string $output_file
   * @param string $out_charset
   * @param string $in_charset
   * @return bool
   */
  public function convertFile($input_file, $output_file,$out_charset, $in_charset = ODDetectEncoding::ENC_AUTO);

  /**
   * Copies a file from one destination to other
   * @param $input_file
   * @param $output_file
   * @return mixed
   */
  public function copyFile($input_file, $output_file);
}