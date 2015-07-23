#include "config.h"
#include "platform/Length.h"

#include "platform/CalculationValue.h"
#include "wtf/ASCIICType.h"
#include "wtf/text/StringBuffer.h"
#include "wtf/text/WTFString.h"

using namespace WTF;

namespace WebCore {

template<typename CharType>
static unsigned splitLength(const CharType* data, unsigned length, unsigned& intLength, unsigned& doubleLength)
{
    ASSERT(length);

    unsigned i = 0;
    while (i < length && isSpaceOrNewline(data[i]))
        ++i;
    if (i < length && (data[i] == '+' || data[i] == '-'))
        ++i;
    while (i < length && isASCIIDigit(data[i]))
        ++i;
    intLength = i;
    while (i < length && (isASCIIDigit(data[i]) || data[i] == '.'))
        ++i;
    doubleLength = i;

    // IE quirk: Skip whitespace between the number and the % character (20 % => 20%).
    while (i < length && isSpaceOrNewline(data[i]))
        ++i;

    return i;
}

template<typename CharType>
static Length parseHTMLAreaCoordinate(const CharType* data, unsigned length)
{
    unsigned intLength;
    unsigned doubleLength;
    splitLength(data, length, intLength, doubleLength);

    bool ok;
    int r = charactersToIntStrict(data, intLength, &ok);
    if (ok)
        return Length(r, Fixed);
    return Length(0, Fixed);
}

// FIXME: Per HTML5, this should follow the "rules for parsing a list of integers".
Vector<Length> parseHTMLAreaElementCoords(const String& string)
{
    unsigned length = string.length();
    StringBuffer<LChar> spacified(length);
    for (unsigned i = 0; i < length; i++) {
        UChar cc = string[i];
        if (cc > '9' || (cc < '0' && cc != '-' && cc != '.'))
            spacified[i] = ' ';
        else
            spacified[i] = cc;
    }
    RefPtr<StringImpl> str = spacified.release();
    str = str->simplifyWhiteSpace();
    ASSERT(str->is8Bit());

    if (!str->length())
        return Vector<Length>();

    unsigned len = str->count(' ') + 1;
    Vector<Length> r(len);

    unsigned i = 0;
    unsigned pos = 0;
    size_t pos2;

    while ((pos2 = str->find(' ', pos)) != kNotFound) {
        r[i++] = parseHTMLAreaCoordinate(str->characters8() + pos, pos2 - pos);
        pos = pos2 + 1;
    }
    r[i] = parseHTMLAreaCoordinate(str->characters8() + pos, str->length() - pos);

    ASSERT(i == len - 1);

    return r;
}

class CalculationValueHandleMap {
    WTF_MAKE_FAST_ALLOCATED;
public:
    CalculationValueHandleMap()
        : m_index(1)
    {
    }

    int insert(PassRefPtr<CalculationValue> calcValue)
    {
        ASSERT(m_index);
 
        while (m_map.contains(m_index))
            m_index++;

        m_map.set(m_index, calcValue);

        return m_index;
    }

    void remove(int index)
    {
        ASSERT(m_map.contains(index));
        m_map.remove(index);
    }

    CalculationValue* get(int index)
    {
        ASSERT(m_map.contains(index));
        return m_map.get(index);
    }

    void decrementRef(int index)
    {
        ASSERT(m_map.contains(index));
        CalculationValue* value = m_map.get(index);
        if (value->hasOneRef()) {
            // Force the CalculationValue destructor early to avoid a potential recursive call inside HashMap remove().
            m_map.set(index, nullptr);
            m_map.remove(index);
        } else {
            value->deref();
        }
    }

private:
    int m_index;
    HashMap<int, RefPtr<CalculationValue> > m_map;
};

static CalculationValueHandleMap& calcHandles()
{
    DEFINE_STATIC_LOCAL(CalculationValueHandleMap, handleMap, ());
    return handleMap;
}

Length::Length(PassRefPtr<CalculationValue> calc)
    : m_quirk(false)
    , m_type(Calculated)
    , m_isFloat(false)
{
    m_intValue = calcHandles().insert(calc);
}

Length Length::blendMixedTypes(const Length& from, double progress, ValueRange range) const
{
    return Length(CalculationValue::create(adoptPtr(new CalcExpressionBlendLength(from, *this, progress)), range));
}

CalculationValue* Length::calculationValue() const
{
    ASSERT(isCalculated());
    return calcHandles().get(calculationHandle());
}

void Length::incrementCalculatedRef() const
{
    ASSERT(isCalculated());
    calculationValue()->ref();
}

void Length::decrementCalculatedRef() const
{
    ASSERT(isCalculated());
    calcHandles().decrementRef(calculationHandle());
}

float Length::nonNanCalculatedValue(int maxValue) const
{
    ASSERT(isCalculated());
    float result = calculationValue()->evaluate(maxValue);
    if (std::isnan(result))
        return 0;
    return result;
}

bool Length::isCalculatedEqual(const Length& o) const
{
    return isCalculated() && (calculationValue() == o.calculationValue() || *calculationValue() == *o.calculationValue());
}

struct SameSizeAsLength {
    int32_t value;
    int32_t metaData;
};
COMPILE_ASSERT(sizeof(Length) == sizeof(SameSizeAsLength), length_should_stay_small);

} // namespace WebCore
