<?php
/**
 * @file
 * views_menus_and_rules.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function views_menus_and_rules_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<nolink>
  $menu_links['main-menu:<nolink>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Данные',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -38,
    'language' => 'ru',
    'customized' => 1,
  );
  // Exported menu link: main-menu:about
  $menu_links['main-menu:about'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'О портале',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:apps
  $menu_links['main-menu:apps'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'apps',
    'router_path' => 'apps',
    'link_title' => 'Приложения',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -34,
    'language' => 'ru',
    'customized' => 1,
  );
  // Exported menu link: main-menu:askopendata
  $menu_links['main-menu:askopendata'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'askopendata',
    'router_path' => 'askopendata',
    'link_title' => 'Запросить данные',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:blog
  $menu_links['main-menu:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Блоги',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:calendar
  $menu_links['main-menu:calendar'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'calendar',
    'router_path' => 'calendar',
    'link_title' => 'Календарь',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -32,
    'language' => 'und',
    'customized' => 0,
  );
  // Exported menu link: main-menu:competitions
  $menu_links['main-menu:competitions'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'competitions',
    'router_path' => 'competitions',
    'link_title' => 'Конкурсы',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:dataset
  $menu_links['main-menu:dataset'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dataset',
    'router_path' => 'dataset',
    'link_title' => 'Наборы данных',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:datasets-map
  $menu_links['main-menu:datasets-map'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'datasets-map',
    'router_path' => 'datasets-map',
    'link_title' => 'Карта',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:eform/submit/opendata-query
  $menu_links['main-menu:eform/submit/opendata-query'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'eform/submit/opendata-query',
    'router_path' => 'eform/submit/%',
    'link_title' => 'Добавить данные',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:feedback
  $menu_links['main-menu:feedback'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'feedback',
    'router_path' => 'feedback',
    'link_title' => 'Обратная связь',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:file-coverting-service
  $menu_links['main-menu:file-coverting-service'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'file-coverting-service',
    'router_path' => 'file-coverting-service',
    'link_title' => 'Конвертер в машиночитаемые форматы',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:forum
  $menu_links['main-menu:forum'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'forum',
    'router_path' => 'forum',
    'link_title' => 'Форум',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:ideas
  $menu_links['main-menu:ideas'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'ideas',
    'router_path' => 'ideas',
    'link_title' => 'Идеи',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:library
  $menu_links['main-menu:library'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'library',
    'router_path' => 'library',
    'link_title' => 'Библиотека',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:library-developers
  $menu_links['main-menu:library-developers'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'library-developers',
    'router_path' => 'library-developers',
    'link_title' => 'Библиотека',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:node/1863
  $menu_links['main-menu:node/1863'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1863',
    'router_path' => 'node/1863',
    'link_title' => 'Правила и рекомендации',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:node/1864
  $menu_links['main-menu:node/1864'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/1864',
    'router_path' => 'node/1864',
    'link_title' => 'Информация',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:node/add/organization
  $menu_links['main-menu:node/add/organization'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/organization',
    'router_path' => 'node/add/organization',
    'link_title' => 'Добавить организацию',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'language' => 'und',
    'customized' => 0,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:organizations
  $menu_links['main-menu:organizations'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'organizations',
    'router_path' => 'organizations',
    'link_title' => 'Организации',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => 2,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:site-usage
  $menu_links['main-menu:site-usage'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'site-usage',
    'router_path' => 'site-usage',
    'link_title' => 'Статистика',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:sparql
  $menu_links['main-menu:sparql'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'sparql',
    'router_path' => 'sparql',
    'link_title' => 'SPARQL endpoint',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/10
  $menu_links['main-menu:taxonomy/term/10'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/10',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Безопасность',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/12
  $menu_links['main-menu:taxonomy/term/12'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/12',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Транспорт',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 9,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/15
  $menu_links['main-menu:taxonomy/term/15'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/15',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Здоровье',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/71
  $menu_links['main-menu:taxonomy/term/71'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/71',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Государство',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/72
  $menu_links['main-menu:taxonomy/term/72'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/72',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'География',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/73
  $menu_links['main-menu:taxonomy/term/73'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/73',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Construction',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'language' => 'en',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/74
  $menu_links['main-menu:taxonomy/term/74'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/74',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Торговля',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 8,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/8
  $menu_links['main-menu:taxonomy/term/8'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/8',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Образование',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 4,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/864
  $menu_links['main-menu:taxonomy/term/864'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/864',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Спорт',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 6,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/865
  $menu_links['main-menu:taxonomy/term/865'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/865',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Экология',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 10,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/866
  $menu_links['main-menu:taxonomy/term/866'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/866',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Культура',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 5,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/867
  $menu_links['main-menu:taxonomy/term/867'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/867',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Электроника',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 12,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: main-menu:taxonomy/term/9
  $menu_links['main-menu:taxonomy/term/9'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/9',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Экономика',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 11,
    'language' => 'ru',
    'customized' => 1,
    'parent_path' => '<nolink>',
  );
  // Exported menu link: menu-footer:about
  $menu_links['menu-footer:about'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'about',
    'router_path' => 'about',
    'link_title' => 'About',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-footer:eform/submit/feedback
  $menu_links['menu-footer:eform/submit/feedback'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'eform/submit/feedback',
    'router_path' => 'eform/submit/%',
    'link_title' => 'Feedback',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 3,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-footer:site-usage
  $menu_links['menu-footer:site-usage'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'site-usage',
    'router_path' => 'site-usage',
    'link_title' => 'Statistics',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 2,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-for-profile:menutoken/52d633d9d33d0
  $menu_links['menu-for-profile:menutoken/52d633d9d33d0'] = array(
    'menu_name' => 'menu-for-profile',
    'link_path' => 'menutoken/52d633d9d33d0',
    'router_path' => 'menutoken/%',
    'link_title' => 'My ideas',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/ideas',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-for-profile:menutoken/52d63dada7bf1
  $menu_links['menu-for-profile:menutoken/52d63dada7bf1'] = array(
    'menu_name' => 'menu-for-profile',
    'link_path' => 'menutoken/52d63dada7bf1',
    'router_path' => 'menutoken/%',
    'link_title' => 'Redaction',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/redaction',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-for-profile:menutoken/52d63e06683fe
  $menu_links['menu-for-profile:menutoken/52d63e06683fe'] = array(
    'menu_name' => 'menu-for-profile',
    'link_path' => 'menutoken/52d63e06683fe',
    'router_path' => 'menutoken/%',
    'link_title' => 'Datasets',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/datasets',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-for-profile:menutoken/52d640b826594
  $menu_links['menu-for-profile:menutoken/52d640b826594'] = array(
    'menu_name' => 'menu-for-profile',
    'link_path' => 'menutoken/52d640b826594',
    'router_path' => 'menutoken/%',
    'link_title' => 'Редакция',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/redaction',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'language' => 'ru',
    'customized' => 1,
  );
  // Exported menu link: menu-for-profile:menutoken/52d640e995b3c
  $menu_links['menu-for-profile:menutoken/52d640e995b3c'] = array(
    'menu_name' => 'menu-for-profile',
    'link_path' => 'menutoken/52d640e995b3c',
    'router_path' => 'menutoken/%',
    'link_title' => 'Наборы данных',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/datasets',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'language' => 'ru',
    'customized' => 1,
  );
  // Exported menu link: menu-for-profile:menutoken/52e253ed3521a
  $menu_links['menu-for-profile:menutoken/52e253ed3521a'] = array(
    'menu_name' => 'menu-for-profile',
    'link_path' => 'menutoken/52e253ed3521a',
    'router_path' => 'menutoken/%',
    'link_title' => 'Активность',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'language' => 'ru',
    'customized' => 1,
  );
  // Exported menu link: menu-for-profile:menutoken/52e2540cd4149
  $menu_links['menu-for-profile:menutoken/52e2540cd4149'] = array(
    'menu_name' => 'menu-for-profile',
    'link_path' => 'menutoken/52e2540cd4149',
    'router_path' => 'menutoken/%',
    'link_title' => 'Activity',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-forum-menu:eform/submit/add-new-forum
  $menu_links['menu-forum-menu:eform/submit/add-new-forum'] = array(
    'menu_name' => 'menu-forum-menu',
    'link_path' => 'eform/submit/add-new-forum',
    'router_path' => 'eform/submit/%',
    'link_title' => 'Новый раздел',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'language' => 'ru',
    'customized' => 1,
  );
  // Exported menu link: menu-forum-menu:node/add/forum
  $menu_links['menu-forum-menu:node/add/forum'] = array(
    'menu_name' => 'menu-forum-menu',
    'link_path' => 'node/add/forum',
    'router_path' => 'node/add/forum',
    'link_title' => 'Новая тема',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'language' => 'ru',
    'customized' => 1,
  );
  // Exported menu link: menu-user-menu-2:new-dataset
  $menu_links['menu-user-menu-2:new-dataset'] = array(
    'menu_name' => 'menu-user-menu-2',
    'link_path' => 'new-dataset',
    'router_path' => 'new-dataset',
    'link_title' => 'Dataset',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-user-menu-2:node/add/competition
  $menu_links['menu-user-menu-2:node/add/competition'] = array(
    'menu_name' => 'menu-user-menu-2',
    'link_path' => 'node/add/competition',
    'router_path' => 'node/add/competition',
    'link_title' => 'Competition',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-user-menu-2:node/add/document
  $menu_links['menu-user-menu-2:node/add/document'] = array(
    'menu_name' => 'menu-user-menu-2',
    'link_path' => 'node/add/document',
    'router_path' => 'node/add/document',
    'link_title' => 'Document',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-user-menu-2:node/add/news
  $menu_links['menu-user-menu-2:node/add/news'] = array(
    'menu_name' => 'menu-user-menu-2',
    'link_path' => 'node/add/news',
    'router_path' => 'node/add/news',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-user-menu-2:node/add/organization
  $menu_links['menu-user-menu-2:node/add/organization'] = array(
    'menu_name' => 'menu-user-menu-2',
    'link_path' => 'node/add/organization',
    'router_path' => 'node/add/organization',
    'link_title' => 'Organization',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-user-menu-2:node/add/quick-fact
  $menu_links['menu-user-menu-2:node/add/quick-fact'] = array(
    'menu_name' => 'menu-user-menu-2',
    'link_path' => 'node/add/quick-fact',
    'router_path' => 'node/add/quick-fact',
    'link_title' => 'Quick facts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-user-menu-3:menutoken/53218ea847130
  $menu_links['menu-user-menu-3:menutoken/53218ea847130'] = array(
    'menu_name' => 'menu-user-menu-3',
    'link_path' => 'menutoken/53218ea847130',
    'router_path' => 'menutoken/%',
    'link_title' => 'Edit profile',
    'options' => array(
      'menu_token_link_path' => 'user/[user:uid]/edit',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: user-menu:messages
  $menu_links['user-menu:messages'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'messages',
    'router_path' => 'messages',
    'link_title' => 'Messages',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'messages',
        ),
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: user-menu:user
  $menu_links['user-menu:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: user-menu:user/1
  $menu_links['user-menu:user/1'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/1',
    'router_path' => 'user/%',
    'link_title' => 'Account',
    'options' => array(
      'menu_token_link_path' => 'user/[current-user:uid]',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'account',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: user-menu:user/1/moderation
  $menu_links['user-menu:user/1/moderation'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/1/moderation',
    'router_path' => 'user/%/moderation',
    'link_title' => 'Moderation',
    'options' => array(
      'menu_token_link_path' => 'user/[current-user:uid]/moderation',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'moderation',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: user-menu:user/login
  $menu_links['user-menu:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'language' => 'und',
    'customized' => 0,
    'parent_path' => 'user',
  );
  // Exported menu link: user-menu:user/logout
  $menu_links['user-menu:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'logout',
        ),
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'language' => 'ru',
    'customized' => 1,
  );
  // Exported menu link: user-menu:user/register
  $menu_links['user-menu:user/register'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Create new account',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'language' => 'und',
    'customized' => 0,
    'parent_path' => 'user',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Account');
  t('Activity');
  t('Competition');
  t('Construction');
  t('Create new account');
  t('Dataset');
  t('Datasets');
  t('Document');
  t('Edit profile');
  t('Feedback');
  t('Log in');
  t('Log out');
  t('Messages');
  t('Moderation');
  t('My ideas');
  t('News');
  t('Organization');
  t('Quick facts');
  t('Redaction');
  t('SPARQL endpoint');
  t('Statistics');
  t('User account');
  t('Активность');
  t('Безопасность');
  t('Библиотека');
  t('Блоги');
  t('География');
  t('Государство');
  t('Данные');
  t('Добавить данные');
  t('Добавить организацию');
  t('Запросить данные');
  t('Здоровье');
  t('Идеи');
  t('Информация');
  t('Календарь');
  t('Карта');
  t('Конвертер в машиночитаемые форматы');
  t('Конкурсы');
  t('Культура');
  t('Наборы данных');
  t('Новая тема');
  t('Новый раздел');
  t('О портале');
  t('Образование');
  t('Обратная связь');
  t('Организации');
  t('Правила и рекомендации');
  t('Приложения');
  t('Редакция');
  t('Спорт');
  t('Статистика');
  t('Торговля');
  t('Транспорт');
  t('Форум');
  t('Экология');
  t('Экономика');
  t('Электроника');


  return $menu_links;
}
