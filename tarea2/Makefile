CC=gcc
DEBUG=-g
CFLAGS=-Wall

default: eje

eje:  main.o sansano.o CartaCurso.o lista.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o eje

