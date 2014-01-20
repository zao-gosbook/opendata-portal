<?php

/**
 * @file
 * Contains the OdApi class.
 */

class OdApi {
  public $vars;
  public $root;
  public $main_page_url;
  public $opendata_page_url;

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
    $this->versions = array(2.3); // scandir(getcwd() . '/objects/versions');
    $this->root = OdApiObject::OBJECT_TYPE_IS_LIST;

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
        $class_name::processArg($arg);
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
          $class_name = $this->getClassNameByType($type, $version);

          $possible_object = new $class_name($this, $parent_object);

          $this->validators = array_merge($this->validators, array_values($possible_object->getValidators()));
          if (!$possible_object->argIsValid || !$possible_object->versionIsValid) {
            continue;
          }
          $object = clone $possible_object;

          $object_is_valid = $object->objectIsValid;

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

          if (!$object_is_valid) { // @todo check it.
            break;
          }
        }
      }
      else {
        $object = $multiple_cardinality ? $objects[$type][$arg] : $objects[$type];
      }

      if (empty($object)) {
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
        $class_name::processArg($arg);
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

    return $object ? $object->getResult() : FALSE;
  }

  public function getContent($args, $vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }

    $object = $this->_getObject($args);

    return $object ? $object->content : FALSE;
  }

  public function getOpendata($site, $vars = array()) {
    // Remove time limit execution script.
    set_time_limit(0);
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }

    // List object.
    $list_args = array('list' => $site);
    $list_result = $this->getResult($list_args);
    if (empty($list_result)) {
      return $list_result;
    }
    $list_result = $list_result['meta'];

    // Meta object.
    foreach ($list_result as &$meta) {
      $meta_args = $meta['#api'];
      $meta_result = $this->getResult($meta_args);
      $meta = $meta_result;
      if (empty($meta)) {
        continue;
      }
      unset($meta['#version']);
      if (empty($meta['source'])) {
        continue;
      }
      $meta['data'] = $meta['source'];
      unset($meta['source']);

      // Publisher object.
      $publisher_args = $meta['publisher']['#api'];
      $publisher_result = $this->getResult($publisher_args);
      $meta['publisher'] = $publisher_result;
      unset($meta['publisher']['#version']);

      // Source object.
      $source_args = $meta['data']['#api'];
      $source_result = $this->getResult($source_args);
      $meta['data'] = $source_result ? $source_result['data'] : $source_result;
      unset($source_result['data']['#version']);
      if (empty($meta['data']) || !is_array($meta['data'])) {
        continue;
      }

      // Data object.
      foreach ($meta['data'] as &$data) {
        $data_args = $data['#api'];
        $data_result = $this->getResult($data_args);
        $data = $data_result;
        unset($data['#version']);
        if (empty($data)) {
          continue;
        }

        // Structure object.
        $structure_args = $data['structure']['#api'];
        $structure_result = $this->getResult($structure_args);
        $data['structure'] = $structure_result;
        unset($data['structure']['#version']);
      }
    }

    // Restore default time limit execution script.
    set_time_limit(ini_get('max_execution_time'));

    return $list_result;
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

  private function getClassNameByType($type, $version = NULL) { // @todo Сделать.
    $version = empty($version) ? 'Default' : filter_var($version, FILTER_SANITIZE_NUMBER_INT);
    return 'OdApi' . ucfirst($type) . $version;
  }
}
