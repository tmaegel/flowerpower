#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>
#include <mysql/errmsg.h>

#define TRUE 1
#define FALSE 0

#define HOST "localhost"
#define USER "root"
#define PASSWORD "TrOoNoIt#90+"
#define DATABASE "data"

MYSQL *db;
MYSQL_RES *result;
MYSQL_ROW row;

unsigned int error;

/**
 * @brief check for options
 * @param char* argument
 * @param char* option
 * @return int exists option, true or false
 */
int getOption(const char *arg, const char *opt) {
	if(arg[0] == '-' && arg[1] == opt[0]) {
		return TRUE;
	}
	return FALSE;
}

/**
 * @brief check for errors
 */
void checkError(void) {
	if(mysql_errno(db) != 0) {
		fprintf(stderr, "Error: %u (%s) \n", mysql_errno(db), mysql_error(db));
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief show helping text
 */
void showHelp() {
	printf("\nProgrammaufruf: database [OPT_1] [STRING_1] ...\n"\
	"./database -d [DB_NAME] -t [TABLE_NAME]\n"\
	"\t-h\t\thelp\n"\
	"\t-d\t\tselect database\n"\
	"\t-t\t\tinit table\n\n");
	
	exit(EXIT_FAILURE);
}

/**
 * @brief select items
 * @param char* pointer to string
 * @return int number of read data 
 */
int readFromDatabase(char *data) {
	int num_fields, i;

	mysql_query(db, "SELECT * FROM table_data");
	result = mysql_store_result(db);

	num_fields = mysql_num_fields(result);

	while ((row = mysql_fetch_row(result))) {
		for(i = 0; i < num_fields; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}

	mysql_free_result(result);
	mysql_close(db);

	/**
	 * @todo other return value
	 */
	return 0;
}

/**
 * @brief insert items
 * @param char* pointer to data
 * @return int number of written data
 */
void writeToDatabase(char *data) {	
	// INSERT INTO table_name VALUES (value1, value2, ...)
	/* char query[256];
	snprintf(query, sizeof(query), "CREATE TABLE IF NOT EXISTS %s (id INT AUTO_INCREMENT PRIMARY KEY, hw_id INT, temp FLOAT, brightness FLOAT, humanity FLOAT, datetime DATETIME)", table);
	
	mysql_query(conn, "INSERT INTO writers VALUES('Leo Tolstoy')");

	mysql_query(db, query);
	checkError();
	printf("create table '%s' success\n", table); */
}

/**
 * @brief create database
 * @param char* database name
 */
void createDatabase(const char *database) {
	char query[128];
	snprintf(query, sizeof(query), "CREATE DATABASE IF NOT EXISTS %s", database);

	mysql_query(db, query);
	checkError();
	printf("create database '%s' success\n", database);
}

/**
 * @brief create table
 * @param char* table name
 */
void createTable(const char *table) {
	char query[256];
	snprintf(query, sizeof(query), "CREATE TABLE IF NOT EXISTS %s (id INT AUTO_INCREMENT PRIMARY KEY, hw_id INT, temp FLOAT, brightness FLOAT, humanity FLOAT, datetime DATETIME)", table);

	mysql_query(db, query);
	checkError();
	printf("create table '%s' success\n", table);
}

/**
 * @brief init database
 * @param char* database name
 * @param char* table name
 */
int init(const char *database, const char *table) {	
	char data[256];							/**< pointer to data  */
		
	// init and reserve memory	
	db = mysql_init(NULL);
	checkError();	
	printf("initialize...\n");

	// database connect
	mysql_real_connect(db, HOST, USER, PASSWORD, NULL, 0, NULL, 0);
	checkError();
	printf("connect  success\n");

	createDatabase(DATABASE);	

	// selectt db
	mysql_select_db(db, DATABASE);
	checkError();
	printf("select success\n");

	// create table
	createTable("table_data");

	readFromDatabase(data);

	// close connection
	mysql_close(db);

	return EXIT_SUCCESS;
}
