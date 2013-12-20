<?php
/*
 * @file
 */

class od_entity_label_translate_class_taxonomy_term extends od_entity_label_translate_abstract {
  function on_entity_view() {
    $this->context['build']['#term']->name = i18n_taxonomy_term_name($this->context['build']['#term'], $this->getLangCode());
  }
}