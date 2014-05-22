<?php
/**
 * @file
 * analyst_instruments.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function analyst_instruments_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'analyst_requests';
  $page->task = 'page';
  $page->admin_title = 'Запросы для аналитика';
  $page->admin_description = '';
  $page->path = 'user/%user/opendata-queries';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'user/1029/opendata-queries
user/1029',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 5,
            1 => 7,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Пользователь: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_analyst_requests_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'analyst_requests';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Пользователь',
        'keyword' => 'user_2',
        'name' => 'user',
        'type' => 'select',
        'uid' => '1029',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Запросы на открытые данные';
  $display->uuid = 'a2f46b75-9726-4271-9fdc-38448274afe6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d85900c1-8e80-4192-bff9-be3170b0faa3';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'analys_info-analyst_requests';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd85900c1-8e80-4192-bff9-be3170b0faa3';
    $display->content['new-d85900c1-8e80-4192-bff9-be3170b0faa3'] = $pane;
    $display->panels['middle'][0] = 'new-d85900c1-8e80-4192-bff9-be3170b0faa3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['analyst_requests'] = $page;

  return $pages;

}
