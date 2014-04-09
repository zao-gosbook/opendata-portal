ymaps.ready(function () {
  ymaps.option.presetStorage.add('custom#examplePreset1', {
    iconLayout: 'default#image',
    iconImageHref: 'http://api.yandex.ru/maps/doc/jsapi/2.x/examples/images/myIcon.gif',
    iconImageSize: [30, 42],
    iconImageOffset: [-3, -42]
  });
  ymaps.option.presetStorage.add('custom#examplePreset2', {
    iconLayout: 'default#image',
    iconImageHref: 'http://api.yandex.ru/maps/jsbox/examples/maps/ru/geolocation_api/images/man.png',
    iconImageSize: [27, 26],
    iconImageOffset: [-10, -24]
  });
  // ...
});
