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

using namespace WebCore;
using namespace WTF;

class TextBaselineView : public SampleView
{
    SkPaint fBGPaint;
public:
	TextBaselineView()
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
            SampleCode::TitleR(evt, "TextBaselineView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->setStrokeColor("blue");
		ctx->moveTo(5, 100);
		ctx->lineTo(395, 100);
		ctx->stroke();
		
		ctx->setFont("40px Arial");
		ctx->setTextBaseline("top");
		ctx->fillText("Top", 5, 100);
		ctx->setTextBaseline("bottom");
		ctx->fillText("Bottom", 50, 100);
		ctx->setTextBaseline("middle");
		ctx->fillText("Middle", 120, 100);
		ctx->setTextBaseline("alphabetic");
		ctx->fillText("Alphabetic", 190, 100);
		ctx->setTextBaseline("hanging");
		ctx->fillText("Hanging", 290, 100);
		
		return;
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new TextBaselineView; }
static SkViewRegister reg(MyFactory);
