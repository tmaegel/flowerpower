

// Hello World server

#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>

// Socket talks to clients
void *context = zmq_ctx_new ();
void *responder = zmq_socket (context, ZMQ_REP);

// Global variables & functions
int size;
int major, minor, patch;
extern char *data_to_db;
extern void text_from_S(void);

//  Receive ZeroMQ string from socket and convert into C string
//  Chops string at 255 chars, if it's longer
static char *s_recv (void *responder) {
    	char buffer [256];
    	size = zmq_recv (responder, buffer, 255, 0);
    	if (size == -1)
        	return NULL;
    	if (size > 255)
        	size = 255;
    		buffer [size] = 0;
    		return strdup (buffer);
}

	
int main (int argc, char* argv[])
{
	//scan parameter
        if (1 == argc || 2 == argc) {
                printf("port ip\n");
                return 1;
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
        }


	//report zmq version
	zmq_version (&major, &minor, &patch);
	printf ("Current 0MQ version is %d.%d.%d\n", major, minor, patch);	

	//binding
	int rc = zmq_bind (responder, tcp_addr);
	assert (rc == 0);
	

	while (1) {
		strcpy(data_to_db, s_recv(responder));
		printf ("Received:%s\n", data_to_db);
		text_from_S();
		
		sleep (1); // Do some 'work'
		zmq_send (responder, "World", 255, 0);
	}

	//delete allocated mem	
	free(param_port);
        free(param_ip);
        free(tcp_addr);

	return 0;

}
