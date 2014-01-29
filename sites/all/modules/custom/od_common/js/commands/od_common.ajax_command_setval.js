(function($) {
  Drupal.ajax.prototype.commands.setval = function (ajax, response, status) {
    var $element = $(response.selector);
    $element.val(response.value);
  }
}) (jQuery);