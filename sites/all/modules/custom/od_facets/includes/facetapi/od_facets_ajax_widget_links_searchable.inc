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
class FacetapiOdFacetsAjaxWidgetLinksSearchable extends FacetapiOdFacetsAjaxWidgetLinks {
  /**
   * Overrides FacetapiOdFacetsAjaxWidgetLinks::init()
   * @inheritdoc
   */
  public function init() {
    parent::init();

    // Add additional javascript.
    drupal_add_js(drupal_get_path('module', 'od_facets'). '/includes/js/search.js');

    // Load fast search library
    drupal_add_library('od_common', 'jquery.fastLiveFilter');

    $this->build['#attributes']['class'][] = 'opendata-ajax-links-facet-searchable';
  }

//  public function buildListItems($build) {
//    $items = parent::buildListItems($build);
//
//    $element = &$this->build[$this->facet['field alias']];
//
//    $this->build['search_block'] = array(
//      '#prefix' => '<div class="search-block-wrapper">',
//      '#suffix' => '</div>',
//      'search' => array(
//        '#markup' => '<input type="text" placeholder="' . t('Search') . '"/>',
//      ),
//      '#weight' => -10,
//    );
//
//
//
//
//    return $items;
//  }
}
