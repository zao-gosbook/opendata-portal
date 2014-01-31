(function ($) {
  Drupal.behaviors.od_cell_popup_popup = {
    attach: function (context, settings) {
      var $context = $(context);
      var actionsWrapper = $context.find('.od-common-popup-cell-actions-wrapper:eq(0)');

      actionsWrapper.find('a.actionsWrapper');
      function getCells() {
        return $('.recline-data-explorer>.data-view-container .slick-viewport>.grid-canvas .slick-cell', context);
      }

      getCells().ready(function(e) {
        setTimeout(main, 500);
      });

      function main() {
        var cells = getCells();
        cells.unbind('click');
        cells.bind('click', function() {
          var $this = $(this);
          if ($this.hasClass('editing-mode')) {
            return;
          }

          var rowNum = $this.parent().attr('row');

          var re = new RegExp('r([0-9]+)$', 'i')
          var colNum = re.exec($this.attr('class'))[1];

          cells.trigger('blur');
          var $input = $this.find('.type-edit');
          var $span = $this.find('.type-view');
          if ($span.length == 0 || $input.length == 0) {
            $input = $('<input />');
            $span = $('<span></span>');

            $input
              .attr('type', 'text')
              .attr('value', $this.html())
              .addClass('type-edit');

            $input.tipTip({
              activation: 'click',
              content: getTipContent(rowNum, colNum),
              keepAlive: true
            });

            $span
              .addClass('type-view');
            $span.html($this.html());

            //Destory content
            $this.html('');

            //Add new content
            $this.append($input);
            $this.append($span);

            //Mark as processed
            $this.addClass('modified-with-input');
          }

          $input.html($span.html());
          $span.hide();
          $input.show();

          $this.addClass('editing-mode');
        });

        cells.bind('blur', function() {
          var $this = $(this);
          var $input = $this.find('.type-edit');
          var $span = $this.find('.type-view');
          if ($span.length == 0 || $input.length == 0) {
            return false;
          }

          $this.removeClass('editing-mode');
          $input.hide();
          $span.show();
        });
      }

      function getTipContent(rowNum, colNum) {
        var href = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'eform/submit/dataset-error-report?field_ds_report_row‎='+ rowNum +'&field_ds_report_col‎='+ colNum;
        var content = '\
        <div class="od-common-popup-cell-actions-wrapper">\
          <div class="tip-tip-actions-wrapper">\
          <span class="action-error-report"><a href="'+ href +'" target="_new">'+ Drupal.t('Send an error report') +'</a></span>\
          </div>\
        </div>\
        ';

        return content;
      }
    }
  }
}) (jQuery);