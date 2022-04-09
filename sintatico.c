/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "sintatico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexico.c"  //Incluir o programa todo.
#include "estrut.c"  //Incluir o programa todo. /* Exemplo de Link Edit: extern char atomo[100]; */


void erro(char *);
int yyerror(char *);
int conta = 0;          /* Contar número de variaveis           */
int rotulo = 0;         /* Marcar locais dentro do código       */
char tipo;           //tipo[4]
char cat;            //MODIFIED: /* Insere uma categoria a variavel      TODO:MODIFICAR PARA VET[4] PRO TIPO PEDIDO   */
int auxIndex;

#line 87 "sintatico.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SINTATICO_H_INCLUDED
# define YY_YY_SINTATICO_H_INCLUDED
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
    T_PROGRAMA = 258,
    T_INICIO = 259,
    T_FIM = 260,
    T_IDENTIF = 261,
    T_LEIA = 262,
    T_ESCREVA = 263,
    T_ENQTO = 264,
    T_FACA = 265,
    T_FIMENQTO = 266,
    T_SE = 267,
    T_ENTAO = 268,
    T_SENAO = 269,
    T_FIMSE = 270,
    T_ATRIB = 271,
    T_VEZES = 272,
    T_DIV = 273,
    T_MAIS = 274,
    T_MENOS = 275,
    T_IGUAL = 276,
    T_MAIOR = 277,
    T_MENOR = 278,
    T_E = 279,
    T_OU = 280,
    T_V = 281,
    T_F = 282,
    T_NUMERO = 283,
    T_NAO = 284,
    T_ABRE = 285,
    T_FECHA = 286,
    T_INTEIRO = 287,
    T_LOGICO = 288,
    T_ABRE_COL = 289,
    T_FECHA_COL = 290,
    T_REPITA = 291,
    T_ATE = 292,
    T_FIMREPITA = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICO_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   147

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  107

#define YYUNDEFTOK  2
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    71,    85,    90,    91,    95,    96,   100,
     101,   105,   105,   110,   119,   118,   132,   138,   145,   155,
     154,   168,   173,   181,   182,   186,   187,   188,   189,   190,
     195,   194,   205,   215,   227,   233,   240,   232,   259,   265,
     258,   278,   287,   277,   302,   301,   321,   330,   339,   350,
     359,   368,   377,   386,   395,   404,   409,   408,   417,   422,
     427,   432,   440
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_PROGRAMA", "T_INICIO", "T_FIM",
  "T_IDENTIF", "T_LEIA", "T_ESCREVA", "T_ENQTO", "T_FACA", "T_FIMENQTO",
  "T_SE", "T_ENTAO", "T_SENAO", "T_FIMSE", "T_ATRIB", "T_VEZES", "T_DIV",
  "T_MAIS", "T_MENOS", "T_IGUAL", "T_MAIOR", "T_MENOR", "T_E", "T_OU",
  "T_V", "T_F", "T_NUMERO", "T_NAO", "T_ABRE", "T_FECHA", "T_INTEIRO",
  "T_LOGICO", "T_ABRE_COL", "T_FECHA_COL", "T_REPITA", "T_ATE",
  "T_FIMREPITA", "$accept", "programa", "$@1", "cabecalho", "variaveis",
  "declaracao_variaveis", "tipo", "variavel", "$@2", "tamanho", "$@3",
  "indice", "posicao", "$@4", "lista_variaveis", "lista_comandos",
  "comando", "leitura", "$@5", "colchetes", "escrita", "repeticao", "$@6",
  "$@7", "$@8", "$@9", "selecao", "$@10", "$@11", "atribuicao", "$@12",
  "expr", "termo", "$@13", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      15,    10,    21,    13,   -27,   -27,   -27,   -27,   -27,   -27,
      17,    43,   -27,   -27,    11,    -4,    -3,   -27,   -27,   -27,
      46,    27,   -27,    27,   -27,    45,    -4,   -27,   -27,   -27,
     -27,   -27,    30,   -27,    25,   -27,   -27,   -27,   -27,   -27,
      27,    27,   122,   -27,    27,   113,    -4,   -27,   -27,   -27,
      27,    50,    47,    48,   -27,    98,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    89,   -27,    41,    49,   122,
      27,    27,   -27,    27,   -27,   -27,   -27,   -27,   -11,   -11,
       7,    44,    44,    -8,    -8,   -27,    -4,    27,   -27,    61,
     122,    51,    70,    -4,    65,   122,   -27,   -27,   -27,    69,
     -27,    59,   -27,    -4,   -27,    68,   -27
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     5,     4,     1,     9,    10,     2,     6,
       0,     0,    11,    22,     8,    23,    13,     7,    21,    44,
       0,     0,    35,     0,    38,     0,    23,    25,    26,    27,
      28,    29,     0,    12,    18,    30,    56,    59,    60,    58,
       0,     0,    34,    55,     0,     0,    23,     3,    24,    14,
       0,     0,    32,    16,    61,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,    19,
       0,     0,    31,     0,    57,    62,    46,    47,    48,    49,
      52,    50,    51,    53,    54,    36,    23,     0,    15,     0,
      45,     0,     0,    23,     0,    39,    20,    33,    17,     0,
      42,     0,    37,    23,    40,     0,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -27,   -27,   -27,   -27,   -27,    71,   -27,    84,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -26,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   -22,    60,   -27
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,     3,     8,     9,    10,    13,    16,    33,
      68,    74,    51,    89,    14,    25,    26,    27,    52,    72,
      28,    29,    44,    93,    46,   101,    30,    86,   103,    31,
      34,    42,    43,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    45,    19,    20,    21,    22,    56,    57,    23,    56,
      57,    58,    59,    60,    61,    62,     4,    12,     1,    55,
      67,     5,    65,    12,    56,    57,    58,    59,    69,    61,
      62,    32,    24,    36,    76,    77,    78,    79,    80,    81,
      82,    83,    84,     6,     7,     6,     7,    15,    90,    91,
      47,    92,    35,    37,    38,    39,    40,    41,    49,    50,
      94,    56,    57,    58,    59,    95,    70,    99,    56,    57,
      58,    59,    60,    61,    62,    63,    64,   105,    87,   100,
     102,    71,    73,   106,    88,    17,    97,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    96,   104,    18,    85,
      54,     0,     0,     0,     0,    98,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    56,    57,    58,    59,    60,
      61,    62,    63,    64,     0,     0,    66,     0,     0,    75,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    56,
      57,    58,    59,    60,    61,    62,    63,    64
};

