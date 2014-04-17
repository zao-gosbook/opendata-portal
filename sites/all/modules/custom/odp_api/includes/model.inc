<?php

/**
 * Get custom text.
 */
function odp_api_get_text($text) {
  $content = new stdClass();

  $format = odp_api_detect_format();

  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $text;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->result = $text;
      break;
  }

  return $content;
}

/**
 * Get organizations.
 */
function odp_api_get_organizations() {
  $content = new stdClass();

  $format = odp_api_detect_format();

  $organizations = _odp_api_get_organizations();
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $organizations;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->organizations = $organizations;
      $content->organizations['#tag'] = 'organization';
      break;
  }

  return $content;
}

/**
 * Get organization.
 */
function odp_api_get_organization($id) {
  $content = new stdClass();

  $format = odp_api_detect_format();

  $organization = _odp_api_get_organization($id);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $organization;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->organization = $organization;
      break;
  }

  return $content;
}

/**
 * Get topics.
 */
function odp_api_get_topics() {
  $content = new stdClass();

  $format = odp_api_detect_format();

  $topics = _odp_api_get_topics();
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $topics;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->topics = $topics;
      $content->topics['#tag'] = 'topic';
      break;
  }

  return $content;
}

/**
 * Get topic.
 */
function odp_api_get_topic($topic) {
  $content = new stdClass();

  $format = odp_api_detect_format();

  $topic = _odp_api_get_topic($topic);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $topic;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->topic = $topic;
      break;
  }

  return $content;
}

/**
 * Get datasets.
 */
function odp_api_get_datasets($params = array()) {
  $content = new stdClass();

  $format = odp_api_detect_format();

  $params = drupal_get_query_parameters() + $params;

  $datasets = _odp_api_get_datasets($params);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $datasets;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->datasets = $datasets;
      $content->datasets['#tag'] = 'dataset';
      break;
  }

  return $content;
}

/**
 * Get dataset.
 */
function odp_api_get_dataset($identifier) {
  $content = new stdClass();

  $format = odp_api_detect_format();

  $dataset = _odp_api_get_dataset($identifier);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $dataset;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->dataset = $dataset;
      break;
  }

  return $content;
}

/**
 * Get dataset publisher.
 */
function odp_api_get_dataset_publisher($identifier) {
  $content = new stdClass();

  $format = odp_api_detect_format();

  $publisher = _odp_api_get_dataset_publisher($identifier);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $publisher;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->publisher = $publisher;
      break;
  }

  return $content;
}

/**
 * Get dataset data.
 */
function odp_api_get_dataset_data($identifier) {
  $content = new stdClass();

  $format = odp_api_detect_format();

  $data = _odp_api_get_dataset_data($identifier);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $data;
      break;
    case ODP_API_FORMAT_XML;
      $content = new stdClass();
      $content->data = $data;
      $content->data['#tag'] = 'version';
      break;
  }

  return $content;
}

/**
 * Get dataset data version.
 */
function odp_api_get_dataset_data_version($identifier, $version) {
  $content = new stdClass();

  $format = odp_api_detect_format();
  $version = strtotime($version);
  $data = _odp_api_get_dataset_data_version($identifier, $version);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $data;
      break;
    case ODP_API_FORMAT_XML;
      if (isset($data->source)) {
        $data->source = htmlentities($data->source);
      }
      $content = new stdClass();
      $content->data = $data;
      break;
  }

  return $content;
}

/**
 * Get dataset data version.
 */
function odp_api_get_dataset_data_version_structure($identifier, $version) {
  $content = new stdClass();

  $format = odp_api_detect_format();
  $version = strtotime($version);
  $structure = _odp_api_get_dataset_data_version_structure($identifier, $version);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $content = $structure;
      break;
    case ODP_API_FORMAT_XML;
      if (isset($structure->source)) {
        $structure->source = htmlentities($structure->source);
      }
      $content = new stdClass();
      $content->structure = $structure;
      break;
  }

  return $content;
}

/**
 * Get dataset data content.
 */
function odp_api_get_dataset_data_version_content($identifier, $version) {
  $content = new stdClass();

  $params = drupal_get_query_parameters();

  $format = odp_api_detect_format();
  $version = strtotime($version);
  $data = _odp_api_get_dataset_data_version_content($identifier, $version, $params);
  switch ($format) {
    case ODP_API_FORMAT_JSON;
      $header = array_shift($data);
      foreach ($data as &$row) {
        foreach (array_keys($row) as $index) {
          $row[$header[$index]] = $row[$index];
          unset($row[$index]);
        }
      }
      $content = $data;
      break;
    case ODP_API_FORMAT_XML;
      foreach ($data as &$row) {
        $row['#tag'] = 'value';
      }

      $inner_content = new stdClass();
      if (!empty($data)) {
        $inner_content->header = array_shift($data);
        $inner_content->rows = $data;
        $inner_content->rows['#tag'] = 'row';
      }

      $content = new stdClass();
      $content->content = $inner_content;
      break;
  }

  return $content;
}

