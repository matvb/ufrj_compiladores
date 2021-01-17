all: a.out entrada.txt lex.yy.c main.cc 
	lex scan.lex
	g++ -Wall -std=c++17 main.cc -lfl
	./a.out < entrada.txt

test: a.out entrada.txt
	./a.out < entrada.txt

lex.yy.c: scan.lex
	lex scan.lex

saida: lex.yy.c main.cc 
	g++ -Wall -std=c++17 main.cc -lfl
	
clean:
	rm saida lex.yy.c

only: saida
	lex scan.l
	g++ -o saida lex.yy.c -lfl
	./saida < entrada.txt