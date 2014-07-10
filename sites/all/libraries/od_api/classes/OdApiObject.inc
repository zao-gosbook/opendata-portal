<?php

/**
 * @file
 * Contains the OdApiObject class.
 */

abstract class OdApiObject {
  const OBJECT_TYPE_IS_META_LIST = 'meta-list';
  const OBJECT_TYPE_IS_META = 'meta';
  const OBJECT_TYPE_IS_PUBLISHER = 'publisher';
  const OBJECT_TYPE_IS_DATA_LIST = 'data-list';
  const OBJECT_TYPE_IS_DATA = 'data';
  const OBJECT_TYPE_IS_STRUCTURE_list = 'structure-list';
  const OBJECT_TYPE_IS_STRUCTURE = 'structure';

  const OBJECT_CARDINALITY_IS_SINGLE = 1;
  const OBJECT_CARDINALITY_IS_MULTIPLE = 2;

  const OBJECT_FORMAT_RDFA = 'rdfa';
  const OBJECT_FORMAT_MICRODATA = 'csv';
  const OBJECT_FORMAT_JSON = 'json';
  const OBJECT_FORMAT_XML = 'xml';
  const OBJECT_FORMAT_CSV = 'csv';

  const MESSAGE_TYPE_IS_WARNING = 1;
  const MESSAGE_TYPE_IS_ERROR = 2;

  // Errors.
  const MACHINE_FORMAT_DETECTED = 1;

  // Warnings.
  const FORMAT_RDFA_DETECTED = 2;
  const FORMAT_MICRODATA_DETECTED = 3;
  const FORMAT_JSON_DETECTED = 4;
  const FORMAT_XML_DETECTED = 5;
  const FORMAT_CSV_DETECTED = 6;
  const FORMAT_CSV_IS_UTF8 = 7;

