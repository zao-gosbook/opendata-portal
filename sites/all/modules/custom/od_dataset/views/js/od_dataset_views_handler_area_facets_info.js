(function($) {
  Drupal.behaviors.od_dataset_views_handler_area_facets_info = {
    attach: function(context, settings) {
      $('.selected-filters-wrapper', context).once('od-dataset-views-handler-area-facets-info', function() {
        var $mainWrapper = $(this);
        $mainWrapper
          .find('.filter-items-wrapper .filter-item-wrapper a')
          .bind('click', function(e) {
            e.preventDefault();

            var $this = $(this);
            var $box = $this.parents('.filter-wrapper:eq(0)');
            var targetDataFacet = $this.attr('data-facet-target');
            var $targetFacets = $('[name="' + targetDataFacet + '"]');
            $targetFacets.trigger('click');

            // Immediately remove wrapper element
            $box.remove();

            if ($mainWrapper.find('.filter-wrapper').length == 0) {
              $mainWrapper.addClass('empty');
            }
          });
      })
    }
  }
}) (jQuery);