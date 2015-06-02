CC = gcc
TARGET = database
SRC = $(TARGET).c
OUT = $(TARGET).o
prog: $(SRC)
	$(CC) -c -I/usr/include/mysql $(SRC)
	$(CC) -o $(TARGET) $(OUT) -L/usr/lib/mysql -lmysqlclient
