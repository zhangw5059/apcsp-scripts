CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = motor.o
EXTRA_LIBS=-lwiringPi -lpthread

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

motor: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f motor $(OBJ) 
