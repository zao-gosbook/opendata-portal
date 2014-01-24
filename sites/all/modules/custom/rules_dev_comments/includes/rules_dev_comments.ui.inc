<?php
/**
 * @file
 * Plugin UI implementation.
 */

class RulesDevCommentUI extends RulesPluginUI {

  public function form(&$form, &$form_state, $options = array()) {
    parent::form($form, $form_state, $options);
    $settings = $this->element->settings;

    $form['comment'] = array(
      '#type' => 'fieldset',
      '#title' => t('Comment'),
      '#description' => t('General code comment.'),
      '#tree' => TRUE,
    );
    $form['comment']['label'] = array(
      '#type' => 'textfield',
      '#title' => t('Comment label'),
      '#default_value' => $settings['comment:label'],
      '#required' => TRUE,
    );
    $form['comment']['text'] = array(
      '#type' => 'text_format',
      '#format' => isset($settings['comment:text']['format']) ? $settings['comment:text']['format'] : 'plain_text',
      '#title' => t('Comment text'),
      '#default_value' => isset($settings['comment:text']['value']) ? $settings['comment:text']['value'] : '',
      '#required' => FALSE,
    );
  }

  function form_extract_values($form, &$form_state) {
    parent::form_extract_values($form, $form_state);
    $form_values = RulesPluginUI::getFormStateValues($form, $form_state);

    $this->element->settings['comment:label'] = $form_values['comment']['label'];
    $this->element->settings['comment:text'] = $form_values['comment']['text'];
  }
}
