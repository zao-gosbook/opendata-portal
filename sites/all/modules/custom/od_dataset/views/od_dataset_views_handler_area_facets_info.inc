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
   * @todo: Should have own configuration with ability to select searcher index
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Render the area
   */
  function render($empty = FALSE) {
    $realm_name = 'block';
    $searcher = 'search_api@' . 'datasets';
    $adapter = facetapi_adapter_load($searcher);

    if (!$adapter) {
      return '';
    }

    $facets_to_proceed = array();
    $enabled_facets = facetapi_get_enabled_facets($searcher, $realm_name);
    foreach ($enabled_facets as $facet) {
      $facets_to_proceed[] = $facet['name'];
    }

    $filters = array(
      '#prefix' => '
        <div class="selected-filters-wrapper">
          <div class="selected-filters-load">
      ',
      '#suffix' => '
          </div>
        </div>',
    );
    $adapter->buildRealm($realm_name);
    foreach ($facets_to_proceed as $facet_name) {
      $facet = $adapter->getFacet(array('name' => $facet_name));
      /*$processor = new FacetapiFacetProcessor($facet);
      $processor->process();
      //$facet->build();*/
      $facet_build = $facet->getBuild();
      $facet_info = $enabled_facets[$facet_name];
      $facet_build = array_filter($facet_build, (function($var) {
        return $var['#active'] != 0;
      }));

      $filter = array();
      if (count($facet_build)) {
        $filter['#prefix'] = '<div class="filter-wrapper">';
        $filter['#suffix'] = '</div>';

        $filter['info']['#markup'] = '<div class="filter-info-wrapper"><span>' . $facet_info['label'] . '</span></div>';
        $filter['filters']['#prefix'] = '<div class="filter-items-wrapper">';
        $filter['filters']['#suffix'] = '</div>';
        $item_index = 0;
        foreach ($facet_build as $item) {
          $wrapper_attributes = array(
            'class' => array('filter-item-wrapper'),
            'data-facet-target' => "{$facet_info['name']}:{$item['#indexed_value']}",
          );

          $filter['filters'][$item_index] = array(
            '#markup' => "
              <a href=\"#\">
                <span class=\"before\"></span>
                <span class=\"item-{$item_index}\">{$item['#markup']}</span>
                <span class=\"after\"></span>
              </a>
            ",
            '#prefix' => '<div '.drupal_attributes($wrapper_attributes).'>',
            '#suffix' => '</div>',
          );

          $item_index++;
        }
      }

      $filters[$facet_name] = $filter;
    }

//    $fake_plugin_info = array(
//      'id' => 'od_facets_term_view_tag',
//      'handler' => array(
//        'label' => 'Fake plugin',
//        'class' => 'ODFacetsTermViewTag',
//        'query types' => array(
//          'term',
//        ),
//      ),
//      'module' => 'od_dataset',
//      'name' => 'od_facets_term_view_tag',
//      'path' => drupal_get_path('module', 'od_dataset'),
//      'file' => NULL,
//      'plugin module' => 'facetapi',
//      'plugin type' => 'widget',
//    );



    return render($filters);
  }
}