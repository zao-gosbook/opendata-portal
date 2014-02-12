<?php

/**
 * A generic Entity handler.
 *
 * The generic base implementation has a variety of overrides to workaround
 * core's largely deficient entity handling.
 */
class ODEntityLabelTranslateEntityReference_SelectionHandler_Generic extends EntityReference_SelectionHandler_Generic {

  /**
   * Implements EntityReferenceHandler::getInstance().
   * @inheritdoc
   */
  public static function getInstance($field, $instance = NULL, $entity_type = NULL, $entity = NULL) {
    $target_entity_type = $field['settings']['target_type'];

    // Check if the entity type does exist and has a base table.
    $entity_info = entity_get_info($target_entity_type);
    if (empty($entity_info['base table'])) {
      return EntityReference_SelectionHandler_Broken::getInstance($field, $instance);
    }

    if (class_exists($class_name = 'ODEntityLabelTranslateEntityReference_SelectionHandler_Generic_' . $target_entity_type)) {
      return new $class_name($field, $instance, $entity_type, $entity);
    }
    else {
      return new static($field, $instance, $entity_type, $entity);
    }
  }
}

/**
 * Override for the Taxonomy term type.
 *
 * This only exists to workaround core bugs.
 */
class ODEntityLabelTranslateEntityReference_SelectionHandler_Generic_taxonomy_term extends EntityReference_SelectionHandler_Generic_taxonomy_term {
  /**
   * Overrides EntityReferenceHandler::getReferencableEntities().
   * @inheritdoc
   */
  public function getReferencableEntities($match = NULL, $match_operator = 'CONTAINS', $limit = 0) {
    if ($match || $limit) {
      return parent::getReferencableEntities($match , $match_operator, $limit);
    }

    $options = array();
    $entity_type = $this->field['settings']['target_type'];

    // We imitate core by calling taxonomy_get_tree().
    $entity_info = entity_get_info('taxonomy_term');
    $bundles = !empty($this->field['settings']['handler_settings']['target_bundles']) ? $this->field['settings']['handler_settings']['target_bundles'] : array_keys($entity_info['bundles']);

    foreach ($bundles as $bundle) {
      if ($vocabulary = taxonomy_vocabulary_machine_name_load($bundle)) {
        if ($terms = taxonomy_get_tree($vocabulary->vid, 0)) {
          foreach ($terms as $term) {
            $context = array(
              'entity' => $term,
            );

            od_entity_label_translate_factory::inst()
              ->getTranslator('taxonomy_term', $context)
              ->triggerEvent('pseudo_entity_load');

            $options[$vocabulary->machine_name][$term->tid] = str_repeat('-', $term->depth) . check_plain($term->name);
          }
        }
      }
    }

    return $options;
  }
}
