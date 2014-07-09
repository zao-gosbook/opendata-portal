(function($) {
  Drupal.behaviors.od_pubdlcnt__attacherjs = {
    attach: function (document_context, settings) {
      if (settings['od_pubdlcnt']['attacherjs']['contexts'] == undefined) {
        return;
      }

      var $box = $(document_context);
      function aClickHandler(e, preventClickDefault) {
        var stat_id = $(this).attr('dlcnt:data-stat-id');
        settings.od_pubdlcnt.attacherjs.locked = settings.od_pubdlcnt.attacherjs.locked || {};
        if (stat_id == undefined || settings.od_pubdlcnt.attacherjs.locked[stat_id] != undefined) {
          return true;
        }

        // Lock while ajax is not ready
        settings.od_pubdlcnt.attacherjs.locked[stat_id] = true;
        var callbackUrl = location.origin + settings.basePath + settings.od_pubdlcnt.attacherjs.callback_url;
        var ajax = new Drupal.ajax(false, false, {
          url: callbackUrl
        });

        var parentBeforeSerialize = ajax.beforeSerialize;
        ajax.beforeSerialize = function(element, options) {
          parentBeforeSerialize(element, options);
          options.data['stat_id'] = stat_id;
        };

        ajax.eventResponse(ajax, {});
      }

      for (var i in settings.od_pubdlcnt.attacherjs.contexts) {
        var context = settings.od_pubdlcnt.attacherjs.contexts[i];
        if (context['selector'] != undefined) {
          // Replace placeholders. @todo: Make separate function or method for replacing placeholders
          var selector = String(context.selector).replace(/\%STAT_ID\%/i, context.stat_id);
          $box.find(selector).once('od_pubdlcnt', function () {
            var $a = $(this);
            $a.attr('target', '_new');
            $a.bind('click', aClickHandler);
            $a.attr('dlcnt:data-stat-id', context.stat_id);
          });
        }
      }
    }
  }

  /**
   * Ajax delivery command.
   * Will be called after response to request done above.
   */
  Drupal.ajax.prototype.commands.odPubdlcntAttacherJS = function (ajax, response, status) {
    if (response.data != undefined) {
      if (response.data.stat_id != undefined) {
        // Unlock locked stat_id element to count links again
        Drupal.settings.od_pubdlcnt.attacherjs.locked[response.data.stat_id] = null;
      }
    }
  }
}) (jQuery);

