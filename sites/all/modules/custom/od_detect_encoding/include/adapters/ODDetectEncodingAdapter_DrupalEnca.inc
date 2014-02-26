<?php
/**
 * @file
 */

class ODDetectEncodingAdapter_DrupalEnca extends ODDetectEncodingAdapter_Enca {
  /**
   * @inheritdoc
   */
  public function guessFileEncoding($path) {
    // Regular path.
    $scheme = file_uri_scheme($path);
    // Remote path
    if ($scheme == 'http' || $scheme == 'https') {
      return $this->guessRemoteFileEncoding($path);
    }

    // Drupal wrapped file
    if ($scheme !== FALSE && ( $sWrapper = file_stream_wrapper_get_instance_by_uri($path) )) {
      $sWrapper = file_stream_wrapper_get_instance_by_uri($path);
      $path = $sWrapper->realpath();
    }

    return parent::guessFileEncoding($path);
  }

  /**
   * Downloads file with wget and
   * @param $url
   * @return array|bool|mixed
   */
  public function guessRemoteFileEncoding($url) {
    $url_escaped = $this->escape($url);
    if ($output = $this->syscall("wget -q -O - \"{$url}\" | {$this->command}")) {
      return $this->processOutput($output);
    }

    return FALSE;
  }

  public function name() {
    return 'drupal_enca';
  }

  public static function check() {
    return parent::check() && static::_checkWgetVersion();
  }

  protected static function _checkWgetVersion() {
    $output = array();
    exec('wget --version', $output);
    $status = FALSE;
    if (count($output) > 0 && preg_match('/([0-9]+)\.([0-9]+)/i', $output[0], $reg)) {
      $status = TRUE;
    }

    return $status;
  }
}