CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = sn754410.o
EXTRA_LIBS=-lwiringPi -lpthread

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sn754410: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f sn754410 $(OBJ) 
