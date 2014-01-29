<?php
/**
 * @file
 */

class ODCommonRulesUI_ef_node_config extends RulesDataUI {
  /**
   * Provides the selection form for a parameter.
   */
  public static function selectionForm($name, $info, $settings, RulesPlugin $element) {
    static $wrapper_id = 'ef-node-config-ajax-wrapper';
    $errors = array(); //Will gather errors
    $main_form = array();
    $main_form['#tree'] = TRUE;
    $main_form['#prefix'] = '<div id="'.$wrapper_id.'">';
    $main_form['#suffix'] = '</div>';

    $ajax_info = array(
      'wrapper' => $wrapper_id,
      'callback' => '_od_common_ef_node_config_ajax_callback',
    );

    $main_form['entityform_type'] = array(
      '#type' => 'select',
      '#title' => t('Entityform type'),
      '#options' => array('' => t('- Select -')),
      '#default_value' => isset($settings['config']['entityform_type']) ? $settings['config']['entityform_type'] : '',
      '#ajax' => $ajax_info + array('event' => 'change'),
    );

    $main_form['node_type'] = array(
      '#type' => 'select',
      '#title' => t('Node type'),
      '#options' => array('' => t('- Select -')) + ($node_types = node_type_get_names()),
      '#default_value' => isset($settings['config']['node_type']) ? $settings['config']['node_type'] : '',
      '#ajax' => $ajax_info + array('event' => 'change'),
    );

    foreach (($ef_types = entityform_get_types()) as $_machine_name => $_ef_type) {
      $main_form['entityform_type']['#options'][$_machine_name] = $_ef_type->label;
    }

    $main_form['field_mappings'] = array();
    $form = &$main_form['field_mappings'];

    if (empty($settings['config']['node_type']) || !isset($node_types[$settings['config']['node_type']])) {
      $errors['node_type'] = t('Please, select correct node type');
    }
    elseif (empty($settings['config']['entityform_type'])) {
      $errors['entityform_type'] = t('Please, select correct entityform type');
    }
    else {
      $ef_wrapper = entity_metadata_wrapper('entityform', $ef_types[$settings['config']['entityform_type']]->id);
      $node_info = entity_get_property_info('node');
      $node_type_info = $node_info['bundles'];

      $node_fields = array();
      foreach ($node_info['bundles'][$settings['config']['node_type']]['properties'] as $_property => $_info) {
        if (!isset($node_fields[$_info['type']])) {
          $node_fields[$_info['type']] = array(
            '' => t('Not mapped'),
          );
        }

        $node_fields[$_info['type']][$_property] = "{$_info['label']} ({$_property})";
      }

      foreach ($ef_wrapper->getPropertyInfo() as $_property => $_info) {
        if (!empty($_info['field']) && isset($node_fields[$_info['type']])) {
          $form[$_property] = array(
            '#type' => 'select',
            '#title' => "{$_info['label']} ({$_property})",
            '#options' => $node_fields[$_info['type']],
            '#default_value' => isset($settings['config']['field_mappings'][$_property]) ? $settings['config']['field_mappings'][$_property] : '',
          );
        }
      }
    }

    if (!empty($errors)) {
      foreach ($errors as $_key => $_error_msg) {
        $main_form['errors'][$_key]['#markup'] = $_error_msg;
      }
    }

    return array('config' => $main_form);
  }

  public static function getDefaultMode() {
    return 'selection';
  }

  public static function render($value) {
    //@todo: Implement this in right way
    return array(
      'content' => array('#markup' => t('@todo: Implement this')),
    );
  }
}

function _od_common_ef_node_config_ajax_callback($form, $form_state) {
  return $form['parameter']['config']['settings']['config'];
}