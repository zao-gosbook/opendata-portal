<?php
/**
 * @file
 */

/**
 * Implements hook_entity_info().
 */
function od_pubdlcnt_entity_info() {
  $return = array(
    'od_pubdlcnt' => array(
      'label' => t('Download count object'),
      'controller class' => 'ODPubdlcntEntityController',
      'base table' => OD_PUBDLCNT_TABLE,
      'fieldable' => TRUE,
      'entity keys' => array(
        'id' => 'id',
      ),
      'bundles' => array(),
      'module' => 'od_pubdlcnt',
    ),
  );

  return $return;
}

function od_pubdlcnt_entity_property_info_alter(&$info) {

}
