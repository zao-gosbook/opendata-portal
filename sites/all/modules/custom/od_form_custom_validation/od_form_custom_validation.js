(function($) {
  Drupal.behaviors.od_common_multi_download_links = {
    attach: function(context, settings) {

      $('div.form-item-field-dataset-id-und-0-value').append('<div id="checkit"><button type="submit" class="btn btn-default">Проверить</button></div>');
      $( ":input[id='edit-field-dataset-id-und-0-value']" )
        .change(function () {
          $(this).submit();
        });

    }
  }
  }) (jQuery);