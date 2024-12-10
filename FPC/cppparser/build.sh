bison -d cppparser.y

flex cppparser.l

gcc -o cpp cppparser.tab.c lex.yy.c -ll

echo "Compilation finished."