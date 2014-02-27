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

    $('.field-name-field-dataset-convert input', context).bind('click', function() {
      processConvertState();
    });

    function processConvertState() {
      var $fileData = $('.od-preprocess-filedata', context);
      var needConvert = $('.field-name-field-dataset-convert input:checked', context).val();
      if (needConvert == 1) {
        $fileData.show();
      }
      else {
        $fileData.hide();
      }
    }

    processConvertState();
    $('.field-name-field-dataset-convert input', context).trigger();
  }
};
})(jQuery);
