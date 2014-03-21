<?php
/**
 * @file
 * views_menus_and_rules.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_menus_and_rules_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'apps';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Приложения';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
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
  /* Связь: Содержимое: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Rating */
  $handler->display->display_options['fields']['field_fivestar']['id'] = 'field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['field'] = 'field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['label'] = '';
  $handler->display->display_options['fields']['field_fivestar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fivestar']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_fivestar']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 1,
    'style' => 'average',
    'text' => 'none',
  );
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
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
    'app' => 'app',
  );

  /* Display: Последние приложения */
  $handler = $view->new_display('panel_pane', 'Последние приложения', '10_latests_apps');
  $handler->display->display_options['display_description'] = 'Вывод 10 последних добавленных приложений на странице Приложения';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Автор';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Поле: Содержимое: Rating */
  $handler->display->display_options['fields']['field_fivestar']['id'] = 'field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['field'] = 'field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['label'] = '';
  $handler->display->display_options['fields']['field_fivestar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fivestar']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_fivestar']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 1,
    'style' => 'average',
    'text' => 'none',
  );
  $handler->display->display_options['pane_title'] = 'Последние приложения';
  $handler->display->display_options['pane_description'] = 'Вывод 10 последних добавленных приложений на странице Приложения';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Популярные приложения */
  $handler = $view->new_display('panel_pane', 'Популярные приложения', 'top_rated_apps');
  $handler->display->display_options['display_description'] = 'Вывод 10 самых популярных приложений на странице Приложения';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Автор';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Поле: Содержимое: Rating */
  $handler->display->display_options['fields']['field_fivestar']['id'] = 'field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['field'] = 'field_fivestar';
  $handler->display->display_options['fields']['field_fivestar']['label'] = '';
  $handler->display->display_options['fields']['field_fivestar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fivestar']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_fivestar']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 1,
    'style' => 'average',
    'text' => 'none',
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Rating (field_fivestar:rating) */
  $handler->display->display_options['sorts']['field_fivestar_rating']['id'] = 'field_fivestar_rating';
  $handler->display->display_options['sorts']['field_fivestar_rating']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['sorts']['field_fivestar_rating']['field'] = 'field_fivestar_rating';
  $handler->display->display_options['sorts']['field_fivestar_rating']['order'] = 'DESC';
  $handler->display->display_options['pane_title'] = 'Популярные приложения';
  $handler->display->display_options['pane_description'] = 'Вывод 10 самых популярных приложений на странице Приложения';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: 3 Приложения */
  $handler = $view->new_display('panel_pane', '3 Приложения', 'top_3_apps');
  $handler->display->display_options['display_description'] = 'Вывод 3 самых крутых приложений на странице Приложения';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Поле: Изображение  */
  $handler->display->display_options['fields']['field_app_image']['id'] = 'field_app_image';
  $handler->display->display_options['fields']['field_app_image']['table'] = 'field_data_field_app_image';
  $handler->display->display_options['fields']['field_app_image']['field'] = 'field_app_image';
  $handler->display->display_options['fields']['field_app_image']['label'] = '';
  $handler->display->display_options['fields']['field_app_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_app_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_app_image']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Rating (field_fivestar:rating) */
  $handler->display->display_options['sorts']['field_fivestar_rating']['id'] = 'field_fivestar_rating';
  $handler->display->display_options['sorts']['field_fivestar_rating']['table'] = 'field_data_field_fivestar';
  $handler->display->display_options['sorts']['field_fivestar_rating']['field'] = 'field_fivestar_rating';
  $handler->display->display_options['sorts']['field_fivestar_rating']['order'] = 'DESC';
  $handler->display->display_options['pane_title'] = '3 приложения';
  $handler->display->display_options['pane_description'] = 'Вывод 3 самых крутых приложений на странице Приложения';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['apps'] = array(
    t('Master'),
    t('ещё'),
    t('Отправить'),
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
    t('автор'),
    t('Последние приложения'),
    t('Вывод 10 последних добавленных приложений на странице Приложения'),
    t('Автор'),
    t('Представления-Фрагменты'),
    t('Популярные приложения'),
    t('Вывод 10 самых популярных приложений на странице Приложения'),
    t('3 Приложения'),
    t('Вывод 3 самых крутых приложений на странице Приложения'),
    t('3 приложения'),
  );
  $export['apps'] = $view;

  $view = new view();
  $view->name = 'apps_search_api';
  $view->description = 'Search API';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_apps';
  $view->human_name = 'APPS Search API';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
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
  /* Поле: Indexed Материал: ID материала */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_apps';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';

  /* Display: Приложения */
  $handler = $view->new_display('panel_pane', 'Приложения', 'apps');
  $handler->display->display_options['display_description'] = 'Вывод на странице /apps. Общий список всех приложений.';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: Сводка результатов */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Все приложения (@total)
';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Поиск: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_apps';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['description'] = 'К примеру: Аптеки Москвы, Каток ';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'body:value' => 'body:value',
  );
  $handler->display->display_options['pane_title'] = 'Приложения';
  $handler->display->display_options['pane_description'] = 'Вывод на странице /apps. Общий список всех приложений.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['apps_search_api'] = array(
    t('Master'),
    t('ещё'),
    t('Отправить'),
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
    t('ID материала'),
    t('.'),
    t(','),
    t('Приложения'),
    t('Вывод на странице /apps. Общий список всех приложений.'),
    t('Все приложения (@total)
'),
    t('К примеру: Аптеки Москвы, Каток '),
    t('Представления-Фрагменты'),
  );
  $export['apps_search_api'] = $view;

  $view = new view();
  $view->name = 'blog_user';
  $view->description = 'Используется в профиле пользователя для закладки "Активность"';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Блог пользователя';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Блог';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '350';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
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
    'blog' => 'blog',
  );

  /* Display: Блог для профиля */
  $handler = $view->new_display('panel_pane', 'Блог для профиля', 'list_blogs_user');
  $handler->display->display_options['display_description'] = 'Используется на закладке "Активность" в профиле пользователя';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Нет записей в блоге';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Блог для профиля';
  $handler->display->display_options['pane_description'] = 'Используется на закладке "Активность" в профиле пользователя';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: UID Автора',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['blog_user'] = array(
    t('Master'),
    t('Блог'),
    t('ещё'),
    t('Submit'),
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
    t('Все'),
    t('Блог для профиля'),
    t('Используется на закладке "Активность" в профиле пользователя'),
    t('Нет записей в блоге'),
    t('Представления-Фрагменты'),
  );
  $export['blog_user'] = $view;

  $view = new view();
  $view->name = 'blogs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Blogs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'blog' => 'blog',
  );

  /* Display: Блоги рубрики */
  $handler = $view->new_display('panel_pane', 'Блоги рубрики', 'blogs_list');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Вывод списка блогов в разрезе рубрики на странице типа  /taxonomy/term/%tid/blogs';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Блоги в данной рубрике отсутствуют.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Поле: Рубрика (field_rubric) */
  $handler->display->display_options['arguments']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['arguments']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['arguments']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['arguments']['field_rubric_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_rubric_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Блоги рубрики';
  $handler->display->display_options['pane_description'] = 'Вывод списка блогов в разрезе рубрики на странице типа  /taxonomy/term/%tid/blogs';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'field_rubric_tid' => array(
      'type' => 'user',
      'context' => 'entity:entity_rule_setting.args',
      'context_optional' => 0,
      'panel' => '1',
      'fixed' => '',
      'label' => 'Поле: Рубрика (field_rubric)',
    ),
  );

  /* Display: Блоги */
  $handler = $view->new_display('panel_pane', 'Блоги', 'list_blogs');
  $handler->display->display_options['display_description'] = 'Вывод на странице /blogs';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Блоги отсутствуют.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Связь: Рубрика */
  $handler->display->display_options['relationships']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['relationships']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['ui_name'] = 'Рубрика';
  $handler->display->display_options['relationships']['field_rubric_tid']['label'] = 'Рубрика';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Пользователь: Изображение */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'avatar-85x85';
  /* Поле: Поле: Рубрика */
  $handler->display->display_options['fields']['field_rubric']['id'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['fields']['field_rubric']['field'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['label'] = '';
  $handler->display->display_options['fields']['field_rubric']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rubric']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rubric']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Поле: Термин таксономии: Image */
  $handler->display->display_options['fields']['field_rubric_image']['id'] = 'field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['table'] = 'field_data_field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['field'] = 'field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['relationship'] = 'field_rubric_tid';
  $handler->display->display_options['fields']['field_rubric_image']['label'] = '';
  $handler->display->display_options['fields']['field_rubric_image']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_rubric_image']['alter']['text'] = '<div class=image>[field_rubric_image]</div>[field_rubric]';
  $handler->display->display_options['fields']['field_rubric_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rubric_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_rubric_image']['settings'] = array(
    'image_style' => 'avatar-85x85',
    'image_link' => 'content',
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Пользователь: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '<span class="label">Автор:</span> [name] (<a href="/blog/[uid]">БЛОГ АВТОРА</a>)';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '600';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Блоги';
  $handler->display->display_options['pane_description'] = 'Вывод на странице /blogs';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['blogs'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('Блоги рубрики'),
    t('Вывод списка блогов в разрезе рубрики на странице типа  /taxonomy/term/%tid/blogs'),
    t('Блоги в данной рубрике отсутствуют.'),
    t('Все'),
    t('Представления-Фрагменты'),
    t('Блоги'),
    t('Вывод на странице /blogs'),
    t('Блоги отсутствуют.'),
    t('автор'),
    t('Рубрика'),
    t('<div class=image>[field_rubric_image]</div>[field_rubric]'),
    t('<span class="label">Автор:</span> [name] (<a href="/blog/[uid]">БЛОГ АВТОРА</a>)'),
  );
  $export['blogs'] = $view;

  $view = new view();
  $view->name = 'comments';
  $view->description = 'List and edit site comments and the comment moderation queue.';
  $view->tag = 'admin';
  $view->base_table = 'comment';
  $view->human_name = 'Комментарии';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Комментарии';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'menu';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'subject' => 'subject',
    'name' => 'name',
    'title' => 'title',
    'timestamp' => 'timestamp',
    'edit_comment' => 'edit_comment',
    'delete_comment' => 'edit_comment',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'subject' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_comment' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_comment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* Поведение при отсутствии результатов: Глобальный: Нефильтруемый текст */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Комментарии отсутствуют.';
  /* Связь: Комментарий: Содержимое */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Материал';
  /* Связь: Комментарий: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'comment';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Поле: Массовые операции: Комментарий */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'comment';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::comment_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Опубликовать',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_comment_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::comment_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Снять с публикации',
    ),
    'action::comment_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::comment_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Комментарий: Заголовок */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  /* Поле: Комментарий: Автор */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'comment';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Опубликовано';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '16';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  /* Поле: Комментарий: Дата обновления */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'comment';
  $handler->display->display_options['fields']['timestamp']['field'] = 'changed';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Обновлено';
  $handler->display->display_options['fields']['timestamp']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Поле: Комментарий: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
  $handler->display->display_options['fields']['edit_comment']['label'] = 'Действия';
  /* Поле: Комментарий: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_comment']['id'] = 'delete_comment';
  $handler->display->display_options['fields']['delete_comment']['table'] = 'comment';
  $handler->display->display_options['fields']['delete_comment']['field'] = 'delete_comment';
  $handler->display->display_options['fields']['delete_comment']['label'] = '';
  /* Поле: Комментарий: Одобрено */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'comment';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Статус';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Критерий сортировки: Комментарий: Дата обновления */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'comment';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'changed';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Критерий фильтра: Комментарий: Заголовок */
  $handler->display->display_options['filters']['subject']['id'] = 'subject';
  $handler->display->display_options['filters']['subject']['table'] = 'comment';
  $handler->display->display_options['filters']['subject']['field'] = 'subject';
  $handler->display->display_options['filters']['subject']['operator'] = 'contains';
  $handler->display->display_options['filters']['subject']['group'] = 1;
  $handler->display->display_options['filters']['subject']['exposed'] = TRUE;
  $handler->display->display_options['filters']['subject']['expose']['operator_id'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['label'] = 'Заголовок';
  $handler->display->display_options['filters']['subject']['expose']['operator'] = 'subject_op';
  $handler->display->display_options['filters']['subject']['expose']['identifier'] = 'subject';
  $handler->display->display_options['filters']['subject']['expose']['remember'] = TRUE;
  /* Критерий фильтра: Пользователь: Название */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Автор';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'nid';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Опубликовано';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'nodeTitle';
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Критерий фильтра: Комментарий: Одобрено */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Опубликовано';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quick_fact' => 'quick_fact',
    'document' => 'document',
    'blog' => 'blog',
    'idea' => 'idea',
    'competition' => 'competition',
    'dataset' => 'dataset',
    'news' => 'news',
    'webform' => 'webform',
    'organization' => 'organization',
    'app' => 'app',
    'resource' => 'resource',
    'event' => 'event',
    'forum' => 'forum',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Тип материала';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;

  /* Display: Комментарии */
  $handler = $view->new_display('panel_pane', 'Комментарии', 'comments');
  $handler->display->display_options['display_description'] = 'Вывод в профиле пользователя в закладке "Модерация"';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Комментарий: Одобрено */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Опубликовано';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quick_fact' => 'quick_fact',
    'document' => 'document',
    'blog' => 'blog',
    'idea' => 'idea',
    'competition' => 'competition',
    'dataset' => 'dataset',
    'news' => 'news',
    'webform' => 'webform',
    'organization' => 'organization',
    'app' => 'app',
    'resource' => 'resource',
    'event' => 'event',
    'forum' => 'forum',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Тип материала';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Комментарии';
  $handler->display->display_options['pane_description'] = 'Вывод в профиле пользователя в закладке "Модерация"';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['comments'] = array(
    t('Defaults'),
    t('Комментарии'),
    t('ещё'),
    t('Submit'),
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
    t('Комментарии отсутствуют.'),
    t('Материал'),
    t('автор'),
    t('Заголовок'),
    t('Автор'),
    t('Опубликовано'),
    t('Обновлено'),
    t('Действия'),
    t('Статус'),
    t('Тип материала'),
    t('Вывод в профиле пользователя в закладке "Модерация"'),
    t('Представления-Фрагменты'),
  );
  $export['comments'] = $view;

  $view = new view();
  $view->name = 'competitions_for_rubrics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Конкурсы';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Шапка: Глобальный: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_competition_rubric_target_id']['id'] = 'field_competition_rubric_target_id';
  $handler->display->display_options['relationships']['field_competition_rubric_target_id']['table'] = 'field_data_field_competition_rubric';
  $handler->display->display_options['relationships']['field_competition_rubric_target_id']['field'] = 'field_competition_rubric_target_id';
  $handler->display->display_options['relationships']['field_competition_rubric_target_id']['label'] = 'Рубрика';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_competition_rubric_target_id';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Опубликовано';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'competition' => 'competition',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Тип';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';

  /* Display: Конкурсы рубрики */
  $handler = $view->new_display('panel_pane', 'Конкурсы рубрики', 'competitions_for_rubric');
  $handler->display->display_options['display_description'] = 'Используется в рубрике в разделе Конкурсы';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Конкурсы в данной рубрике отсутствуют.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
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
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'competition' => 'competition',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Тип';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['pane_title'] = 'Конкурсы рубрики';
  $handler->display->display_options['pane_description'] = 'Используется в рубрике в разделе Конкурсы';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'user',
      'context' => 'entity:entity_rule_setting.args',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Термин таксономии: ID термина',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Модерация конкурсов */
  $handler = $view->new_display('panel_pane', 'Модерация конкурсов', 'competitions_for_moderation');
  $handler->display->display_options['display_description'] = 'Вывод конкурсов для модерации (закладка Модерация) в профиле пользователя.';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_bind_user_to_copied_node' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_given_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_next_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'rules_component::rules_pub_resuest' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_on_completion_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_approve_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_reject_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::od_import_import_organizations_opendata' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Обработать конкурс',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'competition::field_competition_status' => 'competition::field_competition_status',
        ),
      ),
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_rules_apply_request' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Одобрить и опубликовать',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Опубликовать',
    ),
    'rules_component::rules_reject_request' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Опубликовано */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Поле: Содержимое: Статус конкурса */
  $handler->display->display_options['fields']['field_competition_status']['id'] = 'field_competition_status';
  $handler->display->display_options['fields']['field_competition_status']['table'] = 'field_data_field_competition_status';
  $handler->display->display_options['fields']['field_competition_status']['field'] = 'field_competition_status';
  $handler->display->display_options['fields']['field_competition_status']['empty'] = 'статус не указан';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
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
    'competition' => 'competition',
  );
  $handler->display->display_options['pane_title'] = 'Модерация конкурсов';
  $handler->display->display_options['pane_description'] = 'Вывод конкурсов для модерации (закладка Модерация) в профиле пользователя.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Конкурсы */
  $handler = $view->new_display('panel_pane', 'Конкурсы', 'competitions');
  $handler->display->display_options['display_description'] = 'Вывод конкурсов на странице /competitions';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Дополнительные настройки',
    ),
    'field_rubric_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Конкурсы в выбранной рубрике отсутствуют.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_competition_rubric_target_id']['id'] = 'field_competition_rubric_target_id';
  $handler->display->display_options['relationships']['field_competition_rubric_target_id']['table'] = 'field_data_field_competition_rubric';
  $handler->display->display_options['relationships']['field_competition_rubric_target_id']['field'] = 'field_competition_rubric_target_id';
  $handler->display->display_options['relationships']['field_competition_rubric_target_id']['label'] = 'Рубрика';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Опубликовано';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'competition' => 'competition',
  );
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Тип';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  /* Критерий фильтра: Поле: Рубрика (field_rubric) */
  $handler->display->display_options['filters']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['filters']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['operator_id'] = 'field_rubric_tid_op';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['label'] = 'Рубрика';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['operator'] = 'field_rubric_tid_op';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['identifier'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_rubric_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rubric_tid']['vocabulary'] = 'rubrics';
  $handler->display->display_options['pane_title'] = 'Конкурсы';
  $handler->display->display_options['pane_description'] = 'Вывод конкурсов на странице /competitions';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['competitions_for_rubrics'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('Рубрика'),
    t('Все'),
    t('Опубликовано'),
    t('Тип'),
    t('Конкурсы рубрики'),
    t('Используется в рубрике в разделе Конкурсы'),
    t('Конкурсы в данной рубрике отсутствуют.'),
    t('Представления-Фрагменты'),
    t('Модерация конкурсов'),
    t('Вывод конкурсов для модерации (закладка Модерация) в профиле пользователя.'),
    t('Отправить'),
    t('Статус конкурса'),
    t('статус не указан'),
    t('Конкурсы'),
    t('Вывод конкурсов на странице /competitions'),
    t('Применить'),
    t('Конкурсы в выбранной рубрике отсутствуют.'),
  );
  $export['competitions_for_rubrics'] = $view;

  $view = new view();
  $view->name = 'content_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_nodes';
  $view->human_name = 'Поиск по материалам';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search';
  /* Шапка: Глобальный: Сводка результатов */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total материалов';
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Поиск не дал результатов. Попробуйте другое ключевое слово.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Поле: Indexed Материал: ID материала */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_nodes';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Критерий фильтра: Поиск: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_nodes';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['description'] = 'Поиск по словам';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'body:value' => 'body:value',
  );

  /* Display: Поиск по материалам */
  $handler = $view->new_display('panel_pane', 'Поиск по материалам', 'content_search');
  $handler->display->display_options['display_description'] = 'Индекс Search Api';
  $handler->display->display_options['pane_title'] = 'Поиск по материлам';
  $handler->display->display_options['pane_description'] = 'Индекс Search Api';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['content_search'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('@total материалов'),
    t('Поиск не дал результатов. Попробуйте другое ключевое слово.'),
    t('ID материала'),
    t('.'),
    t(','),
    t('Поиск по словам'),
    t('Поиск по материалам'),
    t('Индекс Search Api'),
    t('Поиск по материлам'),
    t('Представления-Фрагменты'),
  );
  $export['content_search'] = $view;

  $view = new view();
  $view->name = 'dataset';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Наборы данных';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );

  /* Display: Количество наборов Администратору */
  $handler = $view->new_display('panel_pane', 'Количество наборов Администратору', 'datasets_total_count');
  $handler->display->display_options['display_description'] = 'Вывод в виде блока на главной странице Администратору';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'global $language;
