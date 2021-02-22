/*  
    Código feito por:
    Mateus Villas Boas 
    DRE: 115054675  
*/

%{
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Atributos {
  vector<string> v;
};

#define YYSTYPE Atributos

void Print( string st );
void Print( vector<string> st );

#define GO_TO "#"
#define GET "@"
#define SET "="
#define JUMP_TRUE "?"
#define _LET "&"
#define GET_PROP "[@]"
#define SET_PROP "[=]"
#define CALL_FUNC "$"
#define POP "^"
#define HALT "."

extern "C" int yylex();
void yyerror( const char* );
int retorna( int tk );

int linha = 1;
int coluna = 1;

string INI_IF;
string END_IF;
string END_ELSE;

string INI_WHILE;
string INI_WHILE_CLOSURE;
string END_WHILE;

string FOR_CONDITION;
string INI_FOR_CLOSURE;
string END_FOR;

vector<string> Variables;
map<string, int> VariableDeclaration;


vector<string> concat(vector<string> a, vector<string> b) {
    vector<string> res;
    
    copy(a.begin(), a.end(), back_inserter(res));
    copy(b.begin(), b.end(), back_inserter(res));
    
    return res;
}

vector<string> operator +(vector<string> a, vector<string> b) {
    return concat(a, b);
}

vector<string> operator +( vector<string> a, string b) {
    return concat( a, vector<string>{b} );
}

vector<string> operator +( string a, vector<string> b) {
    return concat( vector<string>{a}, b );
}

vector<string> operator +( char a, vector<string> b) {
    return concat( vector<string>{ string(1, a) }, b );
}

vector<string> operator +( vector<string> a, char b) {
    return concat( a, vector<string>{ string(1,b) } );
}

string createLabels(string prefix) {
    static int n = 0;
    return prefix + "_" + to_string(++n) + ":";
}

vector<string> solveAddresses(vector<string> input) {
    map<string, int> label;
    vector<string> res;
    int i;

    for(i = 0; i < input.size(); i++) {
        if(input[i][0] == ':') {
            label[input[i].substr(1)] = res.size();
        } else {
            res.push_back(input[i]);
        }
    }

    for(i = 0; i < res.size(); i++) {
        if(label.count(res[i]) > 0) {
            res[i] = to_string(label[res[i]]);
        }
    }

    return res;
}

void nonVariable(string variable) {
    int nonVariable = VariableDeclaration.count(variable); 
    if(nonVariable == 0) {
        cerr << "Erro: a variável '" << variable << "' não foi declarada." << endl;
        exit(1);
    }
}

void duplicateVariable(string variable) {
    int duplicates = VariableDeclaration.count(variable);
    if(duplicates) {
        cerr << "Erro: a variável '" << variable << "' já foi declarada na linha " << VariableDeclaration[variable] << HALT << endl;
        exit(1);
    } else {
        VariableDeclaration[variable] = linha;
    }
}

void CREATE_IF_LABELS(){
    INI_IF = createLabels("ini_if"); 
    END_IF = createLabels("end_if"); 
    END_ELSE = createLabels("end_else");
}

void CREATE_WHILE_LABELS(){
    INI_WHILE = createLabels("ini_while");
    INI_WHILE_CLOSURE = createLabels("ini_while_closure");
    END_WHILE = createLabels("end_while");
}

void CREATE_FOR_LABELS(){
    FOR_CONDITION = createLabels("condition_for");
    INI_FOR_CLOSURE = createLabels("ini_for_closure");
    END_FOR = createLabels("end_for");
}



%}

%token tk_num tk_string tk_id
%token tk_let tk_if tk_else tk_for tk_while
%token tk_condicao tk_novo_array tk_novo_objeto

%left  '+' '-'
%left  '*' '/'

%start START

%%

START : P { Print(solveAddresses($1.v)); Print(HALT); }

P : I       { $$.v = $1.v; }
    | I P   { $$.v = $1.v + $2.v; }
    ;

I : CMD ';'
  | CMD_IF          { $$.v = $1.v; }
  | CMD_FOR         { $$.v = $1.v; }
  | CMD_WHILE       { $$.v = $1.v; }
  ;


CMD_IF  : tk_if '(' CONDITION ')' IF_CLOSURE CMD_ELSE { 
            CREATE_IF_LABELS();
            $$.v = $3.v + INI_IF + JUMP_TRUE + END_IF + GO_TO + (":" + INI_IF) + $5.v + END_ELSE + GO_TO + (":" + END_IF) + $6.v + END_ELSE;
        }
        | tk_if '(' CONDITION ')' IF_CLOSURE { 
            CREATE_IF_LABELS();
            $$.v = $3.v + INI_IF + JUMP_TRUE + END_IF + GO_TO + (":" + INI_IF) + $5.v + (":" + END_IF); 
        }
        ;

IF_CLOSURE : '{' P '}' { $$.v = $2.v; }
           | CMD ';'   { $$.v = $1.v; }
           ;

CMD_ELSE : tk_else IF_CLOSURE { $$.v = $2.v + ":"; }
         | tk_else CMD_IF    { $$.v = $2.v + ":"; }
         ;

CMD_FOR : tk_for '(' CMD ';' CONDITION ';' CMD ')' '{' P '}' {
            string condition_for = createLabels("condition_for"), _condition_for = ':' + condition_for;
            string begin_for_closure = createLabels("begin_for_closure"), _begin_for_closure = ':' + begin_for_closure;
            string end_for = createLabels("end_for"), _end_for = ':' + end_for;
            $$.v = $3.v + _condition_for + $5.v + begin_for_closure + JUMP_TRUE + end_for + GO_TO + _begin_for_closure + $10.v + $7.v + condition_for + GO_TO + _end_for;
        }
        ;

CMD_WHILE : tk_while '(' CONDITION ')' WHILE_CLOSURE {
            CREATE_WHILE_LABELS();
            $$.v = (":" + INI_WHILE) + $3.v + INI_WHILE_CLOSURE + JUMP_TRUE + END_WHILE + GO_TO + (":" + INI_WHILE_CLOSURE) + $5.v + INI_WHILE + GO_TO + (":" + END_WHILE);
          }
          ;

WHILE_CLOSURE : '{' P '}' { $$.v = $2.v; }
              | CMD ';'   { $$.v = $1.v; }
              ;

CONDITION   : E tk_condicao E   { $$.v = $1.v + $3.v + $2.v; }
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

int retorna( int tk ) {  
    vector<string> v{yytext};
    yylval.v = v; 
    coluna += strlen( yytext ); 

    return tk;
}

void yyerror( const char* msg ) {
    cout << endl << "Erro: " << msg << endl
        << "Perto de: '" << yylval.v.back() << "' na linha " << linha << " coluna " << coluna << endl;
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