<?php
/**
 * @file
 * flags_permissions_and_other.features.inc
 */

/**
 * Implements hook_flag_default_flags().
 */
function flags_permissions_and_other_flag_default_flags() {
  $flags = array();
  // Exported flag: "Запрос отправлен".
  $flags['for_request'] = array(
    'entity_type' => 'entityform',
    'title' => 'Запрос отправлен',
    'global' => 0,
    'types' => array(
      0 => 'opendata_query',
    ),
    'flag_short' => 'Запрос отправлен',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Запрос не отправлен',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'email' => 0,
      'confirmation' => 0,
      'download' => 0,
      'table' => 0,
      'review' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'api_version' => 3,
    'module' => 'flags_permissions_and_other',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Добавить роль Публикатор".
  $flags['make_publisher'] = array(
    'entity_type' => 'user',
    'title' => 'Добавить роль Публикатор',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Добавить роль Публикатор',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Убрать роль Публикатора',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 0,
    'access_uid' => 'others',
    'flag_confirmation' => 'Роль добавлена',
    'unflag_confirmation' => 'Роль убрана',
    'api_version' => 3,
    'module' => 'flags_permissions_and_other',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Просмотр материла".
  $flags['materials_shown'] = array(
    'entity_type' => 'node',
    'title' => 'Просмотр материла',
    'global' => 0,
    'types' => array(
      0 => 'dataset',
    ),
    'flag_short' => 'Материал просмотрен',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Материал не показан',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'ideas_list' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'flags_permissions_and_other',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Переадресовано сотрудникам МИНЭК".
  $flags['sent_to_minek'] = array(
    'entity_type' => 'node',
    'title' => 'Переадресовано сотрудникам МИНЭК',
    'global' => 1,
    'types' => array(
      0 => 'idea',
    ),
    'flag_short' => 'Отослано в МИНЭК',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Не отослано в МИНЭК',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'ideas_list' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'flags_permissions_and_other',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Подписка на набор данных".
  $flags['subscribe_dataset'] = array(
    'entity_type' => 'node',
    'title' => 'Подписка на набор данных',
    'global' => 0,
    'types' => array(
      0 => 'dataset',
    ),
    'flag_short' => 'Подписаться на уведомления',
    'flag_long' => 'На вашу электронную почту и в личные сообщения на портале будут приходить уведомления о планируемых изменениях в наборе данных',
    'flag_message' => 'Вы подписались на уведомления',
    'unflag_short' => 'Отписаться от уведомлений',
    'unflag_long' => 'На вашу электронную почту и в личные сообщения на портале перестанут приходить уведомления об изменениях в наборе данных',
    'unflag_message' => 'Вы отписались от уведомлений',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'ideas_list' => 0,
      'token' => 0,
      'search' => 0,
      'table' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'flags_permissions_and_other',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
