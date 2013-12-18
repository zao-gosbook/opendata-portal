<?php
/*
 * @file
 */

class od_entity_label_translate_class_taxonomy_term extends od_entity_label_translate_class {
  protected $labelProperty = 'name';

  function getTranslatedLabel($entity) {
    return i18n_taxonomy_term_name($entity, $this->getLangCode());
  }
}