/*
 * Copyright (C) 2003 Lars Knoll (knoll@kde.org)
 * Copyright (C) 2005 Allan Sandfeld Jensen (kde@carewolf.com)
 * Copyright (C) 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012 Apple Inc. All rights reserved.
 * Copyright (C) 2007 Nicholas Shanks <webkit@nickshanks.com>
 * Copyright (C) 2008 Eric Seidel <eric@webkit.org>
 * Copyright (C) 2009 Torch Mobile Inc. All rights reserved. (http://www.torchmobile.com/)
 * Copyright (C) 2012 Adobe Systems Incorporated. All rights reserved.
 * Copyright (C) 2012 Intel Corporation. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "config.h"
#include "css/CSSTokenizer.h"

#include "css/CSSKeyframeRule.h"
#include "css/BisonCSSParser.h"
#include "css/CSSParserValues.h"
#include "css/StyleRule.h"
//#include "core/html/parser/HTMLParserIdioms.h"
//#include "core/svg/SVGParserUtilities.h"

namespace WebCore {

#include "CSSGrammar.h"

enum CharacterType {
    // Types for the main switch.

    // The first 4 types must be grouped together, as they
    // represent the allowed chars in an identifier.
    CharacterCaselessU,
    CharacterIdentifierStart,
    CharacterNumber,
    CharacterDash,

    CharacterOther,
    CharacterNull,
    CharacterWhiteSpace,
    CharacterEndMediaQueryOrSupports,
    CharacterEndNthChild,
    CharacterQuote,
    CharacterExclamationMark,
    CharacterHashmark,
    CharacterDollar,
    CharacterAsterisk,
    CharacterPlus,
    CharacterDot,
    CharacterSlash,
    CharacterLess,
    CharacterAt,
    CharacterBackSlash,
    CharacterXor,
    CharacterVerticalBar,
    CharacterTilde,
};

// 128 ASCII codes
static const CharacterType typesOfASCIICharacters[128] = {
/*   0 - Null               */ CharacterNull,
/*   1 - Start of Heading   */ CharacterOther,
/*   2 - Start of Text      */ CharacterOther,
/*   3 - End of Text        */ CharacterOther,
/*   4 - End of Transm.     */ CharacterOther,
/*   5 - Enquiry            */ CharacterOther,
/*   6 - Acknowledgment     */ CharacterOther,
/*   7 - Bell               */ CharacterOther,
/*   8 - Back Space         */ CharacterOther,
/*   9 - Horizontal Tab     */ CharacterWhiteSpace,
/*  10 - Line Feed          */ CharacterWhiteSpace,
/*  11 - Vertical Tab       */ CharacterOther,
/*  12 - Form Feed          */ CharacterWhiteSpace,
/*  13 - Carriage Return    */ CharacterWhiteSpace,
/*  14 - Shift Out          */ CharacterOther,
/*  15 - Shift In           */ CharacterOther,
/*  16 - Data Line Escape   */ CharacterOther,
/*  17 - Device Control 1   */ CharacterOther,
/*  18 - Device Control 2   */ CharacterOther,
/*  19 - Device Control 3   */ CharacterOther,
/*  20 - Device Control 4   */ CharacterOther,
/*  21 - Negative Ack.      */ CharacterOther,
/*  22 - Synchronous Idle   */ CharacterOther,
/*  23 - End of Transmit    */ CharacterOther,
/*  24 - Cancel             */ CharacterOther,
/*  25 - End of Medium      */ CharacterOther,
/*  26 - Substitute         */ CharacterOther,
/*  27 - Escape             */ CharacterOther,
/*  28 - File Separator     */ CharacterOther,
/*  29 - Group Separator    */ CharacterOther,
/*  30 - Record Separator   */ CharacterOther,
/*  31 - Unit Separator     */ CharacterOther,
/*  32 - Space              */ CharacterWhiteSpace,
/*  33 - !                  */ CharacterExclamationMark,
/*  34 - "                  */ CharacterQuote,
/*  35 - #                  */ CharacterHashmark,
/*  36 - $                  */ CharacterDollar,
/*  37 - %                  */ CharacterOther,
/*  38 - &                  */ CharacterOther,
/*  39 - '                  */ CharacterQuote,
/*  40 - (                  */ CharacterOther,
/*  41 - )                  */ CharacterEndNthChild,
/*  42 - *                  */ CharacterAsterisk,
/*  43 - +                  */ CharacterPlus,
/*  44 - ,                  */ CharacterOther,
/*  45 - -                  */ CharacterDash,
/*  46 - .                  */ CharacterDot,
/*  47 - /                  */ CharacterSlash,
/*  48 - 0                  */ CharacterNumber,
/*  49 - 1                  */ CharacterNumber,
/*  50 - 2                  */ CharacterNumber,
/*  51 - 3                  */ CharacterNumber,
/*  52 - 4                  */ CharacterNumber,
/*  53 - 5                  */ CharacterNumber,
/*  54 - 6                  */ CharacterNumber,
/*  55 - 7                  */ CharacterNumber,
/*  56 - 8                  */ CharacterNumber,
/*  57 - 9                  */ CharacterNumber,
/*  58 - :                  */ CharacterOther,
/*  59 - ;                  */ CharacterEndMediaQueryOrSupports,
/*  60 - <                  */ CharacterLess,
/*  61 - =                  */ CharacterOther,
/*  62 - >                  */ CharacterOther,
/*  63 - ?                  */ CharacterOther,
/*  64 - @                  */ CharacterAt,
/*  65 - A                  */ CharacterIdentifierStart,
/*  66 - B                  */ CharacterIdentifierStart,
/*  67 - C                  */ CharacterIdentifierStart,
/*  68 - D                  */ CharacterIdentifierStart,
/*  69 - E                  */ CharacterIdentifierStart,
/*  70 - F                  */ CharacterIdentifierStart,
/*  71 - G                  */ CharacterIdentifierStart,
/*  72 - H                  */ CharacterIdentifierStart,
/*  73 - I                  */ CharacterIdentifierStart,
/*  74 - J                  */ CharacterIdentifierStart,
/*  75 - K                  */ CharacterIdentifierStart,
/*  76 - L                  */ CharacterIdentifierStart,
/*  77 - M                  */ CharacterIdentifierStart,
/*  78 - N                  */ CharacterIdentifierStart,
/*  79 - O                  */ CharacterIdentifierStart,
/*  80 - P                  */ CharacterIdentifierStart,
/*  81 - Q                  */ CharacterIdentifierStart,
/*  82 - R                  */ CharacterIdentifierStart,
/*  83 - S                  */ CharacterIdentifierStart,
/*  84 - T                  */ CharacterIdentifierStart,
/*  85 - U                  */ CharacterCaselessU,
/*  86 - V                  */ CharacterIdentifierStart,
/*  87 - W                  */ CharacterIdentifierStart,
/*  88 - X                  */ CharacterIdentifierStart,
/*  89 - Y                  */ CharacterIdentifierStart,
/*  90 - Z                  */ CharacterIdentifierStart,
/*  91 - [                  */ CharacterOther,
/*  92 - \                  */ CharacterBackSlash,
/*  93 - ]                  */ CharacterOther,
/*  94 - ^                  */ CharacterXor,
/*  95 - _                  */ CharacterIdentifierStart,
/*  96 - `                  */ CharacterOther,
/*  97 - a                  */ CharacterIdentifierStart,
/*  98 - b                  */ CharacterIdentifierStart,
/*  99 - c                  */ CharacterIdentifierStart,
/* 100 - d                  */ CharacterIdentifierStart,
/* 101 - e                  */ CharacterIdentifierStart,
/* 102 - f                  */ CharacterIdentifierStart,
/* 103 - g                  */ CharacterIdentifierStart,
/* 104 - h                  */ CharacterIdentifierStart,
/* 105 - i                  */ CharacterIdentifierStart,
/* 106 - j                  */ CharacterIdentifierStart,
/* 107 - k                  */ CharacterIdentifierStart,
/* 108 - l                  */ CharacterIdentifierStart,
/* 109 - m                  */ CharacterIdentifierStart,
/* 110 - n                  */ CharacterIdentifierStart,
/* 111 - o                  */ CharacterIdentifierStart,
/* 112 - p                  */ CharacterIdentifierStart,
/* 113 - q                  */ CharacterIdentifierStart,
/* 114 - r                  */ CharacterIdentifierStart,
/* 115 - s                  */ CharacterIdentifierStart,
/* 116 - t                  */ CharacterIdentifierStart,
/* 117 - u                  */ CharacterCaselessU,
/* 118 - v                  */ CharacterIdentifierStart,
/* 119 - w                  */ CharacterIdentifierStart,
/* 120 - x                  */ CharacterIdentifierStart,
/* 121 - y                  */ CharacterIdentifierStart,
/* 122 - z                  */ CharacterIdentifierStart,
/* 123 - {                  */ CharacterEndMediaQueryOrSupports,
/* 124 - |                  */ CharacterVerticalBar,
/* 125 - }                  */ CharacterOther,
/* 126 - ~                  */ CharacterTilde,
/* 127 - Delete             */ CharacterOther,
};

// Utility functions for the CSS tokenizer.

template <typename CharacterType>
static inline bool isCSSLetter(CharacterType character)
{
    return character >= 128 || typesOfASCIICharacters[character] <= CharacterDash;
}

template <typename CharacterType>
static inline bool isCSSEscape(CharacterType character)
{
    return character >= ' ' && character != 127;
}

template <typename CharacterType>
static inline bool isURILetter(CharacterType character)
{
    return (character >= '*' && character != 127) || (character >= '#' && character <= '&') || character == '!';
}

