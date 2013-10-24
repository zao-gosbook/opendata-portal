<?php
// $Id: comment.tpl.php,v 1.1.1.1.4.1 2010/11/11 13:52:44 danprobo Exp $
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print $picture ?>

  <?php if ($new): ?>
    <span class="new"><?php print $new ?></span>
  <?php endif; ?>

  <div class="submitted">
    <?php print $created . $author; ?>
    <?php print $permalink; ?>
  </div>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      hide($content['links']);
      print render($content);
    ?>
    <?php if ($signature): ?>
    <div class="user-signature clearfix">
      <?php print $signature ?>
    </div>
    <?php endif; ?>
  </div>

  <?php print render($content['links']) ?>
</div>
