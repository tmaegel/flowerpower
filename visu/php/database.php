<?php

/**
 * @author Toni Mägel
 * @brief Verwaltung von Datenbankzugriffe
 */
class database extends PDO {
	
	public $con;			/**< pointer to db connection */
	
	/**
	 * @brief Open database connection
	 * @param host server
	 * @param user user
	 * @param password password
	 * @param database database name
	 */
	public function __construct($host, $user, $password, $database) {
		try {
			$server = "mysql:dbname=$database;host=$host";
			$options = array(PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8');
			$this->con = new PDO($server, $user, $password, $options);
		} catch(PDOException $e) {
			print "Error!: " . $e->getMessage() . "<br/>";
			die();
		}
	}
	
	/**
	 * @brief Close database connection
	 */
	public function __destruct() {
		$this->con = NULL;
	}
	
	/**
	 * @brief Close database connection
	 */
	public function dbClose() {
		$this->con = NULL;
	}
	
	/**
	 * @brief Select
	 * @param query query
	 * @return boolean
	 */
	public function dbSelect($query) {
		$stmt = $this->con->prepare($query);
		$stmt->execute();
		$result = $stmt->fetchAll();
		/*$stmt = $this->con->query($query);
		$result = $stmt->fetchAll();*/
		return $result;
	}
	
	/**
	 * @brief Datenbankanfrage - UPDATE, DELETE, INSERT
	 * @param query Query
	 * @return boolean
	 */
	public function dbQuery($query) {
		$count = $this->con->exec($query);
		return $count;
	}

}

?>