static const yytype_int8 yycheck[] =
{
      26,    23,     6,     7,     8,     9,    17,    18,    12,    17,
      18,    19,    20,    21,    22,    23,     6,     6,     3,    41,
      46,     0,    44,     6,    17,    18,    19,    20,    50,    22,
      23,    34,    36,     6,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    32,    33,    32,    33,     4,    70,    71,
       5,    73,     6,    26,    27,    28,    29,    30,    28,    34,
      86,    17,    18,    19,    20,    87,    16,    93,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   103,    37,    14,
      11,    34,    34,    15,    35,    14,    35,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    35,    38,    14,    10,
      40,    -1,    -1,    -1,    -1,    35,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    -1,    13,    -1,    -1,    31,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    17,
      18,    19,    20,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    40,    42,     6,     0,    32,    33,    43,    44,
      45,    41,     6,    46,    53,     4,    47,    44,    46,     6,
       7,     8,     9,    12,    36,    54,    55,    56,    59,    60,
      65,    68,    34,    48,    69,     6,     6,    26,    27,    28,
      29,    30,    70,    71,    61,    70,    63,     5,    54,    28,
      34,    51,    57,    72,    71,    70,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    70,    13,    54,    49,    70,
      16,    34,    58,    34,    50,    31,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    10,    66,    37,    35,    52,
      70,    70,    70,    62,    54,    70,    35,    35,    35,    54,
      14,    64,    11,    67,    38,    54,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    41,    40,    42,    43,    43,    44,    44,    45,
      45,    47,    46,    48,    49,    48,    50,    50,    51,    52,
      51,    53,    53,    54,    54,    55,    55,    55,    55,    55,
      57,    56,    58,    58,    59,    61,    62,    60,    63,    64,
      60,    66,    67,    65,    69,    68,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    72,    71,    71,    71,
      71,    71,    71
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     2,     0,     1,     3,     2,     1,
       1,     0,     3,     0,     0,     4,     0,     3,     0,     0,
       4,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       0,     4,     0,     3,     2,     0,     0,     7,     0,     0,
       7,     0,     0,     9,     0,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     0,     3,     1,     1,
       1,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 72 "sintatico.y"
            { 
                mostra_tabela(); 
                fprintf(yyout, "\tAMEN\t%d\n", conta);  
                empilha(conta); 
            }
#line 1438 "sintatico.c"
    break;

  case 3:
#line 78 "sintatico.y"
            { 
                fprintf(yyout, "\tDMEN\t%d\n", desempilha());  
                fprintf(yyout, "\tFIMP\n");  
            }
#line 1447 "sintatico.c"
    break;

  case 4:
#line 86 "sintatico.y"
            { fprintf(yyout, "\tINPP\n");  }
#line 1453 "sintatico.c"
    break;

  case 9:
#line 100 "sintatico.y"
                    { tipo = 'i';}
#line 1459 "sintatico.c"
    break;

  case 10:
#line 101 "sintatico.y"
                    { tipo = 'l';}
#line 1465 "sintatico.c"
    break;

  case 11:
#line 105 "sintatico.y"
                  { strcpy(elem_tab.id, atomo); }
#line 1471 "sintatico.c"
    break;

  case 13:
#line 110 "sintatico.y"
        {
            int pos = atoi(atomo);//TODO: cadastrar variavel simples DONE:
            elem_tab.categoria = 'v';     /* v = indica que é uma variavel   */
            elem_tab.endereco = conta;    /* Incrementa conta quando encontrar variaveis          */
            conta++;
            elem_tab.tamanho = 1;
            
        }
#line 1484 "sintatico.c"
    break;

  case 14:
#line 119 "sintatico.y"
            {
                /*TODO:cadastrar vetor*/
                int count = atoi(atomo);
                elem_tab.categoria = 'a';       /* a = indica que é um array   */
                elem_tab.endereco = conta;   /* Incrementa conta quando encontrar variaveis          */
                conta += count; 
                elem_tab.tamanho = count;
                elem_tab.tipo = tipo;
                
            }
#line 1499 "sintatico.c"
    break;

  case 16:
#line 132 "sintatico.y"
      {
        char t = desempilha(); //desempilho o tipo
        if(t != 'i') //if(!(strcmp(t, 'INT')))
                erro("Incompatibilidade de tipos");
        empilha(t);
    }
#line 1510 "sintatico.c"
    break;

  case 17:
#line 139 "sintatico.y"
        {
            //não sei o que faço
        }
#line 1518 "sintatico.c"
    break;

  case 18:
#line 145 "sintatico.y"
        {
            printf("Chegou no na posição ");
            int pos = desempilha();
            int t = TabSimb[pos].tipo;
            if (t != 'i') 
                erro("Incompatibilidade de tipos");
            empilha(pos);
            //fprintf(yyout, "\tARZG\t%d\n", TabSimb[pos].endereco);  /* (endereço da variavel na estrutura) */
        }
#line 1532 "sintatico.c"
    break;

  case 19:
#line 155 "sintatico.y"
            {
                int t = desempilha();
                int p = desempilha();
                if(t != 'i')
                    erro("Tipo do indice deve ser inteiro");
                if(TabSimb[p].categoria != 'a')
                    erro("A variavel nao é um vetor");
                empilha(p);
            }
#line 1546 "sintatico.c"
    break;

  case 21:
#line 169 "sintatico.y"
            {
                elem_tab.tipo = tipo;
                insere_simbolo(elem_tab);       /* Inserir o simbolo na tabela de simbolos              */
            }
#line 1555 "sintatico.c"
    break;

  case 22:
#line 174 "sintatico.y"
            {
                elem_tab.tipo = tipo;
                insere_simbolo(elem_tab);       /* Inserir o simbolo na tabela de simbolos              */
            }
#line 1564 "sintatico.c"
    break;

  case 30:
#line 195 "sintatico.y"
            {
                int pos = busca_simbolo(atomo); /* Busca o nome na tabela de Simbolo associado ao T_IDENTIF guardado na variavel 'atomo' */
                if (pos == -1) erro("Variavel não declarada");
                empilha(pos);
                printf("Chegou no leia");
            }
#line 1575 "sintatico.c"
    break;

  case 32:
#line 205 "sintatico.y"
      {
            printf("Chegou no colchetes ");
            fprintf(yyout, "\tLEIA\n");
            int pos = desempilha();
            int t = TabSimb[pos].tipo;
            if (t != 'i') 
                erro("Incompatibilidade de tipos");
            fprintf(yyout, "\tARZG\t%d\n", TabSimb[pos].endereco);  
            empilha(pos);
        }
#line 1590 "sintatico.c"
    break;

  case 33:
#line 216 "sintatico.y"
        {
            char t = desempilha();
            int pos = desempilha(); //desempilha posiçao
            if(t != 'i') 
                erro("Incompatibilidade de tipos");
            fprintf(yyout, "\tLEIA\n"); 
            fprintf(yyout, "\tARZV\t%d\n", TabSimb[pos].endereco);
            empilha(pos);
        }
#line 1604 "sintatico.c"
    break;

  case 34:
#line 228 "sintatico.y"
            { fprintf(yyout, "\tESCR\n"); }
#line 1610 "sintatico.c"
    break;

  case 35:
#line 233 "sintatico.y"
            { 
                printf("Chega no t-enquanto ");
                rotulo++; //  Cria um rotulo adicionando 1 a variavel  
                fprintf(yyout, "L%d\tNADA\n", rotulo);  //  Marca UM lugar NO CODIGO com o VALOR do ROTULO CRIADO acima  
                empilha(rotulo);  //  Empilha o valor do rotulo como um lugar a ser retornado futuramente  /
            }
#line 1621 "sintatico.c"
    break;

  case 36:
#line 240 "sintatico.y"
            {
                printf("Chega no t-faça ");
                char t = desempilha();           // Desempilha o tipo do identificador /
                    if (t != 'l')
                        erro ("Incompatibilidade de tipos!");
                rotulo++;
                fprintf(yyout, "\tDSVF\tL%d\n", rotulo); // Desvia se Falso / 
                empilha(rotulo);
                printf("Sai do t-faça ");
            }
#line 1636 "sintatico.c"
    break;

  case 37:
#line 251 "sintatico.y"
            {
                printf("Chega no t-fimenquanto ");
                int r1 = desempilha(); // Rotulo de Saida da Repeticao /
                int r2 = desempilha(); // Rotulo de Entrada da Repeticao /
                fprintf(yyout, "\tDSVS\tL%d\n", r2);    // Desvia se Verdadeiro /
                fprintf(yyout, "L%d\tNADA\n", r1);      // Marca desvio Se Falso */
            }
#line 1648 "sintatico.c"
    break;

  case 38:
#line 259 "sintatico.y"
            {
                rotulo++;                                   /*  Cria um rotulo adicionando 1 a variavel  */
                fprintf(yyout, "L%d\tNADA\n", rotulo);      /*  Marca UM lugar NO CODIGO para VOLTAR caso REPITA for DSVF */
                empilha(rotulo);                            /*  Empilha o valor do rotulo SINALIZANDO o LUGAR para VOLTAR */
            }
#line 1658 "sintatico.c"
    break;

  case 39:
#line 265 "sintatico.y"
                {
                    char t = desempilha();                  /* Tipo do identificador */
                    if(t != 'l')                            /* Verificação de tipos coerentes */
                        erro("Incompatibilidade de tipos");
                    int r = desempilha();                   /* Busca o rotulo da repeticao */
                    fprintf(yyout, "\tDSVF\tL%d\n", r);     /* Volta ao rotulo caso Falso */
                }
#line 1670 "sintatico.c"
    break;

  case 41:
#line 278 "sintatico.y"
            {
                char t = desempilha();              /* Desempilha o tipo do identificador */
                    if (t != 'l')
                        erro ("Incompatibilidade de tipos");
                rotulo++; 
                fprintf(yyout, "\tDSVF\tL%d\n", rotulo);  
                empilha(rotulo);                    /*  Rotulo do SENAO  */
            }
#line 1683 "sintatico.c"
    break;

  case 42:
#line 287 "sintatico.y"
            {
                int r = desempilha();                 /* Guarda rotulo do SENAO FALSO*/
                rotulo++;                                   /* Cria rotulo do Desvia Sempre */
                fprintf(yyout, "\tDSVS\tL%d\n", rotulo);    /* Marca com Rotulo Desvia Sempre */
                empilha(rotulo);                            /*  Empilha lugar do Desvia Sempre */
                fprintf(yyout, "L%d\tNADA\n", r);  }
#line 1694 "sintatico.c"
    break;

  case 43:
#line 294 "sintatico.y"
            {
                int r = desempilha();
                fprintf(yyout, "L%d\tNADA\n", r);
            }
#line 1703 "sintatico.c"
    break;

  case 44:
#line 302 "sintatico.y"
            {
                printf("Chegou na atribuiçao 1 ");
                int pos = busca_simbolo(atomo); 
                if (pos == -1) 
                    erro("Variavel não declarada");
                empilha(pos);
            }
#line 1715 "sintatico.c"
    break;

  case 45:
#line 310 "sintatico.y"
            {
                printf("Chegou na atribuiçao 2 ");
                int t = desempilha();
                int pos = desempilha();
                fprintf(yyout, "\tARZV\t%d\n", TabSimb[pos].endereco);  
            
            }
#line 1727 "sintatico.c"
    break;

  case 46:
#line 322 "sintatico.y"
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('i');
                fprintf(yyout, "\tMULT\n");
            }
