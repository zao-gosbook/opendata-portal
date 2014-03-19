<?php
/**
 * @file
 * Provides an Better Exposed Filters exposed form plugin for View 3.x.
 */
class od_common_better_exposed_filters_exposed_form_plugin extends better_exposed_filters_exposed_form_plugin {

  /*
   * Tweak the exposed filter form to show Better Exposed Filter options.
   */
  function exposed_form_alter(&$form, &$form_state) {
    parent::exposed_form_alter($form, $form_state);
    //return ;

    $selected = array(
      '#type' => 'radios',
      '#weight' => '-50000',
      '#title' => t('Selected'),
      '#options' => array(
        0 => t('No'),
        1 => t('Yes'),
      ),
      '#default_value' => 0,
      '#description' => t('Set this to <em>Yes</em> if you would like this category to be selected by default.'),
    );
    $form['selected'] = $selected;
    //unset($form['field_organization_target_id']);
    dpm($form);
  }

}
