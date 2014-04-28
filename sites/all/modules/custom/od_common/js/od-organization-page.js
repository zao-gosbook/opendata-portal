(function($) {
    Drupal.behaviors.od_common_od_map_page = {
        attach: function(context, settings) {
            $('.od_common_module_od_organization_page_render_selector', context).parent().once('od-common-od-organization-page', function() {
                var $wrapper = $(this);

                var $select = $wrapper.find('select');
                var nameAtrr = $select.attr('name');
                var cookieName = nameAtrr;
                $select.bind('change', function() {
                    var $this = $(this);
                    var $formItem = $this.parents('.form-item:eq(0)');
                    var val = $this.val();

                    var $exposedBlock = $('.views-exposed-widgets');
                    var $targets = {
                        0: $exposedBlock.find('.views-widget-filter-title'),
                        1: $exposedBlock.find('.views-widget-filter-field_organization_short_name_value'),
                        2: $exposedBlock.find('.views-widget-filter-field_organization_inn_value')
                    }

                    if (val == 0) {
                        $targets[1].hide();
                        $targets[2].hide();
                        $('input#edit-field-organization-short-name-value').attr('value', '');
                        $('input#edit-field-organization-inn-value').attr('value', '');
                    }
                    if (val == 1) {
                        $targets[0].hide();
                        $targets[2].hide();
                        $('input#edit-title').attr('value', '');
                        $('input#edit-field-organization-inn-value').attr('value', '');
                    }
                    if (val == 2) {
                        $targets[0].hide();
                        $targets[1].hide();
                        $('input#edit-title').attr('value', '');
                        $('input#edit-field-organization-short-name-value').attr('value', '');
                    }

                    $targets[val].show();

                    var $form = $('.view-filters form');
                    $form.removeClass('active-tab-0').removeClass('active-tab-1').addClass('active-tab-' + val);

                    $this.parent().addClass('active-element');
                    $.cookie(cookieName, val);
                });

                var val = $.cookie(cookieName);
                if (val === null || isNaN(val)) {
                    val = 0; //Default
                }

                $select.trigger('change');
            });
        }
    }
}) (jQuery);