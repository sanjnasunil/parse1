/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     NUMBER = 260,
     PLUS = 261,
     MINUS = 262,
     TIMES = 263,
     DIVIDE = 264,
     ASSIGN = 265,
     EQ = 266,
     NE = 267,
     LT = 268,
     LE = 269,
     GE = 270,
     GT = 271,
     POINT = 272,
     DOT = 273,
     AND = 274,
     OR = 275,
     NOT = 276,
     DIV = 277,
     MOD = 278,
     IN = 279,
     COMMA = 280,
     SEMICOLON = 281,
     COLON = 282,
     LPAREN = 283,
     RPAREN = 284,
     LBRACKET = 285,
     RBRACKET = 286,
     DOTDOT = 287,
     ARRAY = 288,
     BEGINBEGIN = 289,
     CASE = 290,
     CONST = 291,
     DO = 292,
     DOWNTO = 293,
     ELSE = 294,
     END = 295,
     FILEFILE = 296,
     FOR = 297,
     FUNCTION = 298,
     GOTO = 299,
     IF = 300,
     LABEL = 301,
     NIL = 302,
     OF = 303,
     PACKED = 304,
     PROCEDURE = 305,
     PROGRAM = 306,
     RECORD = 307,
     REPEAT = 308,
     SET = 309,
     THEN = 310,
     TO = 311,
     TYPE = 312,
     UNTIL = 313,
     VAR = 314,
     WHILE = 315,
     WITH = 316
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING 259
#define NUMBER 260
#define PLUS 261
#define MINUS 262
#define TIMES 263
#define DIVIDE 264
#define ASSIGN 265
#define EQ 266
#define NE 267
#define LT 268
#define LE 269
#define GE 270
#define GT 271
#define POINT 272
#define DOT 273
#define AND 274
#define OR 275
#define NOT 276
#define DIV 277
#define MOD 278
#define IN 279
#define COMMA 280
#define SEMICOLON 281
#define COLON 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define DOTDOT 287
#define ARRAY 288
#define BEGINBEGIN 289
#define CASE 290
#define CONST 291
#define DO 292
#define DOWNTO 293
#define ELSE 294
#define END 295
#define FILEFILE 296
#define FOR 297
#define FUNCTION 298
#define GOTO 299
#define IF 300
#define LABEL 301
#define NIL 302
#define OF 303
#define PACKED 304
#define PROCEDURE 305
#define PROGRAM 306
#define RECORD 307
#define REPEAT 308
#define SET 309
#define THEN 310
#define TO 311
#define TYPE 312
#define UNTIL 313
#define VAR 314
#define WHILE 315
#define WITH 316




