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

class TextAlignView : public SampleView
{
    SkPaint fBGPaint;
public:
	TextAlignView() 
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
            SampleCode::TitleR(evt, "TextAlignView ");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->setStrokeColor("blue");
		ctx->moveTo(150, 20);
		ctx->lineTo(150, 170);
		ctx->stroke();
		
		ctx->setFont("40px Arial");
		ctx->setTextAlign("start");
		ctx->fillText("textAlign=start", 150, 60);

		ctx->setTextAlign("end");
		ctx->fillText("textAlign=end", 150, 80);
		ctx->setTextAlign("left");
		ctx->fillText("textAlign=left", 150, 100);
		ctx->setTextAlign("center");
		ctx->fillText("textAlign=center", 150, 120);
		ctx->setTextAlign("right");
		ctx->fillText("textAlign=right", 150, 140);
		return;
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new TextAlignView; }
static SkViewRegister reg(MyFactory);
