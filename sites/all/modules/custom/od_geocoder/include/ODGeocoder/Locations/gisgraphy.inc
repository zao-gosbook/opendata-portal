<?php
/**
 * @file
 */

namespace ODGeocoder\Locations;
use ODGeocoder\LocationAbstract;

/**
 * Class gisgraphy
 * @package ODGeocoder\Locations
 */
class gisgraphy extends LocationAbstract {
  public function getAddress() {
    return $this->original->address;
  }

  public function getLat() {
    return $this->original->lat;
  }

  public function getLong() {
    return $this->original->lng;
  }
}