/** INCLUDE */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <zmq.h>

/** HEADER */
#include "header/var_server.h"
#include "header/database.h"
#include "header/struct.h"
#include "header/network.h"
#include "header/useful.h"

/** SOURCE */
#include "useful.cpp"
#include "network.cpp"

#define LOOP_SLEEP_TIME 10

// Socket talks to clients
void *context = zmq_ctx_new();
void *responder = zmq_socket(context, ZMQ_REP);

void recv_from_client() {
    char recv_buffer[2], recv_data[256], timestamp_server_last[20];
	struct measurement data;

    while(1) {
        bool ready = false;

        zmq_recv(responder, recv_buffer, 2, 0);
        if(strncmp(recv_buffer, HANDSHAKE_INIT, 2) == 0) {
            printf("handshake init\n");
            // handshake, send timestamp to client
            get_last_timestamp(table, timestamp_server_last);
            while (1) {
                zmq_send(responder, timestamp_server_last, 20, 0);
                // if handshake succes begin transmission, otherwise repeat
                zmq_recv(responder, recv_buffer, 2, 0);
                if(strncmp(recv_buffer, HANDSHAKE_SUCCESS, 2) == 0) {
                    printf("handshake success\n");
                    ready = true;
                    break;
                } else if(strncmp(recv_buffer, HANDSHAKE_FAILED, 2) == 0) {
                    printf("handshake failed\n");
                }

                sleep(5);
            }

            if(ready == true) {
                while (1) {
                    int rc = zmq_recv(responder, recv_data, 256, 0);

                    if(rc > 0) {
                        if(strncmp(recv_data, TRANSMISSION_FINISH, 2) == 0) {
                            zmq_send(responder, TRANSMISSION_FINISH, 2, 0);
                            printf("transmission finish\n");
                            break;
                        }

                        // length 4 = greater than protocol codes
                        if(strlen(recv_data) >= 4) {
                            // transmission success
                            zmq_send(responder, TRANSMISSION_SUCCESS, 2, 0);
                            printf("transmission success\n");
                            decode_data(recv_data, &data);
                            write_to_database(table, &data);
                        } else {
                            // transmission failed
                            zmq_send(responder, TRANSMISSION_FAILED, 2, 0);
                            printf("transmission failed\n");
                        }
                    } else {
                        zmq_send(responder, TRANSMISSION_FAILED, 2, 0);
                        printf("transmission error %d\n", rc);
                    }
                }
            }
        }

        printf("\n\n");
        sleep(LOOP_SLEEP_TIME);
    }
}

void init_server(int argc, char *argv[]) {
    int major, minor, patch;
    char tcp_addr[30];

    //scan parameter
    if (1 == argc || 2 == argc) {
        printf("No server parameter, please type port ip\n");
        exit(0);
    }

    printf("\n\n");

    //report zmq version
    zmq_version (&major, &minor, &patch);
    printf ("Current 0MQ version is %d.%d.%d\n", major, minor, patch);

    snprintf(tcp_addr, sizeof(tcp_addr), "tcp://%s:%s", argv[2], argv[1]);
    printf("bind to %s\n", tcp_addr);

    int rc = zmq_bind(responder, tcp_addr); /** tcp://*:5555 */
    if(rc == 0) {
        printf("bind success\n");
    } else {
        printf("bind failed\n");
        exit(EXIT_FAILURE);
    }
}

int close_server() {

    //delete allocated mem
    //free(param_port);
    // free(param_ip);
    // free(tcp_addr);

	return 0;
}
