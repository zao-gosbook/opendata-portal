<?php
/**
 * Service that uses online http://services.gisgraphy.com/
 */
namespace ODGeocoder\Services;

use ODGeocoder\LocationAbstract;
use ODGeocoder\Locations\gisgraphy;
use ODGeocoder\ServiceAbstract;
class gisgraphy_online extends ServiceAbstract {
  protected $urls = array(
    ''
  );

  /**
   * @var \HTTP_Request2
   */
  protected $http = NULL;

  public function geocode(LocationAbstract $location) {
    $address = urlencode($location->getAddress());
    $url = "http://dev.opendatagov.ru:8082/geocoding/geocode?postal=true&format=json&address={$address}&country={$this->geocoder->getCountry()}";

    $this->http->setUrl($url);
    $this->http->setMethod(\HTTP_Request2::METHOD_GET);

    if (($message = $this->http->send()) && ($message->getStatus() == 200)) {
      $result = json_decode($message->getBody());

      $location->merge($this->geocoder->location(reset($result->result)));
    }

    return $location;
  }

  function init() {
    od_common_module('tools.http_request2');
    $this->http = od_common_tools_http_request2();
  }

  public static function createLocation() {
    require_once OD_GEOCODER_ROOT. '/include/ODGeocoder/Locations/gisgraphy.inc'; // @todo: Autoload
    return new \ODGeocoder\Locations\gisgraphy();
  }
}