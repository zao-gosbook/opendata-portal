<?php

$plugin = array(
  'title' => t('Piwik report iframe'),
  'single' => TRUE,
  'category' => t('Miscellaneous'),
  'defaults' => array('report' => ''),
);

function piwik_report_pane_piwik_report_iframe_content_type_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $block->title = !empty($conf['override_title']) ? check_plain($conf['override_title_text']) : '';
  module_load_include('inc', 'piwik_reports', 'piwik_reports.pages');
  $block->content = empty($conf['report']) ? 'Iframe is not selected' : _piwik_report_pane_piwik_report_iframe_render($conf['report']);
  return $block;
}

function _piwik_report_pane_piwik_report_iframe_render($report) {
  global $user;

  $piwik_auth = (isset($user->data['piwik_reports_token_auth']) && !empty($user->data['piwik_reports_token_auth'])? $user->data['piwik_reports_token_auth'] : variable_get('piwik_reports_token_auth', ''));
  $piwik_url = piwik_reports_get_url();
  $sites = piwik_reports_get_sites($piwik_auth);
  if (empty($sites)) {
    $_SESSION['piwik_reports_site'] == '';
    drupal_set_message(t('You can not access any data on the selected Piwik server. Please check authentication string and permissions with your Piwik server administrator.'), 'warning');
    return;
  }

  $piwik_site_id = reset($sites);
  $piwik_site_id = $piwik_site_id['idsite'];
  $period = isset($_SESSION['piwik_reports_period']) ? $_SESSION['piwik_reports_period'] : 0;

  if ($period == 1) {
    // Special handling for "yesterday" = 1.
    // The yesterday date value is required.
    $date = _piwik_reports_select_period($period);
  }
  else {
    // Otherwise it returns the today date value.
    $date = _piwik_reports_select_period(0);
  }
  $period_name = _piwik_reports_get_period_name($period);

  // Create an array of URL parameters for easier maintenance.
  $data_params[0] = array();
  $data_params[0]['idSite'] = $piwik_site_id;
  $data_params[0]['date'] = $date;
  $data_params[0]['period'] = $period_name;
  $data_params[0]['disableLink'] = 1;
  $data_params[0]['module'] = 'Widgetize';
  $data_params[0]['action'] = 'iframe';
  $data_params[0]['disableLink'] = 1;
  $data_params[0]['widget'] = 1;
  // $data_params[0]['loading'] = t('Loading data...');
  if (!empty($piwik_auth)) {
    $data_params[0]['token_auth'] = $piwik_auth;
  }

  switch ($report) {
    case 'visitors_overview':
      $title[0] = t('Visits trend');
      $data_params[0]['columns[]'] = 'nb_visits';
      $data_params[0]['moduleToWidgetize'] = 'VisitsSummary';
      $data_params[0]['actionToWidgetize'] = 'getEvolutionGraph';
      break;
    case 'visitors_times':
      $title[0] = t('Visits by local time');
      $data_params[0]['moduleToWidgetize'] = 'VisitTime';
      $data_params[0]['actionToWidgetize'] = 'getVisitInformationPerLocalTime';
      break;
    case 'visitors_settings':
      $data_params[0]['filter_limit'] = 6;
      // Browser families
      $title[0] = t('Browser families');
      $data_params[0]['moduleToWidgetize'] = 'UserSettings';
      $data_params[0]['actionToWidgetize'] = 'getBrowserType';
      break;
    case 'getConfiguration':
      // Screen resolutions
      $data_params[0]['filter_limit'] = 6;
      $title[0] = t('Screen resolution');
      $data_params[0]['moduleToWidgetize'] = 'UserSettings';
      $data_params[0]['actionToWidgetize'] = 'getConfiguration';
      break;
    case 'getOS':
      // Operating systems
      $data_params[0]['filter_limit'] = 6;
      $title[0] = t('Operating system');
      $data_params[0]['moduleToWidgetize'] = 'UserSettings';
      $data_params[0]['actionToWidgetize'] = 'getOS';
      break;
    case 'getResolution':
      // Client configurations
      $data_params[0]['filter_limit'] = 6;
      $title[0] = t('Client configuration');
      $data_params[0]['moduleToWidgetize'] = 'UserSettings';
      $data_params[0]['actionToWidgetize'] = 'getResolution';
      break;
    case 'visitors_locations':
      $title[0] = t('Visitors countries');
      $data_params[0]['moduleToWidgetize'] = 'UserCountry';
      $data_params[0]['actionToWidgetize'] = 'getCountry';
      $data_params[0]['filter_limit'] = 15;
      break;
    case 'custom_variables':
      $title[0] = t('Custom variables');
      $iframe_height[0] = 1000;
      $data_params[0]['moduleToWidgetize'] = 'CustomVariables';
      $data_params[0]['actionToWidgetize'] = 'getCustomVariables';
      $data_params[0]['filter_limit'] = 15;
      break;
    case 'actions_pageurls':
      $title[0] = t('Page visits');
      $data_params[0]['moduleToWidgetize'] = 'Actions';
      $data_params[0]['actionToWidgetize'] = 'getPageUrls';
      $data_params[0]['filter_limit'] = 15;
      break;
    case 'actions_entryurls':
      $title[0] = t('Page visits');
      $data_params[0]['moduleToWidgetize'] = 'Actions';
      $data_params[0]['actionToWidgetize'] = 'getEntryPageUrls';
      $data_params[0]['filter_limit'] = 15;
      break;
    case 'actions_exiturls':
      $title[0] = t('Page visits');
      $data_params[0]['moduleToWidgetize'] = 'Actions';
      $data_params[0]['actionToWidgetize'] = 'getExitPageUrls';
      $data_params[0]['filter_limit'] = 15;
      break;
    case 'actions_outlinks':
      $title[0] = '';
      $data_params[0]['moduleToWidgetize'] = 'Actions';
      $data_params[0]['actionToWidgetize'] = 'getOutlinks';
      $data_params[0]['filter_limit'] = 15;
      break;
    case 'actions_downloads':
      $title[0] = '';
      $data_params[0]['moduleToWidgetize'] = 'Actions';
      $data_params[0]['actionToWidgetize'] = 'getDownloads';
      $data_params[0]['filter_limit'] = 15;
      break;
    case 'referers_evolution':
      $title[0] = '';
      $data_params[0]['moduleToWidgetize'] = 'Referers';
      $data_params[0]['actionToWidgetize'] = 'getRefererType';
      break;
    case 'referers_search':
      $title[0] = t('Search engines');
      $data_params[0]['moduleToWidgetize'] = 'Referers';
      $data_params[0]['actionToWidgetize'] = 'getSearchEngines';
      break;
    case 'getKeywords':
      $title[0] = t('Keywords');
      $data_params[0]['moduleToWidgetize'] = 'Referers';
      $data_params[0]['actionToWidgetize'] = 'getKeywords';
      break;
    case 'referers_websites':
      $title[0] = '';
      $data_params[0]['moduleToWidgetize'] = 'Referers';
      $data_params[0]['actionToWidgetize'] = 'getWebsites';
      break;
//    case 'goals_evolution':
//      $goals = piwik_reports_get_goals($piwik_auth, $_SESSION['piwik_reports_site']);
//      if (count($goals) == 0) {
//        $empty_text = t('No goals have been set. Check with your Piwik server administrator if you desire some.');
//        $title[0] = NULL;
//        break;
//      }
//      $common_data_params = $data_params[0];
//      $i = 0;
//      foreach ($goals as $goal) {
//        $title[$i] = $goal['name'];
//        $iframe_height[$i] = 370;
//        $data_params[$i] = $common_data_params;
//        $data_params[$i]['moduleToWidgetize'] = 'Goals';
//        $data_params[$i]['actionToWidgetize'] = 'widgetGoalReport';
//        $data_params[$i]['idGoal'] = $goal['idgoal'];
//        $i++;
//      }
//      break;
  }

  $output = array();

  foreach ($data_params as $key => $data) {

    $data_url[] = array('url' => $piwik_url . 'index.php?' . drupal_http_build_query($data),
      'title' => $title[$key],
      'iframe_height' => ( isset($iframe_height[$key]) && $iframe_height[$key] > 0 ? $iframe_height[$key] : 350),
      'empty_text' => ( isset($empty_text) ? $empty_text : NULL),
    );
  }

  foreach ($data_url as $data) {
    if (!is_null($data['empty_text'])) {
      $output[] = '<div class="piwik-empty-text">' . $data['empty_text'] . '</div>';
    }
    else {
      $output[] = '<div class="widgetIframe"><iframe width="100%" height="' . $data['iframe_height'] . '" src="' . $data['url'] . '" scrolling="no" frameborder="0" marginheight="0" marginwidth="0"></iframe></div>';
    }
  }

  return implode('', $output);
}

/**
 * Edit form callback for the content type.
 */
function piwik_report_pane_piwik_report_iframe_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['report'] = array(
    '#type' => 'textfield',
    '#title' => t('Iframe type'),
    '#required' => TRUE,
    '#size' => 60,
    '#default_value' => isset($conf['report']) ? $conf['report'] : '',
  );

  return $form;
}

/**
 * The submit form stores the data in $conf.
 */
function piwik_report_pane_piwik_report_iframe_content_type_edit_form_submit($form, &$form_state) {
  // Copy everything from our defaults.
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Provide a summary description.
 */
function piwik_report_pane_piwik_report_iframe_content_type_summary($conf, $context) {
  return 'Piwik report iframe: ' . check_plain($conf['report']);
}
