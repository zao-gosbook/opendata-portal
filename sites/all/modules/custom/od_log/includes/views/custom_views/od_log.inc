<?php

$view = new view();
$view->name = 'opendata_log';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'log';
$view->human_name = 'Opendata log';
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
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['columns'] = array(
  'field_log_event_type' => 'field_log_event_type',
  'created' => 'created',
  'message' => 'message',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'field_log_event_type' => array(
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
  'message' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['style_options']['override'] = FALSE;
/* Поведение при отсутствии результатов: Журнал пуст */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['ui_name'] = 'Журнал пуст';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'Событий в журнале не зарегистрировано.';
$handler->display->display_options['empty']['area']['format'] = 'full_html';
/* Связь: User */
$handler->display->display_options['relationships']['log_related_user']['id'] = 'log_related_user';
$handler->display->display_options['relationships']['log_related_user']['table'] = 'log';
$handler->display->display_options['relationships']['log_related_user']['field'] = 'log_related_user';
$handler->display->display_options['relationships']['log_related_user']['ui_name'] = 'User';
$handler->display->display_options['relationships']['log_related_user']['label'] = 'User';
/* Поле: Организация */
$handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
$handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
$handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
$handler->display->display_options['fields']['field_organization']['ui_name'] = 'Организация';
$handler->display->display_options['fields']['field_organization']['element_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_organization']['settings'] = array(
  'link' => 1,
);
/* Поле: Время */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'log';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['ui_name'] = 'Время';
$handler->display->display_options['fields']['created']['label'] = 'Время';
$handler->display->display_options['fields']['created']['element_type'] = '0';
$handler->display->display_options['fields']['created']['element_label_type'] = '0';
$handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'comment';
$handler->display->display_options['fields']['created']['format_date_sql'] = 0;
/* Поле: Набор данных */
$handler->display->display_options['fields']['field_dataset_ref']['id'] = 'field_dataset_ref';
$handler->display->display_options['fields']['field_dataset_ref']['table'] = 'field_data_field_dataset_ref';
$handler->display->display_options['fields']['field_dataset_ref']['field'] = 'field_dataset_ref';
$handler->display->display_options['fields']['field_dataset_ref']['ui_name'] = 'Набор данных';
$handler->display->display_options['fields']['field_dataset_ref']['label'] = 'Набор данных';
$handler->display->display_options['fields']['field_dataset_ref']['element_type'] = '0';
$handler->display->display_options['fields']['field_dataset_ref']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_dataset_ref']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_dataset_ref']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_dataset_ref']['settings'] = array(
  'link' => 1,
);
/* Поле: Сообщение */
$handler->display->display_options['fields']['message']['id'] = 'message';
$handler->display->display_options['fields']['message']['table'] = 'log';
$handler->display->display_options['fields']['message']['field'] = 'message';
$handler->display->display_options['fields']['message']['ui_name'] = 'Сообщение';
$handler->display->display_options['fields']['message']['element_type'] = '0';
$handler->display->display_options['fields']['message']['element_label_type'] = '0';
$handler->display->display_options['fields']['message']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['message']['element_default_classes'] = FALSE;
/* Критерий сортировки: По времени */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'log';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['ui_name'] = 'По времени';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';

/* Display: Журнал открытых данных */
$handler = $view->new_display('page', 'Журнал открытых данных', 'opendata_log');
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Критерий фильтра: Log: Тип лога (field_log_event_type) */
$handler->display->display_options['filters']['field_log_event_type_value']['id'] = 'field_log_event_type_value';
$handler->display->display_options['filters']['field_log_event_type_value']['table'] = 'field_data_field_log_event_type';
$handler->display->display_options['filters']['field_log_event_type_value']['field'] = 'field_log_event_type_value';
$handler->display->display_options['filters']['field_log_event_type_value']['value'] = array(
  'import_data' => 'import_data',
);
$handler->display->display_options['path'] = 'opendata-log';

