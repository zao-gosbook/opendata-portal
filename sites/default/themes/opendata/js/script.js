/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.HintFormElemements = {
    attach: function (context) {      
      $('.entitytype-contact_form-form .form-text, .entitytype-contact_form-form .form-textarea', context).once(function(){        
        $('#field-contact-form-name-add-more-wrapper .form-text', context).attr("placeholder", "Ваше имя");                                 
        $('#edit-field-contact-form-e-mail .form-text', context).attr("placeholder", "E-mail или телефон для ответа");                                 
        $('#edit-field-contact-form-massage .form-textarea', context).attr("placeholder", "Сообщение");     

        $('input[placeholder], textarea[placeholder]').inputHints();
      });    
    }
  } 

  Drupal.behaviors.CustomFormElemements = {
    attach: function (context) {      
      //$('.form-select', context).once(function(){        
        $('#block-views-app-store-block .view-filters .form-select').select2();                                 
      //});     
    }
  }
  
  Drupal.behaviors.ColoredRublics = {
    attach: function (context) { 
      $('.view-block-rubrics-inside a').hover(
        function() {
          rel = $(this).attr('rel');
          color = rel.replace('rubric-color:', '');
          $(this).css('backgroundColor', color);
        },
        function() {
          $(this).css('backgroundColor', 'transparent');
        }
      );
    }
  }

  /* Drupal.behaviors.CarouselAfisha = {
    attach: function (context) {             
      $('.view-events .item-list ul:not(.carousel-processed)', context).each(function(){
        $(this).jcarousel();  
      });           
      $('.view-events .item-list ul:not(.carousel-processed)', context).jcarousel();                               
    }
  } */
  
  Drupal.behaviors.tagCloud = {
    attach: function (context) {   
      $(document).ready(function() {
        $('ul.tags').tagcloud({height:300,type:"sphere",sizemin:1,sizemax:1000,power:0.5});
      });
    }
  }
  
})(jQuery, Drupal, this, this.document);
