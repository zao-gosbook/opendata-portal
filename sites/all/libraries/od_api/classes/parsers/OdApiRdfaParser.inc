<?php

/**
 * @file
 * Contains the OdApiRDFParser class.
 */

class OdApiRDFaParser extends OdApiParser {
  public $subjects;

  protected function parseUrl($url) {
    $subjects = array();

    $parser = new EasyRdf_Graph($url);
    try {
      $parser->load($url);
    } catch (Exception $exception) {
      try {
        $parser->load($url . '/');
      }
      catch (Exception $exception) {
        return $subjects;
      }
    }
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
    $this->url = $url;
    // Using "@" for ignoring ARC2 library errors.

    $parsing_url = !empty($actual_url) ? $actual_url : $this->url;

    $subjects = $this->parseUrl($parsing_url);

    if (!empty($actual_url)) {
      $actual_url = rtrim($actual_url, '/');
      $subjects[$this->url] = isset($subjects[$this->url]) ? array_merge($subjects[$this->url], $subjects[$actual_url]) : $subjects[$actual_url];
      unset($subjects[$actual_url]);
    }

    $this->subjects = $subjects;

    $this->result = isset($this->subjects[$this->url]) ? $this->subjects[$this->url] : array();
    return $this;
  }
}
