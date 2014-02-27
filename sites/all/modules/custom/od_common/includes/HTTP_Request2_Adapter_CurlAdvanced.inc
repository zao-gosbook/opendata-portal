<?php
/**
 * @file
 */

require_once 'HTTP/Request2/Adapter/Curl.php';

class HTTP_Request2_Adapter_CurlAdvanced extends HTTP_Request2_Adapter_Curl {
  protected function createCurlHandle() {
    $ch = parent::createCurlHandle();

    // set request method
    switch ($this->request->getMethod()) {
      case 'PARTIAL_GET':
        curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'GET');
        curl_setopt($ch, CURLOPT_BUFFERSIZE, 128);
        break;
    }

    return $ch;
  }

  /**
   * Callback function called by cURL for saving the response body
   *
   * @param resource $ch     cURL handle (not used)
   * @param string   $string part of the response body
   *
   * @return   integer     number of bytes saved
   * @throws   HTTP_Request2_MessageException
   * @see      HTTP_Request2_Response::appendBody()
   */
  protected function callbackWriteBody($ch, $string) {
    static $count = 0;
    if ($this->request->getMethod() == 'PARTIAL_GET') {
      if (++$count >= 2) {
        return 0;
      }
    }
    else {
      //$count = 0;
    }

    // Default behaviour
    return parent::callbackWriteBody($ch, $string);
  }

  /**
   * Sends request to the remote server and returns its response
   *
   * @param HTTP_Request2 $request HTTP request message
   *
   * @return   HTTP_Request2_Response
   * @throws   HTTP_Request2_Exception
   */
  public function sendRequest(HTTP_Request2 $request)
  {
    if (!extension_loaded('curl')) {
      throw new HTTP_Request2_LogicException(
        'cURL extension not available', HTTP_Request2_Exception::MISCONFIGURATION
      );
    }

    $this->request              = $request;
    $this->response             = null;
    $this->position             = 0;
    $this->eventSentHeaders     = false;
    $this->eventReceivedHeaders = false;

    try {
      if (false === curl_exec($ch = $this->createCurlHandle())) {
        $e = self::wrapCurlError($ch);
        $e = $e->getCode() == 50 ? NULL : $e;
      }
    } catch (Exception $e) {
    }
    if (isset($ch)) {
      $this->lastInfo = curl_getinfo($ch);
      curl_close($ch);
    }

    $response = $this->response;
    unset($this->request, $this->requestBody, $this->response);

    if (!empty($e)) {
      throw $e;
    }

    if ($jar = $request->getCookieJar()) {
      $jar->addCookiesFromResponse($response, $request->getUrl());
    }

    if (0 < $this->lastInfo['size_download']) {
      $request->setLastEvent('receivedBody', $response);
    }
    return $response;
  }
}