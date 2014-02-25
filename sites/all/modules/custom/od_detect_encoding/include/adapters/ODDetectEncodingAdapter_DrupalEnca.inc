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
}