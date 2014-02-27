<?php
/**
 * @file
 */

abstract class ODDetectEncodingAdapterAbstract implements ODDetectEncodingAdapterInterface {
  /**
   * @var string
   */
  protected static $_version = '0.0.0';
  /**
   * @var ODDetectEncodingException
   */
  protected $_error = NULL;

  protected $_convertFallback = NULL;

  public function errorMsg() {}

  public function version() {
    return static::$_version;
  }

  function __construct() {
    $this->_error = new ODDetectEncodingException();
    $this->setConvertFallback('TRANSLIT');
  }
  /**
   * Does system shell execution of a command.
   *   Successfully stolen from source below.
   *
   * @see http://de3.php.net/manual/en/function.system.php#39969
   * @param $command
   * @param bool $stderr
   * @return string|null
   */
  public function syscall($command, $stderr = FALSE){
    $result = '';
    $suffix = $stderr ? "2>&1" : "";
    if ($proc = popen("($command){$suffix}","r")){
      while (!feof($proc)) $result .= fgets($proc, 1000);
      pclose($proc);
      return $result;
    }
  }

  /**
   * @return ODDetectEncodingException
   */
  public function getExceptionObject() {
    return $this->_error;
  }

  public function setConvertFallback($fallback = NULL) {
    $this->_convertFallback = !empty($fallback) ? "//{$fallback}" : NULL;
  }

  public function convertString($string, $out_charset, $in_charset = ODDetectEncoding::ENC_AUTO) {
    if ($in_charset == ODDetectEncoding::ENC_AUTO && ($in_charset = $this->guessEncoding($string)) === FALSE) {
      $this->getExceptionObject()->setInfo(ODDetectEncoding::ERR_CONVERT, 'Can\'t convert a string because an encoding can\'t be determined.');
      return FALSE;
    }

    // Do not try to convert if our string is already has a charset passed by $out_charset.
    if ($in_charset == $out_charset) {
      return $string;
    }

    return iconv($in_charset, $out_charset . $this->_convertFallback, $string);
  }

  public function convertFile($input_file, $output_file, $out_charset, $in_charset = ODDetectEncoding::ENC_AUTO) {
    if ($in_charset == ODDetectEncoding::ENC_AUTO && ($in_charset = $this->guessFileEncoding($input_file)) === FALSE) {
      $this->getExceptionObject()->setInfo(ODDetectEncoding::ERR_CONVERT, 'Can\'t convert a string because an encoding can\'t be determined.');
      return FALSE;
    }

    // Do not try to convert if our string is already has a charset passed by $out_charset.
    if ($in_charset == $out_charset) {
      // Just copy a file
      $this->copyFile($input_file, $output_file);
      return TRUE;
    }

    // Read file contents
    if (!($converted = file_get_contents($input_file))) { //@fixme: replace with adapter's getContent method
      // @fixme: Set an error for this operation
      return FALSE;
    }

    // Convert encoding
    $converted = iconv($in_charset, $out_charset . $this->_convertFallback, $converted);

    // Write an output file
    if (!(file_put_contents($output_file, $converted))) {
      // @fixme: Set an error for this operation
      return FALSE;
    }

    return TRUE;
  }

  public function copyFile($input_file, $output_file) {
    $status = FALSE;
    //@fixme: Replace with calling adapter's copyFile()
    if (copy($input_file, $output_file)) {
      $status = TRUE;
    }
    //@fixme: Replace with calling adapter's getContent method
    elseif (($file_content = file_get_contents($input_file)) && (file_put_contents($output_file, $file_content))) {
      $status = TRUE;
    }

    return $status;
  }
}
