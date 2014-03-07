(function ($) {

/**
 * JS related to the tabs in the Panels tabs.
 */
Drupal.behaviors.panelsTabs = {
  attach: function (context, settings) {
    var tabsID = Drupal.settings.panelsTabs.tabsID;
    var activeCookieName = 'panelsTabs:activeTab:'+tabsID;
    var tabConfig = settings.panelsTabs.tabsConfig[tabsID] || {};
    var saveActiveTab = tabConfig.saveActiveTab || false;

    function callbackSaveActiveTab(event, ui) {
      if (saveActiveTab) {
        $.cookie(activeCookieName, ui.index, {path: window.location.href, expires: 365});
      }
    }

    for (var key in Drupal.settings.panelsTabs.tabsID) {
      $('#' + tabsID[key] +':not(.tabs-processed)', context)
        .addClass('tabs-processed')
        .tabs({
          selected: saveActiveTab ? ($.cookie(activeCookieName) || 0) : 0,
          select: callbackSaveActiveTab
        });
    }
  }
};

})(jQuery);
