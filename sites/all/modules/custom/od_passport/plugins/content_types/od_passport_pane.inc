<?php

$plugin = array(
  'title' => t('Opendata passport'),
  'single' => TRUE,
  'category' => t('Dataset'),
  'edit form' => 'od_passport_pane_content_type_edit_form',
  'render callback' => 'od_passport_pane_content_type_render',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'all contexts' => TRUE,
);

/**
 * 'Edit form' callback for the content type.
 */
function od_passport_pane_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function od_passport_pane_content_type_edit_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}

/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function od_passport_pane_content_type_render($subtype, $conf, $args, $contexts) {
  $nid = $args[0];
  return od_passport_render($nid);
}

function od_passport_render($nid) {
  //Формируем блок и выводим в виде таблицы с атрибутами.
  $rows =  _passport_table_rows($nid);
  $structure = _passport_structured_description($nid);
  $table_attributes = array(
  'about' => "/" . _current_prefix() . "/" . drupal_get_path_alias(),
  'typeof' => 'foaf:Document'
  );
  $block = new stdClass();
  $block->title = t('Dataset passport');
  $header = array(t('Field name passport'), t('Field value'));
  $block->content = array();
  
  //Таблица паспорта
  $block->content['passport_table'] = array(
   '#type' => 'container',
   '#attributes' => array(
     'about' => "/" . _current_prefix() . "/" . drupal_get_path_alias(),
     'typeof' => 'foaf:Document',
   ),
    'sub_div' => array(
      'div_1' => array(
        '#type' => 'markup',
        '#markup' => "<div rel='dc:conformsTo' resource='http://opendata.gosmonitor.ru/standard/3.0'></div>",
      ),
      'passport' => array(
        '#markup' =>  theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => $table_attributes)),
      ),
      'div_2' => array(
        '#type' => 'markup',
        '#markup' => "<div rel='dc:source' resource='#data'></div>",
      ),
    ),
    //Rdf-описание структуры паспорта.
    'passport_versions' => array(
      '#type' => 'container',
      '#attributes' => array(
        'typeof' => 'dc:Collection',
        'about' => '#data',
        'class' => 'dataset-files',
      ),
      'sub_divs' => isset($structure) ? array($structure['div_versions']) : NULL,
    ),
    'passport_structures' => array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => 'structure-files',
      ),
      'sub_divs' => isset($structure) ? array($structure['div_structures']) : NULL,
    ),
  );
  return $block;
}




/**
 * Формируем таблицу паспорта
 */
