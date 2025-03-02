#!/bin/bash

echo "Usage: ./run.sh [lex source file] [test C file] [result file path]."

lex $1

echo "Lex source file compiled successfully."

gcc lex.yy.c -o "lexer" -ll

echo "Generated C file compiled successfully."

./lexer $2 $3