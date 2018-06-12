CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = led-rgb.o
EXTRA_LIBS=-lwiringPi

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

led-rgb: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f led-rgb $(OBJ) 
