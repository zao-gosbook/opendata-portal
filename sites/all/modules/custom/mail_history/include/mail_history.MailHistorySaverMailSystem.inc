<?php
/*
 * @file
 */

class MailHistorySaverMailSystem implements MailSystemInterface {
  /**
   * Send an e-mail message, using Drupal variables and default settings.
   *
   * @see http://php.net/manual/en/function.mail.php
   * @see drupal_mail()
   *
   * @param $message
   *   A message array, as described in hook_mail_alter().
   * @return
   *   TRUE if the mail was successfully accepted, otherwise FALSE.
   */
  public function mail(array $message) {
    //Send email using original MailSystem
    $status = MailHistory::inst()->getOriginalMailSystem($message)->mail($message);

    //And disable hack immediately after message was sent
    MailHistory::inst()->disableHack();

    $message['result'] = $status;
    MailHistory::inst()->addMail($message);

    return $status;
  }

  /**
   * Concatenate and wrap the e-mail body for plain-text mails.
   *
   * @param $message
   *   A message array, as described in hook_mail_alter().
   *
   * @return
   *   The formatted $message.
   */
  public function format(array $message) {
    $message = MailHistory::inst()->getOriginalMailSystem($message)->format($message);
    return $message;
  }

  /**
   * Destructor
   */
  function __destruct() {
    //Disable our hack to let other modules sent emails
    MailHistory::inst()->disableHack();
  }
}