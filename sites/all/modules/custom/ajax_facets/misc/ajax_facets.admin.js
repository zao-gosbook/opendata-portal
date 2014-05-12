(function ($) {

Drupal.behaviors.ajax_facets_admin = {
  attach: function(context, settings) {
    // @see http://drupal.org/node/735528
    $('input[name="update_results"]').change(function() {
      if ($(this).attr('checked')) {
        $('input[name="update_results"]').attr('checked', 'checked');
      }
      else {
        $('input[name="update_results"]').removeAttr('checked');
      }
    });

    // @see http://drupal.org/node/735528
    $('input[name="show_reset_link"]').change(function() {
      if ($(this).attr('checked')) {
        $('input[name="show_reset_link"]').attr('checked', 'checked');
      }
      else {
        $('input[name="show_reset_link"]').removeAttr('checked');
      }
    });
  }
}

})(jQuery);
