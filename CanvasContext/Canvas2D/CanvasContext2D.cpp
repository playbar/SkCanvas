#include "CanvasContext2D.h"
#include "SkiaUtils.h"
#include "graphicstypes.h"
#include "CanvasGradient.h"
#include "CanvasPattern.h"

static const int defaultFontSize = 30;
static const char defaultFontFamily[] = "sans-serif";
static const char defaultFont[] = "10px sans-serif";

static bool parseWinding(const std::string& windingRuleString, WindRule& windRule)
{
	if (windingRuleString == "nonzero")
		windRule = RULE_NONZERO;
	else if (windingRuleString == "evenodd")
		windRule = RULE_EVENODD;
	else
		return false;

	return true;
}

void canonicalizeAngle(float* startAngle, float* endAngle)
{
	// Make 0 <= startAngle < 2*PI
	float newStartAngle = *startAngle;
	if (newStartAngle < 0)
		newStartAngle = twoPiFloat + fmodf(newStartAngle, -twoPiFloat);
	else
		newStartAngle = fmodf(newStartAngle, twoPiFloat);

	float delta = newStartAngle - *startAngle;
	*startAngle = newStartAngle;
	*endAngle = *endAngle + delta;
}


float adjustEndAngle(float startAngle, float endAngle, bool anticlockwise)
{
	float newEndAngle = endAngle;
	if (!anticlockwise && endAngle - startAngle >= twoPiFloat)
		newEndAngle = startAngle + twoPiFloat;
	else if (anticlockwise && startAngle - endAngle >= twoPiFloat)
		newEndAngle = startAngle - twoPiFloat;
	else if (!anticlockwise && startAngle > endAngle)
		newEndAngle = startAngle + (twoPiFloat - fmodf(startAngle - endAngle, twoPiFloat));
	else if (anticlockwise && startAngle < endAngle)
		newEndAngle = startAngle - (twoPiFloat - fmodf(endAngle - startAngle, twoPiFloat));

	return newEndAngle;
}

//////////////////////////////////////////////////////////////////////////

CanvasContext2D::CanvasContext2D(SkCanvas*canvas )
{
	m_pCanvas = canvas;
	m_stateStack.resize(1);
	m_strokePaint.setStyle(SkPaint::kStroke_Style);
	m_fillPaint.setStyle(SkPaint::kFill_Style);

}

CanvasContext2D::~CanvasContext2D()
{

}

CanvasStyle *CanvasContext2D::strokeStyle() const
{
	return NULL;
}

void CanvasContext2D::setStrokeStyle(PassRefPtr<CanvasStyle>prpStyle)
{

}

void CanvasContext2D::applyStokeColor(PassRefPtr<CanvasStyle>style)
{
	switch (style->getType())
	{
	case CanvasStyle::RGBA:
		m_strokePaint.setColor(style->getRgba());
		break;
	case CanvasStyle::CMYKA:
		m_strokePaint.setColor(style->getRgba());
		break;
	case CanvasStyle::Gradient:
		m_strokePaint.setColor(0xff000000);
		m_strokePaint.setShader(style->canvasGradient()->gradient()->shader());
		break;
	case  CanvasStyle::ImagePattern:
		m_strokePaint.setColor(0xff000000);
		m_strokePaint.setShader(style->canvasPattern()->pattern()->shader());
		break;
	default:
		break;
	}
}

CanvasStyle* CanvasContext2D::fillStyle() const
{
	return NULL;
}
void CanvasContext2D::setFillStyle(PassRefPtr<CanvasStyle> prpStyle)
{
	RefPtr <CanvasStyle> style = prpStyle;
	if ( !style )
	{
		return;
	}
	applyFillColor(style);
}

void CanvasContext2D::applyFillColor(PassRefPtr<CanvasStyle> style )
{
	switch (style->getType())
	{
	case CanvasStyle::RGBA:
		m_fillPaint.setColor(style->getRgba());
		break;
	case CanvasStyle::CMYKA:
		m_fillPaint.setColor(style->getRgba());
		break;
	case CanvasStyle::Gradient:
		m_fillPaint.setColor(0xff000000);
		m_fillPaint.setShader(style->canvasGradient()->gradient()->shader());
		break;
	case  CanvasStyle::ImagePattern:
		m_fillPaint.setColor(0xff000000);
		m_fillPaint.setShader(style->canvasPattern()->pattern()->shader());
		break;
	default:
		break;
	}
}

