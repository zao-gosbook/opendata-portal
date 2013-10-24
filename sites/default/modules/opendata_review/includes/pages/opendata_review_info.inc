<?php

/**
 * List of opendata review steps.
 */
function opendata_review_page_opendata_review_steps($type) {
  // Init variables.
  $items = array();

  // Check url existence.
  $items['url_existence'] = array(
    'review_types' => array('site', 'list', 'meta'),
    'type' => 'url_existence',
    'label' => 'Проверка существования веб-страницы',
    'results' => array(
      'status' => 'веб-страница существует',
      'error' => 'веб-страница не существует',
    ),
  );

  // Check url format.
  $items['url_format'] = array(
    'review_types' => array('site', 'list', 'meta'),
    'type' => 'url_format',
    'label' => 'Проверка формата веб-страницы',
    'results' => array(
      'status' => 'формат адреса веб-страницы верный',
      'warning' => 'формат адреса веб-страницы не верный',
    ),
  );

  // Check doctype.
  $items['doctype'] = array(
    'review_types' => array('site', 'list', 'meta'),
    'type' => 'doctype',
    'label' => 'Проверка DOCTYPE на RDFa совместимость',
    'results' => array(
      'status' => 'указан совместимый DOCTYPE',
      'warning' => 'указан не совместимый DOCTYPE или не указан совсем, возможны ошибки валидации сайта',
    ),
  );

  // Check opendata meta existing.
  $items['opendata_list'] = array(
    'review_types' => array('list'),
    'type' => 'opendata_list',
    'label' => 'Проверка наличия списка открытых данных',
    'results' => array(
      'status' => 'обнаружен список открытых данных в формате RDFa на указанной странице',
      'error' => 'данная страница не содержит списка открытых данных в формате RDFa, проследуйте рекомендациям <a href="/manuals">инструкций</a>',
    ),
  );

  // Check opendata meta existing.
  $items['opendata_meta'] = array(
    'review_types' => array('meta'),
    'type' => 'opendata_meta',
    'label' => 'Проверка наличия открытых данных',
    'results' => array(
      'status' => 'обнаружены открытые данные в формате RDFa на указанной странице',
      'error' => 'данная страница не содержит открытых данных в формате RDFa, проследуйте рекомендациям <a href="/manuals">инструкций</a>',
    ),
  );

  // Check opendata properties.
  $items['opendata_properties'] = array(
    'review_types' => array('meta'),
    'type' => 'opendata_properties',
    'label' => 'Проверка параметров открытых данных',
    'results' => array(
      'status' => 'все параметры открытых данных указаны',
      'error' => 'некоторые параметры открытых данных не указаны',
    ),
  );

  // Remove improper steps under the current review type.
  foreach ($items as $item) {
    if (!in_array($type, $item['review_types'])) {
      unset($items[$item['type']]);
    }
  }

  return $items;
}

/**
 * List of opendata properties.
 */
function opendata_review_page_opendata_review_opendata_property_list() {
  // Init variables.
  $items = array();

  $items['identifier'] = array(
    'id' => 1,
    'type' => 'identifier',
    'label' => 'Идентификационный номер (код) набора данных',
  );
  $items['title'] = array(
    'id' => 2,
    'type' => 'title',
    'label' => 'Наименование набора данных',
  );
  $items['description'] = array(
    'id' => 3,
    'type' => 'description',
    'label' => 'Описание набора данных',
  );
  $items['creator'] = array(
    'id' => 4,
    'type' => 'creator',
    'label' => 'Владелец набора данных',
  );
  $items['publisher'] = array(
    'id' => 5,
    'type' => 'publisher',
    'label' => 'Ответственное лицо и способ связи с ним',
  );
  $items['source'] = array(
    'id' => 6,
    'type' => 'source',
    'label' => 'Ссылка (URL) на набор',
  );
  $items['format'] = array(
    'id' => 7,
    'type' => 'format',
    'label' => 'Формат данных',
  );
  $items['conformsTo'] = array(
    'id' => 8,
    'type' => 'conformsTo',
    'label' => 'Структура (модель) данных',
  );
  $items['created'] = array(
    'id' => 9,
    'type' => 'created',
    'label' => 'Дата первой публикации набора данных',
  );
  $items['modified'] = array(
    'id' => 10,
    'type' => 'modified',
    'label' => 'Дата последнего внесения изменений',
  );
  $items['provenance'] = array(
    'id' => 11,
    'type' => 'provenance',
    'label' => 'Содержание последнего изменения',
  );
  $items['isVersionOf'] = array(
    'id' => 12,
    'type' => 'isVersionOf',
    'label' => 'Ссылка (URL) на предыдущий релиз набора данных, если он есть',
  );
  $items['valid'] = array(
    'id' => 13,
    'type' => 'valid',
    'label' => 'Периодичность актуализации набора данных, дней',
  );
  $items['subject'] = array(
    'id' => 14,
    'type' => 'subject',
    'label' => 'Ключевые слова, соответствующие содержанию набора данных',
  );

  return $items;
}

/**
 * List of RDFa compatible doctypes.
 */
function opendata_review_page_opendata_review_opendata_doctype_list() {
  // Init variables.
  $items = array();

  $items[] = array(
    'public' => '-//W3C//DTD XHTML+RDFa 1.1//EN',
    'system' => 'http://www.w3.org/MarkUp/DTD/xhtml-rdfa-2.dtd',
  );
  $items[] = array(
    'public' => '-//W3C//DTD XHTML+RDFa 1.0//EN',
    'system' => 'http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd',
  );
  $items[] = array(
    'public' => '-//W3C//DTD HTML 4.01+RDFa 1.1//EN',
    'system' => 'http://www.w3.org/MarkUp/DTD/html401-rdfa11-1.dtd',
  );
  $items[] = array(
    'public' => '-//W3C//DTD HTML 4.01+RDFa 1.0//EN',
    'system' => 'http://www.w3.org/MarkUp/DTD/html401-rdfa-1.dtd',
  );

  return $items;
}