function _passport_table_rows($nid) {
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $resource = $node_wrapper->field_resources; // Получаем ресурс из паспорта.
  $rows = array();
  
  //Идентификатор
  $data = array(
    'data' => $node_wrapper->field_dataset_id->value(), 
    'property' => 'dc:identifier',
  );
  $rows['field_dataset_id'] = array(t('Identification number'), $data);
  
  //Наименование набора данных
  $data = array(
    'data' => $node_wrapper->title->value(), 
    'property' => 'dc:title',
  );
  $rows['title'] = array(t('Dataset title'), $data);
  
  //Описание набора данных
  $data = array(
    'data' => $node_wrapper->body->value->value(array('decode' => TRUE)), 
    'property' => 'dc:description',
  );
  $rows['body'] = array(t('Dataset description'), $data);
  
  //Владелец набора данных
  $data = array(
    'data' => $node_wrapper->field_owner->value(), 
    'property' => 'dc:creator',
  );
  $rows['field_owner'] = array(t('Dataset owner'), $data);
  
  //Ответственное лицо
  $value = $node_wrapper->field_contact_name->value();
  $html_span = "<span rel='dc:publisher' typeof='foaf:Person' about='#publisher' property='foaf:name'>$value</span>";
  $data = array(
    'data' => !empty($value) ? $html_span : t('No info'),
    'rel' => 'dc:publisher',
    'resource' => '#publisher',
  );
  $rows['field_contact_name'] = array(t('Responsible person'), $data);
  
  //Телефон ответственного лица
  $value = $node_wrapper->field_contact_phone->value();
  $html_span = "<span typeof='foaf:Person' about='#publisher' property='foaf:phone' content=\"$value\">$value</span>";
  $html_span_no_info = "<span typeof='foaf:Person' about='#publisher' property='foaf:phone' content='no info'>" . t('No info') . "</span>";
  $data = array(
    'data' => isset($value) ? $html_span : $html_span_no_info,
    'rel' => 'dc:publisher',
    'resource' => '#publisher',
  );
  $rows['field_contact_phone'] = array(t('Phone number of responsible person'), $data);

  //Адрес электронной почты ответсвенного лица
  $value = $node_wrapper->field_email_responsible->value();
  $html_span = "<span typeof='foaf:Person' about='#publisher' property='foaf:mbox'>$value</span>";
  $html_span_no_info = "<span typeof='foaf:Person' about='#publisher' property='foaf:mbox'>" . t('No info') . "</span>";
  $data = array(
    'data' => isset($value) ? $html_span : $html_span_no_info,
    'rel' => 'dc:publisher',
    'resource' => '#publisher',
  );
  $rows['field_email_responsible'] = array(t('Responsible person email'), $data);

  //Гиперссылка(URL) на набор (Link file + Link API + Upload)
  $url_datasets = array();

  // формируем массив ссылок из трех полей. По логике должно быть заполнено только одно из них.
  if ($resource->value()) {
    if ($field_link_remote_file = $resource->field_link_remote_file->value()) {
    $url_datasets[] = $field_link_remote_file['uri'];
    }
    
    if ($field_link_api = $resource->field_link_api->value()) {  
    $url_datasets[] = $field_link_api['uri'];
    }
    
    if ($field_link_upload = $resource->field_upload) {
      if (isset($field_link_upload->value()->uri)) {
        $url_datasets[] = file_create_url($field_link_upload->value()->uri);
      }
    }
    foreach ($url_datasets as $key => $url) {
      $url_datasets[$key] = "<a href='$url'>$url</a>";
    }
    $data = array(
      'data' => implode('<br />', $url_datasets)
      );
    $rows['dataset_urls'] = array(t('Dataset URL'), !empty($data['data']) ? $data : t('No info'));
    
    //Формат данных
    $value = $resource->field_format->value()->name;
    $data = array(
      'data' => isset($value) ? $value : t('No info'),
      'property' => 'dc:format',
      'content' => isset($value) ? $value : t('No info'),
    );
    $rows['field_format'] = array(t('Dataset format'), $data);
  
  
    //Описание структуры набора данных
    $url_datasets_structure = array();
    
    if ($field_link_structure_file = $resource->field_link_structure_file->value()) {  
        $url_datasets_structure[] = $field_link_structure_file['uri'];
      }
    
    if ($field_upload_structure = $resource->field_upload_structure) {
      $field_upload_structure = $field_upload_structure->value();
      if (isset($field_upload_structure['uri'])) {
        $url_datasets_structure[] = file_create_url($field_upload_structure['uri']);
      }
    } 
  } 
  
  foreach ($url_datasets_structure as $key => $url) {
    $url_datasets_structure[$key] = "<a href='$url'>$url</a>";
  }
  $url_structure_string = implode('<br />', $url_datasets_structure);
  $data = array(
    'data' => !empty($url_structure_string) ? $url_structure_string : t('No info'),
  );
  $rows['dataset_urls_structure'] = array(t('Hyperlink (URL) on the dataset structure'),  $data);
  
  //Дата первой публикации набора данных
  $data = array(
    'data' => date("d.m.Y", $node_wrapper->field_date_first_time_publ->value()),
    'property' => 'dc:created',
    'content' => date("d-m-Y", $node_wrapper->field_date_first_time_publ->value()),
  );
  $rows['field_date_first_time_publ'] = array(t('Date of first publication'), $data);
  
  //Дата последнего внесения изменений
  $value = $node_wrapper->field_date_last_change->value();
  $data = array(
    'data' => isset($value) ? date("d.m.Y", $node_wrapper->field_date_last_change->value()) : t('No info') ,
    'property' => 'dc:modified',
    'content' => date("d-m-Y", $node_wrapper->field_date_last_change->value()),
  );
  $rows['field_date_last_change'] = array(t('Date of last update'), $data);
  
  //Дата актуальности набора
  $value = $node_wrapper->field_date_dataset_actual->value();
  $data = array(
    'data' => isset($value) ? date("d.m.Y", $node_wrapper->field_date_dataset_actual->value()) : t('No info'),
  );
  $rows['field_date_dataset_actual'] = array(t('Date relevance dataset'), $data);
  
  //Периодичность актуализации набора данных
  $value = $node_wrapper->field_frequency->value();
  $data = array(
    'data' => isset($value) ? $value : t('No info'),
    'property' => 'dc:valid',
    'content' =>  isset($value) ? $value : t('No info'),
  );
  $rows['field_frequency'] = array(t('Frequency of updating'), $data);
  
  //Содержание последнего изменения
  if ($resource->value()) {
    $value = $resource->field_provenance->value();
    $data = array(
      'data' => isset($value) ? $value : t('No info'),
    );
    $rows['field_content_last_change'] = array(t('Content of the latter changes'), $data);
  }
  
  //Ключевые слова
  $keywords = array();
  foreach ($node_wrapper->field_tags as $term) {
    // $term_wrapper may now be accessed as a taxonomy term wrapper.
    $keywords[] = $term->name->value();
  }
  $keywords_string = implode(", ", $keywords);
  
  $data = array(
    'data' => !empty($keywords_string) ? $keywords_string : t('No info'),
    'property' => 'dc:subject',
  );
  $rows['field_tags'] = array(t('Keywords'), $data);
  
  
  //Гиперссылки (URL) на версии набора данных (Link file + Link API + Upload)
  //Гиперссылки (URL) на версии структуры набора данных (field_link_structure_file + field_upload_structure) 
  if ($resource->value()) {
    $resource_revisions = node_revision_list($resource->value());
    $url_datasets_revisions = array();
    $url_datasets_structure_revisions = array();
    foreach ($resource_revisions as $revision) {
      $revision_object = entity_metadata_wrapper('node', node_load($resource->nid->value(), $revision->vid));
      if($revision->vid <> $resource->vid->value()) {
        if ($field_link_remote_file = $revision_object->field_link_remote_file->value()) {
          $url_datasets_revisions[] = $field_link_remote_file['uri'];
        }
      
        if ($field_link_api = $revision_object->field_link_api->value()) {  
          $url_datasets_revisions[] = $field_link_api['uri'];
        }
      
        if ($field_link_upload = $revision_object->field_upload) {
          if (isset($field_link_upload->value()->uri)) {
           $url_datasets_revisions[] = file_create_url($field_link_upload->value()->uri);
          }
        }

        if ($field_link_structure_file = $revision_object->field_link_structure_file->value()) {  
          $url_datasets_structure_revisions[] = $field_link_structure_file['uri'];
        }
      
        if ($field_upload_structure = $revision_object->field_upload_structure) {
          $field_upload_structure = $field_upload_structure->value();
          if (isset($field_upload_structure['uri'])) {
           $url_datasets_structure_revisions[] = file_create_url($field_upload_structure['uri']);
          }
        }  
      }  
    }
    
    $url_datasets_revisions= array_unique($url_datasets_revisions);
    $url_datasets_structure_revisions = array_unique($url_datasets_structure_revisions);
    //Гиперссылки (URL) на версии набора данных
    foreach ($url_datasets_revisions as $key=>$url) {
      $url_datasets_revisions[$key] = "<li><a href='$url'>$url</a></li>";
    }
    $url_datasets_string_revisions = implode('', $url_datasets_revisions);
    $url_datasets_string_revisions_list = "<ul>$url_datasets_string_revisions</ul>";
    $data = array(
      'data' => !empty($url_datasets_string_revisions) ? $url_datasets_string_revisions_list : t('No info'),
    );
    $rows['dataset_urls_revisions'] = array(t('Hyperlink (URL) on the dataset versions'),  $data);
    
    //Гиперссылки (URL) на версии структуры набора данных	
    foreach ($url_datasets_structure_revisions as $key=>$url) {
      $url_datasets_structure_revisions[$key] = "<li><a href='$url'>$url</a></li>";
    }  
    $url_datasets_structure_string_revisions = implode('<br />', $url_datasets_structure_revisions);
    $url_datasets_structure_string_revisions_list = "<ul>$url_datasets_structure_string_revisions</ul>";
    $data = array(
      'data' => !empty($url_datasets_structure_string_revisions) ? $url_datasets_structure_string_revisions_list : t('No info'),
    );
    $rows['dataset_urls_structure_revisions'] = array(t('Hyperlink (URL) on the dataset structure versions'), $data);
  }  
  return $rows;
}


