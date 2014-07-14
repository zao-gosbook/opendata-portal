<?php

function odp_import_cron_import_site($nid) {
  odp_import_cron_import_organizations(array($nid));
}

function odp_import_cron_import_organizations($nids) {
  $queue = DrupalQueue::get('odp_import_cron_import_organization');
  foreach ($nids as $nid) {
    $queue->createItem($nid);
  }
}

function odp_import_cron_queue_import_organization($nid) {
  $organization = node_load($nid);

  // Load "Opendata API" library.
  od_api();

  $mapping = variable_get('odp-import-cron-mapping', array());
  $remote_nid = $mapping[$nid];
  $sites = odp_import_cron_sites();
  $site_url = $sites[$remote_nid]['site'];

  // Start timer.
  $time_start = date(ODP_IMPORT_TIMER_FORMAT);

  $list_vars = array(
    'args' => array('meta-list' => $site_url),
    'vars' => array(),
    'org_nid' => $organization->nid,
    'org_name' => $organization->title,
  );
  $list = odp_import_meta_list($list_vars);

  $results = array();
  $results['data'] = array();
  $results['org_nid'] = $organization->nid;
  $results['org_name'] = $organization->title;
  $results['time_start'] = $time_start;

  if (is_array($list) && !empty($list)) {
    // Meta object.
    $results['data'] = array();
    foreach ($list as $meta) {
      $meta_vars = array(
        'args' => $meta['#api'],
        'vars' => array(),
        'meta' => $meta,
      );
      $results['data'][] = odp_import_meta($meta_vars);
    }
  }

  odp_import_meta_from_data($results);
}

/**
 * Temp func for get_sites.
 */
function odp_import_cron_sites() {
  $items = array();

  $items['181'] = array(
    'name' => 'Федеральная служба по техническому и экспортному контролю',
    'site' => 'fstec.ru',
  );
  $items['247'] = array(
    'name' => 'Федеральная служба по экологическому, технологическому и атомному надзору',
    'site' => 'www.gosnadzor.ru',
  );
  $items['184'] = array(
    'name' => 'Федеральное агентство по поставкам вооружения, военной, специальной техники и материальных средств',
    'site' => 'rosoboronpostavka.ru',
  );
  $items['207'] = array(
    'name' => 'Федеральная служба по надзору в сфере природопользования',
    'site' => 'rpn.gov.ru',
  );
  $items['201'] = array(
    'name' => 'Министерство культуры Российской Федерации',
    'site' => 'www.mkrf.ru',
  );
  $items['244'] = array(
    'name' => 'Федеральное агентство по обустройству государственной границы Российской федерации',
    'site' => 'www.rosgranitsa.ru',
  );

  return $items;
}

/**
 * Form with chained submit callbacks.
 */
function odp_import_cron_form() {
  // This value is used to test that $form_state persists through batched
  // submit handlers.
  $form['value'] = array(
    '#type' => 'textfield',
    '#title' => 'Value',
    '#default_value' => 1,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  $form['#submit'] = array(
    'batch_test_chained_form_submit_1',
    'batch_test_chained_form_submit_2',
    'batch_test_chained_form_submit_3',
    'batch_test_chained_form_submit_4',
  );

  return $form;
}
