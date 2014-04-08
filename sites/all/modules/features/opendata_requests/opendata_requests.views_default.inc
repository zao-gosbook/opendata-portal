<?php
/**
 * @file
 * opendata_requests.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function opendata_requests_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'opendata_query';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Публичные запросы открытых данных';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Nid - Исключено из вывода */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Nid - Исключено из вывода';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Поле: Name of data */
  $handler->display->display_options['fields']['field_od_query_data_name']['id'] = 'field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['table'] = 'field_data_field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['field'] = 'field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_data_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_od_query_data_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_od_query_data_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_data_name']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Поле: Поле: Description */
  $handler->display->display_options['fields']['field_od_query_data_description']['id'] = 'field_od_query_data_description';
  $handler->display->display_options['fields']['field_od_query_data_description']['table'] = 'field_data_field_od_query_data_description';
  $handler->display->display_options['fields']['field_od_query_data_description']['field'] = 'field_od_query_data_description';
  $handler->display->display_options['fields']['field_od_query_data_description']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_data_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_data_description']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Поле: Поле: Who do you think might provide them */
  $handler->display->display_options['fields']['field_od_query_data_holder']['id'] = 'field_od_query_data_holder';
  $handler->display->display_options['fields']['field_od_query_data_holder']['table'] = 'field_data_field_od_query_data_holder';
  $handler->display->display_options['fields']['field_od_query_data_holder']['field'] = 'field_od_query_data_holder';
  $handler->display->display_options['fields']['field_od_query_data_holder']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_data_holder']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_data_holder']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Поле: Поле: Which areas include these data */
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['id'] = 'field_od_query_data_rubrics';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['table'] = 'field_data_field_od_query_data_rubrics';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['field'] = 'field_od_query_data_rubrics';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['delta_offset'] = '0';
  /* Поле: Поле: The organization, which is necessary to place a dataset */
  $handler->display->display_options['fields']['field_od_query_data_organization']['id'] = 'field_od_query_data_organization';
  $handler->display->display_options['fields']['field_od_query_data_organization']['table'] = 'field_data_field_od_query_data_organization';
  $handler->display->display_options['fields']['field_od_query_data_organization']['field'] = 'field_od_query_data_organization';
  $handler->display->display_options['fields']['field_od_query_data_organization']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_data_organization']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_data_organization']['settings'] = array(
    'link' => 0,
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Голосовать */
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['id'] = 'field_od_query_vote_up_down';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['table'] = 'field_data_field_od_query_vote_up_down';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['field'] = 'field_od_query_vote_up_down';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['click_sort_column'] = 'vud_widget';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opendata_query' => 'opendata_query',
  );

  /* Display: Публичные запросы */
  $handler = $view->new_display('panel_pane', 'Публичные запросы', 'pane_opendata_query');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'view-ideas';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Nid - Исключено из вывода */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Nid - Исключено из вывода';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Поле: Which areas include these data */
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['id'] = 'field_od_query_data_rubrics';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['table'] = 'field_data_field_od_query_data_rubrics';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['field'] = 'field_od_query_data_rubrics';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['fields']['field_od_query_data_rubrics']['delta_offset'] = '0';
  /* Поле: Содержимое: Голосовать */
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['id'] = 'field_od_query_vote_up_down';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['table'] = 'field_data_field_od_query_vote_up_down';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['field'] = 'field_od_query_vote_up_down';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['click_sort_column'] = 'vud_widget';
  $handler->display->display_options['fields']['field_od_query_vote_up_down']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Поле: Поле: Name of data */
  $handler->display->display_options['fields']['field_od_query_data_name']['id'] = 'field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['table'] = 'field_data_field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['field'] = 'field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_data_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_od_query_data_name']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_od_query_data_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_data_name']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Поле: Поле: Description */
  $handler->display->display_options['fields']['field_od_query_data_description']['id'] = 'field_od_query_data_description';
  $handler->display->display_options['fields']['field_od_query_data_description']['table'] = 'field_data_field_od_query_data_description';
  $handler->display->display_options['fields']['field_od_query_data_description']['field'] = 'field_od_query_data_description';
  $handler->display->display_options['fields']['field_od_query_data_description']['label'] = '';
  $handler->display->display_options['fields']['field_od_query_data_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_od_query_data_description']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Опубликовано';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opendata_query' => 'opendata_query',
  );
  /* Критерий фильтра: Поле: Your request is (field_od_query_type) */
  $handler->display->display_options['filters']['field_od_query_type_value']['id'] = 'field_od_query_type_value';
  $handler->display->display_options['filters']['field_od_query_type_value']['table'] = 'field_data_field_od_query_type';
  $handler->display->display_options['filters']['field_od_query_type_value']['field'] = 'field_od_query_type_value';
  $handler->display->display_options['filters']['field_od_query_type_value']['value'] = array(
    'public' => 'public',
  );
  $handler->display->display_options['pane_title'] = 'Публичный запрос';
  $handler->display->display_options['pane_description'] = 'Используется на странице - Запросы на данные.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['opendata_query'] = array(
    t('Master'),
    t('ещё'),
    t('Применить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Публичные запросы'),
    t('Опубликовано'),
    t('Публичный запрос'),
    t('Используется на странице - Запросы на данные.'),
    t('Представления-Фрагменты'),
  );
  $export['opendata_query'] = $view;

  return $export;
}
