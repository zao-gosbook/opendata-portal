(function ($) {

Drupal.behaviors.opendataFilePreprocess = {
  attach: function (context) {
    $('input[type="radio"]', context).bind('click', function(){
      submit();
    });
    
    function submit() {
      $('input[type="submit"]').click();
    }
  }
};
})(jQuery);
