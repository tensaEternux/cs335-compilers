all: /bin/lexer
bin/lexer: lex.yy.c 
	mkdir bin
	gcc -Isrc/ lex.yy.c src/lexforc.c -o bin/lexer
	rm lex.yy.c
lex.yy.c: src/lexforc.l
	lex src/lexforc.l
clean:
	rm -r bin/	