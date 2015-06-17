
#include <stdio.h>
#include "database.cpp"
#include "/home/moe/workspace/fp_github/flowerpower/c-s/FP_c.cpp"

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

	const char *database = "db_data";
	const char *table = "table_data";
	

	struct measurement data[100];
	
		
	
	init_client(argc, argv);

	init(database, table);

	int num = readFromDatabase(table, data);

	/**< conversion to string and send */
	int dataLength = sizeof(data) / sizeof(data[0]);
	char *hw_id = (char*)malloc(10);
	char *temperature = (char*)malloc(256);
	char *humidity = (char*)malloc(256);
	char *brightness = (char*)malloc(256);
	char *timestamp = (char*)malloc(256);

	for(int i = 0; i < dataLength; i++) {

		printf("%d %f %f %f %s\n", data[i].hw_id, data[i].temperature, data[i].humidity, data[i].brightness, data[i].timestamp);

		sprintf(hw_id,"%d", data[i].hw_id);
		sprintf(temperature,"%f", data[i].temperature);
		sprintf(humidity,"%f", data[i].humidity);
		sprintf(brightness,"%f", data[i].brightness);
		sprintf(timestamp,"%s", data[i].timestamp);
		send_client(hw_id);
		send_client(temperature);
		send_client(humidity);
		send_client(brightness);
		send_client(timestamp);
			
	}



	printf("Anzahl der Elemente: %d\n", num);

	close_client();

	closeDatabase();
	
	return EXIT_SUCCESS;
}
