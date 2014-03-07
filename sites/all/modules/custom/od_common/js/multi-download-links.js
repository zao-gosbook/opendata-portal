(function($) {
  Drupal.behaviors.od_common_multi_download_links = {
    attach: function(context, settings) {
      var $box = $('.multi-download-link-wrapper', context);
      var $dropdownLinks = $box.find('.dropdown-links');
      $box.find('.main-download-link-wrapper>a').bind('click', function(e) {
        e.preventDefault();
        var isExpanded = $dropdownLinks.hasClass('state-expanded') ? true : false;
        if (isExpanded) {
          collapse();
        }
        else {
          expand();
        }
      })

      // Collapse by default
      collapse();
      function collapse() {
        $dropdownLinks.slideUp();
        $dropdownLinks.removeClass('state-expanded');
        $dropdownLinks.addClass('state-collapsed');
      }

      function expand() {
        $dropdownLinks.removeClass('element-invisible');
        $dropdownLinks.slideDown();
        $dropdownLinks.removeClass('state-collapsed');
        $dropdownLinks.addClass('state-expanded');
      }
    }
  }
}) (jQuery);