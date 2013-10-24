<?php

// Define opendata types.
define('OPENDATA_TYPE_META', 'OpendataMeta');

// Define opendata review step result statuses.
define('OPENDATA_REVIEW_STEP_SUCCESS', 'status');
define('OPENDATA_REVIEW_STEP_WARNING', 'warning');
define('OPENDATA_REVIEW_STEP_FAILURE', 'error');

// Include collection functions for opendata review.
require_once DRUPAL_ROOT . '/' . drupal_get_path('module', 'opendata_review') . '/includes/pages/opendata_review_info.inc';

/**
 * Page callback.
 */
function opendata_review_page_opendata_review() {
  // Return page not found if arc2 or easyrdf is disabled.
  if (!arc2() || !easyrdf()) {
    drupal_not_found();
  }

  // Init variables.
  $content = array();

  // Get $_GET parameters for current page.
  $query = drupal_get_query_parameters();

  // Get url, type and file parameters.
  $url = isset($query['url']) ? $query['url'] : FALSE;
  $type = isset($query['type']) ? $query['type'] : FALSE;
  $file = isset($query['file']) && $query['file'] == 'true' ? TRUE : FALSE;

  // Build rdf xml file if 'url' and 'file' parameters have been set. Normally it shouldn't be set and called by the user.
  // It is used by default opendata validation script, it outputs rdf xml file and exit.

  // Add opendata checking form.
  $content['form'] = drupal_get_form('opendata_review_page_opendata_review_form', $url, $type);

  // Validate opendata if url has been set. Default opendata validation script, that return result of validation.
  if ($url) {
    $content['result'] = opendata_review_page_opendata_review_result($url, $type);
  }

  return $content;
}

/**
 * Form for opendata checking.
 */
function opendata_review_page_opendata_review_form($form, &$form_state, $url, $type) {
  $form['type'] = array(
    '#type' => 'select',
    '#title' => 'Выберите тип проверки',
    '#options' => array(
      'site' => 'Полностью весь сайт (http://example.com/)',
      'list' => 'Страницу списка и страницы паспортов (http://example.com/opendata)',
      'meta' => 'Только страницу паспорта (http://example.com/opendata/data1)',
    ),
    '#default_value' => $type,
  );
  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => 'Введите url для проверки',
    '#default_value' => $url,
  );
  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Проверить',
  );

  return $form;
}

/**
 * Default form submit handler.
 *
 * @see opendata_review_page_opendata_review_form
 */
function opendata_review_page_opendata_review_form_submit($form, &$form_state) {
  $values = $form_state['values'];
  $url = $values['url'];
  $type = $values['type'];

  $form_state['redirect'] = url(current_path(), array('absolute' => TRUE, 'query' => array('url' => $url, 'type' => $type)));
}

/**
 * Default opendata validation script.
 *
 * @param string $url
 *   Web-page url for validation.
 * @param string $type
 *   Type of review. Can be one of "site", "list" or "meta".
 * @param array $vars
 *   Common variable "vars", that be passed through all steps (internal use only).
 *
 * @return array
 *   Renderable array with opendata validation result.
 */
