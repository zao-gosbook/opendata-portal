
This module provides by default the ability to translate panel display and
panel pane titles.
Further it introduced an extension to the ctools content_types plugin.
You can now define translatable settings which will be registered in i18n.
Out of the box the module extends the custom content content_type to allow
translation of the content.

Attention: Currently this module needs a patched panels version.
Please apply the patches included in this module or visit:
Additional hooks: http://drupal.org/node/1179034#comment-5664050
UUID support: http://drupal.org/node/1277908#comment-5667824



Plugin definition extension:
------------------------------

This example shows how the content_type custom is extended:

#### Default: ####
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Custom content'),
  'no title override' => TRUE,
  'defaults' => array('admin_title' => '', 'title' => '', 'body' => '', 'format' => filter_fallback_format(), 'substitute' => TRUE),
  'js' => array('misc/autocomplete.js', 'misc/textarea.js', 'misc/collapse.js'),
  // Make sure the edit form is only used for some subtypes.
  'edit form' => '',
  'add form' => '',
  'edit text' => t('Edit'),
  'all contexts' => TRUE,
);

#### Extended Configuration: ####
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Custom content'),
  'no title override' => TRUE,
  'defaults' => array('admin_title' => '', 'title' => '', 'body' => '', 'format' => filter_fallback_format(), 'substitute' => TRUE),
  'js' => array('misc/autocomplete.js', 'misc/textarea.js', 'misc/collapse.js'),
  // Make sure the edit form is only used for some subtypes.
  'edit form' => '',
  'add form' => '',
  'edit text' => t('Edit'),
  'all contexts' => TRUE,
  'i18n_settings' = array(
    'title',
    'body' => array('format' => 'plain_text'),
    'items|0|title'
  ),
);

The new key "i18n_settings" defines an array with the settings that are
translatable. The array contains the names of the settings, they have to be
available in the "defaults" array of the content definition. If you need to
define a format use the name of the setting as the array item key and as item
another array with the detail configuration. E.g
'i18n_settings' = array('body' => array('format' => 'plain_text'))

If i18n_settings is a string it's used as callback. The expected return is an
array equal to the one used in the fix configuration.
You can even declare nested settings  as translatable, to do so use '|' as
delimiter.
E.g. 'items|0|title' is evaluated as $settings['items'][0]['title']

#### Callback: ####
/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Custom content'),
  'no title override' => TRUE,
  'defaults' => array('admin_title' => '', 'title' => '', 'body' => '', 'format' => filter_fallback_format(), 'substitute' => TRUE),
  'js' => array('misc/autocomplete.js', 'misc/textarea.js', 'misc/collapse.js'),
  // Make sure the edit form is only used for some subtypes.
  'edit form' => '',
  'add form' => '',
  'edit text' => t('Edit'),
  'all contexts' => TRUE,
  'i18n_settings' => 'ctools_custom_content_type_i18n_settings',
);

function ctools_custom_content_type_i18n_settings($conf) {
  return array(
    'title',
    'body' => array('format' => $conf['format']),
  );
}