template <typename CharacterType>
static inline bool isIdentifierStartAfterDash(CharacterType* currentCharacter)
{
    return isASCIIAlpha(currentCharacter[0]) || currentCharacter[0] == '_' || currentCharacter[0] >= 128
        || (currentCharacter[0] == '\\' && isCSSEscape(currentCharacter[1]));
}

template <typename CharacterType>
static inline bool isEqualToCSSIdentifier(CharacterType* cssString, const char* constantString)
{
    // Compare an character memory data with a zero terminated string.
    do {
        // The input must be part of an identifier if constantChar or constString
        // contains '-'. Otherwise toASCIILowerUnchecked('\r') would be equal to '-'.
        ASSERT((*constantString >= 'a' && *constantString <= 'z') || *constantString == '-');
        ASSERT(*constantString != '-' || isCSSLetter(*cssString));
        if (toASCIILowerUnchecked(*cssString++) != (*constantString++))
            return false;
    } while (*constantString);
    return true;
}

template <typename CharacterType>
static inline bool isEqualToCSSCaseSensitiveIdentifier(CharacterType* string, const char* constantString)
{
    ASSERT(*constantString);

    do {
        if (*string++ != *constantString++)
            return false;
    } while (*constantString);
    return true;
}

template <typename CharacterType>
static CharacterType* checkAndSkipEscape(CharacterType* currentCharacter)
{
    // Returns with 0, if escape check is failed. Otherwise
    // it returns with the following character.
    ASSERT(*currentCharacter == '\\');

    ++currentCharacter;
    if (!isCSSEscape(*currentCharacter))
        return 0;

    if (isASCIIHexDigit(*currentCharacter)) {
        int length = 6;

        do {
            ++currentCharacter;
        } while (isASCIIHexDigit(*currentCharacter) && --length);

        // Optional space after the escape sequence.
        if (isHTMLSpace<CharacterType>(*currentCharacter))
            ++currentCharacter;
        return currentCharacter;
    }
    return currentCharacter + 1;
}

template <typename CharacterType>
static inline CharacterType* skipWhiteSpace(CharacterType* currentCharacter)
{
    while (isHTMLSpace<CharacterType>(*currentCharacter))
        ++currentCharacter;
    return currentCharacter;
}

// Main CSS tokenizer functions.

template <>
inline LChar*& CSSTokenizer::currentCharacter<LChar>()
{
    return m_currentCharacter8;
}

template <>
inline UChar*& CSSTokenizer::currentCharacter<UChar>()
{
    return m_currentCharacter16;
}

UChar*& CSSTokenizer::currentCharacter16()
{
    if (!m_currentCharacter16) {
        m_dataStart16 = adoptArrayPtr(new UChar[m_length]);
        m_currentCharacter16 = m_dataStart16.get();
    }

    return m_currentCharacter16;
}

template <>
inline LChar* CSSTokenizer::dataStart<LChar>()
{
    return m_dataStart8.get();
}

template <>
inline UChar* CSSTokenizer::dataStart<UChar>()
{
    return m_dataStart16.get();
}

template <typename CharacterType>
inline CSSParserLocation CSSTokenizer::tokenLocation()
{
    CSSParserLocation location;
    location.token.init(tokenStart<CharacterType>(), currentCharacter<CharacterType>() - tokenStart<CharacterType>());
    location.lineNumber = m_tokenStartLineNumber;
    location.offset = tokenStart<CharacterType>() - dataStart<CharacterType>();
    return location;
}

CSSParserLocation CSSTokenizer::currentLocation()
{
    if (is8BitSource())
        return tokenLocation<LChar>();
    return tokenLocation<UChar>();
}

template <typename CharacterType>
inline bool CSSTokenizer::isIdentifierStart()
{
    // Check whether an identifier is started.
    return isIdentifierStartAfterDash((*currentCharacter<CharacterType>() != '-') ? currentCharacter<CharacterType>() : currentCharacter<CharacterType>() + 1);
}

template <typename CharacterType>
static inline CharacterType* checkAndSkipString(CharacterType* currentCharacter, int quote)
{
    // Returns with 0, if string check is failed. Otherwise
    // it returns with the following character. This is necessary
    // since we cannot revert escape sequences, thus strings
    // must be validated before parsing.
    while (true) {
        if (UNLIKELY(*currentCharacter == quote)) {
            // String parsing is successful.
            return currentCharacter + 1;
        }
        if (UNLIKELY(!*currentCharacter)) {
            // String parsing is successful up to end of input.
            return currentCharacter;
        }
        if (UNLIKELY(*currentCharacter <= '\r' && (*currentCharacter == '\n' || (*currentCharacter | 0x1) == '\r'))) {
            // String parsing is failed for character '\n', '\f' or '\r'.
            return 0;
        }

        if (LIKELY(currentCharacter[0] != '\\')) {
            ++currentCharacter;
        } else if (currentCharacter[1] == '\n' || currentCharacter[1] == '\f') {
            currentCharacter += 2;
        } else if (currentCharacter[1] == '\r') {
            currentCharacter += currentCharacter[2] == '\n' ? 3 : 2;
        } else {
            currentCharacter = checkAndSkipEscape(currentCharacter);
            if (!currentCharacter)
                return 0;
        }
    }
}

template <typename CharacterType>
unsigned CSSTokenizer::parseEscape(CharacterType*& src)
{
    ASSERT(*src == '\\' && isCSSEscape(src[1]));

    unsigned unicode = 0;

    ++src;
    if (isASCIIHexDigit(*src)) {

        int length = 6;

        do {
            unicode = (unicode << 4) + toASCIIHexValue(*src++);
        } while (--length && isASCIIHexDigit(*src));

        // Characters above 0x10ffff are not handled.
        if (unicode > 0x10ffff)
            unicode = 0xfffd;

        // Optional space after the escape sequence.
        if (isHTMLSpace<CharacterType>(*src))
            ++src;

        return unicode;
    }

    return *currentCharacter<CharacterType>()++;
}

template <>
inline void CSSTokenizer::UnicodeToChars<LChar>(LChar*& result, unsigned unicode)
{
    ASSERT(unicode <= 0xff);
    *result = unicode;

    ++result;
}

template <>
inline void CSSTokenizer::UnicodeToChars<UChar>(UChar*& result, unsigned unicode)
{
    // Replace unicode with a surrogate pairs when it is bigger than 0xffff
    if (U16_LENGTH(unicode) == 2) {
        *result++ = U16_LEAD(unicode);
        *result = U16_TRAIL(unicode);
    } else {
        *result = unicode;
    }

    ++result;
}

template <typename SrcCharacterType, typename DestCharacterType>
inline bool CSSTokenizer::parseIdentifierInternal(SrcCharacterType*& src, DestCharacterType*& result, bool& hasEscape)
{
    hasEscape = false;
    do {
        if (LIKELY(*src != '\\')) {
            *result++ = *src++;
        } else {
            hasEscape = true;
            SrcCharacterType* savedEscapeStart = src;
            unsigned unicode = parseEscape<SrcCharacterType>(src);
            if (unicode > 0xff && sizeof(DestCharacterType) == 1) {
                src = savedEscapeStart;
                return false;
            }
            UnicodeToChars(result, unicode);
        }
    } while (isCSSLetter(src[0]) || (src[0] == '\\' && isCSSEscape(src[1])));

    return true;
}

template <typename CharacterType>
inline void CSSTokenizer::parseIdentifier(CharacterType*& result, CSSParserString& resultString, bool& hasEscape)
{
    // If a valid identifier start is found, we can safely
    // parse the identifier until the next invalid character.
    ASSERT(isIdentifierStart<CharacterType>());

    CharacterType* start = currentCharacter<CharacterType>();
    if (UNLIKELY(!parseIdentifierInternal(currentCharacter<CharacterType>(), result, hasEscape))) {
        // Found an escape we couldn't handle with 8 bits, copy what has been recognized and continue
        ASSERT(is8BitSource());
        UChar*& result16 = currentCharacter16();
        UChar* start16 = result16;
        int i = 0;
        for (; i < result - start; i++)
            result16[i] = start[i];

        result16 += i;

        parseIdentifierInternal(currentCharacter<CharacterType>(), result16, hasEscape);

        resultString.init(start16, result16 - start16);

        return;
    }

    resultString.init(start, result - start);
}

template <typename SrcCharacterType, typename DestCharacterType>
inline bool CSSTokenizer::parseStringInternal(SrcCharacterType*& src, DestCharacterType*& result, UChar quote)
{
    while (true) {
        if (UNLIKELY(*src == quote)) {
            // String parsing is done.
            ++src;
            return true;
        }
        if (UNLIKELY(!*src)) {
            // String parsing is done, but don't advance pointer if at the end of input.
            return true;
        }
        ASSERT(*src > '\r' || (*src < '\n' && *src) || *src == '\v');

        if (LIKELY(src[0] != '\\')) {
            *result++ = *src++;
        } else if (src[1] == '\n' || src[1] == '\f') {
            src += 2;
        } else if (src[1] == '\r') {
            src += src[2] == '\n' ? 3 : 2;
        } else {
            SrcCharacterType* savedEscapeStart = src;
            unsigned unicode = parseEscape<SrcCharacterType>(src);
            if (unicode > 0xff && sizeof(DestCharacterType) == 1) {
                src = savedEscapeStart;
                return false;
            }
            UnicodeToChars(result, unicode);
        }
    }

    return true;
}

template <typename CharacterType>
inline void CSSTokenizer::parseString(CharacterType*& result, CSSParserString& resultString, UChar quote)
{
    CharacterType* start = currentCharacter<CharacterType>();

    if (UNLIKELY(!parseStringInternal(currentCharacter<CharacterType>(), result, quote))) {
        // Found an escape we couldn't handle with 8 bits, copy what has been recognized and continue
        ASSERT(is8BitSource());
        UChar*& result16 = currentCharacter16();
        UChar* start16 = result16;
        int i = 0;
        for (; i < result - start; i++)
            result16[i] = start[i];

        result16 += i;

        parseStringInternal(currentCharacter<CharacterType>(), result16, quote);

        resultString.init(start16, result16 - start16);
        return;
    }

    resultString.init(start, result - start);
}

