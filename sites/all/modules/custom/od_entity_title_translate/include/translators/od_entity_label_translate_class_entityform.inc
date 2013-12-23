<?php
/*
 * @file
 *
 * This plugin provides translation of taxonomy term titles.
 * @todo: Also should translate views fields.
 * @todo: Move this to appropriate module or make it universal?
 */


class od_entity_label_translate_class_entityform extends od_entity_label_translate_abstract {
  function on_entity_load() {
    if (arg(0) == 'admin') {
      return;
    }

    $entity_wrapper = entity_metadata_wrapper($this->entity_type, $this->context['entity']);
    if ($entity_wrapper->{'type'}->value() == 'od_preprocess_wizard') {
      $user_wrapper = entity_metadata_wrapper('user', $GLOBALS['user']->uid);
      if ($organization = $user_wrapper->field_organization->value()) {
        $entity_wrapper->field_organization->set($organization);
      }
    }
  }
}