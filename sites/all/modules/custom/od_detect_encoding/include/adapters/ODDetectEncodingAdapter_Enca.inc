<?php
/**
 * @file
 */

class ODDetectEncodingAdapter_Enca extends ODDetectEncodingAdapterAbstract {
  /**
   * @inheritdoc
   */
  public function guessFileEncoding($path) {

  }

  /**
   * @inheritdoc
   */
  public function guessEncoding($string) {

  }

  public function check() {
    $result = exec('enca -v');
  }
}