/*
 * @author jkd2972
 *
 * JniShell.java
 */
package com.android.gl2jni;

public class JniShell {
	static {
        System.loadLibrary("runtimecanvas");
    }
	
	public native static void setFilesDir(String fileDir);
	public native static void initApp(int width,int height);
	public native static void pauseApp();
	public native static void resumeApp();
	public native static void mainLoop();
}
