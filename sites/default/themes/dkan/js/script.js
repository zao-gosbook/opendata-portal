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
  
})(jQuery, Drupal, this, this.document);
