/*
 * Copyright 2011 Skia
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SampleApp_DEFINED
#define SampleApp_DEFINED

#include "SkOSMenu.h"
#include "SkPath.h"
#include "SkScalar.h"
#include "SkTDArray.h"
#include "SkTouchGesture.h"
#include "SkWindow.h"

class GrContext;
class GrRenderTarget;

class SkCanvas;
class SkData;
class SkEvent;
class SkPicture;
class SkTypeface;
class SkViewFactory;

class SampleWindow : public SkOSWindow 
{
    SkTDArray<const SkViewFactory*> fSamples;
public:
	class DeviceManager : public SkRefCnt
	{
	public:
		DeviceManager();
		virtual ~DeviceManager();
		virtual void setUpBackend(SampleWindow* win, int msaaSampleCount);
		virtual void tearDownBackend(SampleWindow *win);
		virtual SkCanvas* createCanvas();
		virtual void publishCanvas(SkCanvas* canvas, SampleWindow* win);
		virtual void windowSizeChanged(SampleWindow* win);
		virtual GrContext* getGrContext();
		virtual GrRenderTarget* getGrRenderTarget();

	private:
		GrContext*              fCurContext;
		GrRenderTarget*         fCurRenderTarget;
		int fMSAASampleCount;

		typedef SkRefCnt INHERITED;
	};


    SampleWindow(void* hwnd, int argc, char** argv, DeviceManager*);
    virtual ~SampleWindow();

	virtual SkCanvas* createCanvas() SK_OVERRIDE;

    virtual void draw(SkCanvas* canvas);

    void setDeviceType();
    void toggleRendering();
    void toggleSlideshow();
    void toggleFPS();
    void showOverview();

    GrContext* getGrContext() const { return fDevManager->getGrContext(); }

    void setZoomCenter(float x, float y);
    void changeZoomLevel(float delta);
    bool nextSample();
    bool previousSample();
    bool goToSample(int i);
    SkString getSampleTitle(int i);
    int  sampleCount();
    bool handleTouch(int ownerId, float x, float y,
            SkView::Click::State state);
    void saveToPdf();
    SkData* getPDFData() { return fPDFData; }
    void postInvalDelay();
protected:
    virtual void onDraw(SkCanvas* canvas) SK_OVERRIDE;
    virtual bool onHandleKey(SkKey key) SK_OVERRIDE;
    virtual bool onHandleChar(SkUnichar) SK_OVERRIDE;
    virtual void onSizeChange() SK_OVERRIDE;

    virtual SkCanvas* beforeChildren(SkCanvas*) SK_OVERRIDE;
    virtual void afterChildren(SkCanvas*) SK_OVERRIDE;
    virtual void beforeChild(SkView* child, SkCanvas* canvas) SK_OVERRIDE;
    virtual void afterChild(SkView* child, SkCanvas* canvas) SK_OVERRIDE;

    virtual bool onEvent(const SkEvent& evt) SK_OVERRIDE;
    virtual bool onQuery(SkEvent* evt) SK_OVERRIDE;

    virtual bool onDispatchClick(int x, int y, Click::State, void* owner,
                                 unsigned modi) SK_OVERRIDE;
    virtual bool onClick(Click* click) SK_OVERRIDE;
	virtual Click* onFindClickHandler(float x, float y,
                                      unsigned modi) SK_OVERRIDE;

    void registerPictFileSamples(char** argv, int argc);
    void registerPictFileSample(char** argv, int argc);

private:
    int fCurrIndex;
    SkPicture* fPicture;
    SkPath fClipPath;

    SkTouchGesture fGesture;
	float fZoomLevel;
	float fZoomScale;

    DeviceManager* fDevManager;

    bool fSaveToPdf;
    SkCanvas* fPdfCanvas;
    SkData* fPDFData;

    bool fUseClip;
    bool fNClip;
    bool fAnimating;
    bool fRotate;
	float fRotateAnimTime;
    bool fPerspAnim;
	float fPerspAnimTime;
    bool fRequestGrabImage;
    bool fMeasureFPS;
    SkMSec fMeasureFPS_Time;
    SkMSec fMeasureFPS_StartTime;
    bool fMagnify;
    int fTilingMode;


    SkOSMenu::TriState fPipeState;  // Mixed uses a tiled pipe
                                    // On uses a normal pipe
                                    // Off uses no pipe
    int  fUsePipeMenuItemID;

    // The following are for the 'fatbits' drawing
    // Latest position of the mouse.
    int fMouseX, fMouseY;
    int fFatBitsScale;
    // Used by the text showing position and color values.
    SkTypeface* fTypeface;
    bool fShowZoomer;

    SkOSMenu::TriState fLCDState;
    SkOSMenu::TriState fAAState;
    SkOSMenu::TriState fSubpixelState;
    int fHintingState;
    int fFilterLevelIndex;
    unsigned   fFlipAxis;

    int fMSAASampleCount;

    int fScrollTestX, fScrollTestY;
	float fZoomCenterX, fZoomCenterY;

    SkOSMenu* fAppMenu; // We pass ownership to SkWindow, when we call addMenu
    SkOSMenu* fSlideMenu; // We pass ownership to SkWindow, when we call addMenu

    int fTransitionNext;
    int fTransitionPrev;

    void loadView(SkView*);
    void updateTitle();

    bool zoomIn();
    bool zoomOut();
    void updatePointer(int x, int y);
    void magnify(SkCanvas* canvas);
    void showZoomer(SkCanvas* canvas);
    void updateMatrix();
    void postAnimatingEvent();
    void installDrawFilter(SkCanvas*);
    int findByTitle(const char*);
    void listTitles();
    SkSize tileSize() const;
};

#endif
