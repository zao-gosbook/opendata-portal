<?php
/**
 * @file
 * nodes_breadcrumbs_pm_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function nodes_breadcrumbs_pm_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'blog_panel_context';
  $handler->task = 'blog';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Blog list',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
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
  $display->title = 'Blogs';
  $display->uuid = 'fad47eb7-99cd-4120-b34b-1b6a03b292f5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1839f820-8f86-4d33-b625-02af5e60e97a';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'perm',
          'settings' => array(
            'perm' => 'create blog content',
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'CUSTOM LINK',
      'title' => '',
      'body' => '<?php
print t(\'<div class="pane-btn"><a class="btn" href="@url">Add blog</a></div>\', array(\'@url\' => url(\'node/add/blog\')));
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
    $pane->uuid = '1839f820-8f86-4d33-b625-02af5e60e97a';
    $display->content['new-1839f820-8f86-4d33-b625-02af5e60e97a'] = $pane;
    $display->panels['main'][0] = 'new-1839f820-8f86-4d33-b625-02af5e60e97a';
    $pane = new stdClass();
    $pane->pid = 'new-360784f5-29e7-4678-8ea5-1e2b12504aec';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'blogs-list_blogs';
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
    $pane->uuid = '360784f5-29e7-4678-8ea5-1e2b12504aec';
    $display->content['new-360784f5-29e7-4678-8ea5-1e2b12504aec'] = $pane;
    $display->panels['main'][1] = 'new-360784f5-29e7-4678-8ea5-1e2b12504aec';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['blog_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Быстрые факты',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 1,
        'label' => 'Заголовок',
        'hidden_field' => '1',
      ),
      'body' => array(
        'override' => 0,
        'label' => 'Содержание',
        'hidden_field' => 0,
      ),
      'field_fact_decimal' => array(
        'override' => 0,
        'label' => 'Значение',
        'hidden_field' => 0,
      ),
      'field_fact_url' => array(
        'override' => 0,
        'label' => 'Ссылка',
        'hidden_field' => 0,
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
        'override' => 1,
        'label' => 'Удалить',
        'hidden_field' => '1',
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'quick_fact' => 'quick_fact',
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
  $export['node_edit_form_mutator'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_10';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 9;
  $handler->conf = array(
    'title' => 'Заявка на публикаторство (для Модератора)',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => '',
        'hidden_field' => 0,
      ),
      'field_pubreq_organization_exists' => array(
        'override' => 0,
        'label' => 'Organization exists',
        'hidden_field' => 0,
      ),
      'field_pubreq_created_org' => array(
        'override' => 0,
        'label' => 'Created organization',
        'hidden_field' => 0,
      ),
      'field_pubreq_phone' => array(
        'override' => 0,
        'label' => 'Phone',
        'hidden_field' => 0,
      ),
      'field_pubreq_status' => array(
        'override' => 0,
        'label' => 'pubreq_status',
        'hidden_field' => 1,
      ),
      'field_pubreq_user' => array(
        'override' => 1,
        'label' => 'pubreq_user',
        'hidden_field' => '1',
      ),
      'field_pubreq_selected_org' => array(
        'override' => 0,
        'label' => 'Selected organization',
        'hidden_field' => 0,
      ),
      'field_pubreg_post' => array(
        'override' => 0,
        'label' => 'Должность',
        'hidden_field' => 0,
      ),
      'field_pubreg_name' => array(
        'override' => 0,
        'label' => 'Имя',
        'hidden_field' => 0,
      ),
      'field_pubreg_surname' => array(
        'override' => 0,
        'label' => 'Фамилия',
        'hidden_field' => 0,
      ),
      'field_pubreg_patronymic' => array(
        'override' => 0,
        'label' => 'Отчество',
        'hidden_field' => 0,
      ),
      'field_pubreq_processed' => array(
        'override' => 1,
        'label' => 'pubreg_processed',
        'hidden_field' => '1',
      ),
      'field_pubreg_message' => array(
        'override' => 0,
        'label' => 'Сообщение',
        'hidden_field' => 0,
      ),
      'field_pubreg_reworked' => array(
        'override' => 1,
        'label' => 'Доработано',
        'hidden_field' => '2',
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
        'override' => 1,
        'label' => 'Удалить',
        'hidden_field' => '1',
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'publisher_request' => 'publisher_request',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
        2 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
  );
  $export['node_edit_form_mutator_10'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_11';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 10;
  $handler->conf = array(
    'title' => 'Заявка на публикаторство (для публикатора)',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => '',
        'hidden_field' => 0,
      ),
      'field_pubreq_organization_exists' => array(
        'override' => 0,
        'label' => 'Organization exists',
        'hidden_field' => 0,
      ),
      'field_pubreq_created_org' => array(
        'override' => 0,
        'label' => 'Created organization',
        'hidden_field' => 0,
      ),
      'field_pubreg_post' => array(
        'override' => 0,
        'label' => 'Должность',
        'hidden_field' => 0,
      ),
      'field_pubreq_phone' => array(
        'override' => 0,
        'label' => 'Phone',
        'hidden_field' => 0,
      ),
      'field_pubreq_status' => array(
        'override' => 1,
        'label' => 'pubreq_status',
        'hidden_field' => '1',
      ),
      'field_pubreq_user' => array(
        'override' => 1,
        'label' => 'pubreq_user',
        'hidden_field' => '1',
      ),
      'field_pubreq_selected_org' => array(
        'override' => 0,
        'label' => 'Selected organization',
        'hidden_field' => 0,
      ),
      'field_pubreg_message' => array(
        'override' => 1,
        'label' => 'Сообщение',
        'hidden_field' => '2',
      ),
      'field_pubreg_reworked' => array(
        'override' => 0,
        'label' => 'Доработано',
        'hidden_field' => 0,
      ),
      'field_pubreg_name' => array(
        'override' => 0,
        'label' => 'Имя',
        'hidden_field' => 0,
      ),
      'field_pubreg_surname' => array(
        'override' => 0,
        'label' => 'Фамилия',
        'hidden_field' => 0,
      ),
      'field_pubreg_patronymic' => array(
        'override' => 0,
        'label' => 'Отчество',
        'hidden_field' => 0,
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
        'override' => 1,
        'label' => 'Удалить',
        'hidden_field' => '1',
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'publisher_request' => 'publisher_request',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
  );
  $export['node_edit_form_mutator_11'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_2';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Приложение',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Название',
        'hidden_field' => 1,
      ),
      'field_app_mail' => array(
        'override' => 0,
        'label' => 'Почта',
        'hidden_field' => 0,
      ),
      'field_app_phone' => array(
        'override' => 0,
        'label' => 'Телефон',
        'hidden_field' => 0,
      ),
      'field_app_full_name' => array(
        'override' => 0,
        'label' => 'ФИО',
        'hidden_field' => 0,
      ),
      'field_app_url' => array(
        'override' => 0,
        'label' => 'Ссылка на приложение',
        'hidden_field' => 0,
      ),
      'field_app_url_datasets' => array(
        'override' => 0,
        'label' => 'Ссылка на используемые наборы',
        'hidden_field' => 0,
      ),
      'field_tags' => array(
        'override' => 0,
        'label' => 'Ключевые слова',
        'hidden_field' => 0,
      ),
      'field_fivestar' => array(
        'override' => 0,
        'label' => 'Fivestar',
        'hidden_field' => 0,
      ),
      'field_app_image' => array(
        'override' => 0,
        'label' => 'Изображение ',
        'hidden_field' => 0,
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
        'override' => 0,
        'label' => 'Настройки публикации',
        'hidden_field' => 0,
      ),
      ':revision_information' => array(
        'override' => 1,
        'label' => 'Информация о редакции',
        'hidden_field' => '1',
      ),
      ':redirect' => array(
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
              'app' => 'app',
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
  $export['node_edit_form_mutator_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_3';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Организация',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Название организации',
        'hidden_field' => 0,
      ),
      'field_organization_inn' => array(
        'override' => 0,
        'label' => 'ИНН',
        'hidden_field' => 0,
      ),
      'field_organization_type' => array(
        'override' => 0,
        'label' => 'Тип',
        'hidden_field' => 0,
      ),
      'field_site_url' => array(
        'override' => 0,
        'label' => 'Ссылка на сайт',
        'hidden_field' => 0,
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
      ),
      ':flag' => array(
        'override' => 0,
        'label' => 'Флаги',
        'hidden_field' => 0,
      ),
      ':actions:submit' => array(
        'override' => 0,
        'label' => 'Сохранить',
        'hidden_field' => 0,
      ),
      ':actions:preview' => array(
        'override' => 0,
        'label' => 'Предпросмотр',
        'hidden_field' => 0,
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
              'organization' => 'organization',
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
  $export['node_edit_form_mutator_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_4';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Новость',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Заголовок',
        'hidden_field' => 0,
      ),
      'body' => array(
        'override' => 0,
        'label' => 'Текст',
        'hidden_field' => 0,
      ),
      'field_image' => array(
        'override' => 0,
        'label' => 'Изображение',
        'hidden_field' => 0,
      ),
      'field_rubric' => array(
        'override' => 0,
        'label' => 'Рубрика',
        'hidden_field' => 0,
      ),
      'field_comments_count' => array(
        'override' => 1,
        'label' => 'Количество комментариев',
        'hidden_field' => '1',
      ),
      'field_date_created' => array(
        'override' => 1,
        'label' => 'Дата создания',
        'hidden_field' => '1',
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
        'override' => 0,
        'label' => 'Предпросмотр',
        'hidden_field' => 0,
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
              'news' => 'news',
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
  $export['node_edit_form_mutator_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_5';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Документ',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Название',
        'hidden_field' => 0,
      ),
      'body' => array(
        'override' => 0,
        'label' => 'Содержание',
        'hidden_field' => 0,
      ),
      'field_rubric' => array(
        'override' => 0,
        'label' => 'Рубрика',
        'hidden_field' => 0,
      ),
      'field_tags' => array(
        'override' => 0,
        'label' => 'Ключевые слова',
        'hidden_field' => 0,
      ),
      'field_document_file' => array(
        'override' => 0,
        'label' => 'Файл',
        'hidden_field' => 0,
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
              'document' => 'document',
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
  $export['node_edit_form_mutator_5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_6';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Идея',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Название идеи',
        'hidden_field' => 0,
      ),
      'body' => array(
        'override' => 0,
        'label' => 'Описание идеи',
        'hidden_field' => 0,
      ),
      'field_rubric' => array(
        'override' => 0,
        'label' => 'Рубрика',
        'hidden_field' => 0,
      ),
      'field_idea_vote_up_down' => array(
        'override' => 0,
        'label' => 'Голосовать',
        'hidden_field' => 0,
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
        'override' => 0,
        'label' => 'Предпросмотр',
        'hidden_field' => 0,
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
              'idea' => 'idea',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
  );
  $export['node_edit_form_mutator_6'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_7';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Набор данных',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Заголовок',
        'hidden_field' => 0,
      ),
      'body' => array(
        'override' => 0,
        'label' => 'Описание набора данных',
        'hidden_field' => 0,
      ),
      'field_additional_info' => array(
        'override' => 1,
        'label' => 'Additional Info',
        'hidden_field' => '1',
      ),
      'field_author' => array(
        'override' => 1,
        'label' => 'Author',
        'hidden_field' => '1',
      ),
      'field_contact_name' => array(
        'override' => 0,
        'label' => 'Ответственное лицо',
        'hidden_field' => 0,
      ),
      'field_data_dictionary' => array(
        'override' => 1,
        'label' => 'Data Dictionary',
        'hidden_field' => '1',
      ),
      'field_frequency' => array(
        'override' => 1,
        'label' => 'Периодичность актуализации набора данных',
        'hidden_field' => '1',
      ),
      'field_granularity' => array(
        'override' => 1,
        'label' => 'Granularity',
        'hidden_field' => '1',
      ),
      'field_license' => array(
        'override' => 0,
        'label' => 'Лицензия',
        'hidden_field' => 0,
      ),
      'field_related_content' => array(
        'override' => 1,
        'label' => 'Related Content',
        'hidden_field' => '1',
      ),
      'field_resources' => array(
        'override' => 1,
        'label' => 'Resources',
        'hidden_field' => '1',
      ),
      'field_spatial' => array(
        'override' => 0,
        'label' => 'Spatial / Geographical Coverage Area',
        'hidden_field' => 0,
      ),
      'field_spatial_geographical_cover' => array(
        'override' => 1,
        'label' => 'Spatial / Geographical Coverage Location',
        'hidden_field' => '1',
      ),
      'field_tags' => array(
        'override' => 0,
        'label' => 'Ключевые слова',
        'hidden_field' => 0,
      ),
      'field_dataset_vote' => array(
        'override' => 0,
        'label' => 'Оценка',
        'hidden_field' => 0,
      ),
      'field_dataset_id' => array(
        'override' => 0,
        'label' => 'Идентификационный номер',
        'hidden_field' => 0,
      ),
      'field_contact_phone' => array(
        'override' => 0,
        'label' => 'Телефон ответственного лица',
        'hidden_field' => 0,
      ),
      'field_email_responsible' => array(
        'override' => 0,
        'label' => 'Адрес электронной почты ответственного лица',
        'hidden_field' => 0,
      ),
      'field_organization' => array(
        'override' => 0,
        'label' => 'Владелец набора данных',
        'hidden_field' => 0,
      ),
      'field_rubric' => array(
        'override' => 0,
        'label' => 'Рубрика',
        'hidden_field' => 0,
      ),
      'field_popularity' => array(
        'override' => 1,
        'label' => 'Счетчик популярности',
        'hidden_field' => '1',
      ),
      'field_date_first_time_publ' => array(
        'override' => 0,
        'label' => 'Дата первой публикации набора данных',
        'hidden_field' => 0,
      ),
      'field_date_last_change' => array(
        'override' => 0,
        'label' => 'Дата последнего внесения изменений',
        'hidden_field' => 0,
      ),
      'field_date_dataset_actual' => array(
        'override' => 0,
        'label' => 'Дата актуальности набора данных',
        'hidden_field' => 0,
      ),
      'field_owner' => array(
        'override' => 0,
        'label' => 'Владелец набора данных',
        'hidden_field' => 0,
      ),
      'field_content_last_change' => array(
        'override' => 0,
        'label' => 'Содержание последнего изменения',
        'hidden_field' => 0,
      ),
      'field_vote' => array(
        'override' => 0,
        'label' => 'Голосовалка',
        'hidden_field' => 0,
      ),
      'field_dataset_standard' => array(
        'override' => 1,
        'label' => 'Эталон',
        'hidden_field' => '1',
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
              'dataset' => 'dataset',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
  );
  $export['node_edit_form_mutator_7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_8';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 7;
  $handler->conf = array(
    'title' => 'Конкурс',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Название конкурса',
        'hidden_field' => 0,
      ),
      'field_competition_description' => array(
        'override' => 0,
        'label' => 'Описание',
        'hidden_field' => 0,
      ),
      'field_competition_date' => array(
        'override' => 0,
        'label' => 'Дата',
        'hidden_field' => 0,
      ),
      'field_competition_cost' => array(
        'override' => 0,
        'label' => 'Стоимость',
        'hidden_field' => 0,
      ),
      'field_competition_rubric' => array(
        'override' => 0,
        'label' => 'Рубрика',
        'hidden_field' => 0,
      ),
      'field_competition_place' => array(
        'override' => 0,
        'label' => 'Место',
        'hidden_field' => 0,
      ),
      'field_competition_phone' => array(
        'override' => 0,
        'label' => 'Телефон',
        'hidden_field' => 0,
      ),
      'field_competition_e_mail' => array(
        'override' => 0,
        'label' => 'E-mail',
        'hidden_field' => 0,
      ),
      'field_competition_photo' => array(
        'override' => 0,
        'label' => 'Фото',
        'hidden_field' => 0,
      ),
      'field_competition_type' => array(
        'override' => 0,
        'label' => 'Тип конкурса',
        'hidden_field' => 0,
      ),
      'field_competition_organizer' => array(
        'override' => 0,
        'label' => 'Организатор',
        'hidden_field' => 0,
      ),
      'field_competition_status' => array(
        'override' => 1,
        'label' => 'Статус конкурса',
        'hidden_field' => '1',
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
        'override' => 0,
        'label' => 'Предпросмотр',
        'hidden_field' => 0,
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
              'competition' => 'competition',
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
  $export['node_edit_form_mutator_8'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_form_mutator_9';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'form_mutator';
  $handler->weight = 8;
  $handler->conf = array(
    'title' => 'Ресурс',
    'form_title' => '',
    'contexts' => array(),
    'relationships' => array(),
    'modification' => array(
      ':title' => array(
        'override' => 0,
        'label' => 'Заголовок',
        'hidden_field' => 0,
      ),
      'body' => array(
        'override' => 0,
        'label' => 'Описание',
        'hidden_field' => 0,
      ),
      'field_dataset_ref' => array(
        'override' => 0,
        'label' => 'Dataset',
        'hidden_field' => 0,
      ),
      'field_format' => array(
        'override' => 0,
        'label' => 'Data format',
        'hidden_field' => 0,
      ),
      'field_link_api' => array(
        'override' => 0,
        'label' => 'Link API',
        'hidden_field' => 0,
      ),
      'field_link_remote_file' => array(
        'override' => 0,
        'label' => 'Link File',
        'hidden_field' => 0,
      ),
      'field_upload' => array(
        'override' => 0,
        'label' => 'Upload',
        'hidden_field' => 0,
      ),
      'field_data_structure' => array(
        'override' => 0,
        'label' => 'Описание структуры набора данных',
        'hidden_field' => 0,
      ),
      'field_link_structure_file' => array(
        'override' => 0,
        'label' => 'Ссылка на структуру открытых данных',
        'hidden_field' => 0,
      ),
      'field_upload_structure' => array(
        'override' => 0,
        'label' => 'Opendata structure',
        'hidden_field' => 0,
      ),
      'field_created' => array(
        'override' => 0,
        'label' => 'Дата создания',
        'hidden_field' => 0,
      ),
      'field_provenance' => array(
        'override' => 0,
        'label' => 'Содержание изменений',
        'hidden_field' => 0,
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
        'override' => 1,
        'label' => 'URL redirects',
        'hidden_field' => '1',
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
              'resource' => 'resource',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_edit_form_mutator_9'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Набор данных',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Ресурс',
        'keyword' => 'resource',
        'name' => 'entity_from_field:field_resources-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Рубрика',
        'keyword' => 'rubric',
        'name' => 'entity_from_field:field_rubric-node-taxonomy_term',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      2 => array(
        'identifier' => 'Владелец набора данных',
        'keyword' => 'dataset_owner',
        'name' => 'entity_from_field:field_organization-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      3 => array(
        'identifier' => 'Файл from Материал (on Материал: Набор данных [field_link_remote_file])',
        'keyword' => 'file_resource',
        'name' => 'entity_from_field:field_link_remote_file-node-file',
        'delta' => 0,
        'context' => 'relationship_entity_from_field:field_resources-node-node_2',
        'id' => 1,
      ),
      4 => array(
        'identifier' => 'Материал from Материал (on Материал: Resources [field_resources]) 2',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_resources-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 2,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'dataset' => 'dataset',
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
          0 => 1,
        ),
        'parent' => NULL,
      ),
      1 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 3,
        ),
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 5,
          1 => 4,
        ),
        'parent' => '1',
        'class' => '',
      ),
      4 => array(
        'type' => 'column',
        'width' => '76.15210630477806',
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 7,
          1 => 8,
          2 => 9,
          3 => 10,
          4 => 11,
          5 => 12,
          6 => 13,
        ),
        'class' => 'dataset-right-col',
      ),
      5 => array(
        'type' => 'column',
        'width' => '23.84789369522194',
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 6,
        ),
        'class' => 'dataset-left-col',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'left_region_',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'left_region_' => array(
        'type' => 'region',
        'title' => 'Left region',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'main_',
        ),
        'parent' => '4',
        'class' => '',
      ),
      'main_' => array(
        'type' => 'region',
        'title' => 'Main',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => '',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'links',
        ),
        'parent' => '4',
        'class' => 'data-row-links',
      ),
      'links' => array(
        'type' => 'region',
        'title' => 'Links',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '________',
        ),
        'parent' => '4',
        'class' => 'data-row-maininfo',
      ),
      '________' => array(
        'type' => 'region',
        'title' => 'Info',
        'width' => 100,
        'width_type' => '%',
        'parent' => '9',
        'class' => '',
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'versions',
        ),
        'parent' => '4',
        'class' => 'data-row-versions',
      ),
      'versions' => array(
        'type' => 'region',
        'title' => 'Versions',
        'width' => 100,
        'width_type' => '%',
        'parent' => '10',
        'class' => '',
      ),
      11 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'passport',
        ),
        'parent' => '4',
        'class' => 'data-row-passport',
      ),
      'passport' => array(
        'type' => 'region',
        'title' => 'Passport',
        'width' => 100,
        'width_type' => '%',
        'parent' => '11',
        'class' => '',
      ),
      12 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'developers',
        ),
        'parent' => '4',
        'class' => 'data-row-developers',
      ),
      'developers' => array(
        'type' => 'region',
        'title' => 'Developers',
        'width' => 100,
        'width_type' => '%',
        'parent' => '12',
        'class' => '',
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'comments',
        ),
        'parent' => '4',
        'class' => 'data-row-comments',
      ),
      'comments' => array(
        'type' => 'region',
        'title' => 'Comments',
        'width' => 100,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'left_region' => NULL,
      'left_region_' => NULL,
      'main_' => NULL,
      'links' => NULL,
      '________' => NULL,
      'versions' => NULL,
      'passport' => NULL,
      'developers' => NULL,
      'comments' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '6c108fb5-1b40-47fd-b048-25a3e21315d6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-02a91a17-a6b5-41ce-9253-bc7f3a8feb2c';
    $pane->panel = 'comments';
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
      'admin_title' => 'Предложение зарегистрироваться пользователям для добавления комментария (для анонимов)',
      'title' => '',
      'body' => '<span>Чтобы оставить комментарий зарегистрируйтесь</span>
<a href="/user/register?destination=node/%node:nid">Регистрация</a>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-if-you-unlogged',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '02a91a17-a6b5-41ce-9253-bc7f3a8feb2c';
    $display->content['new-02a91a17-a6b5-41ce-9253-bc7f3a8feb2c'] = $pane;
    $display->panels['comments'][0] = 'new-02a91a17-a6b5-41ce-9253-bc7f3a8feb2c';
    $pane = new stdClass();
    $pane->pid = 'new-6db5b979-9aab-4732-a874-eace4e98a2c9';
    $pane->panel = 'comments';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Обсуждение (заголовок региона)',
      'title' => '',
      'body' => '<h2>Обсуждение</h2>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6db5b979-9aab-4732-a874-eace4e98a2c9';
    $display->content['new-6db5b979-9aab-4732-a874-eace4e98a2c9'] = $pane;
    $display->panels['comments'][1] = 'new-6db5b979-9aab-4732-a874-eace4e98a2c9';
    $pane = new stdClass();
    $pane->pid = 'new-1c793684-92a3-4379-944b-e8edced62a69';
    $pane->panel = 'comments';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1c793684-92a3-4379-944b-e8edced62a69';
    $display->content['new-1c793684-92a3-4379-944b-e8edced62a69'] = $pane;
    $display->panels['comments'][2] = 'new-1c793684-92a3-4379-944b-e8edced62a69';
    $pane = new stdClass();
    $pane->pid = 'new-cbae58e5-6e3b-4aa3-a85d-70ee3c23c9d0';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'cbae58e5-6e3b-4aa3-a85d-70ee3c23c9d0';
    $display->content['new-cbae58e5-6e3b-4aa3-a85d-70ee3c23c9d0'] = $pane;
    $display->panels['comments'][3] = 'new-cbae58e5-6e3b-4aa3-a85d-70ee3c23c9d0';
    $pane = new stdClass();
    $pane->pid = 'new-6e6a4bbf-01cf-4b9b-bc99-563fa17ab31d';
    $pane->panel = 'developers';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Сообщение разработчикам',
      'title' => 'Разработчикам',
      'body' => '<div class="pane-content">Пользователь вправе использовать (в том числе повторно) открытые данные свободно, бессрочно, безвозмездно и без ограничения территории использования, в том числе имеет право копировать, публиковать, распространять открытые данные, видоизменять открытые данные и объединять их с другой информацией, использовать открытые данные в коммерческих целях, использовать для создания программ для ЭВМ и приложений.</div>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6e6a4bbf-01cf-4b9b-bc99-563fa17ab31d';
    $display->content['new-6e6a4bbf-01cf-4b9b-bc99-563fa17ab31d'] = $pane;
    $display->panels['developers'][0] = 'new-6e6a4bbf-01cf-4b9b-bc99-563fa17ab31d';
    $pane = new stdClass();
    $pane->pid = 'new-3f64e1cd-8b18-45ad-998c-028629ac2307';
    $pane->panel = 'left_region_';
    $pane->type = 'flag_link';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'flag_name' => 'subscribe_dataset',
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
    $pane->uuid = '3f64e1cd-8b18-45ad-998c-028629ac2307';
    $display->content['new-3f64e1cd-8b18-45ad-998c-028629ac2307'] = $pane;
    $display->panels['left_region_'][0] = 'new-3f64e1cd-8b18-45ad-998c-028629ac2307';
    $pane = new stdClass();
    $pane->pid = 'new-dd51f259-a793-4d06-b8b1-540fac38f6bc';
    $pane->panel = 'left_region_';
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
      'admin_title' => 'Сообщение для анонимов о необходимости регистрации для подписки на набор',
      'title' => '',
      'body' => '<span class="flag-message">Для подписки на получение уведомлений об изменениях в наборе данных необходимо <a href="/user/login?destination=node/%node:nid">авторизоваться</a> или <a href="/user/register?destination=node/%node:nid">зарегистрироваться</a></span>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'dd51f259-a793-4d06-b8b1-540fac38f6bc';
    $display->content['new-dd51f259-a793-4d06-b8b1-540fac38f6bc'] = $pane;
    $display->panels['left_region_'][1] = 'new-dd51f259-a793-4d06-b8b1-540fac38f6bc';
    $pane = new stdClass();
    $pane->pid = 'new-e17c3888-c67b-4997-a12f-8ad70b5f1d50';
    $pane->panel = 'left_region_';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_spatial';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'geolocation_googlemaps_dynamic',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'data' => 'centroid',
        'format' => 'decimal_degrees',
        'labels' => 1,
        'address' => 1,
        'map_width' => '100%',
        'map_height' => '300px',
        'map_zoomlevel' => '7',
        'map_maptype' => 'roadmap',
        'marker_icon' => '',
        'map_scrollwheel' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Регион',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e17c3888-c67b-4997-a12f-8ad70b5f1d50';
    $display->content['new-e17c3888-c67b-4997-a12f-8ad70b5f1d50'] = $pane;
    $display->panels['left_region_'][2] = 'new-e17c3888-c67b-4997-a12f-8ad70b5f1d50';
    $pane = new stdClass();
    $pane->pid = 'new-6c3f7ddf-11e5-450e-909b-a8266f118b71';
    $pane->panel = 'left_region_';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_geolocation';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'php',
          'settings' => array(
            'description' => 'Проверка на наличие значения в поле набора данных - field_spatial',
            'php' => '//В случае отсутствия значения в поле field_spatial набора данных выводится геоданные организации, которой принадлежит набор.
if (isset($contexts[\'argument_entity_id:node_1\']->data->field_spatial)) {
  $geofield = $contexts[\'argument_entity_id:node_1\']->data->field_spatial;
}
if (is_array($geofield) && empty($geofield)) return TRUE;',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'geolocation_googlemaps_dynamic',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'map_width' => '100%',
        'map_height' => '300px',
        'map_zoomlevel' => '15',
        'map_imageformat' => 'png8',
        'map_maptype' => 'roadmap',
        'marker_icon' => '',
        'map_scrollwheel' => 1,
      ),
      'context' => 'relationship_entity_from_field:field_organization-node-node_1',
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
    $pane->uuid = '6c3f7ddf-11e5-450e-909b-a8266f118b71';
    $display->content['new-6c3f7ddf-11e5-450e-909b-a8266f118b71'] = $pane;
    $display->panels['left_region_'][3] = 'new-6c3f7ddf-11e5-450e-909b-a8266f118b71';
    $pane = new stdClass();
    $pane->pid = 'new-e4d700a1-cf9d-4441-b9dd-ad87dcf31986';
    $pane->panel = 'left_region_';
    $pane->type = 'block';
    $pane->subtype = 'addtoany-addtoany_button';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Рассказать',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'e4d700a1-cf9d-4441-b9dd-ad87dcf31986';
    $display->content['new-e4d700a1-cf9d-4441-b9dd-ad87dcf31986'] = $pane;
    $display->panels['left_region_'][4] = 'new-e4d700a1-cf9d-4441-b9dd-ad87dcf31986';
    $pane = new stdClass();
    $pane->pid = 'new-d97ba908-99e3-47ee-9dfb-7a3d2f7a8bb4';
    $pane->panel = 'links';
    $pane->type = 'views_panes';
    $pane->subtype = 'resources-latest_resource';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd97ba908-99e3-47ee-9dfb-7a3d2f7a8bb4';
    $display->content['new-d97ba908-99e3-47ee-9dfb-7a3d2f7a8bb4'] = $pane;
    $display->panels['links'][0] = 'new-d97ba908-99e3-47ee-9dfb-7a3d2f7a8bb4';
    $pane = new stdClass();
    $pane->pid = 'new-591ff744-81e9-4d06-9694-82e87ebd0765';
    $pane->panel = 'links';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_vote';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '591ff744-81e9-4d06-9694-82e87ebd0765';
    $display->content['new-591ff744-81e9-4d06-9694-82e87ebd0765'] = $pane;
    $display->panels['links'][1] = 'new-591ff744-81e9-4d06-9694-82e87ebd0765';
    $pane = new stdClass();
    $pane->pid = 'new-05abbb5f-19ba-47b7-ac2a-1035d4a5b5ef';
    $pane->panel = 'links';
    $pane->type = 'token';
    $pane->subtype = 'node:total-count';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '05abbb5f-19ba-47b7-ac2a-1035d4a5b5ef';
    $display->content['new-05abbb5f-19ba-47b7-ac2a-1035d4a5b5ef'] = $pane;
    $display->panels['links'][2] = 'new-05abbb5f-19ba-47b7-ac2a-1035d4a5b5ef';
    $pane = new stdClass();
    $pane->pid = 'new-cdd86dbf-6e02-40d4-bfdd-ad49f8edf78b';
    $pane->panel = 'links';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_link_remote_file';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'od_common_file_dlcnt',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_field:field_resources-node-node_1',
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
    $pane->uuid = 'cdd86dbf-6e02-40d4-bfdd-ad49f8edf78b';
    $display->content['new-cdd86dbf-6e02-40d4-bfdd-ad49f8edf78b'] = $pane;
    $display->panels['links'][3] = 'new-cdd86dbf-6e02-40d4-bfdd-ad49f8edf78b';
    $pane = new stdClass();
    $pane->pid = 'new-43b23ac0-8b7e-4a52-b360-3eaa8252acbf';
    $pane->panel = 'links';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_upload';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'od_common_file_dlcnt',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'relationship_entity_from_field:field_resources-node-node_1',
      'override_title' => 1,
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
    $pane->uuid = '43b23ac0-8b7e-4a52-b360-3eaa8252acbf';
    $display->content['new-43b23ac0-8b7e-4a52-b360-3eaa8252acbf'] = $pane;
    $display->panels['links'][4] = 'new-43b23ac0-8b7e-4a52-b360-3eaa8252acbf';
    $pane = new stdClass();
    $pane->pid = 'new-52fc10b9-ad9b-42d5-acf6-f38ebdd26ad0';
    $pane->panel = 'main_';
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
        'image_style' => 'thumbnail',
        'image_link' => 'content',
      ),
      'context' => 'relationship_entity_from_field:field_rubric-node-taxonomy_term_1',
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
    $pane->uuid = '52fc10b9-ad9b-42d5-acf6-f38ebdd26ad0';
    $display->content['new-52fc10b9-ad9b-42d5-acf6-f38ebdd26ad0'] = $pane;
    $display->panels['main_'][0] = 'new-52fc10b9-ad9b-42d5-acf6-f38ebdd26ad0';
    $pane = new stdClass();
    $pane->pid = 'new-cda88a75-118b-4a06-84ed-fba8d3d7b45a';
    $pane->panel = 'main_';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Название рубрики',
      'title' => '',
      'body' => '<a href="%rubric:url">%rubric:i18n-name</a>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-node-field-rubric',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cda88a75-118b-4a06-84ed-fba8d3d7b45a';
    $display->content['new-cda88a75-118b-4a06-84ed-fba8d3d7b45a'] = $pane;
    $display->panels['main_'][1] = 'new-cda88a75-118b-4a06-84ed-fba8d3d7b45a';
    $pane = new stdClass();
    $pane->pid = 'new-be2ff3f2-db98-401d-81a2-976510e92b16';
    $pane->panel = 'main_';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'be2ff3f2-db98-401d-81a2-976510e92b16';
    $display->content['new-be2ff3f2-db98-401d-81a2-976510e92b16'] = $pane;
    $display->panels['main_'][2] = 'new-be2ff3f2-db98-401d-81a2-976510e92b16';
    $pane = new stdClass();
    $pane->pid = 'new-aaa6ce02-aaad-423b-89a5-82874c92d7f7';
    $pane->panel = 'main_';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_popularity';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'radioactivity_combo_formatter',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'energy' => '10',
        'type' => 'none',
        'accuracy' => '100',
      ),
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'aaa6ce02-aaad-423b-89a5-82874c92d7f7';
    $display->content['new-aaa6ce02-aaad-423b-89a5-82874c92d7f7'] = $pane;
    $display->panels['main_'][3] = 'new-aaa6ce02-aaad-423b-89a5-82874c92d7f7';
    $pane = new stdClass();
    $pane->pid = 'new-e90dcb80-44cc-4a83-8250-3e4a633e7f09';
    $pane->panel = 'passport';
    $pane->type = 'od_passport_pane';
    $pane->subtype = 'od_passport_pane';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Паспорт набора',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e90dcb80-44cc-4a83-8250-3e4a633e7f09';
    $display->content['new-e90dcb80-44cc-4a83-8250-3e4a633e7f09'] = $pane;
    $display->panels['passport'][0] = 'new-e90dcb80-44cc-4a83-8250-3e4a633e7f09';
    $pane = new stdClass();
    $pane->pid = 'new-eb0fc67e-8fa3-4b71-80b7-e0c6568d7dc0';
    $pane->panel = 'passport';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'admin_title' => 'Ссылка на кода паспорта',
      'title' => '',
      'body' => '<?php 
  $nid = arg(1);
  print l(t(\'html code passport\'), "node/$nid/code-passport"); 
?>',
      'format' => 'ds_code',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'eb0fc67e-8fa3-4b71-80b7-e0c6568d7dc0';
    $display->content['new-eb0fc67e-8fa3-4b71-80b7-e0c6568d7dc0'] = $pane;
    $display->panels['passport'][1] = 'new-eb0fc67e-8fa3-4b71-80b7-e0c6568d7dc0';
    $pane = new stdClass();
    $pane->pid = 'new-40121981-b041-4236-9cc0-21d63eaab5ed';
    $pane->panel = 'passport';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-passport_dataset';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '40121981-b041-4236-9cc0-21d63eaab5ed';
    $display->content['new-40121981-b041-4236-9cc0-21d63eaab5ed'] = $pane;
    $display->panels['passport'][2] = 'new-40121981-b041-4236-9cc0-21d63eaab5ed';
    $pane = new stdClass();
    $pane->pid = 'new-3b30fcc0-63f2-4cf9-b091-db4de9de2562';
    $pane->panel = 'passport';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-dataset_changes_info';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 0,
      'override_title_text' => 'Информация об изменениях',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '3b30fcc0-63f2-4cf9-b091-db4de9de2562';
    $display->content['new-3b30fcc0-63f2-4cf9-b091-db4de9de2562'] = $pane;
    $display->panels['passport'][3] = 'new-3b30fcc0-63f2-4cf9-b091-db4de9de2562';
    $pane = new stdClass();
    $pane->pid = 'new-98d99e2d-c9a5-4781-915f-c9c80f3306d5';
    $pane->panel = 'versions';
    $pane->type = 'views_panes';
    $pane->subtype = 'revisions-resource_versions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'relationship_entity_from_field:field_resources-node-node_1',
        1 => 'relationship_entity_from_field:field_resources-node-node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '98d99e2d-c9a5-4781-915f-c9c80f3306d5';
    $display->content['new-98d99e2d-c9a5-4781-915f-c9c80f3306d5'] = $pane;
    $display->panels['versions'][0] = 'new-98d99e2d-c9a5-4781-915f-c9c80f3306d5';
    $pane = new stdClass();
    $pane->pid = 'new-7d0ac9be-bcce-4056-a55b-4cdbf06f768e';
    $pane->panel = '________';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Информация',
      'title' => '',
      'body' => '<h3>Информация</h3>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7d0ac9be-bcce-4056-a55b-4cdbf06f768e';
    $display->content['new-7d0ac9be-bcce-4056-a55b-4cdbf06f768e'] = $pane;
    $display->panels['________'][0] = 'new-7d0ac9be-bcce-4056-a55b-4cdbf06f768e';
    $pane = new stdClass();
    $pane->pid = 'new-99911bca-3522-4a51-9ecd-03d4000cf635';
    $pane->panel = '________';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contact_name';
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
      'override_title' => 1,
      'override_title_text' => 'Добавил:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '99911bca-3522-4a51-9ecd-03d4000cf635';
    $display->content['new-99911bca-3522-4a51-9ecd-03d4000cf635'] = $pane;
    $display->panels['________'][1] = 'new-99911bca-3522-4a51-9ecd-03d4000cf635';
    $pane = new stdClass();
    $pane->pid = 'new-f971d1f4-825a-4b78-94a5-ed2777d2c24d';
    $pane->panel = '________';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_contact_phone';
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
      'override_title' => 1,
      'override_title_text' => 'Телефон:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f971d1f4-825a-4b78-94a5-ed2777d2c24d';
    $display->content['new-f971d1f4-825a-4b78-94a5-ed2777d2c24d'] = $pane;
    $display->panels['________'][2] = 'new-f971d1f4-825a-4b78-94a5-ed2777d2c24d';
    $pane = new stdClass();
    $pane->pid = 'new-a9ee817e-9da9-40a3-8b5f-b420cd908f9b';
    $pane->panel = '________';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_email_responsible';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'invisimail_js_entities',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Электронная почта:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a9ee817e-9da9-40a3-8b5f-b420cd908f9b';
    $display->content['new-a9ee817e-9da9-40a3-8b5f-b420cd908f9b'] = $pane;
    $display->panels['________'][3] = 'new-a9ee817e-9da9-40a3-8b5f-b420cd908f9b';
    $pane = new stdClass();
    $pane->pid = 'new-d67a4097-c6e8-49f9-bec2-31b9b802d58b';
    $pane->panel = '________';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_date_first_time_publ';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'date_only',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
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
    $pane->uuid = 'd67a4097-c6e8-49f9-bec2-31b9b802d58b';
    $display->content['new-d67a4097-c6e8-49f9-bec2-31b9b802d58b'] = $pane;
    $display->panels['________'][4] = 'new-d67a4097-c6e8-49f9-bec2-31b9b802d58b';
    $pane = new stdClass();
    $pane->pid = 'new-b639c9f1-3504-4bb6-916e-5f6ad37b8e6e';
    $pane->panel = '________';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_date_last_change';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'date_only',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
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
    $pane->uuid = 'b639c9f1-3504-4bb6-916e-5f6ad37b8e6e';
    $display->content['new-b639c9f1-3504-4bb6-916e-5f6ad37b8e6e'] = $pane;
    $display->panels['________'][5] = 'new-b639c9f1-3504-4bb6-916e-5f6ad37b8e6e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_10';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 10;
  $handler->conf = array(
    'title' => 'Тема форума',
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
              'forum' => 'forum',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0106ee74-a729-49d1-835a-dfd88a2d0aed';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1618a785-3d75-4b7a-bebe-a69fe00ea84c';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1618a785-3d75-4b7a-bebe-a69fe00ea84c';
    $display->content['new-1618a785-3d75-4b7a-bebe-a69fe00ea84c'] = $pane;
    $display->panels['middle'][0] = 'new-1618a785-3d75-4b7a-bebe-a69fe00ea84c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-1618a785-3d75-4b7a-bebe-a69fe00ea84c';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_10'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Конкурс',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'pane-competition',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Комментарий from Материал (on comment.comment_node)',
        'keyword' => 'node_2',
        'name' => 'entity_from_schema:nid-node-comment',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Термин таксономии from Материал (on Материал: Рубрика [field_competition_rubric])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_competition_rubric-node-taxonomy_term',
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
              'competition' => 'competition',
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
          0 => 5,
          1 => 4,
          2 => 3,
          3 => 2,
        ),
        'parent' => 'canvas',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'details_1_',
        ),
        'parent' => 'main',
        'class' => 'Details 1',
      ),
      'details_1_' => array(
        'type' => 'region',
        'title' => 'Additional',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'additional',
        'hide_empty' => 0,
      ),
      3 => array(
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
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'body',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'body' => array(
        'type' => 'region',
        'title' => 'Body',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => '',
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'image',
          1 => 'info',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'image' => array(
        'type' => 'region',
        'title' => 'Image',
        'width' => '20.325078193098502',
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
      ),
      'info' => array(
        'type' => 'region',
        'title' => 'Info',
        'width' => '79.6749218069015',
        'width_type' => '%',
        'parent' => '5',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'details' => NULL,
      'details_' => NULL,
      'details_2' => NULL,
      'details_3' => NULL,
      'details_1' => NULL,
      'details_1_' => NULL,
      'comments' => NULL,
      'body' => NULL,
      'image' => NULL,
      'info' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c3e576a-d30c-41ec-8096-893691b56e6d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-36e08a43-c190-4552-960f-5d7d6c21e3f0';
    $pane->panel = 'body';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_description';
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
    $pane->uuid = '36e08a43-c190-4552-960f-5d7d6c21e3f0';
    $display->content['new-36e08a43-c190-4552-960f-5d7d6c21e3f0'] = $pane;
    $display->panels['body'][0] = 'new-36e08a43-c190-4552-960f-5d7d6c21e3f0';
    $pane = new stdClass();
    $pane->pid = 'new-27dc33cd-16c1-4c77-a523-061be31f8fea';
    $pane->panel = 'comments';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 1,
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
    $pane->uuid = '27dc33cd-16c1-4c77-a523-061be31f8fea';
    $display->content['new-27dc33cd-16c1-4c77-a523-061be31f8fea'] = $pane;
    $display->panels['comments'][0] = 'new-27dc33cd-16c1-4c77-a523-061be31f8fea';
    $pane = new stdClass();
    $pane->pid = 'new-f6d398cc-3bf6-4ffa-8b81-46420a62c5f6';
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
      'override_title_text' => 'Комментарии',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f6d398cc-3bf6-4ffa-8b81-46420a62c5f6';
    $display->content['new-f6d398cc-3bf6-4ffa-8b81-46420a62c5f6'] = $pane;
    $display->panels['comments'][1] = 'new-f6d398cc-3bf6-4ffa-8b81-46420a62c5f6';
    $pane = new stdClass();
    $pane->pid = 'new-9a9b73ec-7a74-426d-b241-2d6a6ca1087f';
    $pane->panel = 'details_1_';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Кнопка - Вернуться',
      'title' => '',
      'body' => '<a class="btn" href="/taxonomy/term/%taxonomy_term:tid/competition">Вернуться  к списку конкурсов </a>',
      'format' => 'ds_code',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-btn',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9a9b73ec-7a74-426d-b241-2d6a6ca1087f';
    $display->content['new-9a9b73ec-7a74-426d-b241-2d6a6ca1087f'] = $pane;
    $display->panels['details_1_'][0] = 'new-9a9b73ec-7a74-426d-b241-2d6a6ca1087f';
    $pane = new stdClass();
    $pane->pid = 'new-6602447a-e1bb-4806-8782-2b797723d476';
    $pane->panel = 'image';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_photo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => '1',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'image_style' => 'competition-330',
        'image_link' => '',
      ),
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
    $pane->uuid = '6602447a-e1bb-4806-8782-2b797723d476';
    $display->content['new-6602447a-e1bb-4806-8782-2b797723d476'] = $pane;
    $display->panels['image'][0] = 'new-6602447a-e1bb-4806-8782-2b797723d476';
    $pane = new stdClass();
    $pane->pid = 'new-5d2ecd2b-01b0-409b-aed9-9938b682ad1b';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_cost';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5d2ecd2b-01b0-409b-aed9-9938b682ad1b';
    $display->content['new-5d2ecd2b-01b0-409b-aed9-9938b682ad1b'] = $pane;
    $display->panels['info'][0] = 'new-5d2ecd2b-01b0-409b-aed9-9938b682ad1b';
    $pane = new stdClass();
    $pane->pid = 'new-920d3a85-04e3-4617-8193-8a0df39ed79e';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_rubric';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 1,
      ),
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '920d3a85-04e3-4617-8193-8a0df39ed79e';
    $display->content['new-920d3a85-04e3-4617-8193-8a0df39ed79e'] = $pane;
    $display->panels['info'][1] = 'new-920d3a85-04e3-4617-8193-8a0df39ed79e';
    $pane = new stdClass();
    $pane->pid = 'new-eb9b155a-19cb-48c6-86ca-deda4155ea26';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_place';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'eb9b155a-19cb-48c6-86ca-deda4155ea26';
    $display->content['new-eb9b155a-19cb-48c6-86ca-deda4155ea26'] = $pane;
    $display->panels['info'][2] = 'new-eb9b155a-19cb-48c6-86ca-deda4155ea26';
    $pane = new stdClass();
    $pane->pid = 'new-99b919d8-ffff-43c7-b87f-bb471e2d0ed3';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'list_default',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '99b919d8-ffff-43c7-b87f-bb471e2d0ed3';
    $display->content['new-99b919d8-ffff-43c7-b87f-bb471e2d0ed3'] = $pane;
    $display->panels['info'][3] = 'new-99b919d8-ffff-43c7-b87f-bb471e2d0ed3';
    $pane = new stdClass();
    $pane->pid = 'new-7a124f5c-1d19-430f-9d93-7e4226a591c3';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'date_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'comment',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Дата',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '7a124f5c-1d19-430f-9d93-7e4226a591c3';
    $display->content['new-7a124f5c-1d19-430f-9d93-7e4226a591c3'] = $pane;
    $display->panels['info'][4] = 'new-7a124f5c-1d19-430f-9d93-7e4226a591c3';
    $pane = new stdClass();
    $pane->pid = 'new-2b534560-5b59-41ac-83d6-aadc76b6df4d';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_organizer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'link_default',
      'delta_limit' => '1',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Организаторы',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '2b534560-5b59-41ac-83d6-aadc76b6df4d';
    $display->content['new-2b534560-5b59-41ac-83d6-aadc76b6df4d'] = $pane;
    $display->panels['info'][5] = 'new-2b534560-5b59-41ac-83d6-aadc76b6df4d';
    $pane = new stdClass();
    $pane->pid = 'new-ebf6a52c-0981-4fd8-a2fc-93212c397361';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_e_mail';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'invisimail_js_entities',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 0,
      ),
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
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'ebf6a52c-0981-4fd8-a2fc-93212c397361';
    $display->content['new-ebf6a52c-0981-4fd8-a2fc-93212c397361'] = $pane;
    $display->panels['info'][6] = 'new-ebf6a52c-0981-4fd8-a2fc-93212c397361';
    $pane = new stdClass();
    $pane->pid = 'new-6f8d76a1-e990-4ef5-8f3a-202edf41dd4d';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_phone';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '6f8d76a1-e990-4ef5-8f3a-202edf41dd4d';
    $display->content['new-6f8d76a1-e990-4ef5-8f3a-202edf41dd4d'] = $pane;
    $display->panels['info'][7] = 'new-6f8d76a1-e990-4ef5-8f3a-202edf41dd4d';
    $pane = new stdClass();
    $pane->pid = 'new-4b8f12ad-7401-416a-aab0-556cc0715986';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_competition_date';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'competition_date_formatter',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'format_type' => 'date_only',
        'multiple_number' => '',
        'multiple_from' => '',
        'multiple_to' => '',
        'fromto' => 'both',
      ),
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '4b8f12ad-7401-416a-aab0-556cc0715986';
    $display->content['new-4b8f12ad-7401-416a-aab0-556cc0715986'] = $pane;
    $display->panels['info'][8] = 'new-4b8f12ad-7401-416a-aab0-556cc0715986';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Ресурс',
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
              'resource' => 'resource',
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
  $display->title = '';
  $display->uuid = '2a27e798-a43f-4851-b9ca-84b15d1cdad4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b1e683db-3828-4cdc-9006-9d46c5a34853';
    $pane->panel = 'main';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b1e683db-3828-4cdc-9006-9d46c5a34853';
    $display->content['new-b1e683db-3828-4cdc-9006-9d46c5a34853'] = $pane;
    $display->panels['main'][0] = 'new-b1e683db-3828-4cdc-9006-9d46c5a34853';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Приложение',
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
              'app' => 'app',
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
          0 => 3,
          1 => 2,
        ),
        'parent' => 'canvas',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'application_info_1',
        ),
        'parent' => 'main',
        'class' => 'app-col-bottom',
        'hide_empty' => 0,
      ),
      'application_info_1' => array(
        'type' => 'region',
        'title' => 'Body',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'app-body',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 4,
          1 => 5,
        ),
        'parent' => 'main',
        'class' => '',
      ),
      4 => array(
        'type' => 'column',
        'width' => '20.01262626262626',
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 6,
        ),
        'class' => 'app-col-left',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'column',
        'width' => '79.98737373737374',
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 7,
          1 => 8,
          2 => 9,
        ),
        'class' => 'app-col-right',
        'hide_empty' => 0,
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'image_',
        ),
        'parent' => '4',
        'class' => '',
      ),
      'image_' => array(
        'type' => 'region',
        'title' => 'Image',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => 'app-image',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'app_info',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'app_info' => array(
        'type' => 'region',
        'title' => 'App info',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => 'app-info',
        'hide_empty' => 0,
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'contacts',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'contacts' => array(
        'type' => 'region',
        'title' => 'Contacts',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => 'apps-contacts',
        'hide_empty' => 0,
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'links',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'links' => array(
        'type' => 'region',
        'title' => 'links',
        'width' => 100,
        'width_type' => '%',
        'parent' => '9',
        'class' => 'app-links',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'application_info' => NULL,
      'application_info_1' => NULL,
      'image' => NULL,
      'image_' => NULL,
      'app_info' => NULL,
      'contacts' => NULL,
      'links' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '4e7c9b3c-3f77-46a8-9bfa-4df41a06f37c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a9000d93-19c7-4df8-9536-38ba84b9d81b';
    $pane->panel = 'application_info_1';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a9000d93-19c7-4df8-9536-38ba84b9d81b';
    $display->content['new-a9000d93-19c7-4df8-9536-38ba84b9d81b'] = $pane;
    $display->panels['application_info_1'][0] = 'new-a9000d93-19c7-4df8-9536-38ba84b9d81b';
    $pane = new stdClass();
    $pane->pid = 'new-8d104ea1-9ede-4c38-9018-4d4962b67eb4';
    $pane->panel = 'app_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_fivestar';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'fivestar_formatter_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'widget' => array(
          'fivestar_widget' => 'default',
        ),
        'style' => 'average',
        'text' => 'average',
        'expose' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Rating',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8d104ea1-9ede-4c38-9018-4d4962b67eb4';
    $display->content['new-8d104ea1-9ede-4c38-9018-4d4962b67eb4'] = $pane;
    $display->panels['app_info'][0] = 'new-8d104ea1-9ede-4c38-9018-4d4962b67eb4';
    $pane = new stdClass();
    $pane->pid = 'new-8e07ed16-79e5-415e-8610-97241df675fc';
    $pane->panel = 'app_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_rubric';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'hs_taxonomy_term_reference_hierarchical_text',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8e07ed16-79e5-415e-8610-97241df675fc';
    $display->content['new-8e07ed16-79e5-415e-8610-97241df675fc'] = $pane;
    $display->panels['app_info'][1] = 'new-8e07ed16-79e5-415e-8610-97241df675fc';
    $pane = new stdClass();
    $pane->pid = 'new-335652e2-a2d2-41e5-b0bf-8442efa4f706';
    $pane->panel = 'app_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'ds_taxonomy_separator',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '335652e2-a2d2-41e5-b0bf-8442efa4f706';
    $display->content['new-335652e2-a2d2-41e5-b0bf-8442efa4f706'] = $pane;
    $display->panels['app_info'][2] = 'new-335652e2-a2d2-41e5-b0bf-8442efa4f706';
    $pane = new stdClass();
    $pane->pid = 'new-38f0b035-790d-4e36-bdb4-389224e4af88';
    $pane->panel = 'app_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_app_url_datasets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'link_default',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '38f0b035-790d-4e36-bdb4-389224e4af88';
    $display->content['new-38f0b035-790d-4e36-bdb4-389224e4af88'] = $pane;
    $display->panels['app_info'][3] = 'new-38f0b035-790d-4e36-bdb4-389224e4af88';
    $pane = new stdClass();
    $pane->pid = 'new-7384c4f7-9de7-4715-997e-74adb2c26898';
    $pane->panel = 'contacts';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_app_url_organization';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Developer:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7384c4f7-9de7-4715-997e-74adb2c26898';
    $display->content['new-7384c4f7-9de7-4715-997e-74adb2c26898'] = $pane;
    $display->panels['contacts'][0] = 'new-7384c4f7-9de7-4715-997e-74adb2c26898';
    $pane = new stdClass();
    $pane->pid = 'new-d333228a-ed15-450f-9f1a-74eb2c7c88f6';
    $pane->panel = 'contacts';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_app_mail';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'invisimail_js_entities',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => 0,
      ),
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd333228a-ed15-450f-9f1a-74eb2c7c88f6';
    $display->content['new-d333228a-ed15-450f-9f1a-74eb2c7c88f6'] = $pane;
    $display->panels['contacts'][1] = 'new-d333228a-ed15-450f-9f1a-74eb2c7c88f6';
    $pane = new stdClass();
    $pane->pid = 'new-1ac8639e-0315-4242-ba71-1fca15d16cd8';
    $pane->panel = 'contacts';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_app_phone';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '1ac8639e-0315-4242-ba71-1fca15d16cd8';
    $display->content['new-1ac8639e-0315-4242-ba71-1fca15d16cd8'] = $pane;
    $display->panels['contacts'][2] = 'new-1ac8639e-0315-4242-ba71-1fca15d16cd8';
    $pane = new stdClass();
    $pane->pid = 'new-7ae8cf02-8665-499c-b98b-08681c59deec';
    $pane->panel = 'image_';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_app_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'medium',
        'image_link' => '',
      ),
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
    $pane->uuid = '7ae8cf02-8665-499c-b98b-08681c59deec';
    $display->content['new-7ae8cf02-8665-499c-b98b-08681c59deec'] = $pane;
    $display->panels['image_'][0] = 'new-7ae8cf02-8665-499c-b98b-08681c59deec';
    $pane = new stdClass();
    $pane->pid = 'new-2f925378-27c6-4203-8348-bd231955852b';
    $pane->panel = 'links';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_app_url_google_play';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
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
    $pane->uuid = '2f925378-27c6-4203-8348-bd231955852b';
    $display->content['new-2f925378-27c6-4203-8348-bd231955852b'] = $pane;
    $display->panels['links'][0] = 'new-2f925378-27c6-4203-8348-bd231955852b';
    $pane = new stdClass();
    $pane->pid = 'new-63cd7ebc-a18e-4f62-b695-d99a68e84b2e';
    $pane->panel = 'links';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_app_url_windows_phone';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '63cd7ebc-a18e-4f62-b695-d99a68e84b2e';
    $display->content['new-63cd7ebc-a18e-4f62-b695-d99a68e84b2e'] = $pane;
    $display->panels['links'][1] = 'new-63cd7ebc-a18e-4f62-b695-d99a68e84b2e';
    $pane = new stdClass();
    $pane->pid = 'new-e9b0564f-8e6e-4541-8492-954c943d7ac5';
    $pane->panel = 'links';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_app_url_apple_store';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e9b0564f-8e6e-4541-8492-954c943d7ac5';
    $display->content['new-e9b0564f-8e6e-4541-8492-954c943d7ac5'] = $pane;
    $display->panels['links'][2] = 'new-e9b0564f-8e6e-4541-8492-954c943d7ac5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Организация',
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
              'organization' => 'organization',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '00dfcef5-18b1-4ab8-8497-3507a25a767a';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-809d1f74-ea15-4ad9-a386-3f19332ed70f';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '809d1f74-ea15-4ad9-a386-3f19332ed70f';
    $display->content['new-809d1f74-ea15-4ad9-a386-3f19332ed70f'] = $pane;
    $display->panels['middle'][0] = 'new-809d1f74-ea15-4ad9-a386-3f19332ed70f';
    $pane = new stdClass();
    $pane->pid = 'new-a1cee5ae-f05d-4553-8284-0cb3782f68a3';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-organization_datasets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a1cee5ae-f05d-4553-8284-0cb3782f68a3';
    $display->content['new-a1cee5ae-f05d-4553-8284-0cb3782f68a3'] = $pane;
    $display->panels['middle'][1] = 'new-a1cee5ae-f05d-4553-8284-0cb3782f68a3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-809d1f74-ea15-4ad9-a386-3f19332ed70f';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Блог',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'author',
        'keyword' => 'author',
        'name' => 'entity_from_schema:uid-node-user',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
      1 => array(
        'identifier' => 'Термин таксономии from Материал (on Материал: Рубрика [field_rubric])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_rubric-node-taxonomy_term',
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
              'blog' => 'blog',
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
        'title' => 'Центр',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'author_avatar',
          1 => 'blog_info',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'author_avatar' => array(
        'type' => 'region',
        'title' => 'Author avatar',
        'width' => '20.20537475801382',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'author-avatar',
      ),
      'blog_info' => array(
        'type' => 'region',
        'title' => 'Blog info',
        'width' => '79.79462524198618',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'blog-info',
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
      'author_avatar' => NULL,
      'blog_info' => NULL,
      'comments' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0cc516c1-e11e-4c38-8e59-23dad6486b6f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-be6a4208-dc28-41e4-b76a-077932ef7af2';
    $pane->panel = 'author_avatar';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_entity_from_schema:uid-node-user_1',
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
    $pane->uuid = 'be6a4208-dc28-41e4-b76a-077932ef7af2';
    $display->content['new-be6a4208-dc28-41e4-b76a-077932ef7af2'] = $pane;
    $display->panels['author_avatar'][0] = 'new-be6a4208-dc28-41e4-b76a-077932ef7af2';
    $pane = new stdClass();
    $pane->pid = 'new-52c921da-48f9-41e5-8ea7-1cfd83793baa';
    $pane->panel = 'blog_info';
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
        'image_style' => 'avatar-60x60',
        'image_link' => 'content',
      ),
      'context' => 'relationship_entity_from_field:field_rubric-node-taxonomy_term_1',
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
    $pane->uuid = '52c921da-48f9-41e5-8ea7-1cfd83793baa';
    $display->content['new-52c921da-48f9-41e5-8ea7-1cfd83793baa'] = $pane;
    $display->panels['blog_info'][0] = 'new-52c921da-48f9-41e5-8ea7-1cfd83793baa';
    $pane = new stdClass();
    $pane->pid = 'new-f2481fdf-494e-44ee-936d-e83a2d73154b';
    $pane->panel = 'blog_info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_rubric';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_link',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f2481fdf-494e-44ee-936d-e83a2d73154b';
    $display->content['new-f2481fdf-494e-44ee-936d-e83a2d73154b'] = $pane;
    $display->panels['blog_info'][1] = 'new-f2481fdf-494e-44ee-936d-e83a2d73154b';
    $pane = new stdClass();
    $pane->pid = 'new-8465b196-af78-44f4-853c-660a144cd305';
    $pane->panel = 'blog_info';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'АВТОР БЛОГА + ССЫЛКА НА БЛОГ',
      'title' => '',
      'body' => '<span class="label">Автор:</span> %author:name (<a href="/blog/%author:uid">БЛОГ АВТОРА</a>)',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8465b196-af78-44f4-853c-660a144cd305';
    $display->content['new-8465b196-af78-44f4-853c-660a144cd305'] = $pane;
    $display->panels['blog_info'][2] = 'new-8465b196-af78-44f4-853c-660a144cd305';
    $pane = new stdClass();
    $pane->pid = 'new-da8650b9-31a4-4d43-bcc8-91dfd9e48a30';
    $pane->panel = 'blog_info';
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
    $pane->uuid = 'da8650b9-31a4-4d43-bcc8-91dfd9e48a30';
    $display->content['new-da8650b9-31a4-4d43-bcc8-91dfd9e48a30'] = $pane;
    $display->panels['blog_info'][3] = 'new-da8650b9-31a4-4d43-bcc8-91dfd9e48a30';
    $pane = new stdClass();
    $pane->pid = 'new-a89f393a-d721-4d89-a02a-12efd946e96e';
    $pane->panel = 'center';
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
    $pane->uuid = 'a89f393a-d721-4d89-a02a-12efd946e96e';
    $display->content['new-a89f393a-d721-4d89-a02a-12efd946e96e'] = $pane;
    $display->panels['center'][0] = 'new-a89f393a-d721-4d89-a02a-12efd946e96e';
    $pane = new stdClass();
    $pane->pid = 'new-e3cf1929-ca24-4803-9c66-8f2e4637475d';
    $pane->panel = 'comments';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 1,
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
    $pane->uuid = 'e3cf1929-ca24-4803-9c66-8f2e4637475d';
    $display->content['new-e3cf1929-ca24-4803-9c66-8f2e4637475d'] = $pane;
    $display->panels['comments'][0] = 'new-e3cf1929-ca24-4803-9c66-8f2e4637475d';
    $pane = new stdClass();
    $pane->pid = 'new-f95d0037-d944-4bf2-9511-bdae0dd24e75';
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
    $pane->uuid = 'f95d0037-d944-4bf2-9511-bdae0dd24e75';
    $display->content['new-f95d0037-d944-4bf2-9511-bdae0dd24e75'] = $pane;
    $display->panels['comments'][1] = 'new-f95d0037-d944-4bf2-9511-bdae0dd24e75';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 7;
  $handler->conf = array(
    'title' => 'Документ',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Файл from Материал (on Материал: Файл [field_document_file])',
        'keyword' => 'file',
        'name' => 'entity_from_field:field_document_file-node-file',
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
              'document' => 'document',
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
  $display->layout = 'onecol';
  $display->layout_settings = array(
    'main_classes' => '',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1b48697e-d58f-4214-a616-6d3b419b1456';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-477e2265-cd63-4383-ab8c-c995df33122b';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_rubric';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'ds_taxonomy_separator',
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
    $pane->uuid = '477e2265-cd63-4383-ab8c-c995df33122b';
    $display->content['new-477e2265-cd63-4383-ab8c-c995df33122b'] = $pane;
    $display->panels['middle'][0] = 'new-477e2265-cd63-4383-ab8c-c995df33122b';
    $pane = new stdClass();
    $pane->pid = 'new-1867a747-8c9b-4318-86cb-ea5a97ed44d4';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'ds_taxonomy_separator',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1867a747-8c9b-4318-86cb-ea5a97ed44d4';
    $display->content['new-1867a747-8c9b-4318-86cb-ea5a97ed44d4'] = $pane;
    $display->panels['middle'][1] = 'new-1867a747-8c9b-4318-86cb-ea5a97ed44d4';
    $pane = new stdClass();
    $pane->pid = 'new-f34a3504-fd3e-4b7b-854e-25242d1d65dd';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Файл (Кастом)',
      'title' => '',
      'body' => '<div class="field-label-inline clearfix">
<div class="field-label">Файл:</div>
<div class="field-items"><a href="%node:field_document_file" class="%file:extension">Скачать</a></div>
</div>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f34a3504-fd3e-4b7b-854e-25242d1d65dd';
    $display->content['new-f34a3504-fd3e-4b7b-854e-25242d1d65dd'] = $pane;
    $display->panels['middle'][2] = 'new-f34a3504-fd3e-4b7b-854e-25242d1d65dd';
    $pane = new stdClass();
    $pane->pid = 'new-e0fae4b9-5e60-4e91-9ee8-9819a14584db';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_document_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'i18n_list_default',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e0fae4b9-5e60-4e91-9ee8-9819a14584db';
    $display->content['new-e0fae4b9-5e60-4e91-9ee8-9819a14584db'] = $pane;
    $display->panels['middle'][3] = 'new-e0fae4b9-5e60-4e91-9ee8-9819a14584db';
    $pane = new stdClass();
    $pane->pid = 'new-ec93d76d-9310-47b1-9eab-2e6fcfdc9a99';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_document_status';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'i18n_list_default',
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
    $pane->uuid = 'ec93d76d-9310-47b1-9eab-2e6fcfdc9a99';
    $display->content['new-ec93d76d-9310-47b1-9eab-2e6fcfdc9a99'] = $pane;
    $display->panels['middle'][4] = 'new-ec93d76d-9310-47b1-9eab-2e6fcfdc9a99';
    $pane = new stdClass();
    $pane->pid = 'new-f7d7bead-f9a5-4266-a58a-b8f33279d8f4';
    $pane->panel = 'middle';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'f7d7bead-f9a5-4266-a58a-b8f33279d8f4';
    $display->content['new-f7d7bead-f9a5-4266-a58a-b8f33279d8f4'] = $pane;
    $display->panels['middle'][5] = 'new-f7d7bead-f9a5-4266-a58a-b8f33279d8f4';
    $pane = new stdClass();
    $pane->pid = 'new-5b162b27-738b-431f-96a9-706b13e059cd';
    $pane->panel = 'middle';
    $pane->type = 'node_updated';
    $pane->subtype = 'node_updated';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'comment',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Дата последнего изменения:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '5b162b27-738b-431f-96a9-706b13e059cd';
    $display->content['new-5b162b27-738b-431f-96a9-706b13e059cd'] = $pane;
    $display->panels['middle'][6] = 'new-5b162b27-738b-431f-96a9-706b13e059cd';
    $pane = new stdClass();
    $pane->pid = 'new-b9476249-794c-4a74-bd0b-4e3d580644df';
    $pane->panel = 'middle';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'comment',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Дата создания:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'b9476249-794c-4a74-bd0b-4e3d580644df';
    $display->content['new-b9476249-794c-4a74-bd0b-4e3d580644df'] = $pane;
    $display->panels['middle'][7] = 'new-b9476249-794c-4a74-bd0b-4e3d580644df';
    $pane = new stdClass();
    $pane->pid = 'new-71e462a7-6dc0-4130-b637-bf004c687c12';
    $pane->panel = 'middle';
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
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '71e462a7-6dc0-4130-b637-bf004c687c12';
    $display->content['new-71e462a7-6dc0-4130-b637-bf004c687c12'] = $pane;
    $display->panels['middle'][8] = 'new-71e462a7-6dc0-4130-b637-bf004c687c12';
    $pane = new stdClass();
    $pane->pid = 'new-472b7a13-8992-4ff5-82c6-e80d4754a193';
    $pane->panel = 'middle';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '50',
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
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '472b7a13-8992-4ff5-82c6-e80d4754a193';
    $display->content['new-472b7a13-8992-4ff5-82c6-e80d4754a193'] = $pane;
    $display->panels['middle'][9] = 'new-472b7a13-8992-4ff5-82c6-e80d4754a193';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_8';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 8;
  $handler->conf = array(
    'title' => 'Идея',
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
        'identifier' => 'Термин таксономии from Материал (on Материал: Рубрика [field_rubric])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_rubric-node-taxonomy_term',
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
              'idea' => 'idea',
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
    $pane->pid = 'new-5d8fea53-86be-4f73-bf0b-735942a76067';
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
      'context' => 'relationship_entity_from_field:field_rubric-node-taxonomy_term_1',
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
    $pane->uuid = '5d8fea53-86be-4f73-bf0b-735942a76067';
    $display->content['new-5d8fea53-86be-4f73-bf0b-735942a76067'] = $pane;
    $display->panels['info'][0] = 'new-5d8fea53-86be-4f73-bf0b-735942a76067';
    $pane = new stdClass();
    $pane->pid = 'new-a5dc4cec-2406-4939-90ba-ba1070698623';
    $pane->panel = 'info';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_rubric';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a5dc4cec-2406-4939-90ba-ba1070698623';
    $display->content['new-a5dc4cec-2406-4939-90ba-ba1070698623'] = $pane;
    $display->panels['info'][1] = 'new-a5dc4cec-2406-4939-90ba-ba1070698623';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c1323212-5cb1-4ec6-8dbd-ea7c3625c299';
    $display->content['new-c1323212-5cb1-4ec6-8dbd-ea7c3625c299'] = $pane;
    $display->panels['info'][2] = 'new-c1323212-5cb1-4ec6-8dbd-ea7c3625c299';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b3963842-7e76-4043-9052-375ce4bc9688';
    $display->content['new-b3963842-7e76-4043-9052-375ce4bc9688'] = $pane;
    $display->panels['info'][3] = 'new-b3963842-7e76-4043-9052-375ce4bc9688';
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
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'f7f6fceb-6245-4d2e-84f6-ce0c60480b2f';
    $display->content['new-f7f6fceb-6245-4d2e-84f6-ce0c60480b2f'] = $pane;
    $display->panels['info'][4] = 'new-f7f6fceb-6245-4d2e-84f6-ce0c60480b2f';
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
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'c1921ae3-f6f6-479e-a634-6ddc884f588e';
    $display->content['new-c1921ae3-f6f6-479e-a634-6ddc884f588e'] = $pane;
    $display->panels['info'][5] = 'new-c1921ae3-f6f6-479e-a634-6ddc884f588e';
    $pane = new stdClass();
    $pane->pid = 'new-6e9beea7-5cdf-4b90-917f-1e1e77ac7f85';
    $pane->panel = 'vote';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_idea_vote_up_down';
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
    $pane->uuid = '6e9beea7-5cdf-4b90-917f-1e1e77ac7f85';
    $display->content['new-6e9beea7-5cdf-4b90-917f-1e1e77ac7f85'] = $pane;
    $display->panels['vote'][0] = 'new-6e9beea7-5cdf-4b90-917f-1e1e77ac7f85';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_8'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_9';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 9;
  $handler->conf = array(
    'title' => 'Новость',
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
              'news' => 'news',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'acadd7d0-e642-4056-9ad0-1a353b200f14';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7470fda5-93b1-4057-af81-cc46e2305d7c';
    $pane->panel = 'middle';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 1,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7470fda5-93b1-4057-af81-cc46e2305d7c';
    $display->content['new-7470fda5-93b1-4057-af81-cc46e2305d7c'] = $pane;
    $display->panels['middle'][0] = 'new-7470fda5-93b1-4057-af81-cc46e2305d7c';
    $pane = new stdClass();
    $pane->pid = 'new-2f898aac-e5ec-4c19-b2fc-c50a26a214ac';
    $pane->panel = 'middle';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 1,
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
    $pane->uuid = '2f898aac-e5ec-4c19-b2fc-c50a26a214ac';
    $display->content['new-2f898aac-e5ec-4c19-b2fc-c50a26a214ac'] = $pane;
    $display->panels['middle'][1] = 'new-2f898aac-e5ec-4c19-b2fc-c50a26a214ac';
    $pane = new stdClass();
    $pane->pid = 'new-5073320d-59a1-45af-b299-b3fea5f7e316';
    $pane->panel = 'middle';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5073320d-59a1-45af-b299-b3fea5f7e316';
    $display->content['new-5073320d-59a1-45af-b299-b3fea5f7e316'] = $pane;
    $display->panels['middle'][2] = 'new-5073320d-59a1-45af-b299-b3fea5f7e316';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_9'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_new_private_message_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'new_private_message';
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
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_5',
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
  $display->title = '';
  $display->uuid = '1ff6c9b2-d59c-4ae8-b5c8-edeead55f2eb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c08871c0-b091-4ea5-bfa0-0ce92b202e03';
    $pane->panel = 'middle';
    $pane->type = 'pm_existing_pages';
    $pane->subtype = 'pm_existing_pages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      0 => 'task_id',
      1 => 'pane_title_from_menu',
      'task_id' => 'new_private_message',
      'pane_title_from_menu' => 0,
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
    $pane->uuid = 'c08871c0-b091-4ea5-bfa0-0ce92b202e03';
    $display->content['new-c08871c0-b091-4ea5-bfa0-0ce92b202e03'] = $pane;
    $display->panels['middle'][0] = 'new-c08871c0-b091-4ea5-bfa0-0ce92b202e03';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c08871c0-b091-4ea5-bfa0-0ce92b202e03';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_new_private_message_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_node_overview_http_response';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'node_overview';
  $handler->handler = 'http_response';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Redirect front 301',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => '<front>',
  );
  $export['pm_existing_pages_node_overview_http_response'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'pm_existing_pages_user_login_page_panel_context';
  $handler->task = 'pm_existing_pages';
  $handler->subtask = 'user_login_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User login',
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
  $display->title = 'Login';
  $display->uuid = '5dcc0d36-92a8-4a4b-b970-2bc1ffe59c84';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-28aeb2c0-67d2-4cba-b07c-1013a68bed6c';
    $pane->panel = 'main';
    $pane->type = 'user_login_form';
    $pane->subtype = 'user_login_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '28aeb2c0-67d2-4cba-b07c-1013a68bed6c';
    $display->content['new-28aeb2c0-67d2-4cba-b07c-1013a68bed6c'] = $pane;
    $display->panels['main'][0] = 'new-28aeb2c0-67d2-4cba-b07c-1013a68bed6c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-28aeb2c0-67d2-4cba-b07c-1013a68bed6c';
  $handler->conf['display'] = $display;
  $export['pm_existing_pages_user_login_page_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -22;
  $handler->conf = array(
    'title' => 'Главная страница',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
          0 => 4,
          1 => 1,
          2 => 3,
          3 => 8,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_main_content',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Row',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'region-orange',
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 5,
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      5 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'children' => array(
          0 => 6,
          1 => 7,
        ),
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_front',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_front' => array(
        'type' => 'region',
        'title' => 'Header front top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => 'header-front-top',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_bottom',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_bottom' => array(
        'type' => 'region',
        'title' => 'Header front bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => 'region-header-facts',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => 'footer-region',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
      'header_front' => NULL,
      'header_bottom' => array(
        'region_title' => 'Open / Close',
        'region_collapsed' => 0,
      ),
    ),
    'header_bottom' => array(
      'style' => 'collapsible',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b7e587df-5bc3-4ad1-963d-b5d032697758';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ed5da075-62d2-4cb2-ba02-12fba716084b';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ed5da075-62d2-4cb2-ba02-12fba716084b';
    $display->content['new-ed5da075-62d2-4cb2-ba02-12fba716084b'] = $pane;
    $display->panels['footer'][0] = 'new-ed5da075-62d2-4cb2-ba02-12fba716084b';
    $pane = new stdClass();
    $pane->pid = 'new-de32ad01-bc08-4758-b621-44d3d6eed8e8';
    $pane->panel = 'header_bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'quick_facts-quick_facts_front';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'style' => 'default',
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'de32ad01-bc08-4758-b621-44d3d6eed8e8';
    $display->content['new-de32ad01-bc08-4758-b621-44d3d6eed8e8'] = $pane;
    $display->panels['header_bottom'][0] = 'new-de32ad01-bc08-4758-b621-44d3d6eed8e8';
    $pane = new stdClass();
    $pane->pid = 'new-981d0af3-6457-43a9-99d2-d7171f3c2ac5';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '981d0af3-6457-43a9-99d2-d7171f3c2ac5';
    $display->content['new-981d0af3-6457-43a9-99d2-d7171f3c2ac5'] = $pane;
    $display->panels['header_front'][0] = 'new-981d0af3-6457-43a9-99d2-d7171f3c2ac5';
    $pane = new stdClass();
    $pane->pid = 'new-75f57c09-1c66-46ee-8cc2-ec164bd3e055';
    $pane->panel = 'header_front';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = '75f57c09-1c66-46ee-8cc2-ec164bd3e055';
    $display->content['new-75f57c09-1c66-46ee-8cc2-ec164bd3e055'] = $pane;
    $display->panels['header_front'][1] = 'new-75f57c09-1c66-46ee-8cc2-ec164bd3e055';
    $pane = new stdClass();
    $pane->pid = 'new-6d2a5326-81eb-4adf-b634-eba781a1db31';
    $pane->panel = 'header_front';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6d2a5326-81eb-4adf-b634-eba781a1db31';
    $display->content['new-6d2a5326-81eb-4adf-b634-eba781a1db31'] = $pane;
    $display->panels['header_front'][2] = 'new-6d2a5326-81eb-4adf-b634-eba781a1db31';
    $pane = new stdClass();
    $pane->pid = 'new-5f831815-4798-45d5-9431-c62b4d90eaba';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '5f831815-4798-45d5-9431-c62b4d90eaba';
    $display->content['new-5f831815-4798-45d5-9431-c62b4d90eaba'] = $pane;
    $display->panels['header_front'][3] = 'new-5f831815-4798-45d5-9431-c62b4d90eaba';
    $pane = new stdClass();
    $pane->pid = 'new-e0bb04bf-a687-410f-85aa-a2c3cf83a67b';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = 'e0bb04bf-a687-410f-85aa-a2c3cf83a67b';
    $display->content['new-e0bb04bf-a687-410f-85aa-a2c3cf83a67b'] = $pane;
    $display->panels['header_front'][4] = 'new-e0bb04bf-a687-410f-85aa-a2c3cf83a67b';
    $pane = new stdClass();
    $pane->pid = 'new-30f9bf74-dff3-44c1-ba4c-532e5c26b3b0';
    $pane->panel = 'region_main_content';
    $pane->type = 'panels_mini';
    $pane->subtype = 'custom_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '30f9bf74-dff3-44c1-ba4c-532e5c26b3b0';
    $display->content['new-30f9bf74-dff3-44c1-ba4c-532e5c26b3b0'] = $pane;
    $display->panels['region_main_content'][0] = 'new-30f9bf74-dff3-44c1-ba4c-532e5c26b3b0';
    $pane = new stdClass();
    $pane->pid = 'new-71ffa430-cc10-4be0-84f1-d83387f6d3f9';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 0,
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
    $pane->uuid = '71ffa430-cc10-4be0-84f1-d83387f6d3f9';
    $display->content['new-71ffa430-cc10-4be0-84f1-d83387f6d3f9'] = $pane;
    $display->panels['region_main_content'][1] = 'new-71ffa430-cc10-4be0-84f1-d83387f6d3f9';
    $pane = new stdClass();
    $pane->pid = 'new-0a18f8fb-242b-41da-971a-b826186ee235';
    $pane->panel = '_______________________';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-datasets_total_count';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Datasets found:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0a18f8fb-242b-41da-971a-b826186ee235';
    $display->content['new-0a18f8fb-242b-41da-971a-b826186ee235'] = $pane;
    $display->panels['_______________________'][0] = 'new-0a18f8fb-242b-41da-971a-b826186ee235';
    $pane = new stdClass();
    $pane->pid = 'new-81610ce5-de29-45c9-b89f-50513e37259e';
    $pane->panel = '_______________________';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-datasets_total_count_for_guest';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Datasets found:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '81610ce5-de29-45c9-b89f-50513e37259e';
    $display->content['new-81610ce5-de29-45c9-b89f-50513e37259e'] = $pane;
    $display->panels['_______________________'][1] = 'new-81610ce5-de29-45c9-b89f-50513e37259e';
    $pane = new stdClass();
    $pane->pid = 'new-a2603c0e-c147-4db7-999d-27bd18833199';
    $pane->panel = '_______________________';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 6,
              1 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Ссылка на добавление данных',
      'title' => '',
      'body' => '<?php
print t(\'<a href="@dataset">Add dataset</a>\', array(\'@dataset\' => url(\'new-dataset\')));
?>',
      'format' => 'ds_code',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a2603c0e-c147-4db7-999d-27bd18833199';
    $display->content['new-a2603c0e-c147-4db7-999d-27bd18833199'] = $pane;
    $display->panels['_______________________'][2] = 'new-a2603c0e-c147-4db7-999d-27bd18833199';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_2';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Разделы рубрик',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'default-template',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
          1 => 2,
          2 => 3,
          3 => 4,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_____________________________________',
        ),
        'parent' => 'main',
        'class' => 'breadcrumbs',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'feedback_block',
          1 => 'rubric_menu',
          2 => 'region_main_content',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Header',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      '_____________________________________' => array(
        'type' => 'region',
        'title' => 'Breadcrumbs',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'breadcrumbs',
        'hide_empty' => 0,
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => '85.76305469603936',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'rubric-content',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => 'footer',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'footer-region',
      ),
      'rubric_menu' => array(
        'type' => 'region',
        'title' => 'Rubric menu',
        'width' => 7.1184726519803,
        'width_type' => '%',
        'parent' => '3',
        'class' => 'rubric-menu',
      ),
      'feedback_block' => array(
        'type' => 'region',
        'title' => 'Feedback block',
        'width' => 7.1184726519803,
        'width_type' => '%',
        'parent' => '3',
        'class' => 'feedback-block',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
      'rubric_menu' => NULL,
      'feedback_block' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e6b751b7-b96e-4351-a961-f40eff270baf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c84da26d-ddb0-4d13-9759-e767acc79bf8';
    $pane->panel = 'feedback_block';
    $pane->type = 'panels_mini';
    $pane->subtype = 'custom_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'c84da26d-ddb0-4d13-9759-e767acc79bf8';
    $display->content['new-c84da26d-ddb0-4d13-9759-e767acc79bf8'] = $pane;
    $display->panels['feedback_block'][0] = 'new-c84da26d-ddb0-4d13-9759-e767acc79bf8';
    $pane = new stdClass();
    $pane->pid = 'new-d9268bf0-4531-46e3-b034-a989984172c3';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'footer-region',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd9268bf0-4531-46e3-b034-a989984172c3';
    $display->content['new-d9268bf0-4531-46e3-b034-a989984172c3'] = $pane;
    $display->panels['footer'][0] = 'new-d9268bf0-4531-46e3-b034-a989984172c3';
    $pane = new stdClass();
    $pane->pid = 'new-1a0c7ec5-c658-4667-940d-9d1dc25e2673';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1a0c7ec5-c658-4667-940d-9d1dc25e2673';
    $display->content['new-1a0c7ec5-c658-4667-940d-9d1dc25e2673'] = $pane;
    $display->panels['region_main_content'][0] = 'new-1a0c7ec5-c658-4667-940d-9d1dc25e2673';
    $pane = new stdClass();
    $pane->pid = 'new-f439b9bf-aca3-48ce-9cdd-894df4334125';
    $pane->panel = 'region_main_content';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
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
    $pane->uuid = 'f439b9bf-aca3-48ce-9cdd-894df4334125';
    $display->content['new-f439b9bf-aca3-48ce-9cdd-894df4334125'] = $pane;
    $display->panels['region_main_content'][1] = 'new-f439b9bf-aca3-48ce-9cdd-894df4334125';
    $pane = new stdClass();
    $pane->pid = 'new-63e740b7-7af0-4dbe-b0eb-312ee98b3edc';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '63e740b7-7af0-4dbe-b0eb-312ee98b3edc';
    $display->content['new-63e740b7-7af0-4dbe-b0eb-312ee98b3edc'] = $pane;
    $display->panels['region_main_content'][2] = 'new-63e740b7-7af0-4dbe-b0eb-312ee98b3edc';
    $pane = new stdClass();
    $pane->pid = 'new-212aafc6-e0ff-447b-943f-f9c364ffdb14';
    $pane->panel = 'rubric_menu';
    $pane->type = 'block';
    $pane->subtype = 'od_rubric_menu-block_rubric_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '212aafc6-e0ff-447b-943f-f9c364ffdb14';
    $display->content['new-212aafc6-e0ff-447b-943f-f9c364ffdb14'] = $pane;
    $display->panels['rubric_menu'][0] = 'new-212aafc6-e0ff-447b-943f-f9c364ffdb14';
    $pane = new stdClass();
    $pane->pid = 'new-9bf94bc0-1eb2-4be1-9ae6-9d27072dd3fe';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '9bf94bc0-1eb2-4be1-9ae6-9d27072dd3fe';
    $display->content['new-9bf94bc0-1eb2-4be1-9ae6-9d27072dd3fe'] = $pane;
    $display->panels['_______________________'][0] = 'new-9bf94bc0-1eb2-4be1-9ae6-9d27072dd3fe';
    $pane = new stdClass();
    $pane->pid = 'new-933d3942-5654-4eda-a958-5a0f029c54f1';
    $pane->panel = '_______________________';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = '933d3942-5654-4eda-a958-5a0f029c54f1';
    $display->content['new-933d3942-5654-4eda-a958-5a0f029c54f1'] = $pane;
    $display->panels['_______________________'][1] = 'new-933d3942-5654-4eda-a958-5a0f029c54f1';
    $pane = new stdClass();
    $pane->pid = 'new-275685df-fc9d-4fb2-a769-9d0437209638';
    $pane->panel = '_______________________';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '275685df-fc9d-4fb2-a769-9d0437209638';
    $display->content['new-275685df-fc9d-4fb2-a769-9d0437209638'] = $pane;
    $display->panels['_______________________'][2] = 'new-275685df-fc9d-4fb2-a769-9d0437209638';
    $pane = new stdClass();
    $pane->pid = 'new-308405cc-face-435a-b226-301ea2b4de58';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '308405cc-face-435a-b226-301ea2b4de58';
    $display->content['new-308405cc-face-435a-b226-301ea2b4de58'] = $pane;
    $display->panels['_______________________'][3] = 'new-308405cc-face-435a-b226-301ea2b4de58';
    $pane = new stdClass();
    $pane->pid = 'new-4682bb1a-9e97-456a-a090-c38b9a604f4e';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '4682bb1a-9e97-456a-a090-c38b9a604f4e';
    $display->content['new-4682bb1a-9e97-456a-a090-c38b9a604f4e'] = $pane;
    $display->panels['_______________________'][4] = 'new-4682bb1a-9e97-456a-a090-c38b9a604f4e';
    $pane = new stdClass();
    $pane->pid = 'new-bb93cb2a-634e-4d72-89b7-efa2e8005778';
    $pane->panel = '_____________________________________';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
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
    $pane->uuid = 'bb93cb2a-634e-4d72-89b7-efa2e8005778';
    $display->content['new-bb93cb2a-634e-4d72-89b7-efa2e8005778'] = $pane;
    $display->panels['_____________________________________'][0] = 'new-bb93cb2a-634e-4d72-89b7-efa2e8005778';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_3';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -26;
  $handler->conf = array(
    'title' => 'Форма',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'custom-form-template',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Node edit form from node',
        'keyword' => 'node_form',
        'name' => 'node_edit_form_from_node',
        'context' => 'node',
        'id' => 1,
      ),
    ),
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
          0 => 4,
          1 => 1,
          2 => 3,
          3 => 7,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_main_content',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Page title',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
        'hide_empty' => 0,
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 5,
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      5 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'children' => array(
          0 => 6,
        ),
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_front',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_front' => array(
        'type' => 'region',
        'title' => 'Header front top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => 'header-front-top',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => 'footer-region',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
      'header_front' => NULL,
      'header_bottom' => NULL,
    ),
    'header_bottom' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '209cbb1b-e391-47e9-a156-ac7df69a1dd3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-14f3bfe3-1386-44eb-9a7d-4ecd001e698d';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '14f3bfe3-1386-44eb-9a7d-4ecd001e698d';
    $display->content['new-14f3bfe3-1386-44eb-9a7d-4ecd001e698d'] = $pane;
    $display->panels['footer'][0] = 'new-14f3bfe3-1386-44eb-9a7d-4ecd001e698d';
    $pane = new stdClass();
    $pane->pid = 'new-6a634e5b-036e-45b1-bc1e-064106abdb9f';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '6a634e5b-036e-45b1-bc1e-064106abdb9f';
    $display->content['new-6a634e5b-036e-45b1-bc1e-064106abdb9f'] = $pane;
    $display->panels['header_front'][0] = 'new-6a634e5b-036e-45b1-bc1e-064106abdb9f';
    $pane = new stdClass();
    $pane->pid = 'new-fe25841b-ed0c-4fe5-b8df-213ac2a13c49';
    $pane->panel = 'header_front';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = 'fe25841b-ed0c-4fe5-b8df-213ac2a13c49';
    $display->content['new-fe25841b-ed0c-4fe5-b8df-213ac2a13c49'] = $pane;
    $display->panels['header_front'][1] = 'new-fe25841b-ed0c-4fe5-b8df-213ac2a13c49';
    $pane = new stdClass();
    $pane->pid = 'new-598bb918-453f-454e-addc-7f2ce398ab4e';
    $pane->panel = 'header_front';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_block';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '598bb918-453f-454e-addc-7f2ce398ab4e';
    $display->content['new-598bb918-453f-454e-addc-7f2ce398ab4e'] = $pane;
    $display->panels['header_front'][2] = 'new-598bb918-453f-454e-addc-7f2ce398ab4e';
    $pane = new stdClass();
    $pane->pid = 'new-28fbfd9b-c10f-494b-9515-91ae79013166';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '28fbfd9b-c10f-494b-9515-91ae79013166';
    $display->content['new-28fbfd9b-c10f-494b-9515-91ae79013166'] = $pane;
    $display->panels['header_front'][3] = 'new-28fbfd9b-c10f-494b-9515-91ae79013166';
    $pane = new stdClass();
    $pane->pid = 'new-af69450d-12a0-4486-9fa0-af019c0ece03';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = 'af69450d-12a0-4486-9fa0-af019c0ece03';
    $display->content['new-af69450d-12a0-4486-9fa0-af019c0ece03'] = $pane;
    $display->panels['header_front'][4] = 'new-af69450d-12a0-4486-9fa0-af019c0ece03';
    $pane = new stdClass();
    $pane->pid = 'new-0abed7ad-8878-43ae-be8a-c6d5bafe3b42';
    $pane->panel = 'region_main_content';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'user/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0abed7ad-8878-43ae-be8a-c6d5bafe3b42';
    $display->content['new-0abed7ad-8878-43ae-be8a-c6d5bafe3b42'] = $pane;
    $display->panels['region_main_content'][0] = 'new-0abed7ad-8878-43ae-be8a-c6d5bafe3b42';
    $pane = new stdClass();
    $pane->pid = 'new-7f801675-81a2-424d-893a-eaa1893c6d94';
    $pane->panel = 'region_main_content';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'relationship_node_edit_form_from_node_1',
      'override_title' => 0,
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
    $pane->uuid = '7f801675-81a2-424d-893a-eaa1893c6d94';
    $display->content['new-7f801675-81a2-424d-893a-eaa1893c6d94'] = $pane;
    $display->panels['region_main_content'][1] = 'new-7f801675-81a2-424d-893a-eaa1893c6d94';
    $pane = new stdClass();
    $pane->pid = 'new-2f5f7278-c607-486a-83ab-8a5ad00c31ed';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2f5f7278-c607-486a-83ab-8a5ad00c31ed';
    $display->content['new-2f5f7278-c607-486a-83ab-8a5ad00c31ed'] = $pane;
    $display->panels['region_main_content'][2] = 'new-2f5f7278-c607-486a-83ab-8a5ad00c31ed';
    $pane = new stdClass();
    $pane->pid = 'new-7809e919-36fa-4522-ae46-c961df63752b';
    $pane->panel = '_______________________';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'user/*/edit',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = '7809e919-36fa-4522-ae46-c961df63752b';
    $display->content['new-7809e919-36fa-4522-ae46-c961df63752b'] = $pane;
    $display->panels['_______________________'][0] = 'new-7809e919-36fa-4522-ae46-c961df63752b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_4';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -27;
  $handler->conf = array(
    'title' => 'Default + Search block',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
          0 => 4,
          1 => 1,
          2 => 3,
          3 => 8,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_main_content',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Row',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'region-orange',
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 5,
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      5 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'children' => array(
          0 => 6,
          1 => 7,
        ),
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_front',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_front' => array(
        'type' => 'region',
        'title' => 'Header front top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => 'header-front-top',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_bottom',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_bottom' => array(
        'type' => 'region',
        'title' => 'Header front bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => 'region-header-facts',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => 'footer-region',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
      'header_front' => NULL,
      'header_bottom' => NULL,
    ),
    'header_bottom' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fd0c4f57-b5b2-4247-9393-b1b6b5491360';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-953148c0-d43c-4d54-ad50-8aa2cafde65e';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'test',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '953148c0-d43c-4d54-ad50-8aa2cafde65e';
    $display->content['new-953148c0-d43c-4d54-ad50-8aa2cafde65e'] = $pane;
    $display->panels['footer'][0] = 'new-953148c0-d43c-4d54-ad50-8aa2cafde65e';
    $pane = new stdClass();
    $pane->pid = 'new-90695bb4-9e6e-4033-af88-251bcddb492a';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '90695bb4-9e6e-4033-af88-251bcddb492a';
    $display->content['new-90695bb4-9e6e-4033-af88-251bcddb492a'] = $pane;
    $display->panels['header_front'][0] = 'new-90695bb4-9e6e-4033-af88-251bcddb492a';
    $pane = new stdClass();
    $pane->pid = 'new-d953c430-f7b7-4776-93de-88af9de16a62';
    $pane->panel = 'header_front';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = 'd953c430-f7b7-4776-93de-88af9de16a62';
    $display->content['new-d953c430-f7b7-4776-93de-88af9de16a62'] = $pane;
    $display->panels['header_front'][1] = 'new-d953c430-f7b7-4776-93de-88af9de16a62';
    $pane = new stdClass();
    $pane->pid = 'new-f45c1665-38de-4041-9929-4ba622f46590';
    $pane->panel = 'header_front';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f45c1665-38de-4041-9929-4ba622f46590';
    $display->content['new-f45c1665-38de-4041-9929-4ba622f46590'] = $pane;
    $display->panels['header_front'][2] = 'new-f45c1665-38de-4041-9929-4ba622f46590';
    $pane = new stdClass();
    $pane->pid = 'new-b6c6f765-28e3-4eaf-b641-c4e365b447fa';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b6c6f765-28e3-4eaf-b641-c4e365b447fa';
    $display->content['new-b6c6f765-28e3-4eaf-b641-c4e365b447fa'] = $pane;
    $display->panels['header_front'][3] = 'new-b6c6f765-28e3-4eaf-b641-c4e365b447fa';
    $pane = new stdClass();
    $pane->pid = 'new-1881f1fd-a422-4b2d-9736-f1b3ce1612d2';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '1881f1fd-a422-4b2d-9736-f1b3ce1612d2';
    $display->content['new-1881f1fd-a422-4b2d-9736-f1b3ce1612d2'] = $pane;
    $display->panels['header_front'][4] = 'new-1881f1fd-a422-4b2d-9736-f1b3ce1612d2';
    $pane = new stdClass();
    $pane->pid = 'new-66f2dc7c-2b7a-426b-bdbc-8c47f6a18244';
    $pane->panel = 'region_main_content';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
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
    $pane->uuid = '66f2dc7c-2b7a-426b-bdbc-8c47f6a18244';
    $display->content['new-66f2dc7c-2b7a-426b-bdbc-8c47f6a18244'] = $pane;
    $display->panels['region_main_content'][0] = 'new-66f2dc7c-2b7a-426b-bdbc-8c47f6a18244';
    $pane = new stdClass();
    $pane->pid = 'new-9311c186-4960-4b64-a740-f566c54643ff';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = '9311c186-4960-4b64-a740-f566c54643ff';
    $display->content['new-9311c186-4960-4b64-a740-f566c54643ff'] = $pane;
    $display->panels['region_main_content'][1] = 'new-9311c186-4960-4b64-a740-f566c54643ff';
    $pane = new stdClass();
    $pane->pid = 'new-d8a47048-e9ae-4a43-b6fc-0f525ce54791';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd8a47048-e9ae-4a43-b6fc-0f525ce54791';
    $display->content['new-d8a47048-e9ae-4a43-b6fc-0f525ce54791'] = $pane;
    $display->panels['region_main_content'][2] = 'new-d8a47048-e9ae-4a43-b6fc-0f525ce54791';
    $pane = new stdClass();
    $pane->pid = 'new-90807739-4d4d-48b8-870c-531daf0c483f';
    $pane->panel = '_______________________';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-datasets_total_count';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 4,
              1 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Number of datasets in the portal:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '90807739-4d4d-48b8-870c-531daf0c483f';
    $display->content['new-90807739-4d4d-48b8-870c-531daf0c483f'] = $pane;
    $display->panels['_______________________'][0] = 'new-90807739-4d4d-48b8-870c-531daf0c483f';
    $pane = new stdClass();
    $pane->pid = 'new-209588be-d613-477f-9d65-08806ff4bb2a';
    $pane->panel = '_______________________';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-datasets_total_count_for_guest';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 6,
              1 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Number of datasets in the portal:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '209588be-d613-477f-9d65-08806ff4bb2a';
    $display->content['new-209588be-d613-477f-9d65-08806ff4bb2a'] = $pane;
    $display->panels['_______________________'][1] = 'new-209588be-d613-477f-9d65-08806ff4bb2a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_5';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Nodes',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'default-template',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
          1 => 2,
          2 => 3,
          3 => 4,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_____________________________________',
        ),
        'parent' => 'main',
        'class' => 'breadcrumbs',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_main_content',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Header',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      '_____________________________________' => array(
        'type' => 'region',
        'title' => 'Breadcrumbs',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => 'breadcrumbs',
        'hide_empty' => 0,
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'footer-region',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
    ),
    'footer' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ae42f641-97cd-46da-a792-e2b1c587d841';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0ab7980b-3e37-4df7-a936-b69e17737629';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'default',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'footer-region',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0ab7980b-3e37-4df7-a936-b69e17737629';
    $display->content['new-0ab7980b-3e37-4df7-a936-b69e17737629'] = $pane;
    $display->panels['footer'][0] = 'new-0ab7980b-3e37-4df7-a936-b69e17737629';
    $pane = new stdClass();
    $pane->pid = 'new-2e13ba90-b386-494e-96d1-30182043c6c6';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = '2e13ba90-b386-494e-96d1-30182043c6c6';
    $display->content['new-2e13ba90-b386-494e-96d1-30182043c6c6'] = $pane;
    $display->panels['region_main_content'][0] = 'new-2e13ba90-b386-494e-96d1-30182043c6c6';
    $pane = new stdClass();
    $pane->pid = 'new-7b64b123-de0c-4fb8-93b1-a5ff83a34963';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'dataset' => 'dataset',
            ),
          ),
          'context' => 'node',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = '7b64b123-de0c-4fb8-93b1-a5ff83a34963';
    $display->content['new-7b64b123-de0c-4fb8-93b1-a5ff83a34963'] = $pane;
    $display->panels['region_main_content'][1] = 'new-7b64b123-de0c-4fb8-93b1-a5ff83a34963';
    $pane = new stdClass();
    $pane->pid = 'new-a7ab1fa7-ae4c-424f-abb0-ac08e6092a9e';
    $pane->panel = 'region_main_content';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
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
    $pane->uuid = 'a7ab1fa7-ae4c-424f-abb0-ac08e6092a9e';
    $display->content['new-a7ab1fa7-ae4c-424f-abb0-ac08e6092a9e'] = $pane;
    $display->panels['region_main_content'][2] = 'new-a7ab1fa7-ae4c-424f-abb0-ac08e6092a9e';
    $pane = new stdClass();
    $pane->pid = 'new-ef9e9ae7-634f-49fc-8099-d84764ac783c';
    $pane->panel = 'region_main_content';
    $pane->type = 'panels_mini';
    $pane->subtype = 'custom_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $pane->uuid = 'ef9e9ae7-634f-49fc-8099-d84764ac783c';
    $display->content['new-ef9e9ae7-634f-49fc-8099-d84764ac783c'] = $pane;
    $display->panels['region_main_content'][3] = 'new-ef9e9ae7-634f-49fc-8099-d84764ac783c';
    $pane = new stdClass();
    $pane->pid = 'new-24ba9552-09d8-43f1-ae15-eea056a10908';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
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
    $pane->uuid = '24ba9552-09d8-43f1-ae15-eea056a10908';
    $display->content['new-24ba9552-09d8-43f1-ae15-eea056a10908'] = $pane;
    $display->panels['region_main_content'][4] = 'new-24ba9552-09d8-43f1-ae15-eea056a10908';
    $pane = new stdClass();
    $pane->pid = 'new-596cd46d-2c8b-4db9-baf9-6374048b5db5';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '596cd46d-2c8b-4db9-baf9-6374048b5db5';
    $display->content['new-596cd46d-2c8b-4db9-baf9-6374048b5db5'] = $pane;
    $display->panels['_______________________'][0] = 'new-596cd46d-2c8b-4db9-baf9-6374048b5db5';
    $pane = new stdClass();
    $pane->pid = 'new-39917682-5082-4f08-ba4d-88c1b912df6c';
    $pane->panel = '_______________________';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = '39917682-5082-4f08-ba4d-88c1b912df6c';
    $display->content['new-39917682-5082-4f08-ba4d-88c1b912df6c'] = $pane;
    $display->panels['_______________________'][1] = 'new-39917682-5082-4f08-ba4d-88c1b912df6c';
    $pane = new stdClass();
    $pane->pid = 'new-8101c2ed-aaf0-43ae-ad12-4dc3d6fac12e';
    $pane->panel = '_______________________';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8101c2ed-aaf0-43ae-ad12-4dc3d6fac12e';
    $display->content['new-8101c2ed-aaf0-43ae-ad12-4dc3d6fac12e'] = $pane;
    $display->panels['_______________________'][2] = 'new-8101c2ed-aaf0-43ae-ad12-4dc3d6fac12e';
    $pane = new stdClass();
    $pane->pid = 'new-bc0ad49e-aa4d-4525-b71c-47451923ae1d';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'bc0ad49e-aa4d-4525-b71c-47451923ae1d';
    $display->content['new-bc0ad49e-aa4d-4525-b71c-47451923ae1d'] = $pane;
    $display->panels['_______________________'][3] = 'new-bc0ad49e-aa4d-4525-b71c-47451923ae1d';
    $pane = new stdClass();
    $pane->pid = 'new-1f1488b4-d4c5-4f60-a2fc-b3d94457d9e5';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '1f1488b4-d4c5-4f60-a2fc-b3d94457d9e5';
    $display->content['new-1f1488b4-d4c5-4f60-a2fc-b3d94457d9e5'] = $pane;
    $display->panels['_______________________'][4] = 'new-1f1488b4-d4c5-4f60-a2fc-b3d94457d9e5';
    $pane = new stdClass();
    $pane->pid = 'new-80c1322f-17d1-4ac9-add6-51b915f5f12a';
    $pane->panel = '_____________________________________';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
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
    $pane->uuid = '80c1322f-17d1-4ac9-add6-51b915f5f12a';
    $display->content['new-80c1322f-17d1-4ac9-add6-51b915f5f12a'] = $pane;
    $display->panels['_____________________________________'][0] = 'new-80c1322f-17d1-4ac9-add6-51b915f5f12a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_6';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -25;
  $handler->conf = array(
    'title' => 'Заглушка',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
          0 => 4,
          1 => 1,
          2 => 3,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_main_content',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Row',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'region-orange',
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => 'footer-region',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 5,
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      5 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'children' => array(
          0 => 6,
        ),
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_front',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_front' => array(
        'type' => 'region',
        'title' => 'Header front top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => 'header-front-top',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
      'header_front' => NULL,
    ),
    'header_bottom' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7f6527a0-a568-4c6e-a922-f3c7398fa077';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8d2daad0-9be9-445d-9dad-df26e26cfbde';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '8d2daad0-9be9-445d-9dad-df26e26cfbde';
    $display->content['new-8d2daad0-9be9-445d-9dad-df26e26cfbde'] = $pane;
    $display->panels['header_front'][0] = 'new-8d2daad0-9be9-445d-9dad-df26e26cfbde';
    $pane = new stdClass();
    $pane->pid = 'new-a7312995-988d-4fdd-a063-6162735768be';
    $pane->panel = 'header_front';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = 'a7312995-988d-4fdd-a063-6162735768be';
    $display->content['new-a7312995-988d-4fdd-a063-6162735768be'] = $pane;
    $display->panels['header_front'][1] = 'new-a7312995-988d-4fdd-a063-6162735768be';
    $pane = new stdClass();
    $pane->pid = 'new-c22ebab9-bf0a-4f24-97bf-485014973fb2';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c22ebab9-bf0a-4f24-97bf-485014973fb2';
    $display->content['new-c22ebab9-bf0a-4f24-97bf-485014973fb2'] = $pane;
    $display->panels['header_front'][2] = 'new-c22ebab9-bf0a-4f24-97bf-485014973fb2';
    $pane = new stdClass();
    $pane->pid = 'new-e54f4edb-0b32-4026-a888-fb620fce0398';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'e54f4edb-0b32-4026-a888-fb620fce0398';
    $display->content['new-e54f4edb-0b32-4026-a888-fb620fce0398'] = $pane;
    $display->panels['header_front'][3] = 'new-e54f4edb-0b32-4026-a888-fb620fce0398';
    $pane = new stdClass();
    $pane->pid = 'new-e9a8c1e9-02d8-4be1-ad24-d9e90de70f08';
    $pane->panel = 'region_main_content';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e9a8c1e9-02d8-4be1-ad24-d9e90de70f08';
    $display->content['new-e9a8c1e9-02d8-4be1-ad24-d9e90de70f08'] = $pane;
    $display->panels['region_main_content'][0] = 'new-e9a8c1e9-02d8-4be1-ad24-d9e90de70f08';
    $pane = new stdClass();
    $pane->pid = 'new-d0e74bc2-3714-4b57-9a4a-77414317412a';
    $pane->panel = '_______________________';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<h2>СТРАНИЦА В СТАДИИ РАЗРАБОТКИ</h2>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd0e74bc2-3714-4b57-9a4a-77414317412a';
    $display->content['new-d0e74bc2-3714-4b57-9a4a-77414317412a'] = $pane;
    $display->panels['_______________________'][0] = 'new-d0e74bc2-3714-4b57-9a4a-77414317412a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_6'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_7';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -24;
  $handler->conf = array(
    'title' => 'Профиль пользователя',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => 'h1 {
  display:none; 
}',
    'contexts' => array(),
    'relationships' => array(),
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
          0 => 4,
          1 => 1,
          2 => 3,
          3 => 8,
          4 => 9,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => 'breadcrumbs',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'avatar__name__roles',
          1 => 'region_main_content',
          2 => 'user_menu',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Breadcrumbs',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'breadcrumbs',
        'hide_empty' => 0,
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'User Info Section',
        'width' => '54.49575449150525',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'region-user-main-info',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 5,
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      5 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'children' => array(
          0 => 6,
        ),
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_front',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_front' => array(
        'type' => 'region',
        'title' => 'Header front top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => 'header-front-top',
      ),
      'avatar__name__roles' => array(
        'type' => 'region',
        'title' => 'Avatar, Name, Roles',
        'width' => '15.6463108239758',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'region-user-avatar',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'user_menu__superfish_',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'user_menu__superfish_' => array(
        'type' => 'region',
        'title' => 'User Menu (Superfish)',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '9',
        'class' => 'footer-region',
      ),
      'user_menu' => array(
        'type' => 'region',
        'title' => 'User menu',
        'width' => '29.857934684518753',
        'width_type' => '%',
        'parent' => '3',
        'class' => 'user-menu',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
      'header_front' => NULL,
      'header_bottom' => NULL,
      'avatar__name__roles' => NULL,
      'user_menu__superfish_' => NULL,
      'user_menu' => NULL,
    ),
    'header_bottom' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '64c05cff-7dce-4ee0-b624-b796a096c783';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3db25023-d255-41dd-af22-14a061c39b4a';
    $pane->panel = 'avatar__name__roles';
    $pane->type = 'user_picture';
    $pane->subtype = 'user_picture';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'account',
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
    $pane->uuid = '3db25023-d255-41dd-af22-14a061c39b4a';
    $display->content['new-3db25023-d255-41dd-af22-14a061c39b4a'] = $pane;
    $display->panels['avatar__name__roles'][0] = 'new-3db25023-d255-41dd-af22-14a061c39b4a';
    $pane = new stdClass();
    $pane->pid = 'new-93ae6f4e-e854-4100-81b7-e05c1c474131';
    $pane->panel = 'avatar__name__roles';
    $pane->type = 'token';
    $pane->subtype = 'user:name-raw';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'account',
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
    $pane->uuid = '93ae6f4e-e854-4100-81b7-e05c1c474131';
    $display->content['new-93ae6f4e-e854-4100-81b7-e05c1c474131'] = $pane;
    $display->panels['avatar__name__roles'][1] = 'new-93ae6f4e-e854-4100-81b7-e05c1c474131';
    $pane = new stdClass();
    $pane->pid = 'new-a379d4e6-75d6-437a-8bf6-2b814a05a7d9';
    $pane->panel = 'avatar__name__roles';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Роли пользователя/PHP + Localize',
      'title' => '',
      'body' => '<div class="panel-pane pane-token pane-user-roles">
        <h2 class="pane-title"><?php print t(\'User roles:\'); ?></h2>
<?php
if (arg(0) == \'user\' && arg(1)) {
  $users_roles = array(2=>\'authenticated user\', 
                             3=>\'editor\',
                             4=>\'moderator\',
                             5=>\'administrator\',
                             6=>\'publisher\', );
  $account=user_load(arg(1)); 
  $user_roles = array();
    foreach ($account->roles as $key=>$val) {
      $user_roles[$key] = t($users_roles[$key]);
    }
   
   $user_roles_string = implode(", ", $user_roles);
   print $user_roles_string;
}
?>
</div>',
      'format' => 'ds_code',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a379d4e6-75d6-437a-8bf6-2b814a05a7d9';
    $display->content['new-a379d4e6-75d6-437a-8bf6-2b814a05a7d9'] = $pane;
    $display->panels['avatar__name__roles'][2] = 'new-a379d4e6-75d6-437a-8bf6-2b814a05a7d9';
    $pane = new stdClass();
    $pane->pid = 'new-3a741654-0744-4dd3-9d1e-9d7c8ba4e57b';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'footer-region',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3a741654-0744-4dd3-9d1e-9d7c8ba4e57b';
    $display->content['new-3a741654-0744-4dd3-9d1e-9d7c8ba4e57b'] = $pane;
    $display->panels['footer'][0] = 'new-3a741654-0744-4dd3-9d1e-9d7c8ba4e57b';
    $pane = new stdClass();
    $pane->pid = 'new-15f2d508-a416-4bfb-b164-f2d7dd283aa4';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '15f2d508-a416-4bfb-b164-f2d7dd283aa4';
    $display->content['new-15f2d508-a416-4bfb-b164-f2d7dd283aa4'] = $pane;
    $display->panels['header_front'][0] = 'new-15f2d508-a416-4bfb-b164-f2d7dd283aa4';
    $pane = new stdClass();
    $pane->pid = 'new-0cb57c93-b05d-434c-ab5b-a307520ea012';
    $pane->panel = 'header_front';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = '0cb57c93-b05d-434c-ab5b-a307520ea012';
    $display->content['new-0cb57c93-b05d-434c-ab5b-a307520ea012'] = $pane;
    $display->panels['header_front'][1] = 'new-0cb57c93-b05d-434c-ab5b-a307520ea012';
    $pane = new stdClass();
    $pane->pid = 'new-28cc0190-1e5a-4fa5-9937-1d40cef9eebb';
    $pane->panel = 'header_front';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '28cc0190-1e5a-4fa5-9937-1d40cef9eebb';
    $display->content['new-28cc0190-1e5a-4fa5-9937-1d40cef9eebb'] = $pane;
    $display->panels['header_front'][2] = 'new-28cc0190-1e5a-4fa5-9937-1d40cef9eebb';
    $pane = new stdClass();
    $pane->pid = 'new-14dafb96-0371-4c02-83fc-c4aada80d8ab';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '14dafb96-0371-4c02-83fc-c4aada80d8ab';
    $display->content['new-14dafb96-0371-4c02-83fc-c4aada80d8ab'] = $pane;
    $display->panels['header_front'][3] = 'new-14dafb96-0371-4c02-83fc-c4aada80d8ab';
    $pane = new stdClass();
    $pane->pid = 'new-de32ddea-cbe7-4546-ae97-3bfc673b7084';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = 'de32ddea-cbe7-4546-ae97-3bfc673b7084';
    $display->content['new-de32ddea-cbe7-4546-ae97-3bfc673b7084'] = $pane;
    $display->panels['header_front'][4] = 'new-de32ddea-cbe7-4546-ae97-3bfc673b7084';
    $pane = new stdClass();
    $pane->pid = 'new-1f1df21b-69b6-4df6-9b78-e8986d88cc47';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = '1f1df21b-69b6-4df6-9b78-e8986d88cc47';
    $display->content['new-1f1df21b-69b6-4df6-9b78-e8986d88cc47'] = $pane;
    $display->panels['region_main_content'][0] = 'new-1f1df21b-69b6-4df6-9b78-e8986d88cc47';
    $pane = new stdClass();
    $pane->pid = 'new-7722ac32-6f03-41d6-9c38-9e1160593831';
    $pane->panel = 'region_main_content';
    $pane->type = 'token';
    $pane->subtype = 'user:name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'account',
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
    $pane->uuid = '7722ac32-6f03-41d6-9c38-9e1160593831';
    $display->content['new-7722ac32-6f03-41d6-9c38-9e1160593831'] = $pane;
    $display->panels['region_main_content'][1] = 'new-7722ac32-6f03-41d6-9c38-9e1160593831';
    $pane = new stdClass();
    $pane->pid = 'new-485a0889-5796-4ac5-a2ed-e114539c09bc';
    $pane->panel = 'region_main_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_user_categorie';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'account',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '485a0889-5796-4ac5-a2ed-e114539c09bc';
    $display->content['new-485a0889-5796-4ac5-a2ed-e114539c09bc'] = $pane;
    $display->panels['region_main_content'][2] = 'new-485a0889-5796-4ac5-a2ed-e114539c09bc';
    $pane = new stdClass();
    $pane->pid = 'new-433a178e-6b5b-4489-932b-fd26feb58a74';
    $pane->panel = 'region_main_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_user_work';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'account',
      'override_title' => 0,
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
    $pane->uuid = '433a178e-6b5b-4489-932b-fd26feb58a74';
    $display->content['new-433a178e-6b5b-4489-932b-fd26feb58a74'] = $pane;
    $display->panels['region_main_content'][3] = 'new-433a178e-6b5b-4489-932b-fd26feb58a74';
    $pane = new stdClass();
    $pane->pid = 'new-d811aa7c-3849-475c-b74a-520aee923439';
    $pane->panel = 'region_main_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_user_work_position';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'account',
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
    $pane->uuid = 'd811aa7c-3849-475c-b74a-520aee923439';
    $display->content['new-d811aa7c-3849-475c-b74a-520aee923439'] = $pane;
    $display->panels['region_main_content'][4] = 'new-d811aa7c-3849-475c-b74a-520aee923439';
    $pane = new stdClass();
    $pane->pid = 'new-7dcbe433-cd15-4d2e-98bb-53081ac553f5';
    $pane->panel = 'region_main_content';
    $pane->type = 'entity_field';
    $pane->subtype = 'user:field_contact_phone_number';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'account',
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
    $pane->uuid = '7dcbe433-cd15-4d2e-98bb-53081ac553f5';
    $display->content['new-7dcbe433-cd15-4d2e-98bb-53081ac553f5'] = $pane;
    $display->panels['region_main_content'][5] = 'new-7dcbe433-cd15-4d2e-98bb-53081ac553f5';
    $pane = new stdClass();
    $pane->pid = 'new-c1a151e1-16c5-4278-98af-7a59eb8f3fb0';
    $pane->panel = 'region_main_content';
    $pane->type = 'entity_field_extra';
    $pane->subtype = 'user:summary';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'account',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'c1a151e1-16c5-4278-98af-7a59eb8f3fb0';
    $display->content['new-c1a151e1-16c5-4278-98af-7a59eb8f3fb0'] = $pane;
    $display->panels['region_main_content'][6] = 'new-c1a151e1-16c5-4278-98af-7a59eb8f3fb0';
    $pane = new stdClass();
    $pane->pid = 'new-f138e471-7110-407b-95a9-34f37a6fefbc';
    $pane->panel = 'user_menu';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-user-menu-3';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'account',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
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
    $pane->uuid = 'f138e471-7110-407b-95a9-34f37a6fefbc';
    $display->content['new-f138e471-7110-407b-95a9-34f37a6fefbc'] = $pane;
    $display->panels['user_menu'][0] = 'new-f138e471-7110-407b-95a9-34f37a6fefbc';
    $pane = new stdClass();
    $pane->pid = 'new-e35414e2-eb6d-4dbf-bac8-aca760222a84';
    $pane->panel = 'user_menu';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-user-menu-2';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 6,
              1 => 3,
              2 => 4,
              3 => 5,
            ),
          ),
          'context' => 'account',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'logged-in-user',
            1 => 'account',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Add content',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e35414e2-eb6d-4dbf-bac8-aca760222a84';
    $display->content['new-e35414e2-eb6d-4dbf-bac8-aca760222a84'] = $pane;
    $display->panels['user_menu'][1] = 'new-e35414e2-eb6d-4dbf-bac8-aca760222a84';
    $pane = new stdClass();
    $pane->pid = 'new-fc8153d4-d2b0-424b-8868-5f650c89cee7';
    $pane->panel = 'user_menu__superfish_';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = 'fc8153d4-d2b0-424b-8868-5f650c89cee7';
    $display->content['new-fc8153d4-d2b0-424b-8868-5f650c89cee7'] = $pane;
    $display->panels['user_menu__superfish_'][0] = 'new-fc8153d4-d2b0-424b-8868-5f650c89cee7';
    $pane = new stdClass();
    $pane->pid = 'new-8fea1b85-211b-4a69-af7a-ba6e6defd86d';
    $pane->panel = 'user_menu__superfish_';
    $pane->type = 'block';
    $pane->subtype = 'superfish-2';
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
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
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
    $pane->uuid = '8fea1b85-211b-4a69-af7a-ba6e6defd86d';
    $display->content['new-8fea1b85-211b-4a69-af7a-ba6e6defd86d'] = $pane;
    $display->panels['user_menu__superfish_'][1] = 'new-8fea1b85-211b-4a69-af7a-ba6e6defd86d';
    $pane = new stdClass();
    $pane->pid = 'new-8abbac51-a228-4cda-8169-5e51e349b9a7';
    $pane->panel = 'user_menu__superfish_';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8abbac51-a228-4cda-8169-5e51e349b9a7';
    $display->content['new-8abbac51-a228-4cda-8169-5e51e349b9a7'] = $pane;
    $display->panels['user_menu__superfish_'][2] = 'new-8abbac51-a228-4cda-8169-5e51e349b9a7';
    $pane = new stdClass();
    $pane->pid = 'new-2edfd71f-d8ff-4982-ac2b-809adc897f7b';
    $pane->panel = '_______________________';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
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
    $pane->uuid = '2edfd71f-d8ff-4982-ac2b-809adc897f7b';
    $display->content['new-2edfd71f-d8ff-4982-ac2b-809adc897f7b'] = $pane;
    $display->panels['_______________________'][0] = 'new-2edfd71f-d8ff-4982-ac2b-809adc897f7b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_8';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -23;
  $handler->conf = array(
    'title' => 'Конкурс',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'competition-template',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
          1 => 2,
          2 => 3,
          3 => 4,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_____________________________________',
        ),
        'parent' => 'main',
        'class' => 'region-orange',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_main_content',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Header',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      '_____________________________________' => array(
        'type' => 'region',
        'title' => 'Abilities',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'class' => 'footer-region',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7c9e2708-7611-453d-a30c-fda60e1dc56d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d98d6173-7b34-4cab-b334-dc2cd3518880';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd98d6173-7b34-4cab-b334-dc2cd3518880';
    $display->content['new-d98d6173-7b34-4cab-b334-dc2cd3518880'] = $pane;
    $display->panels['footer'][0] = 'new-d98d6173-7b34-4cab-b334-dc2cd3518880';
    $pane = new stdClass();
    $pane->pid = 'new-2220229f-69f7-42d6-9eef-ab8a345441a5';
    $pane->panel = 'region_main_content';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Ссылка на общий список конкурсов',
      'title' => '',
      'body' => '<a class="btn" href="/competitions">Вернуться  к списку конкурсов </a>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2220229f-69f7-42d6-9eef-ab8a345441a5';
    $display->content['new-2220229f-69f7-42d6-9eef-ab8a345441a5'] = $pane;
    $display->panels['region_main_content'][0] = 'new-2220229f-69f7-42d6-9eef-ab8a345441a5';
    $pane = new stdClass();
    $pane->pid = 'new-e6beb347-7382-43a5-bf55-dba0f6999252';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = 'e6beb347-7382-43a5-bf55-dba0f6999252';
    $display->content['new-e6beb347-7382-43a5-bf55-dba0f6999252'] = $pane;
    $display->panels['region_main_content'][1] = 'new-e6beb347-7382-43a5-bf55-dba0f6999252';
    $pane = new stdClass();
    $pane->pid = 'new-b5289afe-75a5-48f6-adc0-2fd18b508b10';
    $pane->panel = 'region_main_content';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
      'logic' => 'or',
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b5289afe-75a5-48f6-adc0-2fd18b508b10';
    $display->content['new-b5289afe-75a5-48f6-adc0-2fd18b508b10'] = $pane;
    $display->panels['region_main_content'][2] = 'new-b5289afe-75a5-48f6-adc0-2fd18b508b10';
    $pane = new stdClass();
    $pane->pid = 'new-9cab13b5-e5d1-49d6-8821-c891ff3cf77f';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = '9cab13b5-e5d1-49d6-8821-c891ff3cf77f';
    $display->content['new-9cab13b5-e5d1-49d6-8821-c891ff3cf77f'] = $pane;
    $display->panels['region_main_content'][3] = 'new-9cab13b5-e5d1-49d6-8821-c891ff3cf77f';
    $pane = new stdClass();
    $pane->pid = 'new-bbcf6b58-b52c-44aa-8837-d1682e4a8460';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'bbcf6b58-b52c-44aa-8837-d1682e4a8460';
    $display->content['new-bbcf6b58-b52c-44aa-8837-d1682e4a8460'] = $pane;
    $display->panels['_______________________'][0] = 'new-bbcf6b58-b52c-44aa-8837-d1682e4a8460';
    $pane = new stdClass();
    $pane->pid = 'new-affc66d2-b9d7-4c8e-b5bb-dee733f4c1b0';
    $pane->panel = '_______________________';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = 'affc66d2-b9d7-4c8e-b5bb-dee733f4c1b0';
    $display->content['new-affc66d2-b9d7-4c8e-b5bb-dee733f4c1b0'] = $pane;
    $display->panels['_______________________'][1] = 'new-affc66d2-b9d7-4c8e-b5bb-dee733f4c1b0';
    $pane = new stdClass();
    $pane->pid = 'new-0520eca6-e46a-4131-9ad8-a155d8104881';
    $pane->panel = '_______________________';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0520eca6-e46a-4131-9ad8-a155d8104881';
    $display->content['new-0520eca6-e46a-4131-9ad8-a155d8104881'] = $pane;
    $display->panels['_______________________'][2] = 'new-0520eca6-e46a-4131-9ad8-a155d8104881';
    $pane = new stdClass();
    $pane->pid = 'new-cf44e57c-23d4-4c76-a5bb-34b73c97b6e9';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'cf44e57c-23d4-4c76-a5bb-34b73c97b6e9';
    $display->content['new-cf44e57c-23d4-4c76-a5bb-34b73c97b6e9'] = $pane;
    $display->panels['_______________________'][3] = 'new-cf44e57c-23d4-4c76-a5bb-34b73c97b6e9';
    $pane = new stdClass();
    $pane->pid = 'new-ad094a07-77db-4270-a0e6-701f9cee0432';
    $pane->panel = '_______________________';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = 'ad094a07-77db-4270-a0e6-701f9cee0432';
    $display->content['new-ad094a07-77db-4270-a0e6-701f9cee0432'] = $pane;
    $display->panels['_______________________'][4] = 'new-ad094a07-77db-4270-a0e6-701f9cee0432';
    $pane = new stdClass();
    $pane->pid = 'new-cf0c7dcc-34e2-4338-817e-f7a3707eeb68';
    $pane->panel = '_____________________________________';
    $pane->type = 'block';
    $pane->subtype = 'od_rubric_menu-block_rubric_menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'cf0c7dcc-34e2-4338-817e-f7a3707eeb68';
    $display->content['new-cf0c7dcc-34e2-4338-817e-f7a3707eeb68'] = $pane;
    $display->panels['_____________________________________'][0] = 'new-cf0c7dcc-34e2-4338-817e-f7a3707eeb68';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_8'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context_9';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Custom page (Page manager)',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'library',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
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
          0 => 4,
          1 => 1,
          2 => 3,
          3 => 8,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => '_______________________',
        ),
        'parent' => 'main',
        'class' => 'breadcrumbs',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'region_main_content',
        ),
        'parent' => 'main',
        'class' => 'region-content',
      ),
      '_______________________' => array(
        'type' => 'region',
        'title' => 'Breadcrumbs',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'breadcrumbs',
        'hide_empty' => 0,
      ),
      'region_main_content' => array(
        'type' => 'region',
        'title' => 'Main content',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      4 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 5,
        ),
        'parent' => 'main',
        'class' => 'region-header',
      ),
      5 => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'parent' => '4',
        'children' => array(
          0 => 6,
          1 => 7,
        ),
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_front',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_front' => array(
        'type' => 'region',
        'title' => 'Header front top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => 'header-front-top',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'header_bottom',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'header_bottom' => array(
        'type' => 'region',
        'title' => 'Header front bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => 'region-header-facts',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'footer',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'footer' => array(
        'type' => 'region',
        'title' => 'Footer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => 'footer-region',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'branding' => NULL,
      'header' => NULL,
      'navigation' => NULL,
      'highlighted' => NULL,
      'help' => NULL,
      'content' => NULL,
      'sidebar_first' => NULL,
      'sidebar_second' => NULL,
      'footer' => NULL,
      'main' => NULL,
      '_______________________' => NULL,
      '_____________________________________' => NULL,
      '________________________________________________' => NULL,
      'region_main_content' => NULL,
      'header_front' => NULL,
      'header_bottom' => NULL,
    ),
    'header_bottom' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fd0c4f57-b5b2-4247-9393-b1b6b5491360';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-82531b01-5424-419e-8e9a-12c238220b2d';
    $pane->panel = 'footer';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '© 2014 Russian Ministry of Economic Development',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '82531b01-5424-419e-8e9a-12c238220b2d';
    $display->content['new-82531b01-5424-419e-8e9a-12c238220b2d'] = $pane;
    $display->panels['footer'][0] = 'new-82531b01-5424-419e-8e9a-12c238220b2d';
    $pane = new stdClass();
    $pane->pid = 'new-90695bb4-9e6e-4033-af88-251bcddb492a';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'locale-language';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '90695bb4-9e6e-4033-af88-251bcddb492a';
    $display->content['new-90695bb4-9e6e-4033-af88-251bcddb492a'] = $pane;
    $display->panels['header_front'][0] = 'new-90695bb4-9e6e-4033-af88-251bcddb492a';
    $pane = new stdClass();
    $pane->pid = 'new-d953c430-f7b7-4776-93de-88af9de16a62';
    $pane->panel = 'header_front';
    $pane->type = 'pane_header';
    $pane->subtype = 'pane_header';
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
    $pane->uuid = 'd953c430-f7b7-4776-93de-88af9de16a62';
    $display->content['new-d953c430-f7b7-4776-93de-88af9de16a62'] = $pane;
    $display->panels['header_front'][1] = 'new-d953c430-f7b7-4776-93de-88af9de16a62';
    $pane = new stdClass();
    $pane->pid = 'new-4381bcdc-b5f0-421f-b983-7648096ea712';
    $pane->panel = 'header_front';
    $pane->type = 'panels_mini';
    $pane->subtype = 'search_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4381bcdc-b5f0-421f-b983-7648096ea712';
    $display->content['new-4381bcdc-b5f0-421f-b983-7648096ea712'] = $pane;
    $display->panels['header_front'][2] = 'new-4381bcdc-b5f0-421f-b983-7648096ea712';
    $pane = new stdClass();
    $pane->pid = 'new-b6c6f765-28e3-4eaf-b641-c4e365b447fa';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'superfish-1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-system-main-menu',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b6c6f765-28e3-4eaf-b641-c4e365b447fa';
    $display->content['new-b6c6f765-28e3-4eaf-b641-c4e365b447fa'] = $pane;
    $display->panels['header_front'][3] = 'new-b6c6f765-28e3-4eaf-b641-c4e365b447fa';
    $pane = new stdClass();
    $pane->pid = 'new-1881f1fd-a422-4b2d-9736-f1b3ce1612d2';
    $pane->panel = 'header_front';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
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
    $pane->uuid = '1881f1fd-a422-4b2d-9736-f1b3ce1612d2';
    $display->content['new-1881f1fd-a422-4b2d-9736-f1b3ce1612d2'] = $pane;
    $display->panels['header_front'][4] = 'new-1881f1fd-a422-4b2d-9736-f1b3ce1612d2';
    $pane = new stdClass();
    $pane->pid = 'new-9fc601cf-4aa8-4580-b3be-9d17aa931cd6';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = '9fc601cf-4aa8-4580-b3be-9d17aa931cd6';
    $display->content['new-9fc601cf-4aa8-4580-b3be-9d17aa931cd6'] = $pane;
    $display->panels['region_main_content'][0] = 'new-9fc601cf-4aa8-4580-b3be-9d17aa931cd6';
    $pane = new stdClass();
    $pane->pid = 'new-9311c186-4960-4b64-a740-f566c54643ff';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
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
    $pane->uuid = '9311c186-4960-4b64-a740-f566c54643ff';
    $display->content['new-9311c186-4960-4b64-a740-f566c54643ff'] = $pane;
    $display->panels['region_main_content'][1] = 'new-9311c186-4960-4b64-a740-f566c54643ff';
    $pane = new stdClass();
    $pane->pid = 'new-046bce2d-55ed-4d5d-825c-07a499a4025d';
    $pane->panel = 'region_main_content';
    $pane->type = 'panels_mini';
    $pane->subtype = 'custom_block';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '046bce2d-55ed-4d5d-825c-07a499a4025d';
    $display->content['new-046bce2d-55ed-4d5d-825c-07a499a4025d'] = $pane;
    $display->panels['region_main_content'][2] = 'new-046bce2d-55ed-4d5d-825c-07a499a4025d';
    $pane = new stdClass();
    $pane->pid = 'new-d8a47048-e9ae-4a43-b6fc-0f525ce54791';
    $pane->panel = 'region_main_content';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
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
    $pane->uuid = 'd8a47048-e9ae-4a43-b6fc-0f525ce54791';
    $display->content['new-d8a47048-e9ae-4a43-b6fc-0f525ce54791'] = $pane;
    $display->panels['region_main_content'][3] = 'new-d8a47048-e9ae-4a43-b6fc-0f525ce54791';
    $pane = new stdClass();
    $pane->pid = 'new-bac420fb-5238-4bca-b372-3b7719d2d28b';
    $pane->panel = '_______________________';
    $pane->type = 'page_breadcrumb';
    $pane->subtype = 'page_breadcrumb';
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
    $pane->uuid = 'bac420fb-5238-4bca-b372-3b7719d2d28b';
    $display->content['new-bac420fb-5238-4bca-b372-3b7719d2d28b'] = $pane;
    $display->panels['_______________________'][0] = 'new-bac420fb-5238-4bca-b372-3b7719d2d28b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context_9'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Рубрики',
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
          'name' => 'entity_bundle:taxonomy_term',
          'settings' => array(
            'type' => array(
              'rubrics' => 'rubrics',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
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
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'rubric_menu',
          1 => 'content',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'rubric_menu' => array(
        'type' => 'region',
        'title' => 'Rubric menu',
        'width' => '16.64760815704212',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'menu-rubric',
      ),
      'content' => array(
        'type' => 'region',
        'title' => 'Content',
        'width' => '83.35239184295789',
        'width_type' => '%',
        'parent' => '1',
        'class' => 'main-content',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'rubric_menu' => NULL,
      'content' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cdf1f22e-93d8-4cbb-a75a-7b7e1f92ffa6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cf609bc7-6b6a-47f8-8490-e4255e647df8';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'rubric_nodes-rubric_content';
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
    $pane->uuid = 'cf609bc7-6b6a-47f8-8490-e4255e647df8';
    $display->content['new-cf609bc7-6b6a-47f8-8490-e4255e647df8'] = $pane;
    $display->panels['middle'][0] = 'new-cf609bc7-6b6a-47f8-8490-e4255e647df8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_edit_panel_context';
  $handler->task = 'user_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Редактирование профиля',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
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
  $display->title = 'Edit profile';
  $display->uuid = 'a8d6a6ca-940e-4789-bd14-bfcd947b2227';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f8b83f60-d526-47f4-adaa-1824b8fb70e0';
    $pane->panel = 'center';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
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
    $pane->uuid = 'f8b83f60-d526-47f4-adaa-1824b8fb70e0';
    $display->content['new-f8b83f60-d526-47f4-adaa-1824b8fb70e0'] = $pane;
    $display->panels['center'][0] = 'new-f8b83f60-d526-47f4-adaa-1824b8fb70e0';
    $pane = new stdClass();
    $pane->pid = 'new-24d6704b-801e-4ca4-8ee5-e3dc739ae8f7';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Меню для редактирования',
      'title' => '',
      'body' => '<?php 
global $language;
$uid = arg(1);
$prefix = $language->language;
$view_profile = t(\'View profile\');
$edit_profile = t(\'Edit profile\');
print <<<END
<div class="panel-pane pane-block pane-menu-menu-for-profile">
  <ul class="menu">
    <li class="menu__item is-leaf first leaf"><a href="/$prefix/user/$uid" title="" class="menu__link">$view_profile</a></li>
    <li class="menu__item is-leaf leaf"><a href="/$prefix/user/$uid/edit" title="" class="menu__link active">$edit_profile</a></li>
  </ul>
</div>
END;
?>',
      'format' => 'ds_code',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '24d6704b-801e-4ca4-8ee5-e3dc739ae8f7';
    $display->content['new-24d6704b-801e-4ca4-8ee5-e3dc739ae8f7'] = $pane;
    $display->panels['center'][1] = 'new-24d6704b-801e-4ca4-8ee5-e3dc739ae8f7';
    $pane = new stdClass();
    $pane->pid = 'new-63df8c97-eea0-4ea1-97ee-3bf7b894138b';
    $pane->panel = 'center';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_user_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '63df8c97-eea0-4ea1-97ee-3bf7b894138b';
    $display->content['new-63df8c97-eea0-4ea1-97ee-3bf7b894138b'] = $pane;
    $display->panels['center'][2] = 'new-63df8c97-eea0-4ea1-97ee-3bf7b894138b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_edit_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_login_panel_context';
  $handler->task = 'user_login';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Login page',
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
  $display->title = 'Log in';
  $display->uuid = 'c68125f0-7d20-46b4-93d4-abceeb9a67ac';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-01de8397-7cb5-4b32-a5c2-c02a0dcbe31c';
    $pane->panel = 'middle';
    $pane->type = 'user_login_form';
    $pane->subtype = 'user_login_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '01de8397-7cb5-4b32-a5c2-c02a0dcbe31c';
    $display->content['new-01de8397-7cb5-4b32-a5c2-c02a0dcbe31c'] = $pane;
    $display->panels['middle'][0] = 'new-01de8397-7cb5-4b32-a5c2-c02a0dcbe31c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-01de8397-7cb5-4b32-a5c2-c02a0dcbe31c';
  $handler->conf['display'] = $display;
  $export['user_login_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_password_panel_context';
  $handler->task = 'user_password';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Reset password',
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
  $display->title = 'Forgotten Password Recovery';
  $display->uuid = 'a6223f05-d466-4be7-9f78-113409934720';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d4891ce4-fb31-47bf-8c54-20320b744665';
    $pane->panel = 'middle';
    $pane->type = 'user_password_form';
    $pane->subtype = 'user_password_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'd4891ce4-fb31-47bf-8c54-20320b744665';
    $display->content['new-d4891ce4-fb31-47bf-8c54-20320b744665'] = $pane;
    $display->panels['middle'][0] = 'new-d4891ce4-fb31-47bf-8c54-20320b744665';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-d4891ce4-fb31-47bf-8c54-20320b744665';
  $handler->conf['display'] = $display;
  $export['user_password_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_register_panel_context';
  $handler->task = 'user_register';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Register page',
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
  $display->title = 'Registration';
  $display->uuid = '161edf8d-f09d-4306-9be7-e4030b7fffb3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b882efac-df2e-4a4d-9de6-1a941371faef';
    $pane->panel = 'main';
    $pane->type = 'user_register_form';
    $pane->subtype = 'user_register_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'b882efac-df2e-4a4d-9de6-1a941371faef';
    $display->content['new-b882efac-df2e-4a4d-9de6-1a941371faef'] = $pane;
    $display->panels['main'][0] = 'new-b882efac-df2e-4a4d-9de6-1a941371faef';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b882efac-df2e-4a4d-9de6-1a941371faef';
  $handler->conf['display'] = $display;
  $export['user_register_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Профиль пользователя',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_7',
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
          0 => 'main-row',
          1 => 1,
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
        'class' => '',
        'hide_empty' => 1,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Центр',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
        'hide_empty' => 1,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'masquerade_block',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'masquerade_block' => array(
        'type' => 'region',
        'title' => 'Masquerade block',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => array(
        'panel_tab_id_pattern' => 'region',
        'panel_tab_save_active_tab' => 1,
      ),
      'masquerade_block' => NULL,
    ),
    'center' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '67a1c64e-502c-4711-9427-9dc97262d467';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-99a2ded5-ce50-4a56-a556-bc06da0e1e41';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'last_view_pages-list_last_views_materials';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'argument_entity_id:user_1',
            1 => 'logged-in-user',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Recent views',
      'context' => array(
        0 => 'argument_entity_id:user_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '99a2ded5-ce50-4a56-a556-bc06da0e1e41';
    $display->content['new-99a2ded5-ce50-4a56-a556-bc06da0e1e41'] = $pane;
    $display->panels['center'][0] = 'new-99a2ded5-ce50-4a56-a556-bc06da0e1e41';
    $pane = new stdClass();
    $pane->pid = 'new-fe22c8f5-416f-4c16-b627-cfd531d31cd2';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'blog_user-list_blogs_user';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'argument_entity_id:user_1',
            1 => 'logged-in-user',
          ),
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:user_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'Blog',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fe22c8f5-416f-4c16-b627-cfd531d31cd2';
    $display->content['new-fe22c8f5-416f-4c16-b627-cfd531d31cd2'] = $pane;
    $display->panels['center'][1] = 'new-fe22c8f5-416f-4c16-b627-cfd531d31cd2';
    $pane = new stdClass();
    $pane->pid = 'new-bd5d4986-5c3b-4173-ac60-1b470d4b1d69';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-activity_datasets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Last added datasets',
      'context' => array(
        0 => 'argument_entity_id:user_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bd5d4986-5c3b-4173-ac60-1b470d4b1d69';
    $display->content['new-bd5d4986-5c3b-4173-ac60-1b470d4b1d69'] = $pane;
    $display->panels['center'][2] = 'new-bd5d4986-5c3b-4173-ac60-1b470d4b1d69';
    $pane = new stdClass();
    $pane->pid = 'new-713dfedb-3b78-42df-84f1-076df95a9e12';
    $pane->panel = 'masquerade_block';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
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
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Крутой джедайский код',
      'title' => '',
      'body' => '<?php 
if ($account = user_load(\'%user:uid\'))  {
  if (isset($_SESSION[\'masquerading\'])) {
    print render(masquerade_block_1()); //kal
  }
  else {
    masquerade_user_view($account, \'full\', \'en\');
    print isset($account->content) ? render($account->content) : \'\';
  }
}
?>',
      'format' => 'ds_code',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '713dfedb-3b78-42df-84f1-076df95a9e12';
    $display->content['new-713dfedb-3b78-42df-84f1-076df95a9e12'] = $pane;
    $display->panels['masquerade_block'][0] = 'new-713dfedb-3b78-42df-84f1-076df95a9e12';
    $pane = new stdClass();
    $pane->pid = 'new-c9669656-3512-49c1-a0bc-0b3767376e09';
    $pane->panel = 'masquerade_block';
    $pane->type = 'block';
    $pane->subtype = 'masquerade-masquerade';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'c9669656-3512-49c1-a0bc-0b3767376e09';
    $display->content['new-c9669656-3512-49c1-a0bc-0b3767376e09'] = $pane;
    $display->panels['masquerade_block'][1] = 'new-c9669656-3512-49c1-a0bc-0b3767376e09';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function nodes_breadcrumbs_pm_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about';
  $page->task = 'page';
  $page->admin_title = 'О портале';
  $page->admin_description = '';
  $page->path = 'about';
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
  $handler->name = 'page_about_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'about';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'О портале',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Материал',
        'keyword' => 'node',
        'name' => 'entity:node',
        'entity_id' => '615',
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
  $display->title = 'About';
  $display->uuid = '4048d72f-6a81-46d9-8ad5-1758d8ba6381';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f629c8af-1e01-434b-a45c-a262a7cfb880';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'context_entity:node_1',
      'override_title' => 0,
      'override_title_text' => 'About portal',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f629c8af-1e01-434b-a45c-a262a7cfb880';
    $display->content['new-f629c8af-1e01-434b-a45c-a262a7cfb880'] = $pane;
    $display->panels['main'][0] = 'new-f629c8af-1e01-434b-a45c-a262a7cfb880';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f629c8af-1e01-434b-a45c-a262a7cfb880';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'activity_user';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Активность пользователя';
  $page->admin_description = '';
  $page->path = 'user/%user/activity';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Активность',
    'name' => 'navigation',
    'weight' => '20',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_activity_user_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'activity_user';
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
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_7',
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => array(
        'panel_tab_id_pattern' => 'region',
        'panel_tab_save_active_tab' => 1,
      ),
    ),
    'middle' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'af7030bf-7828-400a-9dc9-0772722e3e20';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9e78a5df-67bc-4f82-8727-72bdaa0534a1';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'last_view_pages-list_last_views_materials';
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
    $pane->uuid = '9e78a5df-67bc-4f82-8727-72bdaa0534a1';
    $display->content['new-9e78a5df-67bc-4f82-8727-72bdaa0534a1'] = $pane;
    $display->panels['middle'][0] = 'new-9e78a5df-67bc-4f82-8727-72bdaa0534a1';
    $pane = new stdClass();
    $pane->pid = 'new-493d7ed3-a1f9-455c-8a43-628ea9332fe3';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'blog_user-list_blogs_user';
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
    $pane->uuid = '493d7ed3-a1f9-455c-8a43-628ea9332fe3';
    $display->content['new-493d7ed3-a1f9-455c-8a43-628ea9332fe3'] = $pane;
    $display->panels['middle'][1] = 'new-493d7ed3-a1f9-455c-8a43-628ea9332fe3';
    $pane = new stdClass();
    $pane->pid = 'new-2a10b959-dad8-4e63-8bcb-c0817696ed58';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-activity_datasets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Последние добавленные наборы',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2a10b959-dad8-4e63-8bcb-c0817696ed58';
    $display->content['new-2a10b959-dad8-4e63-8bcb-c0817696ed58'] = $pane;
    $display->panels['middle'][2] = 'new-2a10b959-dad8-4e63-8bcb-c0817696ed58';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-2a10b959-dad8-4e63-8bcb-c0817696ed58';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['activity_user'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'actualize_dataset';
  $page->task = 'page';
  $page->admin_title = 'Актуализация однотомного набора данных';
  $page->admin_description = '';
  $page->path = 'actualize-dataset';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_actualize_dataset_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'actualize_dataset';
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
}',
    'contexts' => array(
      0 => array(
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '10',
        'id' => 1,
      ),
    ),
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
  $display->title = 'Actualize dataset';
  $display->uuid = '434e986a-43c0-4c8e-bd17-6858e8c226aa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1527a959-b668-43c9-8896-2f4be713381e';
    $pane->panel = 'middle';
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
    $pane->uuid = '1527a959-b668-43c9-8896-2f4be713381e';
    $display->content['new-1527a959-b668-43c9-8896-2f4be713381e'] = $pane;
    $display->panels['middle'][0] = 'new-1527a959-b668-43c9-8896-2f4be713381e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['actualize_dataset'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'actualize_dataset_mv';
  $page->task = 'page';
  $page->admin_title = 'Актуализация многотомного набора данных';
  $page->admin_description = '';
  $page->path = 'actualize-dataset-mv';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_actualize_dataset_mv_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'actualize_dataset_mv';
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
}',
    'contexts' => array(
      0 => array(
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '14',
        'id' => 1,
      ),
    ),
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
  $display->title = 'Actualize dataset';
  $display->uuid = '434e986a-43c0-4c8e-bd17-6858e8c226aa';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1527a959-b668-43c9-8896-2f4be713381e';
    $pane->panel = 'middle';
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
    $pane->uuid = '1527a959-b668-43c9-8896-2f4be713381e';
    $display->content['new-1527a959-b668-43c9-8896-2f4be713381e'] = $pane;
    $display->panels['middle'][0] = 'new-1527a959-b668-43c9-8896-2f4be713381e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['actualize_dataset_mv'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_app';
  $page->task = 'page';
  $page->admin_title = 'Добавление приложения';
  $page->admin_description = '';
  $page->path = 'add_app';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_add_app_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'add_app';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Добавление приложения',
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '5',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
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
  $display->title = 'Add application';
  $display->uuid = '7ade3347-923b-474c-a3d5-39dc199beb68';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3785abaf-0794-4855-a1ac-b23bb7f0cfcd';
    $pane->panel = 'middle';
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
    $pane->uuid = '3785abaf-0794-4855-a1ac-b23bb7f0cfcd';
    $display->content['new-3785abaf-0794-4855-a1ac-b23bb7f0cfcd'] = $pane;
    $display->panels['middle'][0] = 'new-3785abaf-0794-4855-a1ac-b23bb7f0cfcd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_app'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_idea';
  $page->task = 'page';
  $page->admin_title = 'Создание идеи для анонимов';
  $page->admin_description = '';
  $page->path = 'add-idea';
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
  $handler->name = 'page_add_idea_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'add_idea';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Создание идеи',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => 'div.entity-entityform-type h2 {
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
        'entity_id' => '15',
        'id' => 1,
      ),
    ),
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
  $display->title = 'Add idea';
  $display->uuid = '90184649-0c4e-4aca-991e-cf493872467e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-dbb44462-7522-474a-8160-c145b29885e3';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'entityform_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'context_entity:entityform_type_1',
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
    $pane->uuid = 'dbb44462-7522-474a-8160-c145b29885e3';
    $display->content['new-dbb44462-7522-474a-8160-c145b29885e3'] = $pane;
    $display->panels['middle'][0] = 'new-dbb44462-7522-474a-8160-c145b29885e3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_idea'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_material';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Создание материала';
  $page->admin_description = '';
  $page->path = 'user/%user/add-material';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 3,
            2 => 4,
            3 => 5,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Создание материала',
    'name' => 'navigation',
    'weight' => '15',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_add_material_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'add_material';
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
        'entity_id' => '4',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_7',
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
  $display->title = '';
  $display->uuid = '5bb961eb-d42d-4384-b997-3feef2b227fd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-539b7f77-3708-46a6-acd6-57c04599a6d1';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Удалить после наполнения страницы',
      'title' => '',
      'body' => 'Тут будет форма создания нового материала. Уточнить какого именно.',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '539b7f77-3708-46a6-acd6-57c04599a6d1';
    $display->content['new-539b7f77-3708-46a6-acd6-57c04599a6d1'] = $pane;
    $display->panels['middle'][0] = 'new-539b7f77-3708-46a6-acd6-57c04599a6d1';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_material'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'add_new_dataset';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Создание материала, пункт - Набор данных';
  $page->admin_description = '';
  $page->path = 'dataset-actions/add-new-dataset';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Создание материала',
    'name' => 'navigation',
    'weight' => '15',
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
  $handler->name = 'page_add_new_dataset_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'add_new_dataset';
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
        'entity_id' => '4',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
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
  $display->title = '';
  $display->uuid = '975d0db8-da17-4d01-b376-a6690dc81b00';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-42fdaecc-3b62-4252-9777-aa6e47a33b6c';
    $pane->panel = 'middle';
    $pane->type = 'pane_messages';
    $pane->subtype = 'pane_messages';
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
    $pane->uuid = '42fdaecc-3b62-4252-9777-aa6e47a33b6c';
    $display->content['new-42fdaecc-3b62-4252-9777-aa6e47a33b6c'] = $pane;
    $display->panels['middle'][0] = 'new-42fdaecc-3b62-4252-9777-aa6e47a33b6c';
    $pane = new stdClass();
    $pane->pid = 'new-956db6c3-ce5a-482e-914e-86d224d6a940';
    $pane->panel = 'middle';
    $pane->type = 'entity_view';
    $pane->subtype = 'entityform_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'context_entity:entityform_type_1',
      'override_title' => 0,
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
    $pane->uuid = '956db6c3-ce5a-482e-914e-86d224d6a940';
    $display->content['new-956db6c3-ce5a-482e-914e-86d224d6a940'] = $pane;
    $display->panels['middle'][1] = 'new-956db6c3-ce5a-482e-914e-86d224d6a940';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['add_new_dataset'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'all_datasets_map';
  $page->task = 'page';
  $page->admin_title = 'Карта открытых данных';
  $page->admin_description = '';
  $page->path = 'datasets-map';
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
  $handler->name = 'page_all_datasets_map_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'all_datasets_map';
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
    'contexts' => array(),
    'relationships' => array(),
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
  $display->title = 'Карта';
  $display->uuid = '19343bf5-8592-4612-9adb-634a088f275b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-32ea7eb0-0917-46dd-82a3-4750e94020f8';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div class="custom-text-wrapper">
На карте отображаются метки организаций, наборы открытых данных которых представлены на Портале. В настоящий момент Портал наполняется, и количество меток будет увеличиваться с ростом количества организаций, опубликовавших свои наборы открытых данных.
</div>',
      'format' => 'ds_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '32ea7eb0-0917-46dd-82a3-4750e94020f8';
    $display->content['new-32ea7eb0-0917-46dd-82a3-4750e94020f8'] = $pane;
    $display->panels['main'][0] = 'new-32ea7eb0-0917-46dd-82a3-4750e94020f8';
    $pane = new stdClass();
    $pane->pid = 'new-943cb2c9-f7ef-438d-8388-bb0881ad5c70';
    $pane->panel = 'main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Переключатель типов (джедайский код)',
      'title' => '',
      'body' => '<?php
if (od_common_module(\'od_map_page\')) {
  print render(od_common_module_od_map_page_render_selector());
}

?>',
      'format' => 'ds_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '943cb2c9-f7ef-438d-8388-bb0881ad5c70';
    $display->content['new-943cb2c9-f7ef-438d-8388-bb0881ad5c70'] = $pane;
    $display->panels['main'][1] = 'new-943cb2c9-f7ef-438d-8388-bb0881ad5c70';
    $pane = new stdClass();
    $pane->pid = 'new-5dd6e00a-5060-4898-8d35-9a83ec81ce36';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'datasets_map-google_map';
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
    $pane->uuid = '5dd6e00a-5060-4898-8d35-9a83ec81ce36';
    $display->content['new-5dd6e00a-5060-4898-8d35-9a83ec81ce36'] = $pane;
    $display->panels['main'][2] = 'new-5dd6e00a-5060-4898-8d35-9a83ec81ce36';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['all_datasets_map'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apps';
  $page->task = 'page';
  $page->admin_title = 'Приложения';
  $page->admin_description = '';
  $page->path = 'apps';
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
  $handler->name = 'page_apps_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'apps';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Страница приложения',
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
          0 => 3,
        ),
        'parent' => 'canvas',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 4,
          1 => 5,
        ),
        'parent' => 'main',
        'class' => '',
      ),
      4 => array(
        'type' => 'column',
        'width' => '13.595344306004204',
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 6,
        ),
        'class' => 'left-column',
      ),
      5 => array(
        'type' => 'column',
        'width' => '86.40465569399579',
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 9,
          1 => 8,
          2 => 7,
        ),
        'class' => 'right-column',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'facets',
        ),
        'parent' => '4',
        'class' => '',
      ),
      'facets' => array(
        'type' => 'region',
        'title' => 'Facets',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => 'facets-region',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'bottom',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'bottom' => array(
        'type' => 'region',
        'title' => 'Bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => 'right-bottom-region',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'middle_left',
          1 => 'middle_right',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'middle_left' => array(
        'type' => 'region',
        'title' => 'New apps',
        'width' => '50.15212364609955',
        'width_type' => '%',
        'parent' => '8',
        'class' => 'midle-left-region new-apps',
        'hide_empty' => 0,
      ),
      'middle_right' => array(
        'type' => 'region',
        'title' => 'Popular apps',
        'width' => '49.84787635390045',
        'width_type' => '%',
        'parent' => '8',
        'class' => 'middle-right-region popular-apps',
        'hide_empty' => 0,
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'search',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'search' => array(
        'type' => 'region',
        'title' => 'Search',
        'width' => 100,
        'width_type' => '%',
        'parent' => '9',
        'class' => 'middle-search-region',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'left_region' => NULL,
      'right_region' => NULL,
      'buttons' => NULL,
      'facets' => NULL,
      'bottom' => NULL,
      'middle_left' => NULL,
      'middle_right' => NULL,
      'search' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Applications';
  $display->uuid = '69cd47ca-43a2-4970-82a2-3cefc0a9ac6c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-90c086d5-be7c-4b0a-92d7-d07c4dabfc14';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'apps_search_api-apps';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '90c086d5-be7c-4b0a-92d7-d07c4dabfc14';
    $display->content['new-90c086d5-be7c-4b0a-92d7-d07c4dabfc14'] = $pane;
    $display->panels['bottom'][0] = 'new-90c086d5-be7c-4b0a-92d7-d07c4dabfc14';
    $pane = new stdClass();
    $pane->pid = 'new-5cd18854-8119-4f70-ad33-34e45649c116';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-VGwRjQ9yo7CvvyJDxeEm3Pq1KG6knSEs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Topic',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5cd18854-8119-4f70-ad33-34e45649c116';
    $display->content['new-5cd18854-8119-4f70-ad33-34e45649c116'] = $pane;
    $display->panels['facets'][0] = 'new-5cd18854-8119-4f70-ad33-34e45649c116';
    $pane = new stdClass();
    $pane->pid = 'new-d2411d12-46a5-4889-a733-13907c01f151';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-HGYoGBnEsLiRm8mrAsh1t5BfzWxuzIgd';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Keyword',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd2411d12-46a5-4889-a733-13907c01f151';
    $display->content['new-d2411d12-46a5-4889-a733-13907c01f151'] = $pane;
    $display->panels['facets'][1] = 'new-d2411d12-46a5-4889-a733-13907c01f151';
    $pane = new stdClass();
    $pane->pid = 'new-b1f3fd5a-633b-4c23-87f0-3d942782685a';
    $pane->panel = 'middle_left';
    $pane->type = 'views_panes';
    $pane->subtype = 'apps-10_latests_apps';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'New apps',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b1f3fd5a-633b-4c23-87f0-3d942782685a';
    $display->content['new-b1f3fd5a-633b-4c23-87f0-3d942782685a'] = $pane;
    $display->panels['middle_left'][0] = 'new-b1f3fd5a-633b-4c23-87f0-3d942782685a';
    $pane = new stdClass();
    $pane->pid = 'new-0e8fa05c-b2f3-4657-8aee-1e67d25ac279';
    $pane->panel = 'middle_right';
    $pane->type = 'views_panes';
    $pane->subtype = 'apps-top_rated_apps';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Popular apps',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0e8fa05c-b2f3-4657-8aee-1e67d25ac279';
    $display->content['new-0e8fa05c-b2f3-4657-8aee-1e67d25ac279'] = $pane;
    $display->panels['middle_right'][0] = 'new-0e8fa05c-b2f3-4657-8aee-1e67d25ac279';
    $pane = new stdClass();
    $pane->pid = 'new-c2a6fee4-788b-4983-bb80-360efb21a0bb';
    $pane->panel = 'search';
    $pane->type = 'block';
    $pane->subtype = 'views--exp-apps_search_api-apps';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
    $pane->uuid = 'c2a6fee4-788b-4983-bb80-360efb21a0bb';
    $display->content['new-c2a6fee4-788b-4983-bb80-360efb21a0bb'] = $pane;
    $display->panels['search'][0] = 'new-c2a6fee4-788b-4983-bb80-360efb21a0bb';
    $pane = new stdClass();
    $pane->pid = 'new-87ab77c1-8af3-4fc8-8f5e-55f759830e29';
    $pane->panel = 'search';
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
      'admin_title' => 'Ссылка на добавление приложения (для анонимных пользователей)',
      'title' => '',
      'body' => '<a href="/user/login?destination=add_app">Авторизируйтесь перед добавлением приложения</a>',
      'format' => 'html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '87ab77c1-8af3-4fc8-8f5e-55f759830e29';
    $display->content['new-87ab77c1-8af3-4fc8-8f5e-55f759830e29'] = $pane;
    $display->panels['search'][1] = 'new-87ab77c1-8af3-4fc8-8f5e-55f759830e29';
    $pane = new stdClass();
    $pane->pid = 'new-c09fafb7-815a-4c7d-a638-a18dbbdefaff';
    $pane->panel = 'search';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 2,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Ссылка на добавление приложения (для зарегистрированных пользователей)',
      'title' => '',
      'body' => '<a href="/add_app" class="btn">Добавить приложение</a>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-btn',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c09fafb7-815a-4c7d-a638-a18dbbdefaff';
    $display->content['new-c09fafb7-815a-4c7d-a638-a18dbbdefaff'] = $pane;
    $display->panels['search'][2] = 'new-c09fafb7-815a-4c7d-a638-a18dbbdefaff';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apps'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'askopendata';
  $page->task = 'page';
  $page->admin_title = 'Запрос на данные';
  $page->admin_description = '';
  $page->path = 'askopendata';
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
  $handler->name = 'page_askopendata_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'askopendata';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Запрос на данные',
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
    'contexts' => array(
      0 => array(
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '1',
        'id' => 1,
      ),
    ),
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
  $display->title = 'Request to open data';
  $display->uuid = '48b110bd-a35d-4941-99c4-c9f52da306f2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f11e840a-c5cc-4323-b593-d0a6d209276d';
    $pane->panel = 'middle';
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
    $pane->uuid = 'f11e840a-c5cc-4323-b593-d0a6d209276d';
    $display->content['new-f11e840a-c5cc-4323-b593-d0a6d209276d'] = $pane;
    $display->panels['middle'][0] = 'new-f11e840a-c5cc-4323-b593-d0a6d209276d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['askopendata'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'become_publisher';
  $page->task = 'page';
  $page->admin_title = 'Заявка на публикаторство';
  $page->admin_description = '';
  $page->path = 'become-a-publisher';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => TRUE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_become_publisher_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'become_publisher';
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
}',
    'contexts' => array(
      0 => array(
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '13',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'access' => array(
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
  $display->title = 'Publisher application';
  $display->uuid = '6875c858-b143-4ca0-ab22-91d64fcb2004';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b59b999f-e51c-4b65-beff-e983e7cea700';
    $pane->panel = 'middle';
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
    $pane->uuid = 'b59b999f-e51c-4b65-beff-e983e7cea700';
    $display->content['new-b59b999f-e51c-4b65-beff-e983e7cea700'] = $pane;
    $display->panels['middle'][0] = 'new-b59b999f-e51c-4b65-beff-e983e7cea700';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['become_publisher'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'blog_for_rubric';
  $page->task = 'page';
  $page->admin_title = 'Blog for rubric';
  $page->admin_description = '';
  $page->path = 'taxonomy/term/%taxonomy_term/blogs';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'taxonomy_term' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          1 => 0,
          4 => 0,
          2 => 0,
          3 => 0,
          5 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_blog_for_rubric_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'blog_for_rubric';
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
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
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
  $display->title = 'Блог для рубрики %taxonomy_term:name';
  $display->uuid = '60d832f0-5a94-48da-b298-24362e2627e4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-97d653cd-55bf-4421-ad6a-8504e960d740';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'blogs-blogs_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'field_rubric_tid' => '%taxonomy_term:tid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '97d653cd-55bf-4421-ad6a-8504e960d740';
    $display->content['new-97d653cd-55bf-4421-ad6a-8504e960d740'] = $pane;
    $display->panels['main'][0] = 'new-97d653cd-55bf-4421-ad6a-8504e960d740';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['blog_for_rubric'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'code_passport';
  $page->task = 'page';
  $page->admin_title = 'Код паспорта';
  $page->admin_description = '';
  $page->path = 'node/%node/code-passport';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'dataset' => 'dataset',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
      'name' => 'entity_id:node',
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
  $handler->name = 'page_code_passport_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'code_passport';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Код паспорта',
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
              'dataset' => 'dataset',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
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
  $display->title = '';
  $display->uuid = 'b0b70b68-e1af-4c20-baec-7199bed2f1da';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9bcbaed2-df51-4bcb-aaa6-532c03e58fa4';
    $pane->panel = 'main';
    $pane->type = 'od_passport_html_pane';
    $pane->subtype = 'od_passport_html_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '9bcbaed2-df51-4bcb-aaa6-532c03e58fa4';
    $display->content['new-9bcbaed2-df51-4bcb-aaa6-532c03e58fa4'] = $pane;
    $display->panels['main'][0] = 'new-9bcbaed2-df51-4bcb-aaa6-532c03e58fa4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-9bcbaed2-df51-4bcb-aaa6-532c03e58fa4';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['code_passport'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'competitions';
  $page->task = 'page';
  $page->admin_title = 'Конкурсы';
  $page->admin_description = '';
  $page->path = 'competitions';
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
  $handler->name = 'page_competitions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'competitions';
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
  $display->title = 'Competitions';
  $display->uuid = '3e93fc06-c440-46e2-b6d9-c71317c6ef39';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-89f18697-0882-4a8a-b5c7-e2b12217a1b5';
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
              0 => 6,
              1 => 3,
              2 => 4,
              3 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Ссылка на добавление конкурса',
      'title' => '',
      'body' => '<div class="view-organizations"><div class="pane-btn"><a class="btn" href="/node/add/competition?destination=competitions"><?php print t(\'Add competition\');?></a></div></div>',
      'format' => 'ds_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'link-add',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '89f18697-0882-4a8a-b5c7-e2b12217a1b5';
    $display->content['new-89f18697-0882-4a8a-b5c7-e2b12217a1b5'] = $pane;
    $display->panels['middle'][0] = 'new-89f18697-0882-4a8a-b5c7-e2b12217a1b5';
    $pane = new stdClass();
    $pane->pid = 'new-cc19e4bc-26bd-481f-a1cf-5da7845a1f61';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'competitions_for_rubrics-competitions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'cc19e4bc-26bd-481f-a1cf-5da7845a1f61';
    $display->content['new-cc19e4bc-26bd-481f-a1cf-5da7845a1f61'] = $pane;
    $display->panels['middle'][1] = 'new-cc19e4bc-26bd-481f-a1cf-5da7845a1f61';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-cc19e4bc-26bd-481f-a1cf-5da7845a1f61';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['competitions'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'datasets';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Наборы данных';
  $page->admin_description = '';
  $page->path = 'user/%user/datasets';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 5,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
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
  $handler->name = 'page_datasets_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'datasets';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Наборы данных',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_7',
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
  $display->title = 'Datasets';
  $display->uuid = '2d3a68be-0d21-42f5-901b-23a2fae76c99';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d461ef2e-06c9-47f0-b549-3877a9185013';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-datasets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_entity_id:user_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd461ef2e-06c9-47f0-b549-3877a9185013';
    $display->content['new-d461ef2e-06c9-47f0-b549-3877a9185013'] = $pane;
    $display->panels['middle'][0] = 'new-d461ef2e-06c9-47f0-b549-3877a9185013';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['datasets'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'datasets_map';
  $page->task = 'page';
  $page->admin_title = 'Карта открытых данных';
  $page->admin_description = '';
  $page->path = 'taxonomy/term/%taxonomy_term/map';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'taxonomy_term' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          1 => 0,
          4 => 0,
          2 => 0,
          5 => 0,
        ),
        'breadcrumb' => 0,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_datasets_map_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'datasets_map';
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
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
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
  $display->title = '';
  $display->uuid = 'a83a463c-c1bd-410a-abc7-0db490e7936d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0d977b92-fd3d-403a-bf48-cb0b59143ea2';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'datasets_map-rubric_map';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0d977b92-fd3d-403a-bf48-cb0b59143ea2';
    $display->content['new-0d977b92-fd3d-403a-bf48-cb0b59143ea2'] = $pane;
    $display->panels['main'][0] = 'new-0d977b92-fd3d-403a-bf48-cb0b59143ea2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['datasets_map'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'datasets_search';
  $page->task = 'page';
  $page->admin_title = 'Поиск по наборам';
  $page->admin_description = '';
  $page->path = 'dataset';
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
  $handler->name = 'page_datasets_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'datasets_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Datasets Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'dataset',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'Поиск по наборам/Context',
        'keyword' => 'view',
        'name' => 'view:datasets_search-datasets_context',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
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
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'facets',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Центр',
        'width' => '25.0641495584679',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-facet',
      ),
      'facets' => array(
        'type' => 'region',
        'title' => 'Facets',
        'width' => '74.93585044153211',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'dataset-search-facets',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'facets' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Search datasets';
  $display->uuid = 'dbc1551a-7b42-4a91-a691-e0e065364dda';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-05cb27eb-5480-40f8-b4fe-a6399873bfe1';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-yW6mJ3GaJF0LypnLPa433Bf9GI8QdWd9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Format',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '05cb27eb-5480-40f8-b4fe-a6399873bfe1';
    $display->content['new-05cb27eb-5480-40f8-b4fe-a6399873bfe1'] = $pane;
    $display->panels['center'][0] = 'new-05cb27eb-5480-40f8-b4fe-a6399873bfe1';
    $pane = new stdClass();
    $pane->pid = 'new-f4b22130-2551-44fd-a6a1-799af6747fad';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-iqym2Kd38Mx18a15U2HvhA1fbXztUS1o';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Topic',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f4b22130-2551-44fd-a6a1-799af6747fad';
    $display->content['new-f4b22130-2551-44fd-a6a1-799af6747fad'] = $pane;
    $display->panels['center'][1] = 'new-f4b22130-2551-44fd-a6a1-799af6747fad';
    $pane = new stdClass();
    $pane->pid = 'new-a47d2452-c66a-436e-8ae3-cbe36fac4b3a';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-dqCRnp6cKP1cSzAsNB6zqFtY9AVEa0mp';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Keyword',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'a47d2452-c66a-436e-8ae3-cbe36fac4b3a';
    $display->content['new-a47d2452-c66a-436e-8ae3-cbe36fac4b3a'] = $pane;
    $display->panels['center'][2] = 'new-a47d2452-c66a-436e-8ae3-cbe36fac4b3a';
    $pane = new stdClass();
    $pane->pid = 'new-4a089675-f040-4ac2-a9b2-9c7dcafd9b05';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-LT1CHHuJCKRVwclq3E04uVF8hXeMPA1X';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Popularity',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4a089675-f040-4ac2-a9b2-9c7dcafd9b05';
    $display->content['new-4a089675-f040-4ac2-a9b2-9c7dcafd9b05'] = $pane;
    $display->panels['center'][3] = 'new-4a089675-f040-4ac2-a9b2-9c7dcafd9b05';
    $pane = new stdClass();
    $pane->pid = 'new-efab1748-9bc2-4256-a2de-c6e8dab08847';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-HE6muwnBOpuaBbTCC6rMplz09UV0Ej1g';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Organization type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'efab1748-9bc2-4256-a2de-c6e8dab08847';
    $display->content['new-efab1748-9bc2-4256-a2de-c6e8dab08847'] = $pane;
    $display->panels['center'][4] = 'new-efab1748-9bc2-4256-a2de-c6e8dab08847';
    $pane = new stdClass();
    $pane->pid = 'new-5df73e42-c82d-4901-992c-b33c6c812db7';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Q0yeq2X95W7NRL6UUC9zrVVLNw5FrK4y';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Organization',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '5df73e42-c82d-4901-992c-b33c6c812db7';
    $display->content['new-5df73e42-c82d-4901-992c-b33c6c812db7'] = $pane;
    $display->panels['center'][5] = 'new-5df73e42-c82d-4901-992c-b33c6c812db7';
    $pane = new stdClass();
    $pane->pid = 'new-36e1b383-97fd-4886-806a-5f4660242be0';
    $pane->panel = 'facets';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Экспорт реестра наборов',
      'title' => '<none>',
      'body' => '<div class="export-registry-wrapper">
  <h2> <?php print t(\'Export registry\'); ?> </h2>
<div class="export-registry">
  <?php
    print t(\'<a href="@url" class="csv">CSV</a>\', array(\'@url\' => url(\'export-csv\')));
    print t(\'<a href="@url" class="xls">XLS</a>\', array(\'@url\' => url(\'export-xls\')));
   ?>
</div>
</div>',
      'format' => 'ds_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'dataset-export',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '36e1b383-97fd-4886-806a-5f4660242be0';
    $display->content['new-36e1b383-97fd-4886-806a-5f4660242be0'] = $pane;
    $display->panels['facets'][0] = 'new-36e1b383-97fd-4886-806a-5f4660242be0';
    $pane = new stdClass();
    $pane->pid = 'new-a82af0f4-0274-4d84-adef-9597b232306e';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $pane->uuid = 'a82af0f4-0274-4d84-adef-9597b232306e';
    $display->content['new-a82af0f4-0274-4d84-adef-9597b232306e'] = $pane;
    $display->panels['facets'][1] = 'new-a82af0f4-0274-4d84-adef-9597b232306e';
    $pane = new stdClass();
    $pane->pid = 'new-442876b0-7c95-4ea2-a19e-87e163765580';
    $pane->panel = 'facets';
    $pane->type = 'views';
    $pane->subtype = 'dataset';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '5',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'standard_datasets',
      'override_title' => 1,
      'override_title_text' => 'Recommended datasets',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '442876b0-7c95-4ea2-a19e-87e163765580';
    $display->content['new-442876b0-7c95-4ea2-a19e-87e163765580'] = $pane;
    $display->panels['facets'][2] = 'new-442876b0-7c95-4ea2-a19e-87e163765580';
    $pane = new stdClass();
    $pane->pid = 'new-17adc011-4df8-4cb5-8dab-5e2e47a075b9';
    $pane->panel = 'facets';
    $pane->type = 'views_panes';
    $pane->subtype = 'datasets_search-dataset_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '17adc011-4df8-4cb5-8dab-5e2e47a075b9';
    $display->content['new-17adc011-4df8-4cb5-8dab-5e2e47a075b9'] = $pane;
    $display->panels['facets'][3] = 'new-17adc011-4df8-4cb5-8dab-5e2e47a075b9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['datasets_search'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'developer_library';
  $page->task = 'page';
  $page->admin_title = 'Библиотека разработчиков';
  $page->admin_description = '';
  $page->path = 'library-developers';
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
  $handler->name = 'page_developer_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'developer_library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'page-library',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
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
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'facets',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Центр',
        'width' => '80.7477288609364',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'dataset-search-facets',
        'hide_empty' => 0,
      ),
      'facets' => array(
        'type' => 'region',
        'title' => 'Facets',
        'width' => '19.252271139063595',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-facet',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => NULL,
      'facets' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Documents regulating the work with open data';
  $display->uuid = '6afaf5c3-cca9-4803-96c8-3055316cb52c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ec160717-97c1-4cce-986d-246f8e2aec58';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = 'ec160717-97c1-4cce-986d-246f8e2aec58';
    $display->content['new-ec160717-97c1-4cce-986d-246f8e2aec58'] = $pane;
    $display->panels['center'][0] = 'new-ec160717-97c1-4cce-986d-246f8e2aec58';
    $pane = new stdClass();
    $pane->pid = 'new-d8acb088-fe3d-4c1a-94d2-45ee65d0f93e';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'documents_search-document_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-datasets-search-dataset-search',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd8acb088-fe3d-4c1a-94d2-45ee65d0f93e';
    $display->content['new-d8acb088-fe3d-4c1a-94d2-45ee65d0f93e'] = $pane;
    $display->panels['center'][1] = 'new-d8acb088-fe3d-4c1a-94d2-45ee65d0f93e';
    $pane = new stdClass();
    $pane->pid = 'new-7675fb5c-bb10-46fe-8287-21b03edae265';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-hr6DjBRN3CSVW1xFrjnkTZSHOIcZ3hu0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7675fb5c-bb10-46fe-8287-21b03edae265';
    $display->content['new-7675fb5c-bb10-46fe-8287-21b03edae265'] = $pane;
    $display->panels['facets'][0] = 'new-7675fb5c-bb10-46fe-8287-21b03edae265';
    $pane = new stdClass();
    $pane->pid = 'new-54efd9b4-576e-494e-82f7-f41b095e509c';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-epHbEzIKUrnHwmcq6rIz0ktNO3yCeHCD';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Keyword',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '54efd9b4-576e-494e-82f7-f41b095e509c';
    $display->content['new-54efd9b4-576e-494e-82f7-f41b095e509c'] = $pane;
    $display->panels['facets'][1] = 'new-54efd9b4-576e-494e-82f7-f41b095e509c';
    $pane = new stdClass();
    $pane->pid = 'new-39d2b202-ad1e-4ee1-97dd-f538c4f0facb';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-a1eVmbH1sklZfWBPtHGJyKZjLAGRvaGE';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Topic',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '39d2b202-ad1e-4ee1-97dd-f538c4f0facb';
    $display->content['new-39d2b202-ad1e-4ee1-97dd-f538c4f0facb'] = $pane;
    $display->panels['facets'][2] = 'new-39d2b202-ad1e-4ee1-97dd-f538c4f0facb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['developer_library'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'edit_profile';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Редактирование пользователя';
  $page->admin_description = '';
  $page->path = 'user/%user/edit-profile';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Мои идеи',
    'name' => 'navigation',
    'weight' => '5',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_edit_profile_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'edit_profile';
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
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
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
  $display->title = '';
  $display->uuid = '3c3c22b6-9c65-4010-a32a-17efbd06e0bf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-34fd81a4-ace5-4bb2-b6a9-b813143070e6';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'удалить потом',
      'title' => '',
      'body' => 'тут будет редактирование профиля',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '34fd81a4-ace5-4bb2-b6a9-b813143070e6';
    $display->content['new-34fd81a4-ace5-4bb2-b6a9-b813143070e6'] = $pane;
    $display->panels['middle'][0] = 'new-34fd81a4-ace5-4bb2-b6a9-b813143070e6';
    $pane = new stdClass();
    $pane->pid = 'new-30d2888a-c03e-40c9-9982-d0f35223412b';
    $pane->panel = 'middle';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'user:field_user_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
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
    $pane->uuid = '30d2888a-c03e-40c9-9982-d0f35223412b';
    $display->content['new-30d2888a-c03e-40c9-9982-d0f35223412b'] = $pane;
    $display->panels['middle'][1] = 'new-30d2888a-c03e-40c9-9982-d0f35223412b';
    $pane = new stdClass();
    $pane->pid = 'new-b395373c-d359-402e-8165-c8139d44afd4';
    $pane->panel = 'middle';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'user:field_user_last_name';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_entity_id:user_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b395373c-d359-402e-8165-c8139d44afd4';
    $display->content['new-b395373c-d359-402e-8165-c8139d44afd4'] = $pane;
    $display->panels['middle'][2] = 'new-b395373c-d359-402e-8165-c8139d44afd4';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['edit_profile'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'feedback';
  $page->task = 'page';
  $page->admin_title = 'Обратная связь';
  $page->admin_description = '';
  $page->path = 'feedback';
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
  $handler->name = 'page_feedback_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'feedback';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Обратная связь',
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
        'entity_id' => '8',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_everywhere_site_template' => '',
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
  $display->title = 'Feedback';
  $display->uuid = '30281f09-cd16-4244-9d2e-618a137a4534';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e1975613-20b3-44d7-a055-9aab9e86cd0d';
    $pane->panel = 'middle';
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
    $pane->uuid = 'e1975613-20b3-44d7-a055-9aab9e86cd0d';
    $display->content['new-e1975613-20b3-44d7-a055-9aab9e86cd0d'] = $pane;
    $display->panels['middle'][0] = 'new-e1975613-20b3-44d7-a055-9aab9e86cd0d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['feedback'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'file_coverting_service';
  $page->task = 'page';
  $page->admin_title = 'Конвертация в машиночитаемые форматы';
  $page->admin_description = '';
  $page->path = 'file-coverting-service';
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
  $handler->name = 'page_file_coverting_service_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'file_coverting_service';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.entity-entityform-type h2 {display: none}',
    'contexts' => array(
      0 => array(
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '12',
        'id' => 1,
      ),
    ),
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
  $display->title = 'File converting service';
  $display->uuid = 'a816b6b9-7cb0-4584-9266-740b4c33d9ea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3ee27086-17fd-47a2-9f78-60537fe08cac';
    $pane->panel = 'middle';
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
    $pane->uuid = '3ee27086-17fd-47a2-9f78-60537fe08cac';
    $display->content['new-3ee27086-17fd-47a2-9f78-60537fe08cac'] = $pane;
    $display->panels['middle'][0] = 'new-3ee27086-17fd-47a2-9f78-60537fe08cac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['file_coverting_service'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front_page';
  $page->task = 'page';
  $page->admin_title = 'Главная страница';
  $page->admin_description = '';
  $page->path = 'frontpage';
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
  $handler->name = 'page_front_page_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Главная страница',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context',
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
          0 => 'main-row',
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
        'title' => 'Центр',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'front-rubrics',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0fa18e23-79e8-40ce-a1d8-c3ca1e97e2fc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f36c9276-2ed9-4d48-b14a-1daf4ff9ea47';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'rubrics-rubrics_front';
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
    $pane->uuid = 'f36c9276-2ed9-4d48-b14a-1daf4ff9ea47';
    $display->content['new-f36c9276-2ed9-4d48-b14a-1daf4ff9ea47'] = $pane;
    $display->panels['center'][0] = 'new-f36c9276-2ed9-4d48-b14a-1daf4ff9ea47';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ideas';
  $page->task = 'page';
  $page->admin_title = 'Идеи';
  $page->admin_description = '';
  $page->path = 'ideas';
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
  $handler->name = 'page_ideas_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ideas';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Идеи',
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
  $display->title = 'Ideas';
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
            'perm' => 'create idea content',
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
print t(\'<div class="view-organizations"><div class="pane-btn"><a class="btn" href="@url">Add idea</a></div></div>\', array(\'@url\' => url(\'node/add/idea\')));
?>',
      'format' => 'ds_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
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
print t(\'<div class="view-organizations"><div class="pane-btn"><a class="btn" href="@url">Add idea</a></div></div>\', array(\'@url\' => url(\'add-idea\')));
?>',
      'format' => 'ds_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '217f3300-2a00-4bba-82ca-06ec1f0b50b5';
    $display->content['new-217f3300-2a00-4bba-82ca-06ec1f0b50b5'] = $pane;
    $display->panels['middle'][1] = 'new-217f3300-2a00-4bba-82ca-06ec1f0b50b5';
    $pane = new stdClass();
    $pane->pid = 'new-7f658de5-1856-40c7-84b0-831adb42e5ea';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ideas-ideas_list';
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
    $pane->uuid = '7f658de5-1856-40c7-84b0-831adb42e5ea';
    $display->content['new-7f658de5-1856-40c7-84b0-831adb42e5ea'] = $pane;
    $display->panels['middle'][2] = 'new-7f658de5-1856-40c7-84b0-831adb42e5ea';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7f658de5-1856-40c7-84b0-831adb42e5ea';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ideas'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ideas_moderation';
  $page->task = 'page';
  $page->admin_title = 'Идеи для модератора';
  $page->admin_description = '';
  $page->path = 'admin/content/ideas';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Идеи',
    'name' => 'management',
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
  $handler->name = 'page_ideas_moderation_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ideas_moderation';
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
    'contexts' => array(),
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
  $display->title = '';
  $display->uuid = '31815c4b-5224-43b1-b5e8-a629830d7bce';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8d8bfb37-cc92-49bc-a18b-f398bca83dd0';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ideas-panel_pane_1';
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
    $pane->uuid = '8d8bfb37-cc92-49bc-a18b-f398bca83dd0';
    $display->content['new-8d8bfb37-cc92-49bc-a18b-f398bca83dd0'] = $pane;
    $display->panels['middle'][0] = 'new-8d8bfb37-cc92-49bc-a18b-f398bca83dd0';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-8d8bfb37-cc92-49bc-a18b-f398bca83dd0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ideas_moderation'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'info_for_developers';
  $page->task = 'page';
  $page->admin_title = 'Информация для разработчика';
  $page->admin_description = '';
  $page->path = 'node/1864';
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
  $handler->name = 'page_info_for_developers_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'info_for_developers';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Информация для разработчиков',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_5',
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
  $display->title = 'Developer resources';
  $display->uuid = 'b81b2092-770a-4d93-981c-68b3627de884';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fb63d424-a2b2-4e6b-88fb-077091431f34';
    $pane->panel = 'main';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '%1',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
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
    $pane->uuid = 'fb63d424-a2b2-4e6b-88fb-077091431f34';
    $display->content['new-fb63d424-a2b2-4e6b-88fb-077091431f34'] = $pane;
    $display->panels['main'][0] = 'new-fb63d424-a2b2-4e6b-88fb-077091431f34';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['info_for_developers'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'library';
  $page->task = 'page';
  $page->admin_title = 'Библиотека';
  $page->admin_description = '';
  $page->path = 'library';
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
  $handler->name = 'page_library_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'library';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Библиотека',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'page-library',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
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
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'facets',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Центр',
        'width' => '79.92186011053936',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'dataset-search-facets',
      ),
      'facets' => array(
        'type' => 'region',
        'title' => 'Facets',
        'width' => '20.078139889460644',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-facet',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'facets' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Documents regulating the work with open data';
  $display->uuid = '82a3ef94-8f8e-433c-8ba5-6bf993b1c310';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-093967e1-8843-4c56-b03a-7166de62bee8';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '093967e1-8843-4c56-b03a-7166de62bee8';
    $display->content['new-093967e1-8843-4c56-b03a-7166de62bee8'] = $pane;
    $display->panels['center'][0] = 'new-093967e1-8843-4c56-b03a-7166de62bee8';
    $pane = new stdClass();
    $pane->pid = 'new-d1679b34-7bcc-415d-bf4d-09be7bf2a74b';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'documents_search-document_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-datasets-search-dataset-search',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'd1679b34-7bcc-415d-bf4d-09be7bf2a74b';
    $display->content['new-d1679b34-7bcc-415d-bf4d-09be7bf2a74b'] = $pane;
    $display->panels['center'][1] = 'new-d1679b34-7bcc-415d-bf4d-09be7bf2a74b';
    $pane = new stdClass();
    $pane->pid = 'new-c52d204a-e19e-4507-8f21-3d04bd318957';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-hr6DjBRN3CSVW1xFrjnkTZSHOIcZ3hu0';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c52d204a-e19e-4507-8f21-3d04bd318957';
    $display->content['new-c52d204a-e19e-4507-8f21-3d04bd318957'] = $pane;
    $display->panels['facets'][0] = 'new-c52d204a-e19e-4507-8f21-3d04bd318957';
    $pane = new stdClass();
    $pane->pid = 'new-f2511d9e-1b39-4a9b-91c6-99c05c167d58';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-a1eVmbH1sklZfWBPtHGJyKZjLAGRvaGE';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Topic',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f2511d9e-1b39-4a9b-91c6-99c05c167d58';
    $display->content['new-f2511d9e-1b39-4a9b-91c6-99c05c167d58'] = $pane;
    $display->panels['facets'][1] = 'new-f2511d9e-1b39-4a9b-91c6-99c05c167d58';
    $pane = new stdClass();
    $pane->pid = 'new-4b522a8d-3f87-468d-ae3e-84be12bce861';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-epHbEzIKUrnHwmcq6rIz0ktNO3yCeHCD';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Keyword',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '4b522a8d-3f87-468d-ae3e-84be12bce861';
    $display->content['new-4b522a8d-3f87-468d-ae3e-84be12bce861'] = $pane;
    $display->panels['facets'][2] = 'new-4b522a8d-3f87-468d-ae3e-84be12bce861';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['library'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'moderation';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Модерация';
  $page->admin_description = '';
  $page->path = 'user/%user/moderation';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 4,
            1 => 5,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Активность',
    'name' => 'navigation',
    'weight' => '20',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'Пользователь: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
      'keyword' => 'user',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_moderation_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'moderation';
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
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
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
        'class' => 'moderation-tabs',
        'hide_empty' => 0,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Центр',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'top_region',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'top_region' => array(
        'type' => 'region',
        'title' => 'top region',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => 'pane-btn-grey',
        'hide_empty' => 0,
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => array(
        'panel_tab_id_pattern' => 'region',
      ),
      'top_region' => NULL,
    ),
    'center' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = 'Moderation';
  $display->uuid = '46f52b97-c5c4-414b-b729-900ff237d596';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-74ea7ba8-a6b5-43a4-ba3c-af8263b84fd3';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'moderation_users-moderation_list_users';
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
    $pane->uuid = '74ea7ba8-a6b5-43a4-ba3c-af8263b84fd3';
    $display->content['new-74ea7ba8-a6b5-43a4-ba3c-af8263b84fd3'] = $pane;
    $display->panels['center'][0] = 'new-74ea7ba8-a6b5-43a4-ba3c-af8263b84fd3';
    $pane = new stdClass();
    $pane->pid = 'new-5f7719b1-604e-4a3e-881f-5de01e0a502e';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'comments-comments';
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
    $pane->uuid = '5f7719b1-604e-4a3e-881f-5de01e0a502e';
    $display->content['new-5f7719b1-604e-4a3e-881f-5de01e0a502e'] = $pane;
    $display->panels['center'][1] = 'new-5f7719b1-604e-4a3e-881f-5de01e0a502e';
    $pane = new stdClass();
    $pane->pid = 'new-905d0056-6453-42a0-874b-0cc22e35b818';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'moderation_comments-moderation_list_comments';
    $pane->shown = FALSE;
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
    $pane->uuid = '905d0056-6453-42a0-874b-0cc22e35b818';
    $display->content['new-905d0056-6453-42a0-874b-0cc22e35b818'] = $pane;
    $display->panels['center'][2] = 'new-905d0056-6453-42a0-874b-0cc22e35b818';
    $pane = new stdClass();
    $pane->pid = 'new-91e92518-68bb-4181-b6db-3cf1ac505c85';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'moderation_ideas-moderation_ideas';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '91e92518-68bb-4181-b6db-3cf1ac505c85';
    $display->content['new-91e92518-68bb-4181-b6db-3cf1ac505c85'] = $pane;
    $display->panels['center'][3] = 'new-91e92518-68bb-4181-b6db-3cf1ac505c85';
    $pane = new stdClass();
    $pane->pid = 'new-0809504a-a5c9-48f0-9d78-ebe693d5c589';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'competitions_for_rubrics-competitions_for_moderation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Конкурсы',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '0809504a-a5c9-48f0-9d78-ebe693d5c589';
    $display->content['new-0809504a-a5c9-48f0-9d78-ebe693d5c589'] = $pane;
    $display->panels['center'][4] = 'new-0809504a-a5c9-48f0-9d78-ebe693d5c589';
    $pane = new stdClass();
    $pane->pid = 'new-31027937-686c-41d5-9a7c-76d8ae40f7a0';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'moderation_ideas-moderation_quick_facts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '31027937-686c-41d5-9a7c-76d8ae40f7a0';
    $display->content['new-31027937-686c-41d5-9a7c-76d8ae40f7a0'] = $pane;
    $display->panels['center'][5] = 'new-31027937-686c-41d5-9a7c-76d8ae40f7a0';
    $pane = new stdClass();
    $pane->pid = 'new-7a6a07c6-85aa-479d-b532-b6e6514b25b8';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'moderation_ideas-moderation_app';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Приложения',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '7a6a07c6-85aa-479d-b532-b6e6514b25b8';
    $display->content['new-7a6a07c6-85aa-479d-b532-b6e6514b25b8'] = $pane;
    $display->panels['center'][6] = 'new-7a6a07c6-85aa-479d-b532-b6e6514b25b8';
    $pane = new stdClass();
    $pane->pid = 'new-9e282321-8fd9-468b-b7d3-3e14e22eaa3f';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'moderation_opendata_query-moderation_query';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '9e282321-8fd9-468b-b7d3-3e14e22eaa3f';
    $display->content['new-9e282321-8fd9-468b-b7d3-3e14e22eaa3f'] = $pane;
    $display->panels['center'][7] = 'new-9e282321-8fd9-468b-b7d3-3e14e22eaa3f';
    $pane = new stdClass();
    $pane->pid = 'new-5b20a7a5-afab-478a-b7a4-71a821ebe2ca';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'moderation_opendata_query-dataset_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Обращения',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '5b20a7a5-afab-478a-b7a4-71a821ebe2ca';
    $display->content['new-5b20a7a5-afab-478a-b7a4-71a821ebe2ca'] = $pane;
    $display->panels['center'][8] = 'new-5b20a7a5-afab-478a-b7a4-71a821ebe2ca';
    $pane = new stdClass();
    $pane->pid = 'new-be49be5b-70c9-492f-a48a-5c10a264f36c';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'moderate_publisher_requests-moderate_publisher_requests';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'be49be5b-70c9-492f-a48a-5c10a264f36c';
    $display->content['new-be49be5b-70c9-492f-a48a-5c10a264f36c'] = $pane;
    $display->panels['center'][9] = 'new-be49be5b-70c9-492f-a48a-5c10a264f36c';
    $pane = new stdClass();
    $pane->pid = 'new-847ff646-6488-4f0d-91d8-8a46abdd3074';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'entityform_submissions-feedback_submissions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Обратная связь',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = '847ff646-6488-4f0d-91d8-8a46abdd3074';
    $display->content['new-847ff646-6488-4f0d-91d8-8a46abdd3074'] = $pane;
    $display->panels['center'][10] = 'new-847ff646-6488-4f0d-91d8-8a46abdd3074';
    $pane = new stdClass();
    $pane->pid = 'new-859eae61-9951-4b73-860a-9bb00fba40d0';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'rubrics-rubricks_moderation';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Рубрики',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 11;
    $pane->locks = array();
    $pane->uuid = '859eae61-9951-4b73-860a-9bb00fba40d0';
    $display->content['new-859eae61-9951-4b73-860a-9bb00fba40d0'] = $pane;
    $display->panels['center'][11] = 'new-859eae61-9951-4b73-860a-9bb00fba40d0';
    $pane = new stdClass();
    $pane->pid = 'new-22a41f31-25c8-454d-8136-35830edba8e0';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'dataset-recommended_datasets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Наборы данных',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 12;
    $pane->locks = array();
    $pane->uuid = '22a41f31-25c8-454d-8136-35830edba8e0';
    $display->content['new-22a41f31-25c8-454d-8136-35830edba8e0'] = $pane;
    $display->panels['center'][12] = 'new-22a41f31-25c8-454d-8136-35830edba8e0';
    $pane = new stdClass();
    $pane->pid = 'new-7c6c90f5-7a10-46e6-92bd-1a3e5e4934f1';
    $pane->panel = 'top_region';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Ссылка - Добавить Организацию',
      'title' => '',
      'body' => '<a class="btn" href="/node/add/organization">Добавить Организацию</a>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7c6c90f5-7a10-46e6-92bd-1a3e5e4934f1';
    $display->content['new-7c6c90f5-7a10-46e6-92bd-1a3e5e4934f1'] = $pane;
    $display->panels['top_region'][0] = 'new-7c6c90f5-7a10-46e6-92bd-1a3e5e4934f1';
    $pane = new stdClass();
    $pane->pid = 'new-e1d2fcc3-54f3-4f41-8500-55f770bf7006';
    $pane->panel = 'top_region';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Ссылка - Запуск робота мониторинга',
      'title' => '',
      'body' => '<a class="btn" href="/opendata-import">Запуск робота мониторинга</a>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e1d2fcc3-54f3-4f41-8500-55f770bf7006';
    $display->content['new-e1d2fcc3-54f3-4f41-8500-55f770bf7006'] = $pane;
    $display->panels['top_region'][1] = 'new-e1d2fcc3-54f3-4f41-8500-55f770bf7006';
    $pane = new stdClass();
    $pane->pid = 'new-488b46d5-f14c-49b3-b00f-beec85e3ea30';
    $pane->panel = 'top_region';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Ссылка - Журнал робота мониторинга',
      'title' => '',
      'body' => '<a class="btn" href="/ru/opendata-log">Журнал робота мониторинга</a>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '488b46d5-f14c-49b3-b00f-beec85e3ea30';
    $display->content['new-488b46d5-f14c-49b3-b00f-beec85e3ea30'] = $pane;
    $display->panels['top_region'][2] = 'new-488b46d5-f14c-49b3-b00f-beec85e3ea30';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-488b46d5-f14c-49b3-b00f-beec85e3ea30';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['moderation'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'moderation_add_organization';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Модерация, создание Организации';
  $page->admin_description = '';
  $page->path = 'user/%user/add-organization';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 4,
            1 => 5,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Создание материала',
    'name' => 'navigation',
    'weight' => '15',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_moderation_add_organization_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'moderation_add_organization';
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
        'identifier' => 'Форма добавления материала',
        'keyword' => 'node_add',
        'name' => 'node_add_form',
        'type' => 'organization',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
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
  $display->title = '';
  $display->uuid = '920acf9f-04af-463b-beee-a31a82fada54';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a559c675-7b03-4a45-9a11-f340f0b0bcdf';
    $pane->panel = 'middle';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_node_add_form_1',
      'override_title' => 1,
      'override_title_text' => 'Добавить Организацию',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a559c675-7b03-4a45-9a11-f340f0b0bcdf';
    $display->content['new-a559c675-7b03-4a45-9a11-f340f0b0bcdf'] = $pane;
    $display->panels['middle'][0] = 'new-a559c675-7b03-4a45-9a11-f340f0b0bcdf';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['moderation_add_organization'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'new_dataset';
  $page->task = 'page';
  $page->admin_title = 'Добавление набора данных';
  $page->admin_description = '';
  $page->path = 'new-dataset';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 6,
            1 => 5,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_new_dataset_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'new_dataset';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Панель',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '.entity-entityform-type h2 {display: none};',
    'contexts' => array(
      0 => array(
        'identifier' => 'Entityform Type',
        'keyword' => 'entityform_type',
        'name' => 'entity:entityform_type',
        'entity_id' => '4',
        'id' => 1,
      ),
    ),
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
  $display->title = 'Add dataset';
  $display->uuid = '5d2dccfe-0aae-4b81-8534-bd9e24b59bea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c8f9f860-6506-4d20-b1bc-9ccbb1183e0e';
    $pane->panel = 'middle';
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
    $pane->uuid = 'c8f9f860-6506-4d20-b1bc-9ccbb1183e0e';
    $display->content['new-c8f9f860-6506-4d20-b1bc-9ccbb1183e0e'] = $pane;
    $display->panels['middle'][0] = 'new-c8f9f860-6506-4d20-b1bc-9ccbb1183e0e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['new_dataset'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news';
  $page->task = 'page';
  $page->admin_title = 'Новости';
  $page->admin_description = '';
  $page->path = 'taxonomy/term/%taxonomy_term/news';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'taxonomy_term' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          1 => 0,
          4 => 0,
          2 => 0,
          3 => 0,
          5 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_news_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'news';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Список новостей',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Список новостей';
  $display->uuid = '79c51e07-b70d-4a36-b325-f8b4f31ab7cb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-15e4e06f-26c9-403f-87e0-600aa82ed455';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'news-news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_term_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '15e4e06f-26c9-403f-87e0-600aa82ed455';
    $display->content['new-15e4e06f-26c9-403f-87e0-600aa82ed455'] = $pane;
    $display->panels['middle'][0] = 'new-15e4e06f-26c9-403f-87e0-600aa82ed455';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'next_resource';
  $page->task = 'page';
  $page->admin_title = 'Следующий ресурс';
  $page->admin_description = '';
  $page->path = 'node/%node/next';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'resource' => 'resource',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'rb_misc_conditions:rules_access_rule_dataset_is_multivolume',
        'settings' => array(
          'component_name' => 'rules_access_rule_dataset_is_multivolume',
        ),
        'context' => array(
          0 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Next volume',
    'name' => 'navigation',
    'weight' => '10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
      'name' => 'entity_id:node',
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
  $handler->name = 'page_next_resource_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'next_resource';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Следующий ресурс',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Материал from Материал (on Материал: Dataset [field_dataset_ref])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_dataset_ref-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
    'rb_misc_trigger' => 1,
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
  $display->title = '';
  $display->uuid = '0f18eda3-b0b1-4210-a3cb-3a8162486cea';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['next_resource'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'organizations';
  $page->task = 'page';
  $page->admin_title = 'Организации';
  $page->admin_description = '';
  $page->path = 'organizations';
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
  $handler->name = 'page_organizations_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'organizations';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Организации',
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
  $display->title = 'Organizations';
  $display->uuid = 'e10b7097-9d4d-4282-aade-f2cf389426bf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-54d38d22-fcf5-4d07-ab0f-7af1a7e9fc0c';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'organizations-organizations_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '54d38d22-fcf5-4d07-ab0f-7af1a7e9fc0c';
    $display->content['new-54d38d22-fcf5-4d07-ab0f-7af1a7e9fc0c'] = $pane;
    $display->panels['middle'][0] = 'new-54d38d22-fcf5-4d07-ab0f-7af1a7e9fc0c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-54d38d22-fcf5-4d07-ab0f-7af1a7e9fc0c';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['organizations'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'piwik_statictics';
  $page->task = 'page';
  $page->admin_title = 'Piwik statictics';
  $page->admin_description = '';
  $page->path = 'site-usage';
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
  $handler->name = 'page_piwik_statictics_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'piwik_statictics';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Страница статистики',
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
        'class' => 'stat-tabs',
        'hide_empty' => 0,
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Центр',
        'width' => 100,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'moderation-tabs',
        'hide_empty' => 0,
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'date_filter',
        ),
        'parent' => 'main',
        'class' => 'stat-filters',
        'hide_empty' => 0,
      ),
      'date_filter' => array(
        'type' => 'region',
        'title' => 'Date filter',
        'width' => 100,
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'center' => array(
        'panel_tab_id_pattern' => 'region',
        'panel_tab_save_active_tab' => 1,
      ),
      'date_filter' => NULL,
    ),
    'center' => array(
      'style' => 'tabs',
    ),
  );
  $display->cache = array();
  $display->title = 'Site usage statistics';
  $display->uuid = '8e6e3d7e-9827-48bc-96db-5f1ae70f5305';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f686e6cf-3292-4d0c-9689-837e0f666dfa';
    $pane->panel = 'center';
    $pane->type = 'panels_mini';
    $pane->subtype = 'overall_statistics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'General statistics',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f686e6cf-3292-4d0c-9689-837e0f666dfa';
    $display->content['new-f686e6cf-3292-4d0c-9689-837e0f666dfa'] = $pane;
    $display->panels['center'][0] = 'new-f686e6cf-3292-4d0c-9689-837e0f666dfa';
    $pane = new stdClass();
    $pane->pid = 'new-8618d7e2-8e34-454e-8b58-75bc0a09f8a8';
    $pane->panel = 'center';
    $pane->type = 'piwik_report_iframe';
    $pane->subtype = 'piwik_report_iframe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report' => 'getConfiguration',
      'override_title' => 1,
      'override_title_text' => 'Browsers',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '8618d7e2-8e34-454e-8b58-75bc0a09f8a8';
    $display->content['new-8618d7e2-8e34-454e-8b58-75bc0a09f8a8'] = $pane;
    $display->panels['center'][1] = 'new-8618d7e2-8e34-454e-8b58-75bc0a09f8a8';
    $pane = new stdClass();
    $pane->pid = 'new-8f2ac76a-0493-4684-8396-08093a1d08a1';
    $pane->panel = 'center';
    $pane->type = 'piwik_report_iframe';
    $pane->subtype = 'piwik_report_iframe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report' => 'getOS',
      'override_title' => 1,
      'override_title_text' => 'OS',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8f2ac76a-0493-4684-8396-08093a1d08a1';
    $display->content['new-8f2ac76a-0493-4684-8396-08093a1d08a1'] = $pane;
    $display->panels['center'][2] = 'new-8f2ac76a-0493-4684-8396-08093a1d08a1';
    $pane = new stdClass();
    $pane->pid = 'new-ff9c912d-4861-4fe3-8e00-96c819c51ca9';
    $pane->panel = 'center';
    $pane->type = 'piwik_report_iframe';
    $pane->subtype = 'piwik_report_iframe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report' => 'visitors_locations',
      'override_title' => 1,
      'override_title_text' => 'Countries',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ff9c912d-4861-4fe3-8e00-96c819c51ca9';
    $display->content['new-ff9c912d-4861-4fe3-8e00-96c819c51ca9'] = $pane;
    $display->panels['center'][3] = 'new-ff9c912d-4861-4fe3-8e00-96c819c51ca9';
    $pane = new stdClass();
    $pane->pid = 'new-5896806e-06f1-4e36-85bb-33f198b1e719';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'statistic-chart_datasets';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Datasets',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '5896806e-06f1-4e36-85bb-33f198b1e719';
    $display->content['new-5896806e-06f1-4e36-85bb-33f198b1e719'] = $pane;
    $display->panels['center'][4] = 'new-5896806e-06f1-4e36-85bb-33f198b1e719';
    $pane = new stdClass();
    $pane->pid = 'new-cb65836d-ee43-44f3-a99a-51d608cb4ffe';
    $pane->panel = 'date_filter';
    $pane->type = 'piwik_dateselect_form';
    $pane->subtype = 'piwik_dateselect_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report' => NULL,
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
    $pane->uuid = 'cb65836d-ee43-44f3-a99a-51d608cb4ffe';
    $display->content['new-cb65836d-ee43-44f3-a99a-51d608cb4ffe'] = $pane;
    $display->panels['date_filter'][0] = 'new-cb65836d-ee43-44f3-a99a-51d608cb4ffe';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['piwik_statictics'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'previous_resource';
  $page->task = 'page';
  $page->admin_title = 'Предыдущий ресурс';
  $page->admin_description = '';
  $page->path = 'node/%node/previous';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'resource' => 'resource',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'rb_misc_conditions:rules_access_rule_dataset_is_multivolume',
        'settings' => array(
          'component_name' => 'rules_access_rule_dataset_is_multivolume',
        ),
        'context' => array(
          0 => 'argument_entity_id:node_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Previous volume',
    'name' => 'navigation',
    'weight' => '7',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Материал: ID',
      'name' => 'entity_id:node',
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
  $handler->name = 'page_previous_resource_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'previous_resource';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Предыдущий ресурс',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Материал from Материал (on Материал: Dataset [field_dataset_ref])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_dataset_ref-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_9',
    'rb_misc_trigger' => 1,
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
  $display->title = '';
  $display->uuid = '0f18eda3-b0b1-4210-a3cb-3a8162486cea';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['previous_resource'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'profile_add_new';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Создание материала, пункт - добавить Новость';
  $page->admin_description = '';
  $page->path = 'user/%user/add-new';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Создание материала',
    'name' => 'navigation',
    'weight' => '15',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_profile_add_new_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'profile_add_new';
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
        'identifier' => 'Форма добавления материала',
        'keyword' => 'node_add',
        'name' => 'node_add_form',
        'type' => 'news',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_3',
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
  $display->title = '';
  $display->uuid = '6aa70996-4998-4fa9-8f7f-14aadf5e90d6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6fbb4244-53f6-48bd-9044-59900d7e8fe3';
    $pane->panel = 'middle';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'context_node_add_form_1',
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
    $pane->uuid = '6fbb4244-53f6-48bd-9044-59900d7e8fe3';
    $display->content['new-6fbb4244-53f6-48bd-9044-59900d7e8fe3'] = $pane;
    $display->panels['middle'][0] = 'new-6fbb4244-53f6-48bd-9044-59900d7e8fe3';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['profile_add_new'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'quick_facts';
  $page->task = 'page';
  $page->admin_title = 'Быстрые факты';
  $page->admin_description = '';
  $page->path = 'user/%user/facts';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'argument_entity_id:user_1',
          1 => 'logged-in-user',
        ),
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'create quick_fact content',
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Быстрые факты',
    'name' => 'navigation',
    'weight' => '10',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_quick_facts_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'quick_facts';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Быстрые факты',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_7',
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
  $display->title = 'User profile';
  $display->uuid = '6537b06b-6e9f-4a7e-9f99-3b118b03b540';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-52b21fca-a607-4a45-b471-76f17354be49';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'quick_facts-quick_facts';
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
    $pane->uuid = '52b21fca-a607-4a45-b471-76f17354be49';
    $display->content['new-52b21fca-a607-4a45-b471-76f17354be49'] = $pane;
    $display->panels['main'][0] = 'new-52b21fca-a607-4a45-b471-76f17354be49';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['quick_facts'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'redaction';
  $page->task = 'page';
  $page->admin_title = 'Редакция';
  $page->admin_description = '';
  $page->path = 'user/%user/redaction';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 5,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
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
      'keyword' => 'user',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_redaction_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'redaction';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Страница редактора',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_7',
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
  $display->title = 'Redaction';
  $display->uuid = '2c3c28ca-11f9-4db4-ab79-de0c343e4a70';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-681598ca-1989-4531-82e6-e6ea36dfbdbf';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'news-news_redaction';
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
    $pane->uuid = '681598ca-1989-4531-82e6-e6ea36dfbdbf';
    $display->content['new-681598ca-1989-4531-82e6-e6ea36dfbdbf'] = $pane;
    $display->panels['middle'][0] = 'new-681598ca-1989-4531-82e6-e6ea36dfbdbf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['redaction'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'rubric_competitions';
  $page->task = 'page';
  $page->admin_title = 'Рубрика - закладка Конкурсы';
  $page->admin_description = '';
  $page->path = 'taxonomy/term/%taxonomy_term/competition';
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
  $page->arguments = array(
    'taxonomy_term' => array(
      'id' => 1,
      'identifier' => 'Taxonomy term: ID',
      'name' => 'term',
      'settings' => array(
        'input_form' => 'tid',
        'vids' => array(
          3 => '3',
          1 => 0,
          4 => 0,
          2 => 0,
          5 => 0,
        ),
        'breadcrumb' => 1,
        'transform' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_rubric_competitions_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'rubric_competitions';
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
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template_panel_context_2',
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
  $display->title = '';
  $display->uuid = '6ef410d9-37a6-4a35-9887-fa24085052d7';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ea20c951-d2ab-4363-94a6-d20e5240ccc6';
    $pane->panel = 'center';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 6,
              1 => 3,
              2 => 4,
              3 => 5,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => 'Ссылка на добавление конкурса',
      'title' => '',
      'body' => '<div class="view-organizations"><div class="pane-btn"><a class="btn" href="/node/add/competition?destination=taxonomy/term/%taxonomy_term:tid/competition&field_competition_rubric=%taxonomy_term:tid"><?php print t(\'Add competition\');?></a></div></div>',
      'format' => 'ds_code',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ea20c951-d2ab-4363-94a6-d20e5240ccc6';
    $display->content['new-ea20c951-d2ab-4363-94a6-d20e5240ccc6'] = $pane;
    $display->panels['center'][0] = 'new-ea20c951-d2ab-4363-94a6-d20e5240ccc6';
    $pane = new stdClass();
    $pane->pid = 'new-a0d938f0-8a21-4323-9db0-3bca5dbc61e0';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'competitions_for_rubrics-competitions_for_rubric';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'tid' => '%taxonomy_term:tid',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a0d938f0-8a21-4323-9db0-3bca5dbc61e0';
    $display->content['new-a0d938f0-8a21-4323-9db0-3bca5dbc61e0'] = $pane;
    $display->panels['center'][1] = 'new-a0d938f0-8a21-4323-9db0-3bca5dbc61e0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['rubric_competitions'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'rules_and_recommendations';
  $page->task = 'page';
  $page->admin_title = 'Правила и рекомендации';
  $page->admin_description = '';
  $page->path = 'node/1863';
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
  $handler->name = 'page_rules_and_recommendations_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'rules_and_recommendations';
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
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_5',
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
  $display->title = 'Rules and Recommendations';
  $display->uuid = 'b7af63a7-7600-4581-b7a3-185aa1056d49';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ed631167-6bbe-49a7-8c8a-05b37a636d23';
    $pane->panel = 'middle';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '%1',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'full',
      'link_node_title' => 0,
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
    $pane->uuid = 'ed631167-6bbe-49a7-8c8a-05b37a636d23';
    $display->content['new-ed631167-6bbe-49a7-8c8a-05b37a636d23'] = $pane;
    $display->panels['middle'][0] = 'new-ed631167-6bbe-49a7-8c8a-05b37a636d23';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-ed631167-6bbe-49a7-8c8a-05b37a636d23';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['rules_and_recommendations'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search';
  $page->task = 'page';
  $page->admin_title = 'Поиск по сайту';
  $page->admin_description = '';
  $page->path = 'search';
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
  $handler->name = 'page_search_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Поиск по сайту',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => '',
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
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'facets',
          1 => 'center',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Центр',
        'width' => '79.79480337970904',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'dataset-search-facets',
      ),
      'facets' => array(
        'type' => 'region',
        'title' => 'Facets',
        'width' => '20.20519662029096',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => 'region-facet',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'facets' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Поиск по сайту';
  $display->uuid = 'ab89aa29-909a-4370-b0b4-b78d3467d3f8';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d1b7431a-be60-4ae3-bc80-3a781e2f19ca';
    $pane->panel = 'center';
    $pane->type = 'block';
    $pane->subtype = 'search_api_sorts-search-sorts';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-datasets-search-dataset-search',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd1b7431a-be60-4ae3-bc80-3a781e2f19ca';
    $display->content['new-d1b7431a-be60-4ae3-bc80-3a781e2f19ca'] = $pane;
    $display->panels['center'][0] = 'new-d1b7431a-be60-4ae3-bc80-3a781e2f19ca';
    $pane = new stdClass();
    $pane->pid = 'new-f0ad601a-3098-4741-98d3-359556fc75a4';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_search-content_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-datasets-search-dataset-search',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f0ad601a-3098-4741-98d3-359556fc75a4';
    $display->content['new-f0ad601a-3098-4741-98d3-359556fc75a4'] = $pane;
    $display->panels['center'][1] = 'new-f0ad601a-3098-4741-98d3-359556fc75a4';
    $pane = new stdClass();
    $pane->pid = 'new-02aae54e-6eb6-4954-8463-2f4a04f1b965';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-hgpfKHcnFK4kkcAT02ie13K5fYeRqEzY';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Тип материала',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '02aae54e-6eb6-4954-8463-2f4a04f1b965';
    $display->content['new-02aae54e-6eb6-4954-8463-2f4a04f1b965'] = $pane;
    $display->panels['facets'][0] = 'new-02aae54e-6eb6-4954-8463-2f4a04f1b965';
    $pane = new stdClass();
    $pane->pid = 'new-cbe6f93a-3b4b-4fd2-8421-65d65b928576';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-0AS8w8q1RfUr7pHIljRDYijNAojodBMF';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Рубрика',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'cbe6f93a-3b4b-4fd2-8421-65d65b928576';
    $display->content['new-cbe6f93a-3b4b-4fd2-8421-65d65b928576'] = $pane;
    $display->panels['facets'][1] = 'new-cbe6f93a-3b4b-4fd2-8421-65d65b928576';
    $pane = new stdClass();
    $pane->pid = 'new-0ea85f9c-eba9-4a91-8f12-74d4f2ba363f';
    $pane->panel = 'facets';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-bEI7sfj0GE5kGkDqVUF1lL0c1U7dQXVq';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Ключевые слова',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0ea85f9c-eba9-4a91-8f12-74d4f2ba363f';
    $display->content['new-0ea85f9c-eba9-4a91-8f12-74d4f2ba363f'] = $pane;
    $display->panels['facets'][2] = 'new-0ea85f9c-eba9-4a91-8f12-74d4f2ba363f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'success';
  $page->task = 'page';
  $page->admin_title = 'Операция успешно проведена';
  $page->admin_description = '';
  $page->path = 'success';
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
  $handler->name = 'page_success_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'success';
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
  $display->title = 'Congratulation';
  $display->uuid = 'ce6a4c4f-cf8a-438f-92c9-cfad5356f37e';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['success'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_ideas';
  $page->task = 'page';
  $page->admin_title = 'Профиль - закладка Идеи пользователя';
  $page->admin_description = '';
  $page->path = 'user/%user/ideas';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Мои идеи',
    'name' => 'navigation',
    'weight' => '5',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
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
  $handler->name = 'page_user_ideas_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'user_ideas';
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
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context_7',
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
  $display->title = 'My ideas';
  $display->uuid = 'b02f0636-1395-4d22-9872-ee369060a668';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1aab1aeb-0181-40dd-a625-f674107c845c';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Ссылка - добавить идею',
      'title' => '',
      'body' => '<a href="/node/add/idea">Добавить идею</a>',
      'format' => 'full_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1aab1aeb-0181-40dd-a625-f674107c845c';
    $display->content['new-1aab1aeb-0181-40dd-a625-f674107c845c'] = $pane;
    $display->panels['middle'][0] = 'new-1aab1aeb-0181-40dd-a625-f674107c845c';
    $pane = new stdClass();
    $pane->pid = 'new-e0d10a88-8de8-4db4-9820-a8e94c389318';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'ideas-panel_pane_2';
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
    $pane->uuid = 'e0d10a88-8de8-4db4-9820-a8e94c389318';
    $display->content['new-e0d10a88-8de8-4db4-9820-a8e94c389318'] = $pane;
    $display->panels['middle'][1] = 'new-e0d10a88-8de8-4db4-9820-a8e94c389318';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e0d10a88-8de8-4db4-9820-a8e94c389318';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_ideas'] = $page;

  return $pages;

}
