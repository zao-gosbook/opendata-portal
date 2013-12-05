DESCRIPTION
-----------

Module provides 'Node Display Field' field type, that displays various information 
about the node depending of type of widget that has been selected.

Allowed widgets:

* Сomments count
* Created date
* Changed date
* Submitted by (to do)
* Author (to do)
* Links (to do)
* Read more (to do)
* User picture (to do)
*Title (to do)

Each widget has a Settings popup on Dispaly Fields page, where you can change in what format the data will be dispayed.

You can use these fields in Panels and transfer through Features.
 
INSTALLATION
------------

 1. CREATE DIRECTORY

    Create a new directory "node_display_fields" in the sites/all/modules directory and
    place the entire contents of this node_display_fields folder in it or use drush dl node_display_fields

 2. Enable Node Display Field module on admin/modules page;

 3. For content type go to Manage fields page - add new field with 'Node Display Field' field type and choose Widget. 

 4. For content type go to Manage Display page - here you can see new field ('Comment count' for example), use drag-n-drop to put to Field region.

 5. On Manage Display page you can change display settings by clicking on Settings picture in front of field.
