<?php

require_once '../ARC2_TestCase.php';
require_once ARC2_DIR . '/ARC2_Class.php';

class ARC2_ClassTest extends PHPUnit_Framework_TestCase {

    public function setUp() {
         $this->arc2 = new ARC2_Class(array(), new stdClass);
    }

    public function testCamelCase() {
         $this->assertSame("Fish", $this->arc2->camelCase("fish"));
         $this->assertSame("fish", $this->arc2->camelCase("fish", TRUE));
         $this->assertSame("fish", $this->arc2->camelCase("fish", TRUE, TRUE));

         $this->assertSame("FishHeads", $this->arc2->camelCase("fish_heads"));
         $this->assertSame("fishHeads", $this->arc2->camelCase("fish_heads", TRUE));
         $this->assertSame("fishHeads", $this->arc2->camelCase("fish_heads", TRUE, TRUE));

         $this->assertSame("ALLCAPITALS", $this->arc2->camelCase("ALL_CAPITALS"));
    }

    public function testDeCamelCase() {
         $this->assertSame("fish", $this->arc2->deCamelCase("fish"));
         $this->assertSame("Fish", $this->arc2->deCamelCase("fish", TRUE));

         $this->assertSame("fish heads", $this->arc2->deCamelCase("fish_heads"));
         $this->assertSame("Fish heads", $this->arc2->deCamelCase("fish_heads", TRUE));

         $this->assertSame("ALL CAPITALS", $this->arc2->deCamelCase("ALL_CAPITALS"));
    }


    public function testV() {
        $this->assertSame(FALSE, $this->arc2->v(NULL));
        $this->assertSame(FALSE, $this->arc2->v("cats", FALSE, array()));
        $this->assertSame(TRUE, $this->arc2->v("cats", FALSE, array("cats" => TRUE)));

        $o = new stdclass;
        $o->cats = TRUE;
        $this->assertSame(TRUE, $this->arc2->v("cats", FALSE, $o));
    }

    public function testV1() {
        $this->assertSame(FALSE, $this->arc2->v1(NULL));
        $this->assertSame(FALSE, $this->arc2->v1("cats", FALSE, array()));
        $this->assertSame(TRUE, $this->arc2->v1("cats", FALSE, array("cats" => TRUE)));
        $this->assertSame("blackjack", $this->arc2->v1("cats", "blackjack", array("cats" => NULL)));

        $o = new stdclass;
        $o->cats = TRUE;
        $this->assertSame(TRUE, $this->arc2->v1("cats", FALSE, $o));

        $o = new stdclass;
        $o->cats = 0;
        $this->assertSame("blackjack", $this->arc2->v1("cats", "blackjack", $o));
    }

    public function testExtractTermLabel() {
        $this->assertSame("bar", $this->arc2->extractTermLabel('http://example.com/foo#bar'));
        $this->assertSame("bar cats", $this->arc2->extractTermLabel('http://example.com/foo#bar?cats'));
        $this->assertSame("bar", $this->arc2->extractTermLabel('#bar'));
        $this->assertSame("bar", $this->arc2->extractTermLabel('http://example.com/bar'));
        $this->assertSame("bar", $this->arc2->extractTermLabel('http://example.com/bar/'));
    }

}
