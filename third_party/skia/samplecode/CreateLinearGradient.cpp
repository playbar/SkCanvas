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


class CreateLinearGradient : public SampleView
{
    SkPaint fBGPaint;
public:
	CreateLinearGradient() 
	{
    }

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "CreateLinearGradient");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

	void DrawH(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		PassRefPtr<CanvasGradient> grd = ctx->createLinearGradient(0, 0, 170, 0);
		grd->addColorStop(0, "black");
		grd->addColorStop(1, "white");
		RefPtr<CanvasStyle> style = CanvasStyle::createFromGradient(grd);
		ctx->setFillStyle(style);
		ctx->fillRect(20, 20, 150, 100);
	}

	void DrawV(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		PassRefPtr<CanvasGradient> grd1 = ctx->createLinearGradient(0, 0, 0, 170);
		grd1->addColorStop(0, "black");
		grd1->addColorStop(1, "white");
		RefPtr<CanvasStyle> style1 = CanvasStyle::createFromGradient(grd1);
		ctx->setFillStyle(style1);
		ctx->fillRect(20, 20, 150, 100);
	}

	void DrawColor(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		PassRefPtr<CanvasGradient> grd1 = ctx->createLinearGradient(0, 0, 170,100 );
		grd1->addColorStop(0, "black");
		grd1->addColorStop(0.5, "red");
		grd1->addColorStop(1, "white");
		RefPtr<CanvasStyle> style1 = CanvasStyle::createFromGradient(grd1);
		ctx->setFillStyle(style1);
		ctx->fillRect(20, 20, 150, 100);
	}

    virtual void onDrawContent(SkCanvas* canvas)
	{
		DrawColor(canvas);
    }

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new CreateLinearGradient; }
static SkViewRegister reg(MyFactory);
