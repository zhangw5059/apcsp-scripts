CC=gcc
CFLAGS=-I. -lm
DEPS =
OBJ = MAX44009.o MAX44009_test.o
EXTRA_LIBS=-lwiringPi

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

MAX44009_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f MAX44009 $(OBJ)
