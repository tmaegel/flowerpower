#include "database.cpp"

int main()  {
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

	const char *database = "db_data";
	const char *table = "table_data";

	struct measurement data[100];

	init(database, table);

	int num = readFromDatabase(table, data);

	/**< check for data */
	int dataLength = sizeof(data) / sizeof(data[0]);
	for(int i = 0; i < dataLength; i++) {
		printf("%d %f %f %f %s\n", data[i].hw_id, data[i].temperature, data[i].humidity, data[i].brightness, data[i].timestamp);
	}

	printf("Anzahl der Elemente: %d\n", num);

	closeDatabase();
	
	return EXIT_SUCCESS;
}
