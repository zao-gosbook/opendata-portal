<?php
/*
 * @file
 */

/**
 * Main singleton class does these functions:
 *  Collects all mail and saves them to database
 *  Gets mail from database
 */
class MailHistory {
  protected $mails = array();
  protected static $instance = NULL;
  protected $injected = FALSE;
  protected $hack_enabled = FALSE;

  protected $_stack = array();


  /**
   * @return MailHistory
   */
  public static function inst() {
    if (!isset(static::$instance)) {
      self::$instance = new static();
      $GLOBALS['mail_history']['object'] = self::$instance;
    }

    return self::$instance;
  }

  public static function groupUiid($message) {
    return substr(md5($message['to']), 0, 16);
  }

  public function addMail($message) {
    $message['uid'] = $GLOBALS['user']->uid;
    $message['timestamp'] = time();
    $recipients = explode(',', $message['to']);

    $group_key = 'default';
    if (is_array($recipients) && !empty($recipients)) {
      if (count($recipients) > 1) {
        $group_key = $this->groupUiid($message);
      }

      foreach ($recipients as $recipient_raw) {
        $recipient_clean = trim($recipient_raw, ' ');
        $this->mails[$group_key]['index'][] = array(
          'mail_to' => $recipient_clean,
          'group_uuid' => $group_key,
        );
      }
    }
    else {
      $this->mails[$group_key]['index'][] = array(
        'mail_to' => $message['to'],
        'group_uuid' => NULL,
      );
    }

    $this->mails[$group_key]['message'] = $message;
  }

  protected function saveAll() {
    if (!empty($this->mails)) {
      foreach ($this->mails as $group_key => $mail_info) {
        //Save in transaction
        $this->saveMail($mail_info, TRUE);
      }
    }
  }

  protected function __construct() {  }

  /**
   * Writes mail to database
   * @param $mail
   * @param null $transaction
   *    Can be DatabaseTransaction object, TRUE, or NULL. If TRUE - new transaction will be created
   * @return bool
   */
  public function saveMail($mail_info, $transaction = NULL) {
    $result = FALSE;
    $transaction_created = FALSE;
    try {
      $db_transaction = $transaction;
      if ($transaction === TRUE) {
        // Mark that transaction was created by this function and it will be destroyed when it ends.
        $transaction_created = TRUE;

        // Create new transaction.
        $db_transaction = db_transaction();
      }

      $mail = $mail_info['message'];
      $fields = array(
        'mid' => $mail['id'],
        //'group_uuid' => $mail['group_uuid'],
        'mail_key' => $mail['key'],
        'module' => $mail['module'],
        //'mail_to' => $mail['to'],
        'mail_from' => $mail['from'],
        'subject' => $mail['subject'],
        'body' => is_array($mail['body']) ? implode('\n', $mail['body']) : $mail['body'],
        'headers' => implode('\n', $mail['headers']),
        'params' => serialize($mail['params']),
        'language' => $mail['language']->language,
        'send' => (integer) $mail['send'],
        'timestamp' => $mail['timestamp'],
        'uid' => $mail['uid'],
        'result' => isset($mail['result']) ? $mail['result'] : MAIL_HISTORY_RESULT_UNKNOWN,
      );

      $insQuery = db_insert('mail_history');
      $insQuery
        ->fields(array_keys($fields));

      $insQuery
        ->values($fields);

      if (!($mhid = $insQuery->execute())) {
        throw new Exception('Error inserting a message');
      }


      $insQuery = NULL;
      $records_prepared = 0;
      $records_per_insert = 10;
      // Now insert index records.
      foreach ($mail_info['index'] as $index) {
        $fields = array(
          'mhid' => $mhid,
          'mail_to' => $index['mail_to'],
          'group_uuid' => $index['group_uuid'],
        );

        if ($insQuery === NULL) {
          $insQuery = db_insert('mail_history_index');
          $insQuery
            ->fields(array_keys($fields));
        }

        $insQuery->values($fields);

        // Prepare a bunch of records to insert
        if ($records_prepared++ >= $records_per_insert) {
          $insQuery->execute();
          $insQuery = NULL;
          $records_prepared = 0;
        }
      }

      if ($insQuery !== NULL) {
        $insQuery->execute();
      }

      if ($transaction_created) {
        //Immediately destroy transaction to
        unset($db_transaction);
      }

      // Say that it's all ok.
      $result = TRUE;
    }
    catch (Exception $e) {
      //Rollback the transaction in case of error
      if ($db_transaction instanceof DatabaseTransaction) {
        $db_transaction->rollback();
      }

      //Don't throw any exceptions just write to watchdog
      watchdog_exception('mail_history', $e);

      //Of course result is FALSE
      $result = FALSE;
    }

    return $result;
  }

