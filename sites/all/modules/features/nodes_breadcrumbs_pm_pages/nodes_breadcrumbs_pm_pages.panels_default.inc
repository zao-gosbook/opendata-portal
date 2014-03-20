<?php
/**
 * @file
 * nodes_breadcrumbs_pm_pages.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function nodes_breadcrumbs_pm_pages_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'custom_block';
  $mini->category = '';
  $mini->admin_title = 'Блок ссылок (Располагается слева посередине)';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e707a3e6-d108-4ddf-a1fb-9cbb3ecfabbc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0df32391-5d09-4a64-97f5-2cb5933d20cb';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<?php
global $language;
$prefix = $language->language;
$question = t(\'Ask a question\');
$idea = t(\'Suggest an idea\');
$discuss = t(\'Discuss\');
print <<<END
<div class=\'feedback-block\'>
      <ul class="feedback-links">
        <li class="feedback-question">
          <a href="/$prefix/feedback" class="question">$question</a>
        </li>
        <li class="feedback-idea">
          <a href="/$prefix/node/add/idea" class="idea">$idea</a>
        </li>
        <li class="feedback-discuss">
          <a href="/$prefix/forumy/obshchaya-diskussiya" class="discuss"">$discuss</a>
        </li>
      </ul>
 </div>
END;
?>',
      'format' => 'ds_code',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0df32391-5d09-4a64-97f5-2cb5933d20cb';
    $display->content['new-0df32391-5d09-4a64-97f5-2cb5933d20cb'] = $pane;
    $display->panels['middle'][0] = 'new-0df32391-5d09-4a64-97f5-2cb5933d20cb';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-0df32391-5d09-4a64-97f5-2cb5933d20cb';
  $mini->display = $display;
  $export['custom_block'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'overall_statistics';
  $mini->category = '';
  $mini->admin_title = 'Общая статитстика';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1348bfe8-33ed-4249-906e-c9613fbebdcb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f518274e-8038-40d1-85a8-f845f2259e0b';
    $pane->panel = 'middle';
    $pane->type = 'piwik_report_iframe';
    $pane->subtype = 'piwik_report_iframe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report' => 'referers_evolution',
      'override_title' => 1,
      'override_title_text' => 'Overall traffic',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f518274e-8038-40d1-85a8-f845f2259e0b';
    $display->content['new-f518274e-8038-40d1-85a8-f845f2259e0b'] = $pane;
    $display->panels['middle'][0] = 'new-f518274e-8038-40d1-85a8-f845f2259e0b';
    $pane = new stdClass();
    $pane->pid = 'new-b5715c7f-c609-4d94-aa81-2d085e276c6c';
    $pane->panel = 'middle';
    $pane->type = 'piwik_report_iframe';
    $pane->subtype = 'piwik_report_iframe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report' => 'visitors_overview',
      'override_title' => 1,
      'override_title_text' => 'Dynamics visits',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b5715c7f-c609-4d94-aa81-2d085e276c6c';
    $display->content['new-b5715c7f-c609-4d94-aa81-2d085e276c6c'] = $pane;
    $display->panels['middle'][1] = 'new-b5715c7f-c609-4d94-aa81-2d085e276c6c';
    $pane = new stdClass();
    $pane->pid = 'new-711dae88-01bf-4513-b21a-567789cd621d';
    $pane->panel = 'middle';
    $pane->type = 'piwik_report_iframe';
    $pane->subtype = 'piwik_report_iframe';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'report' => 'visitors_times',
      'override_title' => 1,
      'override_title_text' => 'Visiting hours',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '711dae88-01bf-4513-b21a-567789cd621d';
    $display->content['new-711dae88-01bf-4513-b21a-567789cd621d'] = $pane;
    $display->panels['middle'][2] = 'new-711dae88-01bf-4513-b21a-567789cd621d';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-f518274e-8038-40d1-85a8-f845f2259e0b';
  $mini->display = $display;
  $export['overall_statistics'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'search_block';
  $mini->category = '';
  $mini->admin_title = 'Блок поиска';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'facfd367-068a-4bcf-a49e-66878e83991c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-5262d1c3-3a89-453e-a616-b63218b90dd4';
    $pane->panel = 'middle';
    $pane->type = 'gb_search_pane';
    $pane->subtype = 'gb_search_pane';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'query_field_name' => 'query',
      'query_field_size' => '40',
      'redirect_url_datasets' => 'dataset',
      'redirect_url_site' => 'search',
      'submit_value' => 'search',
      'form_build_id' => 'form-xBxE6PYmHM0hNTNyrAAeyc1cnJqlH1Q0q9AQfF2Ko98',
      'form_token' => 'Tx4y-GA_eg0JMiQip_E8n1OTdpO51TiP3iPRTEYSl2o',
      'form_id' => 'gb_search_pane_content_type_edit_form',
      'override_title_text' => '',
      'query_field_label' => 'Search',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5262d1c3-3a89-453e-a616-b63218b90dd4';
    $display->content['new-5262d1c3-3a89-453e-a616-b63218b90dd4'] = $pane;
    $display->panels['middle'][0] = 'new-5262d1c3-3a89-453e-a616-b63218b90dd4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-5262d1c3-3a89-453e-a616-b63218b90dd4';
  $mini->display = $display;
  $export['search_block'] = $mini;

  return $export;
}