function _odp_api_get_organizations() {
  // Main content table.
  $query = db_select('node', 'organization');
  // Content is organization.
  $query->condition('organization.type', 'organization');
  // Organization is published.
  $query->condition('organization.status', 1);

  // Join dataset field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_ORGANIZATION_ID, 'field_organization_id', implode(' AND ', array(
    'field_organization_id.entity_id = organization.nid',
    'field_organization_id.revision_id = organization.vid',
    'field_organization_id.entity_type = \'node\'',
    'field_organization_id.delta = \'0\'',
    'field_organization_id.deleted = \'0\'',
  )));

  // Select dataset property: nid.
  $query->addField('organization', 'nid', 'nid');
  // Select dataset field: identifier.
  $query->addField('field_organization_id', ODP_FIELD_ORGANIZATION_ID . '_value', 'id');
  // Select dataset property: title.
  $query->addField('organization', 'title', 'title');

  // Sort by language.
  $query->orderBy('organization.created', 'DESC');
  $query->orderBy('FIELD(field_organization_id.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'id');
  $query->addField('result', 'title');

  $resource = $query->execute();
  $result = $resource->fetchAll();

  return $result;
}

function _odp_api_get_organization($id) {
  // Main content table.
  $query = db_select('node', 'organization');
  // Content is organization.
  $query->condition('organization.type', 'organization');
  // Organization is published.
  $query->condition('organization.status', 1);

  // Join dataset field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_ORGANIZATION_ID, 'field_organization_id', implode(' AND ', array(
    'field_organization_id.entity_id = organization.nid',
    'field_organization_id.revision_id = organization.vid',
    'field_organization_id.entity_type = \'node\'',
    'field_organization_id.delta = \'0\'',
    'field_organization_id.deleted = \'0\'',
  )));

  // Select dataset property: nid.
  $query->addField('organization', 'nid', 'nid');
  // Select dataset field: identifier.
  $query->addField('field_organization_id', ODP_FIELD_ORGANIZATION_ID . '_value', 'id');
  // Select dataset property: title.
  $query->addField('organization', 'title', 'title');

  // Condition by organization field: id.
  $query->condition('field_organization_id.' . ODP_FIELD_ORGANIZATION_ID . '_value', $id);

  // Sort by language.
  $query->orderBy('organization.created', 'DESC');
  $query->orderBy('FIELD(field_organization_id.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'id');
  $query->addField('result', 'title');

  $resource = $query->execute();
  $result = $resource->fetchAll();
  if (count($result)) {
    $result = reset($result);
  }

  return $result;
}

function _odp_api_get_topics() {
  // Main content table.
  $query = db_select('taxonomy_term_data', 'topic');
  // Content is topic.
  $query->condition('topic.vid', 3);

  // Select topic property: tid.
  $query->addField('topic', 'tid', 'tid');
  // Select topic property: name.
  $query->addField('topic', 'name', 'name');

  // Sort by language.
  $query->orderBy('topic.tid', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'name');

  $resource = $query->execute();
  $result = $resource->fetchAll();

  return $result;
}

function _odp_api_get_topic($topic) {
  // Main content table.
  $query = db_select('taxonomy_term_data', 'topic');
  // Content is topic.
  $query->condition('topic.vid', 3);

  // Select topic property: tid.
  $query->addField('topic', 'tid', 'tid');
  // Select topic property: name.
  $query->addField('topic', 'name', 'name');

  // Condition by topic field: name.
  $query->condition('topic.' . 'name', $topic);

  // Sort by language.
  $query->orderBy('topic.tid', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'name');

  $resource = $query->execute();
  $result = $resource->fetchAll();
  if (count($result)) {
    $result = reset($result);
  }

  return $result;
}

