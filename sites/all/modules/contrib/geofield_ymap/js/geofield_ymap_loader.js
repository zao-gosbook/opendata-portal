(function ($) {
  Drupal.behaviors.geofieldYmapLoader = {
    attach: function (context, settings) {
      if (!Drupal.geofieldYmap && !window.ymaps && $('div.geofield-ymap').length > 0) {
        var scripts = [
          '//api-maps.yandex.ru/2.1-dev/?lang=ru-RU&load=package.full&coordorder=longlat',
          Drupal.settings.geofieldYmap.modulePath + '/js/geofield_ymap.js'
        ];
        if (Drupal.settings.geofieldYmap.presetsPath) {
          scripts.push(Drupal.settings.basePath + Drupal.settings.geofieldYmap.presetsPath);
        }

        Drupal.geofieldYmapLoader.getScripts(scripts, function () {
          Drupal.attachBehaviors(document);
        });
      }
    }
  };

  Drupal.geofieldYmapLoader = Drupal.geofieldYmapLoader || {
    getScripts: function (scripts, callback, index) {
      index = index || 0;
      $.getScript(scripts[index], function () {
        index++;
        if (scripts.length > index) {
          Drupal.geofieldYmapLoader.getScripts(scripts, callback, index);
        }
        else {
          callback();
        }
      });
    }
  };
})(jQuery);
