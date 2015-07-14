#ifndef HTMLParserIdioms_h
#define HTMLParserIdioms_h


#include "wtf/Forward.h"
#include "wtf/text/WTFString.h"

namespace WTF {
class TextEncoding;
}

namespace WebCore {

// Space characters as defined by the HTML specification.
bool isHTMLSpace(UChar);
bool isHTMLLineBreak(UChar);
bool isNotHTMLSpace(UChar);


template<typename CharType>
inline bool isHTMLSpace(CharType character)
{
    // Histogram from Apple's page load test combined with some ad hoc browsing some other test suites.
    //
    //     82%: 216330 non-space characters, all > U+0020
    //     11%:  30017 plain space characters, U+0020
    //      5%:  12099 newline characters, U+000A
    //      2%:   5346 tab characters, U+0009
    //
    // No other characters seen. No U+000C or U+000D, and no other control characters.
    // Accordingly, we check for non-spaces first, then space, then newline, then tab, then the other characters.

    return character <= ' ' && (character == ' ' || character == '\n' || character == '\t' || character == '\r' || character == '\f');
}

template<typename CharType>
inline bool isHTMLSpaceOrComma(CharType character)
{
    return isHTMLSpace<CharType>(character) || character == ',';
}

inline bool isHTMLLineBreak(UChar character)
{
    return character <= '\r' && (character == '\n' || character == '\r');
}

template<typename CharType>
inline bool isNotHTMLSpace(CharType character)
{
    return !isHTMLSpace<CharType>(character);
}



}
#endif
