<?php
/**
 * @file
 * opendata_requests.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function opendata_requests_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_14';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 13;
  $handler->conf = array(
    'title' => 'Запрос на открытые данные',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Заголовок',
        'hidden_field' => 0,
      ),
      'field_od_user_email' => array(
        'override' => 0,
        'label' => 'Email',
        'hidden_field' => 0,
      ),
      'field_od_query_type' => array(
        'override' => 0,
        'label' => 'Your request is',
        'hidden_field' => 0,
      ),
      'field_user_last_name' => array(
        'override' => 0,
        'label' => 'Surname',
        'hidden_field' => 0,
      ),
      'field_user_name' => array(
        'override' => 0,
        'label' => 'Name',
        'hidden_field' => 0,
      ),
      'field_user_middle_name' => array(
        'override' => 0,
        'label' => 'Patronymic',
        'hidden_field' => 0,
      ),
      'field_user_category' => array(
        'override' => 0,
        'label' => 'Categorie',
        'hidden_field' => 0,
      ),
      'field_user_work' => array(
        'override' => 0,
        'label' => 'Place of employment',
        'hidden_field' => 0,
      ),
      'field_user_work_position' => array(
        'override' => 0,
        'label' => 'Position',
        'hidden_field' => 0,
      ),
      'field_od_query_data_name' => array(
        'override' => 0,
        'label' => 'Name of data',
        'hidden_field' => 0,
      ),
      'field_od_query_data_description' => array(
        'override' => 0,
        'label' => 'Description',
        'hidden_field' => 0,
      ),
      'field_od_query_data_holder' => array(
        'override' => 0,
        'label' => 'Who do you think might provide them',
        'hidden_field' => 0,
      ),
      'field_od_query_data_rubrics' => array(
        'override' => 0,
        'label' => 'Which areas include these data',
        'hidden_field' => 0,
      ),
      'field_od_query_data_trouble' => array(
        'override' => 0,
        'label' => 'Do you experience problems with earlier access to these data?',
        'hidden_field' => 0,
      ),
      'field_od_query_data_trbl_reason' => array(
        'override' => 0,
        'label' => 'How would you describe these problems',
        'hidden_field' => 0,
      ),
      'field_od_query_data_trbl_other' => array(
        'override' => 0,
        'label' => 'Enter',
        'hidden_field' => 0,
      ),
      'field_od_query_data_use' => array(
        'override' => 0,
        'label' => 'How are you going to use these data',
        'hidden_field' => 0,
      ),
      'field_od_query_data_use_other' => array(
        'override' => 0,
        'label' => 'Enter',
        'hidden_field' => 0,
      ),
      'field_od_query_data_benefits' => array(
        'override' => 0,
        'label' => 'What benefit do you think will bring the publication of these data',
        'hidden_field' => 0,
      ),
      'field_od_query_data_profit' => array(
        'override' => 0,
        'label' => 'Your assessment of the economic and / or financial benefit from the publication of these data',
        'hidden_field' => 0,
      ),
      'field_od_query_data_organization' => array(
        'override' => 0,
        'label' => 'The organization, which is necessary to place a dataset',
        'hidden_field' => 0,
      ),
      'field_od_query_vote_up_down' => array(
        'override' => 0,
        'label' => 'Голосовать',
        'hidden_field' => 0,
      ),
      'field_notified' => array(
        'override' => 0,
        'label' => 'Кураторам уведомление отправлено',
        'hidden_field' => 2,
      ),
      'field_pubreq_organization_exists' => array(
        'override' => 0,
        'label' => 'Существующая организация',
        'hidden_field' => 2,
      ),
      ':author' => array(
        'override' => 1,
        'label' => 'Информация об авторе',
        'hidden_field' => '1',
      ),
      ':menu' => array(
        'override' => 1,
        'label' => 'Настройки меню',
        'hidden_field' => '1',
      ),
      ':comment_settings' => array(
        'override' => 1,
        'label' => 'Настройки комментариев',
        'hidden_field' => '1',
      ),
      ':path' => array(
        'override' => 1,
        'label' => 'Настройки адресов',
        'hidden_field' => '1',
      ),
      ':options' => array(
        'override' => 1,
        'label' => 'Настройки публикации',
        'hidden_field' => '1',
      ),
      ':revision_information' => array(
        'override' => 1,
        'label' => 'Информация о редакции',
        'hidden_field' => '1',
      ),
      ':redirect' => array(
        'override' => 0,
        'label' => 'URL redirects',
        'hidden_field' => 0,
      ),
      ':flag' => array(
        'override' => 1,
        'label' => 'Флаги',
        'hidden_field' => '1',
      ),
      ':actions:submit' => array(
        'override' => 0,
        'label' => 'Сохранить',
        'hidden_field' => 0,
      ),
      ':actions:preview' => array(
        'override' => 1,
        'label' => 'Предпросмотр',
        'hidden_field' => '1',
      ),
      ':actions:delete' => array(
        'override' => 0,
        'label' => 'Удалить',
        'hidden_field' => 0,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'opendata_query' => 'opendata_query',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
  );
  $export['node_edit_form_mutator_14'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_http_response';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -20;
  $handler->conf = array(
    'title' => 'Запрос на данные (Приватные - 403 Access denied)',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '403',
    'destination' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'opendata_query' => 'opendata_query',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => TRUE,
        ),
        2 => array(
          'name' => 'entity_field_value:node:opendata_query:field_od_query_type',
          'settings' => array(
            'field_od_query_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'private',
                ),
              ),
            ),
            'field_od_query_type_value' => 'private',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_5',
  );
  $export['node_view_http_response'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_11';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -19;
  $handler->conf = array(
    'title' => 'Запрос на данные',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'opendata_query' => 'opendata_query',
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
          2 => 2,
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
        'title' => 'User info',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'query-author-info',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'info',
        ),
        'parent' => 'main',
        'class' => 'opendata-query-info',
        'hide_empty' => 0,
      ),
      'info' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'query-content',
        'hide_empty' => 0,
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'comments',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'comments' => array(
        'type' => 'region',
        'title' => 'Comments',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
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
      'comments' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:field_od_query_data_name';
  $display->uuid = 'e7deae03-878f-4b9d-856c-340cfb5db060';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b86ede93-1c90-4dcf-b5ac-9f3676ca44d4';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_user_email';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'email_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Email:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b86ede93-1c90-4dcf-b5ac-9f3676ca44d4';
    $display->content['new-b86ede93-1c90-4dcf-b5ac-9f3676ca44d4'] = $pane;
    $display->panels['center'][0] = 'new-b86ede93-1c90-4dcf-b5ac-9f3676ca44d4';
    $pane = new stdClass();
    $pane->pid = 'new-8aa1dae7-6b9d-4ba8-a46f-88d6f4304613';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_user_last_name';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Surname:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8aa1dae7-6b9d-4ba8-a46f-88d6f4304613';
    $display->content['new-8aa1dae7-6b9d-4ba8-a46f-88d6f4304613'] = $pane;
    $display->panels['center'][1] = 'new-8aa1dae7-6b9d-4ba8-a46f-88d6f4304613';
    $pane = new stdClass();
    $pane->pid = 'new-4e0145b7-090f-4815-8e90-9643d99cfb79';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_user_name';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Name:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4e0145b7-090f-4815-8e90-9643d99cfb79';
    $display->content['new-4e0145b7-090f-4815-8e90-9643d99cfb79'] = $pane;
    $display->panels['center'][2] = 'new-4e0145b7-090f-4815-8e90-9643d99cfb79';
    $pane = new stdClass();
    $pane->pid = 'new-ce6d6256-78e5-4d0a-86d9-f95dad14fcbe';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_user_middle_name';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Patronymic:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ce6d6256-78e5-4d0a-86d9-f95dad14fcbe';
    $display->content['new-ce6d6256-78e5-4d0a-86d9-f95dad14fcbe'] = $pane;
    $display->panels['center'][3] = 'new-ce6d6256-78e5-4d0a-86d9-f95dad14fcbe';
    $pane = new stdClass();
    $pane->pid = 'new-0bb710f4-aa5d-4f7b-b83d-f45e4c3d8d92';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_user_category';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Categorie:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '0bb710f4-aa5d-4f7b-b83d-f45e4c3d8d92';
    $display->content['new-0bb710f4-aa5d-4f7b-b83d-f45e4c3d8d92'] = $pane;
    $display->panels['center'][4] = 'new-0bb710f4-aa5d-4f7b-b83d-f45e4c3d8d92';
    $pane = new stdClass();
    $pane->pid = 'new-91a762a6-e2ca-422c-84e1-35e37c3e40b6';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_user_work_position';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Position:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '91a762a6-e2ca-422c-84e1-35e37c3e40b6';
    $display->content['new-91a762a6-e2ca-422c-84e1-35e37c3e40b6'] = $pane;
    $display->panels['center'][5] = 'new-91a762a6-e2ca-422c-84e1-35e37c3e40b6';
    $pane = new stdClass();
    $pane->pid = 'new-161af3c4-01e8-4a9a-b18e-5c2555faebd3';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_user_work';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Place of employment:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '161af3c4-01e8-4a9a-b18e-5c2555faebd3';
    $display->content['new-161af3c4-01e8-4a9a-b18e-5c2555faebd3'] = $pane;
    $display->panels['center'][6] = 'new-161af3c4-01e8-4a9a-b18e-5c2555faebd3';
    $pane = new stdClass();
    $pane->pid = 'new-cea8c265-44b1-4cfa-a0dc-0f706d0284e5';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_trouble';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Do you experience problems with earlier access to these data?',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'cea8c265-44b1-4cfa-a0dc-0f706d0284e5';
    $display->content['new-cea8c265-44b1-4cfa-a0dc-0f706d0284e5'] = $pane;
    $display->panels['center'][7] = 'new-cea8c265-44b1-4cfa-a0dc-0f706d0284e5';
    $pane = new stdClass();
    $pane->pid = 'new-3a9017d7-df0c-48af-be1e-2a53311a1f9d';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_trbl_reason';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:opendata_query:field_od_query_data_trbl_reason',
          'settings' => array(
            'field_od_query_data_trbl_reason' => array(
              'und' => array(
                0 => array(
                  'value' => 'other',
                ),
              ),
            ),
            'field_od_query_data_trbl_reason_value' => 'other',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
        1 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'How would you describe these problems',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '3a9017d7-df0c-48af-be1e-2a53311a1f9d';
    $display->content['new-3a9017d7-df0c-48af-be1e-2a53311a1f9d'] = $pane;
    $display->panels['center'][8] = 'new-3a9017d7-df0c-48af-be1e-2a53311a1f9d';
    $pane = new stdClass();
    $pane->pid = 'new-bc4c9450-50cc-4352-924e-36725a519c59';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_trbl_other';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:opendata_query:field_od_query_data_trbl_reason',
          'settings' => array(
            'field_od_query_data_trbl_reason' => array(
              'und' => array(
                0 => array(
                  'value' => 'other',
                ),
              ),
            ),
            'field_od_query_data_trbl_reason_value' => 'other',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'How would you describe these problems:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'bc4c9450-50cc-4352-924e-36725a519c59';
    $display->content['new-bc4c9450-50cc-4352-924e-36725a519c59'] = $pane;
    $display->panels['center'][9] = 'new-bc4c9450-50cc-4352-924e-36725a519c59';
    $pane = new stdClass();
    $pane->pid = 'new-c35c6e02-88f6-4bf0-bce9-1749226c5ebd';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_use';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:opendata_query:field_od_query_data_use',
          'settings' => array(
            'field_od_query_data_use' => array(
              'und' => array(
                0 => array(
                  'value' => 'other_use',
                ),
              ),
            ),
            'field_od_query_data_use_value' => array(
              'other_use' => 'other_use',
              'business' => NULL,
              'personal' => NULL,
              'community' => NULL,
              'research' => NULL,
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
        1 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'i18n_list_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'How are you going to use these data:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = 'c35c6e02-88f6-4bf0-bce9-1749226c5ebd';
    $display->content['new-c35c6e02-88f6-4bf0-bce9-1749226c5ebd'] = $pane;
    $display->panels['center'][10] = 'new-c35c6e02-88f6-4bf0-bce9-1749226c5ebd';
    $pane = new stdClass();
    $pane->pid = 'new-e7b961da-fd8f-4e59-8685-09a6256d92d1';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_use_other';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:opendata_query:field_od_query_data_use',
          'settings' => array(
            'field_od_query_data_use' => array(
              'und' => array(
                0 => array(
                  'value' => 'other_use',
                ),
              ),
            ),
            'field_od_query_data_use_value' => array(
              'other_use' => 'other_use',
              'business' => NULL,
              'personal' => NULL,
              'community' => NULL,
              'research' => NULL,
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'How are you going to use these data:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = 'e7b961da-fd8f-4e59-8685-09a6256d92d1';
    $display->content['new-e7b961da-fd8f-4e59-8685-09a6256d92d1'] = $pane;
    $display->panels['center'][11] = 'new-e7b961da-fd8f-4e59-8685-09a6256d92d1';
    $pane = new stdClass();
    $pane->pid = 'new-3801fd1a-b882-4293-9219-d3f9c4430085';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_benefits';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'What benefit do you think will bring the publication of these data:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $pane->uuid = '3801fd1a-b882-4293-9219-d3f9c4430085';
    $display->content['new-3801fd1a-b882-4293-9219-d3f9c4430085'] = $pane;
    $display->panels['center'][12] = 'new-3801fd1a-b882-4293-9219-d3f9c4430085';
    $pane = new stdClass();
    $pane->pid = 'new-c81508b1-b285-4cd2-b4f2-ee4e8ec0c7ed';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_profit';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'rb_misc_conditions:rules_access_rule_user_is_org_publisher',
          'settings' => array(
            'component_name' => 'rules_access_rule_user_is_org_publisher',
          ),
          'context' => array(
            0 => 'argument_entity_id:node_1',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Your assessment of the economic and/or financial benefit from the publication of these data:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 13;
    $pane->locks = array();
    $pane->uuid = 'c81508b1-b285-4cd2-b4f2-ee4e8ec0c7ed';
    $display->content['new-c81508b1-b285-4cd2-b4f2-ee4e8ec0c7ed'] = $pane;
    $display->panels['center'][13] = 'new-c81508b1-b285-4cd2-b4f2-ee4e8ec0c7ed';
    $pane = new stdClass();
    $pane->pid = 'new-f4025cd3-0606-4842-b244-acee82f27e05';
    $pane->panel = 'comments';
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
    $display->panels['comments'][0] = 'new-f4025cd3-0606-4842-b244-acee82f27e05';
    $pane = new stdClass();
    $pane->pid = 'new-973e8b04-d291-458a-a286-4e6c95f4f7e6';
    $pane->panel = 'comments';
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
    $display->panels['comments'][1] = 'new-973e8b04-d291-458a-a286-4e6c95f4f7e6';
    $pane = new stdClass();
    $pane->pid = 'new-424af062-12a9-4229-86a4-5c32104c94a0';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_vote_up_down';
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
    $pane->uuid = '424af062-12a9-4229-86a4-5c32104c94a0';
    $display->content['new-424af062-12a9-4229-86a4-5c32104c94a0'] = $pane;
    $display->panels['info'][0] = 'new-424af062-12a9-4229-86a4-5c32104c94a0';
    $pane = new stdClass();
    $pane->pid = 'new-ad81b9e5-725c-4a45-bd36-1babf8afedb5';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'ad81b9e5-725c-4a45-bd36-1babf8afedb5';
    $display->content['new-ad81b9e5-725c-4a45-bd36-1babf8afedb5'] = $pane;
    $display->panels['info'][1] = 'new-ad81b9e5-725c-4a45-bd36-1babf8afedb5';
    $pane = new stdClass();
    $pane->pid = 'new-30364027-5744-471a-8c16-f49ec61bbd2f';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Request is:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '30364027-5744-471a-8c16-f49ec61bbd2f';
    $display->content['new-30364027-5744-471a-8c16-f49ec61bbd2f'] = $pane;
    $display->panels['info'][2] = 'new-30364027-5744-471a-8c16-f49ec61bbd2f';
    $pane = new stdClass();
    $pane->pid = 'new-bb3704cd-5c70-451b-ab23-a07d6feecbf8';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_user_category';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Categorie:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'bb3704cd-5c70-451b-ab23-a07d6feecbf8';
    $display->content['new-bb3704cd-5c70-451b-ab23-a07d6feecbf8'] = $pane;
    $display->panels['info'][3] = 'new-bb3704cd-5c70-451b-ab23-a07d6feecbf8';
    $pane = new stdClass();
    $pane->pid = 'new-2abb360d-2557-4374-8ddf-9d6c98bc5eed';
    $pane->panel = 'info';
    $pane->type = 'views_panes';
    $pane->subtype = 'rubric_nodes-query_od_rubrics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Topics:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '2abb360d-2557-4374-8ddf-9d6c98bc5eed';
    $display->content['new-2abb360d-2557-4374-8ddf-9d6c98bc5eed'] = $pane;
    $display->panels['info'][4] = 'new-2abb360d-2557-4374-8ddf-9d6c98bc5eed';
    $pane = new stdClass();
    $pane->pid = 'new-74afa3d1-3285-4071-9e6a-6b9f0f876bad';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_description';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Description:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '74afa3d1-3285-4071-9e6a-6b9f0f876bad';
    $display->content['new-74afa3d1-3285-4071-9e6a-6b9f0f876bad'] = $pane;
    $display->panels['info'][5] = 'new-74afa3d1-3285-4071-9e6a-6b9f0f876bad';
    $pane = new stdClass();
    $pane->pid = 'new-8205de3e-ad49-4db9-af04-8e1d90860f1c';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_holder';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:opendata_query:field_od_query_organiz_exist',
          'settings' => array(
            'field_od_query_organiz_exist' => array(
              'und' => array(
                0 => array(
                  'value' => '0',
                ),
              ),
            ),
            'field_od_query_organiz_exist_value' => '0',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_plain',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Who do you think might provide them:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '8205de3e-ad49-4db9-af04-8e1d90860f1c';
    $display->content['new-8205de3e-ad49-4db9-af04-8e1d90860f1c'] = $pane;
    $display->panels['info'][6] = 'new-8205de3e-ad49-4db9-af04-8e1d90860f1c';
    $pane = new stdClass();
    $pane->pid = 'new-a98c224b-2487-4df1-bcfd-ca91baf1687e';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_od_query_data_organization';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:opendata_query:field_od_query_organiz_exist',
          'settings' => array(
            'field_od_query_organiz_exist' => array(
              'und' => array(
                0 => array(
                  'value' => '1',
                ),
              ),
            ),
            'field_od_query_organiz_exist_value' => '1',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'The organization, which is necessary to place a dataset:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'a98c224b-2487-4df1-bcfd-ca91baf1687e';
    $display->content['new-a98c224b-2487-4df1-bcfd-ca91baf1687e'] = $pane;
    $display->panels['info'][7] = 'new-a98c224b-2487-4df1-bcfd-ca91baf1687e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_11'] = $handler;

  return $export;
}
