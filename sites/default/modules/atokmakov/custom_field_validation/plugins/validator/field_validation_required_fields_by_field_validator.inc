<?php
/**
 * @file
 * Field validation one of several validator.
 *
 */
 
$plugin = array(
  'label' => t('Required fields by field value'),
  'description' => t('Involves filling in these fields if the field has a value.'),
  'handler' => array(
    'class' => 'field_validation_required_fields_by_field_validator',
  ),
);

class field_validation_required_fields_by_field_validator extends field_validation_validator {

  /**
   * Validate field. 
   */
  public function validate() {
  
    ctools_include('export');
    
    $flag = TRUE;
    $error_message = t($this->get_error_message());
   
    $field_values = $this->_get_field_column_value($this->items, $this->rule->col);

    if (count($field_values)) {
      $fields_info = field_info_instances($this->rule->entity_type, $this->rule->bundle);
      foreach ($field_values as $field_value) {
        $field_name = 'validation_fields_require_' . $field_value;
        $fields = (isset($this->rule->settings[$field_name])) ? $this->rule->settings[$field_name] : array();
        foreach ($fields as $field) {
          $field_info = field_info_field($field);
          $func = $field_info['module'] . '_field_is_empty';
          if (function_exists($func)) {
            $field_to_validate = $this->entity->$field;
            foreach($field_to_validate[$this->langcode] as $delta => $item) {
              if ($func($item, $field_info)) {
                $message = field_filter_xss(strtr($error_message, array('[field-name]' => $fields_info[$field]['label'])));
                $error_element = $field . '][' . $this->langcode;
                if (empty($this->rule->settings['errors'])) {
                  form_set_error($error_element, $message);
                }
                else{
                  $this->errors[$this->rule->field_name][$this->langcode][$this->delta][] = array(
                    'error' => $error_element,
                    'message' => $message,
                  );
                }
                $flag = FALSE;
              }
            }
          }
          else {
            watchdog('error', t('Cannot validate required field because @func not exist', array('@func' => $func . '()')));
          }
        }
      }
    }
    return $flag;
  }
  
  /**
   * Provide settings option
   */
  function settings_form(&$form, &$form_state) {
    $default_settings = $this->get_default_settings($form, $form_state);
    
    $fields = field_info_instances($form['entity_type']['#value'], $form['bundle']['#value']);
    if (module_exists('field_group')) {
      $groups = field_group_info_groups($form['entity_type']['#value'], $form['bundle']['#value'],'form');
      $valid_formats = array('tab');
      foreach ($groups as $id => $group) {
        if (!in_array($group->format_type, $valid_formats)) unset($groups[$id]); 
      }
      //dsm($groups);
    }
    $options = array();
    foreach($fields as $key => $field) {
      //dsm($field);
      if ($key != $form['field_name']['#value']) $options[$key] = $field['label'];
    }
    //asort($options);
    
    $this_field = field_info_field($form['field_name']['#value']);
    $values = (isset($this_field['settings']['allowed_values'])) ? array_keys($this_field['settings']['allowed_values']) : array();
    
    foreach ($values as $value) {
      $name = 'validation_fields_require_' . $value;
      $form['settings'][$name] = array(
        '#title' => t('Select required fields when value = @value', array('@value' => $value)),
        '#type' => 'select',
        '#multiple' => TRUE,
        '#options' => $options,
        '#default_value' => isset($default_settings[$name]) ? $default_settings[$name] : array(),
      );

      $name = 'validation_fields_visible_' . $value;    
      $form['settings'][$name] = array(
        '#title' => t('Select visible fields when value = @value', array('@value' => $value)),
        '#type' => 'select',
        '#multiple' => TRUE,
        '#options' => $options,
        '#default_value' => isset($default_settings[$name]) ? $default_settings[$name] : array(),
      );
    }
    
    parent::settings_form($form, $form_state);
  }
  
  /**
   * helper function to get field values
   */
  function _get_field_column_value($items, $column ='value') {
    $field_values = array();
    foreach ($items as $delta => $item) {
      if (isset($item[$column]) && $item[$column] !=='') {
        $field_values[] = $item[$column];
      }
    }
    return $field_values;
  }
}
