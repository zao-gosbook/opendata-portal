<?php

/**
 * @file
 * Admin pages for Extended search admin.
 */

/**
 * Menu callback: extended search content administration.
 * 
 * @see node_admin_content()
 */
function ext_search_admin_admin_content($page) {
  if (is_string($page->ext_search_options)) {
    $page->ext_search_options=(array)unserialize($page->ext_search_options);
  }
  
  drupal_add_css(drupal_get_path('module', 'ext_search_admin') . '/ext_search_admin.css');
  module_load_include('inc', 'node', 'node.admin');
  
  $keys=isset($_GET['k'])?$_GET['k']:NULL;
  $values=ext_search_page_get_filter_values($page, $non_default);

  $admin=drupal_get_form('ext_search_admin_admin_content_admin_nodes', $page, $keys, $values);
  
  // do not display search in confirm form (delete)
  if (!isset($admin['confirm'])) {
    $ret[]=drupal_get_form('ext_search_admin_search_form', $page, $keys, $values, !$non_default);
  }
  
  $ret[]=$admin;

  return $ret;
}

/**
 * Form builder: Builds the node administration overview.
 * It's a basic reworking of node_admin_nodes()
 * 
 * @param array filtered_nids
 *   The nids filtered by the index, associative array id => array( score => *** )
 * 
 * @see node_admin_nodes()
 */
