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


class LineCapView : public SampleView
{
    SkPaint fBGPaint;
public:
	LineCapView()
	{
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "LineCapView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
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

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new LineCapView; }
static SkViewRegister reg(MyFactory);
