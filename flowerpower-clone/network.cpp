/** INCLUDE */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * global vars (protocoll)
 */
#define HANDSHAKE_INIT          "0"
#define HANDSHAKE_SUCCESS       "1"
#define HANDSHAKE_FAILED        "2"
#define TRANSMISSION_SUCCESS    "3"
#define TRANSMISSION_FAILED     "4"
#define TRANSMISSION_FINISH     "5"
#define READY                   "6"

#define CONTINUE                "99"


/**
 * return 1 if changes
 */
int check_for_changes(const char *table, const char *timestamp_last) {
    char timestamp_tmp[20];
    get_last_timestamp(table, timestamp_tmp);

    // check wheather timstamps are different
    if(strncmp(timestamp_last, timestamp_tmp, 20) == 0) {
        return 0;
    } else {
        return 1;
    }
}
