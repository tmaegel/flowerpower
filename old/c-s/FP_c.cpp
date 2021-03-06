

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


//  Receive ZeroMQ string from socket and convert into C string
//  Chops string at 255 chars, if it's longer
static char *s_recv (void *requester) {
        char buffer [256];
        size = zmq_recv (requester, buffer, 255, 0);
        if (size == -1)
                return NULL; // NULL
        if (size > 255)
        		size = 255;
       			buffer [size] = 0;
       			return strdup (buffer);
}




void *send_client(void*ptr_sc){//(const char *table){


	const char *table;
	table = (char*) ptr_sc;

	struct measurement data[5];

	int dataLength;
	char *hw_id = (char*)malloc(10);
	char *temperature = (char*)malloc(256);
    char *humidity = (char*)malloc(256);
    char *brightness = (char*)malloc(256);
    char *timestamp = (char*)malloc(256);
	char *timestamp_tmp = (char*)malloc(256);
	int counts = 0;
	int num;
	extern pthread_cond_t notready;
	extern pthread_cond_t ready;
	extern pthread_mutex_t lock_c;



	while(1){
		pthread_mutex_lock(&lock_c);
		pthread_cond_wait(&notready, &lock_c);
		zmq_send(requester, "GO", 255, 0);
	
		while(1) {
			strcpy(timestamp_tmp, s_recv(requester));
			printf("Timestamp: %s\n", timestamp_tmp); 
			printf("Send Ready\n");
			zmq_send (requester, "client_ready", 255, 0);
			sleep(1);
			
			if(strncmp(s_recv(requester), "server_ready", 12) == 0) {
				printf("Handshake Server Ready\n");
				break;
		}
		
		}


		if(strncmp(timestamp_tmp, "notimestamp", 11) == 0){
		printf("readfromDatabase without timestamp\n");
		num = readFromDatabase(table, data);

		}

		else{
		printf("readfromDatabase with timestamp\n");
		num = readFromDatabase(table, data, timestamp_tmp);
		}



		dataLength = sizeof(data) / sizeof(data[0]);
		printf("num:%d\n", num);
		printf("datalength:%d\n", dataLength);	



			if(num > 0){
				
				for(int i = 0; i < dataLength; i++) {
				//printf("data_hum:%f\n", data[i].humidity);
					if(data[i].humidity != 0){
						printf("%d / %d\n",i, dataLength); 
						printf("Datastruct: %d %f %f %f %s\n", data[i].hw_id, data[i].humidity, data[i].temperature, data[i].brightness, data[i].timestamp);

						sprintf(hw_id,"%d", data[i].hw_id);
						printf ("Sending: %s ... %d \n", hw_id, request_nbr);
						zmq_send (requester, hw_id, 255, 0);
						printf ("Received:%s\n", s_recv(requester));

						sprintf(humidity,"%f", data[i].humidity);
						printf ("Sending: %s ... %d \n", humidity, request_nbr);
						zmq_send (requester, humidity, 255, 0);
						printf ("Received:%s\n", s_recv(requester));

						sprintf(temperature,"%f", data[i].temperature);
						printf ("Sending: %s ... %d \n", temperature, request_nbr);
						zmq_send (requester, temperature, 255, 0);
						printf ("Received:%s\n", s_recv(requester));
					
						sprintf(brightness,"%f", data[i].brightness);
						printf ("Sending: %s ... %d \n", brightness, request_nbr);
						zmq_send (requester, brightness, 255, 0);
						printf ("Received:%s\n", s_recv(requester));

						sprintf(timestamp,"%s", data[i].timestamp);
						printf ("Sending: %s ... %d \n", timestamp, request_nbr);
						zmq_send (requester, timestamp, 255, 0);
						printf ("Received:%s\n", s_recv(requester));

						counts++;
						printf("sended data\n");
					}

				/*zmq_send(requester, "client_finish", 255, 0);
				while(1){
				if(strncmp(s_recv(requester), "server_finish", 13) == 0) {
					printf("Handshake Server Finish\n");
					break;
				}
				}
				sleep(1);*/
			}
		
		//else{
			//	zmq_send (requester, "0", 255, 0);
		//	}
	}			
		sleep(4);
		pthread_mutex_unlock(&lock_c);
		printf("sended data complete\n");
		pthread_cond_signal(&ready);
		printf("sended data complete2\n");
  }	
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
	printf ("Connecting to hello world server\n");
	

	zmq_connect (requester, tcp_addr);
	

	return 0;
}