float CanvasContext2D::lineWidth() const
{
	return 0.0f;
}
void CanvasContext2D::setLineWidth(float thickness )
{
	m_strokePaint.setStrokeWidth(thickness);
}

std::string CanvasContext2D::lineCap() const
{
	return "";
}
void CanvasContext2D::setLineCap(const std::string& s)
{
	LineCap cap;
	if ( !parseLineCap( s, cap ))
	{
		return;
	}
	if ( m_strokePaint.getStrokeCap() == cap )
	{
		return;
	}
	m_strokePaint.setStrokeCap((SkPaint::Cap)cap);
}

std::string CanvasContext2D::lineJoin() const
{
	return "";
}
void CanvasContext2D::setLineJoin(const std::string&s)
{
	LineJoin join;
	if ( !parseLineJoin( s, join ))
	{
		return;
	}
	if ( m_strokePaint.getStrokeJoin() == join )
	{
		return;
	}
	m_strokePaint.setStrokeJoin((SkPaint::Join)join);
}

float CanvasContext2D::miterLimit() const
{
	return 0.0f;
}
void CanvasContext2D::setMiterLimit(float miterLimit)
{
	m_strokePaint.setStrokeMiter(miterLimit);
}

const std::vector<float>& CanvasContext2D::getLineDash() const
{
	std::vector<float> temp;
	return temp;
}
void CanvasContext2D::setLineDash(const std::vector<float>&)
{

}

float CanvasContext2D::lineDashOffset() const
{
	return 0.0f;
}
void CanvasContext2D::setLineDashOffset(float)
{

}

float CanvasContext2D::shadowOffsetX() const
{
	return 0.0f;
}
void CanvasContext2D::setShadowOffsetX(float)
{

}

float CanvasContext2D::shadowOffsetY() const
{
	return 0.0f;
}

void CanvasContext2D::setShadowOffsetY(float)
{

}

float CanvasContext2D::shadowBlur() const
{
	return 0.0f;
}

void CanvasContext2D::setShadowBlur(float)
{

}

std::string CanvasContext2D::shadowColor() const
{
	return "";
}
void CanvasContext2D::setShadowColor(const std::string&)
{

}

float CanvasContext2D::globalAlpha() const
{
	return 0.0f;
}
void CanvasContext2D::setGlobalAlpha(float)
{

}

std::string CanvasContext2D::globalCompositeOperation() const
{
	return "";
}
void CanvasContext2D::setGlobalCompositeOperation(const std::string&)
{

}

void CanvasContext2D::save()
{
}
void CanvasContext2D::restore()
{

}


void CanvasContext2D::setCurrentTransform(PassRefPtr<AffineTransform>)
{

}

void CanvasContext2D::scale(float sx, float sy)
{
	if ( !std::isfinite( sx) | ! std::isfinite( sy ))
	{
		return;
	}
	SkMatrix mat = affineTransformToSkMatrix(AffineTransform().scaleNonUniform(1.0f / sx, 1.0f / sy));
	m_path.transform(mat);
	m_pCanvas->scale(sx, sy);
}

void CanvasContext2D::rotate(float angleInRadians)
{}

void CanvasContext2D::translate(float tx, float ty)
{
	m_pCanvas->translate(tx, ty);
}
void CanvasContext2D::transform(float m11, float m12, float m21, float m22, float dx, float dy)
{

}
void CanvasContext2D::setTransform(float m11, float m12, float m21, float m22, float dx, float dy)
{

}
void CanvasContext2D::resetTransform()
{

}

void CanvasContext2D::setStrokeColor(const std::string& color)
{
	RefPtr<CanvasStyle> style = CanvasStyle::createFromString(color);
	if (!style)
	{
		return;
	}
	applyStokeColor(style);;
}
void CanvasContext2D::setStrokeColor(float grayLevel)
{

}
void CanvasContext2D::setStrokeColor(const std::string& color, float alpha)
{

}
void CanvasContext2D::setStrokeColor(float grayLevel, float alpha)
{

}
void CanvasContext2D::setStrokeColor(float r, float g, float b, float a)
{

}
void CanvasContext2D::setStrokeColor(float c, float m, float y, float k, float a)
{

}

