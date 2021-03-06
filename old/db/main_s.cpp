
#include <stdio.h>
#include "database.cpp"
#include "../c-s/FP_s.cpp"

#include "../struct.h"

int main(int argc, char* argv[])  {
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

	const char *database = "flowerpower_s";
	const char *table = "table_s";

	//struct measurement data[100];

	init_server(argc, argv);

	init(database, table);
 
	send_db(table);

//	printf("Anzahl der Elemente: %d\n", num);

	close_server();

	closeDatabase();

	return EXIT_SUCCESS;
}
