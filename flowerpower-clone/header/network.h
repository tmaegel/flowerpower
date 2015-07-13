#ifndef NETWORK_H

#define NETWORK_H

void init_server(int argc, char* argv[]);
void init_client(int argc, char* argv[]);

int check_for_changes(const char *table, const char *timestamp_last);

void *send_to_server(void *ignored);
void recv_from_client();

int close_client();
int close_server();

#endif
