(function($) {  
  var TextSlider = TextSlider || {};         
  /**
  * Initialize the Text slider.
  */
  TextSlider.init = function() {    
    for (var node_id in Drupal.settings.textSlider) {            
      var field_name = Drupal.settings.textSlider[node_id].field_name;
      var pager_type = Drupal.settings.textSlider[node_id].pager_type;
      var css_node_id = '#' + node_id;
      //alert(pager_type);
      var items = $(css_node_id + ' .field-name-' + field_name + ' .field-item');      
      var pager_items = $(css_node_id + ' .field-type-node-display-fields ul.' + field_name + ' a.pager-item:not(.pager-prev,.pager-next)');            
      // If we don't have enough  
      if (items.size() <= 1) {      
        return;
      }
      // find the highest container
      var highest = 30;
      items.each(function () {
      var sliderHeight = $(this).height();
        if(sliderHeight > highest) {
        highest = sliderHeight;
        }
      });        
      $(css_node_id + ' .field-name-' + field_name + ' .field-item').css('height', highest + 'px');    
      // hide all containers except first
      // all containers has been hidden through css (in text_slider.css file) /$(css_node_id + ' .field-name-' + field_name + ' .field-item:not(:first)').hide();          
      // pager handlers to switch between containers - pass items and field_name + exclude prev-next arrows
      $(css_node_id + ' .field-type-node-display-fields ul.' + field_name + ' a.pager-item:not(.pager-prev,.pager-next)').click({items: items, field_name: field_name, css_node_id: css_node_id}, function(event) {
        var items = event.data.items;
        var field_name = event.data.field_name;  
        var css_node_id = event.data.css_node_id;  
        
        var item_index = $(this).attr('rel');            
        $(css_node_id + ' .field-type-node-display-fields ul.' + field_name + ' a').removeClass('pager-current');
        $(this).addClass('pager-current');                
        items.hide().eq(item_index).show();
        
        return false;
      });  
      if (pager_type == 'normal') {
        var pager_arrows = $(css_node_id + ' .field-type-node-display-fields ul.' + field_name + ' a.pager-item').filter('.pager-prev,.pager-next');
        // prev-next arrows handlers
        $(css_node_id + ' .field-type-node-display-fields ul.' + field_name + ' a.pager-prev,'+ css_node_id + ' .field-type-node-display-fields ul.' + field_name + ' a.pager-next').click({pager_items: pager_items, pager_arrows: pager_arrows}, function(event) {          
          var pager_items = event.data.pager_items;
          var pager_arrows = event.data.pager_arrows;
          
          if ($(this).hasClass('inactive')) { return false; }
          
          var max_pager_index = pager_items.size() - 1;
          var current_item_index = $(this).parent().parent().find('.pager-current').attr('rel');              
          if ($(this).hasClass('pager-prev')) {                        
            var prev_index = parseInt(current_item_index) - 1;            
            pager_items.eq(prev_index).trigger('click');            
            if (prev_index == 0) {
              $(this).addClass('inactive');
            }
          } else if ($(this).hasClass('pager-next')) {   
            pager_arrows.removeClass('inactive');
            var next_index = parseInt(current_item_index) + 1;            
            pager_items.eq(next_index).trigger('click');            
            if (next_index == max_pager_index) {
              $(this).addClass('inactive');
            }
          }
          
          return false;
        });
        // add inactive class to Prev-Next links
        $(css_node_id + ' .field-type-node-display-fields ul.' + field_name + ' a.pager-item').click({pager_items: pager_items, pager_arrows: pager_arrows}, 
          function(event) {
            var pager_items = event.data.pager_items;
            var pager_arrows = event.data.pager_arrows;
            var max_pager_index = pager_items.size() - 1;            
            pager_arrows.removeClass('inactive');
            var current_item_index = $(this).parent().parent().find('.pager-current').attr('rel');              
            if (current_item_index == 0) {
              pager_arrows.eq(0).addClass('inactive');
            } else if (current_item_index == max_pager_index) {
              pager_arrows.eq(1).addClass('inactive');
            }
        });
      }      
    }
  };
  
  Drupal.behaviors.NDFSlider = {
    attach: function () {                 
      TextSlider.init();      
    }
  };  
})(jQuery);