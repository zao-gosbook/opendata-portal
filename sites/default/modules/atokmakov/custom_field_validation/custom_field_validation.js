(function ($) {

Drupal.behaviors.customFieldValidation = {
  attach: function (context) {

    // Set variables.
    var span_required = '<span class="form-required">*</span>';
    var FieldValidationRequiringElement = $('.validation-requiring-element input');

    // Try select control
    if (!FieldValidationRequiringElement.length) 
      FieldValidationRequiringElement = $('.validation-requiring-element select');

    // Init fields.
    $(FieldValidationRequiringElement).each(function () {
      FieldValidationFormControl($(this), false);
    });

    // Set callback for requiring field change event
    FieldValidationRequiringElement.change(function() {
      FieldValidationFormControl($(this), true);
    });

    function FieldValidationFormControl(init_element, animate) {
      var duration = animate ? 600 : 0;
      var init_element_info = elementInfo(init_element);
      var elements = $(init_element).parents('form').find('[id*=' + init_element_info['selector'] + ']');
      var fields = [];

      $(elements).each(function(a, element) {
        element_info = elementInfo(element);
        $.each(element_info['value'], function(b, value) {
          $('.validation-' + element_info['selector'] + value).each(function(c, field) {
            if ($.inArray($(field).attr('id'),fields) == -1) fields.push($(field).attr('id'));
          });
        });
      });
      
      $('div[class*=validation-' + init_element_info['selector'] + ']').each(function(a, field) {
        if ($.inArray($(field).attr('id'), fields) > -1) {
          // Fiels is required
          if (!$(field).find('span.form-required').length)
            $(field).find('label').append(span_required);
        } else {
          // Field is not required
          $(field).find('span.form-required').remove();
          $(field).find('input').removeClass('error');
        }
      });
      
      $(elements).each(function(a, element) {
        element_info = elementInfo(element);
        $.each(element_info['value'], function(b, value) {
          $('.visible-' + element_info['selector'] + value).each(function(c, field) {
            if ($.inArray($(field).attr('id'),fields) == -1) fields.push($(field).attr('id'));
          });
        });
      });
      
      $('div[class*=visible-' + init_element_info['selector'] + ']').each(function(a, field) {
        if ($.inArray($(field).attr('id'), fields) > -1) {
          // Fiels is visible
          if (animate) {
            $(field).show(duration);
          } else {
            $(field).attr('style', 'display:block');
          }
        } else {
          // Field is not visible
          if (animate) {
            $(field).hide(duration);
            $('input', field).attr('value', '').trigger('change');
            $('input', field).attr('checked', false).trigger('change');
            $('select', field).val('').trigger('change');
          } else {
            $(field).attr('style', 'display:none');
          }
        }
      });
    }
    
    function elementInfo(element) {
      var result = [];
      var type = $(element).attr('type');
      var id = $(element).attr('id');
      
      if (type == 'radio') {
        result['value'] = $(element).attr('value');
        result['selector'] = id.slice(0, -result['value'].length);
        result['value'] = ($(element).attr('checked')) ? [result['value']] : [];
      }
      
      if (type == 'checkbox') {
        if ($(element).parents('div.form-item').hasClass('form-type-checkboxes')) {
          result['value'] = $(element).val();
          result['selector'] = id.slice(0, -result['value'].length);
          result['value'] = ($(element).attr('checked')) ? [result['value']] : [];
        } else {
          result['value'] = ($(element).attr('checked')) ? ['-1'] : ['-0'];
          result['selector'] = id;
        }
      }

      if ($(element).attr('type').substr(0,6) == 'select') {
        result['selector'] = id;
        result['value'] = [];
        values = $(element).val();
        if (values) {
          if (typeof values === 'string') {
            result['value'] = ['-' + values];
          } else {
            $.each(values, function(a, value) {
              result['value'].push('-' + value);
            });
          }
        }
      }
      
      return result;
    }  
  }
};
})(jQuery);
