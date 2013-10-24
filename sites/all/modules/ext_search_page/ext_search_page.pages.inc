<?php

/**
 * @file
 * Front pages for Extended search page.
 */


/**
 * Displays a search page.
 *
 * @param $id
 *   The search page's ID.
 * @param $keys
 *   The keys to search for.
 * @param $mode : the render mode.
 */
function ext_search_page_view($id, $keys = NULL, $mode='default') {
  $keys = urldecode($keys);
  
  $page = search_api_page_load($id);
  if (is_string($page->ext_search_options)) {
    $page->ext_search_options=(array)unserialize($page->ext_search_options);
  }
  
  if (!$page) {
    return MENU_NOT_FOUND;
  }
  
  $values=ext_search_page_get_filter_values($page);
  $limit = $page->options['per_page'];
  $offset = pager_find_page() * $limit;
  
  $ret['form'] = drupal_get_form('ext_search_page_search_form', $page, $keys, $values, $mode);
  
  $ret['results']['#theme'] = 'ext_search_default_page_results';
  $ret['results']['#results'] = ext_search_page_search_execute($page, $keys, $values, FALSE, $limit, $offset);
  $ret['results']['#keys'] = $keys;
  $ret['results']['#page'] = $page;
  
  return $ret;
}


/**
 * Default theme function for displaying search results.
 * Uses the default search API page theme.
 * @see theme_search_api_page_results()
 *
 * @param array $variables
 *   An associative array containing:
 *   - page: The search page object.
 *   - results: An array of search results, as returned by SearchApiQueryInterface::execute().
 *   - keys: The keywords of the executed search.
 */
function theme_ext_search_default_page_results(&$variables) {
  $page=&$variables['page'];
  $results=&$variables['results'];
  $keys=&$variables['keys'];
  
  $ret['results']['#theme'] = 'search_api_page_results';
  $ret['results']['#index'] = search_api_index_load($page->index_id);
  $ret['results']['#results'] = $results;
  $ret['results']['#view_mode'] = isset($page->options['view_mode']) ? $page->options['view_mode'] : 'search_api_page_result';
  $ret['results']['#keys'] = $keys;
  
  if ($results['result count'] > $page->options['per_page']) {
    pager_default_initialize($results['result count'], $page->options['per_page']);
    $ret['pager']['#theme'] = 'pager';
    $ret['pager']['#quantity'] = 9;
  }

  if (!empty($results['ignored'])) {
    drupal_set_message(t('The following search keys are too short or too common and were therefore ignored: "@list".', array('@list' => implode(t('", "'), $results['ignored']))), 'warning');
  }
  if (!empty($results['warnings'])) {
    foreach ($results['warnings'] as $warning) {
      drupal_set_message(check_plain($warning), 'warning');
    }
  }
  
  return drupal_render($ret);
}


/**
 * Add ext search filters widgets to the form.
 * 
 * @param array $form
 * @param $page
 * @param string $mode
 *   The render mode
 * @ingroup forms
 */
function ext_search_page_filter_form(&$form, $page, $values, $mode='default') {
  
  drupal_add_css(drupal_get_path('module', 'ext_search_page') . '/ext_search_page.css');
  
  if (!$page->ext_search_options['enabled']) return;

  $filters=array();
  foreach (ext_search_page_get_filter_widgets($page) as $field => $widget) {
    if ($mode=='default'&&!$widget['display']) continue;
    if ($mode=='block'&&!$widget['block']) continue;
    $f=$widget['add_form'];
    $f($filters, $field, $widget, isset($values[$field])?$values[$field]:NULL, $mode);
  } 
  
  if (count($filters)) {    
    $form['filters'] = $filters+array(
      '#type' => 'fieldset',
      '#title' => t('Advanced search'),
      '#theme' => 'exposed_filters__ext_search_page',
      '#collapsible' => FALSE,
      '#collapsed' => TRUE,
      '#tree' => TRUE,
      );
    
    $form['filters']['actions'] = array(
      '#type' => 'actions',
      '#attributes' => array('class' => array('container-inline')),
    );
    $form['filters']['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Filter'),
    );
    if (count($values)) {
      $form['filters']['actions']['reset'] = array(
        '#type' => 'submit',
        '#value' => t('Reset')
      );
    }
  
    drupal_add_js('misc/form.js');
  }
}


