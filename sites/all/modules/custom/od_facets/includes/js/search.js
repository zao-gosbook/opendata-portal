(function ($) {

  Drupal.behaviors.odFacetsWidgetLinksSearch = {
    attach: function (context, settings) {
      var $uls = $('.opendata-ajax-links-facet-searchable').once('facet-search');

      $uls.each(function(index, element) {
        var $ul = $(this);
        var $wrapper = $ul.parent();
        var $div = $wrapper.find('.search-block-wrapper');
        if ($div.length == 0) {
          var $div = $('<div></div>');
          var $input = $('<input />');

          $div
            .addClass('search-block-wrapper');

          $input
            .attr('type', 'text')
            .attr('placeholder', Drupal.t('Search'));

          $input.appendTo($div);
          $wrapper.prepend($div);
        }

        $div.find('input').fastLiveFilter('#' + $ul.attr('id'), {
          //'selector' : 'div>label'
        });

        console.log($ul.attr('id'));
      });
    }
  }

}) (jQuery);
