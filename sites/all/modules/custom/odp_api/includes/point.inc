<?php

function odp_api_point_api($args) {
  $point = array_shift($args);

  switch ($point) {
    case 'organization':
      $content = odp_api_point_api_organization($args);
      break;
    case 'topic':
      $content = odp_api_point_api_topic($args);
      break;
    case 'dataset':
      $content = odp_api_point_api_dataset($args);
      break;
    case NULL;
      $content = odp_api_get_text('API портала открытых данных находится в стадии разработки! Любые методы и их результаты могут быть изменены без уведомления!');
      break;
    default:
      $content = odp_api_get_text('Неверный запрос!');
      break;
  }

  return $content;
}

function odp_api_point_api_organization($args) {
  $id = array_shift($args);
  $point = array_shift($args);

  switch ($point) {
    case 'dataset':
      $params = array(
        'organization' => $id,
      );
      $content = odp_api_point_api_dataset($args, $params);
      break;
    case NULL:
      switch ($id) {
        case NULL:
          $content = odp_api_get_organizations();
          break;
        default:
          $content = odp_api_get_organization($id);
          break;
      }
      break;
    default:
      $content = odp_api_get_text('Неверный запрос!');
      break;
  }

  return $content;
}

function odp_api_point_api_topic($args) {
  $topic = array_shift($args);
  $point = array_shift($args);

  switch ($point) {
    case 'dataset':
      $params = array(
        'topic' => $topic,
      );
      $content = odp_api_point_api_dataset($args, $params);
      break;
    case NULL:
      switch ($topic) {
        case NULL:
          $content = odp_api_get_topics();
          break;
        default:
          $content = odp_api_get_topic($topic);
          break;
      }
      break;
    default:
      $content = odp_api_get_text('Неверный запрос!');
      break;
  }

  return $content;
}

function odp_api_point_api_dataset($args, $params = array()) {
  $identifier = array_shift($args);
  $point = array_shift($args);
  array_unshift($args, $identifier);

  switch ($point) {
    case 'publisher':
      $content = odp_api_point_api_dataset_publisher($args);
      break;
    case 'version':
      $content = odp_api_point_api_dataset_version($args);
      break;
    case NULL:
      switch ($identifier) {
        case NULL:
          $content = odp_api_get_datasets($params);
          break;
        default:
          $content = odp_api_get_dataset($identifier);
          break;
      }
      break;
    default:
      $content = odp_api_get_text('Неверный запрос!');
      break;
  }

  return $content;
}

function odp_api_point_api_dataset_publisher($args) {
  $identifier = array_shift($args);

  $content = odp_api_get_dataset_publisher($identifier);

  return $content;
}

function odp_api_point_api_dataset_version($args) {
  $identifier = array_shift($args);
  $version = array_shift($args);
  $point = array_shift($args);
  array_unshift($args, $version);
  array_unshift($args, $identifier);

  // ISO 8601 validation pattern. See https://www.debuggex.com/r/3rZt9hgYEIE5RaI2
  $pattern = '/^([\+-]?\d{4}(?!\d{2}\b))((-?)((0[1-9]|1[0-2])(\3([12]\d|0[1-9]|3[01]))?|W([0-4]\d|5[0-2])(-?[1-7])?|(00[1-9]|0[1-9]\d|[12]\d{2}|3([0-5]\d|6[1-6])))([T\s]((([01]\d|2[0-3])((:?)[0-5]\d)?|24\:?00)([\.,]\d+(?!:))?)?(\17[0-5]\d([\.,]\d+)?)?([zZ]|([\+-])([01]\d|2[0-3]):?([0-5]\d)?)?)?)?$/';

  if (!empty($version) && !preg_match($pattern, $version)) {
    $version = NULL;
  }

  switch ($point) {
    case 'structure':
      $content = odp_api_point_api_dataset_version_structure($args);
      break;
    case 'content':
      $content = odp_api_point_api_dataset_version_content($args);
      break;
    case NULL:
      switch ($version) {
        case NULL:
          $content = odp_api_get_dataset_versions($identifier);
          break;
        default:
          $content = odp_api_get_dataset_version($identifier, $version);
          break;
      }
      break;
    default:
      $content = odp_api_get_text('Неверный запрос!');
      break;
  }

  return $content;
}

function odp_api_point_api_dataset_version_structure($args) {
  $identifier = array_shift($args);
  $version = array_shift($args);

  $content = odp_api_get_dataset_version_structure($identifier, $version);

  return $content;
}

function odp_api_point_api_dataset_version_content($args) {
  $identifier = array_shift($args);
  $version = array_shift($args);

  $content = odp_api_get_dataset_version_content($identifier, $version);

  return $content;
}
