<?php

$plugin = array(
  'title' => t('Opendata passport html'),
  'single' => TRUE,
  'category' => t('Dataset'),
  'edit form' => 'od_passport_html_pane_content_type_edit_form',
  'render callback' => 'od_passport_html_pane_content_type_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'all contexts' => TRUE,
);

/**
 * 'Edit form' callback for the content type.
 */
function od_passport_html_pane_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function od_passport_html_pane_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function od_passport_html_pane_content_type_render($subtype, $conf, $args, $contexts) {
  $data = drupal_render(od_passport_render(arg(1))->content);
  $html = "<form>
            <p><b>Скопируйте html-код паспорта:</b></p>
            <p><textarea rows='30' cols='100' name='text' value='$data'></textarea></p>
           </form>";
  $block = new stdClass();
  $block->title = t('Dataset passport');
  $block->content = $html;
  
  return $block;
}

