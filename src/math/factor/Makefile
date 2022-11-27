BIN=~/bin
OBJ=~/obj/factor
OUT_DIR=~/output
OUT_FILE=~/output/factor.txt
TESTFILES=../../../testfiles

build: $(BIN)/factor
	
run: $(BIN)/factor
	@mkdir -p $(OUT_DIR) 
	@echo "\n**********$$(date)**********" >> $(OUT_FILE)
	@exec $(BIN)/factor|tee -a $(OUT_FILE)
	@echo "************************************************"

test: $(BIN)/factor
	@echo "\n******* testing input checking functions *******"
	@exec $(BIN)/factor $(TESTFILES)/factor/input_check.txt
	@echo "\n************** testing performance *************"
	@exec $(BIN)/factor $(TESTFILES)/factor/large_numbers.txt

$(BIN)/factor: init $(OBJ)/strnum.o $(OBJ)/factor.o $(OBJ)/main.o
	cc -o $(BIN)/factor $(OBJ)/strnum.o $(OBJ)/factor.o $(OBJ)/main.o

$(OBJ)/main.o: main.c
	cc -o $(OBJ)/main.o -c main.c

$(OBJ)/factor.o: factor.h factor.c
	cc -o $(OBJ)/factor.o -c factor.c

$(OBJ)/strnum.o: strnum.h strnum.c
	cc -o $(OBJ)/strnum.o -c strnum.c

init:
	@mkdir -p $(BIN) 
	@mkdir -p $(OBJ) 

clean:
	rm -f $(BIN)/factor
	rm -f $(OBJ)/*

clear_output:
	rm -f $(OUT_FILE)
