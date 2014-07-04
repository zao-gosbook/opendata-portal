<?php
/**
 * @file
 * suggestions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function suggestions_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_12';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 11;
  $handler->conf = array(
    'title' => 'Предложение',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.pane-page-title h1 {
  display: none;
}',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Термин таксономии from Содержимое (on Содержимое: Тема [field_suggestion_rubric])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_suggestion_rubric-node-taxonomy_term',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'suggestion' => 'suggestion',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_5',
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 1,
          1 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'idea-content',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'info',
          1 => 'vote',
        ),
        'parent' => 'main',
        'class' => 'idea-row-white',
        'hide_empty' => 0,
      ),
      'info' => array(
        'type' => 'region',
        'title' => 'Info',
        'width' => '80.31584884376763',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'idea-info',
      ),
      'vote' => array(
        'type' => 'region',
        'title' => 'Vote',
        'width' => '19.68415115623237',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'idea-vote',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'info' => NULL,
      'vote' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e7deae03-878f-4b9d-856c-340cfb5db060';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f4025cd3-0606-4842-b244-acee82f27e05';
    $pane->panel = 'center';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
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
    $pane->uuid = 'f4025cd3-0606-4842-b244-acee82f27e05';
    $display->content['new-f4025cd3-0606-4842-b244-acee82f27e05'] = $pane;
    $display->panels['center'][0] = 'new-f4025cd3-0606-4842-b244-acee82f27e05';
    $pane = new stdClass();
    $pane->pid = 'new-973e8b04-d291-458a-a286-4e6c95f4f7e6';
    $pane->panel = 'center';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '50',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '973e8b04-d291-458a-a286-4e6c95f4f7e6';
    $display->content['new-973e8b04-d291-458a-a286-4e6c95f4f7e6'] = $pane;
    $display->panels['center'][1] = 'new-973e8b04-d291-458a-a286-4e6c95f4f7e6';
    $pane = new stdClass();
    $pane->pid = 'new-a6686e9a-36d0-4fc7-9a8a-e430b43af47e';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:field_rubric_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'taxonomy-w-65',
        'image_link' => 'content',
      ),
      'context' => 'relationship_entity_from_field:field_suggestion_rubric-node-taxonomy_term_1',
      'override_title' => 0,
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
    $pane->uuid = 'a6686e9a-36d0-4fc7-9a8a-e430b43af47e';
    $display->content['new-a6686e9a-36d0-4fc7-9a8a-e430b43af47e'] = $pane;
    $display->panels['info'][0] = 'new-a6686e9a-36d0-4fc7-9a8a-e430b43af47e';
    $pane = new stdClass();
    $pane->pid = 'new-c1323212-5cb1-4ec6-8dbd-ea7c3625c299';
    $pane->panel = 'info';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c1323212-5cb1-4ec6-8dbd-ea7c3625c299';
    $display->content['new-c1323212-5cb1-4ec6-8dbd-ea7c3625c299'] = $pane;
    $display->panels['info'][1] = 'new-c1323212-5cb1-4ec6-8dbd-ea7c3625c299';
    $pane = new stdClass();
    $pane->pid = 'new-b3963842-7e76-4043-9052-375ce4bc9688';
    $pane->panel = 'info';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Author:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b3963842-7e76-4043-9052-375ce4bc9688';
    $display->content['new-b3963842-7e76-4043-9052-375ce4bc9688'] = $pane;
    $display->panels['info'][2] = 'new-b3963842-7e76-4043-9052-375ce4bc9688';
    $pane = new stdClass();
    $pane->pid = 'new-f7f6fceb-6245-4d2e-84f6-ce0c60480b2f';
    $pane->panel = 'info';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'comment',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'f7f6fceb-6245-4d2e-84f6-ce0c60480b2f';
    $display->content['new-f7f6fceb-6245-4d2e-84f6-ce0c60480b2f'] = $pane;
    $display->panels['info'][3] = 'new-f7f6fceb-6245-4d2e-84f6-ce0c60480b2f';
    $pane = new stdClass();
    $pane->pid = 'new-c1921ae3-f6f6-479e-a634-6ddc884f588e';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'c1921ae3-f6f6-479e-a634-6ddc884f588e';
    $display->content['new-c1921ae3-f6f6-479e-a634-6ddc884f588e'] = $pane;
    $display->panels['info'][4] = 'new-c1921ae3-f6f6-479e-a634-6ddc884f588e';
    $pane = new stdClass();
    $pane->pid = 'new-5aa9b0de-5e3e-4e50-991c-3d5b80b7e07b';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_suggestion_rubric';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'i18n_taxonomy_term_reference_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '5aa9b0de-5e3e-4e50-991c-3d5b80b7e07b';
    $display->content['new-5aa9b0de-5e3e-4e50-991c-3d5b80b7e07b'] = $pane;
    $display->panels['info'][5] = 'new-5aa9b0de-5e3e-4e50-991c-3d5b80b7e07b';
    $pane = new stdClass();
    $pane->pid = 'new-71bc7372-5147-4476-9a4a-82f001296a17';
    $pane->panel = 'vote';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_suggestion_vote';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
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
    $pane->uuid = '71bc7372-5147-4476-9a4a-82f001296a17';
    $display->content['new-71bc7372-5147-4476-9a4a-82f001296a17'] = $pane;
    $display->panels['vote'][0] = 'new-71bc7372-5147-4476-9a4a-82f001296a17';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_12'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function suggestions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_suggestion';
  $page->task = 'page';
  $page->admin_title = 'Создание предложения для анонимного пользователя';
  $page->admin_description = '';
  $page->path = 'add-suggestion';
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
  $handler->name = 'page_add_suggestion_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'add_suggestion';
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
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '30',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
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
  $display->title = 'Add suggestion';
  $display->uuid = '92144d4d-b645-4734-87c0-aeb20116d975';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9e564140-26ce-435c-bcae-db8471132412';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'entityform_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'context_entity:entityform_type_1',
      'override_title' => 0,
      'override_title_text' => 'ыавыав',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-add-suggestion',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9e564140-26ce-435c-bcae-db8471132412';
    $display->content['new-9e564140-26ce-435c-bcae-db8471132412'] = $pane;
    $display->panels['middle'][0] = 'new-9e564140-26ce-435c-bcae-db8471132412';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_suggestion'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'suggestions';
  $page->task = 'page';
  $page->admin_title = 'Предложения';
  $page->admin_description = '';
  $page->path = 'list-suggestions';
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
  $handler->name = 'page_suggestions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'suggestions';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Предложения',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
  $display->title = 'Suggestions';
  $display->uuid = '326d6b51-534d-41b3-9f77-f2daddd1d247';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7d4739f9-9b83-43ba-9c04-718542d6c4af';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create suggestion content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'CUSTOM LINK (Authorized users)',
      'title' => '',
      'body' => '<?php 
 $output = \'<div class="pane-btn">\';
 $output .=  l(t(\'Add Suggestion\'), \'node/add/suggestion\', array(\'attributes\' => array(\'class\' => \'btn\')));
 $output .= \'<div class="additional-info">Вы можете подать предложение по развитию Портала открытых данных, которое может быть реализовано в рамках модернизации Портала.</div>\';
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
    $pane->uuid = '7d4739f9-9b83-43ba-9c04-718542d6c4af';
    $display->content['new-7d4739f9-9b83-43ba-9c04-718542d6c4af'] = $pane;
    $display->panels['middle'][0] = 'new-7d4739f9-9b83-43ba-9c04-718542d6c4af';
    $pane = new stdClass();
    $pane->pid = 'new-217f3300-2a00-4bba-82ca-06ec1f0b50b5';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'CUSTOM LINK (Anonymous user)',
      'title' => '',
      'body' => '<?php 
 $output = \'<div class="pane-btn">\';
 $output .=  l(t(\'Add Suggestion\'), \'add-suggestion\', array(\'attributes\' => array(\'class\' => \'btn\')));
 $output .= \'<div class="additional-info">Вы можете подать предложение по развитию Портала открытых данных, которое может быть реализовано в рамках модернизации Портала.</div>\';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '217f3300-2a00-4bba-82ca-06ec1f0b50b5';
    $display->content['new-217f3300-2a00-4bba-82ca-06ec1f0b50b5'] = $pane;
    $display->panels['middle'][1] = 'new-217f3300-2a00-4bba-82ca-06ec1f0b50b5';
    $pane = new stdClass();
    $pane->pid = 'new-d92131d9-e577-4d43-b8af-97e026f0cee2';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'suggestions-list_suggestions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd92131d9-e577-4d43-b8af-97e026f0cee2';
    $display->content['new-d92131d9-e577-4d43-b8af-97e026f0cee2'] = $pane;
    $display->panels['middle'][2] = 'new-d92131d9-e577-4d43-b8af-97e026f0cee2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['suggestions'] = $page;

  return $pages;

}
