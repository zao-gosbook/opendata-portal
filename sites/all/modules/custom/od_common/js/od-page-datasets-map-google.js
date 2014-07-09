
(function($) {
  Drupal.behaviors.od_common_od_page_datasets_map_google = {
    attach: function(context, settings) {
      $('.page-datasets-map-google', context).once(function() {
        var but = $('#edit-submit-datasets-map').clone();
        but.attr('type', 'button');
        $('#edit-submit-datasets-map').parent().append(but);
        $('#edit-submit-datasets-map').remove();


        function submit() {
          $('#views-exposed-form-datasets-map-google-map').submit();
        }

        $('#edit-submit-datasets-map').unbind().click(function(){

          var e = jQuery.Event("keypress");
          e.which = 13; //choose the one you want
          e.keyCode = 13;
          $("#edit-field-geolocation-distance-googlemap-address-field:input").trigger(e);

          setTimeout(submit, 800);
        });
      });
    }
  }
}) (jQuery);