void CanvasContext2D::setFillColor(const std::string &color)
{
	RefPtr<CanvasStyle> style = CanvasStyle::createFromString(color);
	if ( !style )
	{
		return;
	}
	applyFillColor(style);
}
void CanvasContext2D::setFillColor(float grayLevel)
{

}
void CanvasContext2D::setFillColor(const std::string& color, float alpha)
{

}
void CanvasContext2D::setFillColor(float grayLevel, float alpha)
{

}
void CanvasContext2D::setFillColor(float r, float g, float b, float a)
{

}
void CanvasContext2D::setFillColor(float c, float m, float y, float k, float a)
{

}

void CanvasContext2D::beginPath()
{
	m_path.reset();
}

void CanvasContext2D::closePath()
{
	if ( m_path.isEmpty() )
	{
		return;
	}
	m_path.close();
}

void CanvasContext2D::moveTo(float x, float y)
{
	if (!std::isfinite(x) || !std::isfinite(y))
		return;
	if (!isTransformInvertible())
		return;
	m_path.moveTo(x, y);
}

void CanvasContext2D::lineTo(float x, float y)
{
	if (!std::isfinite(x) || !std::isfinite(y))
		return;
	if (!isTransformInvertible())
		return;
	SkPoint p1 = SkPoint::Make(x, y);
	if (! hasCurrentPoint())
	{
		m_path.moveTo(x, y);
	}
	else if (p1 != currentPoint())
	{
		m_path.lineTo(x, y);
	}


}

void CanvasContext2D::quadraticCurveTo(float cpx, float cpy, float x, float y)
{
	if (!std::isfinite(cpx) || !std::isfinite(cpy) || !std::isfinite(x) || !std::isfinite(y))
		return;
	if ( !hasCurrentPoint() )
	{
		m_path.moveTo(cpx, cpy);
	}
	SkPoint p1 = SkPoint::Make(x, y);
	SkPoint cp = SkPoint::Make(cpx, cpy);
	if ( p1 != currentPoint()  || p1 != cp )
	{
		m_path.quadTo(cp, p1);
	}
}
void CanvasContext2D::bezierCurveTo(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y)
{
	if (!std::isfinite(cp1x) || !std::isfinite(cp1y) || !std::isfinite(cp2x) || !std::isfinite(cp2y) || !std::isfinite(x) || !std::isfinite(y))
		return;
	if ( ! hasCurrentPoint() )
	{
		m_path.moveTo(cp1x, cp1y);
	}
	SkPoint p1 = SkPoint::Make(x, y);
	SkPoint cp1 = SkPoint::Make(cp1x, cp1y);
	SkPoint cp2 = SkPoint::Make(cp2x, cp2y);
	if ( p1 != currentPoint() || p1 != cp1 || p1 != cp2 )
	{
		m_path.cubicTo(cp1, cp2, p1);
	}
	return;
}

void CanvasContext2D::arcTo(float x1, float y1, float x2, float y2, float radius)
{
	if (!std::isfinite(x1) || !std::isfinite(y1) || !std::isfinite(x2) || !std::isfinite(y2) || !std::isfinite(radius))
		return;

	if (radius< 0) {
		return;
	}

	if (!isTransformInvertible())
		return;

	SkPoint p1 = SkPoint::Make(x1, y1);
	SkPoint p2 = SkPoint::Make(x2, y2);
	if ( ! hasCurrentPoint() )
	{
		m_path.moveTo(x1, y1);
	}
	else if (p1 == currentPoint() || p1 == p2 || !radius)
	{
		lineTo(x1, y1);
	}
	else
	{
		m_path.arcTo(x1, y1, x2, y2, radius);
	}
}

void CanvasContext2D::arc(float x, float y, float radius, float startAngle, float endAngle, bool anticlockwise)
{
	if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(radius) || !std::isfinite(startAngle) || !std::isfinite(endAngle))
		return;

	if (radius < 0) {
		return;
	}

	if (!isTransformInvertible())
		return;

	if (!radius || startAngle == endAngle) {
		// The arc is empty but we still need to draw the connecting line.
		lineTo(x + radius * cosf(startAngle), y + radius * sinf(startAngle));
		return;
	}

	canonicalizeAngle(&startAngle, &endAngle);
	float adjustedEndAngle = adjustEndAngle(startAngle, endAngle, anticlockwise);
	addEllipse(FloatPoint(x, y), radius, radius, startAngle, adjustedEndAngle, anticlockwise);

}

