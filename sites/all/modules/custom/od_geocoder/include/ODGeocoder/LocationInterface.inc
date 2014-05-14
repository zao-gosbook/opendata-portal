<?php
/**
 * @file
 */
namespace ODGeocoder;
interface LocationInterface {
  public function getAddress();
  public function getLat();
  public function getLong();
  public function initFromArray(array $data);
  public function initFromObject($data);
  public function merge(LocationAbstract $location);
  public function getOriginal();
}