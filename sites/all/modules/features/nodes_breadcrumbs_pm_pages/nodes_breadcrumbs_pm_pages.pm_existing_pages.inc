<?php
/**
 * @file
 * nodes_breadcrumbs_pm_pages.pm_existing_pages.inc
 */

/**
 * Implements hook_pm_existing_pages_info().
 */
function nodes_breadcrumbs_pm_pages_pm_existing_pages_info() {
  $export = array();

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'new_private_message';
  $pm_existing_page->label = 'Форма создания сообщения';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'messages/new';
  $export['new_private_message'] = $pm_existing_page;

  $pm_existing_page = new stdClass();
  $pm_existing_page->api_version = 1;
  $pm_existing_page->name = 'user_login_page';
  $pm_existing_page->label = 'User Login Page';
  $pm_existing_page->context = '';
  $pm_existing_page->paths = 'user';
  $export['user_login_page'] = $pm_existing_page;

  return $export;
}
