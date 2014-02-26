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

  public function convertTo($in_charset = ODDetectEncoding::ENC_AUTO, $out_charset, $string) {
    if ($in_charset == ODDetectEncoding::ENC_AUTO && ($in_charset = $this->guessEncoding($string)) === FALSE) {
      $this->getExceptionObject()->setInfo(ODDetectEncoding::ERR_CONVERT, 'Can\'t convert a string because an encoding can\'t be determined.');
      return $string;
    }

    // Do not try to convert if our string is already has a charset passed by $out_charset.
    if ($in_charset == $out_charset) {
      return $string;
    }

    return iconv($in_charset, $out_charset . $this->_convertFallback, $string);
  }
}