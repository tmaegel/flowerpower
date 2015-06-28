<?php

/**
 * AUTOLOAD
 */
include "inc_autoload.php";

/**
 * DATABASE
 */
include "inc_database.php";

/**
* @brief Select data
* @param database reference
*/
function selectData($db) {
	$yCount = 3;
	$chart = new jsonChart();

	$dataOut = $db->dbSelect(
							"SELECT
								*
							FROM
								table_s
							ORDER BY
								datetime"
							);

	foreach($dataOut as $item) {
		$y = array();

		$y[] = $item['temp'];
		$y[] = $item['brightness'];
		$y[] = $item['humidity'];

		$chart->data[] = new jsonChartItem($item['datetime'], $y);

		// $yCount++;
	}

	$chart->yCount = $yCount;

	return $chart;
}


switch($_POST['type']) {
	case 'data':
		$result = json_encode(selectData($db));
		break;
}

echo $result;

?>
