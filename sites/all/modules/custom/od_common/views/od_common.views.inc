<?php
// $Id$

/**
 * @file better_exposed_filters.views.inc
 *
 * Adds Views3 support
 *
 * Views3 adds the concept of exposed forms to the mix.  In addition, elements injected into a Views
 * dialog is no longer saved along with the Views form information (see the unpack_options() and
 * options_definition() methods of the views_object object).
 *
 */

/**
 * Implements hook_views_plugins().
 */
function od_common_views_plugins() {
  return array(
    'exposed_form' => array(
      'google_maps_better_exposed_filters' => array(
        'title' => t('Better Exposed Filters for Google Maps'),
        'help' => t('Allow use of checkboxes/radio buttons for exposed filters'),
        'handler' => 'od_common_better_exposed_filters_exposed_form_plugin',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'help topic' => 'exposed-form-basic',
        'type' => 'normal',
        'parent' => 'basic',
      ),
    ),
  );
}