function opendata_review_page_opendata_review_result($url, $type, &$vars = array()) {
  // Init variables.
  $content = array();

  // Format url with scheme.
  $parse_url = parse_url($url);
  if (!isset($parse_url['scheme'])) {
    $url_part_scheme = array(
      'scheme' => 'http',
    );
    $url = http_build_url($url_part_scheme, $url);
  }

  // Format url with path.
  $parse_url = parse_url($url);
  if (!isset($parse_url['path'])) {
    $url_part_path = array(
      'path' => '/',
    );
    $url = http_build_url($url_part_path, $url);
  }

  // Send message about checking.
  drupal_set_message('Выполняется проверка открытых данных по адресу ' . '<i>' . $url . '</i>', 'status');

  // Add variables to "vars".
  $vars['url'] = $url;
  $vars['type'] = $type;

  // Get all steps.
  $steps = opendata_review_page_opendata_review_steps($type);

  // Check url for containing opendata.
  foreach ($steps as $step) {
    // Get step callback.
    $callback = 'opendata_review_page_opendata_review_step_' . $step['type'];

    // Check step callback is callable.
    if (!is_callable($callback)) {
      continue;
    }

    // Get step checking results.
    $step_result = $callback($step, $vars);

    // Prepare message text and type for sending message.
    $message = '<b>' . $step['label'] . '</b>' . ': ' . $step['results'][$step_result];
    $message_type = $step_result;

    // Send message to user.
    drupal_set_message($message, $message_type);

    // Return if step return failure, it means next steps aren't possible.
    if ($step_result === OPENDATA_REVIEW_STEP_FAILURE) {
      break;
    }
  }

  // Make some actions if all steps was passed.
  if (isset($step_result) && $step_result !== OPENDATA_REVIEW_STEP_FAILURE) {
    switch ($type) {
      case 'site':
        // Format url.
        $default_url_list_parts = array(
          'path' => '/opendata',
        );
        $url = http_build_url($url, $default_url_list_parts);

        $content = opendata_review_page_opendata_review_result($url, 'list', $vars);
        break;
      case 'list':
        $opendata_list = $vars['opendata_list'];

        $content['opendata_meta'] = array();
        foreach ($opendata_list as $opendata_meta) {
          $content_opendata_meta[] = opendata_review_page_opendata_review_result($opendata_meta, 'meta', $vars);
        }

        $content_opendata_list = opendata_review_page_opendata_review_opendata_list_render($vars);

        $content = array(
          'opendata_list' => $content_opendata_list,
          'opendata_meta' => $content_opendata_meta,
        );

        break;
      case 'meta':
        // Return opendata table.
        $content = opendata_review_page_opendata_review_opendata_meta_render($vars);
        break;
    }
  }

  return $content;
}

/**
 * Opendata review step callback: check url exists.
 */
function opendata_review_page_opendata_review_step_url_existence(&$step, &$vars) {
  // Fetch variables.
  $url = $vars['url'];

  // Get headers.
  $headers = @get_headers($url);

  // Url doesn't exist if headers is empty or contents 404 Not Found.
  if(!$headers || $headers[0] === 'HTTP/1.1 404 Not Found') {
    return OPENDATA_REVIEW_STEP_FAILURE;
  }

  return OPENDATA_REVIEW_STEP_SUCCESS;
}

/**
 * Opendata review step callback: check url format.
 */
function opendata_review_page_opendata_review_step_url_format(&$step, &$vars) {
  // Fetch variables.
  $url = $vars['url'];
  $type = $vars['type'];

  $parse_url = parse_url($url);
  switch ($type) {
    case 'site':
      if ($parse_url['path'] !== '/') {
        return OPENDATA_REVIEW_STEP_WARNING;
      }
      break;
    case 'list':
      if ($parse_url['path'] !== '/opendata') {
        return OPENDATA_REVIEW_STEP_WARNING;
      }
      break;
    case 'meta':
      // Get first occurrence of a substring in a string.
      $pos = strpos($parse_url['path'], '/opendata/');
      if ($pos === FALSE || $pos !== 0) {
        return OPENDATA_REVIEW_STEP_WARNING;
      }
      break;
  }

  return OPENDATA_REVIEW_STEP_SUCCESS;
}

/**
 * Opendata review step callback: check doctype.
 */
function opendata_review_page_opendata_review_step_doctype(&$step, &$vars) {
  // Fetch variables.
  $url = $vars['url'];

  // Create new dom object.
  $dom = new domDocument;

  // Hide url validation errors.
  $previous_value = libxml_use_internal_errors(TRUE);
  $html = file_get_contents($url);
  $dom->loadHTML($html);
  libxml_clear_errors();
  libxml_use_internal_errors($previous_value);

  // Get site doctype.
  $doctype = $dom->doctype;

  // Check doctype if it exists.
  if (!$doctype) {
    return OPENDATA_REVIEW_STEP_WARNING;
  }

  // Get doctype name.
  $doctype_name = $doctype->name;

  // Check doctype is 'html'.
  if ($doctype_name !== 'html') {
    return OPENDATA_REVIEW_STEP_WARNING;
  }

  // Get doctype public id and doctype system id.
  $doctype_public_id = $doctype->publicId;
  $doctype_system_id = $doctype->systemId;

  // Check doctype public and system ids don't exist, it means that's html5 doctype declaration,
  // that's compatible with RDFa.
  if (!$doctype_public_id && !$doctype_system_id) {
    return OPENDATA_REVIEW_STEP_SUCCESS;
  }

  // Get all compatible doctypes.
  $compatible_doctypes = opendata_review_page_opendata_review_opendata_doctype_list();

  // Check doctype with each compatible doctype.
  $doctype_is_compatible = FALSE;
  foreach ($compatible_doctypes as $compatible_doctype) {
    $compatible_doctype_public_id = $compatible_doctype['public'];
    $compatible_doctype_system_id = $compatible_doctype['system'];
    if ($compatible_doctype_public_id === $doctype_public_id && $compatible_doctype_system_id === $doctype_system_id) {
      $doctype_is_compatible = TRUE;
      break;
    }
  }

  // Return if doctype isn't compatible.
  if (!$doctype_is_compatible) {
    return OPENDATA_REVIEW_STEP_WARNING;
  }

  return OPENDATA_REVIEW_STEP_SUCCESS;
}

