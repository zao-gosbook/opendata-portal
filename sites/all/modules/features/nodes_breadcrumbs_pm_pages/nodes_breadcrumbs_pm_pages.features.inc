<?php
/**
 * @file
 * nodes_breadcrumbs_pm_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function nodes_breadcrumbs_pm_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  if ($module == "pm_existing_pages" && $api == "pm_existing_pages") {
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

/**
 * Implements hook_workflow_default_workflows().
 */
function nodes_breadcrumbs_pm_pages_workflow_default_workflows() {
  $workflows = array();

  // Exported workflow: Ideas processing
  $workflows['Ideas processing'] = array(
    'name' => 'Ideas processing',
    'tab_roles' => '4,5',
    'options' => 'a:6:{s:13:"name_as_title";s:1:"0";s:8:"schedule";s:1:"0";s:17:"schedule_timezone";s:1:"0";s:16:"comment_log_node";s:1:"0";s:15:"comment_log_tab";s:1:"0";s:12:"watchdog_log";s:1:"1";}',
    '' . "\0" . '*' . "\0" . 'creation_sid' => 1,
    '' . "\0" . '*' . "\0" . 'creation_state' => NULL,
    '' . "\0" . '*' . "\0" . 'item' => NULL,
    'states' => array(
      0 => array(
        'state' => '(creation)',
        'weight' => -50,
        'sysid' => 1,
        'status' => 1,
        'name' => 'Ideas processing',
      ),
      1 => array(
        'state' => 'Новая идея (на модерации)',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Ideas processing',
      ),
      2 => array(
        'state' => 'Одобренная/опубликованная идея (прошла модерацию)',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Ideas processing',
      ),
      3 => array(
        'state' => 'Карантин (не прошла модерацию)',
        'weight' => -20,
        'sysid' => 0,
        'status' => 1,
        'name' => 'Ideas processing',
      ),
    ),
    'transitions' => array(
      0 => array(
        'roles' => 'workflow_features_author_name,анонимный пользователь',
        'state' => '(creation)',
        'target_state' => 'Новая идея (на модерации)',
      ),
      1 => array(
        'roles' => 'moderator,administrator',
        'state' => '(creation)',
        'target_state' => 'Одобренная/опубликованная идея (прошла модерацию)',
      ),
      2 => array(
        'roles' => 'moderator,administrator',
        'state' => '(creation)',
        'target_state' => 'Карантин (не прошла модерацию)',
      ),
      3 => array(
        'roles' => 'moderator,administrator',
        'state' => 'Новая идея (на модерации)',
        'target_state' => 'Одобренная/опубликованная идея (прошла модерацию)',
      ),
      4 => array(
        'roles' => 'moderator,administrator',
        'state' => 'Новая идея (на модерации)',
        'target_state' => 'Карантин (не прошла модерацию)',
      ),
      5 => array(
        'roles' => 'moderator,administrator',
        'state' => 'Одобренная/опубликованная идея (прошла модерацию)',
        'target_state' => 'Карантин (не прошла модерацию)',
      ),
      6 => array(
        'roles' => 'moderator,administrator',
        'state' => 'Карантин (не прошла модерацию)',
        'target_state' => 'Одобренная/опубликованная идея (прошла модерацию)',
      ),
    ),
    'node_types' => array(
      0 => 'idea',
    ),
  );

  return $workflows;
}
