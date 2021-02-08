#include "lexforc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Lexer of C language
 * Help:
 * */

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

void printhelp();
void printabout();
void printerror();

int main(int argc, char* argv[]) {
  int tokenid;
  initTokens();
  char *inputfiles[15];
  int inputfilescount=0;
  FILE *outfile = NULL;
  // Handle Arguments
  if (argc == 1) {
    printhelp();
  } else {
    // -h and -v
    for (int i=1; i<argc; i++) {
      if (argv[i][0] == '-') {
        if (argv[i][1] == 'v') {
          printabout();
          return 0;
        } else if (argv[i][1] == 'h') {
          printhelp();
          return 0;
        }
      }
    }
    // -o and input files
    for (int i=1; i<argc; i++) {
      if (argv[i][0] == '-' && argv[i][1] == 'o') {
        if (i == argc-1 || argv[i+1][0] == '-') {
          printerror();
          return 0;
        } else {
          outfile = fopen(argv[i+1], "w");
          i++;
        }
      } else if (argv[i][0] != '-') {
        inputfiles[inputfilescount++] = strdup(argv[i]);
      }
    }
  }
  if (inputfilescount == 0) {
    fprintf(stderr, "Atleast one input file is needed.\n");
    return 0;
  }
  // Open all Input files
  FILE *infiles[inputfilescount];
  for (int i=0; i<inputfilescount; i++) {
    infiles[i] = fopen(inputfiles[i], "r");
    if (!infiles[i]) {
      fprintf(stderr, "Input File <%s> Does Exist.\n", inputfiles[i]);
      return 0;
    }
  }
  if (outfile == NULL) {
    printf("      Token           Lexeme     Line#  Column#\n");
  } else {
    fprintf(outfile, "      Token           Lexeme     Line#  Column#\n");
  }
  for (int i=0; i<inputfilescount; i++) {
    if (inputfilescount > 1) {
      if (outfile == NULL) {
        printf("\n%s:\n", inputfiles[i]);
      } else {
        fprintf(outfile, "\n%s:\n", inputfiles[i]);
      }
    }
    yyin = infiles[i];
    while (tokenid = yylex()) {
      //printf("> TOKEN_ID: %d, YYLINE_NO: %d, COLUMN: %d, YYTEXT: %s\n", tokenid, yylineno, column, yytext);
      if (outfile == NULL) {
        printf("%12s %15s %7d %7d\n", getToken(tokenid), yytext, yylineno, column-(int)strlen(yytext)+1);
      } else {
        fprintf(outfile, "%12s %15s %7d %7d\n", getToken(tokenid), yytext, yylineno, column-(int)strlen(yytext)+1);
      }
    }
  }
  // Close All Opened Files
  for (int i=0; i<inputfilescount; i++) {
    fclose(infiles[i]);
  }
  if (outfile != NULL) {
    fclose(outfile);
  }
  return 0;
}

void printhelp() {
  printf("Usage: lexer [OPTIONS] [FILE 1] [FILE 2] [FILE 3] ...\n");
  printf("Generates analysed output to file or stdout if -o option is not provided.\n\n");
  printf("Options:\n");
  printf("  -h           Print this help message\n");
  printf("  -v           Print version and about the program\n");
  printf("  -o <file>    Print output to <file>\n");
  printf("\nExamples:\n");
  printf("  $ lexer test1.c -o output.txt\n");
}

void printabout() {
  printf("lexer 1.0.0\n");
}

void printerror() {
  fprintf(stderr, "Wrong arguments, please check help with -h.\n");
}