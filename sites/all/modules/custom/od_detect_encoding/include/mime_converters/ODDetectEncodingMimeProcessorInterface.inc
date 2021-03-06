<?php
/**
 * @file
 */

interface ODDetectEncodingMimeProcessorInterface {
  public function setConverterAdapter(ODDetectEncodingAdapterInterface $adapter);
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

  /**
   * Gets mime type for this type of file
   * @return string
   */
  public function getMimeType();
}