<?php

/**
 * Log entity class.
 */
class LogEntity extends Entity {
  /**
   * Set up the object instance on construction or unserializiation.
   */
  protected function setUp() {
    // Invoke parent method.
    parent::setUp();

    // Set default user ID.
    if (empty($this->uid)) {
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
   * Get log entry user ID.
   */
  public function getUid() {
    return isset($this->uid) ? $this->uid : NULL;
  }

  /**
   * Get log entry timestamp.
   */
  public function getCreated() {
    return isset($this->created) ? $this->created : NULL;
  }

  /**
   * Get log entry message.
   */
  public function getMessage() {
    return isset($this->message) ? $this->message : '';
  }
}
