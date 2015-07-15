#ifndef CSSGrammarH
#define CSSGrammarH

/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* Line 1676 of yacc.c  */
#line 68 "C:/MyWork/Chrome35/src/third_party/WebKit/Source/core/css/CSSGrammar.y"

    bool boolean;
    char character;
    int integer;
    double number;
    CSSParserString string;

    StyleRuleBase* rule;
    // The content of the two below HeapVectors are guaranteed to be kept alive by
    // the corresponding m_parsedRules and m_floatingMediaQueryExpList lists in BisonCSSParser.h.
    WillBeHeapVector<RefPtrWillBeMember<StyleRuleBase> >* ruleList;
    WillBeHeapVector<OwnPtrWillBeMember<MediaQueryExp> >* mediaQueryExpList;
    CSSParserSelector* selector;
    Vector<OwnPtr<CSSParserSelector> >* selectorList;
    CSSSelector::MarginBoxType marginBox;
    CSSSelector::Relation relation;
    MediaQuerySet* mediaList;
    MediaQuery* mediaQuery;
    MediaQuery::Restrictor mediaQueryRestrictor;
    MediaQueryExp* mediaQueryExp;
    CSSParserValue value;
    CSSParserValueList* valueList;
    StyleKeyframe* keyframe;
    Vector<RefPtr<StyleKeyframe> >* keyframeRuleList;
    float val;
    CSSPropertyID id;
    CSSParserLocation location;



/* Line 1676 of yacc.c  */
#line 187 "C:/MyWork/Chrome35/src/build/Debug/obj/global_intermediate/blink\\CSSGrammar.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif





#endif
