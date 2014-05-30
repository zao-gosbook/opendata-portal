AutoUpload is a user interface (UI) enhancement for uploading files.

Currently, users must select files, then press the "Upload" button. We
found users often don't realize a button press is necessary and mistakenly
think their image is uploaded when it's not.

This module removes the extra button press and hides the "Upload" button
via JavaScript for a quicker file upload UI. When JavaScript is not
enabled, it falls back to the "Upload" button.

Developed by RMR Labz (http://www.rmrlabz.com).

==================

Handles the core managed file fields and Media module file fields.

Configure the type of file fields you want to use auto upload at
admin/config/media/autoupload.

==================

You can configure your own field types. Configuration settings are as follows.

- Name: Provide a unique name for your field's configuration. Only letters,
numbers, and underscores are allowed.

- Context: jQuery selector which identifies the container for the entire file
field. It must enclose the file input and submit input.

- File Input Selector: jQuery selector which identifies the file input.

- File Event: The event on the file input that should trigger the submit event.

- Submit Input Selector: jQuery selector which identifies the submit input.

- Submit Event: The event on the submit input that should be triggered after the
file event occurs.

- Error : jQuery selector which identifies the element which indicates an error.
After the file event is triggered, this element will be checked for. If found,
the submit event will not be triggered.

- Error Remove: How to handle removal of the error element if found. Because
the presence of an error element will prevent the submit event from triggering,
the error element must be removed before subsequent attempts to auto upload.
  Options are
  - none: No error removal is needed. It's already handled.
  - id: Removes the ID attribute from the element.
  - class: Removes a class from the element. The removed class is the last class
  found in the error selector. (A selector "input.error" will remove the "error"
  class from the input elements.)
  - element: Removes the entire matched element.

==================

EXAMPLE

The markup for the example file field is:
<div class="file-field-wrapper">
  <input type="file" class="file" />
  <input type="button" value="Upload" class="upload" />
</div>

For the above markup, the configuration settings are:
Context = div.file-field-wrapper
File Input Selector = input.file
File Event = change
Submit Input Selector = input.upload
Submit Event = click
Error - input.error
Error Remove - class

In the above example, all elements are contained within a div tag with class
"file-field-wrapper". A "change" event on an input with class "file" will
trigger a "click" event on the input with class "upload" within the same
context.

The code that's responsible for this field type adds the class "error"
to the inputs when an upload error occurs that should prevent the submit event
(such as disallowed file type). The code responsible for this field type does
not automatically remove the error class from the inputs on subsequent upload
attempts, so Auto Upload error remove is set to "class". This means the "error"
class is removed by Auto Upload before subsequent upload attempts.
