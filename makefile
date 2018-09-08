

#run: exe.out
#./exe.out

#gdb: exe.out
#xterm -e gdb ./exe.out

compileAll: driver.o codeGen.o inter_code.o symbol_table.o ast.o parser.o lexer.o set.o stack.o hash_table.o
		gcc -g -o compiler codeGen.o inter_code.o driver.o symbol_table.o ast.o parser.o lexer.o set.o stack.o hash_table.o

driver.o: driver.c codeGen.h inter_code.h symbol_table.h ast.h parser.h lexerDef.h stack.h set.h hash_table.h
		gcc -g -c driver.c

lexer.o: lexer.c hash_table.h lexer.h lexerDef.h
		gcc -g -c lexer.c

set.o: set.c set.h
		gcc -g -c set.c

hash_table.o: hash_table.c hash_table.h lexerDef.h lexer.h
		gcc -g -c hash_table.c

stack.o: stack.c stack.h	lexerDef.h
		gcc -g -c stack.c


parser.o: parser.c parser.h parserDef.h lexer.h
		gcc -g -c parser.c

ast.o: ast.c ast.h parserDef.h parser.h
		gcc -g -c ast.c

symbol_table.o: symbol_table.c symbol_table.h ast.h
		gcc -g -c symbol_table.c

inter_code.o: inter_code.c inter_code.h symbol_table.h
		gcc -g -c inter_code.c


codeGen.o: codeGen.c codeGen.h inter_code.h
		gcc -g -c codeGen.c

clean:
		rm *.o exe.ou
