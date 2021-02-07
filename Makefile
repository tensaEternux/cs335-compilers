all: bin/lexer
bin/lexer: y.tab.h lex.yy.c 
	mkdir -p bin
	gcc -Isrc/ lex.yy.c src/lexforc.c -o bin/lexer
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
y.tab.h: src/lexforc.y
	yacc -d src/lexforc.y
lex.yy.c: src/lexforc.l
	lex src/lexforc.l
clean:
	rm -r bin/	