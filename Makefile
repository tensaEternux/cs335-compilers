CC=g++ -ggdb3 -std=c++11 -w
BIN=./bin
SOURCE=./src
INPUT=./test
BUILD=./build
OBJ=$(BUILD)/nodes.o     \
		$(BUILD)/symTable.o\
		$(BUILD)/typeCheck.o 

all: $(BIN)/parser

# $(BIN)/compile: $(SOURCE)/compile $(BIN)/compiler
# 	@mkdir -p $(BIN)
# 	cp $< $@

$(BIN)/parser: $(BUILD)/parse.tab.c $(BUILD)/lex.yy.c $(OBJ)
	@mkdir -p $(BIN)
	$(CC) $^ -o $@ -I$(BUILD) -I$(SOURCE)

$(BUILD)/parse.tab.c: $(SOURCE)/parse.y
	@mkdir -p $(BUILD)
	bison -d $^ -o $@

$(BUILD)/lex.yy.c: $(SOURCE)/lexer.l
	@mkdir -p $(BUILD)
	lex -t $^ > $@

$(BUILD)/%.o: $(SOURCE)/%.cpp
	@mkdir -p $(BUILD)
	$(CC) -c $^ -o $@ -I$(BUILD) -I$(SOURCE)

%.png: %.gv
	dot -Tpng $? -o $@

clean : 
	rm -rf $(BIN)  $(BUILD)
	rm -f *.csv *.asm *.txt *.gv
