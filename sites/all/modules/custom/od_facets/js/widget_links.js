(function ($) {
  Drupal.behaviors.odFacetsWidgetLinks = {
    attach: function (context, settings) {
      $(context).find('ul.facetapi-od-facetapi-ajax-links>li input.facet-multiselect-checkbox').bind('click', function(e) {
        var $this = $(this);
        var li = $this.parents('li:eq(0)');

        if ($this.is(':checked')) {
          li.addClass('facetapi-active');
        }
        else {
          li.removeClass('facetapi-active');
        }
      });
    }
  }
}) (jQuery);