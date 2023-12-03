
CC=gcc
CFLAGS= -W -Wall -pedantic
INCLUDE= ./include/
PROGRAMS= pilotAuto

all: $(PROGRAMS)



pilotAuto: pilotAuto.o main.o
	$(CC) -o $@ $^


main.o: main.c $(INCLUDE)pilotAuto.h
	$(CC) -o $@ -c main.c $(CFLAGS) -I$(INCLUDE)

pilotAuto.o: pilotAuto.c 
	$(CC) -o $@ -c $^ $(CFLAGS)






clean:
	rm -f *.o *~ $(PROGRAMS)