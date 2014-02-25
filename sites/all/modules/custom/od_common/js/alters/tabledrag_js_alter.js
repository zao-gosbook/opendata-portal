
(function ($) {
  Drupal.tableDrag.prototype.parent_hideColumns = Drupal.tableDrag.prototype.hideColumns;
  Drupal.tableDrag.prototype.hideColumns = function() {
    Drupal.tableDrag.prototype.parent_hideColumns();
    $('.tabledrag-toggle-weight').hide();
  };
})(jQuery);

