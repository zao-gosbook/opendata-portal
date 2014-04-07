<?php

abstract class ODConverterUtilityAbstract implements ODConverterUtilityInterface {
  /**
   * @var string
   */
  protected static $_version = '0.0.0';
  protected $options = array();

  /**
   * Does system shell execution of a command.
   *   Successfully stolen from source below.
   *
   * @see http://de3.php.net/manual/en/function.system.php#39969
   * @param $command
   * @param bool $stderr
   * @return string|null
   */
  public static function syscall($command, $stderr = FALSE){
    $result = '';
    $suffix = $stderr ? "2>&1" : "";
    if ($proc = popen("($command){$suffix}","r")){
      while (!feof($proc)) $result .= fgets($proc, 1000);
      pclose($proc);
      return $result;
    }
  }

  public function setOptions($option, $value = NULL) {
    if ($value === NULL && is_array($option)) {
      $this->options = $option;
    }
    elseif ($value !== NULL) {
      $this->options[$option] = $value;
    }
  }

  protected static function escape($string) {
    return str_replace(array("'"), array("\\'"), $string); //@fixme: Replace with better thing
  }
}