function ext_search_admin_admin_content_admin_nodes($form, &$form_state, $page, $keys = NULL, $values=array()) {
  
  if (isset($form_state['values']['operation']) && $form_state['values']['operation'] == 'delete') {
    return node_multiple_delete_confirm($form, $form_state, array_filter($form_state['values']['nodes']));
  }  
    
  $admin_access = user_access('administer nodes');
  
  // Build the 'Update options' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline')),
    '#access' => $admin_access,
  );
  $opops = array();
  foreach (module_invoke_all('node_operations') as $operation => $array) {
    $opops[$operation] = $array['label'];
  }
  $form['options']['operation'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#title_display' => 'invisible',
    '#options' => $opops,
    '#default_value' => 'approve',
  );
  
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#validate' => array('node_admin_nodes_validate'),
    '#submit' => array('node_admin_nodes_submit'),
  );

  // Enable language column if translation module is enabled
  // or if we have any node with language.
  $multilanguage = (module_exists('translation') || db_query("SELECT COUNT(*) FROM {node} WHERE language <> :language", array(':language' => LANGUAGE_NONE))->fetchField());
  
  $headers = ext_search_admin_content_node_headers($page, $multilanguage);
  
  // default order
  if (empty($_GET['order'])) {
    // order by score if search on words
    if ($keys&&isset($headers['score'])&&$headers['score']['sortable']&&$headers['score']['default_sort']) {
      $_GET['order'] = $headers['score']['data'];
    }
    // else order by changed
    elseif (isset($headers['changed'])&&$headers['changed']['sortable']&&$headers['changed']['default_sort']) {
      $_GET['order'] = $headers['changed']['data'];
    }
  }
  
  $order = FALSE;
  $tmp = array();
  foreach ($headers as $hid => $header) {
    if (!$header['available']) continue;
    if ($header['sortable'] && isset($_GET['order']) && $_GET['order']==$header['data']) {
      $order = $hid;
    }
    $tmp[$hid] = $header;
  }
  $headers = $tmp;

  if ($order) {
    if (!isset($_GET['sort'])) $_GET['sort'] = $headers[$order]['sort'];
    $order = array( $headers[$order]['field'] => $_GET['sort']);
  }
  
  $results=ext_search_page_search_execute($page, $keys, $values, $order, 50, pager_find_page()*50);
  pager_default_initialize(isset($results['result count']) ? $results['result count'] : 0, 50);
  
  $filtered_nids=array();
  if (isset($results['results'])) $filtered_nids=$results['results'];    
  
  $query = db_select('node', 'n')->extend('TableSort');
  
  // TODO it s not very optimized : 2 queries retriving only nids ...
  // TODO ext search -> moe it to ext_search_page_search_execute()
  if (!user_access('bypass node access')) {
    // If the user is able to view their own unpublished nodes, allow them
    // to see these in addition to published nodes. Check that they actually
    // have some unpublished nodes to view before adding the condition.
    if (user_access('view own unpublished content') && $own_unpublished = db_query('SELECT nid FROM {node} WHERE uid = :uid AND status = :status', array(':uid' => $GLOBALS['user']->uid, ':status' => 0))->fetchCol()) {
      $query->condition(db_or()
        ->condition('n.status', 1)
        ->condition('n.nid', $own_unpublished, 'IN')
      );
    }
    else {
      // If not, restrict the query to published nodes.
      $query->condition('n.status', 1);
    }
  }
  
  // filters on the nids filtered by index
  if (count($filtered_nids)) $query->condition('n.nid', array_keys($filtered_nids), 'IN');
  else $query->condition('n.nid', NULL);
    
  $nids = $query
    ->fields('n', array('nid'))
    ->range(0, 50)
    ->execute()
    ->fetchCol();
  $nodes = node_load_multiple($nids);
  
  // reorder nodes with search api order
  if (count($filtered_nids)) {
    $tmp = array();
    foreach (array_keys($filtered_nids) as $nid) {
      if (isset($nodes[$nid])) $tmp[$nid] = $nodes[$nid];
    }
    $nodes = $tmp;
  }
  
  $singles = array_flip(array_keys($headers));
  
  // Prepare the list of nodes.
  $languages = language_list();
  $destination = drupal_get_destination();
  $options = array();
  foreach ($nodes as $node) {
    $l_options = $node->language != LANGUAGE_NONE && isset($languages[$node->language]) ? array('language' => $languages[$node->language]) : array();
    $options[$node->nid] = array(
      'score' => array(
        'data' => round($filtered_nids[$node->nid]['score']*1000),
        'score' => $filtered_nids[$node->nid]['score'],
      ),
      'title' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $node->title,
          '#href' => 'node/' . $node->nid,
          '#options' => $l_options,
          '#suffix' => ' ' . theme('mark', array('type' => node_mark($node->nid, $node->changed))),
        ),
      ),
      'type' => check_plain(node_type_get_name($node)),
      'author' => theme('username', array('account' => $node)),
      'status' => $node->status ? t('published') : t('not published'),
      'changed' => format_date($node->changed, 'short'),
    );
    
    if ($multilanguage) {
      if ($node->language == LANGUAGE_NONE || isset($languages[$node->language])) {
        $options[$node->nid]['language'] = $node->language == LANGUAGE_NONE ? t('Language neutral') : t($languages[$node->language]->name);
      }
      else {
        $options[$node->nid]['language'] = t('Undefined language (@langcode)', array('@langcode' => $node->language));
      }
    }
    // Build a list of all the accessible operations for the current node.
    $operations = array();
    if (node_access('update', $node)) {
      $operations['edit'] = array(
        'title' => t('edit'),
        'href' => 'node/' . $node->nid . '/edit',
        'query' => $destination,
      );
    }
    if (node_access('delete', $node)) {
      $operations['delete'] = array(
        'title' => t('delete'),
        'href' => 'node/' . $node->nid . '/delete',
        'query' => $destination,
      );
    }
    $options[$node->nid]['operations'] = array();
    if (count($operations) > 1) {
      // Render an unordered list of operations links.
      $options[$node->nid]['operations'] = array(
        'data' => array(
          '#theme' => 'links__node_operations',
          '#links' => $operations,
          '#attributes' => array('class' => array('links', 'inline')),
        ),
      );
    }
    elseif (!empty($operations)) {
      // Render the first and only operation as a link.
      $link = reset($operations);
      $options[$node->nid]['operations'] = array(
        'data' => array(
          '#type' => 'link',
          '#title' => $link['title'],
          '#href' => $link['href'],
          '#options' => array('query' => $link['query']),
        ),
      );
    }
    
    // try some magic with unpaired headers
    foreach ($headers as $hid => $header) {
      if (!isset($options[$node->nid][$hid])) {
        $options[$node->nid][$hid] = '';
        if (isset($header['field'])&&isset($node->{$header['field']})) {
          switch ($header['field']) {
            // known fields
            case 'created':
              $options[$node->nid][$hid] = format_date($node->changed, 'short');
              break;
            // other fields
            default:
              $info = field_info_field($header['field']);
              if ($info) {
                $items = field_get_items('node', $node, $header['field']);
                switch ($info['type']) {
                  case 'datestamp':
                    // basic support for date module
                    $options[$node->nid][$hid] = isset($items[0])&&$items[0] ? format_date(date_entity_metadata_struct_getter($items[0], array(), 'value', FALSE), 'short') : '';
                    break;
                  case 'taxonomy_term_reference':
                    // basic support for taxonomy terms
                    if ($items) {
                      $terms = array();
                      foreach ($items as $item) {
                        $term = taxonomy_term_load($item['tid']);
                        $terms[] = l($term->name,'taxonomy/term/'.$item['tid']);
                      }
                      $options[$node->nid][$hid] = implode(', ', $terms);
                    }
                    break;
                  default:
                    $options[$node->nid][$hid] = isset($items[0]['value']) && is_string($items[0]['value']) ? $items[0]['value'] : isset($items[0]) && is_string($items[0]) ? $items[0] : '';
                }
              }
              else {
                $options[$node->nid][$hid] = $node->{$header['field']};
              }
          }
      	}
      }
    }
    
    $context = array('headers' => $headers, 'page' => $page, 'node' => $node);
    // allow other modules to alter the node line
    drupal_alter('ext_search_admin_record', $options[$node->nid], $context);
  }
  
  // Only use a tableselect when the current user is able to perform any
  // operations.
  if ($admin_access) {
    $form['nodes'] = array(
      '#type' => 'tableselect',
      '#header' => $headers,
      '#options' => $options,
      '#empty' => t('No content available.'),
    );
  }
  // Otherwise, use a simple table.
  else {
    $form['nodes'] = array(
      '#theme' => 'table',
      '#header' => $headers,
      '#rows' => $options,
      '#empty' => t('No content available.'),
    );
  }

  $form['pager'] = array('#markup' => theme('pager'));
  return $form;
}

