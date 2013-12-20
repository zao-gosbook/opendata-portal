<?php
/*
 * @file
 *
 * This plugin provides translation of taxonomy term titles.
 * @todo: Also should translate views fields.
 * @todo: Move this to appropriate module or make it universal?
 */


class od_entity_label_translate_class_taxonomy_term extends od_entity_label_translate_abstract {

  function translate($entity) {
    return i18n_taxonomy_term_name($entity, $this->getLangCode());
  }

  function on_entity_view() {
    $this->context['build']['#term']->name = $this->translate($this->context['build']['#term']);
  }

  function on_field_attach_view() {
    $key = key($this->context);
    if (isset($this->context[$key]['#formatter']) && $this->context[$key]['#formatter'] == 'taxonomy_term_reference_link') {
      foreach ($this->context[$key]['#items'] as $delta => $item) {
        $this->context[$key][$delta]['#title'] = 123; //$this->translate($item['taxonomy_term']);
      }
    }
  }
}