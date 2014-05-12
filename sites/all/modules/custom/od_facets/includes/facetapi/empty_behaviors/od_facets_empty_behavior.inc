<?php

/**
 * @file
 * The empty_text empty behavior class.
 */

$plugin = array(
  'title' => t('Opendata AJAX Facet Empty behaviour'),
  'handler' => array(
    'label' => t('Opendata AJAX Facet Empty behaviour'),
    'class' => t('OdFacetsEmptyBehavior'),
  ),
);

/**
 * Empty behavior plugin that displays markup, usually just some text.
 *
 * This plugin allows administrators to display markup filtered through text
 * formats as the contents of a facet when it has no items.
 */
class OdFacetsEmptyBehavior extends FacetapiEmptyBehavior {
  /**
   * Implements FacetapiEmptyBehavior::execute().
   */
  public function execute() {
    if (!$this->check()) {
      throw new Exception(get_class(). ' empty behavior will work only with FacetapiOdFacetsAjaxWidgetLinks'); //@fixme
    }

    $class = 'facet-wrapper-checkboxes facet-empty '. $this->settings['shared_settings']['widget']['identity_class'];
    $build = array(
      '#markup' => "<div class=\"{$class}\"></div>",
    );

    return $build;
  }

  /**
   * Checks if this behavior is applicable to selected widget.
   * @return bool
   */
  public function check() {
    return isset($this->settings['shared_settings']['widget']['identity_class']);
  }

  /**
   * Overrides FacetapiEmptyBehavior::settingsForm().
   */
  public function settingsForm(&$form, &$form_state) {
    if (!$this->check()) {
      //$form['widget']['empty']['od_facets_empty_behavior']['#type'] = 'fieldset';
      $form['widget']['empty']['od_facets_empty_behavior']['#prefix'] = '<div class="empty-behaviour-error messages warning">';
      $form['widget']['empty']['od_facets_empty_behavior']['#suffix'] = '</div>';
      $form['widget']['empty']['od_facets_empty_behavior']['html']['#markup'] = 'Opendata AJAX Facet Empty behaviour will work only with FacetapiOdFacetsAjaxWidgetLinks';
      $form['widget']['empty']['od_facets_empty_behavior']['#states'] = array(
        'visible' => array(
          'select[name="empty_behavior"]' => array('value' => 'od_facets_empty_behavior'),
        ),
      );
    }
  }
}
