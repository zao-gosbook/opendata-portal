<?php
# Move all cached data (except form cache) to memcache storage.
$conf['cache_backends'][] = 'sites/all/modules/contrib/memcache_storage/memcache_storage.inc';
$conf['cache_class_cache'] = 'MemcacheStorage';
//$conf['cache_class_cache_page'] = 'MemcacheStorage';
$conf['cache_class_panels_hash_cache'] = 'MemcacheStorage';

#$conf['maintenance_mode'] = TRUE;

# Do not connect to the database when serving cached page for anonymous users.
#$conf['page_cache_invoke_hooks'] = FALSE;
#$conf['page_cache_without_database'] = TRUE;

# Open persistent memcached connection.
$conf['memcache_storage_persistent_connection'] = TRUE;

# Configure Memcache Storage module.
$conf['memcache_storage_debug'] = FALSE;
$conf['memcache_storage_key_prefix'] = substr(sha1('data.gov.ru'), 0, 8);
$conf['memcache_storage_wildcard_invalidate'] = 60 * 60 * 24 * 5; // 5 days.

# Add multiple memcached instances.
$conf['memcache_servers'] = array(
  'unix:///var/run/memcached/memcached.socket' => 'default',
);

# Set reference between cache bins and memcache server names.
# All other bins will be refered to the 'default' server.
$conf['memcache_bins'] = array(
  'panels_hash_cache'  => 'default',
);

# Set custom expiration for cached pages.
//$conf['memcache_storage_page_cache_custom_expiration'] = TRUE;
//$conf['memcache_storage_page_cache_expire'] = 60 * 60 * 24;  // 1 day.

# Set current extension.
$conf['memcache_extension'] = 'Memcache';

# Configure memcached extenstion.
$conf['memcache_options'] = array(
  Memcached::OPT_TCP_NODELAY => TRUE,
//  Memcached::OPT_BINARY_PROTOCOL => TRUE,
);

