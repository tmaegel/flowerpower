CC = gcc
CFLAGS = `pkg-config --cflags opencv` -Wall -O2
LDFLAGS = `pkg-config --libs opencv` -lm
RPI = -lwiringPi -DRaspberryPi
TARGET = controller
SRC = $(TARGET).cpp
OUT = $(TARGET).o
prog: $(SRC)
	$(CC) -c $(MYSQLINC) $(SRC)
