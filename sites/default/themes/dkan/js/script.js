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
      $('.pane-gb-search-pane .form-text, .pane-datasets-search-dataset-search .view-filters .form-text', context).once(function(){        
        $('.pane-gb-search-pane .form-text', context).attr("placeholder", "Поиск по данным"); 
        $('.pane-datasets-search-dataset-search .view-filters .form-text', context).attr("placeholder", "Поиск по данным"); 

        $('input[placeholder], textarea[placeholder]').inputHints();
      });    
    }
  } 
  
  Drupal.behaviors.TaxonomyColumns = {
    attach: function (context) {      
      $('<div class="view-header"></div>').prependTo('.view-rubric-nodes .view-content');
      var container = document.querySelector('.view-rubric-nodes .view-content');
      var msnry = new Masonry( container, {
        // options
        //columnWidth: 200,
        itemSelector: '.views-row'/**/,
        gutter: '.view-rubric-nodes .view-content .view-header'
      });  
    }
  }   
  
  Drupal.behaviors.ActiveElement = {
    attach: function (context, settings) {

      // Add class for active elements.
      $('input[type="radio"][checked]', context)
        .parent().addClass('active-element');
        
      // Add event for detect active elements.
      $('input[type="radio"]', context).once().change(function() {
        // Find form element for context.
        var $this = $(this),
            $form = $this.parents('form');

        // Remove class from over elements with same name.
        $form.find('input[type="radio"][name="' + $this.attr('name') + '"]')
          .parent().removeClass('active-element');

        // Add class for active element.
        $this.parent().addClass('active-element');
      });         
    }
  }  
  
  Drupal.behaviors.QuickFacts = {
    attach: function (context, settings) {  
      if('.view-quick-facts .view-content') {
        var n = 0;
        var $fact = $('.view-quick-facts .view-content .views-row');
        $($fact[n]).addClass('next');

         setInterval(function(){
          $($fact[n]).removeClass('next');
          if(n+1 == $fact.length) {
            n = 0;
          } else {
            n++;
          }
          setTimeout(function(){
            $($fact[n]).addClass('next');
          }, 500)
        }, 6000);
      }     
    }
  }
  
})(jQuery, Drupal, this, this.document);
