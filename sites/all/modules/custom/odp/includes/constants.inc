<?php

/**
 * Import user ID.
 */
define('OD_COMMON_IMPORT_USER_ID', 107);

/**
 * Dataset fields.
 */
define('ODP_FIELD_DATASET_IDENTIFIER', 'field_dataset_id');
define('ODP_FIELD_DATASET_DESCRIPTION', 'field_dataset_body');
define('ODP_FIELD_DATASET_OWNER', 'field_organization');
define('ODP_FIELD_DATASET_CREATED', 'field_date_first_time_publ');
define('ODP_FIELD_DATASET_UPDATED', 'field_date_last_change');
define('ODP_FIELD_DATASET_SUBJECT', 'field_tags');
define('ODP_FIELD_DATASET_RESOURCES', 'field_resources');
define('ODP_FIELD_DATASET_RUBRIC', 'field_rubric');

/**
 * Dataset publisher fields.
 */
define('ODP_FIELD_DATASET_PUBLISHER_NAME', 'field_contact_name');
define('ODP_FIELD_DATASET_PUBLISHER_PHONE', 'field_contact_phone');
define('ODP_FIELD_DATASET_PUBLISHER_EMAIL', 'field_email_responsible');

/**
 * Resource fields.
 */
define('ODP_FIELD_RESOURCE_DATASET', 'field_dataset_ref');
define('ODP_FIELD_RESOURCE_CREATED', 'field_created');
define('ODP_FIELD_RESOURCE_PROVENANCE', 'field_provenance');
define('ODP_FIELD_RESOURCE_FORMAT', 'field_format');
define('ODP_FIELD_RESOURCE_LOCAL_DATA', 'field_upload');
define('ODP_FIELD_RESOURCE_LOCAL_STRUCTURE', 'field_upload_structure');
define('ODP_FIELD_RESOURCE_REMOTE_DATA', 'field_link_remote_file');
define('ODP_FIELD_RESOURCE_REMOTE_STRUCTURE', 'field_link_structure_file');
define('ODP_FIELD_RESOURCE_CSV_DELIMITER', 'field_csv_delimiter');
define('ODP_FIELD_RESOURCE_UTF8_ENCODING', 'field_utf8_encoding');

/**
 * Organization fields.
 */
define('ODP_FIELD_ORGANIZATION_CURATOR', 'field_organization_curators');
define('ODP_FIELD_ORGANIZATION_ID', 'field_organization_inn');

/**
 * Log fields.
 */
define('ODP_FIELD_LOG_ORGANIZATION', 'field_organization');
define('ODP_FIELD_LOG_DATASET', 'field_dataset');
define('ODP_FIELD_LOG_IMPORTANCE_TYPE', 'field_log_importance_type');
define('ODP_FIELD_LOG_EVENT_TYPE', 'field_log_event_type');
define('ODP_FIELD_LOG_CURATOR_WAS_NOTIFIED', 'field_curator_was_notified');