template <typename CharacterType>
inline bool CSSTokenizer::findURI(CharacterType*& start, CharacterType*& end, UChar& quote)
{
    start = skipWhiteSpace(currentCharacter<CharacterType>());

    if (*start == '"' || *start == '\'') {
        quote = *start++;
        end = checkAndSkipString(start, quote);
        if (!end)
            return false;
    } else {
        quote = 0;
        end = start;
        while (isURILetter(*end)) {
            if (LIKELY(*end != '\\')) {
                ++end;
            } else {
                end = checkAndSkipEscape(end);
                if (!end)
                    return false;
            }
        }
    }

    end = skipWhiteSpace(end);
    if (*end != ')')
        return false;

    return true;
}

template <typename SrcCharacterType, typename DestCharacterType>
inline bool CSSTokenizer::parseURIInternal(SrcCharacterType*& src, DestCharacterType*& dest, UChar quote)
{
    if (quote) {
        ASSERT(quote == '"' || quote == '\'');
        return parseStringInternal(src, dest, quote);
    }

    while (isURILetter(*src)) {
        if (LIKELY(*src != '\\')) {
            *dest++ = *src++;
        } else {
            unsigned unicode = parseEscape<SrcCharacterType>(src);
            if (unicode > 0xff && sizeof(SrcCharacterType) == 1)
                return false;
            UnicodeToChars(dest, unicode);
        }
    }

    return true;
}

template <typename CharacterType>
inline void CSSTokenizer::parseURI(CSSParserString& string)
{
    CharacterType* uriStart;
    CharacterType* uriEnd;
    UChar quote;
    if (!findURI(uriStart, uriEnd, quote))
        return;

    CharacterType* dest = currentCharacter<CharacterType>() = uriStart;
    if (LIKELY(parseURIInternal(currentCharacter<CharacterType>(), dest, quote))) {
        string.init(uriStart, dest - uriStart);
    } else {
        // An escape sequence was encountered that can't be stored in 8 bits.
        // Reset the current character to the start of the URI and re-parse with
        // a 16-bit destination.
        ASSERT(is8BitSource());
        UChar* uriStart16 = currentCharacter16();
        currentCharacter<CharacterType>() = uriStart;
        bool result = parseURIInternal(currentCharacter<CharacterType>(), currentCharacter16(), quote);
        ASSERT_UNUSED(result, result);
        string.init(uriStart16, currentCharacter16() - uriStart16);
    }

    currentCharacter<CharacterType>() = uriEnd + 1;
    m_token = URI;
}

template <typename CharacterType>
inline bool CSSTokenizer::parseUnicodeRange()
{
    CharacterType* character = currentCharacter<CharacterType>() + 1;
    int length = 6;
    ASSERT(*currentCharacter<CharacterType>() == '+');

    while (isASCIIHexDigit(*character) && length) {
        ++character;
        --length;
    }

    if (length && *character == '?') {
        // At most 5 hex digit followed by a question mark.
        do {
            ++character;
            --length;
        } while (*character == '?' && length);
        currentCharacter<CharacterType>() = character;
        return true;
    }

    if (length < 6) {
        // At least one hex digit.
        if (character[0] == '-' && isASCIIHexDigit(character[1])) {
            // Followed by a dash and a hex digit.
            ++character;
            length = 6;
            do {
                ++character;
            } while (--length && isASCIIHexDigit(*character));
        }
        currentCharacter<CharacterType>() = character;
        return true;
    }
    return false;
}

template <typename CharacterType>
bool CSSTokenizer::parseNthChild()
{
    CharacterType* character = currentCharacter<CharacterType>();

    while (isASCIIDigit(*character))
        ++character;
    if (isASCIIAlphaCaselessEqual(*character, 'n')) {
        currentCharacter<CharacterType>() = character + 1;
        return true;
    }
    return false;
}

template <typename CharacterType>
bool CSSTokenizer::parseNthChildExtra()
{
    CharacterType* character = skipWhiteSpace(currentCharacter<CharacterType>());
    if (*character != '+' && *character != '-')
        return false;

    character = skipWhiteSpace(character + 1);
    if (!isASCIIDigit(*character))
        return false;

    do {
        ++character;
    } while (isASCIIDigit(*character));

    currentCharacter<CharacterType>() = character;
    return true;
}

template <typename CharacterType>
inline bool CSSTokenizer::detectFunctionTypeToken(int length)
{
    ASSERT(length > 0);
    CharacterType* name = tokenStart<CharacterType>();
switch (length) {
case 3: {
switch ((name[0] | 0x20)) {
case 'c': {
if (LIKELY((name[1] | 0x20) == 'u' && (name[2] | 0x20) == 'e')) {
            m_token = CUEFUNCTION;
            return true;
}
} break;
case 'n': {
if (LIKELY((name[1] | 0x20) == 'o' && (name[2] | 0x20) == 't')) {
            m_token = NOTFUNCTION;
            return true;
}
} break;
case 'u': {
if (LIKELY((name[1] | 0x20) == 'r' && (name[2] | 0x20) == 'l')) {
            m_token = URI;
            return true;
}
} break;
}
} break;
case 4: {
if ((name[0] | 0x20) == 'c') {
if (LIKELY((name[1] | 0x20) == 'a' && (name[2] | 0x20) == 'l' && (name[3] | 0x20) == 'c')) {
            m_token = CALCFUNCTION;
            return true;
}
} else if (LIKELY((name[0] | 0x20) == 'h')) {
if (LIKELY((name[1] | 0x20) == 'o' && (name[2] | 0x20) == 's' && (name[3] | 0x20) == 't')) {
            m_token = HOSTFUNCTION;
            return true;
}
}
} break;
case 8: {
if (LIKELY((name[0] | 0x20) == 'a' && (name[1] | 0x20) == 'n' && (name[2] | 0x20) == 'c' && (name[3] | 0x20) == 'e' && (name[4] | 0x20) == 's' && (name[5] | 0x20) == 't' && (name[6] | 0x20) == 'o' && (name[7] | 0x20) == 'r')) {
            m_token = ANCESTORFUNCTION;
            return true;
}
} break;
case 9: {
if (LIKELY((name[0] | 0x20) == 'n' && (name[1] | 0x20) == 't' && (name[2] | 0x20) == 'h' && name[3] == '-' && (name[4] | 0x20) == 'c' && (name[5] | 0x20) == 'h' && (name[6] | 0x20) == 'i' && (name[7] | 0x20) == 'l' && (name[8] | 0x20) == 'd')) {
            m_parsingMode = NthChildMode;
            return true;
}
} break;
case 11: {
if (LIKELY((name[0] | 0x20) == 'n' && (name[1] | 0x20) == 't' && (name[2] | 0x20) == 'h' && name[3] == '-' && (name[4] | 0x20) == 'o' && (name[5] | 0x20) == 'f' && name[6] == '-' && (name[7] | 0x20) == 't' && (name[8] | 0x20) == 'y' && (name[9] | 0x20) == 'p' && (name[10] | 0x20) == 'e')) {
            m_parsingMode = NthChildMode;
            return true;
}
} break;
case 14: {
if (LIKELY((name[0] | 0x20) == 'n' && (name[1] | 0x20) == 't' && (name[2] | 0x20) == 'h' && name[3] == '-' && (name[4] | 0x20) == 'l' && (name[5] | 0x20) == 'a' && (name[6] | 0x20) == 's' && (name[7] | 0x20) == 't' && name[8] == '-' && (name[9] | 0x20) == 'c' && (name[10] | 0x20) == 'h' && (name[11] | 0x20) == 'i' && (name[12] | 0x20) == 'l' && (name[13] | 0x20) == 'd')) {
            m_parsingMode = NthChildMode;
            return true;
}
} break;
case 16: {
if (LIKELY((name[0] | 0x20) == 'n' && (name[1] | 0x20) == 't' && (name[2] | 0x20) == 'h' && name[3] == '-' && (name[4] | 0x20) == 'l' && (name[5] | 0x20) == 'a' && (name[6] | 0x20) == 's' && (name[7] | 0x20) == 't' && name[8] == '-' && (name[9] | 0x20) == 'o' && (name[10] | 0x20) == 'f' && name[11] == '-' && (name[12] | 0x20) == 't' && (name[13] | 0x20) == 'y' && (name[14] | 0x20) == 'p' && (name[15] | 0x20) == 'e')) {
            m_parsingMode = NthChildMode;
            return true;
}
} break;
}
    return false;
}

template <typename CharacterType>
inline void CSSTokenizer::detectMediaQueryToken(int length)
{
    ASSERT(m_parsingMode == MediaQueryMode);
    CharacterType* name = tokenStart<CharacterType>();

switch (length) {
case 2: {
if (LIKELY((name[0] | 0x20) == 'o' && (name[1] | 0x20) == 'r')) {
            m_token = MEDIA_OR;
}
} break;
case 3: {
if ((name[0] | 0x20) == 'a') {
if (LIKELY((name[1] | 0x20) == 'n' && (name[2] | 0x20) == 'd')) {
            m_token = MEDIA_AND;
}
} else if (LIKELY((name[0] | 0x20) == 'n')) {
if (LIKELY((name[1] | 0x20) == 'o' && (name[2] | 0x20) == 't')) {
            m_token = MEDIA_NOT;
}
}
} break;
case 4: {
if (LIKELY((name[0] | 0x20) == 'o' && (name[1] | 0x20) == 'n' && (name[2] | 0x20) == 'l' && (name[3] | 0x20) == 'y')) {
            m_token = MEDIA_ONLY;
}
} break;
}
}