/* Copy the first part of user declarations.  */
#line 1 "parse.y"
     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"

        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 290 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    12,    14,    16,    18,    20,    22,    24,
      26,    29,    31,    33,    36,    38,    42,    43,    45,    47,
      51,    55,    57,    61,    63,    70,    74,    77,    81,    83,
      87,    89,    93,    95,   100,   104,   107,   109,   111,   113,
     117,   120,   125,   127,   129,   131,   133,   135,   139,   141,
     143,   145,   147,   150,   152,   156,   158,   160,   162,   164,
     166,   168,   170,   174,   176,   180,   183,   187,   189,   193,
     197,   201,   208,   213,   217,   219,   224,   229,   238,   241,
     243,   247,   249,   253,   255,   259,   261,   265,   267
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      63,     0,    -1,    51,     3,    28,    67,    29,    26,    85,
      18,    -1,     3,    -1,     5,    -1,    47,    -1,     4,    -1,
       6,    -1,     7,    -1,    65,    -1,    65,     3,    -1,     3,
      -1,     5,    -1,    65,     5,    -1,     4,    -1,     3,    25,
       3,    -1,    -1,     3,    -1,     3,    -1,    28,    67,    29,
      -1,    66,    32,    66,    -1,    68,    -1,    68,    25,    69,
      -1,    68,    -1,    33,    30,    69,    31,    48,    70,    -1,
      52,    72,    40,    -1,    17,     3,    -1,    67,    27,    70,
      -1,    71,    -1,    71,    26,    72,    -1,    82,    -1,    82,
      25,    73,    -1,     3,    -1,    74,    30,    73,    31,    -1,
      74,    18,     3,    -1,    74,    17,    -1,    64,    -1,    74,
      -1,    76,    -1,    28,    82,    29,    -1,    21,    75,    -1,
       3,    28,    73,    29,    -1,     8,    -1,     9,    -1,    22,
      -1,    23,    -1,    19,    -1,    78,    77,    75,    -1,    75,
      -1,     6,    -1,     7,    -1,    20,    -1,    65,    78,    -1,
      78,    -1,    80,    79,    78,    -1,    11,    -1,    13,    -1,
      16,    -1,    12,    -1,    14,    -1,    15,    -1,    24,    -1,
      82,    81,    80,    -1,    80,    -1,    67,    27,    70,    -1,
      83,    26,    -1,    59,    84,    86,    -1,    86,    -1,    34,
      88,    89,    -1,     5,    27,    88,    -1,    34,    88,    89,
      -1,    45,    82,    55,    88,    39,    88,    -1,    45,    82,
      55,    88,    -1,    74,    10,    82,    -1,    76,    -1,    60,
      82,    37,    88,    -1,    53,    88,    58,    82,    -1,    42,
       3,    10,    82,    56,    82,    37,    88,    -1,    44,     5,
      -1,    87,    -1,    26,    88,    89,    -1,    40,    -1,    90,
       6,    78,    -1,    78,    -1,    78,     8,    75,    -1,    75,
      -1,    28,    90,    29,    -1,     3,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    80,    80,    83,    83,    83,    83,    85,    85,    87,
      87,    87,    87,    87,    87,    89,    89,    89,    91,    92,
      93,    95,    96,    98,    99,   100,   101,   103,   105,   106,
     108,   109,   111,   112,   113,   114,   116,   117,   118,   119,
     120,   122,   124,   124,   124,   124,   124,   126,   127,   129,
     129,   129,   131,   131,   132,   134,   134,   134,   134,   134,
     134,   134,   136,   137,   159,   162,   164,   165,   167,   172,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     189,   190,   195,   196,   198,   199,   201,   202,   203
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "ASSIGN", "EQ", "NE", "LT", "LE", "GE", "GT",
  "POINT", "DOT", "AND", "OR", "NOT", "DIV", "MOD", "IN", "COMMA",
  "SEMICOLON", "COLON", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "DOTDOT", "ARRAY", "BEGINBEGIN", "CASE", "CONST", "DO", "DOWNTO", "ELSE",
  "END", "FILEFILE", "FOR", "FUNCTION", "GOTO", "IF", "LABEL", "NIL", "OF",
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "THEN",
  "TO", "TYPE", "UNTIL", "VAR", "WHILE", "WITH", "$accept", "program",
  "unsigned_constant", "sign", "constant", "id_list", "simple_type",
  "simple_type_list", "type", "fields", "field_list", "expr_list",
  "variable", "factor", "funcall", "times_op", "term", "plus_op",
  "simple_expression", "compare_op", "expression", "vdef", "vdef_list",
  "vblock", "block", "label", "statement", "endpart", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    68,    68,
      68,    69,    69,    70,    70,    70,    70,    71,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    75,    75,
      75,    76,    77,    77,    77,    77,    77,    78,    78,    79,
      79,    79,    80,    80,    80,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    83,    84,    85,    85,    86,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      89,    89,    90,    90,    78,    78,    75,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     2,     1,     3,     0,     1,     1,     3,
       3,     1,     3,     1,     6,     3,     2,     3,     1,     3,
       1,     3,     1,     4,     3,     2,     1,     1,     1,     3,
       2,     4,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     2,     3,     1,     3,     3,
       3,     6,     4,     3,     1,     4,     4,     8,     2,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    16,    17,     0,     0,     0,
      15,     0,     0,    16,     0,    67,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    79,     0,     0,     0,
       0,     2,     0,     0,     0,     0,    78,     3,     6,     4,
       7,     8,     0,     0,     5,    36,     0,    37,    48,    38,
      53,    63,     0,     0,     0,     0,    35,     0,     0,     0,
      81,    68,     0,    65,    66,     0,    30,    69,    70,     0,
      40,    53,     0,     0,    52,     0,    43,    46,    44,    45,
       0,    49,    50,    51,     0,    55,    58,    56,    59,    60,
      57,    61,     0,     0,     0,     0,    73,    34,     0,     0,
      18,    14,    12,     0,    16,     0,    16,     9,     0,    23,
      64,    41,     0,     0,    39,     0,    86,    84,    47,    54,
      72,    62,    76,    75,    33,    80,    26,     0,     0,     0,
      28,     0,    10,    13,     0,    31,     0,    82,     0,    19,
      21,     0,     0,    16,    25,    11,    20,     0,    71,     0,
       0,    27,    29,     0,    22,     0,    77,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    45,    46,   108,   129,   109,   141,   110,   130,
     131,    65,    47,    48,    49,    80,    50,    84,    51,    93,
      66,    29,    30,    14,    15,    26,    27,    61,    73
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int16 yypact[] =
{
     -36,    22,    44,    17,  -111,    51,    38,    35,    64,    43,
    -111,   -21,    56,    51,    53,  -111,    45,    47,    56,    69,
      73,   115,    56,   115,    93,  -111,  -111,    -3,    60,    62,
      55,  -111,   115,    56,    -3,    92,  -111,   195,  -111,  -111,
    -111,  -111,    30,   115,  -111,  -111,    30,   154,  -111,  -111,
     151,    36,   133,    46,   139,   115,  -111,   105,   115,    56,
    -111,  -111,    24,  -111,  -111,    84,   186,  -111,  -111,   115,
    -111,   151,   167,    20,   151,    30,  -111,  -111,  -111,  -111,
      30,  -111,  -111,  -111,    30,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,    56,   115,   115,    56,   192,  -111,    83,    -3,
      96,  -111,  -111,   112,    51,    94,    51,    57,    97,  -111,
    -111,  -111,   115,    81,  -111,    30,  -111,  -111,  -111,   151,
      91,    36,   192,  -111,  -111,  -111,  -111,   109,   128,   131,
     113,   121,  -111,  -111,   214,  -111,   115,   151,    56,  -111,
     150,   155,    24,    51,  -111,  -111,  -111,   153,  -111,   128,
     137,  -111,  -111,    56,  -111,    24,  -111,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,   -43,    58,     3,  -110,    40,  -102,  -111,
      50,   -46,   -12,   -10,   -11,  -111,   -29,  -111,   101,  -111,
     -19,  -111,  -111,  -111,   157,  -111,   -13,   -31,  -111
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -33
static const yytype_int16 yytable[] =
{
      24,    25,    52,    68,    54,    34,    24,    25,     7,    53,
      24,    25,    98,    12,    71,     1,    28,    74,   140,   107,
      67,    24,    25,    59,    72,     3,   115,   100,   101,   102,
      40,    41,    70,    37,    38,    39,    96,    60,    13,   140,
     151,   103,    81,    82,     4,     5,    99,    24,    25,   116,
     113,    42,   104,   157,     6,   119,    83,   105,    43,    16,
     132,    17,   133,     8,     9,   117,   135,    10,   125,    11,
     118,    31,    35,    32,    33,   122,   106,    44,    36,   120,
      24,    25,   123,    24,    25,   107,   137,    62,    63,    12,
      18,   107,    85,    86,    87,    88,    89,    90,    19,   107,
      20,    21,    69,    55,    94,    91,   107,   127,    97,    22,
      56,    57,   107,   111,   124,   126,    23,   147,    37,    38,
      39,    40,    41,    58,   128,   148,    24,    25,   -11,   134,
     138,   100,   101,   102,    40,    41,    42,   136,   139,   143,
     156,    24,    25,    43,    85,    86,    87,    88,    89,    90,
      85,    86,    87,    88,    89,    90,   104,    91,   142,    75,
      76,   144,    44,    91,    85,    86,    87,    88,    89,    90,
      77,    56,    57,    78,    79,   149,    95,    91,    85,    86,
      87,    88,    89,    90,    58,   155,   150,    64,    92,   154,
     153,    91,   146,   152,   121,     0,   114,    85,    86,    87,
      88,    89,    90,    85,    86,    87,    88,    89,    90,     0,
      91,   112,   -32,   -32,     0,     0,    91,   145,   101,   102,
      40,    41,     0,    32,     0,   -32
};

static const yytype_int16 yycheck[] =
{
      12,    12,    21,    34,    23,    18,    18,    18,     5,    22,
      22,    22,    58,    34,    43,    51,    13,    46,   128,    62,
      33,    33,    33,    26,    43,     3,     6,     3,     4,     5,
       6,     7,    42,     3,     4,     5,    55,    40,    59,   149,
     142,    17,     6,     7,     0,    28,    59,    59,    59,    29,
      69,    21,    28,   155,     3,    84,    20,    33,    28,     3,
       3,     5,     5,    25,    29,    75,   112,     3,    99,    26,
      80,    18,     3,    28,    27,    94,    52,    47,     5,    92,
      92,    92,    95,    95,    95,   128,   115,    27,    26,    34,
      34,   134,    11,    12,    13,    14,    15,    16,    42,   142,
      44,    45,    10,    10,    58,    24,   149,   104,     3,    53,
      17,    18,   155,    29,    31,     3,    60,   136,     3,     4,
       5,     6,     7,    30,    30,   138,   138,   138,    32,    32,
      39,     3,     4,     5,     6,     7,    21,    56,    29,    26,
     153,   153,   153,    28,    11,    12,    13,    14,    15,    16,
      11,    12,    13,    14,    15,    16,    28,    24,    27,     8,
       9,    40,    47,    24,    11,    12,    13,    14,    15,    16,
      19,    17,    18,    22,    23,    25,    37,    24,    11,    12,
      13,    14,    15,    16,    30,    48,    31,    30,    55,   149,
      37,    24,   134,   143,    93,    -1,    29,    11,    12,    13,
      14,    15,    16,    11,    12,    13,    14,    15,    16,    -1,
      24,    25,    17,    18,    -1,    -1,    24,     3,     4,     5,
       6,     7,    -1,    28,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    63,     3,     0,    28,     3,    67,    25,    29,
       3,    26,    34,    59,    85,    86,     3,     5,    34,    42,
      44,    45,    53,    60,    74,    76,    87,    88,    67,    83,
      84,    18,    28,    27,    88,     3,     5,     3,     4,     5,
       6,     7,    21,    28,    47,    64,    65,    74,    75,    76,
      78,    80,    82,    88,    82,    10,    17,    18,    30,    26,
      40,    89,    27,    26,    86,    73,    82,    88,    89,    10,
      75,    78,    82,    90,    78,     8,     9,    19,    22,    23,
      77,     6,     7,    20,    79,    11,    12,    13,    14,    15,
      16,    24,    55,    81,    58,    37,    82,     3,    73,    88,
       3,     4,     5,    17,    28,    33,    52,    65,    66,    68,
      70,    29,    25,    82,    29,     6,    29,    75,    75,    78,
      88,    80,    82,    88,    31,    89,     3,    67,    30,    67,
      71,    72,     3,     5,    32,    73,    56,    78,    39,    29,
      68,    69,    27,    26,    40,     3,    66,    82,    88,    25,
      31,    70,    72,    37,    69,    48,    88,    70
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 80 "parse.y"
    {parseresult = makeprogram((yyvsp[(2) - (8)]), (yyvsp[(4) - (8)]), (yyvsp[(7) - (8)])); }
    break;

  case 15:
#line 89 "parse.y"
    {(yyval) = cons((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 17:
#line 89 "parse.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 18:
#line 91 "parse.y"
    { (yyval) = findtype((yyvsp[(1) - (1)])); }
    break;

  case 41:
#line 122 "parse.y"
    {(yyval) = makefuncall((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));}
    break;

  case 63:
#line 137 "parse.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 64:
#line 159 "parse.y"
    {instvars((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 66:
#line 164 "parse.y"
    { (yyval) = (yyvsp[(3) - (3)]) ; }
    break;

  case 68:
#line 167 "parse.y"
    {(yyval) = cons((yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 70:
#line 174 "parse.y"
    {(yyval) = makeprogn((yyvsp[(1) - (3)]), cons((yyvsp[(2) - (3)]),(yyvsp[(3) - (3)])));}
    break;

  case 73:
#line 177 "parse.y"
    {(yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 77:
#line 181 "parse.y"
    {(yyval) = makefor(1,(yyvsp[(1) - (8)]), binop((yyvsp[(3) - (8)]), (yyvsp[(2) - (8)]), (yyvsp[(4) - (8)])),(yyvsp[(5) - (8)]),(yyvsp[(6) - (8)]),(yyvsp[(7) - (8)]), (yyvsp[(8) - (8)]));}
    break;

  case 80:
#line 189 "parse.y"
    { (yyval) = cons((yyvsp[(2) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 81:
#line 190 "parse.y"
    { (yyval) = NULL; }
    break;

  case 82:
#line 195 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 84:
#line 198 "parse.y"
    { (yyval) = binop((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); }
    break;

  case 86:
#line 201 "parse.y"
    { (yyval) = (yyvsp[(2) - (3)]); }
    break;


/* Line 1267 of yacc.c.  */
#line 1728 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 206 "parse.y"


/* You should add your own debugging flags below, and add debugging
   printouts to your programs.

   You will want to change DEBUG to turn off printouts once things
   are working.
  */

#define DEBUG        31             /* set bits here for debugging, 0 = off  */
#define DB_CONS       1             /* bit to trace cons */
#define DB_BINOP      2             /* bit to trace binop */
#define DB_MAKEIF     4             /* bit to trace makeif */
#define DB_MAKEPROGN  8             /* bit to trace makeprogn */
#define DB_PARSERES  16             /* bit to trace parseresult */

 int labelnumber = 0;  /* sequential counter for internal label numbers */

   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */


TOKEN makeprogram (TOKEN name, TOKEN args, TOKEN statements)
{
TOKEN optok = talloc();
TOKEN argtok = talloc();
TOKEN statement_tok = talloc();

optok->tokentype = OPERATOR;
optok->whichval = PROGRAMOP;
optok-> operands = name;

argtok = makeprogn(argtok , args);
statement_tok = makeprogn(statement_tok , statements);
name -> link = argtok;
argtok -> link = statement_tok;
return optok;
}

TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args)
{

tok->tokentype = OPERATOR;
tok->whichval = FUNCALLOP;
tok->operands = fn;
fn->link = args;
return tok;

}

TOKEN copytok(TOKEN origtok)
{
  TOKEN newtok = talloc();
 *newtok = *origtok;
  newtok -> link = NULL;
  newtok -> operands = NULL;

}

TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr,
              TOKEN tokc, TOKEN statement)
{


TOKEN answer = talloc();
TOKEN extra_tok = talloc();
TOKEN extra_link = talloc();
TOKEN label_tok = talloc();
TOKEN if_tok = talloc();
TOKEN func_tok = talloc();
TOKEN less_than = talloc();
TOKEN less_than_link = talloc();
TOKEN expres = talloc(); 
TOKEN numtok = talloc();
TOKEN assign_tok = talloc();
TOKEN expres_cpy = talloc();
TOKEN plus_op = talloc();
TOKEN expres_cpy2 = talloc();
TOKEN numtok2 = talloc(); 
TOKEN goto_tok = talloc();
TOKEN func_tokcpy = talloc(); 

// function call
 func_tok = makeprogn(func_tok, statement);

// num label token
  numtok->tokentype = NUMBERTOK;
  numtok->basicdt = INTEGER;
  numtok->intval = 0;

  numtok2->tokentype = NUMBERTOK;
  numtok2->basicdt = INTEGER;
  numtok2->intval = 1;

// variable i 
  expres = copytok(asg->operands);

// less than token 
 less_than->tokentype = OPERATOR;
 less_than -> whichval = LEOP;
 less_than->operands = expres;
 
 less_than-> link = func_tok;

 // func_tok->operands = statement;
 expres -> link = endexpr;
 endexpr->link = NULL;

// label token
  label_tok->tokentype = OPERATOR;
  label_tok -> whichval = LABELOP;
  label_tok->operands = numtok;
  
// if token
  if_tok->tokentype = OPERATOR;
  if_tok->whichval = IFOP;
  if_tok->operands = less_than; 


// increment token
  expres_cpy = copytok(expres);
  assign_tok->tokentype = OPERATOR;
  assign_tok -> whichval = ASSIGNOP;
  assign_tok->operands = expres_cpy;
//  statement->link = assign_tok;

func_tokcpy = func_tok->operands;

  plus_op->tokentype = OPERATOR;
  plus_op -> whichval = PLUSOP;
  plus_op->operands = expres_cpy2;
  expres_cpy ->link = plus_op;
  expres_cpy2->link = numtok2; 

  goto_tok->tokentype = OPERATOR;
  goto_tok->whichval = GOTOOP;
  goto_tok->operands = numtok;

 assign_tok->link = goto_tok;

answer = makeprogn(answer, asg);
extra_tok =answer->operands;
extra_tok->link = label_tok;
label_tok->link = if_tok;










 
  /*  TOKEN assign_tok = talloc();
  TOKEN red_cond = talloc();
  TOKEN condtok = talloc();  
  TOKEN numtok = talloc();
  TOKEN iftok = talloc();
  TOKEN goto_tok = talloc();
  TOKEN inc_tok = talloc();  

  // num label token
  numtok->tokentype = NUMBERTOK;
  numtok->basicdt = INTEGER;
  numtok->intval = 0;

  inc_tok->tokentype = NUMBERTOK;
  inc_tok->basicdt = INTEGER;
  inc_tok->intval = 1;

  // label token
  tok->tokentype = OPERATOR;
  tok -> whichval = LABELOP;
  tok->operands = numtok;

  // conditional token
  condtok->tokentype = OPERATOR;
  condtok -> whichval = LEOP;
  

   // if token
  iftok->tokentype = OPERATOR;
  iftok->whichval = IFOP;
  
  iftok->operands =  binop(condtok,copytok(asg->operands),endexpr);


  // assignment and label link
  asg->link = tok;
  
   // link label to if
   tok->link = iftok;
  

 
  // if tokens operand is condtok 
  condtok->link = statement;
 

  // increment token
  assign_tok->tokentype = OPERATOR;
  assign_tok -> whichval = ASSIGNOP;
  assign_tok->operands = asg->operands;
  (copytok(assign_tok->operands))->link =  binop(PLUSOP, copytok(asg->operands),sign); 
  
  copytok((statement->operands))->link = assign_tok;   

  goto_tok->tokentype = OPERATOR;
  goto_tok->whichval = GOTOOP;
  goto_tok->operands = numtok;
   assign_tok->link = goto_tok;
   return asg; */

return answer;

}



TOKEN findtype (TOKEN tok)
{
 SYMBOL symbtype = searchst(tok->stringval);
 tok->symtype = symbtype;
 return tok;

}

void instconst(TOKEN idtok, TOKEN consttok)
{
printf("IN INSTCONST");
SYMBOL varsymb = searchst(idtok->stringval );
varsymb->kind = CONSTSYM;
varsymb->basicdt = consttok->basicdt;
varsymb->size = sizeof(varsymb->basicdt);
varsymb->constval.intnum = consttok -> intval;
consttok -> tokentype = NUMBERTOK;

}

/* install variables in symbol table */
void instvars(TOKEN idlist, TOKEN typetok)
{
 SYMBOL sym, typesym; int align;
  typesym = typetok->symtype;
  align = alignsize(typesym);
  while ( idlist != NULL ) /* for each id */
  { 
    sym = insertsym(idlist->stringval);
    sym->kind = VARSYM;
    sym->offset = /* "next" */
    wordaddress(blockoffs[blocknumber],
    align);
    sym->size = typesym->size;
    blockoffs[blocknumber] = /* "next" */
    sym->offset + sym->size;
    sym->datatype = typesym;
   sym->basicdt = typesym->basicdt;
   idlist = idlist->link;
};
}

TOKEN findid(TOKEN tok) { /* the ID token */
SYMBOL sym, typ;
sym = searchst(tok->stringval);
tok->symentry = sym;
typ = sym->datatype;
tok->symtype = typ;
if ( typ->kind == BASICTYPE ||
typ->kind == POINTERSYM)
tok->basicdt = typ->basicdt;
return tok;
}


TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");
         dbugprinttok(item);
         dbugprinttok(list);
       };
    return item;
  }

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs)        /* reduce binary operator */
  { op->operands = lhs;          /* link operands to operator       */
    lhs->link = rhs;             /* link second operand to first    */
    rhs->link = NULL;            /* terminate operand list          */
    if (DEBUG & DB_BINOP)
       { printf("binop\n");
         dbugprinttok(op);
         dbugprinttok(lhs);
         dbugprinttok(rhs);
       };
    return op;
  }

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart)
  {  tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
     return tok;
   }

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
     return tok;
   }

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void)          /*  */
  { int res;
    initsyms();
    res = yyparse();
//    printst();       /* to shorten, change to:  printstlevel(1);  */
    printf("yyparse result = %8d\n", res);
    if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
    ppexpr(parseresult);           /* Pretty-print the result tree */
    /* uncomment following to call code generator. */
     /* 
    gencode(parseresult, blockoffs[blocknumber], labelnumber);
 */
  }


