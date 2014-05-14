<?php
/**
 * ODGeocoderServiceInterface
 */
namespace ODGeocoder;
interface ServiceInterface {
  //@todo: Need description
  public function geocode(LocationAbstract $location);
}