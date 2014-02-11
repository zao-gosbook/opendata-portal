<?php

// Opendata API object types.
define('OD_IMPORT_DATA_TYPE', 'data');
define('OD_IMPORT_STRUCTURE_TYPE', 'structure');

// Dataset owner user ID.
define('OD_IMPORT_USER_ID', 107);

// Taxonomy vocabularies.
define('OD_IMPORT_VOCABULARY_FORMATS', 'format');
define('OD_IMPORT_VOCABULARY_FORMATS_ID', 1);
define('OD_IMPORT_VOCABULARY_SUBJECTS', 'tags');
define('OD_IMPORT_VOCABULARY_SUBJECTS_ID', 2);

// Meta fields.
define('OD_IMPORT_FIELD_META_IDENTIFIER', 'field_dataset_id');
define('OD_IMPORT_FIELD_META_DESCRIPTION', 'body');
define('OD_IMPORT_FIELD_META_OWNER', 'field_organization');
define('OD_IMPORT_FIELD_META_CREATED', 'field_date_first_time_publ');
define('OD_IMPORT_FIELD_META_UPDATED', 'field_date_last_change');
define('OD_IMPORT_FIELD_META_PROVENANCE', 'field_content_last_change');
define('OD_IMPORT_FIELD_META_SUBJECT', 'field_tags');
define('OD_IMPORT_FIELD_META_RESOURCES', 'field_resources');

// Source fields.
define('OD_IMPORT_FIELD_RESOURCE_CREATED', 'field_created');
define('OD_IMPORT_FIELD_RESOURCE_PROVENANCE', 'field_provenance');
define('OD_IMPORT_FIELD_RESOURCE_FORMAT', 'field_format');
define('OD_IMPORT_FIELD_RESOURCE_DATA', 'field_upload');
define('OD_IMPORT_FIELD_RESOURCE_CSV_DELIMITER', 'field_csv_delimiter');
define('OD_IMPORT_FIELD_RESOURCE_ENCODING', 'field_encoding');
define('OD_IMPORT_FIELD_RESOURCE_STRUCTURE', 'field_upload_structure');

// Publisher fields.
define('OD_IMPORT_FIELD_PUBLISHER_NAME', 'field_contact_name');
define('OD_IMPORT_FIELD_PUBLISHER_PHONE', 'field_contact_phone');
define('OD_IMPORT_FIELD_PUBLISHER_EMAIL', 'field_email_responsible');
