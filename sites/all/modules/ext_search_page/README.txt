
Extended Search Page
--------------------

The goal is to provide a page like the default "Find content" but on top of scalable technology for sites with huge amounts of nodes.
So this module support solr and mysql through Search API and uses entity metadata to discover objects fields.

The module uses the search api pages (see below).

Features
--------

 - fulltext index are searched through a text input 
 - non fulltext index can be used as filters (like in the content page) in the search page form
 - you can choose a form widget for each filter
 - you can specify default value for filters (even if filter is not displayed)
 - each search page can have a dedicated search form block
 - thoses widgets are shown in the search page and managed by URL (vs session for SEO)
 - suported fields : boolean, date with date_range, node_reference (with mono term select)
 - widgets support can be extended by a hook


Test
----

I've done test against solr index.


TODO
----
Field/CCK widget integration for entity_reference (ie a lighbox node browser)


Requirement
-----------

Module search_api : http://drupal.org/project/search_api 
Module search_api_page


Mainterner
----------

David Berlioz aka quazardous
http://drupal.org/user/399916