/**
 * Opendata review step callback: check opendata list exists.
 */
function opendata_review_page_opendata_review_step_opendata_list(&$step, &$vars) {
  // Fetch variables.
  $url = $vars['url'];

  // Define rdf graph builder url.
  $builder_rdf_graph_url = url('arc2/xml', array('absolute' => TRUE, 'query' => array('file' => 'true', 'url' => $url)));

  // Build rdf graph.
  $graph = new EasyRdf_Graph($builder_rdf_graph_url);
  $graph->load($builder_rdf_graph_url);

  // Save graph to common variable.
  $vars['graph'] = $graph;

  // Method "resources" doesn't work. Arc2 library is under developing now (March 4, 2013) and bugs are available.
  // So with constriction below we simulate method "resources", according to arc2 specification.
  $opendata_list = array_keys($graph->toArray());

  // Remove current url from opendata list.
  $opendata_list = array_diff($opendata_list, array($url));

  // Remove non opendata meta objects from opendata list.
  foreach ($opendata_list as $opendata_meta) {
    // Get dublin core type property from primary object. Opendata should be primary object on opendata page always.
    $dc_type = $graph->get($opendata_meta, 'dc:type');

    if ($dc_type->getValue() !== OPENDATA_TYPE_META) {
      $opendata_list = array_diff($opendata_list, array($opendata_meta));
    }
  }
  $opendata_list = array_values($opendata_list);

  // Add opendata_list to "vars".
  $vars['opendata_list'] = $opendata_list;

  // Return if doctype isn't compatible.
  if (empty($opendata_list)) {
    return OPENDATA_REVIEW_STEP_FAILURE;
  }

  return OPENDATA_REVIEW_STEP_SUCCESS;
}

/**
 * Opendata review step callback: check opendata meta exists.
 */
function opendata_review_page_opendata_review_step_opendata_meta(&$step, &$vars) {
  // Fetch variables.
  $url = $vars['url'];

  // Define rdf graph builder url.
  $builder_rdf_graph_url = url('arc2/xml', array('absolute' => TRUE, 'query' => array('file' => 'true', 'url' => $url)));

  // Build rdf graph.
  $graph = new EasyRdf_Graph($builder_rdf_graph_url);
  $graph->load($builder_rdf_graph_url);

  // Save graph to common variable.
  $vars['graph'] = $graph;

  // Get dublin core type property from primary object. Opendata should be primary object on opendata page always.
  $dc_type = $graph->get($url, 'dc:type');
  if ($dc_type === NULL) {
    $dc_type = $graph->get($url . '/', 'dc:type');
  }

  // Check dublin core type property from primary object, this should be special opendata type.
  if ($dc_type === NULL || $dc_type->getValue() !== OPENDATA_TYPE_META) {
    return OPENDATA_REVIEW_STEP_FAILURE;
  }

  // Create opendata variable when opendata was found.
  if (!isset($vars['opendata'])) {
    $vars['opendata'] = array();
  }

  // Add opendata type to opendata variable.
  $vars['opendata'][$url]['type'] = OPENDATA_TYPE_META;

  return OPENDATA_REVIEW_STEP_SUCCESS;
}

/**
 * Opendata review step callback: check opendata properties are correct.
 */
