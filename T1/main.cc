#include <stdio.h>
#include <string>
#include <map>

using namespace std;

enum TOKEN { _ID = 256, _FOR, _IF, _INT, _FLOAT, _MAIG, _MEIG, _IG, _DIF, _STRING, _COMENTARIO };

extern "C" int yylex();  
extern "C" FILE *yyin;

void yyerror(const char* s);  

#include "lex.yy.c"

auto p = &yyunput; // Para evitar uma warning de 'unused variable'

map<int, string> tokens_map = { {256, "_ID"}, {257, "_FOR"}, {258, "_IF"}, {259, "_INT"}, {260, "_FLOAT"}, {261, "_MAIG"}, {262, "_MEIG"}, {263, "_IG"}, {264, "_DIF"}, {265, "_STRING"}, {266, "_COMENTARIO"} };

int main() {
  int token = 0;
  while( (token = yylex()) != 0 )  
    printf( "%d %s %s\n", token, tokens_map[token].c_str(), yytext );
  
  return 0;
}