<?php
/**
 * @file
 */

namespace ODDetectEncodingMimeProcessor\Processors\Text;
use ODDetectEncodingMimeProcessor\Processors;
use ODDetectEncodingMimeProcessorFactory;
ODDetectEncodingMimeProcessorFactory::inc('Text');

class Xml extends Processors\TextDefault {
  public function postConvert(&$string, $out_charset, $in_charset) {
    $string = preg_replace('/(<\?xml[^>]+encoding\=[\'\"])[^\'\"]+([\'\"][^>]+>)/i', "$1{$out_charset}$2", $string);
  }
}