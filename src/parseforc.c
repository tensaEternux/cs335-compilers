#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parseforc.h"

/* Perser for C language
 * Help:
 * */

extern int yylex();
extern int yyparse();
extern int yylineno;
extern int column;
extern char* yytext;
extern FILE *yyin;
FILE *outfile;
int id_count;

int main(int argc, char* argv[]) {
  id_count = 0;
  yyin = NULL;
  outfile = NULL;
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
    // -o and input file
    for (int i=1; i<argc; i++) {
      if (argv[i][0] == '-' && argv[i][1] == 'o') {
        if (i == argc-1 || argv[i+1][0] == '-') {
          printerror();
          return 0;
        } else {
          outfile = fopen(argv[i+1], "w");
          i++;
        }
      } else if (argv[i][0] != '-' && yyin == NULL) {
        yyin = fopen(argv[i], "r");
        if (!yyin) {
          fprintf(stderr, "Input File <%s> Does Exist.\n", argv[i]);
          return 0;
        }
      } else {
        printerror();
        return 0;
      }
    }
  }
  // Final argument check
  if (yyin == NULL) {
    fprintf(stderr, "Input file is needed.\n");
    return 0;
  }
  if (outfile == NULL) {
    outfile = fopen("out.dot", "w");
    printf("Output will be stored in out.dot file.\n");
  }
  // Graph begin
  fprintf(outfile, "digraph G {\n");
  fprintf(outfile, "\tordering=out;\n");
  // Inside
  yyparse();
  // Graph end
  fprintf(outfile, "}\n");
  fclose(outfile);
  return 0;
}

void printhelp() {
  printf("Usage: parser [OPTIONS] [FILE 1] ...\n");
  printf("Generates analysed output to specified file or out.dot if -o option is not provided.\n\n");
  printf("Options:\n");
  printf("  -h           Print this help message\n");
  printf("  -v           Print version and about the program\n");
  printf("  -o <file>    Print output to <file>\n");
  printf("\nExamples:\n");
  printf("  $ parser test1.c -o output.dot\n");
}

void printabout() {
  printf("parser 1.0.0\n");
}

void printerror() {
  fprintf(stderr, "Wrong arguments, please check help with -h.\n");
}


node *nonTerminal(char *str,char *op, node *l, node *r) {
  // printf("001 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name = strdup(str);
  n->id = ++id_count;
  int op_id = ++id_count;
  char *op_str = op;
  if(op){
    fprintf(outfile, "\t%d [label=\"%s\"];\n", op_id, op_str);
  }
  fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  if(l) fprintf(outfile, "\t%d -> %d;\n", n->id, l->id);
  if(op) fprintf(outfile, "\t%d -> %d;\n", n->id, op_id);
  if(r)fprintf(outfile, "\t%d -> %d;\n", n->id, r->id);
  // printf("001 - end\n");
  return n;
}
node *nonTerminal1(char *str,char *op1, node *l,char *op2) {
  // printf("002 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name = strdup(str);
  n->id = ++id_count;
  int op1_id = ++id_count;
  char *op1_str = op1;
  int op2_id = ++id_count;
  char *op2_str = op2;
  if(op1){
    fprintf(outfile, "\t%d [label=\"%s\"];\n", op1_id, op1_str);
  }
  if(op2){
    
    fprintf(outfile, "\t%d [label=\"%s\"];\n", op2_id, op2_str);
  }
  fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  if(op1) fprintf(outfile, "\t%d -> %d;\n", n->id, op1_id);
  if(l)fprintf(outfile, "\t%d -> %d;\n", n->id, l->id);
  if(op2) fprintf(outfile, "\t%d -> %d;\n", n->id, op2_id);
  // printf("002 - end\n");
  return n;
}
node *nonTerminal3(char *str,char *op1,char *op3, node *l,char *op2) {
  // printf("003 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name = strdup(str);
  n->id = ++id_count;
  int op1_id = ++id_count;
  char *op1_str = op1;
  int op3_id = ++id_count;
  char *op3_str = op3;
  int op2_id = ++id_count;
  char *op2_str = op2;
  if(op1){
    fprintf(outfile, "\t%d [label=\"%s\"];\n", op1_id, op1_str);
  }
  if(op3){
    fprintf(outfile, "\t%d [label=\"%s\"];\n", op3_id, op3_str);
  }
  if(op2){
    fprintf(outfile, "\t%d [label=\"%s\"];\n", op2_id, op2_str);
  }
  fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  if(op1) fprintf(outfile, "\t%d -> %d;\n", n->id, op1_id);
  if(op3) fprintf(outfile, "\t%d -> %d;\n", n->id, op3_id);
  if(l)fprintf(outfile, "\t%d -> %d;\n", n->id, l->id);
  if(op2) fprintf(outfile, "\t%d -> %d;\n", n->id, op2_id);
  // printf("003 - end\n");
  return n;
}
node *nonTerminal2(char *str,node *l,node *m, node *r) {
  // printf("004 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name = strdup(str);
  n->id = ++id_count;
  fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  if(l) fprintf(outfile, "\t%d -> %d;\n", n->id, l->id);
  if(m) fprintf(outfile, "\t%d -> %d;\n", n->id, m->id);
  if(r)fprintf(outfile, "\t%d -> %d;\n", n->id, r->id);
  // printf("004 - end\n");
  return n;
}

