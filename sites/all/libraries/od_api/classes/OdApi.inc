<?php

/**
 * @file
 * Contains the OdApi class.
 */

class OdApi {
  private $currentArgs;
  private $versions;

  public $vars;

  public $objects;

  public function __construct($vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }
    $versions = array_values(array_diff(scandir(__DIR__ . '/objects/versions'), array('..', '.')));
    usort($versions, function($a, $b) {
      return version_compare($a, $b, '<');
    });
    $this->versions = $versions;

    return $this;
  }

  public function execute($args, $vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }

    // Get root object type.
    $type = OdApiObject::OBJECT_TYPE_IS_META_LIST;

    // Init current args.
    $this->currentArgs = array();

    // Get current type arg.
    $arg = isset($args[$type]) ? $args[$type] : NULL;

    // Allocate current type objects (will be overwritten by cycle).
    $objects = $this->objects;

    // Walk through args to children objects.
    while ($arg !== NULL) {
      // Prepare and format arg by current type.
      $class_name = OdApiHelper::getClassNameByType($type);
      if (method_exists($class_name, 'processArg')) {
        $arg = $class_name::processArg($arg);
      }

      // Add current arg to current args.
      $this->currentArgs[$type] = $arg;

      // Get current object, which nesting depends on cardinality.
      $multiple_cardinality = $class_name::$typeCardinality === OdApiObject::OBJECT_CARDINALITY_IS_MULTIPLE;
      $object_exists = $multiple_cardinality ? !empty($objects[$type][$arg]) : !empty($objects[$type]);

      if (!$object_exists) {
        // Get parent. Parent may be OdApi class or class extended from OdApiObject class.
        $parent = !empty($object) ? $object : $this;
        // Get parent object. Parent object may be only class extended from OdApiObject class only.
        $parent_object = !empty($object) ? $object : NULL;

        $current = array();
        $current['validVersion'] = FALSE;
        $current['allVersions'] = array();
        foreach ($this->versions as $version) {
          $object = $this->createNewObjectByType($type, $version, $parent_object);
          $current['allVersions'][$version] = $object;

          if ($object->objectIsValid) {
            $current['validVersion'] = $object;
          }

          if ($multiple_cardinality) {
            if (!isset($parent->objects[$type])) {
              $parent->objects[$type] = array();
            }

            $parent->objects[$type][$arg] = $current;
          }
          else {
            $parent->objects[$type] = $current;
          }

          if ($object->objectIsValid) {
            break;
          }

          unset($object);
        }
      }
      else {
        $object = $multiple_cardinality ? $objects[$type][$arg]['validVersion'] : $objects[$type]['validVersion'];
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
          $arg = $args[$type];
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
   * @return boolean|array
   */
  private function getObjectCollection($args = NULL, $vars = array()) {
    $object_collection = FALSE;

    $this->saveVars($vars);

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

    $type = OdApiObject::OBJECT_TYPE_IS_META_LIST;

    $arg = isset($args[$type]) ? $args[$type] : NULL;
    $objects = $this->objects;

    while ($arg !== NULL) {
      // Get current object, which nesting depends on cardinality.
      $class_name = OdApiHelper::getClassNameByType($type);
      if (method_exists($class_name, 'processArg')) {
        $arg = $class_name::processArg($arg);
      }

      $multiple_cardinality = $class_name::$typeCardinality === OdApiObject::OBJECT_CARDINALITY_IS_MULTIPLE;
      $object_collection = $multiple_cardinality ? $objects[$type][$arg] : $objects[$type];
      $object = $object_collection['validVersion'];

      if ($object === FALSE) {
        break;
      }

      // Get children types.
      $children_types = $object::$childrenTypes;

      $children = FALSE;
      foreach ($children_types as $children_type) {
        if (isset($args[$children_type])) {
          $children = TRUE;
          $type = $children_type;
          $arg = $args[$type];
          $objects = $object->objects;
        }
      }

      if (!$children) {
        $arg = NULL;
      }
    }

    return $object_collection;
  }

  /**
   * @param null|array $args
   * @param array $vars
   *
   * @return boolean|OdApiObject
   */
  private function getValidObject($args = NULL, $vars = array()) {
    $object_collection = $this->getObjectCollection($args, $vars);

    return !empty($object_collection) ? $object_collection['validVersion'] : FALSE;
  }

  public function getResult($args, $vars = array()) {
    $this->saveVars($vars);
    $object = $this->getValidObject($args);

    return is_object($object) ? $object->getResult() : FALSE;
  }

  public function getError() {
    $error = NULL;
    $object_collection = $this->getObjectCollection();

    if (!empty($object_collection) && $object_collection['validVersion'] === FALSE) {
      $object = reset($object_collection['allVersions']);
      $error = $object->getError();
    }

    return $error;
  }

  public function saveVars($vars = array()) {
    // Save vars.
    if (!empty($vars)) {
      $this->vars = $vars;
    }
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

  /**
   * @param $type
   * @param $version
   * @param OdApiObject
   * @return OdApiObject
   */
  private function createNewObjectByType($type, $version, $parent_object) {
    $class_name = OdApiHelper::getClassNameByType($type, $version);
    $object = new $class_name($this, $parent_object, $this->currentArgs);

    return $object;
  }

  /**
   * @param null $arg
   * @return array|OdApiObject|bool
   *
   * @todo Refactor this.
   */
  public function getChildren($arg = NULL) {
    $type = OdApiObject::OBJECT_TYPE_IS_META_LIST;
    $class_name = OdApiHelper::getClassNameByType($type);

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
