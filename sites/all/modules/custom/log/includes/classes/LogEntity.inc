<?php

/**
 * Log entity class.
 */
class LogEntity extends Entity {
  /**
   * Constructor.
   */
  public function __construct(array $values = array()) {
    $this->entityType = 'log';
    // Set initial values.
    foreach ($values as $key => $value) {
      $this->$key = $value;
    }
    $this->setUp();
  }

  /**
   * Set up the object instance on construction or unserializiation.
   */
  protected function setUp() {
    // Invoke parent method.
    parent::setUp();

    // Set default user ID.
    if (!isset($this->uid)) {
      global $user;
      if (!empty($user->uid)) {
        $this->uid = $user->uid;
      }
    }

    // Set default current time.
    if (!isset($this->created)) {
      $this->created = time();
    }
  }

  /**
   * Get log entity ID.
   */
  public function getLid() {
    return isset($this->lid) ? $this->lid : NULL;
  }

  /**
   * Get log entity user ID.
   */
  public function getUid() {
    return isset($this->uid) ? $this->uid : NULL;
  }

  /**
   * Get log entity timestamp.
   */
  public function getCreated() {
    return isset($this->created) ? $this->created : NULL;
  }

  /**
   * Get log entity message.
   */
  public function getMessage() {
    return isset($this->message) ? $this->message : '';
  }

  /**
   * Get log default label.
   */
  protected function defaultLabel() {
    $message = $this->getMessage();
    return $message ? 'Log — ' . $this->getMessage() : 'Log';
  }

  /**
   * Get log default uri.
   */
  protected function defaultUri() {
    $lid = $this->getLid();
    return $lid ? $uri = array('path' => 'log/' . $lid) : FALSE;
  }
}
