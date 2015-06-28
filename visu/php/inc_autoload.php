<?php

/**
 * @brief Classes autoload
 * @param className
 * @return boolean
 */
function __autoload($className) {
	$path = array("php/", "./");
	for($iPath = 0; $iPath < count($path); $iPath++) {
		$pathName = $path[$iPath].$className.".php";
	
		if (file_exists($pathName)) {
			include $pathName;
		}
	}
}

?>
