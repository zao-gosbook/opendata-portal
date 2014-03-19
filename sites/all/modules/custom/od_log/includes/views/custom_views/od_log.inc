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
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Применить';
$handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Сбросить';
$handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Сортировать по';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'По возрастанию';
$handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'По убыванию';
$handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
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
);
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
'created' => 'created',
'field_organization' => 'field_organization',
'message' => 'message',
'name' => 'name',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
'created' => array(
'sortable' => 1,
'default_sort_order' => 'asc',
'align' => '',
'separator' => '',
'empty_column' => 0,
),
'field_organization' => array(
'sortable' => 1,
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
/* Поле: Организация */
$handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
$handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
$handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
$handler->display->display_options['fields']['field_organization']['ui_name'] = 'Организация';
$handler->display->display_options['fields']['field_organization']['label'] = 'Организация';
$handler->display->display_options['fields']['field_organization']['element_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_organization']['settings'] = array(
'link' => 1,
'conditions' => array(
0 => array(
'condition' => '',
),
),
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
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Поле: Массовые операции */
$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'log';
$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
$handler->display->display_options['fields']['views_bulk_operations']['ui_name'] = 'Массовые операции';
$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
$handler->display->display_options['fields']['views_bulk_operations']['element_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['views_bulk_operations']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = FALSE;
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
'action::od_log_notify_organization' => array(
'selected' => 1,
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
/* Поле: Организация */
$handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
$handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
$handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
$handler->display->display_options['fields']['field_organization']['ui_name'] = 'Организация';
$handler->display->display_options['fields']['field_organization']['label'] = 'Организация';
$handler->display->display_options['fields']['field_organization']['element_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_organization']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_organization']['settings'] = array(
'link' => 1,
'conditions' => array(
0 => array(
'condition' => '',
),
),
);
/* Поле: Набор данных */
$handler->display->display_options['fields']['field_dataset']['id'] = 'field_dataset';
$handler->display->display_options['fields']['field_dataset']['table'] = 'field_data_field_dataset';
$handler->display->display_options['fields']['field_dataset']['field'] = 'field_dataset';
$handler->display->display_options['fields']['field_dataset']['ui_name'] = 'Набор данных';
$handler->display->display_options['fields']['field_dataset']['label'] = 'Набор данных';
$handler->display->display_options['fields']['field_dataset']['element_type'] = '0';
$handler->display->display_options['fields']['field_dataset']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_dataset']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_dataset']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_dataset']['settings'] = array(
'link' => 1,
'conditions' => array(
0 => array(
'condition' => '',
),
),
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
/* Поле: Куратор уведомлен */
$handler->display->display_options['fields']['field_curator_was_notified']['id'] = 'field_curator_was_notified';
$handler->display->display_options['fields']['field_curator_was_notified']['table'] = 'field_data_field_curator_was_notified';
$handler->display->display_options['fields']['field_curator_was_notified']['field'] = 'field_curator_was_notified';
$handler->display->display_options['fields']['field_curator_was_notified']['ui_name'] = 'Куратор уведомлен';
$handler->display->display_options['fields']['field_curator_was_notified']['element_type'] = '0';
$handler->display->display_options['fields']['field_curator_was_notified']['element_label_type'] = '0';
$handler->display->display_options['fields']['field_curator_was_notified']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['field_curator_was_notified']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_curator_was_notified']['settings'] = array(
'conditions' => array(
0 => array(
'condition' => '',
),
),
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Критерий фильтра: Тип лога */
$handler->display->display_options['filters']['field_log_event_type_value']['id'] = 'field_log_event_type_value';
$handler->display->display_options['filters']['field_log_event_type_value']['table'] = 'field_data_field_log_event_type';
$handler->display->display_options['filters']['field_log_event_type_value']['field'] = 'field_log_event_type_value';
$handler->display->display_options['filters']['field_log_event_type_value']['ui_name'] = 'Тип лога';
$handler->display->display_options['filters']['field_log_event_type_value']['value'] = array(
'import_data' => 'import_data',
);
/* Критерий фильтра: Организация */
$handler->display->display_options['filters']['field_organization_target_id']['id'] = 'field_organization_target_id';
$handler->display->display_options['filters']['field_organization_target_id']['table'] = 'field_data_field_organization';
$handler->display->display_options['filters']['field_organization_target_id']['field'] = 'field_organization_target_id';
$handler->display->display_options['filters']['field_organization_target_id']['ui_name'] = 'Организация';
$handler->display->display_options['filters']['field_organization_target_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_organization_target_id']['expose']['operator_id'] = 'field_organization_target_id_op';
$handler->display->display_options['filters']['field_organization_target_id']['expose']['label'] = 'Организация';
$handler->display->display_options['filters']['field_organization_target_id']['expose']['operator'] = 'field_organization_target_id_op';
$handler->display->display_options['filters']['field_organization_target_id']['expose']['identifier'] = 'opendata_log_organization';
$handler->display->display_options['filters']['field_organization_target_id']['expose']['remember_roles'] = array(
2 => '2',
1 => 0,
6 => 0,
3 => 0,
4 => 0,
5 => 0,
);
/* Критерий фильтра: Куратор уведомлен */
$handler->display->display_options['filters']['field_curator_was_notified_value']['id'] = 'field_curator_was_notified_value';
$handler->display->display_options['filters']['field_curator_was_notified_value']['table'] = 'field_data_field_curator_was_notified';
$handler->display->display_options['filters']['field_curator_was_notified_value']['field'] = 'field_curator_was_notified_value';
$handler->display->display_options['filters']['field_curator_was_notified_value']['ui_name'] = 'Куратор уведомлен';
$handler->display->display_options['filters']['field_curator_was_notified_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_curator_was_notified_value']['expose']['operator_id'] = 'field_curator_was_notified_value_op';
$handler->display->display_options['filters']['field_curator_was_notified_value']['expose']['label'] = 'Куратор уведомлен';
$handler->display->display_options['filters']['field_curator_was_notified_value']['expose']['operator'] = 'field_curator_was_notified_value_op';
$handler->display->display_options['filters']['field_curator_was_notified_value']['expose']['identifier'] = 'opendata_log_curator_was_notified';
$handler->display->display_options['filters']['field_curator_was_notified_value']['expose']['remember_roles'] = array(
2 => '2',
1 => 0,
6 => 0,
3 => 0,
4 => 0,
5 => 0,
);
$handler->display->display_options['path'] = 'opendata-log';

/* Display: Журнал набора открытых данных */
$handler = $view->new_display('page', 'Журнал набора открытых данных', 'opendata_meta_log');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Поле: Время */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'log';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['ui_name'] = 'Время';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_type'] = '0';
$handler->display->display_options['fields']['created']['element_label_type'] = '0';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'comment';
$handler->display->display_options['fields']['created']['format_date_sql'] = 0;
/* Поле: Тип лога */
$handler->display->display_options['fields']['field_log_event_type']['id'] = 'field_log_event_type';
$handler->display->display_options['fields']['field_log_event_type']['table'] = 'field_data_field_log_event_type';
$handler->display->display_options['fields']['field_log_event_type']['field'] = 'field_log_event_type';
$handler->display->display_options['fields']['field_log_event_type']['ui_name'] = 'Тип лога';
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
$handler->display->display_options['fields']['field_log_event_type']['settings'] = array(
'conditions' => array(
0 => array(
'condition' => '',
),
),
);
/* Поле: Сообщение */
$handler->display->display_options['fields']['message']['id'] = 'message';
$handler->display->display_options['fields']['message']['table'] = 'log';
$handler->display->display_options['fields']['message']['field'] = 'message';
$handler->display->display_options['fields']['message']['ui_name'] = 'Сообщение';
$handler->display->display_options['fields']['message']['label'] = '';
$handler->display->display_options['fields']['message']['element_type'] = '0';
$handler->display->display_options['fields']['message']['element_label_type'] = '0';
$handler->display->display_options['fields']['message']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['message']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['message']['element_default_classes'] = FALSE;
/* Поле: Полное имя */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'log_related_user';
$handler->display->display_options['fields']['name']['ui_name'] = 'Полное имя';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['name']['alter']['text'] = 'Изменено: [name]';
$handler->display->display_options['fields']['name']['element_type'] = '0';
$handler->display->display_options['fields']['name']['element_label_type'] = '0';
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['element_wrapper_type'] = '0';
$handler->display->display_options['fields']['name']['element_default_classes'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Контекстный фильтр: ID набора открытых данных */
$handler->display->display_options['arguments']['field_dataset_target_id']['id'] = 'field_dataset_target_id';
$handler->display->display_options['arguments']['field_dataset_target_id']['table'] = 'field_data_field_dataset';
$handler->display->display_options['arguments']['field_dataset_target_id']['field'] = 'field_dataset_target_id';
$handler->display->display_options['arguments']['field_dataset_target_id']['ui_name'] = 'ID набора открытых данных';
$handler->display->display_options['arguments']['field_dataset_target_id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['field_dataset_target_id']['exception']['value'] = '';
$handler->display->display_options['arguments']['field_dataset_target_id']['exception']['title'] = 'Все';
$handler->display->display_options['arguments']['field_dataset_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_dataset_target_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_dataset_target_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_dataset_target_id']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_dataset_target_id']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['field_dataset_target_id']['validate']['type'] = 'node';
$handler->display->display_options['arguments']['field_dataset_target_id']['validate_options']['types'] = array(
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
t('Время'),
t('Организация'),
t('Сообщение'),
t('Журнал открытых данных'),
t('Набор данных'),
t('Куратор уведомлен'),
t('Журнал набора открытых данных'),
t('<div class="[field_log_event_type]"></div>'),
t('Изменено: [name]'),
t('Все'),
);
