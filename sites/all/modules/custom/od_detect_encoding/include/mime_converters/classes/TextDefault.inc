<?php
/**
 * @file
 * Default processor for mime application example
 */

namespace ODDetectEncodingMimeProcessor\Processors;
class TextDefault extends \ODDetectEncodingMimeProcessorDefault {
  public function getMimeType() {
    return 'text/plain';
  }
}