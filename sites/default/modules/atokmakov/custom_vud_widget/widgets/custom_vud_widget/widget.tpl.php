<?php

/**
 * @file
 * widget.tpl.php
 *
 * UpAndDown widget theme for Vote Up/Down
 * TODO use $show_up_as_link and $show_down_as_link
 */
?>
<span class="vud-widget vud-widget-custom" id="<?php print $id; ?>">
  <span class="up-score">
    <?php if ($show_links): ?>
      <?php if ($show_up_as_link): ?>
        <a href="<?php print $link_up; ?>" rel="nofollow" class="<?php print "$link_class_up"; ?>" title="<?php print t('Vote up!'); ?>">
      <?php endif; ?>
          <?php print t('found it useful') ?>
          <span class="up-current-score"><?php print $up_points; ?></span>
          <?php print t('users'); ?>
      <?php if ($show_up_as_link): ?>
        </a>
      <?php endif; ?>
    <?php endif; ?>
  </span>
  |
  <span class="down-score <?php print ($down_points) ? '' : 'down-score-0'; ?>">
    <?php if ($show_links): ?>
      <?php if ($show_down_as_link): ?>
        <a href="<?php print $link_down; ?>" rel="nofollow" class="<?php print "$link_class_down"; ?>" title="<?php print t('Vote down!'); ?>">
      <?php endif; ?>
          <?php print t('considered useless') ?>
          <span class="down-current-score"><?php print $down_points; ?></span>
          <?php print t('users'); ?>
      <?php if ($show_down_as_link): ?>
        </a>
      <?php endif; ?>
    <?php endif; ?>
    
  </span>
  <?php if ($show_reset): ?>
    <a href="<?php print $link_reset; ?>" rel="nofollow" class="<?php print $link_class_reset; ?>" title="<?php print $reset_long_text; ?>">
      <span class="<?php print $class_reset; ?>">
        <?php print $reset_short_text; ?>
      </span>
    </a>
  <?php endif; ?>
</span>
