<?php
/**
 * @file
 */
namespace ODDetectEncodingMimeProcessor\Processors\Application;
use ODDetectEncodingMimeProcessor\Processors\Text;
use ODDetectEncodingMimeProcessorFactory;
ODDetectEncodingMimeProcessorFactory::inc('Text/Xml');

class Xml extends Text\Xml {
  public function getMimeType() {
    return 'application/xml';
  }
}