function _passport_structured_description($nid) {
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $resource = $node_wrapper->field_resources; // Получаем ресурс из паспорта.
  $resource_revisions = node_revision_list($resource->value());
  $first_revision = end($resource_revisions); //Самая первая версия набора
  $url_datasets_revisions = array();
  if ($resource->value()) {
      foreach ($resource_revisions as $key => $revision) {
      $revision_object = entity_metadata_wrapper('node', node_load($resource->nid->value(), $revision->vid));
      $revision_date = date("Ymd\THi", $revision->timestamp);
      //dpm($revision_date, 'revision date');
      $revision_date_iso = date("Y-m-d", $revision->timestamp);
      //Информация о последнем изменении в паспорте
      if ($revision_object->field_provenance->value()) {
        $revision_provenence = $revision_object->field_provenance->value();
      } else {
        $revision_provenence = t('No info');
      }
      //если это первая версия набора, то записываем значения из полей паспорта
      if ($first_revision->vid == $revision->vid) {
        $revision_date = date("Ymd\THi", $node_wrapper->field_date_first_time_publ->value());
        $revision_date_iso = date("Y-m-d", $node_wrapper->field_date_first_time_publ->value());
        $revision_provenence = t('Date of first publication');
      }
       
      $url_datasets_revisions[$key]['date'] = $revision_date; 
      $url_datasets_revisions[$key]['date_iso'] = $revision_date_iso; 
      $url_datasets_revisions[$key]['field_content_last_change'] = $revision_provenence;  
      
      
      //ссылки на файлы наборов
      if ($field_link_remote_file = $revision_object->field_link_remote_file->value()) {
        $url_datasets_revisions[$key]['uri'] = $field_link_remote_file['uri'];
      }
    
      if ($field_link_api = $revision_object->field_link_api->value()) {  
        $url_datasets_revisions[$key]['uri'] = $field_link_api['uri'];
      }
    
      if ($field_link_upload = $revision_object->field_upload) {
        if (isset($field_link_upload->value()->uri)) {
          $url_datasets_revisions[$key]['uri'] = file_create_url($field_link_upload->value()->uri);
        }
      }
      
      //ссылки на структуру наборов
      if ($field_link_structure_file = $revision_object->field_link_structure_file->value()) {  
        $url_datasets_revisions[$key]['structure'] = $field_link_structure_file['uri'];
      }
    
      if ($field_upload_structure = $revision_object->field_upload_structure) {
        $field_upload_structure = $field_upload_structure->value();
        if (isset($field_upload_structure['uri'])) {
          $url_datasets_revisions[$key]['structure'] = file_create_url($field_upload_structure['uri']);
        }
      } 
      isset($url_datasets_revisions[$key]['structure']) ? $url_datasets_revisions[$key]['structure'] : $url_datasets_revisions[$key]['structure'] = NULL;
    }
    return _passport_markup_structured_description($url_datasets_revisions);
  }
  return NULL;
}

