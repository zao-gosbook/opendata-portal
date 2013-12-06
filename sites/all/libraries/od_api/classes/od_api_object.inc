<?php

/**
 * @file
 * Contains the OdApiObject class.
 */

abstract class OdApiObject {
  const OBJECT_TYPE_IS_LIST = 'list';
  const OBJECT_TYPE_IS_META = 'meta';
  const OBJECT_TYPE_IS_PUBLISHER = 'publisher';
  const OBJECT_TYPE_IS_SOURCE = 'source';
  const OBJECT_TYPE_IS_DATA = 'data';
  const OBJECT_TYPE_IS_STRUCTURE = 'structure';

  const OBJECT_CARDINALITY_IS_SINGLE = 1;
  const OBJECT_CARDINALITY_IS_MULTIPLE = 2;

  const MESSAGE_TYPE_IS_WARNING = 1;
  const MESSAGE_TYPE_IS_ERROR = 2;

  // Errors.
  const MACHINE_FORMAT_DETECTED = 1;

  // Warnings.
  const FORMAT_MICRODATA_DETECTED = 2;
  const FORMAT_RDFA_DETECTED = 3;
  const FORMAT_CSV_DETECTED = 4;
  const FORMAT_CSV_IS_UTF8 = 5;
  const FORMAT_XML_DETECTED = 6;
  const FORMAT_JSON_DETECTED = 7;

