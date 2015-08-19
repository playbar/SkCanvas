
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SampleCode.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkPaint.h"

#include "CanvasContext2D.h"
#include "PassOwnPtr.h"
#include "SkiaUtils.h"
#include "CanvasGradient.h"
#include "SkTypeface.h"
#include "SkStream.h"
#include "SkImageDecoder.h"
#include "SkForceLinking.h"
#include "BitmapImage.h"
#include "CanvasPattern.h"
#include "include/v8.h"
#include "include/libplatform/libplatform.h"
using namespace v8;

using namespace WebCore;
using namespace WTF;

// ensure that we don't accidentally screw up the bounds when the oval is
// fractional, and the impl computes the center and radii, and uses them to
// reconstruct the edges of the circle.
// see bug# 1504910

//static SkImageDecoder_DecodeReg gDReg(sk_libpng_dfactory);
//static SkImageDecoder_FormatReg gFormatReg(get_format_png);
//static SkImageEncoder_EncodeReg gEReg(sk_libpng_efactory);

static void test_circlebounds(SkCanvas*) {
    SkRect r = { 1.39999998f, 1, 21.3999996f, 21 };
    SkPath p;
    p.addOval(r);
    SkASSERT(r == p.getBounds());
}

class ArrayBufferAllocator : public v8::ArrayBuffer::Allocator {
public:
	virtual void* Allocate(size_t length) {
		void* data = AllocateUninitialized(length);
		return data == NULL ? data : memset(data, 0, length);
	}
	virtual void* AllocateUninitialized(size_t length) { return malloc(length); }
	virtual void Free(void* data, size_t) { free(data); }
};

class CanvasTestView : public SampleView {
public:
    static const SkScalar ANIM_DX;
    static const SkScalar ANIM_DY;
    static const SkScalar ANIM_RAD;
    SkScalar fDX, fDY, fRAD;
	SkBitmap fbmp;

    CanvasTestView() {
		SkForceLinking(false);
        fDX = fDY = fRAD = 0;
        fN = 3;
		SkFILEStream stream("c:/test_ba.png");
		SkImageDecoder * code = SkImageDecoder::Factory(&stream);
		code->decode(&stream, &fbmp, SkColorType::kRGBA_8888_SkColorType, SkImageDecoder::kDecodePixels_Mode);

    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt) {
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "CanvasTestView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    void circle(SkCanvas* canvas, int width, bool aa) {
        SkPaint paint;

        paint.setAntiAlias(aa);
        if (width < 0) {
            paint.setStyle(SkPaint::kFill_Style);
        } else {
            paint.setStyle(SkPaint::kStroke_Style);
            paint.setStrokeWidth(SkIntToScalar(width));
        }
        canvas->drawCircle(0, 0, SkIntToScalar(9) + fRAD, paint);
        if (false) { // avoid bit rot, suppress warning
            test_circlebounds(canvas);
        }
    }

    void drawSix(SkCanvas* canvas, SkScalar dx, SkScalar dy) {
        for (int width = -1; width <= 1; width++) {
            canvas->save();
            circle(canvas, width, false);
            canvas->translate(0, dy);
            circle(canvas, width, true);
            canvas->restore();
            canvas->translate(dx, 0);
        }
    }

    static void make_poly(SkPath* path, int n) {
        if (n <= 0) {
            return;
        }
        path->incReserve(n + 1);
        path->moveTo(SK_Scalar1, 0);
        SkScalar step = SK_ScalarPI * 2 / n;
        SkScalar angle = 0;
        for (int i = 1; i < n; i++) {
            angle += step;
            SkScalar c, s = SkScalarSinCos(angle, &c);
            path->lineTo(c, s);
        }
        path->close();
    }

    static void rotate(SkCanvas* canvas, SkScalar angle, SkScalar px, SkScalar py) {
        canvas->translate(-px, -py);
        canvas->rotate(angle);
        canvas->translate(px, py);
    }

	void TestArc(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineWidth(5);
		ctx->setStrokeColor("#ff00ff");
		ctx->arc(100, 75, 50, 0, 2 * M_PI, false);
		ctx->stroke();
	}

