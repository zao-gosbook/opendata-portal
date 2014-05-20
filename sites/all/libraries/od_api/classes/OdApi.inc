<?php

/**
 * @file
 * Contains the OdApi class.
 */

class OdApi {
  public $vars;
  public $root;
  public $main_url;
  public $list_url;

  public $args;
  public $currentArgs;
  public $page;
  public $valid;
  public $result;
  public $version;

  public $objects;

  public $validators = array();

  public function __construct($vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }
    $this->versions = array_values(array_diff(scandir(__DIR__ . '/objects/versions'), array('..', '.')));
    $this->root = OdApiObject::OBJECT_TYPE_IS_META_LIST;

    return $this;
  }

  public function execute($args, $vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }

    // Get root type.
    $type = $this->root;

    // Init current args.
    $this->currentArgs = array();

    // Get current type arg.
    $arg = isset($args[$type]) ? $args[$type] : NULL;

    // Allocate current type objects (will be overwritten by cycle).
    $objects = $this->objects;

    // Walk through args to children objects.
    while ($arg !== NULL) {
      // Add current type to current args.
      $this->currentArgs[$type] = $args[$type];

      // Get current object, which nesting depends on cardinality.
      $class_name = $this->getClassNameByType($type);
      if (method_exists($class_name, 'processArg')) {
        $arg = $class_name::processArg($arg);
      }

      $multiple_cardinality = $class_name::$typeCardinality === OdApiObject::OBJECT_CARDINALITY_IS_MULTIPLE;
      $object_exists = $multiple_cardinality ? !empty($objects[$type][$arg]) : !empty($objects[$type]);

      if (!$object_exists) {
        // Get parent. Parent may be OdApi class or class extended from OdApiObject class.
        $parent = !empty($object) ? $object : $this;
        // Get parent object. Parent object may be only class extended from OdApiObject class only.
        $parent_object = !empty($object) ? $object : NULL;

        // Unset current object class.
        unset($object);

        foreach ($this->versions as $version) {
          $possible_object = $this->createNewObjectByType($type, $version, $parent_object);

          $this->validators = array_merge($this->validators, array_values($possible_object->getValidators()));
          if (!$possible_object->argIsValid || !$possible_object->versionIsValid) {
            continue;
          }
          $object = clone $possible_object;
          $object->version = (float) $version;

          $multiple_cardinality = $class_name::$typeCardinality === OdApiObject::OBJECT_CARDINALITY_IS_MULTIPLE;

          if ($multiple_cardinality) {
            if (!isset($parent->objects[$type])) {
              $parent->objects[$type] = array();
            }

            $parent->objects[$type][$arg] = $object;
          }
          else {
            $parent->objects[$type] = $object;
          }

          break;
        }
      }
      else {
        $object = $multiple_cardinality ? $objects[$type][$arg] : $objects[$type];
      }

      if (empty($object)) {
        break;
      }

      if ($object->objectIsValid === FALSE) {
        break;
      }

      $children_types = $object::$childrenTypes;

      $children = FALSE;
      foreach ($children_types as $children_type) {
        if (isset($args[$children_type])) {
          $children = TRUE;
          $type = $children_type;
          $arg = $args[$children_type];
          $objects = $object->objects;
        }
      }

      if (!$children) {
        $arg = NULL;
      }
    }
  }

  /**
   * @param null|array $args
   * @param array $vars
   *
   * @return boolean|OdApiObject
   */
  public function _getObject($args = NULL, $vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }

    // Get current args if incoming args is missing.
    if (empty($args)) {
      if (!empty($this->currentArgs)) {
        $args = $this->currentArgs;
      }
      else {
        return FALSE;
      }
    }

    $this->execute($args);

    $type = $this->root;
    $arg = isset($args[$type]) ? $args[$type] : NULL;
    $objects = $this->objects;

    while ($arg !== NULL) {
      // Get current object, which nesting depends on cardinality.
      $class_name = $this->getClassNameByType($type);
      if (method_exists($class_name, 'processArg')) {
        $arg = $class_name::processArg($arg);
      }

      $multiple_cardinality = $class_name::$typeCardinality === OdApiObject::OBJECT_CARDINALITY_IS_MULTIPLE;
      $object = $multiple_cardinality ? $objects[$type][$arg] : $objects[$type];

      if (!$object || !$object->objectIsValid) {
        break;
      }

      // Get children types.
      $children_types = $object::$childrenTypes;

      $children = FALSE;
      foreach ($children_types as $children_type) {
        if (isset($args[$children_type])) {
          $children = TRUE;
          $type = $children_type;
          $arg = $args[$children_type];
          $objects = $object->objects;
        }
      }

      if (!$children) {
        $arg = NULL;
      }
    }

    return (!empty($object) && $object->objectIsValid) ? $object : FALSE;
  }

  public function getResult($args, $vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }

    $object = $this->_getObject($args);

    return is_object($object) ? $object->getResult() : FALSE;
  }

  public function getContent($args, $vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }

    $object = $this->_getObject($args);

    return is_object($object) ? $object->content : FALSE;
  }

  public function getOpendata($site, $vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }

    // List object.
    $meta_list_args = array('meta-list' => $site);
    $meta_list_result = $this->getResult($meta_list_args);
    if (empty($meta_list_result)) {
      return $meta_list_result;
    }
    $meta_list_result = $meta_list_result['meta'];

    // Meta object.
    foreach ($meta_list_result as &$meta) {
      $meta_args = $meta['#api'];
      $meta_result = $this->getResult($meta_args);
      $meta = $meta_result;
      if (empty($meta)) {
        continue;
      }
      OdApiHelper::clearProperties($meta);
      if (empty($meta['data'])) {
        continue;
      }

      // Publisher object.
      $publisher_args = $meta['publisher']['#api'];
      $publisher_result = $this->getResult($publisher_args);
      $meta['publisher'] = $publisher_result;
      OdApiHelper::clearProperties($meta['publisher']);

      // Source object.
      $data_list_args = $meta['data']['#api'];
      $data_list_result = $this->getResult($data_list_args);
      $meta['data'] = $data_list_result ? $data_list_result['data'] : $data_list_result;
      OdApiHelper::clearProperties($data_list_result['data']);
      if (empty($meta['data']) || !is_array($meta['data'])) {
        continue;
      }

      // Data object.
      foreach ($meta['data'] as &$data) {
        $data_args = $data['#api'];
        $data_result = $this->getResult($data_args);
        $data = $data_result;
        OdApiHelper::clearProperties($data);
        if (empty($data)) {
          continue;
        }

        // Structure object.
        $structure_args = $data['structure']['#api'];
        $structure_result = $this->getResult($structure_args);
        $data['structure'] = $structure_result;
        OdApiHelper::clearProperties($data['structure']);
      }
    }

    return $meta_list_result;
  }

  public function getErrors() {
    $errors = array();
    foreach ($this->validators as $validator) {
      if ($validator['type'] === OdApiObject::MESSAGE_TYPE_IS_ERROR && $validator['value'] === FALSE) {
        $errors[] = $validator;
      }
    }
    return $errors;
  }

  public function getValidators() {
    return $this->validators;
  }

  private function getClassNameByType($type, $version = NULL) {
    $type = preg_replace('/(^|-)([a-z])/e', 'strtoupper("\\2")', $type);
    $version = empty($version) ? 'Default' : filter_var($version, FILTER_SANITIZE_NUMBER_INT);
    return 'OdApi' . $type . $version;
  }

  private function createNewObjectByType($type, $version, $parent_object) {
    $class_name = $this->getClassNameByType($type, $version);
    $object = new $class_name($this, $parent_object);

    return $object;
  }
}
