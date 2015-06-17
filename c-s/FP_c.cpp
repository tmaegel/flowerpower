

// Hello World client
#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 

// Socket talks to server
void *context = zmq_ctx_new ();
void *requester = zmq_socket (context, ZMQ_REQ);

// Global variables & function
int size, set;
int major, minor, patch;
char *data_to_client = (char*)malloc(32 * sizeof(char));
int request_nbr;

//extern int readFromDatabase(char[]);
//extern int init();

//  Receive ZeroMQ string from socket and convert into C string
//  Chops string at 255 chars, if it's longer
static char *s_recv (void *requester) {
        char buffer [256];
        size = zmq_recv (requester, buffer, 255, 0);
        if (size == -1)
                return NULL;
        if (size > 255)
                size = 255;
                buffer [size] = 0;
                return strdup (buffer);
}

char send_client(char *data_to_client){


	//data_to_client = "Hey";	

	//for (request_nbr = 0; request_nbr != 10; request_nbr++) {
		
		printf ("Sending: %s... %d…\n", data_to_client, request_nbr);
		zmq_send (requester, data_to_client, 255, 0);
		printf ("Received:%s\n", s_recv(requester));
	//}
	
	return 0;

}

int close_client(){

	zmq_close (requester);
	zmq_ctx_destroy (context);

	//delete allocated mem
	//delete [] param_port;
	//delete [] param_ip;
	//delete [] tcp_addr;
	
	return 0;
}

int init_client (int argc, char* argv[])
{	
	

	//scan parameter
	if (1 == argc || 2 == argc) {
        	printf("No clientparameter, please type port ip\n");
		exit(0);	        
   	}
	

	char *param_port = (char*)malloc(strlen(argv[1]));
	char *param_ip = (char*)malloc(strlen(argv[2]));
	char *tcp_addr = (char*)malloc(26 * sizeof(char));

	if (3 == argc) {

		strcpy(param_port, argv[1]);
		strcpy(param_ip, argv[2]);

		*(tcp_addr + 0) = 't';	
		*(tcp_addr + 1) = 'c';	
		*(tcp_addr + 2) = 'p';	
		*(tcp_addr + 3) = ':';	
		*(tcp_addr + 4) = '/';	
		*(tcp_addr + 5) = '/';	
		strcpy((tcp_addr + 6), (param_ip));
		*(tcp_addr + (6 + strlen(param_ip))) = ':';
		strcpy((tcp_addr + (7 + strlen(param_ip))), (param_port));
	
		printf("tcp_addr:%s\n", tcp_addr);
	//	printf("tcp_length:%d\n", strlen(tcp_addr));
	}	

	//report zmq version
	zmq_version (&major, &minor, &patch);
   	printf ("Current 0MQ version is %d.%d.%d\n", major, minor, patch);
	
	//begin connecting
	printf ("Connecting to hello world server…\n");
	

	zmq_connect (requester, tcp_addr);
	

	return 0;
}





