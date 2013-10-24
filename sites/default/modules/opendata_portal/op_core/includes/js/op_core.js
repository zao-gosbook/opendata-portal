(function ($) {

  Drupal.behaviors.opCoreOpendataList = {
    attach: function (context) {
      var opendataList = Drupal.settings.opCoreOpendataList;

      $('[typeof="foaf:Document"] a', context).click(function(){
        var parent = $(this).parents('[typeof="foaf:Document"]').first();
        var alias = parent.attr('about');
        if (alias) {
          document.location.href = opendataList[alias];
        }
        return false;
      })
    }
  };

})(jQuery);
