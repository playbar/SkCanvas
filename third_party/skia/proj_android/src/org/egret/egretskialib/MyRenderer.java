package org.egret.egretskialib;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView;

public class MyRenderer implements GLSurfaceView.Renderer {
	private static final String TAG = "MyRenderer";
	int _screenw, _screenh;
	private boolean isGameRun = true;

	boolean isFirst = true;
	
	private long preTime = 0;
	private long currentTime = 0;
	
	private long frameTime  = 1000/60;
	private long dtdd = 0;
	private long frameDt = 0;
	private int renderDelayFrame = 0 ;
	
	public void setFrameTime(long frameTime){
		this.frameTime = frameTime;
	}
	
	public void onDrawFrame(GL10 gl) {
		
		//if(isFirst){
			isFirst = false;
			gl.glClear( GL10.GL_COLOR_BUFFER_BIT | GL10.GL_COLOR_BUFFER_BIT);
			gl.glClearColor(1, 0, 0, 1);
		//	return;
		//}

		

	//	Log.i("GL2JNIView","sleep dt="+(System.currentTimeMillis()-preTime));
		if (isGameRun) { 
			//displayBriefMemory();
			currentTime = System.currentTimeMillis();
			dtdd = frameTime-(currentTime-preTime);
			if(dtdd > 1){
				try{
			//		Log.i("GL2JNIView","run dt="+dtdd);
					Thread.sleep(dtdd-1);
				}catch(Exception e){e.printStackTrace();}
			}
			preTime =  System.currentTimeMillis();
			if(renderDelayFrame == 0){
		//	    mainloop();
			}else{
			    renderDelayFrame--;
			}
			if( GL2JNIView.currentGl2jniview!=null ){
				GL2JNIView.currentGl2jniview.requestRender();
			}
		}
		
	}

	public void setScreenWidthAndHeight(int width, int height) {
		_screenw = width;
		_screenh = height;

	}

	public void onSurfaceChanged(GL10 gl, int width, int height) {
		//EgretContext.logInfo(LOG_TAG, "onSurfaceChanged width="+width+";height="+height);
	}

	public void finalize() throws Throwable {

		EgretContext.logInfo(TAG, "MyRenderer finalize ");
		super.finalize();
	}

	private static boolean is_native_init = false;

	public void onSurfaceCreated(GL10 gl, EGLConfig eglconfig) {

		// Do nothing.
		EgretContext.logInfo("MyRenderer", "MyRenderer::onSurfaceCreated (" + _screenw + ","
				+ _screenh + ")");

//		EgretRuntime  egretRuntime = GL2JNIView.currentGl2jniview.getEgretRuntime();
//		if( egretRuntime == null )
//			return ;
//		
//		String _root =  egretRuntime.getEgretRootFolder();
//		if (false == _root.endsWith("/")) {
//			_root += "/";
//		}
//		
	//	gl.glClearColor(1, 0, 0, 1);
		
		
//		nativeInit(_screenw, _screenh);
		
		
		startNewGame();
	}

	// Touch action
	public void handleActionDown(int idPointerDown, float xPointerDown,
			float yPointerDown) {
	//	nativeTouchesBegin(idPointerDown, xPointerDown, yPointerDown);

	}

	public void handleActionMove(int[] ids, float[] xs, float[] ys) {

	//	nativeTouchesMove(ids, xs, ys);
	}

	public void handleActionUp(int idPointerUp, float xPointerUp,
			float yPointerUp) {

	//	nativeTouchesEnd(idPointerUp, xPointerUp, yPointerUp);
	}

	public void handleActionCancel(int[] ids, float[] xs, float[] ys) {
		// TODO Auto-generated method stub
	//	nativeTouchesCancel(ids, xs, ys);
	}

	public void handleOnPause() {
		EgretContext.logInfo(TAG, "handleOnPause");
		isGameRun = false;
		renderDelayFrame = 1;
	//	nativeOnPause();
	}

	public void handleOnResume() {
	    isGameRun = true;
        preTime =  System.currentTimeMillis();
	//	nativeOnResume();
		
        if( GL2JNIView.currentGl2jniview!=null ){
            GL2JNIView.currentGl2jniview.requestRender();
        }
	}

	public void handleReturnOrMenuKeyDown(int pKeyCode) {
		EgretContext.logInfo(TAG, "handleReturnOrMenuKeyDown");
	//	nativeReturnOrMenuKeyDown(pKeyCode);
	}

	public static void exitApp() {

		EgretContext.logInfo(TAG, "exitApp");
//		if (EgretRuntimeCollecter.isListenerExists()) {
//			EgretContext.logInfo(TAG, "notifyEgretRuntimeWillExit");
//			EgretRuntimeCollecter.notifyEgretRuntimeWillExit();
//		}
	}

	public void handleInsertText(final String pText) {
	//	nativeInsertText(pText);
	}

	public void handleDeleteBackward() {
	//	nativeDeleteBackward();
	}

	public void handleKeyboardDidShow() {
		//nativeKeyboardDidShow();
	}

	public void handleKeyboardDidHide() {
		//nativeKeyboardDidHide();
	}

	public void handleKeyboardFinish() {
		//nativeKeyboardFinish();
	}

	public String getContentText() {

		//return nativeGetContentText();
		return "getContentText unimplement";
	}

	public void startNewGame() {
		
		if (!EgretContext.isRunning){
			return;
		}

	//	nativeStartNewGame(egretRoot, gameId, loaderUrl, updateUrl);
	}

	public void notifyStopGame() {
		EgretContext.logInfo(TAG, "MyRenderer stopGame");
		isGameRun = false;
	//	nativeStopGame();

	}
	
	public void reloadGame(){
	//	isGameRun = false;
	//	nativeReloadGame();
	}
	
	public float[] pointToScreen(float x, float y) {
//		return new int[] {x, y};
	//	return nativePointToScreen(x, y);
		return new float[] {x, y};
	}
	// ////////////////////

/*	private static native void mainloop();

	private static native void nativeStartNewGame(final String egret_root_fold,
			final String gameId, final String loaderUrl, final String updateUrl);

	private static native void nativeStopGame();

	private static native void nativeInit(final int width, final int height);

	private static native void nativeTouchesBegin(final int idPointerDown,
			final float xPointerDown, final float yPointerDown);

	private static native void nativeTouchesEnd(final int idPointerDown,
			final float xPointerDown, final float yPointerDown);

	private static native void nativeTouchesMove(final int[] pIDs,
			final float[] pXs, final float[] pYs);

	private static native void nativeTouchesCancel(final int[] pIDs,
			final float[] pXs, final float[] pYs);
	
	private static native void nativeReloadGame();

	private static native void nativeOnPause();

	private static native void nativeOnResume();

	private static native void nativeReturnOrMenuKeyDown(int pKeyCode);

	private static native void nativeInsertText(final String pText);

	private static native void nativeDeleteBackward();

	private static native void nativeKeyboardDidShow();

	private static native void nativeKeyboardFinish();

	private static native void nativeKeyboardDidHide();

	private static native String nativeGetContentText();

	private static native float[] nativePointToScreen(float x, float y);*/
}
