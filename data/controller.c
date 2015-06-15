#ifdef RaspberryPi 
 
#include <stdio.h> //for printf
#include <stdint.h> //uint8_t definitions
#include <stdlib.h> //for exit(int);
#include <string.h> //for errno
#include <errno.h> //error output
 
#include <wiringPi.h>
#include <wiringSerial.h>
 
char device[]= "/dev/ttyACM0";

int fd;
unsigned long baud = 115200;
unsigned long time=0;
 
int main(void);
void loop(void);
void setup(void);

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

void setup(){ 
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
 
void loop(){
	// Pong every 3 seconds
	if(millis()-time >= 3000){
		// you can also write data from 0-255
		command("rd!");
		// command("vo!");
    	// command("vc!");
		time=millis();
	}
	
	// read signal
	if(serialDataAvail(fd)){
  		char newChar = serialGetchar(fd);
		printf("%c", newChar);
		fflush(stdout);
	} 
}

int main(){
	setup();
	while(1) loop();
	return 0;
}
 
#endif
