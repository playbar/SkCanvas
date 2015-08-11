#ifndef __ASCIITYPE_H__
#define __ASCIITYPE_H__

template<typename CharType> inline bool isASCII(CharType c)
{
	return !(c & ~0x7F);
}

template<typename CharType> inline bool isASCIIAlpha(CharType c)
{
	return (c | 0x20) >= 'a' && (c | 0x20) <= 'z';
}

template<typename CharType> inline bool isASCIIDigit(CharType c)
{
	return c >= '0' && c <= '9';
}

template<typename CharType> inline bool isASCIIAlphanumeric(CharType c)
{
	return isASCIIDigit(c) || isASCIIAlpha(c);
}

template<typename CharType> inline bool isASCIIHexDigit(CharType c)
{
	return isASCIIDigit(c) || ((c | 0x20) >= 'a' && (c | 0x20) <= 'f');
}

template<typename CharType> inline bool isASCIILower(CharType c)
{
	return c >= 'a' && c <= 'z';
}

template<typename CharType> inline bool isASCIIOctalDigit(CharType c)
{
	return (c >= '0') & (c <= '7');
}

template<typename CharType> inline bool isASCIIPrintable(CharType c)
{
	return c >= ' ' && c <= '~';
}

/*
Statistics from a run of Apple's page load test for callers of isASCIISpace:

character          count
---------          -----
non-spaces         689383
20  space          294720
0A  \n             89059
09  \t             28320
0D  \r             0
0C  \f             0
0B  \v             0
*/
template<typename CharType> inline bool isASCIISpace(CharType c)
{
	return c <= ' ' && (c == ' ' || (c <= 0xD && c >= 0x9));
}

template<typename CharType> inline bool isASCIIUpper(CharType c)
{
	return c >= 'A' && c <= 'Z';
}

template<typename CharType> inline CharType toASCIILower(CharType c)
{
#if defined(_MSC_FULL_VER) && _MSC_FULL_VER == 170060610
	// Make a workaround for VS2012 update 3 optimizer bug, remove once VS2012 fix it.
	return (c >= 'A' && c <= 'Z') ? c + 0x20 : c;
#else
	return c | ((c >= 'A' && c <= 'Z') << 5);
#endif
}

template<typename CharType> inline CharType toASCIILowerUnchecked(CharType character)
{
	// This function can be used for comparing any input character
	// to a lowercase English character. The isASCIIAlphaCaselessEqual
	// below should be used for regular comparison of ASCII alpha
	// characters, but switch statements in CSS tokenizer require
	// direct use of this function.
	return character | 0x20;
}

template<typename CharType> inline CharType toASCIIUpper(CharType c)
{
	return c & ~((c >= 'a' && c <= 'z') << 5);
}

template<typename CharType> inline int toASCIIHexValue(CharType c)
{
	SkASSERT(isASCIIHexDigit(c));
	return c < 'A' ? c - '0' : (c - 'A' + 10) & 0xF;
}

template<typename CharType> inline int toASCIIHexValue(CharType upperValue, CharType lowerValue)
{
	ASSERT(isASCIIHexDigit(upperValue) && isASCIIHexDigit(lowerValue));
	return ((toASCIIHexValue(upperValue) << 4) & 0xF0) | toASCIIHexValue(lowerValue);
}

inline char lowerNibbleToASCIIHexDigit(char c)
{
	char nibble = c & 0xF;
	return nibble < 10 ? '0' + nibble : 'A' + nibble - 10;
}

inline char upperNibbleToASCIIHexDigit(char c)
{
	char nibble = (c >> 4) & 0xF;
	return nibble < 10 ? '0' + nibble : 'A' + nibble - 10;
}

template<typename CharType> inline bool isASCIIAlphaCaselessEqual(CharType cssCharacter, char character)
{
	// This function compares a (preferrably) constant ASCII
	// lowercase letter to any input character.
	ASSERT(character >= 'a' && character <= 'z');
	return LIKELY(toASCIILowerUnchecked(cssCharacter) == character);
}

#endif

