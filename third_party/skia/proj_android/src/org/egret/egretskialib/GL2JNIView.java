/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.egret.egretskialib;

/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;

import android.content.Context;
import android.content.res.Configuration;
import android.graphics.Canvas;
import android.graphics.PixelFormat;
import android.opengl.GLSurfaceView;
import android.os.Handler;
import android.os.Message;
import android.view.KeyEvent;
import android.view.MotionEvent;
import android.view.inputmethod.InputMethodManager;

/**
 * A simple GLSurfaceView sub-class that demonstrate how to perform OpenGL ES
 * 2.0 rendering into a GL Surface. Note the following important details:
 * 
 * - The class must use a custom context factory to enable 2.0 rendering. See
 * ContextFactory class definition below.
 * 
 * - The class must use a custom EGLConfigChooser to be able to select an
 * EGLConfig that supports 2.0. This is done by providing a config specification
 * to eglChooseConfig() that has the attribute EGL10.ELG_RENDERABLE_TYPE
 * containing the EGL_OPENGL_ES2_BIT flag set. See ConfigChooser class
 * definition below.
 * 
 * - The class must select the surface's format, then choose an EGLConfig that
 * matches it exactly (with regards to red/green/blue/alpha channels bit
 * depths). Failure to do so would result in an EGL_BAD_MATCH error.
 */

public class GL2JNIView extends GLSurfaceView {
	private static String TAG = "GL2JNIView";
	private static final boolean DEBUG = false;

	public static GL2JNIView currentGl2jniview;

	private MyRenderer myrenderer;

	boolean isSettingRendererSize = false;


	public GL2JNIView(Context context) {
		super(context);
		EgretContext.logInfo(TAG, "new GL2JNIView() ");
		init(false, 16, 8);
	}

	public static void releaseGL2JNIView() {
		if (currentGl2jniview == null)
			return;
		currentGl2jniview.myrenderer = null;
		currentGl2jniview = null;
	}


	@Override
	protected void finalize() throws Throwable {
		EgretContext.logInfo("GL2JNIView", " GL2JNIView finalize");
		//_egt_edittext = null;
		myrenderer = null;

		super.finalize();

	}

	public GL2JNIView(Context context, boolean translucent, int depth,
			int stencil) {
		super(context);
		// GL2JNIView.context = context;
		init(translucent, depth, stencil);

	}

	private int currentSurfaceWidth;
	private int currentSurfaceHeight;
	private boolean isSettingSurfaceSize;

	public void onConfigurationChanged(Configuration newConfig) {

		super.onConfigurationChanged(newConfig);

		if (isSettingSurfaceSize && currentSurfaceWidth > 0
				&& currentSurfaceHeight > 0) {
			getLayoutParams().width = currentSurfaceWidth;
			getLayoutParams().height = currentSurfaceHeight;
			this.setLayoutParams(this.getLayoutParams());
			// this.setLayoutDirection(layoutDirection);
		}

	}

	@Override
	protected void onSizeChanged(final int pNewSurfaceWidth,
			final int pNewSurfaceHeight, final int pOldSurfaceWidth,
			final int pOldSurfaceHeight) {

		if (this.myrenderer == null){
			return;
		}
		// EgretContext.logInfo("GL2JNIView",
		// "GL2JNIView::onSizeChanged ("+pNewSurfaceWidth+","+pNewSurfaceHeight+")")
		// ;
		if (!this.isInEditMode() && !isSettingSurfaceSize) {
			isSettingSurfaceSize = true;
			// layoutDirection = this.getLayoutDirection();
			currentSurfaceWidth = pNewSurfaceWidth;
			currentSurfaceHeight = pNewSurfaceHeight;
			
			this.myrenderer.setScreenWidthAndHeight(pNewSurfaceWidth,
					pNewSurfaceHeight);
		} else {
			getLayoutParams().width = currentSurfaceWidth;
			getLayoutParams().height = currentSurfaceHeight;
		}

	}

	@Override
	public void onPause() {
		EgretContext.logDebug(TAG, "onPause");
		// super.onPause();
		if (myrenderer != null) {
			this.queueEvent(new Runnable() {
				@Override
				public void run() {
					GL2JNIView.this.myrenderer.handleOnPause();
				}
			});
		}

	}

	@Override
	public void onResume() {
		EgretContext.logDebug(TAG, "onResume");
		super.onResume();

		this.queueEvent(new Runnable() {
			@Override
			public void run() {
				GL2JNIView.this.myrenderer.handleOnResume();
			}
		});

	}

	public void reloadGame() {
		if (myrenderer != null) {
			this.queueEvent(new Runnable() {
				public void run() {
					myrenderer.reloadGame();
				}
			});
		}
	}

