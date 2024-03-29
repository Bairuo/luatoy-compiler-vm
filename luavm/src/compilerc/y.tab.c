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
#line 3 "parser.y" /* yacc.c:339  */

#include <iostream>
#include <string>
#include <stdlib.h>
#include "stdio.h"
#include "block.h"
#include "exp.h"
#include "stat.h"

extern char *yytext;
extern int lines;

extern "C" {
	extern int yylex();
	void yyerror(const char *s);
	int yyparse (void);
}

struct Block *finalBlock = nullptr;

struct Standard {
	int line = -1;
	int id = -1;
	std::string name;

	Standard();
	Standard(int line, int id) : line(line), id(id) {}
	Standard(int line, int id, const std::string &name) : line(line), id(id), name(name) {}
};


#line 98 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    TOKEN_EOF = 0,
    TOKEN_VARARG = 1,
    TOKEN_SEP_SEMI = 2,
    TOKEN_SEP_COMMA = 3,
    TOKEN_SEP_DOT = 4,
    TOKEN_SEP_COLON = 5,
    TOKEN_SEP_LABEL = 6,
    TOKEN_SEP_LPAREN = 7,
    TOKEN_SEP_RPAREN = 8,
    TOKEN_SEP_LBRACK = 9,
    TOKEN_SEP_RBRACK = 10,
    TOKEN_SEP_LCURLY = 11,
    TOKEN_SEP_RCURLY = 12,
    TOKEN_OP_ASSIGN = 13,
    TOKEN_OP_MINUS = 14,
    TOKEN_OP_WAVE = 15,
    TOKEN_OP_ADD = 16,
    TOKEN_OP_MUL = 17,
    TOKEN_OP_DIV = 18,
    TOKEN_OP_IDIV = 19,
    TOKEN_OP_POW = 20,
    TOKEN_OP_MOD = 21,
    TOKEN_OP_BAND = 22,
    TOKEN_OP_BOR = 23,
    TOKEN_OP_SHR = 24,
    TOKEN_OP_SHL = 25,
    TOKEN_OP_CONCAT = 26,
    TOKEN_OP_LT = 27,
    TOKEN_OP_LE = 28,
    TOKEN_OP_GT = 29,
    TOKEN_OP_GE = 30,
    TOKEN_OP_EQ = 31,
    TOKEN_OP_NE = 32,
    TOKEN_OP_LEN = 33,
    TOKEN_OP_AND = 34,
    TOKEN_OP_OR = 35,
    TOKEN_OP_NOT = 36,
    TOKEN_KW_BREAK = 37,
    TOKEN_KW_DO = 38,
    TOKEN_KW_ELSE = 39,
    TOKEN_KW_ELSEIF = 40,
    TOKEN_KW_END = 41,
    TOKEN_KW_FALSE = 42,
    TOKEN_KW_FOR = 43,
    TOKEN_KW_FUNCTION = 44,
    TOKEN_KW_GOTO = 45,
    TOKEN_KW_IF = 46,
    TOKEN_KW_IN = 47,
    TOKEN_KW_LOCAL = 48,
    TOKEN_KW_NIL = 49,
    TOKEN_KW_REPEAT = 50,
    TOKEN_KW_RETURN = 51,
    TOKEN_KW_THEN = 52,
    TOKEN_KW_TRUE = 53,
    TOKEN_KW_UNTIL = 54,
    TOKEN_KW_WHILE = 55,
    TOKEN_IDENTIFIER = 56,
    TOKEN_NUMBER = 57,
    TOKEN_STRING = 58,
    TOKEN_OP_UNM = 258,
    TOKEN_OP_SUB = 259,
    TOKEN_OP_BNOT = 260,
    TOKEN_OP_BXOR = 261,
    TOKEN_COMMAVARARG = 262
  };
