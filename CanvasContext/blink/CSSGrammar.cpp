/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse         cssyyparse
#define yylex           cssyylex
#define yyerror         cssyyerror
#define yylval          cssyylval
#define yychar          cssyychar
#define yydebug         cssyydebug
#define yynerrs         cssyynerrs


/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */


/*
 *  Copyright (C) 2002-2003 Lars Knoll (knoll@kde.org)
 *  Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013 Apple Inc. All rights reserved.
 *  Copyright (C) 2006 Alexey Proskuryakov (ap@nypop.com)
 *  Copyright (C) 2008 Eric Seidel <eric@webkit.org>
 *  Copyright (C) 2012 Intel Corporation. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "config.h"

#include "CSSPropertyNames.h"
#include "HTMLNames.h"
#include "css/CSSKeyframeRule.h"
#include "css/CSSKeyframesRule.h"
#include "css/BisonCSSParser.h"
#include "css/CSSParserMode.h"
#include "css/CSSPrimitiveValue.h"
#include "css/CSSSelector.h"
#include "css/CSSSelectorList.h"
//#include "css/MediaQueryExp.h"
//#include "css/StyleRule.h"
//#include "css/StyleSheetContents.h"
#include "wtf/FastMalloc.h"
#include <stdlib.h>
#include <string.h>

using namespace WebCore;
using namespace HTMLNames;

#define YYMALLOC fastMalloc
#define YYFREE fastFree

#define YYENABLE_NLS 0
#define YYLTYPE_IS_TRIVIAL 1
#define YYMAXDEPTH 10000
#define YYDEBUG 0

#if YYDEBUG > 0
#define YYPRINT(File,Type,Value) if (isCSSTokenAString(Type)) YYFPRINTF(File, "%s", String((Value).string).utf8().data())
#endif


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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_EOF = 0,
     LOWEST_PREC = 258,
     UNIMPORTANT_TOK = 259,
     WHITESPACE = 260,
     SGML_CD = 261,
     INCLUDES = 262,
     DASHMATCH = 263,
     BEGINSWITH = 264,
     ENDSWITH = 265,
     CONTAINS = 266,
     STRING = 267,
     IDENT = 268,
     NTH = 269,
     HEX = 270,
     IDSEL = 271,
     IMPORT_SYM = 272,
     PAGE_SYM = 273,
     MEDIA_SYM = 274,
     SUPPORTS_SYM = 275,
     FONT_FACE_SYM = 276,
     CHARSET_SYM = 277,
     NAMESPACE_SYM = 278,
     VIEWPORT_RULE_SYM = 279,
     INTERNAL_DECLS_SYM = 280,
     INTERNAL_MEDIALIST_SYM = 281,
     INTERNAL_RULE_SYM = 282,
     INTERNAL_SELECTOR_SYM = 283,
     INTERNAL_VALUE_SYM = 284,
     INTERNAL_KEYFRAME_RULE_SYM = 285,
     INTERNAL_KEYFRAME_KEY_LIST_SYM = 286,
     INTERNAL_SUPPORTS_CONDITION_SYM = 287,
     KEYFRAMES_SYM = 288,
     WEBKIT_KEYFRAMES_SYM = 289,
     TOPLEFTCORNER_SYM = 290,
     TOPLEFT_SYM = 291,
     TOPCENTER_SYM = 292,
     TOPRIGHT_SYM = 293,
     TOPRIGHTCORNER_SYM = 294,
     BOTTOMLEFTCORNER_SYM = 295,
     BOTTOMLEFT_SYM = 296,
     BOTTOMCENTER_SYM = 297,
     BOTTOMRIGHT_SYM = 298,
     BOTTOMRIGHTCORNER_SYM = 299,
     LEFTTOP_SYM = 300,
     LEFTMIDDLE_SYM = 301,
     LEFTBOTTOM_SYM = 302,
     RIGHTTOP_SYM = 303,
     RIGHTMIDDLE_SYM = 304,
     RIGHTBOTTOM_SYM = 305,
     ATKEYWORD = 306,
     IMPORTANT_SYM = 307,
     MEDIA_ONLY = 308,
     MEDIA_NOT = 309,
     MEDIA_AND = 310,
     MEDIA_OR = 311,
     SUPPORTS_NOT = 312,
     SUPPORTS_AND = 313,
     SUPPORTS_OR = 314,
     REMS = 315,
     CHS = 316,
     QEMS = 317,
     EMS = 318,
     EXS = 319,
     PXS = 320,
     CMS = 321,
     MMS = 322,
     INS = 323,
     PTS = 324,
     PCS = 325,
     DEGS = 326,
     RADS = 327,
     GRADS = 328,
     TURNS = 329,
     MSECS = 330,
     SECS = 331,
     HERTZ = 332,
     KHERTZ = 333,
     DIMEN = 334,
     INVALIDDIMEN = 335,
     PERCENTAGE = 336,
     FLOATTOKEN = 337,
     INTEGER = 338,
     VW = 339,
     VH = 340,
     VMIN = 341,
     VMAX = 342,
     DPPX = 343,
     DPI = 344,
     DPCM = 345,
     FR = 346,
     URI = 347,
     FUNCTION = 348,
     ANYFUNCTION = 349,
     CUEFUNCTION = 350,
     NOTFUNCTION = 351,
     DISTRIBUTEDFUNCTION = 352,
     CALCFUNCTION = 353,
     MINFUNCTION = 354,
     MAXFUNCTION = 355,
     HOSTFUNCTION = 356,
     ANCESTORFUNCTION = 357,
     UNICODERANGE = 358
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */

    bool boolean;
    char character;
    int integer;
    double number;
    CSSParserString string;

    //StyleRuleBase* rule;
    // The content of the two below HeapVectors are guaranteed to be kept alive by
    // the corresponding m_parsedRules and m_floatingMediaQueryExpList lists in BisonCSSParser.h.
    //WillBeHeapVector<RefPtrWillBeMember<StyleRuleBase> >* ruleList;
    //WillBeHeapVector<OwnPtrWillBeMember<MediaQueryExp> >* mediaQueryExpList;
    CSSParserSelector* selector;
    Vector<OwnPtr<CSSParserSelector> >* selectorList;
    CSSSelector::MarginBoxType marginBox;
    CSSSelector::Relation relation;
    //MediaQuerySet* mediaList;
    //MediaQuery* mediaQuery;
    //MediaQuery::Restrictor mediaQueryRestrictor;
    //MediaQueryExp* mediaQueryExp;
    CSSParserValue value;
    CSSParserValueList* valueList;
    StyleKeyframe* keyframe;
    Vector<RefPtr<StyleKeyframe> >* keyframeRuleList;
    float val;
    CSSPropertyID id;
    CSSParserLocation location;



/* Line 214 of yacc.c  */
} YYSTYPE;

# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */

/* Line 264 of yacc.c  */

static inline int cssyyerror(void*, const char*)
{
    return 1;
}

#if YYDEBUG > 0
static inline bool isCSSTokenAString(int yytype)
{
    switch (yytype) {
    case IDENT:
    case STRING:
    case NTH:
    case HEX:
    case IDSEL:
    case DIMEN:
    case INVALIDDIMEN:
    case URI:
    case FUNCTION:
    case ANYFUNCTION:
    case HOSTFUNCTION:
    case ANCESTORFUNCTION:
    case NOTFUNCTION:
    case CALCFUNCTION:
    case MINFUNCTION:
    case MAXFUNCTION:
    case UNICODERANGE:
        return true;
    default:
        return false;
    }
}
#endif

inline static CSSParserValue makeOperatorValue(int value)
{
    CSSParserValue v;
    v.id = CSSValueInvalid;
    v.unit = CSSParserValue::Operator;
    v.iValue = value;
    return v;
}

inline static CSSParserValue makeIdentValue(CSSParserString string)
{
    CSSParserValue v;
    v.id = cssValueKeywordID(string);
    v.unit = CSSPrimitiveValue::CSS_IDENT;
    v.string = string;
    return v;
}



