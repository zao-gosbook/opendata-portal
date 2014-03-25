(function($) {
  Drupal.behaviors.od_common_multi_download_links = {
    attach: function(context, settings) {
      var $box = $('.multi-download-link-wrapper', context);
      $box.find('.main-download-link-wrapper>a').bind('click', function(e) {
        e.preventDefault();

        var $this = $(this);
        var $wrapper = $this.parents('.multi-download-link-wrapper:eq(0)');
        var $dropdownLinks = $wrapper.find('.dropdown-links');
        var isExpanded = $dropdownLinks.hasClass('state-expanded') ? true : false;
        if (isExpanded) {
          collapse($dropdownLinks);
        }
        else {
          expand($dropdownLinks);
        }
      })

      // Collapse all by default
      collapse($box.find('.dropdown-links'));
      function collapse($dropdownLinks) {
        $dropdownLinks.slideUp();
        $dropdownLinks.removeClass('state-expanded');
        $dropdownLinks.addClass('state-collapsed');
      }

      function expand($dropdownLinks) {
        $dropdownLinks.removeClass('element-invisible');
        $dropdownLinks.slideDown();
        $dropdownLinks.removeClass('state-collapsed');
        $dropdownLinks.addClass('state-expanded');
      }
    }
  }
}) (jQuery);