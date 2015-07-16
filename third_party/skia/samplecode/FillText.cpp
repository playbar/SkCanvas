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
#include "SkBlurMaskFilter.h"
#include "SkGradientShader.h"
#include "CanvasGradient.h"
#include "CanvasStyle.h"

using namespace WebCore;
using namespace WTF;

class FillTextView : public SampleView
{
    SkPaint fBGPaint;
public:
	FillTextView() 
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
            SampleCode::TitleR(evt, "FillTextView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->setFont("40px Arial");
		ctx->fillText("Hello world", 10, 50);

		PassRefPtr<CanvasGradient> grd1 = ctx->createLinearGradient(0, 0, 300, 0);
		grd1->addColorStop(0, "magenta");
		grd1->addColorStop(0.5, "blue");
		grd1->addColorStop(1, "red");
		RefPtr<CanvasStyle> style1 = CanvasStyle::createFromGradient(grd1);
		ctx->setFillStyle(style1);

		ctx->fillText("w3school.com.cn", 10, 90);

		return;
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new FillTextView; }
static SkViewRegister reg(MyFactory);
