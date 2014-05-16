<?php
/**
 * @file
 */
namespace ODGeocoder;
class LocationDefault extends LocationAbstract {
  public function getAddress() {
    throw new \Exception('Must be implemented in appropriate Location object');
  }

  public function getLat() {
    throw new \Exception('Must be implemented in appropriate Location object');
  }

  public function getLong() {
    throw new \Exception('Must be implemented in appropriate Location object');
  }
}