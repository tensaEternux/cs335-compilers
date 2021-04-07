typedef struct Node {
  int id;
  char *name;
} node;

void printhelp();
void printabout();
void printerror();

node *nonTerminal(char *str,char *op, node *l, node *r);
node *nonTerminal1(char *str,char *op1, node *l,char *op2);
node *nonTerminal3(char *str,char *op1,char *op3, node *l,char *op2);
node *terminal(char *str);
node *nonTerminal2(char *str,node *l,node *m, node *r);
node *nonTerminalFourChild(char *str,node *a1,node *a2, node *a3, node*a4,char* op);
node *nonTerminalFiveChild(char *str,node *a1,node *a2, node *a3, node*a4,node *a5);
node *nonTerminalRoundB(char *str, node *a);
node *nonTerminalSquareB(char *str, node *a);
node *nonTerminalCurlyB(char *str, node *a);