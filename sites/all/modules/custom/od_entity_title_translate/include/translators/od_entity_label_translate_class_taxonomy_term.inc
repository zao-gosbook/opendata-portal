<?php
/*
 * @file
 *
 * This plugin provides translation of taxonomy term titles.
 * @todo: Also should translate views fields.
 * @todo: Move this to appropriate module or make it universal?
 */


class od_entity_label_translate_class_taxonomy_term extends od_entity_label_translate_abstract {
  function on_entity_view() {
    $this->context['build']['#term']->name = i18n_taxonomy_term_name($this->context['build']['#term'], $this->getLangCode());
  }
}