node *nonTerminalFourChild(char *str,node *a1,node *a2, node *a3, node*a4, char* op) {
  // printf("005 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name = strdup(str);
  n->id = ++id_count;
  int op_id = ++id_count;
  char *op_str = op;
  if(op){
    fprintf(outfile,"\t%d [label=\"%s\"];\n",op_id,op_str);
  }
  fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  if(a1) fprintf(outfile, "\t%d -> %d;\n", n->id, a1->id);
  if(a2) fprintf(outfile, "\t%d -> %d;\n", n->id, a2->id);
  if(a3)fprintf(outfile, "\t%d -> %d;\n", n->id, a3->id);
  if(a4) fprintf(outfile,"\t%d -> %d;\n",n->id,a4->id);
  if(op) fprintf(outfile,"\t%d -> %d;\n",n->id,op_id);
  // printf("005 - end\n");
  return n;
}

node *nonTerminalFiveChild(char *str,node *a1,node *a2, node *a3, node*a4, node* a5) {
  // printf("006 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name = strdup(str);
  n->id = ++id_count;
  fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  if(a1) fprintf(outfile, "\t%d -> %d;\n", n->id, a1->id);
  if(a2) fprintf(outfile, "\t%d -> %d;\n", n->id, a2->id);
  if(a3)fprintf(outfile, "\t%d -> %d;\n", n->id, a3->id);
  if(a4) fprintf(outfile,"\t%d -> %d;\n",n->id,a4->id);
  if(a5) fprintf(outfile,"\t%d -> %d;\n",n->id,a5->id);
  // printf("006 - end\n");
  return n;
}

node *terminal(char *str) {
  // printf("007 - start\n");
  node *n = (node*) malloc(sizeof(node));
  // printf("T57 %s\n", str);
  // printf("%s\n", str);
  int len = strlen(str);
  // printf("T69\n");
  n->id = ++id_count;

  char s[len+10];
  int ptr=0;
  int i=0; 
  if (str[0] == '"') {
    i++;
  }
  for (int i=0; i < len; i++) {
    if (str[i] == '\\') {
      s[ptr++] = '\\';
    }
    s[ptr++] = str[i];
  }
  if (str[0] == '"') {
    s[ptr-1] = '\0';
  }
  s[ptr] = '\0';

  n->name = strdup(s);
  // printf("T34\n");
  if (str[0] == '"') {
    fprintf(outfile, "\t%d [label=\"\\%s\\\"\"];\n", n->id, n->name);
  } else {
    fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  }
  // printf("007 - end\n");
  return n;
}

node *nonTerminalRoundB(char *str, node *a) {
  // printf("008 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name=strdup(str);
  n->id = ++id_count;
  // fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id,n->name);
  if (n->name[0] == '"') {
    fprintf(outfile, "\t%d [label=\"\\%s\\\"\"];\n", n->id, n->name);
  } else {
    fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  }
  int newBracketId = ++id_count;
  fprintf(outfile, "\t%d [label=\"( )\"];\n", newBracketId);
  if(a) fprintf(outfile, "\t%d -> %d;\n", n->id, a->id);
  fprintf(outfile, "\t%d -> %d;\n", n->id, newBracketId);
  // printf("008 - end\n");
  return n;
}
node *nonTerminalSquareB(char *str, node *a) {
  // printf("009 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name=strdup(str);
  n->id = ++id_count;
  // fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id,n->name);
  if (n->name[0] == '"') {
    fprintf(outfile, "\t%d [label=\"\\%s\\\"\"];\n", n->id, n->name);
  } else {
    fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  }
  int newBracketId = ++id_count;
  fprintf(outfile, "\t%d [label=\"[ ]\"];\n", newBracketId);
  if(a) fprintf(outfile, "\t%d -> %d;\n", n->id, a->id);
  fprintf(outfile, "\t%d -> %d;\n", n->id, newBracketId);
  // printf("009 - end\n");
  return n;
}

node *nonTerminalCurlyB(char *str, node *a) {
  // printf("010 - start\n");
  node *n = (node*) malloc(sizeof(node));
  n->name=strdup(str);
  n->id = ++id_count;
  // fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id,n->name);
  if (n->name[0] == '"') {
    fprintf(outfile, "\t%d [label=\"\\%s\\\"\"];\n", n->id, n->name);
  } else {
    fprintf(outfile, "\t%d [label=\"%s\"];\n", n->id, n->name);
  }
  int newBracketId = ++id_count;
  fprintf(outfile, "\t%d [label=\"{ }\"];\n", newBracketId);
  if(a) fprintf(outfile, "\t%d -> %d;\n", n->id, a->id);
  fprintf(outfile, "\t%d -> %d;\n", n->id, newBracketId);
  // printf("010 - end\n");
  return n;
}
