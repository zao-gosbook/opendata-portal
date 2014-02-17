<?php
/**
 * @file
 */

interface StreamWrappersModInterface extends DrupalStreamWrapperInterface {
  /**
   * Overrides getTarget()
   * @inheritdoc
   */
  public function getTarget($uri = NULL);
}

abstract class StreamWrapperModAbstract extends DrupalPublicStreamWrapper implements StreamWrappersModInterface {
  protected static $_context = array();

  public function getTarget($uri = NULL) {
    return parent::getTarget($uri);
  }

  /**
   * Calls any protected method from anywhere.
   * @param $name
   *   A name of a protected method to call.
   * @param ...
   *   Any other arguments.
   *
   * @return mixed
   *
   * @fixme: Fix PHPDoc and use virtual params.
   */
  function _callProtected() {
    $args = func_get_args();
    $name = array_shift($args);

    return call_user_func_array(array($this, $name), $args);
  }

  /**
   * Manipulates with $this->context property.
   *   Used to store any context information.
   * @param null $param
   * @param null $value
   * @param null $remove
   */
  public static function &context($param = NULL, $value = NULL, $remove = FALSE) {
    $context_rw = &static::$_context;
    $context = NULL;
    if ($remove) {
      $context = static::$_context;
      if ($param !== NULL && isset($context_rw[$param])) {
        unset($context_rw[$param]);
      }
      elseif ($param == NULL) {
        $context_rw = array();
      }
    }
    else {
      $context = &$context_rw;
    }

    $retval = NULL;
    if ($param !== NULL) {
      // Getter
      $retval = &$context[$param];

      // Setter
      if ($value !== NULL) {
        $context_rw[$param] = $value;
        $context[$param] = $value;
      }
    }
    elseif ($param === NULL) {
      $retval = &$context;
    }

    return $retval;
  }
}


class StreamWrappersMod_DrupalPublicStreamWrapper extends StreamWrapperModAbstract {
  function getExternalUrl() {
    $sandbox = array(
      'altered_by' => array(),
      'result' => parent::getExternalUrl(),
    );

    drupal_alter('stream_wrappers_mod_get_external_url', $sandbox, $this);

    return $sandbox['result'];
  }
}