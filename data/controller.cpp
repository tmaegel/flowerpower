//#ifdef RaspberryPi 
 
#include <stdio.h> //for printf
#include <stdint.h> //uint8_t definitions
#include <stdlib.h> //for exit(int);
#include <string.h> //for errno
#include <errno.h> //error output
#include <unistd.h>
#include <stdbool.h>
#include "/usr/local/include/wiringPi.h"
//#include <wiringPi.h>
//#include <wiringSerial.h>
#include "/usr/local/include/wiringSerial.h"
//#include "../struct.h"
#include "controller.h"

char device[]= "/dev/ttyACM0";

int fd;
unsigned long baud = 115200;
unsigned long t = 0;
int number = 0;
struct measurement data;
char str[64];
int i = 0;
int count_raute = 0;
int part = 0;

	char *hw_id = (char*)malloc(10);
	char *temperature = (char*)malloc(256);
	char *humidity = (char*)malloc(256);
	char *brightness = (char*)malloc(256);
	char timestamp[20];
void command(const char cmd[]) {
	if(strcmp(cmd, "rd!") == 0) {
		// read
		serialPutchar(fd, 114);
		serialPutchar(fd, 100);
		serialPutchar(fd, 33);
	} else if(strcmp(cmd, "vo!") == 0) {
		// ventil open
		serialPutchar(fd, 118);
		serialPutchar(fd, 111);
		serialPutchar(fd, 33);
	} else if(strcmp(cmd, "vo!") == 0) {
		// ventil close
		serialPutchar(fd, 118);
		serialPutchar(fd, 99);
		serialPutchar(fd, 33);
	} else {
		printf("wrong command\n");
	}
}

void setup() { 
	printf("%s \n", "Raspberry Startup!");
	fflush(stdout);

	//get filedescriptor
	if((fd = serialOpen (device, baud)) < 0) {
		fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno)) ;
		exit(1); //error
	}

	//setup GPIO in wiringPi mode
	if(wiringPiSetup () == -1) {
		fprintf (stdout, "Unable to start wiringPi: %s\n", strerror (errno)) ;
		exit(1); //error
	}
}
 
int loop(const char *table){
	// Pong every 3 seconds
	if(millis()-t >= 5000){
		// you can also write data from 0-255
		command("rd!");
		//command("vo!");
    	// command("vc!");
		t=millis();
	}
	
	// read signal
	/*if(serialDataAvail(fd)){
  		char newChar = serialGetchar(fd);
		printf("%c", newChar);
		fflush(stdout);
	}*/

	if(serialDataAvail(fd)){
		char c = serialGetchar(fd);
		printf("XX: %c\n", c);
		if(c == '#') {
			str_to_struct(str, table);
			i = 1;
			count_raute++;
		
		}else{
			str[i]  = c;
			i++;
		}

		fflush(stdout);

	}
//	count_raute = 1;
	return count_raute;
}

int str_to_struct(char *str, const char *table){
	//printf("%s\n", str);
	
   
   	char delimiter[] = ";";
	char *ptr;
   	
	

	ptr = strtok(str, delimiter);

	while(ptr != NULL) {
		printf("Abschnitt gefunden: %s\n", ptr);
		part++;
		if(part == 3){
			sscanf(ptr, "%d", &data.hw_id);
		}
		if(part == 4){
			sscanf(ptr, "%lf", &data.temperature);
		}
		if(part == 5){			
			sscanf(ptr, "%lf", &data.humidity);
		}
		if(part == 6){
			sscanf(ptr, "%lf", &data.brightness);
		}
		if(part == 7){
			sscanf(ptr, "%s", data.timestamp);
		}


		ptr = strtok(NULL, delimiter);
	}

	writeToDatabase(table, &data);
	printf("\n\n");
}

int init_ctl(const char *table) {
	setup();
	

	while(number < 3){
		number = loop(table);
	}
	
	return 1;
}
 
//#endif
