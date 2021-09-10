CC=gcc
CFLAGS=-I.
DEPS = graph.h list.h 
OBJ = graph.o list.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)