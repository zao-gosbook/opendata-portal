<?php
/**
 * @file
 */

function od_common_module_od_organization_page_render_selector() {
  $build = array();
  $name = __FUNCTION__; // Element's name value
  $build['select'] = form_process_select(array(
    '#type' => 'select',
    '#weight' => 0,
    '#title' => t('Search by'),
    '#options' => array(
      '0' => t('Organization name'),
      '1' => t('Organization short name'),
      '2' => t('TIN')
    ),
    '#default_value' => 0, //isset($_GET[$name]) ? $_GET[$name] : 0,
    //'#description' => t('Сhoose on what criteria to look for the organization.'),
   '#attributes' => array(
      'name' => $name,
      'class' => array(__FUNCTION__),
    ),
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'od_common') . '/js/od-organization-page.js',
      ),
    ),
  ));

  $build['#prefix'] = '<div class="od-organization-page-switcher-wrapper">';
  $build['#suffix'] = '</div>';
  return $build;
}