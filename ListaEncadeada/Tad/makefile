CC = gcc
CFLAGS = -Wall -Wextra

lista: main.o lista.o
	$(CC) main.o lista.o -o lista

main.o: main.c lista.h
	$(CC) $(CFLAGS) -c main.c

lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c

clean:
	rm -f *.o lista