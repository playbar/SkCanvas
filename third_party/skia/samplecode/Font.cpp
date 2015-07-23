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
#include "SkBlurMaskFilter.h"
#include "SkGradientShader.h"

using namespace WebCore;
using namespace WTF;

class FontView : public SampleView
{
    SkPaint fBGPaint;
public:
	FontView() 
	{
		int i = 0;
		i++;
    }

	inline std::string Unicode2ASCII(const std::wstring &strUnicode, UINT CodePage = CP_UTF8)
	{
		int nByte = WideCharToMultiByte(CodePage, 0, strUnicode.c_str(), -1, 0, 0, 0, 0);
		if (nByte <= 0)
		{
			return "";
		}
		std::string strUtf8;
		strUtf8.resize(nByte + 1, '\0');
		WideCharToMultiByte(CodePage, 0, strUnicode.c_str(), -1, &strUtf8[0], nByte, 0, 0);
		return std::string(strUtf8.c_str());
	}

protected:
    // overrides from SkEventSink
    virtual bool onQuery(SkEvent* evt)
	{
        if (SampleCode::TitleQ(*evt)) 
		{
            SampleCode::TitleR(evt, "FontView");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    virtual void onDrawContent(SkCanvas* canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		//ctx->setFont("italic small-caps bold 40px sans-serif");
		ctx->setFont("40px Arial");
		std::string str1 = Unicode2ASCII(std::wstring(L"测试test"));
		String str = "HelloWorld";
		ctx->strokeText(str, 10, 50);
		//return;
		//ctx->strokeText("Hello world", 10, 50);
		SkPaint paint;
		paint.setAntiAlias(true);
		paint.setColor(0xffff0000);
		paint.setTextSize(80);
		paint.setStyle(SkPaint::kStroke_Style);
		//SkPoint p = SkPoint::Make(50, 50);
		//SkPoint q = SkPoint::Make(100, 50);
		//SkPoint pts[] = { p, q };
		//SkScalar t, temp, x, y;
		//SkColor colors[] = {
		//	SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK
		//};
		////红、绿、蓝、白、黑，这些宏的alpha值都是FF，即不透明
		//SkShader *shader;
		//shader = SkGradientShader::CreateLinear(
		//	pts, colors, NULL, SK_ARRAY_COUNT(colors), SkShader::kMirror_TileMode);		canvas->drawText("test", 4, 100, 100, paint);
		//paint.setShader(shader);
		//shader->unref();
		//paint.setTextAlign(SkPaint::kCenter_Align);
		canvas->drawText(str1.c_str(), str1.length(), 100, 200, paint);
		return;
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new FontView; }
static SkViewRegister reg(MyFactory);
