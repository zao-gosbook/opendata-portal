(function ($) {

  Drupal.theme.prototype.ModalMesssagesPopup = function () {
    var html = ''
    html += '  <div id="ctools-modal">';
    html += '    <div class="ctools-modal-content ctools-modal-content-modal-messages">';
    html += '      <div id="modal-content" class="modal-content modal-content-modal-messages">';
    html += '      </div>';
    html += '      <div class="button-wrapper">';
    html += '        <button type="button" class="close">' + Drupal.CTools.Modal.currentSettings.closeText + '</button>';
    html += '      </div>';
    html += '    </div>';
    html += '  </div>';

    return html;
  }

  Drupal.modal_messages_show = function(title, output, style, reload) {
    if ($('#modalContent').length == 0) {
      Drupal.CTools.Modal.show(style);
    }
    if (reload) {
      $('#modal-content').addClass('modal-messages-reload-on-close');
    }
    // Support additional themes with title.
    $('#modal-title').html(title);
    // Simulate an actual page load by scrolling to the top after adding the
    // content. This is helpful for allowing users to see error messages at the
    // top of a form, etc.
    $('#modal-content').html(output).scrollTop(0);
    Drupal.attachBehaviors();
    $('div#modalContent').css({'height': 'auto'});
    $('div.ctools-modal-content').css({'height': 'auto', 'min-height': Drupal.CTools.Modal.currentSettings.modalSize.height});
    $('div.#modal-content').css({'height': 'auto'});
    // Support additional modal styles.
    Drupal.CTools.Modal.currentSettings.modalSize.type = 'dynamic-height';
  }

  Drupal.command_modal_messages_show = function(ajax, response, status) {
    Drupal.modal_messages_show(response.title, response.output, response.style, response.reload);
  }

  Drupal.modal_messages_close = function(reload) {
    Drupal.CTools.Modal.dismiss();
    if (reload) {
      location.reload();
    }
  }

  $(document).bind('CToolsDetachBehaviors', function(event, context) {
    if ($(context).find('#modal-content').hasClass('modal-messages-reload-on-close')) {
      location.reload();
    }
  });

  Drupal.ajax.prototype.commands.modal_messages_show = Drupal.command_modal_messages_show;

})(jQuery);
