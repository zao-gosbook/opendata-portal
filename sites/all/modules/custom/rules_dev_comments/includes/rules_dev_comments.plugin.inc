<?php
/**
 * @file
 * Rules plugin implementation.
 */

class RulesDevComment extends RulesConditionalElement {

  protected $itemName = 'comment';

  public function __construct($settings = array(), $variables = NULL) {
    $this->setUp();
    $this->settings = (array) $settings + array(
      'comment:label' => '',
      'comment:text' => array(),
    );
    if (!empty($variables)) {
      $this->info['variables'] = $variables;
    }
  }
  
  /**
   * Evaluate, whereas by default new vars are visible in the parent's scope.
   */
  public function evaluate(RulesState $state) {
    foreach ($this->children as $action) {
      // Skip evaluation of children since they are commented out!
    }
  }

  /*
   * We provide nothing
   */
  public function providesVariables() {
    return array();
  }

  public function label() {
    $label = isset($this->settings['comment:label']) ? $this->settings['comment:label'] : t('unlabeled comment');
    return $label;
  }
  
  public function buildContent() {
    $content['label'] = array(
      '#markup' => $this->settings['comment:label'],
      '#prefix' => '<div class="rules-element-label">',
      '#suffix' => '</div>',
    );
    $content['text'] = array(
      '#markup' => check_markup($this->settings['comment:text']['value'], $this->settings['comment:text']['format']),
      '#prefix' => '<div class="description">',
      '#suffix' => '</div>',
    );
    $content['#type'] = 'container';
    $content['#is_comment'] = TRUE;
    $content['#attributes'] = array('class' => array('rules-element-content', 'rules-dev-comments'));
    $content['#attached']['css'][] = drupal_get_path('module', 'rules_dev_comments') . '/ui/rules_dev_comments.ui.css';
    return $content;
  }

}
