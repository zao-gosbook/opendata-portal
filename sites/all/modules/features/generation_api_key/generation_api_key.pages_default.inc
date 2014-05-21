<?php
/**
 * @file
 * generation_api_key.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function generation_api_key_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'get_api_key';
  $page->task = 'page';
  $page->admin_title = 'Ключи к API';
  $page->admin_description = '';
  $page->path = 'get-api-key';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_get_api_key_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'get_api_key';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.entity-entityform-type h2 {
  display: none;
}

span.fieldset-legend {
  display: none;
}',
    'contexts' => array(
      0 => array(
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '28',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Get Api Key';
  $display->uuid = '0a78dc00-adeb-43e4-b1ac-23b4461a5a25';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7d186e48-d224-4611-94de-b43a00628f43';
    $pane->panel = 'center';
    $pane->type = 'entity_view';
    $pane->subtype = 'entityform_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'context_entity:entityform_type_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7d186e48-d224-4611-94de-b43a00628f43';
    $display->content['new-7d186e48-d224-4611-94de-b43a00628f43'] = $pane;
    $display->panels['center'][0] = 'new-7d186e48-d224-4611-94de-b43a00628f43';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['get_api_key'] = $page;

  return $pages;

}
