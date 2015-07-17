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
#include "SkStream.h"
#include "SkImageDecoder.h"
#include "CanvasRenderingContext2D.h"
#include "ImageData.h"
#include "platform/graphics/BitmapImage.h"
#include "wtf/Uint8ClampedArray.h"

using namespace WebCore;
using namespace WTF;


class DrawImageView : public SampleView
{
    SkPaint fBGPaint;
public:
	DrawImageView() 
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
            SampleCode::TitleR(evt, "DrawImageView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		
		RefPtr<BitmapImage> img = BitmapImage::create();
		img->src("c:/test00_ba.png");
		ctx->drawImage(img.get(), 10, 10);
		//////////////////////////////////////////////////////////////////////////
		//SkFILEStream stream("c:/test00_ba.png");
		//SkPaint paint;
		//paint.setColor(0xff00ff00);
		//SkBitmap bitmap;
		//SkImageDecoder *coder = SkImageDecoder::Factory(&stream);
		//coder->decode(&stream, &bitmap, SkBitmap::kARGB_8888_Config, SkImageDecoder::kDecodePixels_Mode);
		//canvas->drawBitmap(bitmap, 10, 10, &paint);

		return;
		
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new DrawImageView; }
static SkViewRegister reg(MyFactory);
