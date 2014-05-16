<?php
/**
 * Service that uses online http://services.gisgraphy.com/
 */
namespace ODGeocoder\Services;

use ODGeocoder\LocationAbstract;
use ODGeocoder\Locations\gisgraphy;
use ODGeocoder\ServiceAbstract;
class gisgraphy_dummy extends ServiceAbstract {
  public function geocode(LocationAbstract $location) {
    $location->merge($this->geocoder->location(array('lat' => 65, 'lng' => 86)));
    return $location;
  }

  public static function createLocation() {
    require_once OD_GEOCODER_ROOT. '/include/ODGeocoder/Locations/gisgraphy.inc'; // @todo: Autoload
    return new \ODGeocoder\Locations\gisgraphy();
  }
}