template <typename CharacterType>
inline void CSSTokenizer::detectNumberToken(CharacterType* type, int length)
{
    ASSERT(length > 0);

switch (length) {
case 1: {
if (LIKELY((type[0] | 0x20) == 's')) {
            m_token = SECS;
}
} break;
case 2: {
switch ((type[0] | 0x20)) {
case 'c': {
if ((type[1] | 0x20) == 'h') {
            m_token = CHS;
} else if (LIKELY((type[1] | 0x20) == 'm')) {
            m_token = CMS;
}
} break;
case 'e': {
if ((type[1] | 0x20) == 'm') {
            m_token = EMS;
} else if (LIKELY((type[1] | 0x20) == 'x')) {
            m_token = EXS;
}
} break;
case 'f': {
if (LIKELY((type[1] | 0x20) == 'r')) {
            m_token = FR;
}
} break;
case 'h': {
if (LIKELY((type[1] | 0x20) == 'z')) {
            m_token = HERTZ;
}
} break;
case 'i': {
if (LIKELY((type[1] | 0x20) == 'n')) {
            m_token = INS;
}
} break;
case 'm': {
if ((type[1] | 0x20) == 'm') {
            m_token = MMS;
} else if (LIKELY((type[1] | 0x20) == 's')) {
            m_token = MSECS;
}
} break;
case 'p': {
switch ((type[1] | 0x20)) {
case 'c': {
            m_token = PCS;
} break;
case 't': {
            m_token = PTS;
} break;
case 'x': {
            m_token = PXS;
} break;
}
} break;
case 'v': {
if ((type[1] | 0x20) == 'h') {
            m_token = VH;
} else if (LIKELY((type[1] | 0x20) == 'w')) {
            m_token = VW;
}
} break;
}
} break;
case 3: {
switch ((type[0] | 0x20)) {
case 'd': {
if ((type[1] | 0x20) == 'e') {
if (LIKELY((type[2] | 0x20) == 'g')) {
            m_token = DEGS;
}
} else if (LIKELY((type[1] | 0x20) == 'p')) {
if (LIKELY((type[2] | 0x20) == 'i')) {
            m_token = DPI;
}
}
} break;
case 'k': {
if (LIKELY((type[1] | 0x20) == 'h' && (type[2] | 0x20) == 'z')) {
            m_token = KHERTZ;
}
} break;
case 'r': {
if ((type[1] | 0x20) == 'a') {
if (LIKELY((type[2] | 0x20) == 'd')) {
            m_token = RADS;
}
} else if (LIKELY((type[1] | 0x20) == 'e')) {
if (LIKELY((type[2] | 0x20) == 'm')) {
            m_token = REMS;
}
}
} break;
}
} break;
case 4: {
switch ((type[0] | 0x20)) {
case 'd': {
if (LIKELY((type[1] | 0x20) == 'p')) {
if ((type[2] | 0x20) == 'c') {
if (LIKELY((type[3] | 0x20) == 'm')) {
            m_token = DPCM;
}
} else if (LIKELY((type[2] | 0x20) == 'p')) {
if (LIKELY((type[3] | 0x20) == 'x')) {
            // There is a discussion about the name of this unit on www-style.
            // Keep this compile time guard in place until that is resolved.
            // http://lists.w3.org/Archives/Public/www-style/2012May/0915.html
            m_token = DPPX;
}
}
}
} break;
case 'g': {
if (LIKELY((type[1] | 0x20) == 'r' && (type[2] | 0x20) == 'a' && (type[3] | 0x20) == 'd')) {
            m_token = GRADS;
}
} break;
case 't': {
if (LIKELY((type[1] | 0x20) == 'u' && (type[2] | 0x20) == 'r' && (type[3] | 0x20) == 'n')) {
            m_token = TURNS;
}
} break;
case 'v': {
if (LIKELY((type[1] | 0x20) == 'm')) {
if ((type[2] | 0x20) == 'a') {
if (LIKELY((type[3] | 0x20) == 'x')) {
            m_token = VMAX;
}
} else if (LIKELY((type[2] | 0x20) == 'i')) {
if (LIKELY((type[3] | 0x20) == 'n')) {
            m_token = VMIN;
}
}
}
} break;
}
} break;
case 5: {
if (LIKELY(type[0] == '_' && type[1] == '_' && (type[2] | 0x20) == 'q' && (type[3] | 0x20) == 'e' && (type[4] | 0x20) == 'm')) {
            m_token = QEMS;
}
} break;
}
}

template <typename CharacterType>
inline void CSSTokenizer::detectDashToken(int length)
{
    CharacterType* name = tokenStart<CharacterType>();

    // Ignore leading dash.
    ++name;
    --length;

switch (length) {
case 10: {
if (LIKELY((name[0] | 0x20) == 'w' && (name[1] | 0x20) == 'e' && (name[2] | 0x20) == 'b' && (name[3] | 0x20) == 'k' && (name[4] | 0x20) == 'i' && (name[5] | 0x20) == 't' && name[6] == '-')) {
if ((name[7] | 0x20) == 'a') {
if (LIKELY((name[8] | 0x20) == 'n' && (name[9] | 0x20) == 'y')) {
            m_token = ANYFUNCTION;
}
} else if (LIKELY((name[7] | 0x20) == 'm')) {
if ((name[8] | 0x20) == 'a') {
if (LIKELY((name[9] | 0x20) == 'x')) {
            m_token = MAXFUNCTION;
}
} else if (LIKELY((name[8] | 0x20) == 'i')) {
if (LIKELY((name[9] | 0x20) == 'n')) {
            m_token = MINFUNCTION;
}
}
}
}
} break;
case 11: {
if (LIKELY((name[0] | 0x20) == 'w' && (name[1] | 0x20) == 'e' && (name[2] | 0x20) == 'b' && (name[3] | 0x20) == 'k' && (name[4] | 0x20) == 'i' && (name[5] | 0x20) == 't' && name[6] == '-' && (name[7] | 0x20) == 'c' && (name[8] | 0x20) == 'a' && (name[9] | 0x20) == 'l' && (name[10] | 0x20) == 'c')) {
            m_token = CALCFUNCTION;
}
} break;
case 18: {
if (LIKELY((name[0] | 0x20) == 'w' && (name[1] | 0x20) == 'e' && (name[2] | 0x20) == 'b' && (name[3] | 0x20) == 'k' && (name[4] | 0x20) == 'i' && (name[5] | 0x20) == 't' && name[6] == '-' && (name[7] | 0x20) == 'd' && (name[8] | 0x20) == 'i' && (name[9] | 0x20) == 's' && (name[10] | 0x20) == 't' && (name[11] | 0x20) == 'r' && (name[12] | 0x20) == 'i' && (name[13] | 0x20) == 'b' && (name[14] | 0x20) == 'u' && (name[15] | 0x20) == 't' && (name[16] | 0x20) == 'e' && (name[17] | 0x20) == 'd')) {
            m_token = DISTRIBUTEDFUNCTION;
}
} break;
}
}

