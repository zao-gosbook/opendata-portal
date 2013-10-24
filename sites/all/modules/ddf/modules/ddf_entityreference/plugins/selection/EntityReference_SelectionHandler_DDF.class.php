<?php

/**
 * Entity handler for Views.
 */
class EntityReference_SelectionHandler_DDF extends EntityReference_SelectionHandler_Views {

  private static $controlling_field_values = array();

  public static function storeControllingFieldValues($values) {
    self::$controlling_field_values = $values;
  }
  /**
   * Implements EntityReferenceHandler::getInstance().
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    return new EntityReference_SelectionHandler_DDF($field, $instance, $entity_type, $entity);
  }

  protected function __construct($field, $instance, $entity_type, $entity) {
    $this->field = $field;
    $this->instance = $instance;
    $this->entity = $entity;
    // Get the entity token type of the entity type.
    $entity_info = entity_get_info($entity_type);
    $this->entity_type_token = isset($entity_info['token type']) ? $entity_info['token type'] : $entity_type;
  }

  /**
   * Implements EntityReferenceHandler::settingsForm().
   */
  public static function settingsForm($field, $instance) {
    $form = parent::settingsForm($field, $instance);

    if (isset($form['view']['args'])) {
      $master_fields = array();
      $other_instances = field_info_instances($instance['entity_type'], $instance['bundle']);
      foreach ($other_instances as $other_instance) {
        if ($other_instance['field_name'] == $instance['field_name']) {
          continue;
        }
        if (($other_instance['widget']['type'] != 'options_select') && ($other_instance['widget']['type'] != 'options_buttons')) {
          continue;
        }
        $other_field = field_info_field($other_instance['field_name']);
        if ($other_field['cardinality'] != 1) {
          continue;
        }
        if (count($other_field['columns']) != 1) {
          continue;
        }
        $master_fields[$other_instance['field_name']] = htmlspecialchars($other_instance['label']);
      }
      if (!empty($master_fields)) {
        $dynamic_token_list = '';
        foreach ($master_fields as $master_field_name => $master_field_label) {
          $dynamic_token_list .= '<strong>{' . $master_field_name . '}</strong> - ' . $master_field_label . '<br />';
        }
        $form['view']['dynamic_help'] = array(
          '#type' => 'item',
          '#title' => t('Dynamic arguments'),
          '#description' => t('The list of entities that can be referenced can depend on the current values of other fields. When the user changes these fields, the list is rebuilt.'),
          '#markup' => t('The following dynamic tokens can be used as view arguments:') .
            '<br />' . $dynamic_token_list,
        );
      }
    }

    return $form;
  }

  /**
   * Implements EntityReferenceHandler::getReferencableEntities().
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    $display_name = $this->field['settings']['handler_settings']['view']['display_name'];
    $args = $this->handleArgs($this->field['settings']['handler_settings']['view']['args']);
    $args = $this->handleDynamicArgs($args);
    $result = array();
    if ($this->initializeView($match, $match_operator, $limit)) {
      // Get the results.
      $result = $this->view->execute_display($display_name, (!array_filter($args) ? array() : $args));
    }

    $return = array();
    if ($result) {
      $target_type = $this->field['settings']['target_type'];
      $entities = entity_load($target_type, array_keys($result));
      foreach($entities as $entity) {
        list($id,, $bundle) = entity_extract_ids($target_type, $entity);
        $return[$bundle][$id] = $result[$id];
      }
    }
    return $return;
  }

  function validateReferencableEntities(array $ids) {
    $display_name = $this->field['settings']['handler_settings']['view']['display_name'];
    $args = $this->handleArgs($this->field['settings']['handler_settings']['view']['args']);
    $args = $this->handleDynamicArgs($args);
    $result = array();
    if ($this->initializeView(NULL, 'CONTAINS', 0, $ids)) {
      // Get the results.
      $entities = $this->view->execute_display($display_name, $args);
      $result = array_keys($entities);
    }
    return $result;
  }

  /**
   * Handles arguments for views.
   *
   * Replaces tokens using token_replace().
   *
   * @param array $args
   *   Usually $this->field['settings']['handler_settings']['view']['args'].
   *
   * @return array
   *   The arguments to be send to the View.
   */
  protected function handleArgs($args) {
    // Parameters for token_replace().
    $data = array();
    $options = array('clear' => TRUE);

    if ($this->entity) {
      $data = array($this->entity_type_token => $this->entity);
    }
    // Replace tokens for each argument.
    foreach ($args as $key => $arg) {
      $args[$key] = token_replace($arg, $data, $options);
    }
    return $args;
  }

  protected function handleDynamicArgs($args) {
    $dynamic_args = array();
    foreach ($args as $key => $arg) {
      $matches = array();
      if (preg_match('/^\{([^{}]+)\}$/', $arg, $matches)) {
        $dynamic_args[$key] = $matches[1];
      }
    }
    if (empty($dynamic_args)) {
      return $args;
    }
    foreach ($dynamic_args as $key => $field_name) {
      $field = field_info_field($field_name);
      if (!$field) {
        $args[$key] = '';
        continue;
      }
      $columns = $field['columns'];
      if (count($columns) != 1) {
        $args[$key] = '';
        continue;
      }
      $column_names = array_keys($columns);
      $column = $column_names[0];
      if (isset(self::$controlling_field_values[$field_name])) {
        $args[$key] = self::$controlling_field_values[$field_name];
      }
      elseif (isset($this->entity->{$field_name})) {
        foreach ($this->entity->{$field_name} as $values) {
          foreach ($values as $value) {
            $args[$key] = $value[$column];
          }
        }
      }
      else {
        $args[$key] = '';
        $instance = field_info_instance($this->instance['entity_type'], $field_name, $this->instance['bundle']);
        if (!empty($instance['default_value'])) {
          foreach ($instance['default_value'] as $values) {
            foreach ($values as $value) {
              $args[$key] = $value[$column];
            }
          }
        }
      }
    }
    return $args;
  }
}
