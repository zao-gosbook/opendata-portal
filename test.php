<?php

/**
 * @file
 * The PHP page that serves all page requests on a Drupal installation.
 *
 * The routines here dispatch control to the appropriate handler, which then
 * prints the appropriate page.
 *
 * All Drupal code is released under the GNU General Public License.
 * See COPYRIGHT.txt and LICENSE.txt.
 */

/**
 * Root directory of Drupal installation.
 */
define('DRUPAL_ROOT', getcwd());

require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

libraries_load('od_api');

$list = array(
  'list' => 'http://www.nalog.ru/',
);

$od = new OdApi();
$meta_result = $od->getResult($list);


kpr($od);
kpr($meta_result);

die;


$obj = new stdClass();
test_ololo($obj);

die;

function test_ololo(stdClass $obj = NULL) {
  var_export($obj);
}

die;
$file = file_load(474);
kpr(array($file));
file_delete($file, TRUE);
$file = file_load(474);
kpr(array($file));

die;

$url = 'public://opendata/7701350013-licensestpci/data-2013-06-04t00-00-00-structure-2013-06-04t00-00-00.csv';
$origin_uri = 'http://fstec.ru/opendata/7701350013-licensestpci/data-2014-01-14T00-00-structure-2013-06-04T00-00.csv';


$file = od_import_load_or_create_file($url, $origin_uri);
kpr(array($file));

die;

$url = 'public://opendata/7701350013-licensestpci/data-2013-06-04t00-00-00-structure-2013-06-04t00-00-00.csv';
var_export(od_import_detect_delimiter($url));

die;

$identifier = '7701350013-licensestpci';

$dataset_node = od_import_load_dataset($identifier);
kpr(array($dataset_node));

die;

die;

$file = file_save_data('test_pish', 'public://test.png');
kpr($file);

die;

// $link = 'http://opendata71.ru/opendata/7107030748-IncometaxandnontaxrevenuesoftheconsolidatedbudgetoftheTularegionin2008to2013/data-2014-02-10T18-02-structure-2014-02-10T18-02.csv';
$link = 'http://kalistos.opendatagov.ru/sites/default/files/149-528da2750057a.csv';
$test = od_import_exec_url($link);
kpr($test);

die;
