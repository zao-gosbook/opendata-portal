<?php
/*
 * @file
 */

/**
 *  Implements hook_form_FORM_ID_alter()
 *  Изменяем вывод внешнего фильтра в картах.
 */
function _od_common_map_views_form_views_exposed_form_alter(&$form, &$form_state) {
  if (isset($form['field_geolocation_distance']['googlemap'])) {
    unset($form['field_geolocation_distance']['googlemap']['address']['geocode']);
    $form['field_geolocation_distance']['googlemap']['help']['#markup']=t('Enter an address / location in the textfield');
    $form['field_geolocation_distance']['googlemap']['remove']['#markup'] = t('Clear');
  }
}