<?php
/**
 * @file
 */

class ODConverterCodec_geojson_to_topojson extends ODConverterCodecAbstract {
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
      'input' => 'geojson',
      'output' => 'topojson',
      'utility' => 'topojson_cmd',
    );
  }

  public function convertFile($source, $target) {
    $info = $this->codec();
    $output_format = $this->converter->getFormat($info['output']);
    $input_format = $this->converter->getFormat($info['input']);

    $this->utility->clean();
    $this->utility->setOutputFormat($output_format);
    $this->utility->setInputFormat($input_format);
    $this->utility->setInputFile($source);
    $this->utility->setOutputFile($target);
    $this->utility->setOptions('properties', TRUE);
    $this->utility->execute();
  }

  public function convertString($source) {
    throw new Exception('Not implemented');
  }

  public function __construct(ODConverter $converter) {
    $this->converter = $converter;
  }

  public function setUtility(ODConverterUtilityInterface $utility) {
    $this->utility = $utility;
  }
}