(function ($) {

var uuid = 0;

Drupal.behaviors.ddf = {
  attach: function (context, settings) {
    for (var id in settings.ddf) {
      var form_id = id;
      var form = $('input[value="' + form_id + '"]', context).parents('form');
      if (form.length == 0) {
        continue;
      }

      var dependent = settings.ddf[form_id]['dependent'];
      var fields = settings.ddf[form_id]['fields'];
      var elements = {};

      if (dependent) {
        for (var field_name in dependent) {
          var element = form.find('[name="' + dependent[field_name] + '"],[name="' + dependent[field_name] + '[]"]');
          if (element.length == 1) {
            var dependent_id = element.attr('id');
            if (!dependent_id) {
              uuid++;
              dependent_id = 'ddf-uuid-' + uuid;
            }
            dependent[field_name] = '#' + dependent_id;
          }
          else {
            dependent[field_name] = '#' + form.attr('id') + ' [name="' + element.attr('name') + '"]';
          }
        }
      }

      if (fields) {
        for (var field_name in fields) {
          var element = form.find('[name="' + fields[field_name] + '"],[name="' + fields[field_name] + '[]"]');
          if (element.length > 0) {
            elements[field_name] = element;

            var ajax = new Drupal.ajax(false, element, {
              event: 'change',
              url: settings['basePath'] + 'ddf/update/' + field_name + '/' + settings.ddf[form_id]['entity_type'] + '/' + settings.ddf[form_id]['bundle'] +
                '/' + settings.ddf[form_id]['entity_id']
            });

            ajax.beforeSerialize = function(element, options) {
              options.type = 'GET';
              options.data = {};
              for (var fn in elements) {
                var value = elements[fn].fieldValue();
                value = (value.length > 0) ? value[0] : 'NULL';
                options.data[fn] = value;
              }
              options.data['form_build_id'] = form_id;
              for (var fn in dependent) {
                options.data['dep:' + fn] = dependent[fn];
              }
            };

          }
        }
      }
    }
  }
}

/**
 * Command to insert new content into the DOM without wrapping in extra DIV element.
 */
Drupal.ajax.prototype.commands.insertnowrap = function (ajax, response, status) {
  // Get information from the response. If it is not there, default to
  // our presets.
  var wrapper = response.selector ? $(response.selector) : $(ajax.wrapper);
  var method = response.method || ajax.method;
  var effect = ajax.getEffect(response);

  // We don't know what response.data contains: it might be a string of text
  // without HTML, so don't rely on jQuery correctly iterpreting
  // $(response.data) as new HTML rather than a CSS selector. Also, if
  // response.data contains top-level text nodes, they get lost with either
  // $(response.data) or $('<div></div>').replaceWith(response.data).
  var new_content_wrapped = $('<div></div>').html(response.data);
  var new_content = new_content_wrapped.contents();

  // If removing content from the wrapper, detach behaviors first.
  switch (method) {
    case 'html':
    case 'replaceWith':
    case 'replaceAll':
    case 'empty':
    case 'remove':
      var settings = response.settings || ajax.settings || Drupal.settings;
      Drupal.detachBehaviors(wrapper, settings);
  }

  // Add the new content to the page.
  wrapper[method](new_content);

  // Immediately hide the new content if we're using any effects.
  if (effect.showEffect != 'show') {
    new_content.hide();
  }

  // Determine which effect to use and what content will receive the
  // effect, then show the new content.
  if ($('.ajax-new-content', new_content).length > 0) {
    $('.ajax-new-content', new_content).hide();
    new_content.show();
    $('.ajax-new-content', new_content)[effect.showEffect](effect.showSpeed);
  }
  else if (effect.showEffect != 'show') {
    new_content[effect.showEffect](effect.showSpeed);
  }

  // Attach all JavaScript behaviors to the new content, if it was successfully
  // added to the page, this if statement allows #ajax['wrapper'] to be
  // optional.
  if (new_content.parents('html').length > 0) {
    // Apply any settings from the returned JSON if available.
    var settings = response.settings || ajax.settings || Drupal.settings;
    Drupal.attachBehaviors(wrapper, settings);
  }
};

})(jQuery);
