
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gl/SkNativeGLContext.h"
#include "SkWGL.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

SkNativeGLContext::AutoContextRestore::AutoContextRestore() {
    fOldHGLRC = wglGetCurrentContext();
    fOldHDC = wglGetCurrentDC();
}

SkNativeGLContext::AutoContextRestore::~AutoContextRestore() {
    wglMakeCurrent(fOldHDC, fOldHGLRC);
}

///////////////////////////////////////////////////////////////////////////////

ATOM SkNativeGLContext::gWC = 0;

SkNativeGLContext::SkNativeGLContext()
    : fWindow(NULL)
    , fDeviceContext(NULL)
    , fGlRenderContext(0) {
}

SkNativeGLContext::~SkNativeGLContext() {
    this->destroyGLContext();
}

void SkNativeGLContext::destroyGLContext() {
    if (fGlRenderContext) {
        wglDeleteContext(fGlRenderContext);
    }
    if (fWindow && fDeviceContext) {
        ReleaseDC(fWindow, fDeviceContext);
    }
    if (fWindow) {
        DestroyWindow(fWindow);
    }
}

void SkNativeGLContext::createGLContext() 
{
    HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(NULL);

    if (!gWC) {
        WNDCLASS wc;
        wc.cbClsExtra = 0;
        wc.cbWndExtra = 0;
        wc.hbrBackground = NULL;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wc.hInstance = hInstance;
        wc.lpfnWndProc = (WNDPROC) DefWindowProc;
        wc.lpszClassName = TEXT("Griffin");
        wc.lpszMenuName = NULL;
        wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

        gWC = RegisterClass(&wc);
        if (!gWC)
		{
            SkDebugf("Could not register window class.\n");
            return;
        }
    }

    if (!(fWindow = CreateWindow(TEXT("Griffin"),
                                 TEXT("The Invisible Man"),
                                 WS_OVERLAPPEDWINDOW,
                                 0, 0, 1, 1,
                                 NULL, NULL,
                                 hInstance, NULL))) {
        SkDebugf("Could not create window.\n");
        return;
    }

    if (!(fDeviceContext = GetDC(fWindow))) {
        SkDebugf("Could not get device context.\n");
        this->destroyGLContext();
        return;
    }

    if (!(fGlRenderContext = SkCreateWGLContext(fDeviceContext, 0, true))) {
        SkDebugf("Could not create rendering context.\n");
        this->destroyGLContext();
        return;
    }

    if (!(wglMakeCurrent(fDeviceContext, fGlRenderContext))) {
        SkDebugf("Could not set the context.\n");
        this->destroyGLContext();
        return;
    }
	return;
 
}

void SkNativeGLContext::makeCurrent() const {
    if (!wglMakeCurrent(fDeviceContext, fGlRenderContext)) {
        SkDebugf("Could not create rendering context.\n");
    }
}

void SkNativeGLContext::swapBuffers() const {
    if (!SwapBuffers(fDeviceContext)) {
        SkDebugf("Could not complete SwapBuffers.\n");
    }
}
