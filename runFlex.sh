#!/bin/bash
flex parser.c && bison btree.y -d && gcc lex.yy.c btree.tab.c -ly 2>/dev/null && ./a.out
