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
  $node = node_load($nid);
  $node_wrapper = entity_metadata_wrapper('node', $node);

  //заполняем строки паспорт набора данными
  $rows = array();
  $rows['field_dataset_id'] = array(t('Identification number'), $node_wrapper->field_dataset_id->value());
  $rows['title'] = array(t('Dataset title'), $node_wrapper->title->value());
  $rows['body'] = array(t('Dataset description'), $node_wrapper->body->value->value(array('decode' => TRUE)));
  $rows['field_owner'] = array(t('Dataset owner'), $node_wrapper->field_owner->value());
  $rows['field_contact_name'] = array(t('Responsible person'), $node_wrapper->field_contact_name->value()? $node_wrapper->field_contact_name->value() : t('No info'));
  $rows['field_email_responsible'] = array(t('Responsible person email'), $node_wrapper->field_email_responsible->value() ? $node_wrapper->field_email_responsible->value() : t('No info'));
  
  //Гиперссылка(URL) на набор (Link file + Link API + Upload)
  $url_datasets = array();
  $resource = $node_wrapper->field_resources;
  
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
  $url_datasets_string = implode('<br />', $url_datasets);
  $rows['dataset_urls'] = array(t('Dataset URL'),  $url_datasets_string ? $url_datasets_string : t('No info'));
  $rows['field_format'] = array(t('Dataset format'),  $resource->field_format->value() ? $resource->field_format->value()->name : t('No info'));
  
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

  $url_datasets_structure_string = implode('<br />', $url_datasets_structure);
  $rows['dataset_urls_structure'] = array(t('Hyperlink (URL) on the dataset structure'),  $url_datasets_structure_string ? $url_datasets_structure_string : t('No info'));
  
  $rows['field_date_first_time_publ'] = array(t('Date of first publication'), date("d.m.Y", $node_wrapper->field_date_first_time_publ->value()));
  $rows['field_date_last_change'] = array(t('Date of last update'), $node_wrapper->field_date_last_change->value() ? date("d.m.Y", $node_wrapper->field_date_last_change->value()) : t('No info'));
  $rows['field_date_dataset_actual'] = array(t('Date relevance dataset'), $node_wrapper->field_date_dataset_actual->value() ? date("d.m.Y", $node_wrapper->field_date_dataset_actual->value()) : t('No info'));
  $rows['field_frequency'] = array(t('Frequency of updating'), $node_wrapper->field_frequency->value() ? $node_wrapper->field_frequency->value() : t('No info'));
  $rows['field_content_last_change'] = array(t('Content of the latter changes'), $node_wrapper->field_content_last_change->value() ? $node_wrapper->field_content_last_change->value() : t('No info'));
  
  //Получаем список ключевых слов набора.
  $keywords = array();
  foreach ($node_wrapper->field_tags as $term) {
    // $term_wrapper may now be accessed as a taxonomy term wrapper.
    $keywords[] = $term->name->value();
  }
  $keywords_string = implode(", ", $keywords);
  $rows['field_tags'] = array(t('Keywords'), $keywords_string ? $keywords_string : t('No info'));
  
  
  //Гиперссылки (URL) на версии набора данных (Link file + Link API + Upload)
  //Гиперссылки (URL) на версии структуры набора данных (field_link_structure_file + field_upload_structure) 
  $resource_revisions = node_revision_list($resource->value());
  $url_datasets_revisions = array(); //Массив URL версий набора
  $url_datasets_structure_revisions = array(); //Массив URL структур набора
  foreach ($resource_revisions as $revision) {
    $revision_object = entity_metadata_wrapper('node', node_load($resource->nid->value(), $revision->vid));
    
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
  $url_datasets_string_revisions = implode('<br />', $url_datasets_revisions);
  $rows['dataset_urls_revisions'] = array(t('Hyperlink (URL) on the dataset versions'),  $url_datasets_string_revisions ? $url_datasets_string_revisions : t('No info'));
    
  $url_datasets_structure_string_revisions = implode('<br />', $url_datasets_structure_revisions);
  $rows['dataset_urls_structure_revisions'] = array(t('Hyperlink (URL) on the dataset structure versions'),  $url_datasets_structure_string_revisions ? $url_datasets_structure_string_revisions : t('No info'));

  $block = new stdClass();
  $block->title = t('Dataset passport');
  $header = array(t('Field name passport'), t('Field value'));
  $block->content =  theme('table', array('header' => $header, 'rows' => $rows));

  return $block;
}