void CanvasContext2D::ellipse(float x, float y, float radiusX, float radiusY, float rotation, float startAngle, float endAngle, bool anticlockwise)
{

}

void CanvasContext2D::rect(float x, float y, float width, float height)
{
	if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(width) || !std::isfinite(height))
		return;
	if ( !width && !height )
	{
		m_path.moveTo(x, y);
	}
	m_path.addRect(x, y, x + width, y + height);
}


void CanvasContext2D::addEllipse(const FloatPoint& p, float radiusX, float radiusY, float startAngle, float endAngle, bool anticlockwise)
{
	SkScalar cx = (p.x());
	SkScalar cy = (p.y());
	SkScalar radiusXScalar = (radiusX);
	SkScalar radiusYScalar = (radiusY);

	SkRect oval;
	oval.set(cx - radiusXScalar, cy - radiusYScalar, cx + radiusXScalar, cy + radiusYScalar);

	float sweep = endAngle - startAngle;
	SkScalar startDegrees = (startAngle * 180 / piFloat);
	SkScalar sweepDegrees = (sweep * 180 / piFloat);
	SkScalar s360 = SkIntToScalar(360);

	// We can't use SkPath::addOval(), because addOval() makes new sub-path. addOval() calls moveTo() and close() internally.

	// Use s180, not s360, because SkPath::arcTo(oval, angle, s360, false) draws nothing.
	SkScalar s180 = SkIntToScalar(180);
	if (SkScalarNearlyEqual(sweepDegrees, s360)) {
		// SkPath::arcTo can't handle the sweepAngle that is equal to or greater than 2Pi.
		m_path.arcTo(oval, startDegrees, s180, false);
		m_path.arcTo(oval, startDegrees + s180, s180, false);
		return;
	}
	if (SkScalarNearlyEqual(sweepDegrees, -s360)) {
		m_path.arcTo(oval, startDegrees, -s180, false);
		m_path.arcTo(oval, startDegrees - s180, -s180, false);
		return;
	}

	m_path.arcTo(oval, startDegrees, sweepDegrees, false);
}

void CanvasContext2D::fill(const std::string& winding)
{
	if ( m_path.isEmpty())
	{
		return;
	}
	m_pCanvas->drawPath(m_path, m_fillPaint);
}


void CanvasContext2D::stroke()
{
	m_pCanvas->drawPath(m_path, m_strokePaint);
}

void CanvasContext2D::clip(const std::string& winding)
{
	WindRule newWindRule = RULE_NONZERO;
	if ( ! parseWinding( winding, newWindRule ))
	{
		return;
	}
	SkPath::FillType previousFillType = m_path.getFillType();
	SkPath::FillType temporaryFillType = newWindRule == RULE_EVENODD ? SkPath::kEvenOdd_FillType : SkPath::kWinding_FillType;
	m_path.setFillType(temporaryFillType);
	m_pCanvas->clipPath(m_path);
	m_path.setFillType(previousFillType);
	return;
}

bool CanvasContext2D::isPointInPath(const float x, const float y, const std::string& winding)
{
	return true;
}

void CanvasContext2D::clearRect(float x, float y, float width, float height)
{
	SkRect r = SkRect::MakeXYWH(x, y, width, height);
	SkPaint paint(m_fillPaint);
	paint.setXfermodeMode(SkXfermode::kClear_Mode);
	m_pCanvas->drawRect(r, paint);

}

void CanvasContext2D::fillRect(float x, float y, float width, float height)
{
	SkRect r = SkRect::MakeXYWH(x, y, width, height);
	m_pCanvas->drawRect(r, m_fillPaint );
	return;
}

void CanvasContext2D::strokeRect(float x, float y, float width, float height)
{
	SkRect r = SkRect::MakeXYWH(x, y, width, height);
	m_pCanvas->drawRect(r, m_strokePaint);
}

PassRefPtr<CanvasGradient> CanvasContext2D::createLinearGradient(float x0, float y0, float x1, float y1)
{
	RefPtr< CanvasGradient> gradient = CanvasGradient::create(SkPoint::Make(x0, y0), SkPoint::Make(x1, y1));
	return gradient.release();
}

