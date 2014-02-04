<?php

/**
 * @file
 * Definition of views_handler_area_result.
 */

/**
 * Views area handler to display some configurable result summary.
 *
 * @ingroup views_area_handlers
 */
class views_handler_area_result extends views_handler_area {

  function option_definition() {
    $options = parent::option_definition();

    $options['content'] = array(
      'default' => 'Displaying @start - @end of @total',
      'translatable' => TRUE,
    );
    $options['format_plural'] = array('default' => FALSE, 'bool' => TRUE);
    $options['format_plural_count'] = array('default' => '@total');
    $options['format_plural_plural'] = array(
      'default' => '',
      'translatable' => TRUE,
    );

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $variables = array(
      'items' => array(
        '@start -- the initial record number in the set',
        '@end -- the last record number in the set',
        '@total -- the total records in the set',
        '@name -- the human-readable name of the view',
        '@per_page -- the number of items per page',
        '@current_page -- the current page number',
        '@current_record_count -- the current page record count',
        '@page_count -- the total page count',
      ),
    );
    $list = theme('item_list', $variables);
    $form['content'] = array(
      '#title' => t('Display'),
      '#type' => 'textarea',
      '#rows' => 3,
      '#default_value' => $this->options['content'],
      '#description' => t('You may use HTML code in this field. The following tokens are supported:') . $list,
    );
    $form['format_plural'] = array(
      '#type' => 'checkbox',
      '#title' => t('Format plural'),
      '#description' => t('If checked, special handling will be used for plurality.'),
      '#default_value' => $this->options['format_plural'],
    );
    $form['format_plural_count'] = array(
      '#type' => 'select',
      '#title' => t('Count token'),
      '#description' => t('Token used to select plural format.'),
      '#default_value' => $this->options['format_plural_count'],
      '#options' => drupal_map_assoc(array(
        '@start',
        '@end',
        '@total',
        '@name',
        '@per_page',
        '@current_page',
        '@current_record_count',
        '@page_count'
      )),
      '#dependency' => array('edit-options-format-plural' => array(TRUE)),
    );
    $form['format_plural_plural'] = array(
      '#title' => t('Plural form'),
      '#type' => 'textarea',
      '#rows' => 3,
      '#default_value' => $this->options['format_plural_plural'],
      '#description' => t('Text to use for the plural form.'),
      '#dependency' => array('edit-options-format-plural' => array(TRUE)),
    );
  }


  /**
   * Find out the information to render.
   */
  function render($empty = FALSE) {
    // Must have options and does not work on summaries.
    if (!isset($this->options['content']) || $this->view->plugin_name == 'default_summary') {
      return;
    }
    $output = '';
    $format = $this->options['content'];
    // Calculate the page totals.
    $current_page = (int) $this->view->get_current_page() + 1;
    $per_page = (int) $this->view->get_items_per_page();
    $count = count($this->view->result);
    // @TODO: Maybe use a possible is views empty functionality.
    // Not every view has total_rows set, use view->result instead.
    $total = isset($this->view->total_rows) ? $this->view->total_rows : count($this->view->result);
    $name = check_plain($this->view->human_name);
    if ($per_page === 0) {
      $page_count = 1;
      $start = 1;
      $end = $total;
    }
    else {
      $page_count = (int) ceil($total / $per_page);
      $total_count = $current_page * $per_page;
      if ($total_count > $total) {
        $total_count = $total;
      }
      $start = ($current_page - 1) * $per_page + 1;
      $end = $total_count;
    }
    $current_record_count = ($end - $start) + 1;
    // Get the search information.
    $items = array('start', 'end', 'total', 'name', 'per_page', 'current_page', 'current_record_count', 'page_count');
    $replacements = array();
    foreach ($items as $item) {
      $replacements["@$item"] = ${$item};
    }
    if (!empty($this->options['format_plural']) && $replacements[$this->options['format_plural_count']] != 1) {
      $format = $this->options['format_plural_plural'];
    }
    // Send the output.
    if (!empty($total) || !empty($this->options['empty']) && !empty($this->view->build_info['count_query'])) {
      $output .= filter_xss_admin(str_replace(array_keys($replacements), array_values($replacements), $format));
    }
    return $output;
  }
}
