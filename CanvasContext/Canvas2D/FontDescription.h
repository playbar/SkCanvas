#ifndef FontDescription_h
#define FontDescription_h


#include "MathExtras.h"

#include "RefPtr.h"
#include "string"

namespace WebCore {

	enum FontOrientation 
	{
		Horizontal, 
		Vertical 
	};
	enum NonCJKGlyphOrientation 
	{
		NonCJKGlyphOrientationVerticalRight,
		NonCJKGlyphOrientationUpright 
	};

	enum FontWidthVariant
	{
		RegularWidth,
		HalfWidth,
		ThirdWidth,
		QuarterWidth,
		LastFontWidthVariant = QuarterWidth
	};

	enum FontStyle {
		FontStyleNormal = 0,
		FontStyleItalic = 1
	};

	enum FontVariant {
		FontVariantNormal = 0,
		FontVariantSmallCaps = 1
	};

	enum FontWeight {
		FontWeight100,
		FontWeight200,
		FontWeight300,
		FontWeight400,
		FontWeight500,
		FontWeight600,
		FontWeight700,
		FontWeight800,
		FontWeight900,
		FontWeightNormal = FontWeight400,
		FontWeightBold = FontWeight700
	};

	enum FontStretch {
		FontStretchUltraCondensed = 1,
		FontStretchExtraCondensed = 2,
		FontStretchCondensed = 3,
		FontStretchSemiCondensed = 4,
		FontStretchNormal = 5,
		FontStretchSemiExpanded = 6,
		FontStretchExpanded = 7,
		FontStretchExtraExpanded = 8,
		FontStretchUltraExpanded = 9
	};

	enum FontSmoothingMode
	{
		AutoSmoothing, NoSmoothing, Antialiased, SubpixelAntialiased
	};

	enum TextRenderingMode { AutoTextRendering, OptimizeSpeed, OptimizeLegibility, GeometricPrecision };



class FontDescription
{
public:
    enum GenericFamilyType 
	{
		NoFamily, 
		StandardFamily, 
		SerifFamily, 
		SansSerifFamily, 
		MonospaceFamily, 
		CursiveFamily, 
		FantasyFamily, 
		PictographFamily
	};

    enum Kerning { AutoKerning, NormalKerning, NoneKerning };

    enum LigaturesState { NormalLigaturesState, DisabledLigaturesState, EnabledLigaturesState };

    FontDescription()
        : m_specifiedSize(0)
        , m_computedSize(0)
        , m_letterSpacing(0)
        , m_wordSpacing(0)
        , m_orientation(Horizontal)
        , m_nonCJKGlyphOrientation(NonCJKGlyphOrientationVerticalRight)
        , m_widthVariant(RegularWidth)
        , m_italic(FontStyleNormal)
        , s_variant(FontVariantNormal)
        , m_isAbsoluteSize(false)
        , m_weight(FontWeightNormal)
        , m_stretch(FontStretchNormal)
        , m_genericFamily(NoFamily)
        , m_usePrinterFont(false)
        , m_kerning(AutoKerning)
        , m_commonLigaturesState(NormalLigaturesState)
        , m_discretionaryLigaturesState(NormalLigaturesState)
        , m_historicalLigaturesState(NormalLigaturesState)
        , m_contextualLigaturesState(NormalLigaturesState)
        , m_keywordSize(0)
        , m_fontSmoothing(AutoSmoothing)
        , m_textRendering(AutoTextRendering)
        , m_isSpecifiedFont(false)
        , m_syntheticBold(false)
        , m_syntheticItalic(false)
        , m_subpixelTextPosition(s_useSubpixelTextPositioning)
    {
    }

    bool operator==(const FontDescription&) const;
    bool operator!=(const FontDescription& other) const { return !(*this == other); }

