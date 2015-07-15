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


class SetTransformView : public SampleView
{
    SkPaint fBGPaint;
public:
	SetTransformView() 
	{
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "SetTransformView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
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

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new SetTransformView; }
static SkViewRegister reg(MyFactory);
