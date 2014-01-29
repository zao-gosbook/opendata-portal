<?php

/**
 * @file
 * Default template implementation.
 *
 * Available variables:
 * - $image_buttons: An array of image button positions.
 * - $captcha_codes: An array of hash codes for image buttons.
 */
?>

<?php if ($image_buttons && $captcha_codes && $captcha_sid) : ?>
<div id="draggable-captcha-mini">
  <label>
    <?php print t('Drag or click the correct shape to the grey "drop area".'); ?>
  </label>
  <div class="captchaWrapper-mini" id="captchaWrapper-mini">
    <a href="<?php print base_path();?>draggable-captcha-mini/<?php print $captcha_sid;?>/refresh/nojs/" class="captchaRefresh use-ajax"></a>
    <?php $count = 0;?>
    <?php foreach ($image_buttons as $image_button => $image_button_position): ?>
      <div id="draggable_<?php print $captcha_codes[$image_button];?>" class="draggable"
        style="left:<?php print (($count * 40) + 8);?>px;background-position:<?php print $image_button_position['on']['top'] . ' ' . $image_button_position['on']['left'];?>;">
      </div>
      <?php $count++;?> 
    <?php endforeach; ?>
    <div class="targetWrapper">
      <div class="target" style="background:none;">
        <img alt="Target Image" src="<?php print base_path();?>draggable-captcha-mini/target-img?v<?php print rand(1000, 9999);?>" />
      </div>
    </div>
  </div>
</div>
<?php endif; ?>
