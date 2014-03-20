(function($) {
  Drupal.behaviors.od_common_od_map_page = {
    attach: function(context, settings) {
      $('.od_common_module_od_map_page_render_selector', context).parent().once('od-common-od-map-page', function() {
        var $wrapper = $(this);

        var $radios = $wrapper.find('input');
        var nameAtrr = $radios.eq(0).attr('name');
        var cookieName = nameAtrr;
        $radios.bind('click', function() {
          var $this = $(this);
          var val = $(this).val(); //$wrapper.find('input[name="' + nameAtrr + '"]').val();

          var $exposedBlock = $('.views-exposed-widgets');
          var $targets = {
            0: $exposedBlock.find('.views-widget-filter-field_organization_target_id'),
            1: $exposedBlock.find('.views-widget-filter-field_geolocation_distance')
          }

          if (val == 0) {
            $targets[1].hide();
          }
          else {
            $targets[0].hide();
          }

          $targets[val].show();
          $.cookie(cookieName, val);
        });

        var val = $.cookie(cookieName);
        if (!isNaN(val)) {
          $radios.filter('[value="'+val+'"]').click();
        }
        else {
          $radios.filter('input:checked').click();
        }
      });
    }
  }
}) (jQuery);