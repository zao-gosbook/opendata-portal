<?php

/**
 * @file
 * The facetapi_links and facetapi_checkbox_links widget plugin classes.
 */

/**
 * Widget that renders facets as a list of clickable links.
 *
 * Links make it easy for users to narrow down their search results by clicking
 * on them. The render arrays use theme_item_list() to generate the HTML markup.
 */
class FacetapiOdFacetsAjaxWidgetLinks extends FacetapiAjaxWidgetCheckboxes {
  protected $preprocessors_store = array();
  public function init() {
    parent::init();

    // Add additional javascript.
    drupal_add_js(drupal_get_path('module', 'od_facets'). '/includes/js/widget_links.js');

    // Add default class for facet block.
    $this->build['#attributes']['class'][] = 'opendata-ajax-links-facet';
  }


  /**
   * Just adds builtin preprocessors
   */
  protected function initBuiltInPreprocessors() {
    // Add custom processors
    $this->addPreprocessor('first_to_upper', function(&$item, &$build) {
      $item['#markup'] = drupal_strtoupper(drupal_substr($item['#markup'], 0, 1)) . drupal_substr($item['#markup'], 1);
    }, t('CapitaliZe First letter'));

    $this->addPreprocessor('str_to_upper', function(&$item, &$build) {
      $item['#markup'] = drupal_strtoupper($item['#markup']);
    }, t('CAPITALIZE all facet'));

    $this->addPreprocessor('str_to_lower', function(&$item, &$build) {
      $item['#markup'] = drupal_strtolower($item['#markup']);
    }, t('make all facet lower'));

    // Add some external preprocessors
    drupal_alter('od_facets_facetapi_widget_preprocessors', $this);
  }

  /**
   * Overrides FacetapiAjaxWidgetCheckboxes::__construct().
   *
   * For links, it is better to use the machine name of the facet as opposed to
   * the alias for the key. Alias are usually, but not necessarily, unique. It
   * doesn't make sense to group links in the same element as they are usually
   * rendered in blocks with are separate from one another.
   */
  public function __construct($id, array $realm, FacetapiFacet $facet, stdClass $settings) {
    parent::__construct($id, $realm, $facet, $settings);

    $this->initBuiltInPreprocessors();
  }


  /**
   * Overrides FacetapiWidget::settingsForm().
   */
  function settingsForm(&$form, &$form_state) {
    parent::settingsForm($form, $form_state);

    $form['widget']['widget_settings']['links'][$this->id]['preprocessors'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Preprocessors'),
      '#options' => $this->getCustomPrerpocessors(),
      '#default_value' => $this->settings->settings['preprocessors'],
    );
  }

  /**
   * Overrides FacetapiAjaxWidgetCheckboxes::getDefaultSettings().
   *
   */
  function getDefaultSettings() {
    $settings = parent::getDefaultSettings();

    $settings['preprocessors'] = array();
    return $settings;
  }


  function getCustomPrerpocessors() {
    static $preprocessors = array(
      'count' => NULL,
      'data' => array(),
    );

    // Some caching
    if ($preprocessors['count'] !== count($this->preprocessors_store)) {
      $preprocessors['count'] = count($this->preprocessors_store);
      foreach ($this->preprocessors_store as $_preprocessor => $_preprocessor_info) {
        $preprocessors['data'][$_preprocessor] = $_preprocessor_info['label'];
      }
    }

    return $preprocessors['data'];
  }

  function addPreprocessor($key, $callback, $label = NULL) {
    $this->preprocessors_store[$key] = array(
      'callback' => $callback,
      'label' => $label !== NULL ? $label : $key,
    );
  }

  function callPreprocessor($preprocessor, $arguments) {
    if (isset($this->preprocessors_store[$preprocessor])) {
      return call_user_func_array($this->preprocessors_store[$preprocessor]['callback'], $arguments);
    }

    return FALSE;
  }

  /**
   * Transforms the render array for use with theme_item_list().
   *
   * The recursion allows this function to act on the various levels of a
   * hierarchical data set.
   *
   * @param array $build
   *   The items in the facet's render array being transformed.
   *
   * @return array
   *   The "items" parameter for theme_item_list().
   */
  function buildListItems($build) {
    /*
     * This method was copy-pasted with poker face from FacetapiAjaxWidgetCheckboxes
     */

    $have_active = FALSE;
    // Builds rows.
    $items = array();
    $items_count = count($build);
    $active_items = array();
    $preprocessors = array_filter($this->settings->settings['preprocessors']);
    foreach ($build as $value => $item) {
      foreach ($preprocessors as $preprocessor) {
        $this->callPreprocessor($preprocessor, array(&$item, &$build));
      }

      $row = array('class' => array());
      $attributes = array(
        'class' => array('facet-multiselect-checkbox'),
        'data-facet' => $this->settings->facet,
      );
      // Respect current selection.
      if ($item['#active']) {
        $attributes['checked'] = 'checked';
        $have_active = TRUE;
        $active_items[] = $this->key . ':' . $item['#markup'];
        $row['class'][] = 'facetapi-active'; //Set active class to say that it is really active!
      }

      $checkbox = array(
        '#id' => 'ajax-facets-checkboxes-' . str_replace(array('_', ' ', ':'), '-', $this->key) . '-' . drupal_strtolower($value),
        '#name' => urlencode($this->key) . ':' . $value,
        '#type' => 'checkbox',
        '#title' => $item['#markup'] . theme('facetapi_count',(array('count' => $item['#count']))),
        '#attributes' => $attributes,
      );
      $row['data'] = drupal_render($checkbox);
      if ($items_count == 1) {
        $row['class'][] = 'single-leaf';
      }

      if(!empty($item['#item_children'])) {
        if ($item['#active'] || !empty($this->settings->settings['show_expanded'])) {
          $row['class'][] = 'expanded';
          $row['children'] = $this->buildListItems($item['#item_children']);
        } else {
          $row['class'][] = 'collapsed';
        }
      }
      $items[] = $row;
    }

    $this->jsSettings['haveActiveSelection'] = $this->settings->settings['have_active_selection'] = $have_active;
    sort($active_items);
    $this->jsSettings['activeItems'] = $active_items;
    // Generate reset path on server side to make possible to use aliases.
    if ($have_active) {
      $this->jsSettings['resetPath'] = ajax_facets_facet_build_reset_path($this->facet->getFacet(), $this->facet->getAdapter());
    }
	
    return $items;
  }
}
