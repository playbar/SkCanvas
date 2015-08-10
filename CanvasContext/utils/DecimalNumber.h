#ifndef DecimalNumber_h
#define DecimalNumber_h

#include <math.h>

#include "SkTypes.h"
#include "MathExtras.h"

namespace WTF {

class DecimalNumber {
public:
    DecimalNumber(double d)
	{
		SkASSERT(false);
        //ASSERT(std::isfinite(d));
        //dtoa(m_significand, d, m_sign, m_exponent, m_precision);

        //ASSERT(m_precision);
        //// Zero should always have exponent 0.
        //ASSERT(m_significand[0] != '0' || !m_exponent);
        //// No values other than zero should have a leading zero.
        //ASSERT(m_significand[0] != '0' || m_precision == 1);
        //// No values other than zero should have trailing zeros.
        //ASSERT(m_significand[0] == '0' || m_significand[m_precision - 1] != '0');
    }

    unsigned bufferLengthForStringDecimal() const;
    unsigned bufferLengthForStringExponential() const;

    unsigned toStringDecimal(char* buffer, unsigned bufferLength) const;
    unsigned toStringExponential(char* buffer, unsigned bufferLength) const;

    bool sign() const { return m_sign; }
    int exponent() const { return m_exponent; }
    const char* significand() const { return m_significand; } // significand contains precision characters, is not null-terminated.
    unsigned precision() const { return m_precision; }

private:
    bool m_sign;
    int m_exponent;
    DtoaBuffer m_significand;
    unsigned m_precision;
};

} // namespace WTF

using WTF::DecimalNumber;

#endif // DecimalNumber_h
