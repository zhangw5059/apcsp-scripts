CC=gcc
CFLAGS=-I.
DEPS =
OBJ = TSL2561.o
EXTRA_LIBS=-lwiringPi

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TSL2561: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f TSL2561 $(OBJ)
