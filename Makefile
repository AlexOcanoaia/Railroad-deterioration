CFLAGS = -Wall -Werror

build: list.o graph.o main.c 
	gcc $(CFLAGS) list.o graph.o main.c -o main

graph.o: graph.c graph.h
	gcc -c $(CFLAGS) graph.c -o graph.o

list.o: list.c list.h
	gcc -c $(CFLAGS) list.c -o list.o

clean:
	rm main list.o graph.o