template <typename CharacterType>
inline void CSSTokenizer::detectAtToken(int length, bool hasEscape)
{
    CharacterType* name = tokenStart<CharacterType>();
    ASSERT(name[0] == '@' && length >= 2);

    // Ignore leading @.
    ++name;
    --length;

    // charset, font-face, import, media, namespace, page, supports,
    // -webkit-keyframes, keyframes, and -webkit-mediaquery are not affected by hasEscape.
switch (length) {
case 4: {
if (LIKELY((name[0] | 0x20) == 'p' && (name[1] | 0x20) == 'a' && (name[2] | 0x20) == 'g' && (name[3] | 0x20) == 'e')) {
            m_token = PAGE_SYM;
}
} break;
case 5: {
if (LIKELY((name[0] | 0x20) == 'm' && (name[1] | 0x20) == 'e' && (name[2] | 0x20) == 'd' && (name[3] | 0x20) == 'i' && (name[4] | 0x20) == 'a')) {
            m_parsingMode = MediaQueryMode;
            m_token = MEDIA_SYM;
}
} break;
case 6: {
if (LIKELY((name[0] | 0x20) == 'i' && (name[1] | 0x20) == 'm' && (name[2] | 0x20) == 'p' && (name[3] | 0x20) == 'o' && (name[4] | 0x20) == 'r' && (name[5] | 0x20) == 't')) {
            m_parsingMode = MediaQueryMode;
            m_token = IMPORT_SYM;
}
} break;
case 7: {
if (LIKELY((name[0] | 0x20) == 'c' && (name[1] | 0x20) == 'h' && (name[2] | 0x20) == 'a' && (name[3] | 0x20) == 'r' && (name[4] | 0x20) == 's' && (name[5] | 0x20) == 'e' && (name[6] | 0x20) == 't')) {
            if (name - 1 == dataStart<CharacterType>())
                m_token = CHARSET_SYM;
}
} break;
case 8: {
switch ((name[2] | 0x20)) {
case 'e': {
if (LIKELY((name[0] | 0x20) == 'v' && (name[1] | 0x20) == 'i' && (name[3] | 0x20) == 'w' && (name[4] | 0x20) == 'p' && (name[5] | 0x20) == 'o' && (name[6] | 0x20) == 'r' && (name[7] | 0x20) == 't')) {
            m_token = VIEWPORT_RULE_SYM;
}
} break;
case 'f': {
if (LIKELY((name[0] | 0x20) == 'l' && (name[1] | 0x20) == 'e' && (name[3] | 0x20) == 't' && name[4] == '-' && (name[5] | 0x20) == 't' && (name[6] | 0x20) == 'o' && (name[7] | 0x20) == 'p')) {
            if (LIKELY(!hasEscape))
                m_token = LEFTTOP_SYM;
}
} break;
case 'p': {
if ((name[0] | 0x20) == 's') {
if (LIKELY((name[1] | 0x20) == 'u' && (name[3] | 0x20) == 'p' && (name[4] | 0x20) == 'o' && (name[5] | 0x20) == 'r' && (name[6] | 0x20) == 't' && (name[7] | 0x20) == 's')) {
            m_parsingMode = SupportsMode;
            m_token = SUPPORTS_SYM;
}
} else if (LIKELY((name[0] | 0x20) == 't')) {
if (LIKELY((name[1] | 0x20) == 'o' && name[3] == '-' && (name[4] | 0x20) == 'l' && (name[5] | 0x20) == 'e' && (name[6] | 0x20) == 'f' && (name[7] | 0x20) == 't')) {
            if (LIKELY(!hasEscape))
                m_token = TOPLEFT_SYM;
}
}
} break;
}
} break;
case 9: {
switch ((name[1] | 0x20)) {
case 'a': {
if (LIKELY((name[0] | 0x20) == 'n' && (name[2] | 0x20) == 'm' && (name[3] | 0x20) == 'e' && (name[4] | 0x20) == 's' && (name[5] | 0x20) == 'p' && (name[6] | 0x20) == 'a' && (name[7] | 0x20) == 'c' && (name[8] | 0x20) == 'e')) {
            m_token = NAMESPACE_SYM;
}
} break;
case 'e': {
if (LIKELY((name[0] | 0x20) == 'k' && (name[2] | 0x20) == 'y' && (name[3] | 0x20) == 'f' && (name[4] | 0x20) == 'r' && (name[5] | 0x20) == 'a' && (name[6] | 0x20) == 'm' && (name[7] | 0x20) == 'e' && (name[8] | 0x20) == 's')) {
            if (RuntimeEnabledFeatures::cssAnimationUnprefixedEnabled())
                m_token = KEYFRAMES_SYM;
}
} break;
case 'i': {
if (LIKELY((name[0] | 0x20) == 'r' && (name[2] | 0x20) == 'g' && (name[3] | 0x20) == 'h' && (name[4] | 0x20) == 't' && name[5] == '-' && (name[6] | 0x20) == 't' && (name[7] | 0x20) == 'o' && (name[8] | 0x20) == 'p')) {
            if (LIKELY(!hasEscape))
                m_token = RIGHTTOP_SYM;
}
} break;
case 'o': {
if ((name[0] | 0x20) == 'f') {
if (LIKELY((name[2] | 0x20) == 'n' && (name[3] | 0x20) == 't' && name[4] == '-' && (name[5] | 0x20) == 'f' && (name[6] | 0x20) == 'a' && (name[7] | 0x20) == 'c' && (name[8] | 0x20) == 'e')) {
            m_token = FONT_FACE_SYM;
}
} else if (LIKELY((name[0] | 0x20) == 't')) {
if (LIKELY((name[2] | 0x20) == 'p' && name[3] == '-' && (name[4] | 0x20) == 'r' && (name[5] | 0x20) == 'i' && (name[6] | 0x20) == 'g' && (name[7] | 0x20) == 'h' && (name[8] | 0x20) == 't')) {
            if (LIKELY(!hasEscape))
                m_token = TOPRIGHT_SYM;
}
}
} break;
}
} break;
case 10: {
if (LIKELY((name[0] | 0x20) == 't' && (name[1] | 0x20) == 'o' && (name[2] | 0x20) == 'p' && name[3] == '-' && (name[4] | 0x20) == 'c' && (name[5] | 0x20) == 'e' && (name[6] | 0x20) == 'n' && (name[7] | 0x20) == 't' && (name[8] | 0x20) == 'e' && (name[9] | 0x20) == 'r')) {
            if (LIKELY(!hasEscape))
                m_token = TOPCENTER_SYM;
}
} break;
case 11: {
if (LIKELY((name[3] | 0x20) == 't')) {
if ((name[0] | 0x20) == 'b') {
if (LIKELY((name[1] | 0x20) == 'o' && (name[2] | 0x20) == 't' && (name[4] | 0x20) == 'o' && (name[5] | 0x20) == 'm' && name[6] == '-' && (name[7] | 0x20) == 'l' && (name[8] | 0x20) == 'e' && (name[9] | 0x20) == 'f' && (name[10] | 0x20) == 't')) {
            if (LIKELY(!hasEscape))
                m_token = BOTTOMLEFT_SYM;
}
} else if (LIKELY((name[0] | 0x20) == 'l')) {
if (LIKELY((name[1] | 0x20) == 'e' && (name[2] | 0x20) == 'f' && name[4] == '-')) {
if ((name[5] | 0x20) == 'b') {
if (LIKELY((name[6] | 0x20) == 'o' && (name[7] | 0x20) == 't' && (name[8] | 0x20) == 't' && (name[9] | 0x20) == 'o' && (name[10] | 0x20) == 'm')) {
            if (LIKELY(!hasEscape))
                m_token = LEFTBOTTOM_SYM;
}
} else if (LIKELY((name[5] | 0x20) == 'm')) {
if (LIKELY((name[6] | 0x20) == 'i' && (name[7] | 0x20) == 'd' && (name[8] | 0x20) == 'd' && (name[9] | 0x20) == 'l' && (name[10] | 0x20) == 'e')) {
            if (LIKELY(!hasEscape))
                m_token = LEFTMIDDLE_SYM;
}
}
}
}
}
} break;
case 12: {
if ((name[0] | 0x20) == 'b') {
if (LIKELY((name[1] | 0x20) == 'o' && (name[2] | 0x20) == 't' && (name[3] | 0x20) == 't' && (name[4] | 0x20) == 'o' && (name[5] | 0x20) == 'm' && name[6] == '-' && (name[7] | 0x20) == 'r' && (name[8] | 0x20) == 'i' && (name[9] | 0x20) == 'g' && (name[10] | 0x20) == 'h' && (name[11] | 0x20) == 't')) {
            if (LIKELY(!hasEscape))
                m_token = BOTTOMRIGHT_SYM;
}
} else if (LIKELY((name[0] | 0x20) == 'r')) {
if (LIKELY((name[1] | 0x20) == 'i' && (name[2] | 0x20) == 'g' && (name[3] | 0x20) == 'h' && (name[4] | 0x20) == 't' && name[5] == '-')) {
if ((name[6] | 0x20) == 'b') {
if (LIKELY((name[7] | 0x20) == 'o' && (name[8] | 0x20) == 't' && (name[9] | 0x20) == 't' && (name[10] | 0x20) == 'o' && (name[11] | 0x20) == 'm')) {
            if (LIKELY(!hasEscape))
                m_token = RIGHTBOTTOM_SYM;
}
} else if (LIKELY((name[6] | 0x20) == 'm')) {
if (LIKELY((name[7] | 0x20) == 'i' && (name[8] | 0x20) == 'd' && (name[9] | 0x20) == 'd' && (name[10] | 0x20) == 'l' && (name[11] | 0x20) == 'e')) {
            if (LIKELY(!hasEscape))
                m_token = RIGHTMIDDLE_SYM;
}
}
}
}
} break;
case 13: {
if (LIKELY((name[0] | 0x20) == 'b' && (name[1] | 0x20) == 'o' && (name[2] | 0x20) == 't' && (name[3] | 0x20) == 't' && (name[4] | 0x20) == 'o' && (name[5] | 0x20) == 'm' && name[6] == '-' && (name[7] | 0x20) == 'c' && (name[8] | 0x20) == 'e' && (name[9] | 0x20) == 'n' && (name[10] | 0x20) == 't' && (name[11] | 0x20) == 'e' && (name[12] | 0x20) == 'r')) {
            if (LIKELY(!hasEscape))
                m_token = BOTTOMCENTER_SYM;
}
} break;
case 14: {
if (LIKELY(name[0] == '-' && (name[1] | 0x20) == 'i' && (name[2] | 0x20) == 'n' && (name[3] | 0x20) == 't' && (name[4] | 0x20) == 'e' && (name[5] | 0x20) == 'r' && (name[6] | 0x20) == 'n' && (name[7] | 0x20) == 'a' && (name[8] | 0x20) == 'l' && name[9] == '-' && (name[10] | 0x20) == 'r' && (name[11] | 0x20) == 'u' && (name[12] | 0x20) == 'l' && (name[13] | 0x20) == 'e')) {
            if (LIKELY(!hasEscape && m_internal))
                m_token = INTERNAL_RULE_SYM;
}
} break;
case 15: {
if ((name[1] | 0x20) == 'i') {
if (LIKELY(name[0] == '-' && (name[2] | 0x20) == 'n' && (name[3] | 0x20) == 't' && (name[4] | 0x20) == 'e' && (name[5] | 0x20) == 'r' && (name[6] | 0x20) == 'n' && (name[7] | 0x20) == 'a' && (name[8] | 0x20) == 'l' && name[9] == '-')) {
if ((name[10] | 0x20) == 'd') {
if (LIKELY((name[11] | 0x20) == 'e' && (name[12] | 0x20) == 'c' && (name[13] | 0x20) == 'l' && (name[14] | 0x20) == 's')) {
            if (LIKELY(!hasEscape && m_internal))
                m_token = INTERNAL_DECLS_SYM;
}
} else if (LIKELY((name[10] | 0x20) == 'v')) {
if (LIKELY((name[11] | 0x20) == 'a' && (name[12] | 0x20) == 'l' && (name[13] | 0x20) == 'u' && (name[14] | 0x20) == 'e')) {
            if (LIKELY(!hasEscape && m_internal))
                m_token = INTERNAL_VALUE_SYM;
}
}
}
} else if (LIKELY((name[1] | 0x20) == 'o')) {
if (LIKELY((name[0] | 0x20) == 't' && (name[2] | 0x20) == 'p' && name[3] == '-' && (name[4] | 0x20) == 'l' && (name[5] | 0x20) == 'e' && (name[6] | 0x20) == 'f' && (name[7] | 0x20) == 't' && name[8] == '-' && (name[9] | 0x20) == 'c' && (name[10] | 0x20) == 'o' && (name[11] | 0x20) == 'r' && (name[12] | 0x20) == 'n' && (name[13] | 0x20) == 'e' && (name[14] | 0x20) == 'r')) {
            if (LIKELY(!hasEscape))
                m_token = TOPLEFTCORNER_SYM;
}
}
} break;
case 16: {
if (LIKELY((name[0] | 0x20) == 't' && (name[1] | 0x20) == 'o' && (name[2] | 0x20) == 'p' && name[3] == '-' && (name[4] | 0x20) == 'r' && (name[5] | 0x20) == 'i' && (name[6] | 0x20) == 'g' && (name[7] | 0x20) == 'h' && (name[8] | 0x20) == 't' && name[9] == '-' && (name[10] | 0x20) == 'c' && (name[11] | 0x20) == 'o' && (name[12] | 0x20) == 'r' && (name[13] | 0x20) == 'n' && (name[14] | 0x20) == 'e' && (name[15] | 0x20) == 'r')) {
            if (LIKELY(!hasEscape))
                m_token = TOPRIGHTCORNER_SYM;
}
} break;
case 17: {
if (LIKELY(name[0] == '-' && (name[1] | 0x20) == 'w' && (name[2] | 0x20) == 'e' && (name[3] | 0x20) == 'b' && (name[4] | 0x20) == 'k' && (name[5] | 0x20) == 'i' && (name[6] | 0x20) == 't' && name[7] == '-' && (name[8] | 0x20) == 'k' && (name[9] | 0x20) == 'e' && (name[10] | 0x20) == 'y' && (name[11] | 0x20) == 'f' && (name[12] | 0x20) == 'r' && (name[13] | 0x20) == 'a' && (name[14] | 0x20) == 'm' && (name[15] | 0x20) == 'e' && (name[16] | 0x20) == 's')) {
            m_token = WEBKIT_KEYFRAMES_SYM;
}
} break;
case 18: {
if (LIKELY((name[3] | 0x20) == 't' && (name[17] | 0x20) == 'r')) {
if ((name[1] | 0x20) == 'i') {
if (LIKELY(name[0] == '-' && (name[2] | 0x20) == 'n' && (name[4] | 0x20) == 'e' && (name[5] | 0x20) == 'r' && (name[6] | 0x20) == 'n' && (name[7] | 0x20) == 'a' && (name[8] | 0x20) == 'l' && name[9] == '-' && (name[10] | 0x20) == 's' && (name[11] | 0x20) == 'e' && (name[12] | 0x20) == 'l' && (name[13] | 0x20) == 'e' && (name[14] | 0x20) == 'c' && (name[15] | 0x20) == 't' && (name[16] | 0x20) == 'o')) {
            if (LIKELY(!hasEscape && m_internal))
                m_token = INTERNAL_SELECTOR_SYM;
}
} else if (LIKELY((name[1] | 0x20) == 'o')) {
if (LIKELY((name[0] | 0x20) == 'b' && (name[2] | 0x20) == 't' && (name[4] | 0x20) == 'o' && (name[5] | 0x20) == 'm' && name[6] == '-' && (name[7] | 0x20) == 'l' && (name[8] | 0x20) == 'e' && (name[9] | 0x20) == 'f' && (name[10] | 0x20) == 't' && name[11] == '-' && (name[12] | 0x20) == 'c' && (name[13] | 0x20) == 'o' && (name[14] | 0x20) == 'r' && (name[15] | 0x20) == 'n' && (name[16] | 0x20) == 'e')) {
            if (LIKELY(!hasEscape))
                m_token = BOTTOMLEFTCORNER_SYM;
}
}
}
} break;
case 19: {
if (LIKELY((name[3] | 0x20) == 't')) {
if ((name[1] | 0x20) == 'i') {
if (LIKELY(name[0] == '-' && (name[2] | 0x20) == 'n' && (name[4] | 0x20) == 'e' && (name[5] | 0x20) == 'r' && (name[6] | 0x20) == 'n' && (name[7] | 0x20) == 'a' && (name[8] | 0x20) == 'l' && name[9] == '-' && (name[10] | 0x20) == 'm' && (name[11] | 0x20) == 'e' && (name[12] | 0x20) == 'd' && (name[13] | 0x20) == 'i' && (name[14] | 0x20) == 'a' && (name[15] | 0x20) == 'l' && (name[16] | 0x20) == 'i' && (name[17] | 0x20) == 's' && (name[18] | 0x20) == 't')) {
            if (!m_internal)
                return;
            m_parsingMode = MediaQueryMode;
            m_token = INTERNAL_MEDIALIST_SYM;
}
} else if (LIKELY((name[1] | 0x20) == 'o')) {
if (LIKELY((name[0] | 0x20) == 'b' && (name[2] | 0x20) == 't' && (name[4] | 0x20) == 'o' && (name[5] | 0x20) == 'm' && name[6] == '-' && (name[7] | 0x20) == 'r' && (name[8] | 0x20) == 'i' && (name[9] | 0x20) == 'g' && (name[10] | 0x20) == 'h' && (name[11] | 0x20) == 't' && name[12] == '-' && (name[13] | 0x20) == 'c' && (name[14] | 0x20) == 'o' && (name[15] | 0x20) == 'r' && (name[16] | 0x20) == 'n' && (name[17] | 0x20) == 'e' && (name[18] | 0x20) == 'r')) {
            if (LIKELY(!hasEscape))
                m_token = BOTTOMRIGHTCORNER_SYM;
}
}
}
} break;
case 23: {
if (LIKELY(name[0] == '-' && (name[1] | 0x20) == 'i' && (name[2] | 0x20) == 'n' && (name[3] | 0x20) == 't' && (name[4] | 0x20) == 'e' && (name[5] | 0x20) == 'r' && (name[6] | 0x20) == 'n' && (name[7] | 0x20) == 'a' && (name[8] | 0x20) == 'l' && name[9] == '-' && (name[10] | 0x20) == 'k' && (name[11] | 0x20) == 'e' && (name[12] | 0x20) == 'y' && (name[13] | 0x20) == 'f' && (name[14] | 0x20) == 'r' && (name[15] | 0x20) == 'a' && (name[16] | 0x20) == 'm' && (name[17] | 0x20) == 'e' && name[18] == '-' && (name[19] | 0x20) == 'r' && (name[20] | 0x20) == 'u' && (name[21] | 0x20) == 'l' && (name[22] | 0x20) == 'e')) {
            if (LIKELY(!hasEscape && m_internal))
                m_token = INTERNAL_KEYFRAME_RULE_SYM;
}
} break;
case 27: {
if (LIKELY(name[0] == '-' && (name[1] | 0x20) == 'i' && (name[2] | 0x20) == 'n' && (name[3] | 0x20) == 't' && (name[4] | 0x20) == 'e' && (name[5] | 0x20) == 'r' && (name[6] | 0x20) == 'n' && (name[7] | 0x20) == 'a' && (name[8] | 0x20) == 'l' && name[9] == '-' && (name[10] | 0x20) == 'k' && (name[11] | 0x20) == 'e' && (name[12] | 0x20) == 'y' && (name[13] | 0x20) == 'f' && (name[14] | 0x20) == 'r' && (name[15] | 0x20) == 'a' && (name[16] | 0x20) == 'm' && (name[17] | 0x20) == 'e' && name[18] == '-' && (name[19] | 0x20) == 'k' && (name[20] | 0x20) == 'e' && (name[21] | 0x20) == 'y' && name[22] == '-' && (name[23] | 0x20) == 'l' && (name[24] | 0x20) == 'i' && (name[25] | 0x20) == 's' && (name[26] | 0x20) == 't')) {
            if (!m_internal)
                return;
            m_token = INTERNAL_KEYFRAME_KEY_LIST_SYM;
}
} break;
case 28: {
if (LIKELY(name[0] == '-' && (name[1] | 0x20) == 'i' && (name[2] | 0x20) == 'n' && (name[3] | 0x20) == 't' && (name[4] | 0x20) == 'e' && (name[5] | 0x20) == 'r' && (name[6] | 0x20) == 'n' && (name[7] | 0x20) == 'a' && (name[8] | 0x20) == 'l' && name[9] == '-' && (name[10] | 0x20) == 's' && (name[11] | 0x20) == 'u' && (name[12] | 0x20) == 'p' && (name[13] | 0x20) == 'p' && (name[14] | 0x20) == 'o' && (name[15] | 0x20) == 'r' && (name[16] | 0x20) == 't' && (name[17] | 0x20) == 's' && name[18] == '-' && (name[19] | 0x20) == 'c' && (name[20] | 0x20) == 'o' && (name[21] | 0x20) == 'n' && (name[22] | 0x20) == 'd' && (name[23] | 0x20) == 'i' && (name[24] | 0x20) == 't' && (name[25] | 0x20) == 'i' && (name[26] | 0x20) == 'o' && (name[27] | 0x20) == 'n')) {
            if (!m_internal)
                return;
            m_parsingMode = SupportsMode;
            m_token = INTERNAL_SUPPORTS_CONDITION_SYM;
}
} break;
}
}