#endif
/* Tokens.  */
#define TOKEN_EOF 0
#define TOKEN_VARARG 1
#define TOKEN_SEP_SEMI 2
#define TOKEN_SEP_COMMA 3
#define TOKEN_SEP_DOT 4
#define TOKEN_SEP_COLON 5
#define TOKEN_SEP_LABEL 6
#define TOKEN_SEP_LPAREN 7
#define TOKEN_SEP_RPAREN 8
#define TOKEN_SEP_LBRACK 9
#define TOKEN_SEP_RBRACK 10
#define TOKEN_SEP_LCURLY 11
#define TOKEN_SEP_RCURLY 12
#define TOKEN_OP_ASSIGN 13
#define TOKEN_OP_MINUS 14
#define TOKEN_OP_WAVE 15
#define TOKEN_OP_ADD 16
#define TOKEN_OP_MUL 17
#define TOKEN_OP_DIV 18
#define TOKEN_OP_IDIV 19
#define TOKEN_OP_POW 20
#define TOKEN_OP_MOD 21
#define TOKEN_OP_BAND 22
#define TOKEN_OP_BOR 23
#define TOKEN_OP_SHR 24
#define TOKEN_OP_SHL 25
#define TOKEN_OP_CONCAT 26
#define TOKEN_OP_LT 27
#define TOKEN_OP_LE 28
#define TOKEN_OP_GT 29
#define TOKEN_OP_GE 30
#define TOKEN_OP_EQ 31
#define TOKEN_OP_NE 32
#define TOKEN_OP_LEN 33
#define TOKEN_OP_AND 34
#define TOKEN_OP_OR 35
#define TOKEN_OP_NOT 36
#define TOKEN_KW_BREAK 37
#define TOKEN_KW_DO 38
#define TOKEN_KW_ELSE 39
#define TOKEN_KW_ELSEIF 40
#define TOKEN_KW_END 41
#define TOKEN_KW_FALSE 42
#define TOKEN_KW_FOR 43
#define TOKEN_KW_FUNCTION 44
#define TOKEN_KW_GOTO 45
#define TOKEN_KW_IF 46
#define TOKEN_KW_IN 47
#define TOKEN_KW_LOCAL 48
#define TOKEN_KW_NIL 49
#define TOKEN_KW_REPEAT 50
#define TOKEN_KW_RETURN 51
#define TOKEN_KW_THEN 52
#define TOKEN_KW_TRUE 53
#define TOKEN_KW_UNTIL 54
#define TOKEN_KW_WHILE 55
#define TOKEN_IDENTIFIER 56
#define TOKEN_NUMBER 57
#define TOKEN_STRING 58
#define TOKEN_OP_UNM 258
#define TOKEN_OP_SUB 259
#define TOKEN_OP_BNOT 260
#define TOKEN_OP_BXOR 261
#define TOKEN_COMMAVARARG 262

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "parser.y" /* yacc.c:355  */
   
	   const char *str;

	   struct Standard *standard;

	   struct Block *pBlock;
	   struct Stat *pStat;
	   struct Exp *pExp;

	   struct NameList *pNameList;
	   struct ExpList *pExpList;
	   struct StatList *pStatList;

	   struct IfStat *pIfStat;
	   struct FuncDefExp *pFuncDefExp;
	   struct FuncCallExp *pFuncCallExp;
	   struct FieldExp *pFieldExp;

#line 286 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);



/* Copy the second part of user declarations.  */

#line 317 "y.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   469

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   262

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    61,    62,
      63,    64,    65
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   138,   138,   139,   140,   141,   144,   145,   149,   150,
     151,   152,   153,   154,   155,   156,   158,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   171,   174,   175,   176,
     177,   178,   181,   182,   185,   188,   189,   192,   230,   259,
     260,   263,   264,   265,   269,   270,   271,   272,   275,   276,
     279,   280,   283,   284,   287,   288,   291,   292,   293,   294,
     297,   298,   299,   302,   303,   304,   307,   308,   311,   312,
     315,   316,   317,   320,   321,   324,   327,   330,   331,   334,
     335,   338,   339,   340,   341,   342,   343,   344,   347,   348,
     352,   353,   356,   357,   360,   361,   362,   365,   379,   382,
     383,   384,   385,   386,   387,   388,   391,   392,   393,   394,
     395,   398,   401,   402,   405,   406,   407,   408,   424,   425,
     426,   427,   428
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "TOKEN_EOF", "error", "$undefined", "TOKEN_VARARG", "TOKEN_SEP_SEMI",
  "TOKEN_SEP_COMMA", "TOKEN_SEP_DOT", "TOKEN_SEP_COLON", "TOKEN_SEP_LABEL",
  "TOKEN_SEP_LPAREN", "TOKEN_SEP_RPAREN", "TOKEN_SEP_LBRACK",
  "TOKEN_SEP_RBRACK", "TOKEN_SEP_LCURLY", "TOKEN_SEP_RCURLY",
  "TOKEN_OP_ASSIGN", "TOKEN_OP_MINUS", "TOKEN_OP_WAVE", "TOKEN_OP_ADD",
  "TOKEN_OP_MUL", "TOKEN_OP_DIV", "TOKEN_OP_IDIV", "TOKEN_OP_POW",
  "TOKEN_OP_MOD", "TOKEN_OP_BAND", "TOKEN_OP_BOR", "TOKEN_OP_SHR",
  "TOKEN_OP_SHL", "TOKEN_OP_CONCAT", "TOKEN_OP_LT", "TOKEN_OP_LE",
  "TOKEN_OP_GT", "TOKEN_OP_GE", "TOKEN_OP_EQ", "TOKEN_OP_NE",
  "TOKEN_OP_LEN", "TOKEN_OP_AND", "TOKEN_OP_OR", "TOKEN_OP_NOT",
  "TOKEN_KW_BREAK", "TOKEN_KW_DO", "TOKEN_KW_ELSE", "TOKEN_KW_ELSEIF",
  "TOKEN_KW_END", "TOKEN_KW_FALSE", "TOKEN_KW_FOR", "TOKEN_KW_FUNCTION",
  "TOKEN_KW_GOTO", "TOKEN_KW_IF", "TOKEN_KW_IN", "TOKEN_KW_LOCAL",
  "TOKEN_KW_NIL", "TOKEN_KW_REPEAT", "TOKEN_KW_RETURN", "TOKEN_KW_THEN",
  "TOKEN_KW_TRUE", "TOKEN_KW_UNTIL", "TOKEN_KW_WHILE", "TOKEN_IDENTIFIER",
  "TOKEN_NUMBER", "TOKEN_STRING", "TOKEN_OP_UNM", "TOKEN_OP_SUB",
  "TOKEN_OP_BNOT", "TOKEN_OP_BXOR", "TOKEN_COMMAVARARG", "$accept",
  "block", "stats", "stat", "label", "ifstat", "eifstats", "functiondef",
  "funcbody", "funcname", "pointName", "parlist", "retstat", "explist",
  "namelist", "varlist", "functioncall", "args", "var", "prefixexp",
  "tableconstructor", "fieldlist", "field", "fieldsep", "name", "exp",
  "exp12", "exp11", "exp10", "exp9", "exp8", "exp7", "exp6", "exp5",
  "exp4", "exp2", "exp2l", "exp1", "exp0", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,   258,   259,   260,   261,   262
};
# endif

