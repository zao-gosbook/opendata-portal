<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print ' rel="dc:hasPart"'; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix" property="dc:title" content="<?php print $title; ?>">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php print $ds_content; ?>
</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
