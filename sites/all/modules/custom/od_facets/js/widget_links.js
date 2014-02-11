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

        var $recommendBlock = $(context).find('.view-display-id-standard_datasets').parent();
        if ($(context).find('.facet-wrapper-checkboxes input:checkbox:checked').length > 0) {
          $recommendBlock.hide();
        }
        else {
          $recommendBlock.show();
        }
      });

//      var ajax = new Drupal.ajax(false, false, {
//        event: 'change',
//        url: 'od_test'
//      });


    }
  }
}) (jQuery);