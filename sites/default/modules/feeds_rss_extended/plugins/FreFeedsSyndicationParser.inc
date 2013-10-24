<?php

/**
 * Class definition for Extended Common Syndication Parser.
 *
 * Parses RSS and Atom feeds.
 */
class FreFeedsSyndicationParser extends FeedsSyndicationParser {

  /**
   * Implements FeedsParser::parse().
   */
  public function parse(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    module_load_include('inc', 'feeds_rss_extended',  'libraries/fre_common_syndication_parser');
    $feed = fre_common_syndication_parser_parse($fetcher_result->getRaw());
    $result = new FeedsParserResult();
    $result->title = $feed['title'];
    $result->description = $feed['description'];
    $result->link = $feed['link'];
    if (is_array($feed['items'])) {
      foreach ($feed['items'] as $item) {
        if (isset($item['geolocations'])) {
          foreach ($item['geolocations'] as $k => $v) {
            $item['geolocations'][$k] = new FeedsGeoTermElement($v);
          }
        }
        $result->items[] = $item;
      }
    }
    return $result;
  }


  /**
   * Return mapping sources.
   */
  public function getMappingSources() {
    return parent::getMappingSources() + array(
      'description_summary' => array(
        'name' => t('Description summary'),
        'description' => t('Description summary of the feed item.'),
      ),
    );
  }
}