	public void notifyStopGame() {
		EgretContext.logInfo(TAG, "GL2JNIView notifyStopGame");
		if (myrenderer != null) {
			myrenderer.notifyStopGame();
		}
	}

	/*
	 * @Override public boolean onKeyDown(final int pKeyCode, final KeyEvent
	 * pKeyEvent) { EgretContext.logInfo("GL2JNIView","GL2JNIView onKeyDown");
	 * switch (pKeyCode) { case KeyEvent.KEYCODE_BACK:
	 * 
	 * _egretRuntime.stopGame();
	 * 
	 * //return true; break; default: return super.onKeyDown(pKeyCode,
	 * pKeyEvent); }
	 * 
	 * return super.onKeyDown(pKeyCode, pKeyEvent); }
	 */

	public boolean postReturnKeyOrMenuKeyDown(final int pKeyCode) {
		switch (pKeyCode) {
		case KeyEvent.KEYCODE_BACK:
		case KeyEvent.KEYCODE_MENU:
			this.queueEvent(new Runnable() {
				@Override
				public void run() {
					GL2JNIView.this.myrenderer
							.handleReturnOrMenuKeyDown(pKeyCode == KeyEvent.KEYCODE_BACK ? 0
									: 1);
				}
			});
			return true;
		default:
			return false;
		}
	}

//	@Override
//	public boolean onTouchEvent(final MotionEvent pMotionEvent) {
//		
//		TouchHandler.handleMotionEvent(myrenderer, pMotionEvent);
//		return true;
//	}

	private final static int HANDLER_OPEN_IME_KEYBOARD = 2;
	private final static int HANDLER_CLOSE_IME_KEYBOARD = 3;

	private final static int HANDLER_NOTIFY_CLOSE_IME_KEYBOARD = 5;

	public float[] pointToScreen(float x, float y) {
		if (myrenderer != null) {
			return myrenderer.pointToScreen(x, y);
		}
		return new float[] { 0, 0 };
	}

	private int _orientasion = 0;// NON

	private boolean __isLandscape() {
		if (_orientasion == 0)
			_orientasion = GL2JNIView.currentGl2jniview.getResources()
					.getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE ? 2
					: 1;
		return _orientasion == 2;

	}

	public static boolean isLandscape() {
		if (null != GL2JNIView.currentGl2jniview)
			return GL2JNIView.currentGl2jniview.__isLandscape();
		return false;
	}


//	protected static void showDialog(final String title, final String message) {
//		EgretNativeUI.showDialog(title, message);
//	}

	private void init(boolean translucent, int depth, int stencil) {
		EgretContext.logDebug(TAG, "init(" + translucent + "," + depth + ","
				+ stencil + ");");
		
		this.setEGLContextClientVersion(2);
		
		this.setFocusableInTouchMode(true);

		GL2JNIView.currentGl2jniview = this;

		/*
		 * By default, GLSurfaceView() creates a RGB_565 opaque surface. If we
		 * want a translucent one, we should change the surface's format here,
		 * using PixelFormat.TRANSLUCENT for GL Surfaces is interpreted as any
		 * 32-bit surface with alpha by SurfaceFlinger.
		 */
		if (translucent) {
			this.getHolder().setFormat(PixelFormat.TRANSLUCENT);
		}

		/*
		 * Setup the context factory for 2.0 rendering. See ContextFactory class
		 * definition below
		 */
		setEGLContextFactory(new ContextFactory());

		/*
		 * We need to choose an EGLConfig that matches the format of our surface
		 * exactly. This is going to be done in our custom config chooser. See
		 * ConfigChooser class definition below.
		 */
		setEGLConfigChooser(translucent ? new ConfigChooser(8, 8, 8, 8, depth,
				stencil) : new ConfigChooser(5, 6, 5, 0, depth, stencil));

		this.setDebugFlags(DEBUG_CHECK_GL_ERROR);
		/* Set the renderer responsible for frame rendering */
		myrenderer = new MyRenderer();
		setRenderer(myrenderer);
		this.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
		// renderCallThread = new Thread(this);
		// renderCallThread.start();

	}

	private void _setFrameTime(long frameTime) {
		if (this.myrenderer != null) {
			this.myrenderer.setFrameTime(frameTime);
		}
	}

	public static void setFrameRate(int frameRate) {
		if (GL2JNIView.currentGl2jniview != null) {
			GL2JNIView.currentGl2jniview._setFrameTime(1000 / frameRate);
			EgretContext.logInfo(TAG, "setFrameRate to " + frameRate);
		}
	}

