<?php

class ODPubdlCntController {
  const EXPIRE_ETAGS = 1; //Etag cache
  const EXPIRE_SID = 2; //Site id cache
  const EXPIRE_POSITION = 3; //Position cache
  const EXPIRE_VISITOR = 4; //Visits cache

  protected $_history_table = 'od_pubdlcnt_history';
  protected $_counter_table = 'od_pubdlcnt';
  protected $_urls_table = 'od_pubdlcnt_url';

  protected $fid = NULL;
  protected $url = NULL;
  protected $dbh = NULL;
  public $cache; //CacheController
  protected $rebuild = FALSE;
  protected $group = NULL;

  /**
   * Get expire time for cache type
   * @param null $key
   * @return int
   */
  function getExpire($key = NULL) {
    static $expire_default = NULL;
    static $expires = NULL;

    if ($expire_default === NULL) {
      $expire_default = strtotime('now + 2 hours');
      $expires = array(
        static::EXPIRE_ETAGS => $expire_default, //@todo add others
      );
    }

    return isset($expires[$key]) ? $expires[$key] : $expire_default;
  }


  function __construct($fid, $url) {
    $this->fid = $fid;
    $this->url = $url;
  }

//  public static function initCache($sid = 0) {
//    require_once dirname(__FILE__) . '/CacheController.inc';
//
//    $salt = __FILE__. (isset($_GET['oldsid']) ? $_GET['oldsid'] : '');
//    return CacheController::create('memcache', $_SERVER['HTTP_HOST'] . $salt. $sid, $salt. ':WidgetController'); //fixme: Set other salt
//  }

  function fid() {
    return $this->fid;
  }

  function url() {
    return $this->url;
  }

  public static function flushCaches() {
    $cache = static::initCache();
    $cache->flushGroup();
  }

  function includeHelpers() {
    static $helpers = NULL;
    if ($helpers === NULL) {
      require_once dirname(__FILE__) . '/drupal_helpers/DrupalHelpers.php';
    }

    return TRUE;
  }


  function db() {
    if (!$this->dbh) {
      $helpers = $this->includeHelpers();
      $dbInfo =  \DrupalHelpersNS\DrupalHelpers::getDBInfo();

      $db = $dbInfo['default']['default'];
      $this->dbh = new PDO("mysql:host={$db['host']};dbname={$db['database']}", $db['username'], $db['password']);
      $this->dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    }

    return $this->dbh;
  }

//  function includeSharedCode() {
//    static $included = FALSE;
//    if ($included === FALSE) {
//      require_once dirname(__FILE__). '/shared_code.widget.inc';
//    }
//
//    return TRUE;
//  }

  function createUrl() {
    static $created  = FALSE;
    if (!$created) {
      $created = TRUE;

      // Url fields from parse_url with default values
      $url_fields = array(
        'scheme' => NULL,
        'port' => '80',
        'host' => NULL,
        'path' => NULL,
        'query' => NULL,
        'fragment' => NULL,
      );

      $values = array(
        ':url_key' => $this->urlKey(),
      );

      $fields = array(
        ':url_key' => '`url_key`',
      );

      if ($parsed = parse_url($this->url())) {
        foreach ($url_fields as $field => $default_value) {
          $escaped = '`' . $field . '`';
          $placeholder = ':'. $field;
          $values[$placeholder] = isset($parsed[$field]) ? $parsed[$field] : $default_value;
          $fields[$field] = $escaped;
        }
      }

      $sql = "INSERT IGNORE INTO `{$this->_urls_table}` \n(". implode(', ', $fields). ") \n VALUES \n (" . implode(', ', array_keys($values)) . ")";
      $this->db()->prepare($sql)->execute($values);
    }

    return $this->urlKey();
  }

  function urlKey() {
    static $key = NULL;
    if ($key === NULL) {
      $key = substr(md5($this->url()), 0, 16);
    }

    return $key;
  }

  function addHistoryRecord() {
    $dbh = $this->db();

    $sql = "
    INSERT INTO
      `{$this->_history_table}`
    (
      `fid`,
      `utime`,
      `url_key`
    )
    VALUES (
      :fid,
      :utime,
      :url_key
    )
    ";

    $st = $dbh->prepare($sql);
    $st->bindValue(':fid', $this->fid, PDO::PARAM_INT);
    $st->bindValue(':utime', time(), PDO::PARAM_INT);
    $st->bindValue(':url_key', $this->createUrl());

    return $st->execute();
  }

  function updateDownloadCounts() {
    $this->addHistoryRecord();
    $dbh = $this->db();

    $sql = "
    INSERT INTO
      `{$this->_counter_table}`
    (
      `fid`,
      `nid`,
      `utime`,
      `count`
    )
    VALUES (
      :fid,
      :nid,
      :utime,
      1
    )
    ON DUPLICATE KEY UPDATE
      `nid`=:nid, `utime`=:utime, `count`=`count`+1
    ";

    $st = $dbh->prepare($sql);
    $st->bindValue(':fid', $this->fid(), PDO::PARAM_INT);
    $st->bindValue(':nid', NULL, PDO::PARAM_INT);
    $st->bindValue(':url', $_GET['goto'], PDO::PARAM_STR);
    $st->bindValue(':utime', time(), PDO::PARAM_INT);

    return $st->execute();
  }

  function getDrupalRoot() {
    $helpers = $this->includeHelpers();

    return \DrupalHelpersNS\DrupalHelpers::findDrupalRoot();
  }

  function badUrl() {
    header("HTTP/1.0 503 Forbidden");
    header("HTTP/1.1 503 Forbidden");
    header("Status: 503 Forbidden");
  }

  function isValid() {
    return TRUE; //@fixme: Implement this
  }

  function handleRedirect() {
    if ($this->url()) {
      header('Location: '. $this->url());
    }
    else {
      $this->badUrl();
      $this->endRequest();
    }
  }

  function endRequest() {
    exit;
  }
}
