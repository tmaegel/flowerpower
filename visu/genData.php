<?php

	/**
 	 * AUTOLOAD
 	 */
	include "php/inc_autoload.php";

	/**
	 * DATABASE
	 */
	include "php/inc_database.php";
	echo "connection to database ...<br />";

	echo "generate random data<br />";

	$max = 100;
	
	date_default_timezone_set('Europe/Berlin');
	$date = new DateTime(date("Y-m-d H:i:s", time()));

	$count = 0;
	for($i = 0; $i < $max; $i++) {
		// add 10 minutes
		$date->add(new DateInterval('PT10M'));
		$dateStr = $date->format('Y-m-d H:i:s');
	
		$temp = rand(15, 25);
		$brightness = rand(0, 100);
		$humanity = rand(20, 50);
	
		// write to database
		$result = $db->dbQuery("INSERT INTO table_data value(NULL, 1, $temp, $brightness, $humanity, '".$dateStr."')");
		
		if($result > 0) {
			$count++;
		} 
	}

	echo $count." items was written ...";	 
	
?> 
