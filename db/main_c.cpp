#include <stdio.h>
#include <pthread.h>
#include "database.cpp"
#include "../c-s/FP_c.cpp"
#include "../struct.h"
#include "../data/controller.cpp"

void *send_client (void *ptr_sc);
void *init_ctl (void *ptr_ic);

pthread_cond_t notready;
pthread_mutex_t lock;

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

	const char *database = "flowerpower_c";
	const char *table = "table_c";

	int ith1 ;
	int ith2 ;
	
	pthread_cond_init(&notready, NULL);
	pthread_mutex_init(&lock, NULL);
	pthread_t thread1, thread2;
	
	init_client(argc, argv);
	init(database, table);

	ith1 = pthread_create (&thread1, NULL, init_ctl, (void*) table);
	ith2 = pthread_create (&thread2, NULL, send_client, (void*) table);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	//printf("Anzahl der Elemente: %d\n", num);


	close_client();

	closeDatabase();

	return EXIT_SUCCESS;
}
