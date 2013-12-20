This module adds an administration settings panel to handle
/node page access.

Once it is activated there are three posible configurations:

* Core - Drupal core will handle node page access as usual:
  all users with 'access content' permission
* Disabled - Nobody will be able to access /node.
  It will return 'Page not found' (404).
* By permission - Access will be handled by a new permission:
  'access node page'

The configuration page path is:
admin/config/system/node_page_admin
