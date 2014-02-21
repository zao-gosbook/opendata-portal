<?php
/*
 * @file
 *
 * This plugin provides translation of taxonomy term titles.
 * @todo: Also should translate views fields.
 * @todo: Move this to appropriate module or make it universal?
 */


class od_entity_label_translate_class_entityform extends od_entity_label_translate_abstract {
  function setOrganization($entity) {
    if (arg(0) == 'admin') {
      return;
    }

    $entity_wrapper = entity_metadata_wrapper($this->entity_type, $entity);
    if ($entity_wrapper->{'type'}->value() == 'od_preprocess_wizard') {
      $user_wrapper = entity_metadata_wrapper('user', $GLOBALS['user']->uid);
      if ($organization = $user_wrapper->field_organization->value()) {
        $entity_wrapper->field_organization->set($organization);
      }
    }
  }

  //@fixme: organization has been deleted from user, so this doesn't work
  function _on_form_alter() {
    $form = &$this->context['form'];
    $entity = $this->context['form']['#entity'];
    $this->setOrganization($entity);

    $wrapper = entity_metadata_wrapper($this->entity_type, $entity);
    if ($org = $wrapper->field_organization->value()) {
      $form['field_organization'][LANGUAGE_NONE][0]['target_id']['#default_value'] = "{$org->title} ({$org->nid})";
    }
  }
}