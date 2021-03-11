# CS335 - Compiler Design
Compiler Design for the course [CS335](https://www.cse.iitk.ac.in/pages/CS335.html) at [IIT Kanpur](https://www.iitk.ac.in/).

 - Implementation Language (I): C
 - Target Language (T): x86
 - Source Language (S): C

### Build and Run
```sh
cd .
make
./bin/lexer ./test/test1.c          //for lexer
./bin/parser ./test/test1.c         //for parser
make clean
```
Note: Lex and Yacc required to build the binary.

To generate postscript graph of the c code, execute the following command after executing parser:
`dot -Tps out.dot -o graph.ps`

Note: graphviz required to generate postscript graph.

### Usage
`./bin/lexer -h` : Prints the help message

`./bin/lexer -v` : Prints the lexer version 

`./bin/lexer ./test/test1.c` : Scans **test1.c** file and prints tokens on stdout in tabular form

`./bin/lexer ./test/test2.c -o out1.txt`: Scans **test2.c** file and writes tokens in **out1.txt** file in tabular form

`./bin/lexer ./test/test*.c -o out.txt`: Scans **test<1, 2, 3, 4, 5>.c** files and writes tokens in **out.txt** file in tabular form

`./bin/lexer ./test/test*.c`: Scans **test<1, 2, 3, 4, 5>.c** files and prints tokens on stdout in tabular form

`./bin/parser ./test/test*.c`: Executes parser on test files and generates out.dot file.
### Group Members

* Udit Kumar Jareda (180830)
* Vishwas Choudhary (180876)
* Vivek Kumar Gupta (180880)
* Yashwant Tailor (180894)
