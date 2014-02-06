<?php
/*
 * @file
 */

class ODDownloadPublicStreamWrapper extends DrupalPublicStreamWrapper {
  /**
   * Overrides getExternalUrl().
   * @inheritdoc
   */
  function getExternalUrl() {
    $pathinfo = pathinfo($this->uri);

    if ($pathinfo['dirname'] != "public://temp_converting_service") {
      return parent::getExternalUrl();
    }


    $path = str_replace('\\', '/', $this->getTarget());
    return $GLOBALS['base_url'] . '/od_download/files/' . drupal_encode_path($path);
  }
}