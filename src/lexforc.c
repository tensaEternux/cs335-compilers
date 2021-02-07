#include "lexforc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern int column;
extern char* yytext;
extern FILE *yyin;

char *getToken(int tokenid) {
  if (tokenid > 30 && tokenid < 127) {
    char s[2];
    sprintf(s, "%c", (char)tokenid);
    return strdup(s);
  } else {
    return tokens[tokenid];
  }
}

int main(int argc, char* argv[]) {
  int tokenid;
  initTokens();
  FILE *f;
  if (argc == 2) {
    f = fopen(argv[1], "r");
    if (f) {
      yyin = f;
    } else {
      fprintf(stderr, "Input File Does Exist.\n");
      return 0;
    }
  } else {
    fprintf(stderr, "This Program requires 1 argument.\n");
    return 0;
  }
  printf("      Token           Lexeme     Line#  Column#\n");
  while (tokenid = yylex()) {
    //printf("> TOKEN_ID: %d, YYLINE_NO: %d, COLUMN: %d, YYTEXT: %s\n", tokenid, yylineno, column, yytext);
    printf("%12s %15s %7d %7d\n", getToken(tokenid), yytext, yylineno, column-(int)strlen(yytext)+1);
  }
  return 0;
}