<?php

class ODPubdlCntController {
  const EXPIRE_ETAGS = 1; //Etag cache
  const EXPIRE_SID = 2; //Site id cache
  const EXPIRE_POSITION = 3; //Position cache
  const EXPIRE_VISITOR = 4; //Visits cache

  protected $fid = NULL;
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


  function __construct($fid) {
    $this->fid = $fid;
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

  function updateDownloadCounts() {
    $dbh = $this->db();
    $key = $this->getUniqueKey();
    $cache_cid = 'widget:visitors:'. $key;

    $visitors = $this->cache->get($cache_cid, $this->getExpire(static::EXPIRE_VISITOR), $this->needsRebuild());
    $log[] = 'Counting started. Key is '. $key;
    if (!isset($visitors->data)) {
      $visit = $this->getVisit();

      if (!$visit) {
        $log[] = 'This user hasn\'t visited us yet';
        //print $key;
        $extra = array(
          'server' => $_SERVER,
          'key_raw' => $this->getUniqueKey(FALSE),
        );

        $sql = '
      	INSERT INTO
      		rating_visits
      	(
      		ukey,
      		sid,
      		ip,
      		visit_date,
      		expire_time,
      		extra,
      		valid
      	)
      	VALUES
      	(
      		:ukey,
      		:sid,
      		:ip,
      		:visit_date,
      		:expire_time,
      		:extra,
      		:valid
      	)
      ';

        $query = $dbh->prepare($sql);
        $query->bindValue(':ukey', $key, PDO::PARAM_STR);
        $query->bindValue(':sid', $this->sid, PDO::PARAM_INT);
        $query->bindValue(':ip', NULL, PDO::PARAM_STR);
        $query->bindValue(':visit_date', date('c', time()), PDO::PARAM_STR);
        $query->bindValue(':expire_time', strtotime('tomorrow') - time(), PDO::PARAM_STR);
        $query->bindValue(':extra', NULL, PDO::PARAM_STR);
        $query->bindValue(':valid', 1, PDO::PARAM_INT);

        if ($query->execute()) {
          $log[] = 'Visitor info added to the database';
        }
        else {
          $log[] = 'Error: Visitor info added to the database.';
          $log['pdo_errors'][] = $query->errorInfo();
        }
      }
      else {
        $log[] = 'This user is familiar already';
      }

      $visitors->data = TRUE;
      $this->cache->save($visitors);
    }
    else {
      $log[] = 'I wont count cause it already counted';
    }
  }

  function getDrupalRoot() {
    $helpers = $this->includeHelpers();

    return \DrupalHelpersNS\DrupalHelpers::findDrupalRoot();
  }

  function badUrl() {
    header("HTTP/1.0 503 Forbidden");
    header("HTTP/1.1 503 Forbidden");
    header("Status: 503 Forbidden");

    exit;
  }

  function isValid() {
    return TRUE; //@fixme: Implement this
  }

  function handleRedirect() {
    if (isset($_GET['goto'])) {
      header('Location: '. $_GET['goto']);
    }
    else {
      $this->badUrl();
    }
  }
}
