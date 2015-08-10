#ifndef __CANVASCONTEXT_2D__
#define __CANVASCONTEXT_2D__

#include "SkCanvas.h"
#include "string"
#include "vector"
#include "AffineTransform.h"

using namespace WebCore;

class CanvasStyle;

class CanvasContext2D
{
public:
	static PassRefPtr<CanvasContext2D> create(SkCanvas *canvas)
	{
		return adoptRef(new CanvasContext2D(canvas));
	}

	virtual ~CanvasContext2D();

	CanvasStyle *strokeStyle() const;
	void setStrokeStyle(PassRefPtr<CanvasStyle>);

	CanvasStyle* fillStyle() const;
	void setFillStyle(PassRefPtr<CanvasStyle>);

	float lineWidth() const;
	void setLineWidth(float);

	std::string lineCap() const;
	void setLineCap(const std::string&);

	std::string lineJoin() const;
	void setLineJoin(const std::string&);

	float miterLimit() const;
	void setMiterLimit(float);

	const std::vector<float>& getLineDash() const;
	void setLineDash(const std::vector<float>&);

	float lineDashOffset() const;
	void setLineDashOffset(float);

	float shadowOffsetX() const;
	void setShadowOffsetX(float);

	float shadowOffsetY() const;
	void setShadowOffsetY(float);

	float shadowBlur() const;
	void setShadowBlur(float);

	std::string shadowColor() const;
	void setShadowColor(const std::string&);

	float globalAlpha() const;
	void setGlobalAlpha(float);

	std::string globalCompositeOperation() const;
	void setGlobalCompositeOperation(const std::string&);

	void save() { ++m_stateStack.last().m_unrealizedSaveCount; }
	void restore();

	PassRefPtr<AffineTransform> currentTransform() const
	{
		return adoptRef(new AffineTransform(state().m_transform));
	}
	void setCurrentTransform(PassRefPtr<AffineTransform>);

	void scale(float sx, float sy);
	void rotate(float angleInRadians);
	void translate(float tx, float ty);
	void transform(float m11, float m12, float m21, float m22, float dx, float dy);
	void setTransform(float m11, float m12, float m21, float m22, float dx, float dy);
	void resetTransform();

	void setStrokeColor(const String& color);
	void setStrokeColor(float grayLevel);
	void setStrokeColor(const String& color, float alpha);
	void setStrokeColor(float grayLevel, float alpha);
	void setStrokeColor(float r, float g, float b, float a);
	void setStrokeColor(float c, float m, float y, float k, float a);

	void setFillColor(const String& color);
	void setFillColor(float grayLevel);
	void setFillColor(const String& color, float alpha);
	void setFillColor(float grayLevel, float alpha);
	void setFillColor(float r, float g, float b, float a);
	void setFillColor(float c, float m, float y, float k, float a);

	void beginPath();

	PassRefPtr<Path2D> currentPath();
	void setCurrentPath(Path2D*);
	void fill(const String& winding = "nonzero");
	void fill(Path2D*);
	void fill(Path2D*, const String& winding);
	void stroke();
	void stroke(Path2D*);
	void clip(const String& winding = "nonzero");
	void clip(Path2D*);
	void clip(Path2D*, const String& winding);

	bool isPointInPath(const float x, const float y, const String& winding = "nonzero");
	bool isPointInPath(Path2D*, const float x, const float y);
	bool isPointInPath(Path2D*, const float x, const float y, const String& winding);
	bool isPointInStroke(const float x, const float y);
	bool isPointInStroke(Path2D*, const float x, const float y);

	void clearRect(float x, float y, float width, float height);
	void fillRect(float x, float y, float width, float height);
	void strokeRect(float x, float y, float width, float height);

	void setShadow(float width, float height, float blur);
	void setShadow(float width, float height, float blur, const String& color);
	void setShadow(float width, float height, float blur, float grayLevel);
	void setShadow(float width, float height, float blur, const String& color, float alpha);
	void setShadow(float width, float height, float blur, float grayLevel, float alpha);
	void setShadow(float width, float height, float blur, float r, float g, float b, float a);
	void setShadow(float width, float height, float blur, float c, float m, float y, float k, float a);

	void clearShadow();

	void drawImage(Image*, float x, float y);
	void drawImage(CanvasImageSource*, float x, float y, float width, float height);
	void drawImage(CanvasImageSource*, float sx, float sy, float sw, float sh, float dx, float dy, float dw, float dh);

	void setAlpha(float);

	void setCompositeOperation(const String&);

	PassRefPtr<CanvasGradient> createLinearGradient(float x0, float y0, float x1, float y1);
	PassRefPtr<CanvasGradient> createRadialGradient(float x0, float y0, float r0, float x1, float y1, float r1);
	PassRefPtr<CanvasPattern> createPattern(CanvasImageSource*, const String& repetitionType);

	PassRefPtr<ImageData> createImageData(PassRefPtr<ImageData>) const;
	PassRefPtr<ImageData> createImageData(float width, float height) const;
	PassRefPtr<ImageData> getImageData(float sx, float sy, float sw, float sh) const;
	void putImageData(ImageData*, float dx, float dy);
	void putImageData(ImageData*, float dx, float dy, float dirtyX, float dirtyY, float dirtyWidth, float dirtyHeight);

