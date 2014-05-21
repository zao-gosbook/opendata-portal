<?php
/**
 * @file
 */

namespace ODDetectEncodingMimeProcessor\Processors\Application;
class Zip extends \ODDetectEncodingMimeProcessorAbstract {
  public function getMimeType() {
    return 'application/zip';
  }
}