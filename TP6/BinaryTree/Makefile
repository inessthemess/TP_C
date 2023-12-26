CC=gcc
CFLAGS=-W -Wall -pedantic
INCLUDE=./include/


all: main

main:main.o abr.o
	$(CC) -o $@ $^ 


%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE)

clean:
	rm *.o *~ main