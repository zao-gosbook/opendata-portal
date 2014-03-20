<?php
/**
 * @file
 * nodes_breadcrumbs_pm_pages.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function nodes_breadcrumbs_pm_pages_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = '123';
  $path_breadcrumb->name = 'Заявка на публикаторство';
  $path_breadcrumb->path = 'become-a-publisher';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Organizations',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'organizations',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['123'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'about';
  $path_breadcrumb->name = 'О портале';
  $path_breadcrumb->path = 'about';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['about'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'actualize_dataset';
  $path_breadcrumb->name = 'Актуализация однотомного набора';
  $path_breadcrumb->path = 'actualize-dataset';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['actualize_dataset'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'actualize_dataset_mv';
  $path_breadcrumb->name = 'Актуализация многотомного набора';
  $path_breadcrumb->path = 'actualize-dataset-mv';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['actualize_dataset_mv'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'add_application';
  $path_breadcrumb->name = 'Добавить приложение';
  $path_breadcrumb->path = 'add_app';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Applications',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'apps',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['add_application'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'add_idea';
  $path_breadcrumb->name = 'Добавление идеи (аноним)';
  $path_breadcrumb->path = 'add-idea';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Ideas',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'ideas',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['add_idea'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'app';
  $path_breadcrumb->name = 'Приложение';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Apps',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'apps',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -94;
  $export['app'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'apps';
  $path_breadcrumb->name = 'Приложения';
  $path_breadcrumb->path = 'apps';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Apps',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -99;
  $export['apps'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'blog';
  $path_breadcrumb->name = 'Блог';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Blogs',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'blog',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -93;
  $export['blog'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'blogs';
  $path_breadcrumb->name = 'Блоги';
  $path_breadcrumb->path = 'blog';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Blogs',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'blog',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -98;
  $export['blogs'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'competition';
  $path_breadcrumb->name = 'Конкурс';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Developer resources',
      1 => 'competitions',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'competitions',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -96;
  $export['competition'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'competitions';
  $path_breadcrumb->name = 'Конкурсы';
  $path_breadcrumb->path = 'competitions';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Developer resources',
      1 => 'Competitions',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -97;
  $export['competitions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'dataset';
  $path_breadcrumb->name = 'Набор данных';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Data',
      1 => 'Datasets',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'dataset',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Node: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['dataset'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'dataset_creation';
  $path_breadcrumb->name = 'Добавление набора данных';
  $path_breadcrumb->path = 'new-dataset';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['dataset_creation'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'datasets';
  $path_breadcrumb->name = 'Наборы данных';
  $path_breadcrumb->path = 'dataset';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Data',
      1 => 'Datasets',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['datasets'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'datasets_map';
  $path_breadcrumb->name = 'Карта';
  $path_breadcrumb->path = 'datasets-map';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Data',
      1 => 'Map',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['datasets_map'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'developers_info';
  $path_breadcrumb->name = 'Информация для разработчиков';
  $path_breadcrumb->path = 'node/1864';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Developer resources',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['developers_info'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'developers_info_rules_and_recommendations';
  $path_breadcrumb->name = 'Правила и рекомендации';
  $path_breadcrumb->path = 'node/1863';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Developer resources',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['developers_info_rules_and_recommendations'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'document';
  $path_breadcrumb->name = 'Документ';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Library',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'library',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -92;
  $export['document'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'feedback';
  $path_breadcrumb->name = 'Обратная связь';
  $path_breadcrumb->path = 'feedback';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Services',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['feedback'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'file_coverting_service';
  $path_breadcrumb->name = 'Конвертация файла';
  $path_breadcrumb->path = 'file-coverting-service';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Services',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['file_coverting_service'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'forum';
  $path_breadcrumb->name = 'Форум';
  $path_breadcrumb->path = 'forum';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Forum',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['forum'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'forum_theme';
  $path_breadcrumb->name = 'Тема форума';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Forum',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'forum',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'forum' => 'forum',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['forum_theme'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'idea';
  $path_breadcrumb->name = 'Идея';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Ideas',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'ideas',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -95;
  $export['idea'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'ideas';
  $path_breadcrumb->name = 'Идеи';
  $path_breadcrumb->path = 'ideas';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Ideas',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = -100;
  $export['ideas'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'library';
  $path_breadcrumb->name = 'Библиотека';
  $path_breadcrumb->path = 'library';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Community',
      1 => 'Library',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['library'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'library_developers';
  $path_breadcrumb->name = 'Библиотека';
  $path_breadcrumb->path = 'library-developers';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Developer resources',
      1 => 'Library',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['library_developers'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'message';
  $path_breadcrumb->name = 'Сообщение';
  $path_breadcrumb->path = 'messages/view/%arg';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Messages',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'arg' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Строка',
          'use_tail' => 1,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['message'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'message_list';
  $path_breadcrumb->name = 'Все сообщения';
  $path_breadcrumb->path = 'messages/list';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Messages',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['message_list'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'message_sent';
  $path_breadcrumb->name = 'Отправленные сообщения';
  $path_breadcrumb->path = 'messages/sent';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Messages',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['message_sent'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'messages';
  $path_breadcrumb->name = 'Мои сообщения';
  $path_breadcrumb->path = 'messages';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Messages',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['messages'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'messages_new';
  $path_breadcrumb->name = 'Новое сообщение';
  $path_breadcrumb->path = 'messages/new';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'New message',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['messages_new'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'news';
  $path_breadcrumb->name = 'Новость';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:field-rubric:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%node:field-rubric:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['news'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organization';
  $path_breadcrumb->name = 'Организация';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Data',
      1 => 'Organizations',
      2 => '%node:title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => 'organizations',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -96;
  $export['organization'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'organizations';
  $path_breadcrumb->name = 'Организации';
  $path_breadcrumb->path = 'organizations';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Data',
      1 => 'Organizations',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['organizations'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'request_publisher';
  $path_breadcrumb->name = 'Заявка на публикаторство';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Publisher request',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['request_publisher'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'request_to_opendata';
  $path_breadcrumb->name = 'Запросить данные';
  $path_breadcrumb->path = 'askopendata';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Data',
      1 => 'Request to open data',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['request_to_opendata'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'reset_password';
  $path_breadcrumb->name = 'Восстановление пароля';
  $path_breadcrumb->path = 'user/password';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Reset password',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['reset_password'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'resource';
  $path_breadcrumb->name = 'Ресурс';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%node:field-dataset-ref:title',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%node:field-dataset-ref:title',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Материал: ID',
        ),
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
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = -96;
  $export['resource'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'rubric_term';
  $path_breadcrumb->name = 'Рубрика';
  $path_breadcrumb->path = 'taxonomy/term/%tid';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Topics',
      1 => '%tid:name',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'tid' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
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
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:taxonomy_term',
          'settings' => array(
            'type' => array(
              'rubrics' => 'rubrics',
            ),
          ),
          'context' => 'tid',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['rubric_term'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'rubric_term_blogs';
  $path_breadcrumb->name = 'Блоги рубрики';
  $path_breadcrumb->path = 'taxonomy/term/%tid/blogs';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Topics',
      1 => '%tid:name',
      2 => 'Blogs',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '%tid:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'tid' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
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
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:taxonomy_term',
          'settings' => array(
            'type' => array(
              'rubrics' => 'rubrics',
            ),
          ),
          'context' => 'tid',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['rubric_term_blogs'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'rubric_term_map';
  $path_breadcrumb->name = 'Карты рубрики';
  $path_breadcrumb->path = 'taxonomy/term/%tid/map';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Topics',
      1 => '%tid:name',
      2 => 'Map',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '%tid:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'tid' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
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
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:taxonomy_term',
          'settings' => array(
            'type' => array(
              'rubrics' => 'rubrics',
            ),
          ),
          'context' => 'tid',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['rubric_term_map'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'rubric_term_news';
  $path_breadcrumb->name = 'Новости рубрики';
  $path_breadcrumb->path = 'taxonomy/term/%tid/news';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Topics',
      1 => '%tid:name',
      2 => 'News',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '%tid:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'tid' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
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
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:taxonomy_term',
          'settings' => array(
            'type' => array(
              'rubrics' => 'rubrics',
            ),
          ),
          'context' => 'tid',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['rubric_term_news'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'rubric_term_news_competition';
  $path_breadcrumb->name = 'Конкурсы рубрики';
  $path_breadcrumb->path = 'taxonomy/term/%tid/competition';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Topics',
      1 => '%tid:name',
      2 => 'Competitions',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '%tid:url',
      2 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'tid' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
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
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:taxonomy_term',
          'settings' => array(
            'type' => array(
              'rubrics' => 'rubrics',
            ),
          ),
          'context' => 'tid',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['rubric_term_news_competition'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'site_usage';
  $path_breadcrumb->name = 'Статистика';
  $path_breadcrumb->path = 'site-usage';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => ' Data',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['site_usage'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'sparql_endpoint';
  $path_breadcrumb->name = 'Sparql endpoint';
  $path_breadcrumb->path = 'sparql';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Developer resources',
      1 => 'Sparql Endpoint',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['sparql_endpoint'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'success_page';
  $path_breadcrumb->name = 'Success page';
  $path_breadcrumb->path = 'success';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => ' ',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 0,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['success_page'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_login';
  $path_breadcrumb->name = 'Авторизация';
  $path_breadcrumb->path = 'user/login';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Login',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['user_login'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_login_2';
  $path_breadcrumb->name = 'Авторизация - 2';
  $path_breadcrumb->path = 'user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Login',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
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
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['user_login_2'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_password_reset';
  $path_breadcrumb->name = 'User password change';
  $path_breadcrumb->path = 'user/reset/%arg1/%arg2/%arg3';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Change password',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'arg1' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Строка',
          'use_tail' => 0,
        ),
      ),
      'arg2' => array(
        'position' => 3,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Строка',
          'use_tail' => 0,
        ),
      ),
      'arg3' => array(
        'position' => 4,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Строка',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['user_password_reset'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_profile';
  $path_breadcrumb->name = 'Профиль пользователя';
  $path_breadcrumb->path = 'user/%user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Account',
      1 => '%user:name',
    ),
    'paths' => array(
      0 => '<none>',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Пользователь: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '0',
          ),
          'context' => array(
            0 => 'user',
            1 => 'logged-in-user',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['user_profile'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_profile_own_profile_';
  $path_breadcrumb->name = 'Мой профиль';
  $path_breadcrumb->path = 'user/%user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'My account',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Пользователь: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'compare_users',
          'settings' => array(
            'equality' => '1',
          ),
          'context' => array(
            0 => 'user',
            1 => 'logged-in-user',
          ),
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['user_profile_own_profile_'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_register';
  $path_breadcrumb->name = 'Регистрация';
  $path_breadcrumb->path = 'user/register';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Register',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['user_register'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_tabs';
  $path_breadcrumb->name = 'Профиль пользователя (закладки)';
  $path_breadcrumb->path = 'user/%user/%arg';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '%user:name',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => '%user:url',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'Пользователь: ID',
        ),
      ),
      'arg' => array(
        'position' => 2,
        'argument' => 'string',
        'settings' => array(
          'identifier' => 'Строка',
          'use_tail' => 0,
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['user_tabs'] = $path_breadcrumb;

  return $export;
}
