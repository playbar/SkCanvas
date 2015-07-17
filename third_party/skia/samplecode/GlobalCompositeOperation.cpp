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


class GlobalCompositeOperationView : public SampleView
{
    SkPaint fBGPaint;
public:
	GlobalCompositeOperationView() 
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
            SampleCode::TitleR(evt, "GlobalCompositeOperationView  ");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		//ctx->setFillColor("red");
		//ctx->fillRect(20, 20, 75, 50);
		//ctx->setGlobalCompositeOperation("source-over");
		//ctx->setFillColor("blue");
		//ctx->fillRect(50, 50, 75, 50);

		//ctx->setFillColor("red");
		//ctx->fillRect(150, 20, 75, 50);
		//ctx->setGlobalCompositeOperation("lighter");
		//ctx->setFillColor("blue");
		//ctx->fillRect(180, 50, 75, 50);

		//canvas->drawRect( )

	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new GlobalCompositeOperationView; }
static SkViewRegister reg(MyFactory);
