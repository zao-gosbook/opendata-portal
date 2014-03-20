<?php
/**
 * @file
 * nodes_breadcrumbs_pm_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nodes_breadcrumbs_pm_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function nodes_breadcrumbs_pm_pages_node_info() {
  $items = array(
    'app' => array(
      'name' => t('Приложение'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'competition' => array(
      'name' => t('Конкурс'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название конкурса'),
      'help' => '',
    ),
    'document' => array(
      'name' => t('Документ'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'event' => array(
      'name' => t('Событие'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название'),
      'help' => '',
    ),
    'idea' => array(
      'name' => t('Идея'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название идеи'),
      'help' => '',
    ),
    'news' => array(
      'name' => t('Новость'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
    'organization' => array(
      'name' => t('Организация'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название организации'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Страница'),
      'base' => 'node_content',
      'description' => t('This is a basic page.'),
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
    'potential_organization' => array(
      'name' => t('Потенциальная организация'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Название организации'),
      'help' => '',
    ),
    'publisher_request' => array(
      'name' => t('Заявка на публикаторство'),
      'base' => 'node_content',
      'description' => t('This node type has been created by rules action'),
      'has_title' => '0',
      'title_label' => '',
      'help' => '',
    ),
    'quick_fact' => array(
      'name' => t('Быстрые факты'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Заголовок'),
      'help' => '',
    ),
  );
  return $items;
}
