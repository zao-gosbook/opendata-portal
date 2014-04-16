<?php
/**
 * @file
 */

abstract class ODDetectEncodingMimeProcessorAbstract implements ODDetectEncodingMimeProcessorInterface {
  /**
   * @var ODDetectEncodingAdapterInterface
   */
  protected $converter = NULL;
  public function setConverterAdapter(ODDetectEncodingAdapterInterface $adapter) {
    $this->converter = $adapter;
  }

  protected function postConvert(&$string) {}
  protected function preConvert(&$string) {}

  public function convertFile($input_file, $output_file, $out_charset, $in_charset = ODDetectEncoding::ENC_AUTO) {
    if ($in_charset == ODDetectEncoding::ENC_AUTO && ($in_charset = $this->converter->guessFileEncoding($input_file)) === FALSE) {
      $this->converter->getExceptionObject()->setInfo(ODDetectEncoding::ERR_CONVERT, 'Can\'t convert a string because an encoding can\'t be determined.');
      return FALSE;
    }

    // Do not try to convert if our string is already has a charset passed by $out_charset.
    if ($in_charset == $out_charset) {
      // Just copy a file
      $this->copyFile($input_file, $output_file);
      return TRUE;
    }

    // Read file contents
    // @fixme: replace file_get_contents() with adapter's getContent method
    if (!($converted = file_get_contents($input_file))) {
      // @fixme: Set an error for this operation
      return FALSE;
    }

    // Apply pre conversion operations
    $this->preConvert($converted, $out_charset, $in_charset);

    // Convert encoding
    $converted = iconv($in_charset, $out_charset . $this->converter->getConvertFallback(), $converted);

    // Apply post conversion operations
    $this->postConvert($converted, $out_charset, $in_charset);

    // Write an output file
    if (!(file_put_contents($output_file, $converted))) {
      // @fixme: Set an error for this operation
      return FALSE;
    }

    return TRUE;
  }

  public function convertString($string, $out_charset, $in_charset = ODDetectEncoding::ENC_AUTO) {
    if ($in_charset == ODDetectEncoding::ENC_AUTO && ($in_charset = $this->converter->guessEncoding($string)) === FALSE) {
      $this->converter->getExceptionObject()->setInfo(ODDetectEncoding::ERR_CONVERT, 'Can\'t convert a string because an encoding can\'t be determined.');
      return FALSE;
    }

    // Do not try to convert if our string is already has a charset passed by $out_charset.
    if ($in_charset == $out_charset) {
      return $string;
    }

    // Apply pre conversion operations
    $this->preConvert($converted, $out_charset, $in_charset);

    // Convert encoding
    $converted = iconv($in_charset, $out_charset . $this->converter->getConvertFallback(), $string);

    // Apply post conversion operations
    $this->postConvert($converted, $out_charset, $in_charset);

    return $converted;
  }

  public function copyFile($input_file, $output_file) {
    $status = FALSE;
    if (copy($input_file, $output_file)) {
      $status = TRUE;
    }
    //@fixme: Replace file_get_contents() with calling adapter's getContent method
    elseif (($file_content = file_get_contents($input_file)) && (file_put_contents($output_file, $file_content))) {
      $status = TRUE;
    }

    return $status;
  }
}