#line 1740 "sintatico.c"
    break;

  case 47:
#line 331 "sintatico.y"
            {   
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('i');
                fprintf(yyout, "\tDIVI\n");  
            }
#line 1753 "sintatico.c"
    break;

  case 48:
#line 340 "sintatico.y"
            { 
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos é esse");
                empilha('i');
                fprintf(yyout, "\tSOMA\n");  
                printf("saiu da expressao");
                
            }
#line 1768 "sintatico.c"
    break;

  case 49:
#line 351 "sintatico.y"
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('i');
                fprintf(yyout, "\tSUBT\n");  
            }
#line 1781 "sintatico.c"
    break;

  case 50:
#line 360 "sintatico.y"
            { 
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador      */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tCMMA\n");  
            }
#line 1794 "sintatico.c"
    break;

  case 51:
#line 369 "sintatico.y"
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador       */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tCMME\n");  
            }
#line 1807 "sintatico.c"
    break;

  case 52:
#line 378 "sintatico.y"
            { 
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador       */
                if (t1 != 'i' || t2 != 'i')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tCMIG\n");  
            }
#line 1820 "sintatico.c"
    break;

  case 53:
#line 387 "sintatico.y"
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador       */
                if (t1 != 'l' || t2 != 'l')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tCONJ\n");  
            }
