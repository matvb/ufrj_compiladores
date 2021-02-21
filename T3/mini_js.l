/*  
    Código feito por:
    Mateus Villas Boas 
    DRE: 115054675  
*/

DIGITO  [0-9]
LETRA   [A-Za-z_]

NUM	{DIGITO}+("."{DIGITO}+)?
ID  {LETRA}({LETRA}|{DIGITO})*

STRING (["]([^"\\\n]|\\(.|\n))*["])|[']([^'\\\n]|\\(.|\n))*['] 

CONDICAO (==)|(===)|(!=)|(!==)|(>)|(>=)|(<)|(<=)

%%
"\t"             { coluna += 4; }
" "              { coluna++; }
"\n"	         { linha++; coluna = 1; }
"\r\n"           { linha++; coluna = 1; }

{NUM}           { return retorna( tk_num ); }
{STRING}	    { return retorna( tk_string ); } 

"let"           { return retorna( tk_let ); }
"if"            { return retorna( tk_if ); }
"else"          { return retorna( tk_else ); }
"while"         { return retorna( tk_while ); }
"for"           { return retorna( tk_for ); }

{ID}            { return retorna( tk_id ); }
{CONDICAO}      { return retorna( tk_condicao ); }

"{}"            { return retorna( tk_novo_array ); }
"[]"            { return retorna( tk_novo_objeto ); }

.               { return retorna( *yytext ); }
%%