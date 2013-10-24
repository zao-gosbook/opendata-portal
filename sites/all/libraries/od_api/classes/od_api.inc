<?php

/**
 * @file
 * Contains the OdApi class.
 */

/**
 * Opendata API class.
 */
class OdApi {
  private $args;
  private $query;
  private $baseUrl;
  private $types;
  private $pages;
  private $result;

  public function __construct($vars) {
    $this->args = array_values($vars['args']);
    $this->query = $vars['query'];
    $this->baseUrl = $vars['baseUrl'];

    $this->setTypes();
  }

  private function setTypes() {
    $types = array(
      'OdApiList' => array(
        'OdApiMeta' => array(
          'OdApiPublisher' => array(),
          'OdApiSource' => array(
            'OdApiData' => array(
              'OdApiStructure' => array(),
            ),
          ),
        ),
      ),
    );

    $this->types = $types;
  }

  private function setPages() {
    $pages = array();
    $types = $this->types;

    $object_args = array();
    foreach ($this->args as $arg) {
      $arg_is_valid = FALSE;
      $available_types = array_keys($types);

      $object_args[] = $arg;
      foreach ($available_types as $available_type) {
        $parent = $pages ? end($pages) : NULL;
        $vars = array(
          'args' => $object_args,
          'parent' => $parent,
          'baseUrl' => $this->baseUrl,
        );
        $available_object = new $available_type($vars);

        $object_is_valid = $available_object->isValid;
        if ($object_is_valid) {
          $pages[$available_type] = $available_object;
          $types = $types[$available_type];
          $arg_is_valid = TRUE;
          break;
        }
      }

      if (!$arg_is_valid) {
        $pages = array();
        break;
      }
    }

    $this->pages = $pages;
  }

  private function setResult() {
    $page = end($this->pages);

    if ($page) {
      $this->result = $page->getResult();
    }
  }

  public function parse() {
    $this->setPages();

    return $this;
  }

  public function execute() {
    $this->setResult();

    return $this;
  }

  public function getResult() {
    return $this->result;
  }
}
