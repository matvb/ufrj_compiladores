%{
#include <iostream>
#include <map>
  
using namespace std;  

extern "C" int yylex();  
  
int token;
int linha = 1, coluna_atual = 1, coluna_anterior = 0;

void VS();
void P();
void A();
void R();
void L();
void V();
void T();
void casa( int );

enum { tk_int = 256, tk_char, tk_double, tk_id, 
       tk_cte_int };

map<int,string> nome_tokens = {
  { tk_int, "int" },
  { tk_char, "char" },
  { tk_double, "double" },
  { tk_id, "nome de identificador" },
  { tk_cte_int, "constante inteira" }
};

int tk( int token );

%}

DIGITO	[0-9]
LETRA	[A-Za-z_]

NUM	{DIGITO}+
ID	{LETRA}({LETRA}|{DIGITO})*

%%

" "  		{ coluna_anterior = coluna_atual++; }
"\t"		{ coluna_anterior = coluna_atual; 
                  coluna_atual += 2; }
"\n"            { linha++; 
                  coluna_anterior = coluna_atual;
                  coluna_atual = 1; }
{NUM} 		{ return tk( tk_cte_int ); }
"char"		{ return tk( tk_char ); }
"int"		{ return tk( tk_int ); }
"double"	{ return tk( tk_double ); }

{ID}		{ return tk( tk_id ); }

.		{ return tk( yytext[0] ); }

%%

int tk( int token ) {
  coluna_anterior = coluna_atual;
  coluna_atual += strlen( yytext ); 
  return token;
}

int next_token() {
  return yylex();
}

void erro( string msg ) {
  cout << "*** Erro: ***" << endl
       << "Linha: " << linha << ", coluna: " << coluna_anterior << endl
       << msg << endl;
  exit( 1 );
}

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;
    r = (char) token;
    
    return "'" + r + "'";
  }
}

void P() {
  if( token == '*' ) {
    casa( '*' );
    P();
  }
}

void A() {
  if( token == '[' ) {
    casa( '[' );
    casa( tk_cte_int );
    casa( ']' );
    A();
  }
}

void R() {
  if( token == ',' ) {
    casa( ',' );
    P();
    casa( tk_id );
    A();
    R();
  }
}

void L() {
  P();
  casa( tk_id );
  A();
  R();
}

void T() {
  switch( token ) {
    case tk_int : casa( tk_int ); break;
    case tk_char : casa( tk_char ); break;
    case tk_double : casa( tk_double ); break;
    
    default:
      erro( "Tipo esperado (int, char ou double)"  
	    ", encontrado: " + nome_token( token ) );
  }
}

void V() {
  T();  
  L(); 
  casa( ';' );
}

void casa( int esperado ) {
  if( token == esperado )
    token = next_token();
  else 
    erro( "Esperado " + nome_token( esperado ) +
	  ", encontrado: " + nome_token( token ) );
}

void VS() {
  if( token == tk_int || token == tk_char ||
      token == tk_double ) {
    V();
    VS();
  }
}

auto f = &yyunput;

int main() {
  token = next_token();
  VS();
  
  if( token == 0 )
    cout << "Sintaxe ok!" << endl;
  else
    erro( "Caracteres encontrados após o final do programa" );
  
  return 0;
}