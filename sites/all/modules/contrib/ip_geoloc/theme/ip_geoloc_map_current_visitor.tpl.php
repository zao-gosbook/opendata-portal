<?php

/**
 * @file
 * ip_geoloc_map_current_visitor.tpl.php
 * 
 * This template is used mainly inside a block rather than a view.
 * Lat/long are optional fallbacks in case the HTML5 lookup fails.
 */
?>

<div class="ip-geoloc-map-current-visitor">
  <?php print ip_geoloc_output_map_current_location($div_id, $map_options, $map_style, $latitude, $longitude); ?>
</div>
