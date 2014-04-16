<?php
/**
 * @file
 */

require_once dirname(__FILE__). '/ODConverterCodec_geojson_to_topojson.inc';
class ODConverterCodec_shapefile_to_topojson extends ODConverterCodec_geojson_to_topojson {
  /**
   * @var ODConverter
   */
  protected $converter = NULL;

  /**
   * @var ODConverterUtilityInterface
   */
  protected $utility = NULL;
  public static function codec() {
    return array(
      'input' => 'shapefile',
      'output' => 'topojson',
      'utility' => 'topojson_cmd',
    );
  }

//  public function convertFile($source, $target) {
//    $info = $this->codec();
//    $output_format = $this->converter->getFormat($info['output']);
//    $input_format = $this->converter->getFormat($info['input']);
//
//    $this->utility->clean();
//    $this->utility->setOutputFormat($output_format);
//    $this->utility->setInputFormat($input_format);
//    $this->utility->setInputFile($source);
//    $this->utility->setOutputFile($target);
//    $this->utility->setOptions('properties', TRUE);
//    return $this->utility->execute();
//  }
}