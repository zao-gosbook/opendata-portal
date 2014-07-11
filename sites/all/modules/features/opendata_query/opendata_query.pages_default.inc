<?php
/**
 * @file
 * opendata_query.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function opendata_query_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'opendata_query';
  $page->task = 'page';
  $page->admin_title = 'Запросы на открытые данные (публичные)';
  $page->admin_description = '';
  $page->path = 'opendata-query';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_opendata_query_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'opendata_query';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.entity-entityform-type h2 {
  display: none;
}
.captcha span.fieldset-legend {
  display: none;
}',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
  );
  $display = new panels_display();
  $display->layout = 'zen_no_wrapper';
  $display->layout_settings = array(
    'main_classes' => '',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Opendata query';
  $display->uuid = '2affb531-04b6-4c02-80f5-3b32e3f9bd2e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c82b4f88-5a5d-4693-80e6-5b1f82950600';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Custom button - Opendata query',
      'title' => '',
      'body' => '<?php 
 $output = \'<div class="pane-btn">\';
 $output .=  l(t(\'Request data\'), \'askopendata\', array(\'attributes\' => array(\'class\' => \'btn\')));
 $output .= \'<div class="additional-info">На этой странице размещаются публичные запросы на добавление данных. Запрос вы можете подать, нажав на кнопку слева, или через специальную форму раздела "Сервисы".</div>\';
 $output .= \'</div>\'; 
 print $output;
?>',
      'format' => 'ds_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'view-organizations',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c82b4f88-5a5d-4693-80e6-5b1f82950600';
    $display->content['new-c82b4f88-5a5d-4693-80e6-5b1f82950600'] = $pane;
    $display->panels['main'][0] = 'new-c82b4f88-5a5d-4693-80e6-5b1f82950600';
    $pane = new stdClass();
    $pane->pid = 'new-e369f381-d0ea-4f43-94fe-42553fda4309';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'opendata_query-pane_opendata_query';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e369f381-d0ea-4f43-94fe-42553fda4309';
    $display->content['new-e369f381-d0ea-4f43-94fe-42553fda4309'] = $pane;
    $display->panels['main'][1] = 'new-e369f381-d0ea-4f43-94fe-42553fda4309';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['opendata_query'] = $page;

  return $pages;

}
