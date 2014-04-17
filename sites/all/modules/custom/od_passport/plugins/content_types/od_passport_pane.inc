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
  try {
    $rendered = od_passport_render(intval($args[0]));
  }
  catch (Exception $e) {
    $rendered = NULL;
    watchdog_exception('od_passport', $e);
  }

  return $rendered;
}

function od_passport_render($nid, $options = array()) {
  //Формируем блок и выводим в виде таблицы с атрибутами.
  //По у молчанию подсказки в ячейках таблицы паспорта включены
  $default_options = array(
    'addtip' => TRUE,
  );
  $options += $default_options;

  $rows =  _passport_table_rows($nid, $options);
  $structure = _passport_structured_description($nid);
  $table_attributes = array(
  'about' => "/" . drupal_get_path_alias(),
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
     'about' =>  "/" . drupal_get_path_alias(),
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
function _passport_table_rows($nid, $options = array()) {
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $resource = $node_wrapper->field_resources; // Получаем ресурс из паспорта.
  $resource = $resource->get(0);
  $rows = array();
  
  //Идентификатор
  $data = array(
    'data' => $node_wrapper->field_dataset_id->value(), 
    'property' => 'dc:identifier',
  );

  $label = '<span class="label">' . t('Identification number') . '</span>';
  if ($options['addtip']) {
    $label_tip = '<span class="info-tooltip" title="';
    $label_tip .= t('UNIQUE CODE OF THE DATASET. CODE CONSISTS OF THE TIN ORGANIZATION-OWNER AND THE ENGLISH-LANGUAGE NAME OF THE DATASET.');
    $label_tip .=  '">?</span>';
    $label .= $label_tip;
  }

  $rows['field_dataset_id'] = array('<div class="label">' . $label  . '</div>', $data);
  
  //Наименование набора данных
  $data = array(
    'data' => $node_wrapper->title->value(), 
    'property' => 'dc:title',
  );
  $rows['title'] = array('<div class="label"><span class="label">' . t('Dataset title')  . '</span></div>', $data);
  
  //Описание набора данных
  $data = array(
    'data' => '',
    'property' => 'dc:description',
  );

  if ($value = $node_wrapper->field_dataset_body->value(array('decode' => TRUE))) {
    $data['data'] = $value['value'];
  }

  $rows['field_dataset_body'] = array('<div class="label"><span class="label">' . t('Dataset description')  . '</span></div>', $data);
  
  //Владелец набора данных
  $data = array(
    'data' => $node_wrapper->field_owner->value(), 
    'property' => 'dc:creator',
  );

  $label = '<span class="label">' . t('Dataset owner') . '</span>';
  if ($options['addtip']) {
    $label_tip = '<span class="info-tooltip" title="';
    $label_tip .= t('ORGANIZATION - THE OWNER OF THE DATASET, WHICH HAS ADDED INFORMATION IN THE FORM OF OPEN DATA');
    $label_tip .=  '">?</span>';
    $label .= $label_tip;
  }

  $rows['field_owner'] = array('<div class="label">' . $label  . '</div>', $data);
  
  //Ответственное лицо
  $value = $node_wrapper->field_contact_name->value();
  $html_span = "<span rel='dc:publisher' typeof='foaf:Person' about='#publisher' property='foaf:name'>$value</span>";
  $data = array(
    'data' => !empty($value) ? $html_span : t('No info'),
    'rel' => 'dc:publisher',
    'resource' => '#publisher',
  );

  $label = '<span class="label">' . t('Responsible person') . '</span>';
  if ($options['addtip']) {
    $label_tip = '<span class="info-tooltip" title="';
    $label_tip .= t('OFFICIAL REPRESENTATIVE IS RESPONSIBLE FOR REPRESENTATION OF AN ORGANIZATION-OWNER OF THE DATASET.');
    $label_tip .=  '">?</span>';
    $label .= $label_tip;
  }

  $rows['field_contact_name'] = array('<div class="label">' . $label  . '</div>', $data);
  
  //Телефон ответственного лица
  $value = $node_wrapper->field_contact_phone->value();
  $html_span = "<span typeof='foaf:Person' about='#publisher' property='foaf:phone' content=\"$value\">$value</span>";
  $html_span_no_info = "<span typeof='foaf:Person' about='#publisher' property='foaf:phone' content='no info'>" . t('No info') . "</span>";
  $data = array(
    'data' => isset($value) ? $html_span : $html_span_no_info,
    'rel' => 'dc:publisher',
    'resource' => '#publisher',
  );
  $rows['field_contact_phone'] = array('<div class="label"><span class="label">' . t('Phone number of responsible person')  . '</span></div>', $data);

  //Адрес электронной почты ответсвенного лица
  $value = $node_wrapper->field_email_responsible->value();
  $html_span = "<span typeof='foaf:Person' about='#publisher' property='foaf:mbox'>$value</span>";
  $html_span_no_info = "<span typeof='foaf:Person' about='#publisher' property='foaf:mbox'>" . t('No info') . "</span>";
  $data = array(
    'data' => isset($value) ? $html_span : $html_span_no_info,
    'rel' => 'dc:publisher',
    'resource' => '#publisher',
  );
  $rows['field_email_responsible'] = array('<div class="label"><span class="label">' . t('Responsible person email')  . '</span></div>', $data);

  //Гиперссылка(URL) на набор (Link file + Link API + Upload)
  // формируем массив ссылок из трех полей. По логике должно быть заполнено только одно из них.
  if ($resource->value()) {
    $uri = od_dataset_download_path($node);

    $label = '<span class="label">' . t('Dataset URL') . '</span>';
    if ($options['addtip']) {
      $label_tip = '<span class="info-tooltip" title="';
      $label_tip .= t('HYPERLINK TO THE LATEST VERSION OF THE DATASET.');
      $label_tip .=  '">?</span>';
      $label .= $label_tip;
    }

    $rows['dataset_urls'] = array('<div class="label">' . $label  . '</div>', $uri ? l(url($uri, array('absolute' => true)), url($uri, array('absolute' => true))) : t('No info'));
    
    //Формат данных
    $value = $resource->field_format->value()->name;
    $data = array(
      'data' => isset($value) ? $value : t('No info'),
      'property' => 'dc:format',
      'content' => isset($value) ? $value : t('No info'),
    );

    $label = '<span class="label">' . t('Dataset format') . '</span>';
    if ($options['addtip']) {
      $label_tip = '<span class="info-tooltip" title="';
      $label_tip .= t('THE COMPUTER-READABLE FORMAT, IN WHICH THE LATEST VERSION OF THE DATASET WAS PUBLISHED.');
      $label_tip .=  '">?</span>';
      $label .= $label_tip;
    }

    $rows['field_format'] = array('<div class="label">' . $label  . '</div>', $data);
  
  
    //Описание структуры набора данных
    $uri = od_dataset_download_path($node, NULL,'structure');
    $data = array(
      'data' =>  $uri ? l(url($uri, array('absolute' => true)), url($uri, array('absolute' => true))) : t('No info'),
    );

    $label = '<span class="label">' . t('Hyperlink (URL) on the dataset structure') . '</span>';
    if ($options['addtip']) {
      $label_tip = '<span class="info-tooltip" title="';
      $label_tip .= t('HYPERLINK TO THE LATEST VERSION OF THE FILE STRUCTURE OF THE DATASET - A SET OF OPEN FIELD DESCRIPTION DATA IN MACHINE-READABLE FORMAT.');
      $label_tip .=  '">?</span>';
      $label .= $label_tip;
    }

    $rows['dataset_urls_structure'] = array('<div class="label">' . $label  . '</div>',  $data);
 }
  
  //Дата первой публикации набора данных
  $data = array(
    'data' => date("d.m.Y", $node_wrapper->field_date_first_time_publ->value()),
    'property' => 'dc:created',
    'content' => date("d-m-Y", $node_wrapper->field_date_first_time_publ->value()),
  );

  $label = '<span class="label">' . t('Date of first publication') . '</span>';
  if ($options['addtip']) {
    $label_tip = '<span class="info-tooltip" title="';
    $label_tip .= t('DATE OF FIRST PUBLICATION IN THE ORIGINAL SET.');
    $label_tip .=  '">?</span>';
    $label .= $label_tip;
  }

  $rows['field_date_first_time_publ'] = array('<div class="label">' . $label  . '</div>', $data);
  
  //Дата последнего внесения изменений
  $value = $node_wrapper->field_date_last_change->value();
  $data = array(
    'data' => isset($value) ? date("d.m.Y", $node_wrapper->field_date_last_change->value()) : t('No info') ,
    'property' => 'dc:modified',
    'content' => date("d-m-Y", $node_wrapper->field_date_last_change->value()),
  );
  $rows['field_date_last_change'] = array('<div class="label"><span class="label">' . t('Date of last update')  . '</span></div>', $data);
  
  //Дата актуальности набора
  $value = $node_wrapper->field_date_dataset_actual->value();
  $data = array(
    'data' => isset($value) ? date("d.m.Y", $node_wrapper->field_date_dataset_actual->value()) : t('No info'),
  );

  $label = '<span class="label">' . t('Date relevance dataset') . '</span>';
  if ($options['addtip']) {
    $label_tip = '<span class="info-tooltip" title="';
    $label_tip .= t('THE DATE AFTER WHICH NEEDS TO BE UPDATED THE CURRENT VERSION OF THE DATASET.');
    $label_tip .=  '">?</span>';
    $label .= $label_tip;
  }

  $rows['field_date_dataset_actual'] = array('<div class="label">' . $label  . '</div>', $data);
  
  //Периодичность актуализации набора данных
  $value = $node_wrapper->field_frequency->value();
  $data = array(
    'data' => isset($value) ? $value : t('No info'),
    'property' => 'dc:valid',
    'content' =>  isset($value) ? $value : t('No info'),
  );

  $label = '<span class="label">' . t('Frequency of updating') . '</span>';
  if ($options['addtip']) {
    $label_tip = '<span class="info-tooltip" title="';
    $label_tip .= t('INFORMATION ON HOW FREQUENTLY UPDATED THE DATASET');
    $label_tip .=  '">?</span>';
    $label .= $label_tip;
  }

  $rows['field_frequency'] = array('<div class="label">' . $label  . '</div>', $data);
  
  //Содержание последнего изменения
  if ($resource->value()) {
    $value = $resource->field_provenance->value();
    $data = array(
      'data' => isset($value) ? $value : t('No info'),
    );

    $label = '<span class="label">' . t('Content of the latter changes') . '</span>';
    if ($options['addtip']) {
      $label_tip = '<span class="info-tooltip" title="';
      $label_tip .= t('THE LIST OF SPECIFIC CHANGES TO THE LATEST VERSION OF THE DATASET.');
      $label_tip .=  '">?</span>';
      $label .= $label_tip;
    }

    $rows['field_content_last_change'] = array('<div class="label">' . $label  . '</div>', $data);
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
  $rows['field_tags'] = array('<div class="label"><span class="label">' . t('Keywords')  . '</span></div>', $data);
  
  
  //Гиперссылки (URL) на версии набора данных (Link file + Link API + Upload)
  //Гиперссылки (URL) на версии структуры набора данных (field_link_structure_file + field_upload_structure)
  if ($resource->value()) {
    $dataset_revisions = node_revision_list($node);
    //dpm($dataset_revisions);
    //dpm($node);
    $url_data = array();
    $url_structure = array();
    foreach ($dataset_revisions as $revision) {
      $revision_object = entity_metadata_wrapper('node', node_load($node->nid, $revision->vid));
      if($revision->vid != $node->vid) {
        $url_data[] = od_dataset_download_path($node, $revision->vid,'data')->__toString();
        $url_structure[] = od_dataset_download_path($node, $revision->vid,'structure')->__toString();
      }
    }

    $url_data= array_unique($url_data);
    $url_structure = array_unique($url_structure);

    //Гиперссылки (URL) на версии набора данных
    foreach ($url_data as $key=>$url) {
      $url_datasets_revisions[$key] = '<li>' . l(url($url, array('absolute' => true)), url($url, array('absolute' => true))) . '</li>';
    }
    $url_datasets_string_revisions = implode('', $url_datasets_revisions);
    $url_datasets_string_revisions_list = "<ul>$url_datasets_string_revisions</ul>";
    $data = array(
      'data' => !empty($url_datasets_string_revisions) ? $url_datasets_string_revisions_list : t('No info'),
    );

    $label = '<span class="label">' . t('Hyperlink (URL) on the dataset versions') . '</span>';
    if ($options['addtip']) {
      $label_tip = '<span class="info-tooltip" title="';
      $label_tip .= t('HYPERLINKS TO PREVIOUS VERSIONS OF THE DATASET (IF THEY HAS BEEN CHANGED)');
      $label_tip .=  '">?</span>';
      $label .= $label_tip;
    }

    $rows['dataset_urls_revisions'] = array('<div class="label">' . $label  . '</div>',  $data);
    
    //Гиперссылки (URL) на версии структуры набора данных	
    foreach ($url_structure as $key=>$url) {
      $url_datasets_structure_revisions[$key] = '<li>' . l(url($url, array('absolute' => true)), url($url, array('absolute' => true))) . '</li>';
    }
    $url_datasets_structure_string_revisions = implode('', $url_datasets_structure_revisions);
    $url_datasets_structure_revisions_list = "<ul>$url_datasets_structure_string_revisions</ul>";
    $data = array(
      'data' => !empty($url_datasets_structure_string_revisions) ? $url_datasets_structure_revisions_list : t('No info'),
    );

    $label = '<span class="label">' . t('Hyperlink (URL) on the dataset structure versions') . '</span>';
    if ($options['addtip']) {
      $label_tip = '<span class="info-tooltip" title="';
      $label_tip .= t('HYPERLINKS OF PREVIOUS VERSIONS OF THE STRUCTURE OF THE DATA SET (IF THEY HAS BEEN CHANGED).');
      $label_tip .=  '">?</span>';
      $label .= $label_tip;
    }

    $rows['dataset_urls_structure_revisions'] = array('<div class="label">' . $label  . '</div>', $data);
  }  
  return $rows;
}


function _passport_structured_description($nid) {
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $resource = $node_wrapper->field_resources; // Получаем ресурс из паспорта.
  $resource = $resource->get(0);

  $dataset_revisions = node_revision_list($node);


  $first_revision = end($dataset_revisions); //Самая первая версия набора
  $url_datasets_revisions = array();
  if ($resource->value()) {
      foreach ($dataset_revisions as $key => $revision) {
        $revision_object = entity_metadata_wrapper('node', node_load($node->nid, $revision->vid));
        $revision_object_resource = $revision_object->field_resources; // Получаем ресурс из паспорта.
        $revision_object_resource = $revision_object_resource->get(0);

        $revision_date = date("Ymd\THi", $revision->timestamp);
        $revision_date_iso = date("Y-m-d", $revision->timestamp);
        //Информация о последнем изменении в паспорте
        if ($revision_object_resource->field_provenance->value()) {
          $revision_provenence = $revision_object_resource->field_provenance->value();
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
        $url_datasets_revisions[$key]['uri'] = url(od_dataset_download_path($node, $revision->vid,'data')->__toString(),array('absolute' => true));
        $url_datasets_revisions[$key]['structure'] = url(od_dataset_download_path($node, $revision->vid,'structure')->__toString(),array('absolute' => true));;

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
