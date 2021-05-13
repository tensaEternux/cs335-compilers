CS335 - Compiler Design

Compiler Design for the course CS335 at IIT Kanpur.

    Implementation Language (I): C++
    Target Language (T): MIPS
    Source Language (S): C

Build and Run

cd .
make
./bin/compiler -i ./test/test1.c -o test.gv
make clean

Note: Lex and Yacc required to build the binary.

To generate postscript graph of the c code, execute the following command after executing parser: dot -Tps out.dot -o graph.ps

Note: graphviz required to generate postscript graph.
Usage
bin/compiler -i test/test1.c -o output.gv

Group Members

    Udit Kumar Jareda (180830)
    Vishwas Choudhary (180876)
    Vivek Kumar Gupta (180880)
    Yashwant Tailor (180894)
