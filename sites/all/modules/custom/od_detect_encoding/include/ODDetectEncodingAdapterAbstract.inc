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

  public function getConvertFallback() {
    return $this->_convertFallback;
  }
}
