<?php

/**
 * @file
 * User page callbacks for the ajax_facets module.
 */

/**
 * Callback to update facets content by AJAX.
 */
function ajax_facets_refresh_facets_content() {

  $name = $_GET['view_name'];
  $display_id = $_GET['display_name'];
  // Execute view query to fill facets.
  $view = views_get_view($name);
  $view->execute_display($display_id, $_GET);
  $page = $view->preview($display_id);

  $searcher = 'search_api@' . $_GET['index_id'];
  $adapter = facetapi_adapter_load($searcher);
  $blocks = ajax_facets_process_facet_blocks($searcher);
  $facet_query = !empty($_GET['f']) ? $_GET['f'] : '';

  $result = array(
    'applyUrl' => ajax_facets_facet_build_apply_path($adapter),
    'resetUrls' => $blocks['reset_urls'],
    'newContent' => $blocks['facet_blocks'],
    'hideBlocks' => $blocks['hide_blocks'],
    'activeItems' => $blocks['active_items'],
    'views_content' => $page,
    'display_id' => $display_id,
    'views_name' => $name,
    'facets' => $facet_query,
    'update_results' => $blocks['update_results'],
    'total_results' => $view->total_rows,
    'settings' => array(),
  );

  // @see template_preprocess_views_view();
  // Update settings when view will be reloaded. Specifically $view->dom_id.
  if ($view->use_ajax) {
    $result['settings'] = array(
      'views' => array(
        'ajax_path' => url('views/ajax', array('query' => array('f' => $facet_query))),
        'ajaxViews' => array(
          'views_dom_id:' . $view->dom_id => array(
            'view_name' => $view->name,
            'view_display_id' => $view->current_display,
            'view_args' => check_plain(implode('/', $view->args)),
            'view_path' => check_plain($_GET['q']),
            // Pass through URL to ensure we get e.g. language prefixes.
            'view_base_path' => $view->get_path(),
            'view_dom_id' => $view->dom_id,
            // To fit multiple views on a page, the programmer may have
            // overridden the display's pager_element.
            'pager_element' => isset($view->query->pager) ? $view->query->pager->get_pager_id() : 0,
          ),
        ),
      ),
    );
  }

  return $result;
}