function _odp_api_get_datasets($params) {
  // Main content table.
  $query = db_select('node', 'dataset');
  // Content is dataset.
  $query->condition('dataset.type', 'dataset');
  // Dataset is published.
  $query->condition('dataset.status', 1);

  // Join dataset field: id.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_IDENTIFIER, 'field_dataset_identifier', implode(' AND ', array(
    'field_dataset_identifier.entity_id = dataset.nid',
    'field_dataset_identifier.revision_id = dataset.vid',
    'field_dataset_identifier.entity_type = \'node\'',
    'field_dataset_identifier.delta = \'0\'',
    'field_dataset_identifier.deleted = \'0\'',
  )));

  // Join content from dataset: organization.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_OWNER, 'field_dataset_organization', implode(' AND ', array(
    'field_dataset_organization.entity_id = dataset.nid',
    'field_dataset_organization.revision_id = dataset.vid',
    'field_dataset_organization.entity_type = \'node\'',
    'field_dataset_organization.delta = \'0\'',
    'field_dataset_organization.deleted = \'0\'',
  )));
  $query->leftJoin('node', 'organization', implode(' AND ', array(
    'organization.nid = field_dataset_organization.' . ODP_FIELD_DATASET_OWNER . '_target_id',
  )));

  // Join organization field: id.
  $query->leftJoin('field_data_' . ODP_FIELD_ORGANIZATION_ID, 'field_organization_id', implode(' AND ', array(
    'field_organization_id.entity_id = organization.nid',
    'field_organization_id.revision_id = organization.vid',
    'field_organization_id.entity_type = \'node\'',
    'field_organization_id.delta = \'0\'',
    'field_organization_id.deleted = \'0\'',
  )));

  // Join content from dataset: topic.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_RUBRIC, 'field_topic', implode(' AND ', array(
    'field_topic.entity_id = dataset.nid',
    'field_topic.revision_id = dataset.vid',
    'field_topic.entity_type = \'node\'',
    'field_topic.delta = \'0\'',
    'field_topic.deleted = \'0\'',
  )));
  $query->leftJoin('taxonomy_term_data', 'topic', implode(' AND ', array(
    'topic.tid = field_topic.' . ODP_FIELD_DATASET_RUBRIC . '_tid AND field_topic.entity_type = \'node\'',
  )));

  // Select dataset property: nid.
  $query->addField('dataset', 'nid', 'nid');
  // Select dataset field: id.
  $query->addField('field_dataset_identifier', ODP_FIELD_DATASET_IDENTIFIER . '_value', 'identifier');
  // Select dataset property: title.
  $query->addField('dataset', 'title', 'title');
  // Select organization field: id.
  $query->addField('field_organization_id', ODP_FIELD_ORGANIZATION_ID . '_value', 'organization');
  // Select topic property: title.
  $query->addField('topic', 'name', 'topic');
  // Select dataset property: created.
  $query->addField('dataset', 'created');

  // Condition by organization field: id.
  if (isset($params['organization'])) {
    $query->condition('field_organization_id.' . ODP_FIELD_ORGANIZATION_ID . '_value', $params['organization']);
  }
  if (isset($params['topic'])) {
    $query->condition('topic.' . 'name', $params['topic']);
  }

  // Set pager.
  $offset = isset($params['offset']) ? $params['offset'] : 0;
  $limit = isset($params['limit']) ? $params['limit'] : 10000;
  $query->range($offset, $limit);

  // Sort by dataset created.
  $query->orderBy('dataset.created', 'DESC');
  // Sort by language.
  $query->orderBy('FIELD(field_dataset_identifier.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_dataset_organization.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_organization_id.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_topic.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'identifier');
  $query->addField('result', 'title');
  $query->addField('result', 'organization');
  $query->addField('result', 'topic');
  $query->groupBy('nid');
  $query->orderBy('created');

  $resource = $query->execute();
  $result = $resource->fetchAll();

  return $result;
}

