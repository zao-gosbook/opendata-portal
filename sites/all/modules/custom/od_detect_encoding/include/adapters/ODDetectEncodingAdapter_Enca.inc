<?php
/**
 * @file
 */

class ODDetectEncodingAdapter_Enca extends ODDetectEncodingAdapterAbstract {
  /**
   * @inheritdoc
   */
  public function guessFileEncoding($path) {
    $escaped = str_replace(array('"'), array('\"'), realpath($path));
    if (file_exists($path) && ($output = $this->syscall("enca -e -L russian \"{$path}\""))) {
      $output = trim($output, "\n");
      return $output;
    }

    return FALSE;
  }

  /**
   * @inheritdoc
   */
  public function guessEncoding($string) {
    $escaped = str_replace(array("'"), array("\\'"), $string);
    if ($output = $this->syscall("(echo '{$escaped}' | enca -e -L russian)")) {
      $output = trim($output, "\n");
      return $output;
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
    );
  }

  /**
   * Does system shell execution of a command.
   *   Successfully stolen from source below.
   *
   * @see http://de3.php.net/manual/en/function.system.php#39969
   * @param $command
   * @param bool $stderr
   * @return string|null
   */
  public function syscall($command, $stderr = FALSE){
    $result = '';
    $suffix = $stderr ? "2>&1" : "";
    if ($proc = popen("($command)","r")){
      while (!feof($proc)) $result .= fgets($proc, 1000);
      pclose($proc);
      return $result;
    }
  }

  public function check() {
    $working = FALSE;
    $output = NULL;
    exec('enca -v', $output);

    if (isset($output[0]) && preg_match('/enca ([0-9]+)\.([0-9]+)/i', $output[0], $reg)) {
      $this->_version = "$reg[1].$reg[2]";
      $working = TRUE;
    }

    return $working;
  }

  public function name() {
    return 'enca';
  }
}