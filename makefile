# -*- MakeFile -*-

main: main.o graph.o list.o
	gcc graph.o list.o main.o -o main

main.o: main.c graph.h
	gcc -c main.c 

graph.o: graph.c list.h
	gcc -c graph.c 

list.o: list.c
	gcc -c list.c

clean:
	rm -f *.o main graph list