/**
 * Form builder; ext search admin settings form.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function ext_search_admin_settings() {

  $options = array(NULL => t('None'));
  foreach (ext_search_page_load_pages(array('type' => 'node', 'extended' => TRUE)) as $page) {
     $options[$page->id]=$page->name;
  }
  
  $form['ext_search_admin_page'] = array(
    '#type' => 'select',
    '#title' => t('Admin content overview page'),
    '#description' => t('Use this page as default admin content overview. The underlaying index must be node based. Be aware that extended search page may define filters on node type.'),
    '#default_value' => variable_get('ext_search_admin_page', NULL),
    '#options' => $options,
  );

  $form['ext_search_admin_page_headers'] = array(
    '#type' => 'fieldset',
    '#title' => t('Admin content headers'),
    '#description' => t('You can choose which headers are available. Please double submit if you changed the page...'),
    '#tree' => TRUE,
  	'#theme' => 'ext_search_admin_headers_table',
  );  
  
  $id = variable_get('ext_search_admin_page', NULL);
  if ($id) {
    $page=ext_search_page_load_pages($id);
    if ($page) {
      foreach (ext_search_admin_content_node_headers($page, TRUE) as $hid => $header) {
        $form['ext_search_admin_page_headers'][$hid]['name'] = array(
          '#markup' => $header['data'],
        );  
        $form['ext_search_admin_page_headers'][$hid]['available'] = array(
          '#type' => 'checkbox',
          '#default_value' => $header['available'],
        );      
        if (!isset($header['field'])) continue;
        $form['ext_search_admin_page_headers'][$hid]['sortable'] = array(
          '#type' => 'checkbox',
          '#default_value' => $header['sortable'],
        );
        $form['ext_search_admin_page_headers'][$hid]['weight'] = array(
          '#type' => 'textfield',
          '#size' => 5,
          '#default_value' => isset($header['weight'])?$header['weight']:0,
        	'#attributes' => array('class' => array('filter-weight')),
        );
      }
    }
  }
  
  $form = system_settings_form($form);
  
  $form['#submit'][]='ext_search_admin_settings_submit';
  
  return $form;
}

/**
 * Theme for the filter weights table form fragment.
 * 
 * @param $variables
 *   An associative array containing:
 *   - form: the form to theme
 *   
 * @ingroup themeable
 */
function theme_ext_search_admin_headers_table($variables) {
  $form=&$variables['form'];
  
  drupal_add_tabledrag('ext-search-admin-headers-table', 'order', 'sibling', 'filter-weight');
  
  $rows=array();
  foreach (element_children($form) as $field) {
    $form[$field]['weight']['#attributes']['class'][] = 'filter-weight';
    $row=array();
    
    $row[]=drupal_render($form[$field]['name']);
    $row[]=drupal_render($form[$field]['available']);
    $row[]=drupal_render($form[$field]['sortable']);
    $row[]=drupal_render($form[$field]['weight']);
    
    $row['data']=$row;
    $row['class']=array('draggable');
    $rows[$field]=$row;
  }
  
  $output=theme('table', array(
      'header' => array(t('Name'), t('Available'), t('Sortable'), t('Weight')), 
      'rows' => $rows, 
      'attributes' => array('id' => 'ext-search-admin-headers-table')));

  return $output;
}

/**
 * Aditional submission handler.
 * @see ext_search_admin_settings()
 */
function ext_search_admin_settings_submit($form, &$form_state) {
  // TODO are hook_menu_alter() alteration trapped ?
  menu_rebuild();
}

/**
 * Form handler, build the content admin search form.
 * @param stdClass|Entity $page
 * @param string $keys
 * @param array $values
 * @param boolean $collapsed
 * @param string $mode
 * 
 * @see ext_search_page_search_form
 * @ingroup forms
 */
function ext_search_admin_search_form(array $form, array &$form_state, $page, $keys = NULL, $values=array(), $collapsed = TRUE, $mode = 'default') {
  module_load_include('inc', 'ext_search_page', 'ext_search_page.pages');

  $form=ext_search_page_search_form($form, $form_state, $page, $keys, $values, $mode);
  $form['filters']['#collapsible']=TRUE;
  $form['filters']['#collapsed']=$collapsed;
  $form['#attributes']['class'][]='admin-content';
  unset($form['#submit']); //TODO do it more secure
  
  return $form;
}

/**
 * Submission handler for ext_search_admin_search_form()
 * It uses ext_search_page_search_form_submit()
 * 
 * @see ext_search_admin_search_form()
 * @see ext_search_page_search_form_submit()
 */
function ext_search_admin_search_form_submit(array $form, array &$form_state) {
  ext_search_page_search_form_submit($form, $form_state);
  
  $filter_values=$form_state['storage']['filter_values'];
  if ($form_state['storage']['keys']) $filter_values['k']=$form_state['storage']['keys'];
  
  $form_state['redirect'] = array(
    $_GET['q'],
    array('query' => $filter_values));
}