  protected static $allFormats = array(
    self::OBJECT_FORMAT_RDFA => array(
      'validator' => self::FORMAT_RDFA_DETECTED,
      'parser' => 'parseRdfa',
    ),
    self::OBJECT_FORMAT_MICRODATA => array(
      'validator' => self::FORMAT_MICRODATA_DETECTED,
      'parser' => 'parseMicrodata',
    ),
    self::OBJECT_FORMAT_JSON => array(
      'validator' => self::FORMAT_JSON_DETECTED,
      'parser' => 'parseJson',
    ),
    self::OBJECT_FORMAT_XML => array(
      'validator' => self::FORMAT_XML_DETECTED,
      'parser' => 'parseXml',
    ),
    self::OBJECT_FORMAT_CSV => array(
      'validator' => self::FORMAT_CSV_DETECTED,
      'parser' => 'parseCsv',
    ),
  );
  protected static $validatorsInfo = array(
    self::MACHINE_FORMAT_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'machine format is detected',
        FALSE => 'machine format is not detected',
      ),
    ),
    self::FORMAT_MICRODATA_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'microdata format is detected',
        FALSE => 'microdata format is not detected',
      ),
    ),
    self::FORMAT_RDFA_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'TRUE.',
        FALSE => 'FALSE.',
        TRUE => 'rdfa format is detected',
        FALSE => 'rdfa format is not detected',
      ),
    ),
    self::FORMAT_CSV_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'TRUE.',
        FALSE => 'FALSE.',
        TRUE => 'csv format is detected',
        FALSE => 'csv format is not detected',
      ),
    ),
    self::FORMAT_CSV_IS_UTF8 => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'csv format is utf8',
        FALSE => 'csv format is not utf8',
      ),
    ),
    self::FORMAT_XML_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'TRUE.',
        FALSE => 'FALSE.',
        TRUE => 'xml format is detected',
        FALSE => 'xml format is not detected',
      ),
    ),
    self::FORMAT_JSON_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'json format is detected',
        FALSE => 'json format is not detect',
      ),
    ),
  );

  public static $type;
  public static $title;
  public static $typeCardinality;
  public static $parentType;
  public static $childrenTypes;

  private $_validatorsInfo = array();

  protected $validators = array();
  public $error = NULL;

  /**
   * Root opendata api object.
   *
   * @var OdApi
   */
  public $odApi;

  // Object arg.
  public $arg;
  // Object args.
  public $args;

  /**
   * Object parent.
   *
   * @var OdApiObject
   */
  public $parent;
  public $objects;

  // Current version.
  public $version;
  // Parser type.
  public $format;

  // Defined urls.
  public $url;
  public $urls = array();

  // Parsers.
  public $parserRdfa;
  public $parserMicrodata;
  public $parserCsv;
  public $parserXml;
  public $parserJson;

  // Result.
  public $content;
  public $result;

  // Validation status variables.
  public $argIsValid;
  public $urlIsValid;
  public $parserIsValid;
  public $objectIsValid = TRUE;

  abstract protected function _getAvailableFormats();
  abstract protected function _validateArg();
  abstract protected function _validateUrl();
  abstract protected function _getFormatUrl($format);
  abstract protected function _parseRdfa();
  abstract protected function _parseMicrodata();
  abstract protected function _parseJson();
  abstract protected function _parseXml();
  abstract protected function _parseCsv();
  abstract protected function _getResult();

  /**
   * @param $odApi OdApi
   * @param $parent OdApiObject
   * @param array $args
   */
  public function __construct($odApi, $parent, $args) {
    // Detect current version.
    preg_match('/\d*$/', get_class($this), $matches);
    $this->version = !empty($matches) ? implode('.', str_split(reset($matches))) : FALSE;

    $this->initValidators();
    $this->odApi = $odApi;

    if ($this::$parentType) {
      if ($parent && is_object($parent) && $parent::$type == $this::$parentType) {
        $this->parent = $parent;
      }
    }

    $this->arg = $args[$this::$type];
    $this->args = $args;

    $this->_validateArg();
    $this->argIsValid = $this->objectIsValid;
    if (!$this->argIsValid) {
      return;
    }

    $this->_validateUrl();
    $this->urlIsValid = $this->objectIsValid;
    if (!$this->urlIsValid) {
      return;
    }

    $i = 0;
    do {
      $this->objectIsValid = TRUE;
      $this->error = NULL;

      $this->url = isset($this->urls[$i]) ? $this->urls[$i] : TRUE;

      $this->parse();
      $this->parserIsValid = $this->objectIsValid;
      if ($this->parserIsValid) {
        break;
      }
      $i++;
    }
    while ($i < count($this->urls));
  }

  private function initValidators() {
    $this->_validatorsInfo = array();

    $version_validators = self::$validatorsInfo;

    $default = get_parent_class($this);
    $default_validators = $default::$validatorsInfo;

    $object = get_parent_class($default);
    $object_validators = $object::$validatorsInfo;

    if (!empty($version_validators)) {
      $this->_validatorsInfo += $version_validators;
    }
    if (!empty($default_validators)) {
      $this->_validatorsInfo += $default_validators;
    }
    if (!empty($object_validators)) {
      $this->_validatorsInfo += $object_validators;
    }
  }

  public function getResult() {
    if (!empty($this->result)) {
      return $this->result;
    }

    $this->result = array(
      '#version' => $this->version,
      '#format' => $this->format,
    );
    $this->result += $this->_getResult();

    return $this->result;
  }

  public function getError() {
    return $this->error;
  }

  public function getApi() {
    $func_args = func_get_args();

    $args = $this->args;
    if ($func_args) {
      foreach ($func_args as $arg) {
        $args = array_merge($args, $arg);
      }
    }

    return $args;
  }

  public function parse() {
    foreach ($this->_getAvailableFormats() as $format) {
      $allFormats = $this::$allFormats;
      $value = $allFormats[$format];

      $url = $this->_getFormatUrl($format);
      if ($url === FALSE) {
        continue;
      }

      $this->{$value['parser']}($url);
      $this->{'_' . $value['parser']}($url);

      $result = !empty($this->content);
      $this->setValidator($value['validator'], $result);

      if ($result) {
        $this->format = $format;
        break;
      }
    }

    $this->setValidator($this::MACHINE_FORMAT_DETECTED, !empty($this->format));
  }

  protected function parseRdfa($url) {
    $RDFaParser = new OdApiRDFaParser();

    $actual_url = $this->url !== $url ? $url : NULL; // @todo Check it.
    $this->parserRdfa = $RDFaParser->parse($this->url, $actual_url);
  }

  protected function parseMicrodata($url) {}

  protected function parseJson($url) {}

  protected function parseXml($url) {}

  protected function parseCsv($url) {
    $encoding = !empty($this->odApi->vars['encoding']) ? $this->odApi->vars['encoding'] : NULL;

    if ($url !== TRUE) {
      $CSVParser = new OdApiCsvParser();
      switch ($this->version) {
        case '2.3';
          $this->parserCsv = $CSVParser->parse($url, $encoding, FALSE);
          break;
        default;
          $this->parserCsv = $CSVParser->parse($url, $encoding);
          break;
      }
    }
  }

  public function setValidator($validator_id, $value) {
    $value = (bool) $value;

    // Set validator value.
    $validator = $this->_validatorsInfo[$validator_id];
    $this->validators[$validator_id] = array(
      'type' => $validator['type'],
      'value' => $value,
      'description' => $validator['descriptions'][(integer) $value],
    );

    if ($value === FALSE && $validator['type'] === $this::MESSAGE_TYPE_IS_ERROR) {
      $this->objectIsValid = FALSE;
      $this->error = $validator['descriptions'][(integer) $value];
    }
  }

  public function getValidator($validator_id) {
    $validator = !empty($this->validators[$validator_id]) ? $this->validators[$validator_id]['value'] : FALSE;

    return $validator;
  }

  public function getParent() {
    return $this->parent;
  }

  public function getChildren($type, $arg = NULL) {
    $class_name = OdApiHelper::getClassNameByType($type);

    if (!in_array($type, $this::$childrenTypes)) {
      return FALSE;
    }

    if (empty($this->objects[$type])) {
      return FALSE;
    }

    $multiple_cardinality = $class_name::$typeCardinality === $class_name::OBJECT_CARDINALITY_IS_MULTIPLE;
    if ($multiple_cardinality) {
      $objects = array();
      foreach ($this->objects[$type] as $key => $object) {
        $objects[$key] = $object['validVersion'];
      }

      if (!empty($arg)) {
        if (method_exists($class_name, 'processArg')) {
          $arg = $class_name::processArg($arg);
        }

        if (isset($objects[$arg])) {
          $result = $objects[$arg];
        }
        else {
          return FALSE;
        }
      }
      else {
        $result = $objects;
      }
    }
    else {
      $result = $this->objects[$type]['validVersion'];
    }

    return $result;
  }
}