	// Slated for deprecation:
	void webkitPutImageDataHD(ImageData* image, float dx, float dy) { putImageData(image, dx, dy); }
	void webkitPutImageDataHD(ImageData* image, float dx, float dy, float dirtyX, float dirtyY, float dirtyWidth, float dirtyHeight) { putImageData(image, dx, dy, dirtyX, dirtyY, dirtyWidth, dirtyHeight); }
	PassRefPtr<ImageData> webkitGetImageDataHD(float sx, float sy, float sw, float sh) const;
	float webkitBackingStorePixelRatio() const { return 1; }

	void reset();

	String font() const;
	void setFont(const String&);

	String textAlign() const;
	void setTextAlign(const String&);

	String textBaseline() const;
	void setTextBaseline(const String&);

	void fillText(const String& text, float x, float y);
	void fillText(const String& text, float x, float y, float maxWidth);
	void strokeText(const String& text, float x, float y);
	void strokeText(const String& text, float x, float y, float maxWidth);
	PassRefPtr<TextMetrics> measureText(const String& text);

	LineCap getLineCap() const { return state().m_lineCap; }
	LineJoin getLineJoin() const { return state().m_lineJoin; }

	bool imageSmoothingEnabled() const;
	void setImageSmoothingEnabled(bool);

	PassRefPtr<Canvas2DContextAttributes> getContextAttributes() const;

	void drawSystemFocusRing(Element*);
	bool drawCustomFocusRing(Element*);

private:
	struct State
	{
		State();
		virtual ~State();

		State(const State&);
		State& operator=(const State&);

		// CSSFontSelectorClient implementation
		virtual void fontsNeedUpdate(FontSelector*);

		unsigned m_unrealizedSaveCount;

		String m_unparsedStrokeColor;
		String m_unparsedFillColor;
		RefPtr<CanvasStyle> m_strokeStyle;
		RefPtr<CanvasStyle> m_fillStyle;
		float m_lineWidth;
		LineCap m_lineCap;
		LineJoin m_lineJoin;
		float m_miterLimit;
		FloatSize m_shadowOffset;
		float m_shadowBlur;
		RGBA32 m_shadowColor;
		float m_globalAlpha;
		CompositeOperator m_globalComposite;
		blink::WebBlendMode m_globalBlend;
		AffineTransform m_transform;
		bool m_invertibleCTM;
		Vector<float> m_lineDash;
		float m_lineDashOffset;
		bool m_imageSmoothingEnabled;

		// Text state.
		TextAlign m_textAlign;
		TextBaseline m_textBaseline;

		String m_unparsedFont;
		Font m_font;
		bool m_realizedFont;
	};

	CanvasRenderingContext2D(SkCanvas*, const Canvas2DContextAttributes* attrs, bool usesCSSCompatibilityParseMode);

	State& modifiableState() { return m_stateStack.last(); }
	const State& state() const { return m_stateStack.last(); }

	void applyLineDash();
	void setShadow(const FloatSize& offset, float blur, RGBA32 color);
	void applyShadow();
	bool shouldDrawShadows() const;

	bool computeDirtyRect(const FloatRect& localBounds, FloatRect*);
	bool computeDirtyRect(const FloatRect& localBounds, const FloatRect& transformedClipBounds, FloatRect*);
	void didDraw(const FloatRect&);

	//GraphicsContext* drawingContext() const;

	void unwindStateStack();
	void realizeSaves();

	void applyStrokePattern();
	void applyFillPattern();

	void drawImageInternal(CanvasImageSource*, float sx, float sy, float sw, float sh, float dx, float dy, float dw, float dh, CompositeOperator, blink::WebBlendMode);
	//void drawVideo(HTMLVideoElement*, FloatRect srcRect, FloatRect dstRect);

	void fillInternal(const Path&, const String& windingRuleString);
	void strokeInternal(const Path&);
	void clipInternal(const Path&, const String& windingRuleString);

	bool isPointInPathInternal(const Path&, const float x, const float y, const String& windingRuleString);
	bool isPointInStrokeInternal(const Path&, const float x, const float y);

	void drawTextInternal(const String& text, float x, float y, bool fill, float maxWidth = 0, bool useMaxWidth = false);

	const Font& accessFont();
	int getFontBaseline(const FontMetrics&) const;

	void clearCanvas();
	bool rectContainsTransformedRect(const FloatRect&, const FloatRect&) const;

	void inflateStrokeRect(FloatRect&) const;

	template<class T> void fullCanvasCompositedFill(const T&);
	//template<class T> void fullCanvasCompositedDrawImage(T*, const FloatRect&, const FloatRect&, CompositeOperator);

	bool focusRingCallIsValid(const Path&, Element*);
	void updateFocusRingAccessibility(const Path&, Element*);
	void drawFocusRing(const Path&);

	virtual bool is2d() const { return true; }
	virtual bool isAccelerated() const;
	virtual bool hasAlpha() const { return m_hasAlpha; }

	virtual bool isTransformInvertible() const { return state().m_invertibleCTM; }

	Vector<State, 1> m_stateStack;
	bool m_usesCSSCompatibilityParseMode;
	bool m_hasAlpha;
	MutableStylePropertyMap m_fetchedFonts;


};

#endif