function _odp_api_get_dataset($identifier) {
  // Main content table.
  $query = db_select('node', 'dataset');
  // Content is dataset.
  $query->condition('dataset.type', 'dataset');
  // Dataset is published.
  $query->condition('dataset.status', 1);

  // Join dataset field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_IDENTIFIER, 'field_dataset_identifier', implode(' AND ', array(
    'field_dataset_identifier.entity_id = dataset.nid',
    'field_dataset_identifier.revision_id = dataset.vid',
    'field_dataset_identifier.entity_type = \'node\'',
    'field_dataset_identifier.delta = \'0\'',
    'field_dataset_identifier.deleted = \'0\'',
  )));

  // Join dataset field: description.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_DESCRIPTION, 'field_dataset_description', implode(' AND ', array(
    'field_dataset_description.entity_id = dataset.nid',
    'field_dataset_description.revision_id = dataset.vid',
    'field_dataset_description.entity_type = \'node\'',
    'field_dataset_description.delta = \'0\'',
    'field_dataset_description.deleted = \'0\'',
  )));

  // Join dataset field: created.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_CREATED, 'field_dataset_created', implode(' AND ', array(
    'field_dataset_created.entity_id = dataset.nid',
    'field_dataset_created.revision_id = dataset.vid',
    'field_dataset_created.entity_type = \'node\'',
    'field_dataset_created.delta = \'0\'',
    'field_dataset_created.deleted = \'0\'',
  )));

  // Join dataset field: modified.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_UPDATED, 'field_dataset_modified', implode(' AND ', array(
    'field_dataset_modified.entity_id = dataset.nid',
    'field_dataset_modified.revision_id = dataset.vid',
    'field_dataset_modified.entity_type = \'node\'',
    'field_dataset_modified.delta = \'0\'',
    'field_dataset_modified.deleted = \'0\'',
  )));

  // Join content from resource: tags.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_SUBJECT, 'field_resource_tags', implode(' AND ', array(
    'field_resource_tags.entity_id = dataset.nid',
    'field_resource_tags.revision_id = dataset.vid',
    'field_resource_tags.entity_type = \'node\'',
    'field_resource_tags.deleted = \'0\'',
  )));
  $query->leftJoin('taxonomy_term_data', 'tag', implode(' AND ', array(
    'tag.tid = field_resource_tags.' . ODP_FIELD_DATASET_SUBJECT . '_tid',
  )));

  // Join content from dataset: organization.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_OWNER, 'field_dataset_organization', implode(' AND ', array(
    'field_dataset_organization.entity_id = dataset.nid',
    'field_dataset_organization.revision_id = dataset.vid',
    'field_dataset_organization.entity_type = \'node\'',
    'field_dataset_organization.delta = \'0\'',
    'field_dataset_organization.deleted = \'0\'',
  )));
  $query->leftJoin('node', 'organization', implode(' AND ', array(
    'organization.nid = field_dataset_organization.' . ODP_FIELD_DATASET_OWNER . '_target_id',
  )));

  // Join content from dataset: resource.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_RESOURCES, 'field_resource', implode(' AND ', array(
    'field_resource.entity_id = dataset.nid',
    'field_resource.revision_id = dataset.vid',
    'field_resource.entity_type = \'node\'',
    'field_resource.delta = \'0\'',
    'field_resource.deleted = \'0\'',
  )));
  $query->leftJoin('node', 'resource', implode(' AND ', array(
    'resource.nid = field_resource.' . ODP_FIELD_DATASET_RESOURCES . '_target_id',
  )));

  // Join content from resource: format.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_FORMAT, 'field_resource_format', implode(' AND ', array(
    'field_resource_format.entity_id = resource.nid',
    'field_resource_format.revision_id = resource.vid',
    'field_resource_format.entity_type = \'node\'',
    'field_resource_format.delta = \'0\'',
    'field_resource_format.deleted = \'0\'',
  )));
  $query->leftJoin('taxonomy_term_data', 'format', implode(' AND ', array(
    'format.tid = field_resource_format.' . ODP_FIELD_RESOURCE_FORMAT . '_tid',
  )));

  // Select dataset property: nid.
  $query->addField('dataset', 'nid', 'nid');
  // Select dataset field: identifier.
  $query->addField('field_dataset_identifier', ODP_FIELD_DATASET_IDENTIFIER . '_value', 'identifier');
  // Select dataset property: title.
  $query->addField('dataset', 'title', 'title');
  // Select dataset field: description.
  $query->addField('field_dataset_description', ODP_FIELD_DATASET_DESCRIPTION . '_value', 'description');
  // Select organization property: title.
  $query->addField('organization', 'title', 'creator');
  // Select dataset field: created.
  $query->addField('field_dataset_created', ODP_FIELD_DATASET_CREATED . '_value', 'created');
  // Select dataset field: modified.
  $query->addField('field_dataset_modified', ODP_FIELD_DATASET_UPDATED . '_value', 'modified');
  // Select format property: name.
  $query->addField('format', 'name', 'format');
  // Select tag property: name.
  $query->addField('tag', 'name', 'subject');

  // Condition by dataset field: identifier.
  $query->condition('field_dataset_identifier.' . ODP_FIELD_DATASET_IDENTIFIER . '_value', $identifier);

  // Sort by dataset created.
  $query->orderBy('dataset.created', 'DESC');
  // Sort by language.
  $query->orderBy('FIELD(field_dataset_identifier.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_dataset_description.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_dataset_created.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_dataset_modified.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_tags.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_dataset_organization.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_format.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'identifier');
  $query->addField('result', 'title');
  $query->addField('result', 'description');
  $query->addField('result', 'creator');
  $query->addField('result', 'created');
  $query->addField('result', 'modified');
  $query->addField('result', 'format');
  $query->addExpression('GROUP_CONCAT(subject)', 'subject');

  $resource = $query->execute();
  $result = $resource->fetchAll();
  if (count($result)) {
    $result = reset($result);
    $result->created = date(ODP_API_ISO8601, $result->created);
    $result->modified = date(ODP_API_ISO8601, $result->modified);
  }

  return $result;
}

