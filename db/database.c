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
#define PASSWORD "root"
#define DATABASE "data"

MYSQL *db;

extern char *data_to_db;					/** data to database */
extern char *data_to_client;				/** data to client */

unsigned int error;

/**
 * check for errors
 */
void checkError(void) {
	if(mysql_errno(db) != 0) {
		fprintf(stderr, "Error: %u (%s) \n", mysql_errno(db), mysql_error(db));
		exit(EXIT_FAILURE);
	}
}

/**
 * replace a string with an other string
 */
char *strReplace(char *search, char *replace, char *subject) {
	char *p, *old_subject, *new_subject;
	int final_size = strlen(replace) - strlen(search) + strlen(subject);
	
	// reserve memory
	new_subject = malloc(final_size);
	// set it to blank
	strcpy(new_subject, "");
	// start position
	old_subject = subject;
	// search position
	p = strstr(subject, search);
	// copy text from orginal subject until search position
	strncpy(new_subject + strlen(new_subject), old_subject, p - old_subject);
	// append the repacement text
	strcpy(new_subject + strlen(new_subject), replace);
	// set start position after search text
	old_subject = p + strlen(search);
	// append the end of the orginial subject
	strcpy(new_subject + strlen(new_subject), old_subject);

	return new_subject;
}     

/**
 * show helping text
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
 * create table
 */
void createTable(char *table) {
	char search[] = "<table>";
	char query[] = "CREATE TABLE IF NOT EXISTS <table> (id INT AUTO_INCREMENT PRIMARY KEY, hw_id INT, temp FLOAT, brightness FLOAT, humanity FLOAT, datetime DATETIME)";
	char *sql_query;
	sql_query = strReplace(search, table, query);

	printf("execute query:\n%s\n", sql_query);
	mysql_query(db, sql_query);
	checkError();
	printf("create table '%s'\n", table);
}

void initDB(/*char *database, char *table*/) {
	// init and reserve memory	
	db = mysql_init(NULL);
	checkError();	
	printf("initialize database \n");

	// database connect
	mysql_real_connect(db, HOST, USER, PASSWORD, DATABASE, 0, NULL, 0);
	checkError();
	printf("connect to database \n");

	// interaction with db

	// selectt db
	mysql_select_db(db, DATABASE);
	checkError();

	// create table
	createTable("table_data");
}

/**
 * select items
 */
void readToDatabase() {
	// INSERT INTO table_name VALUES (value1, value2, ...)
}

/**
 * insert items
 */
void writeToDatabase(struct data *struct_data) {	

	// INSERT INTO table_name VALUES (value1, value2, ...)

	/* printf("execute query:\n%s\n", query);
	mysql_query(db, query);
	checkError();
	printf("insert item\n"); */
}

/**
 * check for options
 */
int getOption(char *arg, char *opt) {
	if(arg[0] == '-' && arg[1] == opt[0]) {
		return TRUE;
	}
	return FALSE;
}

/**
 * init db script
 */
int init() {
	
	
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

	// close connection
	mysql_close(db);

	return EXIT_SUCCESS;
}

int main()  {

	
	printf("%s\n", data_to_db);	

	return 0;
}
