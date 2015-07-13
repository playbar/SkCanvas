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
#include "SkColorPriv.h"
#include "SkShader.h"
#include "CanvasRenderingContext2D.h"
using namespace WebCore;
using namespace WTF;


class QuadraticCurveToView : public SampleView
{
    SkPaint fBGPaint;
public:
    QuadraticCurveToView () {
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "QuadraticCurveTo");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		//SkPaint paint;
		//paint.setColor(0xFF0000ff);
		//paint.setStyle(SkPaint::kFill_Style);
		//canvas->translate(0, 0);
		//SkPath path;
		//path.moveTo(10, 10);
		//path.lineTo(300, 300);
		//path.lineTo(100, 10);
		//canvas->drawPath(path, paint);
		////canvas->drawLine(0, 0, 100, 200, paint);

		
	
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		//Color color(255, 102, 234);
		//ctx->setStrokeColor(1.0f, 0.0f, 0.0, 1.0f);
		//ctx->setStrokeColor("#00ff0f");
		ctx->beginPath();
		ctx->setLineWidth(4);
		//ctx->moveTo(10, 10);
		//ctx->lineTo(100, 100);
		//ctx->lineTo(200, 100);
		//ctx->arc(70, 18, 15, 0, 3.14 * 2, true);
		ctx->moveTo( 20, 20);
		ctx->quadraticCurveTo( 20, 100, 200, 20);
		//ctx->closePath();
		ctx->stroke();

    }

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new QuadraticCurveToView; }
static SkViewRegister reg(MyFactory);