function _odp_api_get_dataset_publisher($identifier) {
  // Main content table.
  $query = db_select('node', 'dataset');
  // Content is dataset.
  $query->condition('dataset.type', 'dataset');
  // Dataset is published.
  $query->condition('dataset.status', 1);

  // Join dataset field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_IDENTIFIER, 'field_dataset_identifier', implode(' AND ', array(
    'field_dataset_identifier.entity_id = dataset.nid',
    'field_dataset_identifier.revision_id = dataset.vid',
    'field_dataset_identifier.entity_type = \'node\'',
    'field_dataset_identifier.delta = \'0\'',
    'field_dataset_identifier.deleted = \'0\'',
  )));

  // Join dataset field: publisher name.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_PUBLISHER_NAME, 'field_dataset_publisher_name', implode(' AND ', array(
    'field_dataset_publisher_name.entity_id = dataset.nid',
    'field_dataset_publisher_name.revision_id = dataset.vid',
    'field_dataset_publisher_name.entity_type = \'node\'',
    'field_dataset_publisher_name.delta = \'0\'',
    'field_dataset_publisher_name.deleted = \'0\'',
  )));
  // Join dataset field: publisher phone.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_PUBLISHER_PHONE, 'field_dataset_publisher_phone', implode(' AND ', array(
    'field_dataset_publisher_phone.entity_id = dataset.nid',
    'field_dataset_publisher_phone.revision_id = dataset.vid',
    'field_dataset_publisher_phone.entity_type = \'node\'',
    'field_dataset_publisher_phone.delta = \'0\'',
    'field_dataset_publisher_phone.deleted = \'0\'',
  )));
  // Join dataset field: publisher email.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_PUBLISHER_EMAIL, 'field_dataset_publisher_mail', implode(' AND ', array(
    'field_dataset_publisher_mail.entity_id = dataset.nid',
    'field_dataset_publisher_mail.revision_id = dataset.vid',
    'field_dataset_publisher_mail.entity_type = \'node\'',
    'field_dataset_publisher_mail.delta = \'0\'',
    'field_dataset_publisher_mail.deleted = \'0\'',
  )));

  // Select dataset field: publisher name.
  $query->addField('field_dataset_publisher_name', ODP_FIELD_DATASET_PUBLISHER_NAME . '_value', 'name');
  // Select dataset field: publisher phone.
  $query->addField('field_dataset_publisher_phone', ODP_FIELD_DATASET_PUBLISHER_PHONE . '_value', 'phone');
  // Select dataset field: publisher email.
  $query->addField('field_dataset_publisher_mail', ODP_FIELD_DATASET_PUBLISHER_EMAIL . '_email', 'mbox');

  // Condition by dataset field: identifier.
  $query->condition('field_dataset_identifier.' . ODP_FIELD_DATASET_IDENTIFIER . '_value', $identifier);

  // Sort by dataset created.
  $query->orderBy('dataset.created', 'DESC');
  // Sort by language.
  $query->orderBy('FIELD(field_dataset_publisher_name.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_dataset_publisher_phone.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_dataset_publisher_mail.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'name');
  $query->addField('result', 'phone');
  $query->addField('result', 'mbox');
  $resource = $query->execute();
  $result = $resource->fetchAll();
  if (count($result)) {
    $result = reset($result);
  }

  return $result;
}

function _odp_api_get_dataset_data($identifier) {
  // Main content table.
  $query = db_select('node', 'dataset');
  // Content is dataset.
  $query->condition('dataset.type', 'dataset');
  // Dataset is published.
  $query->condition('dataset.status', 1);

  // Join dataset field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_IDENTIFIER, 'field_dataset_identifier', implode(' AND ', array(
    'field_dataset_identifier.entity_id = dataset.nid',
    'field_dataset_identifier.revision_id = dataset.vid',
    'field_dataset_identifier.entity_type = \'node\'',
    'field_dataset_identifier.delta = \'0\'',
    'field_dataset_identifier.deleted = \'0\'',
  )));

  // Join content from dataset: resource.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_RESOURCES, 'field_resource', implode(' AND ', array(
    'field_resource.entity_id = dataset.nid',
    'field_resource.revision_id = dataset.vid',
    'field_resource.entity_type = \'node\'',
    'field_resource.delta = \'0\'',
    'field_resource.deleted = \'0\'',
  )));
  $query->leftJoin('node_revision', 'resource', implode(' AND ', array(
    'resource.nid = field_resource.' . ODP_FIELD_DATASET_RESOURCES . '_target_id',
  )));

  // Join resource field: created.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_CREATED, 'field_resource_created', implode(' AND ', array(
    'field_resource_created.entity_id = resource.nid',
    'field_resource_created.revision_id = resource.vid',
    'field_resource_created.entity_type = \'node\'',
    'field_resource_created.delta = \'0\'',
    'field_resource_created.deleted = \'0\'',
  )));

  // Select dataset property: nid.
  $query->addField('dataset', 'nid', 'nid');
  // Select dataset field: source.
  $query->addField('field_resource_created', ODP_FIELD_RESOURCE_CREATED . '_value', 'created');

  // Condition by dataset field: identifier.
  $query->condition('field_dataset_identifier.' . ODP_FIELD_DATASET_IDENTIFIER . '_value', $identifier);

  // Sort by dataset created.
  $query->orderBy('dataset.created', 'DESC');
  // Sort by language.
  $query->orderBy('FIELD(field_dataset_identifier.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_created.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'created');

  $resource = $query->execute();
  $result = $resource->fetchAll();

  foreach ($result as &$data) {
    if ($data->created) {
      $data->created = date(ODP_API_ISO8601, $data->created);
    }
  }

  return $result;
}

