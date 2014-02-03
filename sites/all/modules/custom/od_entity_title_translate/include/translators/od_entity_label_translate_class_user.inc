<?php
/*
 * @file
 *
 * This plugin provides translation of taxonomy term titles.
 * @todo: Also should translate views fields.
 * @todo: Move this to appropriate module or make it universal?
 */


class od_entity_label_translate_class_user extends od_entity_label_translate_abstract {

  /**
   * @fixme Very ugly hack. Should be refactored.
   */
  function on_entity_load() {
    //Don't alter on admin pages
    if (arg(0) == 'admin' || arg(2) =='edit') {
      return;
    }

    //$form = &$this->context['form'];
    $user = $this->context['entity'];
    $wrapper = entity_metadata_wrapper('user', $user);

    foreach ($wrapper->getPropertyInfo() as $property => $info) {
      if (!empty($info['field']) && !empty($user->{$property})) {
        $first_item = reset($user->{$property});
        $user->{$property} = array();
        foreach (array('en', 'ru', LANGUAGE_NONE) as $langcode) {
          $user->{$property}[$langcode] = $first_item;
        }
      }
    }

    return;
  }
}