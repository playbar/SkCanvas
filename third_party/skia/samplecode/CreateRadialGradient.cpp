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


class CreateRadialGradient : public SampleView
{
    SkPaint fBGPaint;
public:
	CreateRadialGradient() 
	{
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "CreateRadialGradient");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		PassRefPtr<CanvasGradient> grd = ctx->createRadialGradient( 75, 50, 5, 90, 60, 100 );
		grd->addColorStop(0, "red");
		grd->addColorStop(1, "white");
		RefPtr<CanvasStyle> style = CanvasStyle::createFromGradient(grd);
		ctx->setFillStyle(style);
		ctx->fillRect(10, 10, 150, 100);
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new CreateRadialGradient; }
static SkViewRegister reg(MyFactory);
