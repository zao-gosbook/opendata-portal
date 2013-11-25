<?php


/**
 * @file
 * Sample ctools content type that takes advantage of context.
 *
 * This example uses the context it gets (simplecontext) to demo how a
 * ctools content type can access and use context. Note that the simplecontext
 * can be either configured manually into a panel or it can be retrieved via
 * an argument.
 *
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Configurable search pane'),
  'content_types' => 'gb_search_pane',
  // 'single' means not to be subtyped.
  'single' => TRUE,
  // Name of a function which will render the block.
  'render callback' => 'gb_search_pane_content_type_render',

  // Icon goes in the directory with the content type.
  'icon' => 'icon_example.png',
  'description' => t('Configurable search pane - renders simple form with custom field name, submit button and action url.'),
  'edit form' => 'gb_search_pane_content_type_edit_form',

  // presents a block which is used in the preview of the data.
  // Pn Panels this is the preview pane shown on the panels building page.
  'category' => array(t('Other'), -9),
);



/**
 * Run-time rendering of the body of the block (content type)
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time
 * @param $args
 * @param $context
 *   Context - in this case we don't have any
 *
 * @return
 *   An object with at least title and content members
 */
function gb_search_pane_content_type_render($subtype, $conf, $args) {
  $block = new stdClass();

  // Don't forget to check this data if it's untrusted.
  // The title actually used in rendering.
  $block->title = "Search pane";
  $block->content = drupal_get_form('gb_search_pane_content_type_form', $conf);
  return $block;
}


function gb_search_pane_content_type_form($form, $form_state, $conf) {
  $form_state['conf'] = $conf;

  $form = array();

  $form['#action'] = url('');

  $form['field'] = array(
    '#title' => t($conf['query_field_label']),
    '#type' => 'textfield',
    '#size' => $conf['query_field_size'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t($conf['submit_value']),
  );

  return $form;
}

function gb_search_pane_content_type_form_submit($form, $form_state) {
  $conf = $form_state['conf'];
  $options = array('query' => array($conf['query_field_name'] => $form_state['values']['field']));
  drupal_goto($conf['redirect_url'], $options);
}

/**
 * 'Edit' callback for the content type.
 * This example just returns a form.
 *
 */
function gb_search_pane_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];
  $form['query_field_label'] = array(
    '#type' => 'textfield',
    '#title' => t('Query field label'),
    '#size' => 50,
    '#default_value' => !empty($conf['query_field_label']) ? $conf['query_field_label'] : 'Search',
    '#description' => 'String will be translated',
  );
  $form['query_field_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Query field name'),
    '#size' => 50,
    '#default_value' => !empty($conf['query_field_name']) ? $conf['query_field_name'] : 'query',
  );
  $form['query_field_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Query field size'),
    '#size' => 50,
    '#default_value' => !empty($conf['query_field_size']) ? $conf['query_field_size'] : 20,
  );
  $form['redirect_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect url'),
    '#size' => 128,
    '#default_value' => !empty($conf['redirect_url']) ? $conf['redirect_url'] : 'search',
    '#description' => t('Enter the url form should forward to'),
  );
  $form['submit_value'] = array(
    '#type' => 'textfield',
    '#title' => t('Submit button label'),
    '#size' => 50,
    '#default_value' => !empty($conf['submit_value']) ? $conf['submit_value'] : 'search',
    '#description' => 'String will be translated',
  );

  return $form;
}

function gb_search_pane_content_type_edit_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (!empty($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
