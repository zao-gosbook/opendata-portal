<?php
/*
 * @file
 */

/**
 * @param $form
 * @param $form_state
 */
function mail_history_admin_page_list_form($form, &$form_state) {
  $form = array();

  $form['filters'] = array(
    '#weight' => -10,
    '#type' => 'fieldset',
  );

  $form['filters']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );



  $perpage_limit = 50; //fixme: Constant
  $options = array(
    'start' => pager_find_page() * $perpage_limit,
    'limit' => $perpage_limit,
    'order by' => array('timestamp DESC'),
    //'filters'
  );
  $list = MailHistory::inst()->listMail($options);

  $options = array();
  foreach ($list as $message) {
    $option = array(
      'message_from' => $message->mail_from,
      'message_to' => $message->mail_to,
      'subject' => $message->subject,
      'message_body' => $message->body,
      'status' => $message->send ? t('yes') : t('No'),
    );

    if (preg_match('/^"?.*"?\s*<.*>$/', $message->mail_from)) {
      // . == Matches any single character except line break characters \r and \n.
      // * == Repeats the previous item zero or more times.
      $from_name = preg_replace('/"?([^("\t\n)]*)"?.*$/', '$1', $message->mail_from); // It gives: Name
      $from      = preg_replace("/(.*)\<(.*)\>/i", '$2', $message->mail_from); // It gives: name@domain.tld

      $from_name = base64_decode(preg_replace('/\=\?UTF\-8\?B\?/i', '', $from_name));
      //$from = htmlentities($from);
      $option['message_from'] = "{$from_name} &lt;{$from}&gt;";
    }

    $options[$message->mhid] = $option;
  }

  $header = array(
    'message_from' => t('Sender'),
    'message_to' => t('Recipient'),
    'subject' => t('Subject'),
    'message_body' => t('Message body'),
    'status' => t('Message was send successfully'),
  );

  $form['list']['messages'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No content available.'),
  );





  return $form;
}

function mail_history_admin_page_list_form_submit($form, &$form_state) {
  dpm($form_state);
}