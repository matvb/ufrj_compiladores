/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "mini_js.y" /* yacc.c:339  */

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

int yylex();
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




#line 213 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tk_num = 258,
    tk_string = 259,
    tk_id = 260,
    tk_let = 261,
    tk_if = 262,
    tk_else = 263,
    tk_for = 264,
    tk_while = 265,
    tk_condicao = 266,
    tk_novo_array = 267,
    tk_novo_objeto = 268
  };
#endif
/* Tokens.  */
#define tk_num 258
#define tk_string 259
#define tk_id 260
#define tk_let 261
#define tk_if 262
#define tk_else 263
#define tk_for 264
#define tk_while 265
#define tk_condicao 266
#define tk_novo_array 267
#define tk_novo_objeto 268

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 287 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   268

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      19,    20,    16,    14,    23,    15,    25,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    21,     2,    22,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   165,   165,   167,   168,   171,   172,   173,   174,   178,
     182,   188,   189,   192,   193,   196,   204,   210,   211,   214,
     217,   218,   221,   222,   225,   226,   229,   230,   231,   232,
     235,   236,   237,   238,   239,   242,   243,   244,   245,   246,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     261,   264,   265,   267
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tk_num", "tk_string", "tk_id", "tk_let",
  "tk_if", "tk_else", "tk_for", "tk_while", "tk_condicao", "tk_novo_array",
  "tk_novo_objeto", "'+'", "'-'", "'*'", "'/'", "';'", "'('", "')'", "'{'",
  "'}'", "','", "'='", "'.'", "'['", "']'", "$accept", "START", "P", "I",
  "CMD_IF", "IF_CLOSURE", "CMD_ELSE", "CMD_FOR", "CMD_WHILE",
  "WHILE_CLOSURE", "CONDITION", "CMD", "ARGS", "ATRIB_VALUE", "ATRIB",
  "OBJECT", "E", "F", "FUNCTION", "PARAMS", "PARAM", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,    43,    45,    42,    47,    59,    40,
      41,   123,   125,    44,    61,    46,    91,    93
};
# endif

#define YYPACT_NINF -21

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-21)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     137,   128,    -1,     2,    12,    18,    23,   -21,   137,   -21,
     -21,   -21,     8,   -21,    29,     3,    61,     3,    48,   -21,
      47,    52,    34,    52,   -21,   -21,   -21,     3,   -21,   -21,
      10,   -21,   -21,    90,    52,   -21,   134,   -21,    75,    72,
      69,    46,    52,    -1,    50,    79,   124,    82,    91,   -21,
     134,   105,     3,   -21,   114,    52,    52,    52,    52,    52,
      52,   -21,    87,   134,   -21,   109,    52,    27,    52,    52,
      53,    -7,    70,   -21,    62,    62,   -21,   -21,   134,     7,
     -21,    74,    52,   -21,    88,   137,   108,    99,   134,   100,
     137,   -21,   118,   119,   -21,    52,   -21,    92,   129,   135,
       4,   -21,   -21,    34,   136,   -21,    52,   133,   -21,    52,
     -21,   -21,   -21,   112,   -21,   106,   110,   138,   139,   -21,
     137,   140,   -21
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     2,     3,     6,
       7,     8,     0,    21,     0,     0,     0,     0,    24,    20,
      23,     0,     0,     0,     1,     4,     5,     0,    42,    43,
      40,    48,    49,     0,     0,    26,    27,    39,     0,    30,
       0,     0,     0,     0,    40,     0,     0,     0,     0,    29,
      28,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,    33,    32,    25,    22,     0,     0,     0,     0,     0,
       0,    44,     0,    46,    35,    36,    37,    38,    53,     0,
      52,     0,     0,    44,     0,     0,    10,     0,    19,     0,
       0,    16,     0,    32,    47,     0,    31,     0,     0,     0,
       0,     9,    12,     0,     0,    18,     0,    51,    34,     0,
      11,    14,    13,     0,    17,     0,     0,     0,    45,    45,
       0,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,    -8,   -21,    60,    64,   -21,   -21,   -21,   -21,
     -18,   -20,   122,   -21,    -3,   -21,   -14,   -21,   -21,    66,
     -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    86,   101,    10,    11,    91,
      45,    12,    19,    20,    13,    14,    46,    37,    38,    79,
      80
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,    36,    47,    41,    18,    48,    28,    29,    30,     1,
       2,     3,    35,    50,    40,    31,    32,   -30,    33,    60,
      54,    21,    34,    24,    49,    85,    26,    94,    63,   -50,
      95,    22,     1,     2,    15,    51,    52,    23,    72,     1,
       2,    74,    75,    76,    77,    78,    81,    87,    85,    40,
      92,    89,    84,    27,    88,    28,    29,    44,     1,     2,
      55,    56,    57,    58,    31,    32,    39,    33,    97,   -50,
      43,    34,    42,    62,    90,    65,    66,    99,    57,    58,
      87,    78,   104,   113,    55,    56,    57,    58,    55,    56,
      57,    58,   115,    53,    59,   116,    61,    93,    60,    67,
      69,    96,    55,    56,    57,    58,    55,    56,    57,    58,
      71,    70,   121,    82,    83,    98,   100,   102,   103,   108,
      55,    56,    57,    58,    55,    56,    57,    58,    55,    56,
      57,    58,   117,   118,    73,    68,   105,   119,    55,    56,
      57,    58,     1,     2,     3,   106,     4,     5,    55,    56,
      57,    58,    15,    16,    17,   109,    95,   110,   114,   120,
     111,   107,   122,   -34,   112,    64
};

