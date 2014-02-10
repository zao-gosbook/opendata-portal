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
      if ($('.pane-gb-search-pane .form-text, .pane-datasets-search-dataset-search .view-filters .form-text').length > 0) {
        $('.pane-gb-search-pane .form-text').attr("placeholder", Drupal.t("Search for data"));
        $('.pane-datasets-search-dataset-search .view-filters .form-text').attr("placeholder", Drupal.t("Search for data"));
        //$('input[placeholder], textarea[placeholder]').inputHints();
      }
    }
  } 
  
  Drupal.behaviors.TaxonomyColumns = {
    attach: function (context) {      
      $('.section-rubriki .view-rubric-nodes .view-content, .section-rubrics .view-rubric-nodes .view-content', context).once('massontry', function() {
        var massontry = $(this);
        $('<div class="view-header"></div>').prependTo(massontry);
        var container = document.querySelector('.view-rubric-nodes .view-content');
        var msnry = new Masonry( container, {
          // options
          //columnWidth: 200,
          itemSelector: '.views-row'/**/,
          gutter: '.view-rubric-nodes .view-content .view-header'
        });         
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
      /**/  if('.view-quick-facts .view-content') {
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

  Drupal.behaviors.preventClickHrefUserMenu = {
    attach: function(context, settings) {
      $(context).find('.sf-menu-for-profile.sf-horizontal>li.menuparent>a').bind('click', function(e) {
        e.preventDefault();
        return false;
      });
    }
  }

  /**
   * Кнопка ПОКАЗАТЬ/СКРЫТЬ элементы на главной странице.
   * Показывает только 9 элементов, остальные скрывает. Их можно развернуть по кнопке
   * @type {{attach: Function}}
   */
  Drupal.behaviors.showHideElementsFront = {
    attach: function(context, settings) {
      var showHideToggleEl = $(context).find('.view:not(.processed-showHideElementsFront) div.show-hide-toggle-wrapper>span>a');
      var view = showHideToggleEl.parents('.view:eq(0)');
      var viewContent = view.find('.view-content');
      view.addClass('.processed-showHideElementsFront');

      function processClick(element) {
        var $this = $(element);

        var target = viewContent.find('.views-row').slice(9); //Все элементы, начиная с девятого
        $this.parent().parent().find('span').hide(); //Скрываем саму кнопку показать/скрыть
        //Если элементов всего было 9 -- то нам больше и делать нечего
        if (target.length > 0) {
          //Hide
          if (!view.hasClass('more-toggle-collapsed')) {
            target.slideUp();
            view.addClass('more-toggle-collapsed').removeClass('more-toggle-expanded');
            $this.parent().parent().find('.state-show').show();
          }
          //Show
          else {
            target.slideDown();
            view.addClass('more-toggle-expanded').removeClass('more-toggle-collapsed');
            $this.parent().parent().find('.state-hide').show();
          }
        }
      }

      showHideToggleEl.bind('click', function() {
        processClick(this);
        return false;
      });

      processClick(showHideToggleEl);
    }
  }

  /**
   * Force all links on dataset search page open in new window
   * @fixme ugly warkaround should be replaced with less ugly one
   */
  Drupal.behaviors.openTitleIntNewWindow = {
    attach: function (context, settings) {
      $('body.section-dataset .view-content .field-name-title a').bind('click', function () {
        var win = window.open($(this).attr('href'));
        win.focus();
      });
    }
  }
  
})(jQuery, Drupal, this, this.document);
