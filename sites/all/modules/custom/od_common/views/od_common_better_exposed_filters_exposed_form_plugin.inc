<?php
/**
 * @file
 * Provides an Better Exposed Filters exposed form plugin for View 3.x.
 * This handler actually doesn't work. It lays here just as example.
 */
class od_common_better_exposed_filters_exposed_form_plugin extends views_plugin_exposed_form {//better_exposed_filters_exposed_form_plugin {

  /*
   * Tweak the exposed filter form to show Better Exposed Filter options.
   */
  function _exposed_form_alter(&$form, &$form_state) {
    parent::exposed_form_alter($form, $form_state);

    $widget_key = get_class();
    $selected = array(
      '#type' => 'radios',
      '#weight' => -500,
      '#title' => t('Selected'),
      '#options' => array(
        0 => t('No'),
        1 => t('Yes'),
      ),
      '#default_value' => 0,
      '#description' => t('Set this to <em>Yes</em> if you would like this category to be selected by default.'),
    );

    $form[$widget_key] = $selected;
    $form['#info'] = array(
      $widget_key => array(
        //'operator' => '=',
        'value' => $widget_key,
      ) + $form['#info'],
    );
  }

  public static function renderRadios() {
    $selected = array(
      '#type' => 'radios',
      '#weight' => 0,
      '#title' => t('Selected'),
      '#options' => array(
        0 => t('No'),
        1 => t('Yes'),
      ),
      '#default_value' => 0,
      '#description' => t('Set this to <em>Yes</em> if you would like this category to be selected by default.'),
      '#attributes' => array(
        'name' => get_class(),
      ),
    );

    return form_process_radios($selected);
  }
}
