
CC=gcc
CFLAGS= -W -Wall -pedantic
INCLUDE= ./include/
PROGRAMS= app

all: $(PROGRAMS)



app: reservation.o main.o
	$(CC) -o $@ $^


main.o: main.c $(INCLUDE)reservation.h
	$(CC) -o $@ -c main.c $(CFLAGS) -I$(INCLUDE)

reservation.o: reservation.c $(INCLUDE)reservation.h
	$(CC) -o $@ -c reservation.c $(CFLAGS) -I$(INCLUDE)






clean:
	rm -f *.o *~ $(PROGRAMS)