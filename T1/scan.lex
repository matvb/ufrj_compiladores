/*  
    Código feito por:
    Mateus Villas Boas 
    DRE: 115054675  
*/

DIGITO	[0-9]
LETRA	[A-Za-z_$]

INT {DIGITO}+
FLOAT ({DIGITO}+("."{DIGITO}+))|({DIGITO}+("."{DIGITO}+)?(("e"|"E")("-"|"+")?{DIGITO}+)?)

ID	{LETRA}({LETRA}|{DIGITO})*

FOR [Ff][Oo][Rr]
IF [Ii][Ff]
MAIG ">="
MEIG "<="
IG "=="
DIF "!="

COMENT_UMA_LINHA [/][/][^\n]*
COMMENT_MULT_LINHAS [/][*]([^*]|"*"[^/])*[*][/]

COMENTARIO  {COMENT_UMA_LINHA}|{COMMENT_MULT_LINHAS}

STRING ["]([^\n\"]|["]["]|("\\\""))*["]


%%
{COMENTARIO}	{ return _COMENTARIO; }
{STRING}	{ return _STRING; }
    
" "	{ }
\t	{ }
\n  { }

{FOR}	{ return _FOR; }
{IF}	{ return _IF; }
{MAIG}	{ return _MAIG; }
{MEIG}	{ return _MEIG; }
{IG}	{ return _IG; }
{DIF}	{ return _DIF; }

{INT}	{ return _INT; }
{FLOAT}	{ return _FLOAT; }


{ID}	{ return _ID; }

.       { return yytext[0]; }

%%
