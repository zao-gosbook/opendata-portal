/**
 * @file
 * Javascript for Draggable Captcha.
 */

(function ($) {
  Drupal.behaviors.draggable_captcha = {
    attach: function(context) {
      $(document).ready(function($) {
        $('.captchaWrapper .draggable').draggable({ containment: 'parent', snap: '.target', snapMode: 'inner', snapTolerance: 35, revert: 'invalid', opacity: 0.75});
        $('.captchaWrapper .target').droppable({ accept: '.draggable', tolerance: 'intersect' });

        //On drop of draggable object
        $('.captchaWrapper .target').bind('drop', function(event, ui) {
          $('#edit-captcha-response').val($(ui.draggable).attr('id'));
          $('#captchaWrapper').find('.draggable').draggable('disable');
          $('#captchaWrapper').find('.draggable').unbind('click');
          $('#captchaWrapper').find('.targetWrapper').children('.target').hide();

          //Check captcha answer
          $.post(Drupal.settings.basePath + 'draggable-captcha/'+Drupal.settings.draggable_captcha.captcha_sid+'/verify', { action: 'verify', captcha: $(ui.draggable).attr('id') }, function(data) {
            if (data.status == "success") {
              $('#captchaWrapper').find('.targetWrapper').addClass('captchaSuccess').hide().fadeIn('slow');
            } else {
              $('#captchaWrapper').find('.targetWrapper').addClass('captchaFail').hide().fadeIn('slow');
            }
          }, 'json');
        });

        //On double-click of object
        $('.captchaWrapper #captchaWrapper').find('.draggable').unbind('click');
        $('.captchaWrapper .draggable').bind('click', function(event, ui) {
          $('#edit-captcha-response').val($(this).attr('id'));
          $('#captchaWrapper').find('.draggable').draggable('disable');
         // $('#captchaWrapper').find('.draggable').unbind('click');
          $('#captchaWrapper').find('.targetWrapper').children('.target').hide();
          $(this).removeClass('draggable');
          $(this).addClass('target');
          $('#captchaWrapper').find('.targetWrapper').html($(this));

          //Check captcha answer
          $.post(Drupal.settings.basePath + 'draggable-captcha/'+Drupal.settings.draggable_captcha.captcha_sid+'/verify', { action: 'verify', captcha: $(this).attr('id') }, function(data) {
            if (data.status == "success") {
              $('#captchaWrapper').find('.targetWrapper').addClass('captchaSuccess').hide().fadeIn('slow');
            } else {
              $('#captchaWrapper').find('.targetWrapper').addClass('captchaFail').hide().fadeIn('slow');
            }
          }, 'json');
        });

      });
    }
  }
})(jQuery);
