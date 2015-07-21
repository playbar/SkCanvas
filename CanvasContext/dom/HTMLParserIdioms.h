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
