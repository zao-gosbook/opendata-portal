<?php

class Opendata {
  private $meta;
  private $publisher;
  private $structure;
  private $data;
  private $uri;
  private $fields;
  private $errors;

  public function __construct($node) {
    if (!is_object($node) || !empty($node->is_new) || empty($node->nid)) {
      return FALSE;
    }

    $this->set_node_meta($node);
    $this->set_node_publisher();
    $this->set_node_structure();
    $this->set_node_data();

    $this->set_fields();
    $this->set_url();

    return $this;
  }

  private function set_fields() {
    $fields = array();

    $publisher_fields_error_text = 'Поле ответственного лица открытых данных не заполнено';
    $data_fields_error_text = 'Поле набора открытых данных не заполнено';

    $meta = $this->meta;
    $meta_fields = $meta->get_fields();

    $publisher = $this->publisher;
    if (!empty($publisher) && is_object($publisher)) {
      $publisher_fields = $publisher->get_fields();
    }

    $data = $this->data;
    $previous_data = $data;
    $last_data = array_shift($previous_data);
    if (!empty($last_data) && is_object($last_data)) {
      $last_data_fields = $last_data->get_fields();
    }

    $data_structure = array();
    foreach ($data as $item) {
      $structure_nid = $item->get_structure();
      if (!isset($data_structure[$structure_nid])) {
        $data_structure[$structure_nid] = $this->structure[$structure_nid];
      }
    }
    $previous_data_structure = $data_structure;
    $last_data_structure = array_shift($previous_data_structure);
    if (!empty($last_data_structure) && is_object($last_data_structure)) {
      $last_data_structure_fields = $last_data_structure->get_fields();
    }

    $previous_data_links = array();
    foreach ($previous_data as $item) {
      $item_fields = $item->get_fields();
      $previous_data_links[] = $item_fields['source']['render'];
    }

    $previous_data_structure_links = array();
    foreach ($previous_data_structure as $item) {
      $item_fields = $item->get_fields();
      $previous_data_structure_links[] = $item_fields['source']['render'];
    }

    // Field #1.
    $value = $meta_fields['name']['render'];
    $fields['name'] = array(
      'label' => 'Идентификационный номер',
      'value' => $value,
      'predicate' => array(
        'type' => 'property',
        'value' => 'dc:identifier',
      ),
    );

    // Field #2.
    $value = $meta_fields['title']['render'];
    $fields['title'] = array(
      'label' => 'Наименование набора данных',
      'value' => $value,
      'predicate' => array(
        'type' => 'property',
        'value' => 'dc:title',
      ),
    );

    // Field #3.
    $value = $meta_fields['description']['render'];
    $fields['description'] = array(
      'label' => 'Описание набора данных',
      'value' => $value,
      'predicate' => array(
        'type' => 'property',
        'value' => 'dc:description',
      ),
    );

    // Field #4.
    $value = $meta_fields['owner']['render'];
    $fields['owner'] = array(
      'label' => 'Владелец  набора данных',
      'value' => $value,
      'predicate' => array(
        'type' => 'property',
        'value' => 'dc:owner',
      ),
    );

    // Field #5.
    $value = !empty($publisher_fields) ? $publisher_fields['name']['render'] : $publisher_fields_error_text;
    $fields['publisher_name'] = array(
      'label' => 'Ответственное лицо',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #6.
    $value = !empty($publisher_fields) ? $publisher_fields['phone']['render'] : $publisher_fields_error_text;
    $fields['publisher_phone'] = array(
      'label' => 'Телефон ответственного лица',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #7.
    $value = !empty($publisher_fields) ? $publisher_fields['mail']['render'] : $publisher_fields_error_text;
    $fields['publisher_mail'] = array(
      'label' => 'Адрес электронной почты ответственного лица',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #8.
    $value = !empty($last_data_fields) ? $last_data_fields['source']['render'] : $data_fields_error_text;
    $fields['data_last_link'] = array(
      'label' => 'Гиперсылка (URL) на набор',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #9.
    $value = !empty($last_data_fields) ? $last_data_fields['format']['render'] : $data_fields_error_text;
    $fields['data_last_format'] = array(
      'label' => 'Формат данных',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #10.
    $value = !empty($last_data_structure_fields) ? $last_data_structure_fields['source']['render'] : $data_fields_error_text;
    $fields['data_last_structure_link'] = array(
      'label' => 'Описание структуры набора данных',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #11.
    $value = $meta_fields['created']['render'];
    $fields['created'] = array(
      'label' => 'Дата первой публикации набора данных',
      'value' => $value,
      'predicate' => array(
        'type' => 'property',
        'value' => 'dc:created',
      ),
    );

    // Field #12.
    $value = !empty($last_data_fields) ? $last_data_fields['created']['render'] : $data_fields_error_text;
    $fields['last_data_created'] = array(
      'label' => 'Дата последнего внесения изменений',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #13.
    $value = !empty($last_data_fields) ? $last_data_fields['changes']['render'] : $data_fields_error_text;
    $fields['last_data_changes'] = array(
      'label' => 'Содержание последнего изменения',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #14.
    $value = $meta_fields['valid']['render'];
    $fields['valid'] = array(
      'label' => 'Периодичность актуализации набора данных',
      'value' => $value,
      'predicate' => array(
        'type' => 'property',
        'value' => 'dc:valid',
      ),
    );

    // Field #15.
    $value = $meta_fields['subject']['render'];
    $fields['subject'] = array(
      'label' => 'Ключевые слова, соответствующие содержанию набора данных',
      'value' => $value,
      'predicate' => array(
        'type' => 'property',
        'value' => 'dc:subject',
      ),
    );

    // Field #16.
    $value = !empty($previous_data_links) ? implode('<br />', $previous_data_links): 'null';
    $fields['data_previous_links'] = array(
      'label' => 'Гиперссылки (URL) на версии набора данных',
      'value' => $value,
      'predicate' => FALSE,
    );

    // Field #17.
    $value = !empty($previous_data_structure_links) ? implode('<br />', $previous_data_structure_links): 'null';
    $fields['data_previous_structure_links'] = array(
      'label' => 'Гиперссылки (URL) на версии структуры набора данных',
      'value' => $value,
      'predicate' => FALSE,
    );

    $this->fields = $fields;
  }

  private function set_url() {
    $this->uri = OPENDATA_URL_PREFIX . '/' . $this->fields['name']['value'];
  }

  private function set_node_meta($node) {
    $this->meta = new OpendataMeta($node);
  }

  private function set_node_publisher() {
    $meta = $this->meta;
    $meta_node = $meta->get_node();

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'opendata_publisher');
    $query->fieldCondition('field_opendata_meta', 'target_id', $meta_node->nid);
    $result = $query->execute();

    $publisher = array();
    if (isset($result['node'])) {
      $publisher += node_load_multiple(array_keys($result['node']));
    }

    if (!empty($publisher)) {
      $this->publisher = new OpendataPublisher(reset($publisher));
    }
    else {
      $this->errors['publisher'] = 'Необходимо назначить ответственное лицо.';
    }
  }

  private function set_node_structure() {
    $meta = $this->meta;
    $meta_node = $meta->get_node();

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'opendata_structure');
    $query->fieldCondition('field_opendata_meta', 'target_id', $meta_node->nid);
    $result = $query->execute();

    $structure = array();
    if (isset($result['node'])) {
      $structure += node_load_multiple(array_keys($result['node']));
    }

    $this->structure = array();
    if (!empty($structure)) {
      foreach ($structure as $node) {
        $this->structure[$node->nid] = new OpendataStructure($node);
      }
    }
    else {
      $this->errors['structure'] = 'Необходимо заполнить поле структуры открытых данных.';
    }
  }

  private function set_node_data() {
    $meta = $this->meta;
    $meta_node = $meta->get_node();

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node');
    $query->entityCondition('bundle', 'opendata_data');
    $query->fieldCondition('field_opendata_meta', 'target_id', $meta_node->nid);
    $query->fieldOrderBy('field_oddata_created', 'value', 'DESC');
    $result = $query->execute();

    $data = array();
    if (isset($result['node'])) {
      $data += node_load_multiple(array_keys($result['node']));
    }

    $this->data = array();
    if (!empty($data)) {
      foreach ($data as $node) {
        $this->data[$node->nid] = new OpendataData($node);
      }
    }
    else {
      $errors['data'] = 'Необходимо заполнить поле набора открытых данных.';
    }
  }

  public function get_uri() {
    return $this->uri;
  }

  public function get_fields() {
    return $this->fields;
  }

  public function render() {
    $opendata_meta = '';

    // Init variables.
    $header = array();
    $rows = array();
    $attributes = array();
    $i = 0;

    // Build opendata header.
    $header[] = array(
      'data' => '№',
    );
    $header[] = array(
      'data' => 'Характеристика',
    );
    $header[] = array(
      'data' => 'Значение характеристики',
    );

    // Build rows.
    foreach ($this->fields as $field) {
      // Init variables.
      $cols = array();

      // Increase fields counter.
      $i++;

      // Define columns.
      $serial_col = array(
        'data' => $i,
      );
      $label_col = array(
        'data' => $field['label'],
      );

      // Init output variable.
      $value_col = array();

      // Get field content.
      $field_content = $field['value'];
      // $field_content = opendata_get_opendata_field_content($opendata_meta, $field['field_name']);

      $value_col['data'] = $field_content;

      if ($field['predicate']) {
        $property = $field['predicate']['type'];

        $value_col[$property] = $field['predicate']['value'];
      }

      // Add columns.
      $cols[] = $serial_col;
      $cols[] = $label_col;
      $cols[] = $value_col;

      $rows[] = array(
        'data' => $cols,
      );
    }

    // Build attributes.
    $attributes['about'] = '/' . $this->uri;
    $attributes['typeof'] = 'foaf:Document';

    $table['#theme'] = 'table';
    $table['#header'] = $header;
    $table['#rows'] = $rows;
    $table['#attributes'] = $attributes;
    $table['sticky'] = FALSE;

    $opendata_meta_table = theme('table', $table);

    // Get all data.
    $publisher = $this->publisher;
    $data = $this->data;
    $structure = $this->structure;

    // Set unique identifiers.
    $ids = array();
    $data_counter = 0;
    $structure_counter = 0;
    foreach ($data as $data_item) {
      $data_counter++;
      $data_item_node = $data_item->get_node();
      $data_item_node_nid = $data_item_node->nid;
      $ids[$data_item_node_nid] = $data_counter;
    }
    foreach ($structure as $structure_item) {
      $structure_counter++;
      $structure_item_node = $structure_item->get_node();
      $structure_item_node_nid = $structure_item_node->nid;
      $ids[$structure_item_node_nid] = $structure_counter;
    }

    // Meta.
    $meta_content = '';
    $meta_content .= '<div typeof="foaf:Document" about="' . '/' . $this->uri . '">' . "\n";
    $meta_content .= '<div rel="dc:conformsTo" resource="http://opendata.gosmonitor.ru/standard/2.3"></div>' . "\n";
    $meta_content .= $opendata_meta_table;
    $meta_content .= '<div rel="dc:publisher" resource="#publisher"></div>' . "\n";
    $meta_content .= '<div rel="dc:source" resource="#data"></div>' . "\n";
    $meta_content .= '</div>' . "\n";

    // Publisher.
    $publisher_content = '';
    if ($publisher) {
      $publisher_fields = $publisher->get_fields();
      $publisher_content .= '<div typeof="foaf:Person" about="#publisher">' . "\n";
      foreach ($publisher_fields as $field) {
        $publisher_content .= '<div property="' . $field['predicate'] . '" content="' . $field['value'] . '"></div>' . "\n";
      }
      $publisher_content .= '</div>' . "\n";
    }

    // Data.
    $data_content = '';
    $data_content .= '<div typeof="dc:Collection" about="#data">' . "\n";
    foreach ($data as $data_item) {
      $data_fields = $data_item->get_fields();
      $data_node = $data_item->get_node();
      $data_structure_nid = $data_item->get_structure();
      $data_item_content = '';
      $data_item_content .= '<div rel="dc:hasPart" resource="#data-' . $ids[$data_node->nid] . '">' . "\n";
      $data_item_content .= '<div typeof="foaf:Document" about="#data-' . $ids[$data_node->nid] . '">' . "\n";
      foreach ($data_fields as $field) {
        $data_item_content .= '<div property="' . $field['predicate'] . '" content="' . $field['value'] . '"></div>' . "\n";
      }
      $data_item_content .= '<div rel="dc:conformsTo" resource="#structure-' . $ids[$data_structure_nid] . '"></div>' . "\n";
      $data_item_content .= '</div>' . "\n";
      $data_item_content .= '</div>' . "\n";
      $data_content .= $data_item_content;
    }
    $data_content .= '</div>' . "\n";

    // Structure.
    $structure_content = '';
    $structure_content .= '<div>' . "\n";
    foreach ($structure as $structure_item) {
      $structure_fields = $structure_item->get_fields();
      $structure_node = $structure_item->get_node();
      $structure_item_content = '';
      $structure_item_content .= '<div typeof="foaf:Document" about="#structure-' . $ids[$structure_node->nid] . '">' . "\n";
      foreach ($structure_fields as $field) {
        $structure_item_content .= '<div property="' . $field['predicate'] . '" content="' . $field['value'] . '"></div>' . "\n";
      }
      $structure_item_content .= '</div>' . "\n";
      $structure_content .= $structure_item_content;
    }
    $structure_content .= '</div>' . "\n";

    $opendata_meta .= $meta_content;

    $opendata_meta .= $publisher_content;

    $opendata_meta .= $data_content;

    $opendata_meta .= $structure_content;

    return $opendata_meta;
  }

  public function display_errors() {
    // @todo Finish error block.
    $this->errors;

    if (!empty($errors)) {
      $message = array();
      $message[] = 'Паспорт открытых данных не готов к публикации!';

      $counter = 0;
      foreach ($errors as $error) {
        $counter++;
        $message[] = $counter . ') ' . $error;
      }
      drupal_set_message(implode('<br />', $message), 'error');
    }
  }
}

class OpendataMeta {
  private $inn;
  private $node;
  private $fields;

  public function __construct($node) {
    if (!is_object($node) || !empty($node->is_new) || empty($node->nid) || $node->type !== 'opendata_meta') {
      return FALSE;
    }

    $user = user_load($node->uid);

    $this->inn = !empty($user->field_inn_10) ? $user->field_inn_10[LANGUAGE_NONE]['0']['value'] : FALSE;
    $this->node = $node;

    $this->set_fields();

    return $this;
  }

  private function set_fields() {
    $fields = array();

    // Name.
    $inn = $this->inn;
    $name = !empty($this->node->field_odmeta_id) ? $this->node->field_odmeta_id[LANGUAGE_NONE]['0'] : FALSE;
    $fields['name'] = array(
      'label' => 'Идентификационный номер',
      'predicate' => 'dc:identifier',
      'value' => $inn . '-' . $name['value'],
      'render' => $inn . '-' . $name['value'],
    );

    // Title.
    $title = !empty($this->node->field_odmeta_name) ? $this->node->field_odmeta_name[LANGUAGE_NONE]['0'] : FALSE;
    $fields['title'] = array(
      'label' => 'Наименование набора данных',
      'predicate' => 'dc:title',
      'value' => $title['value'],
      'render' => $title['value'],
    );

    // Description.
    $description = !empty($this->node->field_odmeta_description) ? $this->node->field_odmeta_description[LANGUAGE_NONE]['0'] : FALSE;
    $fields['description'] = array(
      'label' => 'Описание набора данных',
      'predicate' => 'dc:description',
      'value' => $description['value'],
      'render' => $description['value'],
    );

    // Owner.
    $owner = !empty($this->node->field_odmeta_owner) ? $this->node->field_odmeta_owner[LANGUAGE_NONE]['0'] : FALSE;
    $fields['owner'] = array(
      'label' => 'Владелец набора данных',
      'predicate' => 'dc:creator',
      'value' => $owner['value'],
      'render' => $owner['value'],
    );

    // Created.
    $created = !empty($this->node->field_odmeta_created) ? $this->node->field_odmeta_created[LANGUAGE_NONE]['0'] : FALSE;
    $fields['created'] = array(
      'label' => 'Дата первой публикации набора данных',
      'predicate' => 'dc:created',
      'value' => format_date(strtotime($created['value']), 'year_month_date'),
      'render' => format_date(strtotime($created['value']), 'year_month_date'),
    );

    // Valid.
    $valid = !empty($this->node->field_odmeta_valid) ? $this->node->field_odmeta_valid[LANGUAGE_NONE]['0'] : FALSE;
    $fields['valid'] = array(
      'label' => 'Периодичность актуализации набора данных',
      'predicate' => 'dc:valid',
      'value' => $valid['value'],
      'render' => $valid['value'],
    );

    // Subject.
    $subject = !empty($this->node->field_odmeta_subject) ? $this->node->field_odmeta_subject[LANGUAGE_NONE]['0'] : FALSE;
    $fields['subject'] = array(
      'label' => 'Ключевые слова, соответствующие содержанию набора данных',
      'predicate' => 'dc:subject',
      'value' => $subject['value'],
      'render' => $subject['value'],
    );

    $this->fields = $fields;
  }

  public function get_node() {
    return $this->node;
  }

  public function get_fields() {
    return $this->fields;
  }
}

class OpendataPublisher {
  private $node;
  private $fields;

  public function __construct($node) {
    if (!is_object($node) || !empty($node->is_new) || empty($node->nid) || $node->type !== 'opendata_publisher') {
      return FALSE;
    }

    $this->node = $node;

    $this->set_fields();

    return $this;
  }

  private function set_fields() {
    $fields = array();

    // Name.
    $name = !empty($this->node->field_odpublisher_name) ? $this->node->field_odpublisher_name[LANGUAGE_NONE]['0'] : FALSE;
    $fields['name'] = array(
      'label' => 'Имя',
      'predicate' => 'foaf:name',
      'value' => $name['value'],
      'render' => $name['value'],
    );

    // Phone.
    $phone = !empty($this->node->field_odpublisher_phone) ? $this->node->field_odpublisher_phone[LANGUAGE_NONE]['0'] : FALSE;
    $fields['phone'] = array(
      'label' => 'Телефон',
      'predicate' => 'foaf:phone',
      'value' => '+7' . $phone['number'],
      'render' => '+7' . $phone['number'],
    );

    // Mail.
    $mail = !empty($this->node->field_odpublisher_mail) ? $this->node->field_odpublisher_mail[LANGUAGE_NONE]['0'] : FALSE;
    $fields['mail'] = array(
      'label' => 'Электронная почта',
      'predicate' => 'foaf:mbox',
      'value' => $mail['email'],
      'render' => $mail['email'],
    );

    $this->fields = $fields;
  }

  public function get_node() {
    return $this->node;
  }

  public function get_fields() {
    return $this->fields;
  }
}

class OpendataStructure {
  private $node;
  private $fields;

  public function __construct($node) {
    if (!is_object($node) || !empty($node->is_new) || empty($node->nid) || $node->type !== 'opendata_structure') {
      return FALSE;
    }

    $this->node = $node;

    $this->set_fields();

    return $this;
  }

  private function set_fields() {
    $fields = array();

    // Source.
    $source = !empty($this->node->field_odstructure_source) ? $this->node->field_odstructure_source[LANGUAGE_NONE]['0'] : FALSE;
    $fields['source'] = array(
      'label' => 'Ссылка',
      'predicate' => 'dc:source',
      'value' => $source['url'],
      'render' => l($source['title'], $source['url']),
    );

    // Format.
    $format = !empty($this->node->field_odstructure_format) ? $this->node->field_odstructure_format[LANGUAGE_NONE]['0'] : FALSE;
    $fields['format'] = array(
      'label' => 'Формат',
      'predicate' => 'dc:format',
      'value' => $format['value'],
      'render' => $format['value'],
    );

    // Created.
    $created = !empty($this->node->field_odstructure_created) ? $this->node->field_odstructure_created[LANGUAGE_NONE]['0'] : FALSE;
    $fields['created'] = array(
      'label' => 'Дата создания',
      'predicate' => 'dc:created',
      'value' => format_date(strtotime($created['value']), 'year_month_date'),
      'render' => format_date(strtotime($created['value']), 'year_month_date'),
    );

    $this->fields = $fields;
  }

  public function get_node() {
    return $this->node;
  }

  public function get_fields() {
    return $this->fields;
  }
}

class OpendataData {
  private $node;
  private $fields;
  private $structure;

  public function __construct($node) {
    if (!is_object($node) || !empty($node->is_new) || empty($node->nid) || $node->type !== 'opendata_data') {
      return FALSE;
    }

    $this->node = $node;

    $this->set_fields();
    $this->set_structure();

    return $this;
  }

  private function set_fields() {
    $fields = array();

    // Source.
    $source = !empty($this->node->field_oddata_source) ? $this->node->field_oddata_source[LANGUAGE_NONE]['0'] : FALSE;
    $fields['source'] = array(
      'label' => 'Ссылка',
      'predicate' => 'dc:source',
      'value' => $source['url'],
      'render' => l($source['title'], $source['url']),
    );

    // Format.
    $format = !empty($this->node->field_oddata_format) ? $this->node->field_oddata_format[LANGUAGE_NONE]['0'] : FALSE;
    $fields['format'] = array(
      'label' => 'Формат',
      'predicate' => 'dc:format',
      'value' => $format['value'],
      'render' => $format['value'],
    );

    // Created.
    $created = !empty($this->node->field_oddata_created) ? $this->node->field_oddata_created[LANGUAGE_NONE]['0'] : FALSE;
    $fields['created'] = array(
      'label' => 'Дата создания',
      'predicate' => 'dc:created',
      'value' => format_date(strtotime($created['value']), 'year_month_date'),
      'render' => format_date(strtotime($created['value']), 'year_month_date'),
    );

    // Changes.
    $changes = !empty($this->node->field_oddata_changes) ? $this->node->field_oddata_changes[LANGUAGE_NONE]['0'] : FALSE;
    $fields['changes'] = array(
      'label' => 'Содержание изменений',
      'predicate' => 'dc:provenance',
      'value' => $changes['value'],
      'render' => $changes['value'],
    );

    $this->fields = $fields;
  }

  public function get_node() {
    return $this->node;
  }

  private function set_structure() {
    $this->structure = !empty($this->node->field_oddata_structure) ? $this->node->field_oddata_structure[LANGUAGE_NONE]['0']['target_id'] : FALSE;
  }

  public function get_structure() {
    return $this->structure;
  }

  public function get_fields() {
    return $this->fields;
  }
}

class OpendataList {
  private $nodes;
  private $opendata_list;

  public function __construct($nodes) {
    if (!is_array($nodes)) {
      return FALSE;
    }

    $this->nodes = $nodes;
    $this->get_opendata_list();

    return $this;
  }

  private function get_opendata_list() {
    foreach ($this->nodes as $node) {
      $opendata_meta = new Opendata($node);
      if ($opendata_meta) {
        $this->opendata_list[$node->nid] = $opendata_meta;
      }
    }
  }

  public function render() {
    $opendata_list_content = '';

    // Init variables.
    $table = array();
    $header = array();
    $rows = array();
    $attributes = array();
    $i = 0;

    // Build opendata header.
    $header[] = array(
      'data' => '№',
    );
    $header[] = array(
      'data' => 'Название набора данных',
    );

    // Build rows.
    foreach ($this->opendata_list as $opendata_meta) {
      // Init variables.
      $cols = array();
      $href = $opendata_meta->get_uri();
      $opendata_meta_fields = $opendata_meta->get_fields();

      // Get opendata meta title.
      $title = $opendata_meta_fields['title']['value'];

      // Increase fields counter.
      $i++;

      // Add columns.
      $cols[] = array(
        'data' => $i,
      );

      $cols[] = array(
        'data' => l($title, $href),
        'typeof' => 'foaf:Document',
        'about' => '/' . $href,
        'property' => 'dc:title',
        'content' => $title,
      );

      $rows[] = array(
        'data' => $cols,
        'rel' => 'dc:hasPart',
        'resource' => '/' . $href,
      );
    }

    $table['header'] = $header;
    $table['rows'] = $rows;
    $table['attributes'] = $attributes;
    $table['sticky'] = FALSE;

    $opendata_list_table = theme('table', $table);

    $opendata_list_content .= '';
    $opendata_list_content .= '<div typeof="dc:Collection" about="/opendata">' . "\n";
    $opendata_list_content .= '<div rel="dc:conformsTo" resource="http://opendata.gosmonitor.ru/standard/2.3"></div>' . "\n";
    $opendata_list_content .= $opendata_list_table;
    $opendata_list_content .= '</div>' . "\n";

    return $opendata_list_content;
  }
}
