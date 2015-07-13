/** INCLUDE */
#include <pthread.h>

/** HEADER */
#include "header/var_client.h"
#include "header/database.h"
#include "header/struct.h"
#include "header/controller.h"
#include "header/network.h"

/** SOURCE */
#include "database.cpp"
#include "client.cpp"

pthread_cond_t notready;
pthread_mutex_t lock;

int main(int argc, char *argv[]) {
	int ith1, ith2;
	pthread_t thread1, thread2;

	pthread_cond_init(&notready, NULL);
	pthread_mutex_init(&lock, NULL);

	init_database(database, table);
	init_client(argc, argv);

	//ith1 = pthread_create (&thread1, NULL, init_ctl, (void*) table);
	ith2 = pthread_create(&thread2, NULL, send_to_server, (void*)table);

	//pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	close_client();

	close_database();

	return EXIT_SUCCESS;
}
