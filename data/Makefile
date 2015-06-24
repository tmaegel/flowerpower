CC = gcc
CFLAGS = `pkg-config --cflags opencv` -Wall -O2
LDFLAGS = `pkg-config --libs opencv` -lm
RPI = -lwiringPi -DRaspberryPi
TARGET = controller
HEADER = $(TARGET).h
SRC = $(TARGET).cpp
OUT = $(TARGET).o
prog: $(SRC) $(HEADER)
	# $(CC) -o $(TARGET) $(SRC) $(CFLAGS) $(LDFLAGS) $(RPI)
	$(CC) -c $(SRC) $(CFLAGS) $(LDFLAGS) $(RPI)
