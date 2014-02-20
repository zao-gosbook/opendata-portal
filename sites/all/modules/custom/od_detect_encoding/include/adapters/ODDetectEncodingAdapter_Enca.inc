<?php
/**
 * @file
 */

class ODDetectEncodingAdapter_Enca extends ODDetectEncodingAdapterAbstract {
  /**
   * @inheritdoc
   */
  public function guessFileEncoding($path) {
    $escaped = str_replace(array('"'), array('\"'), $path);
    if (file_exists($path) && ($output = $this->syscall("(enca -e -L russian \"{$path}\""))) {
      $a = 1;
    }
  }

  /**
   * @inheritdoc
   */
  public function guessEncoding($string) {
    $escaped = str_replace(array("'"), array("\\'"), $string);
    if ($output = $this->syscall("(echo '{$escaped}' | enca -e -L russian)")) {
      $a = 1;
    }
  }

  protected function processOutput() {

  }
  function convertList() {
    return array(

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