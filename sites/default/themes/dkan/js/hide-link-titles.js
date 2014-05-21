(function ($, Drupal, window, document, undefined) {

    Drupal.behaviors.HideLinkTitles = {
        attach: function (context) {
            if ($(window).width() >= 1580) {
                $('.pane-system-user-menu ul li').each(function() {
                  $(this).find('a').attr('data-title', $(this).find('a').attr('title'));
                  $(this).find('a').attr('title', '');
                });
            }
        }
    }
})(jQuery, Drupal, this, this.document);
