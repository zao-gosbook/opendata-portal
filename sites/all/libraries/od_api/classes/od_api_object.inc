<?php

/**
 * @file
 * Contains the OdApiObject class.
 */

abstract class OdApiObject {
  public $args;
  public $parent;
  public $baseUrl;
  public $parentClass;
  public $api;
  public $url;
  public $subject;
  public $subjects;

  private $localNamespaces;

  public $isValid = TRUE;

  abstract public function setUrl();
  abstract public function validate();
  abstract public function getResult();

  public function __construct($vars) {
    if ($this->parentClass) {
      if ($vars['parent'] && is_object($vars['parent']) && get_class($vars['parent']) == $this->parentClass) {
        $this->parent = $vars['parent'];
      }
      else {
        $this->isValid = FALSE;
        return;
      }
    }

    $this->args = $vars['args'];
    $this->api = implode('/', $this->args);
    $this->setLocalNamespaces();

    $this->setUrl();

    if (!$this->url) {
      $this->isValid = FALSE;
      return;
    }

    if (!$this->validate()) {
      $this->isValid = FALSE;
      return;
    }

    $this->baseUrl = $vars['baseUrl'];

    $this->parse();
  }

  public function parse() {
    $parser = new OdApiRDFParser();
    $parser->parse($this->url);

    $this->subjects = $parser->getSubjects();
    $this->subject = $this->subjects[$this->url];
  }

  private function setLocalNamespaces() {
    $local_namespaces = array(
      'rdf:' => 'http://www.w3.org/1999/02/22-rdf-syntax-ns#',
      'dc:' => 'http://purl.org/dc/terms/',
      'foaf:' => 'http://xmlns.com/foaf/0.1/',
    );

    $this->localNamespaces = $local_namespaces;
  }

  public function localNamespaceWrap($var) {
    return strtr($var, array_flip($this->localNamespaces));
  }

  public function localNamespaceUnwrap($var) {
    return strtr($var, $this->localNamespaces);
  }
}
