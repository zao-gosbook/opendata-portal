<?php
/**
 * @file
 */

class ODDetectEncodingException extends Exception {
  public function setMessage($message) {
    $this->message = $message;
  }

  public function setCode($code) {
    $this->code = $code;
  }

  public function setInfo($code, $message) {
    $this->setCode($code);
    $this->setMessage($message);
  }
}