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


class GlobalAlphaView : public SampleView
{
    SkPaint fBGPaint;
public:
	GlobalAlphaView() 
	{
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "GlobalAlphaView ");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->setFillColor("red");
		ctx->fillRect(20, 20, 75, 50);

		ctx->setGlobalAlpha(0.2);
		ctx->setFillColor("blue");
		ctx->fillRect(50, 50, 75, 50);
		ctx->setFillColor("green");
		ctx->fillRect(80, 80, 75, 50);
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new GlobalAlphaView; }
static SkViewRegister reg(MyFactory);
