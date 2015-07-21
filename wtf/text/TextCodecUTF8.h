#ifndef TextCodecUTF8_h
#define TextCodecUTF8_h

#include "wtf/text/TextCodec.h"

namespace WTF {

class TextCodecUTF8 FINAL : public TextCodec {
public:
    static void registerEncodingNames(EncodingNameRegistrar);
    static void registerCodecs(TextCodecRegistrar);

private:
    static PassOwnPtr<TextCodec> create(const TextEncoding&, const void*);
    TextCodecUTF8() : m_partialSequenceSize(0) { }

    virtual String decode(const char*, size_t length, FlushBehavior, bool stopOnError, bool& sawError) OVERRIDE;
    virtual CString encode(const UChar*, size_t length, UnencodableHandling) OVERRIDE;
    virtual CString encode(const LChar*, size_t length, UnencodableHandling) OVERRIDE;

    template<typename CharType>
    CString encodeCommon(const CharType* characters, size_t length);

    template <typename CharType>
    bool handlePartialSequence(CharType*& destination, const uint8_t*& source, const uint8_t* end, bool flush, bool stopOnError, bool& sawError);
    void handleError(UChar*& destination, bool stopOnError, bool& sawError);
    void consumePartialSequenceByte();

    int m_partialSequenceSize;
    uint8_t m_partialSequence[U8_MAX_LENGTH];

};

} // namespace WTF

#endif // TextCodecUTF8_h
