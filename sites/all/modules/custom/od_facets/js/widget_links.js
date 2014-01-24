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

      //Ugly warkaround against bug with getting placeholder value with val()
      if ($.valHooks !== undefined && typeof $.valHooks == 'object') {
        $.valHooks.text = jQuery.valHooks['text'] === undefined ? new Object() : $.valHooks.text;
        $.valHooks.text.get =  function (a) {
          return a.getAttribute('value');
        }

        $.valHooks.text.set = function (a, b) {
          return a.setAttribute('value', b);
        }
      }
    }
  }
}) (jQuery);