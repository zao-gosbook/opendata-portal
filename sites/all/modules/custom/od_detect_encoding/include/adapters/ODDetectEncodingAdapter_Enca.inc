<?php
/**
 * @file
 */

class ODDetectEncodingAdapter_Enca extends ODDetectEncodingAdapterAbstract {
  //protected $_command = 'enca -e -L russian';
  protected $command = 'enca -e -L russian'; // @todo: Replace this with magic __get()

  /**
   * @inheritdoc
   */
  public function guessFileEncoding($path) {
    $escaped = $this->escape(realpath($path));
    if (!file_exists($path)) {
      $this->getExceptionObject()->setInfo(ODDetectEncoding::ERR_FILE_NOT_FOUND, "File '{$path}' was not found");
    }
    elseif (($output = $this->syscall("{$this->command} '{$escaped}'"))) {
      return $this->processOutput($output);
    }

    return FALSE;
  }

  /**
   * @inheritdoc
   */
  public function guessEncoding($string) {
    $escaped = $this->escape($string);
    if ($output = $this->syscall("echo '{$escaped}' | {$this->command}")) {
      return $this->processOutput($output);
    }

    return FALSE;
  }

  function convertList() {
    return array(
      'ASCII' => ODDetectEncoding::ENC_ASCII,
      'UTF-8' => ODDetectEncoding::ENC_UTF8,
      'CP1251' => ODDetectEncoding::ENC_CP1251,
      'ISO-8859-16' => ODDetectEncoding::ENC_ISO_8859_16,
      'unknown' => ODDetectEncoding::ENC_UNKNOWN,
      //@todo Add other encodings
    );
  }

  public static function check() {
    $working = FALSE;
    $output = NULL;
    exec('enca -v', $output);

    if (isset($output[0]) && preg_match('/enca ([0-9]+)\.([0-9]+)/i', $output[0], $reg)) {
      static::$_version = "$reg[1].$reg[2]";
      $working = TRUE;
    }

    return $working;
  }

  public function name() {
    return 'enca';
  }

  protected function processOutput($output) {
    $output = explode('/', trim($output, "\n"));
    return is_array($output) ? reset($output) : $output;
  }

  protected function escape($string) {
    return str_replace(array("'"), array("\\'"), $string); //@fixme: Replace with better thing
  }
}
