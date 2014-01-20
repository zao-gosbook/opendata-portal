<?php

class menu_token_entity_context implements menu_token_handler {
  function form_options($options) {
    // Nothing to do here.
  }

  function form_submit($form, &$form_state) {
    // Nothing to do here.
  }

  function form_validate($form, &$form_state) {
    // Nothing to do here.
  }

  function form_alter(&$form, &$form_state) {
    // Nothing to do here.
  }

  function object_load($options) {
    $entity_type = $options['_type'];
    $entity_info = entity_get_info($entity_type);

    if ($menu_item = menu_get_item()) {
      // Use the first menu argument flagged as loadable for the entity id.
      $id_pos = reset(array_keys($menu_item['load_functions']));
      $entity = entity_load_single($entity_type, arg($id_pos));

      if ($entity) {
        $uri = entity_uri($entity_type, $entity);

        // The first loadable argument might have resulted in an incorrect
        // entity getting loaded. If the loaded entity's path matches at least
        // the initial part of the current URL then it should be correct.
        if (strpos($menu_item['href'], $uri['path']) === 0) {
          return $entity;
        }
      }
    }

    return FALSE;
  }
}