template <typename CharacterType>
inline void CSSTokenizer::detectSupportsToken(int length)
{
    ASSERT(m_parsingMode == SupportsMode);
    CharacterType* name = tokenStart<CharacterType>();

if (length == 2) {
if (LIKELY((name[0] | 0x20) == 'o' && (name[1] | 0x20) == 'r')) {
            m_token = SUPPORTS_OR;
}
} else if (LIKELY(length == 3)) {
if ((name[0] | 0x20) == 'a') {
if (LIKELY((name[1] | 0x20) == 'n' && (name[2] | 0x20) == 'd')) {
            m_token = SUPPORTS_AND;
}
} else if (LIKELY((name[0] | 0x20) == 'n')) {
if (LIKELY((name[1] | 0x20) == 'o' && (name[2] | 0x20) == 't')) {
            m_token = SUPPORTS_NOT;
}
}
}
}

template <typename SrcCharacterType>
int CSSTokenizer::realLex(void* yylvalWithoutType)
{
    YYSTYPE* yylval = static_cast<YYSTYPE*>(yylvalWithoutType);
    // Write pointer for the next character.
    SrcCharacterType* result;
    CSSParserString resultString;
    bool hasEscape;

    // The input buffer is terminated by a \0 character, so
    // it is safe to read one character ahead of a known non-null.
#ifndef NDEBUG
    // In debug we check with an ASSERT that the length is > 0 for string types.
    yylval->string.clear();
#endif

restartAfterComment:
    result = currentCharacter<SrcCharacterType>();
    setTokenStart(result);
    m_tokenStartLineNumber = m_lineNumber;
    m_token = *currentCharacter<SrcCharacterType>();
    ++currentCharacter<SrcCharacterType>();

    switch ((m_token <= 127) ? typesOfASCIICharacters[m_token] : CharacterIdentifierStart) {
    case CharacterCaselessU:
        if (UNLIKELY(*currentCharacter<SrcCharacterType>() == '+')) {
            if (parseUnicodeRange<SrcCharacterType>()) {
                m_token = UNICODERANGE;
                yylval->string.init(tokenStart<SrcCharacterType>(), currentCharacter<SrcCharacterType>() - tokenStart<SrcCharacterType>());
                break;
            }
        }
        // Fall through to CharacterIdentifierStart.

    case CharacterIdentifierStart:
        --currentCharacter<SrcCharacterType>();
        parseIdentifier(result, yylval->string, hasEscape);
        m_token = IDENT;

        if (UNLIKELY(*currentCharacter<SrcCharacterType>() == '(')) {
            if (m_parsingMode == SupportsMode && !hasEscape) {
                detectSupportsToken<SrcCharacterType>(result - tokenStart<SrcCharacterType>());
                if (m_token != IDENT)
                    break;
            }

            m_token = FUNCTION;
            if (!hasEscape)
                detectFunctionTypeToken<SrcCharacterType>(result - tokenStart<SrcCharacterType>());

            // Skip parenthesis
            ++currentCharacter<SrcCharacterType>();
            ++result;
            ++yylval->string.m_length;

            if (m_token == URI) {
                m_token = FUNCTION;
                // Check whether it is really an URI.
                if (yylval->string.is8Bit())
                    parseURI<LChar>(yylval->string);
                else
                    parseURI<UChar>(yylval->string);
            }
        } else if (UNLIKELY(m_parsingMode != NormalMode) && !hasEscape) {
            if (m_parsingMode == MediaQueryMode) {
                detectMediaQueryToken<SrcCharacterType>(result - tokenStart<SrcCharacterType>());
            } else if (m_parsingMode == SupportsMode) {
                detectSupportsToken<SrcCharacterType>(result - tokenStart<SrcCharacterType>());
            } else if (m_parsingMode == NthChildMode && isASCIIAlphaCaselessEqual(tokenStart<SrcCharacterType>()[0], 'n')) {
                if (result - tokenStart<SrcCharacterType>() == 1) {
                    // String "n" is IDENT but "n+1" is NTH.
                    if (parseNthChildExtra<SrcCharacterType>()) {
                        m_token = NTH;
                        yylval->string.m_length = currentCharacter<SrcCharacterType>() - tokenStart<SrcCharacterType>();
                    }
                } else if (result - tokenStart<SrcCharacterType>() >= 2 && tokenStart<SrcCharacterType>()[1] == '-') {
                    // String "n-" is IDENT but "n-1" is NTH.
                    // Set currentCharacter to '-' to continue parsing.
                    SrcCharacterType* nextCharacter = result;
                    currentCharacter<SrcCharacterType>() = tokenStart<SrcCharacterType>() + 1;
                    if (parseNthChildExtra<SrcCharacterType>()) {
                        m_token = NTH;
                        yylval->string.setLength(currentCharacter<SrcCharacterType>() - tokenStart<SrcCharacterType>());
                    } else {
                        // Revert the change to currentCharacter if unsuccessful.
                        currentCharacter<SrcCharacterType>() = nextCharacter;
                    }
                }
            }
        }
        break;

    case CharacterDot:
        if (!isASCIIDigit(currentCharacter<SrcCharacterType>()[0]))
            break;
        // Fall through to CharacterNumber.

    case CharacterNumber: {
        bool dotSeen = (m_token == '.');

        while (true) {
            if (!isASCIIDigit(currentCharacter<SrcCharacterType>()[0])) {
                // Only one dot is allowed for a number,
                // and it must be followed by a digit.
                if (currentCharacter<SrcCharacterType>()[0] != '.' || dotSeen || !isASCIIDigit(currentCharacter<SrcCharacterType>()[1]))
                    break;
                dotSeen = true;
            }
            ++currentCharacter<SrcCharacterType>();
        }

        if (UNLIKELY(m_parsingMode == NthChildMode) && !dotSeen && isASCIIAlphaCaselessEqual(*currentCharacter<SrcCharacterType>(), 'n')) {
            // "[0-9]+n" is always an NthChild.
            ++currentCharacter<SrcCharacterType>();
            parseNthChildExtra<SrcCharacterType>();
            m_token = NTH;
            yylval->string.init(tokenStart<SrcCharacterType>(), currentCharacter<SrcCharacterType>() - tokenStart<SrcCharacterType>());
            break;
        }

        // Use SVG parser for numbers on SVG presentation attributes.
        if (isSVGNumberParsingEnabledForMode(m_parser.m_context.mode())) {
            // We need to take care of units like 'em' or 'ex'.
            SrcCharacterType* character = currentCharacter<SrcCharacterType>();
            if (isASCIIAlphaCaselessEqual(*character, 'e')) {
                ASSERT(character - tokenStart<SrcCharacterType>() > 0);
                ++character;
                if (*character == '-' || *character == '+' || isASCIIDigit(*character)) {
                    ++character;
                    while (isASCIIDigit(*character))
                        ++character;
                    // Use FLOATTOKEN if the string contains exponents.
                    dotSeen = true;
                    currentCharacter<SrcCharacterType>() = character;
                }
            }
            if (!parseSVGNumber(tokenStart<SrcCharacterType>(), character - tokenStart<SrcCharacterType>(), yylval->number))
                break;
        } else {
            yylval->number = charactersToDouble(tokenStart<SrcCharacterType>(), currentCharacter<SrcCharacterType>() - tokenStart<SrcCharacterType>());
        }

        // Type of the function.
        if (isIdentifierStart<SrcCharacterType>()) {
            SrcCharacterType* type = currentCharacter<SrcCharacterType>();
            result = currentCharacter<SrcCharacterType>();

            parseIdentifier(result, resultString, hasEscape);

            m_token = DIMEN;
            if (!hasEscape)
                detectNumberToken(type, currentCharacter<SrcCharacterType>() - type);

            if (m_token == DIMEN) {
                // The decoded number is overwritten, but this is intentional.
                yylval->string.init(tokenStart<SrcCharacterType>(), currentCharacter<SrcCharacterType>() - tokenStart<SrcCharacterType>());
            }
        } else if (*currentCharacter<SrcCharacterType>() == '%') {
            // Although the CSS grammar says {num}% we follow
            // webkit at the moment which uses {num}%+.
            do {
                ++currentCharacter<SrcCharacterType>();
            } while (*currentCharacter<SrcCharacterType>() == '%');
            m_token = PERCENTAGE;
        } else {
            m_token = dotSeen ? FLOATTOKEN : INTEGER;
        }
        break;
    }

    case CharacterDash:
        if (isIdentifierStartAfterDash(currentCharacter<SrcCharacterType>())) {
            --currentCharacter<SrcCharacterType>();
            parseIdentifier(result, resultString, hasEscape);
            m_token = IDENT;

            if (*currentCharacter<SrcCharacterType>() == '(') {
                m_token = FUNCTION;
                if (!hasEscape)
                    detectDashToken<SrcCharacterType>(result - tokenStart<SrcCharacterType>());
                ++currentCharacter<SrcCharacterType>();
                ++result;
            } else if (UNLIKELY(m_parsingMode == NthChildMode) && !hasEscape && isASCIIAlphaCaselessEqual(tokenStart<SrcCharacterType>()[1], 'n')) {
                if (result - tokenStart<SrcCharacterType>() == 2) {
                    // String "-n" is IDENT but "-n+1" is NTH.
                    if (parseNthChildExtra<SrcCharacterType>()) {
                        m_token = NTH;
                        result = currentCharacter<SrcCharacterType>();
                    }
                } else if (result - tokenStart<SrcCharacterType>() >= 3 && tokenStart<SrcCharacterType>()[2] == '-') {
                    // String "-n-" is IDENT but "-n-1" is NTH.
                    // Set currentCharacter to second '-' of '-n-' to continue parsing.
                    SrcCharacterType* nextCharacter = result;
                    currentCharacter<SrcCharacterType>() = tokenStart<SrcCharacterType>() + 2;
                    if (parseNthChildExtra<SrcCharacterType>()) {
                        m_token = NTH;
                        result = currentCharacter<SrcCharacterType>();
                    } else {
                        // Revert the change to currentCharacter if unsuccessful.
                        currentCharacter<SrcCharacterType>() = nextCharacter;
                    }
                }
            }
            resultString.setLength(result - tokenStart<SrcCharacterType>());
            yylval->string = resultString;
        } else if (currentCharacter<SrcCharacterType>()[0] == '-' && currentCharacter<SrcCharacterType>()[1] == '>') {
            currentCharacter<SrcCharacterType>() += 2;
            m_token = SGML_CD;
        } else if (UNLIKELY(m_parsingMode == NthChildMode)) {
            // "-[0-9]+n" is always an NthChild.
            if (parseNthChild<SrcCharacterType>()) {
                parseNthChildExtra<SrcCharacterType>();
                m_token = NTH;
                yylval->string.init(tokenStart<SrcCharacterType>(), currentCharacter<SrcCharacterType>() - tokenStart<SrcCharacterType>());
            }
        }
        break;

    case CharacterOther:
        // m_token is simply the current character.
        break;

    case CharacterNull:
        // Do not advance pointer at the end of input.
        --currentCharacter<SrcCharacterType>();
        break;

    case CharacterWhiteSpace:
        m_token = WHITESPACE;
        // Might start with a '\n'.
        --currentCharacter<SrcCharacterType>();
        do {
            if (*currentCharacter<SrcCharacterType>() == '\n')
                ++m_lineNumber;
            ++currentCharacter<SrcCharacterType>();
        } while (*currentCharacter<SrcCharacterType>() <= ' ' && (typesOfASCIICharacters[*currentCharacter<SrcCharacterType>()] == CharacterWhiteSpace));
        break;

    case CharacterEndMediaQueryOrSupports:
        if (m_parsingMode == MediaQueryMode || m_parsingMode == SupportsMode)
            m_parsingMode = NormalMode;
        break;

    case CharacterEndNthChild:
        if (m_parsingMode == NthChildMode)
            m_parsingMode = NormalMode;
        break;

    case CharacterQuote:
        if (checkAndSkipString(currentCharacter<SrcCharacterType>(), m_token)) {
            ++result;
            parseString<SrcCharacterType>(result, yylval->string, m_token);
            m_token = STRING;
        }
        break;

    case CharacterExclamationMark: {
        SrcCharacterType* start = skipWhiteSpace(currentCharacter<SrcCharacterType>());
        if (isEqualToCSSIdentifier(start, "important")) {
            m_token = IMPORTANT_SYM;
            currentCharacter<SrcCharacterType>() = start + 9;
        }
        break;
    }

    case CharacterHashmark: {
        SrcCharacterType* start = currentCharacter<SrcCharacterType>();
        result = currentCharacter<SrcCharacterType>();

        if (isASCIIDigit(*currentCharacter<SrcCharacterType>())) {
            // This must be a valid hex number token.
            do {
                ++currentCharacter<SrcCharacterType>();
            } while (isASCIIHexDigit(*currentCharacter<SrcCharacterType>()));
            m_token = HEX;
            yylval->string.init(start, currentCharacter<SrcCharacterType>() - start);
        } else if (isIdentifierStart<SrcCharacterType>()) {
            m_token = IDSEL;
            parseIdentifier(result, yylval->string, hasEscape);
            if (!hasEscape) {
                // Check whether the identifier is also a valid hex number.
                SrcCharacterType* current = start;
                m_token = HEX;
                do {
                    if (!isASCIIHexDigit(*current)) {
                        m_token = IDSEL;
                        break;
                    }
                    ++current;
                } while (current < result);
            }
        }
        break;
    }

    case CharacterSlash:
        // Ignore comments. They are not even considered as white spaces.
        if (*currentCharacter<SrcCharacterType>() == '*') {
            const CSSParserLocation startLocation = currentLocation();
            if (m_parser.m_observer) {
                unsigned startOffset = currentCharacter<SrcCharacterType>() - dataStart<SrcCharacterType>() - 1; // Start with a slash.
                m_parser.m_observer->startComment(startOffset - m_parsedTextPrefixLength);
            }
            ++currentCharacter<SrcCharacterType>();
            while (currentCharacter<SrcCharacterType>()[0] != '*' || currentCharacter<SrcCharacterType>()[1] != '/') {
                if (*currentCharacter<SrcCharacterType>() == '\n')
                    ++m_lineNumber;
                if (*currentCharacter<SrcCharacterType>() == '\0') {
                    // Unterminated comments are simply ignored.
                    currentCharacter<SrcCharacterType>() -= 2;
                    m_parser.reportError(startLocation, UnterminatedCommentCSSError);
                    break;
                }
                ++currentCharacter<SrcCharacterType>();
            }
            currentCharacter<SrcCharacterType>() += 2;
            if (m_parser.m_observer) {
                unsigned endOffset = currentCharacter<SrcCharacterType>() - dataStart<SrcCharacterType>();
                unsigned userTextEndOffset = static_cast<unsigned>(m_length - 1 - m_parsedTextSuffixLength);
                m_parser.m_observer->endComment(std::min(endOffset, userTextEndOffset) - m_parsedTextPrefixLength);
            }
            goto restartAfterComment;
        }
        break;

    case CharacterDollar:
        if (*currentCharacter<SrcCharacterType>() == '=') {
            ++currentCharacter<SrcCharacterType>();
            m_token = ENDSWITH;
        }
        break;

    case CharacterAsterisk:
        if (*currentCharacter<SrcCharacterType>() == '=') {
            ++currentCharacter<SrcCharacterType>();
            m_token = CONTAINS;
        }
        break;

    case CharacterPlus:
        if (UNLIKELY(m_parsingMode == NthChildMode)) {
            // Simplest case. "+[0-9]*n" is always NthChild.
            if (parseNthChild<SrcCharacterType>()) {
                parseNthChildExtra<SrcCharacterType>();
                m_token = NTH;
                yylval->string.init(tokenStart<SrcCharacterType>(), currentCharacter<SrcCharacterType>() - tokenStart<SrcCharacterType>());
            }
        }
        break;

    case CharacterLess:
        if (currentCharacter<SrcCharacterType>()[0] == '!' && currentCharacter<SrcCharacterType>()[1] == '-' && currentCharacter<SrcCharacterType>()[2] == '-') {
            currentCharacter<SrcCharacterType>() += 3;
            m_token = SGML_CD;
        }
        break;

    case CharacterAt:
        if (isIdentifierStart<SrcCharacterType>()) {
            m_token = ATKEYWORD;
            ++result;
            parseIdentifier(result, resultString, hasEscape);
            detectAtToken<SrcCharacterType>(result - tokenStart<SrcCharacterType>(), hasEscape);
        }
        break;

    case CharacterBackSlash:
        if (isCSSEscape(*currentCharacter<SrcCharacterType>())) {
            --currentCharacter<SrcCharacterType>();
            parseIdentifier(result, yylval->string, hasEscape);
            m_token = IDENT;
        }
        break;

    case CharacterXor:
        if (*currentCharacter<SrcCharacterType>() == '=') {
            ++currentCharacter<SrcCharacterType>();
            m_token = BEGINSWITH;
        }
        break;

    case CharacterVerticalBar:
        if (*currentCharacter<SrcCharacterType>() == '=') {
            ++currentCharacter<SrcCharacterType>();
            m_token = DASHMATCH;
        }
        break;

    case CharacterTilde:
        if (*currentCharacter<SrcCharacterType>() == '=') {
            ++currentCharacter<SrcCharacterType>();
            m_token = INCLUDES;
        }
        break;

    default:
        ASSERT_NOT_REACHED();
        break;
    }

    return m_token;
}