#line 1833 "sintatico.c"
    break;

  case 54:
#line 396 "sintatico.y"
            {
                char t1 = desempilha();             /* Desempilha o tipo do primeiro identificador      */
                char t2 = desempilha();             /* Desempilha o tipo do segundo identificador       */
                if (t1 != 'l' || t2 != 'l')         /* Se tipos não puderem ser equacionados            */
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tDISJ\n");  
            }
#line 1846 "sintatico.c"
    break;

  case 56:
#line 409 "sintatico.y"
            {
                int pos = busca_simbolo(atomo);     
                if (pos == -1) 
                    erro("Variavel não declarada");
                fprintf(yyout, "\tCRVG\t%d\n", TabSimb[pos].endereco);
                empilha(pos);
                empilha(TabSimb[pos].tipo); //aqui empila tipo também
            }
#line 1859 "sintatico.c"
    break;

  case 58:
#line 418 "sintatico.y"
            { 
                empilha('i');
                fprintf(yyout, "\tCRCT\t%s\n", atomo);  
            }
#line 1868 "sintatico.c"
    break;

  case 59:
#line 423 "sintatico.y"
            { 
                empilha('l');
                fprintf(yyout, "\tCRCT\t1\n");  
            }
#line 1877 "sintatico.c"
    break;

  case 60:
#line 428 "sintatico.y"
            { 
                empilha('l');
                fprintf(yyout, "\tCRCT\t0\n");  
            }
#line 1886 "sintatico.c"
    break;

  case 61:
#line 433 "sintatico.y"
            {
                char t = desempilha();
                if (t != 'l')
                    erro ("Incompatibilidade de tipos");
                empilha('l');
                fprintf(yyout, "\tNEGA\n");  
            }
#line 1898 "sintatico.c"
    break;


#line 1902 "sintatico.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 443 "sintatico.y"


void erro (char *s){
    printf("ERRO: %s\n", s);
}

int yyerror (char *s){
    erro(s);
}


 int main(int argc, char *argv[]){ // Adicionar feature de leitura por parametro //argv[0] = nome do executavel
    char *p, nameIn[100], nameOut[100];
    argv++; // incrementando pós nome do executavel
    if(argc < 2){ // indo para o parametro passado em linha de comando
        puts("\nCompilador Simples");
        puts("\tUSO: ./simples <nomefonte>[.simples]\n\n"); // Imprimir como usar na tela.
        exit(10);
    }
    p = strstr(argv[0], ".simples"); 
    if (p) *p = 0; // Se tiver extensão apaga a extensão
    
    strcpy(nameIn, argv[0]); //arquivo de entrada
    strcat(nameIn, ".simples"); //extensão simples
    strcpy(nameOut, argv[0]); //arquivo de saida
    strcat(nameOut, ".mvs"); //extensão mvs da Maquina Simples

    yyin = fopen(nameIn, "rt");
    if(!yyin){
        puts("Programa fonte nao encontrado!");
        exit(10);
    }
    yyout = fopen(nameOut, "wt");

    if(!yyparse())
        puts("Programa Ok!");//se não houver erro
}
