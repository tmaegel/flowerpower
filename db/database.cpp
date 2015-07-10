#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>
#include <mysql/errmsg.h>

#include <time.h>

#include "../struct.h"

#define HOST "localhost"
#define USER "flowerpower"
#define PASSWORD "flowerpower"

MYSQL *db;
MYSQL_RES *result;
MYSQL_ROW row;

unsigned int error;
time_t t1, t2;
struct tm* tm_info;
char str_time[26];

/**
 * @brief check for options
 * @param char* argumentIst aber egal jetzt :D Mach dir kein Stress. Ich mache die Visualisierung weiter. Musst mir Nächste woche mal genau sagen was da runter geladen hast.
 * @param char* option
 * @return int exists option, true or false
 */
int getOption(const char *arg, const char *opt) {
	if(arg[0] == '-' && arg[1] == opt[0]) {
		return true;
	}
	return false;
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
 * @brief get last timestamp
 * @param char* pointer to table
 * @param char* pointer to tiemstamp
 * @return int error
 */
int getLastTimestamp(const char *table, char *timestamp) {
	char query[256];
	int num, err = 0;

	// Select last datetime
	snprintf(query, sizeof(query), "SELECT datetime FROM %s ORDER BY id DESC LIMIT 1", table);

	mysql_query(db, query);
	result = mysql_store_result(db);

	num = mysql_num_rows(result);
	printf("%d\n", num);
	if(num > 0) {
		err = 1;
		row = mysql_fetch_row(result);
		printf("%s\n", row[0]);
		strcpy(timestamp, row[0]);
	} else {
		err = -1;
	}

	mysql_free_result(result);

	return err;
}

/**
 * @brief select items
 * @param char* pointer to string
 * @param datetime limit (select greater than datetime)
 * @return int number of read data
 */
int readFromDatabase(const char *table, struct measurement *data, const char *datetime = NULL) {
	char query[256];
	int num = 0;

	if(datetime != NULL) {
		snprintf(query, sizeof(query), "SELECT * FROM %s WHERE datetime > '%s'", table, datetime);
	} else {
		snprintf(query, sizeof(query), "SELECT * FROM %s", table);
	}

	mysql_query(db, query);
	result = mysql_store_result(db);

	num = mysql_num_rows(result);

	if(num > 0) {
		printf("Get %d blocks\n", num);
		while ((row = mysql_fetch_row(result))) {
			/**< row[0] ignored, its index */
			data[num].hw_id = atoi(row[1]);
			data[num].humidity = atof(row[2]);
			data[num].temperature = atof(row[3]);
			data[num].brightness= atof(row[4]);
			strcpy(data[num].timestamp, row[5]);

			num++;
		}
	} else {
		printf("No blocks\n");
	}

	mysql_free_result(result);

	return num;
}

/**
 * @brief insert items
 * @param char* pointer to data
 * @todo return int for number of written data
 */
void writeToDatabase(const char *table, struct measurement *data) {
	char query[256];

	snprintf(query, sizeof(query), "INSERT INTO %s VALUES (NULL, %d, %f, %f, %f, '%s')", table, data->hw_id, data->humidity, data->temperature, data->brightness, data->timestamp);

	printf("%s\n", query);
	mysql_query(db, query);
	checkError();
}

/**
 * @brief create database
 * @param char* database name
 */
void createDatabase(const char *database) {
	char query[128];
	snprintf(query, sizeof(query), "CREATE DATABASE IF NOT EXISTS %s", database);

	printf("%s\n", query);
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
	snprintf(query, sizeof(query), "CREATE TABLE IF NOT EXISTS %s (id INT AUTO_INCREMENT PRIMARY KEY, hw_id INT, temp FLOAT, brightness FLOAT, humidity FLOAT, datetime DATETIME)", table);

	printf("%s\n", query);
	mysql_query(db, query);
	checkError();
	printf("create table '%s' success\n", table);
}

/**
 * @brief Insert simulation data
 */
void insertSimData(const char *table, int num = 100) {
	struct measurement data;

	time(&t1);
	srand(time(NULL));

	for(int i = 0; i < num; i++) {
		/**< add 10 minutes */
		t2 = t1 + i * 600;
		tm_info = localtime(&t2);

		strftime(str_time, 26, "%Y-%m-%d %H:%M:%S", tm_info);

		data.hw_id = 1;
		data.temperature = rand() % 30;
		data.brightness = rand() % 150;
		data.humidity = rand() % 80;
		strcpy(data.timestamp, str_time);

		writeToDatabase(table, &data);
	}
}

/**
 * @brief init database
 * @param char* database name
 * @param char* table name
 * @param bool simulate date
 */
void init(const char *database, const char *table, bool simulate = false) {
	char data[256];							/**< pointer to data  */

	// init and reserve memory
	db = mysql_init(NULL);
	checkError();
	printf("initialize...\n");

	// database connect
	mysql_real_connect(db, HOST, USER, PASSWORD, NULL, 0, NULL, 0);
	checkError();
	printf("connect  success\n");

	createDatabase(database);

	// selectt db
	mysql_select_db(db, database);
	checkError();
	printf("select success\n");

	// create table
	createTable(table);

	if(simulate) {
		insertSimData(table);
	}
}

/**
 * @brief close database
 */
void closeDatabase() {
	mysql_close(db);
}