	private static class ContextFactory implements
			GLSurfaceView.EGLContextFactory {
		private static int EGL_CONTEXT_CLIENT_VERSION = 0x3098;

		public EGLContext createContext(EGL10 egl, EGLDisplay display,
				EGLConfig eglConfig) {
			EgretContext.logWarn(TAG, "creating OpenGL ES 2.0 context");
			checkEglError("Before eglCreateContext", egl);
			int[] attrib_list = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL10.EGL_NONE };
			EGLContext context = egl.eglCreateContext(display, eglConfig,
					EGL10.EGL_NO_CONTEXT, attrib_list);
			checkEglError("After eglCreateContext", egl);

			return context;
		}

		public void destroyContext(EGL10 egl, EGLDisplay display,
				EGLContext context) {
			egl.eglDestroyContext(display, context);
		}
	}

	private static void checkEglError(String prompt, EGL10 egl) {
		int error;
		while ((error = egl.eglGetError()) != EGL10.EGL_SUCCESS) {
			EgretContext.logError(TAG,
					String.format("%s: EGL error: 0x%x", prompt, error));
		}
	}

	private static class ConfigChooser implements
			GLSurfaceView.EGLConfigChooser {

		public ConfigChooser(int r, int g, int b, int a, int depth, int stencil) {
			mRedSize = r;
			mGreenSize = g;
			mBlueSize = b;
			mAlphaSize = a;
			mDepthSize = depth;
			mStencilSize = stencil;
		}

		/*
		 * This EGL config specification is used to specify 2.0 rendering. We
		 * use a minimum size of 4 bits for red/green/blue, but will perform
		 * actual matching in chooseConfig() below.
		 */
		private static int EGL_OPENGL_ES2_BIT = 4;
		private static int[] s_configAttribs2 = { EGL10.EGL_RED_SIZE, 4,
				EGL10.EGL_GREEN_SIZE, 4, EGL10.EGL_BLUE_SIZE, 4,
				EGL10.EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT, EGL10.EGL_NONE };

		public EGLConfig chooseConfig(EGL10 egl, EGLDisplay display) {

			/*
			 * Get the number of minimally matching EGL configurations
			 */
			int[] num_config = new int[1];
			egl.eglChooseConfig(display, s_configAttribs2, null, 0, num_config);

			int numConfigs = num_config[0];

			if (numConfigs <= 0) {
				throw new IllegalArgumentException(
						"No configs match configSpec");
			}

			/*
			 * Allocate then read the array of minimally matching EGL configs
			 */
			EGLConfig[] configs = new EGLConfig[numConfigs];
			egl.eglChooseConfig(display, s_configAttribs2, configs, numConfigs,
					num_config);

			if (DEBUG) {
				printConfigs(egl, display, configs);
			}
			/*
			 * Now return the "best" one
			 */
			return chooseConfig(egl, display, configs);
		}

		public EGLConfig chooseConfig(EGL10 egl, EGLDisplay display,
				EGLConfig[] configs) {
			for (EGLConfig config : configs) {
				int d = findConfigAttrib(egl, display, config,
						EGL10.EGL_DEPTH_SIZE, 0);
				int s = findConfigAttrib(egl, display, config,
						EGL10.EGL_STENCIL_SIZE, 0);

				// We need at least mDepthSize and mStencilSize bits
				if (d < mDepthSize || s < mStencilSize)
					continue;

				// We want an *exact* match for red/green/blue/alpha
				int r = findConfigAttrib(egl, display, config,
						EGL10.EGL_RED_SIZE, 0);
				int g = findConfigAttrib(egl, display, config,
						EGL10.EGL_GREEN_SIZE, 0);
				int b = findConfigAttrib(egl, display, config,
						EGL10.EGL_BLUE_SIZE, 0);
				int a = findConfigAttrib(egl, display, config,
						EGL10.EGL_ALPHA_SIZE, 0);

				if (r == mRedSize && g == mGreenSize && b == mBlueSize
						&& a == mAlphaSize) {
					EgretContext.logWarn(TAG, "had chooseConfig : ");
					printConfig(egl, display, config);
					return config;
				}
			}
			return null;
		}

		private int findConfigAttrib(EGL10 egl, EGLDisplay display,
				EGLConfig config, int attribute, int defaultValue) {

			if (egl.eglGetConfigAttrib(display, config, attribute, mValue)) {
				return mValue[0];
			}
			return defaultValue;
		}

		private void printConfigs(EGL10 egl, EGLDisplay display,
				EGLConfig[] configs) {
			int numConfigs = configs.length;
			EgretContext.logWarn(TAG,
					String.format("%d configurations", numConfigs));
			for (int i = 0; i < numConfigs; i++) {
				EgretContext.logWarn(TAG,
						String.format("Configuration %d:\n", i));
				printConfig(egl, display, configs[i]);
			}

		}

		private void printConfig(EGL10 egl, EGLDisplay display, EGLConfig config) {
			int[] attributes = { EGL10.EGL_BUFFER_SIZE, EGL10.EGL_ALPHA_SIZE,
					EGL10.EGL_BLUE_SIZE,
					EGL10.EGL_GREEN_SIZE,
					EGL10.EGL_RED_SIZE,
					EGL10.EGL_DEPTH_SIZE,
					EGL10.EGL_STENCIL_SIZE,
					EGL10.EGL_CONFIG_CAVEAT,
					EGL10.EGL_CONFIG_ID,
					EGL10.EGL_LEVEL,
					EGL10.EGL_MAX_PBUFFER_HEIGHT,
					EGL10.EGL_MAX_PBUFFER_PIXELS,
					EGL10.EGL_MAX_PBUFFER_WIDTH,
					EGL10.EGL_NATIVE_RENDERABLE,
					EGL10.EGL_NATIVE_VISUAL_ID,
					EGL10.EGL_NATIVE_VISUAL_TYPE,
					0x3030, // EGL10.EGL_PRESERVED_RESOURCES,
					EGL10.EGL_SAMPLES,
					EGL10.EGL_SAMPLE_BUFFERS,
					EGL10.EGL_SURFACE_TYPE,
					EGL10.EGL_TRANSPARENT_TYPE,
					EGL10.EGL_TRANSPARENT_RED_VALUE,
					EGL10.EGL_TRANSPARENT_GREEN_VALUE,
					EGL10.EGL_TRANSPARENT_BLUE_VALUE,
					0x3039, // EGL10.EGL_BIND_TO_TEXTURE_RGB,
					0x303A, // EGL10.EGL_BIND_TO_TEXTURE_RGBA,
					0x303B, // EGL10.EGL_MIN_SWAP_INTERVAL,
					0x303C, // EGL10.EGL_MAX_SWAP_INTERVAL,
					EGL10.EGL_LUMINANCE_SIZE, EGL10.EGL_ALPHA_MASK_SIZE,
					EGL10.EGL_COLOR_BUFFER_TYPE, EGL10.EGL_RENDERABLE_TYPE,
					0x3042 // EGL10.EGL_CONFORMANT
			};
			String[] names = { "EGL_BUFFER_SIZE", "EGL_ALPHA_SIZE",
					"EGL_BLUE_SIZE", "EGL_GREEN_SIZE", "EGL_RED_SIZE",
					"EGL_DEPTH_SIZE", "EGL_STENCIL_SIZE", "EGL_CONFIG_CAVEAT",
					"EGL_CONFIG_ID", "EGL_LEVEL", "EGL_MAX_PBUFFER_HEIGHT",
					"EGL_MAX_PBUFFER_PIXELS", "EGL_MAX_PBUFFER_WIDTH",
					"EGL_NATIVE_RENDERABLE", "EGL_NATIVE_VISUAL_ID",
					"EGL_NATIVE_VISUAL_TYPE", "EGL_PRESERVED_RESOURCES",
					"EGL_SAMPLES", "EGL_SAMPLE_BUFFERS", "EGL_SURFACE_TYPE",
					"EGL_TRANSPARENT_TYPE", "EGL_TRANSPARENT_RED_VALUE",
					"EGL_TRANSPARENT_GREEN_VALUE",
					"EGL_TRANSPARENT_BLUE_VALUE", "EGL_BIND_TO_TEXTURE_RGB",
					"EGL_BIND_TO_TEXTURE_RGBA", "EGL_MIN_SWAP_INTERVAL",
					"EGL_MAX_SWAP_INTERVAL", "EGL_LUMINANCE_SIZE",
					"EGL_ALPHA_MASK_SIZE", "EGL_COLOR_BUFFER_TYPE",
					"EGL_RENDERABLE_TYPE", "EGL_CONFORMANT" };
			int[] value = new int[1];
			for (int i = 0; i < attributes.length; i++) {
				int attribute = attributes[i];
				String name = names[i];
				if (egl.eglGetConfigAttrib(display, config, attribute, value)) {
					EgretContext.logWarn(TAG,
							String.format("  %s: %d\n", name, value[0]));
				} else {
					// Log.w(TAG, String.format("  %s: failed\n", name));
					while (egl.eglGetError() != EGL10.EGL_SUCCESS)
						;
				}
			}
		}

		// Subclasses can adjust these values:
		protected int mRedSize;
		protected int mGreenSize;
		protected int mBlueSize;
		protected int mAlphaSize;
		protected int mDepthSize;
		protected int mStencilSize;
		private int[] mValue = new int[1];
	}

	// //////////////////////

	// ////////////////////////
}
