CC=gcc
CFLAGS=-W -Wall -pedantic
INCLUDE=./include/


all: main


main: list.o main.o
	$(CC) -o $@ $^


%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE)

clean:
	rm -f *.o *~ all
