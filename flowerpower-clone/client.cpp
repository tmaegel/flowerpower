/** INCLUDE */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <zmq.h>

/** HEADER */
#include "header/var_client.h"
#include "header/database.h"
#include "header/struct.h"
#include "header/network.h"

/** SOURCES */
#include "network.cpp"

#define LOOP_SLEEP_TIME 10

// Socket talks to server
void *context = zmq_ctx_new();
void *requester = zmq_socket(context, ZMQ_REQ);

char timestamp_client_last[20];

void* send_to_server(void *ignored) {
    bool init = true;
    int data_index = 0, num, length = 5, size;
    char recv_buffer[20], send_buffer[256], timestamp_server_last[20];
    struct measurement data[length];

    while(1) {
        zmq_send(requester, HANDSHAKE_INIT, 2, 0);
        printf("handshake init\n");
        while(1) {
            int rc = zmq_recv(requester, recv_buffer, 20, 0);
            if(strlen(recv_buffer) >= 4 && rc > 0) {
                strncpy(timestamp_server_last, recv_buffer, 20);
                break;
            } else {
                printf("handshake failed\n");
                zmq_send(requester, HANDSHAKE_FAILED, 2, 0);
            }

            sleep(5);
        }

        // check for differences
        if(check_for_changes(table, timestamp_server_last) == 1) {
            zmq_send(requester, HANDSHAKE_SUCCESS, 2, 0);
            printf("handshake success\n");

            if(strcmp(timestamp_server_last, "none") == 0) {
                printf("get all data\n");
                num = read_from_database(table, data, length);
        	} else {
                printf("get timestamp based data\n");
                num = read_from_database(table, data, length, timestamp_server_last);
            }

            printf("transmitt %d blocks\n", num);
        	//pthread_cond_wait(&notready, &lock);

            while(data_index < num) {
                sprintf(send_buffer, "#;%d;%f;%f;%f;%s", data[data_index].hw_id, data[data_index].temperature, data[data_index].brightness, data[data_index].humidity, data[data_index].timestamp);

                zmq_send(requester, send_buffer, 256, 0);
                printf("sending data %s\n", send_buffer);

                // if transmission success, next otherwise skip
                int rc = zmq_recv(requester, recv_buffer, 2, 0);
                if(rc > 0) {
                    if(strncmp(recv_buffer, TRANSMISSION_SUCCESS, 2) == 0) {
                        printf("transmission success\n");
                        data_index++;
                    } else if(strncmp(recv_buffer, TRANSMISSION_FAILED, 2) == 0) {
                        printf("transmission failed\n");
                    }
                } else {
                        printf("transmission error %d\n", rc);
                }
            }

            // send finish transmission
            while(1) {
                zmq_send(requester, TRANSMISSION_FINISH, 2, 0);

                zmq_recv(requester, recv_buffer, 2, 0);
                if(strncmp(recv_buffer, TRANSMISSION_FINISH, 2) == 0) {
                    data_index = 0;
                    printf("transmission finish\n");
                    break;
                }
            }

        } else {
                printf("no changes\n");
        }

        printf("\n\n");
        sleep(LOOP_SLEEP_TIME);
    }
}

void init_client(int argc, char *argv[]) {
    int major, minor, patch;
    char tcp_addr[30];

    //scan parameter
    if(1 == argc || 2 == argc) {
        printf("No clientparameter, please type port ip\n");
        exit(0);
    }

    printf("\n\n");

    //report zmq version
    zmq_version(&major, &minor, &patch);
    printf("Current 0MQ version is %d.%d.%d\n", major, minor, patch);

    snprintf(tcp_addr, sizeof(tcp_addr), "tcp://%s:%s", argv[2], argv[1]);
    printf("connect to %s\n", tcp_addr);

    printf ("connecting to server\n");
    int rc = zmq_connect(requester, tcp_addr); /** tcp://localhost:5555 */
    if(rc == 0) {
        printf("connect success\n");
    } else {
        printf("connect failed\n");
        exit(EXIT_FAILURE);
    }
}

int close_client() {

    zmq_close(requester);
    zmq_ctx_destroy(context);

    printf("disconnect\n");

	return 0;
}