    float specifiedSize() const { return m_specifiedSize; }
    float computedSize() const { return m_computedSize; }
    FontStyle style() const { return static_cast<FontStyle>(m_italic); }
    int computedPixelSize() const { return int(m_computedSize + 0.5f); }
    FontVariant variant() const { return static_cast<FontVariant>(s_variant); }
    bool isAbsoluteSize() const { return m_isAbsoluteSize; }
    FontWeight weight() const { return static_cast<FontWeight>(m_weight); }
    FontStretch stretch() const { return static_cast<FontStretch>(m_stretch); }
    FontWeight lighterWeight() const;
    FontWeight bolderWeight() const;
    GenericFamilyType genericFamily() const { return static_cast<GenericFamilyType>(m_genericFamily); }
    bool usePrinterFont() const { return m_usePrinterFont; }
    // only use fixed default size when there is only one font family, and that family is "monospace"
    Kerning kerning() const { return static_cast<Kerning>(m_kerning); }
    LigaturesState commonLigaturesState() const { return static_cast<LigaturesState>(m_commonLigaturesState); }
    LigaturesState discretionaryLigaturesState() const { return static_cast<LigaturesState>(m_discretionaryLigaturesState); }
    LigaturesState historicalLigaturesState() const { return static_cast<LigaturesState>(m_historicalLigaturesState); }
    LigaturesState contextualLigaturesState() const { return static_cast<LigaturesState>(m_contextualLigaturesState); }
    unsigned keywordSize() const { return m_keywordSize; }
    FontSmoothingMode fontSmoothing() const { return static_cast<FontSmoothingMode>(m_fontSmoothing); }
    TextRenderingMode textRendering() const { return static_cast<TextRenderingMode>(m_textRendering); }
    bool isSyntheticBold() const { return m_syntheticBold; }
    bool isSyntheticItalic() const { return m_syntheticItalic; }
    bool useSubpixelPositioning() const { return m_subpixelTextPosition; }

    float wordSpacing() const { return m_wordSpacing; }
    float letterSpacing() const { return m_letterSpacing; }
    bool isSpecifiedFont() const { return m_isSpecifiedFont; }
    FontOrientation orientation() const { return static_cast<FontOrientation>(m_orientation); }
    NonCJKGlyphOrientation nonCJKGlyphOrientation() const { return static_cast<NonCJKGlyphOrientation>(m_nonCJKGlyphOrientation); }
    FontWidthVariant widthVariant() const { return static_cast<FontWidthVariant>(m_widthVariant); }
    FontDescription makeNormalFeatureSettings() const;

    float effectiveFontSize() const; // Returns either the computedSize or the computedPixelSize

    void setComputedSize(float s) { m_computedSize = clampToFloat(s); }
    void setSpecifiedSize(float s) { m_specifiedSize = clampToFloat(s); }
    void setStyle(FontStyle i) { m_italic = i; }
    void setStyle(bool i) { setStyle(i ? FontStyleItalic : FontStyleNormal); }
    void setVariant(FontVariant c) { s_variant = c; }
    void setIsAbsoluteSize(bool s) { m_isAbsoluteSize = s; }
    void setWeight(FontWeight w) { m_weight = w; }
    void setStretch(FontStretch s) { m_stretch = s; }
    void setGenericFamily(GenericFamilyType genericFamily) { m_genericFamily = genericFamily; }
    void setUsePrinterFont(bool p) { m_usePrinterFont = p; }
    void setKerning(Kerning kerning) { m_kerning = kerning; }
    void setCommonLigaturesState(LigaturesState commonLigaturesState) { m_commonLigaturesState = commonLigaturesState; }
    void setDiscretionaryLigaturesState(LigaturesState discretionaryLigaturesState) { m_discretionaryLigaturesState = discretionaryLigaturesState;  }
    void setHistoricalLigaturesState(LigaturesState historicalLigaturesState) { m_historicalLigaturesState = historicalLigaturesState;  }
    void setContextualLigaturesState(LigaturesState contextualLigaturesState) { m_contextualLigaturesState = contextualLigaturesState;  }
    void setKeywordSize(unsigned s) { m_keywordSize = s; }
    void setFontSmoothing(FontSmoothingMode smoothing) { m_fontSmoothing = smoothing; }
    void setTextRendering(TextRenderingMode rendering) { m_textRendering = rendering; }
    void setIsSpecifiedFont(bool isSpecifiedFont) { m_isSpecifiedFont = isSpecifiedFont; }
    void setOrientation(FontOrientation orientation) { m_orientation = orientation; }
    void setNonCJKGlyphOrientation(NonCJKGlyphOrientation orientation) { m_nonCJKGlyphOrientation = orientation; }
    void setWidthVariant(FontWidthVariant widthVariant) { m_widthVariant = widthVariant; }
    void setSyntheticBold(bool syntheticBold) { m_syntheticBold = syntheticBold; }
    void setSyntheticItalic(bool syntheticItalic) { m_syntheticItalic = syntheticItalic; }
    void setWordSpacing(float s) { m_wordSpacing = s; }
    void setLetterSpacing(float s) { m_letterSpacing = s; }


