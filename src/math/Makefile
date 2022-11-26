BIN=../../bin
OBJ=../../obj
TESTFILES=../../testfiles

all: $(BIN)/factor

factor: $(BIN)/factor

$(BIN)/factor: init $(OBJ)/factor/strnum.o $(OBJ)/factor/factor.o $(OBJ)/factor/main.o
	cc -o $(BIN)/factor $(OBJ)/factor/strnum.o $(OBJ)/factor/factor.o $(OBJ)/factor/main.o

$(OBJ)/factor/main.o: factor/main.c
	cc -o $(OBJ)/factor/main.o -c factor/main.c

$(OBJ)/factor/factor.o: factor/factor.c factor/factor.h
	cc -o $(OBJ)/factor/factor.o -c factor/factor.c

$(OBJ)/factor/strnum.o: factor/strnum.c factor/strnum.h
	cc -o $(OBJ)/factor/strnum.o -c factor/strnum.c

init:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)
	mkdir -p $(OBJ)/factor

clean:
	rm -f $(BIN)/factor
	rm -f $(OBJ)/factor/*
