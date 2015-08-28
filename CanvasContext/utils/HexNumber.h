#ifndef HexNumber_h
#define HexNumber_h


namespace Canvas2D {

enum HexConversionMode {
    Lowercase,
    Uppercase
};

namespace Internal {

const char lowerHexDigits[17] = "0123456789abcdef";
const char upperHexDigits[17] = "0123456789ABCDEF";
inline const char* hexDigitsForMode(HexConversionMode mode)
{
    return mode == Lowercase ? lowerHexDigits : upperHexDigits;
}

}; // namespace Internal

template<typename T>
inline void appendByteAsHex(unsigned char byte, T& destination, HexConversionMode mode = Uppercase)
{
	const char* hexDigits = Internal::hexDigitsForMode(mode);
    destination.push_back(hexDigits[byte >> 4]);
	destination.push_back(hexDigits[byte & 0xF]);
}

template<typename T>
inline void placeByteAsHexCompressIfPossible(unsigned char byte, T& destination, unsigned& index, HexConversionMode mode = Uppercase)
{
	const char* hexDigits = Internal::hexDigitsForMode(mode);
    if (byte >= 0x10)
        destination[index++] = hexDigits[byte >> 4];
    destination[index++] = hexDigits[byte & 0xF];
}

template<typename T>
inline void placeByteAsHex(unsigned char byte, T& destination, HexConversionMode mode = Uppercase)
{
	const char* hexDigits = Internal::hexDigitsForMode(mode);
    *destination++ = hexDigits[byte >> 4];
    *destination++ = hexDigits[byte & 0xF];
}

template<typename T>
inline void appendUnsignedAsHex(unsigned number, T& destination, HexConversionMode mode = Uppercase)
{
	const char* hexDigits = Internal::hexDigitsForMode(mode);
	std::vector<char> result;
	result.resize(8);
    do {
        result.prepend(hexDigits[number % 16]);
        number >>= 4;
    } while (number > 0);

    destination.append(result.data(), result.size());
}

// Same as appendUnsignedAsHex, but using exactly 'desiredDigits' for the conversion.
template<typename T>
inline void appendUnsignedAsHexFixedSize(unsigned number, T& destination, unsigned desiredDigits, HexConversionMode mode = Uppercase)
{
    ASSERT(desiredDigits);

	const char* hexDigits = Internal::hexDigitsForMode(mode);
	std::vector<char> result;
	result.resize(8);
    do {
        result.prepend(hexDigits[number % 16]);
        number >>= 4;
    } while (result.size() < desiredDigits);

    ASSERT(result.size() == desiredDigits);
    destination.append(result.data(), result.size());
}

} // 

#endif // HexNumber_h