function _odp_api_get_dataset_data_version($identifier, $version) {
  // Main content table.
  $query = db_select('node', 'dataset');
  // Content is dataset.
  $query->condition('dataset.type', 'dataset');
  // Dataset is published.
  $query->condition('dataset.status', 1);

  // Join dataset field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_IDENTIFIER, 'field_dataset_identifier', implode(' AND ', array(
    'field_dataset_identifier.entity_id = dataset.nid',
    'field_dataset_identifier.revision_id = dataset.vid',
    'field_dataset_identifier.entity_type = \'node\'',
    'field_dataset_identifier.delta = \'0\'',
    'field_dataset_identifier.deleted = \'0\'',
  )));

  // Join content from dataset: resource.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_RESOURCES, 'field_resource', implode(' AND ', array(
    'field_resource.entity_id = dataset.nid',
    'field_resource.revision_id = dataset.vid',
    'field_resource.entity_type = \'node\'',
    'field_resource.delta = \'0\'',
    'field_resource.deleted = \'0\'',
  )));
  $query->leftJoin('node_revision', 'resource', implode(' AND ', array(
    'resource.nid = field_resource.' . ODP_FIELD_DATASET_RESOURCES . '_target_id',
  )));

  // Join resource field: created.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_CREATED, 'field_resource_created', implode(' AND ', array(
    'field_resource_created.entity_id = resource.nid',
    'field_resource_created.revision_id = resource.vid',
    'field_resource_created.entity_type = \'node\'',
    'field_resource_created.delta = \'0\'',
    'field_resource_created.deleted = \'0\'',
  )));

  // Join resource field: provenance.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_PROVENANCE, 'field_resource_provenance', implode(' AND ', array(
    'field_resource_provenance.entity_id = resource.nid',
    'field_resource_provenance.revision_id = resource.vid',
    'field_resource_provenance.entity_type = \'node\'',
    'field_resource_provenance.delta = \'0\'',
    'field_resource_provenance.deleted = \'0\'',
  )));

  // Join content from resource: data.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_DATA, 'field_resource_source', implode(' AND ', array(
    'field_resource_source.entity_id = resource.nid',
    'field_resource_source.revision_id = resource.vid',
    'field_resource_source.entity_type = \'node\'',
    'field_resource_source.delta = \'0\'',
    'field_resource_source.deleted = \'0\'',
  )));
  $query->leftJoin('file_managed', 'data', implode(' AND ', array(
    'data.fid = field_resource_source.' . ODP_FIELD_RESOURCE_DATA . '_fid',
  )));

  // Join content from resource: format.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_FORMAT, 'field_resource_format', implode(' AND ', array(
    'field_resource_format.entity_id = resource.nid',
    'field_resource_format.revision_id = resource.vid',
    'field_resource_format.entity_type = \'node\'',
    'field_resource_format.delta = \'0\'',
    'field_resource_format.deleted = \'0\'',
  )));
  $query->leftJoin('taxonomy_term_data', 'format', implode(' AND ', array(
    'format.tid = field_resource_format.' . ODP_FIELD_RESOURCE_FORMAT . '_tid',
  )));

  // Select dataset property: nid.
  $query->addField('dataset', 'nid', 'nid');
  // Select data property: uri.
  $query->addField('data', 'uri', 'source');
  // Select dataset field: created.
  $query->addField('field_resource_created', ODP_FIELD_RESOURCE_CREATED . '_value', 'created');
  // Select dataset field: provenance.
  $query->addField('field_resource_provenance', ODP_FIELD_RESOURCE_PROVENANCE . '_value', 'provenance');
  // Select format property: name.
  $query->addField('format', 'name', 'format');

  // Condition by dataset field: identifier.
  $query->condition('field_dataset_identifier.' . ODP_FIELD_DATASET_IDENTIFIER . '_value', $identifier);
  // Condition by resource field: created.
  $query->condition('field_resource_created.' . ODP_FIELD_RESOURCE_CREATED . '_value', $version);

  // Sort by dataset created.
  $query->orderBy('dataset.created', 'DESC');
  // Sort by language.
  $query->orderBy('FIELD(field_dataset_identifier.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_created.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_provenance.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_source.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'created');
  $query->addField('result', 'source');
  $query->addField('result', 'provenance');
  $query->addField('result', 'format');

  $resource = $query->execute();
  $result = $resource->fetchAll();

  if (count($result)) {
    $result = reset($result);
  }

  $result->source = file_create_url($result->source);
  if ($result->created) {
    $result->created = date(ODP_API_ISO8601, $result->created);
  }

  return $result;
}

