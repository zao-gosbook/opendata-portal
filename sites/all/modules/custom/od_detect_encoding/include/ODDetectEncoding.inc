<?php
/**
 * @file
 */

class ODDetectEncoding {
  /**
   * @var ODDetectEncodingAdapterInterface
   */
  protected $_adapter = NULL;

  function __construct(ODDetectEncodingAdapterInterface $adapter) {
    $this->setAdapter($adapter);
  }

  function setAdapter(ODDetectEncodingAdapterInterface $adapter) {
    $this->_adapter = $adapter;
  }

  function guessFileEncoding($path) {
    return $this->_adapter->guessFileEncoding($path);
  }

  function guessEncoding($string) {
    return $this->guessEncoding($string);
  }
}

interface ODDetectEncodingAdapterInterface {
  public function guessFileEncoding($path);
  public function guessEncoding($string);
}

abstract class ODDetectEncodingAdapterAbstract implements ODDetectEncodingAdapterInterface {}