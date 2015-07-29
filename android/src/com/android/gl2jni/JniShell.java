/*
 * @author jkd2972
 *
 * JniShell.java
 * обнГ5:26:24 2015-7-28
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
