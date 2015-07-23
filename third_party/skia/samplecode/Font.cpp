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
#include "TextMetrics.h"

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


	void BlurMask_path(SkCanvas* pskCanvas)
	{
		SkPaint embossPaint;
		embossPaint.setAntiAlias(true);
		embossPaint.setColor(SK_ColorRED);
		SkScalar dir[3] = { -5, 5, 5 };
		SkMaskFilter *embossMask = SkBlurMaskFilter::CreateEmboss(dir,
			0.5, 1, 2);
		embossPaint.setMaskFilter(embossMask);
		embossMask->unref();

		SkMaskFilter * blurMask[SkBlurMaskFilter::kBlurStyleCount];
		for (size_t i = 0; i < SK_ARRAY_COUNT(blurMask); i++)
		{
			//下面依次实验flags参数
			//maskFilter[i] = SkBlurMaskFilter::Create(2,SkBlurMaskFilter::BlurStyle(i));//默认flags
			//maskFilter[i] = SkBlurMaskFilter::Create(2,SkBlurMaskFilter::BlurStyle(i),
			//SkBlurMaskFilter::kIgnoreTransform_BlurFlag);//忽略矩阵变换,注意只有模板半径忽略矩阵变换
			blurMask[i] = SkBlurMaskFilter::Create(2, SkBlurMaskFilter::BlurStyle(i),
				SkBlurMaskFilter::kHighQuality_BlurFlag);
			//maskFilter[i] = SkBlurMaskFilter::Create(2,SkBlurMaskFilter::BlurStyle(i),
			//  SkBlurMaskFilter::kAll_BlurFlag);
		}
		SkPaint blurPaint[SK_ARRAY_COUNT(blurMask)];
		for (size_t i = 0; i < SK_ARRAY_COUNT(blurMask); i++)
		{
			blurPaint[i].setAntiAlias(true);
			blurPaint[i].setColor(SK_ColorRED);
			blurPaint[i].setMaskFilter(blurMask[i]);
			blurMask[i]->unref();
		}

		//DrawImage("\\USER\\Skia\\music-n.png",pskCanvas,g_rtImg,&embossPaint); //对画图片没效果

		float pts[] =
		{
			0, 0,
			10, 0,
			10, 5,
			20, -5,
			10, -15,
			10, -10,
			0, -10
		}; //将这些坐标连起来是一个箭头形状
		SkPath fPath;
		fPath.moveTo(pts[0], pts[1]);
		for (size_t i = 2; i < SK_ARRAY_COUNT(pts); i += 2)
		{
			fPath.lineTo(pts[i], pts[i + 1]);
		}
		pskCanvas->scale(5, 5);        //水平垂直都放大5倍
		pskCanvas->translate(10, 30); //移动坐标原点

		for (size_t i = 0; i < SK_ARRAY_COUNT(blurMask); i++)
		{
			pskCanvas->drawPath(fPath, blurPaint[i]);
			pskCanvas->translate(32, 0); //水平移动32像素（实际效果要经过scale）
		}
		pskCanvas->drawPath(fPath, embossPaint);
	}

	void TestAlign(SkCanvas *canvas)
	{
		SkPaint paint;
		paint.setAntiAlias(true);
		paint.setColor(0xffff0000);
		paint.setTextSize(30);
		paint.setStyle(SkPaint::kStroke_Style);
		paint.setStrokeWidth(2);
		paint.setVerticalText(true);
		paint.setUnderlineText(true);
		canvas->drawLine(150, 20, 150, 170, paint);
		paint.setTextAlign(SkPaint::kCenter_Align);
		canvas->drawText("test", 4, 150, 60, paint);

		paint.setTextAlign(SkPaint::kLeft_Align);
		canvas->drawText("test", 4, 150, 80, paint);
		paint.setTextAlign(SkPaint::kRight_Align);
		canvas->drawText("test", 4, 150, 140, paint );

	}

	void TestBaseLine(SkCanvas *canvas)
	{
		//SkPaint paint;
		//paint.setAntiAlias(true);
		//paint.setColor(0xffff0000);
		//paint.setTextSize(30);
		//paint.setStyle(SkPaint::kStroke_Style);
		//paint.setStrokeWidth(2);
		SkPaint paint;
		paint.setAntiAlias(true);
		paint.setColor(0xffff0000);
		paint.setTextSize(30);
		paint.setStyle(SkPaint::kStroke_Style);
		//paint.setStrokeWidth(1);
		//paint.setVerticalText(true);
		paint.setUnderlineText(true);

		std::string str1 = Unicode2ASCII(std::wstring(L"Hello"));
		float ilen = paint.measureText(str1.c_str(), str1.length());
		ilen += 0;
		canvas->drawLine(5, 100, 395, 100, paint);
		canvas->drawText("test", 4, 150, 60, paint);
		

		paint.setTextAlign(SkPaint::kLeft_Align);
		canvas->drawText("test", 4, 150, 80, paint);
		paint.setTextAlign(SkPaint::kRight_Align);
		canvas->drawText("test", 4, 150, 140, paint);

	}

	void DrawTest(SkCanvas *canvas)
	{
		PassOwnPtr<CanvasRenderingContext2D> ctx = CanvasRenderingContext2D::create(canvas, NULL, false);
		ctx->setFont("italic small-caps 800 40px sans-serif");
		//ctx->setFont("40px Arial");
		String str = "Hello";
		RefPtr<TextMetrics> textMetri = ctx->measureText(str);
		ctx->strokeText(str, 10, 50);
		//return;
		//ctx->strokeText("Hello world", 10, 50);
		SkPaint paint;
		paint.setAntiAlias(true);
		paint.setColor(0xffff0000);
		paint.setTextSize(30);
		paint.setStyle(SkPaint::kStroke_Style);
		paint.setStrokeWidth(2);
		paint.setVerticalText(true);
		paint.setUnderlineText(true);
		
		SkPoint p = SkPoint::Make(50, 100);
		SkPoint q = SkPoint::Make(10, 100);
		SkPoint pts[] = { p, q };
		//SkScalar t, temp, x, y;
		SkColor colors[] = {
			SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK
		};
		////红、绿、蓝、白、黑，这些宏的alpha值都是FF，即不透明
		SkShader *shader;
		shader = SkGradientShader::CreateLinear(pts, colors, NULL, SK_ARRAY_COUNT(colors), SkShader::kMirror_TileMode);		
		
		//canvas->drawText("test", 4, 100, 100, paint);
		//paint.setShader(shader);
		shader->unref();
		//paint.setTextAlign(SkPaint::kCenter_Align);
		std::string str1 = Unicode2ASCII(std::wstring(L"Hello"));
		SkPaint::FontMetrics metrix;
		paint.getFontMetrics(&metrix);
		canvas->drawPosText(str1.c_str(), str1.length(), pts, paint);
		float ilen = paint.measureText(str1.c_str(), str1.length());
		ilen += 0;
		return;
	}


	void PaintShader(SkCanvas* pskCanvas)
	{
		SkPaint paint;
		paint.setAntiAlias(true);
		//paint.setStyle(SkPaint::kStroke_Style);
		//paint.setStrokeWidth(SkScalarHalf(SkIntToScalar(3)));
		//paint.setStyle(SkPaint::kFill_Style);
		SkPoint p = SkPoint::Make(50, 50);
		SkPoint q = SkPoint::Make(100, 50);
		SkPoint pts[] = { p, q };
		SkScalar t, temp, x, y;
		SkColor colors[] = {
			SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE, SK_ColorBLACK
		};
		//红、绿、蓝、白、黑，这些宏的alpha值都是FF，即不透明
		SkShader *shader;
		shader = SkGradientShader::CreateLinear(
			pts, colors, NULL, SK_ARRAY_COUNT(colors), SkShader::kMirror_TileMode);
		//pts决定Gradient的起始点和走向，以及过渡完gClors的颜色需要的像素距离
		paint.setShader(shader);
		shader->unref();
		SkRect r = { 0, 0, SkIntToScalar(200), SkIntToScalar(100) };
		// 如果r范围小于pts，则只显示完整过渡colors需要像素的一部分，如果大于就会按mode重复
		//kMirror_TileMode就是红绿蓝白黑+白蓝绿红+绿蓝白黑+白...重复
		pskCanvas->drawRect(r, paint);

		shader = SkGradientShader::CreateLinear(
			pts, colors, NULL, SK_ARRAY_COUNT(colors), SkShader::kRepeat_TileMode);
		paint.setShader(shader);
		shader->ref();
		r.setLTRB(0, SkIntToScalar(110), SkIntToScalar(200), SkIntToScalar(210));
		pskCanvas->drawRect(r, paint);

		shader = SkGradientShader::CreateLinear(
			pts, colors, NULL, SK_ARRAY_COUNT(colors), SkShader::kClamp_TileMode);
		paint.setShader(shader);
		shader->ref();
		r.setLTRB(0, SkIntToScalar(220), SkIntToScalar(200), SkIntToScalar(320));
		pskCanvas->drawRect(r, paint);


	}

    virtual void onDrawContent(SkCanvas* canvas)
	{
		TestBaseLine(canvas);
	}

private:
    typedef SampleView INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new FontView; }
static SkViewRegister reg(MyFactory);
