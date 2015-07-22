#ifndef WTF_StringView_h
#define WTF_StringView_h

#include "wtf/text/StringImpl.h"

namespace WTF {

class WTF_EXPORT StringView {
public:
    StringView()
        : m_offset(0)
        , m_length(0)
    {
    }

    explicit StringView(PassRefPtr<StringImpl> impl)
        : m_impl(impl)
        , m_offset(0)
        , m_length(m_impl->length())
    {
    }

    StringView(PassRefPtr<StringImpl> impl, unsigned offset, unsigned length)
        : m_impl(impl)
        , m_offset(offset)
        , m_length(length)
    {
        ASSERT_WITH_SECURITY_IMPLICATION(offset + length <= m_impl->length());
    }

    void narrow(unsigned offset, unsigned length)
    {
        ASSERT_WITH_SECURITY_IMPLICATION(offset + length <= m_length);
        m_offset += offset;
        m_length = length;
    }

    bool isEmpty() const { return !m_length; }
    unsigned length() const { return m_length; }

    bool is8Bit() const { return m_impl->is8Bit(); }

    const LChar* characters8() const
    {
        if (!m_impl)
            return 0;
        ASSERT(is8Bit());
        return m_impl->characters8() + m_offset;
    }

    const UChar* characters16() const
    {
        if (!m_impl)
            return 0;
        ASSERT(!is8Bit());
        return m_impl->characters16() + m_offset;
    }

    PassRefPtr<StringImpl> toString() const
    {
        if (!m_impl)
            return m_impl;
        if (m_impl->is8Bit())
            return StringImpl::create(characters8(), m_length);
        return StringImpl::create(characters16(), m_length);
    }

private:
    RefPtr<StringImpl> m_impl;
    unsigned m_offset;
    unsigned m_length;
};

}

using WTF::StringView;

#endif