  protected static $validatorsInfo = array(
    self::MACHINE_FORMAT_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_ERROR,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'Machine format detected.',
        FALSE => 'Machine format did not detect.',
      ),
    ),
    self::FORMAT_MICRODATA_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'Microdata format detected.',
        FALSE => 'Microdata format did not detect.',
      ),
    ),
    self::FORMAT_RDFA_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'TRUE.',
        FALSE => 'FALSE.',
        TRUE => 'Rdfa format detected.',
        FALSE => 'Rdfa format did not detect.',
      ),
    ),
    self::FORMAT_CSV_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'TRUE.',
        FALSE => 'FALSE.',
        TRUE => 'Csv format detected.',
        FALSE => 'Csv format did not detect.',
      ),
    ),
    self::FORMAT_CSV_IS_UTF8 => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'Csv format is utf8.',
        FALSE => 'Csv format is not utf8.',
      ),
    ),
    self::FORMAT_XML_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'TRUE.',
        FALSE => 'FALSE.',
        TRUE => 'Xml format detected.',
        FALSE => 'Xml format did not detect.',
      ),
    ),
    self::FORMAT_JSON_DETECTED => array(
      'type' => self::MESSAGE_TYPE_IS_WARNING,
      'value' => NULL,
      'descriptions' => array(
        TRUE => 'Json format detected.',
        FALSE => 'Json format did not detect.',
      ),
    ),
  );

  protected static $type;
  protected static $parentType;
  /**
   * @var array
   */
  protected static $childrenTypes;
  /**
   * @var array
   */
  protected static $message_texts;

  public static $title;

  private $_validatorsInfo = array();
  public $validators = array();

  private $localNamespaces; // @todo Check it.

  /**
   * Root opendata api object.
   *
   * @var OdApi
   */
  public $od_api;

  // Object api args.
  public $args;
  public $api;

  /**
   * Object parent.
   *
   * @var OdApiObject
   */
  public $parent;
  public $objects;

  // Defined parser type.
  public $formatType;

  // Defined urls.
  public $url;
  public $urls;

  /**
   * RDFa parser.
   *
   * @var OdApiRDFaParser
   */
  public $parserRDFa;
  public $parserMicrodata;
  /**
   * CSV parser.
   *
   * @var OdApiCSVParser
   */
  public $parserCSV;
  public $parserXML;
  public $parserJSON;

  // Messages.
  public $messages = array();

  // Result.
  public $content;
  public $result;

  // Validation status variables.
  public $argIsValid;
  public $versionIsValid;
  public $parserIsValid;

  public $objectIsValid = TRUE;

  abstract public function setPossibleUrls();
  abstract public function validateArg();
  abstract public function validateVersion();
  abstract public function validateObject();
  abstract public function _parseRdf();
  abstract public function _parseCsv();
  abstract public function getResult();

  /**
   * @param $od_api OdApi
   * @param $parent OdApiObject
   */
  public function __construct($od_api, $parent) {
    $this->initValidators();
    $this->od_api = $od_api;

    if ($this::$parentType) {
      if ($parent && is_object($parent) && $parent::$type == $this::$parentType) {
        $this->parent = $parent;
      }
    }

    $this->args = $od_api->currentArgs;

    $this->validateArg();
    $this->argIsValid = $this->objectIsValid;
    if (!$this->argIsValid) {
      return;
    }

    $this->validateVersion();
    $this->versionIsValid = $this->objectIsValid;
    if (!$this->versionIsValid) {
      return;
    }

    $this->api = $this->getApi();

    $this->setLocalNamespaces();
    $this->setPossibleUrls();

    $this->validateObject();
    $this->parserIsValid = $this->objectIsValid; // @todo Check parseIsValid set before parsing.
    if (!$this->parserIsValid) {
      return;
    }

    $this->parse();
    $this->parserIsValid = $this->objectIsValid;
    if (!$this->parserIsValid) {
      return;
    }
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

  private function setLocalNamespaces() {
    $local_namespaces = array(
      'rdf:' => 'http://www.w3.org/1999/02/22-rdf-syntax-ns#',
      'dc:' => 'http://purl.org/dc/terms/',
      'foaf:' => 'http://xmlns.com/foaf/0.1/',
    );

    $this->localNamespaces = $local_namespaces;
  }

  public function getApi() {
    $args = func_get_args();

    $api = $this->args;
    if ($args) {
      foreach ($args as $arg) {
        $api = array_merge($api, $arg);
      }
    }

    return $api;
  }

  public function localNamespaceWrap($var) {
    return strtr($var, array_flip($this->localNamespaces));
  }

  public function localNamespaceUnwrap($var) {
    return strtr($var, $this->localNamespaces);
  }

  /**
   * @todo Add another parsers for 3.0 version.
   */
  public function parse() {
    if (empty($this->formatType) && isset($this->urls['semantic'])) {
      $this->parseRDFa();

      if ($this->getValidator($this::FORMAT_RDFA_DETECTED)) {
        $this->formatType = 'rdfa';
      }
    }

    if (empty($this->formatType) && isset($this->urls['file_csv'])) {
      $this->parseCSV();

      if ($this->getValidator($this::FORMAT_CSV_DETECTED)) {
        $this->formatType = 'csv';
      }
    }

    $this->setValidator($this::MACHINE_FORMAT_DETECTED, !empty($this->formatType));
  }

  public function parseRDFa() {
    $this->parserRDFa = new OdApiRDFaParser();
    $this->parserRDFa->parse($this->urls['semantic']);

    $this->_parseRdf();
  }

  public function parseCSV() {
    $encoding = !empty($this->od_api->vars['encoding']) ? $this->od_api->vars['encoding'] : FALSE;

    $this->parserCSV = new OdApiCSVParser();
    $this->parserCSV->parse($this->urls['file_csv'], $encoding);

    $this->_parseCsv();
  }

  public function getMessageText($message_id, $value, $args) {
    $message_texts = $this::$message_texts;

    $message = isset($message_texts[$message_id]) ? format_string($message_texts[$message_id][$value], $args) : FALSE;

    return $message;
  }

  public function setValidator($validator_id, $value, $args = array()) {
    // Set validator value.
    $validator = $this->_validatorsInfo[$validator_id];
    $this->validators[$validator_id] = array(
      'type' => $validator['type'],
      'value' => $value,
      'description' => $validator['descriptions'][(integer) $value],
    );

    if ($value === FALSE && $validator['type'] === $this::MESSAGE_TYPE_IS_ERROR) {
      $this->objectIsValid = FALSE;
    }
  }

  public function getValidator($validator_id) {
    $validator = !empty($this->validators[$validator_id]) ? (bool) $this->validators[$validator_id]['value'] : FALSE;

    return $validator;
  }

  public function getValidators() {
    return $this->validators;
  }

  public function getError() {
    $error = NULL;
    foreach ($this->validators as $validator) {
      if ($validator['value'] === (integer) FALSE && $validator['type'] === $this::MESSAGE_TYPE_IS_ERROR) {
        $error = $validator;
        break;
      }
    }

    return $error;
  }

  public function checkUrl($url) {
    $curl = curl_init();
    curl_setopt($curl, CURLOPT_URL, $url);
    curl_setopt($curl, CURLOPT_HEADER, 1);
    curl_setopt($curl, CURLOPT_NOBODY, 1);
    curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($curl, CURLOPT_FRESH_CONNECT, 1);

    $result = curl_exec($curl) && curl_getinfo($curl, CURLINFO_HTTP_CODE) < 400;

    curl_close($curl);

    return $result;
  }

  public function checkErrorExists() {
    $error = $this->getError();

    return !empty($error);
  }
}
