<?php

/**
 * @file
 * Contains the opendata list style plugin.
 */

/**
 * Style plugin to render opendata list.
 *
 * @ingroup views_style_plugins
 */
class opendata_views_plugin_style_opendata_table extends views_plugin_style {
  /**
   * Add entity id field to query.
   */
  function query() {
    // Nid field.
    $this->view->query->fields['nid'] = array(
      'field' => 'nid',
      'table' => 'node',
      'alias' => 'nid',
    );
  }

  /**
   * Set default options.
   */
  function options(&$options) {
    parent::options($options);
  }

  /**
   * Set default form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
}
