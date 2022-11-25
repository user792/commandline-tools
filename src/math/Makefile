BIN=../../bin
LIB=../../lib
TESTFILES=../../testfiles

all: factor

factor: init factor.o strnum.o
	cc -o $(BIN)/factor $(LIB)/factor/strnum.o $(LIB)/factor/factor.o factor/main.c
factor.o:
	cc -o $(LIB)/factor/factor.o -c factor/factor.c
strnum.o:
	cc -o $(LIB)/factor/strnum.o -c factor/strnum.c

init:
	mkdir -p ../../bin
	mkdir -p ../../lib
	mkdir -p ../../lib/factor

clean:
	rm $(BIN)/factor
	rm $(LIB)/factor.o
	rm $(LIB)/strnum.o
	