function _odp_api_get_dataset_data_version_structure($identifier, $version) {
  // Main content table.
  $query = db_select('node', 'dataset');
  // Content is dataset.
  $query->condition('dataset.type', 'dataset');
  // Dataset is published.
  $query->condition('dataset.status', 1);

  // Join dataset field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_IDENTIFIER, 'field_dataset_identifier', implode(' AND ', array(
    'field_dataset_identifier.entity_id = dataset.nid',
    'field_dataset_identifier.revision_id = dataset.vid',
    'field_dataset_identifier.entity_type = \'node\'',
    'field_dataset_identifier.delta = \'0\'',
    'field_dataset_identifier.deleted = \'0\'',
  )));

  // Join content from dataset: resource.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_RESOURCES, 'field_structure', implode(' AND ', array(
    'field_structure.entity_id = dataset.nid',
    'field_structure.revision_id = dataset.vid',
    'field_structure.entity_type = \'node\'',
    'field_structure.delta = \'0\'',
    'field_structure.deleted = \'0\'',
  )));
  $query->leftJoin('node_revision', 'resource', implode(' AND ', array(
    'resource.nid = field_structure.' . ODP_FIELD_DATASET_RESOURCES . '_target_id',
  )));

  // Join resource field: created.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_CREATED, 'field_structure_created', implode(' AND ', array(
    'field_structure_created.entity_id = resource.nid',
    'field_structure_created.revision_id = resource.vid',
    'field_structure_created.entity_type = \'node\'',
    'field_structure_created.delta = \'0\'',
    'field_structure_created.deleted = \'0\'',
  )));

  // Join content from resource: file.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_STRUCTURE, 'field_structure_source', implode(' AND ', array(
    'field_structure_source.entity_id = resource.nid',
    'field_structure_source.revision_id = resource.vid',
    'field_structure_source.entity_type = \'node\'',
    'field_structure_source.delta = \'0\'',
    'field_structure_source.deleted = \'0\'',
  )));
  $query->leftJoin('file_managed', 'structure', implode(' AND ', array(
    'structure.fid = field_structure_source.' . ODP_FIELD_RESOURCE_STRUCTURE . '_fid',
  )));

  // Select dataset property: nid.
  $query->addField('dataset', 'nid', 'nid');
  // Select structure property: uri.
  $query->addField('structure', 'uri', 'source');
  // Select dataset field: source.
  $query->addField('field_structure_created', ODP_FIELD_RESOURCE_CREATED . '_value', 'created');

  // Condition by dataset field: identifier.
  $query->condition('field_dataset_identifier.' . ODP_FIELD_DATASET_IDENTIFIER . '_value', $identifier);
  // Condition by resource field: created.
  $query->condition('field_structure_created.' . ODP_FIELD_RESOURCE_CREATED . '_value', $version);

  // Sort by dataset created.
  $query->orderBy('dataset.created', 'DESC');
  // Sort by language.
  $query->orderBy('FIELD(field_dataset_identifier.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_structure.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_structure_created.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_structure_source.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'created');
  $query->addField('result', 'source');

  $resource = $query->execute();
  $result = $resource->fetchAll();

  if (count($result)) {
    $result = reset($result);
  }

  if (isset($result->source) && !empty($result->source)) {
    $result->source = file_create_url($result->source);
  }
  if (isset($result->created) && !empty($result->created)) {
    $result->created = date(ODP_API_ISO8601, $result->created);
  }

  return $result;
}