/* Display: Журнал набора открытых данных */
$handler = $view->new_display('page', 'Журнал набора открытых данных', 'opendata_meta_log');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Поле: Тип лога (исключено) */
$handler->display->display_options['fields']['field_log_event_type']['id'] = 'field_log_event_type';
$handler->display->display_options['fields']['field_log_event_type']['table'] = 'field_data_field_log_event_type';
$handler->display->display_options['fields']['field_log_event_type']['field'] = 'field_log_event_type';
$handler->display->display_options['fields']['field_log_event_type']['ui_name'] = 'Тип лога (исключено)';
$handler->display->display_options['fields']['field_log_event_type']['label'] = '';
$handler->display->display_options['fields']['field_log_event_type']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_log_event_type']['alter']['text'] = '<div class="[field_log_event_type]"></div>';
$handler->display->display_options['fields']['field_log_event_type']['element_type'] = '0';
$handler->display->display_options['fields']['field_log_event_type']['element_class'] = 'icon';
$handler->display->display_options['fields']['field_log_event_type']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_log_event_type']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_log_event_type']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_log_event_type']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_log_event_type']['type'] = 'list_key';
/* Поле: Фото */
$handler->display->display_options['fields']['picture']['id'] = 'picture';
$handler->display->display_options['fields']['picture']['table'] = 'users';
$handler->display->display_options['fields']['picture']['field'] = 'picture';
$handler->display->display_options['fields']['picture']['relationship'] = 'log_related_user';
$handler->display->display_options['fields']['picture']['ui_name'] = 'Фото';
$handler->display->display_options['fields']['picture']['label'] = '';
$handler->display->display_options['fields']['picture']['element_type'] = '0';
$handler->display->display_options['fields']['picture']['element_label_type'] = '0';
$handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['picture']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['picture']['image_style'] = 'avatar-45x45';
/* Поле: Время */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'log';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['ui_name'] = 'Время';
$handler->display->display_options['fields']['created']['label'] = 'Время';
$handler->display->display_options['fields']['created']['element_type'] = '0';
$handler->display->display_options['fields']['created']['element_label_type'] = '0';
$handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'comment';
$handler->display->display_options['fields']['created']['format_date_sql'] = 0;
/* Поле: Сообщение */
$handler->display->display_options['fields']['message']['id'] = 'message';
$handler->display->display_options['fields']['message']['table'] = 'log';
$handler->display->display_options['fields']['message']['field'] = 'message';
$handler->display->display_options['fields']['message']['ui_name'] = 'Сообщение';
$handler->display->display_options['fields']['message']['element_type'] = '0';
$handler->display->display_options['fields']['message']['element_label_type'] = '0';
$handler->display->display_options['fields']['message']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['message']['element_default_classes'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Контекстный фильтр: ID набора открытых данных */
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['id'] = 'field_dataset_ref_target_id';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['table'] = 'field_data_field_dataset_ref';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['field'] = 'field_dataset_ref_target_id';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['ui_name'] = 'ID набора открытых данных';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['exception']['title'] = 'Все';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['validate']['type'] = 'node';
$handler->display->display_options['arguments']['field_dataset_ref_target_id']['validate_options']['types'] = array(
  'dataset' => 'dataset',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Критерий фильтра: Log: Тип лога (field_log_event_type) */
$handler->display->display_options['filters']['field_log_event_type_value']['id'] = 'field_log_event_type_value';
$handler->display->display_options['filters']['field_log_event_type_value']['table'] = 'field_data_field_log_event_type';
$handler->display->display_options['filters']['field_log_event_type_value']['field'] = 'field_log_event_type_value';
$handler->display->display_options['filters']['field_log_event_type_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_log_event_type_value']['value'] = array(
  'import_data' => 'import_data',
);
$handler->display->display_options['path'] = 'node/%/opendata-log';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Журнал';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['opendata_log'] = array(
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
  t('Событий в журнале не зарегистрировано.'),
  t('User'),
  t('Владелец набора данных'),
  t('Время'),
  t('Набор данных'),
  t('Сообщение'),
  t('Журнал открытых данных'),
  t('Журнал набора открытых данных'),
  t('<div class="[field_log_event_type]"></div>'),
  t('Все'),
);
