
CC=gcc
CFLAGS= -W -Wall -pedantic
INCLUDE= ./include/
PROGRAMS= app

all: $(PROGRAMS)



app: testSante.o main.o
	$(CC) -o $@ $^


main.o: main.c $(INCLUDE)patient.h
	$(CC) -o $@ -c main.c $(CFLAGS) -I$(INCLUDE)

testSante.o: testSante.c $(INCLUDE)patient.h
	$(CC) -o $@ -c testSante.c $(CFLAGS) -I$(INCLUDE)






clean:
	rm -f *.o *~ $(PROGRAMS)