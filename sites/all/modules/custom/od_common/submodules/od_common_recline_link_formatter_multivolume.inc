<?php
/**
 * @file
 */

function od_common_module__recline_link_formatter_multivolume(&$element, $entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  foreach ($items as $delta => $item) {
    // Change download callback to od_dataset's callback to support encodings
    $download_uri = 'dataset-actions/download_file/'. $item['fid'];
    try {
      $wrapper = entity_metadata_wrapper($entity_type, $entity);
      if (($dataset = $wrapper->field_dataset_ref->value()) && ($wrapper->field_dataset_ref->field_multivolume->raw() == TRUE)) {
        $download_uri = 'dataset-actions/download_package/' . $dataset->nid;
      }
    }
    catch (Exception $e) {
      // @fixme: prevent errors here.
      watchdog_exception('od_common', $e);
      //throw $e;
    }

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