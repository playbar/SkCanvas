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
#include "CanvasGradient.h"
#include "CanvasStyle.h"

using namespace WebCore;
using namespace WTF;


class AddColorStop : public SampleView
{
    SkPaint fBGPaint;
public:
	AddColorStop() 
	{
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "AddColorStop ");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		PassRefPtr<CanvasGradient> grd = ctx->createLinearGradient( 0, 0, 170, 0 );
		grd->addColorStop(0, "black");
		grd->addColorStop(0.3, "magenta");
		grd->addColorStop(0.5, "blue");
		grd->addColorStop(0.6, "green");
		grd->addColorStop(0.8, "yellow");
		grd->addColorStop(1, "red");
		RefPtr<CanvasStyle> style = CanvasStyle::createFromGradient(grd);
		ctx->setFillStyle(style);
		ctx->fillRect(10, 10, 150, 100);
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new AddColorStop; }
static SkViewRegister reg(MyFactory);