function _odp_api_get_dataset_data_version_for_content($identifier, $version) {
  // Main content table.
  $query = db_select('node', 'dataset');
  // Content is dataset.
  $query->condition('dataset.type', 'dataset');
  // Dataset is published.
  $query->condition('dataset.status', 1);

  // Join dataset field: identifier.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_IDENTIFIER, 'field_dataset_identifier', implode(' AND ', array(
    'field_dataset_identifier.entity_id = dataset.nid',
    'field_dataset_identifier.revision_id = dataset.vid',
    'field_dataset_identifier.entity_type = \'node\'',
    'field_dataset_identifier.delta = \'0\'',
    'field_dataset_identifier.deleted = \'0\'',
  )));

  // Join content from dataset: resource.
  $query->leftJoin('field_data_' . ODP_FIELD_DATASET_RESOURCES, 'field_resource', implode(' AND ', array(
    'field_resource.entity_id = dataset.nid',
    'field_resource.revision_id = dataset.vid',
    'field_resource.entity_type = \'node\'',
    'field_resource.delta = \'0\'',
    'field_resource.deleted = \'0\'',
  )));
  $query->leftJoin('node_revision', 'resource', implode(' AND ', array(
    'resource.nid = field_resource.' . ODP_FIELD_DATASET_RESOURCES . '_target_id',
  )));

  // Join content from resource: data.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_DATA, 'field_resource_source', implode(' AND ', array(
    'field_resource_source.entity_id = resource.nid',
    'field_resource_source.revision_id = resource.vid',
    'field_resource_source.entity_type = \'node\'',
    'field_resource_source.delta = \'0\'',
    'field_resource_source.deleted = \'0\'',
  )));
  $query->leftJoin('file_managed', 'data', implode(' AND ', array(
    'data.fid = field_resource_source.' . ODP_FIELD_RESOURCE_DATA . '_fid',
  )));

  // Join resource field: csv delimiter.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_CSV_DELIMITER, 'field_resource_csv_delimiter', implode(' AND ', array(
    'field_resource_csv_delimiter.entity_id = resource.nid',
    'field_resource_csv_delimiter.revision_id = resource.vid',
    'field_resource_csv_delimiter.entity_type = \'node\'',
    'field_resource_csv_delimiter.delta = \'0\'',
    'field_resource_csv_delimiter.deleted = \'0\'',
  )));

  // Join resource field: created.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_CREATED, 'field_resource_created', implode(' AND ', array(
    'field_resource_created.entity_id = resource.nid',
    'field_resource_created.revision_id = resource.vid',
    'field_resource_created.entity_type = \'node\'',
    'field_resource_created.delta = \'0\'',
    'field_resource_created.deleted = \'0\'',
  )));

  // Join content from resource: format.
  $query->leftJoin('field_data_' . ODP_FIELD_RESOURCE_FORMAT, 'field_resource_format', implode(' AND ', array(
    'field_resource_format.entity_id = resource.nid',
    'field_resource_format.revision_id = resource.vid',
    'field_resource_format.entity_type = \'node\'',
    'field_resource_format.delta = \'0\'',
    'field_resource_format.deleted = \'0\'',
  )));
  $query->leftJoin('taxonomy_term_data', 'format', implode(' AND ', array(
    'format.tid = field_resource_format.' . ODP_FIELD_RESOURCE_FORMAT . '_tid',
  )));

  // Select dataset property: nid.
  $query->addField('dataset', 'nid', 'nid');
  // Select data property: uri.
  $query->addField('data', 'uri', 'source');
  // Select format property: name.
  $query->addField('format', 'name', 'format');
  // Select data property: uri.
  $query->addField('field_resource_csv_delimiter', ODP_FIELD_RESOURCE_CSV_DELIMITER . '_value', 'csv_delimiter');

  // Condition by dataset field: identifier.
  $query->condition('field_dataset_identifier.' . ODP_FIELD_DATASET_IDENTIFIER . '_value', $identifier);
  // Condition by resource field: created.
  $query->condition('field_resource_created.' . ODP_FIELD_RESOURCE_CREATED . '_value', $version);

  // Sort by dataset created.
  $query->orderBy('dataset.created', 'DESC');
  // Sort by language.
  $query->orderBy('FIELD(field_dataset_identifier.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_source.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_csv_delimiter.language, ' . _odp_api_language_sort() . ')', 'DESC');
  $query->orderBy('FIELD(field_resource_created.language, ' . _odp_api_language_sort() . ')', 'DESC');

  // Wrap query into query for grouping after order.
  $query = db_select($query, 'result');
  $query->addField('result', 'source');
  $query->addField('result', 'format');
  $query->addField('result', 'csv_delimiter');

  $resource = $query->execute();
  $result = $resource->fetchAll();

  if (count($result)) {
    $result = reset($result);
  }

  $result->source = file_create_url($result->source);
  if ($result->created) {
    $result->created = date(ODP_API_ISO8601, $result->created);
  }

  return $result;
}

function _odp_api_get_dataset_data_version_content($identifier, $version, $params = array()) {
  $result = array();

  $data = _odp_api_get_dataset_data_version_for_content($identifier, $version);

  switch ($data->format) {
    case 'csv':
      if (empty($data->source)) {
        break;
      }
      $content = _odp_api_get_dataset_data_version_content_trash1($data->source);
      $result = _odp_api_get_dataset_data_version_content_trash2($content, $params);
      break;
    default:
      break;
  }

  return $result;
}

function _odp_api_get_dataset_data_version_content_trash1($path) {
  $content = file_get_contents($path);
  $in_encode = od_detect_encoding_guess_file($path);
  $out_encode = 'UTF-8';
  $content = iconv($in_encode, $out_encode, $content);

  return $content;
}

function _odp_api_get_dataset_data_version_content_trash2($content, $params) {
  if (empty($content)) {
    return array();
  }

  $delimiter = odp_detect_csv_delimiter($content);
  $content = preg_split("/\\r\\n|\\r|\\n/", $content);

  $header = array_shift($content);

  if (!empty($params['search']) && (is_string($params['search']) || is_numeric($params['search']))) {
    foreach ($content as $key => $string) {
      if (stripos($string, $params['search']) === FALSE) {
        unset($content[$key]);
      }
    }
  }

  array_unshift($content, $header);
  foreach ($content as &$row) {
    $row = str_getcsv($row, $delimiter);
  }

  return $content;
}