function _passport_markup_structured_description($dataset_data) {
  $divs_versions = array();
  $divs_structures = array();
  foreach ($dataset_data as $rev_id => $rev_value) {
    $date = $rev_value['date'];
    $date_iso = $rev_value['date_iso'];
    $uri = t('No info');
    if (isset($rev_value['uri'])) $uri = $rev_value['uri'];
    $provenance = $rev_value['field_content_last_change'];
    $structure = $rev_value['structure'];
    $structure_url = $structure ? "<div rel='dc:conformsTo' resource='#structure-$date'></div>" : '';
    //Структура наборов
    $divs_versions[$rev_id] = array('div' => array(
      '#type' => 'markup',
      '#markup' => "<div rel='dc:hasPart' resource='#data-$date'>
                      <div typeof='foaf:Document' about='#data-$date'>
                        <div property='dc:source' content='$uri'></div>
                        <div property='dc:created' content='$date_iso'></div>
                        <div property='dc:provenance' content='$provenance'></div>
                        $structure_url
                      </div>
                  </div>",
      ),            
    );
    //Структура файлов структуры 
    if ($structure) {
      $divs_structures[$rev_id] = array('div' => array(
      '#type' => 'markup',
      '#markup' => "<div typeof='foaf:Document' about='#structure-$date'>
                      <div property='dc:source' content='$structure'></div>
                      <div property='dc:created' content='$date_iso'></div>
                   </div>",
       ),
     );
    } 
  }
 $divs = array ('div_versions' => $divs_versions, 'div_structures' => $divs_structures);
 return $divs;
}

//определяем префикс языка
function _current_prefix() {
  global $language;
  return $language->language;
}
