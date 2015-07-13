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


class RectView : public SampleView
{
    SkPaint fBGPaint;
public:
	RectView() 
	{
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "Rect");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->beginPath();
		ctx->setLineWidth(4);
		//ctx->moveTo(10, 10);
		//ctx->lineTo(100, 100);
		//ctx->lineTo(200, 100);
		//ctx->arc(70, 18, 15, 0, 3.14 * 2, true);
		//ctx->closePath();
		ctx->rect(20, 20, 150, 100);
		ctx->stroke();

    }

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new RectView; }
static SkViewRegister reg(MyFactory);
