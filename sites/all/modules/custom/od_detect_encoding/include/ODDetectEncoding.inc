<?php
/**
 * @file
 */

class ODDetectEncoding {
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

    return FALSE;
  }

  function guessEncoding($string) {
    if ($encoding = $this->_adapter->guessEncoding($string)) {
      return $this->getInnerEncoding($encoding);
    }

    return FALSE;
  }
}

interface ODDetectEncodingAdapterInterface {
  public function guessFileEncoding($path);
  public function guessEncoding($string);
  public function check();
  public function name();
  public function errorMsg();
  public function version();
  public function convertList();
}

abstract class ODDetectEncodingAdapterAbstract implements ODDetectEncodingAdapterInterface {
  protected $_version = '0.0.0';
  public function errorMsg() {}
  public function version() {
    return $this->_version;
  }
}