function opendata_review_page_opendata_review_step_opendata_properties(&$step, &$vars) {
  // Fetch variables.
  $url = $vars['url'];
  $graph = $vars['graph'];

  // Init variables.
  $opendata_properties = array();
  $missed_opendata_properties = array();

  // Get list of properties.
  $properties = opendata_review_page_opendata_review_opendata_property_list();

  // Check opendata on existing each opendata property.
  foreach ($properties as $property) {
    $property_value = $graph->get($url, 'dc:' . $property['type']);
    if ($property_value === NULL) {
      $property_value = $graph->get($url . '/', 'dc:' . $property['type']);
    }

    if ($property_value !== NULL) {
      $opendata_properties[$property['type']] = $property_value;
    }
    else {
      $missed_opendata_properties[] = '<i>' . $property['label'] . '</i>';
    }
  }

  // Add existing opendata properties to opendata variable.
  $vars['opendata'][$url]['properties'] = $opendata_properties;

  // Return failure result message with missed properties.
  if (!empty($missed_opendata_properties)) {
    $step['results']['error'] = $step['results']['error'] . ' (' . implode(', ', $missed_opendata_properties) . ')';
    return OPENDATA_REVIEW_STEP_FAILURE;
  }

  return OPENDATA_REVIEW_STEP_SUCCESS;
}

/**
 * Render validated opendata list.
 *
 * @param array $opendata
 *   Array that contents arrays of properties.
 *
 * @return string
 *   Table with successful validated opendata passport.
 */
function opendata_review_page_opendata_review_opendata_list_render($vars) {
  // Init variables.
  $content = '';

  // Fetch variables.
  $opendata_list = $vars['opendata_list'];
  $opendata = $vars['opendata'];
  $url = $vars['url'];

  // Set table header.
  $table_header = array();
  $table_header[] = array(
    'data' => '№',
  );
  $table_header[] = array(
    'data' => 'Ссылка на набор данных',
  );

  // Set table rows.
  $table_rows = array();
  foreach ($opendata_list as $key => $opendata_meta_source) {
    $property = $opendata[$opendata_meta_source]['properties'];

    $table_row = array(
      'data' => array(),
    );

    $table_row['data'][] = array(
      'data' => $key + 1,
    );
    $table_row['data'][] = array(
      'data' => $opendata_meta_source,
    );

    $table_rows[] = $table_row;
  }

  $table_vars = array(
    'header' => $table_header,
    'rows' => $table_rows,
  );

  $content .= theme('table', $table_vars);

  return array('#markup' => $content);
}

/**
 * Render validated opendata passport.
 *
 * @param array $opendata
 *   Array that contents arrays of properties.
 *
 * @return string
 *   Table with successful validated opendata passport.
 */
function opendata_review_page_opendata_review_opendata_meta_render($vars) {
  // Init variables.
  $content = '';

  // Fetch variables.
  $opendata = $vars['opendata'];
  $url = $vars['url'];

  $properties = opendata_review_page_opendata_review_opendata_property_list();
  foreach ($properties as $property) {
    $type = $property['type'];
    $properties[$type]['value'] = $opendata[$url]['properties'][$type];
  }

  // Set table header.
  $table_header = array();
  $table_header[] = array(
    'data' => '№',
  );
  $table_header[] = array(
    'data' => 'Характеристика',
  );
  $table_header[] = array(
    'data' => 'Значение характеристики',
  );

  // Set table rows.
  $table_rows = array();
  foreach ($properties as $property) {
    $table_row = array(
      'data' => array(),
    );

    $table_row['data'][] = array(
      'data' => $property['id'],
    );
    $table_row['data'][] = array(
      'data' => $property['label'],
    );
    $table_row['data'][] = array(
      'data' => $property['value'],
    );

    $table_rows[] = $table_row;
  }

  $table_vars = array(
    'header' => $table_header,
    'rows' => $table_rows,
  );

  $content .= theme('table', $table_vars);

  return array('#markup' => $content);
}

