#ifndef GraphicsTypes_h
#define GraphicsTypes_h

#include "SkPaint.h"
#include "string"

namespace WebCore
{

	enum WindRule 
	{
		RULE_NONZERO = 0,
		RULE_EVENODD = 1
	};

	enum WebBlendMode {
		WebBlendModeNormal,
		WebBlendModeMultiply,
		WebBlendModeScreen,
		WebBlendModeOverlay,
		WebBlendModeDarken,
		WebBlendModeLighten,
		WebBlendModeColorDodge,
		WebBlendModeColorBurn,
		WebBlendModeHardLight,
		WebBlendModeSoftLight,
		WebBlendModeDifference,
		WebBlendModeExclusion,
		WebBlendModeHue,
		WebBlendModeSaturation,
		WebBlendModeColor,
		WebBlendModeLuminosity
	};

enum StrokeStyle 
{
    NoStroke,
    SolidStroke,
    DottedStroke,
    DashedStroke,
    DoubleStroke,
    WavyStroke,
};

enum InterpolationQuality {
    InterpolationDefault,
    InterpolationNone,
    InterpolationLow,
    InterpolationMedium,
    InterpolationHigh
};

enum CompositeOperator {
    CompositeClear,
    CompositeCopy,
    CompositeSourceOver,
    CompositeSourceIn,
    CompositeSourceOut,
    CompositeSourceAtop,
    CompositeDestinationOver,
    CompositeDestinationIn,
    CompositeDestinationOut,
    CompositeDestinationAtop,
    CompositeXOR,
    CompositePlusDarker,
    CompositePlusLighter,
    CompositeDifference
};

enum GradientSpreadMethod {
    SpreadMethodPad,
    SpreadMethodReflect,
    SpreadMethodRepeat
};

enum LineCap {
    ButtCap = SkPaint::kButt_Cap,
    RoundCap = SkPaint::kRound_Cap,
    SquareCap = SkPaint::kSquare_Cap
};

enum LineJoin {
    MiterJoin = SkPaint::kMiter_Join,
    RoundJoin = SkPaint::kRound_Join,
    BevelJoin = SkPaint::kBevel_Join
};

enum HorizontalAlignment { AlignLeft, AlignRight, AlignHCenter };

enum TextBaseline 
{
	AlphabeticTextBaseline, 
	TopTextBaseline,
	MiddleTextBaseline,
	BottomTextBaseline,
	IdeographicTextBaseline,
	HangingTextBaseline 
};

enum TextAlign { StartTextAlign, EndTextAlign, LeftTextAlign, CenterTextAlign, RightTextAlign };

enum TextDrawingMode {
    TextModeFill      = 1 << 0,
    TextModeStroke    = 1 << 1,
};
typedef unsigned TextDrawingModeFlags;

enum ColorFilter {
    ColorFilterNone,
    ColorFilterLuminanceToAlpha,
    ColorFilterSRGBToLinearRGB,
    ColorFilterLinearRGBToSRGB
};

 std::string compositeOperatorName(CompositeOperator, WebBlendMode);
 bool parseCompositeAndBlendOperator(const  std::string&, CompositeOperator&, WebBlendMode&);

 std::string lineCapName(LineCap);
 bool parseLineCap(const  std::string&, LineCap&);

 std::string lineJoinName(LineJoin);
 bool parseLineJoin(const  std::string&, LineJoin&);

 std::string textAlignName(TextAlign);
 bool parseTextAlign(const  std::string&, TextAlign&);

 std::string textBaselineName(TextBaseline);
 bool parseTextBaseline(const  std::string&, TextBaseline&);

} // namespace WebCore

#endif
