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
 * @param hw id
 */
function selectData($db, $hw_id) {
	$yCount = 3;
	$chart = new jsonChart();

	$dataOut = $db->dbSelect(
							"SELECT
								*
							FROM
								table_s
							WHERE
								hw_id=".$hw_id."
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

/**
* @brief Select hw ids^
* @param database reference
*/
function selectHwId($db) {
	$ids = array();

	$dataOut = $db->dbSelect(
							"SELECT
								hw_id
							FROM
								table_s
							GROUP By
								hw_id"
							);

	foreach($dataOut as $item) {
		$ids[] = $item['hw_id'];
	}

	return $ids;
}


switch($_POST['type']) {
	case 'data':
		$result = json_encode(selectData($db, $_POST['id']));
		break;
	case 'hw-ids':
		$result = json_encode(selectHwId($db));
		break;
}

echo $result;

?>
