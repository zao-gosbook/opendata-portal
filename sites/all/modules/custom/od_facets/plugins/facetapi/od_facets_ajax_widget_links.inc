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
  /**
   * Transforms the render array for use with theme_item_list().
   *
   * The recursion allows this function to act on the various levels of a
   * hierarchical data set.
   *
   * @param array $build
   *   The items in the facet's render array being transformed.
   *
   * @return array
   *   The "items" parameter for theme_item_list().
   */
  function buildListItems($build) {
    /*
     * This method was copy-pasted with poker face from FacetapiAjaxWidgetCheckboxes
     */

    $have_active = FALSE;
    // Builds rows.
    $items = array();
    $items_count = count($build);
    $active_items = array();

    foreach ($build as $value => $item) {
      $row = array('class' => array());
      $attributes = array(
        'class' => array('facet-multiselect-checkbox'),
        'data-facet' => $this->settings->facet,
      );
      // Respect current selection.
      if ($item['#active']) {
        $attributes['checked'] = 'checked';
        $have_active = TRUE;
        $active_items[] = $this->key . ':' . $item['#markup'];
        $row['class'][] = 'facetapi-active'; //Set active class to say that it is really active!
      }

      $checkbox = array(
        '#id' => 'ajax-facets-checkboxes-' . str_replace(array('_', ' ', ':'), '-', $this->key) . '-' . drupal_strtolower($value),
        '#name' => urlencode($this->key) . ':' . $value,
        '#type' => 'checkbox',
        '#title' => $item['#markup'] . theme('facetapi_count',(array('count' => $item['#count']))),
        '#attributes' => $attributes,
      );
      $row['data'] = drupal_render($checkbox);
      if ($items_count == 1) {
        $row['class'][] = 'single-leaf';
      }

      if(!empty($item['#item_children'])) {
        if ($item['#active'] || !empty($this->settings->settings['show_expanded'])) {
          $row['class'][] = 'expanded';
          $row['children'] = $this->buildListItems($item['#item_children']);
        } else {
          $row['class'][] = 'collapsed';
        }
      }
      $items[] = $row;
    }

    $this->jsSettings['haveActiveSelection'] = $this->settings->settings['have_active_selection'] = $have_active;
    sort($active_items);
    $this->jsSettings['activeItems'] = $active_items;
    // Generate reset path on server side to make possible to use aliases.
    if ($have_active) {
      $this->jsSettings['resetPath'] = ajax_facets_facet_build_reset_path($this->facet->getFacet(), $this->facet->getAdapter());
    }

    $this->addJsOnce();
    return $items;
  }

  protected function addJsOnce() {
    static $added = FALSE;
    if (!$added) {
      drupal_add_js(drupal_get_path('module', 'od_facets'). '/js/widget_links.js');
    }

    return TRUE;
  }
}