static const yytype_uint8 yycheck[] =
{
       8,    15,    22,    17,     5,    23,     3,     4,     5,     5,
       6,     7,    15,    27,    17,    12,    13,    24,    15,    26,
      34,    19,    19,     0,    27,    21,    18,    20,    42,    19,
      23,    19,     5,     6,    24,    25,    26,    19,    52,     5,
       6,    55,    56,    57,    58,    59,    60,    67,    21,    52,
      70,    69,    66,    24,    68,     3,     4,     5,     5,     6,
      14,    15,    16,    17,    12,    13,     5,    15,    82,    19,
      23,    19,    24,    27,    21,    25,    26,    85,    16,    17,
     100,    95,    90,   103,    14,    15,    16,    17,    14,    15,
      16,    17,   106,     3,    19,   109,    27,    27,    26,    20,
      18,    27,    14,    15,    16,    17,    14,    15,    16,    17,
       5,    20,   120,    26,     5,    27,     8,    18,    18,    27,
      14,    15,    16,    17,    14,    15,    16,    17,    14,    15,
      16,    17,    20,    27,    20,    11,    18,    27,    14,    15,
      16,    17,     5,     6,     7,    26,     9,    10,    14,    15,
      16,    17,    24,    25,    26,    26,    23,    22,    22,    21,
     100,    95,    22,    24,   100,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,     9,    10,    29,    30,    31,    32,
      35,    36,    39,    42,    43,    24,    25,    26,     5,    40,
      41,    19,    19,    19,     0,    30,    18,    24,     3,     4,
       5,    12,    13,    15,    19,    42,    44,    45,    46,     5,
      42,    44,    24,    23,     5,    38,    44,    39,    38,    42,
      44,    25,    26,     3,    44,    14,    15,    16,    17,    19,
      26,    27,    27,    44,    40,    25,    26,    20,    11,    18,
      20,     5,    44,    20,    44,    44,    44,    44,    44,    47,
      48,    44,    26,     5,    44,    21,    33,    39,    44,    38,
      21,    37,    39,    27,    20,    23,    27,    44,    27,    30,
       8,    34,    18,    18,    30,    18,    26,    47,    27,    26,
      22,    32,    33,    39,    22,    44,    44,    20,    27,    27,
      21,    30,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    31,    31,    31,    32,
      32,    33,    33,    34,    34,    35,    36,    37,    37,    38,
      39,    39,    40,    40,    41,    41,    42,    42,    42,    42,
      43,    43,    43,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      46,    47,    47,    48
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     1,     1,     6,
       5,     3,     2,     2,     2,    11,     5,     3,     2,     3,
       2,     1,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     6,     4,     4,     7,     3,     3,     3,     3,     1,
       1,     2,     1,     1,     3,     7,     3,     4,     1,     1,
       1,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 165 "mini_js.y" /* yacc.c:1646  */
    { Print(solveAddresses((yyvsp[0]).v)); Print(HALT); }
#line 1447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 167 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; }
#line 1453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-1]).v + (yyvsp[0]).v; }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 172 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 173 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 174 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 178 "mini_js.y" /* yacc.c:1646  */
    { 
            CREATE_IF_LABELS();
            (yyval).v = (yyvsp[-3]).v + INI_IF + JUMP_TRUE + END_IF + GO_TO + (":" + INI_IF) + (yyvsp[-1]).v + END_ELSE + GO_TO + (":" + END_IF) + (yyvsp[0]).v + END_ELSE;
        }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 182 "mini_js.y" /* yacc.c:1646  */
    { 
            CREATE_IF_LABELS();
            (yyval).v = (yyvsp[-2]).v + INI_IF + JUMP_TRUE + END_IF + GO_TO + (":" + INI_IF) + (yyvsp[0]).v + (":" + END_IF); 
        }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 188 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-1]).v; }
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 189 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-1]).v; }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v + ":"; }
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 193 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v + ":"; }
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 196 "mini_js.y" /* yacc.c:1646  */
    {
            string condition_for = createLabels("condition_for"), _condition_for = ':' + condition_for;
            string begin_for_closure = createLabels("begin_for_closure"), _begin_for_closure = ':' + begin_for_closure;
            string end_for = createLabels("end_for"), _end_for = ':' + end_for;
            (yyval).v = (yyvsp[-8]).v + _condition_for + (yyvsp[-6]).v + begin_for_closure + JUMP_TRUE + end_for + GO_TO + _begin_for_closure + (yyvsp[-1]).v + (yyvsp[-4]).v + condition_for + GO_TO + _end_for;
        }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 204 "mini_js.y" /* yacc.c:1646  */
    {
            CREATE_WHILE_LABELS();
            (yyval).v = (":" + INI_WHILE) + (yyvsp[-2]).v + INI_WHILE_CLOSURE + JUMP_TRUE + END_WHILE + GO_TO + (":" + INI_WHILE_CLOSURE) + (yyvsp[0]).v + INI_WHILE + GO_TO + (":" + END_WHILE);
          }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 210 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-1]).v; }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 211 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-1]).v; }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 214 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + (yyvsp[-1]).v; }
