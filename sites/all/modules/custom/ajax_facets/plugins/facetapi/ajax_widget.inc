<?php

/**
 * @file
 * Base ajax_facets widget
 */

/**
 * Widget that renders facets as a list of clickable links.
 *
 * Links make it easy for users to narrow down their search results by clicking
 * on them. The render arrays use theme_item_list() to generate the HTML markup.
 */
class FacetapiAjaxWidget extends FacetapiWidgetCheckboxLinks {

  /**
   * Overrides FacetapiWidget::settingsForm().
   */
  function settingsForm(&$form, &$form_state) {


    $form['widget']['widget_settings']['links'][$this->id]['wrapper_container'] = array(
      '#type' => 'container',
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    $form['widget']['widget_settings']['ajax'][$this->id]['update_results'] = array(
      '#type' => 'checkbox',
      '#title' => t('Update results by ajax'),
      '#default_value' => !empty($this->settings->settings['update_results']),
      '#description' => t('If active, then search results will be updated by AJAX when facet was changed.
       If not active, then after than facet will be updated, user will see special popup with link for filter results.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    $form['widget']['widget_settings']['ajax'][$this->id]['show_reset_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display reset link'),
      '#default_value' => !empty($this->settings->settings['show_reset_link']),
      '#description' => t('Display link for reset facet.'),
      '#states' => array(
        'visible' => array(
          'select[name="widget"]' => array('value' => $this->id),
        ),
      ),
    );

    $searcher = $this->facet->getAdapter()->getSearcher();
    $class = drupal_html_class("facetapi-facet-$searcher-{$this->realm['name']}-{$this->facet['name']}");
    $form['widget']['widget_settings']['links'][$this->id]['wrapper_container']['wrapper_code'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="form-item messages warning">'
        . t(
          'Please select "@empty" as @d_text. Use "Full html" as format and add this wrapper as empty text.
          It\'s need for avoid problem, when some facets was empty on page and cannot be loaded again after
          than values of other facets will be changed.
          ',
          array(
            '@empty' => t('Empty facet behavior'),
            '@d_text' => t('Display text')
          )
        )
        . '<br />'
        . t('More info here !link', array('!link' => l('https://drupal.org/node/2081831', 'https://drupal.org/node/2081831')))
        . '<br /><br />'
        . check_plain('<div class="facet-wrapper-selectbox ' . $class . '"></div>')

        . '</div>',
    );
  }
}
