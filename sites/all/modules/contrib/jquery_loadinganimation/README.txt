README.txt
----------
JQuery loadinganimation module shows a loading layer on page loading events.
These may be triggered by form submission, clicking a hyperlink or executing an AJAX call.

Hyperlinks may be excluded from trigger by adding a ".noLoadingAnimation" class.
Further "javascript" and "#" hyperlinks are automatically excluded.
Loading and animation may be aborted by pressing "ESC".

There are settings for all these three type of triggers:
- Form submit
- AJAX Request
- Hyperlink Click

JavaScript API functions allow to show and hide separately by calling:
Drupal.behaviors.jquery_loadinganimation.Loadinganimation.show();
or
Drupal.behaviors.jquery_loadinganimation.Loadinganimation.hide();

JavaScript API
------------
- Drupal.behaviors.jquery_loadinganimation.Loadinganimation.show()
- Drupal.behaviors.jquery_loadinganimation.Loadinganimation.hide()

DEPENDENCIES
------------
- none -

INSTALLATION
------------
1. Download and enable this module.
2. Edit the settings ("admin/config/user-interface/jquery_loadinganimation") if you like to.

AUTHOR/MAINTAINER
-----------------
- Julian Pustkuchen (http://Julian.Pustkuchen.com)
- Development proudly sponsored by:
    webks: websolutions kept simple (http://www.webks.de)
      and
    DROWL: Drupalbasierte Lösungen aus Ostwestfalen-Lippe (http://www.drowl.de)