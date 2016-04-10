IDIR =./
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./
LDIR =../lib

LIBS=-lm

_DEPS = List.h map.h status.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = List.o map.o mapLauncher.o status.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

CityMap: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 