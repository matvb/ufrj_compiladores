%{
#include <string>
#include <iostream>
#include <map>

using namespace std;

//extern "C" int yylex();

struct Atributos {
  string v;
};

#define YYSTYPE Atributos

void Print( string st );
void Print( vector<string> st );


int yylex();
void yyerror( const char* );
int retorna( int tk );

%}

%token tk_num tk_string tk_id
%token tk_let tk_if tk_else tk_for tk_while
%token tk_condicao tk_novo_array tk_novo_objeto

%right '='
%left '.'
%left  '+' '-'
%left  '*' '/'
%left '%'

%start P

%%

P : CMD ';' P       { $$.v = $1.v + $3.v; }
  | CMD ';'
  | CMD_IF          { $$.v = $1.v; }
  | CMD_IF P        { $$.v = $1.v + $2.v; }
  | CMD_FOR         { $$.v = $1.v; }
  | CMD_FOR P       { $$.v = $1.v + $2.v; }
  | CMD_WHILE       { $$.v = $1.v; }
  | CMD_WHILE P     { $$.v = $1.v + $2.v; }
  ;

CMD_IF  : tk_if CONDITION IF_CLOSURE CMD_ELSE { 
            CREATE_IF_LABELS();
            $$.v = $2.v + INI_IF + JUMP_TRUE + END_IF + GO_TO + (":" + INI_IF) + $3.v + (":" + END_IF) + $4.v; 
        }
        ;

IF_CLOSURE : '{' P '}' { $$.v = $2.v + END_ELSE + GO_TO; }
           | CMD ';'   { $$.v = $1.v + END_ELSE + GO_TO; }
           ;

CMD_ELSE : tk_else CLOSURE   { $$.v = $2.v + (":" + END_ELSE); }
         | tk_else CMD ';'   { $$.v = $2.v + (":" + END_ELSE); }
         | tk_else CMD_IF    { $$.v = $2.v + (":" + END_ELSE); }
         ;

CMD_FOR : tk_for '(' CMD ';' CONDITION_EXPRESSION ';' CMD ')' CLOSURE {
            string condition_for = createLabels("condition_for"), _condition_for = ':' + condition_for;
            string begin_for_closure = createLabels("begin_for_closure"), _begin_for_closure = ':' + begin_for_closure;
            string end_for = createLabels("end_for"), _end_for = ':' + end_for;
            $$.v = $3.v + _condition_for + $5.v + begin_for_closure + JUMP_TRUE + end_for + GO_TO + _begin_for_closure + $9.v + $7.v + condition_for + GO_TO + _end_for;
        }
        ;

CMD_WHILE : tk_while CONDITION WHILE_CLOSURE {
            CREATE_WHILE_LABELS();
            $$.v = (":" + INI_WHILE) + $2.v + INI_WHILE_CLOSURE + JUMP_TRUE + END_WHILE + GO_TO + (":" + INI_WHILE_CLOSURE) + $3.v + INI_WHILE + GO_TO + (":" + END_WHILE);
          }
          ;

WHILE_CLOSURE : '{' P '}' { $$.v = $2.v; }
              | CMD ';'   { $$.v = $1.v; }
              ;

CONDITION : '(' CONDITION_EXPRESSION ')' { $$.v = $2.v;  }
          ;

//EDIT ideia, juntar todos os tks em um só tk_condition_exp ou algo assim
CONDITION_EXPRESSION : E tk_condicao E   { $$.v = $1.v + $3.v + $2.v; }
                     ;

CLOSURE : '{' P '}' { $$.v = $2.v; }
        ;

CMD : tk_let ARGS { $$.v = $2.v; }
    | ATRIB   { $$.v = $1.v + POP; }
    ;

ARGS : ATRIB_VALUE ',' ARGS { $$.v = $1.v + $3.v; }
     | ATRIB_VALUE          { $$.v = $1.v; }
     ;

ATRIB_VALUE : tk_id       { duplicateVariable($1.v[0]); $$.v = $1.v + _LET ; }
            | tk_id '=' E { duplicateVariable($1.v[0]); $$.v = $1.v + _LET + $1.v + $3.v + SET + POP; }
            ;

ATRIB : tk_id '=' ATRIB     { nonVariable($1.v[0]); $$.v = $1.v + $3.v + SET; }
      | tk_id '=' E         { nonVariable($1.v[0]); $$.v = $1.v + $3.v + SET; }
      | OBJECT '=' E        { $$.v = $1.v + $3.v + SET_PROP; }
      | OBJECT '=' ATRIB    { $$.v = $1.v + $3.v + SET_PROP; }
      ;

OBJECT : tk_id '.' tk_id                { $$.v = $1.v + GET + $3.v; }
       | tk_id '.' tk_id '[' E ']'      { $$.v = $1.v + GET + $3.v + GET_PROP + $5.v; }
       | tk_id '[' E ']'                { $$.v = $1.v + GET + $3.v; }
       | tk_id '[' ATRIB ']'            { $$.v = $1.v + GET + $3.v; }
       | tk_id '[' E ']' '[' E ']'      { $$.v = $1.v + GET + $3.v + GET_PROP + $6.v; }
       ;

E : E '+' E            { $$.v = $1.v + $3.v + "+"; }
  | E '-' E            { $$.v = $1.v + $3.v + "-"; }
  | E '*' E            { $$.v = $1.v + $3.v + "*"; }
  | E '/' E            { $$.v = $1.v + $3.v + "/"; }
  | F
  ;
  
F : tk_id                       { $$.v = $1.v +  GET; }
  | '-' tk_num                  { $$.v = "0" + $2.v + "-"; }
  | tk_num                      { $$.v = $1.v; }
  | tk_string                   { $$.v = $1.v; }
  | tk_id '.' tk_id             { $$.v = $1.v + GET + $3.v + GET_PROP; }
  | tk_id '[' E ']' '[' E ']'   { $$.v = $1.v + GET + $3.v + GET_PROP + $6.v + GET_PROP; }
  | '(' E ')'                   { $$.v = $2.v; }
  | FUNCTION '(' PARAMS ')'     { Print( $1.v + GO_TO ); }
  | tk_novo_array
  | tk_novo_objeto
  ;

FUNCTION : tk_id
         ;

PARAMS : PARAMS ',' PARAMS
       | PARAM

PARAM : E
      ;

%%

#include "lex.yy.c"

map<int,string> nome_tokens = {
  { tk_id, "Nome de Identificador" },
  { tk_num, "Número" },
  { tk_string, "String" },
  { tk_let, "LET" },
  { tk_if, "IF" },
  { tk_else, "ELSE" },
  { tk_for, "FOR" },
  { tk_while, "WHILE" },
  { tk_condicao, "CONDIÇÃO DO IF" },
  { tk_novo_array, "Simbolo de novo array" },
  { tk_novo_objeto, "Simbolo de novo objeto" },
};

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;
    
    r = token;
    return r;
  }
}

void yyerror( const char* msg ) {
    cout << endl << "Erro: " << msg << endl
        << "Perto de: '" << yylval.v.back() << endl;
    exit( 1 );
}

void Print(string x) {
    cout << x << " ";
}

void Print( vector<string> x ) {
    for(int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
}

int main() {
    yyparse();
    cout <<  endl ;

    return 0;
}