	void TestArcTo(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setStrokeColor("green");
		ctx->setLineWidth(8);
		ctx->moveTo(20, 20);
		ctx->lineTo(100, 20);
		ctx->arcTo(150, 20, 150, 70, 50);
		ctx->lineTo(150, 120);
		ctx->stroke();
		return;
	}

	// todo 
	void TestFillStyle(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setFillColor("#0000ff");
		ctx->fillRect(20, 20, 150, 100);
	}

	void TestBeginPath(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineWidth(4);
		ctx->setStrokeColor("#0000ff");
		ctx->moveTo(0, 75);
		ctx->lineTo(250, 75);
		ctx->stroke();

		ctx->beginPath();
		ctx->setStrokeColor("#00ff00");
		ctx->setLineWidth(10);
		ctx->moveTo(50, 0);
		ctx->lineTo(150, 130);
		ctx->stroke();
	}

	void TestQuadraticCureTo(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineWidth(4);
		ctx->moveTo(20, 20);
		ctx->quadraticCurveTo(20, 100, 200, 20);
		ctx->stroke();
	}

	void TestStrokeStyle(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setLineWidth(6);
		ctx->setStrokeColor("#00ff00");
		ctx->strokeRect(20, 20, 150, 100);
	}

	void TestStroke(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineWidth(5);
		ctx->moveTo(20, 20);
		ctx->lineTo(20, 100);
		ctx->lineTo(70, 100);
		ctx->closePath();
		ctx->setStrokeColor("green");
		ctx->stroke();
	}

	void TestScale(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->strokeRect(5, 5, 25, 15);
		ctx->scale(2, 2);
		ctx->strokeRect(5, 5, 15, 15);
	}

	void TestRect(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineWidth(6);
		ctx->setStrokeColor("red");
		ctx->rect(5, 5, 290, 140);
		ctx->stroke();

		ctx->beginPath();
		ctx->setLineWidth(4);
		ctx->setStrokeColor("green");
		ctx->rect(30, 30, 50, 50);
		ctx->stroke();

		ctx->beginPath();
		ctx->setLineWidth(10);
		ctx->setStrokeColor("blue");
		ctx->rect(50, 50, 150, 80);
		ctx->stroke();
	}
	void TestMiterLimit(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineWidth(10);
		ctx->setLineJoin("miter");
		ctx->setMiterLimit(5);
		ctx->moveTo(20, 20);
		ctx->lineTo(50, 27);
		ctx->lineTo(20, 34);
		ctx->stroke();
	}

	void TestLineCap(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineCap("butt");
		ctx->setLineWidth(10);
		ctx->moveTo(20, 20);
		ctx->lineTo(200, 20);
		ctx->stroke();

		ctx->beginPath();
		ctx->setLineCap("round");
		ctx->moveTo(20, 40);
		ctx->lineTo(200, 40);
		ctx->stroke();

		ctx->beginPath();
		ctx->setLineCap("square");
		ctx->moveTo(20, 60);
		ctx->lineTo(200, 60);
		ctx->stroke();
	}

	void TestIsPointInPath(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->moveTo(20, 20);
		ctx->lineTo(20, 100);
		ctx->lineTo(100, 100);
		ctx->closePath();
		if (ctx->isPointInPath( 90, 90))
		{
			ctx->stroke();
		}
		
	}

	void TestFill(SkCanvas *canvas)
	{
		SkPaint paint;
		//paint.setColor(0xFF008000);
		//canvas->drawRectCoords(0, 0, 100, 100, paint);
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->rect(5, 5, 50, 50);
		ctx->setFillColor("blue");
		ctx->fill();

	}

	void TestAddColorStop(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		PassRefPtr<CanvasGradient> grd = ctx->createLinearGradient(0, 0, 170, 0);
		grd->addColorStop(0, "black");
		grd->addColorStop(0.3, "magenta");
		grd->addColorStop(0.5, "blue");
		grd->addColorStop(0.6, "green");
		grd->addColorStop(0.8, "yellow");
		grd->addColorStop(1, "red");
		RefPtr<CanvasStyle> style = CanvasStyle::createFromGradient(grd);
		ctx->setFillStyle(style);
		ctx->fillRect(10, 10, 150, 100);
	}