    static void setSubpixelPositioning(bool b) { s_useSubpixelTextPositioning = b; }
    static bool subpixelPositioning() { return s_useSubpixelTextPositioning; }

	void parseFontDes(const std::string &newFont);

	std::string m_fontName;
private:

    float m_specifiedSize;   // Specified CSS value. Independent of rendering issues such as integer
                             // rounding, minimum font sizes, and zooming.
    float m_computedSize;    // Computed size adjusted for the minimum font size and the zoom factor.

    float m_letterSpacing;
    float m_wordSpacing;

    unsigned m_orientation : 1; // FontOrientation - Whether the font is rendering on a horizontal line or a vertical line.
    unsigned m_nonCJKGlyphOrientation : 1; // NonCJKGlyphOrientation - Only used by vertical text. Determines the default orientation for non-ideograph glyphs.

    unsigned m_widthVariant : 2; // FontWidthVariant

    unsigned m_italic : 1; // FontStyle
    unsigned s_variant : 1; // FontVariant
    unsigned m_isAbsoluteSize : 1; // Whether or not CSS specified an explicit size
                                  // (logical sizes like "medium" don't count).
    unsigned m_weight : 4; // FontWeight
    unsigned m_stretch : 4; // FontStretch
    unsigned m_genericFamily : 3; // GenericFamilyType
    unsigned m_usePrinterFont : 1;

    unsigned m_kerning : 2; // Kerning

    unsigned m_commonLigaturesState : 2;
    unsigned m_discretionaryLigaturesState : 2;
    unsigned m_historicalLigaturesState : 2;
    unsigned m_contextualLigaturesState : 2;

    unsigned m_keywordSize : 4; // We cache whether or not a font is currently represented by a CSS keyword (e.g., medium).  If so,
                           // then we can accurately translate across different generic families to adjust for different preference settings
                           // (e.g., 13px monospace vs. 16px everything else).  Sizes are 1-8 (like the HTML size values for <font>).

    unsigned m_fontSmoothing : 2; // FontSmoothingMode
    unsigned m_textRendering : 2; // TextRenderingMode
    unsigned m_isSpecifiedFont : 1; // True if a web page specifies a non-generic font family as the first font family.
    unsigned m_script : 7; // Used to help choose an appropriate font for generic font families.
    unsigned m_syntheticBold : 1;
    unsigned m_syntheticItalic : 1;
    unsigned m_subpixelTextPosition : 1;

    mutable unsigned m_typesettingFeatures : 2; // TypesettingFeatures

    static bool s_useSubpixelTextPositioning;
};

inline bool FontDescription::operator==(const FontDescription& other) const
{
    return m_specifiedSize == other.m_specifiedSize
        && m_computedSize == other.m_computedSize
        && m_letterSpacing == other.m_letterSpacing
        && m_wordSpacing == other.m_wordSpacing
        && m_italic == other.m_italic
        && s_variant == other.s_variant
        && m_isAbsoluteSize == other.m_isAbsoluteSize
        && m_weight == other.m_weight
        && m_stretch == other.m_stretch
        && m_genericFamily == other.m_genericFamily
        && m_usePrinterFont == other.m_usePrinterFont
        && m_kerning == other.m_kerning
        && m_commonLigaturesState == other.m_commonLigaturesState
        && m_discretionaryLigaturesState == other.m_discretionaryLigaturesState
        && m_historicalLigaturesState == other.m_historicalLigaturesState
        && m_contextualLigaturesState == other.m_contextualLigaturesState
        && m_keywordSize == other.m_keywordSize
        && m_fontSmoothing == other.m_fontSmoothing
        && m_textRendering == other.m_textRendering
        && m_isSpecifiedFont == other.m_isSpecifiedFont
        && m_orientation == other.m_orientation
        && m_nonCJKGlyphOrientation == other.m_nonCJKGlyphOrientation
        && m_widthVariant == other.m_widthVariant
        && m_script == other.m_script
        && m_syntheticBold == other.m_syntheticBold
        && m_syntheticItalic == other.m_syntheticItalic
        && m_subpixelTextPosition == other.m_subpixelTextPosition;
}

}

#endif
