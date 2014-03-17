<?php
/**
 * @file
 */

class od_dataset_views_handler_area_facets_info extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }
  /**
   * Options form that provides the label widget that all fields
   * should have.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Render the area
   */
  function render($empty = FALSE) {
    $searcher = 'search_api@' . 'datasets';
    $adapter = facetapi_adapter_load($searcher);

    if (!$adapter) {
      return '';
    }

    $fake_plugin_info = array(
      'id' => 'od_facets_term_view_tag',
      'handler' => array(
        'label' => 'Fake plugin',
        'class' => 'ODFacetsTermViewTag',
        'query types' => array(
          'term',
        ),
      ),
      'module' => 'od_dataset',
      'name' => 'od_facets_term_view_tag',
      'path' => drupal_get_path('module', 'od_dataset'),
      'file' => NULL,
      'plugin module' => 'facetapi',
      'plugin type' => 'widget',
    );

    //$plugins = &drupal_static('ctools_plugins', array());
    $plugins['facetapi']['widgets']['od_facets_term_view_tag'] = $fake_plugin_info;


    //$adapter->settings

    $adapter->setViewMode(TRUE);
    $adapter->addViewHack('field_resources:field_format', 'sss');
    //$blocks = ajax_facets_process_facet_blocks($searcher);
    $adapter->setViewMode(FALSE);

    return '';
  }
}