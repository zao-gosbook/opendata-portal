<?php
/**
 * @file
 * Default processor for mime application example
 */

namespace ODDetectEncodingMimeProcessor\Processors;
class ApplicationDefault extends \ODDetectEncodingMimeProcessorDefault {
  public function getMimeType() {
    return 'application/undefined';
  }
}