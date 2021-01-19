
all: saida entrada.txt lex.yy.c
	lex scan.l
	g++ lex.yy.c -o saida -ll
	./saida < entrada.txt

test: a.out entrada.txt
	./a.out < entrada.txt
	
clean:
	rm saida lex.yy.c


