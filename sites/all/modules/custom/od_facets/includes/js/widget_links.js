(function ($) {

  Drupal.behaviors.odFacetsWidgetLinks = {
    attach: function (context, settings) {
      // Identify "opendata ajax links" facet for "apps" index.
      var opendataAjaxLinksFacet = $('.opendata-ajax-links-facet', context);

      // Identify "latest apps" panel.
      var latestAppsPanel = $('.view-display-id-10_latests_apps', context).parent();
      // Identify "rated apps" block.
      var ratedAppsPanel = $('.view-display-id-top_rated_apps', context).parent();

      // Bind  checkbox clicking.
      $('input', opendataAjaxLinksFacet).bind('click', function() {
        // Get current list item.
        var li = $(this).closest('li');

        // Add/remove "facetapi-active" class.
        if ($(this).is(':checked')) {
          li.addClass('facetapi-active');
        }
        else {
          li.removeClass('facetapi-active');
        }

        // Hide/show additional blocks. They should be hidden if facet is selected.
        if ($('.facetapi-active', opendataAjaxLinksFacet).length > 0) {
          latestAppsPanel.hide();
          ratedAppsPanel.hide();
        }
        else {
          latestAppsPanel.show();
          ratedAppsPanel.show();
        }
      });
    }
  }

}) (jQuery);
