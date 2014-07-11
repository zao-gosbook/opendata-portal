<?php

function odp_import_cron_get_organizations() {
  // Main content table.
  $query = db_select('node', 'organization');
  // Content is organization.
  $query->condition('organization.type', 'organization');
  // Organization is published.
  $query->condition('organization.status', 1);

  // Join organization field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_ORGANIZATION_URL, 'field_organization_url', implode(' AND ', array(
    'field_organization_url.entity_id = organization.nid',
    'field_organization_url.revision_id = organization.vid',
    'field_organization_url.entity_type = \'node\'',
    'field_organization_url.delta = \'0\'',
    'field_organization_url.deleted = \'0\'',
  )));

  // Select organization property: nid.
  $query->addField('organization', 'nid', 'nid');
  // Select organization property: title.
  $query->addField('organization', 'title', 'title');
  // Select organization field: url.
  $query->addField('field_organization_url', ODP_FIELD_ORGANIZATION_URL . '_url', 'url');

  // Sort by created.
  $query->orderBy('organization.created', 'DESC');
  // Sort by language.
  $query->orderBy('FIELD(field_organization_url.language, ' . odp_query_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'nid');
  $query->addField('result', 'title');
  $query->addField('result', 'url');

  // Sort by title.
  $query->orderBy('result.title', 'ASC');

  $resource = $query->execute();
  $result = $resource->fetchAllAssoc('nid');

  return $result;
}
