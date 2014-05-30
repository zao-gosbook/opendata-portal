<?php

/**
 * @file
 * Row style plugin for displaying the results as entities.
 */

/**
 * Plugin class for displaying Views results with entity_view.
 */
class cached_entity_view_views_plugin_row_entity_cached_view extends entity_views_plugin_row_entity_view {
  /**
   * Overrides entity_views_plugin_row_entity_view:pre_render()
   * @inheritdoc
   */
  public function pre_render($values) {
    if (!empty($values)) {
      list($this->entity_type, $this->entities) = $this->view->query->get_result_entities($values, !empty($this->relationship) ? $this->relationship : NULL, isset($this->field_alias) ? $this->field_alias : NULL);
    }

    // Render the entities.
    if ($this->entities) {
      $render = $this->render_cached_entities($this->entity_type, $this->entities, $this->options['view_mode']);
      // Remove the first level of the render array.
      $this->rendered_content = $render;
    }
  }

  /**
   * Renders entities and caches them. Also filters already rendered entities
   * @param $type
   * @param $entities
   * @param $view_mode
   * @return array
   */
  public function render_cached_entities($type, $entities, $view_mode) {
    //$cache_key = $this->view->name. $type . $view_mode;
    $rendered = array();
    $cache_default = array(
      'cid' => substr(md5(get_class(). $this->view->name), 0, 8),
      'bin' => 'cache', //@fixme: Setup from config form
      'expire' => strtotime('today 23:59:59') - time(),
    );

    $cache = cache_get($cache_default['cid'], $cache_default['bin']);
    $cache = (object) (($cache ? (array) $cache : array()) + $cache_default);

    foreach ($entities as $key => $entity) {
      list ($id, , ) = entity_extract_ids($type, $entity);
      $cache_key = $id. $view_mode;
      if (isset($cache->data[$cache_key])) {
        $rendered[$id] = $cache->data[$cache_key];
        unset($entities[$key]);
      }
    }

    if (!empty($entities)) {
      $render = entity_view($this->entity_type, $this->entities, $this->options['view_mode']);
      $render = reset($render);
      foreach ($render as $id => $_rendered_entity) {
        if (substr($id, 0, 1) != '#') {
          $cache_key = $id. $view_mode;
          $cache->data[$cache_key] = $_rendered_entity;
          $rendered[$id] = $_rendered_entity;
        }
      }

      cache_set($cache->cid, $cache->data, $cache->bin, $cache->expire);
    }

    return $rendered;
  }
}
