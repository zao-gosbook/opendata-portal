<?php

/**
 * @file
 * Contains the OdApiRDFParser class.
 */

class OdApiRDFaParser extends OdApiParser {
  public $subjects;

  protected function parseUrl($url) {
    $subjects = array();

    $data = OdApiHelper::getUrlData($url);
    // Fix DOMDocument loadHTML encoding bug.
    $data = preg_replace('/<meta\s+charset="([\w-]+)"/', '/<meta http-equiv="Content-Type" content="text/html; charset=$1"/', $data, 1);
    if (strpos($data, '<meta http-equiv="Content-Type" content="text/html; charset=') === FALSE) {
      if (strpos($data, '<head>') !== FALSE) {
        $data = preg_replace('/<head>/', '/<head>' . "\n" . '<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />', $data, 1);
      }
      else {
        $data = '';
      }
    }
    $parser = new EasyRdf_Graph($url, $data);

    $resources = $parser->resources();
    foreach ($resources as $resource) {
      $uri = $resource->getUri();
      $property_names = $resource->properties();

      foreach ($property_names as $property_name) {
        $property_values = $resource->all($property_name);
        $full_property_name = EasyRdf_Namespace::expand($property_name);

        $resource_subjects = array();
        foreach ($property_values as $property) {
          switch (get_class($property)) {
            case 'EasyRdf_Literal':
              $resource_subjects[] = $property->getValue();
              break;
            case 'EasyRdf_Resource':
              $resource_subjects[] = $property->getUri();
              break;
          }
        }

        if (isset($resource_subjects)) {
          if (!isset($subjects[$uri])) {
            $subjects[$uri] = array();
          }

          $subjects[$uri][$full_property_name] = $resource_subjects;
        }
      }
    }

    foreach ($subjects as $link => $subject) {
      if (substr($link, -1) !== '/') {
        continue;
      }

      $correct_link = substr($link, 0, -1);

      if (isset($subjects[$correct_link])) {
        $subjects[$correct_link] = array_merge($subjects[$correct_link], $subjects[$link]);
      }
      else {
        $subjects[$correct_link] = $subjects[$link];
      }

      unset($subjects[$link]);
    }

    return $subjects;
  }

  public function parse($url, $actual_url = NULL) {
    $url = rtrim($url, '/');
    $parsing_url = !empty($actual_url) ? $actual_url : $url;
    $parsing_url = OdApiHelper::formatUrl($parsing_url, PHP_URL_QUERY);

    if (isset($this->results[$parsing_url])) {
      return $this->results[$parsing_url];
    }

    $this->results[$parsing_url] = array();
    $error = &$this->results[$parsing_url]['error'];
    $subjects = &$this->results[$parsing_url]['subjects'];
    $result = &$this->results[$parsing_url]['result'];

    $subjects = $this->parseUrl($parsing_url);

    // Detect empty result.
    if (!$subjects) {
      $error = 'rdfaNotDetected';
      return $this->results[$parsing_url];
    }

    if (!empty($actual_url)) {
      $actual_url = rtrim($actual_url, '/');
      $subjects[$url] = isset($subjects[$url]) ? array_merge($subjects[$url], $subjects[$actual_url]) : $subjects[$actual_url];
      unset($subjects[$actual_url]);
    }

    $result = isset($subjects[$url]) ? $subjects[$url] : array();
    return $this->results[$parsing_url];
  }
}
