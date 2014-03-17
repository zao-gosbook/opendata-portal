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
    $searcher = 'search_api@' . $_GET['index_id'];
    $adapter = facetapi_adapter_load($searcher);

    return 'Test!';
  }
}