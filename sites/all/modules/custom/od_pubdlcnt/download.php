<?php
// $Id: 

/**
 * @file
 *
 * file download external script
 *
 * @ingroup pubdlcnt
 *
 * Usage:  pubdlcnt.php?file=http://server/path/file.ext
 *
 * Requirement: PHP5 - get_headers() function is used
 *              (The script works fine with PHP4 but better with PHP5)
 *
 * NOTE: we can not use variable_get() function from this external PHP program
 *	     since variable_get() depends on Drupal's internal global variable.
 *       So we need to directly access {variable} table of the Drupal databse 
 *       to obtain some module settings.
 *
 * Copyright 2009 Hideki Ito <hide@pixture.com> Pixture Inc.
 * Distributed under the GPL Licence.
 */

/**
 * Step-1: start Drupal's bootstrap to use drupal database
 *         and includes necessary drupal files
 */



if (isset($_GET['fid']) && isset($_GET['goto'])) {
  require_once dirname(__FILE__). '/include/controller.inc';
  $controller = new ODPubdlCntController(intval($_GET['fid']), $_GET['goto']);
  if (!$controller->isValid()) {
    $controller->badUrl();
  }

  $controller->handleRedirect();
  try {
    $controller->updateDownloadCounts();
  }
  catch (Exception $e) {
    //@todo: Log error, send email or something... And watchdog is great too.
  }

  $controller->endRequest();
}

$controller->badUrl();
$controller->endRequest();
?>