	void TestBezierCurveTo(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineWidth(4);
		ctx->setStrokeColor("red");
		ctx->moveTo(20, 20);
		ctx->bezierCurveTo(20, 100, 200, 100, 200, 20);
		ctx->stroke();
	}

	void TestClearRect(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setFillColor("red");
		ctx->fillRect(0, 0, 300, 150);
		ctx->clearRect( 20, 20 , 100, 50 );
	}

	void TestClip(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->rect(50, 20, 200, 100);
		ctx->stroke();
		ctx->clip();
		ctx->setFillColor("green");
		ctx->fillRect(0, 0, 150, 100);
	}

	void TestTranslate(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->fillRect(10, 10, 100, 50);
		ctx->translate(70, 70);
		ctx->fillRect(10, 10, 100, 50);
	}

	void TestFont(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setFont("12");
		ctx->strokeText("Hello", 10, 50);
	}

	inline std::string Unicode2ASCII(const std::wstring &strUnicode, UINT CodePage = CP_UTF8)
	{
		int nByte = WideCharToMultiByte(CodePage, 0, strUnicode.c_str(), -1, 0, 0, 0, 0);
		if (nByte <= 0)
		{
			return "";
		}
		std::string strUtf8;
		strUtf8.resize(nByte + 1, '\0');
		WideCharToMultiByte(CodePage, 0, strUnicode.c_str(), -1, &strUtf8[0], nByte, 0, 0);
		return std::string(strUtf8.c_str());
	}

	void TestDrawZHText(SkCanvas *canvas)
	{
		SkPaint paint;
		SkTypeface* pFace = SkTypeface::CreateFromName("ËÎÌå", SkTypeface::kNormal);
		paint.setTypeface(pFace);
		std::string str = "1234¹È¸è56789";
		//std::string str = Unicode2ASCII(std::wstring(L"1234¹È¸è56789"));
		paint.setAntiAlias(true);
		paint.setColor(0xff008000);
		paint.setTextSize(150);
		paint.setStyle(SkPaint::kStroke_Style);
		paint.setStrokeWidth(2);
		canvas->drawText( str.c_str(), str.length(), 150, 150, paint);
	}

	void TestRotate(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->rotate(20 * M_PI / 180);
		ctx->fillRect(50, 20, 100, 50);
	}

	void TestTransform(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setFillColor("yellow");
		ctx->fillRect(0, 0, 250, 100);

		ctx->transform(1, 0.5, -0.5, 1, 30, 10);
		ctx->setFillColor("red");
		ctx->fillRect(0, 0, 250, 100);

		ctx->transform(1, 0.5, -0.5, 1, 30, 10);
		ctx->setFillColor("blue");
		ctx->fillRect(0, 0, 250, 100);
	}

	void TestSetTransform(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setFillColor("yellow");
		ctx->fillRect(0, 0, 250, 100);

		ctx->setTransform(1, 0.5, -0.5, 1, 30, 10);
		ctx->setFillColor("red");
		ctx->fillRect(0, 0, 250, 100);

		ctx->setTransform(1, 0.5, -0.5, 1, 30, 10);
		ctx->setFillColor("blue");
		ctx->fillRect(0, 0, 250, 100);
		return;
	}

	void TestTextAlign(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setStrokeColor("blue");
		ctx->setLineWidth(0.5);
		ctx->moveTo(150, 20);
		ctx->lineTo(150, 170);
		ctx->stroke();

		ctx->setFont("15px Arial");
		ctx->setTextAlign("start");
		ctx->fillText("textAlign=start", 150, 60);

		ctx->setTextAlign("end");
		ctx->fillText("testAlign=end", 150, 80);

		ctx->setTextAlign("left");
		ctx->fillText("testAlign=left", 150, 100);

		ctx->setTextAlign("center");
		ctx->fillText("testAlign=center", 150, 120);

		ctx->setTextAlign("right");
		ctx->fillText("testAlign=right", 150, 140);

	}

