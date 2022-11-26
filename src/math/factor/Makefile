BIN=../../../bin
LIB=../../../lib/factor
TESTFILES=../../../testfiles

build: $(BIN)/factor
	
run: $(BIN)/factor
	@exec $(BIN)/factor

test: $(BIN)/factor
	@echo "\n******* testing input checking functions *******"
	@exec $(BIN)/factor $(TESTFILES)/factor/input_check.txt
	@echo "\n************** testing performance *************"
	@exec $(BIN)/factor $(TESTFILES)/factor/large_numbers.txt

$(BIN)/factor: init $(LIB)/strnum.o $(LIB)/factor.o $(LIB)/main.o
	cc -o $(BIN)/factor $(LIB)/strnum.o $(LIB)/factor.o $(LIB)/main.o

$(LIB)/main.o: main.c
	cc -o $(LIB)/main.o -c main.c

$(LIB)/factor.o: factor.h factor.c
	cc -o $(LIB)/factor.o -c factor.c

$(LIB)/strnum.o: strnum.h strnum.c
	cc -o $(LIB)/strnum.o -c strnum.c

init:
	@mkdir -p $(BIN) 
	@mkdir -p $(LIB) 

clean:
	rm -f $(BIN)/factor
	rm -f $(LIB)/*
