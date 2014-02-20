<?php
/**
 * @file
 */

class ODDetectEncoding {
  const ENC_UTF8 = 0x00;
  const ENC_CP1251 = 0x00;
  const ENC_CP1252 = 0x00;
  const ENC_ISO = 0x00;


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

  function guessFileEncoding($path) {
    return $this->_adapter->guessFileEncoding($path);
  }

  function guessEncoding($string) {
    return $this->_adapter->guessEncoding($string);
  }
}

interface ODDetectEncodingAdapterInterface {
  public function guessFileEncoding($path);
  public function guessEncoding($string);
  public function check();
  public function name();
  public function errorMsg();
  public function version();
}

abstract class ODDetectEncodingAdapterAbstract implements ODDetectEncodingAdapterInterface {
  protected $_version = '0.0.0';
  public function errorMsg() {}
  public function version() {
    return $this->_version;
  }
}