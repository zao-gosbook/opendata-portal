<?php
/**
 * @file
 */

class ODDetectEncoding {
  /**
   * Encodings definition
   * @fixme: Add other encodings
   */
  const ENC_ASCII = 'ASCII';
  const ENC_UTF8 = 'UTF-8';
  const ENC_CP1251 = 'CP1251';
  const ENC_CP1252 = 'CP1252';
  const ENC_ISO_8859_16 = 'ISO-8859-16';
  const ENC_UNKNOWN = 'unknown';
  const ENC_AUTO = 'auto';

  /**
   * Errors definition
   */
  // File was not found.
  const ERR_FILE_NOT_FOUND = 1;

  // Internal adapter encoding has not been implemented in convertList() to
  // provide common encoding defined in ODDetectEncoding::ENC_* constants.
  const ERR_ENCODING_NOT_IMPLEMENTED = 2;

  // An error has been occurred while converting.
  const ERR_CONVERT = 3;

  // When an error
  const ERR_UNKNOWN = -1;

  // When no error actually has been occurred
  const ERR_NONE = 0;

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

  /**
   * @return ODDetectEncodingAdapterInterface
   */
  function getAdapter() {
    return $this->_adapter;
  }

  protected function getInnerEncoding($external_encoding) {
    $list = $this->_adapter->convertList();

    if (!isset($list[$external_encoding])) {
      $this->_adapter->getExceptionObject()->setInfo(static::ERR_ENCODING_NOT_IMPLEMENTED, 'Encoding not implemented');
      return FALSE;
    }

    return $list[$external_encoding];
  }

  public function latestError() {
    return $this->_error;
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