#ifndef __CANVASCONTEXTTEST_H__
#define __CANVASCONTEXTTEST_H__

//#include "blink/config.h"
//#include "core/html/canvas/CanvasRenderingContext2D.h"

class CanvasContextTest
{
public:
	CanvasContextTest(SkCanvas *canvas);
	~CanvasContextTest();

private:
	OwnPtr<WebCore::CanvasRenderingContext2D> mpCanvas;

};

#endif

