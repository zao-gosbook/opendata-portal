<?php

class ODConverterUtility_topojson_cmd extends ODConverterUtilityAbstract {
  protected $binaries = array();
  protected $command_build = array();
  protected $result = NULL;
  public static function check() {
    return TRUE; //@fixme: check properly
  }

  function __construct() {
    $this->construct();
  }

  protected function construct() {
    // @fixme
    $binary_path = dirname(__FILE__). '/../../3rdparty/topojson.nodejs/topojson/bin';
    $this->binaries['topojson'] = $binary_path. '/topojson';
  }

  public function setOutputFile($path) {
    $this->command_build['options']['output'] = '-o '. static::escape($path);
  }

  protected function fixFormat() {
    if (isset($this->command_build['input']['#file_original']) && isset($this->command_build['input']['#format'])) {
      $format = $this->command_build['input']['#format'];
      $file = $this->command_build['input']['#file_original'];
      $newfile = $file;
      if (($extension = pathinfo($file, PATHINFO_EXTENSION)) != $format::extension()) {
        $newfile = tempnam(sys_get_temp_dir(), get_class()). "{$format::extension()}";
        if (!copy($file, $newfile)) {
          throw new Exception("Can\"t copy file {$file} to {$newfile}");
        }
      }

      $this->command_build['input']['file'] = static::escape($newfile);
    }
  }

  public function setInputFile($path) {
    $this->command_build['input']['#file_original'] = $path;
    $this->fixFormat();
  }

  public function setInputFormat(ODConverterFormatInterface $format) {
    $this->command_build['input']['#format'] = $format;
    $this->fixFormat();
  }

  public function setOutputFormat(ODConverterFormatInterface $format) {
    $this->command_build['options']['output']['#format'] = $format;
    $this->fixFormat();
  }

  public function clean() {
    $this->command_build = array();
    $this->command_build['command'] = $this->binaries['topojson'];
  }

  protected function sortOrder() {
    return array(
      'options' => 0,
      'input' => 50,
    );
  }

  protected function sortCallback() {

  }

  protected function buildRecurse(&$build_array = NULL) {
    $built = '';
    if ($build_array === NULL) {
      $build_array = &$this->command_build;
    }

    //@fixme: Add sorts
    foreach ($build_array as $key => $clause) {
      if (substr($key, 0, 1) != '#') {
        if (is_array($clause)) {
          $built .= " ". $this->buildRecurse($clause);
        }
        else {
          $built .= " ". $clause;
        }
      }
    }

    return trim($built, " ");
  }

  public function execute() {
    $command = $this->buildRecurse();
    $output = $this->syscall($command);
    $this->result = $output;

    // Success if empty
    return empty($output);
  }

  public function getResult() {
    return $this->result;
  }
}