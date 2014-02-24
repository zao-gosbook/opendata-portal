<?php
/**
 * @file
 */

class ODDetectEncoding {
  /**
   * @fixme: Add other encodings
   */
  const ENC_ASCII = 'ASCII';
  const ENC_UTF8 = 'UTF8';
  const ENC_CP1251 = 'CP1251';
  const ENC_ISO_8859_16 = 'ISO-8859-16';
  const ENC_UNKNOWN = 'unknown';

  /**
   * @var ODDetectEncodingAdapterInterface
   */
  protected $_adapter = NULL;

  function __construct(ODDetectEncodingAdapterInterface $adapter) {
    if ($adapter->check()) {
      $this->setAdapter($adapter);
    }
    else {
      throw new Exception('Adapter ' . $adapter->name() . ' is broken and doesnt work because '. $adapter->errorMsg());
    }
  }

  function setAdapter(ODDetectEncodingAdapterInterface $adapter) {
    $this->_adapter = $adapter;
  }

  protected function getInnerEncoding($external_encoding) {
    $list = $this->_adapter->convertList();

    return isset($list[$external_encoding]) ? $list[$external_encoding] : static::ENC_UNKNOWN;
  }

  function guessFileEncoding($path) {
    if ($encoding = $this->_adapter->guessFileEncoding($path)) {
      return $this->getInnerEncoding($encoding);
    }

    return static::ENC_UNKNOWN;
  }

  function guessEncoding($string) {
    if ($encoding = $this->_adapter->guessEncoding($string)) {
      return $this->getInnerEncoding($encoding);
    }

    return static::ENC_UNKNOWN;
  }
}

interface ODDetectEncodingAdapterInterface {
  public function guessFileEncoding($path);
  public function guessEncoding($string);
  public static function check();
  public function name();
  public function errorMsg();
  public function version();
  public function convertList();
}

abstract class ODDetectEncodingAdapterAbstract implements ODDetectEncodingAdapterInterface {
  protected static $_version = '0.0.0';
  public function errorMsg() {}
  public function version() {
    return static::$_version;
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
}