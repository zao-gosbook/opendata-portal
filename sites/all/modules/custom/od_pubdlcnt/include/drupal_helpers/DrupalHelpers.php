<?php

namespace DrupalHelpersNS;

class DrupalHelpers {
  protected static $options = array();
  protected static $settingsIncluded = FALSE;

  public static function setOptions(array $options) {
    static::$options = $options;
  }

  public static function findDrupalRoot() {
    $cwd = NULL;
    if (!isset(static::$options['start_dir'])) {
      //Get current directory
      $cwd = dirname(__FILE__);
    }
    else {
      $cwd = static::$options['start_dir'];
    }

    /* Now we must find where the drupal root directory is*/
    $find = FALSE;
    $max_hops = 50;
    $temp_cwd = $cwd;
    $hop = 0;
    $drupal_root = NULL;

    //Do it by recursively searching back to one directory and check if index.php exists
    do {
      $fpath = "{$temp_cwd}/index.php";
      $find = file_exists($fpath);

      if ($find && strpos(file_get_contents($fpath), 'DRUPAL_ROOT') == FALSE) {
        $find = FALSE;
      }

      $drupal_root = $temp_cwd;
      $temp_cwd = dirname($temp_cwd);
    }
    while (!$find && $drupal_root!=$temp_cwd && $hop++<$max_hops);

    if (!$find) {
      die("Could not find index.php");
    }

    chdir($drupal_root);
    $drupal_root_absolute = getcwd();

    //Return back
    chdir($cwd);

    return $drupal_root_absolute;
  }

  public static function includeSettings() {
    global $databases, $cookie_domain, $conf, $base_url, $drupal_hash_salt;
    $drupal_root = static::findDrupalRoot();
    $settings_path = static::confPath();

    require_once $drupal_root.DIRECTORY_SEPARATOR.$settings_path.'/settings.php';

    static::$settingsIncluded = true;
  }
  public static function getDBInfo() {
    static::includeSettings();
    global $databases;

    return $databases;
  }

  public static function getDrupalSessionName() {
    static::includeSettings();
    global $cookie_domain, $base_url;

    $is_https = isset($_SERVER['HTTPS']) && strtolower($_SERVER['HTTPS']) == 'on';
    if (isset($base_url)) {
      // Parse fixed base URL from settings.php.
      $parts = parse_url($base_url);
      if (!isset($parts['path'])) {
        $parts['path'] = '';
      }
      $base_path = $parts['path'] . '/';
      // Build $base_root (everything until first slash after "scheme://").
      $base_root = substr($base_url, 0, strlen($base_url) - strlen($parts['path']));
    }
    else {
      // Create base URL.
      $http_protocol = $is_https ? 'https' : 'http';
      $base_root = $http_protocol . '://' . $_SERVER['HTTP_HOST'];

      $base_url = $base_root;

      // $_SERVER['SCRIPT_NAME'] can, in contrast to $_SERVER['PHP_SELF'], not
      // be modified by a visitor.
      /*if ($dir = rtrim(dirname($_SERVER['SCRIPT_NAME']), '\/')) {
        $base_path = $dir;
        $base_url .= $base_path;
      }*/
    }

    if (isset($cookie_domain)) {
      // If the user specifies the cookie domain, also use it for session name.
      $session_name = $cookie_domain;
    }
    else {
      // Otherwise use $base_url as session name, without the protocol
      // to use the same session identifiers across HTTP and HTTPS.
      list( , $session_name) = explode('://', $base_url, 2);
      // HTTP_HOST can be modified by a visitor, but we already sanitized it
      // in drupal_settings_initialize().
      if (!empty($_SERVER['HTTP_HOST'])) {
        $cookie_domain = $_SERVER['HTTP_HOST'];
        // Strip leading periods, www., and port numbers from cookie domain.
        $cookie_domain = ltrim($cookie_domain, '.');
        if (strpos($cookie_domain, 'www.') === 0) {
          $cookie_domain = substr($cookie_domain, 4);
        }
        $cookie_domain = explode(':', $cookie_domain);
        $cookie_domain = '.' . $cookie_domain[0];
      }
    }

    // To prevent session cookies from being hijacked, a user can configure the
    // SSL version of their website to only transfer session cookies via SSL by
    // using PHP's session.cookie_secure setting. The browser will then use two
    // separate session cookies for the HTTPS and HTTP versions of the site. So we
    // must use different session identifiers for HTTPS and HTTP to prevent a
    // cookie collision.
//    if ($is_https) {
//      ini_set('session.cookie_secure', TRUE);
//    }
    $prefix = ini_get('session.cookie_secure') ? 'SSESS' : 'SESS';
    $session_name = $prefix . substr(hash('sha256', $session_name), 0, 32);

//    if (isset($_COOKIE[$session_name])) {
//      return $_COOKIE[$session_name];
//    }

    return $session_name;
  }

  public static function confPath($require_settings = TRUE, $reset = FALSE) {
    static $conf = array();

    $drupal_root = static::findDrupalRoot();
    if ($conf && !$reset) {
      return $conf;
    }

    $confdir = 'sites';

    $sites = array();
    if (file_exists($drupal_root . '/' . $confdir . '/sites.php')) {
      // This will overwrite $sites with the desired mappings.
      include($drupal_root . '/' . $confdir . '/sites.php');
    }

    $uri = explode('/', $_SERVER['SCRIPT_NAME'] ? $_SERVER['SCRIPT_NAME'] : $_SERVER['SCRIPT_FILENAME']);
    $server = explode('.', implode('.', array_reverse(explode(':', rtrim($_SERVER['HTTP_HOST'], '.')))));
    for ($i = count($uri) - 1; $i > 0; $i--) {
      for ($j = count($server); $j > 0; $j--) {
        $dir = implode('.', array_slice($server, -$j)) . implode('.', array_slice($uri, 0, $i));
        if (isset($sites[$dir]) && file_exists($drupal_root . '/' . $confdir . '/' . $sites[$dir])) {
          $dir = $sites[$dir];
        }
        if (file_exists($drupal_root . '/' . $confdir . '/' . $dir . '/settings.php') || (!$require_settings && file_exists($drupal_root . '/' . $confdir . '/' . $dir))) {
          $conf = "$confdir/$dir";
          return $conf;
        }
      }
    }
    $conf = "$confdir/default";
    return $conf;
  }
}
