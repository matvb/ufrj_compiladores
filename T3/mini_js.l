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


NEW_ARRAY \[\]
NEW_OBJECT   \{\}

%%
"\t"            { coluna += 4; }
" "             { coluna++; }
"\n"	        { linha++; coluna = 1; }
"\r"            { linha++; coluna = 1; }
"\r\n"          { linha++; coluna = 1; }

{NUM}           {   yylval.v = yytext;
                    coluna += strlen( yytext ); 
                    return tk_num );
                }
{STRING}	    { return retorna( tk_string ); }

"print"         { return retorna( tk_print ); }
"let"           { return retorna( tk_let ); }
"if"            { return retorna( tk_if ); }
"else"          { return retorna( tk_else ); }
"while"         { return retorna( tk_while ); }
"for"           { return retorna( tk_for   ); }

{ID}            { return retorna( tk_id ); }

"=="            { return retorna( tk_igual ); }
"==="           { return retorna( tk_estrit_igual ); }
"!="            { return retorna( tk_dif ); }
"!=="           { return retorna( tk_estrit_dif ); }
">" 	        { return retorna( tk_maior ); }
">="	        { return retorna( tk_maior_igual ); }
"<"	            { return retorna( tk_menor ); }
"<="	        { return retorna( tk_menor_igual ); }

{NEW_ARRAY}     { return retorna( tk_novo_array );}
{NEW_OBJECT}    { return retorna( tk_novo_objeto );}
{COMENTARIO}    { return retorna( tk_coment ); } 

.               { return retorna( *yytext ); }
%%