template <>
inline void CSSTokenizer::setTokenStart<LChar>(LChar* tokenStart)
{
    m_tokenStart.ptr8 = tokenStart;
}

template <>
inline void CSSTokenizer::setTokenStart<UChar>(UChar* tokenStart)
{
    m_tokenStart.ptr16 = tokenStart;
}

void CSSTokenizer::setupTokenizer(const char* prefix, unsigned prefixLength, const String& string, const char* suffix, unsigned suffixLength)
{
    m_parsedTextPrefixLength = prefixLength;
    m_parsedTextSuffixLength = suffixLength;
    unsigned stringLength = string.length();
    unsigned length = stringLength + m_parsedTextPrefixLength + m_parsedTextSuffixLength + 1;
    m_length = length;

    if (!stringLength || string.is8Bit()) {
        m_dataStart8 = adoptArrayPtr(new LChar[length]);
        for (unsigned i = 0; i < m_parsedTextPrefixLength; i++)
            m_dataStart8[i] = prefix[i];

        if (stringLength)
            memcpy(m_dataStart8.get() + m_parsedTextPrefixLength, string.characters8(), stringLength * sizeof(LChar));

        unsigned start = m_parsedTextPrefixLength + stringLength;
        unsigned end = start + suffixLength;
        for (unsigned i = start; i < end; i++)
            m_dataStart8[i] = suffix[i - start];

        m_dataStart8[length - 1] = 0;

        m_is8BitSource = true;
        m_currentCharacter8 = m_dataStart8.get();
        m_currentCharacter16 = 0;
        setTokenStart<LChar>(m_currentCharacter8);
        m_lexFunc = &CSSTokenizer::realLex<LChar>;
        return;
    }

    m_dataStart16 = adoptArrayPtr(new UChar[length]);
    for (unsigned i = 0; i < m_parsedTextPrefixLength; i++)
        m_dataStart16[i] = prefix[i];

    ASSERT(stringLength);
    memcpy(m_dataStart16.get() + m_parsedTextPrefixLength, string.characters16(), stringLength * sizeof(UChar));

    unsigned start = m_parsedTextPrefixLength + stringLength;
    unsigned end = start + suffixLength;
    for (unsigned i = start; i < end; i++)
        m_dataStart16[i] = suffix[i - start];

    m_dataStart16[length - 1] = 0;

    m_is8BitSource = false;
    m_currentCharacter8 = 0;
    m_currentCharacter16 = m_dataStart16.get();
    setTokenStart<UChar>(m_currentCharacter16);
    m_lexFunc = &CSSTokenizer::realLex<UChar>;
}

} // namespace WebCore
