#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>
#include <mysql/errmsg.h>

#include <time.h>

#define HOST "localhost"
#define USER "root"
#define PASSWORD "TrOoNoIt#90+"

MYSQL *db;
MYSQL_RES *result;
MYSQL_ROW row;

/**< struct to manage the measurements */
struct measurement {
	int hw_id;
	double temperature;
	double humidity;
	double brightness;
	char timestamp[20];		/**< char ausreichend, da timestamp in Datenbank als Zeichenkette an SQL übergeben wird */
};

unsigned int error;

/**
 * @brief check for options
 * @param char* argument
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
 * @brief select items
 * @param char* pointer to string
 * @return int number of read data 
 */
int readFromDatabase(const char *table, struct measurement *data) {
	char query[256];
	int num_fields, num = 0;

	snprintf(query, sizeof(query), "SELECT * FROM %s", table);
	
	mysql_query(db, query);
	result = mysql_store_result(db);

	num_fields = mysql_num_fields(result);

	while ((row = mysql_fetch_row(result))) {
		/* for(int i = 0; i < num_fields; i++) {
			printf("%s ", row[i] ? row[i] : "NULL");
		} */
		// printf("\n");

		/**< row[0] ignored, its index */
		data[num].hw_id = atoi(row[1]);
		data[num].temperature = atof(row[2]);
		data[num].humidity = atof(row[3]);
		data[num].brightness= atof(row[4]);
		strcpy(data[num].timestamp, row[5]);
		
		num++;
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
	
	snprintf(query, sizeof(query), "INSERT INTO %s VALUES (NULL, %d, %f, %f, %f, '%s')", table, data->hw_id, data->temperature, data->brightness, data->humidity, data->timestamp);

	printf("%s\n", query);
	mysql_query(db, query);
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
	snprintf(query, sizeof(query), "CREATE TABLE IF NOT EXISTS %s (id INT AUTO_INCREMENT PRIMARY KEY, hw_id INT, temp FLOAT, brightness FLOAT, humidity FLOAT, datetime DATETIME)", table);

	mysql_query(db, query);
	checkError();
	printf("create table '%s' success\n", table);
}

/**
 * @brief Insert simulation data
 */
void insertSimData(const char *table, int num = 100) {
	time_t t1, t2;
	struct measurement data;
	struct tm* tm_info;
	char str_time[26];

	time(&t1);
	srand(time(NULL));
	
	for(int i = 0; i < num; i++) {
		/**< add 10 minutes */
		t2 = t1 + i * 600;
		tm_info = localtime(&t2);

		strftime(str_time, 26, "%Y:%m:%d %H:%M:%S", tm_info);
		
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
