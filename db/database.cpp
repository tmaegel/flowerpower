// #include "interface.h"

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
int getOption(char *arg, char *opt) {
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
 * @brief create database
 * @param char* database name
 */
void createDatabase(char *database) {
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
void createTable(char *table) {
	char query[256];
	snprintf(query, sizeof(query), "CREATE TABLE IF NOT EXISTS %s (id INT AUTO_INCREMENT PRIMARY KEY, hw_id INT, temp FLOAT, brightness FLOAT, humanity FLOAT, datetime DATETIME)", table);

	mysql_query(db, query);
	checkError();
	printf("create table '%s' success\n", table);
}

/**
 * @brief init database
 */
void initDB(/*char *database, char *table*/) {
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

	mysql_query(db, query);
	checkError();
	printf("create table '%s' success\n", table); */
}

/**
 * @brief init db script
 */
int init() {
	
	char data[256];

	// int database = -1, table = -1;				/**< parameter index for arguments */

	//if(argc > 1) {
	//	int argi;								/**< parameter index */
	//	int argument = FALSE;					/**< next parameter must be an argument */
	/*	for(argi = 0; argi < argc; argi++) {
			if(argument == FALSE) {
				if(getOption(argv[argi], "d") == TRUE) {
					argument = TRUE;
				} else if(getOption(argv[argi], "t") == TRUE) {
					argument = TRUE;
				} else if(getOption(argv[argi], "h") == TRUE) {
					showHelp();
				}
			} else {
				argument = FALSE;
				if(getOption(argv[argi-1], "d") == TRUE) {
					database = argi;
				} else if(getOption(argv[argi-1], "t") == TRUE) {
					table = argi;
				} else {
					printf("wrong argument\n");
					exit(EXIT_FAILURE);
				}
			}
		}
	} else {
		showHelp();
	}
	
	if(database != -1 && table != -1) {
		db_init(argv[database], argv[table]);
	} else {
		printf("wrong input\n");
		exit(EXIT_FAILURE);
	}*/

	// init database
	initDB(/*argv[database] , argv[table]*/);

	readFromDatabase(data);

	// close connection
	mysql_close(db);

	return EXIT_SUCCESS;
}

/*int main()  {


	init();	

	return 0;
}*/
