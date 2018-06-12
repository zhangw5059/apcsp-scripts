CC=gcc
CFLAGS=-I.
DEPS = 
OBJ1 = led-strip-smd3528.o
OBJ2 = led-strip-smd3528-pwm.o
EXTRA_LIBS=-lwiringPi -lpthread
CFLAGS=-std=c99

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

led-blink: $(OBJ1)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

led-pwm: $(OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f led-blink led-pwm $(OBJ1) $(OBJ2)
