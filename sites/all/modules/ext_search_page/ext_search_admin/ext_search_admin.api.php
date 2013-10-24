<?php

/**
 * @file
 * Hooks provided by Extended search admin.
 */

/**
 * This hook is called to alter admin content header.
 * @see ext_search_admin_content_node_headers()
 * 
 * @param $headers
 *   Table headers to alter
 * @param $page
 * 		The object representing the target search page
 * 
 * @ingroup hooks
 */
function hook_ext_search_admin_headers_alter(&$headers, $page)
{
  // stuff : add a column header
}

/**
 * This hook is called to alter admin content node line.
 * @see ext_search_admin_admin_content_admin_nodes()
 * 
 * @param $record
 *   The line record to alter
 * @param $context
 *   An array keyed with :
 * 		 - page : The object representing the target search page
 *     - headers : the current headers
 *     - node : the current node
 * 
 * @ingroup hooks
 */
function hook_ext_search_admin_record_alter(&$record, $context)
{
  // more stuff : add a column
}