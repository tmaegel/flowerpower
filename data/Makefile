CC = gcc
CFLAGS = `pkg-config --cflags opencv` -Wall -O2
LDFLAGS = `pkg-config --libs opencv` -lm
RPI = -lwiringPi -DRaspberryPi
MYSQLLIB = -L/usr/lib/mysql -lmysqlclient
MYSQLINC = -I/usr/include/mysql
TARGET = controller
SRC = $(TARGET).cpp
OUT = $(TARGET).o
prog: $(SRC)
	$(CC) -c $(MYSQLINC) $(SRC)
	$(CC) -o $(TARGET) $(OUT) $(CFLAGS) $(LDFLAGS) $(MYSQLLIB) $(RPI)
