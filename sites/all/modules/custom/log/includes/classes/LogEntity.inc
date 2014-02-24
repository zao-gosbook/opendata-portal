<?php

/**
 * Log entity class.
 */
class LogEntity extends Entity {
  /**
   * Constructor.
   */
  public function __construct(array $values = array(), $entityType = NULL) {
    if (empty($entityType)) {
      throw new Exception('Cannot create an instance of Entity without a specified entity type.');
    }
    $this->entityType = $entityType;
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
