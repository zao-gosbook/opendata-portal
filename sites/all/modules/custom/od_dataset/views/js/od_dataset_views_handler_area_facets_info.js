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
            var $box = $this.parents('.filter-item-wrapper:eq(0)');
            var targetDataFacet = $this.attr('data-facet-name') + ':' + $this.attr('data-facet-value');
            var $targetFacets = $('[name="' + targetDataFacet + '"]');
            if ($targetFacets.length > 0) {
              $targetFacets.trigger('click');

              // Immediately remove wrapper element
              $box.remove();

              if ($mainWrapper.find('.filter-wrapper').length == 0) {
                $mainWrapper.addClass('empty');
              }
            }
          });
      })
    }
  }
}) (jQuery);