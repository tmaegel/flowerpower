<?php

/**
 * JSON ChartItem Object
 */
class jsonChartItem {
	public $x;
	public $y = array();

	public function __construct($x, $y) {
		$this->x = $x;
		$this->y = $y;
	}
}

?>
