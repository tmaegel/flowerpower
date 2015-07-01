#include <stdio.h>
#include <stdlib.h>
const char *data_to_client = (char*)malloc(32 * sizeof(char));


void text_from_DB(void){


	data_to_client = "Hello_in_from_DB";
}
