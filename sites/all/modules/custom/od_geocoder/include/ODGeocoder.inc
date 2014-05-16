<?php
/**
 * ODGeocoder main controller
 */

/**
 * Class ODGeocoder
 */
class ODGeocoder {
  const COUNTRY_RUSSIA = 'RU';

  protected $country = NULL;

  /**
   * @var ODGeocoder\ServiceInterface
   */
  protected $service = NULL;

  public function setService($service_name) {
    // @todo: Refactory with autoload factory pattern here
    // @todo: Add new geocoders
    require_once dirname(__FILE__). '/ODGeocoder/Services/'. $service_name . '.inc';
    $class_path = "ODGeocoder\\Services\\{$service_name}";
    $this->service = new $class_path($this);

    return $this;
  }

  public function location($data) {
    $classname = get_class($this->service);
    if (method_exists($classname, 'createLocation')) {
      $location = call_user_func(array($classname, 'createLocation'));
    }
    else {
      $location = new \ODGeocoder\LocationDefault();
    }

    if (is_array($data)) {
      $location->initFromArray($data);
    }
    elseif (is_object($data)) {
      $location->initFromObject($data);
    }

    return $location;
  }

  public function setCountry($country) {
    $this->country = $country;
  }

  public function getCountry() {
    return $this->country;
  }

  /**
   * @param \ODGeocoder\LocationAbstract $location
   * @return \ODGeocoder\LocationAbstract
   */
  public function geocode(ODGeocoder\LocationAbstract $location) {
    return $this->service->geocode($location);
  }
}