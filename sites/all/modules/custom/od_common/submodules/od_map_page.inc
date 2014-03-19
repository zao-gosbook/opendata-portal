<?php
/**
 * @file
 */

function od_common_module_od_map_page_render_selector() {
  $build = array();

  $build['radios'] = form_process_radios(array(
    '#type' => 'radios',
    '#weight' => 0,
    '#title' => t('Search by'),
    '#options' => array(
      '0' => t('Organization name'),
      '1' => t('Location'),
    ),
    '#default_value' => 0,
    '#description' => t('Set this to <em>Yes</em> if you would like this category to be selected by default.'),
    '#attributes' => array(
      'name' => __FUNCTION__,
      'class' => array(__FUNCTION__),
    ),
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'od_common') . '/js/od-map-page.js',
      ),
    )
  ));

  $build['#prefix'] = '<div class="od-map-page-switcher-wrapper">';
  $build['#suffix'] = '</div>';
  return $build;
}