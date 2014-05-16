<?php
/**
 * ODGeocoderServiceAbstract
 */
namespace ODGeocoder;
abstract class ServiceAbstract implements ServiceInterface {
  protected $geocoder = NULL;
  public function __construct(\ODGeocoder $geocoder) {
    $this->geocoder = $geocoder;

    $this->init();
  }

  /**
   * Some init functions
   */
  protected function init() {}
}