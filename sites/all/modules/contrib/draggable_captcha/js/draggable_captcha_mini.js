/**
 * @file
 * Javascript for Draggable Captcha.
 */

(function ($) {
  Drupal.behaviors.draggable_captcha_mini = {
    attach: function(context) {
      $(document).ready(function($) {
        $('.captchaWrapper-mini .draggable').draggable({ containment: 'parent', snap: '.target', snapMode: 'inner', snapTolerance: 35, revert: 'invalid', opacity: 0.75});
        $('.captchaWrapper-mini .target').droppable({ accept: '.draggable', tolerance: 'intersect' });

        //On drop of draggable object
        $('.captchaWrapper-mini .target').bind('drop', function(event, ui) {
          $('#edit-captcha-response').val($(ui.draggable).attr('id'));
          $('#captchaWrapper-mini').find('.draggable').draggable('disable');
          $('#captchaWrapper-mini').find('.draggable').unbind('click');
          $('#captchaWrapper-mini').find('.targetWrapper').children('.target').hide();

          //Check captcha answer
          $.post(Drupal.settings.basePath + 'draggable-captcha-mini/'+Drupal.settings.draggable_captcha_mini.captcha_sid+'/verify', { action: 'verify', captcha: $(ui.draggable).attr('id') }, function(data) {
            if (data.status == "success") {
              $('#captchaWrapper-mini').find('.targetWrapper').addClass('captchaSuccess').hide().fadeIn('slow');
            } else {
              $('#captchaWrapper-mini').find('.targetWrapper').addClass('captchaFail').hide().fadeIn('slow');
            }
          }, 'json');
        });

        //On double-click of object
        $('#captchaWrapper-mini').find('.draggable').unbind('click');
        $('.captchaWrapper-mini .draggable').bind('click', function(event, ui) {
          $('#edit-captcha-response').val($(this).attr('id'));
          $('#captchaWrapper-mini').find('.draggable').draggable('disable');
         // $('#captchaWrapper-mini').find('.draggable').unbind('click');
          $('#captchaWrapper-mini').find('.targetWrapper').children('.target').hide();
          $(this).removeClass('draggable');
          $(this).addClass('target');
          $('#captchaWrapper-mini').find('.targetWrapper').html($(this));

          //Check captcha answer
          $.post(Drupal.settings.basePath + 'draggable-captcha-mini/'+Drupal.settings.draggable_captcha_mini.captcha_sid+'/verify', { action: 'verify', captcha: $(this).attr('id') }, function(data) {
            if (data.status == "success") {
              $('#captchaWrapper-mini').find('.targetWrapper').addClass('captchaSuccess').hide().fadeIn('slow');
            } else {
              $('#captchaWrapper-mini').find('.targetWrapper').addClass('captchaFail').hide().fadeIn('slow');
            }
          }, 'json');
        });

      });
    }
  }
})(jQuery);
