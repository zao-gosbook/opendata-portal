(function($) {
  /**
   * Represents the loading animation.
   */
  Loadinganimation = function(context, settings) {
    this.settings = settings;
    this._init = function(context) {
      // Exclude subselectors.
      if (settings.subselector != '') {
        var subselectorSuffix = ' ' + settings.subselector;
      } else {
        var subselectorSuffix = '';
      }
      // Show on href click!
      if (Drupal.settings.jquery_loadinganimation.show_on_href) {
        // Exclude some further cases that shell not trigger.
        $(context)
            .find("a[href]" + settings.subselector)
            .not('a[href*="javascript:"]')
            .not('a[href^="#"]')
            .not(".noLoadingAnimation")
            .each(
                function(i, element) {
                  // Only trigger links that have no js events registered.
                  if (typeof $(this).data("events") == 'undefined'
                      || jQuery.isEmptyObject($(this).data("events"))) {
                    $(this)
                        .click(
                            function(eventObject) {
                              // Nicht bei Öffnen in neuem Tab (Strg+Klick)
                              if (!eventObject.ctrlKey) {
                                Drupal.behaviors.jquery_loadinganimation.Loadinganimation
                                    .show();
                              }
                            });
                  }
                });
      }

      // Show on form submit
      if (Drupal.settings.jquery_loadinganimation.show_on_form_submit) {
        // Only execute if no other js events are registered to prevent cases
        // where page is not being reloaded and layer does not close though.
        $(context).find("form" + subselectorSuffix).submit(function() {
          Drupal.behaviors.jquery_loadinganimation.Loadinganimation.show();
          $(context).ajaxStop(function() {
            // Hide loading animation after ALL ajax events have finished
            Drupal.behaviors.jquery_loadinganimation.Loadinganimation.hide();
          });
        });
      }

      // Show on AJAX
      if (context == document) {
        // Global context!
        if (Drupal.settings.jquery_loadinganimation.show_on_ajax) {
          // Register loading animations for ajax events!
          $(context).ajaxStart(function() {
            // Show loading animation on request.
            Drupal.behaviors.jquery_loadinganimation.Loadinganimation.show();
          });

          $(context).ajaxStop(function() {
            // Hide loading animation after finish.
            Drupal.behaviors.jquery_loadinganimation.Loadinganimation.hide();
          });
        }
      }

      // Hide on animation click!
      if (Drupal.settings.jquery_loadinganimation.close_on_click) {
        $("div#loadinganimation").live('click', function() {
          Drupal.behaviors.jquery_loadinganimation.Loadinganimation.hide();
        });
      }

      // Hide on ESC press.
      if (Drupal.settings.jquery_loadinganimation.close_on_esc) {
        $(document).keyup(function(event) {
          var keycode = event.which;
          if (keycode == 27) { // escape, close box
            Drupal.behaviors.jquery_loadinganimation.Loadinganimation.hide();
          }
        });
      }
    };

    // Initialize!
    this._init(context);

    // Register global Drupal.behaviors.jquery_loadinganimation.Loadinganimation
    // object after init!
    Drupal.behaviors.jquery_loadinganimation.Loadinganimation = this;

    // Preload images.
    jQuery.preload_images(Drupal.settings.basePath
        + Drupal.settings.jquery_loadinganimation.img_src);

    /**
     * Displays the loading animation.
     */
    this.show = function() {
      // Only show if not already shown.
      if ($("div#loadinganimation").length == 0) {
        $("body")
            .append(
                '<div id="loadinganimation"><div class="border top"></div><div class="inner"><img class="first" src="'
                    + Drupal.settings.basePath
                    + Drupal.settings.jquery_loadinganimation.img_src
                    + '" alt="'
                    + Drupal.t('Loading')
                    + '..." /><img class="second" src="'
                    + Drupal.settings.basePath
                    + Drupal.settings.jquery_loadinganimation.img_src
                    + '" alt="'
                    + Drupal.t('Loading')
                    + '..." /><img class="third" src="'
                    + Drupal.settings.basePath
                    + Drupal.settings.jquery_loadinganimation.img_src
                    + '" alt="'
                    + Drupal.t('Loading')
                    + '..." /><br />'
                    + Drupal.t('Loading')
                    + '...</div><div class="border bottom"></div></div>');
      }
    };

    /**
     * Hides the loading animation.
     */
    this.hide = function() {
      $("div#loadinganimation").remove();
    };
  };

  /**
   * Preload images via jQuery.
   */
  (function($) {
    var images_cache = [];
    // Arguments are image paths relative to the current page.
    $.preload_images = function() {
      var arg_length = arguments.length;
      for ( var i = arg_length; i--;) {
        var image_to_cache = document.createElement('img');
        image_to_cache.src = arguments[i];
        images_cache.push(image_to_cache);
      }
    };
  })(jQuery);

  /**
   * Initialization
   */
  Drupal.behaviors.jquery_loadinganimation = {
    /**
     * Run Drupal module JS initialization.
     * 
     * @param context
     * @param settings
     */
    attach : function(context, settings) {
      // Initialize general loading animation.
      Drupal.behaviors.jquery_loadinganimation.Loadinganimation = new Loadinganimation(
          context, settings.jquery_loadinganimation);
    }
  };
})(jQuery);