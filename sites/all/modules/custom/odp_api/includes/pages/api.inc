<?php

/**
 * Page callback.
 */
function odp_api_page() {
  $args = func_get_args();

  $content = odp_api_point_api($args);
  return $content;
}