/* Line 264 of yacc.c  */

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2339

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  124
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  143
/* YYNRULES -- Number of rules.  */
#define YYNRULES  387
/* YYNRULES -- Number of states.  */
#define YYNSTATES  737

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   358

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   122,     2,   123,     2,     2,
     113,   110,    20,   116,   114,   120,    18,   119,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    17,   112,
       2,   121,   118,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    19,     2,   111,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   115,    21,   109,   117,     2,     2,     2,
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
      15,    16,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    11,    13,    15,    17,    19,
      21,    23,    29,    35,    40,    45,    50,    56,    61,    66,
      68,    71,    72,    74,    75,    78,    81,    83,    85,    87,
      89,    91,    93,    95,    97,    98,   104,   107,   108,   112,
     114,   116,   118,   120,   122,   124,   126,   128,   130,   131,
     134,   137,   139,   142,   143,   147,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   169,   172,   173,   177,   184,
     191,   198,   199,   202,   204,   206,   207,   211,   218,   223,
     225,   231,   233,   239,   240,   243,   246,   249,   253,   255,
     260,   264,   265,   267,   269,   272,   274,   279,   285,   286,
     287,   289,   293,   302,   304,   315,   316,   317,   319,   321,
     323,   325,   329,   334,   339,   344,   349,   355,   357,   364,
     375,   386,   387,   391,   395,   405,   407,   409,   411,   414,
     415,   420,   426,   432,   435,   441,   444,   446,   449,   450,
     461,   464,   468,   471,   472,   474,   479,   480,   488,   490,
     492,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   516,   518,   520,   521,   530,   531,   540,   543,
     546,   549,   554,   556,   557,   559,   561,   563,   564,   565,
     566,   576,   577,   579,   586,   589,   591,   593,   596,   600,
     604,   606,   609,   612,   614,   617,   619,   622,   626,   629,
     631,   637,   639,   641,   643,   646,   648,   650,   652,   654,
     656,   659,   662,   667,   676,   682,   692,   696,   698,   700,
     702,   704,   706,   708,   710,   712,   715,   719,   724,   732,
     738,   745,   751,   758,   763,   770,   778,   785,   790,   797,
     802,   809,   814,   819,   826,   831,   836,   840,   841,   843,
     846,   848,   852,   857,   864,   873,   880,   885,   889,   893,
     896,   897,   900,   904,   908,   913,   918,   920,   924,   927,
     931,   934,   937,   940,   944,   947,   950,   953,   957,   960,
     963,   966,   969,   972,   975,   978,   981,   984,   986,   988,
     990,   992,   994,   996,   998,  1000,  1002,  1004,  1006,  1008,
    1010,  1012,  1014,  1016,  1018,  1020,  1022,  1024,  1026,  1028,
    1030,  1032,  1034,  1036,  1038,  1040,  1042,  1044,  1049,  1053,
    1058,  1060,  1063,  1067,  1071,  1075,  1079,  1080,  1082,  1088,
    1093,  1095,  1099,  1103,  1105,  1108,  1114,  1120,  1125,  1127,
    1129,  1134,  1139,  1141,  1143,  1147,  1151,  1154,  1157,  1160,
    1164,  1168,  1174,  1178,  1181,  1184,  1188,  1194,  1198,  1202,
    1206,  1211,  1214,  1217,  1218,  1222,  1226,  1230,  1232,  1234,
    1236,  1238,  1240,  1242,  1244,  1246,  1248,  1250,  1251,  1252,
    1253,  1256,  1259,  1262,  1265,  1266,  1269,  1272
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     125,     0,    -1,   141,   136,   142,    -1,   129,    -1,   126,
      -1,   132,    -1,   130,    -1,   131,    -1,   127,    -1,   128,
      -1,   133,    -1,    32,   135,   143,   135,     0,    -1,    35,
     135,   188,   135,     0,    -1,    36,   135,   189,     0,    -1,
      30,   206,   229,     0,    -1,    34,   135,   236,     0,    -1,
      31,   135,   264,   164,     0,    -1,    33,   135,   212,     0,
      -1,    37,   135,   176,     0,    -1,     5,    -1,   134,     5,
      -1,    -1,   134,    -1,    -1,   136,     6,    -1,   136,     5,
      -1,   109,    -1,     0,    -1,   110,    -1,     0,    -1,   111,
      -1,     0,    -1,   112,    -1,     0,    -1,    -1,    27,   135,
      12,   135,   140,    -1,    27,   252,    -1,    -1,   142,   145,
     136,    -1,   210,    -1,   171,    -1,   193,    -1,   200,    -1,
     184,    -1,   154,    -1,   153,    -1,   173,    -1,   202,    -1,
      -1,   144,   143,    -1,   144,   256,    -1,   147,    -1,   147,
     148,    -1,    -1,   147,   150,   136,    -1,   144,   257,    -1,
     210,    -1,   193,    -1,   200,    -1,   171,    -1,   184,    -1,
     173,    -1,   202,    -1,   154,    -1,   144,   149,    -1,   144,
     256,    -1,    -1,   151,    22,   135,    -1,   152,   156,   135,
     264,   164,   140,    -1,   152,   156,   135,   264,   164,   259,
      -1,    28,   135,   155,   156,   135,   140,    -1,    -1,    13,
     135,    -1,    12,    -1,    97,    -1,    -1,    17,   135,   236,
      -1,   113,   135,    13,   135,   157,   138,    -1,   113,     1,
     265,   138,    -1,   158,    -1,   159,   135,    60,   135,   158,
      -1,   135,    -1,   135,    60,   135,   159,   135,    -1,    -1,
      58,   135,    -1,    59,   135,    -1,   159,   135,    -1,   161,
     172,   160,    -1,   162,    -1,   162,     1,   263,   266,    -1,
       1,   263,   266,    -1,    -1,   165,    -1,   163,    -1,   166,
     163,    -1,   166,    -1,   163,   114,   135,   264,    -1,   166,
     163,   114,   135,   264,    -1,    -1,    -1,   135,    -1,   168,
      24,   135,    -1,   170,   164,   208,   115,   167,   135,   146,
     137,    -1,    13,    -1,   174,    25,   135,   176,   175,   115,
     167,   135,   146,   137,    -1,    -1,    -1,   180,    -1,   177,
      -1,   178,    -1,   179,    -1,    62,   135,   180,    -1,   180,
      63,   135,   180,    -1,   178,    63,   135,   180,    -1,   180,
      64,   135,   180,    -1,   179,    64,   135,   180,    -1,   113,
     135,   176,   138,   135,    -1,   181,    -1,   113,     1,   263,
     265,   138,   135,    -1,   113,   135,    13,   135,    17,   135,
     236,   233,   138,   135,    -1,   113,   135,    13,   135,    17,
     135,     1,   265,   138,   135,    -1,    -1,   182,    38,   135,
      -1,   182,    39,   135,    -1,   183,   185,   169,   115,   167,
     135,   264,   186,   137,    -1,    13,    -1,    12,    -1,   187,
      -1,   187,   191,    -1,    -1,   187,   188,   135,   264,    -1,
     187,   191,   259,   135,   264,    -1,   189,   115,   135,   229,
     137,    -1,   190,   135,    -1,   189,   114,   135,   190,   135,
      -1,   204,    86,    -1,    13,    -1,     1,   266,    -1,    -1,
     192,    23,   135,   194,   208,   115,   167,   206,   195,   137,
      -1,    13,   135,    -1,    13,   226,   135,    -1,   226,   135,
      -1,    -1,   229,    -1,   195,   196,   135,   229,    -1,    -1,
     198,   197,   135,   115,   135,   229,   137,    -1,    40,    -1,
      41,    -1,    42,    -1,    43,    -1,    44,    -1,    45,    -1,
      46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,    -1,
      51,    -1,    52,    -1,    53,    -1,    54,    -1,    55,    -1,
      -1,   199,    26,   169,   115,   167,   206,   229,   137,    -1,
      -1,   201,    29,   169,   115,   167,   206,   229,   137,    -1,
     116,   135,    -1,   117,   135,    -1,   118,   135,    -1,   119,
      13,   119,   135,    -1,   205,    -1,    -1,   120,    -1,   116,
      -1,   135,    -1,    -1,    -1,    -1,   207,   212,   209,   208,
     115,   167,   206,   229,   137,    -1,    -1,   214,    -1,   212,
     209,   114,   135,   211,   214,    -1,   203,   214,    -1,   214,
      -1,   216,    -1,   214,     5,    -1,   214,     5,   216,    -1,
     214,   203,   216,    -1,    21,    -1,    20,    21,    -1,    13,
      21,    -1,   218,    -1,   218,   219,    -1,   219,    -1,   215,
     218,    -1,   215,   218,   219,    -1,   215,   219,    -1,   216,
      -1,   217,   135,   114,   135,   216,    -1,    13,    -1,    20,
      -1,   220,    -1,   219,   220,    -1,    16,    -1,    15,    -1,
     221,    -1,   223,    -1,   227,    -1,    18,    13,    -1,    13,
     135,    -1,    19,   135,   222,   139,    -1,    19,   135,   222,
     224,   135,   225,   135,   139,    -1,    19,   135,   215,   222,
     139,    -1,    19,   135,   215,   222,   224,   135,   225,   135,
     139,    -1,    19,   228,   139,    -1,   121,    -1,     7,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    13,    -1,
      12,    -1,    17,    13,    -1,    17,   263,    13,    -1,    17,
      17,   263,    13,    -1,    17,    17,   100,   135,   217,   135,
     138,    -1,    17,    17,   100,   228,   138,    -1,    17,    17,
     102,   135,   213,   138,    -1,    17,    17,   102,   228,   138,
      -1,    17,    99,   135,   217,   135,   138,    -1,    17,    99,
     228,   138,    -1,    17,    98,   135,    14,   135,   138,    -1,
      17,    98,   135,   204,    88,   135,   138,    -1,    17,    98,
     135,    13,   135,   138,    -1,    17,    98,   228,   138,    -1,
      17,   101,   135,   216,   135,   138,    -1,    17,   101,   228,
     138,    -1,    17,   106,   135,   217,   135,   138,    -1,    17,
     106,   135,   138,    -1,    17,   106,   228,   138,    -1,    17,
     107,   135,   217,   135,   138,    -1,    17,   107,   135,   138,
      -1,    17,   107,   228,   138,    -1,     1,   263,   265,    -1,
      -1,   231,    -1,   230,   231,    -1,   230,    -1,   231,   112,
     135,    -1,   230,   231,   112,   135,    -1,   232,    17,   135,
     263,   236,   233,    -1,   232,    17,   135,   263,   236,   233,
       1,   265,    -1,   232,    17,   135,   263,     1,   265,    -1,
     232,     1,   263,   265,    -1,     1,   263,   265,    -1,   263,
      13,   135,    -1,    57,   135,    -1,    -1,    13,   135,    -1,
     234,    13,   135,    -1,   113,   135,   138,    -1,   113,   135,
     234,   138,    -1,   113,   135,   237,   138,    -1,   239,    -1,
     236,   238,   239,    -1,   236,   239,    -1,     1,   263,   265,
      -1,   119,   135,    -1,   114,   135,    -1,   240,   135,    -1,
     205,   240,   135,    -1,    12,   135,    -1,    13,   135,    -1,
      84,   135,    -1,   205,    84,   135,    -1,    97,   135,    -1,
     108,   135,    -1,    15,   135,    -1,   122,   135,    -1,   241,
     135,    -1,   248,   135,    -1,   250,   135,    -1,   123,   135,
      -1,   235,   135,    -1,    88,    -1,    87,    -1,    86,    -1,
      70,    -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,
      75,    -1,    76,    -1,    77,    -1,    78,    -1,    79,    -1,
      80,    -1,    81,    -1,    82,    -1,    83,    -1,    68,    -1,
      67,    -1,    69,    -1,    65,    -1,    66,    -1,    89,    -1,
      90,    -1,    91,    -1,    92,    -1,    93,    -1,    94,    -1,
      95,    -1,    96,    -1,    98,   135,   236,   138,    -1,    98,
     135,   138,    -1,    98,   135,   237,   138,    -1,   240,    -1,
     205,   240,    -1,   134,   116,   134,    -1,   134,   120,   134,
      -1,   244,    20,   135,    -1,   244,   119,   135,    -1,    -1,
       5,    -1,   113,   135,   246,   244,   138,    -1,   113,   135,
     237,   138,    -1,   242,    -1,   246,   243,   242,    -1,   246,
     243,   245,    -1,   245,    -1,   246,   244,    -1,   247,   114,
     135,   246,   244,    -1,   103,   135,   246,   244,   138,    -1,
     103,   135,   237,   138,    -1,   104,    -1,   105,    -1,   249,
     135,   247,   138,    -1,   249,   135,   237,   138,    -1,    56,
      -1,   198,    -1,   253,   258,   254,    -1,     1,   263,   266,
      -1,   258,   140,    -1,   258,   259,    -1,   183,   253,    -1,
     192,    23,   253,    -1,   199,    26,   253,    -1,   174,    25,
       1,   263,   266,    -1,   201,    29,   253,    -1,   152,   253,
      -1,    28,   253,    -1,   263,   251,   253,    -1,     1,   263,
     266,   258,   259,    -1,   255,   258,   112,    -1,   255,   258,
     259,    -1,   170,   164,   112,    -1,     1,   263,   266,   258,
      -1,   255,   258,    -1,   170,   164,    -1,    -1,   115,   265,
     137,    -1,    19,   265,   139,    -1,   262,   265,   138,    -1,
     113,    -1,    98,    -1,   103,    -1,   104,    -1,   105,    -1,
      99,    -1,   101,    -1,   100,    -1,   102,    -1,   106,    -1,
      -1,    -1,    -1,   265,     1,    -1,   265,   259,    -1,   265,
     260,    -1,   265,   261,    -1,    -1,   266,     1,    -1,   266,
     260,    -1,   266,   261,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   379,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   391,   397,   403,   409,   415,   425,   431,   438,   444,
     445,   449,   450,   453,   455,   456,   460,   461,   465,   466,
     470,   471,   475,   476,   479,   481,   486,   489,   491,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   510,   516,
     521,   528,   529,   533,   534,   540,   546,   547,   548,   549,
     550,   551,   552,   553,   557,   561,   568,   574,   581,   584,
     590,   597,   598,   602,   603,   607,   610,   616,   622,   628,
     632,   639,   642,   648,   651,   654,   660,   663,   670,   671,
     675,   682,   685,   689,   693,   697,   704,   708,   715,   721,
     727,   733,   736,   742,   746,   752,   759,   766,   767,   768,
     769,   773,   779,   782,   788,   791,   797,   800,   801,   808,
     822,   829,   835,   838,   844,   850,   851,   855,   856,   861,
     865,   869,   876,   882,   886,   893,   896,   908,   914,   920,
     934,   938,   943,   947,   954,   955,   959,   959,   967,   970,
     973,   976,   979,   982,   985,   988,   991,   994,   997,  1000,
    1003,  1006,  1009,  1012,  1018,  1024,  1031,  1038,  1046,  1047,
    1048,  1051,  1066,  1067,  1071,  1072,  1076,  1082,  1089,  1095,
    1101,  1107,  1112,  1117,  1124,  1131,  1135,  1136,  1137,  1146,
    1157,  1158,  1159,  1163,  1166,  1171,  1176,  1181,  1186,  1194,
    1198,  1205,  1210,  1217,  1218,  1224,  1231,  1242,  1243,  1244,
    1248,  1258,  1266,  1271,  1277,  1282,  1288,  1294,  1297,  1300,
    1303,  1306,  1309,  1315,  1316,  1320,  1333,  1346,  1361,  1370,
    1373,  1380,  1388,  1398,  1402,  1412,  1422,  1439,  1443,  1458,
    1461,  1472,  1481,  1484,  1495,  1504,  1510,  1513,  1514,  1515,
    1518,  1522,  1526,  1533,  1550,  1557,  1563,  1569,  1576,  1585,
    1586,  1590,  1594,  1601,  1604,  1607,  1613,  1617,  1622,  1629,
    1635,  1638,  1644,  1645,  1646,  1647,  1649,  1650,  1651,  1652,
    1653,  1654,  1656,  1657,  1658,  1659,  1662,  1666,  1667,  1668,
    1669,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,
    1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,  1691,  1692,
    1693,  1694,  1695,  1696,  1697,  1698,  1699,  1703,  1706,  1709,
    1715,  1716,  1720,  1723,  1726,  1729,  1734,  1736,  1740,  1745,
    1751,  1755,  1760,  1765,  1769,  1770,  1778,  1781,  1788,  1789,
    1793,  1796,  1802,  1803,  1807,  1811,  1817,  1818,  1822,  1823,
    1824,  1825,  1829,  1832,  1833,  1834,  1841,  1844,  1845,  1846,
    1850,  1853,  1854,  1858,  1864,  1870,  1874,  1877,  1877,  1877,
    1877,  1877,  1877,  1877,  1877,  1877,  1877,  1880,  1885,  1890,
    1892,  1893,  1894,  1895,  1898,  1900,  1901,  1902
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "TOKEN_EOF", "error", "$undefined", "LOWEST_PREC", "UNIMPORTANT_TOK",
  "WHITESPACE", "SGML_CD", "INCLUDES", "DASHMATCH", "BEGINSWITH",
  "ENDSWITH", "CONTAINS", "STRING", "IDENT", "NTH", "HEX", "IDSEL", "':'",
  "'.'", "'['", "'*'", "'|'", "IMPORT_SYM", "PAGE_SYM", "MEDIA_SYM",
  "SUPPORTS_SYM", "FONT_FACE_SYM", "CHARSET_SYM", "NAMESPACE_SYM",
  "VIEWPORT_RULE_SYM", "INTERNAL_DECLS_SYM", "INTERNAL_MEDIALIST_SYM",
  "INTERNAL_RULE_SYM", "INTERNAL_SELECTOR_SYM", "INTERNAL_VALUE_SYM",
  "INTERNAL_KEYFRAME_RULE_SYM", "INTERNAL_KEYFRAME_KEY_LIST_SYM",
  "INTERNAL_SUPPORTS_CONDITION_SYM", "KEYFRAMES_SYM",
  "WEBKIT_KEYFRAMES_SYM", "TOPLEFTCORNER_SYM", "TOPLEFT_SYM",
  "TOPCENTER_SYM", "TOPRIGHT_SYM", "TOPRIGHTCORNER_SYM",
  "BOTTOMLEFTCORNER_SYM", "BOTTOMLEFT_SYM", "BOTTOMCENTER_SYM",
  "BOTTOMRIGHT_SYM", "BOTTOMRIGHTCORNER_SYM", "LEFTTOP_SYM",
  "LEFTMIDDLE_SYM", "LEFTBOTTOM_SYM", "RIGHTTOP_SYM", "RIGHTMIDDLE_SYM",
  "RIGHTBOTTOM_SYM", "ATKEYWORD", "IMPORTANT_SYM", "MEDIA_ONLY",
  "MEDIA_NOT", "MEDIA_AND", "MEDIA_OR", "SUPPORTS_NOT", "SUPPORTS_AND",
  "SUPPORTS_OR", "REMS", "CHS", "QEMS", "EMS", "EXS", "PXS", "CMS", "MMS",
  "INS", "PTS", "PCS", "DEGS", "RADS", "GRADS", "TURNS", "MSECS", "SECS",
  "HERTZ", "KHERTZ", "DIMEN", "INVALIDDIMEN", "PERCENTAGE", "FLOATTOKEN",
  "INTEGER", "VW", "VH", "VMIN", "VMAX", "DPPX", "DPI", "DPCM", "FR",
  "URI", "FUNCTION", "ANYFUNCTION", "CUEFUNCTION", "NOTFUNCTION",
  "DISTRIBUTEDFUNCTION", "CALCFUNCTION", "MINFUNCTION", "MAXFUNCTION",
  "HOSTFUNCTION", "ANCESTORFUNCTION", "UNICODERANGE", "'}'", "')'", "']'",
  "';'", "'('", "','", "'{'", "'+'", "'~'", "'>'", "'/'", "'-'", "'='",
  "'#'", "'%'", "$accept", "stylesheet", "internal_rule",
  "internal_keyframe_rule", "internal_keyframe_key_list", "internal_decls",
  "internal_value", "internal_medialist", "internal_selector",
  "internal_supports_condition", "space", "maybe_space", "maybe_sgml",
  "closing_brace", "closing_parenthesis", "closing_square_bracket",
  "semi_or_eof", "maybe_charset", "rule_list", "valid_rule", "before_rule",
  "rule", "block_rule_body", "block_rule_list", "block_rule_recovery",
  "block_valid_rule", "block_rule", "before_import_rule",
  "import_rule_start", "import", "namespace", "maybe_ns_prefix",
  "string_or_uri", "maybe_media_value", "media_query_exp",
  "media_query_exp_list", "maybe_and_media_query_exp_list",
  "maybe_media_restrictor", "valid_media_query", "media_query",
  "maybe_media_list", "media_list", "mq_list", "at_rule_body_start",
  "before_media_rule", "at_rule_header_end_maybe_space",
  "media_rule_start", "media", "medium", "supports",
  "before_supports_rule", "at_supports_rule_header_end",
  "supports_condition", "supports_negation", "supports_conjunction",
  "supports_disjunction", "supports_condition_in_parens",
  "supports_declaration_condition", "before_keyframes_rule",
  "keyframes_rule_start", "keyframes", "keyframe_name", "keyframes_rule",
  "keyframe_rule_list", "keyframe_rule", "key_list", "key",
  "keyframes_error_recovery", "before_page_rule", "page", "page_selector",
  "declarations_and_margins", "margin_box", "$@1", "margin_sym",
  "before_font_face_rule", "font_face", "before_viewport_rule", "viewport",
  "combinator", "maybe_unary_operator", "unary_operator",
  "maybe_space_before_declaration", "before_selector_list",
  "at_rule_header_end", "at_selector_end", "ruleset",
  "before_selector_group_item", "selector_list", "relative_selector",
  "selector", "namespace_selector", "simple_selector",
  "simple_selector_list", "element_name", "specifier_list", "specifier",
  "class", "attr_name", "attrib", "match", "ident_or_string",
  "pseudo_page", "pseudo", "selector_recovery", "declaration_list",
  "decl_list", "declaration", "property", "prio", "ident_list",
  "track_names_list", "expr", "expr_recovery", "operator", "term",
  "unary_term", "function", "calc_func_term", "calc_func_operator",
  "calc_maybe_space", "calc_func_paren_expr", "calc_func_expr",
  "calc_func_expr_list", "calc_function", "min_or_max",
  "min_or_max_function", "invalid_at", "at_rule_recovery",
  "at_rule_header_recovery", "at_rule_end",
  "regular_invalid_at_rule_header", "invalid_rule", "invalid_rule_header",
  "at_invalid_rule_header_end", "invalid_block",
  "invalid_square_brackets_block", "invalid_parentheses_block",
  "opening_parenthesis", "error_location", "location_label",
  "error_recovery", "rule_error_recovery", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    58,    46,    91,
      42,   124,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   125,
      41,    93,    59,    40,    44,   123,    43,   126,    62,    47,
      45,    61,    35,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   124,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     134,   135,   135,   136,   136,   136,   137,   137,   138,   138,
     139,   139,   140,   140,   141,   141,   141,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   144,   145,
     145,   146,   146,   147,   147,   148,   149,   149,   149,   149,
     149,   149,   149,   149,   150,   150,   151,   152,   153,   153,
     154,   155,   155,   156,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   161,   161,   161,   162,   162,   163,   163,
     163,   164,   164,   165,   165,   165,   166,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   176,   176,
     176,   177,   178,   178,   179,   179,   180,   180,   180,   181,
     181,   182,   183,   183,   184,   185,   185,   186,   186,   187,
     187,   187,   188,   189,   189,   190,   190,   191,   192,   193,
     194,   194,   194,   194,   195,   195,   197,   196,   198,   198,
     198,   198,   198,   198,   198,   198,   198,   198,   198,   198,
     198,   198,   198,   198,   199,   200,   201,   202,   203,   203,
     203,   203,   204,   204,   205,   205,   206,   207,   208,   209,
     210,   211,   212,   212,   213,   213,   214,   214,   214,   214,
     215,   215,   215,   216,   216,   216,   216,   216,   216,   217,
     217,   218,   218,   219,   219,   220,   220,   220,   220,   220,
     221,   222,   223,   223,   223,   223,   223,   224,   224,   224,
     224,   224,   224,   225,   225,   226,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   228,   229,   229,   229,
     229,   230,   230,   231,   231,   231,   231,   231,   232,   233,
     233,   234,   234,   235,   235,   235,   236,   236,   236,   237,
     238,   238,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   241,   241,   241,
     242,   242,   243,   243,   243,   243,   244,   244,   245,   245,
     246,   246,   246,   246,   247,   247,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   253,   254,   254,   255,   255,
     255,   255,   255,   255,   255,   255,   256,   256,   256,   256,
     257,   257,   257,   258,   259,   260,   261,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   263,   264,   265,
     265,   265,   265,   265,   266,   266,   266,   266
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     4,     4,     4,     5,     4,     4,     1,
       2,     0,     1,     0,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     2,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     2,
       2,     1,     2,     0,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     3,     6,     6,
       6,     0,     2,     1,     1,     0,     3,     6,     4,     1,
       5,     1,     5,     0,     2,     2,     2,     3,     1,     4,
       3,     0,     1,     1,     2,     1,     4,     5,     0,     0,
       1,     3,     8,     1,    10,     0,     0,     1,     1,     1,
       1,     3,     4,     4,     4,     4,     5,     1,     6,    10,
      10,     0,     3,     3,     9,     1,     1,     1,     2,     0,
       4,     5,     5,     2,     5,     2,     1,     2,     0,    10,
       2,     3,     2,     0,     1,     4,     0,     7,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     8,     0,     8,     2,     2,
       2,     4,     1,     0,     1,     1,     1,     0,     0,     0,
       9,     0,     1,     6,     2,     1,     1,     2,     3,     3,
       1,     2,     2,     1,     2,     1,     2,     3,     2,     1,
       5,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     2,     4,     8,     5,     9,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     7,     5,
       6,     5,     6,     4,     6,     7,     6,     4,     6,     4,
       6,     4,     4,     6,     4,     4,     3,     0,     1,     2,
       1,     3,     4,     6,     8,     6,     4,     3,     3,     2,
       0,     2,     3,     3,     4,     4,     1,     3,     2,     3,
       2,     2,     2,     3,     2,     2,     2,     3,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     4,
       1,     2,     3,     3,     3,     3,     0,     1,     5,     4,
       1,     3,     3,     1,     2,     5,     5,     4,     1,     1,
       4,     4,     1,     1,     3,     3,     2,     2,     2,     3,
       3,     5,     3,     2,     2,     3,     5,     3,     3,     3,
       4,     2,     2,     0,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     0,     0,
       2,     2,     2,     2,     0,     2,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
      34,     0,    21,    21,    21,    21,    21,    21,    21,    21,
       0,     4,     8,     9,     3,     6,     7,     5,    10,    23,
     377,    19,    22,     0,    36,   363,   176,     0,   378,   177,
       0,     0,   173,   173,     0,     1,    37,   384,    20,    21,
     363,   377,     0,     0,   248,     0,     0,     0,    21,    21,
       0,     0,    45,    44,     0,     0,    40,    46,     0,     0,
       0,    43,     0,    41,     0,    42,     0,    47,     0,    39,
     201,   206,   205,   377,     0,     0,   202,   190,   179,   182,
       0,   186,   193,   195,   203,   207,   208,   209,    21,    21,
      21,   307,   308,   305,   304,   306,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
      21,   289,   288,   287,   309,   310,   311,   312,   313,   314,
     315,   316,    21,    21,    21,   338,   339,    21,    21,   175,
     174,    21,    21,     0,    21,     0,   266,    21,    21,    21,
      21,    21,   136,    21,     0,    21,     0,   172,     0,    21,
       0,     0,   108,   109,   110,   107,   117,    25,    24,    48,
       0,     0,   344,     0,   379,    14,   249,    21,   377,    21,
      21,   377,    21,    21,     0,    79,    21,     0,     0,    93,
       0,    92,     0,    71,     0,    21,    73,    74,    21,    21,
     178,    21,    21,    21,   126,   125,    21,    21,    21,    21,
     179,   192,   377,     0,     0,     0,     0,     0,     0,   210,
     377,     0,     0,   191,    17,     0,   187,    21,    21,    21,
       0,     0,   201,   202,   196,   198,   194,   204,   274,   275,
     280,   276,   278,     0,     0,   279,     0,   281,   285,    21,
      21,   286,    15,    21,    21,     0,   268,   272,   282,   283,
       0,   284,     0,    21,    21,   133,   135,    13,     0,   377,
       0,    18,    21,    21,    21,    21,     0,    23,   385,   379,
     368,   372,   374,   373,   375,   369,   370,   371,   376,   367,
     386,   387,   379,    33,    32,    35,   379,   346,   347,     0,
      21,   251,   379,   377,   258,   384,    84,    85,   379,     0,
      86,   103,    21,   377,    21,    16,    94,    21,     0,    11,
      67,   378,   101,     0,     0,   122,   123,   100,     0,   143,
       0,     0,   178,     0,     0,     0,   173,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   226,   379,    21,     0,
       0,     0,    31,    30,   216,    21,   188,   168,   169,   170,
       0,   189,   197,    29,   377,    28,   318,     0,     0,    21,
       0,     0,   320,   330,   333,   326,    21,   263,     0,     0,
     277,   273,   271,   270,   267,     0,   326,     0,    12,   173,
       0,   111,   379,    21,     0,     0,     0,     0,     0,   377,
       0,    49,     0,     0,     0,     0,     0,     0,     0,   363,
      50,     0,    38,     0,     0,     0,   380,   381,   382,   383,
     252,     0,     0,     0,     0,    21,    21,    81,    87,   384,
     378,    21,    72,    21,     0,    98,   106,    98,    21,     0,
     178,    21,    98,    98,     0,     0,     0,     0,     0,   227,
      21,    21,     0,   237,   199,    21,   233,    21,   239,   241,
      21,   242,   244,    21,   245,     0,   211,    21,     0,   218,
     219,   220,   221,   222,   217,   212,    21,   181,    21,   379,
     317,   319,     0,   321,   337,   327,     0,     0,     0,   261,
      21,   264,   265,   341,   334,    21,   340,    21,     0,     0,
       0,    21,   113,   115,   112,   114,   384,   354,   353,   178,
       0,   348,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   342,   343,     0,   365,   366,    27,    26,   364,
     379,   260,    78,    75,     0,    21,     0,    96,   378,     0,
       0,    21,     0,    21,   140,    21,   225,     0,   142,    21,
      21,    98,    21,   229,     0,     0,   185,   231,     0,     0,
      21,     0,     0,     0,     0,   214,    21,     0,     0,   171,
       0,     0,   326,     0,     0,   331,   332,    21,    21,   336,
     262,     0,   134,   132,    21,    21,   116,     0,   359,   377,
     349,   350,   352,   357,   358,   355,     0,    21,     0,    21,
       0,    80,     0,    97,    70,    68,    69,    53,    98,   378,
     141,    98,     0,     0,    21,     0,   184,   230,   236,   234,
       0,    21,   232,   238,   240,   243,     0,   224,   223,    21,
     183,   329,     0,   322,   323,   324,   325,   326,   118,     0,
       0,   384,   259,   379,     0,    77,    21,     0,    48,    21,
     129,    21,     0,     0,     0,   228,   235,     0,    21,     0,
     328,   335,   379,   260,   356,     0,     0,    76,    82,   102,
       0,    52,    23,    53,     0,     0,     0,   165,   167,     0,
     200,     0,   213,     0,     0,   377,    64,     0,    63,     0,
      59,    61,    60,    57,    58,    62,    56,   363,    65,    55,
      54,     0,   124,   384,    21,   128,     0,   144,   180,   215,
      21,    21,   384,   362,   361,   104,     0,   378,    21,   139,
      21,   146,   120,   119,     0,   130,   378,     0,    21,   360,
     131,   145,     0,    21,     0,     0,   147
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      22,    26,    36,   529,   356,   344,   285,    19,   159,    49,
     266,   267,   647,   648,   671,   686,   672,    50,    51,    52,
      53,   308,   188,   600,   175,   176,   418,   177,   178,   179,
     180,   181,   182,   541,    54,   320,    55,    56,   302,    57,
     394,   542,   151,   152,   153,   154,   155,   156,    59,   395,
      61,   196,   674,   675,   143,   144,   145,   705,   396,    63,
     430,   706,   720,   728,   523,   397,    65,   398,    67,   221,
     146,   133,    27,    68,   313,   215,    69,   568,    78,   555,
      79,    80,    81,   445,    82,    83,    84,    85,   341,    86,
     466,   629,   431,    87,   212,    42,    43,    44,    45,   598,
     368,   134,   135,   358,   245,   136,   137,   138,   363,   477,
     478,   364,   365,   377,   139,   140,   141,   524,    24,   498,
     162,   399,   400,   699,    40,   407,   408,   409,   282,    46,
      47,   289,   160
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -421
static const yytype_int16 yypact[] =
{
     840,   330,    79,    79,    79,    79,    79,    79,    79,    79,
      76,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,    87,    99,  -421,  -421,  -421,    90,  -421,   673,
     742,  1908,   210,   210,   -13,  -421,   114,  -421,  -421,    79,
    -421,  -421,   154,  2007,     2,    53,   169,   629,    79,    79,
     145,     1,  -421,  -421,   196,   504,  -421,  -421,   201,   313,
     342,  -421,   237,  -421,   247,  -421,   254,  -421,   742,  -421,
     264,  -421,  -421,   526,   286,   536,   267,  -421,   307,   112,
     584,  -421,   459,   459,  -421,  -421,  -421,  -421,    79,    79,
      79,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
      79,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,    79,    79,    79,  -421,  -421,    79,    79,  -421,
    -421,    79,    79,  2211,    79,   850,  -421,    79,    79,    79,
      79,    79,  -421,    79,   333,    79,   224,  -421,    75,    79,
     295,   312,  -421,   251,   252,   331,  -421,  -421,  -421,   324,
     568,    69,  -421,    46,  -421,  -421,   226,    79,  -421,    79,
      79,  -421,    79,    79,   100,  -421,    79,   349,    71,   229,
     346,  -421,   412,   353,   371,    79,  -421,  -421,    79,    79,
    -421,    79,    79,    79,  -421,  -421,    79,    79,    79,    79,
    -421,  -421,   146,   335,  1000,  1000,  1384,  1384,   366,  -421,
    -421,    73,    65,  -421,  -421,   274,   742,    79,    79,    79,
     385,   742,  -421,  -421,   459,   459,   459,  -421,  -421,  -421,
    -421,  -421,  -421,   967,  1224,  -421,   291,  -421,  -421,    79,
      79,  -421,  -421,    79,    79,  1908,  -421,  -421,  -421,  -421,
    1224,  -421,   400,    79,    79,  -421,  -421,  -421,   290,  -421,
     228,  -421,    79,    79,    79,    79,  2107,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  1308,
      79,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,   396,
     351,  -421,    79,  -421,    79,  -421,   302,    79,     1,  -421,
    -421,  -421,  -421,   306,   -13,  -421,  -421,  -421,   309,    89,
     318,   322,   274,  1000,   728,   430,   253,    33,   742,    33,
     742,    33,  1845,    33,  1845,    33,  -421,  -421,    56,   267,
     432,   376,  -421,  -421,  -421,    79,  -421,  -421,  -421,  -421,
     344,  -421,   459,  -421,  -421,  -421,  -421,   708,    33,    79,
    2243,    33,  -421,  -421,  -421,   445,    79,  -421,   280,    33,
    -421,  -421,  -421,  -421,  -421,    33,   445,    60,  -421,   210,
     115,  -421,  -421,    79,    33,   290,   290,   290,   290,  -421,
     308,  -421,   275,   480,   429,   316,   441,   440,   439,  -421,
    -421,  1601,   114,   753,  1512,  1562,  -421,  -421,  -421,  -421,
    -421,  1328,  1066,   885,  1512,    79,    79,   422,  -421,  -421,
    -421,    79,  -421,    79,   460,  -421,  -421,  -421,    61,   470,
    -421,    79,  -421,  -421,   370,   742,    33,  2024,    33,  -421,
      79,    79,   401,  -421,  -421,    79,  -421,    79,  -421,  -421,
      79,  -421,  -421,    79,  -421,  1102,  -421,    79,   376,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,    79,  -421,    79,  -421,
    -421,  -421,  1224,  -421,  -421,    91,   105,  2155,    37,  -421,
      79,  -421,  -421,  -421,   262,    79,  -421,    79,    25,  1512,
     474,    79,  -421,  -421,  -421,  -421,  -421,  -421,  -421,   382,
     297,  -421,    50,   235,   235,    -8,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,  -421,  -421,   494,  -421,  -421,  -421,  -421,  -421,
    -421,  1734,  -421,   481,   387,    79,   995,  -421,  -421,    69,
      46,    79,   389,    79,  -421,    79,  -421,   391,  -421,    79,
      79,  -421,    79,  -421,   742,    33,   112,  -421,    33,    33,
      79,   135,    33,   135,   135,  -421,    79,   446,   742,  -421,
    1583,    33,   445,    79,    79,  -421,  -421,    79,    79,  -421,
    -421,  2155,  -421,  -421,    79,    79,  -421,  1671,  -421,  -421,
    -421,  -421,  -421,  -421,  -421,  -421,  1435,    79,  1418,    79,
      33,  -421,   387,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -421,  -421,   115,   115,    79,   135,   112,  -421,  -421,  -421,
      33,    79,  -421,  -421,  -421,  -421,   446,  -421,  -421,    79,
     112,  -421,    37,    87,    87,  -421,  -421,   445,  -421,  1165,
     392,  -421,  -421,  -421,  1908,  -421,    79,    25,    41,    79,
    -421,    79,    25,    25,   115,  -421,  -421,   742,    79,    65,
    -421,   262,  -421,  1734,  -421,  1492,  1455,  1821,   351,  -421,
    2163,  -421,  -421,  -421,    25,   406,  2025,  -421,  -421,    25,
    -421,    65,  -421,  1512,    33,  -421,  -421,   494,  -421,  1010,
    -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
     114,    25,  -421,  -421,    79,   392,  1659,  -421,  -421,  -421,
      79,    79,  -421,   162,    -8,  -421,  1619,  -421,    79,  -421,
      79,  -421,  -421,  -421,  1639,  -421,  -421,  2025,    79,   392,
    -421,  -421,   393,    79,   115,    25,  -421
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,  -421,
    -303,    -1,  -255,  -420,   278,  -306,  -147,  -421,  -421,   243,
    -138,  -421,  -157,  -421,  -421,  -421,  -421,  -421,  -239,  -421,
    -142,  -421,   215,  -421,    -5,   -72,  -421,  -421,  -421,   350,
     -46,  -421,  -421,  -374,  -421,  -165,  -238,  -135,  -421,  -125,
     507,  -421,  -215,  -421,  -421,  -421,  -173,  -421,  -421,   517,
    -123,  -421,  -421,  -421,  -122,   519,   176,  -421,   529,  -110,
    -421,  -421,  -421,  -421,  -139,   535,   -96,   549,   -89,   149,
     263,   -15,  -217,  -421,  -158,   388,   -79,  -421,   538,  -421,
    -408,   383,  -177,    -7,   528,   -30,   -47,  -421,   276,  -421,
     156,   -11,   190,  -421,  -124,  -357,  -421,   578,  -421,   -41,
    -421,  -421,  -203,  -194,  -421,  -113,  -109,  -421,   157,  -421,
    -362,   160,  -207,  -421,  -421,  -421,  -421,  -421,  -421,     9,
    -421,   -44,   -32,  -421,   -39,  -144,  -145,  -134,  -421,    -9,
    -291,  -174,  -274
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -378
static const yytype_int16 yytable[] =
{
      23,   163,    28,    29,    30,    31,    32,    33,    34,   190,
      25,    37,   402,   186,   484,   280,   287,   147,   147,   288,
     424,   413,   246,   488,   240,   527,   281,   392,   393,   556,
     357,   318,   164,   353,   321,   465,   227,   353,   161,   346,
     361,   -51,   369,   376,   351,   384,   283,   183,   184,   149,
     225,    20,   226,   543,   168,    21,   375,   577,   549,   550,
     353,    21,   476,   -21,   208,   342,    21,   -21,   583,   283,
     169,   -88,   303,   476,   211,   257,    35,   201,   429,   327,
     329,   331,   333,   335,    21,   381,   338,   228,   229,   230,
    -247,    41,    38,   339,    77,   403,   -19,   525,   187,   426,
     150,   298,   428,  -377,   593,    21,   429,   286,   404,   231,
      38,    39,   405,   -21,   167,  -247,    41,   216,   411,   157,
     158,   232,   233,   234,   414,   362,   235,   236,  -377,   537,
     237,   238,   374,   241,   528,   353,   247,   248,   249,   250,
     251,   362,   252,   355,   255,   536,   616,   355,   258,   260,
     -51,   444,   565,   447,   165,   444,   578,   444,   284,   292,
     630,   286,   295,   455,   434,   -21,   291,   185,   293,   294,
     355,   296,   297,   299,   485,   300,   343,   614,   227,   227,
     -88,   284,   170,   -88,   310,   -88,   -88,   311,   312,   253,
     314,   315,   316,   325,   352,   317,   319,   317,   317,   436,
     438,   337,   326,   328,   330,   332,   334,   -19,   489,   531,
     632,   -19,   492,   493,   494,   495,   347,   348,   349,   360,
     189,   573,   587,   142,  -247,   574,   191,   669,   217,   218,
     219,   220,   677,   678,   649,   360,    20,   651,   370,   371,
      21,   383,   372,   373,   246,   355,   323,   603,   324,   621,
     382,   473,   379,   380,   702,   652,   653,   401,   444,   708,
     197,   385,   386,   387,   388,   572,   440,   441,   280,   476,
     633,   634,   547,   198,   588,   661,    20,  -178,   571,   281,
     353,   715,   577,   199,   412,   201,   719,   186,   213,   410,
     149,   353,   354,   480,   419,   570,   259,   679,   589,   209,
      21,   417,    21,   420,   366,   227,   422,   214,   -21,    20,
     256,   147,   261,    21,   262,   736,   263,    20,   650,   707,
     -21,   -21,   435,   437,    -2,   450,   129,   453,   194,   195,
     130,    20,   612,   613,   476,    21,   210,   456,   290,   321,
      21,   150,   -21,   304,   467,   469,   305,   499,   -21,   -21,
     -21,   192,   193,   682,   194,   195,   596,   -21,   472,   -21,
     505,   594,   301,   362,   147,   479,   307,   665,   362,   129,
     731,   309,   187,   130,   637,   709,   342,   735,   540,   336,
     496,   578,   490,   459,   460,   461,   462,   463,   345,   183,
     355,   280,   604,   605,   264,   265,   606,   654,   350,   497,
     378,   355,   281,   150,   501,   -21,  -127,   703,   -21,   415,
     -21,   416,   -95,   171,   533,   534,   421,   700,   246,   142,
     538,   425,   539,   -21,   427,   -83,   725,   544,   552,   716,
     548,   687,   689,   432,   676,   730,   663,   433,   724,   558,
     559,   667,   280,   439,   561,   457,   562,   253,   254,   563,
     475,   -21,   564,   281,   500,   -21,   456,   360,   627,   628,
     -91,   171,   360,   468,   502,   567,   503,   569,   504,   666,
     172,   173,   362,   -83,    71,    72,    73,    74,    75,   580,
     680,   171,   535,   546,   581,   551,   582,   343,   683,   560,
     586,   585,  -173,   -83,   588,    20,   664,   464,   599,   314,
     174,   319,   317,   317,   608,   171,   611,   286,   733,   391,
     670,   590,   591,   592,   367,  -127,   701,   -83,   172,   173,
     280,   -95,   129,   423,   -95,   174,   130,   -95,   688,   601,
     646,   281,   306,   595,   602,   690,    58,   210,   172,   173,
     607,    21,   609,   202,   610,   691,    60,   692,   640,   -21,
     246,   615,   148,   704,   246,   487,   -21,   -21,    62,   620,
     693,   718,   172,   173,    64,   626,   360,   721,  -345,   268,
     594,   280,   -91,   174,   694,   -91,   635,   636,    66,   280,
     641,   695,   281,   638,   639,   664,   554,   269,   322,   442,
     281,   696,   -91,   174,   340,   -91,   642,   222,   644,    71,
      72,    73,    74,    75,   223,   443,   200,   446,   224,   448,
     449,   451,   452,   454,   566,   658,   458,   174,   545,   -91,
     657,   166,   684,     0,   203,   204,   697,   205,   659,   -91,
     171,     0,   206,   207,   575,   470,   471,   576,   698,   474,
       0,     0,   -83,   713,     0,   668,   481,   482,   673,     0,
       0,     0,     0,   483,     0,   486,     0,   681,   714,     0,
     147,   401,   491,     0,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,     0,   712,  -345,     0,     0,
    -345,   279,   526,  -345,     0,   729,     0,   172,   173,     0,
       0,     0,   532,     0,     0,   -66,  -138,   -99,  -105,  -164,
       0,    48,  -166,   717,     0,     0,     0,     0,   353,   722,
     723,  -121,  -121,     0,   553,     0,   557,   726,     0,   727,
      88,    89,     0,    90,     0,     0,     0,   732,     0,   210,
       0,     0,   734,    21,     0,     0,     0,     0,     0,     0,
       0,   -21,   174,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
       0,     0,     0,   342,   406,    70,   579,    71,    72,    73,
      74,    75,    76,    77,     0,     0,     0,   584,     0,     0,
       0,     0,   269,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,     0,     0,     0,
       0,   124,   125,   126,     0,     0,   127,     0,   355,     0,
       0,   128,   243,     0,   129,     0,     0,   244,   130,     0,
     131,   132,     0,   617,     0,     0,   618,   619,     0,   622,
     623,   624,   625,     0,   -21,   -21,   -21,   -21,     0,   631,
     242,   270,   271,   272,   273,   274,   275,   276,   277,   278,
       0,     0,    88,    89,   343,    90,   279,     1,   286,     0,
       2,     3,     4,     5,     6,     7,     8,     9,   645,     0,
       0,     0,     0,     0,     0,   -90,   268,     0,     0,     0,
       0,     0,     0,   655,     0,     0,     0,     0,   656,     0,
       0,     0,     0,     0,   269,     0,     0,     0,     0,     0,
     660,     0,     0,     0,     0,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,     0,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,   124,   125,   126,     0,     0,   127,     0,
       0,   710,   711,   128,   243,     0,   129,   353,   354,   244,
     130,     0,   131,   132,     0,     0,     0,     0,     0,    88,
      89,     0,    90,   270,   271,   272,   273,   274,   275,   276,
     277,   278,     0,     0,   -90,   -89,   268,   -90,   279,   -90,
     -90,   210,     0,     0,     0,    21,     0,     0,     0,     0,
     -91,   171,     0,   -21,   269,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,     0,   -83,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,     0,   530,   172,   173,
     124,   125,   126,     0,     0,   127,     0,   355,    88,    89,
     128,    90,     0,   129,     0,     0,     0,   130,     0,   131,
     132,     0,     0,   270,   271,   272,   273,   274,   275,   276,
     277,   278,  -246,   406,   -89,     0,     0,   -89,   279,   -89,
     -89,     0,     0,     0,     0,     0,     0,     0,     0,   -91,
       0,   269,   -91,   174,     0,   -91,     0,     0,     0,     0,
       0,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,     0,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     0,   662,     0,     0,   124,
     125,   126,     0,     0,   127,     0,     0,    88,    89,   128,
      90,     0,   129,     0,     0,     0,   130,     0,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,     0,
       0,     0,  -246,  -246,     0,   279,     0,   286,     0,     0,
       0,     0,     0,     0,     0,   354,     0,     0,     0,     0,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,     0,     0,     0,     0,   124,   125,
     126,     0,     0,   127,     0,     0,     0,     0,   128,     0,
       0,   129,     0,     0,     0,   130,     0,   131,   132,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,  -257,   406,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,     0,     0,     0,     0,     0,     0,   269,  -256,   406,
       0,     0,     0,     0,     0,     0,     0,   359,     0,     0,
     129,     0,     0,     0,   130,     0,     0,   269,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,     0,     0,     0,     0,  -256,  -256,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -256,   -21,   210,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,   -21,     0,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   270,   271,   272,   273,
     274,   275,   276,   277,   278,     0,     0,  -257,  -253,   643,
    -257,   279,     0,   286,     0,     0,   270,   271,   272,   273,
     274,   275,   276,   277,   278,  -255,   406,  -256,     0,     0,
    -256,   279,     0,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,  -254,   406,     0,  -253,  -253,
    -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -253,   269,  -255,  -255,  -255,  -255,  -255,
    -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,  -255,
    -255,     0,  -351,   268,   -21,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,   269,   353,   406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -253,     0,     0,
    -253,   269,     0,   270,   271,   272,   273,   274,   275,   276,
     277,   278,     0,     0,  -255,     0,     0,  -255,   279,     0,
     286,     0,     0,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   527,   406,  -254,     0,     0,  -254,   279,     0,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,  -269,   406,     0,     0,     0,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,     0,
       0,  -351,   269,     0,  -351,   279,     0,  -351,     0,     0,
     270,   271,   272,   273,   274,   275,   276,   277,   278,  -137,
     268,     0,   355,     0,     0,   279,     0,   286,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   269,  -363,
     268,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   269,   527,
     270,   271,   272,   273,   274,   275,   276,   277,   278,     0,
       0,   528,   268,     0,     0,   279,     0,   286,     0,     0,
       0,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     269,     0,     0,  -269,     0,     0,   279,     0,   286,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,     0,     0,   270,   271,   272,
     273,   274,   275,   276,   277,   278,     0,     0,  -137,     0,
       0,     0,   279,     0,  -137,     0,     0,   270,   271,   272,
     273,   274,   275,   276,   277,   278,    88,    89,  -363,    90,
       0,     0,   279,     0,  -363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,   270,
     271,   272,   273,   274,   275,   276,   277,   278,     0,     0,
       0,     0,     0,     0,   279,     0,  -363,     0,     0,     0,
       0,   597,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,     0,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,    88,    89,     0,    90,   124,   125,   126,
       0,     0,   127,     0,     0,   353,     0,   128,   243,     0,
     129,     0,     0,   244,   130,     0,   131,   132,    70,     0,
      71,    72,    73,    74,    75,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
      88,    89,     0,    90,   124,   125,   126,     0,     0,   127,
       0,     0,     0,     0,   128,   243,     0,   129,     0,     0,
     244,   130,     0,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   355,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,     0,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,  -250,    41,     0,
       0,   124,   125,   126,     0,     0,   127,     0,     0,     0,
    -377,   128,     0,     0,   129,  -247,    41,     0,   130,     0,
     131,   132,     0,     0,     0,     0,     0,    70,  -377,    71,
      72,    73,    74,    75,    76,    77,     0,  -250,  -250,  -250,
    -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,  -250,
    -250,  -250,  -250,     0,     0,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   389,     0,
       0,     0,     0,     0,     0,     0,  -250,     0,     0,     0,
    -177,     0,  -177,  -177,  -177,  -177,  -177,  -177,  -177,   -66,
    -138,   -99,  -105,  -164,  -247,   390,  -166,     0,     0,     0,
     217,   218,   219,   220,     0,  -121,  -121,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,   685,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -177,     0,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,   -66,  -138,   -99,  -105,  -164,
       0,   390,  -166,     0,     0,     0,     0,     0,     0,     0,
       0,  -121,  -121,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
    -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,  -377,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   359,     0,
       0,   129,     0,     0,     0,   130,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   239,     0,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121
};

static const yytype_int16 yycheck[] =
{
       1,    40,     3,     4,     5,     6,     7,     8,     9,    55,
       1,    20,   267,    12,   376,   160,   163,    32,    33,   163,
     311,   295,   135,   380,   133,     0,   160,   266,   266,   437,
     233,   196,    41,     0,   199,   341,    83,     0,    39,   216,
     234,     0,   236,   250,   221,   260,     0,    48,    49,    62,
      80,     1,    82,   427,     1,     5,   250,    20,   432,   433,
       0,     5,   365,    13,    73,     0,     5,    17,   488,     0,
      17,     0,     1,   376,    75,     0,     0,    21,    17,   203,
     204,   205,   206,   207,     5,   258,    13,    88,    89,    90,
       0,     1,     5,    20,    21,   269,     5,   403,    97,   314,
     113,     1,    13,    13,   112,     5,    17,   115,   282,   110,
       5,    12,   286,    13,   112,     0,     1,     5,   292,     5,
       6,   122,   123,   124,   298,   234,   127,   128,    13,   420,
     131,   132,   245,   134,   109,     0,   137,   138,   139,   140,
     141,   250,   143,   110,   145,   419,   554,   110,   149,   150,
     109,   328,   458,   330,     0,   332,   119,   334,   112,   168,
     568,   115,   171,   337,   322,   115,   167,    22,   169,   170,
     110,   172,   173,   174,   114,   176,   111,   551,   225,   226,
     109,   112,    13,   112,   185,   114,   115,   188,   189,   114,
     191,   192,   193,   202,   224,   196,   197,   198,   199,   323,
     324,   210,   203,   204,   205,   206,   207,   116,   382,   412,
     572,   120,   385,   386,   387,   388,   217,   218,   219,   234,
      24,   116,   496,    13,   109,   120,    25,   647,   116,   117,
     118,   119,   652,   653,   608,   250,     1,   611,   239,   240,
       5,    13,   243,   244,   357,   110,   100,   538,   102,   114,
     259,   360,   253,   254,   674,   612,   613,   266,   435,   679,
      23,   262,   263,   264,   265,   472,    13,    14,   413,   572,
     573,   574,   430,    26,   112,   637,     1,   115,   472,   413,
       0,   701,    20,    29,   293,    21,   706,    12,    21,   290,
      62,     0,     1,    13,   303,   469,     1,   654,     1,    13,
       5,   302,     5,   304,    13,   352,   307,     0,    13,     1,
      86,   326,     0,     5,    63,   735,    64,     1,   609,   676,
      12,    13,   323,   324,     0,   332,   116,   334,    12,    13,
     120,     1,   549,   550,   637,     5,     1,   338,   112,   504,
       5,   113,    12,   114,   345,   354,     0,   393,    13,    14,
     115,    38,    39,   659,    12,    13,   530,    62,   359,    62,
     399,   505,    13,   472,   379,   366,    13,   641,   477,   116,
     727,     0,    97,   120,   581,   681,     0,   734,   424,    13,
     389,   119,   383,     7,     8,     9,    10,    11,   114,   390,
     110,   536,   539,   540,    63,    64,   540,   614,    13,   390,
       0,   110,   536,   113,   395,    97,     0,     1,   113,    13,
     113,    60,     0,     1,   415,   416,   114,   672,   531,    13,
     421,   115,   423,    88,   115,    13,   717,   428,   435,   703,
     431,   670,   670,   115,   651,   726,   639,   115,   712,   440,
     441,   644,   587,    13,   445,    13,   447,   114,   115,   450,
       5,   116,   453,   587,    25,   120,   457,   472,    12,    13,
       0,     1,   477,   119,    23,   466,    26,   468,    29,   643,
      58,    59,   581,    13,    15,    16,    17,    18,    19,   480,
     657,     1,    60,    13,   485,   115,   487,   111,   662,    88,
     491,    17,    86,    13,   112,     1,   640,   121,    17,   500,
     113,   502,   503,   504,   115,     1,   115,   115,   115,   266,
     648,   502,   503,   504,   236,   109,   673,    13,    58,    59,
     665,   109,   116,   308,   112,   113,   120,   115,   670,   534,
     602,   665,   182,   524,   535,   670,    29,     1,    58,    59,
     541,     5,   543,    17,   545,   670,    29,   670,   587,    13,
     663,   552,    33,   675,   667,   379,    20,    21,    29,   560,
     670,   705,    58,    59,    29,   566,   581,   706,     0,     1,
     714,   716,   112,   113,   670,   115,   577,   578,    29,   724,
     589,   670,   716,   584,   585,   729,   437,    19,   200,   326,
     724,   670,   112,   113,   211,   115,   597,    13,   599,    15,
      16,    17,    18,    19,    20,   327,    68,   329,    80,   331,
     332,   333,   334,   335,   458,   626,   340,   113,   428,   115,
     621,    43,   663,    -1,    98,    99,   670,   101,   629,     0,
       1,    -1,   106,   107,   477,   357,   358,   477,   670,   361,
      -1,    -1,    13,   689,    -1,   646,   368,   369,   649,    -1,
      -1,    -1,    -1,   375,    -1,   377,    -1,   658,   697,    -1,
     675,   670,   384,    -1,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,   685,   109,    -1,    -1,
     112,   113,   404,   115,    -1,   724,    -1,    58,    59,    -1,
      -1,    -1,   414,    -1,    -1,    22,    23,    24,    25,    26,
      -1,    28,    29,   704,    -1,    -1,    -1,    -1,     0,   710,
     711,    38,    39,    -1,   436,    -1,   438,   718,    -1,   720,
      12,    13,    -1,    15,    -1,    -1,    -1,   728,    -1,     1,
      -1,    -1,   733,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,   113,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    -1,     0,     1,    13,   478,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,   489,    -1,    -1,
      -1,    -1,    19,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    -1,    -1,    -1,
      -1,   103,   104,   105,    -1,    -1,   108,    -1,   110,    -1,
      -1,   113,   114,    -1,   116,    -1,    -1,   119,   120,    -1,
     122,   123,    -1,   555,    -1,    -1,   558,   559,    -1,   561,
     562,   563,   564,    -1,   116,   117,   118,   119,    -1,   571,
       0,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      -1,    -1,    12,    13,   111,    15,   113,    27,   115,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,   600,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,    -1,    -1,   615,    -1,    -1,    -1,    -1,   620,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,
     632,    -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,   103,   104,   105,    -1,    -1,   108,    -1,
      -1,   683,   684,   113,   114,    -1,   116,     0,     1,   119,
     120,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,    12,
      13,    -1,    15,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,   109,     0,     1,   112,   113,   114,
     115,     1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
       0,     1,    -1,    13,    19,    15,    16,    17,    18,    19,
      20,    21,    -1,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    -1,     1,    58,    59,
     103,   104,   105,    -1,    -1,   108,    -1,   110,    12,    13,
     113,    15,    -1,   116,    -1,    -1,    -1,   120,    -1,   122,
     123,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     1,   109,    -1,    -1,   112,   113,   114,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    19,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    -1,     1,    -1,    -1,   103,
     104,   105,    -1,    -1,   108,    -1,    -1,    12,    13,   113,
      15,    -1,   116,    -1,    -1,    -1,   120,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,    -1,   110,   111,    -1,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    -1,    -1,    -1,    -1,   103,   104,
     105,    -1,    -1,   108,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,    -1,    -1,   120,    -1,   122,   123,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    19,     0,     1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
     116,    -1,    -1,    -1,   120,    -1,    -1,    19,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,     0,     1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    -1,    -1,   109,     0,     1,
     112,   113,    -1,   115,    -1,    -1,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,     1,   109,    -1,    -1,
     112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,     0,     1,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    19,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,     0,     1,   110,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    19,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
     112,    19,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    -1,    -1,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,    -1,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,     1,   109,    -1,    -1,   112,   113,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,   109,    19,    -1,   112,   113,    -1,   115,    -1,    -1,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
       1,    -1,   110,    -1,    -1,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,     0,
       1,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    19,     0,
      98,    99,   100,   101,   102,   103,   104,   105,   106,    -1,
      -1,   109,     1,    -1,    -1,   113,    -1,   115,    -1,    -1,
      -1,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      19,    -1,    -1,   110,    -1,    -1,   113,    -1,   115,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    -1,    -1,   109,    -1,
      -1,    -1,   113,    -1,   115,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    12,    13,   109,    15,
      -1,    -1,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,   115,    -1,    -1,    -1,
      -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    -1,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    12,    13,    -1,    15,   103,   104,   105,
      -1,    -1,   108,    -1,    -1,     0,    -1,   113,   114,    -1,
     116,    -1,    -1,   119,   120,    -1,   122,   123,    13,    -1,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      12,    13,    -1,    15,   103,   104,   105,    -1,    -1,   108,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,    -1,    -1,
     119,   120,    -1,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,     0,     1,    -1,
      -1,   103,   104,   105,    -1,    -1,   108,    -1,    -1,    -1,
      13,   113,    -1,    -1,   116,     0,     1,    -1,   120,    -1,
     122,   123,    -1,    -1,    -1,    -1,    -1,    13,    13,    15,
      16,    17,    18,    19,    20,    21,    -1,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   109,    28,    29,    -1,    -1,    -1,
     116,   117,   118,   119,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,     1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,    -1,    -1,   120,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    -1,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    -1,    -1,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    27,    30,    31,    32,    33,    34,    35,    36,    37,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   141,
       1,     5,   134,   135,   252,   253,   135,   206,   135,   135,
     135,   135,   135,   135,   135,     0,   136,   263,     5,    12,
     258,     1,   229,   230,   231,   232,   263,   264,    28,   143,
     151,   152,   153,   154,   168,   170,   171,   173,   174,   182,
     183,   184,   192,   193,   199,   200,   201,   202,   207,   210,
      13,    15,    16,    17,    18,    19,    20,    21,   212,   214,
     215,   216,   218,   219,   220,   221,   223,   227,    12,    13,
      15,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,   103,   104,   105,   108,   113,   116,
     120,   122,   123,   205,   235,   236,   239,   240,   241,   248,
     249,   250,    13,   188,   189,   190,   204,   205,   189,    62,
     113,   176,   177,   178,   179,   180,   181,     5,     6,   142,
     266,   135,   254,   258,   263,     0,   231,   112,     1,    17,
      13,     1,    58,    59,   113,   158,   159,   161,   162,   163,
     164,   165,   166,   135,   135,    22,    12,    97,   156,    24,
     164,    25,    38,    39,    12,    13,   185,    23,    26,    29,
     212,    21,    17,    98,    99,   101,   106,   107,   263,    13,
       1,   135,   228,    21,     0,   209,     5,   116,   117,   118,
     119,   203,    13,    20,   218,   219,   219,   220,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,    84,
     240,   135,     0,   114,   119,   238,   239,   135,   135,   135,
     135,   135,   135,   114,   115,   135,    86,     0,   135,     1,
     135,     0,    63,    64,    63,    64,   144,   145,     1,    19,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   113,
     260,   261,   262,     0,   112,   140,   115,   140,   259,   265,
     112,   135,   263,   135,   135,   263,   135,   135,     1,   135,
     135,    13,   172,     1,   114,     0,   163,    13,   155,     0,
     135,   135,   135,   208,   135,   135,   135,   135,   169,   135,
     169,   169,   209,   100,   102,   263,   135,   228,   135,   228,
     135,   228,   135,   228,   135,   228,    13,   263,    13,    20,
     215,   222,     0,   111,   139,   114,   216,   135,   135,   135,
      13,   216,   219,     0,     1,   110,   138,   236,   237,   113,
     205,   237,   240,   242,   245,   246,    13,   138,   234,   237,
     135,   135,   135,   135,   239,   237,   246,   247,     0,   135,
     135,   180,   263,    13,   176,   135,   135,   135,   135,     1,
      28,   143,   152,   170,   174,   183,   192,   199,   201,   255,
     256,   263,   136,   265,   265,   265,     1,   259,   260,   261,
     135,   265,   263,   266,   265,    13,    60,   135,   160,   263,
     135,   114,   135,   156,   264,   115,   176,   115,    13,    17,
     194,   226,   115,   115,   208,   135,   228,   135,   228,    13,
      13,    14,   204,   138,   216,   217,   138,   216,   138,   138,
     217,   138,   138,   217,   138,   265,   135,    13,   222,     7,
       8,     9,    10,    11,   121,   139,   224,   135,   119,   263,
     138,   138,   135,   240,   138,     5,   134,   243,   244,   135,
      13,   138,   138,   138,   244,   114,   138,   190,   229,   265,
     135,   138,   180,   180,   180,   180,   263,   253,   253,   164,
      25,   253,    23,    26,    29,   258,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,   198,   251,   139,   138,     0,   109,   137,
       1,   236,   138,   135,   135,    60,   266,   264,   135,   135,
     164,   167,   175,   167,   135,   226,    13,   208,   135,   167,
     167,   115,   217,   138,   203,   213,   214,   138,   135,   135,
      88,   135,   135,   135,   135,   139,   224,   135,   211,   135,
     265,   237,   246,   116,   120,   242,   245,    20,   119,   138,
     135,   135,   135,   137,   138,    17,   135,   266,   112,     1,
     253,   253,   253,   112,   259,   253,   265,    57,   233,    17,
     157,   158,   135,   264,   140,   140,   259,   135,   115,   135,
     135,   115,   206,   206,   167,   135,   214,   138,   138,   138,
     135,   114,   138,   138,   138,   138,   135,    12,    13,   225,
     214,   138,   244,   134,   134,   135,   135,   246,   135,   135,
     258,   263,   135,     1,   135,   138,   159,   146,   147,   167,
     264,   167,   229,   229,   206,   138,   138,   135,   225,   135,
     138,   244,     1,   236,   259,   266,   265,   236,   135,   137,
     144,   148,   150,   135,   186,   187,   206,   137,   137,   229,
     216,   135,   139,   265,   233,     1,   149,   152,   154,   170,
     171,   173,   184,   193,   200,   202,   210,   255,   256,   257,
     136,   146,   137,     1,   188,   191,   195,   229,   137,   139,
     138,   138,   263,   164,   258,   137,   266,   135,   259,   137,
     196,   198,   135,   135,   266,   264,   135,   135,   197,   258,
     264,   229,   135,   115,   135,   229,   137
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
      yyerror (parser, YY_("syntax error: cannot back up")); \
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
# if YYLTYPE_IS_TRIVIAL
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
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, parser)
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
		  Type, Value, parser); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, BisonCSSParser* parser)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    BisonCSSParser* parser;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (parser);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, BisonCSSParser* parser)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    BisonCSSParser* parser;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parser);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, BisonCSSParser* parser)