return l($row->nid, \'dataset\');
';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $row->php; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  $handler->display->display_options['pane_title'] = 'Количество наборов Админу';
  $handler->display->display_options['pane_description'] = 'Вывод в виде блока на главной странице Администратору';
  $handler->display->display_options['pane_category']['name'] = '';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'none',
      'context' => 'entity:entity_rule_setting.args',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: UID Автора',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Паспорт */
  $handler = $view->new_display('panel_pane', 'Паспорт', 'passport_dataset');
  $handler->display->display_options['display_description'] = 'Вывод на странице набора данных';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'flipped';
  $handler->display->display_options['style_options']['columns'] = array(
    'nothing' => 'nothing',
    'field_dataset_id' => 'field_dataset_id',
    'title' => 'title',
    'body' => 'body',
    'field_owner' => 'field_owner',
    'field_contact_name' => 'field_contact_name',
    'field_email_responsible' => 'field_email_responsible',
    'view' => 'view',
    'view_1' => 'view_1',
    'view_2' => 'view_2',
    'field_date_first_time_publ' => 'field_date_first_time_publ',
    'field_date_last_change' => 'field_date_last_change',
    'field_content_last_change' => 'field_content_last_change',
    'field_tags' => 'field_tags',
    'nid' => 'nid',
    'vid' => 'vid',
    'view_3' => 'view_3',
    'view_4' => 'view_4',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dataset_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_owner' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_contact_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email_responsible' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_first_time_publ' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date_last_change' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_content_last_change' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_4' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['caption'] = 'Паспорт';
  $handler->display->display_options['style_options']['summary'] = 'Паспорт';
  $handler->display->display_options['style_options']['flipped_table_header_first_field'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Ресурс */
  $handler->display->display_options['relationships']['field_resources_target_id']['id'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['table'] = 'field_data_field_resources';
  $handler->display->display_options['relationships']['field_resources_target_id']['field'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['ui_name'] = 'Ресурс';
  $handler->display->display_options['relationships']['field_resources_target_id']['label'] = 'Ресурс';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'НАЗВАНИЕ ПОЛЯ ПАСПОРТА';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'ЗНАЧЕНИЕ ПОЛЯ ПАСПОРТА';
  /* Поле: Глобальный: Пользовательский текст */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'dc:';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Поле: Поле: Идентификационный номер */
  $handler->display->display_options['fields']['field_dataset_id']['id'] = 'field_dataset_id';
  $handler->display->display_options['fields']['field_dataset_id']['table'] = 'field_data_field_dataset_id';
  $handler->display->display_options['fields']['field_dataset_id']['field'] = 'field_dataset_id';
  $handler->display->display_options['fields']['field_dataset_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dataset_id']['alter']['text'] = '<span property="[nothing_1]identifier">[field_dataset_id]</span>';
  $handler->display->display_options['fields']['field_dataset_id']['empty'] = 'нет информации';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Наименование набора данных';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span property="[nothing_1]title">[title]</span>';
  $handler->display->display_options['fields']['title']['empty'] = 'нет информации';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Описание набора данных';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '<span property="[nothing_1]description">[body]</span>';
  /* Поле: Содержимое: Владелец набора данных */
  $handler->display->display_options['fields']['field_owner']['id'] = 'field_owner';
  $handler->display->display_options['fields']['field_owner']['table'] = 'field_data_field_owner';
  $handler->display->display_options['fields']['field_owner']['field'] = 'field_owner';
  $handler->display->display_options['fields']['field_owner']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_owner']['alter']['text'] = '<span property="[nothing_1]owner">[field_owner]</span>';
  $handler->display->display_options['fields']['field_owner']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_owner']['empty'] = '<span property="[nothing_1]owner">нет информации</span>';
  /* Поле: Поле: Ответственное лицо */
  $handler->display->display_options['fields']['field_contact_name']['id'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['empty'] = 'нет информации';
  /* Поле: Поле: Адрес электронной почты ответственного лица */
  $handler->display->display_options['fields']['field_email_responsible']['id'] = 'field_email_responsible';
  $handler->display->display_options['fields']['field_email_responsible']['table'] = 'field_data_field_email_responsible';
  $handler->display->display_options['fields']['field_email_responsible']['field'] = 'field_email_responsible';
  $handler->display->display_options['fields']['field_email_responsible']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email_responsible']['empty'] = 'нет информации';
  $handler->display->display_options['fields']['field_email_responsible']['type'] = 'email_plain';
  /* Поле: Глобальный: Просмотр */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = 'Гиперссылка (URL) на набор';
  $handler->display->display_options['fields']['view']['empty'] = 'нет информации';
  $handler->display->display_options['fields']['view']['view'] = 'resources';
  $handler->display->display_options['fields']['view']['display'] = 'actual_resource_version';
  $handler->display->display_options['fields']['view']['arguments'] = '!1';
  /* Поле: Глобальный: Просмотр */
  $handler->display->display_options['fields']['view_1']['id'] = 'view_1';
  $handler->display->display_options['fields']['view_1']['table'] = 'views';
  $handler->display->display_options['fields']['view_1']['field'] = 'view';
  $handler->display->display_options['fields']['view_1']['label'] = 'Data format';
  $handler->display->display_options['fields']['view_1']['empty'] = 'нет информации';
  $handler->display->display_options['fields']['view_1']['view'] = 'resources';
  $handler->display->display_options['fields']['view_1']['display'] = 'actual_resource_format';
  $handler->display->display_options['fields']['view_1']['arguments'] = '!1';
  /* Поле: Глобальный: Просмотр */
  $handler->display->display_options['fields']['view_2']['id'] = 'view_2';
  $handler->display->display_options['fields']['view_2']['table'] = 'views';
  $handler->display->display_options['fields']['view_2']['field'] = 'view';
  $handler->display->display_options['fields']['view_2']['label'] = 'Описание структуры набора данных';
  $handler->display->display_options['fields']['view_2']['empty'] = 'информации нет';
  $handler->display->display_options['fields']['view_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['view_2']['view'] = 'resources';
  $handler->display->display_options['fields']['view_2']['display'] = 'actual_resource_structure';
  $handler->display->display_options['fields']['view_2']['arguments'] = '!1';
  /* Поле: Поле: Дата первой публикации набора данных */
  $handler->display->display_options['fields']['field_date_first_time_publ']['id'] = 'field_date_first_time_publ';
  $handler->display->display_options['fields']['field_date_first_time_publ']['table'] = 'field_data_field_date_first_time_publ';
  $handler->display->display_options['fields']['field_date_first_time_publ']['field'] = 'field_date_first_time_publ';
  $handler->display->display_options['fields']['field_date_first_time_publ']['alter']['text'] = '<span property="[nothing_1]created">[field_date_first_time_publ]</span>';
  $handler->display->display_options['fields']['field_date_first_time_publ']['empty'] = 'информации нет';
  $handler->display->display_options['fields']['field_date_first_time_publ']['settings'] = array(
    'format_type' => 'comment',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Поле: Дата последнего внесения изменений */
  $handler->display->display_options['fields']['field_date_last_change']['id'] = 'field_date_last_change';
  $handler->display->display_options['fields']['field_date_last_change']['table'] = 'field_data_field_date_last_change';
  $handler->display->display_options['fields']['field_date_last_change']['field'] = 'field_date_last_change';
  $handler->display->display_options['fields']['field_date_last_change']['empty'] = 'информации нет';
  $handler->display->display_options['fields']['field_date_last_change']['settings'] = array(
    'format_type' => 'comment',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Поле: Дата актуальности набора данных */
  $handler->display->display_options['fields']['field_date_dataset_actual']['id'] = 'field_date_dataset_actual';
  $handler->display->display_options['fields']['field_date_dataset_actual']['table'] = 'field_data_field_date_dataset_actual';
  $handler->display->display_options['fields']['field_date_dataset_actual']['field'] = 'field_date_dataset_actual';
  $handler->display->display_options['fields']['field_date_dataset_actual']['empty'] = 'информации нет';
  $handler->display->display_options['fields']['field_date_dataset_actual']['settings'] = array(
    'format_type' => 'comment',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Содержимое: Периодичность актуализации набора данных */
  $handler->display->display_options['fields']['field_frequency']['id'] = 'field_frequency';
  $handler->display->display_options['fields']['field_frequency']['table'] = 'field_data_field_frequency';
  $handler->display->display_options['fields']['field_frequency']['field'] = 'field_frequency';
  $handler->display->display_options['fields']['field_frequency']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_frequency']['empty'] = 'информации нет';
  /* Поле: Entityform Submission: Содержание последнего изменения */
  $handler->display->display_options['fields']['field_content_last_change']['id'] = 'field_content_last_change';
  $handler->display->display_options['fields']['field_content_last_change']['table'] = 'field_data_field_content_last_change';
  $handler->display->display_options['fields']['field_content_last_change']['field'] = 'field_content_last_change';
  $handler->display->display_options['fields']['field_content_last_change']['empty'] = 'информации нет';
  /* Поле: Поле: Ключевые слова */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_tags']['alter']['text'] = '<span property="[nothing_1]subject">[field_tags]</span>';
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Поле: Редакции материала: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['vid']['exclude'] = TRUE;
  /* Поле: Глобальный: Просмотр */
  $handler->display->display_options['fields']['view_3']['id'] = 'view_3';
  $handler->display->display_options['fields']['view_3']['table'] = 'views';
  $handler->display->display_options['fields']['view_3']['field'] = 'view';
  $handler->display->display_options['fields']['view_3']['label'] = 'Гиперссылки (URL) на версии набора данных ';
  $handler->display->display_options['fields']['view_3']['empty'] = 'информации нет';
  $handler->display->display_options['fields']['view_3']['view'] = 'revisions';
  $handler->display->display_options['fields']['view_3']['display'] = 'versions_datasets';
  $handler->display->display_options['fields']['view_3']['arguments'] = '[%nid]/[%vid]';
  /* Поле: Глобальный: Просмотр */
  $handler->display->display_options['fields']['view_4']['id'] = 'view_4';
  $handler->display->display_options['fields']['view_4']['table'] = 'views';
  $handler->display->display_options['fields']['view_4']['field'] = 'view';
  $handler->display->display_options['fields']['view_4']['label'] = 'Гиперссылки (URL) на версии структуры набора данных';
  $handler->display->display_options['fields']['view_4']['empty'] = 'информации нет';
  $handler->display->display_options['fields']['view_4']['view'] = 'revisions';
  $handler->display->display_options['fields']['view_4']['display'] = 'versions_datasets_structure';
  $handler->display->display_options['fields']['view_4']['arguments'] = '[%nid]/[%vid]';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Паспорт';
  $handler->display->display_options['pane_description'] = 'Вывод на странице набора данных';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: Nid',
    ),
  );

  /* Display: Количество наборов Гостю */
  $handler = $view->new_display('panel_pane', 'Количество наборов Гостю', 'datasets_total_count_for_guest');
  $handler->display->display_options['display_description'] = 'Вывод в виде блока на главной странице';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'global $language;
return l($row->nid, \'dataset\');';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $row->php; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['pane_title'] = 'Количество наборов Гостю';
  $handler->display->display_options['pane_description'] = 'Вывод в виде блока на главной странице для гостя';
  $handler->display->display_options['pane_category']['name'] = '';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'none',
      'context' => 'entity:entity_rule_setting.args',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: UID Автора',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Наборы и Уведомления */
  $handler = $view->new_display('panel_pane', 'Наборы и Уведомления', 'datasets');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Отправленные уведомления';
  $handler->display->display_options['display_description'] = 'Вывод наборов с уведомлениями пользователя с ролью Публикатор/Админ в профиле в закладке "Наборы данных"';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'name' => 'name',
    'field_date_update' => 'field_date_update',
    'field_body' => 'field_body',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_date_update' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: Текстовое поле */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Ссылка на отправку уведомления';
  $handler->display->display_options['header']['area']['content'] = '<a href="/notify">Отправить уведомление</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<a href="/notify">Отправить уведомление</a>

Уведомления отсутствуют.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Организация */
  $handler->display->display_options['relationships']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['relationships']['field_organization_target_id']['field'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['ui_name'] = 'Организация';
  $handler->display->display_options['relationships']['field_organization_target_id']['label'] = 'Организация';
  /* Связь: Кураторы организации */
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['id'] = 'field_organization_curators_target_id';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['table'] = 'field_data_field_organization_curators';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['field'] = 'field_organization_curators_target_id';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['ui_name'] = 'Кураторы организации';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['label'] = 'Кураторы организации';
  /* Связь: Уведомление */
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['id'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['field'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['ui_name'] = 'Уведомление';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['label'] = 'Уведомление';
  /* Связь: Автор уведомления */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'entityform';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['relationship'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['relationships']['user']['ui_name'] = 'Автор уведомления';
  $handler->display->display_options['relationships']['user']['label'] = 'Автор уведомления';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'Автор уведомления';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Поле: Поле: Дата внесения изменений */
  $handler->display->display_options['fields']['field_date_update']['id'] = 'field_date_update';
  $handler->display->display_options['fields']['field_date_update']['table'] = 'field_data_field_date_update';
  $handler->display->display_options['fields']['field_date_update']['field'] = 'field_date_update';
  $handler->display->display_options['fields']['field_date_update']['relationship'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['fields']['field_date_update']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Поле: Сообщение */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['relationship'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['fields']['field_body']['label'] = 'Текст уведомления';
  /* Поле: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['fields']['created']['label'] = 'Дата отправки уведомления';
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Entityform Submission: Date submitted */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Пользователь: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_organization_curators_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['exception']['value'] = '1';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Наборы публикатора';
  $handler->display->display_options['pane_description'] = 'Вывод наборов с уведомлениями пользователя с ролью Публикатор/Админ в профиле в закладке "Наборы данных"';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Пользователь: Uid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Информация об изменениях */
  $handler = $view->new_display('panel_pane', 'Информация об изменениях', 'dataset_changes_info');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Информация об изменениях';
  $handler->display->display_options['display_description'] = 'Вывод последнего уведомления о планируемых изменениях в наборе данных. Вывод на странице набора';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Информация отсутствует';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Уведомления */
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['id'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['field'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['ui_name'] = 'Уведомления';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['label'] = 'Уведомления';
  $handler->display->display_options['relationships']['reverse_field_dataset_entityform']['required'] = TRUE;
  /* Связь: Автор уведомления */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'entityform';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['relationship'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['relationships']['user']['ui_name'] = 'Автор уведомления';
  $handler->display->display_options['relationships']['user']['label'] = 'Автор уведомления';
  $handler->display->display_options['relationships']['user']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Поле: Сообщение */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['relationship'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['fields']['field_body']['label'] = '';
  $handler->display->display_options['fields']['field_body']['element_label_colon'] = FALSE;
  /* Поле: Поле: Дата внесения изменений */
  $handler->display->display_options['fields']['field_date_update']['id'] = 'field_date_update';
  $handler->display->display_options['fields']['field_date_update']['table'] = 'field_data_field_date_update';
  $handler->display->display_options['fields']['field_date_update']['field'] = 'field_date_update';
  $handler->display->display_options['fields']['field_date_update']['relationship'] = 'reverse_field_dataset_entityform';
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'Автор уведомления';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Entityform Submission: Date submitted */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['relationship'] = 'reverse_field_dataset_entityform';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Информация об изменениях';
  $handler->display->display_options['pane_description'] = 'Вывод последнего уведомления о планируемых изменениях в наборе данных. Вывод на странице набора';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Последние добавленные наборы */
  $handler = $view->new_display('panel_pane', 'Последние добавленные наборы', 'activity_datasets');
  $handler->display->display_options['display_description'] = 'Вывод в профиле пользователя с ролью Публикатора в разделе Активность последних добавленных наборов. ';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    6 => '6',
  );
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: Сводка результатов */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Наборов добавлено: @total';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Пользователь не добавил ни одного набора открытых данных.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Последние добавленные наборы';
  $handler->display->display_options['pane_description'] = 'Вывод в профиле пользователя с ролью Публикатора в разделе Активность последних добавленных наборов. ';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: UID Автора',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Модерация наборов */
  $handler = $view->new_display('panel_pane', 'Модерация наборов', 'recommended_datasets');
  $handler->display->display_options['display_description'] = 'Вывод на странице Модерации в профиле пользователя. ';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'field_dataset_standard' => 'field_dataset_standard',
    'status' => 'status',
    'created' => 'created',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_dataset_standard' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-center',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Результатов нет';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_bind_user_to_copied_node' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_given_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_next_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'rules_component::rules_pub_resuest' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_on_completion_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_approve_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_reject_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_dataset_is_recommended' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::od_import_import_organizations_opendata' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Изменить значение поля Эталон',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'dataset::field_dataset_standard' => 'dataset::field_dataset_standard',
        ),
      ),
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_rules_apply_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Опубликовать',
    ),
    'rules_component::rules_reject_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Снять с публикации',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_dataset_isnt_recommended' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название наборе';
  /* Поле: Содержимое: Рекомендовано */
  $handler->display->display_options['fields']['field_dataset_standard']['id'] = 'field_dataset_standard';
  $handler->display->display_options['fields']['field_dataset_standard']['table'] = 'field_data_field_dataset_standard';
  $handler->display->display_options['fields']['field_dataset_standard']['field'] = 'field_dataset_standard';
  $handler->display->display_options['fields']['field_dataset_standard']['label'] = 'Находится в блоке Рекомендуемые';
  $handler->display->display_options['fields']['field_dataset_standard']['empty'] = 'Значение отсутствует';
  /* Поле: Содержимое: Опубликовано */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Критерий фильтра: Поле: Рубрика (field_rubric) */
  $handler->display->display_options['filters']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['filters']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['operator_id'] = 'field_rubric_tid_op';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['label'] = 'Рубрика';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['operator'] = 'field_rubric_tid_op';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['identifier'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_rubric_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rubric_tid']['vocabulary'] = 'rubrics';
  /* Критерий фильтра: Глобальный: Фильтр комбинированных полей */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Название';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
  );
  /* Критерий фильтра: Содержимое: Рекомендовано (field_dataset_standard) */
  $handler->display->display_options['filters']['field_dataset_standard_value']['id'] = 'field_dataset_standard_value';
  $handler->display->display_options['filters']['field_dataset_standard_value']['table'] = 'field_data_field_dataset_standard';
  $handler->display->display_options['filters']['field_dataset_standard_value']['field'] = 'field_dataset_standard_value';
  $handler->display->display_options['filters']['field_dataset_standard_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_dataset_standard_value']['expose']['operator_id'] = 'field_dataset_standard_value_op';
  $handler->display->display_options['filters']['field_dataset_standard_value']['expose']['label'] = 'Рекомендован';
  $handler->display->display_options['filters']['field_dataset_standard_value']['expose']['operator'] = 'field_dataset_standard_value_op';
  $handler->display->display_options['filters']['field_dataset_standard_value']['expose']['identifier'] = 'field_dataset_standard_value';
  $handler->display->display_options['filters']['field_dataset_standard_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Опубликовано';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['pane_title'] = 'Модерация наборов';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Модерации в профиле пользователя. ';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Рекомендуемые наборы */
  $handler = $view->new_display('block', 'Рекомендуемые наборы', 'standard_datasets');
  $handler->display->display_options['display_description'] = 'Выводе в блоке на странице наборы данных /datasets';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата обновления */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Критерий фильтра: Содержимое: Рекомендовано (field_dataset_standard) */
  $handler->display->display_options['filters']['field_dataset_standard_value']['id'] = 'field_dataset_standard_value';
  $handler->display->display_options['filters']['field_dataset_standard_value']['table'] = 'field_data_field_dataset_standard';
  $handler->display->display_options['filters']['field_dataset_standard_value']['field'] = 'field_dataset_standard_value';
  $handler->display->display_options['filters']['field_dataset_standard_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Рекомендуемые наборы';

  /* Display: Export CSV */
  $handler = $view->new_display('views_data_export', 'Export CSV', 'export_csv');
  $handler->display->display_options['display_description'] = 'Экпорт реестра набора данных в csv формате';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['separator'] = ';';
  $handler->display->display_options['style_options']['quote'] = 0;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Глобальный: Счетчик результатов */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '№';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название набора данных';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Ссылка на набора данных';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print url(\'node/\'. $row->nid, array(\'absolute\' => TRUE));
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'export-csv';

  /* Display: Export XLS */
  $handler = $view->new_display('views_data_export', 'Export XLS', 'export_xls');
  $handler->display->display_options['display_description'] = 'Экпорт реестра набора данных в XLS формате';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Поле: Глобальный: Счетчик результатов */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '№';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название набора данных';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Глобальный: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Ссылка на набора данных';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
print url(\'node/\'. $row->nid, array(\'absolute\' => TRUE));
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'export-xls';
  $translatables['dataset'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('Количество наборов Администратору'),
    t('Вывод в виде блока на главной странице Администратору'),
    t('Количество наборов Админу'),
    t('Паспорт'),
    t('Вывод на странице набора данных'),
    t('Ресурс'),
    t('НАЗВАНИЕ ПОЛЯ ПАСПОРТА'),
    t('ЗНАЧЕНИЕ ПОЛЯ ПАСПОРТА'),
    t('dc:'),
    t('Идентификационный номер'),
    t('<span property="[nothing_1]identifier">[field_dataset_id]</span>'),
    t('нет информации'),
    t('Наименование набора данных'),
    t('<span property="[nothing_1]title">[title]</span>'),
    t('Описание набора данных'),
    t('<span property="[nothing_1]description">[body]</span>'),
    t('Владелец набора данных'),
    t('<span property="[nothing_1]owner">[field_owner]</span>'),
    t('<span property="[nothing_1]owner">нет информации</span>'),
    t('Ответственное лицо'),
    t('Адрес электронной почты ответственного лица'),
    t('Гиперссылка (URL) на набор'),
    t('Data format'),
    t('Описание структуры набора данных'),
    t('информации нет'),
    t('Дата первой публикации набора данных'),
    t('<span property="[nothing_1]created">[field_date_first_time_publ]</span>'),
    t('Дата последнего внесения изменений'),
    t('Дата актуальности набора данных'),
    t('Периодичность актуализации набора данных'),
    t('Содержание последнего изменения'),
    t('Ключевые слова'),
    t('<span property="[nothing_1]subject">[field_tags]</span>'),
    t('Nid'),
    t('Vid'),
    t('Гиперссылки (URL) на версии набора данных '),
    t('Гиперссылки (URL) на версии структуры набора данных'),
    t('Все'),
    t('Представления-Фрагменты'),
    t('Количество наборов Гостю'),
    t('Вывод в виде блока на главной странице'),
    t('Вывод в виде блока на главной странице для гостя'),
    t('Наборы и Уведомления'),
    t('Отправленные уведомления'),
    t('Вывод наборов с уведомлениями пользователя с ролью Публикатор/Админ в профиле в закладке "Наборы данных"'),
    t('Ссылка на отправку уведомления'),
    t('<a href="/notify">Отправить уведомление</a>'),
    t('<a href="/notify">Отправить уведомление</a>

Уведомления отсутствуют.'),
    t('Организация'),
    t('Кураторы организации'),
    t('Уведомление'),
    t('Автор уведомления'),
    t('Дата внесения изменений'),
    t('Текст уведомления'),
    t('Дата отправки уведомления'),
    t('Наборы публикатора'),
    t('Информация об изменениях'),
    t('Вывод последнего уведомления о планируемых изменениях в наборе данных. Вывод на странице набора'),
    t('Информация отсутствует'),
    t('Уведомления'),
    t('Последние добавленные наборы'),
    t('Вывод в профиле пользователя с ролью Публикатора в разделе Активность последних добавленных наборов. '),
    t('Наборов добавлено: @total'),
    t('Пользователь не добавил ни одного набора открытых данных.'),
    t('Модерация наборов'),
    t('Вывод на странице Модерации в профиле пользователя. '),
    t('Результатов нет'),
    t('Название наборе'),
    t('Находится в блоке Рекомендуемые'),
    t('Значение отсутствует'),
    t('Опубликовано'),
    t('Дата публикации'),
    t('Рубрика'),
    t('Название'),
    t('Рекомендован'),
    t('Рекомендуемые наборы'),
    t('Выводе в блоке на странице наборы данных /datasets'),
    t('Export CSV'),
    t('Экпорт реестра набора данных в csv формате'),
    t('№'),
    t('Название набора данных'),
    t('Ссылка на набора данных'),
    t('Export XLS'),
    t('Экпорт реестра набора данных в XLS формате'),
  );
  $export['dataset'] = $view;

  $view = new view();
  $view->name = 'datasets_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Карта открытых данных';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'ip_geoloc_map';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'title',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_latitude'] = 'field_geolocation';
  $handler->display->display_options['style_options']['ip_geoloc_views_plugin_longitude'] = 'field_geolocation';
  $handler->display->display_options['style_options']['differentiator']['differentiator_field'] = 'node_title_1';
  $handler->display->display_options['style_options']['default_marker_color'] = 'red+dot';
  $handler->display->display_options['style_options']['center_option'] = '1';
  $handler->display->display_options['style_options']['gps_roles'] = array(
    1 => '1',
    2 => '2',
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['style_options']['map_options'] = '{"zoom":10}';
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['relationships']['field_organization_target_id']['field'] = 'field_organization_target_id';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Адрес */
  $handler->display->display_options['fields']['field_geolocation']['id'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['field'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['fields']['field_geolocation']['label'] = '';
  $handler->display->display_options['fields']['field_geolocation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_geolocation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation']['click_sort_column'] = 'lat';
  $handler->display->display_options['fields']['field_geolocation']['settings'] = array(
    'map_width' => '300px',
    'map_height' => '300px',
    'marker_icon' => '',
    'map_scrollwheel' => 0,
    'map_maptype' => 'roadmap',
    'map_zoomlevel' => '7',
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Контекстный фильтр: Поле: Рубрика (field_rubric) */
  $handler->display->display_options['arguments']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['arguments']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['arguments']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['arguments']['field_rubric_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_rubric_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';

  /* Display: Карта Google Рубрики */
  $handler = $view->new_display('panel_pane', 'Карта Google Рубрики', 'rubric_map');
  $handler->display->display_options['display_description'] = 'Вывод карты в разделе Карты определенной рубрики';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Наборы для рубрики "%1" отсутствуют';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Рубрика */
  $handler->display->display_options['relationships']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['relationships']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['ui_name'] = 'Рубрика';
  $handler->display->display_options['relationships']['field_rubric_tid']['label'] = 'Рубрика';
  /* Связь: Организация */
  $handler->display->display_options['relationships']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['relationships']['field_organization_target_id']['field'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['ui_name'] = 'Организация';
  $handler->display->display_options['relationships']['field_organization_target_id']['label'] = 'Организация';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Адрес */
  $handler->display->display_options['fields']['field_geolocation']['id'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['field'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['fields']['field_geolocation']['label'] = '';
  $handler->display->display_options['fields']['field_geolocation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_geolocation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation']['click_sort_column'] = 'lat';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_rubric_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Карта Google Рубрики';
  $handler->display->display_options['pane_description'] = 'Вывод карты в разделе Карты определенной рубрики';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Термин таксономии: ID термина',
    ),
  );

  /* Display: Карта Google */
  $handler = $view->new_display('panel_pane', 'Карта Google', 'google_map');
  $handler->display->display_options['display_description'] = 'Вывод карты в разделе Карты';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Дополнительные настройки',
    ),
    'field_organization_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'field_geolocation_distance' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Наборы отсутствуют. Попробуйте еще раз.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Рубрика */
  $handler->display->display_options['relationships']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['relationships']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['ui_name'] = 'Рубрика';
  $handler->display->display_options['relationships']['field_rubric_tid']['label'] = 'Рубрика';
  /* Связь: Организация */
  $handler->display->display_options['relationships']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['relationships']['field_organization_target_id']['field'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['ui_name'] = 'Организация';
  $handler->display->display_options['relationships']['field_organization_target_id']['label'] = 'Организация';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Адрес */
  $handler->display->display_options['fields']['field_geolocation']['id'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['field'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['fields']['field_geolocation']['label'] = '';
  $handler->display->display_options['fields']['field_geolocation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_geolocation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation']['click_sort_column'] = 'lat';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Критерий фильтра: Поле: Владелец набора данных (field_organization) */
  $handler->display->display_options['filters']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['filters']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['filters']['field_organization_target_id']['field'] = 'field_organization_target_id';
  $handler->display->display_options['filters']['field_organization_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_organization_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_target_id']['expose']['operator_id'] = 'field_organization_target_id_op';
  $handler->display->display_options['filters']['field_organization_target_id']['expose']['label'] = 'Организация владелец набора:
';
  $handler->display->display_options['filters']['field_organization_target_id']['expose']['operator'] = 'field_organization_target_id_op';
  $handler->display->display_options['filters']['field_organization_target_id']['expose']['identifier'] = 'field_organization_target_id';
  $handler->display->display_options['filters']['field_organization_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Критерий фильтра: Geolocation: Distance */
  $handler->display->display_options['filters']['field_geolocation_distance']['id'] = 'field_geolocation_distance';
  $handler->display->display_options['filters']['field_geolocation_distance']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['filters']['field_geolocation_distance']['field'] = 'field_geolocation_distance';
  $handler->display->display_options['filters']['field_geolocation_distance']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['filters']['field_geolocation_distance']['value'] = array(
    'latitude' => '',
    'longitude' => '',
    'search_distance' => '100',
    'search_units' => 'kilometers',
    'type' => 'googlemap',
  );
  $handler->display->display_options['filters']['field_geolocation_distance']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_geolocation_distance']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_geolocation_distance']['expose']['operator'] = 'field_geolocation_distance_op';
  $handler->display->display_options['filters']['field_geolocation_distance']['expose']['identifier'] = 'field_geolocation_distance';
  $handler->display->display_options['filters']['field_geolocation_distance']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['pane_title'] = 'Карта Google';
  $handler->display->display_options['pane_description'] = 'Вывод карты в разделе Карты';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Термин таксономии: ID термина',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['datasets_map'] = array(
    t('Master'),
    t('ещё'),
    t('Отправить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Сущность Содержимое связана через поле field_organization'),
    t('Все'),
    t('Карта Google Рубрики'),
    t('Вывод карты в разделе Карты определенной рубрики'),
    t('Наборы для рубрики "%1" отсутствуют'),
    t('Рубрика'),
    t('Организация'),
    t('Представления-Фрагменты'),
    t('Карта Google'),
    t('Вывод карты в разделе Карты'),
    t('Применить'),
    t('Наборы отсутствуют. Попробуйте еще раз.'),
    t('Организация владелец набора:
'),
  );
  $export['datasets_map'] = $view;

  $view = new view();
  $view->name = 'datasets_rest';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Datasets REST';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'datasets';
  $handler->display->display_options['style_options']['top_child_object'] = 'dataset';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 1;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['relationships']['field_organization_target_id']['field'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['label'] = 'Организация';
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resources_target_id']['id'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['table'] = 'field_data_field_resources';
  $handler->display->display_options['relationships']['field_resources_target_id']['field'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['label'] = 'Ресурс';
  /* Связь: Поле: Ключевые слова (field_tags) */
  $handler->display->display_options['relationships']['field_tags_tid']['id'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['table'] = 'field_data_field_tags';
  $handler->display->display_options['relationships']['field_tags_tid']['field'] = 'field_tags_tid';
  $handler->display->display_options['relationships']['field_tags_tid']['label'] = 'Ключевые слова';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'название';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Содержимое: Материал UUID */
  $handler->display->display_options['fields']['uuid']['id'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['table'] = 'node';
  $handler->display->display_options['fields']['uuid']['field'] = 'uuid';
  $handler->display->display_options['fields']['uuid']['label'] = '';
  $handler->display->display_options['fields']['uuid']['element_type'] = '0';
  $handler->display->display_options['fields']['uuid']['element_label_type'] = '0';
  $handler->display->display_options['fields']['uuid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uuid']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['uuid']['element_default_classes'] = FALSE;
  /* Поле: Содержимое: Путь */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'uri';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Поле: Поле: Дата первой публикации набора данных */
  $handler->display->display_options['fields']['field_date_first_time_publ']['id'] = 'field_date_first_time_publ';
  $handler->display->display_options['fields']['field_date_first_time_publ']['table'] = 'field_data_field_date_first_time_publ';
  $handler->display->display_options['fields']['field_date_first_time_publ']['field'] = 'field_date_first_time_publ';
  $handler->display->display_options['fields']['field_date_first_time_publ']['label'] = 'first_time_publ';
  $handler->display->display_options['fields']['field_date_first_time_publ']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date_first_time_publ']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_date_first_time_publ']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_first_time_publ']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_date_first_time_publ']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_first_time_publ']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date_first_time_publ']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Поле: Дата последнего внесения изменений */
  $handler->display->display_options['fields']['field_date_last_change']['id'] = 'field_date_last_change';
  $handler->display->display_options['fields']['field_date_last_change']['table'] = 'field_data_field_date_last_change';
  $handler->display->display_options['fields']['field_date_last_change']['field'] = 'field_date_last_change';
  $handler->display->display_options['fields']['field_date_last_change']['label'] = 'last_change';
  $handler->display->display_options['fields']['field_date_last_change']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date_last_change']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_date_last_change']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_last_change']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_date_last_change']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_last_change']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date_last_change']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Entityform Submission: Содержание последнего изменения */
  $handler->display->display_options['fields']['field_content_last_change']['id'] = 'field_content_last_change';
  $handler->display->display_options['fields']['field_content_last_change']['table'] = 'field_data_field_content_last_change';
  $handler->display->display_options['fields']['field_content_last_change']['field'] = 'field_content_last_change';
  $handler->display->display_options['fields']['field_content_last_change']['label'] = 'last_change_description';
  $handler->display->display_options['fields']['field_content_last_change']['element_type'] = '0';
  $handler->display->display_options['fields']['field_content_last_change']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_content_last_change']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_content_last_change']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_content_last_change']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_content_last_change']['type'] = 'text_plain';
  /* Поле: Поле: Дата актуальности набора данных */
  $handler->display->display_options['fields']['field_date_dataset_actual']['id'] = 'field_date_dataset_actual';
  $handler->display->display_options['fields']['field_date_dataset_actual']['table'] = 'field_data_field_date_dataset_actual';
  $handler->display->display_options['fields']['field_date_dataset_actual']['field'] = 'field_date_dataset_actual';
  $handler->display->display_options['fields']['field_date_dataset_actual']['label'] = 'dataset_actual';
  $handler->display->display_options['fields']['field_date_dataset_actual']['element_type'] = '0';
  $handler->display->display_options['fields']['field_date_dataset_actual']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_date_dataset_actual']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_date_dataset_actual']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_date_dataset_actual']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_date_dataset_actual']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_date_dataset_actual']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Поле: Содержимое: Периодичность актуализации набора данных */
  $handler->display->display_options['fields']['field_frequency']['id'] = 'field_frequency';
  $handler->display->display_options['fields']['field_frequency']['table'] = 'field_data_field_frequency';
  $handler->display->display_options['fields']['field_frequency']['field'] = 'field_frequency';
  $handler->display->display_options['fields']['field_frequency']['label'] = 'update_frequency';
  $handler->display->display_options['fields']['field_frequency']['element_type'] = '0';
  $handler->display->display_options['fields']['field_frequency']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_frequency']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_frequency']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_frequency']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_frequency']['type'] = 'i18n_list_default';
  /* Поле: Поле: Ключевые слова */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = 'keywords';
  $handler->display->display_options['fields']['field_tags']['element_type'] = '0';
  $handler->display->display_options['fields']['field_tags']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_tags']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  /* Поле: Поле: Лицензия */
  $handler->display->display_options['fields']['field_license']['id'] = 'field_license';
  $handler->display->display_options['fields']['field_license']['table'] = 'field_data_field_license';
  $handler->display->display_options['fields']['field_license']['field'] = 'field_license';
  $handler->display->display_options['fields']['field_license']['label'] = 'license';
  $handler->display->display_options['fields']['field_license']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_license']['type'] = 'text_plain';
  /* Поле: Поле: Ответственное лицо */
  $handler->display->display_options['fields']['field_contact_name']['id'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['table'] = 'field_data_field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['field'] = 'field_contact_name';
  $handler->display->display_options['fields']['field_contact_name']['label'] = 'contact_name';
  $handler->display->display_options['fields']['field_contact_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_contact_name']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_contact_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_contact_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_contact_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_contact_name']['type'] = 'text_plain';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'owner_name';
  $handler->display->display_options['fields']['title_1']['element_type'] = '0';
  $handler->display->display_options['fields']['title_1']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Поле: Содержимое: ИНН */
  $handler->display->display_options['fields']['field_organization_inn']['id'] = 'field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['table'] = 'field_data_field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['field'] = 'field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['fields']['field_organization_inn']['label'] = 'owner_id';
  $handler->display->display_options['fields']['field_organization_inn']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_organization_inn']['type'] = 'text_plain';
  /* Поле: Содержимое: Upload */
  $handler->display->display_options['fields']['field_upload']['id'] = 'field_upload';
  $handler->display->display_options['fields']['field_upload']['table'] = 'field_data_field_upload';
  $handler->display->display_options['fields']['field_upload']['field'] = 'field_upload';
  $handler->display->display_options['fields']['field_upload']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_upload']['label'] = 'data';
  $handler->display->display_options['fields']['field_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload']['type'] = 'file_url_plain';
  /* Поле: Содержимое: Opendata structure */
  $handler->display->display_options['fields']['field_upload_structure']['id'] = 'field_upload_structure';
  $handler->display->display_options['fields']['field_upload_structure']['table'] = 'field_data_field_upload_structure';
  $handler->display->display_options['fields']['field_upload_structure']['field'] = 'field_upload_structure';
  $handler->display->display_options['fields']['field_upload_structure']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_upload_structure']['label'] = 'structure';
  $handler->display->display_options['fields']['field_upload_structure']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload_structure']['type'] = 'file_url_plain';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: Заголовок */
  $handler->display->display_options['arguments']['title']['id'] = 'title';
  $handler->display->display_options['arguments']['title']['table'] = 'node';
  $handler->display->display_options['arguments']['title']['field'] = 'title';
  $handler->display->display_options['arguments']['title']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['arguments']['title']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['title']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['title']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['title']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['title']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['title']['limit'] = '0';
  /* Контекстный фильтр: Содержимое: ИНН (field_organization_inn) */
  $handler->display->display_options['arguments']['field_organization_inn_value']['id'] = 'field_organization_inn_value';
  $handler->display->display_options['arguments']['field_organization_inn_value']['table'] = 'field_data_field_organization_inn';
  $handler->display->display_options['arguments']['field_organization_inn_value']['field'] = 'field_organization_inn_value';
  $handler->display->display_options['arguments']['field_organization_inn_value']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['arguments']['field_organization_inn_value']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_organization_inn_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_organization_inn_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_organization_inn_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_organization_inn_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_organization_inn_value']['limit'] = '0';
  /* Контекстный фильтр: Термин таксономии: Название */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'field_tags_tid';
  $handler->display->display_options['arguments']['name']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
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
    'dataset' => 'dataset',
  );
  $translatables['datasets_rest'] = array(
    t('Master'),
    t('ещё'),
    t('Отправить'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Организация'),
    t('Ресурс'),
    t('Ключевые слова'),
    t('название'),
    t('uri'),
    t('first_time_publ'),
    t('last_change'),
    t('last_change_description'),
    t('dataset_actual'),
    t('update_frequency'),
    t('keywords'),
    t('license'),
    t('contact_name'),
    t('owner_name'),
    t('owner_id'),
    t('data'),
    t('structure'),
    t('Все'),
  );
  $export['datasets_rest'] = $view;

  $view = new view();
  $view->name = 'datasets_revisions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Редакции наборов ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'realname' => 'realname',
    'type' => 'type',
    'title' => 'title',
  );
  /* Связь: Редакции материала: Содержимое */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Связь: Редакции материала: Пользователь */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Поле: Realname: Реальное имя */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['label'] = '';
  $handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Тип */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['type']['label'] = 'изменил(а)';
  $handler->display->display_options['fields']['type']['alter']['text'] = ' [type]';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Поле: Редакции материала: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'vid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Поле: Редакции материала: Сообщение в системный журнал */
  $handler->display->display_options['fields']['log']['id'] = 'log';
  $handler->display->display_options['fields']['log']['table'] = 'node_revision';
  $handler->display->display_options['fields']['log']['field'] = 'log';
  $handler->display->display_options['fields']['log']['label'] = 'Сообщение';
  $handler->display->display_options['fields']['log']['hide_empty'] = TRUE;
  /* Поле: Редакции материала: Дата обновления */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Обновлено';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  /* Критерий сортировки: Редакции материала: Дата обновления */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Контекстный фильтр: Глобальный: Ноль */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
  );
  /* Критерий фильтра: Редакции материала: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node_revision';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'nid';
  $handler->display->display_options['filters']['nid']['value']['value'] = '!1';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Dataset (field_dataset_ref) */
  $handler->display->display_options['filters']['field_dataset_ref_target_id']['id'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['filters']['field_dataset_ref_target_id']['table'] = 'field_data_field_dataset_ref';
  $handler->display->display_options['filters']['field_dataset_ref_target_id']['field'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['filters']['field_dataset_ref_target_id']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_dataset_ref_target_id']['value']['value'] = '!1';
  $handler->display->display_options['filters']['field_dataset_ref_target_id']['group'] = 2;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'resource' => 'resource',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 2;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'node/%/activity';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Processed';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['datasets_revisions'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Получить актуальное содержимое из редакций.'),
    t('редакция пользователя'),
    t('изменил(а)'),
    t(' [type]'),
    t('Сообщение'),
    t('Обновлено'),
    t('Все'),
    t('Page'),
  );
  $export['datasets_revisions'] = $view;

  $view = new view();
  $view->name = 'datasets_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_datasets';
  $view->human_name = 'Search Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'dataset-search';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Дополнительные настройки',
    ),
    'search_api_views_fulltext' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = '[field_dataset_standard]';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Шапка: Глобальный: Сводка результатов */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '@total наборов';
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Поиск не дал результатов. Попробуйте другое ключевое слово.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Поле: Indexed Материал: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_datasets';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Поле: Indexed Материал: Текст основного поля body » Сводка */
  $handler->display->display_options['fields']['body_summary']['id'] = 'body_summary';
  $handler->display->display_options['fields']['body_summary']['table'] = 'search_api_index_datasets';
  $handler->display->display_options['fields']['body_summary']['field'] = 'body_summary';
  $handler->display->display_options['fields']['body_summary']['label'] = '';
  $handler->display->display_options['fields']['body_summary']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body_summary']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_summary']['link_to_entity'] = 0;
  /* Критерий фильтра: Поиск: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_datasets';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['description'] = 'Поиск по словам';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'body:value' => 'body:value',
  );

  /* Display: Поиск по наборам */
  $handler = $view->new_display('panel_pane', 'Поиск по наборам', 'dataset_search');
  $handler->display->display_options['display_description'] = 'Вывод на странице поиска наборов   /dataset';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Дополнительные настройки',
    ),
    'search_api_views_fulltext' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Результаты вьюса';
  $handler->display->display_options['header']['php']['php_output'] = '<div class="view-results">
<?php 
print format_plural($view->total_rows, \'1 dataset\', \'@count datasets\');
?>
</div>';
  /* Шапка: Глобальный: PHP */
  $handler->display->display_options['header']['php_1']['id'] = 'php_1';
  $handler->display->display_options['header']['php_1']['table'] = 'views';
  $handler->display->display_options['header']['php_1']['field'] = 'php';
  $handler->display->display_options['header']['php_1']['label'] = 'Внешний фильтр (Fulltext search)';
  $handler->display->display_options['header']['php_1']['empty'] = TRUE;
  $handler->display->display_options['header']['php_1']['php_output'] = '<div class="exposed-search-form">
<?php
  $block  = module_invoke_all(\'block_view\', \'0609bb8abc3c8dd9e21fb123bae13c67\');
  print $block[\'content\'][\'#markup\'];
?>
</div>';
  /* Шапка: Наборы данных: Dataset Search Selected Facets Info */
  $handler->display->display_options['header']['od_dataset_selected_facets_info']['id'] = 'od_dataset_selected_facets_info';
  $handler->display->display_options['header']['od_dataset_selected_facets_info']['table'] = 'views';
  $handler->display->display_options['header']['od_dataset_selected_facets_info']['field'] = 'od_dataset_selected_facets_info';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Indexed Материал: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_datasets';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Поле: Indexed Материал: Текст основного поля body » Сводка */
  $handler->display->display_options['fields']['body_summary']['id'] = 'body_summary';
  $handler->display->display_options['fields']['body_summary']['table'] = 'search_api_index_datasets';
  $handler->display->display_options['fields']['body_summary']['field'] = 'body_summary';
  $handler->display->display_options['fields']['body_summary']['label'] = '';
  $handler->display->display_options['fields']['body_summary']['alter']['max_length'] = '100';
  $handler->display->display_options['fields']['body_summary']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_summary']['link_to_entity'] = 0;
  /* Поле: Indexed Материал: Рекомендовано */
  $handler->display->display_options['fields']['field_dataset_standard']['id'] = 'field_dataset_standard';
  $handler->display->display_options['fields']['field_dataset_standard']['table'] = 'search_api_index_datasets';
  $handler->display->display_options['fields']['field_dataset_standard']['field'] = 'field_dataset_standard';
  $handler->display->display_options['fields']['field_dataset_standard']['label'] = '';
  $handler->display->display_options['fields']['field_dataset_standard']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_dataset_standard']['alter']['text'] = 'recommended-[field_dataset_standard-value] ';
  $handler->display->display_options['fields']['field_dataset_standard']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_dataset_standard']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_dataset_standard']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_dataset_standard']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Поиск: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_datasets';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['description'] = 'Например: Реестр, Федеральная таможенная служба';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'body:value' => 'body:value',
  );
  /* Критерий фильтра: Indexed Материал: Статус */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_datasets';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['pane_title'] = 'Поиск по наборам';
  $handler->display->display_options['pane_description'] = 'Вывод на странице поиска наборов   /dataset';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['datasets_search'] = array(
    t('Master'),
    t('ещё'),
    t('Отправить'),
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
    t('@total наборов'),
    t('Поиск не дал результатов. Попробуйте другое ключевое слово.'),
    t('Поиск по словам'),
    t('Поиск по наборам'),
    t('Вывод на странице поиска наборов   /dataset'),
    t('Результаты вьюса'),
    t('Внешний фильтр (Fulltext search)'),
    t('recommended-[field_dataset_standard-value] '),
    t('Например: Реестр, Федеральная таможенная служба'),
    t('Представления-Фрагменты'),
  );
  $export['datasets_search'] = $view;

  $view = new view();
  $view->name = 'documents_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_documents';
  $view->human_name = 'Библиотека';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Шапка: Глобальный: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php 
print format_plural($view->total_rows, \'1 document\', \'@count documents\');
?>
';
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Поиск не дал результатов. Попробуйте другое ключевое слово.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Indexed Материал: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Поле: Indexed Материал: Дата изменена */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Дата последнего изменения';
  $handler->display->display_options['fields']['changed']['date_format'] = 'comment';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 0;
  /* Поле: Indexed Материал: Дата создания */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Поле: Indexed Материал: Текст основного поля body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '350';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;

  /* Display: Библиотека */
  $handler = $view->new_display('panel_pane', 'Библиотека', 'document_search');
  $handler->display->display_options['display_description'] = 'Поиск по документам. Индекс Search API.';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Indexed Материал: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Поле: Indexed Материал: Статус документа */
  $handler->display->display_options['fields']['field_document_status']['id'] = 'field_document_status';
  $handler->display->display_options['fields']['field_document_status']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['field_document_status']['field'] = 'field_document_status';
  $handler->display->display_options['fields']['field_document_status']['hide_empty'] = TRUE;
  /* Поле: Indexed Материал: Дата изменена */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Дата последнего изменения';
  $handler->display->display_options['fields']['changed']['date_format'] = 'comment';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 0;
  /* Поле: Indexed Материал: Дата создания */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Поле: Indexed Материал: Текст основного поля body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_documents';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '350';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Поиск: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_documents';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['description'] = 'поиск по';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'query';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'body:value' => 'body:value',
  );
  $handler->display->display_options['pane_title'] = 'Библиотека';
  $handler->display->display_options['pane_description'] = 'Поиск по документам. Индекс Search API.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['documents_search'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('Поиск не дал результатов. Попробуйте другое ключевое слово.'),
    t('Дата последнего изменения'),
    t('Дата создания'),
    t('Библиотека'),
    t('Поиск по документам. Индекс Search API.'),
    t('Статус документа'),
    t('поиск по'),
    t('Представления-Фрагменты'),
  );
  $export['documents_search'] = $view;

  $view = new view();
  $view->name = 'entityform_submissions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'Entityform submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'edit any entityform';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_e_mail' => 'field_e_mail',
    'field_body' => 'field_body',
    'field_user_name' => 'field_user_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_e_mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поле: Поле: Name */
  $handler->display->display_options['fields']['field_user_name']['id'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['table'] = 'field_data_field_user_name';
  $handler->display->display_options['fields']['field_user_name']['field'] = 'field_user_name';
  $handler->display->display_options['fields']['field_user_name']['label'] = 'Имя';
  /* Поле: Entityform Submission: E-mail */
  $handler->display->display_options['fields']['field_e_mail']['id'] = 'field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['table'] = 'field_data_field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['field'] = 'field_e_mail';
  $handler->display->display_options['fields']['field_e_mail']['label'] = 'Адрес электронной почты';
  $handler->display->display_options['fields']['field_e_mail']['type'] = 'email_plain';
  /* Поле: Поле: Сообщение */
  $handler->display->display_options['fields']['field_body']['id'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['table'] = 'field_data_field_body';
  $handler->display->display_options['fields']['field_body']['field'] = 'field_body';
  $handler->display->display_options['fields']['field_body']['type'] = 'text_plain';
  /* Поле: Entityform Submission: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_entityform';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Ссылка на запрос';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Критерий фильтра: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'feedback' => 'feedback',
  );

  /* Display: Обратная связь */
  $handler = $view->new_display('panel_pane', 'Обратная связь', 'feedback_submissions');
  $handler->display->display_options['display_description'] = 'Вывод запросов отправленных через форму обратной связи';
  $handler->display->display_options['pane_title'] = 'Обратная связь';
  $handler->display->display_options['pane_description'] = 'Вывод запросов отправленных через форму обратной связи';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $translatables['entityform_submissions'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('Имя'),
    t('Адрес электронной почты'),
    t('Сообщение'),
    t('Ссылка на запрос'),
    t('Обратная связь'),
    t('Вывод запросов отправленных через форму обратной связи'),
    t('Представления-Фрагменты'),
  );
  $export['entityform_submissions'] = $view;

  $view = new view();
  $view->name = 'er_';
  $view->description = 'Entityreference displays - Материалы';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ER Материалы';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['relationships']['field_organization_target_id']['field'] = 'field_organization_target_id';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
    'organization' => 'organization',
  );

  /* Display: ER организации */
  $handler = $view->new_display('entityreference', 'ER организации', 'er_list_organizations');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Используется в Заявке на данные.';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';

  /* Display: Наборы публикатора */
  $handler = $view->new_display('entityreference', 'Наборы публикатора', 'publisher_datasets');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Вывод списка наборов публикатора в форме отправки уведомления на набор и Актуализации набора';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Организация */
  $handler->display->display_options['relationships']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['relationships']['field_organization_target_id']['field'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['ui_name'] = 'Организация';
  $handler->display->display_options['relationships']['field_organization_target_id']['label'] = 'Организация';
  /* Связь: Кураторы/Публикаторы организации */
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['id'] = 'field_organization_curators_target_id';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['table'] = 'field_data_field_organization_curators';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['field'] = 'field_organization_curators_target_id';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['ui_name'] = 'Кураторы/Публикаторы организации';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['label'] = 'Кураторы/Публикаторы организации';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Пользователь: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_organization_curators_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['value'] = '1';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );

  /* Display: Организации публикатора */
  $handler = $view->new_display('entityreference', 'Организации публикатора', 'publisher_organizations');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Вывод списка организаций публикатора в форме добавления набора данных.';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Публикаторы */
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['id'] = 'field_organization_curators_target_id';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['table'] = 'field_data_field_organization_curators';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['field'] = 'field_organization_curators_target_id';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['ui_name'] = 'Публикаторы';
  $handler->display->display_options['relationships']['field_organization_curators_target_id']['label'] = 'Публикаторы';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Пользователь: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_organization_curators_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['value'] = '1';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'organization' => 'organization',
  );
  $translatables['er_'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('Сущность Содержимое связана через поле field_organization'),
    t('ER организации'),
    t('Используется в Заявке на данные.'),
    t('Наборы публикатора'),
    t('Вывод списка наборов публикатора в форме отправки уведомления на набор и Актуализации набора'),
    t('Организация'),
    t('Кураторы/Публикаторы организации'),
    t('Все'),
    t('Организации публикатора'),
    t('Вывод списка организаций публикатора в форме добавления набора данных.'),
    t('Публикаторы'),
  );
  $export['er_'] = $view;

  $view = new view();
  $view->name = 'forum_themes';
  $view->description = 'Shows the topics in a given forum';
  $view->tag = 'Advanced Forum';
  $view->base_table = 'node';
  $view->human_name = 'Темы форума';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Forum Name';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 20;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'forum_topic_list';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'teaser' => 'teaser',
    'topic_icon' => 'topic_icon',
    'title' => 'title',
    'timestamp' => 'title',
    'topic_pager' => 'title',
    'name_1' => 'title',
    'created' => 'title',
    'new_comments' => 'comment_count',
    'comment_count' => 'comment_count',
    'totalcount' => 'totalcount',
    'last_comment_name' => 'last_updated',
    'last_updated' => 'last_updated',
    'sticky' => 'sticky',
    'comment' => 'comment',
  );
  $handler->display->display_options['style_options']['default'] = 'last_updated';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'teaser' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'topic_icon' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'topic_pager' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'new_comments' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'totalcount' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_comment_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'last_updated' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'sticky' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['tid'] = 'argument.tid';
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['text']['id'] = 'text';
  $handler->display->display_options['empty']['text']['table'] = 'views';
  $handler->display->display_options['empty']['text']['field'] = 'area';
  $handler->display->display_options['empty']['text']['empty'] = TRUE;
  $handler->display->display_options['empty']['text']['content'] = 'Нет ни одного поста.';
  $handler->display->display_options['empty']['text']['format'] = 'plain_text';
  /* Связь: Содержимое: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['teaser']['id'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['teaser']['field'] = 'body';
  $handler->display->display_options['fields']['teaser']['label'] = 'Анонс';
  $handler->display->display_options['fields']['teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['teaser']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['teaser']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['teaser']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['teaser']['settings'] = array(
    'trim_length' => '200',
  );
  /* Поле: Содержимое: Значок темы */
  $handler->display->display_options['fields']['topic_icon']['id'] = 'topic_icon';
  $handler->display->display_options['fields']['topic_icon']['table'] = 'node';
  $handler->display->display_options['fields']['topic_icon']['field'] = 'topic_icon';
  $handler->display->display_options['fields']['topic_icon']['label'] = '';
  $handler->display->display_options['fields']['topic_icon']['hot_topic_threshold'] = '15';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Топик / Автору топика';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="forum-topic-title">[title]</span> ';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[teaser]';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['ui_name'] = 'Has new content';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '[timestamp] ';
  $handler->display->display_options['fields']['timestamp']['comments'] = TRUE;
  /* Поле: Содержимое: Постраничная навигация */
  $handler->display->display_options['fields']['topic_pager']['id'] = 'topic_pager';
  $handler->display->display_options['fields']['topic_pager']['table'] = 'node';
  $handler->display->display_options['fields']['topic_pager']['field'] = 'topic_pager';
  $handler->display->display_options['fields']['topic_pager']['total_pages_shown'] = '3';
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = '<br /> автор [name_1] ';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '» [created]';
  /* Поле: Содержимое: Новые комментарии */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['exclude'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['new_comments']['prefix'] = 'View ';
  $handler->display->display_options['fields']['new_comments']['suffix'] = ' новый';
  /* Поле: Содержимое: Количество комментариев */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Ответов';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '[comment_count]<br />[new_comments] ';
  $handler->display->display_options['fields']['comment_count']['empty'] = '0';
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = FALSE;
  /* Поле: Статистика содержимого: Всего просмотров */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = 'Просмотры';
  $handler->display->display_options['fields']['totalcount']['empty'] = '0';
  $handler->display->display_options['fields']['totalcount']['empty_zero'] = TRUE;
  /* Поле: Содержимое: Автор последнего комментария */
  $handler->display->display_options['fields']['last_comment_name']['id'] = 'last_comment_name';
  $handler->display->display_options['fields']['last_comment_name']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_comment_name']['field'] = 'last_comment_name';
  $handler->display->display_options['fields']['last_comment_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_comment_name']['alter']['text'] = 'автор [last_comment_name] ';
  /* Поле: Содержимое: Дата обновления/комментирования */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Последнее сообщение';
  /* Поле: Содержимое: Прикреплено */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sticky']['not'] = 0;
  /* Поле: Содержимое: Разрешение комментировать */
  $handler->display->display_options['fields']['comment']['id'] = 'comment';
  $handler->display->display_options['fields']['comment']['table'] = 'node';
  $handler->display->display_options['fields']['comment']['field'] = 'comment';
  $handler->display->display_options['fields']['comment']['exclude'] = TRUE;
  /* Поле: Поле: Рубрика */
  $handler->display->display_options['fields']['field_rubric']['id'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['fields']['field_rubric']['field'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Критерий сортировки: Содержимое: Прикреплено */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Контекстный фильтр: ID Форума */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['ui_name'] = 'ID Форума';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Поле: Рубрика (field_rubric) */
  $handler->display->display_options['filters']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['filters']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['operator_id'] = 'field_rubric_tid_op';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['label'] = 'Рубрика';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['operator'] = 'field_rubric_tid_op';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['identifier'] = 'field_rubric_tid';
  $handler->display->display_options['filters']['field_rubric_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_rubric_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rubric_tid']['vocabulary'] = 'rubrics';

  /* Display: Темы форума */
  $handler = $view->new_display('panel_pane', 'Темы форума', 'forum_themes');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Вывод тем форума на странице Форума';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['teaser']['id'] = 'teaser';
  $handler->display->display_options['fields']['teaser']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['teaser']['field'] = 'body';
  $handler->display->display_options['fields']['teaser']['label'] = 'Анонс';
  $handler->display->display_options['fields']['teaser']['exclude'] = TRUE;
  $handler->display->display_options['fields']['teaser']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['teaser']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['teaser']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['teaser']['settings'] = array(
    'trim_length' => '200',
  );
  /* Поле: Содержимое: Значок темы */
  $handler->display->display_options['fields']['topic_icon']['id'] = 'topic_icon';
  $handler->display->display_options['fields']['topic_icon']['table'] = 'node';
  $handler->display->display_options['fields']['topic_icon']['field'] = 'topic_icon';
  $handler->display->display_options['fields']['topic_icon']['label'] = '';
  $handler->display->display_options['fields']['topic_icon']['hot_topic_threshold'] = '15';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Топик';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<span class="forum-topic-title">[title]</span> ';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['alt'] = '[teaser]';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['ui_name'] = 'Has new content';
  $handler->display->display_options['fields']['timestamp']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['alter']['text'] = '[timestamp] ';
  $handler->display->display_options['fields']['timestamp']['comments'] = TRUE;
  /* Поле: Содержимое: Постраничная навигация */
  $handler->display->display_options['fields']['topic_pager']['id'] = 'topic_pager';
  $handler->display->display_options['fields']['topic_pager']['table'] = 'node';
  $handler->display->display_options['fields']['topic_pager']['field'] = 'topic_pager';
  $handler->display->display_options['fields']['topic_pager']['total_pages_shown'] = '3';
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name_1']['alter']['text'] = '<br /> автор [name_1] ';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '» [created]';
  /* Поле: Содержимое: Новые комментарии */
  $handler->display->display_options['fields']['new_comments']['id'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['table'] = 'node';
  $handler->display->display_options['fields']['new_comments']['field'] = 'new_comments';
  $handler->display->display_options['fields']['new_comments']['exclude'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['new_comments']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['new_comments']['prefix'] = 'View ';
  $handler->display->display_options['fields']['new_comments']['suffix'] = ' новый';
  /* Поле: Содержимое: Количество комментариев */
  $handler->display->display_options['fields']['comment_count']['id'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['comment_count']['field'] = 'comment_count';
  $handler->display->display_options['fields']['comment_count']['label'] = 'Ответов';
  $handler->display->display_options['fields']['comment_count']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['alter']['text'] = '[comment_count]<br />[new_comments] ';
  $handler->display->display_options['fields']['comment_count']['empty'] = '0';
  $handler->display->display_options['fields']['comment_count']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['comment_count']['hide_alter_empty'] = FALSE;
  /* Поле: Статистика содержимого: Всего просмотров */
  $handler->display->display_options['fields']['totalcount']['id'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['table'] = 'node_counter';
  $handler->display->display_options['fields']['totalcount']['field'] = 'totalcount';
  $handler->display->display_options['fields']['totalcount']['label'] = 'Количество просмотров';
  $handler->display->display_options['fields']['totalcount']['empty'] = '0';
  $handler->display->display_options['fields']['totalcount']['empty_zero'] = TRUE;
  /* Поле: Содержимое: Автор последнего комментария */
  $handler->display->display_options['fields']['last_comment_name']['id'] = 'last_comment_name';
  $handler->display->display_options['fields']['last_comment_name']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_comment_name']['field'] = 'last_comment_name';
  $handler->display->display_options['fields']['last_comment_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['last_comment_name']['alter']['text'] = 'автор [last_comment_name] ';
  /* Поле: Содержимое: Дата обновления/комментирования */
  $handler->display->display_options['fields']['last_updated']['id'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['table'] = 'node_comment_statistics';
  $handler->display->display_options['fields']['last_updated']['field'] = 'last_updated';
  $handler->display->display_options['fields']['last_updated']['label'] = 'Последнее сообщение';
  /* Поле: Содержимое: Прикреплено */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['exclude'] = TRUE;
  $handler->display->display_options['fields']['sticky']['not'] = 0;
  /* Поле: Содержимое: Разрешение комментировать */
  $handler->display->display_options['fields']['comment']['id'] = 'comment';
  $handler->display->display_options['fields']['comment']['table'] = 'node';
  $handler->display->display_options['fields']['comment']['field'] = 'comment';
  $handler->display->display_options['fields']['comment']['exclude'] = TRUE;
  /* Поле: Поле: Рубрика */
  $handler->display->display_options['fields']['field_rubric']['id'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['fields']['field_rubric']['field'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['pane_title'] = 'Темы форума';
  $handler->display->display_options['pane_description'] = 'Вывод тем форума на странице Форума';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'user',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'ID Форума',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['forum_themes'] = array(
    t('Defaults'),
    t('Forum Name'),
    t('ещё'),
    t('Submit'),
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
    t('Нет ни одного поста.'),
    t('автор'),
    t('Nid'),
    t('Анонс'),
    t('Топик / Автору топика'),
    t('<span class="forum-topic-title">[title]</span> '),
    t('[teaser]'),
    t('Содержимое обновлено'),
    t('[timestamp] '),
    t('Постраничная навигация'),
    t('Название'),
    t('<br /> автор [name_1] '),
    t('Дата публикации'),
    t('» [created]'),
    t('Новые комментарии'),
    t('.'),
    t(','),
    t('View '),
    t(' новый'),
    t('Ответов'),
    t('[comment_count]<br />[new_comments] '),
    t('Просмотры'),
    t('Автор последнего комментария'),
    t('автор [last_comment_name] '),
    t('Последнее сообщение'),
    t('Прикреплено'),
    t('Разрешение комментировать'),
    t('Рубрика'),
    t('Все'),
    t('Темы форума'),
    t('Вывод тем форума на странице Форума'),
    t('Топик'),
    t('Количество просмотров'),
    t('Представления-Фрагменты'),
  );
  $export['forum_themes'] = $view;

  $view = new view();
  $view->name = 'fullcalendar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Календарь';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Календарь';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'fullcalendar';
  $handler->display->display_options['style_options']['firstDay'] = '1';
  $handler->display->display_options['style_options']['fields']['date_field'] = array(
    'field_event_date' => 'field_event_date',
  );
  $handler->display->display_options['style_options']['fields']['date'] = TRUE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Время проведения */
  $handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
  $handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
  $handler->display->display_options['fields']['field_event_date']['label'] = '';
  $handler->display->display_options['fields']['field_event_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
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
    'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'calendar';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Календарь';
  $handler->display->display_options['menu']['weight'] = '10';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['fullcalendar'] = array(
    t('Master'),
    t('Календарь'),
    t('ещё'),
    t('Submit'),
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
    t('Page'),
  );
  $export['fullcalendar'] = $view;

  $view = new view();
  $view->name = 'ideas';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Идеи';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Содержимое: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Результаты голосования';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => '',
    'function' => 'positives',
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий сортировки: Результаты голосования: Значение */
  $handler->display->display_options['sorts']['value']['id'] = 'value';
  $handler->display->display_options['sorts']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['field'] = 'value';
  $handler->display->display_options['sorts']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['sorts']['value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['value']['coalesce'] = 1;
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
    'idea' => 'idea',
  );

  /* Display: Идеи в сообществах */
  $handler = $view->new_display('page', 'Идеи в сообществах', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Идеи';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Листинг идей в сообществах';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: Текстовое поле */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Ссылка добавить Идею';
  $handler->display->display_options['header']['area']['content'] = '<a href="node/add/idea">Добавить идею</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Результаты голосования';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => '',
    'function' => 'positives',
  );
  /* Связь: Поле: Рубрика (field_rubric) */
  $handler->display->display_options['relationships']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['relationships']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['label'] = 'Term from field_rubric';
  /* Связь: Флаги: sent_to_minek */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'Flag MINEK';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'sent_to_minek';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Связь: Содержимое: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Image */
  $handler->display->display_options['fields']['field_rubric_image']['id'] = 'field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['table'] = 'field_data_field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['field'] = 'field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['relationship'] = 'field_rubric_tid';
  $handler->display->display_options['fields']['field_rubric_image']['label'] = '';
  $handler->display->display_options['fields']['field_rubric_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rubric_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_rubric_image']['settings'] = array(
    'image_style' => 'taxonomy-w-65',
    'image_link' => '',
  );
  /* Поле: Поле: Рубрика */
  $handler->display->display_options['fields']['field_rubric']['id'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['fields']['field_rubric']['field'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['label'] = '';
  $handler->display->display_options['fields']['field_rubric']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rubric']['type'] = 'taxonomy_term_reference_plain';
  /* Поле: Содержимое: Голосовать */
  $handler->display->display_options['fields']['field_idea_vote_up_down']['id'] = 'field_idea_vote_up_down';
  $handler->display->display_options['fields']['field_idea_vote_up_down']['table'] = 'field_data_field_idea_vote_up_down';
  $handler->display->display_options['fields']['field_idea_vote_up_down']['field'] = 'field_idea_vote_up_down';
  $handler->display->display_options['fields']['field_idea_vote_up_down']['label'] = '';
  $handler->display->display_options['fields']['field_idea_vote_up_down']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_idea_vote_up_down']['click_sort_column'] = 'vud_widget';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Флаги: Ссылка флага */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Автор';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  $handler->display->display_options['path'] = 'ideas';

  /* Display: Идеи для модератора */
  $handler = $view->new_display('panel_pane', 'Идеи для модератора', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Идеи для модератора';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
    4 => '4',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Результаты голосования';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => '',
    'function' => 'positives',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::workflow_vbo_given_state_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_next_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'idea' => 'idea',
  );
  /* Критерий фильтра: Процесс: Current state */
  $handler->display->display_options['filters']['sid']['id'] = 'sid';
  $handler->display->display_options['filters']['sid']['table'] = 'workflow_node';
  $handler->display->display_options['filters']['sid']['field'] = 'sid';
  $handler->display->display_options['filters']['sid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['sid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sid']['expose']['operator_id'] = 'sid_op';
  $handler->display->display_options['filters']['sid']['expose']['label'] = 'Статус';
  $handler->display->display_options['filters']['sid']['expose']['operator'] = 'sid_op';
  $handler->display->display_options['filters']['sid']['expose']['identifier'] = 'sid';
  $handler->display->display_options['filters']['sid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Идеи пользователя */
  $handler = $view->new_display('panel_pane', 'Идеи пользователя', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Мои идеи';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Результаты голосования';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => '',
    'function' => 'positives',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '350';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: UID Автора */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'idea' => 'idea',
  );
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'panel',
      'context' => 'entity:entity_rule_setting.args',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: UID Автора',
    ),
  );

  /* Display: Идеи */
  $handler = $view->new_display('panel_pane', 'Идеи', 'ideas_list');
  $handler->display->display_options['display_description'] = 'вывод на странице /ideas';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['label'] = 'Результаты голосования';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => 'points',
    'tag' => '',
    'function' => 'positives',
  );
  /* Связь: Поле: Рубрика (field_rubric) */
  $handler->display->display_options['relationships']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['relationships']['field_rubric_tid']['field'] = 'field_rubric_tid';
  /* Связь: Флаги: sent_to_minek */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'Flag MINEK';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'sent_to_minek';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Связь: Содержимое: Автор */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Image */
  $handler->display->display_options['fields']['field_rubric_image']['id'] = 'field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['table'] = 'field_data_field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['field'] = 'field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['relationship'] = 'field_rubric_tid';
  $handler->display->display_options['fields']['field_rubric_image']['label'] = '';
  $handler->display->display_options['fields']['field_rubric_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rubric_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_rubric_image']['settings'] = array(
    'image_style' => 'taxonomy-w-65',
    'image_link' => '',
  );
  /* Поле: Поле: Рубрика */
  $handler->display->display_options['fields']['field_rubric']['id'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['fields']['field_rubric']['field'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['label'] = '';
  $handler->display->display_options['fields']['field_rubric']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rubric']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Поле: Содержимое: Голосовать */
  $handler->display->display_options['fields']['field_idea_vote_up_down']['id'] = 'field_idea_vote_up_down';
  $handler->display->display_options['fields']['field_idea_vote_up_down']['table'] = 'field_data_field_idea_vote_up_down';
  $handler->display->display_options['fields']['field_idea_vote_up_down']['field'] = 'field_idea_vote_up_down';
  $handler->display->display_options['fields']['field_idea_vote_up_down']['label'] = '';
  $handler->display->display_options['fields']['field_idea_vote_up_down']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_idea_vote_up_down']['click_sort_column'] = 'vud_widget';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Флаги: Ссылка флага */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Автор';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  $handler->display->display_options['pane_title'] = 'Идеи';
  $handler->display->display_options['pane_description'] = 'вывод на странице /ideas';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['ideas'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('Результаты голосования'),
    t('Идеи в сообществах'),
    t('Идеи'),
    t('Листинг идей в сообществах'),
    t('Ссылка добавить Идею'),
    t('<a href="node/add/idea">Добавить идею</a>'),
    t('Term from field_rubric'),
    t('Flag MINEK'),
    t('автор'),
    t('Автор'),
    t('Идеи для модератора'),
    t('Статус'),
    t('Представления-Фрагменты'),
    t('Идеи пользователя'),
    t('Мои идеи'),
    t('Все'),
    t('вывод на странице /ideas'),
    t('термин из field_rubric'),
  );
  $export['ideas'] = $view;

  $view = new view();
  $view->name = 'last_view_pages';
  $view->description = 'Используется в профиле пользователя для закладки "Активность"';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Последние просмотры. Последние наборы';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Последние просмотры';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Связь: Флаги: materials_shown */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'Отмечено флагом';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'materials_shown';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '350';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий сортировки: Флаги: Время отметки флагом */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
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
    'dataset' => 'dataset',
  );

  /* Display: Последние просмотры */
  $handler = $view->new_display('panel_pane', 'Последние просмотры', 'list_last_views_materials');
  $handler->display->display_options['display_description'] = 'Используется в профиле пользователя на закладке "Активность"';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Флаги: materials_shown */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['label'] = 'Отмечено флагом';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'materials_shown';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Флаги: Время отметки флагом */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'comment';
  $handler->display->display_options['fields']['timestamp']['format_date_sql'] = 0;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Поле: Описание набора данных */
  $handler->display->display_options['fields']['field_dataset_body']['id'] = 'field_dataset_body';
  $handler->display->display_options['fields']['field_dataset_body']['table'] = 'field_data_field_dataset_body';
  $handler->display->display_options['fields']['field_dataset_body']['field'] = 'field_dataset_body';
  $handler->display->display_options['fields']['field_dataset_body']['label'] = '';
  $handler->display->display_options['fields']['field_dataset_body']['alter']['max_length'] = '250';
  $handler->display->display_options['fields']['field_dataset_body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_dataset_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Флаги: UID пользователя */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'flagging';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Последние просмотры';
  $handler->display->display_options['pane_description'] = 'Используется в профиле пользователя на закладке "Активность"';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'uid' => array(
      'type' => 'context',
      'context' => 'entity:user.uid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Флаги: UID пользователя',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Последние наборы */
  $handler = $view->new_display('panel_pane', 'Последние наборы', 'list_last_dataset');
  $handler->display->display_options['display_description'] = 'Используется в профиле на закладке Активность';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['pane_title'] = 'Последние наборы';
  $handler->display->display_options['pane_description'] = 'Используется в профиле на закладке Активность';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['last_view_pages'] = array(
    t('Master'),
    t('Последние просмотры'),
    t('ещё'),
    t('Submit'),
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
    t('Отмечено флагом'),
    t('Используется в профиле пользователя на закладке "Активность"'),
    t('Все'),
    t('Представления-Фрагменты'),
    t('Последние наборы'),
    t('Используется в профиле на закладке Активность'),
  );
  $export['last_view_pages'] = $view;

  $view = new view();
  $view->name = 'moderate_publisher_requests';
  $view->description = 'Используется в профиле на закладке - Модерация.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Модерация - Заявки на публикаторство. Moderate publisher requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Заявки на публикаторство';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'publisher_request' => 'publisher_request',
  );

  /* Display: Заявки на публикаторство */
  $handler = $view->new_display('panel_pane', 'Заявки на публикаторство', 'moderate_publisher_requests');
  $handler->display->display_options['display_description'] = 'Используется в профиле на закладке - Модерация';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'realname' => 'realname',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'realname' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_pubreq_user_target_id']['id'] = 'field_pubreq_user_target_id';
  $handler->display->display_options['relationships']['field_pubreq_user_target_id']['table'] = 'field_data_field_pubreq_user';
  $handler->display->display_options['relationships']['field_pubreq_user_target_id']['field'] = 'field_pubreq_user_target_id';
  $handler->display->display_options['relationships']['field_pubreq_user_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Nid - исключено из вывода */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['ui_name'] = 'Nid - исключено из вывода';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Заявка';
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Новая заявка';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Статус заявки */
  $handler->display->display_options['fields']['field_pubreq_status']['id'] = 'field_pubreq_status';
  $handler->display->display_options['fields']['field_pubreq_status']['table'] = 'field_data_field_pubreq_status';
  $handler->display->display_options['fields']['field_pubreq_status']['field'] = 'field_pubreq_status';
  /* Поле: Realname: Реальное имя */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'field_pubreq_user_target_id';
  $handler->display->display_options['fields']['realname']['label'] = 'Автор заявки';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Создано';
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  /* Поле: Содержимое: Установить значение одобрить в заявке на публикаторство */
  $handler->display->display_options['fields']['approve_publisher_request']['id'] = 'approve_publisher_request';
  $handler->display->display_options['fields']['approve_publisher_request']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['approve_publisher_request']['field'] = 'approve_publisher_request';
  $handler->display->display_options['fields']['approve_publisher_request']['label'] = 'одобрить';
  $handler->display->display_options['fields']['approve_publisher_request']['rules_link'] = array(
    'rules_link_parameters' => '',
    'rules_link_rewrite' => '',
  );
  /* Поле: Содержимое: Установить значение отклонить в заявке на публикаторство */
  $handler->display->display_options['fields']['reject_publisher_request']['id'] = 'reject_publisher_request';
  $handler->display->display_options['fields']['reject_publisher_request']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['reject_publisher_request']['field'] = 'reject_publisher_request';
  $handler->display->display_options['fields']['reject_publisher_request']['label'] = 'отклонить';
  $handler->display->display_options['fields']['reject_publisher_request']['rules_link'] = array(
    'rules_link_parameters' => '',
    'rules_link_rewrite' => '',
  );
  /* Поле: Содержимое: Отправить на доработку заявку на публикаторство */
  $handler->display->display_options['fields']['on_completion_publisher_request']['id'] = 'on_completion_publisher_request';
  $handler->display->display_options['fields']['on_completion_publisher_request']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['on_completion_publisher_request']['field'] = 'on_completion_publisher_request';
  $handler->display->display_options['fields']['on_completion_publisher_request']['label'] = 'На доработку';
  $handler->display->display_options['fields']['on_completion_publisher_request']['rules_link'] = array(
    'rules_link_parameters' => '',
    'rules_link_rewrite' => '',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'publisher_request' => 'publisher_request',
  );
  $handler->display->display_options['pane_title'] = 'Заявки на публикаторство';
  $handler->display->display_options['pane_description'] = 'Используется в профиле на закладке - Модерация';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['moderate_publisher_requests'] = array(
    t('Master'),
    t('Заявки на публикаторство'),
    t('ещё'),
    t('Submit'),
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
    t('Используется в профиле на закладке - Модерация'),
    t('Сущность Пользователь связана через поле field_pubreq_user'),
    t('Nid'),
    t('Заявка'),
    t('Новая заявка'),
    t('Статус заявки'),
    t('Автор заявки'),
    t('Создано'),
    t('одобрить'),
    t('отклонить'),
    t('На доработку'),
    t('Представления-Фрагменты'),
  );
  $export['moderate_publisher_requests'] = $view;

  $view = new view();
  $view->name = 'moderation_comments';
  $view->description = 'Используется в профиле пользователя на закладке "Модерация"';
  $view->tag = 'default';
  $view->base_table = 'comment';
  $view->human_name = 'Модерация - список комментариев';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Комментарии';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'subject' => 'subject',
    'comment_body' => 'comment_body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'subject' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'comment_body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Нет результатов для отображения.';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Нет результатов для отображения.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Комментарий: Содержимое */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'comment';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Поле: Массовые операции: Комментарий */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'comment';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::comment_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_comment_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::comment_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Снять с публикации',
    ),
    'action::comment_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::comment_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Удалить комментарий',
    ),
  );
  /* Поле: Комментарий: Заголовок */
  $handler->display->display_options['fields']['subject']['id'] = 'subject';
  $handler->display->display_options['fields']['subject']['table'] = 'comment';
  $handler->display->display_options['fields']['subject']['field'] = 'subject';
  $handler->display->display_options['fields']['subject']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['subject']['alter']['ellipsis'] = FALSE;
  /* Поле: Комментарий: Comment */
  $handler->display->display_options['fields']['comment_body']['id'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['table'] = 'field_data_comment_body';
  $handler->display->display_options['fields']['comment_body']['field'] = 'comment_body';
  $handler->display->display_options['fields']['comment_body']['label'] = 'Комментарий';
  $handler->display->display_options['fields']['comment_body']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Тип */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['relationship'] = 'nid';
  /* Критерий сортировки: Комментарий: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'comment';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Комментарий: Одобрено */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'comment';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;

  /* Display: Модерация - комментарии */
  $handler = $view->new_display('panel_pane', 'Модерация - комментарии', 'moderation_list_comments');
  $handler->display->display_options['display_description'] = 'Модерация - комментарии';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status_node']['id'] = 'status_node';
  $handler->display->display_options['filters']['status_node']['table'] = 'node';
  $handler->display->display_options['filters']['status_node']['field'] = 'status';
  $handler->display->display_options['filters']['status_node']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status_node']['value'] = 1;
  $handler->display->display_options['filters']['status_node']['group'] = 1;
  $handler->display->display_options['filters']['status_node']['expose']['operator'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Модерация - комментарии';
  $handler->display->display_options['pane_description'] = 'Используется в профиле пользователя на закладке "Модерация"';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['moderation_comments'] = array(
    t('Master'),
    t('Комментарии'),
    t('ещё'),
    t('Submit'),
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
    t('Нет результатов для отображения.'),
    t('Содержимое'),
    t('Заголовок'),
    t('Комментарий'),
    t('Тип'),
    t('Модерация - комментарии'),
    t('Используется в профиле пользователя на закладке "Модерация"'),
    t('Представления-Фрагменты'),
  );
  $export['moderation_comments'] = $view;

  $view = new view();
  $view->name = 'moderation_ideas';
  $view->description = 'Используется модератором в профиле закладка "Модерация"для публикации Идей и Приложений. ';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Модерация - идеи. Модерация - приложения.';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Идеи';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Нет результатов для отображения.';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Нет результатов для отображения.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::workflow_vbo_given_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_next_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::od_import_organizations' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Опубликовать',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Описание';
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'idea' => 'idea',
  );

  /* Display: Модерация - идеи */
  $handler = $view->new_display('panel_pane', 'Модерация - идеи', 'moderation_ideas');
  $handler->display->display_options['display_description'] = 'Используется в профиле, закладка модерация.';
  $handler->display->display_options['pane_title'] = 'Модерация - идеи';
  $handler->display->display_options['pane_description'] = 'Используется в профиле, закладка модерация.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Модерация - приложений */
  $handler = $view->new_display('panel_pane', 'Модерация - приложений', 'moderation_app');
  $handler->display->display_options['display_description'] = 'Используется в профиле, закладка модерация.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::workflow_vbo_given_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_next_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::od_import_organizations' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Опубликовать',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'app' => 'app',
  );
  $handler->display->display_options['pane_title'] = 'Модерация - приложения';
  $handler->display->display_options['pane_description'] = 'Используется в профиле, закладка модерация.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Модерация - быстрые факты */
  $handler = $view->new_display('panel_pane', 'Модерация - быстрые факты', 'moderation_quick_facts');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Быстрые факты';
  $handler->display->display_options['display_description'] = 'Используется модератором в профиле, в закладке - Модерация.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Описание';
  /* Поле: Содержимое: Значение */
  $handler->display->display_options['fields']['field_fact_value']['id'] = 'field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['table'] = 'field_data_field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['field'] = 'field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['empty'] = 'отсутствует';
  /* Поле: Содержимое: Процент */
  $handler->display->display_options['fields']['field_fact_percentage']['id'] = 'field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['table'] = 'field_data_field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['field'] = 'field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['empty'] = 'отсутствует';
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['text'] = 'редактировать';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'quick_fact' => 'quick_fact',
  );
  $handler->display->display_options['pane_title'] = 'Модерация - быстрые факты';
  $handler->display->display_options['pane_description'] = 'Используется модератором в профиле, в закладке - Модерация.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['moderation_ideas'] = array(
    t('Master'),
    t('Идеи'),
    t('ещё'),
    t('Submit'),
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
    t('Нет результатов для отображения.'),
    t('Заголовок'),
    t('Описание'),
    t('Модерация - идеи'),
    t('Используется в профиле, закладка модерация.'),
    t('Представления-Фрагменты'),
    t('Модерация - приложений'),
    t('Модерация - приложения'),
    t('Модерация - быстрые факты'),
    t('Быстрые факты'),
    t('Используется модератором в профиле, в закладке - Модерация.'),
    t('Значение'),
    t('отсутствует'),
    t('Процент'),
    t('Ссылка на редактирование'),
    t('редактировать'),
    t('Ссылка на удаление'),
  );
  $export['moderation_ideas'] = $view;

  $view = new view();
  $view->name = 'moderation_opendata_query';
  $view->description = 'Используется в профиле для закладки Запросы/Обращения';
  $view->tag = 'default';
  $view->base_table = 'entityform';
  $view->human_name = 'Модерация - Запросы/Обращения';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Запросы';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '5';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entityform_id' => 'entityform_id',
    'field_od_query_mark_title' => 'field_od_query_mark_title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'entityform_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_od_query_mark_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Нет результатов для отображения.';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Нет результатов для отображения.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Связь: Флаги: for_request */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'entityform';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'for_request';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Связь: Организация */
  $handler->display->display_options['relationships']['field_od_query_data_organization_target_id']['id'] = 'field_od_query_data_organization_target_id';
  $handler->display->display_options['relationships']['field_od_query_data_organization_target_id']['table'] = 'field_data_field_od_query_data_organization';
  $handler->display->display_options['relationships']['field_od_query_data_organization_target_id']['field'] = 'field_od_query_data_organization_target_id';
  $handler->display->display_options['relationships']['field_od_query_data_organization_target_id']['ui_name'] = 'Организация';
  $handler->display->display_options['relationships']['field_od_query_data_organization_target_id']['label'] = 'Организация';
  /* Поле: Массовые операции: Entityform Submission */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'entityform';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_add_opendata' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_create_app' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Entityform Submission: Идентификатор Entityform submission */
  $handler->display->display_options['fields']['entityform_id']['id'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['table'] = 'entityform';
  $handler->display->display_options['fields']['entityform_id']['field'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['exclude'] = TRUE;
  /* Поле: Entityform Submission: Name of data */
  $handler->display->display_options['fields']['field_od_query_data_name']['id'] = 'field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['table'] = 'field_data_field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['field'] = 'field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['label'] = 'Название запрашиваемых данных';
  /* Поле: Entityform Submission: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_entityform';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Посмотреть запрос';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '<a href="[url]">Посмотреть запрос</a>';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Поле: Entityform Submission: Delete Link */
  $handler->display->display_options['fields']['delete_entityform']['id'] = 'delete_entityform';
  $handler->display->display_options['fields']['delete_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['delete_entityform']['field'] = 'delete_entityform';
  $handler->display->display_options['fields']['delete_entityform']['label'] = 'Удалить запрос';
  /* Критерий фильтра: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'opendata_query' => 'opendata_query',
  );

  /* Display: Модерация - Запросы */
  $handler = $view->new_display('panel_pane', 'Модерация - Запросы', 'moderation_query');
  $handler->display->display_options['display_description'] = 'Используется в профиле для закладки Модерация.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Entityform Submission */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'entityform';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_add_forum_forum' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_copy_ef_to_node' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_create_publisher_request_node' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_dataset_actualization' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_validation_od_preprocess_wizard' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_add_opendata' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_opendata_creation_backup' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'rules_component::rules_create_file_and_download' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_dataset_send_notifications' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_notify_organization_curators' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Отправить уведомление Кураторам организации',
    ),
    'rules_component::rules_register_anonymous_through_the_dataset_error_report' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_create_app' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_feedback_notification' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_entityform_submission' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Entityform Submission: Идентификатор Entityform submission */
  $handler->display->display_options['fields']['entityform_id']['id'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['table'] = 'entityform';
  $handler->display->display_options['fields']['entityform_id']['field'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['exclude'] = TRUE;
  /* Поле: Entityform Submission: Name of data */
  $handler->display->display_options['fields']['field_od_query_data_name']['id'] = 'field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['table'] = 'field_data_field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['field'] = 'field_od_query_data_name';
  $handler->display->display_options['fields']['field_od_query_data_name']['label'] = 'Название запрашиваемых данных';
  /* Поле: Entityform Submission: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_entityform';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Посмотреть запрос';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '<a href="[url]">Посмотреть запрос</a>';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Поле: Флаги: Помечено */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = 'Уведомление отправлено';
  $handler->display->display_options['fields']['flagged']['not'] = 0;
  /* Поле: Entityform Submission: The organization, which is necessary to place a dataset */
  $handler->display->display_options['fields']['field_od_query_data_organization']['id'] = 'field_od_query_data_organization';
  $handler->display->display_options['fields']['field_od_query_data_organization']['table'] = 'field_data_field_od_query_data_organization';
  $handler->display->display_options['fields']['field_od_query_data_organization']['field'] = 'field_od_query_data_organization';
  $handler->display->display_options['fields']['field_od_query_data_organization']['label'] = 'Организация';
  $handler->display->display_options['fields']['field_od_query_data_organization']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Содержимое: Кураторы */
  $handler->display->display_options['fields']['field_organization_curators']['id'] = 'field_organization_curators';
  $handler->display->display_options['fields']['field_organization_curators']['table'] = 'field_data_field_organization_curators';
  $handler->display->display_options['fields']['field_organization_curators']['field'] = 'field_organization_curators';
  $handler->display->display_options['fields']['field_organization_curators']['relationship'] = 'field_od_query_data_organization_target_id';
  $handler->display->display_options['fields']['field_organization_curators']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_organization_curators']['delta_offset'] = '0';
  $handler->display->display_options['pane_title'] = 'Модерация - Запросы';
  $handler->display->display_options['pane_description'] = 'Используется в профиле для закладки Модерация.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Обращения */
  $handler = $view->new_display('panel_pane', 'Обращения', 'dataset_reports');
  $handler->display->display_options['display_description'] = 'Используется в профиле для закладки Модерация.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '5';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Ресурс */
  $handler->display->display_options['relationships']['field_ef_dataset_resources_target_id']['id'] = 'field_ef_dataset_resources_target_id';
  $handler->display->display_options['relationships']['field_ef_dataset_resources_target_id']['table'] = 'field_data_field_ef_dataset_resources';
  $handler->display->display_options['relationships']['field_ef_dataset_resources_target_id']['field'] = 'field_ef_dataset_resources_target_id';
  $handler->display->display_options['relationships']['field_ef_dataset_resources_target_id']['ui_name'] = 'Ресурс';
  $handler->display->display_options['relationships']['field_ef_dataset_resources_target_id']['label'] = 'Ресурс';
  /* Связь: Набор данных */
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['id'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['table'] = 'field_data_field_dataset_ref';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['field'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['relationship'] = 'field_ef_dataset_resources_target_id';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['ui_name'] = 'Набор данных';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['label'] = 'Набор данных';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Entityform Submission */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'entityform';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_add_forum_forum' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_copy_ef_to_node' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_create_publisher_request_node' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_dataset_actualization' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_validation_od_preprocess_wizard' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_add_opendata' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_opendata_creation_backup' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_report_user_values_copying' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'rules_component::rules_create_file_and_download' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_dataset_send_notifications' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_notify_organization_curators' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_notify_organization_curators_about_new_reports' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Отправить уведомления кураторам',
    ),
    'rules_component::rules_register_anonymous_through_the_dataset_error_report' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_back_redirect_to_the_resource' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_create_app' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_feedback_notification' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_entityform_submission' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Набор данных';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['empty'] = 'не указан';
  /* Поле: Поле: Владелец набора данных */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['relationship'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['fields']['field_organization']['label'] = 'Организация';
  $handler->display->display_options['fields']['field_organization']['empty'] = 'не указан';
  $handler->display->display_options['fields']['field_organization']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Entityform Submission: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_entityform';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = 'Посмотреть запрос';
  $handler->display->display_options['fields']['url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['url']['alter']['text'] = '<a href="[url]">Посмотреть запрос</a>';
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Поле: Entityform Submission: Уведомление отправлено */
  $handler->display->display_options['fields']['field_notified']['id'] = 'field_notified';
  $handler->display->display_options['fields']['field_notified']['table'] = 'field_data_field_notified';
  $handler->display->display_options['fields']['field_notified']['field'] = 'field_notified';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset_error_report' => 'dataset_error_report',
  );
  $handler->display->display_options['pane_title'] = 'Обращения';
  $handler->display->display_options['pane_description'] = 'Используется в профиле для закладки Модерация.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['moderation_opendata_query'] = array(
    t('Master'),
    t('Запросы'),
    t('ещё'),
    t('Submit'),
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
    t('Нет результатов для отображения.'),
    t('отметить'),
    t('Организация'),
    t('Идентификатор Entityform submission'),
    t('.'),
    t(','),
    t('Название запрашиваемых данных'),
    t('Посмотреть запрос'),
    t('<a href="[url]">Посмотреть запрос</a>'),
    t('Удалить запрос'),
    t('Модерация - Запросы'),
    t('Используется в профиле для закладки Модерация.'),
    t('Уведомление отправлено'),
    t('Кураторы'),
    t('Представления-Фрагменты'),
    t('Обращения'),
    t('Ресурс'),
    t('Набор данных'),
    t('не указан'),
  );
  $export['moderation_opendata_query'] = $view;

  $view = new view();
  $view->name = 'moderation_users';
  $view->description = 'Используется в профиле пользователя для закладки "Модерация"';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Модерация - список пользователей';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Пользователи';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Связь: Флаги: make_publisher */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'make_publisher';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Поле: Пользователь: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Пользователь';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Поле: Пользователь: Роли */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Поле: Флаги: Ссылка флага */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Добавить роль публикатора';
  $handler->display->display_options['fields']['ops']['link_type'] = 'confirm';
  /* Критерий сортировки: Пользователь: Дата создания */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Пользователь: Активно */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Модерация - пользователи */
  $handler = $view->new_display('panel_pane', 'Модерация - пользователи', 'moderation_list_users');
  $handler->display->display_options['display_description'] = 'Модерация - пользователи';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['pane_title'] = 'Модерация - пользователи';
  $handler->display->display_options['pane_description'] = 'Используется в профиле пользователя на закладке "Модерация"';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['moderation_users'] = array(
    t('Master'),
    t('Пользователи'),
    t('ещё'),
    t('Submit'),
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
    t('отметить'),
    t('Пользователь'),
    t('Роли'),
    t('Добавить роль публикатора'),
    t('Модерация - пользователи'),
    t('Используется в профиле пользователя на закладке "Модерация"'),
    t('Представления-Фрагменты'),
  );
  $export['moderation_users'] = $view;

  $view = new view();
  $view->name = 'news';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Новости';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
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
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser';
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Результаты отсутствуют';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );

  /* Display: Новости Рубрики */
  $handler = $view->new_display('panel_pane', 'Новости Рубрики', 'news');
  $handler->display->display_options['display_description'] = 'Вывод на странице Рубрики в разделе Новости';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Новости в данной рубрике отсутствуют.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Рубрика */
  $handler->display->display_options['relationships']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['relationships']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['ui_name'] = 'Рубрика';
  $handler->display->display_options['relationships']['field_rubric_tid']['label'] = 'Рубрика';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: ID Рубрики */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'field_rubric_tid';
  $handler->display->display_options['arguments']['tid']['ui_name'] = 'ID Рубрики';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Новости Рубрики';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Рубрики в разделе Новости';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'ID Рубрики',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Новости для Редакции  */
  $handler = $view->new_display('panel_pane', 'Новости для Редакции ', 'news_redaction');
  $handler->display->display_options['display_description'] = 'Список новостей для редакции. Вывод в закладке Редакция в профиле Редактора. ';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_bind_user_to_copied_node' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_given_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_next_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'rules_component::rules_pub_resuest' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_on_completion_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_approve_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_reject_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::od_import_import_organizations_opendata' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Привязать к рубрике',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          'news::field_rubric' => 'news::field_rubric',
        ),
      ),
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Опубликовать',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Снять с публикации',
    ),
    'action::node_save_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Удалить',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Анонс новости */
  $handler->display->display_options['fields']['field_teaser']['id'] = 'field_teaser';
  $handler->display->display_options['fields']['field_teaser']['table'] = 'field_data_field_teaser';
  $handler->display->display_options['fields']['field_teaser']['field'] = 'field_teaser';
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата создания';
  $handler->display->display_options['fields']['created']['date_format'] = 'comment';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 0;
  /* Поле: Содержимое: Опубликовано */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Поле: Поле: Рубрика */
  $handler->display->display_options['fields']['field_rubric']['id'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['fields']['field_rubric']['field'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['type'] = 'taxonomy_term_reference_plain';
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Критерий фильтра: Содержимое: Опубликовано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
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
  $handler->display->display_options['pane_title'] = 'Новости для Редакции';
  $handler->display->display_options['pane_description'] = 'Список новостей для редакции. Вывод в закладке Редакция в профиле Редактора. ';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['news'] = array(
    t('Master'),
    t('ещё'),
    t('Отправить'),
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
    t('Результаты отсутствуют'),
    t('Новости Рубрики'),
    t('Вывод на странице Рубрики в разделе Новости'),
    t('Новости в данной рубрике отсутствуют.'),
    t('Рубрика'),
    t('Все'),
    t('Представления-Фрагменты'),
    t('Новости для Редакции '),
    t('Список новостей для редакции. Вывод в закладке Редакция в профиле Редактора. '),
    t('Анонс новости'),
    t('Дата создания'),
    t('Опубликовано'),
    t('Ссылка на редактирование'),
    t('Новости для Редакции'),
  );
  $export['news'] = $view;

  $view = new view();
  $view->name = 'organizations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Организации';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Организации';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'type' => 'type',
    'field_organization_inn' => 'field_organization_inn',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization_inn' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Поле: Глобальный: Счетчик результатов */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Тип */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Поле: Содержимое: ИНН */
  $handler->display->display_options['fields']['field_organization_inn']['id'] = 'field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['table'] = 'field_data_field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['field'] = 'field_organization_inn';
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
    'organization' => 'organization',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Организации';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Вывод списка организаций в целях модерации и заполнения контентом.';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Дополнительные настройки',
    ),
    'field_organization_type_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'title' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'field_organization_type' => 'field_organization_type',
    'field_organization_inn' => 'field_organization_inn',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization_inn' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<div class="pane-btn">
<?php 
//!isset($GLOBALS[\'user\']->roles[6]) && 
if (!user_is_anonymous()) print l(\'Стать публикатором\', \'become-a-publisher\', array(\'attributes\' => array(\'class\' => \'btn\'))); 
?>
</div>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Глобальный: Счетчик результатов */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '№';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Тип */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['type'] = 'taxonomy_term_reference_plain';
  /* Поле: Содержимое: ИНН */
  $handler->display->display_options['fields']['field_organization_inn']['id'] = 'field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['table'] = 'field_data_field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['field'] = 'field_organization_inn';
  /* Поле: Содержимое: Ссылка на сайт */
  $handler->display->display_options['fields']['field_site_url']['id'] = 'field_site_url';
  $handler->display->display_options['fields']['field_site_url']['table'] = 'field_data_field_site_url';
  $handler->display->display_options['fields']['field_site_url']['field'] = 'field_site_url';
  $handler->display->display_options['fields']['field_site_url']['label'] = 'Сайт';
  $handler->display->display_options['fields']['field_site_url']['empty'] = '<span class="no-results"></span>';
  $handler->display->display_options['fields']['field_site_url']['click_sort_column'] = 'url';
  /* Поле: Содержимое: Ссылка на сайт Портала ОД организации */
  $handler->display->display_options['fields']['field_opendata_portal_url']['id'] = 'field_opendata_portal_url';
  $handler->display->display_options['fields']['field_opendata_portal_url']['table'] = 'field_data_field_opendata_portal_url';
  $handler->display->display_options['fields']['field_opendata_portal_url']['field'] = 'field_opendata_portal_url';
  $handler->display->display_options['fields']['field_opendata_portal_url']['label'] = 'Портал ОД организации';
  $handler->display->display_options['fields']['field_opendata_portal_url']['empty'] = '<span class="no-results"></span>';
  $handler->display->display_options['fields']['field_opendata_portal_url']['click_sort_column'] = 'url';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'organization' => 'organization',
  );
  /* Критерий фильтра: Содержимое: Тип (field_organization_type) */
  $handler->display->display_options['filters']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['operator_id'] = 'field_organization_type_tid_op';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['label'] = 'Тип';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['operator'] = 'field_organization_type_tid_op';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['identifier'] = 'field_organization_type_tid';
  $handler->display->display_options['filters']['field_organization_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_organization_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_organization_type_tid']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['field_organization_type_tid']['hierarchy'] = 1;
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'allwords';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Поиск';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['path'] = 'organizations';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Список организаций';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Наборы организации */
  $handler = $view->new_display('panel_pane', 'Наборы организации', 'organization_datasets');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Наборы открытых данных';
  $handler->display->display_options['display_description'] = 'Вывод списка наборов организации на странице отдельной организации';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_rubric_image' => 'field_rubric_image',
    'field_rubric' => 'field_rubric',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Наборы отсутствуют.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Организация */
  $handler->display->display_options['relationships']['field_organization_target_id']['id'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['table'] = 'field_data_field_organization';
  $handler->display->display_options['relationships']['field_organization_target_id']['field'] = 'field_organization_target_id';
  $handler->display->display_options['relationships']['field_organization_target_id']['ui_name'] = 'Организация';
  $handler->display->display_options['relationships']['field_organization_target_id']['label'] = 'Организация';
  $handler->display->display_options['relationships']['field_organization_target_id']['required'] = TRUE;
  /* Связь: Рубрика */
  $handler->display->display_options['relationships']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['relationships']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['relationships']['field_rubric_tid']['ui_name'] = 'Рубрика';
  $handler->display->display_options['relationships']['field_rubric_tid']['label'] = 'Рубрика';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Image */
  $handler->display->display_options['fields']['field_rubric_image']['id'] = 'field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['table'] = 'field_data_field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['field'] = 'field_rubric_image';
  $handler->display->display_options['fields']['field_rubric_image']['relationship'] = 'field_rubric_tid';
  $handler->display->display_options['fields']['field_rubric_image']['label'] = '';
  $handler->display->display_options['fields']['field_rubric_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rubric_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_rubric_image']['settings'] = array(
    'image_style' => 'taxonomy-w-65',
    'image_link' => '',
  );
  /* Поле: Поле: Рубрика */
  $handler->display->display_options['fields']['field_rubric']['id'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['fields']['field_rubric']['field'] = 'field_rubric';
  $handler->display->display_options['fields']['field_rubric']['label'] = '';
  $handler->display->display_options['fields']['field_rubric']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rubric']['type'] = 'hs_taxonomy_term_reference_hierarchical_text';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_organization_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'dataset' => 'dataset',
  );
  $handler->display->display_options['pane_title'] = 'Наборы организации';
  $handler->display->display_options['pane_description'] = 'Вывод списка наборов организации на странице отдельной организации';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Организации */
  $handler = $view->new_display('panel_pane', 'Организации', 'organizations_list');
  $handler->display->display_options['display_description'] = 'Вывод списка организаций на странице /organizations';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Дополнительные настройки',
    ),
    'term_node_tid_depth' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
    'title' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'counter' => 'counter',
    'title' => 'title',
    'field_organization_type' => 'field_organization_type',
    'field_organization_inn' => 'field_organization_inn',
    'field_site_url' => 'field_site_url',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'counter' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_organization_inn' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_site_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php 
if (!isset($GLOBALS[\'user\']->roles[6]) && !user_is_anonymous()) {
  print \'<div class="pane-btn">\' . l(\'Стать публикатором\', \'become-a-publisher\', array(\'attributes\' => array(\'class\' => \'btn\'))) . \'</div>\'; 
}
?>
';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Содержимое: Тип (field_organization_type) */
  $handler->display->display_options['relationships']['field_organization_type_tid']['id'] = 'field_organization_type_tid';
  $handler->display->display_options['relationships']['field_organization_type_tid']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['relationships']['field_organization_type_tid']['field'] = 'field_organization_type_tid';
  $handler->display->display_options['relationships']['field_organization_type_tid']['label'] = 'Тип организации';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Глобальный: Счетчик результатов */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Название';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Тип */
  $handler->display->display_options['fields']['field_organization_type']['id'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['table'] = 'field_data_field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['field'] = 'field_organization_type';
  $handler->display->display_options['fields']['field_organization_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_organization_type']['settings'] = array(
    'conditions' => array(
      0 => array(
        'condition' => '',
      ),
    ),
  );
  /* Поле: Содержимое: ИНН */
  $handler->display->display_options['fields']['field_organization_inn']['id'] = 'field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['table'] = 'field_data_field_organization_inn';
  $handler->display->display_options['fields']['field_organization_inn']['field'] = 'field_organization_inn';
  /* Поле: Содержимое: Ссылка на сайт */
  $handler->display->display_options['fields']['field_site_url']['id'] = 'field_site_url';
  $handler->display->display_options['fields']['field_site_url']['table'] = 'field_data_field_site_url';
  $handler->display->display_options['fields']['field_site_url']['field'] = 'field_site_url';
  $handler->display->display_options['fields']['field_site_url']['label'] = 'Сайт';
  $handler->display->display_options['fields']['field_site_url']['empty'] = '<span class="no-results"></span>';
  $handler->display->display_options['fields']['field_site_url']['click_sort_column'] = 'url';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Содержимое: Заголовок */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'organization' => 'organization',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерий фильтра: Содержимое: Имеет термины таксономии (с глубиной) */
  $handler->display->display_options['filters']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['value'] = array(
    17 => '17',
    21 => '21',
    22 => '22',
    23 => '23',
    19 => '19',
    18 => '18',
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator_id'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['label'] = 'Тип';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['operator'] = 'term_node_tid_depth_op';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['identifier'] = 'term_node_tid_depth';
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['term_node_tid_depth']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['term_node_tid_depth']['type'] = 'select';
  $handler->display->display_options['filters']['term_node_tid_depth']['vocabulary'] = 'organization_type';
  $handler->display->display_options['filters']['term_node_tid_depth']['hierarchy'] = 1;
  $handler->display->display_options['filters']['term_node_tid_depth']['depth'] = '1';
  /* Критерий фильтра: Содержимое: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Поиск';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['pane_title'] = 'Организации';
  $handler->display->display_options['pane_description'] = 'Вывод списка организаций на странице /organizations';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['organizations'] = array(
    t('Master'),
    t('Организации'),
    t('ещё'),
    t('Отправить'),
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
    t('Название'),
    t('Тип'),
    t('ИНН'),
    t('Page'),
    t('Вывод списка организаций в целях модерации и заполнения контентом.'),
    t('№'),
    t('Сайт'),
    t('<span class="no-results"></span>'),
    t('Портал ОД организации'),
    t('Поиск'),
    t('Наборы организации'),
    t('Наборы открытых данных'),
    t('Вывод списка наборов организации на странице отдельной организации'),
    t('Наборы отсутствуют.'),
    t('Организация'),
    t('Рубрика'),
    t('Все'),
    t('Представления-Фрагменты'),
    t('Вывод списка организаций на странице /organizations'),
    t('Применить'),
    t('Тип организации'),
  );
  $export['organizations'] = $view;

  $view = new view();
  $view->name = 'quick_facts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Быстрые факты';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'По умолчанию',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_fact_value' => 0,
    'body' => 0,
    'field_fact_url' => 0,
    'field_fact_is_percentage' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_fact_value' => 0,
    'body' => 0,
    'field_fact_url' => 0,
    'field_fact_is_percentage' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '5000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '1500';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Содержимое: Значение */
  $handler->display->display_options['fields']['field_fact_value']['id'] = 'field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['table'] = 'field_data_field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['field'] = 'field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['label'] = '';
  $handler->display->display_options['fields']['field_fact_value']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Ссылка */
  $handler->display->display_options['fields']['field_fact_url']['id'] = 'field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['table'] = 'field_data_field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['field'] = 'field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['label'] = '';
  $handler->display->display_options['fields']['field_fact_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fact_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_fact_url']['type'] = 'link_plain';
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
    'quick_fact' => 'quick_fact',
  );

  /* Display: Блок - Быстрые факты */
  $handler = $view->new_display('panel_pane', 'Блок - Быстрые факты', 'quick_facts_front');
  $handler->display->display_options['display_description'] = 'Вывод на главной странице';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Подвал: Глобальный: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['php_output'] = '<div class="frontpage-important-info-block">
Уважаемые пользователи!
До 28 апреля 2014 года осуществляется сбор предложений по доработкам Портала. Свои идеи и пожелания вы можете оставлять на форуме в соответствующей теме или на странице идей. Благодарим за участие!
</div>
';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Значение */
  $handler->display->display_options['fields']['field_fact_value']['id'] = 'field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['table'] = 'field_data_field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['field'] = 'field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['label'] = '';
  $handler->display->display_options['fields']['field_fact_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fact_value']['hide_empty'] = TRUE;
  /* Поле: Содержимое: Процент */
  $handler->display->display_options['fields']['field_fact_percentage']['id'] = 'field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['table'] = 'field_data_field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['field'] = 'field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['label'] = '';
  $handler->display->display_options['fields']['field_fact_percentage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fact_percentage']['hide_empty'] = TRUE;
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Ссылка */
  $handler->display->display_options['fields']['field_fact_url']['id'] = 'field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['table'] = 'field_data_field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['field'] = 'field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['label'] = '';
  $handler->display->display_options['fields']['field_fact_url']['alter']['text'] = '<div class="quick-fact"><a href="[field_fact_url-url] class="quick-fact body-link">[body]</a>[field_fact_url]<div>';
  $handler->display->display_options['fields']['field_fact_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fact_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_fact_url']['type'] = 'link_short';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'quick_fact' => 'quick_fact',
  );
  /* Критерий фильтра: Содержимое: Содержание (body:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['pane_title'] = 'Быстрые факты';
  $handler->display->display_options['pane_description'] = 'Вывод на главной странице';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Профиль-Быстрые факты */
  $handler = $view->new_display('panel_pane', 'Профиль-Быстрые факты', 'quick_facts');
  $handler->display->display_options['display_description'] = 'Вывод быстрых фактов в профиле пользователя.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_fact_value' => 'field_fact_value',
    'body' => 'body',
    'field_fact_url' => 'field_fact_url',
    'field_fact_is_percentage' => 'field_fact_is_percentage',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_fact_value' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fact_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_fact_is_percentage' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Значение */
  $handler->display->display_options['fields']['field_fact_value']['id'] = 'field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['table'] = 'field_data_field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['field'] = 'field_fact_value';
  $handler->display->display_options['fields']['field_fact_value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fact_value']['empty'] = 'нет';
  /* Поле: Содержимое: Процент */
  $handler->display->display_options['fields']['field_fact_percentage']['id'] = 'field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['table'] = 'field_data_field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['field'] = 'field_fact_percentage';
  $handler->display->display_options['fields']['field_fact_percentage']['empty'] = 'нет';
  /* Поле: Содержимое: Содержание */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Текст';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Ссылка */
  $handler->display->display_options['fields']['field_fact_url']['id'] = 'field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['table'] = 'field_data_field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['field'] = 'field_fact_url';
  $handler->display->display_options['fields']['field_fact_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_fact_url']['empty'] = 'не указана';
  $handler->display->display_options['fields']['field_fact_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_fact_url']['type'] = 'link_url';
  /* Поле: Содержимое: Ссылка на редактирование */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Поле: Содержимое: Ссылка на удаление */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['pane_title'] = 'Профиль-Быстрые факты';
  $handler->display->display_options['pane_description'] = 'Вывод быстрых фактов в профиле пользователя.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['quick_facts'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Блок - Быстрые факты'),
    t('Вывод на главной странице'),
    t('<div class="quick-fact"><a href="[field_fact_url-url] class="quick-fact body-link">[body]</a>[field_fact_url]<div>'),
    t('Быстрые факты'),
    t('Представления-Фрагменты'),
    t('Профиль-Быстрые факты'),
    t('Вывод быстрых фактов в профиле пользователя.'),
    t('Элементов на страницу'),
    t('- Все -'),
    t('Пропустить'),
    t('« первая'),
    t('‹ предыдущая'),
    t('следующая ›'),
    t('последняя »'),
    t('Значение'),
    t('нет'),
    t('Процент'),
    t('Текст'),
    t('Ссылка'),
    t('не указана'),
    t('Ссылка на редактирование'),
    t('Ссылка на удаление'),
  );
  $export['quick_facts'] = $view;

  $view = new view();
  $view->name = 'resources';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Ресурсы';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'информации нет';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Поле: Набор данных */
  $handler->display->display_options['fields']['field_link_remote_file']['id'] = 'field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['table'] = 'field_data_field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['field'] = 'field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['label'] = '';
  $handler->display->display_options['fields']['field_link_remote_file']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_link_remote_file']['alter']['text'] = '<a href="[field_link_remote_file]" class="upload-link" target="_blank">Скачать</a>';
  $handler->display->display_options['fields']['field_link_remote_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_remote_file']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_link_remote_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_link_remote_file']['type'] = 'file_url_plain';
  /* Поле: Содержимое: Upload */
  $handler->display->display_options['fields']['field_upload']['id'] = 'field_upload';
  $handler->display->display_options['fields']['field_upload']['table'] = 'field_data_field_upload';
  $handler->display->display_options['fields']['field_upload']['field'] = 'field_upload';
  $handler->display->display_options['fields']['field_upload']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_upload']['label'] = '';
  $handler->display->display_options['fields']['field_upload']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_upload']['alter']['text'] = '[field_upload-fid]';
  $handler->display->display_options['fields']['field_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload']['type'] = 'recline_link_formatter';
  /* Поле: Содержимое: Data format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_format']['label'] = '';
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_format']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Детали';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['argument'] = '12311123';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
    'resource' => 'resource',
  );

  /* Display: Последняя версия набора */
  $handler = $view->new_display('panel_pane', 'Последняя версия набора', 'latest_resource');
  $handler->display->display_options['display_description'] = 'Вывод на странице Набора данных';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resources_target_id']['id'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['table'] = 'field_data_field_resources';
  $handler->display->display_options['relationships']['field_resources_target_id']['field'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['label'] = 'Ресурс';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Поле: Набор данных */
  $handler->display->display_options['fields']['field_link_remote_file']['id'] = 'field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['table'] = 'field_data_field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['field'] = 'field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_link_remote_file']['label'] = '';
  $handler->display->display_options['fields']['field_link_remote_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_remote_file']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_link_remote_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_link_remote_file']['type'] = 'recline_link_formatter';
  /* Поле: Содержимое: Upload */
  $handler->display->display_options['fields']['field_upload']['id'] = 'field_upload';
  $handler->display->display_options['fields']['field_upload']['table'] = 'field_data_field_upload';
  $handler->display->display_options['fields']['field_upload']['field'] = 'field_upload';
  $handler->display->display_options['fields']['field_upload']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_upload']['label'] = '';
  $handler->display->display_options['fields']['field_upload']['alter']['text'] = '[field_upload-fid]';
  $handler->display->display_options['fields']['field_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_upload']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload']['type'] = 'od_common_recline_link_formatter_multivolume';
  /* Поле: Содержимое: Data format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_format']['label'] = '';
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_format']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_format']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Детали';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'dataset-details';
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'dataset' => 'dataset',
  );
  $handler->display->display_options['pane_title'] = 'Последняя версия набора';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Набора данных';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: Nid',
    ),
  );

  /* Display: Гиперссылка (URL) на набор */
  $handler = $view->new_display('panel_pane', 'Гиперссылка (URL) на набор', 'actual_resource_version');
  $handler->display->display_options['display_description'] = 'Вывод на странице Набора данных в таблице, через Dynamic field.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resources_target_id']['id'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['table'] = 'field_data_field_resources';
  $handler->display->display_options['relationships']['field_resources_target_id']['field'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['label'] = 'Ресурс';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Поле: Набор данных */
  $handler->display->display_options['fields']['field_link_remote_file']['id'] = 'field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['table'] = 'field_data_field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['field'] = 'field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_link_remote_file']['label'] = '';
  $handler->display->display_options['fields']['field_link_remote_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_remote_file']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_link_remote_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_link_remote_file']['type'] = 'file_url_plain';
  /* Поле: Содержимое: Upload */
  $handler->display->display_options['fields']['field_upload']['id'] = 'field_upload';
  $handler->display->display_options['fields']['field_upload']['table'] = 'field_data_field_upload';
  $handler->display->display_options['fields']['field_upload']['field'] = 'field_upload';
  $handler->display->display_options['fields']['field_upload']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_upload']['label'] = '';
  $handler->display->display_options['fields']['field_upload']['alter']['text'] = '[field_upload-fid]';
  $handler->display->display_options['fields']['field_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_upload']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload']['type'] = 'recline_link_formatter';
  $handler->display->display_options['pane_title'] = 'Гиперссылка (URL) на набор';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Набора данных в таблице, через Dynamic field.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: Nid',
    ),
  );

  /* Display: Формат данных */
  $handler = $view->new_display('panel_pane', 'Формат данных', 'actual_resource_format');
  $handler->display->display_options['display_description'] = 'Вывод на странице Набора данных в таблице, через Dynamic field.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resources_target_id']['id'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['table'] = 'field_data_field_resources';
  $handler->display->display_options['relationships']['field_resources_target_id']['field'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['label'] = 'Ресурс';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Data format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_format']['label'] = '';
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_format']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_format']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['pane_title'] = 'Формат данных';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Набора данных в таблице, через Dynamic field.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: Nid',
    ),
  );

  /* Display: Описание структуры набора данных */
  $handler = $view->new_display('panel_pane', 'Описание структуры набора данных', 'actual_resource_structure');
  $handler->display->display_options['display_description'] = 'Вывод на странице Набора данных в таблице, через Dynamic field.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_resources_target_id']['id'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['table'] = 'field_data_field_resources';
  $handler->display->display_options['relationships']['field_resources_target_id']['field'] = 'field_resources_target_id';
  $handler->display->display_options['relationships']['field_resources_target_id']['label'] = 'Ресурс';
  $handler->display->display_options['relationships']['field_resources_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Поле: Структура открытых данных */
  $handler->display->display_options['fields']['field_link_structure_file']['id'] = 'field_link_structure_file';
  $handler->display->display_options['fields']['field_link_structure_file']['table'] = 'field_data_field_link_structure_file';
  $handler->display->display_options['fields']['field_link_structure_file']['field'] = 'field_link_structure_file';
  $handler->display->display_options['fields']['field_link_structure_file']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_link_structure_file']['label'] = '';
  $handler->display->display_options['fields']['field_link_structure_file']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_structure_file']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_link_structure_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_link_structure_file']['type'] = 'file_url_plain';
  /* Поле: Содержимое: Opendata structure */
  $handler->display->display_options['fields']['field_upload_structure']['id'] = 'field_upload_structure';
  $handler->display->display_options['fields']['field_upload_structure']['table'] = 'field_data_field_upload_structure';
  $handler->display->display_options['fields']['field_upload_structure']['field'] = 'field_upload_structure';
  $handler->display->display_options['fields']['field_upload_structure']['relationship'] = 'field_resources_target_id';
  $handler->display->display_options['fields']['field_upload_structure']['label'] = '';
  $handler->display->display_options['fields']['field_upload_structure']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_upload_structure']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_upload_structure']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload_structure']['type'] = 'file_url_plain';
  $handler->display->display_options['pane_title'] = 'Описание структуры набора данных';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Набора данных в таблице, через Dynamic field.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Содержимое: Nid',
    ),
  );

  /* Display: Ресурс RULES */
  $handler = $view->new_display('panel_pane', 'Ресурс RULES', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Используется для получения Ресурса Набора в правиле "Актуализация набора" и Публикация набора/Снятие с публикации';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Связь: Набор */
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['id'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['table'] = 'field_data_field_dataset_ref';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['field'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['ui_name'] = 'Набор';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['label'] = 'Набор';
  $handler->display->display_options['relationships']['field_dataset_ref_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Массовые операции: Содержимое */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'rules_component::rules_bind_user_to_copied_node' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_given_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::workflow_vbo_next_state_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'rules_component::rules_pub_resuest' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_on_completion_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_approve_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_link_set_reject_publisher_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::auto_entitylabel_entity_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_promote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_dataset_is_recommended' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::od_import_import_organizations_opendata' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_assign_owner_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_rules_apply_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_publish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_reject_request' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_by_keyword_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_node_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_save_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpromote_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'rules_component::rules_dataset_isnt_recommended' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Содержимое: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_dataset_ref_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Содержимое: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  $handler->display->display_options['pane_title'] = 'Ресурс набора';
  $handler->display->display_options['pane_description'] = 'Используется для получения Ресурса Набора в правиле "Актуализация набора"';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $translatables['resources'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('информации нет'),
    t('<a href="[field_link_remote_file]" class="upload-link" target="_blank">Скачать</a>'),
    t('[field_upload-fid]'),
    t('Детали'),
    t('Все'),
    t('Последняя версия набора'),
    t('Вывод на странице Набора данных'),
    t('Ресурс'),
    t('Представления-Фрагменты'),
    t('Гиперссылка (URL) на набор'),
    t('Вывод на странице Набора данных в таблице, через Dynamic field.'),
    t('Формат данных'),
    t('Описание структуры набора данных'),
    t('Ресурс RULES'),
    t('Используется для получения Ресурса Набора в правиле "Актуализация набора" и Публикация набора/Снятие с публикации'),
    t('Набор'),
    t('Заголовок'),
    t('Ресурс набора'),
    t('Используется для получения Ресурса Набора в правиле "Актуализация набора"'),
  );
  $export['resources'] = $view;

  $view = new view();
  $view->name = 'revisions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Ревизии';
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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['layout'] = 'threecol_33_34_33';
  $handler->display->display_options['row_options']['regions'] = array(
    'field_format-revision_id' => 'left',
    'title' => 'middle',
    'body-revision_id' => 'middle',
    'field_link_remote_file-revision_id' => 'right',
    'timestamp' => 'right',
    'field_upload-revision_id' => 'right',
  );
  /* Шапка: Глобальный: Сводка результатов */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2>Список версий (@total)</h2>';
  /* Поле: Содержимое (исторические данные): Data format */
  $handler->display->display_options['fields']['field_format-revision_id']['id'] = 'field_format-revision_id';
  $handler->display->display_options['fields']['field_format-revision_id']['table'] = 'field_revision_field_format';
  $handler->display->display_options['fields']['field_format-revision_id']['field'] = 'field_format-revision_id';
  $handler->display->display_options['fields']['field_format-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_format-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_format-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Поле: Редакции материала: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Содержимое (исторические данные): Содержание */
  $handler->display->display_options['fields']['body-revision_id']['id'] = 'body-revision_id';
  $handler->display->display_options['fields']['body-revision_id']['table'] = 'field_revision_body';
  $handler->display->display_options['fields']['body-revision_id']['field'] = 'body-revision_id';
  $handler->display->display_options['fields']['body-revision_id']['label'] = '';
  $handler->display->display_options['fields']['body-revision_id']['element_label_colon'] = FALSE;
  /* Поле: Поле (исторические данные): Набор данных */
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['id'] = 'field_link_remote_file-revision_id';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['table'] = 'field_revision_field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['field'] = 'field_link_remote_file-revision_id';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['alter']['text'] = '<a href="[field_link_remote_file]" class="upload-link" target="_blank">Скачать</a>';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['type'] = 'file_url_plain';
  /* Поле: Редакции материала: Дата обновления */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'date_only';
  /* Критерий сортировки: Редакции материала: Vid */
  $handler->display->display_options['sorts']['vid']['id'] = 'vid';
  $handler->display->display_options['sorts']['vid']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['vid']['field'] = 'vid';
  /* Контекстный фильтр: Редакции материала: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Версии Ресурсов */
  $handler = $view->new_display('panel_pane', 'Версии Ресурсов', 'resource_versions');
  $handler->display->display_options['display_description'] = 'Вывод на странице Набора данных. Выводятся прошлые версии Ресурса, прикрепленных к Набору Данных.';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Элементов на страницу';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Все -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Пропустить';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« первая';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ предыдущая';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'следующая ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'последняя »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['layout'] = 'threecol_33_34_33';
  $handler->display->display_options['row_options']['regions'] = array(
    'field_format-revision_id' => 'left',
    'title' => 'right',
    'body-revision_id' => 'right',
    'field_link_remote_file-revision_id' => 'middle',
    'field_upload-revision_id' => 'middle',
    'timestamp' => 'middle',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<div class="view-header">
      <h2>Список версий</h2>   
      <div>Версии отсутствуют</div>
 </div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое (исторические данные): Data format */
  $handler->display->display_options['fields']['field_format-revision_id']['id'] = 'field_format-revision_id';
  $handler->display->display_options['fields']['field_format-revision_id']['table'] = 'field_revision_field_format';
  $handler->display->display_options['fields']['field_format-revision_id']['field'] = 'field_format-revision_id';
  $handler->display->display_options['fields']['field_format-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_format-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_format-revision_id']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Поле: Редакции материала: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Содержимое (исторические данные): Содержание */
  $handler->display->display_options['fields']['body-revision_id']['id'] = 'body-revision_id';
  $handler->display->display_options['fields']['body-revision_id']['table'] = 'field_revision_body';
  $handler->display->display_options['fields']['body-revision_id']['field'] = 'body-revision_id';
  $handler->display->display_options['fields']['body-revision_id']['label'] = '';
  $handler->display->display_options['fields']['body-revision_id']['element_label_colon'] = FALSE;
  /* Поле: Поле (исторические данные): Набор данных */
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['id'] = 'field_link_remote_file-revision_id';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['table'] = 'field_revision_field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['field'] = 'field_link_remote_file-revision_id';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['type'] = 'recline_link_formatter';
  /* Поле: Содержимое (исторические данные): Upload */
  $handler->display->display_options['fields']['field_upload-revision_id']['id'] = 'field_upload-revision_id';
  $handler->display->display_options['fields']['field_upload-revision_id']['table'] = 'field_revision_field_upload';
  $handler->display->display_options['fields']['field_upload-revision_id']['field'] = 'field_upload-revision_id';
  $handler->display->display_options['fields']['field_upload-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_upload-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_upload-revision_id']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_upload-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload-revision_id']['type'] = 'recline_link_formatter';
  /* Поле: Редакции материала: Дата обновления */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'date_only';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Редакции материала: Vid */
  $handler->display->display_options['sorts']['vid']['id'] = 'vid';
  $handler->display->display_options['sorts']['vid']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['vid']['field'] = 'vid';
  $handler->display->display_options['sorts']['vid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Редакции материала: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Контекстный фильтр: Редакции материала: Vid */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['vid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['vid']['not'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Версии Ресурсов';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Набора данных. Выводятся прошлые версии Ресурса, прикрепленных к Набору Данных.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Редакции материала: Nid',
    ),
    'vid' => array(
      'type' => 'context',
      'context' => 'entity:node.vid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Редакции материала: Vid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Гиперссылки (URL) на версии набора данных */
  $handler = $view->new_display('panel_pane', 'Гиперссылки (URL) на версии набора данных', 'versions_datasets');
  $handler->display->display_options['display_description'] = 'Вывод на странице Набора данных в таблице через Dynamic field. Выводятся прошлые версии Ресурса, прикрепленных к Набору Данных.';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['row_options']['layout'] = 'zen_no_wrapper';
  $handler->display->display_options['row_options']['regions'] = array(
    'field_link_remote_file-revision_id' => 'main',
    'field_upload-revision_id' => 'main',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'информации нет';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Поле (исторические данные): Набор данных */
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['id'] = 'field_link_remote_file-revision_id';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['table'] = 'field_revision_field_link_remote_file';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['field'] = 'field_link_remote_file-revision_id';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_link_remote_file-revision_id']['type'] = 'file_url_plain';
  /* Поле: Содержимое (исторические данные): Upload */
  $handler->display->display_options['fields']['field_upload-revision_id']['id'] = 'field_upload-revision_id';
  $handler->display->display_options['fields']['field_upload-revision_id']['table'] = 'field_revision_field_upload';
  $handler->display->display_options['fields']['field_upload-revision_id']['field'] = 'field_upload-revision_id';
  $handler->display->display_options['fields']['field_upload-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_upload-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_upload-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload-revision_id']['type'] = 'recline_link_formatter';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Редакции материала: Vid */
  $handler->display->display_options['sorts']['vid']['id'] = 'vid';
  $handler->display->display_options['sorts']['vid']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['vid']['field'] = 'vid';
  $handler->display->display_options['sorts']['vid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Редакции материала: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Контекстный фильтр: Редакции материала: Vid */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['vid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['vid']['not'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Гиперссылки (URL) на версии набора данных';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Набора данных в таблице через Dynamic field. Выводятся прошлые версии Ресурса, прикрепленных к Набору Данных.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.field_resources',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Редакции материала: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Гиперссылки (URL) на версии структуры набора данных */
  $handler = $view->new_display('panel_pane', 'Гиперссылки (URL) на версии структуры набора данных', 'versions_datasets_structure');
  $handler->display->display_options['display_description'] = 'Вывод на странице Набора данных в таблице через Dynamic field. Выводятся прошлые версии Ресурса, прикрепленных к Набору Данных.';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['row_options']['layout'] = 'zen_no_wrapper';
  $handler->display->display_options['row_options']['regions'] = array(
    'field_link_remote_file-revision_id' => 'main',
    'field_upload-revision_id' => 'main',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'информации нет';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Поле (исторические данные): Структура открытых данных */
  $handler->display->display_options['fields']['field_link_structure_file-revision_id']['id'] = 'field_link_structure_file-revision_id';
  $handler->display->display_options['fields']['field_link_structure_file-revision_id']['table'] = 'field_revision_field_link_structure_file';
  $handler->display->display_options['fields']['field_link_structure_file-revision_id']['field'] = 'field_link_structure_file-revision_id';
  $handler->display->display_options['fields']['field_link_structure_file-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_link_structure_file-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link_structure_file-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_link_structure_file-revision_id']['type'] = 'file_url_plain';
  /* Поле: Содержимое (исторические данные): Opendata structure */
  $handler->display->display_options['fields']['field_upload_structure-revision_id']['id'] = 'field_upload_structure-revision_id';
  $handler->display->display_options['fields']['field_upload_structure-revision_id']['table'] = 'field_revision_field_upload_structure';
  $handler->display->display_options['fields']['field_upload_structure-revision_id']['field'] = 'field_upload_structure-revision_id';
  $handler->display->display_options['fields']['field_upload_structure-revision_id']['label'] = '';
  $handler->display->display_options['fields']['field_upload_structure-revision_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_upload_structure-revision_id']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_upload_structure-revision_id']['type'] = 'file_url_plain';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерий сортировки: Редакции материала: Vid */
  $handler->display->display_options['sorts']['vid']['id'] = 'vid';
  $handler->display->display_options['sorts']['vid']['table'] = 'node_revision';
  $handler->display->display_options['sorts']['vid']['field'] = 'vid';
  $handler->display->display_options['sorts']['vid']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Редакции материала: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Контекстный фильтр: Редакции материала: Vid */
  $handler->display->display_options['arguments']['vid']['id'] = 'vid';
  $handler->display->display_options['arguments']['vid']['table'] = 'node_revision';
  $handler->display->display_options['arguments']['vid']['field'] = 'vid';
  $handler->display->display_options['arguments']['vid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['vid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['vid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['vid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['vid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['vid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['vid']['not'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Гиперссылки (URL) на версии набора данных';
  $handler->display->display_options['pane_description'] = 'Вывод на странице Набора данных в таблице через Dynamic field. Выводятся прошлые версии Ресурса, прикрепленных к Набору Данных.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.field_resources',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Редакции материала: Nid',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['revisions'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('<h2>Список версий (@total)</h2>'),
    t('<a href="[field_link_remote_file]" class="upload-link" target="_blank">Скачать</a>'),
    t('Все'),
    t('Версии Ресурсов'),
    t('Вывод на странице Набора данных. Выводятся прошлые версии Ресурса, прикрепленных к Набору Данных.'),
    t('<div class="view-header">
      <h2>Список версий</h2>   
      <div>Версии отсутствуют</div>
 </div>'),
    t('Представления-Фрагменты'),
    t('Гиперссылки (URL) на версии набора данных'),
    t('Вывод на странице Набора данных в таблице через Dynamic field. Выводятся прошлые версии Ресурса, прикрепленных к Набору Данных.'),
    t('информации нет'),
    t('Гиперссылки (URL) на версии структуры набора данных'),
  );
  $export['revisions'] = $view;

  $view = new view();
  $view->name = 'rubric_nodes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Материалы рубрик';
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
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>По этой рубрике пока нет материалов</p>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерий сортировки: Содержимое: Дата публикации */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'rubrics' => 'rubrics',
  );
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
    'blog' => 'blog',
    'news' => 'news',
  );

  /* Display: Материалы рубрики */
  $handler = $view->new_display('panel_pane', 'Материалы рубрики', 'rubric_content');
  $handler->display->display_options['display_description'] = 'Вывод материалов рубрики на странице рубрики';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: Текстовое поле */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="gutter"></span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Поле: Рубрика (field_rubric) */
  $handler->display->display_options['arguments']['field_rubric_tid']['id'] = 'field_rubric_tid';
  $handler->display->display_options['arguments']['field_rubric_tid']['table'] = 'field_data_field_rubric';
  $handler->display->display_options['arguments']['field_rubric_tid']['field'] = 'field_rubric_tid';
  $handler->display->display_options['arguments']['field_rubric_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_rubric_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_rubric_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_rubric_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_rubric_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_rubric_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_rubric_tid']['validate_options']['vocabularies'] = array(
    'rubrics' => 'rubrics',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'blog' => 'blog',
    'news' => 'news',
  );
  $handler->display->display_options['pane_title'] = 'Материалы рубрики';
  $handler->display->display_options['pane_description'] = 'Вывод материалов рубрики на странице рубрики';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['argument_input'] = array(
    'field_rubric_tid' => array(
      'type' => 'none',
      'context' => 'entity:universal_data_storage.bind-to',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Поле: Рубрика (field_rubric)',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['rubric_nodes'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('<p>По этой рубрике пока нет материалов</p>'),
    t('Все'),
    t('Материалы рубрики'),
    t('Вывод материалов рубрики на странице рубрики'),
    t('<span class="gutter"></span>'),
    t('Представления-Фрагменты'),
  );
  $export['rubric_nodes'] = $view;

  $view = new view();
  $view->name = 'rubrics';
  $view->description = 'Термины таксономии';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Рубрики';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'front_page';
  /* Связь: Термин таксономии: Материалы с термином */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Материалы';
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Критерий сортировки: Термин таксономии: Вес */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Критерий фильтра: Словарь таксономии: Машинное имя */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'rubrics' => 'rubrics',
  );

  /* Display: Рубрики на главной */
  $handler = $view->new_display('panel_pane', 'Рубрики на главной', 'rubrics_front');
  $handler->display->display_options['display_description'] = 'Вывод рубрик со связанными материалами на главной.';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Отправить';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'front_page';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: Текстовое поле */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Заголовок';
  $handler->display->display_options['header']['area']['content'] = '<div class="title"><?php print t(\'or select a topic\'); ?></div>';
  $handler->display->display_options['header']['area']['format'] = 'ds_code';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Подвал: Глобальный: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['php_output'] = '<div class="show-hide-toggle-wrapper">
   <span class="state-show"><a href="#"><?php print t(\'Show\'); ?></a></span>
   <span class="state-hide"><a href="#"><?php print t(\'Hide\'); ?></a></span>
</div>';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термин таксономии: Название */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Поле: Термин таксономии: ID термина */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Поле: Глобальный: Просмотр */
  $handler->display->display_options['fields']['view']['id'] = 'view';
  $handler->display->display_options['fields']['view']['table'] = 'views';
  $handler->display->display_options['fields']['view']['field'] = 'view';
  $handler->display->display_options['fields']['view']['label'] = '';
  $handler->display->display_options['fields']['view']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view']['view'] = 'rubrics';
  $handler->display->display_options['fields']['view']['display'] = 'rubrick_recent_content';
  $handler->display->display_options['fields']['view']['arguments'] = '[!tid]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерий фильтра: Словарь таксономии: Машинное имя */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'rubrics' => 'rubrics',
  );
  /* Критерий фильтра: Термин таксономии: Показывать на главной странице (field_show_front_page) */
  $handler->display->display_options['filters']['field_show_front_page_value']['id'] = 'field_show_front_page_value';
  $handler->display->display_options['filters']['field_show_front_page_value']['table'] = 'field_data_field_show_front_page';
  $handler->display->display_options['filters']['field_show_front_page_value']['field'] = 'field_show_front_page_value';
  $handler->display->display_options['filters']['field_show_front_page_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_front_page_value']['expose']['operator_id'] = 'field_show_front_page_value_op';
  $handler->display->display_options['filters']['field_show_front_page_value']['expose']['label'] = 'Показывать на главной странице (field_show_front_page)';
  $handler->display->display_options['filters']['field_show_front_page_value']['expose']['operator'] = 'field_show_front_page_value_op';
  $handler->display->display_options['filters']['field_show_front_page_value']['expose']['identifier'] = 'field_show_front_page_value';
  $handler->display->display_options['filters']['field_show_front_page_value']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_show_front_page_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['pane_title'] = 'Рубрики на главной';
  $handler->display->display_options['pane_description'] = 'Вывод рубрик со связанными материалами на главной.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Материалы рубрики */
  $handler = $view->new_display('panel_pane', 'Материалы рубрики', 'rubrick_recent_content');
  $handler->display->display_options['display_description'] = 'Используется в дисплее "Рубрики на главной". Выводит три последних материала рубрики.';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Содержимое: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'nid';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Термин таксономии: ID термина */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Материалы рубрики';
  $handler->display->display_options['pane_description'] = 'Используется в дисплее "Рубрики на главной". Выводит три последних материала рубрики.';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';

  /* Display: Модерация рубрик */
  $handler = $view->new_display('panel_pane', 'Модерация рубрик', 'rubricks_moderation');
  $handler->display->display_options['display_description'] = 'Вывод списка рубрик для модерации в профиле (закладка Модерация).';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Шапка: Глобальный: Текстовое поле */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/admin/structure/taxonomy/rubrics/add?destination=user/!1/moderation#tabs-0-center-10">Добавить рубрику</a>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстный фильтр: Глобальный: Ноль */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['pane_title'] = 'Модерация рубрик';
  $handler->display->display_options['pane_description'] = 'Вывод списка рубрик для модерации в профиле (закладка Модерация).';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['rubrics'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
    t('Сбросить'),
    t('Сортировать по'),
    t('По возрастанию'),
    t('По убыванию'),
    t('Материалы'),
    t('Рубрики на главной'),
    t('Вывод рубрик со связанными материалами на главной.'),
    t('Отправить'),
    t('Заголовок'),
    t('<div class="title"><?php print t(\'or select a topic\'); ?></div>'),
    t('.'),
    t(','),
    t('Показывать на главной странице (field_show_front_page)'),
    t('Представления-Фрагменты'),
    t('Материалы рубрики'),
    t('Используется в дисплее "Рубрики на главной". Выводит три последних материала рубрики.'),
    t('Все'),
    t('Модерация рубрик'),
    t('Вывод списка рубрик для модерации в профиле (закладка Модерация).'),
    t('<a href="/admin/structure/taxonomy/rubrics/add?destination=user/!1/moderation#tabs-0-center-10">Добавить рубрику</a>'),
  );
  $export['rubrics'] = $view;

  $view = new view();
  $view->name = 'statistic';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Статистика';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ещё';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Submit';
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
  $handler->display->display_options['style_plugin'] = 'views_dataviz';
  $handler->display->display_options['style_options']['type'] = 'AreaChart';
  $handler->display->display_options['style_options']['_curveType'] = '0';
  $handler->display->display_options['style_options']['chart_area_left'] = '90';
  $handler->display->display_options['style_options']['chart_area_top'] = '50';
  /* Поведение при отсутствии результатов: Глобальный: Текстовое поле */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Результаты отсутствуют.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Поле: COUNT(Содержимое: Заголовок) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['group_type'] = 'count';
  $handler->display->display_options['fields']['title']['label'] = 'Количество добавленных наборов';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd-M-Y';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
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
    'dataset' => 'dataset',
  );

  /* Display: График */
  $handler = $view->new_display('panel_pane', 'График', 'chart_datasets');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Diagram';
  $handler->display->display_options['display_description'] = 'Выводит информацию по количеству добавленных наборов за промежуток времени в виде диаграммы в разделе статистики';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: COUNT(Содержимое: Заголовок) */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['group_type'] = 'count';
  $handler->display->display_options['fields']['title']['label'] = 'Количество добавленных наборов';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Содержимое: Дата публикации */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd-M-Y';
  $handler->display->display_options['fields']['created']['format_date_sql'] = 1;
  $handler->display->display_options['pane_title'] = 'График';
  $handler->display->display_options['pane_description'] = 'Выводит информацию по количеству добавленных наборов за промежуток времени в виде диаграммы в разделе статистики';
  $handler->display->display_options['pane_category']['name'] = 'Представления-Фрагменты';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $translatables['statistic'] = array(
    t('Master'),
    t('ещё'),
    t('Submit'),
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
    t('Результаты отсутствуют.'),
    t('Количество добавленных наборов'),
    t('График'),
    t('Diagram'),
    t('Выводит информацию по количеству добавленных наборов за промежуток времени в виде диаграммы в разделе статистики'),
    t('Представления-Фрагменты'),
  );
  $export['statistic'] = $view;

  return $export;
}