/**
 * Display a search form.
 *
 * @param $page
 *   The search page for which this form is displayed.
 * @param $keys
 *   The search keys.
 * @param $mode
 *   Render mode (e.g. for blocks) instead of a normal one.
 * @ingroup forms
 */
function ext_search_page_search_form(array $form, array &$form_state, $page, $keys = NULL, $values=array(), $mode = 'default') {

  if (!isset($page->ext_search_options['hide_fulltext'])||!$page->ext_search_options['hide_fulltext']) {
    $fulltext=array(
      '#type' => 'fieldset',
      '#attributes' => array('class' => array('edit-fulltext')),
    );
    
    $fulltext['keys'] = array(
      '#type' => 'textfield',
      '#default_value' => $keys,
    );
    
    $fulltext['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Search'),
    );
    
    if ($mode=='default') {
      $fulltext['keys']['#title']=t('Enter your keywords');
      $form['fulltext']=$fulltext;
    }
    else {
      $fulltext['keys']['#size'] = 15;
      $form+=$fulltext;
    }
  }
  
  if ($mode=='default') {
    $form = array(
      '#type' => 'fieldset',
      '#title' => check_plain($page->name),
      'form' => $form,
    );
    if ($page->description) {
      $form['text']['#markup'] = $page->description;
      $form['text']['#weight'] = -5;
    }
  }

  $form['#attributes']['class'][]='ext-search-page-search-form';
  $form['#attributes']['class'][]='search-mode-' . $mode;
  
  ext_search_page_filter_form($form, $page, $values, $mode);
  
  return $form;
}


/**
 * Submit callback for search_api_page_search_form().
 * 
 * @see ext_search_page_search_form()
 */
function ext_search_page_search_form_submit(array $form, array &$form_state) {
  $page=&$form_state['build_info']['args'][0];
  $filter_values = array();
  switch ($form_state['values']['op']) {
    case t('Reset'):
      // nothing ...
      break;
    default:
      if (!isset($form_state['values']['filters'])) break;
      foreach (ext_search_page_get_filter_widgets($page) as $field => $widget) {
        $f=$widget['get_values'];
        $values=$f(
          $field, 
          $widget, 
          $form_state['values']['filters']);
        if ($values===NULL) {
          unset($filter_values[$field]);
        }
        elseif ($widget['default']==$values) {
          //default value not needed to be pass
          unset($filter_values[$field]);
        }
        else {
          $filter_values[$field]=is_array($values)?implode('|', $values):$values;
        }
      }
      break;
  }
  
  // @todo Take care of "/"s in the keys
  $keys = trim($form_state['values']['keys']);

  // to be nice with other modules callbacks
  $form_state['storage']['keys']=$keys;
  $form_state['storage']['filter_values']=$filter_values;
  
  $form_state['redirect'] = array(
    $page->path . '/' . urlencode($keys),
    array('query' => $filter_values));
}

/**
 * Helper function for taxonomy autocompletion
 * It's a quick rewrite of taxonomy_autocomplete()
 */
function ext_search_page_taxonomy_autocomplete($vocabulary, $tags_typed = '') {

  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary);
  // The user enters a comma-separated list of tags. We only autocomplete the last tag.
  $tags_typed = drupal_explode_tags($tags_typed);
  $tag_last = drupal_strtolower(array_pop($tags_typed));

  $matches = array();
  if ($tag_last != '') {

    $query = db_select('taxonomy_term_data', 't');
    $query->addTag('translatable');
    $query->addTag('term_access');

    // Do not select already entered terms.
    if (!empty($tags_typed)) {
      $query->condition('t.name', $tags_typed, 'NOT IN');
    }
    // Select rows that match by term name.
    $tags_return = $query
      ->fields('t', array('tid', 'name'))
      ->condition('t.vid', $vocabulary->vid)
      ->condition('t.name', '%' . db_like($tag_last) . '%', 'LIKE')
      ->range(0, 10)
      ->execute()
      ->fetchAllKeyed();

    $prefix = count($tags_typed) ? implode(', ', $tags_typed) . ', ' : '';

    $term_matches = array();
    foreach ($tags_return as $tid => $name) {
      $n = $name;
      // Term names containing commas or quotes must be wrapped in quotes.
      if (strpos($name, ',') !== FALSE || strpos($name, '"') !== FALSE) {
        $n = '"' . str_replace('"', '""', $name) . '"';
      }
      else {
        $term_matches[$prefix . $n] = check_plain($name);
      }
    }
  }

  drupal_json_output($term_matches);
}
