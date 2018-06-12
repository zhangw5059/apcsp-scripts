CC=gcc
CFLAGS=-I.
DEPS = 
OBJ = smbus.o BMP180.o BMP180_test.o
EXTRA_LIBS=-lm

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BMP180_test: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(EXTRA_LIBS)

.PHONY: clean

clean:
	rm -f BMP180_test $(OBJ) 
