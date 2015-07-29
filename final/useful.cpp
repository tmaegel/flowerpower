/** INCLUDE */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/** HEADER */
#include "header/useful.h"
#include "header/struct.h"

void decode_data(char *data1, struct measurement *data2) {
	int part = 1;
	char delimiter[] = ";";
	char *ptr;

	ptr = strtok(data1, delimiter);

	while(ptr != NULL) {
		/** hw_id | temperature | brightness | humidity | timestamp */
		if(part == 2) {
			data2->hw_id = atoi(ptr);
		}
		if(part == 3) {
			data2->temperature = atof(ptr);
		}
		if(part == 4) {
			data2->brightness = atof(ptr);
		}
		if(part == 5) {
			data2->humidity = atof(ptr);
		}
		if(part == 6) {
			strncpy(data2->timestamp, ptr, 20);
		}

		ptr = strtok(NULL, delimiter);
		part++;
	}
}
