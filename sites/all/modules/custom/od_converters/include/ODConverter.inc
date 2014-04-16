<?php
/**
 * @file
 */

class ODConverter {
  /**
   * Errors definition
   */
  // File was not found.
  const ERR_FILE_NOT_FOUND = 1;

  // Internal adapter encoding has not been implemented in convertList() to
  // provide common encoding defined in ODDetectEncoding::ENC_* constants.
  const ERR_FORMAT_NOT_IMPLEMENTED = 2;

  // An error has been occurred while converting.
  const ERR_FORMATING = 3;

  // When an error
  const ERR_UNKNOWN = -1;

  // When no error actually has been occurred
  const ERR_NONE = 0;

  protected $codecs = array();
  protected $formats = array();
  protected $utilities = array();

  protected $codecOptions = array();

  /**
   * @param $source string
   * @param $fmt_source
   * @param $fmt_target
   */
  public function convertString($source, $fmt_source, $fmt_target) {
    if (!$this->isConversionSupported($fmt_source, $fmt_target)) {
      return FALSE;
    }

    $codec = $this->getCodec($fmt_source, $fmt_target);
    return $codec->convertString($source);
  }

  public function convertFile($source, $fmt_source, $target, $fmt_target) {
    $realpath_source = static::extractRealPath($source);
    if (!file_exists($realpath_source)) {
      return static::ERR_FILE_NOT_FOUND;
    }

    if (!$this->isConversionSupported($fmt_source, $fmt_target)) {
      return FALSE;
    }

    $codec = $this->getCodec($fmt_source, $fmt_target);
    return $codec->convertFile($realpath_source, static::extractRealPath($target));
  }

  /**
   * @param $fmt_source
   * @param $fmt_target
   */
  public function isConversionSupported($fmt_source, $fmt_target) {
    $codec_key = $this->codecKey(
      $this->getFormat($fmt_source)->name(),
      $this->getFormat($fmt_target)->name()
    );

    $codec = $this->getCodec($fmt_source, $fmt_target);
    return isset($this->codecs[$codec_key]);
  }

  public function codecKey($fmt_input, $fmt_output) {
    return "{$fmt_input}_to_{$fmt_output}";
  }

  /**
   * @param $format_name
   * @return ODConverterFormatInterface
   */
  public function getFormat($format_name) {
    if (!isset($this->formats[$format_name])) {
      $classname = "ODConverterFormat_{$format_name}";
      $file = static::directory('formats'). "/{$classname}.inc";
      if (file_exists($file)) {
        require_once $file;
      }

      if (!class_exists($classname)) {
        $this->formats[$format_name] = FALSE;
      }

      $this->formats[$format_name] = new $classname();
    }

    return $this->formats[$format_name];
  }

  public static function directory($type) {
    static $directories = NULL;
    if ($directories === NULL) {
      $root_dir = dirname(__FILE__);
      $directories = array(
        'utilities' => "$root_dir/utilities",
        'formats' => "$root_dir/formats",
        'codecs' => "$root_dir/codecs",
        'root' => $root_dir,
      );
    }

    if (!isset($directories[$type])) {
      throw new Exception("No directory for {$type}");
    }

    return $directories[$type];
  }

  /**
   * @param $fmt_source
   * @param $fmt_target
   * @return ODConverterCodecInterface
   * @throws Exception
   */
  public function getCodec($fmt_source, $fmt_target) {
    $codec_key = $this->codecKey($fmt_source, $fmt_target);
    if (!isset($this->codecs[$codec_key])) {
      $classname = "ODConverterCodec_{$codec_key}";
      $file = static::directory('codecs'). "/{$classname}.inc";
      if (file_exists($file)) {
        require_once $file;
      }

      if (!class_exists($classname)) {
        throw new Exception("Codec {$classname} cound\"t be loaded");
      }

      $codec = new $classname($this);
      $info = $codec->codec();
      if (isset($info['utility'])) {
        $codec->setUtility($this->getUtility($info['utility']));
      }

      $this->codecs[$codec_key] = $codec;
    }

    return $this->codecs[$codec_key];
  }

  public function getUtility($utility) {
    if (!isset($this->utilities[$utility])) {
      $classname = "ODConverterUtility_{$utility}";
      $file = static::directory('utilities'). "/{$classname}.inc";
      if (file_exists($file)) {
        require_once $file;
      }

      if (!class_exists($classname)) {
        throw new Exception("Codec {$classname} cound\"t be loaded");
      }

      // Call static method
      if (!call_user_func(array($classname, 'check'))) {
        throw new Exception("Utility {$utility} doesn\"t work");
      }

      $utilityObject = new $classname($this);
      $this->utilities[$utility] = $utilityObject;
    }

    return $this->utilities[$utility];
  }

  public function setCodecOptions($fmt_source, $fmt_target, $options, $value = NULL) {
    $codec_key = $this->codecKey($fmt_source, $fmt_target);
    $store = &$this->codecOptions[$codec_key];

    if (is_array($options)) {
      $store = $options;
    }
    elseif ($value !== NULL) {
      $store[$options] = $value;
    }
  }

  public function getCodecOptions($fmt_source, $fmt_target) {
    $codec_key = $this->codecKey($fmt_source, $fmt_target);

    return isset($this->codecOptions[$codec_key]) ? $this->codecOptions[$codec_key] : array();
  }


  public static function extractRealPath($path) {
    $realpath = $path;
    if ($wrapper = file_stream_wrapper_get_instance_by_uri($path)) {
      $realpath = $wrapper->realpath();
    }

    return $realpath;
  }
}
