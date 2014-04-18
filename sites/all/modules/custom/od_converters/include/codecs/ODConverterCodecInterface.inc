<?php
/**
 * @file
 */

interface ODConverterCodecInterface {
  public static function codec();
  public function convertFile($source, $target);
  public function convertString($source);
  public function setUtility(ODConverterUtilityInterface $utility);
}
