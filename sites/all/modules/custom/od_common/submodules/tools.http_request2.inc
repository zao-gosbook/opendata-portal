<?php
/**
 * @file
 */
od_common_module('tools.pear');
require_once TOOLS_DIR. '/pear/HTTP/Request2.php';

/**
 * @return HTTP_Request2
 */
function od_common_tools_http_request2() {
  $http = new HTTP_Request2();
  $http->setConfig(array(
    'follow_redirects' => TRUE,
    'timeout' => 30,
    'adapter' => 'CurlAdvanced',
    'ssl_verify_peer' => FALSE,
    'max_redirects' => 5,
  ));

  $http->setHeader(array(
    'User-Agent' => 'Mozilla/5.0 (compatible; OpendataPortal/1.0b; Engine: PHP '. PHP_VERSION.'; Bot: yes; Timestamp:'. time(). ')',
    'Content-type' => 'text/html',
    'Accept' => 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
    'Accept-Charset' => 'windows-1251,utf-8;q=0.7,*;q=0.3',
    'Accept-Encoding' => 'gzip,deflate,sdch',
    'Accept-Language' => 'ru-RU,ru;q=0.8,en-US;q=0.6,en;q=0.4',
    'Referer' => "http://{$_SERVER['HTTP_HOST']}",
    //'User-agent' => 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.97 Safari/537.11',
  ));

  class_exists('HTTP_Request2_Adapter_CurlAdvanced'); // Call autoloader cause HTTP_Request2 won't do it.

  return $http;
}