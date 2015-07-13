/** INCLUDE */

/** HEADER */
#include "header/var_server.h"
#include "header/database.h"
#include "header/struct.h"
#include "header/controller.h"
#include "header/network.h"

/** SOURCE */
#include "database.cpp"
#include "server.cpp"

int main(int argc, char* argv[])  {
	init_database(database, table);
	init_server(argc, argv);

	recv_from_client();

	close_server();
	close_database();

	return EXIT_SUCCESS;
}
