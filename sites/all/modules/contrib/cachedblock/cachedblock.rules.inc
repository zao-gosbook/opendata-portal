<?php

/**
 * Implements hook_rules_action_info().
 */
function cachedblock_rules_action_info() {
  $items = array();

  $items['cachedblock_rules_clear_cache'] = array(
    'label' => t('Clear block cache'),
    'group' => t('System'),
    'parameter' => array(
      'block' => array(
        'type' => 'token',
        'label' => t('Block'),
        'description' => t('The name of the block to refresh.'),
        'options list' => 'cachedblock_rules_block_options',
        'restriction' => 'input',
      ),
    ),
  );

  return $items;
}

/**
 * Returns options for choosing a block.
 */
function cachedblock_rules_block_options() {
  $blocks = array();

  foreach (_cachedblock_block_list() as $block) {
    $title = '-';
    $info = module_invoke($block->module, 'block_info');
    if (isset($info[$block->delta])) {
      $title = $info[$block->delta]['info'];
    }
    $blocks[$block->module . ':' . $block->delta] = $title;
  }

  return $blocks;
}

/**
 * Action: Clear block cache.
 */
function cachedblock_rules_clear_cache($block) {
  list($module, $delta) = explode(':', $block, 2);
  cachedblock_clear_block_cache($module, $delta);
}
