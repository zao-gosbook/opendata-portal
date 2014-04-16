<?php

interface ODConverterUtilityInterface {
  public static function check();
  public function clean();
  public function setOptions($option, $value = NULL);
  public function setInputFormat(ODConverterFormatInterface $format);
  public function setOutputFormat(ODConverterFormatInterface $format);
  public function setInputFile($path);
  public function setOutputFile($path);
  public function execute();
}