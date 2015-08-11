
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

using namespace WebCore;
using namespace WTF;

// ensure that we don't accidentally screw up the bounds when the oval is
// fractional, and the impl computes the center and radii, and uses them to
// reconstruct the edges of the circle.
// see bug# 1504910
static void test_circlebounds(SkCanvas*) {
    SkRect r = { 1.39999998f, 1, 21.3999996f, 21 };
    SkPath p;
    p.addOval(r);
    SkASSERT(r == p.getBounds());
}

class CanvasTestView : public SampleView {
public:
    static const SkScalar ANIM_DX;
    static const SkScalar ANIM_DY;
    static const SkScalar ANIM_RAD;
    SkScalar fDX, fDY, fRAD;

    CanvasTestView() {
        fDX = fDY = fRAD = 0;
        fN = 3;
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
		ctx->rect(20, 20, 150, 100);
		//if ( ctx->isPoint)
		//{
		//}
		
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
    virtual void onDrawContent(SkCanvas* canvas) {
		TestArcTo(canvas);
		return;
		SkPaint paint;
		//paint.setAntiAlias(true);
		paint.setStyle(SkPaint::kStroke_Style);
		paint.setColor(0xff008000);
		paint.setStrokeWidth(8);
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
