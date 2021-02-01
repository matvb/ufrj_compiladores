/*  
    Código feito por:
    Mateus Villas Boas 
    DRE: 115054675  
*/


/* EDIT: posso usar WS ao invés de contabilizar as linhas e colunas par diferenciar mais os trabalhos */
WS	[ \n\t\r]

DIGITO  [0-9]
LETRA   [A-Za-z_]

NUM	{DIGITO}+("."{DIGITO}+)?
ID  {LETRA}({LETRA}|{DIGITO})*

STRING (["]([^"\\\n]|\\(.|\n))*["])|[']([^'\\\n]|\\(.|\n))*['] 

COMENT_UMA_LINHA    [/][/][^\n]*
COMMENT_MULT_LINHAS [/][*]([^*]|"*"[^/])*[*][/]
COMENTARIO          {COMENT_UMA_LINHA}|{COMMENT_MULT_LINHAS}

CONDICAO (==)|(===)|(!=)|(!==)|(>)|(>=)|(<)|(<=)

NEW_ARRAY \[\]
NEW_OBJECT   \{\}

%%
{WS}            { }
"\r\n"          { }

{NUM}           {   yylval.v = yytext;
                    return tk_num;
                }
{STRING}	    { 
                    yylval.v = yytext;
                    return tk_string; 
                }

"let"           { yylval.v = yytext; return tk_let; }
"if"            { yylval.v = yytext; return tk_if; }
"else"          { yylval.v = yytext; return tk_else; }
"while"         { yylval.v = yytext; return tk_while; }
"for"           { yylval.v = yytext; return tk_for; }

{ID}            { yylval.v = yytext; return tk_id; }

{CONDICAO}      { yylval.v = yytext; return tk_condicao; }

{NEW_ARRAY}     { yylval.v = yytext; return tk_novo_array;}
{NEW_OBJECT}    { yylval.v = yytext; return tk_novo_objeto;}

.               { yylval.e = (string) "erro: " + yytext; return yytext[0]; }
%%