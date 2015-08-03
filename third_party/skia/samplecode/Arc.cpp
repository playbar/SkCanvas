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


class ArcView : public SampleView
{
    SkPaint fBGPaint;
public:
	ArcView() 
	{
		int i = 0;
		i++;
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "ArcView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

	void TestArc(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->beginPath();
		ctx->setLineWidth(5);
		ctx->arc(100, 75, 50, 0, 2 * M_PI, false);
		ctx->stroke();
	}

	void TestLine(SkCanvas *canvas)
	{
		SkPaint paint;
		paint.setColor(0xffff0000);
		paint.setStrokeWidth(10);
		canvas->drawLine(0, 0, 100, 100, paint);
		//canvas->drawColor(0xff00ff00);
		

	}

    virtual void onDrawContent(SkCanvas* canvas)
	{
		TestLine(canvas);
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new ArcView; }
static SkViewRegister reg(MyFactory);
