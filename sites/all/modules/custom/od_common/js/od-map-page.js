(function($) {
  Drupal.behaviors.od_common_od_map_page = {
    attach: function(context, settings) {
      $('.od_common_module_od_map_page_render_selector', context).parent().once('od-common-od-map-page', function() {
        var $wrapper = $(this);

        var $radios = $wrapper.find('input');
        $radios.bind('click', function() {
          var $this = $(this);
          var val = $wrapper.find('input[name="' + $this.attr('name') + '"]').val();

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
        });

        $wrapper.find('input:checked').trigger('click');
      });
    }
  }
}) (jQuery);