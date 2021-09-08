CC=gcc
CFLAGS=-I.
DEPS = ADT.h
OBJ = ADT.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)