#else
static void
yy_reduce_print (yyvsp, yyrule, parser)
    YYSTYPE *yyvsp;
    int yyrule;
    BisonCSSParser* parser;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , parser);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, parser); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, BisonCSSParser* parser)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, parser)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    BisonCSSParser* parser;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (parser);

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
int yyparse (BisonCSSParser* parser);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */





/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
yyparse (BisonCSSParser* parser)
#else
int
yyparse (parser)
    BisonCSSParser* parser;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 11:
    {
        //parser->m_rule = (yyvsp[(3) - (5)].rule);
    ;}
    break;

  case 12:
    {
        parser->m_keyframe = (yyvsp[(3) - (5)].keyframe);
    ;}
    break;

  case 13:
    {
        parser->m_valueList = parser->sinkFloatingValueList((yyvsp[(3) - (4)].valueList));
    ;}
    break;

  case 14:
    {
        /* can be empty */
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
    {
        parser->m_valueList = parser->sinkFloatingValueList((yyvsp[(3) - (4)].valueList));
        int oldParsedProperties = parser->m_parsedProperties.size();
        if (!parser->parseValue(parser->m_id, parser->m_important))
            parser->rollbackLastProperties(parser->m_parsedProperties.size() - oldParsedProperties);
        parser->m_valueList = nullptr;
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
    {
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
    {
        if (parser->m_selectorListForParseSelector)
            parser->m_selectorListForParseSelector->adoptSelectorVector(*(yyvsp[(3) - (4)].selectorList));
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
    {
        parser->m_supportsCondition = (yyvsp[(3) - (4)].boolean);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
    {
       //if (parser->m_styleSheet)
       //    parser->m_styleSheet->parserSetEncodingFromCharsetRule((yyvsp[(3) - (5)].string));
       parser->startEndUnknownRule();
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
    {
     //if ((yyvsp[(2) - (3)].rule) && parser->m_styleSheet)
     //    parser->m_styleSheet->parserAppendRule((yyvsp[(2) - (3)].rule));
 ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
    {
        parser->startRule();
    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = (yyvsp[(2) - (2)].rule);
        parser->m_hadSyntacticallyValidCSSRule = true;
        //parser->endRule(!!(yyval.rule));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = 0;
        parser->endRule(false);
    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
    //{ (yyval.ruleList) = 0; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
    {
      //(yyval.ruleList) = parser->appendRule((yyvsp[(1) - (3)].ruleList), (yyvsp[(2) - (3)].rule));
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
    {
        parser->endRule(false);
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = (yyvsp[(2) - (2)].rule);
        //parser->endRule(!!(yyval.rule));
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = 0;
        parser->endRule(false);
    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
    {
        parser->startRuleHeader(CSSRuleSourceData::IMPORT_RULE);
    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
    {
        parser->endRuleHeader();
        parser->startRuleBody();
    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = parser->createImportRule((yyvsp[(2) - (6)].string), (yyvsp[(5) - (6)].mediaList));
    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = 0;
    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
    {
        parser->addNamespace((yyvsp[(3) - (6)].string), (yyvsp[(4) - (6)].string));
        //(yyval.rule) = 0;
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
    { (yyval.string).clear(); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = 0;
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(3) - (3)].valueList);
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
    {
        parser->tokenToLowerCase((yyvsp[(3) - (6)].string));
        //(yyval.mediaQueryExp) = parser->createFloatingMediaQueryExp((yyvsp[(3) - (6)].string), (yyvsp[(5) - (6)].valueList));
        //if (!(yyval.mediaQueryExp))
        //    YYERROR;
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaQueryExpList) = parser->createFloatingMediaQueryExpList();
        //(yyval.mediaQueryExpList)->append(parser->sinkFloatingMediaQueryExp((yyvsp[(1) - (1)].mediaQueryExp)));
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaQueryExpList) = (yyvsp[(1) - (5)].mediaQueryExpList);
        //(yyval.mediaQueryExpList)->append(parser->sinkFloatingMediaQueryExp((yyvsp[(5) - (5)].mediaQueryExp)));
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaQueryExpList) = parser->createFloatingMediaQueryExpList();
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaQueryExpList) = (yyvsp[(4) - (5)].mediaQueryExpList);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaQueryRestrictor) = MediaQuery::None;
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaQueryRestrictor) = MediaQuery::Only;
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaQueryRestrictor) = MediaQuery::Not;
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaQuery) = parser->createFloatingMediaQuery(parser->sinkFloatingMediaQueryExpList((yyvsp[(1) - (2)].mediaQueryExpList)));
    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
    {
        parser->tokenToLowerCase((yyvsp[(2) - (3)].string));
        //(yyval.mediaQuery) = parser->createFloatingMediaQuery((yyvsp[(1) - (3)].mediaQueryRestrictor), (yyvsp[(2) - (3)].string), parser->sinkFloatingMediaQueryExpList((yyvsp[(3) - (3)].mediaQueryExpList)));
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError(parser->lastLocationLabel(), InvalidMediaQueryCSSError);
        //(yyval.mediaQuery) = parser->createFloatingNotAllQuery();
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError(parser->lastLocationLabel(), InvalidMediaQueryCSSError);
        //(yyval.mediaQuery) = parser->createFloatingNotAllQuery();
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaList) = parser->createMediaQuerySet();
    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaList) = parser->createMediaQuerySet();
        //(yyval.mediaList)->addMediaQuery(parser->sinkFloatingMediaQuery((yyvsp[(1) - (1)].mediaQuery)));
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaList) = (yyvsp[(1) - (2)].mediaList);
        //(yyval.mediaList)->addMediaQuery(parser->sinkFloatingMediaQuery((yyvsp[(2) - (2)].mediaQuery)));
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaList) = (yyvsp[(1) - (1)].mediaList);
        //(yyval.mediaList)->addMediaQuery(parser->sinkFloatingMediaQuery(parser->createFloatingNotAllQuery()));
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaList) = parser->createMediaQuerySet();
        //(yyval.mediaList)->addMediaQuery(parser->sinkFloatingMediaQuery((yyvsp[(1) - (4)].mediaQuery)));
    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
    {
        //(yyval.mediaList) = (yyvsp[(1) - (5)].mediaList);
        //(yyval.mediaList)->addMediaQuery(parser->sinkFloatingMediaQuery((yyvsp[(2) - (5)].mediaQuery)));
    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
    {
        parser->startRuleBody();
    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
    {
        parser->startRuleHeader(CSSRuleSourceData::MEDIA_RULE);
    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
    {
        parser->endRuleHeader();
    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = parser->createMediaRule((yyvsp[(2) - (8)].mediaList), (yyvsp[(7) - (8)].ruleList));
    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = parser->createSupportsRule((yyvsp[(4) - (10)].boolean), (yyvsp[(9) - (10)].ruleList));
    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
    {
        parser->startRuleHeader(CSSRuleSourceData::SUPPORTS_RULE);
        parser->markSupportsRuleHeaderStart();
    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
    {
        parser->endRuleHeader();
        parser->markSupportsRuleHeaderEnd();
    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = !(yyvsp[(3) - (3)].boolean);
    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = (yyvsp[(1) - (4)].boolean) && (yyvsp[(4) - (4)].boolean);
    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = (yyvsp[(1) - (4)].boolean) && (yyvsp[(4) - (4)].boolean);
    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = (yyvsp[(1) - (4)].boolean) || (yyvsp[(4) - (4)].boolean);
    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = (yyvsp[(1) - (4)].boolean) || (yyvsp[(4) - (4)].boolean);
    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = (yyvsp[(3) - (5)].boolean);
    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(3) - (6)].location), InvalidSupportsConditionCSSError);
        (yyval.boolean) = false;
    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = false;
        CSSPropertyID id = cssPropertyID((yyvsp[(3) - (10)].string));
        if (id != CSSPropertyInvalid) {
            parser->m_valueList = parser->sinkFloatingValueList((yyvsp[(7) - (10)].valueList));
            int oldParsedProperties = parser->m_parsedProperties.size();
            (yyval.boolean) = parser->parseValue(id, (yyvsp[(8) - (10)].boolean));
            // We just need to know if the declaration is supported as it is written. Rollback any additions.
            if ((yyval.boolean))
                parser->rollbackLastProperties(parser->m_parsedProperties.size() - oldParsedProperties);
        }
        parser->m_valueList = nullptr;
        //parser->endProperty((yyvsp[(8) - (10)].boolean), false);
    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = false;
        //parser->endProperty(false, false, GeneralCSSError);
    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
    {
        parser->startRuleHeader(CSSRuleSourceData::KEYFRAMES_RULE);
    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = false;
    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = true;
    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = parser->createKeyframesRule((yyvsp[(2) - (9)].string), parser->sinkFloatingKeyframeVector((yyvsp[(8) - (9)].keyframeRuleList)), (yyvsp[(1) - (9)].boolean) /* isPrefixed */);
    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
    {
        parser->clearProperties();
    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
    {
        (yyval.keyframeRuleList) = parser->createFloatingKeyframeVector();
        parser->resumeErrorLogging();
    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
    {
        (yyval.keyframeRuleList) = (yyvsp[(1) - (4)].keyframeRuleList);
        (yyval.keyframeRuleList)->append((yyvsp[(2) - (4)].keyframe));
    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
    {
        parser->clearProperties();
        parser->resumeErrorLogging();
    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
    {
        (yyval.keyframe) = parser->createKeyframe((yyvsp[(1) - (5)].valueList));
    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = parser->createFloatingValueList();
        (yyval.valueList)->addValue(parser->sinkFloatingValue((yyvsp[(1) - (2)].value)));
    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(1) - (5)].valueList);
        (yyval.valueList)->addValue(parser->sinkFloatingValue((yyvsp[(4) - (5)].value)));
    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
    {
        (yyval.value).setFromNumber((yyvsp[(1) - (2)].integer) * (yyvsp[(2) - (2)].number));
    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
    {
        if ((yyvsp[(1) - (1)].string).equalIgnoringCase("from"))
            (yyval.value).setFromNumber(0);
        else if ((yyvsp[(1) - (1)].string).equalIgnoringCase("to"))
            (yyval.value).setFromNumber(100);
        else {
            YYERROR;
        }
    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError(parser->lastLocationLabel(), InvalidKeyframeSelectorCSSError);
    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
    {
        parser->startRuleHeader(CSSRuleSourceData::PAGE_RULE);
    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
    {
        //if ((yyvsp[(4) - (10)].selector))
        //    (yyval.rule) = parser->createPageRule(parser->sinkFloatingSelector((yyvsp[(4) - (10)].selector)));
        //else {
        //    // Clear properties in the invalid @page rule.
        //    parser->clearProperties();
        //    // Also clear margin at-rules here once we fully implement margin at-rules parsing.
        //    (yyval.rule) = 0;
        //}
    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelectorWithTagName(QualifiedName(nullAtom, (yyvsp[(1) - (2)].string), parser->m_defaultNamespace));
        (yyval.selector)->setForPage();
    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = (yyvsp[(2) - (3)].selector);
        (yyval.selector)->prependTagSelector(QualifiedName(nullAtom, (yyvsp[(1) - (3)].string), parser->m_defaultNamespace));
        (yyval.selector)->setForPage();
    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = (yyvsp[(1) - (2)].selector);
        (yyval.selector)->setForPage();
    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setForPage();
    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
    {
        parser->startDeclarationsForMarginBox();
    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = parser->createMarginAtRule((yyvsp[(1) - (7)].marginBox));
    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::TopLeftCornerMarginBox;
    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::TopLeftMarginBox;
    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::TopCenterMarginBox;
    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::TopRightMarginBox;
    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::TopRightCornerMarginBox;
    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::BottomLeftCornerMarginBox;
    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::BottomLeftMarginBox;
    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::BottomCenterMarginBox;
    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::BottomRightMarginBox;
    ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::BottomRightCornerMarginBox;
    ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::LeftTopMarginBox;
    ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::LeftMiddleMarginBox;
    ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::LeftBottomMarginBox;
    ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::RightTopMarginBox;
    ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::RightMiddleMarginBox;
    ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
    {
        (yyval.marginBox) = CSSSelector::RightBottomMarginBox;
    ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
    {
        parser->startRuleHeader(CSSRuleSourceData::FONT_FACE_RULE);
    ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = parser->createFontFaceRule();
    ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
    {
        parser->markViewportRuleBodyStart();
        parser->startRuleHeader(CSSRuleSourceData::VIEWPORT_RULE);
    ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = parser->createViewportRule();
        parser->markViewportRuleBodyEnd();
    ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
    { (yyval.relation) = CSSSelector::DirectAdjacent; ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
    { (yyval.relation) = CSSSelector::IndirectAdjacent; ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
    { (yyval.relation) = CSSSelector::Child; ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
    {
        if (!RuntimeEnabledFeatures::shadowDOMEnabled())
            YYERROR;
        if ((yyvsp[(2) - (4)].string).equalIgnoringCase("shadow"))
            (yyval.relation) = CSSSelector::Shadow;
        else if ((yyvsp[(2) - (4)].string).equalIgnoringCase("shadow-deep"))
            (yyval.relation) = CSSSelector::ShadowDeep;
        else if ((yyvsp[(2) - (4)].string).equalIgnoringCase("content"))
            (yyval.relation) = CSSSelector::ShadowContent;
        else
            YYERROR;
    ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
    { (yyval.integer) = 1; ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
    { (yyval.integer) = -1; ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
    { (yyval.integer) = 1; ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
    {
        parser->startProperty();
    ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
    {
        parser->startRuleHeader(CSSRuleSourceData::STYLE_RULE);
        parser->startSelector();
    ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
    {
        parser->endRuleHeader();
    ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
    {
        parser->endSelector();
    ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
    {
        //(yyval.rule) = parser->createStyleRule((yyvsp[(2) - (9)].selectorList));
    ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
    {
        parser->startSelector();
    ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
    {
        (yyval.selectorList) = parser->reusableSelectorVector();
        (yyval.selectorList)->shrink(0);
        (yyval.selectorList)->append(parser->sinkFloatingSelector((yyvsp[(1) - (1)].selector)));
    ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
    {
        (yyval.selectorList) = (yyvsp[(1) - (6)].selectorList);
        (yyval.selectorList)->append(parser->sinkFloatingSelector((yyvsp[(6) - (6)].selector)));
    ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = (yyvsp[(2) - (2)].selector);
        CSSParserSelector* end = (yyval.selector);
        while (end->tagHistory())
            end = end->tagHistory();
        end->setRelation((yyvsp[(1) - (2)].relation));
    ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = (yyvsp[(3) - (3)].selector);
        CSSParserSelector* end = (yyval.selector);
        while (end->tagHistory())
            end = end->tagHistory();
        end->setRelation(CSSSelector::Descendant);
        end->setTagHistory(parser->sinkFloatingSelector((yyvsp[(1) - (3)].selector)));
    ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = (yyvsp[(3) - (3)].selector);
        CSSParserSelector* end = (yyval.selector);
        while (end->tagHistory())
            end = end->tagHistory();
        end->setRelation((yyvsp[(2) - (3)].relation));
        end->setTagHistory(parser->sinkFloatingSelector((yyvsp[(1) - (3)].selector)));
    ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
    { (yyval.string).clear(); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
    { static const LChar star = '*'; (yyval.string).init(&star, 1); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelectorWithTagName(QualifiedName(nullAtom, (yyvsp[(1) - (1)].string), parser->m_defaultNamespace));
    ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->rewriteSpecifiersWithElementName(nullAtom, (yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].selector));
        if (!(yyval.selector))
            YYERROR;
    ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->rewriteSpecifiersWithNamespaceIfNeeded((yyvsp[(1) - (1)].selector));
        if (!(yyval.selector))
            YYERROR;
    ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelectorWithTagName(parser->determineNameInNamespace((yyvsp[(1) - (2)].string), (yyvsp[(2) - (2)].string)));
        if (!(yyval.selector))
            YYERROR;
    ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->rewriteSpecifiersWithElementName((yyvsp[(1) - (3)].string), (yyvsp[(2) - (3)].string), (yyvsp[(3) - (3)].selector));
        if (!(yyval.selector))
            YYERROR;
    ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->rewriteSpecifiersWithElementName((yyvsp[(1) - (2)].string), starAtom, (yyvsp[(2) - (2)].selector));
        if (!(yyval.selector))
            YYERROR;
    ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
    {
        (yyval.selectorList) = parser->createFloatingSelectorVector();
        (yyval.selectorList)->append(parser->sinkFloatingSelector((yyvsp[(1) - (1)].selector)));
    ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
    {
        (yyval.selectorList) = (yyvsp[(1) - (5)].selectorList);
        (yyval.selectorList)->append(parser->sinkFloatingSelector((yyvsp[(5) - (5)].selector)));
    ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
    {
        if (parser->m_context.isHTMLDocument())
            parser->tokenToLowerCase((yyvsp[(1) - (1)].string));
        (yyval.string) = (yyvsp[(1) - (1)].string);
    ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
    {
        static const LChar star = '*';
        (yyval.string).init(&star, 1);
    ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->rewriteSpecifiers((yyvsp[(1) - (2)].selector), (yyvsp[(2) - (2)].selector));
    ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::Id);
        if (isQuirksModeBehavior(parser->m_context.mode()))
            parser->tokenToLowerCase((yyvsp[(1) - (1)].string));
        (yyval.selector)->setValue((yyvsp[(1) - (1)].string));
    ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
    {
        if ((yyvsp[(1) - (1)].string)[0] >= '0' && (yyvsp[(1) - (1)].string)[0] <= '9') {
            YYERROR;
        } else {
            (yyval.selector) = parser->createFloatingSelector();
            (yyval.selector)->setMatch(CSSSelector::Id);
            if (isQuirksModeBehavior(parser->m_context.mode()))
                parser->tokenToLowerCase((yyvsp[(1) - (1)].string));
            (yyval.selector)->setValue((yyvsp[(1) - (1)].string));
        }
    ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::Class);
        if (isQuirksModeBehavior(parser->m_context.mode()))
            parser->tokenToLowerCase((yyvsp[(2) - (2)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (2)].string));
    ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
    {
        if (parser->m_context.isHTMLDocument())
            parser->tokenToLowerCase((yyvsp[(1) - (2)].string));
        (yyval.string) = (yyvsp[(1) - (2)].string);
    ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setAttribute(QualifiedName(nullAtom, (yyvsp[(3) - (4)].string), nullAtom));
        (yyval.selector)->setMatch(CSSSelector::Set);
    ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setAttribute(QualifiedName(nullAtom, (yyvsp[(3) - (8)].string), nullAtom));
        (yyval.selector)->setMatch((CSSSelector::Match)(yyvsp[(4) - (8)].integer));
        (yyval.selector)->setValue((yyvsp[(6) - (8)].string));
    ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setAttribute(parser->determineNameInNamespace((yyvsp[(3) - (5)].string), (yyvsp[(4) - (5)].string)));
        (yyval.selector)->setMatch(CSSSelector::Set);
    ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setAttribute(parser->determineNameInNamespace((yyvsp[(3) - (9)].string), (yyvsp[(4) - (9)].string)));
        (yyval.selector)->setMatch((CSSSelector::Match)(yyvsp[(5) - (9)].integer));
        (yyval.selector)->setValue((yyvsp[(7) - (9)].string));
    ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
    {
        (yyval.integer) = CSSSelector::Exact;
    ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
    {
        (yyval.integer) = CSSSelector::List;
    ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
    {
        (yyval.integer) = CSSSelector::Hyphen;
    ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
    {
        (yyval.integer) = CSSSelector::Begin;
    ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
    {
        (yyval.integer) = CSSSelector::End;
    ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
    {
        (yyval.integer) = CSSSelector::Contain;
    ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
    {
        if ((yyvsp[(2) - (2)].string).isFunction())
            YYERROR;
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PagePseudoClass);
        parser->tokenToLowerCase((yyvsp[(2) - (2)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (2)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type == CSSSelector::PseudoUnknown)
            YYERROR;
    ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
    {
        if ((yyvsp[(3) - (3)].string).isFunction())
            YYERROR;
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        parser->tokenToLowerCase((yyvsp[(3) - (3)].string));
        (yyval.selector)->setValue((yyvsp[(3) - (3)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type == CSSSelector::PseudoUnknown) {
            //parser->reportError((yyvsp[(2) - (3)].location), InvalidSelectorPseudoCSSError);
            YYERROR;
        }
    ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
    {
        if ((yyvsp[(4) - (4)].string).isFunction())
            YYERROR;
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoElement);
        parser->tokenToLowerCase((yyvsp[(4) - (4)].string));
        (yyval.selector)->setValue((yyvsp[(4) - (4)].string));
        // FIXME: This call is needed to force selector to compute the pseudoType early enough.
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type == CSSSelector::PseudoUnknown) {
            //parser->reportError((yyvsp[(3) - (4)].location), InvalidSelectorPseudoCSSError);
            YYERROR;
        }
    ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoElement);
        (yyval.selector)->adoptSelectorVector(*parser->sinkFloatingSelectorVector((yyvsp[(5) - (7)].selectorList)));
        (yyval.selector)->setValue((yyvsp[(3) - (7)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type != CSSSelector::PseudoCue)
            YYERROR;
    ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoElement);
        (yyval.selector)->setFunctionArgumentSelector((yyvsp[(5) - (6)].selector));
        parser->tokenToLowerCase((yyvsp[(3) - (6)].string));
        (yyval.selector)->setValue((yyvsp[(3) - (6)].string));
    ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        (yyval.selector)->adoptSelectorVector(*parser->sinkFloatingSelectorVector((yyvsp[(4) - (6)].selectorList)));
        parser->tokenToLowerCase((yyvsp[(2) - (6)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (6)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type != CSSSelector::PseudoAny)
            YYERROR;
    ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        (yyval.selector)->setArgument((yyvsp[(4) - (6)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (6)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type == CSSSelector::PseudoUnknown)
            YYERROR;
    ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        (yyval.selector)->setArgument(AtomicString::number((yyvsp[(4) - (7)].integer) * (yyvsp[(5) - (7)].number)));
        (yyval.selector)->setValue((yyvsp[(2) - (7)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type == CSSSelector::PseudoUnknown)
            YYERROR;
    ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        (yyval.selector)->setArgument((yyvsp[(4) - (6)].string));
        parser->tokenToLowerCase((yyvsp[(2) - (6)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (6)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type == CSSSelector::PseudoUnknown)
            YYERROR;
        else if (type == CSSSelector::PseudoNthChild ||
                 type == CSSSelector::PseudoNthOfType ||
                 type == CSSSelector::PseudoNthLastChild ||
                 type == CSSSelector::PseudoNthLastOfType) {
            if (!isValidNthToken((yyvsp[(4) - (6)].string)))
                YYERROR;
        }
    ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
    {
        if (!(yyvsp[(4) - (6)].selector)->isSimple())
            YYERROR;
        else {
            (yyval.selector) = parser->createFloatingSelector();
            (yyval.selector)->setMatch(CSSSelector::PseudoClass);

            Vector<OwnPtr<CSSParserSelector> > selectorVector;
            selectorVector.append(parser->sinkFloatingSelector((yyvsp[(4) - (6)].selector)));
            (yyval.selector)->adoptSelectorVector(selectorVector);

            parser->tokenToLowerCase((yyvsp[(2) - (6)].string));
            (yyval.selector)->setValue((yyvsp[(2) - (6)].string));
        }
    ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        (yyval.selector)->adoptSelectorVector(*parser->sinkFloatingSelectorVector((yyvsp[(4) - (6)].selectorList)));
        parser->tokenToLowerCase((yyvsp[(2) - (6)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (6)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type != CSSSelector::PseudoHost)
            YYERROR;
    ;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        parser->tokenToLowerCase((yyvsp[(2) - (4)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (4)].string).atomicSubstring(0, (yyvsp[(2) - (4)].string).length() - 1));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type != CSSSelector::PseudoHost)
            YYERROR;
    ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        (yyval.selector)->adoptSelectorVector(*parser->sinkFloatingSelectorVector((yyvsp[(4) - (6)].selectorList)));
        parser->tokenToLowerCase((yyvsp[(2) - (6)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (6)].string));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type != CSSSelector::PseudoAncestor)
            YYERROR;
    ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
    {
        (yyval.selector) = parser->createFloatingSelector();
        (yyval.selector)->setMatch(CSSSelector::PseudoClass);
        parser->tokenToLowerCase((yyvsp[(2) - (4)].string));
        (yyval.selector)->setValue((yyvsp[(2) - (4)].string).atomicSubstring(0, (yyvsp[(2) - (4)].string).length() - 1));
        CSSSelector::PseudoType type = (yyval.selector)->pseudoType();
        if (type != CSSSelector::PseudoAncestor)
            YYERROR;
    ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
    { (yyval.boolean) = false; ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = (yyvsp[(1) - (2)].boolean) || (yyvsp[(2) - (2)].boolean);
    ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
    {
        parser->startProperty();
        (yyval.boolean) = (yyvsp[(1) - (3)].boolean);
    ;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
    {
        parser->startProperty();
        (yyval.boolean) = (yyvsp[(1) - (4)].boolean) || (yyvsp[(2) - (4)].boolean);
    ;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
    {
        (yyval.boolean) = false;
        bool isPropertyParsed = false;
        if ((yyvsp[(1) - (6)].id) != CSSPropertyInvalid) {
            parser->m_valueList = parser->sinkFloatingValueList((yyvsp[(5) - (6)].valueList));
            int oldParsedProperties = parser->m_parsedProperties.size();
            (yyval.boolean) = parser->parseValue((yyvsp[(1) - (6)].id), (yyvsp[(6) - (6)].boolean));
            if (!(yyval.boolean)) {
                parser->rollbackLastProperties(parser->m_parsedProperties.size() - oldParsedProperties);
                //parser->reportError((yyvsp[(4) - (6)].location), InvalidPropertyValueCSSError);
            } else
                isPropertyParsed = true;
            parser->m_valueList = nullptr;
        }
        //parser->endProperty((yyvsp[(6) - (6)].boolean), isPropertyParsed);
    ;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
    {
        /* When we encounter something like p {color: red !important fail;} we should drop the declaration */
        //parser->reportError((yyvsp[(4) - (8)].location), InvalidPropertyValueCSSError);
        //parser->endProperty(false, false);
        (yyval.boolean) = false;
    ;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(4) - (6)].location), InvalidPropertyValueCSSError);
        //parser->endProperty(false, false);
        (yyval.boolean) = false;
    ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(3) - (4)].location), PropertyDeclarationCSSError);
        //parser->endProperty(false, false, GeneralCSSError);
        (yyval.boolean) = false;
    ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(2) - (3)].location), PropertyDeclarationCSSError);
        (yyval.boolean) = false;
    ;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
    {
        (yyval.id) = cssPropertyID((yyvsp[(2) - (3)].string));
        parser->setCurrentProperty((yyval.id));
        //if ((yyval.id) == CSSPropertyInvalid)
            //parser->reportError((yyvsp[(1) - (3)].location), InvalidPropertyCSSError);
    ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
    { (yyval.boolean) = true; ;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
    { (yyval.boolean) = false; ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = parser->createFloatingValueList();
        (yyval.valueList)->addValue(makeIdentValue((yyvsp[(1) - (2)].string)));
    ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(1) - (3)].valueList);
        (yyval.valueList)->addValue(makeIdentValue((yyvsp[(2) - (3)].string)));
    ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
    {
        (yyval.value).setFromValueList(parser->sinkFloatingValueList(parser->createFloatingValueList()));
    ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
    {
        (yyval.value).setFromValueList(parser->sinkFloatingValueList((yyvsp[(3) - (4)].valueList)));
    ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = parser->createFloatingValueList();
        (yyval.valueList)->addValue(parser->sinkFloatingValue((yyvsp[(1) - (1)].value)));
    ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(1) - (3)].valueList);
        (yyval.valueList)->addValue(makeOperatorValue((yyvsp[(2) - (3)].character)));
        (yyval.valueList)->addValue(parser->sinkFloatingValue((yyvsp[(3) - (3)].value)));
    ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(1) - (2)].valueList);
        (yyval.valueList)->addValue(parser->sinkFloatingValue((yyvsp[(2) - (2)].value)));
    ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(2) - (3)].location), PropertyDeclarationCSSError);
    ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
    {
        (yyval.character) = '/';
    ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
    {
        (yyval.character) = ',';
    ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
    { (yyval.value) = (yyvsp[(2) - (3)].value); (yyval.value).fValue *= (yyvsp[(1) - (3)].integer); ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
    { (yyval.value).id = CSSValueInvalid; (yyval.value).string = (yyvsp[(1) - (2)].string); (yyval.value).unit = CSSPrimitiveValue::CSS_STRING; ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
    { (yyval.value) = makeIdentValue((yyvsp[(1) - (2)].string)); ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
    { (yyval.value).id = CSSValueInvalid; (yyval.value).string = (yyvsp[(1) - (2)].string); (yyval.value).unit = CSSPrimitiveValue::CSS_DIMENSION; ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
    { (yyval.value).id = CSSValueInvalid; (yyval.value).string = (yyvsp[(2) - (3)].string); (yyval.value).unit = CSSPrimitiveValue::CSS_DIMENSION; ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
    { (yyval.value).id = CSSValueInvalid; (yyval.value).string = (yyvsp[(1) - (2)].string); (yyval.value).unit = CSSPrimitiveValue::CSS_URI; ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
    { (yyval.value).id = CSSValueInvalid; (yyval.value).string = (yyvsp[(1) - (2)].string); (yyval.value).unit = CSSPrimitiveValue::CSS_UNICODE_RANGE; ;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
    { (yyval.value).id = CSSValueInvalid; (yyval.value).string = (yyvsp[(1) - (2)].string); (yyval.value).unit = CSSPrimitiveValue::CSS_PARSER_HEXCOLOR; ;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
    { (yyval.value).id = CSSValueInvalid; (yyval.value).string = CSSParserString(); (yyval.value).unit = CSSPrimitiveValue::CSS_PARSER_HEXCOLOR; ;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
    { /* Handle width: %; */
      (yyval.value).id = CSSValueInvalid; (yyval.value).unit = 0;
  ;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number)); (yyval.value).isInt = true; ;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number)); ;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_PERCENTAGE); ;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_PX); ;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_CM); ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_MM); ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_IN); ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_PT); ;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_PC); ;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_DEG); ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_RAD); ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_GRAD); ;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_TURN); ;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_MS); ;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_S); ;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_HZ); ;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_KHZ); ;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_EMS); ;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSParserValue::Q_EMS); ;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_EXS); ;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
    {
      (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_REMS);
      //if (parser->m_styleSheet)
          //parser->m_styleSheet->parserSetUsesRemUnits(true);
  ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_CHS); ;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_VW); ;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_VH); ;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_VMIN); ;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_VMAX); ;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_DPPX); ;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_DPI); ;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_DPCM); ;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
    { (yyval.value).setFromNumber((yyvsp[(1) - (1)].number), CSSPrimitiveValue::CSS_FR); ;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
    {
        (yyval.value).setFromFunction(parser->createFloatingFunction((yyvsp[(1) - (4)].string), parser->sinkFloatingValueList((yyvsp[(3) - (4)].valueList))));
    ;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
    {
        (yyval.value).setFromFunction(parser->createFloatingFunction((yyvsp[(1) - (3)].string), parser->sinkFloatingValueList(parser->createFloatingValueList())));
    ;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
    { (yyval.value) = (yyvsp[(2) - (2)].value); (yyval.value).fValue *= (yyvsp[(1) - (2)].integer); ;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
    {
        (yyval.character) = '+';
    ;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
    {
        (yyval.character) = '-';
    ;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
    {
        (yyval.character) = '*';
    ;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
    {
        (yyval.character) = '/';
    ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(3) - (5)].valueList);
        (yyval.valueList)->insertValueAt(0, makeOperatorValue('('));
        (yyval.valueList)->addValue(makeOperatorValue(')'));
    ;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = parser->createFloatingValueList();
        (yyval.valueList)->addValue(parser->sinkFloatingValue((yyvsp[(1) - (1)].value)));
    ;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(1) - (3)].valueList);
        (yyval.valueList)->addValue(makeOperatorValue((yyvsp[(2) - (3)].character)));
        (yyval.valueList)->addValue(parser->sinkFloatingValue((yyvsp[(3) - (3)].value)));
    ;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(1) - (3)].valueList);
        (yyval.valueList)->addValue(makeOperatorValue((yyvsp[(2) - (3)].character)));
        (yyval.valueList)->stealValues(*((yyvsp[(3) - (3)].valueList)));
    ;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
    {
        (yyval.valueList) = (yyvsp[(1) - (5)].valueList);
        (yyval.valueList)->addValue(makeOperatorValue(','));
        (yyval.valueList)->stealValues(*((yyvsp[(4) - (5)].valueList)));
    ;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
    {
        (yyval.value).setFromFunction(parser->createFloatingFunction((yyvsp[(1) - (5)].string), parser->sinkFloatingValueList((yyvsp[(3) - (5)].valueList))));
    ;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
    {
        (yyval.value).setFromFunction(parser->createFloatingFunction((yyvsp[(1) - (4)].string), parser->sinkFloatingValueList((yyvsp[(3) - (4)].valueList))));
    ;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
    {
        YYERROR;
    ;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(2) - (3)].location), InvalidRuleCSSError);
    ;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(4) - (5)].location), InvalidSupportsConditionCSSError);
        parser->popSupportsRuleData();
    ;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
    {
        parser->markViewportRuleBodyEnd();
    ;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
    {
        parser->resumeErrorLogging();
        //parser->reportError((yyvsp[(1) - (3)].location), InvalidRuleCSSError);
    ;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(2) - (5)].location), InvalidRuleCSSError);
    ;}
    break;

  case 360:

/* Line 1455 of yacc.c  */
    {
        //parser->reportError((yyvsp[(2) - (4)].location), InvalidRuleCSSError);
    ;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
    {
       parser->endInvalidRuleHeader();
   ;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
    {
        parser->invalidBlockHit();
    ;}
    break;

  case 377:

/* Line 1455 of yacc.c  */
    {
        //(yyval.location) = parser->currentLocation();
    ;}
    break;

  case 378:

/* Line 1455 of yacc.c  */
    {
        //parser->setLocationLabel(parser->currentLocation());
    ;}
    break;



/* Line 1455 of yacc.c  */
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
      yyerror (parser, YY_("syntax error"));
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
	    yyerror (parser, yymsg);
	  }
	else
	  {
	    yyerror (parser, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
		      yytoken, &yylval, parser);
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
		  yystos[yystate], yyvsp, parser);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (parser, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, parser);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, parser);
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



/* Line 1675 of yacc.c  */



