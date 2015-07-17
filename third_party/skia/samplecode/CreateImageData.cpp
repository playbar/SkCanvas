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
#include "ImageData.h"
#include "wtf/Uint8ClampedArray.h"

using namespace WebCore;
using namespace WTF;


class CreateImageDataView : public SampleView
{
    SkPaint fBGPaint;
public:
	CreateImageDataView() 
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
            SampleCode::TitleR(evt, "CreateImageDataView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		RefPtr<ImageData> imgData = ctx->createImageData(100, 100);
		int ilen = imgData->width() * imgData->height() * 4;
		ilen = imgData->data()->length();
		for (int i = 0; i < ilen; i++ )
		{
			imgData->data()->data()[i + 0] = 255;
			imgData->data()->data()[i + 1] = 0;
			imgData->data()->data()[i + 2] = 0;
			imgData->data()->data()[i + 3] = 255;
		}
		ctx->putImageData(imgData.get(), 10, 10);
		return;
		
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new CreateImageDataView; }
static SkViewRegister reg(MyFactory);
