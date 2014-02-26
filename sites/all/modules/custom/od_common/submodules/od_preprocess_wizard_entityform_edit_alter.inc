<?php
/**
 * @file
 */

/**
 * Implements hook_preprocess_form_element()
 */
function _od_common_form_od_preprocess_wizard_entityform_edit_preprocess_form_element(&$variables) {
  $old_pos = variable_get('description-popup-position', 0);
  $GLOBALS['conf']['description-popup-position'] = 'suffix';
  _popup_descriptions_apply_popup_description($variables['element']); //Manually add popup description to other position
  $GLOBALS['conf']['description-popup-position'] = $old_pos;
}