	void TestBaseLine(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setStrokeColor("blue");
		ctx->moveTo(5, 100);
		ctx->lineTo(395, 100);
		ctx->stroke();

		ctx->setFont("italic small-caps bold 20px arial");
		ctx->setTextBaseline("top");
		ctx->fillText("Top", 5, 100);

		ctx->setTextBaseline("bottom");
		ctx->fillText("bottom", 50, 100);

		ctx->setTextBaseline("middle");
		ctx->fillText("middle", 120, 100);

		ctx->setTextBaseline("alphabetic");
		ctx->fillText("alphabetic", 190, 100);

		ctx->setTextBaseline("hanging");
		ctx->fillText("Hanging", 290, 100);

		float re = ctx->measureText("test");
		re += 0;

	}

	void TestGlobalAlpha(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setFillColor("red");
		ctx->fillRect(20, 20, 75, 50);

		ctx->setGlobalAlpha(0.2);
		ctx->setFillColor("green");
		ctx->fillRect(50, 50, 75, 50);
		ctx->setFillColor("blue");
		ctx->fillRect(80, 80, 75, 50);
	}

	void TestGlobalCompositeOperation( SkCanvas *canvas )
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setFillColor("red");
		ctx->fillRect(20, 20, 75, 50);
		ctx->setGlobalCompositeOperation("destination-over");
		ctx->setFillColor("blue");
		ctx->fillRect(50, 50, 75, 50);

	}

	void TestShadowColor(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setShadowBlur(20);
		ctx->setShadowColor("black");
		ctx->setFillColor("blue");
		ctx->fillRect(20, 20, 150, 100);
	}

	void TestShadowOffset(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->setShadowBlur(10);
		ctx->setShadowOffsetX(20);
		ctx->setShadowOffsetY(40);
		ctx->setShadowColor("black");
		ctx->setFillColor("blue");
		ctx->fillRect(20, 20, 100, 80);
	}
	void TestSkPaint(SkCanvas *canvas)
	{
		SkTypeface *typeface = SkTypeface::RefDefault(SkTypeface::kBold);
		SkPaint paint;
		if ( typeface )
		{
			paint.setTypeface(typeface);
		}
		paint.setAntiAlias(true);
		paint.setTextSize(80);
		paint.setDither(true);
		paint.setLinearText(true);
		paint.setLCDRenderText(true);
		//paint.setVerticalText(true);
		paint.setDevKernText(true);
		paint.setFilterLevel(SkPaint::kHigh_FilterLevel);
		//paint.setTextSkewX(1);
		paint.setStyle(SkPaint::kStroke_Style);
		//canvas->drawText("abcd", 4, 200, 300, paint);
		SkPoint pt[2];
		pt[0] = SkPoint::Make(200, 300);
		pt[1] = SkPoint::Make(300, 300);
		canvas->drawPosText("ABCD", 4, pt, paint);
		//canvas->
	}

	void TestLineJoin(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		ctx->beginPath();
		ctx->setLineWidth(10);
		ctx->setLineJoin("round");
		ctx->setStrokeColor("red");
		ctx->moveTo(20, 20);
		ctx->lineTo(100, 50);
		ctx->lineTo(20, 100);
		ctx->stroke();
	}

	void TestCreateRadialGradient(SkCanvas *canvas )
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		PassRefPtr<CanvasGradient> grd = ctx->createRadialGradient(75, 50, 5, 90, 60, 100);
		grd->addColorStop(0, "red");
		grd->addColorStop(1, "white");
		RefPtr<CanvasStyle> style = CanvasStyle::createFromGradient(grd);
		ctx->setFillStyle(style);
		ctx->fillRect(10, 10, 150, 100);
	}


	void TestDrawImage1(SkCanvas *canvas)
	{
		//PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);

		SkPaint paint;
		paint.setColor(0xFF00ff00);
		paint.setStrokeWidth(2);
		paint.setStyle(SkPaint::kStroke_Style);

		//int fx = 10;
		//int fy = 10;
		SkPath path;
		path.moveTo(10, 10);
		path.lineTo(50, 50);
		canvas->drawBitmap(fbmp, 10, 10, &paint);
		canvas->drawPath(path, paint);

		SkBitmap destBitmap;
		SkImageInfo info = SkImageInfo::MakeN32Premul( 128, 128 );

		destBitmap.allocPixels(info);
		canvas->readPixels(&destBitmap, 10, 10);
		canvas->writePixels(destBitmap, 400, 200);
		//canvas->drawBitmap(destBitmap, 400, 200, &paint);
		//this->inval(NULL);
	}

	void TestDrawImage(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		RefPtr<BitmapImage> img = BitmapImage::create();
		img->src("c:/test_ba.png");
		ctx->drawImage(img.get(), 100, 10);
	}

	void TestCreateImageData(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		RefPtr<ImageData> data = ctx->createImageData(100, 100);
		for (int i = 0; i < data->length(); i += 4 )
		{
			data->data()[i + 0] = 0;
			data->data()[i + 1] = 0;
			data->data()[i + 2] = 255;
			data->data()[i + 3] = 255;
		}
		ctx->putImageData(data.get(), 100, 10);
		//this->inval(NULL);
	}

	void TestCreatePattern(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasContext2D> ctx = CanvasContext2D::create(canvas);
		RefPtr<BitmapImage> img = BitmapImage::create();
		img->src("c:/test_ba.png");
		PassRefPtr<CanvasPattern> pattern = ctx->createPattern(img.get(), "repeat");
		ctx->rect(0, 0, 800, 600);
		RefPtr<CanvasStyle> style = CanvasStyle::createFromPattern(pattern);
		ctx->setFillStyle(style);
		//////////////////////////////////////////////////////////////////////////
		ctx->setShadowBlur(10);
		ctx->setShadowOffsetX(20);
		ctx->setShadowOffsetY(20);
		ctx->setShadowColor("#00ff00");
		ctx->fill();
		//ctx->save();
		//ctx->beginPath();
		//ctx->moveTo(100, 100);
		//ctx->lineTo(200, 200);
		//ctx->stroke();
		//ctx->restore();
	}

	void TestV8()
	{
		V8::InitializeICU();
		Platform* platform = platform::CreateDefaultPlatform();
		V8::InitializePlatform(platform);
		V8::Initialize();

		// Create a new Isolate and make it the current one.
		ArrayBufferAllocator allocator;
		Isolate::CreateParams create_params;
		create_params.array_buffer_allocator = &allocator;
		Isolate* isolate = Isolate::New(create_params);
		{
			Isolate::Scope isolate_scope(isolate);

			// Create a stack-allocated handle scope.
			HandleScope handle_scope(isolate);

			// Create a new context.
			Local<Context> context = Context::New(isolate);

			// Enter the context for compiling and running the hello world script.
			Context::Scope context_scope(context);

			// Create a string containing the JavaScript source code.
			Local<String> source =
				String::NewFromUtf8(isolate, "'Hello' + ', World!'",
				NewStringType::kNormal).ToLocalChecked();

			// Compile the source code.
			Local<Script> script = Script::Compile(context, source).ToLocalChecked();

			// Run the script to get the result.
			Local<Value> result = script->Run(context).ToLocalChecked();

			// Convert the result to an UTF8 string and print it.
			String::Utf8Value utf8(result);
			printf("%s\n", *utf8);
		}

		// Dispose the isolate and tear down V8.
		isolate->Dispose();
		V8::Dispose();
		V8::ShutdownPlatform();
		delete platform;

	}

    virtual void onDrawContent(SkCanvas* canvas) {
		//TestDrawZHText(canvas);
		TestV8();
		return;
		SkPaint paint;
		paint.setAntiAlias(true);
		paint.setStyle(SkPaint::kStroke_Style);
		paint.setColor(0xff008000);
		paint.setStrokeWidth(0.5);
		paint.setShader(0);
		//SkRect r = SkRect::MakeXYWH(200, 200, 100, 100);
		SkPath path;
		path.moveTo(10, 10);
		path.lineTo(100, 50);
		path.addCircle(200, 200, 50);
		//path.addRect( 200, 200, 300, 300);
		canvas->drawPath(path, paint);
		//this->inval(NULL);
		return;
    }

private:
    int fN;
    typedef SampleView INHERITED;
};

const SkScalar CanvasTestView::ANIM_DX(SK_Scalar1 / 67);
const SkScalar CanvasTestView::ANIM_DY(SK_Scalar1 / 29);
const SkScalar CanvasTestView::ANIM_RAD(SK_Scalar1 / 19);

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new CanvasTestView; }
static SkViewRegister reg(MyFactory);
