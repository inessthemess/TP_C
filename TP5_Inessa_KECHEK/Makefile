CC=gcc
CFLAGS= -W -Wall -pedantic
INCLUDE= ./include/


all: main



main: image.o main.o
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE)

clean:
	rm -f *.o *~ all main recorded_lena.pgm bin_lena.pgm bin_lena_inverse.pgm er_lena.pgm dil_lena.pgm 