BIN=../../bin
LIB=../../lib
TESTFILES=../../testfiles

all: $(BIN)/factor

factor: $(BIN)/factor

$(BIN)/factor: init $(LIB)/factor/strnum.o $(LIB)/factor/factor.o $(LIB)/factor/main.o
	cc -o $(BIN)/factor $(LIB)/factor/strnum.o $(LIB)/factor/factor.o $(LIB)/factor/main.o

$(LIB)/factor/main.o: factor/main.c
	cc -o $(LIB)/factor/main.o -c factor/main.c

$(LIB)/factor/factor.o: factor/factor.c factor/factor.h
	cc -o $(LIB)/factor/factor.o -c factor/factor.c

$(LIB)/factor/strnum.o: factor/strnum.c factor/strnum.h
	cc -o $(LIB)/factor/strnum.o -c factor/strnum.c

init:
	mkdir -p $(BIN)
	mkdir -p $(LIB)
	mkdir -p $(LIB)/factor

clean:
	rm -f $(BIN)/factor
	rm -f $(LIB)/factor/*
