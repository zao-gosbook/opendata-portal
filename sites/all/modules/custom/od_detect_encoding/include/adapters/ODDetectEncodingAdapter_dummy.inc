<?php
/**
 * @file
 */

class ODDetectEncodingAdapter_dummy extends ODDetectEncodingAdapterAbstract {
  /**
   * @inheritdoc
   */
  public function guessFileEncoding($path) {
    return FALSE;
  }

  /**
   * @inheritdoc
   */
  public function guessEncoding($string) {
    return FALSE;
  }

  function convertList() {
    return array();
  }

  public static function check() {
    return TRUE;
  }

  public function name() {
    return 'dummy';
  }
}