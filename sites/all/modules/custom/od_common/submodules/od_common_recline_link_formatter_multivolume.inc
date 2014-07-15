<?php
/**
 * @file
 */

function od_common_module__recline_link_formatter_multivolume(&$element, $entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $dataset_wrapper = od_dataset_get_wrapper_by_resource($entity, $entity->vid);
  //list($entity_id, $revision_id, $bundle) = entity_extract_ids($entity_type, $entity);
  $entity_id = $dataset_wrapper->nid->value();
  $revision_id = $dataset_wrapper->vid->value();
  $bundle = $dataset_wrapper->getBundle();
  $context = od_pubdlcnt_api_attacher_context_add($entity_type, $entity_id, $revision_id, "{$bundle}:all", array(
    'selector' => '.multi-download-link-wrapper[data-stat-id="%STAT_ID%"] .dropdown-links .download a',
  ));

  $context = $context ? $context : array('stat_id' => -1);

  foreach ($items as $delta => $item) {
    // Change download callback to od_dataset's callback to support encodings
    $download_uri = (string) od_dataset_download_path($dataset_wrapper);
    $element[$delta]['links_container'] = array(
      '#prefix' => '<div class="multi-download-link-wrapper">',
      '#suffix' => '</div>',
      'main_link' => array(
        '#markup' => '<div class="main-download-link-wrapper"><a href="#">'. t('Download').'</a></div>'
      ),
      'dropdown_links' => array(
        '#prefix' => '<div class="element-invisible dropdown-links state-collapsed">',
        '#suffix' => '</div>',
      ),
    );

    $element[$delta]['links_container']['#attached']['js'][] = array(
      'type' => 'file',
      'data' => drupal_get_path('module', 'od_common'). '/js/multi-download-links.js',
    );

    static $encodings_map = array(
      ODDetectEncoding::ENC_CP1251 => 'Windows-1251',
      ODDetectEncoding::ENC_UTF8 => 'Unicode (UTF-8)'
    );

    foreach ($encodings_map as $target_encoding => $encoding_label) {
      $options = array();
      $options['query']['encoding'] = $target_encoding;
      $options['html'] = TRUE;

      // Replace our uri to different
      $item['uri'] = $download_uri; //url($download_uri, $options);

      // Use recline's theme function
      $element[$delta]['links_container']['dropdown_links'][$target_encoding] = array(
        'item' => array(
          '#theme' => 'od_common_recline_link_formatter',
          '#item' => $item,
          '#options' => $options,
          '#link_attributes' => array(
            'dlcnt:data-stat-id' => $context['stat_id'],
          ),
          '#title' => t('Download in %encoding encoding', array('%encoding' => $target_encoding)),
        ),
//            'item_suffix' => array(
//              '#markup' => "<span>(in {$target_encoding} encoding)</span>",
//            ),
        '#attributes' => array(
          'class' => array("encoding-{$target_encoding}"),
        ),
      );
    }
  }
}

