<?php

/**
 * @file
 * Admin pages for Extended search page.
 */


/**
 * Altering the default search api page admin form.
 * 
 * @see search_api_page_admin_edit()
 * @ingroup forms
 */
function ext_search_page_admin_edit_alter_form(&$form, &$form_state, $form_id) {
  drupal_add_css(drupal_get_path('module', 'ext_search_page') . '/ext_search_page.css');
  
  $page=&$form_state['build_info']['args'][0];
  if (is_string($page->ext_search_options)) {
    $page->ext_search_options=(array)unserialize($page->ext_search_options);
  }
  
  $form['ext_search_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Extended search page'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['ext_search_options']['block'] = array(
    '#type' => 'checkbox',
    '#title' => t('Create a search form block'),
    '#description' => t('Create a search form block for this search page. Will also work without extended search.'),
    '#default_value' => isset($page->ext_search_options['block'])?$page->ext_search_options['block']:false,
  );
  
  $form['ext_search_options']['enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable extended search'),
    '#description' => t('Display the extended search form with index filters.'),
    '#default_value' => isset($page->ext_search_options['enabled'])?$page->ext_search_options['enabled']:false,
  );

  $form['ext_search_options']['hide_fulltext'] = array(
    '#type' => 'checkbox',
    '#title' => t('Hide fulltext input field'),
    '#description' => t('You can also hide the fulltext input field.'),
    '#default_value' => isset($page->ext_search_options['hide_fulltext'])?$page->ext_search_options['hide_fulltext']:false,
  );
  
  foreach (ext_search_page_get_widgets_registry($page) as $field => $field_info) {

     $form['ext_search_options']['filters'][$field]['default_name'] = array(
      '#markup' => check_plain($field_info['default_name']),
    );
    
    $form['ext_search_options']['filters'][$field]['display_name'] = array(
      '#type' => 'textfield',
      '#size' => 16,
      '#default_value' => $field_info['display_name'],
    );

    // display filter
    $form['ext_search_options']['filters'][$field]['display'] = array(
      '#type' => 'select',
      '#options' => array('' => t('Disabled'), 'true' => t('Enabled')),
      '#default_value' => $field_info['display'],
    );

    // display filter in block
    $form['ext_search_options']['filters'][$field]['block'] = array(
      '#type' => 'select',
      '#options' => array('' => t('Disabled'), 'true' => t('Enabled')),
      '#default_value' => $field_info['block'],
    );
    
    // widget selection 
    $options=array();
    if (isset($field_info['widgets'])) {
      foreach ($field_info['widgets'] as $wid => $widget) {
        $options[$wid]=$widget['name'];
      }
    }
    if (count($options)) {
      $form['ext_search_options']['filters'][$field]['wid'] = array(
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => $field_info['wid'],
      );
    }
    else {
      $form['ext_search_options']['filters'][$field]['wid'] = array(
        '#markup' => t('No widgets'),
      );
    }
    
    // default value
    $form['ext_search_options']['filters'][$field]['default']=array();
    if (isset($field_info['widgets'][$field_info['wid']])) {
      $values=array();
      if (isset($field_info['default'])) {
        $values=$field_info['default'];
      }
      
      $f=$field_info['widgets'][$field_info['wid']]['add_form'];
      $f(
        $form['ext_search_options']['filters'][$field]['default'], 
        $field,
        $field_info['widgets'][$field_info['wid']],
        $values,
        'admin');
    }
    
    // weight
    $form['ext_search_options']['filters'][$field]['weight']=array(
      '#type' => 'textfield',
      '#size' => 5,
      '#default_value' => $field_info['weight'],
      '#attributes' => array('class' => array('filter-weight')));
    
    $form['ext_search_options']['description']['#markup']=
      t('You can specify default value even if widget is not activated. This will result in hidden forced filters. You can use &lt;default&gt; for default filter name or &lt;none&gt; for no name at all.');
  }
  
  $form['ext_search_options']['filters']['#theme']='ext_search_page_filters_table';
    
  $form['#submit'][]='ext_search_page_admin_edit_submit';
  
  $i=100;
  $form['submit']['#weight']=$i++;
  $form['delete']['#weight']=$i++;

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
function theme_ext_search_page_filters_table($variables) {
  $form=&$variables['form'];
  
  drupal_add_tabledrag('ext-search-filters-table', 'order', 'sibling', 'filter-weight');
  
  $rows=array();
  foreach (element_children($form) as $field) {
    $form[$field]['weight']['#attributes']['class'][] = 'filter-weight';
    $row=array();
    
    $row[]=drupal_render($form[$field]['default_name']);
    $row[]=drupal_render($form[$field]['display_name']);
    $row[]=drupal_render($form[$field]['display']);
    $row[]=drupal_render($form[$field]['block']);
    $row[]=drupal_render($form[$field]['wid']);
    $row[]=drupal_render($form[$field]['default']);
    $row[]=drupal_render($form[$field]['weight']);
    
    $row['data']=$row;
    $row['class']=array('draggable');
    $rows[$field]=$row;
  }
  
  $output=theme('table', array(
      'header' => array(t('Filter'), t('Name'), t('Display'), t('Block'), t('Widget'), t('Default'), t('Weight')), 
      'rows' => $rows, 
      'attributes' => array('id' => 'ext-search-filters-table')));

  return $output;
}


/**
 * Form submission handler for search_api_page_admin_edit().
 * 
 * @see search_api_page_admin_edit()
 */
function ext_search_page_admin_edit_submit(array $form, array &$form_state) {
  $page=&$form_state['build_info']['args'][0];
  if (is_string($page->ext_search_options)) {
    $page->ext_search_options=(array)unserialize($page->ext_search_options);
  }
  
  $rebuild=FALSE;
  if (!isset($page->ext_search_options['enabled'])) $page->ext_search_options['enabled']=FALSE;
  if ($page->ext_search_options['enabled']!=$form_state['values']['ext_search_options']['enabled']) {
    $page->ext_search_options['enabled']=$form_state['values']['ext_search_options']['enabled'];
    $rebuild=TRUE;
  }
  
  $page->ext_search_options['block']=$form_state['values']['ext_search_options']['block'];
  $page->ext_search_options['hide_fulltext']=$form_state['values']['ext_search_options']['hide_fulltext'];
  
  $page->ext_search_options['filters']=array();
  foreach (ext_search_page_get_widgets_registry($page) as $field => $field_info) {
    if (isset($form_state['values']['ext_search_options']['filters'][$field])) {
      foreach (array('wid', 'weight', 'display', 'block', 'display_name') as $param) {
        $page->ext_search_options['filters'][$field][$param]=NULL;
        if (isset($form_state['values']['ext_search_options']['filters'][$field][$param])) {
          $page->ext_search_options['filters'][$field][$param]=$form_state['values']['ext_search_options']['filters'][$field][$param];
        }
      }
      
      if (isset($field_info['widgets'][$field_info['wid']])) {       
        $f=$field_info['widgets'][$field_info['wid']]['get_values'];
        $page->ext_search_options['filters'][$field]['default']=$f(
          $field, 
          $field_info['widgets'][$field_info['wid']], 
          $form_state['values']['ext_search_options']['filters'][$field]['default']);
      }

    }
  }
  
  $fields=array(
    'ext_search_options' => serialize($page->ext_search_options),
  );
  $ret = db_update('search_api_page')
     ->fields($fields)
     ->condition('id', $page->id)
     ->execute();
  if ($rebuild) {
    // will impact the hook_menu_alter() so rebuild !
    menu_rebuild();
  }

  $form_state['redirect'] = $_GET['q'];
}