#line 1557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 217 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 218 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v + POP; }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 221 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v; }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 222 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; }
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 225 "mini_js.y" /* yacc.c:1646  */
    { duplicateVariable((yyvsp[0]).v[0]); (yyval).v = (yyvsp[0]).v + _LET ; }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 226 "mini_js.y" /* yacc.c:1646  */
    { duplicateVariable((yyvsp[-2]).v[0]); (yyval).v = (yyvsp[-2]).v + _LET + (yyvsp[-2]).v + (yyvsp[0]).v + SET + POP; }
#line 1593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 229 "mini_js.y" /* yacc.c:1646  */
    { nonVariable((yyvsp[-2]).v[0]); (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + SET; }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 230 "mini_js.y" /* yacc.c:1646  */
    { nonVariable((yyvsp[-2]).v[0]); (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + SET; }
#line 1605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 231 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + SET_PROP; }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 232 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + SET_PROP; }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 235 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + GET + (yyvsp[0]).v; }
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 236 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-5]).v + GET + (yyvsp[-3]).v + GET_PROP + (yyvsp[-1]).v; }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 237 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-3]).v + GET + (yyvsp[-1]).v; }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 238 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-3]).v + GET + (yyvsp[-1]).v; }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 239 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-6]).v + GET + (yyvsp[-4]).v + GET_PROP + (yyvsp[-1]).v; }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 242 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + "+"; }
#line 1653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 243 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + "-"; }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 244 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + "*"; }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 245 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + (yyvsp[0]).v + "/"; }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 249 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v +  GET; }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 250 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = "0" + (yyvsp[0]).v + "-"; }
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 251 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 252 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[0]).v; }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 253 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-2]).v + GET + (yyvsp[0]).v + GET_PROP; }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 254 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-6]).v + GET + (yyvsp[-4]).v + GET_PROP + (yyvsp[-1]).v + GET_PROP; }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 255 "mini_js.y" /* yacc.c:1646  */
    { (yyval).v = (yyvsp[-1]).v; }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 256 "mini_js.y" /* yacc.c:1646  */
    { Print( (yyvsp[-3]).v + GO_TO ); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1723 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 270 "mini_js.y" /* yacc.c:1906  */


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
