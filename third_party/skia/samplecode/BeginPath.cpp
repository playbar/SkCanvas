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


class BeginPathView : public SampleView
{
    SkPaint fBGPaint;
public:
	BeginPathView()
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
            SampleCode::TitleR(evt, "BeginPath");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->beginPath();
		ctx->setLineWidth(4);
		ctx->setStrokeColor("red");
		ctx->moveTo(0, 75);
		ctx->lineTo(250, 75);
		ctx->stroke();

		ctx->beginPath();
		ctx->moveTo(50, 0);
		ctx->lineTo(150, 130);
		ctx->stroke();

		return;

    }

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new BeginPathView; }
static SkViewRegister reg(MyFactory);
