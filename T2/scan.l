%{
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int token;

void S();
void C();
void P();
void A();
void E();
void E_linha();
void T();
void T_linha();
void F();
void erro();
void casa( int );

enum { tk_int = 256, tk_id, tk_num, tk_print, tk_endl};

string lexema;

map<int,string> nome_tokens = {
  { tk_id, "nome de identificador" },
  { tk_num, "constante inteira" },
  { tk_print, "funcao print" },
  { tk_endl, "ponto e virgula" }
};

%}

WS	[ \n\t]
DIGITO	[0-9]
LETRA	[A-Za-z_]

NUM	{DIGITO}+("."{DIGITO}+)?
ID	{LETRA}({LETRA}|{DIGITO})*

%%

{WS}  		{ }
{NUM} 		{ return tk_num; }
"print"   { return tk_print; }
";"       { return tk_endl; }
{ID}		  { return tk_id; }

.		{ return yytext[0]; }

%%

int next_token() {
  int yylex_temp = yylex();
  lexema = yytext;
  return yylex_temp;
}

int next_token2() {
  static int look_ahead = ' ';
  
  while( look_ahead == ' ' || look_ahead == '\n' || look_ahead == '\r' || look_ahead == '\t' )
     look_ahead = getchar();
  
  if( isdigit( look_ahead ) ) {
    lexema = (char) look_ahead;
    
    look_ahead = getchar();
    return tk_num;
  }
  
  if( isalpha( look_ahead ) ) {
    lexema = (char) look_ahead;
    
    look_ahead = getchar();
    while( isalpha( look_ahead ) ) {
      lexema += (char) look_ahead;
    
      look_ahead = getchar();   
    }
      
    return tk_id;
  }
  switch( look_ahead ) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
    case '@':
    case '#':
    case ';':
      int temp = look_ahead;
      look_ahead = getchar();
      return temp;
  }
  return 000;
}

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;
    
    r = token;
    return r;
  }
}

void print(string x){
  cout << x + " ";
}

void S() {
  if (token) {
    C();
    casa( tk_endl );
    S();
  }
}

void C() {
  if ( token  != tk_print) {
    A();
  }
  else {
    P();
  }

}

void P() {
  casa( tk_print );
  E();
  print( "print #" );
}

void A() {
// Guardamos o lexema pois a função 'casa' altera o seu valor.
  string temp = lexema;
  casa( tk_id );
  print( temp );
  casa( '=' );
  E();
  print( "=" );
}

void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : casa( '+' ); T(); print( "+"); E_linha(); break;
    case '-' : casa( '-' ); T(); print( "-"); E_linha(); break;
  }
}

void T() {
  F();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : casa( '*' ); F(); print( "*"); T_linha(); break;
    case '/' : casa( '/' ); F(); print( "/"); T_linha(); break;
  }
}

void F() {
  switch( token ) {
    case tk_id : {
      string temp = lexema;
      casa( tk_id ); print( temp + " @" ); } 
      break;
    case tk_num : {
      string temp = lexema;
      casa( tk_num ); print( temp ); }
      break;
    case '(': 
      casa( '(' ); E(); casa ( ')' ); break;
    default:
      erro();
  }
}

void casa( int esperado ) {
  if( token == esperado )
    token = next_token();
  else {
      cout << "Esperado " << nome_token( esperado ) 
	   << " , encontrado: " << nome_token( token ) << endl;
    exit( 1 );
  }
}

void erro() {
  cout << "*** Erro: ***" << endl;
  exit( 1 );
}

int main() {
  token = next_token();
  //cout << "=== Código ===" << endl;
  S();
  //cout << endl;
  //cout << "=== Console ===" << endl;
  //cout << "=== Vars ===" << endl ;
  //cout << "=== Pilha ===" << endl ;

  /*
  if( token == 0 )
    cout << "Sintaxe ok!" << endl;
  else
    cout << "Caracteres encontrados após o final do programa" << endl;
  */
  return 0;
}