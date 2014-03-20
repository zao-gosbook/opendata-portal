<?php

/**
 * @file
 * The facetapi_links and facetapi_checkbox_links widget plugin classes.
 */

/**
 * Widget that renders facets as a list of clickable links.
 *
 * Links make it easy for users to narrow down their search results by clicking
 * on them. The render arrays use theme_item_list() to generate the HTML markup.
 */
class FacetapiOdFacetsAjaxWidgetLinks extends FacetapiAjaxWidgetCheckboxes {
  public function init() {
    parent::init();

    // Add additional javascript.
    drupal_add_js(drupal_get_path('module', 'od_facets'). '/includes/js/widget_links.js');

    // Add default class for facet block.
    $this->build['#attributes']['class'][] = 'opendata-ajax-links-facet';
  }


  public function buildListItems($build) {
    $items = parent::buildListItems($build);

    foreach (array_values($build) as $index => $build_item) {
      if ($build_item['#active']) {
        $items[$index]['class'][] = 'facetapi-active';
      }
    }

    return $items;
  }
}
