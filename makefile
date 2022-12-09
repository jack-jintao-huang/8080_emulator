CC=gcc
CFLAGS=-I.
DEPS = emulator.h
OBJ = emulator.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

emulator: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)