#define YYPACT_NINF -71

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     396,   -71,   -38,   379,   -71,   396,    13,   -38,   -38,    50,
     -11,   396,   267,   129,   -71,    37,   -13,   411,   -71,   -71,
     -71,    58,    51,    39,    32,   -71,    67,   -71,   231,   249,
     249,   249,   249,   -71,    43,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,    32,   -71,    74,   -71,    53,    57,   161,    81,
      90,    92,    56,    95,    79,   -71,    96,    77,    82,    75,
      55,    43,   119,   122,   -71,    86,    85,   -38,   116,   130,
      80,   -71,   133,   142,   105,   114,   -71,   -71,   -71,   379,
      14,   -38,   -38,   307,   379,   -71,   -71,   -71,   -71,   379,
     -71,   143,    44,   144,   -71,   -71,   -71,   -71,   -71,    16,
     -71,   -71,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   -71,   -71,   -71,   379,   -38,   379,   -71,
     -38,   -38,   -71,   396,    43,   379,   379,   -71,   379,   -71,
     396,   -71,   -71,   -71,    -5,   -71,   148,   150,   151,   -71,
     -71,   -71,   343,   379,   -71,   396,   158,   106,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   120,
     -71,   165,   -71,   -71,    36,   -71,   -71,   -71,   -71,   134,
     -71,   -71,   -71,   157,   -71,   -71,   135,   396,   -71,   396,
     379,   396,   379,   -71,   -10,   -71,   379,   -71,   136,   138,
      29,   139,   149,   396,   -71,   -71,   -71,   -71,   379,   396,
     -71,   396,   140,   156,   162,   164,   -71,   396,   -71,   -71,
     172,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     8,     0,     0,     9,     5,     0,     0,     0,     0,
       0,     5,    47,     0,    75,     0,     3,     7,    10,    22,
       4,     0,    23,    63,     0,    60,     0,   119,     0,     0,
       0,     0,     0,   115,     0,   114,   116,   117,   118,   120,
      64,    63,   121,   122,     0,    76,    78,    80,    87,    89,
      91,    93,    96,    98,   105,   110,   113,     0,     0,     0,
      51,     0,    38,    40,    11,     0,     0,     0,     0,    51,
       0,    46,    45,    49,     0,     0,     1,     2,     6,     0,
       0,     0,     0,     0,     0,    59,    54,    58,    26,     0,
      67,     0,    69,    60,    72,   106,   107,   108,   109,     0,
      34,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   112,    12,    25,     0,     0,     0,    18,
       0,     0,    31,     5,     0,     0,     0,    44,     0,    24,
       5,    21,    52,    62,     0,    56,     0,     0,     0,    66,
      74,    73,     0,     0,    43,     5,     0,    42,    77,    79,
      81,    82,    83,    84,    85,    86,    88,    90,    92,    95,
      94,    97,    99,   100,   101,   102,   103,   104,   111,     0,
      50,     0,    37,    39,     0,    19,    20,    14,    48,     0,
      55,    57,    61,     0,    68,    71,     0,     5,    41,     5,
       0,     5,     0,    27,     0,    13,     0,    36,     0,     0,
       0,     0,     0,     5,    29,    70,    35,    17,     0,     5,
      28,     5,     0,     0,     0,    33,    30,     5,    15,    32,
       0,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,    11,   159,   -71,   -71,   -71,   -21,   -71,   -58,   -71,
      87,   -71,   200,   -70,    -8,   137,    10,    97,     0,     1,
     -17,    73,   -71,   -71,    22,    33,   124,   146,   224,   126,
     132,   141,   -27,   131,   218,   128,   -71,    83,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    17,    18,    19,   204,    39,   100,    61,
      62,   156,    20,    72,    59,    21,    40,    86,    41,    42,
      43,    91,    92,   152,    25,    73,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,   123,    55,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    24,    68,   129,    83,    23,    24,    87,    28,   141,
      22,    23,    24,   146,    58,    22,    57,    23,    24,   154,
      14,    22,    70,     3,    26,    87,   155,    22,    60,    63,
      64,   213,    69,   214,   218,    67,    44,    76,    81,    82,
      12,    83,    66,    84,    80,    28,    75,    14,   150,   151,
      93,    65,    99,    27,   -53,    85,   179,   -64,   -64,     3,
     127,    94,   -64,    28,   -64,   186,    29,    30,   188,   219,
     128,    14,    14,    79,    14,    88,   185,   201,   202,   203,
      23,    24,   113,   114,   101,    31,   169,   170,    32,   134,
     102,   157,    85,   103,    33,   116,    34,   117,   118,   119,
     120,    35,   121,   143,   144,    36,   110,   111,    14,    37,
      38,   -64,    95,    96,    97,    98,   112,   147,   122,   180,
     124,    69,   148,   115,   126,   125,   130,    87,   131,   132,
      74,   135,    27,    23,    24,   127,   136,   137,     3,   133,
      23,    24,    28,    22,   184,    29,    30,   138,   139,    69,
      22,   189,   182,    63,   140,    23,    24,   149,   191,   153,
     199,   181,   192,   193,    31,    22,   196,    32,   197,   187,
     200,   198,   206,    33,    93,    34,    78,   205,   207,   216,
      35,   217,   220,   226,    36,    94,   195,    14,    37,    38,
     104,   105,   106,   107,   108,   109,   227,    23,    24,    23,
      24,    23,    24,   221,   229,   228,   202,    22,   208,    22,
     209,    22,   211,    23,    24,   231,    77,   142,   183,    23,
      24,    23,    24,    22,   222,   194,   158,    23,    24,    22,
     224,    22,   225,   210,    27,   212,   166,    22,   230,   215,
       3,   190,    89,   167,    28,    90,   171,    29,    30,   159,
     178,   223,    27,   168,     0,     0,     0,     0,     3,     0,
       0,     0,    28,     0,     0,     0,    31,     0,     0,    32,
      27,    71,     0,     0,     0,    33,     3,    34,     0,     0,
      28,     0,    35,    29,    30,     0,    36,     0,     0,    14,
      37,    38,     0,    33,     0,    34,     0,     0,     0,     0,
      35,     0,    31,     0,    36,    32,     0,    14,    37,    38,
      27,    33,     0,    34,     0,     0,     3,   145,    35,     0,
      28,     0,    36,    29,    30,    14,    37,    38,   160,   161,
     162,   163,   164,   165,   172,   173,   174,   175,   176,   177,
       0,     0,    31,     0,     0,    32,    27,     0,     0,     0,
       0,    33,     3,    34,    89,     0,    28,     0,    35,    29,
      30,     0,    36,     0,     0,    14,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,    32,    27,     0,     0,     0,     0,    33,     3,    34,
       0,     0,    28,     0,    35,    29,    30,     0,    36,     0,
       1,    14,    37,    38,     2,     3,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     1,     0,    32,     0,     2,
       3,     0,     0,    33,     0,    34,     0,     0,     0,     0,
      35,     0,     0,     0,    36,     4,     5,    14,    37,    38,
       0,     6,     7,     8,     9,     0,    10,     0,    11,    12,
       4,     5,     0,    13,    14,     0,     6,     7,     8,     9,
       0,    10,     0,    11,     0,     0,     0,     0,    13,    14
};

