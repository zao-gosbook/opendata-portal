<?php
/**
 * @file
 * nodes_breadcrumbs_pm_pages.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function nodes_breadcrumbs_pm_pages_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_blog|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_blog';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_comment',
    ),
    'author' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_thumbnail',
    ),
  );
  $export['comment|comment_node_blog|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_competition|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_competition';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_short',
    ),
    'author' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_thumbnail',
    ),
  );
  $export['comment|comment_node_competition|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_dataset|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_dataset';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_comment',
    ),
    'author' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_thumbnail',
    ),
  );
  $export['comment|comment_node_dataset|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|app|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'app';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|app|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'author' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'author',
    ),
    'post_date' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'ds_post_date_comment',
    ),
  );
  $export['node|blog|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog|search';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog';
  $ds_fieldsetting->view_mode = 'search';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|blog|search'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|blog|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'blog';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'conditions' => array(),
      ),
    ),
    'author' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'author',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_avatar-85x85',
    ),
  );
  $export['node|blog|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|competition|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'competition';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'dynamic_field' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:9:{s:5:"label";s:5:"title";s:9:"formatter";s:26:"competition_date_formatter";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:0:{}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:1;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:27:"node:field_competition_date";}',
        'load_terms' => 0,
      ),
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|competition|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dataset|table';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dataset';
  $ds_fieldsetting->view_mode = 'table';
  $ds_fieldsetting->settings = array(
    'dataset_table_1' => array(
      'weight' => '18',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:7:"context";a:1:{i:0;s:25:"argument_entity_id:node_1";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:35:"dataset-datasets_versions_structure";}',
        'load_terms' => 0,
      ),
    ),
    'dynamic_field' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:7:{s:4:"link";i:0;s:6:"markup";s:4:"none";s:2:"id";s:0:"";s:5:"class";s:0:"";s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:1;s:19:"override_title_text";s:0:"";}s:4:"type";s:10:"node_title";s:7:"subtype";s:10:"node_title";}',
        'load_terms' => 0,
      ),
    ),
    'dynamic_field_3' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:7:"context";a:1:{i:0;s:25:"argument_entity_id:node_1";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:33:"resources-actual_resource_version";}',
        'load_terms' => 0,
      ),
    ),
    'dynamic_field_4' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:7:"context";a:1:{i:0;s:25:"argument_entity_id:node_1";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:32:"resources-actual_resource_format";}',
        'load_terms' => 0,
      ),
    ),
    'dynamic_field_5' => array(
      'weight' => '10',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:7:"context";a:1:{i:0;s:25:"argument_entity_id:node_1";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:35:"resources-actual_resource_structure";}',
        'load_terms' => 0,
      ),
    ),
    'dynamic_field_6' => array(
      'weight' => '17',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:7:"context";a:1:{i:0;s:25:"argument_entity_id:node_1";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:30:"dataset-dataset_versions_files";}',
        'load_terms' => 0,
      ),
    ),
  );
  $export['node|dataset|table'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|dataset|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'dataset';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'dynamic_field_1' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:9:{s:5:"label";s:6:"hidden";s:9:"formatter";s:23:"text_summary_or_trimmed";s:11:"delta_limit";i:0;s:12:"delta_offset";s:1:"0";s:14:"delta_reversed";b:0;s:18:"formatter_settings";a:1:{s:11:"trim_length";s:3:"600";}s:7:"context";s:25:"argument_entity_id:node_1";s:14:"override_title";i:1;s:19:"override_title_text";s:0:"";}s:4:"type";s:12:"entity_field";s:7:"subtype";s:9:"node:body";}',
        'load_terms' => 0,
        'field_formatter_label' => '',
        'conditions' => array(),
      ),
    ),
    'resource_format' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 0,
        'title_wrapper' => '',
        'ctools' => 'a:3:{s:4:"conf";a:1:{s:7:"context";a:1:{i:0;s:25:"argument_entity_id:node_1";}}s:4:"type";s:11:"views_panes";s:7:"subtype";s:32:"resources-actual_resource_format";}',
        'load_terms' => 0,
        'conditions' => array(),
      ),
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'field_formatter_label' => '',
        'conditions' => array(),
      ),
    ),
  );
  $export['node|dataset|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|document|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'document';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|document|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|search';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'search';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_comment',
    ),
  );
  $export['node|event|search'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|forum|search';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'forum';
  $ds_fieldsetting->view_mode = 'search';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_comment',
    ),
  );
  $export['node|forum|search'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|idea|search';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'idea';
  $ds_fieldsetting->view_mode = 'search';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_comment',
    ),
  );
  $export['node|idea|search'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comments' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_comment',
    ),
  );
  $export['node|news|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|search';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'search';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_comment',
    ),
  );
  $export['node|news|search'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|news|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'news';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|news|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resource|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resource';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'cf_resource' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|resource|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'taxonomy_term|rubrics|rubric_icon_with_title';
  $ds_fieldsetting->entity_type = 'taxonomy_term';
  $ds_fieldsetting->bundle = 'rubrics';
  $ds_fieldsetting->view_mode = 'rubric_icon_with_title';
  $ds_fieldsetting->settings = array(
    'title_i18n' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['taxonomy_term|rubrics|rubric_icon_with_title'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function nodes_breadcrumbs_pm_pages_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cf_dataset_recommended';
  $ds_field->label = 'CF Dataset recommended';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'dataset|teaser';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
print token_replace(\'[node:field-dataset-standard]\', array(\'node\' => $node));
$string = token_replace(\'[node:field-dataset-standard]\', array(\'node\' => $node));
dpm($node);
/*if (token_replace(\'[node:field_dataset_standard]\', array(\'node\' => $node))) {
  print \'<div class="recommended-dataset">\' . t(\'Recommended\') . \'</div>\';
  print token_replace(\'[node:field_dataset_standard]\', array(\'node\' => $node));
}*/
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['cf_dataset_recommended'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'cf_resource';
  $ds_field->label = 'CF Resource';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'resource|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$resource = node_load(arg(1));
if(isset($resource->field_link_passport[\'und\'][0][\'url\'])) {
  $url_raw = $resource->field_link_passport[\'und\'][0][\'url\'];
  if (empty($resource->field_link_remote_file) && empty($resource->field_upload) && empty($resource->field_link_api)) {
    $string =  t(\'A set of open data does not comply with guidelines. Link to the data set on the site of its owner:\');
  } else {
    $string =  t(\'Link to the data set on the site of its owner:\');
  }
  print $string;
}
?> [node:field_link_passport]


',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['cf_resource'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dynamic_field';
  $ds_field->label = 'Dynamic field';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'resource|*
competition|teaser';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Например: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['dynamic_field'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dynamic_field_1';
  $ds_field->label = 'Dynamic field 1';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'dataset|teaser';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Например: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['dynamic_field_1'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'dynamic_field_2';
  $ds_field->label = 'Dynamic field 2';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'dataset|teaser';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Например: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['dynamic_field_2'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'resource_format';
  $ds_field->label = 'Формат данных';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'dataset|teaser';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Например: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['resource_format'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'title_i18n';
  $ds_field->label = 'Title i18n';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div>
  <div class="field-type-taxonomy-term-reference">
    <div class="field-name-title">
      <h2>[term:i18n-name]</h2>
    </div>
  </div>
</div>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['title_i18n'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function nodes_breadcrumbs_pm_pages_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_blog|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_blog';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'ds_user_picture',
      ),
      'right' => array(
        1 => 'post_date',
        2 => 'author',
        3 => 'comment_body',
        4 => 'links',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left',
      'post_date' => 'right',
      'author' => 'right',
      'comment_body' => 'right',
      'links' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_blog|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_competition|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_competition';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'ds_user_picture',
        1 => 'post_date',
        2 => 'author',
        3 => 'comment_body',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'ds_content',
      'post_date' => 'ds_content',
      'author' => 'ds_content',
      'comment_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_competition|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_dataset|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_dataset';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'ds_user_picture',
      ),
      'right' => array(
        1 => 'post_date',
        2 => 'author',
        3 => 'comment_body',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'left',
      'post_date' => 'right',
      'author' => 'right',
      'comment_body' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_dataset|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|app|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'app';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_app_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'field_fivestar',
      ),
    ),
    'fields' => array(
      'field_app_image' => 'left',
      'title' => 'right',
      'field_fivestar' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|app|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'author',
        1 => 'post_date',
        2 => 'field_rubric',
        3 => 'body',
        4 => 'comments',
      ),
    ),
    'fields' => array(
      'author' => 'ds_content',
      'post_date' => 'ds_content',
      'field_rubric' => 'ds_content',
      'body' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|blog|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|search';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'search';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'field_date_created',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_date_created' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|blog|search'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|blog|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'blog';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'ds_user_picture',
        1 => 'author',
        2 => 'title',
        3 => 'body',
        4 => 'field_rubric',
        5 => 'field_date_created',
        6 => 'field_comments_count',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'ds_content',
      'author' => 'ds_content',
      'title' => 'ds_content',
      'body' => 'ds_content',
      'field_rubric' => 'ds_content',
      'field_date_created' => 'ds_content',
      'field_comments_count' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|blog|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|competition|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'competition';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_2col';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_competition_photo',
      ),
      'right' => array(
        1 => 'field_competition_rubric',
        2 => 'title',
        3 => 'field_competition_place',
        4 => 'field_competition_type',
        5 => 'field_competition_date',
        6 => 'field_competition_organizer',
        7 => 'dynamic_field',
      ),
    ),
    'fields' => array(
      'field_competition_photo' => 'left',
      'field_competition_rubric' => 'right',
      'title' => 'right',
      'field_competition_place' => 'right',
      'field_competition_type' => 'right',
      'field_competition_date' => 'right',
      'field_competition_organizer' => 'right',
      'dynamic_field' => 'right',
    ),
    'limit' => array(
      'field_competition_organizer' => '1',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|competition|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dataset|table';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dataset';
  $ds_layout->view_mode = 'table';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_additional',
        1 => 'field_dataset_id',
        2 => 'dynamic_field',
        3 => 'body',
        4 => 'field_organization',
        5 => 'field_contact_name',
        6 => 'field_contact_phone',
        7 => 'field_email_responsible',
        8 => 'dynamic_field_3',
        9 => 'dynamic_field_4',
        10 => 'dynamic_field_5',
        11 => 'field_date_first_time_publ',
        12 => 'field_date_last_change',
        13 => 'field_content_last_change',
        14 => 'field_date_dataset_actual',
        15 => 'field_frequency',
        16 => 'field_tags',
        17 => 'dynamic_field_6',
        18 => 'dataset_table_1',
      ),
    ),
    'fields' => array(
      'group_additional' => 'ds_content',
      'field_dataset_id' => 'ds_content',
      'dynamic_field' => 'ds_content',
      'body' => 'ds_content',
      'field_organization' => 'ds_content',
      'field_contact_name' => 'ds_content',
      'field_contact_phone' => 'ds_content',
      'field_email_responsible' => 'ds_content',
      'dynamic_field_3' => 'ds_content',
      'dynamic_field_4' => 'ds_content',
      'dynamic_field_5' => 'ds_content',
      'field_date_first_time_publ' => 'ds_content',
      'field_date_last_change' => 'ds_content',
      'field_content_last_change' => 'ds_content',
      'field_date_dataset_actual' => 'ds_content',
      'field_frequency' => 'ds_content',
      'field_tags' => 'ds_content',
      'dynamic_field_6' => 'ds_content',
      'dataset_table_1' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|dataset|table'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|dataset|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'dataset';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_dataset_standard',
        1 => 'field_rubric',
        2 => 'title',
        3 => 'field_organization',
        4 => 'dynamic_field_1',
        5 => 'resource_format',
      ),
    ),
    'fields' => array(
      'field_dataset_standard' => 'ds_content',
      'field_rubric' => 'ds_content',
      'title' => 'ds_content',
      'field_organization' => 'ds_content',
      'dynamic_field_1' => 'ds_content',
      'resource_format' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|dataset|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|document|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'document';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_rubric',
        2 => 'field_tags',
        3 => 'field_document_file',
        4 => 'field_document_type',
        5 => 'comments',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_rubric' => 'ds_content',
      'field_tags' => 'ds_content',
      'field_document_file' => 'ds_content',
      'field_document_type' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|document|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|search';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'search';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'post_date',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'post_date' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|event|search'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|forum|search';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'forum';
  $ds_layout->view_mode = 'search';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'post_date',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'post_date' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|forum|search'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|idea|search';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'idea';
  $ds_layout->view_mode = 'search';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'body',
        2 => 'post_date',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'body' => 'ds_content',
      'post_date' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|idea|search'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'post_date',
        1 => 'field_image',
        2 => 'body',
        3 => 'field_url_source',
        4 => 'comments',
      ),
    ),
    'fields' => array(
      'post_date' => 'ds_content',
      'field_image' => 'ds_content',
      'body' => 'ds_content',
      'field_url_source' => 'ds_content',
      'comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|news|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|search';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'search';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_teaser',
        2 => 'post_date',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_teaser' => 'ds_content',
      'post_date' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|news|search'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|news|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'news';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'field_teaser',
        3 => 'field_date_created',
        4 => 'field_rubric',
        5 => 'field_comments_count',
      ),
    ),
    'fields' => array(
      'field_image' => 'ds_content',
      'title' => 'ds_content',
      'field_teaser' => 'ds_content',
      'field_date_created' => 'ds_content',
      'field_rubric' => 'ds_content',
      'field_comments_count' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|news|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|page|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|quick_fact|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'quick_fact';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_fact_value',
        1 => 'body',
        2 => 'field_fact_url',
      ),
    ),
    'fields' => array(
      'field_fact_value' => 'ds_content',
      'body' => 'ds_content',
      'field_fact_url' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|quick_fact|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resource|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resource';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_link_api',
        1 => 'field_data_structure',
        2 => 'field_link_structure_file',
        3 => 'field_upload_structure',
        4 => 'field_provenance',
        5 => 'field_created',
        6 => 'cf_resource',
        7 => 'field_link_remote_file',
        8 => 'field_upload',
      ),
    ),
    'fields' => array(
      'field_link_api' => 'ds_content',
      'field_data_structure' => 'ds_content',
      'field_link_structure_file' => 'ds_content',
      'field_upload_structure' => 'ds_content',
      'field_provenance' => 'ds_content',
      'field_created' => 'ds_content',
      'cf_resource' => 'ds_content',
      'field_link_remote_file' => 'ds_content',
      'field_upload' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|resource|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'taxonomy_term|rubrics|rubric_icon_with_title';
  $ds_layout->entity_type = 'taxonomy_term';
  $ds_layout->bundle = 'rubrics';
  $ds_layout->view_mode = 'rubric_icon_with_title';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_rubric_image',
        1 => 'title_i18n',
      ),
    ),
    'fields' => array(
      'field_rubric_image' => 'ds_content',
      'title_i18n' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['taxonomy_term|rubrics|rubric_icon_with_title'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|default';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['user|user|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function nodes_breadcrumbs_pm_pages_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'rubric_icon_with_title';
  $ds_view_mode->label = 'Иконка + заголовок рубрики';
  $ds_view_mode->entities = array(
    'taxonomy_term' => 'taxonomy_term',
  );
  $export['rubric_icon_with_title'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search';
  $ds_view_mode->label = 'search';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'table';
  $ds_view_mode->label = 'Table';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['table'] = $ds_view_mode;

  return $export;
}
