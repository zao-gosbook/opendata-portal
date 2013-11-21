(function ($) {

Drupal.behaviors.opendataFilePreprocess = {
  attach: function (context) {

    function opendataFilePreprocessSetSelect(element) {
      if ($(element).val() == 'undefined') {
        $(element).addClass('error');
      } else {
        $(element).removeClass('error');      
      }    
    }
  
    $('select.od-preprocess-datatype-selector').each(function() {
      opendataFilePreprocessSetSelect(this);
      $(this).change(function() {
        opendataFilePreprocessSetSelect(this);
      });
    });
    
    
  }
};
})(jQuery);
