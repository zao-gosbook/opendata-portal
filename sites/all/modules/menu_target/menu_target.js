// $Id: menu_target.js, v 7.0, 2011/06/17 09:07:27, skilip Exp $

(function ($) {

  /**
   * Attaches 'open in new window' behavior to links with the 'target-blank' class.
   * This is used as a replacement of the regular 'target' attribute which is depricated 
   * since XHTML 1.1.
   */
  Drupal.behaviors.targetBlank = {
    attach: function (context, settings) {

      $('a.target-blank', context).once('target-blank', function () {
        $(this).click(function() {
          window.open(this.href);
          return false;
        });
      });
    }
  };

})(jQuery);
