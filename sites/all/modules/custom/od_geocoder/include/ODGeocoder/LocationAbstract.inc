<?php
/**
 * @file
 */
namespace ODGeocoder;
abstract class LocationAbstract implements LocationInterface {
  protected $original = array();
  public function initFromArray(array $data) {
    $this->original = (object) $data;
  }

  public function initFromObject($data) {
    $this->original = $data;
  }

  public function merge(LocationAbstract $location) {
    $this->original = (object) array_merge((array) $this->original, (array) $location->getOriginal());
  }

  public function getOriginal() {
    return $this->original;
  }
}