  function enableHack() {
    //Check if hack was already enabled
    if ($this->hack_enabled) {
      return;
    }

    //Mark that hack is enabled
    $this->hack_enabled = TRUE;

    global $conf;

    //Create backup
    $this->stashSystems();
    //$conf['mail_system_dump'] = $conf['mail_system'];

    //Empty mail systems been to force the system think that we have only one mail system
    $conf['mail_system'] = array();
    $conf['mail_system']['default-system'] = 'MailHistorySaverMailSystem';
  }

  /**
   * Returns original mail system object to send email natively
   * @return mixed
   */
  function getOriginalMailSystem($message) {
    static $system = NULL;
    if (!isset($system)) {
      $this->disableHack();
      $classname = drupal_mail_system($message['module'], $message['key']);
      $this->enableHack();

      //Recursion protection. Fallback to default mail system in case of error
      if ($classname == 'MailHistorySaverMailSystem') {
        $classname = 'DefaultMailSystem';
      }

      $system = new $classname;
    }

    return $system;
  }

  /**
   * Restores original mail system
   */
  function disableHack() {
    //Если хак не был включен -- выходим
    if (!$this->hack_enabled) {
      return;
    }

    //Mark that hack is disabled
    $this->hack_enabled = FALSE;

    global $conf;

    if ($backup = $this->popSystems()) {
      $conf['mail_system'] = $backup;
    }
  }

  /**
   * @param array $options
   * @return array
   *
   * @todo Static cache
   */
  function listMail(array $options = array()) {
    $defaults = array(
      'offset' => NULL,
      'limit' => NULL,
    );


    $options = array_merge($defaults, $options);
    $query = db_select('mail_history', 'm');
    $query
      ->fields('m');

    //Apply filters
    if (!empty($options['filters'])) {
      foreach ($options['filters'] as $_property => $_info) {
        $_options = array();
        if (is_array($_info) && isset($_info['value'])) {
          $_options['operator'] = isset($_info['operator']) ? $_info['operator'] : '=';
          $_options['value'] = $_info['value'];
        }
        elseif (!is_array($_info) && isset($_info)) {
          $_options['operator'] = '=';
          $_options['value'] = $_info;
        }

        if (array_key_exists('value', $_options) && isset($_options['operator'])) {
          $query
            ->condition($_property, $_options['value']);
        }
      }
    }

    //Apply order by
    if (!empty($options['order by'])) {
      foreach ($options['order by'] as $_rule) {
        if (!is_array($_rule)) {
          $_rule = explode(' ', $_rule) + array('mhid', 'ASC');
        }

        $query
          ->orderBy($_rule[0], $_rule[1]);
      }
    }

    //Set ranges
    $query
      ->range($options['offset'], $options['limit']);

    $rows = $query->execute();

    $mails = array();
    if ($rows) {
      foreach ($rows as $row) {
        $mails[] = $row;
      }
    }

    return $mails;
  }

  function stashSystems() {
    $this->_stack['mail_systems'] = variable_get('mail_system', array('default-system' => 'DefaultMailSystem'));
  }

  function popSystems() {
    if (isset($this->_stack['mail_systems'])) {
      $ret = $this->_stack['mail_systems'];
      $this->_stack['mail_systems'] = NULL;

      return $ret;
    }

    return FALSE;
  }


  function __destruct() {
    $this->disableHack();
    $this->saveAll();
  }
}