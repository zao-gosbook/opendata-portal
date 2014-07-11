
(function($) {
    Drupal.behaviors.od_common_od_page_apps = {
        attach: function(context, settings) {
            // Context parameter is omitted intentionally.
            $('.view-apps-search-api .view-header').each(function() {
                $('.pane-views-exp-apps-search-api-apps .view-header').remove();
                $('.pane-views-exp-apps-search-api-apps').prepend($('.view-apps-search-api .view-header').detach());
            });
        }
    };
}) (jQuery);