bool CanvasContext2D::isAccelerated() const
{
	return true;
}

bool CanvasContext2D::hasCurrentPoint() const
{
	return m_path.getPoints(0, 0);
}

SkPoint CanvasContext2D::currentPoint() const
{
	if ( m_path.countPoints() > 0 )
	{
		SkPoint skResult;
		m_path.getLastPt(&skResult);
		return skResult;
	}
	float quietNan = std::numeric_limits<float>::quiet_NaN();
	return SkPoint::Make(quietNan, quietNan);
}

CanvasContext2D::State::State()
	: m_unrealizedSaveCount(0)	
	, m_lineWidth(1)
	, m_lineCap(ButtCap)
	, m_lineJoin(MiterJoin)
	, m_miterLimit(10)
	, m_shadowBlur(0)
	, m_shadowColor(Color::transparent)
	, m_globalAlpha(1)
	, m_globalComposite(CompositeSourceOver)
	, m_globalBlend(WebBlendModeNormal)
	, m_invertibleCTM(true)
	, m_lineDashOffset(0)
	, m_imageSmoothingEnabled(true)
	, m_textAlign(StartTextAlign)
	, m_textBaseline(AlphabeticTextBaseline)
	, m_unparsedFont(defaultFont)
	, m_realizedFont(false)
{
	m_strokeStyle = (CanvasStyle::createFromRGBA(Color::black));
	m_fillStyle = (CanvasStyle::createFromRGBA(Color::black));
}

CanvasContext2D::State::State(const State& other)
	: m_unrealizedSaveCount(other.m_unrealizedSaveCount)
	, m_unparsedStrokeColor(other.m_unparsedStrokeColor)
	, m_unparsedFillColor(other.m_unparsedFillColor)
	, m_strokeStyle(other.m_strokeStyle)
	, m_fillStyle(other.m_fillStyle)
	, m_lineWidth(other.m_lineWidth)
	, m_lineCap(other.m_lineCap)
	, m_lineJoin(other.m_lineJoin)
	, m_miterLimit(other.m_miterLimit)
	, m_shadowOffset(other.m_shadowOffset)
	, m_shadowBlur(other.m_shadowBlur)
	, m_shadowColor(other.m_shadowColor)
	, m_globalAlpha(other.m_globalAlpha)
	, m_globalComposite(other.m_globalComposite)
	, m_globalBlend(other.m_globalBlend)
	, m_transform(other.m_transform)
	, m_invertibleCTM(other.m_invertibleCTM)
	, m_lineDashOffset(other.m_lineDashOffset)
	, m_imageSmoothingEnabled(other.m_imageSmoothingEnabled)
	, m_textAlign(other.m_textAlign)
	, m_textBaseline(other.m_textBaseline)
	, m_unparsedFont(other.m_unparsedFont)
	//, m_font(other.m_font)
	, m_realizedFont(other.m_realizedFont)
{
	
}

CanvasContext2D::State& CanvasContext2D::State::operator=(const State& other)
{
	if (this == &other)
		return *this;

	m_unrealizedSaveCount = other.m_unrealizedSaveCount;
	m_unparsedStrokeColor = other.m_unparsedStrokeColor;
	m_unparsedFillColor = other.m_unparsedFillColor;
	m_strokeStyle = other.m_strokeStyle;
	m_fillStyle = other.m_fillStyle;
	m_lineWidth = other.m_lineWidth;
	m_lineCap = other.m_lineCap;
	m_lineJoin = other.m_lineJoin;
	m_miterLimit = other.m_miterLimit;
	m_shadowOffset = other.m_shadowOffset;
	m_shadowBlur = other.m_shadowBlur;
	m_shadowColor = other.m_shadowColor;
	m_globalAlpha = other.m_globalAlpha;
	m_globalComposite = other.m_globalComposite;
	m_globalBlend = other.m_globalBlend;
	m_transform = other.m_transform;
	m_invertibleCTM = other.m_invertibleCTM;
	m_imageSmoothingEnabled = other.m_imageSmoothingEnabled;
	m_textAlign = other.m_textAlign;
	m_textBaseline = other.m_textBaseline;
	m_unparsedFont = other.m_unparsedFont;
	//m_font = other.m_font;
	m_realizedFont = other.m_realizedFont;

	return *this;
}

CanvasContext2D::State::~State()
{
}