static const yytype_int16 yycheck[] =
{
       0,     0,    10,    61,     9,     5,     5,    24,    13,    79,
       0,    11,    11,    83,     1,     5,     5,    17,    17,     3,
      58,    11,    11,     9,     2,    42,    10,    17,     6,     7,
       8,    41,    10,    43,     5,    46,     3,     0,     6,     7,
      53,     9,     9,    11,     5,    13,    13,    58,     4,     5,
      28,     1,     9,     3,    15,    60,   126,     6,     7,     9,
       5,    28,    11,    13,    13,   135,    16,    17,   138,    40,
      15,    58,    58,    15,    58,     8,   134,    41,    42,    43,
      80,    80,    26,    27,    10,    35,   113,   114,    38,    67,
      37,    99,    60,    36,    44,    16,    46,    18,    19,    20,
      21,    51,    23,    81,    82,    55,    25,    17,    58,    59,
      60,    60,    29,    30,    31,    32,    24,    84,    22,   127,
      43,    99,    89,    28,    49,    43,     7,   144,     6,    43,
       1,    15,     3,   133,   133,     5,    56,     4,     9,    54,
     140,   140,    13,   133,   133,    16,    17,     5,    43,   127,
     140,   140,   130,   131,    40,   155,   155,    14,    10,    15,
      40,   128,    12,    12,    35,   155,   155,    38,    10,   136,
       5,    65,    15,    44,   152,    46,    17,    43,    43,    43,
      51,    43,    43,    43,    55,   152,   153,    58,    59,    60,
      29,    30,    31,    32,    33,    34,    40,   197,   197,   199,
     199,   201,   201,    54,   225,    43,    42,   197,   197,   199,
     199,   201,   201,   213,   213,    43,    16,    80,   131,   219,
     219,   221,   221,   213,   213,   152,   102,   227,   227,   219,
     219,   221,   221,   200,     3,   202,   110,   227,   227,   206,
       9,   144,    11,   111,    13,    14,   115,    16,    17,   103,
     122,   218,     3,   112,    -1,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    35,    -1,    -1,    38,
       3,     4,    -1,    -1,    -1,    44,     9,    46,    -1,    -1,
      13,    -1,    51,    16,    17,    -1,    55,    -1,    -1,    58,
      59,    60,    -1,    44,    -1,    46,    -1,    -1,    -1,    -1,
      51,    -1,    35,    -1,    55,    38,    -1,    58,    59,    60,
       3,    44,    -1,    46,    -1,    -1,     9,    10,    51,    -1,
      13,    -1,    55,    16,    17,    58,    59,    60,   104,   105,
     106,   107,   108,   109,   116,   117,   118,   119,   120,   121,
      -1,    -1,    35,    -1,    -1,    38,     3,    -1,    -1,    -1,
      -1,    44,     9,    46,    11,    -1,    13,    -1,    51,    16,
      17,    -1,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    38,     3,    -1,    -1,    -1,    -1,    44,     9,    46,
      -1,    -1,    13,    -1,    51,    16,    17,    -1,    55,    -1,
       4,    58,    59,    60,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,     4,    -1,    38,    -1,     8,
       9,    -1,    -1,    44,    -1,    46,    -1,    -1,    -1,    -1,
      51,    -1,    -1,    -1,    55,    39,    40,    58,    59,    60,
      -1,    45,    46,    47,    48,    -1,    50,    -1,    52,    53,
      39,    40,    -1,    57,    58,    -1,    45,    46,    47,    48,
      -1,    50,    -1,    52,    -1,    -1,    -1,    -1,    57,    58
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     8,     9,    39,    40,    45,    46,    47,    48,
      50,    52,    53,    57,    58,    67,    68,    69,    70,    71,
      78,    81,    82,    84,    85,    90,    90,     3,    13,    16,
      17,    35,    38,    44,    46,    51,    55,    59,    60,    73,
      82,    84,    85,    86,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   103,   104,    67,     1,    80,
      90,    75,    76,    90,    90,     1,    91,    46,    80,    90,
      67,     4,    79,    91,     1,    91,     0,    78,    68,    15,
       5,     6,     7,     9,    11,    60,    83,    86,     8,    11,
      14,    87,    88,    90,    91,   103,   103,   103,   103,     9,
      74,    10,    37,    36,    29,    30,    31,    32,    33,    34,
      25,    17,    24,    26,    27,    28,    16,    18,    19,    20,
      21,    23,    22,   102,    43,    43,    49,     5,    15,    74,
       7,     6,    43,    54,    90,    15,    56,     4,     5,    43,
      40,    79,    81,    90,    90,    10,    79,    91,    91,    14,
       4,     5,    89,    15,     3,    10,    77,    80,    92,    93,
      94,    94,    94,    94,    94,    94,    95,    96,    97,    98,
      98,    99,   100,   100,   100,   100,   100,   100,   101,    79,
      80,    91,    90,    76,    67,    74,    79,    91,    79,    67,
      83,    10,    12,    12,    87,    91,    67,    10,    65,    40,
       5,    41,    42,    43,    72,    43,    15,    43,    67,    67,
      91,    67,    91,    41,    43,    91,    43,    43,     5,    40,
      43,    54,    67,    91,    67,    67,    43,    40,    43,    72,
      67,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    66,    67,    67,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    71,    71,    71,
      71,    71,    72,    72,    73,    74,    74,    75,    75,    76,
      76,    77,    77,    77,    78,    78,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      84,    84,    84,    85,    85,    85,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    90,    91,    92,    92,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    98,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   101,   101,
     101,   102,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     2,     1,     1,     1,
       1,     2,     3,     5,     4,     9,    11,     7,     3,     4,
       4,     3,     1,     1,     3,     3,     3,     5,     7,     6,
       8,     3,     5,     4,     2,     5,     4,     3,     1,     3,
       1,     2,     1,     1,     3,     2,     2,     1,     3,     1,
       3,     1,     3,     1,     2,     4,     2,     3,     1,     1,
       1,     4,     3,     1,     1,     3,     3,     2,     3,     1,
       5,     3,     1,     1,     1,     1,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval.pBlock) = new Block(); (yyval.pBlock)->lastline = lines; (yyval.pBlock)->stats = (yyvsp[-1].pStatList)->stats; (yyval.pBlock)->retExps = (yyvsp[0].pExpList)->exps; finalBlock = (yyval.pBlock);}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval.pBlock) = new Block(); (yyval.pBlock)->lastline = lines; (yyval.pBlock)->stats = (yyvsp[0].pStatList)->stats; finalBlock = (yyval.pBlock);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.pBlock) = new Block(); (yyval.pBlock)->lastline = lines; (yyval.pBlock)->retExps = (yyvsp[0].pExpList)->exps; finalBlock = (yyval.pBlock);}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval.pBlock) = new Block(); (yyval.pBlock)->lastline = lines; finalBlock = (yyval.pBlock);}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].pStatList)->stats.push_back((yyvsp[-1].pStat)); (yyval.pStatList) = (yyvsp[0].pStatList);}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval.pStatList) = new StatList(); (yyval.pStatList)->stats.push_back((yyvsp[0].pStat));}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.pStat) = new Stat();}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 150 "parser.y" /* yacc.c:1646  */
    {auto t = new BreakStat(); t->line = lines; (yyval.pStat) = t;}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 151 "parser.y" /* yacc.c:1646  */
    {auto t = new LabelStat(); t->name = (yyvsp[0].str); (yyval.pStat) = t;}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 152 "parser.y" /* yacc.c:1646  */
    {auto t = new GotoStat(); t->name = (yyvsp[0].str); (yyval.pStat) = t;}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 153 "parser.y" /* yacc.c:1646  */
    {auto t = new DoStat(); t->block = (yyvsp[-1].pBlock); (yyval.pStat) = t;}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 154 "parser.y" /* yacc.c:1646  */
    {auto t = new WhileStat(); t->exp = (yyvsp[-3].pExp); t->block = (yyvsp[-1].pBlock); (yyval.pStat) = t;}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 155 "parser.y" /* yacc.c:1646  */
    {auto t = new RepeatStat(); t->block = (yyvsp[-2].pBlock); t->exp = (yyvsp[0].pExp); (yyval.pStat) = t;}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 157 "parser.y" /* yacc.c:1646  */
    {auto t = new ForNumStat(); t->varName = (yyvsp[-7].str); t->initExp = (yyvsp[-5].pExp); t->limitEXp = (yyvsp[-3].pExp); t->stepExp = new IntegerExp(lines, 1); t->block = (yyvsp[-1].pBlock); (yyval.pStat) = t;}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 159 "parser.y" /* yacc.c:1646  */
    {auto t = new ForNumStat(); t->varName = (yyvsp[-9].str); t->initExp = (yyvsp[-7].pExp); t->limitEXp = (yyvsp[-5].pExp); t->stepExp = (yyvsp[-3].pExp); t->block = (yyvsp[-1].pBlock); (yyval.pStat) = t;}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 160 "parser.y" /* yacc.c:1646  */
    {auto t = new ForInStat(); t->nameList = (yyvsp[-5].pNameList)->names; t->expList = (yyvsp[-3].pExpList)->exps; t->block = (yyvsp[-1].pBlock); (yyval.pStat) = t;}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 161 "parser.y" /* yacc.c:1646  */
    {auto t = new LocalFuncDefStat(); t->nameExp =(yyvsp[-1].pExp); t->defExp = (yyvsp[0].pFuncDefExp); (yyval.pStat) = t;}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 162 "parser.y" /* yacc.c:1646  */
    {auto t = new LocalFuncDefStat(); t->nameExp = new NameExp(0, (yyvsp[-1].str)); t->defExp = (yyvsp[0].pFuncDefExp); (yyval.pStat) = t;}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 163 "parser.y" /* yacc.c:1646  */
    {auto t = new LocalVarDeclStat(); t->nameList = (yyvsp[-2].pNameList)->names; t->expList = (yyvsp[0].pExpList)->exps; (yyval.pStat) = t;}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 164 "parser.y" /* yacc.c:1646  */
    {auto t = new AssignStat(); t->varList = (yyvsp[-2].pExpList)->exps; t->expList = (yyvsp[0].pExpList)->exps; (yyval.pStat) = t;}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.pStat) = (yyvsp[0].pStat);}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 166 "parser.y" /* yacc.c:1646  */
    {auto t = new FuncCallStat(); t->funcCallEXp = (yyvsp[0].pFuncCallExp); (yyval.pStat) = t;}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 167 "parser.y" /* yacc.c:1646  */
    {printf("error: in whilestat, line: %d\n", (yyvsp[-2].standard)->line); (yyval.pStat) = new WhileStat();}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 168 "parser.y" /* yacc.c:1646  */
    {printf("error: in forstat, line: %d\n", (yyvsp[-2].standard)->line); (yyval.pStat) = new EmptyStat();}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 171 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[-1].str);}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 174 "parser.y" /* yacc.c:1646  */
    {auto t = new IfStat(); t->exps.push_back((yyvsp[-3].pExp)); t->blocks.push_back((yyvsp[-1].pBlock)); (yyval.pStat) = t;}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 175 "parser.y" /* yacc.c:1646  */
    {auto t = new IfStat(); t->exps.push_back((yyvsp[-5].pExp)); t->blocks.push_back((yyvsp[-3].pBlock)); t->blocks.push_back((yyvsp[-1].pBlock)); (yyval.pStat) = t;}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 176 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].pIfStat)->exps.push_back((yyvsp[-4].pExp)); (yyvsp[-1].pIfStat)->blocks.push_back((yyvsp[-2].pBlock)); (yyval.pStat) = (yyvsp[-1].pIfStat);}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 177 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-3].pIfStat)->exps.push_back((yyvsp[-6].pExp)); (yyvsp[-3].pIfStat)->blocks.push_back((yyvsp[-4].pBlock)); (yyvsp[-3].pIfStat)->blocks.push_back((yyvsp[-1].pBlock)); (yyval.pStat) = (yyvsp[-3].pIfStat);}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 178 "parser.y" /* yacc.c:1646  */
    {printf("error: in ifstat, line: %d\n", (yyvsp[-2].standard)->line); (yyval.pStat) = new IfStat();}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 181 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].pIfStat)->exps.push_back((yyvsp[-3].pExp)); (yyvsp[0].pIfStat)->blocks.push_back((yyvsp[-1].pBlock)); (yyval.pIfStat) = (yyvsp[0].pIfStat);}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 182 "parser.y" /* yacc.c:1646  */
    {auto t = new IfStat(); t->exps.push_back((yyvsp[-2].pExp)); t->blocks.push_back((yyvsp[0].pBlock)); (yyval.pIfStat) = t;}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 185 "parser.y" /* yacc.c:1646  */
    {(yyval.pFuncDefExp) = (yyvsp[0].pFuncDefExp);}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 188 "parser.y" /* yacc.c:1646  */
    {(yyval.pFuncDefExp) = new FuncDefExp(); (yyval.pFuncDefExp)->parlist = (yyvsp[-3].pNameList)->names; (yyval.pFuncDefExp)->block = (yyvsp[-1].pBlock);}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.pFuncDefExp) = new FuncDefExp(); (yyval.pFuncDefExp)->block = (yyvsp[-1].pBlock);}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 193 "parser.y" /* yacc.c:1646  */
    {

		 		if((yyvsp[-2].pNameList)->names.size() > 1){
		 			auto ts = new TableAccessExp();

		 			for(auto it = (yyvsp[-2].pNameList)->names.rbegin(); it != (yyvsp[-2].pNameList)->names.rend(); it++){
		 				if(ts->prefixExp == nullptr){
		 					ts->prefixExp = new NameExp(0, *it);
		 				}
		 				else if(ts->keyExp == nullptr){
		 					ts->keyExp = new NameExp(0, *it);
		 				}
		 				else{
		 					auto t = ts;
		 					ts = new TableAccessExp();
		 					ts->prefixExp = t;
		 					ts->keyExp = new NameExp(0, *it);
		 				}
		 			}		
		 			
		 			auto t = ts;
		 			ts = new TableAccessExp();
		 			ts->prefixExp = t;
		 			ts->keyExp = new NameExp(0, (yyvsp[0].str));

		 			(yyval.pExp) = ts;
		 		}
		 		else{
		 			auto ts = new TableAccessExp();

		 			ts->prefixExp = new NameExp(0, (yyvsp[-2].pNameList)->names[0]);
		 			ts->keyExp = new NameExp(0, (yyvsp[0].str));

		 			(yyval.pExp) = ts;
		 		}

		 	}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 231 "parser.y" /* yacc.c:1646  */
    {

		 		if((yyvsp[0].pNameList)->names.size() > 1){
		 			auto ts = new TableAccessExp();

		 			for(auto it = (yyvsp[0].pNameList)->names.rbegin(); it != (yyvsp[0].pNameList)->names.rend(); it++){
		 				if(ts->prefixExp == nullptr){
		 					ts->prefixExp = new NameExp(0, *it);
		 				}
		 				else if(ts->keyExp == nullptr){
		 					ts->keyExp = new NameExp(0, *it);
		 				}
		 				else{
		 					auto t = ts;
		 					ts = new TableAccessExp();
		 					ts->prefixExp = t;
		 					ts->keyExp = new NameExp(0, *it);
		 				}
		 			}		
		 			(yyval.pExp) = ts;
		 		}
		 		else{
		 			(yyval.pExp) = new NameExp(0, (yyvsp[0].pNameList)->names[0]);
		 		}

		 	}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 259 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].pNameList)->names.push_back((yyvsp[-2].str)); (yyval.pNameList) = (yyvsp[0].pNameList);}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.pNameList) = new NameList(); (yyval.pNameList)->names.push_back((yyvsp[0].str));}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 263 "parser.y" /* yacc.c:1646  */
    {(yyval.pNameList) = (yyvsp[-1].pNameList); (yyval.pNameList)->names.push_back("...");}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyval.pNameList) = (yyvsp[0].pNameList);}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 265 "parser.y" /* yacc.c:1646  */
    {(yyval.pNameList) = new NameList(); (yyval.pNameList)->names.push_back("...");}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 269 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = (yyvsp[-1].pExpList);}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = (yyvsp[0].pExpList);}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 271 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList();}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 272 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList();}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].pExpList)->exps.push_back((yyvsp[-2].pExp)); (yyval.pExpList) = (yyvsp[0].pExpList);}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 276 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList(); (yyval.pExpList)->exps.push_back((yyvsp[0].pExp));}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 279 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].pNameList)->names.push_back((yyvsp[-2].str)); (yyval.pNameList) = (yyvsp[0].pNameList);}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 280 "parser.y" /* yacc.c:1646  */
    {(yyval.pNameList) = new NameList(); (yyval.pNameList)->names.push_back((yyvsp[0].str));}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 283 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].pExpList)->exps.push_back((yyvsp[-2].pExp)); (yyval.pExpList) = (yyvsp[0].pExpList);}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 284 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList(); (yyval.pExpList)->exps.push_back((yyvsp[0].pExp));}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.pFuncCallExp) = new FuncCallExp(); (yyval.pFuncCallExp)->prefixExp = (yyvsp[-1].pExp); (yyval.pFuncCallExp)->args = (yyvsp[0].pExpList)->exps;}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.pFuncCallExp) = new FuncCallExp(); (yyval.pFuncCallExp)->prefixExp = (yyvsp[-3].pExp); (yyval.pFuncCallExp)->nameExp = new StringExp(lines, (yyvsp[-1].str)); (yyval.pFuncCallExp)->args = (yyvsp[0].pExpList)->exps;}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 291 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList();}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList(); (yyval.pExpList)->exps = (yyvsp[-1].pExpList)->exps;}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 293 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList(); (yyval.pExpList)->exps.push_back((yyvsp[0].pExp));}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 294 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList(); (yyval.pExpList)->exps.push_back(new StringExp(lines, (yyvsp[0].standard)->name.c_str()));}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = new NameExp(lines, (yyvsp[0].str));}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 298 "parser.y" /* yacc.c:1646  */
    {auto t = new TableAccessExp(); t->prefixExp = (yyvsp[-3].pExp); t->keyExp = (yyvsp[-1].pExp); (yyval.pExp) = t;}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 299 "parser.y" /* yacc.c:1646  */
    {auto t = new TableAccessExp(); t->prefixExp = (yyvsp[-2].pExp); t->keyExp = new NameExp(lines, (yyvsp[0].str)); (yyval.pExp) = t;}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 302 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 303 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pFuncCallExp);}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 304 "parser.y" /* yacc.c:1646  */
    {auto t = new ParensExp(); t->exp = (yyvsp[-1].pExp); (yyval.pExp) = t;}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 307 "parser.y" /* yacc.c:1646  */
    {auto t = new TableConstructorExp(); t->fieldExps = (yyvsp[-1].pExpList)->exps; (yyval.pExp) = t;}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 308 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = new TableConstructorExp();}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 311 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].pExpList)->exps.push_back((yyvsp[-2].pFieldExp)); (yyval.pExpList) = (yyvsp[0].pExpList);}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 312 "parser.y" /* yacc.c:1646  */
    {(yyval.pExpList) = new ExpList(); (yyval.pExpList)->exps.push_back((yyvsp[0].pFieldExp));}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 315 "parser.y" /* yacc.c:1646  */
    {(yyval.pFieldExp) = new FieldExp(); (yyval.pFieldExp)->keyExp = (yyvsp[-3].pExp); (yyval.pFieldExp)->valExp = (yyvsp[0].pExp);}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 316 "parser.y" /* yacc.c:1646  */
    {(yyval.pFieldExp) = new FieldExp(); (yyval.pFieldExp)->keyExp = new StringExp(lines, (yyvsp[-2].str)); (yyval.pFieldExp)->valExp = (yyvsp[0].pExp);}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 317 "parser.y" /* yacc.c:1646  */
    {(yyval.pFieldExp) = new FieldExp(); (yyval.pFieldExp)->keyExp = nullptr; (yyval.pFieldExp)->valExp = (yyvsp[0].pExp);}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 324 "parser.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].standard)->name.c_str();}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 327 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 330 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 331 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 334 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 335 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 338 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 339 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 340 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 341 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 342 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 343 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 344 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 347 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 348 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 352 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 353 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 356 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 357 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 360 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 361 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 362 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 366 "parser.y" /* yacc.c:1646  */
    {
			auto t = dynamic_cast<ConcatExp*>((yyvsp[0].pExp));
			if(t != nullptr){
				t->exps.push_back((yyvsp[-2].pExp));
				(yyval.pExp) = (yyvsp[0].pExp);
			}
			else{
				auto t = new ConcatExp();
				t->exps.push_back((yyvsp[-2].pExp));
				t->exps.push_back((yyvsp[0].pExp));
				(yyval.pExp) = t;
			}
		}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 382 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 383 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 384 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 385 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 386 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 387 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp1 = (yyvsp[-2].pExp); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 388 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 391 "parser.y" /* yacc.c:1646  */
    {auto t = new UnopExp(); t->op = (yyvsp[-1].standard)->id; t->exp = (yyvsp[0].pExp); (yyval.pExp) = t;}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 392 "parser.y" /* yacc.c:1646  */
    {auto t = new UnopExp(); t->op = (yyvsp[-1].standard)->id; t->exp = (yyvsp[0].pExp); (yyval.pExp) = t;}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 393 "parser.y" /* yacc.c:1646  */
    {auto t = new UnopExp(); t->op = (yyvsp[-1].standard)->id; t->exp = (yyvsp[0].pExp); (yyval.pExp) = t;}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 394 "parser.y" /* yacc.c:1646  */
    {auto t = new UnopExp(); t->op = (yyvsp[-1].standard)->id; t->exp = (yyvsp[0].pExp); (yyval.pExp) = t;}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 395 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 398 "parser.y" /* yacc.c:1646  */
    {auto t = new BinopExp(); t->exp2 = (yyvsp[0].pExp); t->op = (yyvsp[-1].standard)->id; (yyval.pExp) = t;}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 401 "parser.y" /* yacc.c:1646  */
    {((BinopExp*)(yyvsp[0].pExp))->exp1 = (yyvsp[-1].pExp);}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 402 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 405 "parser.y" /* yacc.c:1646  */
    {auto t = new NilExp(); t->line = (yyvsp[0].standard)->line; (yyval.pExp) = t;}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 406 "parser.y" /* yacc.c:1646  */
    {auto t = new FalseExp(); t->line = (yyvsp[0].standard)->line; (yyval.pExp) = t;}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 407 "parser.y" /* yacc.c:1646  */
    {auto t = new TrueExp(); t->line = (yyvsp[0].standard)->line; (yyval.pExp) = t;}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 409 "parser.y" /* yacc.c:1646  */
    {
	 		if((yyvsp[0].standard)->name.find(".") == (yyvsp[0].standard)->name.npos){
	 			auto t = new IntegerExp(); 
	 			t->line = (yyvsp[0].standard)->line; 
	 			t->val = atoi((yyvsp[0].standard)->name.c_str());
	 			(yyval.pExp) = t;	 			
	 		}
	 		else{
	 			auto t = new FloatExp(); 
	 			t->line = (yyvsp[0].standard)->line; 
	 			t->val = atof((yyvsp[0].standard)->name.c_str());
	 			(yyval.pExp) = t;	 
	 		}

	 	}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 424 "parser.y" /* yacc.c:1646  */
    {auto t = new StringExp(); t->line = (yyvsp[0].standard)->line; t->str = (yyvsp[0].standard)->name; (yyval.pExp) = t;}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 425 "parser.y" /* yacc.c:1646  */
    {auto t = new VarargExp(); t->line = (yyvsp[0].standard)->line; (yyval.pExp) = t;}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 426 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pFuncDefExp);}
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 427 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 428 "parser.y" /* yacc.c:1646  */
    {(yyval.pExp) = (yyvsp[0].pExp);}
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2507 "y.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 431 "parser.y" /* yacc.c:1906  */


#include "lex.yy.c"
#include "showast.cpp"

extern FILE *yyin;

int main(int argc, char *argv[]){
	yyin = stdin;

	yyparse();

	showast(finalBlock, "");
	
	return 0;
}
