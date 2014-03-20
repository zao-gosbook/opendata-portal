<?php
/**
 * @file
 * views_menus_and_rules.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function views_menus_and_rules_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: devel.
  $menus['devel'] = array(
    'menu_name' => 'devel',
    'title' => 'Разработка',
    'description' => 'Development link',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: management.
  $menus['management'] = array(
    'menu_name' => 'management',
    'title' => 'Management',
    'description' => 'The <em>Management</em> menu contains links for administrative tasks.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-for-profile.
  $menus['menu-for-profile'] = array(
    'menu_name' => 'menu-for-profile',
    'title' => 'Меню для профиля пользователя',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-forum-menu.
  $menus['menu-forum-menu'] = array(
    'menu_name' => 'menu-forum-menu',
    'title' => 'Forum menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-masquerade-menu.
  $menus['menu-masquerade-menu'] = array(
    'menu_name' => 'menu-masquerade-menu',
    'title' => 'Masquerade menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-user-menu-2.
  $menus['menu-user-menu-2'] = array(
    'menu_name' => 'menu-user-menu-2',
    'title' => 'Меню для профиля пользователя - 2',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-user-menu-3.
  $menus['menu-user-menu-3'] = array(
    'menu_name' => 'menu-user-menu-3',
    'title' => 'Меню для профиля пользователя - 3',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: navigation.
  $menus['navigation'] = array(
    'menu_name' => 'navigation',
    'title' => 'Navigation',
    'description' => 'The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Development link');
  t('Footer');
  t('Forum menu');
  t('Main menu');
  t('Management');
  t('Masquerade menu');
  t('Navigation');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('The <em>Management</em> menu contains links for administrative tasks.');
  t('The <em>Navigation</em> menu contains links intended for site visitors. Links are added to the <em>Navigation</em> menu automatically by some modules.');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');
  t('Меню для профиля пользователя');
  t('Меню для профиля пользователя - 2');
  t('Меню для профиля пользователя - 3');
  t('Разработка');


  return $menus;
}
