CC = gcc
CFLAGS = `pkg-config --cflags opencv` -Wall -O2
LDFLAGS = `pkg-config --libs opencv` -lm
TARGET = controller
SRC = $(TARGET).c
OUT = $(TARGET).o
prog: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(SRC) -lwiringPi -DRaspberryPi

