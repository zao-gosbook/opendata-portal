<?php

/**
 * @file
 * JQuery Loadinganimation admin/configuration functionality.
 */

/**
 * jquery_loadinganimation admin settings form.
 */
function jquery_loadinganimation_settings_form() {
  $module_path = drupal_get_path('module', 'jquery_loadinganimation');
  $img_src_default = $module_path . '/images/ajax-loader.gif';
  $form['jquery_loadinganimation_img_src'] = array(
    '#type' => 'textfield',
    '#title' => t('Loading animation spinner path'),
    '#description' => t(
        "The loading animation spinner path to use. Relative to base path. Default: \"%img_src_default\". !open_permanent_link to display the popup to preview the style. Exit with ESC.", array(
      '%img_src_default' => $img_src_default,
      '!open_permanent_link' => l('Click here', current_path(), array(
        'fragment' => 'top',
        'attributes' => array('onclick' => 'event.preventDefault(); Drupal.behaviors.jquery_loadinganimation.Loadinganimation.show();'))))),
    '#required' => TRUE,
    '#default_value' => variable_get('jquery_loadinganimation_img_src', $img_src_default));
  $form['jquery_loadinganimation_show_on_ajax'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show during AJAX requests'),
    '#description' => t(
        "Display the loading animation during AJAX requests too. Notice: Use with caution, may be disturbing."),
    '#default_value' => variable_get('jquery_loadinganimation_show_on_ajax', FALSE));
  $form['jquery_loadinganimation_show_on_form_submit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show after form submission'),
    '#description' => t("Display the loading animation on form submit. <em>Important:</em> Buttons with further JS events registered are excluded from this trigger."),
    '#default_value' => variable_get(
        'jquery_loadinganimation_show_on_form_submit', TRUE));
  $form['jquery_loadinganimation_show_on_href'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show on href click'),
    '#description' => t(
        "Display the loading animation after a link has been clicked."),
    '#default_value' => variable_get('jquery_loadinganimation_show_on_href', TRUE));
  $form['jquery_loadinganimation_subselector'] = array(
    '#type' => 'textfield',
    '#title' => t('JQuery subselector'),
    '#description' => t(
        "You may optionally use this subselector to reduce the DOM context which to register loading animation to."),
    '#required' => FALSE,
    '#default_value' => variable_get('jquery_loadinganimation_subselector', ''));
  // Exclude
  $form['jquery_loadinganimation_path_match_exclude'] = array(
    '#type' => 'textarea',
    '#title' => t('Exclude the following path(s)'),
    '#description' => t(
        "jQuery Loadinganimation will not be used for paths that match these patterns.") . ' ' . t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.") . ' ' . t("Default: 'admin/*'"),
    '#required' => TRUE,
    '#default_value' => variable_get('jquery_loadinganimation_path_match_exclude', 'admin/*'));
  $form['jquery_loadinganimation_close_on_click'] = array(
    '#type' => 'checkbox',
    '#title' => t('Close on layer click'),
    '#description' => t(
        "Close the layer if user clicks on it while loading process is still in progress."),
    '#default_value' => variable_get('jquery_loadinganimation_close_on_click', TRUE));
  $form['jquery_loadinganimation_close_on_esc'] = array(
    '#type' => 'checkbox',
    '#title' => t('Close on ESC press'),
    '#description' => t(
        "Close the layer if user presses ESC while loading process is still in progress."),
    '#default_value' => variable_get('jquery_loadinganimation_close_on_esc', TRUE));
  return system_settings_form($form);
}