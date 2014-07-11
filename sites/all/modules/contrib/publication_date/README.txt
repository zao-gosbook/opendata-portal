
README
--------------------------------------------------------------------------
The Publication Date module adds a field to each node containing the date when
it was first published.

This published date field can be used in any templates, or views, and integrates
well with the Scheduler module: <http://drupal.org/project/scheduler>

Without this, the only dates available for nodes are their created date and
changed date, but these are often insufficient to meet the needs of publishing
workflows. Sorting nodes by their created date doesn't account for content which
is held in draft form for a time while being readied for publication. Sorting
nodes by their changed date fails to account for content needing minor
corrections after being published.

The "Published on" date can be edited through the node edit form, allowing a
custom published date to be set. If a custom date is set prior to publication,
it will be respected when the node is published. The publication date is also
retained when a node is unpublished and then republished.


INSTALLATION
--------------------------------------------------------------------------
1. Copy the publication_date folder to your modules directory
2. Go to admin > Site building > Modules, and enable this module.

This will add a new $node->published_at field to nodes, containing the published
date, or 'false' if no published date has been set. You can then use this field
in any templates. Moreover, this field is available in the views parameters.

IMPORTANT: For nodes that were published BEFORE the installation of this module,
we can not know the exact date of publication, so $node->published_at will
initially contain the creation date.


API
--------------------------------------------------------------------------
Other modules can use hook_publication_date_alter() to change the publication
date when it is set. See publication_date.api.php for more documentation.


CREDITS
--------------------------------------------------------------------------
The Publication Date module was originally written by Emmanuelle Gouleau and
Tristan Marly from Clever Age: http://www.clever-age.org

The initial D7 Port was by Joost van der Locht