// Define http_build_url function if it's missing.
if (!function_exists('http_build_url')) {
  define('HTTP_URL_REPLACE', 1);              // Replace every part of the first URL when there's one of the second URL
  define('HTTP_URL_JOIN_PATH', 2);            // Join relative paths
  define('HTTP_URL_JOIN_QUERY', 4);           // Join query strings
  define('HTTP_URL_STRIP_USER', 8);           // Strip any user authentication information
  define('HTTP_URL_STRIP_PASS', 16);          // Strip any password authentication information
  define('HTTP_URL_STRIP_AUTH', 32);          // Strip any authentication information
  define('HTTP_URL_STRIP_PORT', 64);          // Strip explicit port numbers
  define('HTTP_URL_STRIP_PATH', 128);         // Strip complete path
  define('HTTP_URL_STRIP_QUERY', 256);        // Strip query string
  define('HTTP_URL_STRIP_FRAGMENT', 512);     // Strip any fragments (#identifier)
  define('HTTP_URL_STRIP_ALL', 1024);         // Strip anything but scheme and host

  // Build an URL
  // The parts of the second URL will be merged into the first according to the flags argument.
  //
  // @param   mixed           (Part(s) of) an URL in form of a string or associative array like parse_url() returns
  // @param   mixed           Same as the first argument
  // @param   int             A bitmask of binary or'ed HTTP_URL constants (Optional)HTTP_URL_REPLACE is the default
  // @param   array           If set, it will be filled with the parts of the composed url like parse_url() would return
  function http_build_url($url, $parts=array(), $flags=HTTP_URL_REPLACE, &$new_url=FALSE)
  {
    $keys = array('user','pass','port','path','query','fragment');

    // HTTP_URL_STRIP_ALL becomes all the HTTP_URL_STRIP_Xs
    if ($flags & HTTP_URL_STRIP_ALL)
    {
      $flags |= HTTP_URL_STRIP_USER;
      $flags |= HTTP_URL_STRIP_PASS;
      $flags |= HTTP_URL_STRIP_PORT;
      $flags |= HTTP_URL_STRIP_PATH;
      $flags |= HTTP_URL_STRIP_QUERY;
      $flags |= HTTP_URL_STRIP_FRAGMENT;
    }
    // HTTP_URL_STRIP_AUTH becomes HTTP_URL_STRIP_USER and HTTP_URL_STRIP_PASS
    else if ($flags & HTTP_URL_STRIP_AUTH)
    {
      $flags |= HTTP_URL_STRIP_USER;
      $flags |= HTTP_URL_STRIP_PASS;
    }

    // Parse the original URL
    $parse_url = is_string($url) ? parse_url($url) : $url;

    // Parse the original parts
    $parts = is_string($parts) ? parse_url($parts) : $parts;

    // Scheme and Host are always replaced
    if (isset($parts['scheme']))
      $parse_url['scheme'] = $parts['scheme'];
    if (isset($parts['host']))
      $parse_url['host'] = $parts['host'];

    // (If applicable) Replace the original URL with it's new parts
    if ($flags & HTTP_URL_REPLACE)
    {
      foreach ($keys as $key)
      {
        if (isset($parts[$key]))
          $parse_url[$key] = $parts[$key];
      }
    }
    else
    {
      // Join the original URL path with the new path
      if (isset($parts['path']) && ($flags & HTTP_URL_JOIN_PATH))
      {
        if (isset($parse_url['path']))
          $parse_url['path'] = rtrim(str_replace(basename($parse_url['path']), '', $parse_url['path']), '/') . '/' . ltrim($parts['path'], '/');
        else
          $parse_url['path'] = $parts['path'];
      }

      // Join the original query string with the new query string
      if (isset($parts['query']) && ($flags & HTTP_URL_JOIN_QUERY))
      {
        if (isset($parse_url['query']))
          $parse_url['query'] .= '&' . $parts['query'];
        else
          $parse_url['query'] = $parts['query'];
      }
    }

    // Strips all the applicable sections of the URL
    // Note: Scheme and Host are never stripped
    foreach ($keys as $key)
    {
      if ($flags & (int)constant('HTTP_URL_STRIP_' . strtoupper($key)))
        unset($parse_url[$key]);
    }


    $new_url = $parse_url;

    return
      ((isset($parse_url['scheme'])) ? $parse_url['scheme'] . '://' : '')
      .((isset($parse_url['user'])) ? $parse_url['user'] . ((isset($parse_url['pass'])) ? ':' . $parse_url['pass'] : '') .'@' : '')
      .((isset($parse_url['host'])) ? $parse_url['host'] : '')
      .((isset($parse_url['port'])) ? ':' . $parse_url['port'] : '')
      .((isset($parse_url['path'])) ? $parse_url['path'] : '')
      .((isset($parse_url['query'])) ? '?' . $parse_url['query'] : '')
      .((isset($parse_url['fragment'])) ? '#' . $parse_url['fragment'] : '')
      ;
  }
}
