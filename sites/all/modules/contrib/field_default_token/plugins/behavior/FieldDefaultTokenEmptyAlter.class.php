<?php

class FieldDefaultTokenEmptyAlter extends EntityReference_BehaviorHandler_Abstract {

  public function is_empty_alter(&$empty, $item, $field) {
    // If field value contains tokens, entityreference.module treats it as empty.
    if (($empty) && (isset($item['target_id'])) && (strpos($item['target_id'], '[') !== FALSE)) {
      $empty = FALSE;
    }
  }

}
