
Entityform to node is a little module that provides
an ability to copy entityform to node.

How to use
------------

1) Install the module
2) Enable the module
3) Create new content type without creating any other fields
4 ) Go and add new action from group "Entityforms" to rule
    (which is called after entityform submission for example)
5) Define field mappings and other settings

When action is triggered it will create all necessary fields for node
and copy values from entityform's fields using defined mappings.

Installation
------------

Extract archive to your site's modules directory,
e.g. sites/default/modules/contrib or sites/all/modules/contrib.

Author
------
Cadilos Cupelios
ilgis2007@list.ru
