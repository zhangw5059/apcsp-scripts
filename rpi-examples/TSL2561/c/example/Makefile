CC=gcc
CFLAGS=-I.
DEPS = TSL2561.h
OBJ = TSL2561.o TSL2561_test.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TSL2561_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f TSL2561_test $(OBJ) 
