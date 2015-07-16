#ifndef CSSValuePool_h
#define CSSValuePool_h

#include "CSSPropertyNames.h"
#include "CSSValueKeywords.h"
#include "CSSInheritedValue.h"
#include "CSSInitialValue.h"
#include "CSSPrimitiveValue.h"
#include "wtf/HashMap.h"
#include "wtf/RefPtr.h"
#include "wtf/text/AtomicStringHash.h"

namespace WebCore {

class CSSValueList;

class CSSValuePool {
	WTF_MAKE_FAST_ALLOCATED;
public:
    PassRefPtr<CSSValueList> createFontFaceValue(const AtomicString&);
	PassRefPtr<CSSPrimitiveValue> createFontFamilyValue(const String&);
	PassRefPtr<CSSInheritedValue> createInheritedValue() { return m_inheritedValue; }
	PassRefPtr<CSSInitialValue> createImplicitInitialValue() { return m_implicitInitialValue; }
	PassRefPtr<CSSInitialValue> createExplicitInitialValue() { return m_explicitInitialValue; }
	PassRefPtr<CSSPrimitiveValue> createIdentifierValue(CSSValueID identifier);
	PassRefPtr<CSSPrimitiveValue> createIdentifierValue(CSSPropertyID identifier);
	PassRefPtr<CSSPrimitiveValue> createColorValue(unsigned rgbValue);
	PassRefPtr<CSSPrimitiveValue> createValue(double value, CSSPrimitiveValue::UnitTypes);
	PassRefPtr<CSSPrimitiveValue> createValue(const String& value, CSSPrimitiveValue::UnitTypes type) { return CSSPrimitiveValue::create(value, type); }
	//PassRefPtr<CSSPrimitiveValue> createValue(const Length& value, const RenderStyle&);
	PassRefPtr<CSSPrimitiveValue> createValue(const Length& value, float zoom) { return CSSPrimitiveValue::create(value, zoom); }
	template<typename T> static PassRefPtr<CSSPrimitiveValue> createValue(T value) { return CSSPrimitiveValue::create(value); }

private:
    CSSValuePool();

    RefPtr<CSSInheritedValue> m_inheritedValue;
    RefPtr<CSSInitialValue> m_implicitInitialValue;
    RefPtr<CSSInitialValue> m_explicitInitialValue;

    Vector<RefPtr<CSSPrimitiveValue>, numCSSValueKeywords> m_identifierValueCache;

    typedef HashMap<unsigned, RefPtr<CSSPrimitiveValue> > ColorValueCache;
    ColorValueCache m_colorValueCache;
	RefPtr<CSSPrimitiveValue> m_colorTransparent;
	RefPtr<CSSPrimitiveValue> m_colorWhite;
	RefPtr<CSSPrimitiveValue> m_colorBlack;

    static const int maximumCacheableIntegerValue = 255;

    Vector<RefPtr<CSSPrimitiveValue>, maximumCacheableIntegerValue + 1> m_pixelValueCache;
	Vector<RefPtr<CSSPrimitiveValue>, maximumCacheableIntegerValue + 1> m_percentValueCache;
	Vector<RefPtr<CSSPrimitiveValue>, maximumCacheableIntegerValue + 1> m_numberValueCache;

    typedef HashMap<AtomicString, RefPtr<CSSValueList> > FontFaceValueCache;
    FontFaceValueCache m_fontFaceValueCache;

	typedef HashMap<AtomicString, RefPtr<CSSPrimitiveValue> > FontFamilyValueCache;
    FontFamilyValueCache m_fontFamilyValueCache;

    friend CSSValuePool& cssValuePool();
};

CSSValuePool& cssValuePool();

}

#endif
