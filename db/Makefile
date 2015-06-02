CC = gcc
TARGET = database
SRC = $(TARGET).c
OUT = $(TARGET).o
prog: $(SRC)
	$(CC) -c -I/usr/include/mysql $(SRC)
	$(CC) -o $(TARGET) $(OUT) FP_DB_to_C.cpp FP_S_to_DB.cpp -L/usr/lib/mysql -lmysqlclient
